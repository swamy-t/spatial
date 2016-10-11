package generated.scala
//activation record for fat loop
final class activation_x745 {
var left_act: activation_x745 = _
var x745: Array[FixedPoint[Signed,B32,B0]] = _
var x745_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x745 {
}
object kernel_x745 {
def apply(resourceInfo:generated.scala.ResourceInfo,x4:Int,x2:FixedPoint[Signed,B32,B0]): activation_x745 = {
val x745_closure = new generated.scala.DeliteOpMultiLoop[activation_x745] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x4
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x745 = {
val __act: activation_x745 = new activation_x745()
val x10 = (loopSize).asInstanceOf[Int]
if (x10 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x709 = new Array[FixedPoint[Signed,B32,B0]](x10.toInt)
__act.x745_data = x709
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x745,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x745]): activation_x745 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x745 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x745 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x745): activation_x745 = {
val act: activation_x745 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x745,start:Long,end:Long): activation_x745 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x745 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x745,x5:Int,isEmpty:Boolean): activation_x745 = {
if (!isEmpty) {
process(resourceInfo,__act,x5)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x745,x5:Int): Unit = {
val x6 = {
FixedPoint[Signed,B32,B0](x5)
}
val x7 = {
x6 * x2
}
val x9 = x7
val x8 = __act.x745_data
val x713 = x8(x5.toInt) = x9
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x745,rhs:activation_x745): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x745,lhs:activation_x745): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x745): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x745): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x745): Unit = {
var x8: Array[FixedPoint[Signed,B32,B0]] = __act.x745_data
__act.x745_data = null
__act.x745 = x8
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x745 = {
val act: activation_x745 = new activation_x745
act
}

}
x745_closure.loopStart = 0
x745_closure.loopSize = x4
val alloc: activation_x745 = x745_closure.alloc(resourceInfo)
var x745: activation_x745 = null
if (resourceInfo.availableThreads <= 1) {
x745 = x745_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x745] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x745](x745_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x745_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x745 = x745_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x745
}}

/**********/

