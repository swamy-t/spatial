package generated.scala
//activation record for fat loop
final class activation_x1346 {
var left_act: activation_x1346 = _
var x1346: Array[FixedPoint[Signed,B32,B0]] = _
var x1346_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1346 {
}
object kernel_x1346 {
def apply(resourceInfo:generated.scala.ResourceInfo,x118:Int,x121:FixedPoint[Signed,B32,B0],x126:FixedPoint[Signed,B32,B0]): activation_x1346 = {
val x1346_closure = new generated.scala.DeliteOpMultiLoop[activation_x1346] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x118
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1346 = {
val __act: activation_x1346 = new activation_x1346()
val x133 = (loopSize).asInstanceOf[Int]
if (x133 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1310 = new Array[FixedPoint[Signed,B32,B0]](x133.toInt)
__act.x1346_data = x1310
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1346,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1346]): activation_x1346 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1346 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1346 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1346): activation_x1346 = {
val act: activation_x1346 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1346,start:Long,end:Long): activation_x1346 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1346 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1346,x127:Int,isEmpty:Boolean): activation_x1346 = {
if (!isEmpty) {
process(resourceInfo,__act,x127)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1346,x127:Int): Unit = {
val x128 = {
FixedPoint[Signed,B32,B0](x127)
}
val x129 = {
x128 * x121
}
val x130 = {
x126 + x129
}
val x132 = x130
val x131 = __act.x1346_data
val x1314 = x131(x127.toInt) = x132
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1346,rhs:activation_x1346): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1346,lhs:activation_x1346): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1346): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1346): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1346): Unit = {
var x131: Array[FixedPoint[Signed,B32,B0]] = __act.x1346_data
__act.x1346_data = null
__act.x1346 = x131
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1346 = {
val act: activation_x1346 = new activation_x1346
act
}

}
x1346_closure.loopStart = 0
x1346_closure.loopSize = x118
val alloc: activation_x1346 = x1346_closure.alloc(resourceInfo)
var x1346: activation_x1346 = null
if (resourceInfo.availableThreads <= 1) {
x1346 = x1346_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1346] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1346](x1346_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1346_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1346 = x1346_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1346
}}

/**********/

