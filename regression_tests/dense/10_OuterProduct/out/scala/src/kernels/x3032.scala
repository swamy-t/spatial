package generated.scala
//activation record for fat loop
final class activation_x3032 {
var left_act: activation_x3032 = _
var x3032: FixedPoint[Signed,B32,B0] = _
var x3032_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x3032 {
}
object kernel_x3032 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3027:Int,x99:FixedPoint[Signed,B32,B0],x3026:Array[FixedPoint[Signed,B32,B0]]): activation_x3032 = {
val x3032_closure = new generated.scala.DeliteOpMultiLoop[activation_x3032] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3027
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3032 = {
val __act: activation_x3032 = new activation_x3032()
__act.x3032_zero = x99
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3032,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3032]): activation_x3032 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3032 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3032 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3032): activation_x3032 = {
val act: activation_x3032 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3032,start:Long,end:Long): activation_x3032 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3032 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3032,x459:Int,isEmpty:Boolean): activation_x3032 = {
val __act2: activation_x3032 = new activation_x3032()
__act2.x3032_zero = __act.x3032_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x3032 = __act2.x3032_zero
if (!isEmpty) {
val x3028 = x3026(x459.toInt)
__act2.x3032 = x3028
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3032,x459:Int): Unit = {
val x3028 = x3026(x459.toInt)
val x464 = __act.x3032
val x465 = x3028
val x466 = {
x464 + x465
}
__act.x3032 = x466
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3032,rhs:activation_x3032): Unit = {
val x464 = __act.x3032
val x465 = rhs.x3032
if (x464 == __act.x3032_zero) {
__act.x3032 = x465
}
else if (x465 != __act.x3032_zero) {
val x466 = {
x464 + x465
}
__act.x3032 = x466
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3032,lhs:activation_x3032): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3032): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3032): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3032): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3032 = {
val act: activation_x3032 = new activation_x3032
act.x3032_zero = x99
act
}

}
x3032_closure.loopStart = 0
x3032_closure.loopSize = x3027
val alloc: activation_x3032 = x3032_closure.alloc(resourceInfo)
var x3032: activation_x3032 = null
if (resourceInfo.availableThreads <= 1) {
x3032 = x3032_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3032] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3032](x3032_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3032_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3032 = x3032_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3032
}}

/**********/

