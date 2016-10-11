package generated.scala
//activation record for fat loop
final class activation_x4704 {
var left_act: activation_x4704 = _
var x4704: Array[FixedPoint[Signed,B32,B0]] = _
var x4704_data: Array[FixedPoint[Signed,B32,B0]] = _
var x4704_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x4704_size: Int = _
var x4704_offset: Int = _
var x4704_conditionals: Int = _
def x4704_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x4704_data = xs
x4704_conditionals = cs
if (left_act ne null)
left_act.x4704_data_set(resourceInfo,xs,cs)
}

}
object activation_x4704 {
}
object kernel_x4704 {
def apply(resourceInfo:generated.scala.ResourceInfo,x7:Int,x4666:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x4704 = {
val x4704_closure = new generated.scala.DeliteOpMultiLoop[activation_x4704] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x7
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x4704 = {
val __act: activation_x4704 = new activation_x4704()
// __act.x4704 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4704,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x4704]): activation_x4704 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x4704 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x4704 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x4704 = act
while (j < localEnd) {
val rhsAct: activation_x4704 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4704): activation_x4704 = {
val act: activation_x4704 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4704,start:Long,end:Long): activation_x4704 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x4704 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4704,x187:Int,isEmpty:Boolean): activation_x4704 = {
val __act2: activation_x4704 = new activation_x4704()
val x195 = 0
if (x195 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4667 = new Array[FixedPoint[Signed,B32,B0]](x195.toInt)
__act2.x4704_buf = x4667
if (!isEmpty) {
val x4703 = x4666(x187.toInt)
val x190 = x4703
val x191 = x190.length
var x189: Int = 0
while (x189 < x191) { //flatMap loop
val x192 = x190(x189.toInt)
val x193 = __act2.x4704_buf
val x194 = x192
if (true) {
val x4673 = __act2.x4704_size
val x4674 = x193.length
val x4675 = x4674 - 1
val x4676 = x4673 > x4675
val x4689 = {
def x4689thenb(): Unit = {
val x4677 = x4674 < 16
val x4681 = {
def x4681thenb(): Int = {
16
}
def x4681elseb(): Int = {
val x4678 = x4674 * 2
val x4679 = x4678 < 0
val x4680 = {
def x4680thenb(): Int = {
2147483647
}
def x4680elseb(): Int = {
x4678
}
if (x4679) {
x4680thenb()
} else { 
x4680elseb()
}
}
x4680
}
if (x4677) {
x4681thenb()
} else { 
x4681elseb()
}
}
if (x4681 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4682 = new Array[FixedPoint[Signed,B32,B0]](x4681.toInt)
val x4683 = System.arraycopy(x193,0.toInt,x4682,0.toInt,x4674.toInt)
val x4684 = x4682(x4673.toInt) = x194
val x4685 = __act2.x4704_buf = x4682
x4685
}
def x4689elseb(): Unit = {
val x4687 = x193(x4673.toInt) = x194
x4687
}
if (x4676) {
x4689thenb()
} else { 
x4689elseb()
}
}
__act2.x4704_size = __act2.x4704_size + 1
}
__act2.x4704_conditionals = __act2.x4704_conditionals + 1
x189 = x189 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4704,x187:Int): Unit = {
val x4703 = x4666(x187.toInt)
val x190 = x4703
val x191 = x190.length
var x189: Int = 0
while (x189 < x191) { //flatMap loop
val x192 = x190(x189.toInt)
val x193 = __act.x4704_buf
val x194 = x192
if (true) {
val x4673 = __act.x4704_size
val x4674 = x193.length
val x4675 = x4674 - 1
val x4676 = x4673 > x4675
val x4689 = {
def x4689thenb(): Unit = {
val x4677 = x4674 < 16
val x4681 = {
def x4681thenb(): Int = {
16
}
def x4681elseb(): Int = {
val x4678 = x4674 * 2
val x4679 = x4678 < 0
val x4680 = {
def x4680thenb(): Int = {
2147483647
}
def x4680elseb(): Int = {
x4678
}
if (x4679) {
x4680thenb()
} else { 
x4680elseb()
}
}
x4680
}
if (x4677) {
x4681thenb()
} else { 
x4681elseb()
}
}
if (x4681 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4682 = new Array[FixedPoint[Signed,B32,B0]](x4681.toInt)
val x4683 = System.arraycopy(x193,0.toInt,x4682,0.toInt,x4674.toInt)
val x4684 = x4682(x4673.toInt) = x194
val x4685 = __act.x4704_buf = x4682
x4685
}
def x4689elseb(): Unit = {
val x4687 = x193(x4673.toInt) = x194
x4687
}
if (x4676) {
x4689thenb()
} else { 
x4689elseb()
}
}
__act.x4704_size = __act.x4704_size + 1
}
__act.x4704_conditionals = __act.x4704_conditionals + 1
x189 = x189 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4704,rhs:activation_x4704): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4704,lhs:activation_x4704): Unit = {
__act.x4704_offset = lhs.x4704_offset+lhs.x4704_size
__act.x4704_conditionals = __act.x4704_conditionals+lhs.x4704_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4704): Unit = {
if (__act.x4704_offset > 0) {
val x195 = __act.x4704_offset + __act.x4704_size
val x193 = __act.x4704_buf
if (x195 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4699 = new Array[FixedPoint[Signed,B32,B0]](x195.toInt)
__act.x4704_data_set(resourceInfo,x4699,__act.x4704_conditionals)
} else {
__act.x4704_data_set(resourceInfo,__act.x4704_buf,__act.x4704_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4704): Unit = {
if (__act.x4704_data ne __act.x4704_buf) {
val x195 = __act.x4704_size
val x198 = __act.x4704_buf
val x193 = __act.x4704_data
val x196 = 0
val x197 = __act.x4704_offset
val x4701 = System.arraycopy(x198,x196.toInt,x193,x197.toInt,x195.toInt)
}
__act.x4704_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4704): Unit = {
var x193: Array[FixedPoint[Signed,B32,B0]] = __act.x4704_data
__act.x4704_data = null
val x195 = __act.x4704_conditionals
val x4691 = x193.length
val x4692 = x4691 > x195
val x4697 = {
def x4697thenb(): Unit = {
if (x195 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4693 = new Array[FixedPoint[Signed,B32,B0]](x195.toInt)
val x4694 = System.arraycopy(x193,0.toInt,x4693,0.toInt,x195.toInt)
val x4695 = x193 = x4693
x4695
}
if (x4692) {
x4697thenb()
}
}
__act.x4704 = x193
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x4704 = {
val act: activation_x4704 = new activation_x4704
act
}

}
x4704_closure.loopStart = 0
x4704_closure.loopSize = x7
val alloc: activation_x4704 = x4704_closure.alloc(resourceInfo)
var x4704: activation_x4704 = null
if (resourceInfo.availableThreads <= 1) {
x4704 = x4704_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x4704] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x4704](x4704_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x4704_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x4704 = x4704_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x4704
}}

/**********/

