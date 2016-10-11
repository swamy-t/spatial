package generated.scala
//activation record for thin loop
final class activation_x1773 {
var left_act: activation_x1773 = _
var x1773: Array[FixedPoint[Signed,B32,B0]] = _
var x1773_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1773 {
}
object kernel_x1773 {
def apply(resourceInfo:generated.scala.ResourceInfo,x125:Int,x124:FixedPoint[Signed,B32,B0]): activation_x1773 = {
// a *thin* loop follows: x1773
val x1773_closure = new generated.scala.DeliteOpMultiLoop[activation_x1773] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x125
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1773 = {
val __act: activation_x1773 = new activation_x1773()
val x131 = (loopSize).asInstanceOf[Int]
if (x131 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1737 = new Array[FixedPoint[Signed,B32,B0]](x131.toInt)
__act.x1773_data = x1737
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1773,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1773]): activation_x1773 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1773 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1773 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1773): activation_x1773 = {
val act: activation_x1773 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1773,start:Long,end:Long): activation_x1773 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1773 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1773,x126:Int,isEmpty:Boolean): activation_x1773 = {
if (!isEmpty) {
process(resourceInfo,__act,x126)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1773,x126:Int): Unit = {
val x1735 = {
FixedPoint.randbnd[Signed,B32,B0](x124)
}
val x130 = x1735
val x129 = __act.x1773_data
val x1741 = x129(x126.toInt) = x130
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1773,rhs:activation_x1773): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1773,lhs:activation_x1773): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1773): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1773): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1773): Unit = {
var x129: Array[FixedPoint[Signed,B32,B0]] = __act.x1773_data
__act.x1773_data = null
__act.x1773 = x129
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1773 = {
val act: activation_x1773 = new activation_x1773
act
}

}
x1773_closure.loopStart = 0
x1773_closure.loopSize = x125
val alloc: activation_x1773 = x1773_closure.alloc(resourceInfo)
var x1773: activation_x1773 = null
if (resourceInfo.availableThreads <= 1) {
x1773 = x1773_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1773] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1773](x1773_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1773_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1773 = x1773_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1773
}}

/**********/

