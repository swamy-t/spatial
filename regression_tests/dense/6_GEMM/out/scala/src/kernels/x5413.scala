package generated.scala
//activation record for fat loop
final class activation_x5413 {
var left_act: activation_x5413 = _
var x5413: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x5413_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x5413 {
}
object kernel_x5413 {
def apply(resourceInfo:generated.scala.ResourceInfo,x7:Int,x5376:Array[FixedPoint[Signed,B32,B0]]): activation_x5413 = {
val x5413_closure = new generated.scala.DeliteOpMultiLoop[activation_x5413] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x7
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5413 = {
val __act: activation_x5413 = new activation_x5413()
val x57 = (loopSize).asInstanceOf[Int]
if (x57 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5377 = new Array[Array[FixedPoint[Signed,B32,B0]]](x57.toInt)
__act.x5413_data = x5377
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5413,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5413]): activation_x5413 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5413 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5413 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5413): activation_x5413 = {
val act: activation_x5413 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5413,start:Long,end:Long): activation_x5413 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5413 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5413,x8:Int,isEmpty:Boolean): activation_x5413 = {
if (!isEmpty) {
process(resourceInfo,__act,x8)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5413,x8:Int): Unit = {
val x56 = x5376
val x55 = __act.x5413_data
val x5381 = x55(x8.toInt) = x56
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5413,rhs:activation_x5413): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5413,lhs:activation_x5413): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5413): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5413): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5413): Unit = {
var x55: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x5413_data
__act.x5413_data = null
__act.x5413 = x55
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5413 = {
val act: activation_x5413 = new activation_x5413
act
}

}
x5413_closure.loopStart = 0
x5413_closure.loopSize = x7
val alloc: activation_x5413 = x5413_closure.alloc(resourceInfo)
var x5413: activation_x5413 = null
if (resourceInfo.availableThreads <= 1) {
x5413 = x5413_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5413] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5413](x5413_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5413_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5413 = x5413_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5413
}}

/**********/

