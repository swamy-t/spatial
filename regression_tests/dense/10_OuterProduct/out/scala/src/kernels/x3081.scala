package generated.scala
//activation record for fat loop
final class activation_x3081 {
var left_act: activation_x3081 = _
var x3081: Array[Boolean] = _
var x3081_data: Array[Boolean] = _
}
object activation_x3081 {
}
object kernel_x3081 {
def apply(resourceInfo:generated.scala.ResourceInfo,x2987:Int,x2825:Array[FixedPoint[Signed,B32,B0]],x2941:Array[FixedPoint[Signed,B32,B0]]): activation_x3081 = {
val x3081_closure = new generated.scala.DeliteOpMultiLoop[activation_x3081] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x2987
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3081 = {
val __act: activation_x3081 = new activation_x3081()
val x487 = (loopSize).asInstanceOf[Int]
if (x487 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3045 = new Array[Boolean](x487.toInt)
__act.x3081_data = x3045
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3081,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3081]): activation_x3081 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3081 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3081 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3081): activation_x3081 = {
val act: activation_x3081 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3081,start:Long,end:Long): activation_x3081 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3081 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3081,x480:Int,isEmpty:Boolean): activation_x3081 = {
if (!isEmpty) {
process(resourceInfo,__act,x480)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3081,x480:Int): Unit = {
val x3041 = x2825(x480.toInt)
val x3042 = x2941(x480.toInt)
val x3043 = {
x3041 == x3042
}
val x486 = x3043
val x485 = __act.x3081_data
val x3049 = x485(x480.toInt) = x486
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3081,rhs:activation_x3081): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3081,lhs:activation_x3081): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3081): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3081): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3081): Unit = {
var x485: Array[Boolean] = __act.x3081_data
__act.x3081_data = null
__act.x3081 = x485
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3081 = {
val act: activation_x3081 = new activation_x3081
act
}

}
x3081_closure.loopStart = 0
x3081_closure.loopSize = x2987
val alloc: activation_x3081 = x3081_closure.alloc(resourceInfo)
var x3081: activation_x3081 = null
if (resourceInfo.availableThreads <= 1) {
x3081 = x3081_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3081] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3081](x3081_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3081_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3081 = x3081_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3081
}}

/**********/

