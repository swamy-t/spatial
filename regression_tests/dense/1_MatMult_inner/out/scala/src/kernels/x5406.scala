package generated.scala
//activation record for fat loop
final class activation_x5406 {
var left_act: activation_x5406 = _
var x5406: FixedPoint[Signed,B32,B0] = _
var x5406_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x5406 {
}
object kernel_x5406 {
def apply(resourceInfo:generated.scala.ResourceInfo,x5400:Int,x285:FixedPoint[Signed,B32,B0],x5404:Array[FixedPoint[Signed,B32,B0]]): activation_x5406 = {
val x5406_closure = new generated.scala.DeliteOpMultiLoop[activation_x5406] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x5400
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5406 = {
val __act: activation_x5406 = new activation_x5406()
__act.x5406_zero = x285
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5406,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5406]): activation_x5406 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5406 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5406 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5406): activation_x5406 = {
val act: activation_x5406 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5406,start:Long,end:Long): activation_x5406 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5406 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5406,x759:Int,isEmpty:Boolean): activation_x5406 = {
val __act2: activation_x5406 = new activation_x5406()
__act2.x5406_zero = __act.x5406_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x5406 = __act2.x5406_zero
if (!isEmpty) {
val x5405 = x5404(x759.toInt)
__act2.x5406 = x5405
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5406,x759:Int): Unit = {
val x5405 = x5404(x759.toInt)
val x763 = __act.x5406
val x764 = x5405
val x765 = {
x763 + x764
}
__act.x5406 = x765
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5406,rhs:activation_x5406): Unit = {
val x763 = __act.x5406
val x764 = rhs.x5406
if (x763 == __act.x5406_zero) {
__act.x5406 = x764
}
else if (x764 != __act.x5406_zero) {
val x765 = {
x763 + x764
}
__act.x5406 = x765
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5406,lhs:activation_x5406): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5406): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5406): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5406): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5406 = {
val act: activation_x5406 = new activation_x5406
act.x5406_zero = x285
act
}

}
x5406_closure.loopStart = 0
x5406_closure.loopSize = x5400
val alloc: activation_x5406 = x5406_closure.alloc(resourceInfo)
var x5406: activation_x5406 = null
if (resourceInfo.availableThreads <= 1) {
x5406 = x5406_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5406] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5406](x5406_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5406_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5406 = x5406_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5406
}}

/**********/

