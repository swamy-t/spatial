package generated.scala
//activation record for fat loop
final class activation_x1954 {
var left_act: activation_x1954 = _
var x1954: Array[FixedPoint[Signed,B32,B0]] = _
var x1954_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1954 {
}
object kernel_x1954 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6:Int,x1916:Array[FixedPoint[Signed,B32,B0]]): activation_x1954 = {
val x1954_closure = new generated.scala.DeliteOpMultiLoop[activation_x1954] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1954 = {
val __act: activation_x1954 = new activation_x1954()
val x277 = (loopSize).asInstanceOf[Int]
if (x277 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1918 = new Array[FixedPoint[Signed,B32,B0]](x277.toInt)
__act.x1954_data = x1918
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1954,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1954]): activation_x1954 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1954 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1954 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1954): activation_x1954 = {
val act: activation_x1954 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1954,start:Long,end:Long): activation_x1954 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1954 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1954,x273:Int,isEmpty:Boolean): activation_x1954 = {
if (!isEmpty) {
process(resourceInfo,__act,x273)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1954,x273:Int): Unit = {
val x1917 = x1916(x273.toInt)
val x276 = x1917
val x275 = __act.x1954_data
val x1922 = x275(x273.toInt) = x276
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1954,rhs:activation_x1954): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1954,lhs:activation_x1954): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1954): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1954): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1954): Unit = {
var x275: Array[FixedPoint[Signed,B32,B0]] = __act.x1954_data
__act.x1954_data = null
__act.x1954 = x275
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1954 = {
val act: activation_x1954 = new activation_x1954
act
}

}
x1954_closure.loopStart = 0
x1954_closure.loopSize = x6
val alloc: activation_x1954 = x1954_closure.alloc(resourceInfo)
var x1954: activation_x1954 = null
if (resourceInfo.availableThreads <= 1) {
x1954 = x1954_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1954] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1954](x1954_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1954_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1954 = x1954_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1954
}}

/**********/

