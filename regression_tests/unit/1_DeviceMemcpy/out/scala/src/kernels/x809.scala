package generated.scala
//activation record for fat loop
final class activation_x809 {
var left_act: activation_x809 = _
var x809: Array[Boolean] = _
var x809_data: Array[Boolean] = _
}
object activation_x809 {
}
object kernel_x809 {
def apply(resourceInfo:generated.scala.ResourceInfo,x768:Int,x753:Array[FixedPoint[Signed,B32,B0]],x745:Array[FixedPoint[Signed,B32,B0]]): activation_x809 = {
val x809_closure = new generated.scala.DeliteOpMultiLoop[activation_x809] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x768
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x809 = {
val __act: activation_x809 = new activation_x809()
val x91 = (loopSize).asInstanceOf[Int]
if (x91 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x773 = new Array[Boolean](x91.toInt)
__act.x809_data = x773
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x809,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x809]): activation_x809 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x809 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x809 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x809): activation_x809 = {
val act: activation_x809 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x809,start:Long,end:Long): activation_x809 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x809 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x809,x84:Int,isEmpty:Boolean): activation_x809 = {
if (!isEmpty) {
process(resourceInfo,__act,x84)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x809,x84:Int): Unit = {
val x769 = x753(x84.toInt)
val x770 = x745(x84.toInt)
val x771 = {
x769 == x770
}
val x90 = x771
val x89 = __act.x809_data
val x777 = x89(x84.toInt) = x90
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x809,rhs:activation_x809): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x809,lhs:activation_x809): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x809): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x809): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x809): Unit = {
var x89: Array[Boolean] = __act.x809_data
__act.x809_data = null
__act.x809 = x89
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x809 = {
val act: activation_x809 = new activation_x809
act
}

}
x809_closure.loopStart = 0
x809_closure.loopSize = x768
val alloc: activation_x809 = x809_closure.alloc(resourceInfo)
var x809: activation_x809 = null
if (resourceInfo.availableThreads <= 1) {
x809 = x809_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x809] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x809](x809_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x809_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x809 = x809_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x809
}}

/**********/

