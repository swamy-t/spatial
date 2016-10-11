package generated.scala
//activation record for fat loop
final class activation_x2941 {
var left_act: activation_x2941 = _
var x2941: Array[FixedPoint[Signed,B32,B0]] = _
var x2941_data: Array[FixedPoint[Signed,B32,B0]] = _
var x2941_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x2941_size: Int = _
var x2941_offset: Int = _
var x2941_conditionals: Int = _
def x2941_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x2941_data = xs
x2941_conditionals = cs
if (left_act ne null)
left_act.x2941_data_set(resourceInfo,xs,cs)
}

}
object activation_x2941 {
}
object kernel_x2941 {
def apply(resourceInfo:generated.scala.ResourceInfo,x5:Int,x2903:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x2941 = {
val x2941_closure = new generated.scala.DeliteOpMultiLoop[activation_x2941] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x5
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x2941 = {
val __act: activation_x2941 = new activation_x2941()
// __act.x2941 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2941,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x2941]): activation_x2941 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x2941 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x2941 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x2941 = act
while (j < localEnd) {
val rhsAct: activation_x2941 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2941): activation_x2941 = {
val act: activation_x2941 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2941,start:Long,end:Long): activation_x2941 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x2941 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2941,x306:Int,isEmpty:Boolean): activation_x2941 = {
val __act2: activation_x2941 = new activation_x2941()
val x314 = 0
if (x314 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2904 = new Array[FixedPoint[Signed,B32,B0]](x314.toInt)
__act2.x2941_buf = x2904
if (!isEmpty) {
val x2940 = x2903(x306.toInt)
val x309 = x2940
val x310 = x309.length
var x308: Int = 0
while (x308 < x310) { //flatMap loop
val x311 = x309(x308.toInt)
val x312 = __act2.x2941_buf
val x313 = x311
if (true) {
val x2910 = __act2.x2941_size
val x2911 = x312.length
val x2912 = x2911 - 1
val x2913 = x2910 > x2912
val x2926 = {
def x2926thenb(): Unit = {
val x2914 = x2911 < 16
val x2918 = {
def x2918thenb(): Int = {
16
}
def x2918elseb(): Int = {
val x2915 = x2911 * 2
val x2916 = x2915 < 0
val x2917 = {
def x2917thenb(): Int = {
2147483647
}
def x2917elseb(): Int = {
x2915
}
if (x2916) {
x2917thenb()
} else { 
x2917elseb()
}
}
x2917
}
if (x2914) {
x2918thenb()
} else { 
x2918elseb()
}
}
if (x2918 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2919 = new Array[FixedPoint[Signed,B32,B0]](x2918.toInt)
val x2920 = System.arraycopy(x312,0.toInt,x2919,0.toInt,x2911.toInt)
val x2921 = x2919(x2910.toInt) = x313
val x2922 = __act2.x2941_buf = x2919
x2922
}
def x2926elseb(): Unit = {
val x2924 = x312(x2910.toInt) = x313
x2924
}
if (x2913) {
x2926thenb()
} else { 
x2926elseb()
}
}
__act2.x2941_size = __act2.x2941_size + 1
}
__act2.x2941_conditionals = __act2.x2941_conditionals + 1
x308 = x308 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2941,x306:Int): Unit = {
val x2940 = x2903(x306.toInt)
val x309 = x2940
val x310 = x309.length
var x308: Int = 0
while (x308 < x310) { //flatMap loop
val x311 = x309(x308.toInt)
val x312 = __act.x2941_buf
val x313 = x311
if (true) {
val x2910 = __act.x2941_size
val x2911 = x312.length
val x2912 = x2911 - 1
val x2913 = x2910 > x2912
val x2926 = {
def x2926thenb(): Unit = {
val x2914 = x2911 < 16
val x2918 = {
def x2918thenb(): Int = {
16
}
def x2918elseb(): Int = {
val x2915 = x2911 * 2
val x2916 = x2915 < 0
val x2917 = {
def x2917thenb(): Int = {
2147483647
}
def x2917elseb(): Int = {
x2915
}
if (x2916) {
x2917thenb()
} else { 
x2917elseb()
}
}
x2917
}
if (x2914) {
x2918thenb()
} else { 
x2918elseb()
}
}
if (x2918 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2919 = new Array[FixedPoint[Signed,B32,B0]](x2918.toInt)
val x2920 = System.arraycopy(x312,0.toInt,x2919,0.toInt,x2911.toInt)
val x2921 = x2919(x2910.toInt) = x313
val x2922 = __act.x2941_buf = x2919
x2922
}
def x2926elseb(): Unit = {
val x2924 = x312(x2910.toInt) = x313
x2924
}
if (x2913) {
x2926thenb()
} else { 
x2926elseb()
}
}
__act.x2941_size = __act.x2941_size + 1
}
__act.x2941_conditionals = __act.x2941_conditionals + 1
x308 = x308 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2941,rhs:activation_x2941): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2941,lhs:activation_x2941): Unit = {
__act.x2941_offset = lhs.x2941_offset+lhs.x2941_size
__act.x2941_conditionals = __act.x2941_conditionals+lhs.x2941_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2941): Unit = {
if (__act.x2941_offset > 0) {
val x314 = __act.x2941_offset + __act.x2941_size
val x312 = __act.x2941_buf
if (x314 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2936 = new Array[FixedPoint[Signed,B32,B0]](x314.toInt)
__act.x2941_data_set(resourceInfo,x2936,__act.x2941_conditionals)
} else {
__act.x2941_data_set(resourceInfo,__act.x2941_buf,__act.x2941_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2941): Unit = {
if (__act.x2941_data ne __act.x2941_buf) {
val x314 = __act.x2941_size
val x317 = __act.x2941_buf
val x312 = __act.x2941_data
val x315 = 0
val x316 = __act.x2941_offset
val x2938 = System.arraycopy(x317,x315.toInt,x312,x316.toInt,x314.toInt)
}
__act.x2941_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x2941): Unit = {
var x312: Array[FixedPoint[Signed,B32,B0]] = __act.x2941_data
__act.x2941_data = null
val x314 = __act.x2941_conditionals
val x2928 = x312.length
val x2929 = x2928 > x314
val x2934 = {
def x2934thenb(): Unit = {
if (x314 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2930 = new Array[FixedPoint[Signed,B32,B0]](x314.toInt)
val x2931 = System.arraycopy(x312,0.toInt,x2930,0.toInt,x314.toInt)
val x2932 = x312 = x2930
x2932
}
if (x2929) {
x2934thenb()
}
}
__act.x2941 = x312
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x2941 = {
val act: activation_x2941 = new activation_x2941
act
}

}
x2941_closure.loopStart = 0
x2941_closure.loopSize = x5
val alloc: activation_x2941 = x2941_closure.alloc(resourceInfo)
var x2941: activation_x2941 = null
if (resourceInfo.availableThreads <= 1) {
x2941 = x2941_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x2941] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x2941](x2941_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x2941_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x2941 = x2941_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x2941
}}

/**********/

