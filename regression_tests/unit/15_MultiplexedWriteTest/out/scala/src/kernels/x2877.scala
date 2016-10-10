package generated.scala
//activation record for fat loop
final class activation_x2877 {
var left_act: activation_x2877 = _
var x2877: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x2877_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x2877 {
}
object kernel_x2877 {
def apply(resourceInfo:generated.scala.ResourceInfo,x183:Int,x116:FixedPoint[Signed,B32,B0],x50:FixedPoint[Signed,B32,B0],x189:FixedPoint[Signed,B32,B0],x190:Int,x186:Int): activation_x2877 = {
val x2877_closure = new generated.scala.DeliteOpMultiLoop[activation_x2877] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x183
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2877 = {
val __act: activation_x2877 = new activation_x2877()
val x340 = (loopSize).asInstanceOf[Int]
if (x340 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2725 = new Array[Array[FixedPoint[Signed,B32,B0]]](x340.toInt)
__act.x2877_data = x2725
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2877,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2877]): activation_x2877 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2877 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2877 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2877): activation_x2877 = {
val act: activation_x2877 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2877,start:Long,end:Long): activation_x2877 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2877 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2877,x184:Int,isEmpty:Boolean): activation_x2877 = {
if (!isEmpty) {
process(resourceInfo,__act,x184)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2877,x184:Int): Unit = {
val x185 = {
FixedPoint[Signed,B32,B0](x184)
}
val x197 = {
x185 * x189
}
var x248: Int = x186
if (x248 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2650 = new Array[Array[FixedPoint[Signed,B32,B0]]](x248.toInt)
val x2686_data: Array[Array[FixedPoint[Signed,B32,B0]]] = x2650
var x2686_size: Int = 0
var x2686_conditionals: Int = 0
var x187: Int = 0
while (x187 < x186) {  // begin fat loop x2686
val x188 = {
FixedPoint[Signed,B32,B0](x187)
}
val x193 = {
x188 + x116
}
val x199 = {
x193 * x185
}
val x200 = {
x199 * x189
}
val x201 = {
x200 * x50
}
var x205: Int = x190
if (x205 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2613 = new Array[FixedPoint[Signed,B32,B0]](x205.toInt)
val x2649_data: Array[FixedPoint[Signed,B32,B0]] = x2613
var x2649_size: Int = 0
var x2649_conditionals: Int = 0
var x191: Int = 0
while (x191 < x190) {  // begin fat loop x2649
val x192 = {
FixedPoint[Signed,B32,B0](x191)
}
val x194 = {
x193 * x192
}
val x195 = {
x194 * x50
}
val x196 = {
x192 + x195
}
val x198 = {
x196 + x197
}
val x202 = {
x198 + x201
}
val x204 = x202
val x203 = x2649_data
val x2617 = x203(x191.toInt) = x204
x191 = x191 + 1
} // end fat loop x2649
val x203 = x2649_data
val x2649 = x203
val x247 = x2649
val x246 = x2686_data
val x2654 = x246(x187.toInt) = x247
x187 = x187 + 1
} // end fat loop x2686
val x246 = x2686_data
val x2686 = x246
var x297: Int = 0
if (x297 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2687 = new Array[FixedPoint[Signed,B32,B0]](x297.toInt)
var x2724_buf: Array[FixedPoint[Signed,B32,B0]] = x2687
var x2724_size: Int = 0
var x2724_conditionals: Int = 0
var x289: Int = 0
while (x289 < x186) {  // begin fat loop x2724
val x2723 = x2686(x289.toInt)
val x292 = x2723
val x293 = x292.length
var x291: Int = 0
while (x291 < x293) { //flatMap loop
val x294 = x292(x291.toInt)
val x295 = x2724_buf
val x296 = x294
if (true) {
val x2693 = x2724_size
val x2694 = x295.length
val x2695 = x2694 - 1
val x2696 = x2693 > x2695
val x2709 = {
def x2709thenb(): Unit = {
val x2697 = x2694 < 16
val x2701 = {
def x2701thenb(): Int = {
16
}
def x2701elseb(): Int = {
val x2698 = x2694 * 2
val x2699 = x2698 < 0
val x2700 = {
def x2700thenb(): Int = {
2147483647
}
def x2700elseb(): Int = {
x2698
}
if (x2699) {
x2700thenb()
} else { 
x2700elseb()
}
}
x2700
}
if (x2697) {
x2701thenb()
} else { 
x2701elseb()
}
}
if (x2701 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2702 = new Array[FixedPoint[Signed,B32,B0]](x2701.toInt)
val x2703 = System.arraycopy(x295,0.toInt,x2702,0.toInt,x2694.toInt)
val x2704 = x2702(x2693.toInt) = x296
val x2705 = x2724_buf = x2702
x2705
}
def x2709elseb(): Unit = {
val x2707 = x295(x2693.toInt) = x296
x2707
}
if (x2696) {
x2709thenb()
} else { 
x2709elseb()
}
}
x2724_size = x2724_size + 1
}
x2724_conditionals = x2724_conditionals + 1
x291 = x291 + 1
}
x289 = x289 + 1
} // end fat loop x2724
var x295: Array[FixedPoint[Signed,B32,B0]] = x2724_buf
x297 = x2724_conditionals
val x2711 = x295.length
val x2712 = x2711 > x297
val x2717 = {
def x2717thenb(): Unit = {
if (x297 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2713 = new Array[FixedPoint[Signed,B32,B0]](x297.toInt)
val x2714 = System.arraycopy(x295,0.toInt,x2713,0.toInt,x297.toInt)
val x2715 = x295 = x2713
x2715
}
if (x2712) {
x2717thenb()
}
}
val x2724 = x295
val x339 = x2724
val x338 = __act.x2877_data
val x2729 = x338(x184.toInt) = x339
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2877,rhs:activation_x2877): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2877,lhs:activation_x2877): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2877): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2877): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2877): Unit = {
var x338: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x2877_data
__act.x2877_data = null
__act.x2877 = x338
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2877 = {
val act: activation_x2877 = new activation_x2877
act
}

}
x2877_closure.loopStart = 0
x2877_closure.loopSize = x183
val alloc: activation_x2877 = x2877_closure.alloc(resourceInfo)
var x2877: activation_x2877 = null
if (resourceInfo.availableThreads <= 1) {
x2877 = x2877_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2877] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2877](x2877_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2877_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2877 = x2877_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2877
}}

/**********/

