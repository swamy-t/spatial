package generated.scala
//activation record for fat loop
final class activation_x815 {
var left_act: activation_x815 = _
var x815: Boolean = _
var x815_zero: Boolean = _
}
object activation_x815 {
}
object kernel_x815 {
def apply(resourceInfo:generated.scala.ResourceInfo,x810:Int,x132:Boolean,x809:Array[Boolean]): activation_x815 = {
val x815_closure = new generated.scala.DeliteOpMultiLoop[activation_x815] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x810
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x815 = {
val __act: activation_x815 = new activation_x815()
__act.x815_zero = x132
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x815,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x815]): activation_x815 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x815 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x815 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x815): activation_x815 = {
val act: activation_x815 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x815,start:Long,end:Long): activation_x815 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x815 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x815,x134:Int,isEmpty:Boolean): activation_x815 = {
val __act2: activation_x815 = new activation_x815()
__act2.x815_zero = __act.x815_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x815 = __act2.x815_zero
if (!isEmpty) {
val x811 = x809(x134.toInt)
__act2.x815 = x811
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x815,x134:Int): Unit = {
val x811 = x809(x134.toInt)
val x139 = __act.x815
val x140 = x811
val x141 = {
x139 && x140
}
__act.x815 = x141
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x815,rhs:activation_x815): Unit = {
val x139 = __act.x815
val x140 = rhs.x815
if (x139 == __act.x815_zero) {
__act.x815 = x140
}
else if (x140 != __act.x815_zero) {
val x141 = {
x139 && x140
}
__act.x815 = x141
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x815,lhs:activation_x815): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x815): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x815): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x815): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x815 = {
val act: activation_x815 = new activation_x815
act.x815_zero = x132
act
}

}
x815_closure.loopStart = 0
x815_closure.loopSize = x810
val alloc: activation_x815 = x815_closure.alloc(resourceInfo)
var x815: activation_x815 = null
if (resourceInfo.availableThreads <= 1) {
x815 = x815_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x815] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x815](x815_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x815_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x815 = x815_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x815
}}

/**********/

