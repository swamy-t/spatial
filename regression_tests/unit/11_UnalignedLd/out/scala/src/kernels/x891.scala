package generated.scala
//activation record for fat loop
final class activation_x891 {
var left_act: activation_x891 = _
var x891: Array[FixedPoint[Signed,B32,B0]] = _
var x891_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x891 {
}
object kernel_x891 {
def apply(resourceInfo:generated.scala.ResourceInfo,x99:Int): activation_x891 = {
val x891_closure = new generated.scala.DeliteOpMultiLoop[activation_x891] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x99
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x891 = {
val __act: activation_x891 = new activation_x891()
val x104 = (loopSize).asInstanceOf[Int]
if (x104 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x855 = new Array[FixedPoint[Signed,B32,B0]](x104.toInt)
__act.x891_data = x855
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x891,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x891]): activation_x891 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x891 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x891 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x891): activation_x891 = {
val act: activation_x891 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x891,start:Long,end:Long): activation_x891 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x891 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x891,x100:Int,isEmpty:Boolean): activation_x891 = {
if (!isEmpty) {
process(resourceInfo,__act,x100)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x891,x100:Int): Unit = {
val x101 = {
FixedPoint[Signed,B32,B0](x100)
}
val x103 = x101
val x102 = __act.x891_data
val x859 = x102(x100.toInt) = x103
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x891,rhs:activation_x891): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x891,lhs:activation_x891): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x891): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x891): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x891): Unit = {
var x102: Array[FixedPoint[Signed,B32,B0]] = __act.x891_data
__act.x891_data = null
__act.x891 = x102
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x891 = {
val act: activation_x891 = new activation_x891
act
}

}
x891_closure.loopStart = 0
x891_closure.loopSize = x99
val alloc: activation_x891 = x891_closure.alloc(resourceInfo)
var x891: activation_x891 = null
if (resourceInfo.availableThreads <= 1) {
x891 = x891_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x891] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x891](x891_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x891_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x891 = x891_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x891
}}

/**********/

