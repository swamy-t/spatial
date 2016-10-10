package generated.scala
//activation record for thin loop
final class activation_x2448 {
var left_act: activation_x2448 = _
var x2448: Array[Array[FloatPoint[B24,B8]]] = _
var x2448_data: Array[Array[FloatPoint[B24,B8]]] = _
}
object activation_x2448 {
}
object kernel_x2448 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x8:FloatPoint[B24,B8],x6:Int): activation_x2448 = {
// a *thin* loop follows: x2448
val x2448_closure = new generated.scala.DeliteOpMultiLoop[activation_x2448] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2448 = {
val __act: activation_x2448 = new activation_x2448()
val x58 = (loopSize).asInstanceOf[Int]
if (x58 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2412 = new Array[Array[FloatPoint[B24,B8]]](x58.toInt)
__act.x2448_data = x2412
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2448,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2448]): activation_x2448 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2448 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2448 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2448): activation_x2448 = {
val act: activation_x2448 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2448,start:Long,end:Long): activation_x2448 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2448 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2448,x4:Int,isEmpty:Boolean): activation_x2448 = {
if (!isEmpty) {
process(resourceInfo,__act,x4)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2448,x4:Int): Unit = {
def x2410_thin = {
// a *thin* loop follows: x2410
var x14: Int = x6
if (x14 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2374 = new Array[FloatPoint[B24,B8]](x14.toInt)
val x2410_data: Array[FloatPoint[B24,B8]] = x2374
var x2410_size: Int = 0
var x2410_conditionals: Int = 0
var x7: Int = 0
while (x7 < x6) {  // begin fat loop x2410
val x2371 = {
FloatPoint.rand[B24,B8]
}
val x2372 = {
x2371 * x8
}
val x13 = x2372
val x12 = x2410_data
val x2378 = x12(x7.toInt) = x13
x7 = x7 + 1
} // end fat loop x2410
val x12 = x2410_data
val x2410 = x12
x2410
}
val x2410 = x2410_thin
val x57 = x2410
val x56 = __act.x2448_data
val x2416 = x56(x4.toInt) = x57
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2448,rhs:activation_x2448): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2448,lhs:activation_x2448): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2448): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2448): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2448): Unit = {
var x56: Array[Array[FloatPoint[B24,B8]]] = __act.x2448_data
__act.x2448_data = null
__act.x2448 = x56
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2448 = {
val act: activation_x2448 = new activation_x2448
act
}

}
x2448_closure.loopStart = 0
x2448_closure.loopSize = x3
val alloc: activation_x2448 = x2448_closure.alloc(resourceInfo)
var x2448: activation_x2448 = null
if (resourceInfo.availableThreads <= 1) {
x2448 = x2448_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2448] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2448](x2448_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2448_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2448 = x2448_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2448
}}

/**********/

