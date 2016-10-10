package generated.scala
//activation record for fat loop
final class activation_x5382 {
var left_act: activation_x5382 = _
var x5382: Array[FixedPoint[Signed,B32,B0]] = _
var x5382_data: Array[FixedPoint[Signed,B32,B0]] = _
var x5382_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x5382_size: Int = _
var x5382_offset: Int = _
var x5382_conditionals: Int = _
def x5382_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x5382_data = xs
x5382_conditionals = cs
if (left_act ne null)
left_act.x5382_data_set(resourceInfo,xs,cs)
}

}
object activation_x5382 {
}
object kernel_x5382 {
def apply(resourceInfo:generated.scala.ResourceInfo,x9:Int,x5380:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x5382 = {
val x5382_closure = new generated.scala.DeliteOpMultiLoop[activation_x5382] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x9
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5382 = {
val __act: activation_x5382 = new activation_x5382()
// __act.x5382 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5382,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5382]): activation_x5382 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5382 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5382 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x5382 = act
while (j < localEnd) {
val rhsAct: activation_x5382 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5382): activation_x5382 = {
val act: activation_x5382 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5382,start:Long,end:Long): activation_x5382 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5382 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5382,x236:Int,isEmpty:Boolean): activation_x5382 = {
val __act2: activation_x5382 = new activation_x5382()
val x244 = 0
if (x244 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4780 = new Array[FixedPoint[Signed,B32,B0]](x244.toInt)
__act2.x5382_buf = x4780
if (!isEmpty) {
val x5381 = x5380(x236.toInt)
val x239 = x5381
val x240 = x239.length
var x238: Int = 0
while (x238 < x240) { //flatMap loop
val x241 = x239(x238.toInt)
val x242 = __act2.x5382_buf
val x243 = x241
if (true) {
val x4786 = __act2.x5382_size
val x4787 = x242.length
val x4788 = x4787 - 1
val x4789 = x4786 > x4788
val x4802 = {
def x4802thenb(): Unit = {
val x4790 = x4787 < 16
val x4794 = {
def x4794thenb(): Int = {
16
}
def x4794elseb(): Int = {
val x4791 = x4787 * 2
val x4792 = x4791 < 0
val x4793 = {
def x4793thenb(): Int = {
2147483647
}
def x4793elseb(): Int = {
x4791
}
if (x4792) {
x4793thenb()
} else { 
x4793elseb()
}
}
x4793
}
if (x4790) {
x4794thenb()
} else { 
x4794elseb()
}
}
if (x4794 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4795 = new Array[FixedPoint[Signed,B32,B0]](x4794.toInt)
val x4796 = System.arraycopy(x242,0.toInt,x4795,0.toInt,x4787.toInt)
val x4797 = x4795(x4786.toInt) = x243
val x4798 = __act2.x5382_buf = x4795
x4798
}
def x4802elseb(): Unit = {
val x4800 = x242(x4786.toInt) = x243
x4800
}
if (x4789) {
x4802thenb()
} else { 
x4802elseb()
}
}
__act2.x5382_size = __act2.x5382_size + 1
}
__act2.x5382_conditionals = __act2.x5382_conditionals + 1
x238 = x238 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5382,x236:Int): Unit = {
val x5381 = x5380(x236.toInt)
val x239 = x5381
val x240 = x239.length
var x238: Int = 0
while (x238 < x240) { //flatMap loop
val x241 = x239(x238.toInt)
val x242 = __act.x5382_buf
val x243 = x241
if (true) {
val x4786 = __act.x5382_size
val x4787 = x242.length
val x4788 = x4787 - 1
val x4789 = x4786 > x4788
val x4802 = {
def x4802thenb(): Unit = {
val x4790 = x4787 < 16
val x4794 = {
def x4794thenb(): Int = {
16
}
def x4794elseb(): Int = {
val x4791 = x4787 * 2
val x4792 = x4791 < 0
val x4793 = {
def x4793thenb(): Int = {
2147483647
}
def x4793elseb(): Int = {
x4791
}
if (x4792) {
x4793thenb()
} else { 
x4793elseb()
}
}
x4793
}
if (x4790) {
x4794thenb()
} else { 
x4794elseb()
}
}
if (x4794 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4795 = new Array[FixedPoint[Signed,B32,B0]](x4794.toInt)
val x4796 = System.arraycopy(x242,0.toInt,x4795,0.toInt,x4787.toInt)
val x4797 = x4795(x4786.toInt) = x243
val x4798 = __act.x5382_buf = x4795
x4798
}
def x4802elseb(): Unit = {
val x4800 = x242(x4786.toInt) = x243
x4800
}
if (x4789) {
x4802thenb()
} else { 
x4802elseb()
}
}
__act.x5382_size = __act.x5382_size + 1
}
__act.x5382_conditionals = __act.x5382_conditionals + 1
x238 = x238 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5382,rhs:activation_x5382): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5382,lhs:activation_x5382): Unit = {
__act.x5382_offset = lhs.x5382_offset+lhs.x5382_size
__act.x5382_conditionals = __act.x5382_conditionals+lhs.x5382_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5382): Unit = {
if (__act.x5382_offset > 0) {
val x244 = __act.x5382_offset + __act.x5382_size
val x242 = __act.x5382_buf
if (x244 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4812 = new Array[FixedPoint[Signed,B32,B0]](x244.toInt)
__act.x5382_data_set(resourceInfo,x4812,__act.x5382_conditionals)
} else {
__act.x5382_data_set(resourceInfo,__act.x5382_buf,__act.x5382_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5382): Unit = {
if (__act.x5382_data ne __act.x5382_buf) {
val x244 = __act.x5382_size
val x247 = __act.x5382_buf
val x242 = __act.x5382_data
val x245 = 0
val x246 = __act.x5382_offset
val x4814 = System.arraycopy(x247,x245.toInt,x242,x246.toInt,x244.toInt)
}
__act.x5382_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5382): Unit = {
var x242: Array[FixedPoint[Signed,B32,B0]] = __act.x5382_data
__act.x5382_data = null
val x244 = __act.x5382_conditionals
val x4804 = x242.length
val x4805 = x4804 > x244
val x4810 = {
def x4810thenb(): Unit = {
if (x244 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4806 = new Array[FixedPoint[Signed,B32,B0]](x244.toInt)
val x4807 = System.arraycopy(x242,0.toInt,x4806,0.toInt,x244.toInt)
val x4808 = x242 = x4806
x4808
}
if (x4805) {
x4810thenb()
}
}
__act.x5382 = x242
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5382 = {
val act: activation_x5382 = new activation_x5382
act
}

}
x5382_closure.loopStart = 0
x5382_closure.loopSize = x9
val alloc: activation_x5382 = x5382_closure.alloc(resourceInfo)
var x5382: activation_x5382 = null
if (resourceInfo.availableThreads <= 1) {
x5382 = x5382_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5382] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5382](x5382_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5382_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5382 = x5382_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5382
}}

/**********/

