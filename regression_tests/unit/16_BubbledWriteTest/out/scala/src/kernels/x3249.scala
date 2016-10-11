package generated.scala
//activation record for fat loop
final class activation_x3249 {
var left_act: activation_x3249 = _
var x3249: Boolean = _
var x3249_zero: Boolean = _
}
object activation_x3249 {
}
object kernel_x3249 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3246:Int,x559:Boolean,x3245:Array[Boolean]): activation_x3249 = {
val x3249_closure = new generated.scala.DeliteOpMultiLoop[activation_x3249] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3246
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3249 = {
val __act: activation_x3249 = new activation_x3249()
__act.x3249_zero = x559
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3249,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3249]): activation_x3249 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3249 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3249 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3249): activation_x3249 = {
val act: activation_x3249 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3249,start:Long,end:Long): activation_x3249 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3249 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3249,x561:Int,isEmpty:Boolean): activation_x3249 = {
val __act2: activation_x3249 = new activation_x3249()
__act2.x3249_zero = __act.x3249_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x3249 = __act2.x3249_zero
if (!isEmpty) {
val x3247 = x3245(x561.toInt)
__act2.x3249 = x3247
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3249,x561:Int): Unit = {
val x3247 = x3245(x561.toInt)
val x566 = __act.x3249
val x567 = x3247
val x568 = {
x566 && x567
}
__act.x3249 = x568
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3249,rhs:activation_x3249): Unit = {
val x566 = __act.x3249
val x567 = rhs.x3249
if (x566 == __act.x3249_zero) {
__act.x3249 = x567
}
else if (x567 != __act.x3249_zero) {
val x568 = {
x566 && x567
}
__act.x3249 = x568
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3249,lhs:activation_x3249): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3249): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3249): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3249): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3249 = {
val act: activation_x3249 = new activation_x3249
act.x3249_zero = x559
act
}

}
x3249_closure.loopStart = 0
x3249_closure.loopSize = x3246
val alloc: activation_x3249 = x3249_closure.alloc(resourceInfo)
var x3249: activation_x3249 = null
if (resourceInfo.availableThreads <= 1) {
x3249 = x3249_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3249] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3249](x3249_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3249_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3249 = x3249_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3249
}}

/**********/

