package spatial.compiler.ops

import scala.reflect.{Manifest,SourceContext}

import spatial.shared._
import spatial.shared.ops._
import spatial.compiler._
import spatial.compiler.ops._

trait LatencyAnalysisExp extends LatencyModel {
  this: SpatialExp =>

  val interruptCycles = 96
  val flushCycles = 512
  val pcieCycles = 42500
  val baseCycles = flushCycles + interruptCycles + pcieCycles

  var CLK = 150.0f // Clock frequency in MHz
}

trait LatencyAnalyzer extends ModelingTraversal {
  val IR: SpatialExp with LatencyAnalysisExp
  import IR._
  import ReductionTreeAnalysis._

  override val name = "Latency Analyzer"
  debugMode = SpatialConfig.debugging || SpatialConfig.loudModels
  verboseMode = SpatialConfig.verbose

  override def silence() {
    IR.silenceLatencyModel()
    super.silence()
  }

  var cycleScope: List[Long] = Nil
  var totalCycles: Long = 0L
  var scopeLevel: Int = 0

  def debugs(x: => Any) = debug(".."*scopeLevel + x)

  override def resume() {
    inHwScope = true
    cycleScope ::= latencyOfBlock(savedBlock.get).sum
    inHwScope = false
  }

  def latencyOfBlock(b: Block[Any]): List[Long] = {
    val outerScope = cycleScope
    cycleScope = Nil
    scopeLevel += 1
    //traverseBlock(b) -- can cause us to see things like counters as "stages"
    getControlNodes(b).foreach{
      case s@Def(d) => traverse(s.asInstanceOf[Sym[Any]], d)
      case _ =>
    }
    scopeLevel -= 1

    val cycles = cycleScope
    cycleScope = outerScope
    (cycles)
  }

