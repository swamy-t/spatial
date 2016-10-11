package generated.scala
//activation record for fat loop
final class activation_x2143 {
var left_act: activation_x2143 = _
var x2143: FixedPoint[Signed,B32,B0] = _
var x2143_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x2143 {
}
object kernel_x2143 {
def apply(resourceInfo:generated.scala.ResourceInfo,x161:Int,x96:FixedPoint[Signed,B32,B0],x2141:Array[FixedPoint[Signed,B32,B0]]): activation_x2143 = {
val x2143_closure = new generated.scala.DeliteOpMultiLoop[activation_x2143] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x161
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2143 = {
val __act: activation_x2143 = new activation_x2143()
__act.x2143_zero = x96
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2143,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2143]): activation_x2143 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2143 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2143 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2143): activation_x2143 = {
val act: activation_x2143 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2143,start:Long,end:Long): activation_x2143 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2143 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2143,x355:Int,isEmpty:Boolean): activation_x2143 = {
val __act2: activation_x2143 = new activation_x2143()
__act2.x2143_zero = __act.x2143_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x2143 = __act2.x2143_zero
if (!isEmpty) {
val x2142 = x2141(x355.toInt)
__act2.x2143 = x2142
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2143,x355:Int): Unit = {
val x2142 = x2141(x355.toInt)
val x359 = __act.x2143
val x360 = x2142
val x361 = {
x359 + x360
}
__act.x2143 = x361
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2143,rhs:activation_x2143): Unit = {
val x359 = __act.x2143
val x360 = rhs.x2143
if (x359 == __act.x2143_zero) {
__act.x2143 = x360
}
else if (x360 != __act.x2143_zero) {
val x361 = {
x359 + x360
}
__act.x2143 = x361
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2143,lhs:activation_x2143): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2143): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2143): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2143): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2143 = {
val act: activation_x2143 = new activation_x2143
act.x2143_zero = x96
act
}

}
x2143_closure.loopStart = 0
x2143_closure.loopSize = x161
val alloc: activation_x2143 = x2143_closure.alloc(resourceInfo)
var x2143: activation_x2143 = null
if (resourceInfo.availableThreads <= 1) {
x2143 = x2143_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2143] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2143](x2143_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2143_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2143 = x2143_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2143
}}

/**********/

