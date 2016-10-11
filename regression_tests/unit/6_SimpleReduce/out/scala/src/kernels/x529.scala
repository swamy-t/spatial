package generated.scala
//activation record for fat loop
final class activation_x529 {
var left_act: activation_x529 = _
var x529: FixedPoint[Signed,B32,B0] = _
var x529_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x529 {
}
object kernel_x529 {
def apply(resourceInfo:generated.scala.ResourceInfo,x36:Int,x4:FixedPoint[Signed,B32,B0],x525:Array[FixedPoint[Signed,B32,B0]]): activation_x529 = {
val x529_closure = new generated.scala.DeliteOpMultiLoop[activation_x529] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x36
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x529 = {
val __act: activation_x529 = new activation_x529()
__act.x529_zero = x4
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x529,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x529]): activation_x529 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x529 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x529 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x529): activation_x529 = {
val act: activation_x529 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x529,start:Long,end:Long): activation_x529 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x529 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x529,x83:Int,isEmpty:Boolean): activation_x529 = {
val __act2: activation_x529 = new activation_x529()
__act2.x529_zero = __act.x529_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x529 = __act2.x529_zero
if (!isEmpty) {
val x526 = x525(x83.toInt)
__act2.x529 = x526
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x529,x83:Int): Unit = {
val x526 = x525(x83.toInt)
val x87 = __act.x529
val x88 = x526
val x89 = {
x87 + x88
}
__act.x529 = x89
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x529,rhs:activation_x529): Unit = {
val x87 = __act.x529
val x88 = rhs.x529
if (x87 == __act.x529_zero) {
__act.x529 = x88
}
else if (x88 != __act.x529_zero) {
val x89 = {
x87 + x88
}
__act.x529 = x89
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x529,lhs:activation_x529): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x529): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x529): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x529): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x529 = {
val act: activation_x529 = new activation_x529
act.x529_zero = x4
act
}

}
x529_closure.loopStart = 0
x529_closure.loopSize = x36
val alloc: activation_x529 = x529_closure.alloc(resourceInfo)
var x529: activation_x529 = null
if (resourceInfo.availableThreads <= 1) {
x529 = x529_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x529] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x529](x529_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x529_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x529 = x529_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x529
}}

/**********/

