package generated.scala
//activation record for fat loop
final class activation_x1867 {
var left_act: activation_x1867 = _
var x1867: FixedPoint[Signed,B32,B0] = _
var x1867_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x1867 {
}
object kernel_x1867 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1862:Int,x53:FixedPoint[Signed,B32,B0],x1850:Array[FixedPoint[Signed,B32,B0]]): activation_x1867 = {
val x1867_closure = new generated.scala.DeliteOpMultiLoop[activation_x1867] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1862
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1867 = {
val __act: activation_x1867 = new activation_x1867()
__act.x1867_zero = x53
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1867,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1867]): activation_x1867 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1867 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1867 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1867): activation_x1867 = {
val act: activation_x1867 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1867,start:Long,end:Long): activation_x1867 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1867 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1867,x244:Int,isEmpty:Boolean): activation_x1867 = {
val __act2: activation_x1867 = new activation_x1867()
__act2.x1867_zero = __act.x1867_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x1867 = __act2.x1867_zero
if (!isEmpty) {
val x1863 = x1850(x244.toInt)
__act2.x1867 = x1863
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1867,x244:Int): Unit = {
val x1863 = x1850(x244.toInt)
val x249 = __act.x1867
val x250 = x1863
val x251 = {
x249 + x250
}
__act.x1867 = x251
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1867,rhs:activation_x1867): Unit = {
val x249 = __act.x1867
val x250 = rhs.x1867
if (x249 == __act.x1867_zero) {
__act.x1867 = x250
}
else if (x250 != __act.x1867_zero) {
val x251 = {
x249 + x250
}
__act.x1867 = x251
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1867,lhs:activation_x1867): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1867): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1867): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1867): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1867 = {
val act: activation_x1867 = new activation_x1867
act.x1867_zero = x53
act
}

}
x1867_closure.loopStart = 0
x1867_closure.loopSize = x1862
val alloc: activation_x1867 = x1867_closure.alloc(resourceInfo)
var x1867: activation_x1867 = null
if (resourceInfo.availableThreads <= 1) {
x1867 = x1867_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1867] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1867](x1867_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1867_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1867 = x1867_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1867
}}

/**********/

