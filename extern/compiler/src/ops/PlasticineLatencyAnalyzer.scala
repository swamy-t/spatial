package spatial.compiler.ops

import scala.reflect.{Manifest,SourceContext}

import spatial.shared._
import spatial.shared.ops._
import spatial.compiler._
import spatial.compiler.ops._

trait PlasticineLatencyAnalyzer extends ModelingTraversal {
  val IR: SpatialExp with NodeMetadataOpsExp with LatencyModel
  import IR._
  import ReductionTreeAnalysis._

  override val name = "Plasticine Latency"
  debugMode = SpatialConfig.debugging || SpatialConfig.loudModels || SpatialConfig.pirdebug
  verboseMode = SpatialConfig.verbose || SpatialConfig.pirdebug

  lazy val model = new PlasticineLatencyModel{val IR: PlasticineLatencyAnalyzer.this.IR.type = PlasticineLatencyAnalyzer.this.IR}

  override def latencyOf(e: Exp[Any]) = if (inHwScope) model.latencyOf(e, inReduce) else 0L

  override def latencyOfPipe(b: Block[Any]): Long = {
    getStages(b).map{stage => latencyOf(stage)}.sum
  }

  override def silence() {
    model.silence()
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
        val N = Math.ceil(nIters(cchain,ignorePar=true).toDouble / model.LANES).toLong
        debugs(s"Foreach $lhs (N = $N):")
        val pipe = latencyOfPipe(func)

        debugs(s"- pipe = $pipe")
        pipe + N - 1 + latencyOf(lhs)

      case EatReflect(Pipe_fold(cchain,accum,zero,fA,iFunc,ld,st,func,rFunc,_,_,_,_,rV)) if isInnerPipe(lhs) =>
        val N = Math.ceil(nIters(cchain,ignorePar=true).toDouble / model.LANES).toLong
        val P = model.LANES

        debugs(s"Reduce $lhs (N = $N):")

        val body = latencyOfPipe(func)
        val internal = latencyOfPipe(rFunc) * reductionTreeHeight(P)

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
        val internal = latencyOfPipe(rFunc) * P //* reductionTreeHeight(P)
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
        val internal: Long = latencyOfPipe(iFunc) + latencyOfPipe(ld1) + latencyOfPipe(rFunc) * Pm
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

  override def run[A:Manifest](b: Block[A]) = {
    if (SpatialConfig.genCGRA) super.run(b) else b
  }

  override def preprocess[A:Manifest](b: Block[A]) = {
    cycleScope = Nil
    super.preprocess(b)
  }
  override def postprocess[A:Manifest](b: Block[A]): Block[A] = {
    // TODO: Could potentially have multiple accelerator designs in a single program
    // Eventually want to be able to support multiple accel scopes
    totalCycles = cycleScope.sum

    report(s"Plasticine Report: ")
    report(s"Estimated cycles: $totalCycles")
    report(s"Estimated runtime (at " + "%.2f".format(model.CLK) +"MHz): " + "%.8f".format(totalCycles/(model.CLK*1000000f)) + "s")

    (b)
  }

}
