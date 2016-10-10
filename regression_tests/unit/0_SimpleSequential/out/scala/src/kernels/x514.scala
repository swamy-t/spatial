package generated.scala
//activation record for fat loop
final class activation_x514 {
var left_act: activation_x514 = _
var x514: Array[FixedPoint[Signed,B32,B0]] = _
var x514_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x514 {
}
object kernel_x514 {
def apply(resourceInfo:generated.scala.ResourceInfo,x34:Int,x2:FixedPoint[Signed,B32,B0]): activation_x514 = {
val x514_closure = new generated.scala.DeliteOpMultiLoop[activation_x514] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x34
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x514 = {
val __act: activation_x514 = new activation_x514()
val x40 = (loopSize).asInstanceOf[Int]
if (x40 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x478 = new Array[FixedPoint[Signed,B32,B0]](x40.toInt)
__act.x514_data = x478
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x514,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x514]): activation_x514 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x514 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x514 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x514): activation_x514 = {
val act: activation_x514 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x514,start:Long,end:Long): activation_x514 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x514 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x514,x35:Int,isEmpty:Boolean): activation_x514 = {
if (!isEmpty) {
process(resourceInfo,__act,x35)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x514,x35:Int): Unit = {
val x36 = {
FixedPoint[Signed,B32,B0](x35)
}
val x37 = {
x2 * x36
}
val x39 = x37
val x38 = __act.x514_data
val x482 = x38(x35.toInt) = x39
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x514,rhs:activation_x514): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x514,lhs:activation_x514): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x514): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x514): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x514): Unit = {
var x38: Array[FixedPoint[Signed,B32,B0]] = __act.x514_data
__act.x514_data = null
__act.x514 = x38
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x514 = {
val act: activation_x514 = new activation_x514
act
}

}
x514_closure.loopStart = 0
x514_closure.loopSize = x34
val alloc: activation_x514 = x514_closure.alloc(resourceInfo)
var x514: activation_x514 = null
if (resourceInfo.availableThreads <= 1) {
x514 = x514_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x514] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x514](x514_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x514_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x514 = x514_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x514
}}

/**********/

