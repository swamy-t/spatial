package generated.scala
//activation record for fat loop
final class activation_x2751 {
var left_act: activation_x2751 = _
var x2751: Array[FixedPoint[Signed,B32,B0]] = _
var x2751_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x2751 {
}
object kernel_x2751 {
def apply(resourceInfo:generated.scala.ResourceInfo,x51:Int,x53:FixedPoint[Signed,B32,B0]): activation_x2751 = {
val x2751_closure = new generated.scala.DeliteOpMultiLoop[activation_x2751] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x51
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2751 = {
val __act: activation_x2751 = new activation_x2751()
val x56 = (loopSize).asInstanceOf[Int]
if (x56 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2715 = new Array[FixedPoint[Signed,B32,B0]](x56.toInt)
__act.x2751_data = x2715
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2751,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2751]): activation_x2751 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2751 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2751 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2751): activation_x2751 = {
val act: activation_x2751 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2751,start:Long,end:Long): activation_x2751 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2751 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2751,x52:Int,isEmpty:Boolean): activation_x2751 = {
if (!isEmpty) {
process(resourceInfo,__act,x52)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2751,x52:Int): Unit = {
val x55 = x53
val x54 = __act.x2751_data
val x2719 = x54(x52.toInt) = x55
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2751,rhs:activation_x2751): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2751,lhs:activation_x2751): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2751): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2751): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2751): Unit = {
var x54: Array[FixedPoint[Signed,B32,B0]] = __act.x2751_data
__act.x2751_data = null
__act.x2751 = x54
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2751 = {
val act: activation_x2751 = new activation_x2751
act
}

}
x2751_closure.loopStart = 0
x2751_closure.loopSize = x51
val alloc: activation_x2751 = x2751_closure.alloc(resourceInfo)
var x2751: activation_x2751 = null
if (resourceInfo.availableThreads <= 1) {
x2751 = x2751_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2751] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2751](x2751_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2751_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2751 = x2751_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2751
}}

/**********/

