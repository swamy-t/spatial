package generated.scala
//activation record for fat loop
final class activation_x3745 {
var left_act: activation_x3745 = _
var x3745: Array[FixedPoint[Signed,B32,B0]] = _
var x3745_data: Array[FixedPoint[Signed,B32,B0]] = _
var x3745_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x3745_size: Int = _
var x3745_offset: Int = _
var x3745_conditionals: Int = _
def x3745_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x3745_data = xs
x3745_conditionals = cs
if (left_act ne null)
left_act.x3745_data_set(resourceInfo,xs,cs)
}

}
object activation_x3745 {
}
object kernel_x3745 {
def apply(resourceInfo:generated.scala.ResourceInfo,x314:Int,x3707:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x3745 = {
val x3745_closure = new generated.scala.DeliteOpMultiLoop[activation_x3745] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x314
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3745 = {
val __act: activation_x3745 = new activation_x3745()
// __act.x3745 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3745,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3745]): activation_x3745 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3745 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3745 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x3745 = act
while (j < localEnd) {
val rhsAct: activation_x3745 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3745): activation_x3745 = {
val act: activation_x3745 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3745,start:Long,end:Long): activation_x3745 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3745 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3745,x744:Int,isEmpty:Boolean): activation_x3745 = {
val __act2: activation_x3745 = new activation_x3745()
val x752 = 0
if (x752 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3708 = new Array[FixedPoint[Signed,B32,B0]](x752.toInt)
__act2.x3745_buf = x3708
if (!isEmpty) {
val x3744 = x3707(x744.toInt)
val x747 = x3744
val x748 = x747.length
var x746: Int = 0
while (x746 < x748) { //flatMap loop
val x749 = x747(x746.toInt)
val x750 = __act2.x3745_buf
val x751 = x749
if (true) {
val x3714 = __act2.x3745_size
val x3715 = x750.length
val x3716 = x3715 - 1
val x3717 = x3714 > x3716
val x3730 = {
def x3730thenb(): Unit = {
val x3718 = x3715 < 16
val x3722 = {
def x3722thenb(): Int = {
16
}
def x3722elseb(): Int = {
val x3719 = x3715 * 2
val x3720 = x3719 < 0
val x3721 = {
def x3721thenb(): Int = {
2147483647
}
def x3721elseb(): Int = {
x3719
}
if (x3720) {
x3721thenb()
} else { 
x3721elseb()
}
}
x3721
}
if (x3718) {
x3722thenb()
} else { 
x3722elseb()
}
}
if (x3722 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3723 = new Array[FixedPoint[Signed,B32,B0]](x3722.toInt)
val x3724 = System.arraycopy(x750,0.toInt,x3723,0.toInt,x3715.toInt)
val x3725 = x3723(x3714.toInt) = x751
val x3726 = __act2.x3745_buf = x3723
x3726
}
def x3730elseb(): Unit = {
val x3728 = x750(x3714.toInt) = x751
x3728
}
if (x3717) {
x3730thenb()
} else { 
x3730elseb()
}
}
__act2.x3745_size = __act2.x3745_size + 1
}
__act2.x3745_conditionals = __act2.x3745_conditionals + 1
x746 = x746 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3745,x744:Int): Unit = {
val x3744 = x3707(x744.toInt)
val x747 = x3744
val x748 = x747.length
var x746: Int = 0
while (x746 < x748) { //flatMap loop
val x749 = x747(x746.toInt)
val x750 = __act.x3745_buf
val x751 = x749
if (true) {
val x3714 = __act.x3745_size
val x3715 = x750.length
val x3716 = x3715 - 1
val x3717 = x3714 > x3716
val x3730 = {
def x3730thenb(): Unit = {
val x3718 = x3715 < 16
val x3722 = {
def x3722thenb(): Int = {
16
}
def x3722elseb(): Int = {
val x3719 = x3715 * 2
val x3720 = x3719 < 0
val x3721 = {
def x3721thenb(): Int = {
2147483647
}
def x3721elseb(): Int = {
x3719
}
if (x3720) {
x3721thenb()
} else { 
x3721elseb()
}
}
x3721
}
if (x3718) {
x3722thenb()
} else { 
x3722elseb()
}
}
if (x3722 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3723 = new Array[FixedPoint[Signed,B32,B0]](x3722.toInt)
val x3724 = System.arraycopy(x750,0.toInt,x3723,0.toInt,x3715.toInt)
val x3725 = x3723(x3714.toInt) = x751
val x3726 = __act.x3745_buf = x3723
x3726
}
def x3730elseb(): Unit = {
val x3728 = x750(x3714.toInt) = x751
x3728
}
if (x3717) {
x3730thenb()
} else { 
x3730elseb()
}
}
__act.x3745_size = __act.x3745_size + 1
}
__act.x3745_conditionals = __act.x3745_conditionals + 1
x746 = x746 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3745,rhs:activation_x3745): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3745,lhs:activation_x3745): Unit = {
__act.x3745_offset = lhs.x3745_offset+lhs.x3745_size
__act.x3745_conditionals = __act.x3745_conditionals+lhs.x3745_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3745): Unit = {
if (__act.x3745_offset > 0) {
val x752 = __act.x3745_offset + __act.x3745_size
val x750 = __act.x3745_buf
if (x752 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3740 = new Array[FixedPoint[Signed,B32,B0]](x752.toInt)
__act.x3745_data_set(resourceInfo,x3740,__act.x3745_conditionals)
} else {
__act.x3745_data_set(resourceInfo,__act.x3745_buf,__act.x3745_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3745): Unit = {
if (__act.x3745_data ne __act.x3745_buf) {
val x752 = __act.x3745_size
val x755 = __act.x3745_buf
val x750 = __act.x3745_data
val x753 = 0
val x754 = __act.x3745_offset
val x3742 = System.arraycopy(x755,x753.toInt,x750,x754.toInt,x752.toInt)
}
__act.x3745_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3745): Unit = {
var x750: Array[FixedPoint[Signed,B32,B0]] = __act.x3745_data
__act.x3745_data = null
val x752 = __act.x3745_conditionals
val x3732 = x750.length
val x3733 = x3732 > x752
val x3738 = {
def x3738thenb(): Unit = {
if (x752 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3734 = new Array[FixedPoint[Signed,B32,B0]](x752.toInt)
val x3735 = System.arraycopy(x750,0.toInt,x3734,0.toInt,x752.toInt)
val x3736 = x750 = x3734
x3736
}
if (x3733) {
x3738thenb()
}
}
__act.x3745 = x750
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3745 = {
val act: activation_x3745 = new activation_x3745
act
}

}
x3745_closure.loopStart = 0
x3745_closure.loopSize = x314
val alloc: activation_x3745 = x3745_closure.alloc(resourceInfo)
var x3745: activation_x3745 = null
if (resourceInfo.availableThreads <= 1) {
x3745 = x3745_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3745] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3745](x3745_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3745_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3745 = x3745_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3745
}}

/**********/

