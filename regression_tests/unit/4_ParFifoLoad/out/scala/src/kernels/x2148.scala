package generated.scala
//activation record for fat loop
final class activation_x2148 {
var left_act: activation_x2148 = _
var x2148: Array[FixedPoint[Signed,B32,B0]] = _
var x2148_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x2148 {
}
object kernel_x2148 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x1875:Array[FixedPoint[Signed,B32,B0]],x2125:Array[FixedPoint[Signed,B32,B0]]): activation_x2148 = {
val x2148_closure = new generated.scala.DeliteOpMultiLoop[activation_x2148] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2148 = {
val __act: activation_x2148 = new activation_x2148()
val x259 = (loopSize).asInstanceOf[Int]
if (x259 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1953 = new Array[FixedPoint[Signed,B32,B0]](x259.toInt)
__act.x2148_data = x1953
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2148,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2148]): activation_x2148 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2148 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2148 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2148): activation_x2148 = {
val act: activation_x2148 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2148,start:Long,end:Long): activation_x2148 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2148 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2148,x253:Int,isEmpty:Boolean): activation_x2148 = {
if (!isEmpty) {
process(resourceInfo,__act,x253)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2148,x253:Int): Unit = {
val x1950 = x1875(x253.toInt)
val x2144 = x2125(x253.toInt)
val x2145 = {
x1950 * x2144
}
val x258 = x2145
val x257 = __act.x2148_data
val x1957 = x257(x253.toInt) = x258
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2148,rhs:activation_x2148): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2148,lhs:activation_x2148): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2148): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2148): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2148): Unit = {
var x257: Array[FixedPoint[Signed,B32,B0]] = __act.x2148_data
__act.x2148_data = null
__act.x2148 = x257
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2148 = {
val act: activation_x2148 = new activation_x2148
act
}

}
x2148_closure.loopStart = 0
x2148_closure.loopSize = x3
val alloc: activation_x2148 = x2148_closure.alloc(resourceInfo)
var x2148: activation_x2148 = null
if (resourceInfo.availableThreads <= 1) {
x2148 = x2148_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2148] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2148](x2148_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2148_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2148 = x2148_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2148
}}

/**********/

