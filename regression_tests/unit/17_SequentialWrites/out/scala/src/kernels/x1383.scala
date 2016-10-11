package generated.scala
//activation record for fat loop
final class activation_x1383 {
var left_act: activation_x1383 = _
var x1383: Array[FixedPoint[Signed,B32,B0]] = _
var x1383_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1383 {
}
object kernel_x1383 {
def apply(resourceInfo:generated.scala.ResourceInfo,x4:Int,x132:FixedPoint[Signed,B32,B0],x129:FixedPoint[Signed,B32,B0]): activation_x1383 = {
val x1383_closure = new generated.scala.DeliteOpMultiLoop[activation_x1383] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x4
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1383 = {
val __act: activation_x1383 = new activation_x1383()
val x137 = (loopSize).asInstanceOf[Int]
if (x137 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1347 = new Array[FixedPoint[Signed,B32,B0]](x137.toInt)
__act.x1383_data = x1347
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1383,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1383]): activation_x1383 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1383 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1383 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1383): activation_x1383 = {
val act: activation_x1383 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1383,start:Long,end:Long): activation_x1383 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1383 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1383,x130:Int,isEmpty:Boolean): activation_x1383 = {
if (!isEmpty) {
process(resourceInfo,__act,x130)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1383,x130:Int): Unit = {
val x131 = {
FixedPoint[Signed,B32,B0](x130)
}
val x133 = {
x131 * x132
}
val x134 = {
x129 + x133
}
val x136 = x134
val x135 = __act.x1383_data
val x1351 = x135(x130.toInt) = x136
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1383,rhs:activation_x1383): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1383,lhs:activation_x1383): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1383): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1383): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1383): Unit = {
var x135: Array[FixedPoint[Signed,B32,B0]] = __act.x1383_data
__act.x1383_data = null
__act.x1383 = x135
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1383 = {
val act: activation_x1383 = new activation_x1383
act
}

}
x1383_closure.loopStart = 0
x1383_closure.loopSize = x4
val alloc: activation_x1383 = x1383_closure.alloc(resourceInfo)
var x1383: activation_x1383 = null
if (resourceInfo.availableThreads <= 1) {
x1383 = x1383_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1383] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1383](x1383_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1383_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1383 = x1383_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1383
}}

/**********/

