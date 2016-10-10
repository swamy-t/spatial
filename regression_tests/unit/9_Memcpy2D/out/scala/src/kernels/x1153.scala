package generated.scala
//activation record for fat loop
final class activation_x1153 {
var left_act: activation_x1153 = _
var x1153: Boolean = _
var x1153_zero: Boolean = _
}
object activation_x1153 {
}
object kernel_x1153 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1148:Int,x201:Boolean,x1147:Array[Boolean]): activation_x1153 = {
val x1153_closure = new generated.scala.DeliteOpMultiLoop[activation_x1153] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1148
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1153 = {
val __act: activation_x1153 = new activation_x1153()
__act.x1153_zero = x201
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1153,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1153]): activation_x1153 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1153 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1153 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1153): activation_x1153 = {
val act: activation_x1153 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1153,start:Long,end:Long): activation_x1153 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1153 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1153,x203:Int,isEmpty:Boolean): activation_x1153 = {
val __act2: activation_x1153 = new activation_x1153()
__act2.x1153_zero = __act.x1153_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x1153 = __act2.x1153_zero
if (!isEmpty) {
val x1149 = x1147(x203.toInt)
__act2.x1153 = x1149
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1153,x203:Int): Unit = {
val x1149 = x1147(x203.toInt)
val x208 = __act.x1153
val x209 = x1149
val x210 = {
x208 && x209
}
__act.x1153 = x210
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1153,rhs:activation_x1153): Unit = {
val x208 = __act.x1153
val x209 = rhs.x1153
if (x208 == __act.x1153_zero) {
__act.x1153 = x209
}
else if (x209 != __act.x1153_zero) {
val x210 = {
x208 && x209
}
__act.x1153 = x210
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1153,lhs:activation_x1153): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1153): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1153): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1153): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1153 = {
val act: activation_x1153 = new activation_x1153
act.x1153_zero = x201
act
}

}
x1153_closure.loopStart = 0
x1153_closure.loopSize = x1148
val alloc: activation_x1153 = x1153_closure.alloc(resourceInfo)
var x1153: activation_x1153 = null
if (resourceInfo.availableThreads <= 1) {
x1153 = x1153_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1153] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1153](x1153_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1153_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1153 = x1153_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1153
}}

/**********/

