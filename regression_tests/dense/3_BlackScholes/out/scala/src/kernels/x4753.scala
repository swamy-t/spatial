package generated.scala
//activation record for fat loop
final class activation_x4753 {
var left_act: activation_x4753 = _
var x4753: Array[Boolean] = _
var x4753_data: Array[Boolean] = _
}
object activation_x4753 {
}
object kernel_x4753 {
def apply(resourceInfo:generated.scala.ResourceInfo,x4701:Int,x4568:Array[FloatPoint[B24,B8]],x412:FloatPoint[B24,B8],x4693:Array[FloatPoint[B24,B8]]): activation_x4753 = {
val x4753_closure = new generated.scala.DeliteOpMultiLoop[activation_x4753] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x4701
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x4753 = {
val __act: activation_x4753 = new activation_x4753()
val x689 = (loopSize).asInstanceOf[Int]
if (x689 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4717 = new Array[Boolean](x689.toInt)
__act.x4753_data = x4717
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4753,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x4753]): activation_x4753 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x4753 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x4753 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4753): activation_x4753 = {
val act: activation_x4753 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4753,start:Long,end:Long): activation_x4753 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x4753 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4753,x678:Int,isEmpty:Boolean): activation_x4753 = {
if (!isEmpty) {
process(resourceInfo,__act,x678)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4753,x678:Int): Unit = {
val x4709 = x4568(x678.toInt)
val x4710 = {
x4709 + x412
}
val x4711 = x4693(x678.toInt)
val x4712 = {
x4711 < x4710
}
val x4713 = {
x4709 - x412
}
val x4714 = {
x4713 < x4711
}
val x4715 = {
x4712 && x4714
}
val x688 = x4715
val x687 = __act.x4753_data
val x4721 = x687(x678.toInt) = x688
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4753,rhs:activation_x4753): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4753,lhs:activation_x4753): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4753): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4753): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4753): Unit = {
var x687: Array[Boolean] = __act.x4753_data
__act.x4753_data = null
__act.x4753 = x687
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x4753 = {
val act: activation_x4753 = new activation_x4753
act
}

}
x4753_closure.loopStart = 0
x4753_closure.loopSize = x4701
val alloc: activation_x4753 = x4753_closure.alloc(resourceInfo)
var x4753: activation_x4753 = null
if (resourceInfo.availableThreads <= 1) {
x4753 = x4753_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x4753] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x4753](x4753_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x4753_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x4753 = x4753_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x4753
}}

/**********/

