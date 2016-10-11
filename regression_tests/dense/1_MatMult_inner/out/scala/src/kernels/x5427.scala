package generated.scala
//activation record for fat loop
final class activation_x5427 {
var left_act: activation_x5427 = _
var x5427: Boolean = _
var x5427_zero: Boolean = _
}
object activation_x5427 {
}
object kernel_x5427 {
def apply(resourceInfo:generated.scala.ResourceInfo,x5424:Int,x876:Boolean,x5423:Array[Boolean]): activation_x5427 = {
val x5427_closure = new generated.scala.DeliteOpMultiLoop[activation_x5427] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x5424
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5427 = {
val __act: activation_x5427 = new activation_x5427()
__act.x5427_zero = x876
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5427,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5427]): activation_x5427 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5427 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5427 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5427): activation_x5427 = {
val act: activation_x5427 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5427,start:Long,end:Long): activation_x5427 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5427 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5427,x878:Int,isEmpty:Boolean): activation_x5427 = {
val __act2: activation_x5427 = new activation_x5427()
__act2.x5427_zero = __act.x5427_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x5427 = __act2.x5427_zero
if (!isEmpty) {
val x5425 = x5423(x878.toInt)
__act2.x5427 = x5425
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5427,x878:Int): Unit = {
val x5425 = x5423(x878.toInt)
val x883 = __act.x5427
val x884 = x5425
val x885 = {
x883 && x884
}
__act.x5427 = x885
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5427,rhs:activation_x5427): Unit = {
val x883 = __act.x5427
val x884 = rhs.x5427
if (x883 == __act.x5427_zero) {
__act.x5427 = x884
}
else if (x884 != __act.x5427_zero) {
val x885 = {
x883 && x884
}
__act.x5427 = x885
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5427,lhs:activation_x5427): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5427): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5427): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5427): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5427 = {
val act: activation_x5427 = new activation_x5427
act.x5427_zero = x876
act
}

}
x5427_closure.loopStart = 0
x5427_closure.loopSize = x5424
val alloc: activation_x5427 = x5427_closure.alloc(resourceInfo)
var x5427: activation_x5427 = null
if (resourceInfo.availableThreads <= 1) {
x5427 = x5427_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5427] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5427](x5427_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5427_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5427 = x5427_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5427
}}

/**********/

