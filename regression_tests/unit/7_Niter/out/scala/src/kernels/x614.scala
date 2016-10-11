package generated.scala
//activation record for fat loop
final class activation_x614 {
var left_act: activation_x614 = _
var x614: FixedPoint[Signed,B32,B0] = _
var x614_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x614 {
}
object kernel_x614 {
def apply(resourceInfo:generated.scala.ResourceInfo,x46:Int,x4:FixedPoint[Signed,B32,B0],x610:Array[FixedPoint[Signed,B32,B0]]): activation_x614 = {
val x614_closure = new generated.scala.DeliteOpMultiLoop[activation_x614] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x46
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x614 = {
val __act: activation_x614 = new activation_x614()
__act.x614_zero = x4
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x614,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x614]): activation_x614 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x614 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x614 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x614): activation_x614 = {
val act: activation_x614 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x614,start:Long,end:Long): activation_x614 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x614 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x614,x92:Int,isEmpty:Boolean): activation_x614 = {
val __act2: activation_x614 = new activation_x614()
__act2.x614_zero = __act.x614_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x614 = __act2.x614_zero
if (!isEmpty) {
val x611 = x610(x92.toInt)
__act2.x614 = x611
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x614,x92:Int): Unit = {
val x611 = x610(x92.toInt)
val x96 = __act.x614
val x97 = x611
val x98 = {
x96 + x97
}
__act.x614 = x98
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x614,rhs:activation_x614): Unit = {
val x96 = __act.x614
val x97 = rhs.x614
if (x96 == __act.x614_zero) {
__act.x614 = x97
}
else if (x97 != __act.x614_zero) {
val x98 = {
x96 + x97
}
__act.x614 = x98
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x614,lhs:activation_x614): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x614): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x614): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x614): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x614 = {
val act: activation_x614 = new activation_x614
act.x614_zero = x4
act
}

}
x614_closure.loopStart = 0
x614_closure.loopSize = x46
val alloc: activation_x614 = x614_closure.alloc(resourceInfo)
var x614: activation_x614 = null
if (resourceInfo.availableThreads <= 1) {
x614 = x614_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x614] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x614](x614_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x614_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x614 = x614_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x614
}}

/**********/

