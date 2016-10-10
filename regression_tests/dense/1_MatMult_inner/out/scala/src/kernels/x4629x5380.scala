package generated.scala
//activation record for fat loop
final class activation_x4629x5380 {
var left_act: activation_x4629x5380 = _
var x4629: Array[FixedPoint[Signed,B32,B0]] = _
var x4629_data: Array[FixedPoint[Signed,B32,B0]] = _
var x5380: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x5380_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x4629x5380 {
}
object kernel_x4629x5380 {
def apply(resourceInfo:generated.scala.ResourceInfo,x9:Int,x11:FixedPoint[Signed,B32,B0],x4742:Array[FixedPoint[Signed,B32,B0]]): activation_x4629x5380 = {
val x4629x5380_closure = new generated.scala.DeliteOpMultiLoop[activation_x4629x5380] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x9
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x4629x5380 = {
val __act: activation_x4629x5380 = new activation_x4629x5380()
val x14 = (loopSize).asInstanceOf[Int]
if (x14 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4593 = new Array[FixedPoint[Signed,B32,B0]](x14.toInt)
__act.x4629_data = x4593
val x146 = (loopSize).asInstanceOf[Int]
if (x146 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4743 = new Array[Array[FixedPoint[Signed,B32,B0]]](x146.toInt)
__act.x5380_data = x4743
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4629x5380,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x4629x5380]): activation_x4629x5380 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x4629x5380 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x4629x5380 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4629x5380): activation_x4629x5380 = {
val act: activation_x4629x5380 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4629x5380,start:Long,end:Long): activation_x4629x5380 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x4629x5380 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4629x5380,x10:Int,isEmpty:Boolean): activation_x4629x5380 = {
if (!isEmpty) {
process(resourceInfo,__act,x10)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4629x5380,x10:Int): Unit = {
val x13 = x11
val x12 = __act.x4629_data
val x4597 = x12(x10.toInt) = x13
val x145 = x4742
val x144 = __act.x5380_data
val x5378 = x144(x10.toInt) = x145
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4629x5380,rhs:activation_x4629x5380): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4629x5380,lhs:activation_x4629x5380): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4629x5380): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4629x5380): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4629x5380): Unit = {
var x12: Array[FixedPoint[Signed,B32,B0]] = __act.x4629_data
__act.x4629_data = null
__act.x4629 = x12
var x144: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x5380_data
__act.x5380_data = null
__act.x5380 = x144
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x4629x5380 = {
val act: activation_x4629x5380 = new activation_x4629x5380
act
}

}
x4629x5380_closure.loopStart = 0
x4629x5380_closure.loopSize = x9
val alloc: activation_x4629x5380 = x4629x5380_closure.alloc(resourceInfo)
var x4629x5380: activation_x4629x5380 = null
if (resourceInfo.availableThreads <= 1) {
x4629x5380 = x4629x5380_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x4629x5380] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x4629x5380](x4629x5380_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x4629x5380_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x4629x5380 = x4629x5380_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x4629x5380
}}

/**********/

