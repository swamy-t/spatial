package generated.scala
//activation record for fat loop
final class activation_x6261 {
var left_act: activation_x6261 = _
var x6261: Array[Boolean] = _
var x6261_data: Array[Boolean] = _
}
object activation_x6261 {
}
object kernel_x6261 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6234:Int,x5834:Array[FixedPoint[Signed,B32,B0]],x6224:Array[FixedPoint[Signed,B32,B0]]): activation_x6261 = {
val x6261_closure = new generated.scala.DeliteOpMultiLoop[activation_x6261] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6234
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6261 = {
val __act: activation_x6261 = new activation_x6261()
val x1024 = (loopSize).asInstanceOf[Int]
if (x1024 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x6146 = new Array[Boolean](x1024.toInt)
__act.x6261_data = x6146
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6261,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6261]): activation_x6261 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6261 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6261 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6261): activation_x6261 = {
val act: activation_x6261 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6261,start:Long,end:Long): activation_x6261 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6261 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6261,x1017:Int,isEmpty:Boolean): activation_x6261 = {
if (!isEmpty) {
process(resourceInfo,__act,x1017)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6261,x1017:Int): Unit = {
val x6142 = x5834(x1017.toInt)
val x6256 = x6224(x1017.toInt)
val x6257 = {
x6142 == x6256
}
val x1023 = x6257
val x1022 = __act.x6261_data
val x6150 = x1022(x1017.toInt) = x1023
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6261,rhs:activation_x6261): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6261,lhs:activation_x6261): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6261): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6261): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6261): Unit = {
var x1022: Array[Boolean] = __act.x6261_data
__act.x6261_data = null
__act.x6261 = x1022
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6261 = {
val act: activation_x6261 = new activation_x6261
act
}

}
x6261_closure.loopStart = 0
x6261_closure.loopSize = x6234
val alloc: activation_x6261 = x6261_closure.alloc(resourceInfo)
var x6261: activation_x6261 = null
if (resourceInfo.availableThreads <= 1) {
x6261 = x6261_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6261] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6261](x6261_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6261_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6261 = x6261_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6261
}}

/**********/

