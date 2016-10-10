package generated.scala
//activation record for thin loop
final class activation_x4269 {
var left_act: activation_x4269 = _
var x4269: Array[FloatPoint[B24,B8]] = _
var x4269_data: Array[FloatPoint[B24,B8]] = _
}
object activation_x4269 {
}
object kernel_x4269 {
def apply(resourceInfo:generated.scala.ResourceInfo,x14:Int): activation_x4269 = {
// a *thin* loop follows: x4269
val x4269_closure = new generated.scala.DeliteOpMultiLoop[activation_x4269] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x14
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x4269 = {
val __act: activation_x4269 = new activation_x4269()
val x251 = (loopSize).asInstanceOf[Int]
if (x251 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4233 = new Array[FloatPoint[B24,B8]](x251.toInt)
__act.x4269_data = x4233
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4269,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x4269]): activation_x4269 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x4269 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x4269 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4269): activation_x4269 = {
val act: activation_x4269 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4269,start:Long,end:Long): activation_x4269 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x4269 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4269,x246:Int,isEmpty:Boolean): activation_x4269 = {
if (!isEmpty) {
process(resourceInfo,__act,x246)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4269,x246:Int): Unit = {
val x4231 = {
FloatPoint.rand[B24,B8]
}
val x250 = x4231
val x249 = __act.x4269_data
val x4237 = x249(x246.toInt) = x250
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4269,rhs:activation_x4269): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4269,lhs:activation_x4269): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4269): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4269): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4269): Unit = {
var x249: Array[FloatPoint[B24,B8]] = __act.x4269_data
__act.x4269_data = null
__act.x4269 = x249
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x4269 = {
val act: activation_x4269 = new activation_x4269
act
}

}
x4269_closure.loopStart = 0
x4269_closure.loopSize = x14
val alloc: activation_x4269 = x4269_closure.alloc(resourceInfo)
var x4269: activation_x4269 = null
if (resourceInfo.availableThreads <= 1) {
x4269 = x4269_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x4269] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x4269](x4269_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x4269_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x4269 = x4269_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x4269
}}

/**********/

