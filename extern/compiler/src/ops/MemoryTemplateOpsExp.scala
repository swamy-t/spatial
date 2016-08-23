package spatial.compiler.ops

import java.io.{File,FileWriter,PrintWriter}
import scala.virtualization.lms.common.{BaseExp, EffectExp, ScalaGenEffect, CGenEffect, DotGenEffect, MaxJGenEffect, MaxJGenFat, Record}
import scala.virtualization.lms.internal.{Traversal}
import scala.reflect.{Manifest,SourceContext}
import ppl.delite.framework.transform.{DeliteTransform}
import scala.collection.mutable.Set

import spatial.shared._
import spatial.shared.ops._
import spatial.compiler._
import spatial.compiler.ops._

trait BlockRAM[T]
trait SpatialFIFO[T]
trait SpatialCAM[K,V]
trait SpatialVector[T]
trait CACHE[T]
trait Register[T]
trait DRAM[T]

trait SpatialPipeline
trait SpatialIndices

trait MemoryTemplateTypesExp extends MemoryTemplateTypes with BaseExp {
  type OffChipMem[T] = DRAM[T]
  type BRAM[T] = BlockRAM[T]
  type FIFO[T] = SpatialFIFO[T]
  type CAM[K,V] = SpatialCAM[K,V]
  type Vector[T] = SpatialVector[T]
  type Cache[T] = CACHE[T]
  type Reg[T] = Register[T]

  type Pipeline = SpatialPipeline
  type Indices = SpatialIndices

  def isPipeline[T:Manifest] = isSubtype(manifest[T].runtimeClass, classOf[SpatialPipeline])
  def isRegister[T:Manifest] = isSubtype(manifest[T].runtimeClass, classOf[Register[_]])
  def isBRAM[T:Manifest]     = isSubtype(manifest[T].runtimeClass, classOf[BlockRAM[_]])
  def isFIFO[T:Manifest]     = isSubtype(manifest[T].runtimeClass, classOf[SpatialFIFO[_]])
  def isCache[T:Manifest]    = isSubtype(manifest[T].runtimeClass, classOf[CACHE[_]])
  def isCAM[T:Manifest]      = isSubtype(manifest[T].runtimeClass, classOf[SpatialCAM[_,_]])
  def isVector[T:Manifest]   = isSubtype(manifest[T].runtimeClass, classOf[SpatialVector[_]])

  def offchipMemManifest[T:Manifest]: Manifest[OffChipMem[T]] = manifest[DRAM[T]]
  def bramManifest[T:Manifest]: Manifest[BRAM[T]] = manifest[BlockRAM[T]]
  def fifoManifest[T:Manifest]: Manifest[FIFO[T]] = manifest[SpatialFIFO[T]]
  def camManifest[K:Manifest,V:Manifest]: Manifest[CAM[K,V]] = manifest[SpatialCAM[K,V]]
  def vectorManifest[T:Manifest]: Manifest[Vector[T]] = manifest[SpatialVector[T]]
  def cacheManifest[T:Manifest]: Manifest[Cache[T]] = manifest[CACHE[T]]
  def regManifest[T:Manifest]: Manifest[Reg[T]] = manifest[Register[T]]
  def pipelineManifest: Manifest[Pipeline] = manifest[SpatialPipeline]

  // TODO: Should be refined manifest? But how to know how many fields to fill in?
  def indicesManifest: Manifest[Indices] = manifest[SpatialIndices]
}

trait MemoryTemplateOpsExp extends MemoryTemplateTypesExp with ExternPrimitiveOpsExp with EffectExp with BRAMOpsExp {
  this: SpatialExp =>

  // --- Nodes
  case class Vector_from_list[T](elems: List[Exp[T]])(implicit val mT: Manifest[T], val ctx: SourceContext) extends Def[Vector[T]]

  // --- Internal API
  def vector_from_list[T:Manifest](elems: List[Rep[T]])(implicit ctx: SourceContext): Rep[Vector[T]] = reflectPure(Vector_from_list(elems))

  // --- Mirroring
  override def mirror[A:Manifest](e: Def[A], f: Transformer)(implicit pos: SourceContext): Exp[A] = e match {
    case e@Vector_from_list(elems) => reflectPure(Vector_from_list(f(elems))(e.mT, e.ctx))(mtype(manifest[A]), pos)
    case Reflect(e@Vector_from_list(elems), u, es) => reflectMirrored(Reflect(Vector_from_list(f(elems))(e.mT,e.ctx), mapOver(f,u), f(es)))(mtype(manifest[A]), pos)
    case _ => super.mirror(e, f)
  }
}

// Defines type remappings required in Scala gen (should be same as in library)
trait ScalaGenMemoryTemplateOps extends ScalaGenEffect with ScalaGenControllerTemplateOps {
  val IR: ControllerTemplateOpsExp with SpatialCodegenOps
  import IR._

  override def remap[A](m: Manifest[A]): String = m.erasure.getSimpleName match {
    case "BlockRAM" => "Array[" + remap(m.typeArguments(0)) + "]"
    case "SpatialFIFO" => "scala.collection.mutable.Queue[" + remap(m.typeArguments(0)) + "]"
    case "SpatialCAM"  => "scala.collection.mutable.HashMap[" + remap(m.typeArguments(0)) + ", " + remap(m.typeArguments(1)) + "]"
    case "SpatialVector" => "Array[" + remap(m.typeArguments(0)) + "]"
    case "CACHE"     => "Array[" + remap(m.typeArguments(0)) + "]"
    case "Register" => "Array[" + remap(m.typeArguments(0)) + "]"
    case "DRAM"     => "Array[" + remap(m.typeArguments(0)) + "]"
    case "SpatialPipeline" => "Unit"
    case _ => super.remap(m)
  }

  override def emitNode(sym: Sym[Any], rhs: Def[Any]) = rhs match {
    case Vector_from_list(elems) =>
      emitValDef(sym, "Array" + elems.map(quote).mkString("(", ",", ")"))

    case _ => super.emitNode(sym, rhs)
  }
}

trait CGenMemoryTemplateOps extends CGenEffect {
  val IR: ControllerTemplateOpsExp with SpatialIdentifiers with OffChipMemOpsExp
  with NosynthOpsExp
  import IR._

  // Current TileLd/St templates expect that LMem addresses are
  // statically known during graph build time in MaxJ. That can be
  // changed, but until then we have to assign LMem addresses
  // statically. Assigning each OffChipArray a 384MB chunk now
  val burstSize = 384
  var nextLMemAddr: Long = burstSize * 1024 * 1024
  def getNextLMemAddr() = {
    val addr = nextLMemAddr
    nextLMemAddr += burstSize * 1024 * 1024;
    addr
  }

