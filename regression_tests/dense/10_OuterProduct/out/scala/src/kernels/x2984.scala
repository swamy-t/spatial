package generated.scala
//activation record for fat loop
final class activation_x2984 {
var left_act: activation_x2984 = _
var x2984: FixedPoint[Signed,B32,B0] = _
var x2984_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x2984 {
}
object kernel_x2984 {
def apply(resourceInfo:generated.scala.ResourceInfo,x2942:Int,x99:FixedPoint[Signed,B32,B0],x2980:Array[FixedPoint[Signed,B32,B0]]): activation_x2984 = {
val x2984_closure = new generated.scala.DeliteOpMultiLoop[activation_x2984] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x2942
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2984 = {
val __act: activation_x2984 = new activation_x2984()
__act.x2984_zero = x99
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2984,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2984]): activation_x2984 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2984 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2984 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2984): activation_x2984 = {
val act: activation_x2984 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2984,start:Long,end:Long): activation_x2984 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2984 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2984,x401:Int,isEmpty:Boolean): activation_x2984 = {
val __act2: activation_x2984 = new activation_x2984()
__act2.x2984_zero = __act.x2984_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x2984 = __act2.x2984_zero
if (!isEmpty) {
val x2981 = x2980(x401.toInt)
__act2.x2984 = x2981
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2984,x401:Int): Unit = {
val x2981 = x2980(x401.toInt)
val x405 = __act.x2984
val x406 = x2981
val x407 = {
x405 + x406
}
__act.x2984 = x407
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2984,rhs:activation_x2984): Unit = {
val x405 = __act.x2984
val x406 = rhs.x2984
if (x405 == __act.x2984_zero) {
__act.x2984 = x406
}
else if (x406 != __act.x2984_zero) {
val x407 = {
x405 + x406
}
__act.x2984 = x407
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2984,lhs:activation_x2984): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2984): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2984): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2984): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2984 = {
val act: activation_x2984 = new activation_x2984
act.x2984_zero = x99
act
}

}
x2984_closure.loopStart = 0
x2984_closure.loopSize = x2942
val alloc: activation_x2984 = x2984_closure.alloc(resourceInfo)
var x2984: activation_x2984 = null
if (resourceInfo.availableThreads <= 1) {
x2984 = x2984_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2984] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2984](x2984_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2984_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2984 = x2984_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2984
}}

/**********/

