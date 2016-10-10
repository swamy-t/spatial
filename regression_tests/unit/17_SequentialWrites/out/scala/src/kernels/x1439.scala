package generated.scala
//activation record for fat loop
final class activation_x1439 {
var left_act: activation_x1439 = _
var x1439: Array[Boolean] = _
var x1439_data: Array[Boolean] = _
}
object activation_x1439 {
}
object kernel_x1439 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1391:Int,x1344:Array[FixedPoint[Signed,B32,B0]],x1383:Array[FixedPoint[Signed,B32,B0]]): activation_x1439 = {
val x1439_closure = new generated.scala.DeliteOpMultiLoop[activation_x1439] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1391
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1439 = {
val __act: activation_x1439 = new activation_x1439()
val x208 = (loopSize).asInstanceOf[Int]
if (x208 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1403 = new Array[Boolean](x208.toInt)
__act.x1439_data = x1403
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1439,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1439]): activation_x1439 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1439 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1439 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1439): activation_x1439 = {
val act: activation_x1439 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1439,start:Long,end:Long): activation_x1439 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1439 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1439,x201:Int,isEmpty:Boolean): activation_x1439 = {
if (!isEmpty) {
process(resourceInfo,__act,x201)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1439,x201:Int): Unit = {
val x1399 = x1344(x201.toInt)
val x1400 = x1383(x201.toInt)
val x1401 = {
x1399 == x1400
}
val x207 = x1401
val x206 = __act.x1439_data
val x1407 = x206(x201.toInt) = x207
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1439,rhs:activation_x1439): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1439,lhs:activation_x1439): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1439): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1439): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1439): Unit = {
var x206: Array[Boolean] = __act.x1439_data
__act.x1439_data = null
__act.x1439 = x206
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1439 = {
val act: activation_x1439 = new activation_x1439
act
}

}
x1439_closure.loopStart = 0
x1439_closure.loopSize = x1391
val alloc: activation_x1439 = x1439_closure.alloc(resourceInfo)
var x1439: activation_x1439 = null
if (resourceInfo.availableThreads <= 1) {
x1439 = x1439_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1439] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1439](x1439_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1439_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1439 = x1439_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1439
}}

/**********/

