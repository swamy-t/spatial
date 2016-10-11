package generated.scala
//activation record for thin loop
final class activation_x4318 {
var left_act: activation_x4318 = _
var x4318: Array[FixedPoint[Signed,B32,B0]] = _
var x4318_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x4318 {
}
object kernel_x4318 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6:Int,x9:FixedPoint[Signed,B32,B0]): activation_x4318 = {
// a *thin* loop follows: x4318
val x4318_closure = new generated.scala.DeliteOpMultiLoop[activation_x4318] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x4318 = {
val __act: activation_x4318 = new activation_x4318()
val x104 = (loopSize).asInstanceOf[Int]
if (x104 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4282 = new Array[FixedPoint[Signed,B32,B0]](x104.toInt)
__act.x4318_data = x4282
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4318,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x4318]): activation_x4318 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x4318 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x4318 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4318): activation_x4318 = {
val act: activation_x4318 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4318,start:Long,end:Long): activation_x4318 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x4318 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4318,x99:Int,isEmpty:Boolean): activation_x4318 = {
if (!isEmpty) {
process(resourceInfo,__act,x99)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4318,x99:Int): Unit = {
val x4280 = {
FixedPoint.randbnd[Signed,B32,B0](x9)
}
val x103 = x4280
val x102 = __act.x4318_data
val x4286 = x102(x99.toInt) = x103
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4318,rhs:activation_x4318): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4318,lhs:activation_x4318): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4318): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4318): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4318): Unit = {
var x102: Array[FixedPoint[Signed,B32,B0]] = __act.x4318_data
__act.x4318_data = null
__act.x4318 = x102
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x4318 = {
val act: activation_x4318 = new activation_x4318
act
}

}
x4318_closure.loopStart = 0
x4318_closure.loopSize = x6
val alloc: activation_x4318 = x4318_closure.alloc(resourceInfo)
var x4318: activation_x4318 = null
if (resourceInfo.availableThreads <= 1) {
x4318 = x4318_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x4318] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x4318](x4318_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x4318_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x4318 = x4318_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x4318
}}

/**********/

