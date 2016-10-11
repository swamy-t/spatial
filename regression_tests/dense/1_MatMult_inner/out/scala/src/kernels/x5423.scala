package generated.scala
//activation record for fat loop
final class activation_x5423 {
var left_act: activation_x5423 = _
var x5423: Array[Boolean] = _
var x5423_data: Array[Boolean] = _
}
object activation_x5423 {
}
object kernel_x5423 {
def apply(resourceInfo:generated.scala.ResourceInfo,x5279:Int,x5035:Array[FixedPoint[Signed,B32,B0]],x5399:Array[FixedPoint[Signed,B32,B0]]): activation_x5423 = {
val x5423_closure = new generated.scala.DeliteOpMultiLoop[activation_x5423] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x5279
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5423 = {
val __act: activation_x5423 = new activation_x5423()
val x835 = (loopSize).asInstanceOf[Int]
if (x835 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5331 = new Array[Boolean](x835.toInt)
__act.x5423_data = x5331
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5423,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5423]): activation_x5423 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5423 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5423 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5423): activation_x5423 = {
val act: activation_x5423 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5423,start:Long,end:Long): activation_x5423 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5423 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5423,x828:Int,isEmpty:Boolean): activation_x5423 = {
if (!isEmpty) {
process(resourceInfo,__act,x828)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5423,x828:Int): Unit = {
val x5327 = x5035(x828.toInt)
val x5418 = x5399(x828.toInt)
val x5419 = {
x5327 == x5418
}
val x834 = x5419
val x833 = __act.x5423_data
val x5335 = x833(x828.toInt) = x834
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5423,rhs:activation_x5423): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5423,lhs:activation_x5423): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5423): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5423): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5423): Unit = {
var x833: Array[Boolean] = __act.x5423_data
__act.x5423_data = null
__act.x5423 = x833
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5423 = {
val act: activation_x5423 = new activation_x5423
act
}

}
x5423_closure.loopStart = 0
x5423_closure.loopSize = x5279
val alloc: activation_x5423 = x5423_closure.alloc(resourceInfo)
var x5423: activation_x5423 = null
if (resourceInfo.availableThreads <= 1) {
x5423 = x5423_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5423] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5423](x5423_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5423_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5423 = x5423_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5423
}}

/**********/

