package generated.scala
//activation record for fat loop
final class activation_x6229 {
var left_act: activation_x6229 = _
var x6229: Array[FixedPoint[Signed,B32,B0]] = _
var x6229_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x6229 {
}
object kernel_x6229 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6225:Int,x6224:Array[FixedPoint[Signed,B32,B0]]): activation_x6229 = {
val x6229_closure = new generated.scala.DeliteOpMultiLoop[activation_x6229] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6225
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6229 = {
val __act: activation_x6229 = new activation_x6229()
val x885 = (loopSize).asInstanceOf[Int]
if (x885 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x6035 = new Array[FixedPoint[Signed,B32,B0]](x885.toInt)
__act.x6229_data = x6035
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6229,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6229]): activation_x6229 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6229 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6229 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6229): activation_x6229 = {
val act: activation_x6229 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6229,start:Long,end:Long): activation_x6229 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6229 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6229,x881:Int,isEmpty:Boolean): activation_x6229 = {
if (!isEmpty) {
process(resourceInfo,__act,x881)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6229,x881:Int): Unit = {
val x6226 = x6224(x881.toInt)
val x884 = x6226
val x883 = __act.x6229_data
val x6039 = x883(x881.toInt) = x884
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6229,rhs:activation_x6229): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6229,lhs:activation_x6229): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6229): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6229): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6229): Unit = {
var x883: Array[FixedPoint[Signed,B32,B0]] = __act.x6229_data
__act.x6229_data = null
__act.x6229 = x883
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6229 = {
val act: activation_x6229 = new activation_x6229
act
}

}
x6229_closure.loopStart = 0
x6229_closure.loopSize = x6225
val alloc: activation_x6229 = x6229_closure.alloc(resourceInfo)
var x6229: activation_x6229 = null
if (resourceInfo.availableThreads <= 1) {
x6229 = x6229_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6229] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6229](x6229_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6229_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6229 = x6229_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6229
}}

/**********/

