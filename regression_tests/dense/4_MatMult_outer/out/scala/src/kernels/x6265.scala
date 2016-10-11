package generated.scala
//activation record for fat loop
final class activation_x6265 {
var left_act: activation_x6265 = _
var x6265: Boolean = _
var x6265_zero: Boolean = _
}
object activation_x6265 {
}
object kernel_x6265 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6262:Int,x1065:Boolean,x6261:Array[Boolean]): activation_x6265 = {
val x6265_closure = new generated.scala.DeliteOpMultiLoop[activation_x6265] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6262
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6265 = {
val __act: activation_x6265 = new activation_x6265()
__act.x6265_zero = x1065
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6265,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6265]): activation_x6265 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6265 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6265 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6265): activation_x6265 = {
val act: activation_x6265 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6265,start:Long,end:Long): activation_x6265 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6265 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6265,x1067:Int,isEmpty:Boolean): activation_x6265 = {
val __act2: activation_x6265 = new activation_x6265()
__act2.x6265_zero = __act.x6265_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x6265 = __act2.x6265_zero
if (!isEmpty) {
val x6263 = x6261(x1067.toInt)
__act2.x6265 = x6263
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6265,x1067:Int): Unit = {
val x6263 = x6261(x1067.toInt)
val x1072 = __act.x6265
val x1073 = x6263
val x1074 = {
x1072 && x1073
}
__act.x6265 = x1074
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6265,rhs:activation_x6265): Unit = {
val x1072 = __act.x6265
val x1073 = rhs.x6265
if (x1072 == __act.x6265_zero) {
__act.x6265 = x1073
}
else if (x1073 != __act.x6265_zero) {
val x1074 = {
x1072 && x1073
}
__act.x6265 = x1074
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6265,lhs:activation_x6265): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6265): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6265): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6265): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6265 = {
val act: activation_x6265 = new activation_x6265
act.x6265_zero = x1065
act
}

}
x6265_closure.loopStart = 0
x6265_closure.loopSize = x6262
val alloc: activation_x6265 = x6265_closure.alloc(resourceInfo)
var x6265: activation_x6265 = null
if (resourceInfo.availableThreads <= 1) {
x6265 = x6265_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6265] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6265](x6265_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6265_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6265 = x6265_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6265
}}

/**********/

