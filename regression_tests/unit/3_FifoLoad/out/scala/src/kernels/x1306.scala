package generated.scala
//activation record for fat loop
final class activation_x1306 {
var left_act: activation_x1306 = _
var x1306: Boolean = _
var x1306_zero: Boolean = _
}
object activation_x1306 {
}
object kernel_x1306 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1301:Int,x215:Boolean,x1300:Array[Boolean]): activation_x1306 = {
val x1306_closure = new generated.scala.DeliteOpMultiLoop[activation_x1306] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1301
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1306 = {
val __act: activation_x1306 = new activation_x1306()
__act.x1306_zero = x215
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1306,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1306]): activation_x1306 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1306 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1306 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1306): activation_x1306 = {
val act: activation_x1306 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1306,start:Long,end:Long): activation_x1306 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1306 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1306,x217:Int,isEmpty:Boolean): activation_x1306 = {
val __act2: activation_x1306 = new activation_x1306()
__act2.x1306_zero = __act.x1306_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x1306 = __act2.x1306_zero
if (!isEmpty) {
val x1302 = x1300(x217.toInt)
__act2.x1306 = x1302
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1306,x217:Int): Unit = {
val x1302 = x1300(x217.toInt)
val x222 = __act.x1306
val x223 = x1302
val x224 = {
x222 && x223
}
__act.x1306 = x224
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1306,rhs:activation_x1306): Unit = {
val x222 = __act.x1306
val x223 = rhs.x1306
if (x222 == __act.x1306_zero) {
__act.x1306 = x223
}
else if (x223 != __act.x1306_zero) {
val x224 = {
x222 && x223
}
__act.x1306 = x224
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1306,lhs:activation_x1306): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1306): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1306): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1306): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1306 = {
val act: activation_x1306 = new activation_x1306
act.x1306_zero = x215
act
}

}
x1306_closure.loopStart = 0
x1306_closure.loopSize = x1301
val alloc: activation_x1306 = x1306_closure.alloc(resourceInfo)
var x1306: activation_x1306 = null
if (resourceInfo.availableThreads <= 1) {
x1306 = x1306_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1306] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1306](x1306_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1306_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1306 = x1306_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1306
}}

/**********/

