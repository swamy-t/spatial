package generated.scala
//activation record for fat loop
final class activation_x5404 {
var left_act: activation_x5404 = _
var x5404: Array[FixedPoint[Signed,B32,B0]] = _
var x5404_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x5404 {
}
object kernel_x5404 {
def apply(resourceInfo:generated.scala.ResourceInfo,x5400:Int,x5399:Array[FixedPoint[Signed,B32,B0]]): activation_x5404 = {
val x5404_closure = new generated.scala.DeliteOpMultiLoop[activation_x5404] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x5400
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5404 = {
val __act: activation_x5404 = new activation_x5404()
val x718 = (loopSize).asInstanceOf[Int]
if (x718 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5236 = new Array[FixedPoint[Signed,B32,B0]](x718.toInt)
__act.x5404_data = x5236
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5404,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5404]): activation_x5404 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5404 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5404 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5404): activation_x5404 = {
val act: activation_x5404 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5404,start:Long,end:Long): activation_x5404 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5404 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5404,x714:Int,isEmpty:Boolean): activation_x5404 = {
if (!isEmpty) {
process(resourceInfo,__act,x714)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5404,x714:Int): Unit = {
val x5401 = x5399(x714.toInt)
val x717 = x5401
val x716 = __act.x5404_data
val x5240 = x716(x714.toInt) = x717
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5404,rhs:activation_x5404): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5404,lhs:activation_x5404): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5404): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5404): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5404): Unit = {
var x716: Array[FixedPoint[Signed,B32,B0]] = __act.x5404_data
__act.x5404_data = null
__act.x5404 = x716
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5404 = {
val act: activation_x5404 = new activation_x5404
act
}

}
x5404_closure.loopStart = 0
x5404_closure.loopSize = x5400
val alloc: activation_x5404 = x5404_closure.alloc(resourceInfo)
var x5404: activation_x5404 = null
if (resourceInfo.availableThreads <= 1) {
x5404 = x5404_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5404] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5404](x5404_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5404_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5404 = x5404_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5404
}}

/**********/

