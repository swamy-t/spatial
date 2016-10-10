package generated.scala
//activation record for fat loop
final class activation_x3405 {
var left_act: activation_x3405 = _
var x3405: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x3405_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x3405 {
}
object kernel_x3405 {
def apply(resourceInfo:generated.scala.ResourceInfo,x5:Int,x4:FixedPoint[Signed,B32,B0],x8:Int): activation_x3405 = {
val x3405_closure = new generated.scala.DeliteOpMultiLoop[activation_x3405] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x5
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3405 = {
val __act: activation_x3405 = new activation_x3405()
val x58 = (loopSize).asInstanceOf[Int]
if (x58 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3369 = new Array[Array[FixedPoint[Signed,B32,B0]]](x58.toInt)
__act.x3405_data = x3369
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3405,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3405]): activation_x3405 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3405 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3405 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3405): activation_x3405 = {
val act: activation_x3405 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3405,start:Long,end:Long): activation_x3405 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3405 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3405,x6:Int,isEmpty:Boolean): activation_x3405 = {
if (!isEmpty) {
process(resourceInfo,__act,x6)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3405,x6:Int): Unit = {
val x7 = {
FixedPoint[Signed,B32,B0](x6)
}
val x11 = {
x7 * x4
}
var x15: Int = x8
if (x15 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3332 = new Array[FixedPoint[Signed,B32,B0]](x15.toInt)
val x3368_data: Array[FixedPoint[Signed,B32,B0]] = x3332
var x3368_size: Int = 0
var x3368_conditionals: Int = 0
var x9: Int = 0
while (x9 < x8) {  // begin fat loop x3368
val x10 = {
FixedPoint[Signed,B32,B0](x9)
}
val x12 = {
x11 + x10
}
val x14 = x12
val x13 = x3368_data
val x3336 = x13(x9.toInt) = x14
x9 = x9 + 1
} // end fat loop x3368
val x13 = x3368_data
val x3368 = x13
val x57 = x3368
val x56 = __act.x3405_data
val x3373 = x56(x6.toInt) = x57
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3405,rhs:activation_x3405): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3405,lhs:activation_x3405): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3405): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3405): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3405): Unit = {
var x56: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x3405_data
__act.x3405_data = null
__act.x3405 = x56
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3405 = {
val act: activation_x3405 = new activation_x3405
act
}

}
x3405_closure.loopStart = 0
x3405_closure.loopSize = x5
val alloc: activation_x3405 = x3405_closure.alloc(resourceInfo)
var x3405: activation_x3405 = null
if (resourceInfo.availableThreads <= 1) {
x3405 = x3405_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3405] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3405](x3405_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3405_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3405 = x3405_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3405
}}

/**********/

