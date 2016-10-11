package generated.scala
//activation record for fat loop
final class activation_x6206 {
var left_act: activation_x6206 = _
var x6206: Array[FixedPoint[Signed,B32,B0]] = _
var x6206_data: Array[FixedPoint[Signed,B32,B0]] = _
var x6206_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x6206_size: Int = _
var x6206_offset: Int = _
var x6206_conditionals: Int = _
def x6206_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x6206_data = xs
x6206_conditionals = cs
if (left_act ne null)
left_act.x6206_data_set(resourceInfo,xs,cs)
}

}
object activation_x6206 {
}
object kernel_x6206 {
def apply(resourceInfo:generated.scala.ResourceInfo,x7:Int,x6204:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x6206 = {
val x6206_closure = new generated.scala.DeliteOpMultiLoop[activation_x6206] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x7
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6206 = {
val __act: activation_x6206 = new activation_x6206()
// __act.x6206 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6206,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6206]): activation_x6206 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6206 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6206 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x6206 = act
while (j < localEnd) {
val rhsAct: activation_x6206 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6206): activation_x6206 = {
val act: activation_x6206 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6206,start:Long,end:Long): activation_x6206 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6206 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6206,x374:Int,isEmpty:Boolean): activation_x6206 = {
val __act2: activation_x6206 = new activation_x6206()
val x382 = 0
if (x382 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5661 = new Array[FixedPoint[Signed,B32,B0]](x382.toInt)
__act2.x6206_buf = x5661
if (!isEmpty) {
val x6205 = x6204(x374.toInt)
val x377 = x6205
val x378 = x377.length
var x376: Int = 0
while (x376 < x378) { //flatMap loop
val x379 = x377(x376.toInt)
val x380 = __act2.x6206_buf
val x381 = x379
if (true) {
val x5667 = __act2.x6206_size
val x5668 = x380.length
val x5669 = x5668 - 1
val x5670 = x5667 > x5669
val x5683 = {
def x5683thenb(): Unit = {
val x5671 = x5668 < 16
val x5675 = {
def x5675thenb(): Int = {
16
}
def x5675elseb(): Int = {
val x5672 = x5668 * 2
val x5673 = x5672 < 0
val x5674 = {
def x5674thenb(): Int = {
2147483647
}
def x5674elseb(): Int = {
x5672
}
if (x5673) {
x5674thenb()
} else { 
x5674elseb()
}
}
x5674
}
if (x5671) {
x5675thenb()
} else { 
x5675elseb()
}
}
if (x5675 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5676 = new Array[FixedPoint[Signed,B32,B0]](x5675.toInt)
val x5677 = System.arraycopy(x380,0.toInt,x5676,0.toInt,x5668.toInt)
val x5678 = x5676(x5667.toInt) = x381
val x5679 = __act2.x6206_buf = x5676
x5679
}
def x5683elseb(): Unit = {
val x5681 = x380(x5667.toInt) = x381
x5681
}
if (x5670) {
x5683thenb()
} else { 
x5683elseb()
}
}
__act2.x6206_size = __act2.x6206_size + 1
}
__act2.x6206_conditionals = __act2.x6206_conditionals + 1
x376 = x376 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6206,x374:Int): Unit = {
val x6205 = x6204(x374.toInt)
val x377 = x6205
val x378 = x377.length
var x376: Int = 0
while (x376 < x378) { //flatMap loop
val x379 = x377(x376.toInt)
val x380 = __act.x6206_buf
val x381 = x379
if (true) {
val x5667 = __act.x6206_size
val x5668 = x380.length
val x5669 = x5668 - 1
val x5670 = x5667 > x5669
val x5683 = {
def x5683thenb(): Unit = {
val x5671 = x5668 < 16
val x5675 = {
def x5675thenb(): Int = {
16
}
def x5675elseb(): Int = {
val x5672 = x5668 * 2
val x5673 = x5672 < 0
val x5674 = {
def x5674thenb(): Int = {
2147483647
}
def x5674elseb(): Int = {
x5672
}
if (x5673) {
x5674thenb()
} else { 
x5674elseb()
}
}
x5674
}
if (x5671) {
x5675thenb()
} else { 
x5675elseb()
}
}
if (x5675 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5676 = new Array[FixedPoint[Signed,B32,B0]](x5675.toInt)
val x5677 = System.arraycopy(x380,0.toInt,x5676,0.toInt,x5668.toInt)
val x5678 = x5676(x5667.toInt) = x381
val x5679 = __act.x6206_buf = x5676
x5679
}
def x5683elseb(): Unit = {
val x5681 = x380(x5667.toInt) = x381
x5681
}
if (x5670) {
x5683thenb()
} else { 
x5683elseb()
}
}
__act.x6206_size = __act.x6206_size + 1
}
__act.x6206_conditionals = __act.x6206_conditionals + 1
x376 = x376 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6206,rhs:activation_x6206): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6206,lhs:activation_x6206): Unit = {
__act.x6206_offset = lhs.x6206_offset+lhs.x6206_size
__act.x6206_conditionals = __act.x6206_conditionals+lhs.x6206_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6206): Unit = {
if (__act.x6206_offset > 0) {
val x382 = __act.x6206_offset + __act.x6206_size
val x380 = __act.x6206_buf
if (x382 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5693 = new Array[FixedPoint[Signed,B32,B0]](x382.toInt)
__act.x6206_data_set(resourceInfo,x5693,__act.x6206_conditionals)
} else {
__act.x6206_data_set(resourceInfo,__act.x6206_buf,__act.x6206_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6206): Unit = {
if (__act.x6206_data ne __act.x6206_buf) {
val x382 = __act.x6206_size
val x385 = __act.x6206_buf
val x380 = __act.x6206_data
val x383 = 0
val x384 = __act.x6206_offset
val x5695 = System.arraycopy(x385,x383.toInt,x380,x384.toInt,x382.toInt)
}
__act.x6206_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6206): Unit = {
var x380: Array[FixedPoint[Signed,B32,B0]] = __act.x6206_data
__act.x6206_data = null
val x382 = __act.x6206_conditionals
val x5685 = x380.length
val x5686 = x5685 > x382
val x5691 = {
def x5691thenb(): Unit = {
if (x382 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5687 = new Array[FixedPoint[Signed,B32,B0]](x382.toInt)
val x5688 = System.arraycopy(x380,0.toInt,x5687,0.toInt,x382.toInt)
val x5689 = x380 = x5687
x5689
}
if (x5686) {
x5691thenb()
}
}
__act.x6206 = x380
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6206 = {
val act: activation_x6206 = new activation_x6206
act
}

}
x6206_closure.loopStart = 0
x6206_closure.loopSize = x7
val alloc: activation_x6206 = x6206_closure.alloc(resourceInfo)
var x6206: activation_x6206 = null
if (resourceInfo.availableThreads <= 1) {
x6206 = x6206_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6206] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6206](x6206_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6206_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6206 = x6206_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6206
}}

/**********/

