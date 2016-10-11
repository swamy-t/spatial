package generated.scala
//activation record for fat loop
final class activation_x1147 {
var left_act: activation_x1147 = _
var x1147: Array[Boolean] = _
var x1147_data: Array[Boolean] = _
}
object activation_x1147 {
}
object kernel_x1147 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1099:Int,x1089:Array[FixedPoint[Signed,B32,B0]],x1041:Array[FixedPoint[Signed,B32,B0]]): activation_x1147 = {
val x1147_closure = new generated.scala.DeliteOpMultiLoop[activation_x1147] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1099
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1147 = {
val __act: activation_x1147 = new activation_x1147()
val x160 = (loopSize).asInstanceOf[Int]
if (x160 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1111 = new Array[Boolean](x160.toInt)
__act.x1147_data = x1111
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1147,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1147]): activation_x1147 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1147 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1147 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1147): activation_x1147 = {
val act: activation_x1147 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1147,start:Long,end:Long): activation_x1147 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1147 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1147,x153:Int,isEmpty:Boolean): activation_x1147 = {
if (!isEmpty) {
process(resourceInfo,__act,x153)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1147,x153:Int): Unit = {
val x1107 = x1089(x153.toInt)
val x1108 = x1041(x153.toInt)
val x1109 = {
x1107 == x1108
}
val x159 = x1109
val x158 = __act.x1147_data
val x1115 = x158(x153.toInt) = x159
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1147,rhs:activation_x1147): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1147,lhs:activation_x1147): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1147): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1147): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1147): Unit = {
var x158: Array[Boolean] = __act.x1147_data
__act.x1147_data = null
__act.x1147 = x158
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1147 = {
val act: activation_x1147 = new activation_x1147
act
}

}
x1147_closure.loopStart = 0
x1147_closure.loopSize = x1099
val alloc: activation_x1147 = x1147_closure.alloc(resourceInfo)
var x1147: activation_x1147 = null
if (resourceInfo.availableThreads <= 1) {
x1147 = x1147_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1147] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1147](x1147_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1147_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1147 = x1147_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1147
}}

/**********/

