package generated.scala
//activation record for fat loop
final class activation_x4533 {
var left_act: activation_x4533 = _
var x4533: Array[FixedPoint[Signed,B32,B0]] = _
var x4533_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x4533 {
}
object kernel_x4533 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6:Int): activation_x4533 = {
val x4533_closure = new generated.scala.DeliteOpMultiLoop[activation_x4533] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x4533 = {
val __act: activation_x4533 = new activation_x4533()
val x149 = (loopSize).asInstanceOf[Int]
if (x149 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4497 = new Array[FixedPoint[Signed,B32,B0]](x149.toInt)
__act.x4533_data = x4497
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4533,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x4533]): activation_x4533 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x4533 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x4533 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4533): activation_x4533 = {
val act: activation_x4533 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4533,start:Long,end:Long): activation_x4533 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x4533 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4533,x145:Int,isEmpty:Boolean): activation_x4533 = {
if (!isEmpty) {
process(resourceInfo,__act,x145)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4533,x145:Int): Unit = {
val x146 = {
FixedPoint[Signed,B32,B0](x145)
}
val x148 = x146
val x147 = __act.x4533_data
val x4501 = x147(x145.toInt) = x148
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4533,rhs:activation_x4533): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4533,lhs:activation_x4533): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4533): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4533): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4533): Unit = {
var x147: Array[FixedPoint[Signed,B32,B0]] = __act.x4533_data
__act.x4533_data = null
__act.x4533 = x147
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x4533 = {
val act: activation_x4533 = new activation_x4533
act
}

}
x4533_closure.loopStart = 0
x4533_closure.loopSize = x6
val alloc: activation_x4533 = x4533_closure.alloc(resourceInfo)
var x4533: activation_x4533 = null
if (resourceInfo.availableThreads <= 1) {
x4533 = x4533_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x4533] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x4533](x4533_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x4533_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x4533 = x4533_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x4533
}}

/**********/

