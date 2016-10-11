package generated.scala
//activation record for fat loop
final class activation_x2896 {
var left_act: activation_x2896 = _
var x2896: Array[Boolean] = _
var x2896_data: Array[Boolean] = _
}
object activation_x2896 {
}
object kernel_x2896 {
def apply(resourceInfo:generated.scala.ResourceInfo,x2880:Int,x2610:Array[FixedPoint[Signed,B32,B0]],x2879:Array[FixedPoint[Signed,B32,B0]]): activation_x2896 = {
val x2896_closure = new generated.scala.DeliteOpMultiLoop[activation_x2896] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x2880
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2896 = {
val __act: activation_x2896 = new activation_x2896()
val x461 = (loopSize).asInstanceOf[Int]
if (x461 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2821 = new Array[Boolean](x461.toInt)
__act.x2896_data = x2821
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2896,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2896]): activation_x2896 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2896 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2896 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2896): activation_x2896 = {
val act: activation_x2896 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2896,start:Long,end:Long): activation_x2896 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2896 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2896,x454:Int,isEmpty:Boolean): activation_x2896 = {
if (!isEmpty) {
process(resourceInfo,__act,x454)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2896,x454:Int): Unit = {
val x2817 = x2610(x454.toInt)
val x2891 = x2879(x454.toInt)
val x2892 = {
x2891 == x2817
}
val x460 = x2892
val x459 = __act.x2896_data
val x2825 = x459(x454.toInt) = x460
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2896,rhs:activation_x2896): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2896,lhs:activation_x2896): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2896): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2896): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2896): Unit = {
var x459: Array[Boolean] = __act.x2896_data
__act.x2896_data = null
__act.x2896 = x459
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2896 = {
val act: activation_x2896 = new activation_x2896
act
}

}
x2896_closure.loopStart = 0
x2896_closure.loopSize = x2880
val alloc: activation_x2896 = x2896_closure.alloc(resourceInfo)
var x2896: activation_x2896 = null
if (resourceInfo.availableThreads <= 1) {
x2896 = x2896_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2896] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2896](x2896_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2896_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2896 = x2896_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2896
}}

/**********/