  def bitsToStringInt(x: Int) = x match {
    case n: Int if n <= 8 => "8"
    case n: Int if n <= 16 => "16"
    case n: Int if n <= 32 => "32"
    case _ => "64"
  }

  def bitsToFloatType(bits: Int) = bits match {
    case n: Int if n <= 32 => "float"
    case _ => "double"
  }

//  private def bitsToStringInt(bits: Int): String = {
//    if (bits <= 8) "8"
//    else if (bits <= 16) "16"
//    else if (bits <= 32) "32"
//    else "64"
//  }

//  private def bitsToFloatType(bits: Int) = {
//    if (bits <= 32) "float"
//    else "double"
//  }

  override def remap[A](m: Manifest[A]): String = m.erasure.getSimpleName match {
    case "BlockRAM" => remapWithRef(m.typeArguments(0))
    case "SpatialVector" => remapWithRef(m.typeArguments(0))
    // case "SpatialFIFO" => ???
    case "Register" => remapWithRef(m.typeArguments(0))
    case "DRAM"     => "maxjLmem"

    case "SpatialCounter" => "int32_t"
    case "SpatialCounterChain" => "int32_t*"
    case "SpatialPipeline" => "void"

    case "SpatialBit" => "bool"
    case "Signed" => ""
    case "Unsign" => "u"
    case "FixedPoint" => remap(m.typeArguments(0)) + "int" + bitsToStringInt(remap(m.typeArguments(1)).toInt + remap(m.typeArguments(2)).toInt) + "_t"
    case "FloatPoint" => bitsToFloatType(remap(m.typeArguments(0)).toInt + remap(m.typeArguments(1)).toInt)
    case bx(n) => n
    case _ => super.remap(m)
  }


  override def emitDataStructures(path: String) {
    super.emitDataStructures(path)
    val stream = new PrintWriter(path + "maxjLmem.h")
    stream.println(
"""
#ifndef __MAXJLMEM_H__
#define __MAXJLMEM_H__
#include <stdint.h>

class maxjLmem {
public:
  uint64_t baseAddr;
  uint32_t size;

  maxjLmem(uint64_t base, int size) {
    this->baseAddr = base;
    this->size = size;
  }
};
#endif
""")
    stream.close()

    typesStream.println(s"""#include "maxjLmem.h"""")
    typesStream.println(s"""#include <Top.h>""")
    typesStream.println(s"""extern max_engine_t *engine;""")
  }

  override def emitNode(sym: Sym[Any], rhs: Def[Any]) = rhs match {
    case Set_mem(fpgamem, cpumem) =>
      stream.println(s"""
      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t ${quote(fpgamem)}_wrAct;
      ${quote(fpgamem)}_wrAct.param_size = ${quote(cpumem)}->length * sizeof(${remap(fpgamem.tp.typeArguments.head)});
      ${quote(fpgamem)}_wrAct.param_start = ${quote(fpgamem)}->baseAddr;
      ${quote(fpgamem)}_wrAct.instream_fromcpu = (const uint8_t*) ${quote(cpumem)}->data;
      Top_writeLMem_run(engine, &${quote(fpgamem)}_wrAct);""")
    case Get_mem(fpgamem, cpumem) =>
      stream.println(s"""
      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t ${quote(fpgamem)}_rdAct;
      ${quote(fpgamem)}_rdAct.param_size = ${quote(cpumem)}->length *sizeof(${remap(fpgamem.tp.typeArguments.head)});
      ${quote(fpgamem)}_rdAct.param_start = ${quote(fpgamem)}->baseAddr;
      ${quote(fpgamem)}_rdAct.outstream_tocpu = (uint8_t*) ${quote(cpumem)}->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\\n");
      Top_readLMem_run(engine, &${quote(fpgamem)}_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\\n");""")
    case Offchip_new(size) =>
      emitValDef(sym, s"""new maxjLmem(${getNextLMemAddr()}, ${quote(size)})""")

    case Forloop(start, end, step, body, idx) =>
      val itp = remap(start.tp)
      stream.println(s"""for(${quote(itp)} i=${quote(start)}; i<${quote(end)}; i+=${quote(step)}) {""")
      stream.println(s"""${quote(itp)} ${quote(idx)} = i;""")
      emitBlock(body)
      stream.println(s"""}""")


    case _ => super.emitNode(sym, rhs)
  }
}

trait MaxJGenMemoryTemplateOps extends MaxJGenEffect with MaxJGenFat with MaxJGenControllerTemplateOps {
  val IR: LoweredPipeOpsExp with ControllerTemplateOpsExp with TpesOpsExp with ParallelOpsExp
          with PipeOpsExp with OffChipMemOpsExp with RegOpsExp with ExternCounterOpsExp
          with ExternPrimitiveOpsExp with SpatialCodegenOps with NosynthOpsExp with MemoryAnalysisExp with FIFOOpsExp with VectorOpsExp
          with DeliteTransform with ReductionAnalysisExp
  import IR.{println=>_,_}

  override def remap[A](m: Manifest[A]): String = m.erasure.getSimpleName match {
    case "SpatialVector" => "DFEVector<DFEVar>"
    case _ => super.remap(m)
  }

  // Current TileLd/St templates expect that LMem addresses are
  // statically known during graph build time in MaxJ. That can be
  // changed, but until then we have to assign LMem addresses
  // statically. Assigning each OffChipArray a 384MB chunk now
  val burstSize = 384
  var nextLMemAddr: Long = burstSize * 1024 * 1024
  def getNextLMemAddr() = {
    val addr = nextLMemAddr
    nextLMemAddr += burstSize * 1024 * 1024;
    addr/burstSize
  }

  var emittedSize = Set.empty[Exp[Any]]
  override def initializeGenerator(buildDir:String): Unit = {
    emittedSize = Set.empty[Exp[Any]]
    nextLMemAddr = burstSize * 1024 * 1024
    super.initializeGenerator(buildDir)
  }

