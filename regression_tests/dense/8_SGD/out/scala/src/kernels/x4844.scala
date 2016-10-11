package generated.scala
//activation record for fat loop
final class activation_x4844 {
var left_act: activation_x4844 = _
var x4844: Boolean = _
var x4844_zero: Boolean = _
}
object activation_x4844 {
}
object kernel_x4844 {
def apply(resourceInfo:generated.scala.ResourceInfo,x4839:Int,x838:Boolean,x4838:Array[Boolean]): activation_x4844 = {
val x4844_closure = new generated.scala.DeliteOpMultiLoop[activation_x4844] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x4839
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x4844 = {
val __act: activation_x4844 = new activation_x4844()
__act.x4844_zero = x838
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4844,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x4844]): activation_x4844 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x4844 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x4844 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4844): activation_x4844 = {
val act: activation_x4844 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4844,start:Long,end:Long): activation_x4844 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x4844 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4844,x840:Int,isEmpty:Boolean): activation_x4844 = {
val __act2: activation_x4844 = new activation_x4844()
__act2.x4844_zero = __act.x4844_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x4844 = __act2.x4844_zero
if (!isEmpty) {
val x4840 = x4838(x840.toInt)
__act2.x4844 = x4840
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4844,x840:Int): Unit = {
val x4840 = x4838(x840.toInt)
val x845 = __act.x4844
val x846 = x4840
val x847 = {
x845 && x846
}
__act.x4844 = x847
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4844,rhs:activation_x4844): Unit = {
val x845 = __act.x4844
val x846 = rhs.x4844
if (x845 == __act.x4844_zero) {
__act.x4844 = x846
}
else if (x846 != __act.x4844_zero) {
val x847 = {
x845 && x846
}
__act.x4844 = x847
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4844,lhs:activation_x4844): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4844): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4844): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4844): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x4844 = {
val act: activation_x4844 = new activation_x4844
act.x4844_zero = x838
act
}

}
x4844_closure.loopStart = 0
x4844_closure.loopSize = x4839
val alloc: activation_x4844 = x4844_closure.alloc(resourceInfo)
var x4844: activation_x4844 = null
if (resourceInfo.availableThreads <= 1) {
x4844 = x4844_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x4844] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x4844](x4844_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x4844_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x4844 = x4844_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x4844
}}

/**********/

