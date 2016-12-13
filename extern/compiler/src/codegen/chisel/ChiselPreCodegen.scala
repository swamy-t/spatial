package spatial.compiler.ops

import scala.reflect.{Manifest,SourceContext}
import scala.virtualization.lms.internal.{ChiselCodegen}
import scala.virtualization.lms.internal.{MaxJCodegen}
import scala.virtualization.lms.internal.{Traversal}
import java.io.{File, PrintWriter}
import scala.collection.mutable.ListBuffer

import spatial.shared._
import spatial.shared.ops._
import spatial.compiler._
import spatial.compiler.ops._
import scala.collection.mutable.Set

import ppl.delite.framework.DeliteApplication

trait ChiselPreCodegen extends Traversal  {
    val IR:SpatialExp with MemoryAnalysisExp with UnrollingTransformExp with ExternPrimitiveOpsExp
    import IR.{infix_until => _, looprange_until => _, println => _, _}

    var buildDir:String = _

  //debugMode = false
  override val name = "ChiselPreCodegen"

    lazy val chiselManagerGen = new ChiselManagerGen {
        val IR: ChiselPreCodegen.this.IR.type = ChiselPreCodegen.this.IR
    }

   //def isConstOrArgOrBnd(x: Exp[Any]) = x match {
     //case s@Sym(n) => {
       //s match {
         //case Deff(ConstFixPt(_,_,_,_)) => true
         //case Deff(ConstFltPt(_,_,_)) => true
         //case Deff(Reg_read(xx)) => // Only if rhs of exp is argin
           //xx match {
             //case Deff(Argin_new(_)) => true
             //case _ =>  false
           //}
         //case Deff(_) => false // None
         //case _ => true // Is bound
       //}
     //}
   //}

