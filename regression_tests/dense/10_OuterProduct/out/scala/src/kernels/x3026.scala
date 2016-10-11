package generated.scala
//activation record for fat loop
final class activation_x3026 {
var left_act: activation_x3026 = _
var x3026: Array[FixedPoint[Signed,B32,B0]] = _
var x3026_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x3026 {
}
object kernel_x3026 {
def apply(resourceInfo:generated.scala.ResourceInfo,x2987:Int,x2825:Array[FixedPoint[Signed,B32,B0]]): activation_x3026 = {
val x3026_closure = new generated.scala.DeliteOpMultiLoop[activation_x3026] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x2987
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3026 = {
val __act: activation_x3026 = new activation_x3026()
val x417 = (loopSize).asInstanceOf[Int]
if (x417 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2990 = new Array[FixedPoint[Signed,B32,B0]](x417.toInt)
__act.x3026_data = x2990
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3026,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3026]): activation_x3026 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3026 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3026 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3026): activation_x3026 = {
val act: activation_x3026 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3026,start:Long,end:Long): activation_x3026 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3026 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3026,x412:Int,isEmpty:Boolean): activation_x3026 = {
if (!isEmpty) {
process(resourceInfo,__act,x412)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3026,x412:Int): Unit = {
val x2988 = x2825(x412.toInt)
val x416 = x2988
val x415 = __act.x3026_data
val x2994 = x415(x412.toInt) = x416
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3026,rhs:activation_x3026): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3026,lhs:activation_x3026): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3026): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3026): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3026): Unit = {
var x415: Array[FixedPoint[Signed,B32,B0]] = __act.x3026_data
__act.x3026_data = null
__act.x3026 = x415
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3026 = {
val act: activation_x3026 = new activation_x3026
act
}

}
x3026_closure.loopStart = 0
x3026_closure.loopSize = x2987
val alloc: activation_x3026 = x3026_closure.alloc(resourceInfo)
var x3026: activation_x3026 = null
if (resourceInfo.availableThreads <= 1) {
x3026 = x3026_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3026] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3026](x3026_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3026_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3026 = x3026_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3026
}}

/**********/

