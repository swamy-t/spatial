package generated.scala
//activation record for fat loop
final class activation_x2879 {
var left_act: activation_x2879 = _
var x2879: Array[FixedPoint[Signed,B32,B0]] = _
var x2879_data: Array[FixedPoint[Signed,B32,B0]] = _
var x2879_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x2879_size: Int = _
var x2879_offset: Int = _
var x2879_conditionals: Int = _
def x2879_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x2879_data = xs
x2879_conditionals = cs
if (left_act ne null)
left_act.x2879_data_set(resourceInfo,xs,cs)
}

}
object activation_x2879 {
}
object kernel_x2879 {
def apply(resourceInfo:generated.scala.ResourceInfo,x183:Int,x2877:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x2879 = {
val x2879_closure = new generated.scala.DeliteOpMultiLoop[activation_x2879] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x183
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2879 = {
val __act: activation_x2879 = new activation_x2879()
// __act.x2879 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2879,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2879]): activation_x2879 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2879 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2879 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x2879 = act
while (j < localEnd) {
val rhsAct: activation_x2879 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2879): activation_x2879 = {
val act: activation_x2879 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2879,start:Long,end:Long): activation_x2879 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2879 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2879,x381:Int,isEmpty:Boolean): activation_x2879 = {
val __act2: activation_x2879 = new activation_x2879()
val x389 = 0
if (x389 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2762 = new Array[FixedPoint[Signed,B32,B0]](x389.toInt)
__act2.x2879_buf = x2762
if (!isEmpty) {
val x2878 = x2877(x381.toInt)
val x384 = x2878
val x385 = x384.length
var x383: Int = 0
while (x383 < x385) { //flatMap loop
val x386 = x384(x383.toInt)
val x387 = __act2.x2879_buf
val x388 = x386
if (true) {
val x2768 = __act2.x2879_size
val x2769 = x387.length
val x2770 = x2769 - 1
val x2771 = x2768 > x2770
val x2784 = {
def x2784thenb(): Unit = {
val x2772 = x2769 < 16
val x2776 = {
def x2776thenb(): Int = {
16
}
def x2776elseb(): Int = {
val x2773 = x2769 * 2
val x2774 = x2773 < 0
val x2775 = {
def x2775thenb(): Int = {
2147483647
}
def x2775elseb(): Int = {
x2773
}
if (x2774) {
x2775thenb()
} else { 
x2775elseb()
}
}
x2775
}
if (x2772) {
x2776thenb()
} else { 
x2776elseb()
}
}
if (x2776 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2777 = new Array[FixedPoint[Signed,B32,B0]](x2776.toInt)
val x2778 = System.arraycopy(x387,0.toInt,x2777,0.toInt,x2769.toInt)
val x2779 = x2777(x2768.toInt) = x388
val x2780 = __act2.x2879_buf = x2777
x2780
}
def x2784elseb(): Unit = {
val x2782 = x387(x2768.toInt) = x388
x2782
}
if (x2771) {
x2784thenb()
} else { 
x2784elseb()
}
}
__act2.x2879_size = __act2.x2879_size + 1
}
__act2.x2879_conditionals = __act2.x2879_conditionals + 1
x383 = x383 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2879,x381:Int): Unit = {
val x2878 = x2877(x381.toInt)
val x384 = x2878
val x385 = x384.length
var x383: Int = 0
while (x383 < x385) { //flatMap loop
val x386 = x384(x383.toInt)
val x387 = __act.x2879_buf
val x388 = x386
if (true) {
val x2768 = __act.x2879_size
val x2769 = x387.length
val x2770 = x2769 - 1
val x2771 = x2768 > x2770
val x2784 = {
def x2784thenb(): Unit = {
val x2772 = x2769 < 16
val x2776 = {
def x2776thenb(): Int = {
16
}
def x2776elseb(): Int = {
val x2773 = x2769 * 2
val x2774 = x2773 < 0
val x2775 = {
def x2775thenb(): Int = {
2147483647
}
def x2775elseb(): Int = {
x2773
}
if (x2774) {
x2775thenb()
} else { 
x2775elseb()
}
}
x2775
}
if (x2772) {
x2776thenb()
} else { 
x2776elseb()
}
}
if (x2776 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2777 = new Array[FixedPoint[Signed,B32,B0]](x2776.toInt)
val x2778 = System.arraycopy(x387,0.toInt,x2777,0.toInt,x2769.toInt)
val x2779 = x2777(x2768.toInt) = x388
val x2780 = __act.x2879_buf = x2777
x2780
}
def x2784elseb(): Unit = {
val x2782 = x387(x2768.toInt) = x388
x2782
}
if (x2771) {
x2784thenb()
} else { 
x2784elseb()
}
}
__act.x2879_size = __act.x2879_size + 1
}
__act.x2879_conditionals = __act.x2879_conditionals + 1
x383 = x383 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2879,rhs:activation_x2879): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2879,lhs:activation_x2879): Unit = {
__act.x2879_offset = lhs.x2879_offset+lhs.x2879_size
__act.x2879_conditionals = __act.x2879_conditionals+lhs.x2879_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2879): Unit = {
if (__act.x2879_offset > 0) {
val x389 = __act.x2879_offset + __act.x2879_size
val x387 = __act.x2879_buf
if (x389 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2794 = new Array[FixedPoint[Signed,B32,B0]](x389.toInt)
__act.x2879_data_set(resourceInfo,x2794,__act.x2879_conditionals)
} else {
__act.x2879_data_set(resourceInfo,__act.x2879_buf,__act.x2879_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2879): Unit = {
if (__act.x2879_data ne __act.x2879_buf) {
val x389 = __act.x2879_size
val x392 = __act.x2879_buf
val x387 = __act.x2879_data
val x390 = 0
val x391 = __act.x2879_offset
val x2796 = System.arraycopy(x392,x390.toInt,x387,x391.toInt,x389.toInt)
}
__act.x2879_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2879): Unit = {
var x387: Array[FixedPoint[Signed,B32,B0]] = __act.x2879_data
__act.x2879_data = null
val x389 = __act.x2879_conditionals
val x2786 = x387.length
val x2787 = x2786 > x389
val x2792 = {
def x2792thenb(): Unit = {
if (x389 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2788 = new Array[FixedPoint[Signed,B32,B0]](x389.toInt)
val x2789 = System.arraycopy(x387,0.toInt,x2788,0.toInt,x389.toInt)
val x2790 = x387 = x2788
x2790
}
if (x2787) {
x2792thenb()
}
}
__act.x2879 = x387
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2879 = {
val act: activation_x2879 = new activation_x2879
act
}

}
x2879_closure.loopStart = 0
x2879_closure.loopSize = x183
val alloc: activation_x2879 = x2879_closure.alloc(resourceInfo)
var x2879: activation_x2879 = null
if (resourceInfo.availableThreads <= 1) {
x2879 = x2879_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2879] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2879](x2879_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2879_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2879 = x2879_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2879
}}

/**********/

