package generated.scala
//activation record for fat loop
final class activation_x1402 {
var left_act: activation_x1402 = _
var x1402: Array[Boolean] = _
var x1402_data: Array[Boolean] = _
}
object activation_x1402 {
}
object kernel_x1402 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1354:Int,x1307:Array[FixedPoint[Signed,B32,B0]],x1346:Array[FixedPoint[Signed,B32,B0]]): activation_x1402 = {
val x1402_closure = new generated.scala.DeliteOpMultiLoop[activation_x1402] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1354
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1402 = {
val __act: activation_x1402 = new activation_x1402()
val x204 = (loopSize).asInstanceOf[Int]
if (x204 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1366 = new Array[Boolean](x204.toInt)
__act.x1402_data = x1366
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1402,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1402]): activation_x1402 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1402 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1402 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1402): activation_x1402 = {
val act: activation_x1402 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1402,start:Long,end:Long): activation_x1402 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1402 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1402,x197:Int,isEmpty:Boolean): activation_x1402 = {
if (!isEmpty) {
process(resourceInfo,__act,x197)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1402,x197:Int): Unit = {
val x1362 = x1307(x197.toInt)
val x1363 = x1346(x197.toInt)
val x1364 = {
x1362 == x1363
}
val x203 = x1364
val x202 = __act.x1402_data
val x1370 = x202(x197.toInt) = x203
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1402,rhs:activation_x1402): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1402,lhs:activation_x1402): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1402): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1402): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1402): Unit = {
var x202: Array[Boolean] = __act.x1402_data
__act.x1402_data = null
__act.x1402 = x202
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1402 = {
val act: activation_x1402 = new activation_x1402
act
}

}
x1402_closure.loopStart = 0
x1402_closure.loopSize = x1354
val alloc: activation_x1402 = x1402_closure.alloc(resourceInfo)
var x1402: activation_x1402 = null
if (resourceInfo.availableThreads <= 1) {
x1402 = x1402_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1402] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1402](x1402_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1402_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1402 = x1402_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1402
}}

/**********/

