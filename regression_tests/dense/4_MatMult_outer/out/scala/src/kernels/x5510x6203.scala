package generated.scala
//activation record for fat loop
final class activation_x5510x6203 {
var left_act: activation_x5510x6203 = _
var x5510: Array[FixedPoint[Signed,B32,B0]] = _
var x5510_data: Array[FixedPoint[Signed,B32,B0]] = _
var x6203: Array[FixedPoint[Signed,B32,B0]] = _
var x6203_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x5510x6203 {
}
object kernel_x5510x6203 {
def apply(resourceInfo:generated.scala.ResourceInfo,x99:Int,x11:FixedPoint[Signed,B32,B0],x189:FixedPoint[Signed,B32,B0]): activation_x5510x6203 = {
val x5510x6203_closure = new generated.scala.DeliteOpMultiLoop[activation_x5510x6203] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x99
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5510x6203 = {
val __act: activation_x5510x6203 = new activation_x5510x6203()
val x103 = (loopSize).asInstanceOf[Int]
if (x103 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5474 = new Array[FixedPoint[Signed,B32,B0]](x103.toInt)
__act.x5510_data = x5474
val x192 = (loopSize).asInstanceOf[Int]
if (x192 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5587 = new Array[FixedPoint[Signed,B32,B0]](x192.toInt)
__act.x6203_data = x5587
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5510x6203,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5510x6203]): activation_x5510x6203 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5510x6203 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5510x6203 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5510x6203): activation_x5510x6203 = {
val act: activation_x5510x6203 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5510x6203,start:Long,end:Long): activation_x5510x6203 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5510x6203 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5510x6203,x100:Int,isEmpty:Boolean): activation_x5510x6203 = {
if (!isEmpty) {
process(resourceInfo,__act,x100)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5510x6203,x100:Int): Unit = {
val x102 = x11
val x101 = __act.x5510_data
val x5478 = x101(x100.toInt) = x102
val x191 = x189
val x190 = __act.x6203_data
val x6201 = x190(x100.toInt) = x191
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5510x6203,rhs:activation_x5510x6203): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5510x6203,lhs:activation_x5510x6203): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5510x6203): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5510x6203): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5510x6203): Unit = {
var x101: Array[FixedPoint[Signed,B32,B0]] = __act.x5510_data
__act.x5510_data = null
__act.x5510 = x101
var x190: Array[FixedPoint[Signed,B32,B0]] = __act.x6203_data
__act.x6203_data = null
__act.x6203 = x190
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5510x6203 = {
val act: activation_x5510x6203 = new activation_x5510x6203
act
}

}
x5510x6203_closure.loopStart = 0
x5510x6203_closure.loopSize = x99
val alloc: activation_x5510x6203 = x5510x6203_closure.alloc(resourceInfo)
var x5510x6203: activation_x5510x6203 = null
if (resourceInfo.availableThreads <= 1) {
x5510x6203 = x5510x6203_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5510x6203] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5510x6203](x5510x6203_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5510x6203_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5510x6203 = x5510x6203_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5510x6203
}}

/**********/

