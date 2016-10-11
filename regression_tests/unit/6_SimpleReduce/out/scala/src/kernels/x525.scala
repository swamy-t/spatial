package generated.scala
//activation record for fat loop
final class activation_x525 {
var left_act: activation_x525 = _
var x525: Array[FixedPoint[Signed,B32,B0]] = _
var x525_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x525 {
}
object kernel_x525 {
def apply(resourceInfo:generated.scala.ResourceInfo,x36:Int,x3:FixedPoint[Signed,B32,B0]): activation_x525 = {
val x525_closure = new generated.scala.DeliteOpMultiLoop[activation_x525] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x36
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x525 = {
val __act: activation_x525 = new activation_x525()
val x42 = (loopSize).asInstanceOf[Int]
if (x42 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x489 = new Array[FixedPoint[Signed,B32,B0]](x42.toInt)
__act.x525_data = x489
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x525,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x525]): activation_x525 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x525 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x525 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x525): activation_x525 = {
val act: activation_x525 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x525,start:Long,end:Long): activation_x525 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x525 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x525,x37:Int,isEmpty:Boolean): activation_x525 = {
if (!isEmpty) {
process(resourceInfo,__act,x37)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x525,x37:Int): Unit = {
val x38 = {
FixedPoint[Signed,B32,B0](x37)
}
val x39 = {
x3 * x38
}
val x41 = x39
val x40 = __act.x525_data
val x493 = x40(x37.toInt) = x41
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x525,rhs:activation_x525): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x525,lhs:activation_x525): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x525): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x525): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x525): Unit = {
var x40: Array[FixedPoint[Signed,B32,B0]] = __act.x525_data
__act.x525_data = null
__act.x525 = x40
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x525 = {
val act: activation_x525 = new activation_x525
act
}

}
x525_closure.loopStart = 0
x525_closure.loopSize = x36
val alloc: activation_x525 = x525_closure.alloc(resourceInfo)
var x525: activation_x525 = null
if (resourceInfo.availableThreads <= 1) {
x525 = x525_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x525] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x525](x525_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x525_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x525 = x525_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x525
}}

/**********/

