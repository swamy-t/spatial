package generated.scala
//activation record for fat loop
final class activation_x3087 {
var left_act: activation_x3087 = _
var x3087: Boolean = _
var x3087_zero: Boolean = _
}
object activation_x3087 {
}
object kernel_x3087 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3082:Int,x528:Boolean,x3081:Array[Boolean]): activation_x3087 = {
val x3087_closure = new generated.scala.DeliteOpMultiLoop[activation_x3087] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3082
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3087 = {
val __act: activation_x3087 = new activation_x3087()
__act.x3087_zero = x528
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3087,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3087]): activation_x3087 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3087 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3087 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3087): activation_x3087 = {
val act: activation_x3087 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3087,start:Long,end:Long): activation_x3087 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3087 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3087,x530:Int,isEmpty:Boolean): activation_x3087 = {
val __act2: activation_x3087 = new activation_x3087()
__act2.x3087_zero = __act.x3087_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x3087 = __act2.x3087_zero
if (!isEmpty) {
val x3083 = x3081(x530.toInt)
__act2.x3087 = x3083
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3087,x530:Int): Unit = {
val x3083 = x3081(x530.toInt)
val x535 = __act.x3087
val x536 = x3083
val x537 = {
x535 && x536
}
__act.x3087 = x537
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3087,rhs:activation_x3087): Unit = {
val x535 = __act.x3087
val x536 = rhs.x3087
if (x535 == __act.x3087_zero) {
__act.x3087 = x536
}
else if (x536 != __act.x3087_zero) {
val x537 = {
x535 && x536
}
__act.x3087 = x537
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3087,lhs:activation_x3087): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3087): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3087): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3087): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3087 = {
val act: activation_x3087 = new activation_x3087
act.x3087_zero = x528
act
}

}
x3087_closure.loopStart = 0
x3087_closure.loopSize = x3082
val alloc: activation_x3087 = x3087_closure.alloc(resourceInfo)
var x3087: activation_x3087 = null
if (resourceInfo.availableThreads <= 1) {
x3087 = x3087_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3087] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3087](x3087_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3087_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3087 = x3087_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3087
}}

/**********/

