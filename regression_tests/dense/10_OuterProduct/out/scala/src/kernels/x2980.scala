package generated.scala
//activation record for fat loop
final class activation_x2980 {
var left_act: activation_x2980 = _
var x2980: Array[FixedPoint[Signed,B32,B0]] = _
var x2980_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x2980 {
}
object kernel_x2980 {
def apply(resourceInfo:generated.scala.ResourceInfo,x2942:Int,x2941:Array[FixedPoint[Signed,B32,B0]]): activation_x2980 = {
val x2980_closure = new generated.scala.DeliteOpMultiLoop[activation_x2980] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x2942
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2980 = {
val __act: activation_x2980 = new activation_x2980()
val x360 = (loopSize).asInstanceOf[Int]
if (x360 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2944 = new Array[FixedPoint[Signed,B32,B0]](x360.toInt)
__act.x2980_data = x2944
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2980,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2980]): activation_x2980 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2980 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2980 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2980): activation_x2980 = {
val act: activation_x2980 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2980,start:Long,end:Long): activation_x2980 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2980 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2980,x356:Int,isEmpty:Boolean): activation_x2980 = {
if (!isEmpty) {
process(resourceInfo,__act,x356)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2980,x356:Int): Unit = {
val x2943 = x2941(x356.toInt)
val x359 = x2943
val x358 = __act.x2980_data
val x2948 = x358(x356.toInt) = x359
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2980,rhs:activation_x2980): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2980,lhs:activation_x2980): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2980): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2980): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2980): Unit = {
var x358: Array[FixedPoint[Signed,B32,B0]] = __act.x2980_data
__act.x2980_data = null
__act.x2980 = x358
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2980 = {
val act: activation_x2980 = new activation_x2980
act
}

}
x2980_closure.loopStart = 0
x2980_closure.loopSize = x2942
val alloc: activation_x2980 = x2980_closure.alloc(resourceInfo)
var x2980: activation_x2980 = null
if (resourceInfo.availableThreads <= 1) {
x2980 = x2980_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2980] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2980](x2980_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2980_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2980 = x2980_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2980
}}

/**********/

