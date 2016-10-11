package generated.scala
//activation record for thin loop
final class activation_x2488 {
var left_act: activation_x2488 = _
var x2488: Array[FloatPoint[B24,B8]] = _
var x2488_data: Array[FloatPoint[B24,B8]] = _
}
object activation_x2488 {
}
object kernel_x2488 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x8:FloatPoint[B24,B8]): activation_x2488 = {
// a *thin* loop follows: x2488
val x2488_closure = new generated.scala.DeliteOpMultiLoop[activation_x2488] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2488 = {
val __act: activation_x2488 = new activation_x2488()
val x105 = (loopSize).asInstanceOf[Int]
if (x105 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2452 = new Array[FloatPoint[B24,B8]](x105.toInt)
__act.x2488_data = x2452
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2488,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2488]): activation_x2488 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2488 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2488 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2488): activation_x2488 = {
val act: activation_x2488 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2488,start:Long,end:Long): activation_x2488 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2488 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2488,x99:Int,isEmpty:Boolean): activation_x2488 = {
if (!isEmpty) {
process(resourceInfo,__act,x99)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2488,x99:Int): Unit = {
val x2449 = {
FloatPoint.rand[B24,B8]
}
val x2450 = {
x2449 * x8
}
val x104 = x2450
val x103 = __act.x2488_data
val x2456 = x103(x99.toInt) = x104
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2488,rhs:activation_x2488): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2488,lhs:activation_x2488): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2488): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2488): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2488): Unit = {
var x103: Array[FloatPoint[B24,B8]] = __act.x2488_data
__act.x2488_data = null
__act.x2488 = x103
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2488 = {
val act: activation_x2488 = new activation_x2488
act
}

}
x2488_closure.loopStart = 0
x2488_closure.loopSize = x3
val alloc: activation_x2488 = x2488_closure.alloc(resourceInfo)
var x2488: activation_x2488 = null
if (resourceInfo.availableThreads <= 1) {
x2488 = x2488_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2488] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2488](x2488_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2488_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2488 = x2488_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2488
}}

/**********/

