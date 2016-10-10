package generated.scala
//activation record for fat loop
final class activation_x3707 {
var left_act: activation_x3707 = _
var x3707: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x3707_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x3707 {
}
object kernel_x3707 {
def apply(resourceInfo:generated.scala.ResourceInfo,x314:Int,x206:FixedPoint[Signed,B32,B0],x312:FixedPoint[Signed,B32,B0],x451:Int,x405:Int,x197:FixedPoint[Signed,B32,B0]): activation_x3707 = {
val x3707_closure = new generated.scala.DeliteOpMultiLoop[activation_x3707] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x314
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3707 = {
val __act: activation_x3707 = new activation_x3707()
val x703 = (loopSize).asInstanceOf[Int]
if (x703 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3671 = new Array[Array[FixedPoint[Signed,B32,B0]]](x703.toInt)
__act.x3707_data = x3671
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3707,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3707]): activation_x3707 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3707 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3707 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3707): activation_x3707 = {
val act: activation_x3707 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3707,start:Long,end:Long): activation_x3707 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3707 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3707,x497:Int,isEmpty:Boolean): activation_x3707 = {
if (!isEmpty) {
process(resourceInfo,__act,x497)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3707,x497:Int): Unit = {
val x498 = {
FixedPoint[Signed,B32,B0](x497)
}
val x505 = {
x498 * x206
}
val x506 = {
x505 * x312
}
var x660: Int = x314
if (x660 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3634 = new Array[FixedPoint[Signed,B32,B0]](x660.toInt)
val x3670_data: Array[FixedPoint[Signed,B32,B0]] = x3634
var x3670_size: Int = 0
var x3670_conditionals: Int = 0
var x499: Int = 0
while (x499 < x314) {  // begin fat loop x3670
val x500 = {
FixedPoint[Signed,B32,B0](x499)
}
val x507 = {
x506 + x500
}
var x559: Int = x405
if (x559 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3554 = new Array[Array[FixedPoint[Signed,B32,B0]]](x559.toInt)
val x3590_data: Array[Array[FixedPoint[Signed,B32,B0]]] = x3554
var x3590_size: Int = 0
var x3590_conditionals: Int = 0
var x501: Int = 0
while (x501 < x405) {  // begin fat loop x3590
val x502 = {
FixedPoint[Signed,B32,B0](x501)
}
val x508 = {
x502 * x206
}
val x509 = {
x508 * x312
}
val x510 = {
x509 * x206
}
val x511 = {
x507 + x510
}
var x516: Int = x451
if (x516 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3517 = new Array[FixedPoint[Signed,B32,B0]](x516.toInt)
val x3553_data: Array[FixedPoint[Signed,B32,B0]] = x3517
var x3553_size: Int = 0
var x3553_conditionals: Int = 0
var x503: Int = 0
while (x503 < x451) {  // begin fat loop x3553
val x504 = {
FixedPoint[Signed,B32,B0](x503)
}
val x512 = {
x504 * x206
}
val x513 = {
x511 + x512
}
val x515 = x513
val x514 = x3553_data
val x3521 = x514(x503.toInt) = x515
x503 = x503 + 1
} // end fat loop x3553
val x514 = x3553_data
val x3553 = x514
val x558 = x3553
val x557 = x3590_data
val x3558 = x557(x501.toInt) = x558
x501 = x501 + 1
} // end fat loop x3590
val x557 = x3590_data
val x3590 = x557
var x608: Int = 0
if (x608 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3591 = new Array[FixedPoint[Signed,B32,B0]](x608.toInt)
var x3628_buf: Array[FixedPoint[Signed,B32,B0]] = x3591
var x3628_size: Int = 0
var x3628_conditionals: Int = 0
var x600: Int = 0
while (x600 < x405) {  // begin fat loop x3628
val x3627 = x3590(x600.toInt)
val x603 = x3627
val x604 = x603.length
var x602: Int = 0
while (x602 < x604) { //flatMap loop
val x605 = x603(x602.toInt)
val x606 = x3628_buf
val x607 = x605
if (true) {
val x3597 = x3628_size
val x3598 = x606.length
val x3599 = x3598 - 1
val x3600 = x3597 > x3599
val x3613 = {
def x3613thenb(): Unit = {
val x3601 = x3598 < 16
val x3605 = {
def x3605thenb(): Int = {
16
}
def x3605elseb(): Int = {
val x3602 = x3598 * 2
val x3603 = x3602 < 0
val x3604 = {
def x3604thenb(): Int = {
2147483647
}
def x3604elseb(): Int = {
x3602
}
if (x3603) {
x3604thenb()
} else { 
x3604elseb()
}
}
x3604
}
if (x3601) {
x3605thenb()
} else { 
x3605elseb()
}
}
if (x3605 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3606 = new Array[FixedPoint[Signed,B32,B0]](x3605.toInt)
val x3607 = System.arraycopy(x606,0.toInt,x3606,0.toInt,x3598.toInt)
val x3608 = x3606(x3597.toInt) = x607
val x3609 = x3628_buf = x3606
x3609
}
def x3613elseb(): Unit = {
val x3611 = x606(x3597.toInt) = x607
x3611
}
if (x3600) {
x3613thenb()
} else { 
x3613elseb()
}
}
x3628_size = x3628_size + 1
}
x3628_conditionals = x3628_conditionals + 1
x602 = x602 + 1
}
x600 = x600 + 1
} // end fat loop x3628
var x606: Array[FixedPoint[Signed,B32,B0]] = x3628_buf
x608 = x3628_conditionals
val x3615 = x606.length
val x3616 = x3615 > x608
val x3621 = {
def x3621thenb(): Unit = {
if (x608 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3617 = new Array[FixedPoint[Signed,B32,B0]](x608.toInt)
val x3618 = System.arraycopy(x606,0.toInt,x3617,0.toInt,x608.toInt)
val x3619 = x606 = x3617
x3619
}
if (x3616) {
x3621thenb()
}
}
val x3628 = x606
val x3629 = x3628.length
val x3633_zero: FixedPoint[Signed,B32,B0] = x197
var x3633: FixedPoint[Signed,B32,B0] = x3633_zero
var x650: Int = 0
if (x3629 > 0) { // prerun fat loop x3633
val x3630 = x3628(x650.toInt)
x3633 = x3630
}
x650 = 1
while (x650 < x3629) {  // begin fat loop x3633
val x3630 = x3628(x650.toInt)
val x654 = x3633
val x655 = x3630
val x656 = {
x654 + x655
}
x3633 = x656
x650 = x650 + 1
} // end fat loop x3633
val x659 = x3633
val x658 = x3670_data
val x3638 = x658(x499.toInt) = x659
x499 = x499 + 1
} // end fat loop x3670
val x658 = x3670_data
val x3670 = x658
val x702 = x3670
val x701 = __act.x3707_data
val x3675 = x701(x497.toInt) = x702
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3707,rhs:activation_x3707): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3707,lhs:activation_x3707): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3707): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3707): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3707): Unit = {
var x701: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x3707_data
__act.x3707_data = null
__act.x3707 = x701
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3707 = {
val act: activation_x3707 = new activation_x3707
act
}

}
x3707_closure.loopStart = 0
x3707_closure.loopSize = x314
val alloc: activation_x3707 = x3707_closure.alloc(resourceInfo)
var x3707: activation_x3707 = null
if (resourceInfo.availableThreads <= 1) {
x3707 = x3707_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3707] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3707](x3707_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3707_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3707 = x3707_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3707
}}

/**********/

