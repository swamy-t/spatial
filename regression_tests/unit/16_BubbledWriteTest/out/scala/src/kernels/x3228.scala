package generated.scala
//activation record for fat loop
final class activation_x3228 {
var left_act: activation_x3228 = _
var x3228: Array[FixedPoint[Signed,B32,B0]] = _
var x3228_data: Array[FixedPoint[Signed,B32,B0]] = _
var x3228_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x3228_size: Int = _
var x3228_offset: Int = _
var x3228_conditionals: Int = _
def x3228_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x3228_data = xs
x3228_conditionals = cs
if (left_act ne null)
left_act.x3228_data_set(resourceInfo,xs,cs)
}

}
object activation_x3228 {
}
object kernel_x3228 {
def apply(resourceInfo:generated.scala.ResourceInfo,x240:Int,x3226:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x3228 = {
val x3228_closure = new generated.scala.DeliteOpMultiLoop[activation_x3228] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x240
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3228 = {
val __act: activation_x3228 = new activation_x3228()
// __act.x3228 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3228,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3228]): activation_x3228 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3228 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3228 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x3228 = act
while (j < localEnd) {
val rhsAct: activation_x3228 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3228): activation_x3228 = {
val act: activation_x3228 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3228,start:Long,end:Long): activation_x3228 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3228 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3228,x438:Int,isEmpty:Boolean): activation_x3228 = {
val __act2: activation_x3228 = new activation_x3228()
val x446 = 0
if (x446 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3111 = new Array[FixedPoint[Signed,B32,B0]](x446.toInt)
__act2.x3228_buf = x3111
if (!isEmpty) {
val x3227 = x3226(x438.toInt)
val x441 = x3227
val x442 = x441.length
var x440: Int = 0
while (x440 < x442) { //flatMap loop
val x443 = x441(x440.toInt)
val x444 = __act2.x3228_buf
val x445 = x443
if (true) {
val x3117 = __act2.x3228_size
val x3118 = x444.length
val x3119 = x3118 - 1
val x3120 = x3117 > x3119
val x3133 = {
def x3133thenb(): Unit = {
val x3121 = x3118 < 16
val x3125 = {
def x3125thenb(): Int = {
16
}
def x3125elseb(): Int = {
val x3122 = x3118 * 2
val x3123 = x3122 < 0
val x3124 = {
def x3124thenb(): Int = {
2147483647
}
def x3124elseb(): Int = {
x3122
}
if (x3123) {
x3124thenb()
} else { 
x3124elseb()
}
}
x3124
}
if (x3121) {
x3125thenb()
} else { 
x3125elseb()
}
}
if (x3125 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3126 = new Array[FixedPoint[Signed,B32,B0]](x3125.toInt)
val x3127 = System.arraycopy(x444,0.toInt,x3126,0.toInt,x3118.toInt)
val x3128 = x3126(x3117.toInt) = x445
val x3129 = __act2.x3228_buf = x3126
x3129
}
def x3133elseb(): Unit = {
val x3131 = x444(x3117.toInt) = x445
x3131
}
if (x3120) {
x3133thenb()
} else { 
x3133elseb()
}
}
__act2.x3228_size = __act2.x3228_size + 1
}
__act2.x3228_conditionals = __act2.x3228_conditionals + 1
x440 = x440 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3228,x438:Int): Unit = {
val x3227 = x3226(x438.toInt)
val x441 = x3227
val x442 = x441.length
var x440: Int = 0
while (x440 < x442) { //flatMap loop
val x443 = x441(x440.toInt)
val x444 = __act.x3228_buf
val x445 = x443
if (true) {
val x3117 = __act.x3228_size
val x3118 = x444.length
val x3119 = x3118 - 1
val x3120 = x3117 > x3119
val x3133 = {
def x3133thenb(): Unit = {
val x3121 = x3118 < 16
val x3125 = {
def x3125thenb(): Int = {
16
}
def x3125elseb(): Int = {
val x3122 = x3118 * 2
val x3123 = x3122 < 0
val x3124 = {
def x3124thenb(): Int = {
2147483647
}
def x3124elseb(): Int = {
x3122
}
if (x3123) {
x3124thenb()
} else { 
x3124elseb()
}
}
x3124
}
if (x3121) {
x3125thenb()
} else { 
x3125elseb()
}
}
if (x3125 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3126 = new Array[FixedPoint[Signed,B32,B0]](x3125.toInt)
val x3127 = System.arraycopy(x444,0.toInt,x3126,0.toInt,x3118.toInt)
val x3128 = x3126(x3117.toInt) = x445
val x3129 = __act.x3228_buf = x3126
x3129
}
def x3133elseb(): Unit = {
val x3131 = x444(x3117.toInt) = x445
x3131
}
if (x3120) {
x3133thenb()
} else { 
x3133elseb()
}
}
__act.x3228_size = __act.x3228_size + 1
}
__act.x3228_conditionals = __act.x3228_conditionals + 1
x440 = x440 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3228,rhs:activation_x3228): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3228,lhs:activation_x3228): Unit = {
__act.x3228_offset = lhs.x3228_offset+lhs.x3228_size
__act.x3228_conditionals = __act.x3228_conditionals+lhs.x3228_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3228): Unit = {
if (__act.x3228_offset > 0) {
val x446 = __act.x3228_offset + __act.x3228_size
val x444 = __act.x3228_buf
if (x446 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3143 = new Array[FixedPoint[Signed,B32,B0]](x446.toInt)
__act.x3228_data_set(resourceInfo,x3143,__act.x3228_conditionals)
} else {
__act.x3228_data_set(resourceInfo,__act.x3228_buf,__act.x3228_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3228): Unit = {
if (__act.x3228_data ne __act.x3228_buf) {
val x446 = __act.x3228_size
val x449 = __act.x3228_buf
val x444 = __act.x3228_data
val x447 = 0
val x448 = __act.x3228_offset
val x3145 = System.arraycopy(x449,x447.toInt,x444,x448.toInt,x446.toInt)
}
__act.x3228_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3228): Unit = {
var x444: Array[FixedPoint[Signed,B32,B0]] = __act.x3228_data
__act.x3228_data = null
val x446 = __act.x3228_conditionals
val x3135 = x444.length
val x3136 = x3135 > x446
val x3141 = {
def x3141thenb(): Unit = {
if (x446 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3137 = new Array[FixedPoint[Signed,B32,B0]](x446.toInt)
val x3138 = System.arraycopy(x444,0.toInt,x3137,0.toInt,x446.toInt)
val x3139 = x444 = x3137
x3139
}
if (x3136) {
x3141thenb()
}
}
__act.x3228 = x444
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3228 = {
val act: activation_x3228 = new activation_x3228
act
}

}
x3228_closure.loopStart = 0
x3228_closure.loopSize = x240
val alloc: activation_x3228 = x3228_closure.alloc(resourceInfo)
var x3228: activation_x3228 = null
if (resourceInfo.availableThreads <= 1) {
x3228 = x3228_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3228] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3228](x3228_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3228_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3228 = x3228_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3228
}}

/**********/

