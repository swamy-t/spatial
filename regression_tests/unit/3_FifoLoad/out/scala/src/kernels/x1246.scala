package generated.scala
//activation record for fat loop
final class activation_x1246 {
var left_act: activation_x1246 = _
var x1246: Array[FixedPoint[Signed,B32,B0]] = _
var x1246_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1246 {
}
object kernel_x1246 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x1171:Array[FixedPoint[Signed,B32,B0]]): activation_x1246 = {
val x1246_closure = new generated.scala.DeliteOpMultiLoop[activation_x1246] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1246 = {
val __act: activation_x1246 = new activation_x1246()
val x107 = (loopSize).asInstanceOf[Int]
if (x107 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1210 = new Array[FixedPoint[Signed,B32,B0]](x107.toInt)
__act.x1246_data = x1210
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1246,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1246]): activation_x1246 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1246 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1246 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1246): activation_x1246 = {
val act: activation_x1246 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1246,start:Long,end:Long): activation_x1246 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1246 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1246,x103:Int,isEmpty:Boolean): activation_x1246 = {
if (!isEmpty) {
process(resourceInfo,__act,x103)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1246,x103:Int): Unit = {
val x1209 = x1171(x103.toInt)
val x106 = x1209
val x105 = __act.x1246_data
val x1214 = x105(x103.toInt) = x106
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1246,rhs:activation_x1246): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1246,lhs:activation_x1246): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1246): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1246): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1246): Unit = {
var x105: Array[FixedPoint[Signed,B32,B0]] = __act.x1246_data
__act.x1246_data = null
__act.x1246 = x105
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1246 = {
val act: activation_x1246 = new activation_x1246
act
}

}
x1246_closure.loopStart = 0
x1246_closure.loopSize = x3
val alloc: activation_x1246 = x1246_closure.alloc(resourceInfo)
var x1246: activation_x1246 = null
if (resourceInfo.availableThreads <= 1) {
x1246 = x1246_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1246] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1246](x1246_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1246_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1246 = x1246_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1246
}}

/**********/

