package generated.scala
//activation record for fat loop
final class activation_x1041 {
var left_act: activation_x1041 = _
var x1041: Array[FixedPoint[Signed,B32,B0]] = _
var x1041_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1041 {
}
object kernel_x1041 {
def apply(resourceInfo:generated.scala.ResourceInfo,x2:Int): activation_x1041 = {
val x1041_closure = new generated.scala.DeliteOpMultiLoop[activation_x1041] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x2
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1041 = {
val __act: activation_x1041 = new activation_x1041()
val x7 = (loopSize).asInstanceOf[Int]
if (x7 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1005 = new Array[FixedPoint[Signed,B32,B0]](x7.toInt)
__act.x1041_data = x1005
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1041,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1041]): activation_x1041 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1041 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1041 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1041): activation_x1041 = {
val act: activation_x1041 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1041,start:Long,end:Long): activation_x1041 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1041 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1041,x3:Int,isEmpty:Boolean): activation_x1041 = {
if (!isEmpty) {
process(resourceInfo,__act,x3)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1041,x3:Int): Unit = {
val x4 = {
FixedPoint[Signed,B32,B0](x3)
}
val x6 = x4
val x5 = __act.x1041_data
val x1009 = x5(x3.toInt) = x6
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1041,rhs:activation_x1041): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1041,lhs:activation_x1041): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1041): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1041): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1041): Unit = {
var x5: Array[FixedPoint[Signed,B32,B0]] = __act.x1041_data
__act.x1041_data = null
__act.x1041 = x5
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1041 = {
val act: activation_x1041 = new activation_x1041
act
}

}
x1041_closure.loopStart = 0
x1041_closure.loopSize = x2
val alloc: activation_x1041 = x1041_closure.alloc(resourceInfo)
var x1041: activation_x1041 = null
if (resourceInfo.availableThreads <= 1) {
x1041 = x1041_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1041] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1041](x1041_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1041_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1041 = x1041_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1041
}}

/**********/