  val brams = Set[Exp[BRAM[Any]]]()
  val regs = Set[(Exp[Reg[Any]], Int)]()
  override def emitFileFooter() = {
    emit(s"""// rdone signals for BRAMs go here""")
    brams.foreach { b =>
      b match { // Only generate for non-bound syms
        case Def(exist) =>
          val dups = duplicatesOf(b)
          dups.length match {
            case 1 =>
              if (isDblBuf(b)) {
                val reader = topReadersOf(b).last._1 // CRITICAL TODO: What to do with actual multiple readers?
                emit(s"""${quote(b)}.connectRdone(${quote(reader)}_done);""")
                if (writersOf(b).isEmpty) throw new Exception(s"Bram ${quote(b)} has no writer!")
                val topWriter = topWritersOf(b).head
                topWriter match {
                  case (writer, _, _) =>
                    emit(s"""${quote(b)}.connectWdone(${quote(writer)}_done);""")
                  case _ =>
                    val writer = writersOf(b).head._1
                    emit(s"""${quote(b)}.connectWdone(${quote(writer)}_done);""")
                }
              }
            case _ =>
              dups.zipWithIndex.foreach { case (d, i) =>
                if (d.depth > 1) {
                  topReadersOf(b).foreach { r =>
                    if (instanceIndexOf(r._3, b) == i) {
                      val reader = r._1
                      emit(s"""${quote(b)}_${i}.connectRdone(${quote(reader)}_done);""")
                    }
                  }
                  if (writersOf(b).isEmpty) throw new Exception(s"Bram ${quote(b)} has no writer!")
                  val topWriter = topWritersOf(b).head
                  topWriter match {
                    case (writer, _, _) =>
                      emit(s"""${quote(b)}_${i}.connectWdone(${quote(writer)}_done);""")
                    case _ =>
                      val writer = writersOf(b).head._1
                      emit(s"""${quote(b)}_${i}.connectWdone(${quote(writer)}_done);""")
                  }

                }
              }
          }
        case _ => //do nothing
      }

    }
    regs.foreach { case (b, i) =>
      val meminst = duplicatesOf(b)(i)
      if (meminst.depth > 1) {
        val readers = readersOf(b)
        val reader = readers(i)._1
        emit(s"""${quote(b)}_${i}_lib.connectRdone(${quote(reader)}_done);""")
        if (writersOf(b).isEmpty) throw new Exception(s"Reg ${quote(b)} has no writer!")
        val writer = writersOf(b).head._1
        emit(s"""${quote(b)}_${i}_lib.connectWdone(${quote(writer)}_done);""")
      }
    }
    super.emitFileFooter()
  }

  def bramLoad(sym: Sym[Any], bram_in: Exp[BRAM[Any]], addr: Exp[Any], par: Boolean = false) {
    val bram = if (bram_redloop_map.contains(bram_in)) {bram_redloop_map(bram_in)} else {bram_in}
    emitComment("Bram_load {")
    val bnd = bram match {
      case Def(rhs) => false
      case _ => true
    }
    // Console.println(s"cg: generating reader $sym on bram ${bram}x${duplicatesOf(bram).length}(bound ${bnd}) inst ${instanceIndexOf(sym, bram)}")
    if (isDummy(bram)) {
      val pre = if (!par) maxJPre(bram) else "DFEVector<DFEVar>"
      emit(s"""${pre} ${quote(sym)} = ${quote(bram)}.connectRport(${quote(addr)}); //1""")
    } else {
      val dups = duplicatesOf(bram)
      val r = readersOf(bram)
      val choose_from = r.map { case (_,_,a) => a }
      val i = choose_from.indexOf(sym)
      val b_i = instanceIndexOf(sym, bram)
      val bram_name = if (dups.length == 1) { s"${quote(bram)}" } else {s"${quote(bram)}_${b_i}"}
      val pre = if (!par) maxJPre(bram) else "DFEVector<DFEVar>"
      val num_dims = dimsOf(bram).length

      val inds = parIndicesOf(r(i)._3) match {
        case Nil => List(accessIndicesOf(r(i)._3))
        case _ => parIndicesOf(r(i)._3)
      }
      
      num_dims match {
        case 1 => // 1D bram
          inds.length match {
            case 1 => // One address
              // Spit out DFEVar if not already done
              val addr0 = inds(0)(0)
              addr0 match {
                case Def(rhs0) =>
                  if (!emitted_consts.contains((addr0, rhs0))) {
                    emitted_consts += ((addr0, rhs0))
                  }
                case _ =>
              }
              if (par) {
                emit(s"""$pre ${quote(sym)} = new DFEVectorType<DFEVar>(${bram_name}.type, 1).newInstance(this, Arrays.asList(${quote(bram)}.connectRport(${quote(addr0)}))); //2""")
              } else {
                emit(s"""${pre} ${quote(sym)} = ${bram_name}.connectRport(${quote(addr0)}); //3""")            
              }
            case _ => // Many address
              emit(s"""${pre} ${quote(sym)} = ${bram_name}.connectRport(${quote(addr)}); //4""")
          }
        case 2 => // 2D bram
          inds.length match {
            case 1 => // One address
              val addr0 = inds(0)(0)
              val addr1 = inds(0)(1)
              addr0 match {
                case Def(rhs0) => if (!emitted_consts.contains((addr0, rhs0))) { emitted_consts += ((addr0, rhs0)) }
                case _ =>
              }
              addr1 match {
                case Def(rhs1) => if (!emitted_consts.contains((addr1, rhs1))) { emitted_consts += ((addr1, rhs1)) }
                case _ =>
              }
              if (par) {
                emit(s"""$pre ${quote(sym)} = new DFEVectorType<DFEVar>(${bram_name}.type, 1).newInstance(this, Arrays.asList(${bram_name}.connectRport(${quote(addr0)}, ${quote(addr1)}))); //5""")
              } else {
                emit(s"""$pre ${quote(sym)} = ${bram_name}.connectRport(${quote(addr0)}, ${quote(addr1)}); //6""")
              }
            case _ =>
              val a = inds(0)
              val b = inds(1)
              if (quote(a(1)) == quote(b(1))) { // TODO: Check if stride = dim, rather than if quote(first_colAddr) = quote(second_colAddr)
                var addr1 = ""
                val addr0 = inds.map { row =>
                              row.length match {
                                case 1 =>
                                  addr1 = quote(1)
                                  quote(row(0))
                                case _ =>
                                  addr1 = quote(row(1))
                                  quote(row(0))
                                }
                          }
                emit(s"""//all readers share column. vectorized """)
                emit(s"""${pre} ${quote(sym)} = ${bram_name}.connectRport(new DFEVectorType<DFEVar>(${addr0(0)}.getType(), ${inds.length}).newInstance(this, Arrays.asList(${addr0.map(quote).mkString(",")})), ${quote(addr1)}); //7""")
              } else if (quote(a(0)) == quote(b(0))) {
                var addr0 = ""
                val addr1 = inds.map { row =>
                              row.length match {
                                case 1 =>
                                  addr0 = quote(1) // Assume all are from same row?
                                  quote(row(0))
                                case _ =>
                                  addr0 = quote(row(0)) // Assume all are from same row?
                                  quote(row(1))
                                }
                          }

                emit(s"""//all readers share row. vectorized""")
                emit(s"""${pre} ${quote(sym)} = ${bram_name}.connectRport(${quote(addr0)}, new DFEVectorType<DFEVar>(${quote(addr1(0))}.getType(), ${inds.length}).newInstance(this, Arrays.asList(${addr1.map(quote).mkString(",")}))); //8""")
              } else {
                throw new Exception("Cannot handle this parallel reader because not exclusively row-wise or column-wise access!")
              }
            }
          case _ =>
            throw new Exception("Cannot handle more than 2D bram!")
      }

    }

    brams += bram.asInstanceOf[Sym[BRAM[Any]]]
    // Handle if loading a composite type
    //n.compositeValues.zipWithIndex.map { t =>
    //  val v = t._1
    //  val idx = t._2
    //  visitNode(v)
    //  emit(s"""${quote(v)} <== ${quote(sym)}[$idx];""")
    //}
    emitComment("} Bram_load")
  }

