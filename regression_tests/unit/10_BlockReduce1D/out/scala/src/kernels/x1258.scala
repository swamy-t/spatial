package generated.scala
//activation record for fat loop
final class activation_x1258 {
var left_act: activation_x1258 = _
var x1258: Array[FixedPoint[Signed,B32,B0]] = _
var x1258_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1258 {
}
object kernel_x1258 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int): activation_x1258 = {
val x1258_closure = new generated.scala.DeliteOpMultiLoop[activation_x1258] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1258 = {
val __act: activation_x1258 = new activation_x1258()
val x8 = (loopSize).asInstanceOf[Int]
if (x8 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1222 = new Array[FixedPoint[Signed,B32,B0]](x8.toInt)
__act.x1258_data = x1222
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1258,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1258]): activation_x1258 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1258 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1258 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1258): activation_x1258 = {
val act: activation_x1258 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1258,start:Long,end:Long): activation_x1258 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1258 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1258,x4:Int,isEmpty:Boolean): activation_x1258 = {
if (!isEmpty) {
process(resourceInfo,__act,x4)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1258,x4:Int): Unit = {
val x5 = {
FixedPoint[Signed,B32,B0](x4)
}
val x7 = x5
val x6 = __act.x1258_data
val x1226 = x6(x4.toInt) = x7
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1258,rhs:activation_x1258): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1258,lhs:activation_x1258): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1258): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1258): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1258): Unit = {
var x6: Array[FixedPoint[Signed,B32,B0]] = __act.x1258_data
__act.x1258_data = null
__act.x1258 = x6
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1258 = {
val act: activation_x1258 = new activation_x1258
act
}

}
x1258_closure.loopStart = 0
x1258_closure.loopSize = x3
val alloc: activation_x1258 = x1258_closure.alloc(resourceInfo)
var x1258: activation_x1258 = null
if (resourceInfo.availableThreads <= 1) {
x1258 = x1258_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1258] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1258](x1258_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1258_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1258 = x1258_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1258
}}

/**********/

