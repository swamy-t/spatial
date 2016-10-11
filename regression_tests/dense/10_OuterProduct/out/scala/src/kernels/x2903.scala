package generated.scala
//activation record for fat loop
final class activation_x2903 {
var left_act: activation_x2903 = _
var x2903: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x2903_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x2903 {
}
object kernel_x2903 {
def apply(resourceInfo:generated.scala.ResourceInfo,x5:Int,x2713:Array[FixedPoint[Signed,B32,B0]],x2751:Array[FixedPoint[Signed,B32,B0]],x51:Int): activation_x2903 = {
val x2903_closure = new generated.scala.DeliteOpMultiLoop[activation_x2903] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x5
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2903 = {
val __act: activation_x2903 = new activation_x2903()
val x265 = (loopSize).asInstanceOf[Int]
if (x265 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2867 = new Array[Array[FixedPoint[Signed,B32,B0]]](x265.toInt)
__act.x2903_data = x2867
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2903,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2903]): activation_x2903 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2903 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2903 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2903): activation_x2903 = {
val act: activation_x2903 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2903,start:Long,end:Long): activation_x2903 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2903 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2903,x211:Int,isEmpty:Boolean): activation_x2903 = {
if (!isEmpty) {
process(resourceInfo,__act,x211)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2903,x211:Int): Unit = {
val x212 = {
FixedPoint[Signed,B32,B0](x211)
}
val x215 = {
x212.toInt
}
val x2827 = x2713(x215.toInt)
var x222: Int = x51
if (x222 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2830 = new Array[FixedPoint[Signed,B32,B0]](x222.toInt)
val x2866_data: Array[FixedPoint[Signed,B32,B0]] = x2830
var x2866_size: Int = 0
var x2866_conditionals: Int = 0
var x213: Int = 0
while (x213 < x51) {  // begin fat loop x2866
val x214 = {
FixedPoint[Signed,B32,B0](x213)
}
val x217 = {
x214.toInt
}
val x2828 = x2751(x217.toInt)
val x2829 = {
x2827 * x2828
}
val x221 = x2829
val x220 = x2866_data
val x2834 = x220(x213.toInt) = x221
x213 = x213 + 1
} // end fat loop x2866
val x220 = x2866_data
val x2866 = x220
val x264 = x2866
val x263 = __act.x2903_data
val x2871 = x263(x211.toInt) = x264
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2903,rhs:activation_x2903): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2903,lhs:activation_x2903): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2903): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2903): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2903): Unit = {
var x263: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x2903_data
__act.x2903_data = null
__act.x2903 = x263
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2903 = {
val act: activation_x2903 = new activation_x2903
act
}

}
x2903_closure.loopStart = 0
x2903_closure.loopSize = x5
val alloc: activation_x2903 = x2903_closure.alloc(resourceInfo)
var x2903: activation_x2903 = null
if (resourceInfo.availableThreads <= 1) {
x2903 = x2903_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2903] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2903](x2903_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2903_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2903 = x2903_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2903
}}

/**********/