  def bramStore(sym: Sym[Any], bram_in: Exp[BRAM[Any]], addr: Exp[Any], value: Exp[Any]) {
    emitComment("Bram_store {")
    val bram = if (bram_redloop_map.contains(bram_in)) {bram_redloop_map(bram_in)} else {bram_in}
    val dataStr = quote(value)
    val dups = duplicatesOf(bram)
    val writers = writersOf(bram)
    val find_id = writers.map{case (_, _, s) => s}
    val i = find_id.indexOf(sym)
    val this_writer = writers(i)._1
    val inds = parIndicesOf(writers(i)._3)
    val num_dims = dimsOf(bram).length



    if (isAccum(bram)) {

      val offsetStr = quote(writersOf(bram).head._1) + "_offset"
      val parentPipe = parentOf(bram).getOrElse(throw new Exception(s"Bram ${quote(bram)} does not have a parent!"))
      val parentCtr = parentPipe match {
        case Def(EatReflect(d)) => d match {
          case d:Pipe_fold[_,_] => d.cchain
          case d:Pipe_foreach => d.cchain
          case d:ParPipeReduce[_,_] => d.cc
          case d:ParPipeForeach => d.cc
          case _ => throw new Exception(s"Unknown parent ${d}!")
        }
        case p => throw new Exception(s"Unknown parent type ${p}!")
      }
      if (dups.length == 1) {
        if (writers.length == 1) {
          emit(s"""${quote(bram)}.connectWport(stream.offset(${quote(addr)}, -$offsetStr),
            stream.offset($dataStr, -$offsetStr), stream.offset(${quote(parentPipe)}_datapath_en, -1) & stream.offset(${quote(parentPipe)}_datapath_en, -$offsetStr)); //1""") 
        } else {
          val bank_num = i
          emit(s"""${quote(bram)}.connectBankWport(${bank_num}, stream.offset(${quote(addr)}, -$offsetStr),
            stream.offset($dataStr, -$offsetStr), stream.offset(${quote(parentPipe)}_datapath_en, -1) & stream.offset(${quote(parentPipe)}_datapath_en, -$offsetStr)); //2""")
        }
      } else {
        if (writers.length == 1) {
          dups.zipWithIndex.foreach {case (dd, ii) =>
            // I KNOW THERE ARE MORE CASES TO ADD IN THIS ACCUM SECTION!!!!
            num_dims match {
              case 1 =>
                emit(s"""${quote(bram)}_${ii}.connectWport(stream.offset(${quote(addr)}, -$offsetStr),
                  stream.offset($dataStr, -$offsetStr), stream.offset(${quote(this_writer)}_done /* Not sure why this sig works, but it does */, -$offsetStr)); //3""")
              case _ =>
                emit(s"""${quote(bram)}_${ii}.connectWport(stream.offset(${quote(inds(0)(0))}, -$offsetStr), stream.offset(${quote(inds(0)(1))}, -$offsetStr),
                  stream.offset($dataStr, -$offsetStr), stream.offset(${quote(this_writer)}_done /* Not sure why this sig works, but it does */, -$offsetStr)); //4""")
            }
          }
        } else {
          val bank_num = i
          dups.zipWithIndex.foreach {case (dd, ii) =>
            emit(s"""${quote(bram)}_${ii}.connectBankWport(${bank_num}, stream.offset(${quote(addr)}, -$offsetStr),
              stream.offset($dataStr, -$offsetStr), stream.offset(${quote(this_writer)}_done /* Not sure why this sig works, but it does */, -$offsetStr)); //5""") 
          }
        }
      }
    } else { // Not accum
      // [TODO] Raghu: Current assumption is that this always returns the parent
      // writing to the BRAM. Is this always true? Confirm
      if (isDummy(bram)) {
        emit(s"""${quote(bram)}.connectWport(${quote(addr)}, ${dataStr}, ${quote(this_writer)}_datapath_en); //6""")
      } else {
        inds.length match {
          case 0 =>
            throw new Exception("What?!")
          case 1 =>
            if (num_dims == 1) {
              if (dups.length == 1) {
                emit(s"""${quote(bram)}.connectWport(${quote(addr)}, ${dataStr}, ${quote(this_writer)}_datapath_en); //7""") 
              } else {
                dups.zipWithIndex.foreach {case (dd, ii) =>
                  emit(s"""${quote(bram)}_${ii}.connectWport(${quote(addr)}, ${dataStr}, ${quote(this_writer)}_datapath_en); //8""")
                }
              }
            } else {
              val addrs = inds(0)
              if (dups.length == 1) {
                emit(s"""${quote(bram)}.connectWport(${quote(addrs(0))}, ${quote(addrs(1))}, ${dataStr}, ${quote(this_writer)}_datapath_en); //9""")
              } else {
                dups.zipWithIndex.foreach {case (dd, ii) =>
                  emit(s"""${quote(bram)}_${ii}.connectWport(${quote(addrs(0))}, ${quote(addrs(1))}, ${dataStr}, ${quote(this_writer)}_datapath_en); //10""")
                }
              }              
            }
          case _ =>
            val a = inds(0)
            val b = inds(1)
            a.length match {
              case 1 => 
              if (dups.length == 1) {
                emit(s"""${quote(bram)}.connectWport(${quote(addr)}, ${quote(value)}, ${quote(this_writer)}_datapath_en); //11""")                
              } else {
                dups.zipWithIndex.foreach {case (dd, ii) => 
                  emit(s"""${quote(bram)}_${ii}.connectWport(${quote(addr)}, ${quote(value)}, ${quote(this_writer)}_datapath_en); //11""")                
                }
              }
              case _ =>
                if (quote(a(1)) == quote(b(1))) { // ugly hack
                  var addr1 = ""
                  val addr0 = inds.map {
                    case List(row, col) =>
                      addr1 = quote(col) 
                      quote(row)
                  }
                  emit(s"""// all have same column.  """)
                  if (dups.length == 1) {
                    emit(s"""${quote(bram)}.connectWport(new DFEVectorType<DFEVar>(${addr0(0)}.getType(), ${inds.length}).newInstance(this, Arrays.asList(${addr0.mkString(",")})), ${addr1},
                    ${dataStr}, ${quote(this_writer)}_datapath_en); //12""")
                  } else {
                    dups.zipWithIndex.foreach {case (dd, ii) => 
                      emit(s"""${quote(bram)}_${ii}.connectWport(new DFEVectorType<DFEVar>(${addr1(0)}.getType(), ${inds.length}).newInstance(this, Arrays.asList(${addr1.mkString(",")})), ${addr1}, 
                      ${dataStr}, ${quote(this_writer)}_datapath_en); //13""") 
                    }
                  }

                } else {
                  var addr0 = ""
                  val addr1 = inds.map {
                    case List(row, col) =>
                      addr0 = quote(row) // Assume all are from same row?
                      quote(col)
                  }
                  emit(s"""// all have same row.  DFEVector<DFEVar> ${addr1(0)}_vectorized = new DFEVectorType<DFEVar>(${addr1(0)}.getType(), ${inds.length}).newInstance(this, Arrays.asList(${addr1.mkString(",")}));""")
                  if (dups.length == 1) {
                    emit(s"""${quote(bram)}.connectWport(${addr0}, new DFEVectorType<DFEVar>(${addr1(0)}.getType(), ${inds.length}).newInstance(this, Arrays.asList(${addr1.mkString(",")})), 
                    ${dataStr}, ${quote(this_writer)}_datapath_en); //14""")
                  } else {
                    dups.zipWithIndex.foreach {case (dd, ii) => 
                      emit(s"""${quote(bram)}_${ii}.connectWport(${addr0}, new DFEVectorType<DFEVar>(${addr1(0)}.getType(), ${inds.length}).newInstance(this, Arrays.asList(${addr1.mkString(",")})), 
                      ${dataStr}, ${quote(this_writer)}_datapath_en); // 15""") 
                    }
                  }
                }
            }

        }

      }
    }
    emitComment("} Bram_store")
  }

