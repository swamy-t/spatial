package generated.scala
//activation record for thin loop
final class activation_x2631 {
var left_act: activation_x2631 = _
var x2631: Array[FixedPoint[Unsign,B32,B0]] = _
var x2631_data: Array[FixedPoint[Unsign,B32,B0]] = _
}
object activation_x2631 {
}
object kernel_x2631 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x5:FixedPoint[Unsign,B32,B0],x7:FixedPoint[Unsign,B32,B0]): activation_x2631 = {
// a *thin* loop follows: x2631
val x2631_closure = new generated.scala.DeliteOpMultiLoop[activation_x2631] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2631 = {
val __act: activation_x2631 = new activation_x2631()
val x12 = (loopSize).asInstanceOf[Int]
if (x12 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2595 = new Array[FixedPoint[Unsign,B32,B0]](x12.toInt)
__act.x2631_data = x2595
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2631,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2631]): activation_x2631 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2631 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2631 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2631): activation_x2631 = {
val act: activation_x2631 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2631,start:Long,end:Long): activation_x2631 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2631 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2631,x4:Int,isEmpty:Boolean): activation_x2631 = {
if (!isEmpty) {
process(resourceInfo,__act,x4)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2631,x4:Int): Unit = {
val x2592 = {
FixedPoint.randbnd[Unsign,B32,B0](x5)
}
val x2593 = {
x2592 + x7
}
val x11 = x2593
val x10 = __act.x2631_data
val x2599 = x10(x4.toInt) = x11
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2631,rhs:activation_x2631): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2631,lhs:activation_x2631): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2631): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2631): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2631): Unit = {
var x10: Array[FixedPoint[Unsign,B32,B0]] = __act.x2631_data
__act.x2631_data = null
__act.x2631 = x10
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2631 = {
val act: activation_x2631 = new activation_x2631
act
}

}
x2631_closure.loopStart = 0
x2631_closure.loopSize = x3
val alloc: activation_x2631 = x2631_closure.alloc(resourceInfo)
var x2631: activation_x2631 = null
if (resourceInfo.availableThreads <= 1) {
x2631 = x2631_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2631] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2631](x2631_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2631_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2631 = x2631_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2631
}}

/**********/

