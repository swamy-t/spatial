package generated.scala
//activation record for fat loop
final class activation_x6224 {
var left_act: activation_x6224 = _
var x6224: FixedPoint[Signed,B32,B0] = _
var x6224_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x6224 {
}
object kernel_x6224 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6221:Int,x189:FixedPoint[Signed,B32,B0],x6220:Array[FixedPoint[Signed,B32,B0]]): activation_x6224 = {
val x6224_closure = new generated.scala.DeliteOpMultiLoop[activation_x6224] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6221
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6224 = {
val __act: activation_x6224 = new activation_x6224()
__act.x6224_zero = x189
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6224]): activation_x6224 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6224 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6224 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224): activation_x6224 = {
val act: activation_x6224 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224,start:Long,end:Long): activation_x6224 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6224 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224,x1034:Int,isEmpty:Boolean): activation_x6224 = {
val __act2: activation_x6224 = new activation_x6224()
__act2.x6224_zero = __act.x6224_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x6224 = __act2.x6224_zero
if (!isEmpty) {
val x6222 = x6220(x1034.toInt)
__act2.x6224 = x6222
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224,x1034:Int): Unit = {
val x6222 = x6220(x1034.toInt)
val x1039 = __act.x6224
val x1040 = x6222
val x1041 = {
x1039 + x1040
}
__act.x6224 = x1041
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224,rhs:activation_x6224): Unit = {
val x1039 = __act.x6224
val x1040 = rhs.x6224
if (x1039 == __act.x6224_zero) {
__act.x6224 = x1040
}
else if (x1040 != __act.x6224_zero) {
val x1041 = {
x1039 + x1040
}
__act.x6224 = x1041
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224,lhs:activation_x6224): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6224 = {
val act: activation_x6224 = new activation_x6224
act.x6224_zero = x189
act
}

}
x6224_closure.loopStart = 0
x6224_closure.loopSize = x6221
val alloc: activation_x6224 = x6224_closure.alloc(resourceInfo)
var x6224: activation_x6224 = null
if (resourceInfo.availableThreads <= 1) {
x6224 = x6224_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6224] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6224](x6224_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6224_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6224 = x6224_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6224
}}

/**********/

