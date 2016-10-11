package generated.scala
//activation record for fat loop
final class activation_x6180 {
var left_act: activation_x6180 = _
var x6180: Array[FixedPoint[Signed,B32,B0]] = _
var x6180_data: Array[FixedPoint[Signed,B32,B0]] = _
var x6180_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x6180_size: Int = _
var x6180_offset: Int = _
var x6180_conditionals: Int = _
def x6180_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x6180_data = xs
x6180_conditionals = cs
if (left_act ne null)
left_act.x6180_data_set(resourceInfo,xs,cs)
}

}
object activation_x6180 {
}
object kernel_x6180 {
def apply(resourceInfo:generated.scala.ResourceInfo,x9:Int,x6178:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x6180 = {
val x6180_closure = new generated.scala.DeliteOpMultiLoop[activation_x6180] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x9
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6180 = {
val __act: activation_x6180 = new activation_x6180()
// __act.x6180 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6180,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6180]): activation_x6180 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6180 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6180 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x6180 = act
while (j < localEnd) {
val rhsAct: activation_x6180 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6180): activation_x6180 = {
val act: activation_x6180 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6180,start:Long,end:Long): activation_x6180 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6180 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6180,x325:Int,isEmpty:Boolean): activation_x6180 = {
val __act2: activation_x6180 = new activation_x6180()
val x333 = 0
if (x333 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5527 = new Array[FixedPoint[Signed,B32,B0]](x333.toInt)
__act2.x6180_buf = x5527
if (!isEmpty) {
val x6179 = x6178(x325.toInt)
val x328 = x6179
val x329 = x328.length
var x327: Int = 0
while (x327 < x329) { //flatMap loop
val x330 = x328(x327.toInt)
val x331 = __act2.x6180_buf
val x332 = x330
if (true) {
val x5533 = __act2.x6180_size
val x5534 = x331.length
val x5535 = x5534 - 1
val x5536 = x5533 > x5535
val x5549 = {
def x5549thenb(): Unit = {
val x5537 = x5534 < 16
val x5541 = {
def x5541thenb(): Int = {
16
}
def x5541elseb(): Int = {
val x5538 = x5534 * 2
val x5539 = x5538 < 0
val x5540 = {
def x5540thenb(): Int = {
2147483647
}
def x5540elseb(): Int = {
x5538
}
if (x5539) {
x5540thenb()
} else { 
x5540elseb()
}
}
x5540
}
if (x5537) {
x5541thenb()
} else { 
x5541elseb()
}
}
if (x5541 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5542 = new Array[FixedPoint[Signed,B32,B0]](x5541.toInt)
val x5543 = System.arraycopy(x331,0.toInt,x5542,0.toInt,x5534.toInt)
val x5544 = x5542(x5533.toInt) = x332
val x5545 = __act2.x6180_buf = x5542
x5545
}
def x5549elseb(): Unit = {
val x5547 = x331(x5533.toInt) = x332
x5547
}
if (x5536) {
x5549thenb()
} else { 
x5549elseb()
}
}
__act2.x6180_size = __act2.x6180_size + 1
}
__act2.x6180_conditionals = __act2.x6180_conditionals + 1
x327 = x327 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6180,x325:Int): Unit = {
val x6179 = x6178(x325.toInt)
val x328 = x6179
val x329 = x328.length
var x327: Int = 0
while (x327 < x329) { //flatMap loop
val x330 = x328(x327.toInt)
val x331 = __act.x6180_buf
val x332 = x330
if (true) {
val x5533 = __act.x6180_size
val x5534 = x331.length
val x5535 = x5534 - 1
val x5536 = x5533 > x5535
val x5549 = {
def x5549thenb(): Unit = {
val x5537 = x5534 < 16
val x5541 = {
def x5541thenb(): Int = {
16
}
def x5541elseb(): Int = {
val x5538 = x5534 * 2
val x5539 = x5538 < 0
val x5540 = {
def x5540thenb(): Int = {
2147483647
}
def x5540elseb(): Int = {
x5538
}
if (x5539) {
x5540thenb()
} else { 
x5540elseb()
}
}
x5540
}
if (x5537) {
x5541thenb()
} else { 
x5541elseb()
}
}
if (x5541 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5542 = new Array[FixedPoint[Signed,B32,B0]](x5541.toInt)
val x5543 = System.arraycopy(x331,0.toInt,x5542,0.toInt,x5534.toInt)
val x5544 = x5542(x5533.toInt) = x332
val x5545 = __act.x6180_buf = x5542
x5545
}
def x5549elseb(): Unit = {
val x5547 = x331(x5533.toInt) = x332
x5547
}
if (x5536) {
x5549thenb()
} else { 
x5549elseb()
}
}
__act.x6180_size = __act.x6180_size + 1
}
__act.x6180_conditionals = __act.x6180_conditionals + 1
x327 = x327 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6180,rhs:activation_x6180): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6180,lhs:activation_x6180): Unit = {
__act.x6180_offset = lhs.x6180_offset+lhs.x6180_size
__act.x6180_conditionals = __act.x6180_conditionals+lhs.x6180_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6180): Unit = {
if (__act.x6180_offset > 0) {
val x333 = __act.x6180_offset + __act.x6180_size
val x331 = __act.x6180_buf
if (x333 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5559 = new Array[FixedPoint[Signed,B32,B0]](x333.toInt)
__act.x6180_data_set(resourceInfo,x5559,__act.x6180_conditionals)
} else {
__act.x6180_data_set(resourceInfo,__act.x6180_buf,__act.x6180_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6180): Unit = {
if (__act.x6180_data ne __act.x6180_buf) {
val x333 = __act.x6180_size
val x336 = __act.x6180_buf
val x331 = __act.x6180_data
val x334 = 0
val x335 = __act.x6180_offset
val x5561 = System.arraycopy(x336,x334.toInt,x331,x335.toInt,x333.toInt)
}
__act.x6180_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6180): Unit = {
var x331: Array[FixedPoint[Signed,B32,B0]] = __act.x6180_data
__act.x6180_data = null
val x333 = __act.x6180_conditionals
val x5551 = x331.length
val x5552 = x5551 > x333
val x5557 = {
def x5557thenb(): Unit = {
if (x333 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5553 = new Array[FixedPoint[Signed,B32,B0]](x333.toInt)
val x5554 = System.arraycopy(x331,0.toInt,x5553,0.toInt,x333.toInt)
val x5555 = x331 = x5553
x5555
}
if (x5552) {
x5557thenb()
}
}
__act.x6180 = x331
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6180 = {
val act: activation_x6180 = new activation_x6180
act
}

}
x6180_closure.loopStart = 0
x6180_closure.loopSize = x9
val alloc: activation_x6180 = x6180_closure.alloc(resourceInfo)
var x6180: activation_x6180 = null
if (resourceInfo.availableThreads <= 1) {
x6180 = x6180_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6180] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6180](x6180_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6180_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6180 = x6180_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6180
}}

/**********/

