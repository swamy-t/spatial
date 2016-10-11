package generated.scala
//activation record for fat loop
final class activation_x1408 {
var left_act: activation_x1408 = _
var x1408: Boolean = _
var x1408_zero: Boolean = _
}
object activation_x1408 {
}
object kernel_x1408 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1403:Int,x245:Boolean,x1402:Array[Boolean]): activation_x1408 = {
val x1408_closure = new generated.scala.DeliteOpMultiLoop[activation_x1408] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1403
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1408 = {
val __act: activation_x1408 = new activation_x1408()
__act.x1408_zero = x245
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1408,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1408]): activation_x1408 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1408 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1408 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1408): activation_x1408 = {
val act: activation_x1408 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1408,start:Long,end:Long): activation_x1408 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1408 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1408,x247:Int,isEmpty:Boolean): activation_x1408 = {
val __act2: activation_x1408 = new activation_x1408()
__act2.x1408_zero = __act.x1408_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x1408 = __act2.x1408_zero
if (!isEmpty) {
val x1404 = x1402(x247.toInt)
__act2.x1408 = x1404
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1408,x247:Int): Unit = {
val x1404 = x1402(x247.toInt)
val x252 = __act.x1408
val x253 = x1404
val x254 = {
x252 && x253
}
__act.x1408 = x254
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1408,rhs:activation_x1408): Unit = {
val x252 = __act.x1408
val x253 = rhs.x1408
if (x252 == __act.x1408_zero) {
__act.x1408 = x253
}
else if (x253 != __act.x1408_zero) {
val x254 = {
x252 && x253
}
__act.x1408 = x254
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1408,lhs:activation_x1408): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1408): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1408): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1408): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1408 = {
val act: activation_x1408 = new activation_x1408
act.x1408_zero = x245
act
}

}
x1408_closure.loopStart = 0
x1408_closure.loopSize = x1403
val alloc: activation_x1408 = x1408_closure.alloc(resourceInfo)
var x1408: activation_x1408 = null
if (resourceInfo.availableThreads <= 1) {
x1408 = x1408_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1408] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1408](x1408_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1408_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1408 = x1408_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1408
}}

/**********/

