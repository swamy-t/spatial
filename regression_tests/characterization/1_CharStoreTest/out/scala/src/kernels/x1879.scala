package generated.scala
//activation record for fat loop
final class activation_x1879 {
var left_act: activation_x1879 = _
var x1879: FixedPoint[Signed,B32,B0] = _
var x1879_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x1879 {
}
object kernel_x1879 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1874:Int,x53:FixedPoint[Signed,B32,B0],x1854:Array[FixedPoint[Signed,B32,B0]]): activation_x1879 = {
val x1879_closure = new generated.scala.DeliteOpMultiLoop[activation_x1879] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1874
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1879 = {
val __act: activation_x1879 = new activation_x1879()
__act.x1879_zero = x53
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1879,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1879]): activation_x1879 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1879 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1879 = sync.get(localStart)
//combine local
var i: Int = localStart+1
while (i < localEnd) {
combine(resourceInfo,act,sync.get(i))
i = i+1
}
//combine remote
var half: Int = tid
var step: Int = 1
while ((half % 2 == 0) && (tid + step < numThreads)) {
combine(resourceInfo,act,sync.getC(tid+step))
half = half / 2
step = step * 2
}
sync.setC(tid,act)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1879): activation_x1879 = {
val act: activation_x1879 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1879,start:Long,end:Long): activation_x1879 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1879 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1879,x264:Int,isEmpty:Boolean): activation_x1879 = {
val __act2: activation_x1879 = new activation_x1879()
__act2.x1879_zero = __act.x1879_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x1879 = __act2.x1879_zero
if (!isEmpty) {
val x1875 = x1854(x264.toInt)
__act2.x1879 = x1875
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1879,x264:Int): Unit = {
val x1875 = x1854(x264.toInt)
val x269 = __act.x1879
val x270 = x1875
val x271 = {
x269 + x270
}
__act.x1879 = x271
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1879,rhs:activation_x1879): Unit = {
val x269 = __act.x1879
val x270 = rhs.x1879
if (x269 == __act.x1879_zero) {
__act.x1879 = x270
}
else if (x270 != __act.x1879_zero) {
val x271 = {
x269 + x270
}
__act.x1879 = x271
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1879,lhs:activation_x1879): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1879): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1879): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1879): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1879 = {
val act: activation_x1879 = new activation_x1879
act.x1879_zero = x53
act
}

}
x1879_closure.loopStart = 0
x1879_closure.loopSize = x1874
val alloc: activation_x1879 = x1879_closure.alloc(resourceInfo)
var x1879: activation_x1879 = null
if (resourceInfo.availableThreads <= 1) {
x1879 = x1879_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1879] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1879](x1879_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1879_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1879 = x1879_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1879
}}

/**********/

