package generated.scala
//activation record for fat loop
final class activation_x6232 {
var left_act: activation_x6232 = _
var x6232: Array[Boolean] = _
var x6232_data: Array[Boolean] = _
}
object activation_x6232 {
}
object kernel_x6232 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6208:Int,x5835:Array[FixedPoint[Signed,B32,B0]],x6207:Array[FixedPoint[Signed,B32,B0]]): activation_x6232 = {
val x6232_closure = new generated.scala.DeliteOpMultiLoop[activation_x6232] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6208
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6232 = {
val __act: activation_x6232 = new activation_x6232()
val x1052 = (loopSize).asInstanceOf[Int]
if (x1052 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x6131 = new Array[Boolean](x1052.toInt)
__act.x6232_data = x6131
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6232,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6232]): activation_x6232 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6232 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6232 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6232): activation_x6232 = {
val act: activation_x6232 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6232,start:Long,end:Long): activation_x6232 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6232 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6232,x1045:Int,isEmpty:Boolean): activation_x6232 = {
if (!isEmpty) {
process(resourceInfo,__act,x1045)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6232,x1045:Int): Unit = {
val x6127 = x5835(x1045.toInt)
val x6227 = x6207(x1045.toInt)
val x6228 = {
x6227 == x6127
}
val x1051 = x6228
val x1050 = __act.x6232_data
val x6135 = x1050(x1045.toInt) = x1051
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6232,rhs:activation_x6232): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6232,lhs:activation_x6232): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6232): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6232): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6232): Unit = {
var x1050: Array[Boolean] = __act.x6232_data
__act.x6232_data = null
__act.x6232 = x1050
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6232 = {
val act: activation_x6232 = new activation_x6232
act
}

}
x6232_closure.loopStart = 0
x6232_closure.loopSize = x6208
val alloc: activation_x6232 = x6232_closure.alloc(resourceInfo)
var x6232: activation_x6232 = null
if (resourceInfo.availableThreads <= 1) {
x6232 = x6232_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6232] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6232](x6232_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6232_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6232 = x6232_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6232
}}

/**********/

