package generated.scala
//activation record for thin loop
final class activation_x1567 {
var left_act: activation_x1567 = _
var x1567: Array[FixedPoint[Signed,B32,B0]] = _
var x1567_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1567 {
}
object kernel_x1567 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x5:FixedPoint[Signed,B32,B0]): activation_x1567 = {
// a *thin* loop follows: x1567
val x1567_closure = new generated.scala.DeliteOpMultiLoop[activation_x1567] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1567 = {
val __act: activation_x1567 = new activation_x1567()
val x56 = (loopSize).asInstanceOf[Int]
if (x56 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1531 = new Array[FixedPoint[Signed,B32,B0]](x56.toInt)
__act.x1567_data = x1531
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1567,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1567]): activation_x1567 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1567 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1567 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1567): activation_x1567 = {
val act: activation_x1567 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1567,start:Long,end:Long): activation_x1567 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1567 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1567,x51:Int,isEmpty:Boolean): activation_x1567 = {
if (!isEmpty) {
process(resourceInfo,__act,x51)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1567,x51:Int): Unit = {
val x1529 = {
FixedPoint.randbnd[Signed,B32,B0](x5)
}
val x55 = x1529
val x54 = __act.x1567_data
val x1535 = x54(x51.toInt) = x55
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1567,rhs:activation_x1567): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1567,lhs:activation_x1567): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1567): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1567): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1567): Unit = {
var x54: Array[FixedPoint[Signed,B32,B0]] = __act.x1567_data
__act.x1567_data = null
__act.x1567 = x54
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1567 = {
val act: activation_x1567 = new activation_x1567
act
}

}
x1567_closure.loopStart = 0
x1567_closure.loopSize = x3
val alloc: activation_x1567 = x1567_closure.alloc(resourceInfo)
var x1567: activation_x1567 = null
if (resourceInfo.availableThreads <= 1) {
x1567 = x1567_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1567] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1567](x1567_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1567_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1567 = x1567_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1567
}}

/**********/

