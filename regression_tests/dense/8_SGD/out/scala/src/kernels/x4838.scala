package generated.scala
//activation record for fat loop
final class activation_x4838 {
var left_act: activation_x4838 = _
var x4838: Array[Boolean] = _
var x4838_data: Array[Boolean] = _
}
object activation_x4838 {
}
object kernel_x4838 {
def apply(resourceInfo:generated.scala.ResourceInfo,x4793:Int,x4493:Array[FixedPoint[Signed,B32,B0]],x4491:Array[FixedPoint[Signed,B32,B0]],x303:FixedPoint[Signed,B32,B0]): activation_x4838 = {
val x4838_closure = new generated.scala.DeliteOpMultiLoop[activation_x4838] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x4793
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x4838 = {
val __act: activation_x4838 = new activation_x4838()
val x797 = (loopSize).asInstanceOf[Int]
if (x797 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4802 = new Array[Boolean](x797.toInt)
__act.x4838_data = x4802
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4838,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x4838]): activation_x4838 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x4838 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x4838 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4838): activation_x4838 = {
val act: activation_x4838 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4838,start:Long,end:Long): activation_x4838 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x4838 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4838,x786:Int,isEmpty:Boolean): activation_x4838 = {
if (!isEmpty) {
process(resourceInfo,__act,x786)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4838,x786:Int): Unit = {
val x4794 = x4493(x786.toInt)
val x4795 = x4491(x786.toInt)
val x4796 = {
x4795 + x303
}
val x4797 = {
x4794 < x4796
}
val x4798 = {
x4795 - x303
}
val x4799 = {
x4798 < x4794
}
val x4800 = {
x4797 && x4799
}
val x796 = x4800
val x795 = __act.x4838_data
val x4806 = x795(x786.toInt) = x796
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4838,rhs:activation_x4838): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4838,lhs:activation_x4838): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4838): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4838): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4838): Unit = {
var x795: Array[Boolean] = __act.x4838_data
__act.x4838_data = null
__act.x4838 = x795
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x4838 = {
val act: activation_x4838 = new activation_x4838
act
}

}
x4838_closure.loopStart = 0
x4838_closure.loopSize = x4793
val alloc: activation_x4838 = x4838_closure.alloc(resourceInfo)
var x4838: activation_x4838 = null
if (resourceInfo.availableThreads <= 1) {
x4838 = x4838_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x4838] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x4838](x4838_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x4838_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x4838 = x4838_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x4838
}}

/**********/

