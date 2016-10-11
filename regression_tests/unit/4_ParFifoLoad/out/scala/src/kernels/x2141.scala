package generated.scala
//activation record for fat loop
final class activation_x2141 {
var left_act: activation_x2141 = _
var x2141: Array[FixedPoint[Signed,B32,B0]] = _
var x2141_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x2141 {
}
object kernel_x2141 {
def apply(resourceInfo:generated.scala.ResourceInfo,x161:Int,x2129:Array[FixedPoint[Signed,B32,B0]],x2136:Array[FixedPoint[Signed,B32,B0]]): activation_x2141 = {
val x2141_closure = new generated.scala.DeliteOpMultiLoop[activation_x2141] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x161
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2141 = {
val __act: activation_x2141 = new activation_x2141()
val x314 = (loopSize).asInstanceOf[Int]
if (x314 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2071 = new Array[FixedPoint[Signed,B32,B0]](x314.toInt)
__act.x2141_data = x2071
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2141,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2141]): activation_x2141 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2141 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2141 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2141): activation_x2141 = {
val act: activation_x2141 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2141,start:Long,end:Long): activation_x2141 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2141 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2141,x308:Int,isEmpty:Boolean): activation_x2141 = {
if (!isEmpty) {
process(resourceInfo,__act,x308)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2141,x308:Int): Unit = {
val x2130 = x2129(x308.toInt)
val x2137 = x2136(x308.toInt)
val x2138 = {
x2130 * x2137
}
val x313 = x2138
val x312 = __act.x2141_data
val x2075 = x312(x308.toInt) = x313
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2141,rhs:activation_x2141): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2141,lhs:activation_x2141): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2141): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2141): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2141): Unit = {
var x312: Array[FixedPoint[Signed,B32,B0]] = __act.x2141_data
__act.x2141_data = null
__act.x2141 = x312
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2141 = {
val act: activation_x2141 = new activation_x2141
act
}

}
x2141_closure.loopStart = 0
x2141_closure.loopSize = x161
val alloc: activation_x2141 = x2141_closure.alloc(resourceInfo)
var x2141: activation_x2141 = null
if (resourceInfo.availableThreads <= 1) {
x2141 = x2141_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2141] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2141](x2141_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2141_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2141 = x2141_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2141
}}

/**********/

