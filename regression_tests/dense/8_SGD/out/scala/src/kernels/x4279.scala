package generated.scala
//activation record for thin loop
final class activation_x4279 {
var left_act: activation_x4279 = _
var x4279: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x4279_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x4279 {
}
object kernel_x4279 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6:Int,x9:FixedPoint[Signed,B32,B0]): activation_x4279 = {
// a *thin* loop follows: x4279
val x4279_closure = new generated.scala.DeliteOpMultiLoop[activation_x4279] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x4279 = {
val __act: activation_x4279 = new activation_x4279()
val x58 = (loopSize).asInstanceOf[Int]
if (x58 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4243 = new Array[Array[FixedPoint[Signed,B32,B0]]](x58.toInt)
__act.x4279_data = x4243
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4279,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x4279]): activation_x4279 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x4279 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x4279 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4279): activation_x4279 = {
val act: activation_x4279 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4279,start:Long,end:Long): activation_x4279 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x4279 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4279,x7:Int,isEmpty:Boolean): activation_x4279 = {
if (!isEmpty) {
process(resourceInfo,__act,x7)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4279,x7:Int): Unit = {
def x4241_thin = {
// a *thin* loop follows: x4241
var x14: Int = x6
if (x14 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4205 = new Array[FixedPoint[Signed,B32,B0]](x14.toInt)
val x4241_data: Array[FixedPoint[Signed,B32,B0]] = x4205
var x4241_size: Int = 0
var x4241_conditionals: Int = 0
var x8: Int = 0
while (x8 < x6) {  // begin fat loop x4241
val x4203 = {
FixedPoint.randbnd[Signed,B32,B0](x9)
}
val x13 = x4203
val x12 = x4241_data
val x4209 = x12(x8.toInt) = x13
x8 = x8 + 1
} // end fat loop x4241
val x12 = x4241_data
val x4241 = x12
x4241
}
val x4241 = x4241_thin
val x57 = x4241
val x56 = __act.x4279_data
val x4247 = x56(x7.toInt) = x57
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4279,rhs:activation_x4279): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4279,lhs:activation_x4279): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4279): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4279): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4279): Unit = {
var x56: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x4279_data
__act.x4279_data = null
__act.x4279 = x56
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x4279 = {
val act: activation_x4279 = new activation_x4279
act
}

}
x4279_closure.loopStart = 0
x4279_closure.loopSize = x6
val alloc: activation_x4279 = x4279_closure.alloc(resourceInfo)
var x4279: activation_x4279 = null
if (resourceInfo.availableThreads <= 1) {
x4279 = x4279_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x4279] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x4279](x4279_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x4279_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x4279 = x4279_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x4279
}}

/**********/

