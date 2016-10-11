package generated.scala
//activation record for fat loop
final class activation_x1995 {
var left_act: activation_x1995 = _
var x1995: Array[Boolean] = _
var x1995_data: Array[Boolean] = _
}
object activation_x1995 {
}
object kernel_x1995 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1947:Int,x1854:Array[FixedPoint[Signed,B32,B0]],x1939:Array[FixedPoint[Signed,B32,B0]]): activation_x1995 = {
val x1995_closure = new generated.scala.DeliteOpMultiLoop[activation_x1995] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1947
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1995 = {
val __act: activation_x1995 = new activation_x1995()
val x354 = (loopSize).asInstanceOf[Int]
if (x354 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1959 = new Array[Boolean](x354.toInt)
__act.x1995_data = x1959
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1995,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1995]): activation_x1995 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1995 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1995 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1995): activation_x1995 = {
val act: activation_x1995 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1995,start:Long,end:Long): activation_x1995 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1995 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1995,x347:Int,isEmpty:Boolean): activation_x1995 = {
if (!isEmpty) {
process(resourceInfo,__act,x347)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1995,x347:Int): Unit = {
val x1955 = x1854(x347.toInt)
val x1956 = x1939(x347.toInt)
val x1957 = {
x1955 == x1956
}
val x353 = x1957
val x352 = __act.x1995_data
val x1963 = x352(x347.toInt) = x353
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1995,rhs:activation_x1995): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1995,lhs:activation_x1995): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1995): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1995): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1995): Unit = {
var x352: Array[Boolean] = __act.x1995_data
__act.x1995_data = null
__act.x1995 = x352
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1995 = {
val act: activation_x1995 = new activation_x1995
act
}

}
x1995_closure.loopStart = 0
x1995_closure.loopSize = x1947
val alloc: activation_x1995 = x1995_closure.alloc(resourceInfo)
var x1995: activation_x1995 = null
if (resourceInfo.availableThreads <= 1) {
x1995 = x1995_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1995] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1995](x1995_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1995_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1995 = x1995_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1995
}}

/**********/

