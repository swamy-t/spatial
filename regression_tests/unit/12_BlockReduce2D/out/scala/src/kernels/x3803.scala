package generated.scala
//activation record for fat loop
final class activation_x3803 {
var left_act: activation_x3803 = _
var x3803: Array[Boolean] = _
var x3803_data: Array[Boolean] = _
}
object activation_x3803 {
}
object kernel_x3803 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3755:Int,x3514:Array[FixedPoint[Signed,B32,B0]],x3745:Array[FixedPoint[Signed,B32,B0]]): activation_x3803 = {
val x3803_closure = new generated.scala.DeliteOpMultiLoop[activation_x3803] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3755
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3803 = {
val __act: activation_x3803 = new activation_x3803()
val x824 = (loopSize).asInstanceOf[Int]
if (x824 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3767 = new Array[Boolean](x824.toInt)
__act.x3803_data = x3767
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3803,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3803]): activation_x3803 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3803 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3803 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3803): activation_x3803 = {
val act: activation_x3803 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3803,start:Long,end:Long): activation_x3803 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3803 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3803,x817:Int,isEmpty:Boolean): activation_x3803 = {
if (!isEmpty) {
process(resourceInfo,__act,x817)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3803,x817:Int): Unit = {
val x3763 = x3514(x817.toInt)
val x3764 = x3745(x817.toInt)
val x3765 = {
x3763 == x3764
}
val x823 = x3765
val x822 = __act.x3803_data
val x3771 = x822(x817.toInt) = x823
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3803,rhs:activation_x3803): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3803,lhs:activation_x3803): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3803): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3803): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3803): Unit = {
var x822: Array[Boolean] = __act.x3803_data
__act.x3803_data = null
__act.x3803 = x822
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3803 = {
val act: activation_x3803 = new activation_x3803
act
}

}
x3803_closure.loopStart = 0
x3803_closure.loopSize = x3755
val alloc: activation_x3803 = x3803_closure.alloc(resourceInfo)
var x3803: activation_x3803 = null
if (resourceInfo.availableThreads <= 1) {
x3803 = x3803_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3803] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3803](x3803_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3803_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3803 = x3803_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3803
}}

/**********/

