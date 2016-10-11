package generated.scala
//activation record for fat loop
final class activation_x5411 {
var left_act: activation_x5411 = _
var x5411: Array[FixedPoint[Signed,B32,B0]] = _
var x5411_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x5411 {
}
object kernel_x5411 {
def apply(resourceInfo:generated.scala.ResourceInfo,x5279:Int,x5035:Array[FixedPoint[Signed,B32,B0]]): activation_x5411 = {
val x5411_closure = new generated.scala.DeliteOpMultiLoop[activation_x5411] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x5279
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5411 = {
val __act: activation_x5411 = new activation_x5411()
val x775 = (loopSize).asInstanceOf[Int]
if (x775 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5282 = new Array[FixedPoint[Signed,B32,B0]](x775.toInt)
__act.x5411_data = x5282
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5411,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5411]): activation_x5411 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5411 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5411 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5411): activation_x5411 = {
val act: activation_x5411 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5411,start:Long,end:Long): activation_x5411 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5411 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5411,x770:Int,isEmpty:Boolean): activation_x5411 = {
if (!isEmpty) {
process(resourceInfo,__act,x770)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5411,x770:Int): Unit = {
val x5280 = x5035(x770.toInt)
val x774 = x5280
val x773 = __act.x5411_data
val x5286 = x773(x770.toInt) = x774
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5411,rhs:activation_x5411): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5411,lhs:activation_x5411): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5411): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5411): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5411): Unit = {
var x773: Array[FixedPoint[Signed,B32,B0]] = __act.x5411_data
__act.x5411_data = null
__act.x5411 = x773
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5411 = {
val act: activation_x5411 = new activation_x5411
act
}

}
x5411_closure.loopStart = 0
x5411_closure.loopSize = x5279
val alloc: activation_x5411 = x5411_closure.alloc(resourceInfo)
var x5411: activation_x5411 = null
if (resourceInfo.availableThreads <= 1) {
x5411 = x5411_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5411] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5411](x5411_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5411_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5411 = x5411_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5411
}}

/**********/

