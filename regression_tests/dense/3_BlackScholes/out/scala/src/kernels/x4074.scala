package generated.scala
//activation record for thin loop
final class activation_x4074 {
var left_act: activation_x4074 = _
var x4074: Array[FixedPoint[Unsign,B32,B0]] = _
var x4074_data: Array[FixedPoint[Unsign,B32,B0]] = _
}
object activation_x4074 {
}
object kernel_x4074 {
def apply(resourceInfo:generated.scala.ResourceInfo,x14:Int,x16:FixedPoint[Unsign,B32,B0]): activation_x4074 = {
// a *thin* loop follows: x4074
val x4074_closure = new generated.scala.DeliteOpMultiLoop[activation_x4074] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x14
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x4074 = {
val __act: activation_x4074 = new activation_x4074()
val x21 = (loopSize).asInstanceOf[Int]
if (x21 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4038 = new Array[FixedPoint[Unsign,B32,B0]](x21.toInt)
__act.x4074_data = x4038
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4074,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x4074]): activation_x4074 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x4074 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x4074 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4074): activation_x4074 = {
val act: activation_x4074 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4074,start:Long,end:Long): activation_x4074 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x4074 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4074,x15:Int,isEmpty:Boolean): activation_x4074 = {
if (!isEmpty) {
process(resourceInfo,__act,x15)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4074,x15:Int): Unit = {
val x4036 = {
FixedPoint.randbnd[Unsign,B32,B0](x16)
}
val x20 = x4036
val x19 = __act.x4074_data
val x4042 = x19(x15.toInt) = x20
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4074,rhs:activation_x4074): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4074,lhs:activation_x4074): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4074): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4074): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4074): Unit = {
var x19: Array[FixedPoint[Unsign,B32,B0]] = __act.x4074_data
__act.x4074_data = null
__act.x4074 = x19
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x4074 = {
val act: activation_x4074 = new activation_x4074
act
}

}
x4074_closure.loopStart = 0
x4074_closure.loopSize = x14
val alloc: activation_x4074 = x4074_closure.alloc(resourceInfo)
var x4074: activation_x4074 = null
if (resourceInfo.availableThreads <= 1) {
x4074 = x4074_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x4074] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x4074](x4074_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x4074_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x4074 = x4074_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x4074
}}

/**********/