  override def emitNode(sym: Sym[Any], rhs: Def[Any]) = rhs match {
    case Offchip_new(size) =>
        emitComment(s""" Offchip_new(${quote(size)}) {""")
        alwaysGen { emit(s"""int ${quote(sym)} = ${getNextLMemAddr()};""") }
        emitComment(s""" Offchip_new(${quote(size)}) }""")

    case Offchip_load_cmd(mem, fifo, ofs, len, par) =>
      emit(s"""// ${quote(sym)}: Offchip_load_cmd(${quote(mem)},${quote(fifo)}, ${quote(ofs)}, ${quote(len)}, ${quote(par)})""")
      emit(s"""MemoryCmdGenLib ${quote(sym)} = new MemoryCmdGenLib(
          this,
          ${quote(sym)}_en, ${quote(sym)}_done,
          ${quote(mem)}, ${quote(ofs)},
          "${quote(mem)}_${quote(sym)}_in",
          ${quote(len)},
          ${quote(fifo)}_readEn, ${quote(fifo)}_rdata);""")
      emit(s"""${quote(fifo)}_writeEn <== ${quote(sym)}_en;""")
      emit(s"""${quote(fifo)}_wdata <== ${quote(fifo)}_rdata;""")

    case Offchip_store_cmd(mem, fifo, ofs, len, par) =>
      emit(s"""// ${quote(sym)}: Offchip_store_cmd(${quote(mem)},${quote(fifo)}, ${quote(ofs)}, ${quote(len)}, ${quote(par)})""")
      emit(s"""MemoryCmdStLib ${quote(sym)} = new MemoryCmdStLib(
          this,
          ${quote(sym)}_en, ${quote(sym)}_done,
          ${quote(mem)}, ${quote(ofs)},
          "${quote(mem)}_${quote(sym)}_out",
          ${quote(len)},
          ${quote(fifo)}_writeEn, ${quote(fifo)}_wdata);""")
      emit(s"""${quote(fifo)}_readEn <== ${quote(sym)}_en;""")

//      emitComment("Offchip store from fifo")

    case Reg_new(init) =>
      if (!bram_redloop_map.contains(sym)) {
        withStream(baseStream) {
          emitComment("Reg_new {")
          val ts = tpstr(parOf(sym))(sym.tp.typeArguments.head, implicitly[SourceContext])
          val duplicates = duplicatesOf(sym)
          val rstVal = resetValue(sym.asInstanceOf[Sym[Reg[Any]]]) match {
            case ConstFix(rv) => rv
            case ConstFlt(rv) => rv
          }
          duplicates.zipWithIndex.foreach { case (d, i) =>
            regType(sym) match {
              case Regular =>
                (reduceType(sym), i) match {
                  case (Some(fps: ReduceFunction), 0) =>
                    // Assume only duplicate 1 needs reg_lib if this is reducetype
                  case _ =>
                    val parent = if (parentOf(sym).isEmpty) "top" else quote(parentOf(sym).get) //TODO
                    if (d.depth > 1) {
                      emit(s"""DblBufReg ${quote(sym)}_${i}_lib = new DblBufReg(this, $ts, "${quote(sym)}_${i}", ${parOf(sym)}, new Bits(${quote(ts)}.getTotalBits(), $rstVal));""")
                      val readstr = if (parOf(sym)>1) "readv" else "read"
                      emit(s"""${maxJPre(sym)} ${quote(sym)}_$i = ${quote(sym)}_${i}_lib.${readstr}();""")
                      emit(s"""${maxJPre(sym)} ${quote(sym)}_${i}_delayed = ${ts}.newInstance(this);""")
                      regs += ((sym.asInstanceOf[Sym[Reg[Any]]], i))
                    } else {
                      emit(s"""DelayLib ${quote(sym)}_${i}_lib = new DelayLib(this, ${quote(ts)}, new Bits(${quote(ts)}.getTotalBits(), $rstVal));""")
                      val readstr = if (parOf(sym) > 1) "readv" else "read"
                      emit(s"""${maxJPre(sym)} ${quote(sym)}_$i = ${quote(sym)}_${i}_lib.${readstr}();""")
                      emit(s"""${maxJPre(sym)} ${quote(sym)}_${i}_delayed = ${ts}.newInstance(this);""")
                    }
                }
              case _ => throw new Exception(s"""Unknown reg type ${regType(sym)}""")
            }
          }
          emitComment("Reg_new }")
        }
      }

    case Argin_new(init) =>
      val ts = tpstr(parOf(sym))(sym.tp.typeArguments.head, implicitly[SourceContext])
            emit(s"""DFEVar ${quote(sym)} = io.scalarInput("${quote(sym)}", $ts );""")
            if (argToExp.contains(sym.asInstanceOf[Sym[Reg[Any]]])) {
              emit(s"""${quote(argToExp(sym.asInstanceOf[Sym[Reg[Any]]]))} <== ${quote(sym)};""")
            }

    case Argout_new(init) => //emitted in reg_write

    case e@Reg_read(reg) =>
      if (! bram_redloop_map.contains(reg)) { // Hack to check if this is reduction read
        val pre = maxJPre(sym)
        val regIdx = if (readersOf(reg).map{_._3}.indexOf(sym) > duplicatesOf(reg).length - 1) {
          duplicatesOf(reg).length - 1
        } else {
          readersOf(reg).map{_._3}.indexOf(sym)
        }
        // val regIdx = instanceIndexOf(sym, reg)
        val regStr = regType(reg) match {
          case Regular =>
            val suffix = if (!controlNodeStack.isEmpty) {
              val Def(EatReflect(curPipe)) = controlNodeStack.top
              curPipe match {
                  case n: ParPipeReduce[_,_] => if (n.acc == reg) "_delayed" else ""   // Use the delayed (stream-offset) version inside reduce
                  case Unit_pipe(_) => if (isAccum(reg) && writtenIn(controlNodeStack.top).contains(reg)) "_delayed" else ""   // Use the delayed (stream-offset) version inside reduce
                  case _ => ""
              }
            } else {
              ""
            }
            quote(reg) + s"_${regIdx}" + suffix
          case _ =>
            quote(reg)
        }
        regType(reg) match {
          case Regular =>
            regIdx match {
              case -1 =>
                emit(s"""//Cannot write ${quote(sym)} = $regStr""")
              case _ =>
                if (!(isAccum(reg) & instanceIndexOf(sym, reg) == 0)) {emit(s"""$pre ${quote(sym)} = $regStr;""")}
            }
          case _ =>
            emit(s"""$pre ${quote(sym)} = $regStr;""")        
        }
        } else {
          emit(s"""// ${quote(sym)} is just a register read""")
        }

    case e@Reg_write(pre_reg, value) =>
      val reg = aliasOf(pre_reg)
      if (!bram_redloop_map.contains(reg)) {
        emitComment("Reg_write {")
        if (writersOf(reg).isEmpty)
            throw new Exception(s"Reg ${quote(reg)} is not written by a controller, which is not supported at the moment")
        val writer = writersOf(reg).head._1  // Regs have unique writer which also drives reset
        val ts = tpstr(parOf(reg))(reg.tp.typeArguments.head, implicitly[SourceContext])
        val duplicates = duplicatesOf(reg)
        val numDuplicates = duplicatesOf(reg).length
        regType(reg) match {
          case ArgumentOut =>
            val controlStr = if (parentOf(reg).isEmpty) s"top_done" else quote(parentOf(reg).get) + "_done"
            emit(s"""io.scalarOutput("${quote(reg)}", ${quote(value)}, $ts, $controlStr);""")
          case _ =>
            if (isAccum(reg)) {
              regType(reg) match {
                case Regular =>
                  val rstStr = quote(parentOf(reg).get) + "_rst_en"
                  writer match {
                    case p@Def(EatReflect(pipe:Pipe_foreach)) => 
                      throw new Exception(s"How do you have a foreach with an accumulator?")
                    case p@Def(EatReflect(pipe:Pipe_fold[_,_])) => 
                      emit(s"// Pipe_fold accum")
                      val enstr = styleOf(p) match {
                        case InnerPipe => emit(s"""DFEVar ${quote(reg)}_en = ${quote(p)}_datapath_en & ${quote(writer)}_redLoop_done;""")
                        case _ => emit(s"""DFEVar ${quote(reg)}_en = ${quote(p)}_en & ${quote(writer)}_redLoop_done;""")
                      }
                      reduceType(reg) match {
                        case Some(fps: ReduceFunction) => fps match {
                          case FixPtSum =>
                            emit(s"""Accumulator.Params ${quote(reg)}_accParams = Reductions.accumulator.makeAccumulatorConfig($ts).withClear(${rstStr}).withEnable(${quote(reg)}_en);""")
                            emit(s"""DFEVar ${quote(reg)}_hold = Reductions.accumulator.makeAccumulator(${quote(value)}, ${quote(reg)}_accParams);""")
                            emit(s"""DFEVar ${quote(reg)} = ${quote(reg)}_hold;""")
                          case FltPtSum =>
                            emit(s"""DFEVar ${quote(reg)} = FloatingPointAccumulator.accumulateWithReset(${quote(value)}, ${quote(reg)}_en, $rstStr, true);""")
                        }
                        emit(s"""${quote(reg)}_1_lib.write(${quote(reg)}, ${quote(writer)}_done, constant.var(false));""")
                      }
                    case p@Def(EatReflect(pipe:ParPipeReduce[_,_])) => 
                      emit(s"// ParPipeReduce accum")
                      val enstr = styleOf(p) match {
                        case InnerPipe => emit(s"""DFEVar ${quote(reg)}_en = ${quote(p)}_datapath_en & ${quote(writer)}_redLoop_done;""")
                        case _ => emit(s"""DFEVar ${quote(reg)}_en = ${quote(p)}_en & ${quote(writer)}_redLoop_done;""")
                      }
                      reduceType(reg) match {
                        case Some(fps: ReduceFunction) => fps match {
                          case FixPtSum =>
                            emit(s"""Accumulator.Params ${quote(reg)}_accParams = Reductions.accumulator.makeAccumulatorConfig($ts).withClear(${rstStr}).withEnable(${quote(reg)}_en);""")
                            emit(s"""DFEVar ${quote(reg)}_hold = Reductions.accumulator.makeAccumulator(${quote(value)}, ${quote(reg)}_accParams);""")
                            emit(s"""DFEVar ${quote(reg)} = ${quote(reg)}_hold;""")
                          case FltPtSum =>
                            emit(s"""DFEVar ${quote(reg)} = FloatingPointAccumulator.accumulateWithReset(${quote(value)}, ${quote(reg)}_en, $rstStr, true);""")
                        }
                        emit(s"""${quote(reg)}_1_lib.write(${quote(reg)}, ${quote(writer)}_done, constant.var(false));""")
                      }
                    case p@Def(EatReflect(Unit_pipe(func))) =>
                      emit(s"// Unit_pipe accum")
                      val enstr = styleOf(p) match {
                        case InnerPipe => emit(s"""DFEVar ${quote(reg)}_en = ${quote(writer)}_rst_en;""")
                        case _ => emit(s"""DFEVar ${quote(reg)}_en = ${quote(p)}_en & ${quote(writer)}_redLoop_done;""")
                      }
                      Console.println(s"reg $reg in $p has no reduceType")
                      reduceType(reg) match {
                        case Some(fps: ReduceFunction) => fps match {
                          case FixPtSum =>
                            emit(s"""Accumulator.Params ${quote(reg)}_accParams = Reductions.accumulator.makeAccumulatorConfig($ts).withClear(${rstStr} & constant.var(false) /* TODO: Not sure if disabling rst is correct */).withEnable(${quote(reg)}_en);""")
                            emit(s"""DFEVar ${quote(reg)}_hold = Reductions.accumulator.makeAccumulator(${quote(value)}, ${quote(reg)}_accParams);""")
                            emit(s"""DFEVar ${quote(reg)} = ${quote(reg)}_hold;""")
                          case FltPtSum =>
                            emit(s"""DFEVar ${quote(reg)} = FloatingPointAccumulator.accumulateWithReset(${quote(value)}, ${quote(reg)}_en, $rstStr & constant.var(false) /* TODO: Not sure if disabling rst is correct */, true);""")
                          case _ =>
                            throw new Exception(s"Reduce type of reg $reg, pipe $p, not implemented!")
                        }
                        emit(s"""${quote(reg)}_1_lib.write(${quote(reg)}, ${quote(writer)}_done, constant.var(false));""")
                      }

                    case _ =>
                        emit(s"DFEVar ${quote(reg)}_en = constant.var(true)")
                  }
                case ArgumentIn => new Exception("Cannot write to ArgIn " + quote(reg) + "!")
                case ArgumentOut => throw new Exception(s"""ArgOut (${quote(reg)}) cannot be used as an accumulator!""")
              }
            } else { // Non-accumulator registers
              (0 until numDuplicates) foreach { ii =>
                val regname = s"${quote(reg)}_${ii}"
                regType(reg) match {
                  case ArgumentIn => new Exception("Cannot write to ArgIn " + quote(reg) + "!")
                  case Regular =>
                    val rstStr = quote(parentOf(reg).get) + "_rst_en"
  //                  emit(s"""${regname}_lib.write(${quote(value)}, constant.var(true), $rstStr);""")
                    if (duplicates(ii).depth > 1) {
                      emit(s"""${regname}_lib.write(${quote(value)}, ${quote(writer)}_done, constant.var(false));""")
                    } else {
                      // Using an enable signal instead of "always true" is causing an illegal loop.
                      // Using a reset signal instead of "always false" is causing an illegal loop.
                      // These signals don't matter for pass-through registers anyways.
                      emit(s"""${regname}_lib.write(${quote(value)}, constant.var(true), constant.var(false));""")
                    }
                }
              }
            }
        }
        emitComment(s"} Reg_write // regType ${regType(reg)}, numDuplicates = $numDuplicates")
      }

    case Bram_new(size, zero) =>
      withStream(baseStream) {
        if (!bram_redloop_map.contains(sym)) { // Only emit for non-bound syms
          emitComment("Bram_new {")
          val ts = tpstr(parOf(sym))(sym.tp.typeArguments.head, implicitly[SourceContext])
          //TODO: does templete assume bram has 2 dimension?
          val dims = dimsOf(sym)
          val Def(d0) = dims(0)
          val sizes = dims.map { case dim => 
            bound(dim).get.toInt
          }
          val size0 = sizes(0) 
          val size1 = sizes.size match {
            case 1 => 1
            case 2 => sizes(1) 
            case _ => 1
          }
          val dups = duplicatesOf(sym)
          dups.length match {
            case 1 =>
              val banks = {
                val bnks = dups(0).banking.map { a =>
                  a match {
                    case DiagonalBanking(_, banks) => banks
                    case StridedBanking(_, banks) => banks
                    case _ => 1
                    }}
                dups(0).banking.length match {
                  case 1 => bnks(0)
                  case 2 => bnks.mkString("new int[] {", ",", "}")
                  case _ => throw new Exception(s"Can't handle ${dups(0).banking.length}-D memory!")
                }
              }
              val strides = {
                val strds = dups(0).banking.map { a =>
                  a match {
                    case DiagonalBanking(strides, _) => throw new Exception(s"Can't handle Diagonal banking yet")
                    case StridedBanking(stride, _) => stride
                    case _ => 1
                    }}
                dups(0).banking.length match {
                  case 1 => strds(0)
                  case 2 => strds.mkString("new int[] {", ",", "}")
                  case _ => throw new Exception(s"Can't handle ${dups(0).banking.length}-D memory!")
                }
              }
              if (isDblBuf(sym)) { // TODO: Are these three actually mutually exclusive?
                    emit(s"""SMIO ${quote(sym)}_sm = addStateMachine("${quote(sym)}_sm", new ${quote(sym)}_DblBufSM(this));""")
                    emit(s"""DblBufKernelLib ${quote(sym)} = new DblBufKernelLib(this, ${quote(sym)}_sm,
                      ${quote(size0)}, ${quote(size1)}, $ts, ${banks}, ${strides}, ${readersOf(sym).size});""")
              } else if (isDummy(sym)) {
                emit(s"""DummyMemLib ${quote(sym)} = new DummyMemLib(this, ${ts}, ${banks}); //dummymem""") 
              } else {
                emit(s"""BramLib ${quote(sym)} = new BramLib(this, ${quote(size0)}, ${quote(size1)}, ${ts}, /*banks*/ ${banks}, /* stride */ ${strides});""") // [TODO] Raghu: Stride from metadata
              }
            case _ => // multiple readers
              dups.zipWithIndex.foreach { case (r, i) =>
                val banks = {
                  val bnks = r.banking.map { a =>
                    a match {
                      case DiagonalBanking(_, banks) => banks
                      case StridedBanking(_, banks) => banks
                      case _ => 1
                      }}
                  r.banking.length match {
                    case 1 => bnks(0)
                    case 2 => bnks.mkString("new int[] {", ",", "}")
                    case _ => throw new Exception(s"Can't handle ${dups(0).banking.length}-D memory!")
                  }
                }
                val strides = {
                  val strds = r.banking.map { a =>
                    a match {
                      case DiagonalBanking(strides, _) => throw new Exception(s"Can't handle Diagonal banking yet")
                      case StridedBanking(stride, _) => stride
                      case _ => 1
                      }}
                  r.banking.length match {
                    case 1 => strds(0)
                    case 2 => strds.mkString("new int[] {", ",", "}")
                    case _ => throw new Exception(s"Can't handle ${dups(0).banking.length}-D memory!")
                  }
                }

                if (isDummy(sym)) {
                  emit(s"""DummyMemLib ${quote(sym)}_${i} = new DummyMemLib(this, ${ts}, ${banks}); //dummymem""") 
                } else {
                  if (r.depth == 1) {
                    emit(s"""BramLib ${quote(sym)}_${i} = new BramLib(this, ${quote(size0)}, ${quote(size1)}, ${ts}, /*banks*/ ${banks}, /* stride */ ${strides});""") // [TODO] Raghu: Stride from metadata
                  } else if (r.depth == 2) {
                    val countlist = readersOf(sym)
                    val numReaders_for_this_duplicate = countlist.map{q => q}.filter{ q => (instanceIndexOf(q._3, sym) == i)}.length

                    emit(s"""SMIO ${quote(sym)}_${i}_sm = addStateMachine("${quote(sym)}_${i}_sm", new ${quote(sym)}_${i}_DblBufSM(this));""")
                    emit(s"""DblBufKernelLib ${quote(sym)}_${i} = new DblBufKernelLib(this, ${quote(sym)}_${i}_sm,
                      ${quote(size0)}, ${quote(size1)}, $ts, ${banks}, ${strides}, ${numReaders_for_this_duplicate});""")
                  }
                }
              }

          }
          emitComment("} Bram_new")
        }
      }

    case Bram_load(bram, addr) =>
      bramLoad(sym, bram, addr)

    case Par_bram_load(bram, addr) =>
      bramLoad(sym, bram, addr, true)

    case Bram_store(bram, addr, value) =>
      sym match {
        case Def(_) => // weed out mysterious Bram bound syms that pretend to be writers 
          bramStore(sym, bram, addr, value)
        case _ =>
      }

    case Par_bram_store(bram, addr, value) =>
      sym match {
        case Def(_) => // weed out mysterious Bram bound syms that pretend to be writers  
          bramStore(sym, bram, addr, value)
        case _ =>
      }

    case Fifo_new(size, zero) =>  // FIFO is always parallel
      val duplicates = duplicatesOf(sym)
      if (duplicates.size != 1) throw new Exception(s"More than 1 duplicates: $duplicates. Don't know how to handle.")
      if (duplicates.head.banking.size != 1) throw new Exception(s"More than 1 banking dimension: Don't know how to handle.")
      val par = duplicates.head.banking.head.banks
      val ts = tpstr(1)(sym.tp.typeArguments.head, implicitly[SourceContext])
      emit(s"""// FIFO ${quote(sym)} = Fifo_new[$ts](${quote(size)}, ${quote(zero)});""")
      emit(s"""DFEVector<DFEVar> ${quote(sym)}_rdata = new DFEVectorType<DFEVar>($ts, $par).newInstance(this);""")
      emit(s"""DFEVector<DFEVar> ${quote(sym)}_wdata = new DFEVectorType<DFEVar>($ts, $par).newInstance(this);""")
      emit(s"""DFEVar ${quote(sym)}_readEn = dfeBool().newInstance(this);""")
      emit(s"""DFEVar ${quote(sym)}_writeEn = dfeBool().newInstance(this);""")

    case Par_push_fifo(fifo, value, en, shuffle) =>
      emit(s"""// Par_push_fifo(${quote(fifo)}, ${quote(value)}, ${quote(en)}, ${quote(shuffle)});""")
      val writer = quote(writersOf(fifo).head._1)  // Not using 'en' or 'shuffle'
      emit(s"""${quote(fifo)}_writeEn <== ${writer}_ctr_en;""")
      emit(s"""${quote(fifo)}_wdata <== ${quote(value)};""")


    case Par_pop_fifo(fifo, par) =>
      emit(s"""// DFEVar ${quote(sym)} = Par_pop_fifo(${quote(fifo)}, ${quote(par)});""")
      val reader = quote(readersOf(fifo).head._1)  // Assuming that each fifo has a unique reader
      emit(s"""${quote(fifo)}_readEn <== ${reader}_ctr_en;""")
      emit(s"""DFEVector<DFEVar> ${quote(sym)} = ${quote(fifo)}_rdata;""")

    case Pop_fifo(fifo) =>
      emit(s"""// DFEVar ${quote(sym)} = Par_pop_fifo(${quote(fifo)}, 1);""")
      val reader = quote(readersOf(fifo).head._1)  // Assuming that each fifo has a unique reader
      emit(s"""${quote(fifo)}_readEn <== ${reader}_ctr_en;""")
      emit(s"""DFEVar ${quote(sym)} = ${quote(fifo)}_rdata[0];""")

    case Vec_apply(vec, idx) =>
      emit(s"""DFEVar ${quote(sym)} = ${quote(vec)}[${quote(idx)}];""")

    case Vector_from_list(elems) =>
      val ts = tpstr(1)(elems(0).tp, implicitly[SourceContext])
      emit(s"""DFEVector<DFEVar> ${quote(sym)} = new DFEVectorType<DFEVar>($ts, ${elems.size}).newInstance(this, Arrays.asList(${elems.map(quote).mkString(",")}));""")

    case _ => super.emitNode(sym, rhs)
  }

}
