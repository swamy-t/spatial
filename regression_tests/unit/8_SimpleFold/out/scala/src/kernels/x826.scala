package generated.scala
//activation record for fat loop
final class activation_x826 {
var left_act: activation_x826 = _
var x826: FixedPoint[Signed,B32,B0] = _
var x826_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x826 {
}
object kernel_x826 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x50:FixedPoint[Signed,B32,B0],x761:Array[FixedPoint[Signed,B32,B0]]): activation_x826 = {
val x826_closure = new generated.scala.DeliteOpMultiLoop[activation_x826] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x826 = {
val __act: activation_x826 = new activation_x826()
__act.x826_zero = x50
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x826,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x826]): activation_x826 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x826 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x826 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x826): activation_x826 = {
val act: activation_x826 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x826,start:Long,end:Long): activation_x826 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x826 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x826,x130:Int,isEmpty:Boolean): activation_x826 = {
val __act2: activation_x826 = new activation_x826()
__act2.x826_zero = __act.x826_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x826 = __act2.x826_zero
if (!isEmpty) {
val x823 = x761(x130.toInt)
__act2.x826 = x823
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x826,x130:Int): Unit = {
val x823 = x761(x130.toInt)
val x134 = __act.x826
val x135 = x823
val x136 = {
x134 + x135
}
__act.x826 = x136
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x826,rhs:activation_x826): Unit = {
val x134 = __act.x826
val x135 = rhs.x826
if (x134 == __act.x826_zero) {
__act.x826 = x135
}
else if (x135 != __act.x826_zero) {
val x136 = {
x134 + x135
}
__act.x826 = x136
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x826,lhs:activation_x826): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x826): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x826): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x826): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x826 = {
val act: activation_x826 = new activation_x826
act.x826_zero = x50
act
}

}
x826_closure.loopStart = 0
x826_closure.loopSize = x3
val alloc: activation_x826 = x826_closure.alloc(resourceInfo)
var x826: activation_x826 = null
if (resourceInfo.availableThreads <= 1) {
x826 = x826_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x826] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x826](x826_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x826_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x826 = x826_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x826
}}

/**********/

