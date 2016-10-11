package generated.scala
//activation record for fat loop
final class activation_x2814x3220 {
var left_act: activation_x2814x3220 = _
var x2814: Array[FixedPoint[Signed,B32,B0]] = _
var x2814_data: Array[FixedPoint[Signed,B32,B0]] = _
var x3220: Array[FixedPoint[Signed,B32,B0]] = _
var x3220_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x2814x3220 {
}
object kernel_x2814x3220 {
def apply(resourceInfo:generated.scala.ResourceInfo,x2:Int,x50:FixedPoint[Signed,B32,B0]): activation_x2814x3220 = {
val x2814x3220_closure = new generated.scala.DeliteOpMultiLoop[activation_x2814x3220] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x2
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2814x3220 = {
val __act: activation_x2814x3220 = new activation_x2814x3220()
val x7 = (loopSize).asInstanceOf[Int]
if (x7 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2778 = new Array[FixedPoint[Signed,B32,B0]](x7.toInt)
__act.x2814_data = x2778
val x54 = (loopSize).asInstanceOf[Int]
if (x54 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2816 = new Array[FixedPoint[Signed,B32,B0]](x54.toInt)
__act.x3220_data = x2816
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2814x3220,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2814x3220]): activation_x2814x3220 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2814x3220 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2814x3220 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2814x3220): activation_x2814x3220 = {
val act: activation_x2814x3220 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2814x3220,start:Long,end:Long): activation_x2814x3220 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2814x3220 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2814x3220,x3:Int,isEmpty:Boolean): activation_x2814x3220 = {
if (!isEmpty) {
process(resourceInfo,__act,x3)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2814x3220,x3:Int): Unit = {
val x4 = {
FixedPoint[Signed,B32,B0](x3)
}
val x3217 = {
x4 * x50
}
val x6 = x4
val x5 = __act.x2814_data
val x2782 = x5(x3.toInt) = x6
val x53 = x3217
val x52 = __act.x3220_data
val x3218 = x52(x3.toInt) = x53
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2814x3220,rhs:activation_x2814x3220): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2814x3220,lhs:activation_x2814x3220): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2814x3220): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2814x3220): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2814x3220): Unit = {
var x5: Array[FixedPoint[Signed,B32,B0]] = __act.x2814_data
__act.x2814_data = null
__act.x2814 = x5
var x52: Array[FixedPoint[Signed,B32,B0]] = __act.x3220_data
__act.x3220_data = null
__act.x3220 = x52
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2814x3220 = {
val act: activation_x2814x3220 = new activation_x2814x3220
act
}

}
x2814x3220_closure.loopStart = 0
x2814x3220_closure.loopSize = x2
val alloc: activation_x2814x3220 = x2814x3220_closure.alloc(resourceInfo)
var x2814x3220: activation_x2814x3220 = null
if (resourceInfo.availableThreads <= 1) {
x2814x3220 = x2814x3220_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2814x3220] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2814x3220](x2814x3220_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2814x3220_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2814x3220 = x2814x3220_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2814x3220
}}

/**********/

