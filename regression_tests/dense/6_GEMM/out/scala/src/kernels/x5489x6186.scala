package generated.scala
//activation record for fat loop
final class activation_x5489x6186 {
var left_act: activation_x5489x6186 = _
var x5489: Array[FixedPoint[Signed,B32,B0]] = _
var x5489_data: Array[FixedPoint[Signed,B32,B0]] = _
var x6186: Array[FixedPoint[Signed,B32,B0]] = _
var x6186_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x5489x6186 {
}
object kernel_x5489x6186 {
def apply(resourceInfo:generated.scala.ResourceInfo,x99:Int,x11:FixedPoint[Signed,B32,B0],x189:FixedPoint[Signed,B32,B0]): activation_x5489x6186 = {
val x5489x6186_closure = new generated.scala.DeliteOpMultiLoop[activation_x5489x6186] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x99
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5489x6186 = {
val __act: activation_x5489x6186 = new activation_x5489x6186()
val x103 = (loopSize).asInstanceOf[Int]
if (x103 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5453 = new Array[FixedPoint[Signed,B32,B0]](x103.toInt)
__act.x5489_data = x5453
val x192 = (loopSize).asInstanceOf[Int]
if (x192 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5566 = new Array[FixedPoint[Signed,B32,B0]](x192.toInt)
__act.x6186_data = x5566
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5489x6186,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5489x6186]): activation_x5489x6186 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5489x6186 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5489x6186 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5489x6186): activation_x5489x6186 = {
val act: activation_x5489x6186 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5489x6186,start:Long,end:Long): activation_x5489x6186 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5489x6186 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5489x6186,x100:Int,isEmpty:Boolean): activation_x5489x6186 = {
if (!isEmpty) {
process(resourceInfo,__act,x100)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5489x6186,x100:Int): Unit = {
val x102 = x11
val x101 = __act.x5489_data
val x5457 = x101(x100.toInt) = x102
val x191 = x189
val x190 = __act.x6186_data
val x6184 = x190(x100.toInt) = x191
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5489x6186,rhs:activation_x5489x6186): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5489x6186,lhs:activation_x5489x6186): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5489x6186): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5489x6186): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5489x6186): Unit = {
var x101: Array[FixedPoint[Signed,B32,B0]] = __act.x5489_data
__act.x5489_data = null
__act.x5489 = x101
var x190: Array[FixedPoint[Signed,B32,B0]] = __act.x6186_data
__act.x6186_data = null
__act.x6186 = x190
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5489x6186 = {
val act: activation_x5489x6186 = new activation_x5489x6186
act
}

}
x5489x6186_closure.loopStart = 0
x5489x6186_closure.loopSize = x99
val alloc: activation_x5489x6186 = x5489x6186_closure.alloc(resourceInfo)
var x5489x6186: activation_x5489x6186 = null
if (resourceInfo.availableThreads <= 1) {
x5489x6186 = x5489x6186_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5489x6186] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5489x6186](x5489x6186_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5489x6186_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5489x6186 = x5489x6186_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5489x6186
}}

/**********/