  override def traverse(lhs: Sym[Any], rhs: Def[Any]) {
    val cycles = rhs match {
      case EatReflect(Hwblock(blk)) =>
        inHwScope = true
        val body = latencyOfBlock(blk).sum
        save(blk)
        inHwScope = false
        body

      case EatReflect(Pipe_parallel(func)) =>
        debugs(s"Parallel $lhs: ")
        val blks = latencyOfBlock(func)
        if (debugMode) blks.reverse.zipWithIndex.foreach{case (s,i) => debugs(s"- $i. $s")}
        blks.max + latencyOf(lhs)

      // --- Pipe
      case EatReflect(Unit_pipe(func)) if isInnerPipe(lhs) =>
        debugs(s"Pipe $lhs: ")
        val pipe = latencyOfPipe(func)
        debugs(s"- pipe = $pipe")
        pipe + latencyOf(lhs)

      case EatReflect(Pipe_foreach(cchain, func, _)) if isInnerPipe(lhs) =>
        val N = nIters(cchain)
        debugs(s"Foreach $lhs (N = $N):")
        val pipe = latencyOfPipe(func)

        debugs(s"- pipe = $pipe")
        pipe + N - 1 + latencyOf(lhs)

      case EatReflect(Pipe_fold(cchain,accum,zero,fA,iFunc,ld,st,func,rFunc,_,_,_,_,rV)) if isInnerPipe(lhs) =>
        val N = nIters(cchain)
        val P = parsOf(cchain).reduce(_*_)

        debugs(s"Reduce $lhs (N = $N):")

        val fuseMapReduce = canFuse(func,rFunc,rV,P)

        val body = latencyOfPipe(func)
        val internal = if (fuseMapReduce) Math.max(reductionTreeHeight(P) - 2, 0)
                       else latencyOfPipe(rFunc) * reductionTreeHeight(P)

        val cycle = latencyOfCycle(iFunc) + latencyOfCycle(ld) + latencyOfCycle(rFunc) + latencyOfCycle(st)

        debugs(s"- body  = $body")
        debugs(s"- tree  = $internal")
        debugs(s"- cycle = $cycle")
        body + internal + N*cycle + latencyOf(lhs)

      // --- Sequential
      case EatReflect(Unit_pipe(func)) if isSequential(lhs) =>
        debugs(s"Outer Pipe $lhs:")
        val stages = latencyOfBlock(func)
        if (debugMode) stages.reverse.zipWithIndex.foreach{case (s,i) => debugs(s"- $i. $s")}

        stages.sum + latencyOf(lhs)


      // --- Metapipeline and Sequential
      case EatReflect(Pipe_foreach(cchain, func, _)) =>
        val N = nIters(cchain)
        debugs(s"Outer Foreach $lhs (N = $N):")
        val stages = latencyOfBlock(func)
        if (debugMode) stages.reverse.zipWithIndex.foreach{case (s,i) => debugs(s"- $i. $s")}

        if (isMetaPipe(lhs)) { stages.max * (N - 1) + stages.sum + latencyOf(lhs) }
        else                 { stages.sum * N + latencyOf(lhs) }

      case EatReflect(Pipe_fold(cchain,accum,zero,fA,iFunc,ld,st,func,rFunc,_,_,_,_,_)) =>
        val N = nIters(cchain)
        val P = parsOf(cchain).reduce(_*_)
        debugs(s"Outer Reduce $lhs (N = $N):")

        val mapStages = latencyOfBlock(func)
        val internal = latencyOfPipe(rFunc) * reductionTreeHeight(P)
        val cycle = latencyOfCycle(iFunc) + latencyOfCycle(ld) + latencyOfCycle(rFunc) + latencyOfCycle(st)

        val reduceStage = internal + cycle
        val stages = mapStages :+ reduceStage

        if (debugMode) stages.reverse.zipWithIndex.foreach{case (s,i) => debugs(s"- $i. $s")}

        if (isMetaPipe(lhs)) { stages.max * (N - 1) + stages.sum + latencyOf(lhs) }
        else                 { stages.sum * N + latencyOf(lhs) }

      case EatReflect(Accum_fold(ccOuter,ccInner,accum,zero,fA,iFunc,func,ld1,ld2,rFunc,st,_,_,_,_,_,_,_)) =>
        val Nm = nIters(ccOuter)
        val Nr = nIters(ccInner)
        val Pm = parsOf(ccOuter).reduce(_*_) // Parallelization factor for map
        val Pr = parsOf(ccInner).reduce(_*_) // Parallelization factor for reduce

        debugs(s"Block Reduce $lhs (Nm = $Nm, Nr = $Nr)")

        val mapStages: List[Long] = latencyOfBlock(func)
        val internal: Long = latencyOfPipe(iFunc) + latencyOfPipe(ld1) + latencyOfPipe(rFunc) * reductionTreeHeight(Pm)
        val accumulate: Long = latencyOfPipe(ld2) + latencyOfPipe(rFunc) + latencyOfPipe(st)

        val reduceStage: Long = internal + accumulate + Nr - 1
        val stages = mapStages :+ reduceStage

        if (debugMode) stages.reverse.zipWithIndex.foreach{case (s,i) => debugs(s"- $i. $s")}

        if (isMetaPipe(lhs)) { stages.max * (Nm - 1) + stages.sum + latencyOf(lhs) }
        else                 { stages.sum * Nm + latencyOf(lhs) }

      case _ =>
        // No general rule for combining blocks
        blocks(rhs).foreach{blk => traverseBlock(blk)}
        latencyOf(lhs)
    }
    cycleScope ::= cycles
  }

  override def preprocess[A:Manifest](b: Block[A]) = {
    cycleScope = Nil
    super.preprocess(b)
  }
  override def postprocess[A:Manifest](b: Block[A]): Block[A] = {
    // TODO: Could potentially have multiple accelerator designs in a single program
    // Eventually want to be able to support multiple accel scopes
    totalCycles = cycleScope.sum + IR.baseCycles

    report(s"Estimated cycles: $totalCycles")
    report(s"Estimated runtime (at " + "%.2f".format(IR.CLK) +"MHz): " + "%.8f".format(totalCycles/(IR.CLK*1000000f)) + "s")

    (b)
  }

}
