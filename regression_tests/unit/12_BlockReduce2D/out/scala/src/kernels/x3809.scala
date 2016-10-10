package generated.scala
//activation record for fat loop
final class activation_x3809 {
var left_act: activation_x3809 = _
var x3809: Boolean = _
var x3809_zero: Boolean = _
}
object activation_x3809 {
}
object kernel_x3809 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3804:Int,x865:Boolean,x3803:Array[Boolean]): activation_x3809 = {
val x3809_closure = new generated.scala.DeliteOpMultiLoop[activation_x3809] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3804
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3809 = {
val __act: activation_x3809 = new activation_x3809()
__act.x3809_zero = x865
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3809,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3809]): activation_x3809 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3809 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3809 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3809): activation_x3809 = {
val act: activation_x3809 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3809,start:Long,end:Long): activation_x3809 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3809 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3809,x867:Int,isEmpty:Boolean): activation_x3809 = {
val __act2: activation_x3809 = new activation_x3809()
__act2.x3809_zero = __act.x3809_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x3809 = __act2.x3809_zero
if (!isEmpty) {
val x3805 = x3803(x867.toInt)
__act2.x3809 = x3805
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3809,x867:Int): Unit = {
val x3805 = x3803(x867.toInt)
val x872 = __act.x3809
val x873 = x3805
val x874 = {
x872 && x873
}
__act.x3809 = x874
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3809,rhs:activation_x3809): Unit = {
val x872 = __act.x3809
val x873 = rhs.x3809
if (x872 == __act.x3809_zero) {
__act.x3809 = x873
}
else if (x873 != __act.x3809_zero) {
val x874 = {
x872 && x873
}
__act.x3809 = x874
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3809,lhs:activation_x3809): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3809): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3809): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3809): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3809 = {
val act: activation_x3809 = new activation_x3809
act.x3809_zero = x865
act
}

}
x3809_closure.loopStart = 0
x3809_closure.loopSize = x3804
val alloc: activation_x3809 = x3809_closure.alloc(resourceInfo)
var x3809: activation_x3809 = null
if (resourceInfo.availableThreads <= 1) {
x3809 = x3809_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3809] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3809](x3809_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3809_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3809 = x3809_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3809
}}

/**********/

