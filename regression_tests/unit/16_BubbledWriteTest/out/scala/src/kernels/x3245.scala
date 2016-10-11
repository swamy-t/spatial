package generated.scala
//activation record for fat loop
final class activation_x3245 {
var left_act: activation_x3245 = _
var x3245: Array[Boolean] = _
var x3245_data: Array[Boolean] = _
}
object activation_x3245 {
}
object kernel_x3245 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3229:Int,x2959:Array[FixedPoint[Signed,B32,B0]],x3228:Array[FixedPoint[Signed,B32,B0]]): activation_x3245 = {
val x3245_closure = new generated.scala.DeliteOpMultiLoop[activation_x3245] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3229
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3245 = {
val __act: activation_x3245 = new activation_x3245()
val x518 = (loopSize).asInstanceOf[Int]
if (x518 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3170 = new Array[Boolean](x518.toInt)
__act.x3245_data = x3170
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3245,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3245]): activation_x3245 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3245 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3245 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3245): activation_x3245 = {
val act: activation_x3245 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3245,start:Long,end:Long): activation_x3245 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3245 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3245,x511:Int,isEmpty:Boolean): activation_x3245 = {
if (!isEmpty) {
process(resourceInfo,__act,x511)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3245,x511:Int): Unit = {
val x3166 = x2959(x511.toInt)
val x3240 = x3228(x511.toInt)
val x3241 = {
x3240 == x3166
}
val x517 = x3241
val x516 = __act.x3245_data
val x3174 = x516(x511.toInt) = x517
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3245,rhs:activation_x3245): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3245,lhs:activation_x3245): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3245): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3245): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3245): Unit = {
var x516: Array[Boolean] = __act.x3245_data
__act.x3245_data = null
__act.x3245 = x516
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3245 = {
val act: activation_x3245 = new activation_x3245
act
}

}
x3245_closure.loopStart = 0
x3245_closure.loopSize = x3229
val alloc: activation_x3245 = x3245_closure.alloc(resourceInfo)
var x3245: activation_x3245 = null
if (resourceInfo.availableThreads <= 1) {
x3245 = x3245_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3245] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3245](x3245_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3245_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3245 = x3245_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3245
}}

/**********/

