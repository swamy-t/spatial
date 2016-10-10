package generated.scala
//activation record for fat loop
final class activation_x1873 {
var left_act: activation_x1873 = _
var x1873: FixedPoint[Signed,B32,B0] = _
var x1873_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x1873 {
}
object kernel_x1873 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1868:Int,x53:FixedPoint[Signed,B32,B0],x1852:Array[FixedPoint[Signed,B32,B0]]): activation_x1873 = {
val x1873_closure = new generated.scala.DeliteOpMultiLoop[activation_x1873] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1868
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1873 = {
val __act: activation_x1873 = new activation_x1873()
__act.x1873_zero = x53
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1873,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1873]): activation_x1873 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1873 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1873 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1873): activation_x1873 = {
val act: activation_x1873 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1873,start:Long,end:Long): activation_x1873 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1873 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1873,x254:Int,isEmpty:Boolean): activation_x1873 = {
val __act2: activation_x1873 = new activation_x1873()
__act2.x1873_zero = __act.x1873_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x1873 = __act2.x1873_zero
if (!isEmpty) {
val x1869 = x1852(x254.toInt)
__act2.x1873 = x1869
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1873,x254:Int): Unit = {
val x1869 = x1852(x254.toInt)
val x259 = __act.x1873
val x260 = x1869
val x261 = {
x259 + x260
}
__act.x1873 = x261
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1873,rhs:activation_x1873): Unit = {
val x259 = __act.x1873
val x260 = rhs.x1873
if (x259 == __act.x1873_zero) {
__act.x1873 = x260
}
else if (x260 != __act.x1873_zero) {
val x261 = {
x259 + x260
}
__act.x1873 = x261
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1873,lhs:activation_x1873): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1873): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1873): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1873): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1873 = {
val act: activation_x1873 = new activation_x1873
act.x1873_zero = x53
act
}

}
x1873_closure.loopStart = 0
x1873_closure.loopSize = x1868
val alloc: activation_x1873 = x1873_closure.alloc(resourceInfo)
var x1873: activation_x1873 = null
if (resourceInfo.availableThreads <= 1) {
x1873 = x1873_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1873] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1873](x1873_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1873_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1873 = x1873_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1873
}}

/**********/

