package generated.scala
//activation record for fat loop
final class activation_x1380 {
var left_act: activation_x1380 = _
var x1380: Array[Boolean] = _
var x1380_data: Array[Boolean] = _
}
object activation_x1380 {
}
object kernel_x1380 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1339:Int,x1285:Array[FixedPoint[Signed,B32,B0]],x1326:Array[FixedPoint[Signed,B32,B0]]): activation_x1380 = {
val x1380_closure = new generated.scala.DeliteOpMultiLoop[activation_x1380] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1339
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1380 = {
val __act: activation_x1380 = new activation_x1380()
val x187 = (loopSize).asInstanceOf[Int]
if (x187 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1344 = new Array[Boolean](x187.toInt)
__act.x1380_data = x1344
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1380,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1380]): activation_x1380 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1380 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1380 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1380): activation_x1380 = {
val act: activation_x1380 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1380,start:Long,end:Long): activation_x1380 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1380 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1380,x180:Int,isEmpty:Boolean): activation_x1380 = {
if (!isEmpty) {
process(resourceInfo,__act,x180)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1380,x180:Int): Unit = {
val x1340 = x1285(x180.toInt)
val x1341 = x1326(x180.toInt)
val x1342 = {
x1340 == x1341
}
val x186 = x1342
val x185 = __act.x1380_data
val x1348 = x185(x180.toInt) = x186
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1380,rhs:activation_x1380): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1380,lhs:activation_x1380): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1380): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1380): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1380): Unit = {
var x185: Array[Boolean] = __act.x1380_data
__act.x1380_data = null
__act.x1380 = x185
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1380 = {
val act: activation_x1380 = new activation_x1380
act
}

}
x1380_closure.loopStart = 0
x1380_closure.loopSize = x1339
val alloc: activation_x1380 = x1380_closure.alloc(resourceInfo)
var x1380: activation_x1380 = null
if (resourceInfo.availableThreads <= 1) {
x1380 = x1380_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1380] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1380](x1380_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1380_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1380 = x1380_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1380
}}

/**********/

