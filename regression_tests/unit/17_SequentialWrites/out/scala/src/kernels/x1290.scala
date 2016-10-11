package generated.scala
//activation record for fat loop
final class activation_x1290 {
var left_act: activation_x1290 = _
var x1290: Array[FixedPoint[Signed,B32,B0]] = _
var x1290_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1290 {
}
object kernel_x1290 {
def apply(resourceInfo:generated.scala.ResourceInfo,x4:Int): activation_x1290 = {
val x1290_closure = new generated.scala.DeliteOpMultiLoop[activation_x1290] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x4
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1290 = {
val __act: activation_x1290 = new activation_x1290()
val x9 = (loopSize).asInstanceOf[Int]
if (x9 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1254 = new Array[FixedPoint[Signed,B32,B0]](x9.toInt)
__act.x1290_data = x1254
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1290,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1290]): activation_x1290 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1290 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1290 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1290): activation_x1290 = {
val act: activation_x1290 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1290,start:Long,end:Long): activation_x1290 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1290 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1290,x5:Int,isEmpty:Boolean): activation_x1290 = {
if (!isEmpty) {
process(resourceInfo,__act,x5)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1290,x5:Int): Unit = {
val x6 = {
FixedPoint[Signed,B32,B0](x5)
}
val x8 = x6
val x7 = __act.x1290_data
val x1258 = x7(x5.toInt) = x8
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1290,rhs:activation_x1290): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1290,lhs:activation_x1290): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1290): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1290): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1290): Unit = {
var x7: Array[FixedPoint[Signed,B32,B0]] = __act.x1290_data
__act.x1290_data = null
__act.x1290 = x7
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1290 = {
val act: activation_x1290 = new activation_x1290
act
}

}
x1290_closure.loopStart = 0
x1290_closure.loopSize = x4
val alloc: activation_x1290 = x1290_closure.alloc(resourceInfo)
var x1290: activation_x1290 = null
if (resourceInfo.availableThreads <= 1) {
x1290 = x1290_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1290] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1290](x1290_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1290_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1290 = x1290_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1290
}}

/**********/

