package generated.scala
//activation record for fat loop
final class activation_x6189 {
var left_act: activation_x6189 = _
var x6189: Array[FixedPoint[Signed,B32,B0]] = _
var x6189_data: Array[FixedPoint[Signed,B32,B0]] = _
var x6189_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x6189_size: Int = _
var x6189_offset: Int = _
var x6189_conditionals: Int = _
def x6189_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x6189_data = xs
x6189_conditionals = cs
if (left_act ne null)
left_act.x6189_data_set(resourceInfo,xs,cs)
}

}
object activation_x6189 {
}
object kernel_x6189 {
def apply(resourceInfo:generated.scala.ResourceInfo,x7:Int,x6187:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x6189 = {
val x6189_closure = new generated.scala.DeliteOpMultiLoop[activation_x6189] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x7
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6189 = {
val __act: activation_x6189 = new activation_x6189()
// __act.x6189 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6189,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6189]): activation_x6189 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6189 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6189 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x6189 = act
while (j < localEnd) {
val rhsAct: activation_x6189 = sync.get(j)
postCombine(resourceInfo,rhsAct,currentAct)
currentAct = rhsAct
j = j+1
}
if (tid == numThreads-1) postProcInit(resourceInfo,currentAct)
sync.setP(tid, currentAct)
sync.awaitBarrier
//post process
var k: Int = localStart
while (k < localEnd) {
postProcess(resourceInfo,sync.get(k))
k = k+1
}
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6189): activation_x6189 = {
val act: activation_x6189 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6189,start:Long,end:Long): activation_x6189 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6189 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6189,x374:Int,isEmpty:Boolean): activation_x6189 = {
val __act2: activation_x6189 = new activation_x6189()
val x382 = 0
if (x382 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5640 = new Array[FixedPoint[Signed,B32,B0]](x382.toInt)
__act2.x6189_buf = x5640
if (!isEmpty) {
val x6188 = x6187(x374.toInt)
val x377 = x6188
val x378 = x377.length
var x376: Int = 0
while (x376 < x378) { //flatMap loop
val x379 = x377(x376.toInt)
val x380 = __act2.x6189_buf
val x381 = x379
if (true) {
val x5646 = __act2.x6189_size
val x5647 = x380.length
val x5648 = x5647 - 1
val x5649 = x5646 > x5648
val x5662 = {
def x5662thenb(): Unit = {
val x5650 = x5647 < 16
val x5654 = {
def x5654thenb(): Int = {
16
}
def x5654elseb(): Int = {
val x5651 = x5647 * 2
val x5652 = x5651 < 0
val x5653 = {
def x5653thenb(): Int = {
2147483647
}
def x5653elseb(): Int = {
x5651
}
if (x5652) {
x5653thenb()
} else { 
x5653elseb()
}
}
x5653
}
if (x5650) {
x5654thenb()
} else { 
x5654elseb()
}
}
if (x5654 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5655 = new Array[FixedPoint[Signed,B32,B0]](x5654.toInt)
val x5656 = System.arraycopy(x380,0.toInt,x5655,0.toInt,x5647.toInt)
val x5657 = x5655(x5646.toInt) = x381
val x5658 = __act2.x6189_buf = x5655
x5658
}
def x5662elseb(): Unit = {
val x5660 = x380(x5646.toInt) = x381
x5660
}
if (x5649) {
x5662thenb()
} else { 
x5662elseb()
}
}
__act2.x6189_size = __act2.x6189_size + 1
}
__act2.x6189_conditionals = __act2.x6189_conditionals + 1
x376 = x376 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6189,x374:Int): Unit = {
val x6188 = x6187(x374.toInt)
val x377 = x6188
val x378 = x377.length
var x376: Int = 0
while (x376 < x378) { //flatMap loop
val x379 = x377(x376.toInt)
val x380 = __act.x6189_buf
val x381 = x379
if (true) {
val x5646 = __act.x6189_size
val x5647 = x380.length
val x5648 = x5647 - 1
val x5649 = x5646 > x5648
val x5662 = {
def x5662thenb(): Unit = {
val x5650 = x5647 < 16
val x5654 = {
def x5654thenb(): Int = {
16
}
def x5654elseb(): Int = {
val x5651 = x5647 * 2
val x5652 = x5651 < 0
val x5653 = {
def x5653thenb(): Int = {
2147483647
}
def x5653elseb(): Int = {
x5651
}
if (x5652) {
x5653thenb()
} else { 
x5653elseb()
}
}
x5653
}
if (x5650) {
x5654thenb()
} else { 
x5654elseb()
}
}
if (x5654 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5655 = new Array[FixedPoint[Signed,B32,B0]](x5654.toInt)
val x5656 = System.arraycopy(x380,0.toInt,x5655,0.toInt,x5647.toInt)
val x5657 = x5655(x5646.toInt) = x381
val x5658 = __act.x6189_buf = x5655
x5658
}
def x5662elseb(): Unit = {
val x5660 = x380(x5646.toInt) = x381
x5660
}
if (x5649) {
x5662thenb()
} else { 
x5662elseb()
}
}
__act.x6189_size = __act.x6189_size + 1
}
__act.x6189_conditionals = __act.x6189_conditionals + 1
x376 = x376 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6189,rhs:activation_x6189): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6189,lhs:activation_x6189): Unit = {
__act.x6189_offset = lhs.x6189_offset+lhs.x6189_size
__act.x6189_conditionals = __act.x6189_conditionals+lhs.x6189_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6189): Unit = {
if (__act.x6189_offset > 0) {
val x382 = __act.x6189_offset + __act.x6189_size
val x380 = __act.x6189_buf
if (x382 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5672 = new Array[FixedPoint[Signed,B32,B0]](x382.toInt)
__act.x6189_data_set(resourceInfo,x5672,__act.x6189_conditionals)
} else {
__act.x6189_data_set(resourceInfo,__act.x6189_buf,__act.x6189_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6189): Unit = {
if (__act.x6189_data ne __act.x6189_buf) {
val x382 = __act.x6189_size
val x385 = __act.x6189_buf
val x380 = __act.x6189_data
val x383 = 0
val x384 = __act.x6189_offset
val x5674 = System.arraycopy(x385,x383.toInt,x380,x384.toInt,x382.toInt)
}
__act.x6189_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6189): Unit = {
var x380: Array[FixedPoint[Signed,B32,B0]] = __act.x6189_data
__act.x6189_data = null
val x382 = __act.x6189_conditionals
val x5664 = x380.length
val x5665 = x5664 > x382
val x5670 = {
def x5670thenb(): Unit = {
if (x382 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5666 = new Array[FixedPoint[Signed,B32,B0]](x382.toInt)
val x5667 = System.arraycopy(x380,0.toInt,x5666,0.toInt,x382.toInt)
val x5668 = x380 = x5666
x5668
}
if (x5665) {
x5670thenb()
}
}
__act.x6189 = x380
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6189 = {
val act: activation_x6189 = new activation_x6189
act
}

}
x6189_closure.loopStart = 0
x6189_closure.loopSize = x7
val alloc: activation_x6189 = x6189_closure.alloc(resourceInfo)
var x6189: activation_x6189 = null
if (resourceInfo.availableThreads <= 1) {
x6189 = x6189_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6189] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6189](x6189_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6189_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6189 = x6189_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6189
}}

/**********/

