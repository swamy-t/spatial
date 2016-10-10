package generated.scala
//activation record for fat loop
final class activation_x2150 {
var left_act: activation_x2150 = _
var x2150: FixedPoint[Signed,B32,B0] = _
var x2150_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x2150 {
}
object kernel_x2150 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x96:FixedPoint[Signed,B32,B0],x2148:Array[FixedPoint[Signed,B32,B0]]): activation_x2150 = {
val x2150_closure = new generated.scala.DeliteOpMultiLoop[activation_x2150] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2150 = {
val __act: activation_x2150 = new activation_x2150()
__act.x2150_zero = x96
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2150,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2150]): activation_x2150 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2150 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2150 = sync.get(localStart)
//combine local
var i: Int = localStart+1
while (i < localEnd) {
combine(resourceInfo,act,sync.get(i))
i = i+1
}
//combine remote
var half: Int = tid
var step: Int = 1
while ((half % 2 == 0) && (tid + step < numThreads)) {
combine(resourceInfo,act,sync.getC(tid+step))
half = half / 2
step = step * 2
}
sync.setC(tid,act)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2150): activation_x2150 = {
val act: activation_x2150 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2150,start:Long,end:Long): activation_x2150 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2150 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2150,x300:Int,isEmpty:Boolean): activation_x2150 = {
val __act2: activation_x2150 = new activation_x2150()
__act2.x2150_zero = __act.x2150_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x2150 = __act2.x2150_zero
if (!isEmpty) {
val x2149 = x2148(x300.toInt)
__act2.x2150 = x2149
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2150,x300:Int): Unit = {
val x2149 = x2148(x300.toInt)
val x304 = __act.x2150
val x305 = x2149
val x306 = {
x304 + x305
}
__act.x2150 = x306
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2150,rhs:activation_x2150): Unit = {
val x304 = __act.x2150
val x305 = rhs.x2150
if (x304 == __act.x2150_zero) {
__act.x2150 = x305
}
else if (x305 != __act.x2150_zero) {
val x306 = {
x304 + x305
}
__act.x2150 = x306
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2150,lhs:activation_x2150): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2150): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2150): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2150): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2150 = {
val act: activation_x2150 = new activation_x2150
act.x2150_zero = x96
act
}

}
x2150_closure.loopStart = 0
x2150_closure.loopSize = x3
val alloc: activation_x2150 = x2150_closure.alloc(resourceInfo)
var x2150: activation_x2150 = null
if (resourceInfo.availableThreads <= 1) {
x2150 = x2150_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2150] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2150](x2150_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2150_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2150 = x2150_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2150
}}

/**********/

