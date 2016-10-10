package generated.scala
//activation record for thin loop
final class activation_x2670 {
var left_act: activation_x2670 = _
var x2670: Array[FixedPoint[Unsign,B32,B0]] = _
var x2670_data: Array[FixedPoint[Unsign,B32,B0]] = _
}
object activation_x2670 {
}
object kernel_x2670 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x54:FixedPoint[Unsign,B32,B0]): activation_x2670 = {
// a *thin* loop follows: x2670
val x2670_closure = new generated.scala.DeliteOpMultiLoop[activation_x2670] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2670 = {
val __act: activation_x2670 = new activation_x2670()
val x59 = (loopSize).asInstanceOf[Int]
if (x59 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2634 = new Array[FixedPoint[Unsign,B32,B0]](x59.toInt)
__act.x2670_data = x2634
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2670,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2670]): activation_x2670 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2670 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2670 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2670): activation_x2670 = {
val act: activation_x2670 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2670,start:Long,end:Long): activation_x2670 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2670 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2670,x53:Int,isEmpty:Boolean): activation_x2670 = {
if (!isEmpty) {
process(resourceInfo,__act,x53)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2670,x53:Int): Unit = {
val x2632 = {
FixedPoint.randbnd[Unsign,B32,B0](x54)
}
val x58 = x2632
val x57 = __act.x2670_data
val x2638 = x57(x53.toInt) = x58
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2670,rhs:activation_x2670): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2670,lhs:activation_x2670): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2670): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2670): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2670): Unit = {
var x57: Array[FixedPoint[Unsign,B32,B0]] = __act.x2670_data
__act.x2670_data = null
__act.x2670 = x57
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2670 = {
val act: activation_x2670 = new activation_x2670
act
}

}
x2670_closure.loopStart = 0
x2670_closure.loopSize = x3
val alloc: activation_x2670 = x2670_closure.alloc(resourceInfo)
var x2670: activation_x2670 = null
if (resourceInfo.availableThreads <= 1) {
x2670 = x2670_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2670] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2670](x2670_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2670_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2670 = x2670_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2670
}}

/**********/

