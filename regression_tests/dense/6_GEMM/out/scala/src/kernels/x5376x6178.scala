package generated.scala
//activation record for fat loop
final class activation_x5376x6178 {
var left_act: activation_x5376x6178 = _
var x5376: Array[FixedPoint[Signed,B32,B0]] = _
var x5376_data: Array[FixedPoint[Signed,B32,B0]] = _
var x6178: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x6178_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x5376x6178 {
}
object kernel_x5376x6178 {
def apply(resourceInfo:generated.scala.ResourceInfo,x9:Int,x11:FixedPoint[Signed,B32,B0],x5489:Array[FixedPoint[Signed,B32,B0]]): activation_x5376x6178 = {
val x5376x6178_closure = new generated.scala.DeliteOpMultiLoop[activation_x5376x6178] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x9
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5376x6178 = {
val __act: activation_x5376x6178 = new activation_x5376x6178()
val x14 = (loopSize).asInstanceOf[Int]
if (x14 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5340 = new Array[FixedPoint[Signed,B32,B0]](x14.toInt)
__act.x5376_data = x5340
val x146 = (loopSize).asInstanceOf[Int]
if (x146 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5490 = new Array[Array[FixedPoint[Signed,B32,B0]]](x146.toInt)
__act.x6178_data = x5490
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5376x6178,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5376x6178]): activation_x5376x6178 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5376x6178 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5376x6178 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5376x6178): activation_x5376x6178 = {
val act: activation_x5376x6178 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5376x6178,start:Long,end:Long): activation_x5376x6178 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5376x6178 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5376x6178,x10:Int,isEmpty:Boolean): activation_x5376x6178 = {
if (!isEmpty) {
process(resourceInfo,__act,x10)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5376x6178,x10:Int): Unit = {
val x13 = x11
val x12 = __act.x5376_data
val x5344 = x12(x10.toInt) = x13
val x145 = x5489
val x144 = __act.x6178_data
val x6176 = x144(x10.toInt) = x145
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5376x6178,rhs:activation_x5376x6178): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5376x6178,lhs:activation_x5376x6178): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5376x6178): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5376x6178): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5376x6178): Unit = {
var x12: Array[FixedPoint[Signed,B32,B0]] = __act.x5376_data
__act.x5376_data = null
__act.x5376 = x12
var x144: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x6178_data
__act.x6178_data = null
__act.x6178 = x144
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5376x6178 = {
val act: activation_x5376x6178 = new activation_x5376x6178
act
}

}
x5376x6178_closure.loopStart = 0
x5376x6178_closure.loopSize = x9
val alloc: activation_x5376x6178 = x5376x6178_closure.alloc(resourceInfo)
var x5376x6178: activation_x5376x6178 = null
if (resourceInfo.availableThreads <= 1) {
x5376x6178 = x5376x6178_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5376x6178] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5376x6178](x5376x6178_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5376x6178_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5376x6178 = x5376x6178_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5376x6178
}}

/**********/

