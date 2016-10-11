package generated.scala
//activation record for fat loop
final class activation_x2900 {
var left_act: activation_x2900 = _
var x2900: Boolean = _
var x2900_zero: Boolean = _
}
object activation_x2900 {
}
object kernel_x2900 {
def apply(resourceInfo:generated.scala.ResourceInfo,x2897:Int,x502:Boolean,x2896:Array[Boolean]): activation_x2900 = {
val x2900_closure = new generated.scala.DeliteOpMultiLoop[activation_x2900] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x2897
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2900 = {
val __act: activation_x2900 = new activation_x2900()
__act.x2900_zero = x502
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2900,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2900]): activation_x2900 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2900 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2900 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2900): activation_x2900 = {
val act: activation_x2900 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2900,start:Long,end:Long): activation_x2900 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2900 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2900,x504:Int,isEmpty:Boolean): activation_x2900 = {
val __act2: activation_x2900 = new activation_x2900()
__act2.x2900_zero = __act.x2900_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x2900 = __act2.x2900_zero
if (!isEmpty) {
val x2898 = x2896(x504.toInt)
__act2.x2900 = x2898
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2900,x504:Int): Unit = {
val x2898 = x2896(x504.toInt)
val x509 = __act.x2900
val x510 = x2898
val x511 = {
x509 && x510
}
__act.x2900 = x511
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2900,rhs:activation_x2900): Unit = {
val x509 = __act.x2900
val x510 = rhs.x2900
if (x509 == __act.x2900_zero) {
__act.x2900 = x510
}
else if (x510 != __act.x2900_zero) {
val x511 = {
x509 && x510
}
__act.x2900 = x511
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2900,lhs:activation_x2900): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2900): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2900): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2900): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2900 = {
val act: activation_x2900 = new activation_x2900
act.x2900_zero = x502
act
}

}
x2900_closure.loopStart = 0
x2900_closure.loopSize = x2897
val alloc: activation_x2900 = x2900_closure.alloc(resourceInfo)
var x2900: activation_x2900 = null
if (resourceInfo.availableThreads <= 1) {
x2900 = x2900_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2900] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2900](x2900_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2900_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2900 = x2900_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2900
}}

/**********/

