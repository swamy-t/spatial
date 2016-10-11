package generated.scala
//activation record for fat loop
final class activation_x610 {
var left_act: activation_x610 = _
var x610: Array[FixedPoint[Signed,B32,B0]] = _
var x610_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x610 {
}
object kernel_x610 {
def apply(resourceInfo:generated.scala.ResourceInfo,x46:Int): activation_x610 = {
val x610_closure = new generated.scala.DeliteOpMultiLoop[activation_x610] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x46
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x610 = {
val __act: activation_x610 = new activation_x610()
val x51 = (loopSize).asInstanceOf[Int]
if (x51 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x574 = new Array[FixedPoint[Signed,B32,B0]](x51.toInt)
__act.x610_data = x574
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x610,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x610]): activation_x610 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x610 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x610 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x610): activation_x610 = {
val act: activation_x610 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x610,start:Long,end:Long): activation_x610 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x610 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x610,x47:Int,isEmpty:Boolean): activation_x610 = {
if (!isEmpty) {
process(resourceInfo,__act,x47)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x610,x47:Int): Unit = {
val x48 = {
FixedPoint[Signed,B32,B0](x47)
}
val x50 = x48
val x49 = __act.x610_data
val x578 = x49(x47.toInt) = x50
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x610,rhs:activation_x610): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x610,lhs:activation_x610): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x610): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x610): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x610): Unit = {
var x49: Array[FixedPoint[Signed,B32,B0]] = __act.x610_data
__act.x610_data = null
__act.x610 = x49
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x610 = {
val act: activation_x610 = new activation_x610
act
}

}
x610_closure.loopStart = 0
x610_closure.loopSize = x46
val alloc: activation_x610 = x610_closure.alloc(resourceInfo)
var x610: activation_x610 = null
if (resourceInfo.availableThreads <= 1) {
x610 = x610_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x610] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x610](x610_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x610_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x610 = x610_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x610
}}

/**********/

