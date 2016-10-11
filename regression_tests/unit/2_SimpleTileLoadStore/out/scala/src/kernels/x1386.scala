package generated.scala
//activation record for fat loop
final class activation_x1386 {
var left_act: activation_x1386 = _
var x1386: Boolean = _
var x1386_zero: Boolean = _
}
object activation_x1386 {
}
object kernel_x1386 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1381:Int,x228:Boolean,x1380:Array[Boolean]): activation_x1386 = {
val x1386_closure = new generated.scala.DeliteOpMultiLoop[activation_x1386] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1381
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1386 = {
val __act: activation_x1386 = new activation_x1386()
__act.x1386_zero = x228
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1386,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1386]): activation_x1386 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1386 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1386 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1386): activation_x1386 = {
val act: activation_x1386 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1386,start:Long,end:Long): activation_x1386 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1386 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1386,x230:Int,isEmpty:Boolean): activation_x1386 = {
val __act2: activation_x1386 = new activation_x1386()
__act2.x1386_zero = __act.x1386_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x1386 = __act2.x1386_zero
if (!isEmpty) {
val x1382 = x1380(x230.toInt)
__act2.x1386 = x1382
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1386,x230:Int): Unit = {
val x1382 = x1380(x230.toInt)
val x235 = __act.x1386
val x236 = x1382
val x237 = {
x235 && x236
}
__act.x1386 = x237
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1386,rhs:activation_x1386): Unit = {
val x235 = __act.x1386
val x236 = rhs.x1386
if (x235 == __act.x1386_zero) {
__act.x1386 = x236
}
else if (x236 != __act.x1386_zero) {
val x237 = {
x235 && x236
}
__act.x1386 = x237
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1386,lhs:activation_x1386): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1386): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1386): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1386): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1386 = {
val act: activation_x1386 = new activation_x1386
act.x1386_zero = x228
act
}

}
x1386_closure.loopStart = 0
x1386_closure.loopSize = x1381
val alloc: activation_x1386 = x1386_closure.alloc(resourceInfo)
var x1386: activation_x1386 = null
if (resourceInfo.availableThreads <= 1) {
x1386 = x1386_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1386] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1386](x1386_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1386_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1386 = x1386_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1386
}}

/**********/

