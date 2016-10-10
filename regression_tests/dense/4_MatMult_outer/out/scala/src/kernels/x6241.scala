package generated.scala
//activation record for fat loop
final class activation_x6241 {
var left_act: activation_x6241 = _
var x6241: FixedPoint[Signed,B32,B0] = _
var x6241_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x6241 {
}
object kernel_x6241 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6238:Int,x189:FixedPoint[Signed,B32,B0],x6237:Array[FixedPoint[Signed,B32,B0]]): activation_x6241 = {
val x6241_closure = new generated.scala.DeliteOpMultiLoop[activation_x6241] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6238
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6241 = {
val __act: activation_x6241 = new activation_x6241()
__act.x6241_zero = x189
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6241,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6241]): activation_x6241 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6241 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6241 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6241): activation_x6241 = {
val act: activation_x6241 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6241,start:Long,end:Long): activation_x6241 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6241 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6241,x984:Int,isEmpty:Boolean): activation_x6241 = {
val __act2: activation_x6241 = new activation_x6241()
__act2.x6241_zero = __act.x6241_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x6241 = __act2.x6241_zero
if (!isEmpty) {
val x6239 = x6237(x984.toInt)
__act2.x6241 = x6239
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6241,x984:Int): Unit = {
val x6239 = x6237(x984.toInt)
val x989 = __act.x6241
val x990 = x6239
val x991 = {
x989 + x990
}
__act.x6241 = x991
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6241,rhs:activation_x6241): Unit = {
val x989 = __act.x6241
val x990 = rhs.x6241
if (x989 == __act.x6241_zero) {
__act.x6241 = x990
}
else if (x990 != __act.x6241_zero) {
val x991 = {
x989 + x990
}
__act.x6241 = x991
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6241,lhs:activation_x6241): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6241): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6241): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6241): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6241 = {
val act: activation_x6241 = new activation_x6241
act.x6241_zero = x189
act
}

}
x6241_closure.loopStart = 0
x6241_closure.loopSize = x6238
val alloc: activation_x6241 = x6241_closure.alloc(resourceInfo)
var x6241: activation_x6241 = null
if (resourceInfo.availableThreads <= 1) {
x6241 = x6241_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6241] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6241](x6241_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6241_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6241 = x6241_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6241
}}

/**********/

