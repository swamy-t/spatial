package generated.scala
//activation record for fat loop
final class activation_x1445 {
var left_act: activation_x1445 = _
var x1445: Boolean = _
var x1445_zero: Boolean = _
}
object activation_x1445 {
}
object kernel_x1445 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1440:Int,x249:Boolean,x1439:Array[Boolean]): activation_x1445 = {
val x1445_closure = new generated.scala.DeliteOpMultiLoop[activation_x1445] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1440
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1445 = {
val __act: activation_x1445 = new activation_x1445()
__act.x1445_zero = x249
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1445,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1445]): activation_x1445 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1445 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1445 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1445): activation_x1445 = {
val act: activation_x1445 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1445,start:Long,end:Long): activation_x1445 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1445 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1445,x251:Int,isEmpty:Boolean): activation_x1445 = {
val __act2: activation_x1445 = new activation_x1445()
__act2.x1445_zero = __act.x1445_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x1445 = __act2.x1445_zero
if (!isEmpty) {
val x1441 = x1439(x251.toInt)
__act2.x1445 = x1441
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1445,x251:Int): Unit = {
val x1441 = x1439(x251.toInt)
val x256 = __act.x1445
val x257 = x1441
val x258 = {
x256 && x257
}
__act.x1445 = x258
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1445,rhs:activation_x1445): Unit = {
val x256 = __act.x1445
val x257 = rhs.x1445
if (x256 == __act.x1445_zero) {
__act.x1445 = x257
}
else if (x257 != __act.x1445_zero) {
val x258 = {
x256 && x257
}
__act.x1445 = x258
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1445,lhs:activation_x1445): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1445): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1445): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1445): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1445 = {
val act: activation_x1445 = new activation_x1445
act.x1445_zero = x249
act
}

}
x1445_closure.loopStart = 0
x1445_closure.loopSize = x1440
val alloc: activation_x1445 = x1445_closure.alloc(resourceInfo)
var x1445: activation_x1445 = null
if (resourceInfo.availableThreads <= 1) {
x1445 = x1445_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1445] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1445](x1445_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1445_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1445 = x1445_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1445
}}

/**********/

