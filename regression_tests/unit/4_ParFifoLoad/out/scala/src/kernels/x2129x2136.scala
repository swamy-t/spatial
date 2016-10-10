package generated.scala
//activation record for fat loop
final class activation_x2129x2136 {
var left_act: activation_x2129x2136 = _
var x2129: Array[FixedPoint[Signed,B32,B0]] = _
var x2129_data: Array[FixedPoint[Signed,B32,B0]] = _
var x2136: Array[FixedPoint[Signed,B32,B0]] = _
var x2136_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x2129x2136 {
}
object kernel_x2129x2136 {
def apply(resourceInfo:generated.scala.ResourceInfo,x161:Int,x51:FixedPoint[Signed,B32,B0]): activation_x2129x2136 = {
val x2129x2136_closure = new generated.scala.DeliteOpMultiLoop[activation_x2129x2136] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x161
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2129x2136 = {
val __act: activation_x2129x2136 = new activation_x2129x2136()
val x166 = (loopSize).asInstanceOf[Int]
if (x166 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1994 = new Array[FixedPoint[Signed,B32,B0]](x166.toInt)
__act.x2129_data = x1994
val x212 = (loopSize).asInstanceOf[Int]
if (x212 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2031 = new Array[FixedPoint[Signed,B32,B0]](x212.toInt)
__act.x2136_data = x2031
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2129x2136,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2129x2136]): activation_x2129x2136 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2129x2136 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2129x2136 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2129x2136): activation_x2129x2136 = {
val act: activation_x2129x2136 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2129x2136,start:Long,end:Long): activation_x2129x2136 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2129x2136 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2129x2136,x162:Int,isEmpty:Boolean): activation_x2129x2136 = {
if (!isEmpty) {
process(resourceInfo,__act,x162)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2129x2136,x162:Int): Unit = {
val x163 = {
FixedPoint[Signed,B32,B0](x162)
}
val x2131 = {
x163 * x51
}
val x165 = x163
val x164 = __act.x2129_data
val x1998 = x164(x162.toInt) = x165
val x211 = x2131
val x210 = __act.x2136_data
val x2134 = x210(x162.toInt) = x211
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2129x2136,rhs:activation_x2129x2136): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2129x2136,lhs:activation_x2129x2136): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2129x2136): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2129x2136): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2129x2136): Unit = {
var x164: Array[FixedPoint[Signed,B32,B0]] = __act.x2129_data
__act.x2129_data = null
__act.x2129 = x164
var x210: Array[FixedPoint[Signed,B32,B0]] = __act.x2136_data
__act.x2136_data = null
__act.x2136 = x210
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2129x2136 = {
val act: activation_x2129x2136 = new activation_x2129x2136
act
}

}
x2129x2136_closure.loopStart = 0
x2129x2136_closure.loopSize = x161
val alloc: activation_x2129x2136 = x2129x2136_closure.alloc(resourceInfo)
var x2129x2136: activation_x2129x2136 = null
if (resourceInfo.availableThreads <= 1) {
x2129x2136 = x2129x2136_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2129x2136] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2129x2136](x2129x2136_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2129x2136_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2129x2136 = x2129x2136_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2129x2136
}}

/**********/

