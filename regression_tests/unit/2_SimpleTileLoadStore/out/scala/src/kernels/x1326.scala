package generated.scala
//activation record for fat loop
final class activation_x1326 {
var left_act: activation_x1326 = _
var x1326: Array[FixedPoint[Signed,B32,B0]] = _
var x1326_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1326 {
}
object kernel_x1326 {
def apply(resourceInfo:generated.scala.ResourceInfo,x4:Int,x1236:Array[FixedPoint[Signed,B32,B0]],x2:FixedPoint[Signed,B32,B0]): activation_x1326 = {
val x1326_closure = new generated.scala.DeliteOpMultiLoop[activation_x1326] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x4
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1326 = {
val __act: activation_x1326 = new activation_x1326()
val x120 = (loopSize).asInstanceOf[Int]
if (x120 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1290 = new Array[FixedPoint[Signed,B32,B0]](x120.toInt)
__act.x1326_data = x1290
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1326,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1326]): activation_x1326 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1326 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1326 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1326): activation_x1326 = {
val act: activation_x1326 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1326,start:Long,end:Long): activation_x1326 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1326 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1326,x115:Int,isEmpty:Boolean): activation_x1326 = {
if (!isEmpty) {
process(resourceInfo,__act,x115)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1326,x115:Int): Unit = {
val x1288 = x1236(x115.toInt)
val x1289 = {
x1288 * x2
}
val x119 = x1289
val x118 = __act.x1326_data
val x1294 = x118(x115.toInt) = x119
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1326,rhs:activation_x1326): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1326,lhs:activation_x1326): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1326): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1326): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1326): Unit = {
var x118: Array[FixedPoint[Signed,B32,B0]] = __act.x1326_data
__act.x1326_data = null
__act.x1326 = x118
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1326 = {
val act: activation_x1326 = new activation_x1326
act
}

}
x1326_closure.loopStart = 0
x1326_closure.loopSize = x4
val alloc: activation_x1326 = x1326_closure.alloc(resourceInfo)
var x1326: activation_x1326 = null
if (resourceInfo.availableThreads <= 1) {
x1326 = x1326_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1326] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1326](x1326_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1326_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1326 = x1326_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1326
}}

/**********/

