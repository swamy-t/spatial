package generated.scala
//activation record for fat loop
final class activation_x3096 {
var left_act: activation_x3096 = _
var x3096: FixedPoint[Signed,B32,B0] = _
var x3096_zero: FixedPoint[Signed,B32,B0] = _
}
object activation_x3096 {
}
object kernel_x3096 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x195:FixedPoint[Signed,B32,B0],x3092:Array[FixedPoint[Signed,B32,B0]]): activation_x3096 = {
val x3096_closure = new generated.scala.DeliteOpMultiLoop[activation_x3096] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3096 = {
val __act: activation_x3096 = new activation_x3096()
__act.x3096_zero = x195
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3096,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3096]): activation_x3096 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3096 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3096 = sync.get(localStart)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3096): activation_x3096 = {
val act: activation_x3096 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3096,start:Long,end:Long): activation_x3096 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3096 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3096,x464:Int,isEmpty:Boolean): activation_x3096 = {
val __act2: activation_x3096 = new activation_x3096()
__act2.x3096_zero = __act.x3096_zero
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2.x3096 = __act2.x3096_zero
if (!isEmpty) {
val x3093 = x3092(x464.toInt)
__act2.x3096 = x3093
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3096,x464:Int): Unit = {
val x3093 = x3092(x464.toInt)
val x468 = __act.x3096
val x469 = x3093
val x470 = {
x468 + x469
}
__act.x3096 = x470
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3096,rhs:activation_x3096): Unit = {
val x468 = __act.x3096
val x469 = rhs.x3096
if (x468 == __act.x3096_zero) {
__act.x3096 = x469
}
else if (x469 != __act.x3096_zero) {
val x470 = {
x468 + x469
}
__act.x3096 = x470
}
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3096,lhs:activation_x3096): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3096): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3096): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3096): Unit = {
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3096 = {
val act: activation_x3096 = new activation_x3096
act.x3096_zero = x195
act
}

}
x3096_closure.loopStart = 0
x3096_closure.loopSize = x3
val alloc: activation_x3096 = x3096_closure.alloc(resourceInfo)
var x3096: activation_x3096 = null
if (resourceInfo.availableThreads <= 1) {
x3096 = x3096_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3096] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3096](x3096_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3096_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3096 = x3096_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3096
}}

/**********/

