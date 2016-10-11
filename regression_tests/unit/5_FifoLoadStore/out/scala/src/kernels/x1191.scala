package generated.scala
//activation record for fat loop
final class activation_x1191 {
var left_act: activation_x1191 = _
var x1191: Array[Boolean] = _
var x1191_data: Array[Boolean] = _
}
object activation_x1191 {
}
object kernel_x1191 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1150:Int,x1096:Array[FixedPoint[Signed,B32,B0]],x1136:Array[FixedPoint[Signed,B32,B0]]): activation_x1191 = {
val x1191_closure = new generated.scala.DeliteOpMultiLoop[activation_x1191] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x1150
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1191 = {
val __act: activation_x1191 = new activation_x1191()
val x153 = (loopSize).asInstanceOf[Int]
if (x153 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1155 = new Array[Boolean](x153.toInt)
__act.x1191_data = x1155
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1191,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1191]): activation_x1191 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1191 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1191 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1191): activation_x1191 = {
val act: activation_x1191 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1191,start:Long,end:Long): activation_x1191 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1191 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1191,x146:Int,isEmpty:Boolean): activation_x1191 = {
if (!isEmpty) {
process(resourceInfo,__act,x146)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1191,x146:Int): Unit = {
val x1151 = x1096(x146.toInt)
val x1152 = x1136(x146.toInt)
val x1153 = {
x1151 == x1152
}
val x152 = x1153
val x151 = __act.x1191_data
val x1159 = x151(x146.toInt) = x152
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1191,rhs:activation_x1191): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1191,lhs:activation_x1191): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1191): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1191): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1191): Unit = {
var x151: Array[Boolean] = __act.x1191_data
__act.x1191_data = null
__act.x1191 = x151
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1191 = {
val act: activation_x1191 = new activation_x1191
act
}

}
x1191_closure.loopStart = 0
x1191_closure.loopSize = x1150
val alloc: activation_x1191 = x1191_closure.alloc(resourceInfo)
var x1191: activation_x1191 = null
if (resourceInfo.availableThreads <= 1) {
x1191 = x1191_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1191] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1191](x1191_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1191_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1191 = x1191_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1191
}}

/**********/

