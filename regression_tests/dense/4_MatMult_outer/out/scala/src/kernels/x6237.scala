package generated.scala
//activation record for fat loop
final class activation_x6237 {
var left_act: activation_x6237 = _
var x6237: Array[FixedPoint[Signed,B32,B0]] = _
var x6237_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x6237 {
}
object kernel_x6237 {
def apply(resourceInfo:generated.scala.ResourceInfo,x6234:Int,x5834:Array[FixedPoint[Signed,B32,B0]]): activation_x6237 = {
val x6237_closure = new generated.scala.DeliteOpMultiLoop[activation_x6237] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x6234
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6237 = {
val __act: activation_x6237 = new activation_x6237()
val x942 = (loopSize).asInstanceOf[Int]
if (x942 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x6081 = new Array[FixedPoint[Signed,B32,B0]](x942.toInt)
__act.x6237_data = x6081
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6237,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6237]): activation_x6237 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6237 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6237 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6237): activation_x6237 = {
val act: activation_x6237 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6237,start:Long,end:Long): activation_x6237 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6237 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6237,x937:Int,isEmpty:Boolean): activation_x6237 = {
if (!isEmpty) {
process(resourceInfo,__act,x937)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6237,x937:Int): Unit = {
val x6079 = x5834(x937.toInt)
val x941 = x6079
val x940 = __act.x6237_data
val x6085 = x940(x937.toInt) = x941
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6237,rhs:activation_x6237): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6237,lhs:activation_x6237): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6237): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6237): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6237): Unit = {
var x940: Array[FixedPoint[Signed,B32,B0]] = __act.x6237_data
__act.x6237_data = null
__act.x6237 = x940
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6237 = {
val act: activation_x6237 = new activation_x6237
act
}

}
x6237_closure.loopStart = 0
x6237_closure.loopSize = x6234
val alloc: activation_x6237 = x6237_closure.alloc(resourceInfo)
var x6237: activation_x6237 = null
if (resourceInfo.availableThreads <= 1) {
x6237 = x6237_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6237] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6237](x6237_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6237_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6237 = x6237_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6237
}}

/**********/

