package generated.scala
//activation record for fat loop
final class activation_x2713 {
var left_act: activation_x2713 = _
var x2713: Array[FixedPoint[Signed,B32,B0]] = _
var x2713_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x2713 {
}
object kernel_x2713 {
def apply(resourceInfo:generated.scala.ResourceInfo,x5:Int): activation_x2713 = {
val x2713_closure = new generated.scala.DeliteOpMultiLoop[activation_x2713] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x5
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2713 = {
val __act: activation_x2713 = new activation_x2713()
val x10 = (loopSize).asInstanceOf[Int]
if (x10 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2677 = new Array[FixedPoint[Signed,B32,B0]](x10.toInt)
__act.x2713_data = x2677
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2713,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2713]): activation_x2713 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2713 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2713 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2713): activation_x2713 = {
val act: activation_x2713 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2713,start:Long,end:Long): activation_x2713 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2713 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2713,x6:Int,isEmpty:Boolean): activation_x2713 = {
if (!isEmpty) {
process(resourceInfo,__act,x6)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2713,x6:Int): Unit = {
val x7 = {
FixedPoint[Signed,B32,B0](x6)
}
val x9 = x7
val x8 = __act.x2713_data
val x2681 = x8(x6.toInt) = x9
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2713,rhs:activation_x2713): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2713,lhs:activation_x2713): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2713): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2713): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2713): Unit = {
var x8: Array[FixedPoint[Signed,B32,B0]] = __act.x2713_data
__act.x2713_data = null
__act.x2713 = x8
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2713 = {
val act: activation_x2713 = new activation_x2713
act
}

}
x2713_closure.loopStart = 0
x2713_closure.loopSize = x5
val alloc: activation_x2713 = x2713_closure.alloc(resourceInfo)
var x2713: activation_x2713 = null
if (resourceInfo.availableThreads <= 1) {
x2713 = x2713_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2713] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2713](x2713_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2713_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2713 = x2713_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2713
}}

/**********/

