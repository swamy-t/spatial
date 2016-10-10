package generated.scala
//activation record for thin loop
final class activation_x2710 {
var left_act: activation_x2710 = _
var x2710: Array[FixedPoint[Signed,B32,B0]] = _
var x2710_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x2710 {
}
object kernel_x2710 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x102:FixedPoint[Signed,B32,B0]): activation_x2710 = {
// a *thin* loop follows: x2710
val x2710_closure = new generated.scala.DeliteOpMultiLoop[activation_x2710] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2710 = {
val __act: activation_x2710 = new activation_x2710()
val x107 = (loopSize).asInstanceOf[Int]
if (x107 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2674 = new Array[FixedPoint[Signed,B32,B0]](x107.toInt)
__act.x2710_data = x2674
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2710,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2710]): activation_x2710 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2710 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2710 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2710): activation_x2710 = {
val act: activation_x2710 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2710,start:Long,end:Long): activation_x2710 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2710 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2710,x100:Int,isEmpty:Boolean): activation_x2710 = {
if (!isEmpty) {
process(resourceInfo,__act,x100)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2710,x100:Int): Unit = {
val x2671 = {
FixedPoint.rand[Signed,B32,B0]
}
val x2672 = {
x2671 / x102
}
val x106 = x2672
val x105 = __act.x2710_data
val x2678 = x105(x100.toInt) = x106
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2710,rhs:activation_x2710): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2710,lhs:activation_x2710): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2710): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2710): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2710): Unit = {
var x105: Array[FixedPoint[Signed,B32,B0]] = __act.x2710_data
__act.x2710_data = null
__act.x2710 = x105
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2710 = {
val act: activation_x2710 = new activation_x2710
act
}

}
x2710_closure.loopStart = 0
x2710_closure.loopSize = x3
val alloc: activation_x2710 = x2710_closure.alloc(resourceInfo)
var x2710: activation_x2710 = null
if (resourceInfo.availableThreads <= 1) {
x2710 = x2710_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2710] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2710](x2710_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2710_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2710 = x2710_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2710
}}

/**********/

