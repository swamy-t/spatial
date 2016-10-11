package generated.scala
//activation record for fat loop
final class activation_x2001 {
var left_act: activation_x2001 = _
var x2001: Boolean = _
var x2001_zero: Boolean = _
}
object activation_x2001 {
}
object kernel_x2001 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1996:Int,x268:Boolean,x1995:Array[Boolean]): activation_x2001 = {
val x2001_closure = new generated.scala.DeliteOpMultiLoop[activation_x2001] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1996
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2001 = {
val __act: activation_x2001 = new activation_x2001()
__act.x2001_zero = x268
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2001,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2001]): activation_x2001 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2001 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2001 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2001): activation_x2001 = {
val act: activation_x2001 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2001,start:Long,end:Long): activation_x2001 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2001 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2001,x396:Int,isEmpty:Boolean): activation_x2001 = {
val __act2: activation_x2001 = new activation_x2001()
__act2.x2001_zero = __act.x2001_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x2001 = __act2.x2001_zero
if (!isEmpty) {
val x1997 = x1995(x396.toInt)
__act2.x2001 = x1997
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2001,x396:Int): Unit = {
val x1997 = x1995(x396.toInt)
val x401 = __act.x2001
val x402 = x1997
val x403 = {
x401 && x402
}
__act.x2001 = x403
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2001,rhs:activation_x2001): Unit = {
val x401 = __act.x2001
val x402 = rhs.x2001
if (x401 == __act.x2001_zero) {
__act.x2001 = x402
}
else if (x402 != __act.x2001_zero) {
val x403 = {
x401 && x402
}
__act.x2001 = x403
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2001,lhs:activation_x2001): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2001): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2001): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2001): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2001 = {
val act: activation_x2001 = new activation_x2001
act.x2001_zero = x268
act
}

}
x2001_closure.loopStart = 0
x2001_closure.loopSize = x1996
val alloc: activation_x2001 = x2001_closure.alloc(resourceInfo)
var x2001: activation_x2001 = null
if (resourceInfo.availableThreads <= 1) {
x2001 = x2001_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2001] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2001](x2001_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2001_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2001 = x2001_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2001
}}

/**********/

