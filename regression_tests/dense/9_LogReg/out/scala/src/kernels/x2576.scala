package generated.scala
//activation record for fat loop
final class activation_x2576 {
var left_act: activation_x2576 = _
var x2576: Array[FloatPoint[B24,B8]] = _
var x2576_data: Array[FloatPoint[B24,B8]] = _
var x2576_buf: Array[FloatPoint[B24,B8]] = _
var x2576_size: Int = _
var x2576_offset: Int = _
var x2576_conditionals: Int = _
def x2576_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FloatPoint[B24,B8]],cs:Int): Unit = {
x2576_data = xs
x2576_conditionals = cs
if (left_act ne null)
left_act.x2576_data_set(resourceInfo,xs,cs)
}

}
object activation_x2576 {
}
object kernel_x2576 {
def apply(resourceInfo:generated.scala.ResourceInfo,x2538:Int,x2448:Array[Array[FloatPoint[B24,B8]]]): activation_x2576 = {
val x2576_closure = new generated.scala.DeliteOpMultiLoop[activation_x2576] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x2538
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2576 = {
val __act: activation_x2576 = new activation_x2576()
// __act.x2576 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2576,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2576]): activation_x2576 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2576 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2576 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x2576 = act
while (j < localEnd) {
val rhsAct: activation_x2576 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2576): activation_x2576 = {
val act: activation_x2576 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2576,start:Long,end:Long): activation_x2576 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2576 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2576,x195:Int,isEmpty:Boolean): activation_x2576 = {
val __act2: activation_x2576 = new activation_x2576()
val x203 = 0
if (x203 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2539 = new Array[FloatPoint[B24,B8]](x203.toInt)
__act2.x2576_buf = x2539
if (!isEmpty) {
val x2575 = x2448(x195.toInt)
val x198 = x2575
val x199 = x198.length
var x197: Int = 0
while (x197 < x199) { //flatMap loop
val x200 = x198(x197.toInt)
val x201 = __act2.x2576_buf
val x202 = x200
if (true) {
val x2545 = __act2.x2576_size
val x2546 = x201.length
val x2547 = x2546 - 1
val x2548 = x2545 > x2547
val x2561 = {
def x2561thenb(): Unit = {
val x2549 = x2546 < 16
val x2553 = {
def x2553thenb(): Int = {
16
}
def x2553elseb(): Int = {
val x2550 = x2546 * 2
val x2551 = x2550 < 0
val x2552 = {
def x2552thenb(): Int = {
2147483647
}
def x2552elseb(): Int = {
x2550
}
if (x2551) {
x2552thenb()
} else { 
x2552elseb()
}
}
x2552
}
if (x2549) {
x2553thenb()
} else { 
x2553elseb()
}
}
if (x2553 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2554 = new Array[FloatPoint[B24,B8]](x2553.toInt)
val x2555 = System.arraycopy(x201,0.toInt,x2554,0.toInt,x2546.toInt)
val x2556 = x2554(x2545.toInt) = x202
val x2557 = __act2.x2576_buf = x2554
x2557
}
def x2561elseb(): Unit = {
val x2559 = x201(x2545.toInt) = x202
x2559
}
if (x2548) {
x2561thenb()
} else { 
x2561elseb()
}
}
__act2.x2576_size = __act2.x2576_size + 1
}
__act2.x2576_conditionals = __act2.x2576_conditionals + 1
x197 = x197 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2576,x195:Int): Unit = {
val x2575 = x2448(x195.toInt)
val x198 = x2575
val x199 = x198.length
var x197: Int = 0
while (x197 < x199) { //flatMap loop
val x200 = x198(x197.toInt)
val x201 = __act.x2576_buf
val x202 = x200
if (true) {
val x2545 = __act.x2576_size
val x2546 = x201.length
val x2547 = x2546 - 1
val x2548 = x2545 > x2547
val x2561 = {
def x2561thenb(): Unit = {
val x2549 = x2546 < 16
val x2553 = {
def x2553thenb(): Int = {
16
}
def x2553elseb(): Int = {
val x2550 = x2546 * 2
val x2551 = x2550 < 0
val x2552 = {
def x2552thenb(): Int = {
2147483647
}
def x2552elseb(): Int = {
x2550
}
if (x2551) {
x2552thenb()
} else { 
x2552elseb()
}
}
x2552
}
if (x2549) {
x2553thenb()
} else { 
x2553elseb()
}
}
if (x2553 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2554 = new Array[FloatPoint[B24,B8]](x2553.toInt)
val x2555 = System.arraycopy(x201,0.toInt,x2554,0.toInt,x2546.toInt)
val x2556 = x2554(x2545.toInt) = x202
val x2557 = __act.x2576_buf = x2554
x2557
}
def x2561elseb(): Unit = {
val x2559 = x201(x2545.toInt) = x202
x2559
}
if (x2548) {
x2561thenb()
} else { 
x2561elseb()
}
}
__act.x2576_size = __act.x2576_size + 1
}
__act.x2576_conditionals = __act.x2576_conditionals + 1
x197 = x197 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2576,rhs:activation_x2576): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2576,lhs:activation_x2576): Unit = {
__act.x2576_offset = lhs.x2576_offset+lhs.x2576_size
__act.x2576_conditionals = __act.x2576_conditionals+lhs.x2576_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2576): Unit = {
if (__act.x2576_offset > 0) {
val x203 = __act.x2576_offset + __act.x2576_size
val x201 = __act.x2576_buf
if (x203 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2571 = new Array[FloatPoint[B24,B8]](x203.toInt)
__act.x2576_data_set(resourceInfo,x2571,__act.x2576_conditionals)
} else {
__act.x2576_data_set(resourceInfo,__act.x2576_buf,__act.x2576_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2576): Unit = {
if (__act.x2576_data ne __act.x2576_buf) {
val x203 = __act.x2576_size
val x206 = __act.x2576_buf
val x201 = __act.x2576_data
val x204 = 0
val x205 = __act.x2576_offset
val x2573 = System.arraycopy(x206,x204.toInt,x201,x205.toInt,x203.toInt)
}
__act.x2576_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2576): Unit = {
var x201: Array[FloatPoint[B24,B8]] = __act.x2576_data
__act.x2576_data = null
val x203 = __act.x2576_conditionals
val x2563 = x201.length
val x2564 = x2563 > x203
val x2569 = {
def x2569thenb(): Unit = {
if (x203 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2565 = new Array[FloatPoint[B24,B8]](x203.toInt)
val x2566 = System.arraycopy(x201,0.toInt,x2565,0.toInt,x203.toInt)
val x2567 = x201 = x2565
x2567
}
if (x2564) {
x2569thenb()
}
}
__act.x2576 = x201
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2576 = {
val act: activation_x2576 = new activation_x2576
act
}

}
x2576_closure.loopStart = 0
x2576_closure.loopSize = x2538
val alloc: activation_x2576 = x2576_closure.alloc(resourceInfo)
var x2576: activation_x2576 = null
if (resourceInfo.availableThreads <= 1) {
x2576 = x2576_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2576] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2576](x2576_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2576_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2576 = x2576_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2576
}}

/**********/

