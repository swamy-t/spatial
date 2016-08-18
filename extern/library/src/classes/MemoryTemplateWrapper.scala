package spatial.library.classes

import scala.annotation.unchecked.uncheckedVariance
import scala.reflect.{Manifest,RefinedManifest,SourceContext}
import scala.virtualization.lms.common.Record

import scala.collection.mutable.{HashMap, Queue}

import spatial.shared._
import spatial.shared.ops._
import spatial.library._
import spatial.library.classes._

trait MemoryTemplateWrapper extends ControllerTemplateWrapper with ExternPrimitiveWrapper {
  this: SpatialBase with SpatialClasses =>

  // Memories are all equivalent to Scala Arrays in library
  type OffChipMem[T] = Array[T]
  type BRAM[T] = Array[T]
  type FIFO[T] = Queue[T]
  type CAM[K,V] = HashMap[K,V]
  type Vector[T] = Array[T]
  type Cache[T] = Array[T]
  type Reg[T] = Array[T]
  type Pipeline = Unit
  type Indices = RecordImpl

  // Library can't definitively tell the difference between BRAM, Reg, and Cache
  def isBRAM[T:Manifest] = isSubtype(manifest[T].runtimeClass, classOf[Array[_]])
  def isFIFO[T:Manifest] = isSubtype(manifest[T].runtimeClass, classOf[Queue[_]])
  def isRegister[T:Manifest] = isSubtype(manifest[T].runtimeClass, classOf[Array[_]])
  def isCache[T:Manifest] = isSubtype(manifest[T].runtimeClass, classOf[Array[_]])
  def isCAM[T:Manifest] = isSubtype(manifest[T].runtimeClass, classOf[HashMap[_,_]])

  def offchipMemManifest[T:Manifest]: Manifest[OffChipMem[T]] = manifest[Array[T]]
  def bramManifest[T:Manifest]: Manifest[BRAM[T]] = manifest[Array[T]]
  def fifoManifest[T:Manifest]: Manifest[FIFO[T]] = manifest[Queue[T]]
  def camManifest[K:Manifest,V:Manifest]: Manifest[CAM[K,V]] = manifest[HashMap[K,V]]
  def vectorManifest[T:Manifest]: Manifest[Vector[T]] = manifest[Array[T]]
  def cacheManifest[T:Manifest]: Manifest[Cache[T]] = manifest[Array[T]]
  def regManifest[T:Manifest]: Manifest[Reg[T]] = manifest[Array[T]]
  def pipelineManifest: Manifest[Pipeline] = manifest[Unit]
  def indicesManifest: Manifest[Indices] = manifest[RecordImpl]

  def vector_from_list[T:Manifest](elems: List[Rep[T]])(implicit ctx: SourceContext): Rep[Vector[T]] = elems.toArray
}
