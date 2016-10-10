package generated.scala
//activation record for fat loop
final class activation_x1197 {
var left_act: activation_x1197 = _
var x1197: Boolean = _
var x1197_zero: Boolean = _
}
object activation_x1197 {
}
object kernel_x1197 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1192:Int,x194:Boolean,x1191:Array[Boolean]): activation_x1197 = {
val x1197_closure = new generated.scala.DeliteOpMultiLoop[activation_x1197] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1192
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1197 = {
val __act: activation_x1197 = new activation_x1197()
__act.x1197_zero = x194
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1197,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1197]): activation_x1197 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1197 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1197 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1197): activation_x1197 = {
val act: activation_x1197 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1197,start:Long,end:Long): activation_x1197 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1197 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1197,x196:Int,isEmpty:Boolean): activation_x1197 = {
val __act2: activation_x1197 = new activation_x1197()
__act2.x1197_zero = __act.x1197_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x1197 = __act2.x1197_zero
if (!isEmpty) {
val x1193 = x1191(x196.toInt)
__act2.x1197 = x1193
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1197,x196:Int): Unit = {
val x1193 = x1191(x196.toInt)
val x201 = __act.x1197
val x202 = x1193
val x203 = {
x201 && x202
}
__act.x1197 = x203
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1197,rhs:activation_x1197): Unit = {
val x201 = __act.x1197
val x202 = rhs.x1197
if (x201 == __act.x1197_zero) {
__act.x1197 = x202
}
else if (x202 != __act.x1197_zero) {
val x203 = {
x201 && x202
}
__act.x1197 = x203
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1197,lhs:activation_x1197): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1197): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1197): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1197): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1197 = {
val act: activation_x1197 = new activation_x1197
act.x1197_zero = x194
act
}

}
x1197_closure.loopStart = 0
x1197_closure.loopSize = x1192
val alloc: activation_x1197 = x1197_closure.alloc(resourceInfo)
var x1197: activation_x1197 = null
if (resourceInfo.availableThreads <= 1) {
x1197 = x1197_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1197] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1197](x1197_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1197_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1197 = x1197_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1197
}}

/**********/

