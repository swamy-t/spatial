package generated.scala
//activation record for fat loop
final class activation_x1754 {
var left_act: activation_x1754 = _
var x1754: Array[FixedPoint[Signed,B32,B0]] = _
var x1754_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1754 {
}
object kernel_x1754 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1569:Int,x1528:Array[FixedPoint[Signed,B32,B0]],x1567:Array[FixedPoint[Signed,B32,B0]]): activation_x1754 = {
val x1754_closure = new generated.scala.DeliteOpMultiLoop[activation_x1754] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1569
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1754 = {
val __act: activation_x1754 = new activation_x1754()
val x225 = (loopSize).asInstanceOf[Int]
if (x225 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1718 = new Array[FixedPoint[Signed,B32,B0]](x225.toInt)
__act.x1754_data = x1718
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1754,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1754]): activation_x1754 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1754 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1754 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1754): activation_x1754 = {
val act: activation_x1754 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1754,start:Long,end:Long): activation_x1754 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1754 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1754,x219:Int,isEmpty:Boolean): activation_x1754 = {
if (!isEmpty) {
process(resourceInfo,__act,x219)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1754,x219:Int): Unit = {
val x1715 = x1528(x219.toInt)
val x1716 = x1567(x219.toInt)
val x1717 = {
x1715 * x1716
}
val x224 = x1717
val x223 = __act.x1754_data
val x1722 = x223(x219.toInt) = x224
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1754,rhs:activation_x1754): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1754,lhs:activation_x1754): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1754): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1754): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1754): Unit = {
var x223: Array[FixedPoint[Signed,B32,B0]] = __act.x1754_data
__act.x1754_data = null
__act.x1754 = x223
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1754 = {
val act: activation_x1754 = new activation_x1754
act
}

}
x1754_closure.loopStart = 0
x1754_closure.loopSize = x1569
val alloc: activation_x1754 = x1754_closure.alloc(resourceInfo)
var x1754: activation_x1754 = null
if (resourceInfo.availableThreads <= 1) {
x1754 = x1754_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1754] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1754](x1754_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1754_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1754 = x1754_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1754
}}

/**********/