  def emitBuildSBT(stream:PrintWriter) = {
	this.stream = stream
  	emit(s"""libraryDependencies += "edu.berkeley.cs" %% "chisel" % "latest.release"""")
  }

  def quote(x: Exp[Any]) = x match {
    case s@Sym(n) => {
      s match {
        case Def(Argin_new(init)) =>
          s"argin_" + s.tp.erasure.getSimpleName() + n
        case Def(ConstFix(value)) =>
          s"const${value}_" + s.tp.erasure.getSimpleName() + n
        case Def(ConstFlt(value)) =>
          s"const${value}_" + s.tp.erasure.getSimpleName() + n
        case _ =>
          chiselManagerGen.quote(x)
      }}
    case _ =>
      chiselManagerGen.quote(x)
  }

    val argInOuts  = Set.empty[Sym[Reg[_]]]
    val memStreams = Set.empty[Sym[Any]]

  override def preprocess[A:Manifest](b: Block[A]): Block[A] = {
        argInOuts.clear
        memStreams.clear
        b
    }
  override def postprocess[A:Manifest](b: Block[A]): Block[A] = {
		/*withStream(newStream("ChiselManager")) {
			chiselManagerGen.emitManager(stream, argInOuts, memStreams)
		}
		withStream(newSBTStream("build")) {
			emitBuildSBT(stream)
		}*/
		b
	}

	def newSBTStream(fileName:String):PrintWriter = {
		val path = buildDir + java.io.File.separator + fileName + ".sbt"
		val pw = new PrintWriter(path)
		pw
	}

	def newStream(fileName:String):PrintWriter = {
		val path = buildDir + java.io.File.separator + fileName + ".scala"
		val pw = new PrintWriter(path)
		pw
	}

    var stream:PrintWriter = _

  def withStream[A](out: PrintWriter)(body: => A): A = {
    val save = stream
    stream = out
    try { body } finally { stream.flush; stream.close; stream = save }
  }


    def emit(str: String):Unit = {
        stream.println(str)
    }

  override def traverseStm(stm: Stm): Unit = stm match { // override this to implement custom traversal
    case TP(sym, rhs) => {
            preGenNodes(sym,rhs)
            super.traverseStm(stm)
        }
    case _ =>
      super.traverseStm(stm)
    }

  def preGenNodes(sym: Sym[Any], rhs: Def[Any]):Unit = rhs match {
    case e@Hwblock(func) =>
            withStream(newStream("sequential_" + quote(sym))) {
                emitSeqSM(quote(sym), childrenOf(sym).length)
            }
        case e@ParallelPipe(func: Block[Unit]) =>
            withStream(newStream("parallel_" + quote(sym))) {
                emitParallelSM(quote(sym), childrenOf(sym).length)
            }
    case e@OpForeach(cchain, func, inds) =>
            styleOf(sym.asInstanceOf[Rep[Pipeline]]) match {
                case CoarsePipe =>
                    withStream(newStream("metapipe_" + quote(sym))) {
                    emitMPSM(s"${quote(sym)}", childrenOf(sym).size)
                    }
                case InnerPipe =>
                case SequentialPipe =>
                    withStream(newStream("sequential_" + quote(sym))) {
                    emitSeqSM(s"${quote(sym)}", childrenOf(sym).size)
                    }
            }
    case e@OpReduce(cchain, accum, zero, foldAccum, ldFunc, stFunc, func, rFunc, inds, acc, res, rV) =>
            styleOf(sym.asInstanceOf[Rep[Pipeline]]) match {

                case CoarsePipe =>
                    withStream(newStream("metapipe_" + quote(sym))) {
                    emitMPSM(s"${quote(sym)}", childrenOf(sym).size)
                    }
                case InnerPipe =>
                case SequentialPipe =>
                    withStream(newStream("sequential_" + quote(sym))) {
                    emitSeqSM(s"${quote(sym)}", childrenOf(sym).size)
                    }
            }

    case e@UnrolledForeach(cc, func, inds, vs) =>
            styleOf(sym.asInstanceOf[Rep[Pipeline]]) match {
                case CoarsePipe =>
                    withStream(newStream("metapipe_" + quote(sym))) {
                    emitMPSM(s"${quote(sym)}", childrenOf(sym).size)
                    }
                case InnerPipe =>
          parentOf(sym).get match {
            case e@Deff(_:UnrolledReduce[_,_]) => // If part of reduce, emit custom red kernel
              if (childrenOf(parentOf(sym).get).indexOf(sym) == childrenOf(parentOf(sym).get).length-1) {
                withStream(newStream(s"${quote(sym)}_reduce_kernel")) {
                  emitReduction(sym, rhs)
                }
              }
            case _ =>
          }
                case SequentialPipe =>
                    withStream(newStream("sequential_" + quote(sym))) {
                    emitSeqSM(s"${quote(sym)}", childrenOf(sym).size)
                    }
            }
    case e@UnrolledReduce(cchain, accum, func, rFunc, inds, vs, acc, rV) =>
      withStream(newStream("metapipe_" + quote(sym))) {
        emitMPSM(s"${quote(sym)}", childrenOf(sym).size)
      }
      styleOf(sym.asInstanceOf[Rep[Pipeline]]) match {
        case InnerPipe =>
          withStream(newStream(s"${quote(sym)}_reduce_kernel")) {
            emitReduction(sym, rhs)
          }
        case _ =>
      }

    case e@UnitPipe(func) =>
            styleOf(sym.asInstanceOf[Rep[Pipeline]]) match {
                case CoarsePipe =>
                    withStream(newStream("metapipe_" + quote(sym))) {
            emitMPSM(s"${quote(sym)}", childrenOf(sym).size)
                    }
                case InnerPipe =>
          parentOf(sym).get match {
            case e@Deff(_:UnrolledReduce[_,_]) => // If part of reduce, emit custom red kernel
              if (childrenOf(parentOf(sym).get).indexOf(sym) == childrenOf(parentOf(sym).get).length-1) {
                withStream(newStream(s"${quote(sym)}_reduce_kernel")) {
                  emitReduction(sym, rhs)
                }
              }
            case _ =>
          }
                case SequentialPipe =>
          withStream(newStream("sequential_" + quote(sym))) {
            emitSeqSM(s"${quote(sym)}", childrenOf(sym).size)
                    }
            }

    case e@Counter_new(start,end,step,par) =>
      withStream(newStream("counter_" + quote(sym))) {
        emitCtrSM(quote(sym), List(parOf(sym)), 0, 1)
      }
    case e@Counterchain_new(counters) =>
      val pars = counters.map { ctr => parOf(ctr) }
      val gaps = counters.map { ctr => 0 }
      withStream(newStream("counter_" + quote(sym))) {
        emitCtrSM(quote(sym), pars, 0, counters.length)
      }

        case e:Argin_new[_] => argInOuts += sym.asInstanceOf[Sym[Register[_]]]
    case e:Argout_new[_] => argInOuts += sym.asInstanceOf[Sym[Register[_]]]

    case _:BurstStore[_] => memStreams += sym
    case _:BurstLoad[_] => memStreams += sym
    case _:Scatter[_] => memStreams += sym
    case _:Gather[_] => memStreams += sym

    case Sram_new(size, zero) =>
      val dups = duplicatesOf(sym)
      dups.zipWithIndex.foreach { case (d, i) =>
        val readers = readersOf(sym)
        if (false/*d.depth == 2*/) {
          val numReaders_for_this_duplicate = readers.filter{r => instanceIndicesOf(r, sym).contains(i) }.map{r => parentOf(r.controlNode)}.distinct.length
          withStream(newStream("bram_" + quote(sym) + "_" + i)) {
            emitDblBufSM(quote(sym) + "_" + i, numReaders_for_this_duplicate)
          }
        } else if (d.depth > 2) {
          val numReaders_for_this_duplicate = readers.filter{r => instanceIndicesOf(r, sym).contains(i) }.length
          withStream(newStream("bram_" + quote(sym) + "_" + i)) {
            emitDblBufSM(quote(sym) + "_" + i, numReaders_for_this_duplicate)
          }
          // withStream(newStream("bram_" + quote(sym) + "_" + i)) {
          //   emitNBufSM(quote(sym) + "_" + i, d.depth)
          // }
        }
      }

    // case Reg_new(init) =>
    //   val duplicates = duplicatesOf(sym)
    //   duplicates.zipWithIndex.foreach { case (d, i) =>
    //     if (d.depth > 2) {
    //       withStream(newStream("nbuf_" + quote(sym) + "_" + i)) {
    //         emitNBufSM(quote(sym), i, d.depth)
    //       }
    //     }
    //   }



    case Reflect(s, u, effects) =>
      preGenNodes(sym, s)
    case Reify(s, u, effects) =>
        case _ => {
            //println("tp:" + sym.tp.erasure.getSimpleName() + "rhs:" + rhs)
        }
    }

//   def emitNBufSM(name: String, i: Int, bufs: Int) = {
//   stream.println(s"""
// package engine;
// import com.maxeler.maxcompiler.v2.kernelcompiler.KernelLib;
// import com.maxeler.maxcompiler.v2.statemachine.DFEsmInput;
// import com.maxeler.maxcompiler.v2.statemachine.DFEsmOutput;
// import com.maxeler.maxcompiler.v2.statemachine.DFEsmStateEnum;
// import com.maxeler.maxcompiler.v2.statemachine.DFEsmStateValue;
// import com.maxeler.maxcompiler.v2.statemachine.kernel.KernelStateMachine;
// import com.maxeler.maxcompiler.v2.statemachine.types.DFEsmValueType;

// class ${name}_${i}_NBufSM extends KernelStateMachine {

//   // States
//   enum States {""")
//   val states = getStates(bufs)
//   val stateNames = states.map(stateStr(_))
//   emit(s"""
//   // States
//   enum States {
//     ${stateNames.reduce(_ + ",\n      " + _) + ",\nDONE"}
//   }

//   // State IO
//   private final DFEsmInput[] stageDone;
//   private final DFEsmOutput[] curBuf;

//   // State storage
//   private final DFEsmStateEnum<States> stateFF;
//   private final DFEsmStateValue[] curBufFF;
//   private final DFEsmStateValue[] rdoneBitVectorFF;
//   private final DFEsmValue allRdone;

//   // Initialize state machine in constructor
//   public ${name}_${i}_NBufSM(KernelLib owner, int nn, int bits) {
//     super(owner);
//     n = nn;
//     DFEsmValueType wireType = dfeBool();
//     DFEsmValueType counterType = dfeUInt(bits);

//     // Define state machine IO
//     stageDone = new DFEsmInput[n];
//     curBuf = new DFEsmOutput[n];
//     curBufFF = new DFEsmStateValue[n];
//     for (int i = 0; i < n; i++) {
//       stageDone[i] = io.input("stageDone" + i, wireType);
//       curBuf[i] = io.output("curBuf" + i, counterType);
//       curBufFF[i] = state.value(counterType, i);
//     }

//     // Define state storage elements and initial state
//     stateFF = state.enumerated(States.class, States.RUNNING);
//   }


//   private void resetBitVector() {
//     for (int i=0; i<$bufs; i++) {
//       rdoneBitVectorFF[i].next <== 0;
//     }
//   }



//   @Override
//   protected void nextState() {""")

//   (0 until bufs) map { i =>
//     stream.println(s"""
//       IF (r_done_$i) {
//         rdoneBitVectorFF[$i].next <== 1;
//       }""")
//   }
//   stream.println(s"""
//     SWITCH(stateFF) {
//       CASE(States.W) {
//         IF (w_done) {
//           stateFF.next <== States.SWAP;
//         }
//       }
//       CASE(States.RW) {
//         IF (allRdone & w_done) {
//           stateFF.next <== States.SWAP;
//         } ELSE {
//           IF (allRdone) {
//           stateFF.next <== States.W;
//           } ELSE {
//             IF (w_done) {
//               stateFF.next <== States.R;
//             }
//           }
//         }
//       }
//       CASE(States.R) {
//         IF (allRdone) {
//           stateFF.next <== States.SWAP;
//         }
//       }
//       CASE(States.SWAP) {
//         curBufFF.next <== ~curBufFF;
//         stateFF.next <== States.RW;
//         resetBitVector();
//       }
//       OTHERWISE {
//         stateFF.next <== stateFF;
//       }
//     }
//   }

//   @Override
//   protected void outputFunction() {
//     curBuf <== curBufFF;
//   }
//   }
//   """)
//   }


  def isConstOrArgOrBnd(x: Exp[Any]) = x match {
    case s@Sym(n) => {
      s match {
        case Deff(ConstFixPt(_,_,_,_)) => true
        case Deff(ConstFltPt(_,_,_)) => true
        case Deff(Reg_read(xx)) => // Only if rhs of exp is argin
          xx match {
            case Deff(Argin_new(_)) => true
            case _ =>
              if (isReduceStarter(s)) {false} else {true}
          }
        case Deff(_) => false // None
        case _ => true // Is bound
      }
    }
  }

  def addConstOrArgOrBnd(x: Exp[Any], set: Set[Exp[Any]]) = {
    var ret = Set[Exp[Any]]()
    val Deff(dd) = x
    dd match {
      case FltPt_Add(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FixPt_Add(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FltPt_Mul(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FixPt_Mul(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FixPt_Lt(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FixPt_Leq(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FixPt_Neq(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FixPt_Eql(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FixPt_And(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FixPt_Or(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FixPt_Lsh(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FixPt_Rsh(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FltPt_Lt(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FltPt_Leq(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FltPt_Neq(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case FltPt_Eql(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case Bit_And(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case Bit_Or(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case Bit_Xor(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case Bit_Xnor(a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case Bit_Not(a) => if (isConstOrArgOrBnd(a)) {ret += a}
      case Mux2(sel,a,b) => {if (isConstOrArgOrBnd(a)) {ret += a}; if (isConstOrArgOrBnd(b)) {ret += b}}
      case _ =>
    }
    set ++ ret
  }
  def emitReduction(sym: Sym[Any], rhs: Def[Any]) = {
      emit(s"""import Chisel._
class ${quote(sym)}_reduce_kernel extends KernelLib {""")
    rhs match {
      case _:UnrolledReduce[_,_] | _:UnrolledForeach | _:UnitPipe =>
        var isVecResult = false
        val func = rhs match {
          case e:UnrolledReduce[_,_] => e.func
          case e:UnrolledForeach     =>
            isVecResult = true
            e.func
          case UnitPipe(func) => func
        }

        // If there is no result to this kernel, then turn off isStarter and isResult metadata
        val hasRegWrite = focusBlock(func){ focusExactScope(func){ stms => stms.zipWithIndex.map { case (TP(s,d), ii) =>
          val Deff(dd) = s
          dd match {
            case Reg_write(_,_,_) => true
            case _ => false
          }
        }}}.reduce{_|_}

        var inputVecs = Set[Sym[Any]]()
        var treeResultSyms = Set[Sym[Any]]()
        var finalLineReg = ""
        var finalLineBram = ""
        var vecs_from_lists = Set[Exp[Any]]()
        var consts_args_bnds_list = Set[Exp[Any]]()
        var first_reg_read = List(999) // HACK TO SEPARATE ADDRESS CALC ARITHMETIC FROM REDUCE ARITHMETIC
        val treeStringPre = focusBlock(func){ // Send reduce tree to separate file
          focusExactScope(func){ stms =>
            stms.zipWithIndex.map { case (TP(s,d), ii) =>
              val Deff(dd) = s
              consts_args_bnds_list = addConstOrArgOrBnd(s, consts_args_bnds_list)
              Console.println(s" Reduction ${quote(sym)} unroll ${s} ${dd}")
              dd match {
                case Reg_read(_) =>
                  first_reg_read = first_reg_read :+ ii
                  s""
                // case ListVector(_) => // seems to have replaced reg_read with davids merge
                //   // TODO: ask david how to actually detect tree start and tree result because this is sooo hacky!!!
                //   first_reg_read = first_reg_read :+ ii
                //   vecs_from_lists += s
                //   s""
                case tag @ Vec_apply(vec,idx) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  s"var ${quote(s)} = ${quote(vec)}[$idx];"
                case tag @ FixPt_Div(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  s"""${maxJPre(s)} ${quote(s)} = ${quote(a)} / ${quote(b)};"""
                case tag @ FltPt_Div(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  s"""${maxJPre(s)} ${quote(s)} = ${quote(a)} / ${quote(b)};"""
                case tag @ FltPt_Add(a,b) =>
                  // TODO: Way of doing this args & consts check that isn't stupid
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  if (isReduceResult(s)) {
                    treeResultSyms += s
                    if (hasRegWrite) {
                      s"${quote(s)} <== ${quote(a)}; // is tree result, do not add $b"
                    } else {
                      s"${quote(s)} <== ${quote(a)} + ${quote(b)};"
                      // isReduceResult(s) = false
                    }
                  } else {
                    //s"""$pre ${quote(s)} = ${quote(a)} + ${quote(b)};"""
                  }
                case tag @ FixPt_Add(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  if (isReduceResult(s)) {
                    treeResultSyms += s
                    if (hasRegWrite) {
                      s"${quote(s)} <== ${quote(a)}; // is tree result, do not add $b"
                    } else {
                      s"${quote(s)} <== ${quote(a)} + ${quote(b)};"
                      // isReduceResult(s) = false
                    }
                  } else {
                    s"""$pre ${quote(s)} = ${quote(a)} + ${quote(b)};"""
                  }
                case tag @ FltPt_Mul(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = ${quote(a)} * ${quote(b)};"""
                case tag @ FixPt_Mul(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = ${quote(a)} * ${quote(b)};"""
                case FixPt_Lt(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = dfeFixOffset(1, 0, SignMode.UNSIGNED).newInstance(this);\n${quote(s)} = ${quote(a)} < ${quote(b)};"""
                case FixPt_Leq(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = dfeFixOffset(1, 0, SignMode.UNSIGNED).newInstance(this);\n${quote(s)} = ${quote(a)} <= ${quote(b)};"""
                case FixPt_Neq(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = dfeFixOffset(1, 0, SignMode.UNSIGNED).newInstance(this);\n${quote(s)} = ${quote(a)} !== ${quote(b)};"""
                case FixPt_Eql(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = dfeFixOffset(1, 0, SignMode.UNSIGNED).newInstance(this);\n${quote(s)} = ${quote(a)} === ${quote(b)};"""
                case FixPt_And(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = ${quote(a)} & ${quote(b)};"""
                case FixPt_Or(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = ${quote(a)} & ${quote(b)};"""
                case FixPt_Lsh(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = ${quote(a)} & ${quote(b)};"""
                case FixPt_Rsh(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = ${quote(a)} & ${quote(b)};"""
                case FltPt_Lt(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = dfeFixOffset(1, 0, SignMode.UNSIGNED).newInstance(this);\n${quote(s)} = ${quote(a)} < ${quote(b)};"""
                case FltPt_Leq(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = dfeFixOffset(1, 0, SignMode.UNSIGNED).newInstance(this);\n${quote(s)} = ${quote(a)} <= ${quote(b)};"""
                case FltPt_Neq(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = dfeFixOffset(1, 0, SignMode.UNSIGNED).newInstance(this);\n${quote(s)} = ${quote(a)} !== ${quote(b)};"""
                case FltPt_Eql(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = dfeFixOffset(1, 0, SignMode.UNSIGNED).newInstance(this);\n${quote(s)} = ${quote(a)} === ${quote(b)};"""
                case Bit_Not(a) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = ~${quote(a)};"""
                case Bit_And(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = ${quote(a)} & ${quote(b)};"""
                case Bit_Or(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = ${quote(a)} | ${quote(b)};"""
                case Bit_Xor(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = ${quote(a)} ^ ${quote(b)};"""
                case Bit_Xnor(a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = ~(${quote(a)} ^ ${quote(b)});"""
                case Mux2(sel,a,b) =>
                  if (first_reg_read.length > 1) { rTreeMap(s) = sym }
                  val pre = maxJPre(s)
                  s"""$pre ${quote(s)} = ${quote(sel)} ? ${quote(a)} : ${quote(b)} ;"""
                case input @ ( Par_sram_load(_,_) ) =>
                  if (isVecResult) { // Assume there is no reg_write in UnrolledForeach stage, so use par_sram_load
                    first_reg_read = first_reg_read :+ ii
                  }
                  inputVecs += s
                  s"/* Par_sram_load */"
                case input @ ( _:Par_pop_fifo[_] | _:Pop_fifo[_] ) =>
                  inputVecs += s
                  s"/* Par_pop_fifo */"
                case _ =>
                  s"/* Unknown Deff $s $dd */"
              }
            }
          }
        }

        // // TODO: Assume last ListVector node is packing a single element (tree result) into a list
        // val Deff(dd) = vecs_from_lists.toList.last
        // isReduceResult(vecs_from_lists.toList.last) = true
        // val treeResult = dd match {
        //   case ListVector(node) => quote(node.head) // Assume list of one thing
        //   case _ => throw new Exception(s"No tree result found on $sym $rhs reduction!")
        // }

        val treeString = if (first_reg_read.length > 1) {
          treeStringPre.zipWithIndex.filter{
            case (entry: String, ii: Int) => ii > first_reg_read.last
          }.map{ case (entry: String, ii: Int) => entry}.mkString("\n")
        } else { s"// Couldn't figure out what to move to separate kernel for $sym" }

        val treeResult = treeResultSyms.map{a=>quote(a)}.toList.sortWith(_ < _).mkString(",")
        val res_input_arg = if (treeResult != "") {treeResultSyms.map { a => s"var ${quote(a)}"}.mkString(",")} else {""}
        // val cst_arg_input_args = if (args_and_consts.toList.length > 0) {
        //   ", DFEVar " + args_and_consts.map(quote(_)).mkString(", DFEVar ")
        // } else { "" }


        val cst_genStr = ""
        // val cst_genStr = consts_args_bnds_list.map { exp =>
        //   val ts = tpstr(1)(exp.tp, implicitly[SourceContext])
        //   exp match {
        //     case s@Sym(_) => { s match {
        //       case Def(ConstFixPt(num,_,_,_)) =>
        //         s"""DFEVar ${quote(s)} = constant.var($ts, $num);"""
        //       case Def(ConstFltPt(num,_,_)) =>
        //         s"""DFEVar ${quote(s)} = constant.var($ts, $num);"""
        //       case _ =>
        //         s"""Can't handle $s yet"""
        //     }}
        //   }
        // }.mkString("\n")

        val vec_input_args = inputVecs.map { exp => s"DFEVector<DFEVar> ${quote(exp)}"}.toList.sortWith(_ < _).mkString(",")
        val first_comma = if (vec_input_args != "") { "," } else {""}
        val second_comma = if (treeResult != "") { "," } else {""}
        val trailing_args = consts_args_bnds_list.toList
        val owner_comma = if (trailing_args.length > 0 & (vec_input_args != "" | res_input_arg != "")) {","} else {""} // TODO: Super ugly hack

        val trailing_args_comma = if (
          (trailing_args.length > 0) & (
            (first_comma == "" & vec_input_args == "" & second_comma == "" & res_input_arg == "") |
            (vec_input_args != "" & second_comma == "" & res_input_arg == "") |
            (res_input_arg != ""))
            ) "," else ""
        val trailing_args_string = trailing_args.map { exp =>
          s"""var ${quote(exp)}"""
        }.sortWith(_ < _).mkString(",")
        emit(s"""void common($vec_input_args /*1*/ ${if (vec_input_args != "" & treeResult != "") "," else ""}
                $res_input_arg /*2*/ $owner_comma $trailing_args_string /*3*/) {
// For now, I just regenerate constants because java is being annoying about class extensions
$cst_genStr

$treeString
}

${quote(sym)}_reduce_kernel(KernelLib owner $first_comma /*1*/ $vec_input_args $second_comma /*2*/
                $res_input_arg $trailing_args_comma /*3*/  $trailing_args_string) {
  super(owner);
  common(${inputVecs.map( exp => quote(exp)).toList.sortWith(_<_).mkString(", ")} ${if (vec_input_args != "" & treeResult != "") "," else ""} ${treeResult} ${if ((treeResult != "" | inputVecs.toList.length != 0) & trailing_args.length > 0) "," else ""} ${trailing_args.map { exp => quote(exp)}.sortWith(_ < _).mkString(",")});
}
}""")

    }
  }

  def emitCtrSM(name: String, par: List[Int], gap: Int, numCtrs: Int) = {
    stream.println("""
        package engine;
        import Chisel._
    """)

  val smName = name
  stream.println(s"""class ${smName}_CtrSM(s: Array[Int]) extends Module {""")

  stream.println(s"""// ** VISUALIZATION FOR COUNTER **""")
  par.zipWithIndex.map { case (p, i) =>
    stream.println(s"""//    ctr${i}: ${(0 until p).map{_ => "o"}.mkString(" ")}""")
  }


  stream.println(s"""
    // States
    val s_COUNT :: s_SATURATED :: Nil = Enum(UInt(), 2)

    // State IO
    """)
  // TODO: Not tested for parallelism in higher level counters
  stream.println(s"""
      val io = new Bundle {
      """)
  for (i <- 0 until numCtrs){
      stream.println(s"""val count${i} = UInt(OUTPUT)""")
      stream.println(s"""val max${i} = UInt(INPUT)""")
  }
  for (i <- 0 until par.size){
    if (par(i) > 1){
        for(j <- 0 until par(i)-1) {
              stream.println(s"""val  counter${i}_extension${j} = UInt(OUTPUT)""")
        }
    }
  }
  stream.println(s"""
    val saturated = Bool(OUTPUT);
    val done = Bool(OUTPUT);
    val en = Bool(INPUT);
    val reset = Bool(INPUT);
    """)

  stream.println(s"""
      }
      """)
  stream.println(s"""
    val strides = s
    val ff_extensions = new Array[Int](${par.size});
    // Gap between the end of one array of count to the start of the next.
    //   This is useful for padding non-powerof2-banked SRAMs to the next highest pwr of 2 banks
    // i.e- gap = 32, stride = 1, par = 96 would do this:
    // cycle1: count = [0, 1, ..., 94, 95]
    // cycle2: count = [128, 129, ..., 222, 223]
    val gap = UInt(${gap});

    // State storage
    val countFF = Vec.fill(${numCtrs}){Reg(init = UInt(0))}
    """)
  if (numCtrs > 1) {
  stream.println(s"""    val gapBumpFF = Vec.fill(Reg(init = UInt(${par(par.size-1)})))""")}
  stream.println(s"""    val stateFF = Reg(init = s_COUNT)
    """)

  stream.println(s"""
      // Define state machine IO
      """)
  for (j <- 0 until par.size){
    if (par(j) > 1){
      stream.println(s"""      // Par extension for ${j}
      ff_extensions(${j}) = ${par(j)-1} * strides(${j});
      """)
    } else {
      stream.println(s"""      ff_extensions(${j}) = 0""")
    }
  }

  stream.println(s"""
    when (reset) {""")

  for(i <- 0 until numCtrs) {
    stream.println(s"""        countFF(${i}) := UInt(0)""")
  }

  stream.println(s"""        stateFF := s_COUNT
    } .otherwise {
          switch(stateFF) {
            is(s_COUNT) {
              when(io.en) {
                when (""")

  // Generate saturated case
  for(i <- 0 until numCtrs) {
    if(i == numCtrs - 1){
      stream.println(s"""                  (countFF(${i}) + UInt(ff_extensions(${i})) >= io.max${i} - UInt(strides(${i})))) {""")
    } else {
      stream.println(s"""                  (countFF(${i}) + UInt(ff_extensions(${i})) >= io.max${i} - UInt(strides(${i}))) &""")
    }
  }

  stream.println(s"""                stateFF := s_SATURATED""")

  // Generated wrap cases
  for(i <- 1 to numCtrs-1) {
    stream.println(s"""                }.otherwise{ when (""")
    for(j <- numCtrs-1 to i by -1){
      if (j == i){
        stream.println(s"""                  (countFF(${j}) + UInt(ff_extensions(${j})) >= io.max${j} - UInt(strides(${i})))) {""")
      } else {
        stream.println(s"""                  (countFF(${j}) + UInt(ff_extensions(${j})) >= io.max${j} - UInt(strides(${i}))) &""")
      }
    }
    for(j <- numCtrs-1 to i by -1){
      stream.println(s"""                countFF(${j}) := UInt(0);""")
    }
    stream.println(s"""                when (countFF(${i-1}) + UInt(ff_extensions(${i-1})) === gapBumpFF[${i-1}] - UInt(strides(${i-1}))) {
                  countFF(${i-1}) := countFF(${i-1}) + UInt(${par(i-1)} * strides(${i-1})) + gap
                  gapBumpFF(${i-1}) := gapBumpFF(${i-1}) + gap + UInt(${par(par.size-1)})
                } .otherwise {
                  countFF(${i-1}) := countFF(${i-1}) + UInt(${par(i-1)} * strides(${i-1}))
                }""")
  }
  stream.println(s"""                } .otherwise { // innermost ctr
                countFF(${numCtrs-1}) := countFF(${numCtrs-1}) + UInt(${par(numCtrs-1)} * strides(${numCtrs-1})) + gap;""")
  for(j <- 0 until numCtrs){
    stream.print(s"""}""")
  }
  stream.println(s"""           } .otherwise {
              stateFF := s_COUNT
            }
          }""")

  stream.println(s"""          is(s_SATURATED) {
            stateFF := s_SATURATED;
          }
        }
      }
    

        """)

  for(i <- 0 until numCtrs) {
    stream.println(s"""      io.count${i} := countFF(${i})""")
  }
  for (i <- 0 until par.size){
    if (par(i) > 1){
        for(j <- 0 until par(i)-1) {

      stream.println(s"""      
        io.counter${i}_extension${j} := countFF(${i}) + UInt(strides(${i}) * (${j}+1));
      """)
        }

    }
  }


  stream.println(s"""
      io.saturated := UInt(0)
      io.done := UInt(0)
      switch(stateFF){
        is(s_COUNT){
          when(io.en) {

            when (""")

  for(i <- 0 until numCtrs) {
    if(i == numCtrs - 1){
      stream.println(s"""               (countFF(${i}) + UInt(ff_extensions(${i})) >= io.max${i} - UInt(strides(${i})))) {""")
    } else {
      stream.println(s"""               (countFF(${i}) + UInt(ff_extensions(${i})) >= io.max${i} - UInt(strides(${i}))) &""")
    }
  }

  stream.println(s"""             io.saturated := Bool(true);
             io.done := Bool(true);
            }
          }
        }
        is(s_SATURATED){
          when (io.en) {
           io.done := Bool(true);
          }
          io.saturated := Bool(true);
        }
      }
}""")







  }

  def emitDblBufSM(name: String, numReaders: Int) = {
  stream.println(s"""
  package engine;
  import com.maxeler.maxcompiler.v2.kernelcompiler.KernelLib;
  import com.maxeler.maxcompiler.v2.statemachine.DFEsmInput;
  import com.maxeler.maxcompiler.v2.statemachine.DFEsmOutput;
  import com.maxeler.maxcompiler.v2.statemachine.DFEsmStateEnum;
  import com.maxeler.maxcompiler.v2.statemachine.DFEsmStateValue;
  import com.maxeler.maxcompiler.v2.statemachine.DFEsmValue;
  import com.maxeler.maxcompiler.v2.statemachine.kernel.KernelStateMachine;
  import com.maxeler.maxcompiler.v2.statemachine.types.DFEsmValueType;

  class ${name}_DblBufSM extends KernelStateMachine {

    // States
    enum States {
      W, R, RW, SWAP
    }

    // State IO
    private final DFEsmInput w_done;
    private final DFEsmOutput curBuf;""");

    for(i <- 0 until numReaders) {
  stream.println(s"""
  private final DFEsmInput r_done_$i;
  """)
    }

  stream.println(s"""
    // State storage
    private final DFEsmStateEnum<States> stateFF;
    private final DFEsmStateValue curBufFF;

    private final DFEsmStateValue[] rdoneBitVectorFF;
    private final DFEsmValue allRdone;

    // Initialize state machine in constructor
    public ${name}_DblBufSM(KernelLib owner) {
      super(owner);

      // Declare all types required to wire the state machine together
      DFEsmValueType counterType = dfeUInt(32);
      DFEsmValueType wireType = dfeBool();

      // Define state machine IO
      w_done = io.input("w_done", wireType);
  """)

  for(i <- 0 until numReaders) {
      stream.println(s"""
        r_done_${i} = io.input("r_done_${i}", wireType);
      """)
    }


  stream.println(s"""
      curBuf = io.output("curBuf", wireType);

      // Define state storage elements and initial state
      stateFF = state.enumerated(States.class, States.W);
      curBufFF = state.value(wireType, 0);

      rdoneBitVectorFF = new DFEsmStateValue[$numReaders];
      for (int i = 0; i < $numReaders; i++) {
        rdoneBitVectorFF[i] = state.value(wireType, 0);
      }
""")

   stream.println(s"""allRdone = ${(0 until numReaders) map ("rdoneBitVectorFF["+_+"]") mkString(" & ")};""")


  stream.println(s"""
    }

    private void resetBitVector() {
      for (int i=0; i<$numReaders; i++) {
        rdoneBitVectorFF[i].next <== 0;
      }
    }



  @Override
  protected void nextState() {""")

  (0 until numReaders) map { i =>
    stream.println(s"""
      IF (r_done_$i) {
        rdoneBitVectorFF[$i].next <== 1;
      }""")
  }
  stream.println(s"""
    SWITCH(stateFF) {
      CASE(States.W) {
        IF (w_done) {
          stateFF.next <== States.SWAP;
        }
      }
      CASE(States.RW) {
        IF (allRdone & w_done) {
          stateFF.next <== States.SWAP;
        } ELSE {
          IF (allRdone) {
          stateFF.next <== States.W;
          } ELSE {
            IF (w_done) {
              stateFF.next <== States.R;
            }
          }
        }
      }
      CASE(States.R) {
        IF (allRdone) {
          stateFF.next <== States.SWAP;
        }
      }
      CASE(States.SWAP) {
        curBufFF.next <== ~curBufFF;
        stateFF.next <== States.RW;
        resetBitVector();
      }
      OTHERWISE {
        stateFF.next <== stateFF;
      }
    }
  }

  @Override
  protected void outputFunction() {
    curBuf <== curBufFF;
  }
  }
  """)
  }

  private def stateTextSeq(state: Int, N: Int) = {
    val max = N-1
    val condStr = s"(bitVector(${state}))"

    emit(s"""when($condStr) {
      (0 until numStates) foreach {i => bitVector(i) := Bool(false)}""")
    if (state == max) {
      emit(s"""
      counterFF := counterFF + UInt(1);
      when (counterFF >= sizeFF-UInt(1)) {
        stateFF := pipeDone;
      }
      .otherwise {
        stateFF := s0;
      }""")
      emit("}")
    } else {
      emit(s"stateFF := S${state+1}")
      emit("}")
    }
  }

  def emitSeqSM(name: String, numStates: Int):Unit = {
        if (numStates==0) {
            emit(s"""//Number of stages = 0 for ${name}. Nothing is emitted""")
            return
        }
    emit("""
    import Chisel._
    """)

  val smName = name
  val states = (0 until numStates).map(List(_)).toList
  emit(s"""class ${smName}_SeqSM extends Module {""")

  val stateNames = states.map(stateStr(_))
  emit(s"""
    // States
    val pipeInit :: pipeReset :: ${stateNames.reduce(_ + " :: " + _)} :: pipeDone :: pipeSpinWait :: Nil = Enum(UInt(), ${stateNames.length + 4})
  """)

  emit("""

       // Module IO
    val io = new Bundle {
      
      // State machine IO
      val sm_done = Bool(OUTPUT)
      val sm_en = Bool(INPUT)

      // Reset IO
      val rst_en = Bool(OUTPUT)

      // Number of iterations
      val sm_numIter = UInt(INPUT)

      // Generated state IO
      """)
  
  for(i <- 0 until numStates) {
    emit(s"""
    val s${i}_done = Bool(INPUT)
    val s${i}_en = Bool(OUTPUT)
    """)
  }

  emit("""}

    // Defaults
    io.sm_done := Bool(false)
    io.rst_en := Bool(false)
    """)

  for (i <- 0 until numStates) {
    emit(s"""
      io.s${i}_en := Bool(false)""")
  }


  emit(s"""

    val numStates = ${numStates};
    val rstCycles = 10; // <-- hardcoded
  """)

  emit("""
    // Initialize registers
    val stateFF = Reg(init = pipeInit)
    val sizeFF = Reg(init = UInt(0, 32))
    val counterFF = Reg(init = UInt(0, 32))
    val rstCounterFF = Reg(init = UInt(0, 32))

    // Bitvector keeps track of which kernels have finished execution
    // This is a useful hardware synchronization structure to keep
    // track of which kernels have executed/finished execution
    val bitVector = Vec.fill(numStates) {Reg(init = Bool(false))}

    def resetBitVector() = {
        (0 until numStates) foreach { i => bitVector(i) := Bool(false) }
    }
    """)

  emit(s"""
      when(io.sm_en) {

        // State-agnostic update logic for bitVector
    """)
  for(i <- 0 until numStates) {
    emit(s"""
        when (io.s${i}_done) {
        (0 until numStates) foreach { i => bitVector(i) := Bool(true) }
        }""")
  }

  emit(s"""
        switch(stateFF) {

          is (pipeInit) {
            sizeFF := io.sm_numIter
            stateFF := pipeReset
            counterFF := UInt(0)
            rstCounterFF := UInt(0)
          }

          is (pipeReset) {
              io.rst_en := UInt(1);
            rstCounterFF := rstCounterFF + UInt(1)
            when (rstCounterFF === UInt(rstCycles)) {
              stateFF := s0
            }
            .otherwise {
              stateFF := pipeReset
            }
          }
          """)

  for(i <- 0 until states.size) {
    val state = states(i)
    val name = stateNames(i)
    emit(s"""
          is (${name}) {""")
            for (s <- state) {
               emit(s"""io.s${s}_en := ~(  bitVector(${s}) | io.s${s}_done);""")
            }

              stateTextSeq(state(0), numStates)
    emit(s"""
          }""")
  }

  emit(s"""
         is (pipeDone) {
           (0 until numStates) foreach {i => bitVector(i) := Bool(false)}
           io.sm_done := Bool(true);
           stateFF := pipeInit
         }

        }
      }
    }""")

  //emit("""
      //}
    //}
  //}
//}
  //""")

  }

  private def stateStr(state:List[Int]) = {
    "s" + state.map( _.toString).reduce(_+_)
  }

    def emitParallelSM(name: String, numParallel: Int):Unit = {
        if (numParallel==0) {
            emit(s"""//Number of parallel stages = 0 for ${name}. Nothing is emitted""")
            return
        }
        emit(s"""
            import Chisel._ 

            // States
            val pipeInit :: pipeRun :: pipeDone :: Nil = Enum(UInt(), 3)
          """)


        emit(s"""
            // Module IO
            val io = new Bundle {
      
             // State machine IO
              val sm_done = Bool(OUTPUT)
              val sm_en = Bool(INPUT)
            """);

        for(i <- 0 until numParallel) {
            emit(s"""
                val io.s${i}_done = Bool(INPUT)
                val io.s${i}_en = Bool(OUTPUT)
                """)
        }

        emit(s"""
            // State storage
            val stateFF = Reg(init = pipeInit)
            val bitVector = Vec.fill(${numParallel}) {Reg(init = Bool(false))}

            val numParallel = ${numParallel}
            """)

        emit(s"""
            when (io.sm_en) {
                    """)

        for(i <- 0 until numParallel) {
            emit(s"""
                when (io.s${i}_done) {
                    bitVector($i) := Bool(true)
                """)
            for (i <- 0 until numParallel) {
                emit(s"""io.s${i}_en := ~(bitVector(${i}) | io.s${i}_done)""")
            }
            emit(s"""}""")
                                
        }

        emit(s"""
            switch (stateFF) {
                is (pipeInit) {
                    stateFF := pipeRun
                }
                """)

        emit(s"""
            is (pipeRun) {""")
                val condStr = (0 until numParallel).map("bitVector(" + _ + ")").reduce(_ + " & " + _)
                emit(s"""
                    when($condStr) {
                        (0 until numParallel) foreach { i => bitVector(i) := Bool(false) }
                        stateFF := pipeDone
                    }
            }

            is (pipeDone) {
                (0 until numParallel) foreach { i => bitVector(i) := Bool(false) }
                io.sm_done := 1
                stateFF := pipeDone;
            }
            
            }
            }
            """)
    }

  private def getStates(N: Int) = {
    val l = 0.until(N).toList
    val lb_total = ListBuffer[List[Int]]()
    for (i <- 0 until l.size) {
         val lb = ListBuffer[List[Int]]()
         lb.append(List(i))
         for (j <- i+1 until l.size) {
           lb.append((lb.last ++ List(j)))
         }
         lb_total.appendAll(lb)
    }
    lb_total.toList
  }

  private def stateText(state: List[Int], N: Int) = {
    val condStr = state.map("bitVector(" + _ + ")").reduce(_ + " & " + _)
    val max = N-1

    emit(s"""when($condStr) {
          (0 until numParallel) foreach { i => bitVector(i) := Bool(false) }
        }""")
    if (state.size == 1 && state.max == max && !state.contains(0)) {
      emit("  stateFF := pipeDone")
    } else {
      if (state.contains(0)) {
        emit("  counterFF := counterFF + UInt(1)")
        emit("  when (counterFF >= sizeFF-UInt(1)) {")
        stream.print("    stateFF := ")
        if (state.max == max) {
          if (state.size == 1) {  // Only state 0
            stream.print("pipeDone")
          } else {
            stream.print(stateStr(state.drop(1)))
          }
        } else {
          stream.print(stateStr(state.drop(1) ++ List(state.max+1)))
        }
          emit("  } .otherwise {")
        stream.print("    stateFF := ")
        if (state.max == max) stream.print(stateStr(state)) else stream.print(stateStr(state ++ List(state.max+1)))
          emit("  }")
      } else {
        stream.print("stateFF := ")
        if (state.max == max) stream.print(stateStr(state.drop(1))) else stream.print(stateStr(state.drop(1) ++ List(state.max+1)))
        emit(";")
      }
    }
    emit("}")
  }

  def emitMPSM(name: String, numStates: Int):Unit = {
        if (numStates==0) {
            emit(s"""//Number of stages = 0 for ${name}. Nothing is emitted""")
            return
        }
    emit("""import Chisel._""")

  val smName = name
  val states = getStates(numStates)
  emit(s"""class ${smName}_MPSM {""")


  // val stateNames = states.map("S" + _.map( _.toString).reduce(_+_))
  val stateNames = states.map(stateStr(_))
  emit(s"""
    // States
    val pipeInit :: pipeReset :: ${stateNames.reduce(_ + " :: " + _)} :: pipeDone:: Nil = Enum(UInt(), ${stateNames.length + 3})
  """)


  emit("""

    // Module IO
    val io = new Bundle {
      val sm_done = Bool(OUTPUT)
      val sm_last = Bool(OUTPUT)
      val sm_en = Bool(INPUT)
      val sm_numIter = UInt(INPUT)
      val rst_en = Bool(OUTPUT)
  """)

  for(i <- 0 until numStates) {
    emit(s"""
    val s${i}_done = Bool(INPUT)
    val s${i}_en = Bool(OUTPUT)
    """)
  }
  emit(s"""}""")

  emit(s"""
    // State storage
    val sizeFF = Reg(init = UInt(0, 32))
    private final DFEsmStateValue lastFF;
    val lastFF = Reg(init = Bool(false))
    val stateFF = Reg(init = pipeInit)
    val counterFF = Reg(init = UInt(0, 32))
    val resetCounterFF = Reg(init = UInt(0, 32))
    val bitVector = Vec.fill(${numStates}) {Reg(init = Bool(false))}

    val numStates = ${numStates}
    val rstCycles = 10 // <-- hardcoded

    // Default values
    io.sm_done := Bool(false);
    io.sm_last := Bool(false);
    io.rst_en := Bool(false);
  """)

  for (i <- 0 until numStates) {
    emit(s"""
      io.s${i}_en := Bool(false);""")
  }



  emit(s"""
      when(io.sm_en) {
        // State-agnostic update logic for bitVector
    """)
  for(i <- 0 until numStates) {
    emit(s"""
        when (s${i}_done) {
          bitVector($i) := Bool(true);
        }
        when(counterFF >= sizeFF - UInt(1)) {
          io.sm_last := Bool(true)
        }
        .otherwise {
          io.sm_last := Bool(false)
        }
        """)
  }

emit("""
        when (counterFF === sizeFF-UInt(2) {
          lastFF := Bool(true);
        }""")

  emit(s"""
        switch(stateFF) {
          is (pipeInit) {
            sizeFF := io.sm_numIter;
            stateFF := pipeReset;
            counterFF := UInt(0);
            rstCounterFF := UInt(0);
            lastFF := Bool(false);
          }

          is (pipeReset) {
            rstCounterFF := rstCounterFF + UInt(1)
            io.rst_en := Bool(true)

            when (rstCounterFF === UInt(rstCycles)) {
              stateFF := S0;
            }
            .otherwise {
              stateFF := pipeReset;
            }
          }
          """)

  for(i <- 0 until states.size) {
    val state = states(i)
    val name = stateNames(i)
    emit(s"""
          is (${name}) {""")
            for (s <- state) {
               emit(s"""s${s}_en := ~(bitVector($s) | io.s${s}_done)""")
            }
            stateText(state, numStates)
    emit(s"""
          }""")
  }

  emit(s"""
         is (pipeDone) {
          io.sm_done := Bool(true)
          (0 until numStates) foreach { i => bitVector(i) := Bool(false) }
          stateFF := pipeInit
         }
      }
    }
    }""")
  }

}
