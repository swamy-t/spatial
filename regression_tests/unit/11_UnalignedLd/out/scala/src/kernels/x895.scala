package generated.scala
//activation record for fat loop
final class activation_x895 {
var left_act: activation_x895 = _
var x895: FixedPoint[Signed,B32,B0] = _
var x895_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x895 {
}
object kernel_x895 {
def apply(resourceInfo:generated.scala.ResourceInfo,x99:Int,x49:FixedPoint[Signed,B32,B0],x891:Array[FixedPoint[Signed,B32,B0]]): activation_x895 = {
val x895_closure = new generated.scala.DeliteOpMultiLoop[activation_x895] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x99
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x895 = {
val __act: activation_x895 = new activation_x895()
__act.x895_zero = x49
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x895,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x895]): activation_x895 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x895 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x895 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x895): activation_x895 = {
val act: activation_x895 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x895,start:Long,end:Long): activation_x895 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x895 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x895,x145:Int,isEmpty:Boolean): activation_x895 = {
val __act2: activation_x895 = new activation_x895()
__act2.x895_zero = __act.x895_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x895 = __act2.x895_zero
if (!isEmpty) {
val x892 = x891(x145.toInt)
__act2.x895 = x892
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x895,x145:Int): Unit = {
val x892 = x891(x145.toInt)
val x149 = __act.x895
val x150 = x892
val x151 = {
x149 + x150
}
__act.x895 = x151
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x895,rhs:activation_x895): Unit = {
val x149 = __act.x895
val x150 = rhs.x895
if (x149 == __act.x895_zero) {
__act.x895 = x150
}
else if (x150 != __act.x895_zero) {
val x151 = {
x149 + x150
}
__act.x895 = x151
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x895,lhs:activation_x895): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x895): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x895): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x895): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x895 = {
val act: activation_x895 = new activation_x895
act.x895_zero = x49
act
}

}
x895_closure.loopStart = 0
x895_closure.loopSize = x99
val alloc: activation_x895 = x895_closure.alloc(resourceInfo)
var x895: activation_x895 = null
if (resourceInfo.availableThreads <= 1) {
x895 = x895_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x895] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x895](x895_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x895_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x895 = x895_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x895
}}

/**********/

