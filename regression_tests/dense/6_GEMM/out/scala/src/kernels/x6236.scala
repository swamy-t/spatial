package generated.scala
//activation record for fat loop
final class activation_x6236 {
var left_act: activation_x6236 = _
var x6236: Boolean = _
var x6236_zero: Boolean = _
}
object activation_x6236 {
}
object kernel_x6236 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6233:Int,x1093:Boolean,x6232:Array[Boolean]): activation_x6236 = {
val x6236_closure = new generated.scala.DeliteOpMultiLoop[activation_x6236] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6233
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6236 = {
val __act: activation_x6236 = new activation_x6236()
__act.x6236_zero = x1093
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6236,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6236]): activation_x6236 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6236 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6236 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6236): activation_x6236 = {
val act: activation_x6236 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6236,start:Long,end:Long): activation_x6236 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6236 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6236,x1095:Int,isEmpty:Boolean): activation_x6236 = {
val __act2: activation_x6236 = new activation_x6236()
__act2.x6236_zero = __act.x6236_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x6236 = __act2.x6236_zero
if (!isEmpty) {
val x6234 = x6232(x1095.toInt)
__act2.x6236 = x6234
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6236,x1095:Int): Unit = {
val x6234 = x6232(x1095.toInt)
val x1100 = __act.x6236
val x1101 = x6234
val x1102 = {
x1100 && x1101
}
__act.x6236 = x1102
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6236,rhs:activation_x6236): Unit = {
val x1100 = __act.x6236
val x1101 = rhs.x6236
if (x1100 == __act.x6236_zero) {
__act.x6236 = x1101
}
else if (x1101 != __act.x6236_zero) {
val x1102 = {
x1100 && x1101
}
__act.x6236 = x1102
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6236,lhs:activation_x6236): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6236): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6236): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6236): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6236 = {
val act: activation_x6236 = new activation_x6236
act.x6236_zero = x1093
act
}

}
x6236_closure.loopStart = 0
x6236_closure.loopSize = x6233
val alloc: activation_x6236 = x6236_closure.alloc(resourceInfo)
var x6236: activation_x6236 = null
if (resourceInfo.availableThreads <= 1) {
x6236 = x6236_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6236] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6236](x6236_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6236_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6236 = x6236_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6236
}}

/**********/

