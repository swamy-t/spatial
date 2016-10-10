package generated.scala
//activation record for fat loop
final class activation_x3092 {
var left_act: activation_x3092 = _
var x3092: Array[FixedPoint[Signed,B32,B0]] = _
var x3092_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x3092 {
}
object kernel_x3092 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x3043:Array[Boolean],x2750:Array[FixedPoint[Signed,B32,B0]],x2710:Array[FixedPoint[Signed,B32,B0]],x195:FixedPoint[Signed,B32,B0]): activation_x3092 = {
val x3092_closure = new generated.scala.DeliteOpMultiLoop[activation_x3092] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3092 = {
val __act: activation_x3092 = new activation_x3092()
val x423 = (loopSize).asInstanceOf[Int]
if (x423 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3056 = new Array[FixedPoint[Signed,B32,B0]](x423.toInt)
__act.x3092_data = x3056
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3092,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3092]): activation_x3092 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3092 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3092 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3092): activation_x3092 = {
val act: activation_x3092 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3092,start:Long,end:Long): activation_x3092 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3092 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3092,x412:Int,isEmpty:Boolean): activation_x3092 = {
if (!isEmpty) {
process(resourceInfo,__act,x412)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3092,x412:Int): Unit = {
val x413 = {
FixedPoint[Signed,B32,B0](x412)
}
val x414 = {
x413.toInt
}
val x3050 = x3043(x414.toInt)
val x3051 = {
x3050
}
val x3055 = {
def x3055thenb(): FixedPoint[Signed,B32,B0] = {
val x3052 = x2750(x414.toInt)
val x3053 = x2710(x414.toInt)
val x3054 = {
x3052 * x3053
}
x3054
}
def x3055elseb(): FixedPoint[Signed,B32,B0] = {
x195
}
if (x3051) {
x3055thenb()
} else { 
x3055elseb()
}
}
val x422 = x3055
val x421 = __act.x3092_data
val x3060 = x421(x412.toInt) = x422
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3092,rhs:activation_x3092): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3092,lhs:activation_x3092): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3092): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3092): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3092): Unit = {
var x421: Array[FixedPoint[Signed,B32,B0]] = __act.x3092_data
__act.x3092_data = null
__act.x3092 = x421
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3092 = {
val act: activation_x3092 = new activation_x3092
act
}

}
x3092_closure.loopStart = 0
x3092_closure.loopSize = x3
val alloc: activation_x3092 = x3092_closure.alloc(resourceInfo)
var x3092: activation_x3092 = null
if (resourceInfo.availableThreads <= 1) {
x3092 = x3092_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3092] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3092](x3092_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3092_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3092 = x3092_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3092
}}

/**********/

