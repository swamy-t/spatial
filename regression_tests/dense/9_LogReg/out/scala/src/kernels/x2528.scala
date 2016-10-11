package generated.scala
//activation record for thin loop
final class activation_x2528 {
var left_act: activation_x2528 = _
var x2528: Array[FloatPoint[B24,B8]] = _
var x2528_data: Array[FloatPoint[B24,B8]] = _
}
object activation_x2528 {
}
object kernel_x2528 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6:Int,x147:FloatPoint[B24,B8]): activation_x2528 = {
// a *thin* loop follows: x2528
val x2528_closure = new generated.scala.DeliteOpMultiLoop[activation_x2528] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2528 = {
val __act: activation_x2528 = new activation_x2528()
val x153 = (loopSize).asInstanceOf[Int]
if (x153 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2492 = new Array[FloatPoint[B24,B8]](x153.toInt)
__act.x2528_data = x2492
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2528,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2528]): activation_x2528 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2528 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2528 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2528): activation_x2528 = {
val act: activation_x2528 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2528,start:Long,end:Long): activation_x2528 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2528 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2528,x146:Int,isEmpty:Boolean): activation_x2528 = {
if (!isEmpty) {
process(resourceInfo,__act,x146)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2528,x146:Int): Unit = {
val x2489 = {
FloatPoint.rand[B24,B8]
}
val x2490 = {
x2489 * x147
}
val x152 = x2490
val x151 = __act.x2528_data
val x2496 = x151(x146.toInt) = x152
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2528,rhs:activation_x2528): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2528,lhs:activation_x2528): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2528): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2528): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2528): Unit = {
var x151: Array[FloatPoint[B24,B8]] = __act.x2528_data
__act.x2528_data = null
__act.x2528 = x151
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2528 = {
val act: activation_x2528 = new activation_x2528
act
}

}
x2528_closure.loopStart = 0
x2528_closure.loopSize = x6
val alloc: activation_x2528 = x2528_closure.alloc(resourceInfo)
var x2528: activation_x2528 = null
if (resourceInfo.availableThreads <= 1) {
x2528 = x2528_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2528] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2528](x2528_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2528_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2528 = x2528_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2528
}}

/**********/

