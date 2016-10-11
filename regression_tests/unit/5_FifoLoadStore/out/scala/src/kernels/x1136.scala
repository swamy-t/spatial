package generated.scala
//activation record for fat loop
final class activation_x1136 {
var left_act: activation_x1136 = _
var x1136: Array[FixedPoint[Signed,B32,B0]] = _
var x1136_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1136 {
}
object kernel_x1136 {
def apply(resourceInfo:generated.scala.ResourceInfo,x2:Int,x1076:Array[FixedPoint[Signed,B32,B0]]): activation_x1136 = {
val x1136_closure = new generated.scala.DeliteOpMultiLoop[activation_x1136] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x2
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1136 = {
val __act: activation_x1136 = new activation_x1136()
val x86 = (loopSize).asInstanceOf[Int]
if (x86 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1100 = new Array[FixedPoint[Signed,B32,B0]](x86.toInt)
__act.x1136_data = x1100
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1136,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1136]): activation_x1136 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1136 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1136 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1136): activation_x1136 = {
val act: activation_x1136 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1136,start:Long,end:Long): activation_x1136 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1136 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1136,x82:Int,isEmpty:Boolean): activation_x1136 = {
if (!isEmpty) {
process(resourceInfo,__act,x82)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1136,x82:Int): Unit = {
val x1099 = x1076(x82.toInt)
val x85 = x1099
val x84 = __act.x1136_data
val x1104 = x84(x82.toInt) = x85
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1136,rhs:activation_x1136): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1136,lhs:activation_x1136): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1136): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1136): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1136): Unit = {
var x84: Array[FixedPoint[Signed,B32,B0]] = __act.x1136_data
__act.x1136_data = null
__act.x1136 = x84
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1136 = {
val act: activation_x1136 = new activation_x1136
act
}

}
x1136_closure.loopStart = 0
x1136_closure.loopSize = x2
val alloc: activation_x1136 = x1136_closure.alloc(resourceInfo)
var x1136: activation_x1136 = null
if (resourceInfo.availableThreads <= 1) {
x1136 = x1136_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1136] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1136](x1136_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1136_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1136 = x1136_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1136
}}

/**********/

