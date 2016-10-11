package generated.scala
//activation record for fat loop
final class activation_x3226 {
var left_act: activation_x3226 = _
var x3226: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x3226_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x3226 {
}
object kernel_x3226 {
def apply(resourceInfo:generated.scala.ResourceInfo,x240:Int,x119:FixedPoint[Signed,B32,B0],x50:FixedPoint[Signed,B32,B0],x246:FixedPoint[Signed,B32,B0],x247:Int,x243:Int): activation_x3226 = {
val x3226_closure = new generated.scala.DeliteOpMultiLoop[activation_x3226] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x240
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3226 = {
val __act: activation_x3226 = new activation_x3226()
val x397 = (loopSize).asInstanceOf[Int]
if (x397 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3074 = new Array[Array[FixedPoint[Signed,B32,B0]]](x397.toInt)
__act.x3226_data = x3074
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3226,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3226]): activation_x3226 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3226 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3226 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3226): activation_x3226 = {
val act: activation_x3226 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3226,start:Long,end:Long): activation_x3226 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3226 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3226,x241:Int,isEmpty:Boolean): activation_x3226 = {
if (!isEmpty) {
process(resourceInfo,__act,x241)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3226,x241:Int): Unit = {
val x242 = {
FixedPoint[Signed,B32,B0](x241)
}
val x254 = {
x242 * x246
}
var x305: Int = x243
if (x305 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2999 = new Array[Array[FixedPoint[Signed,B32,B0]]](x305.toInt)
val x3035_data: Array[Array[FixedPoint[Signed,B32,B0]]] = x2999
var x3035_size: Int = 0
var x3035_conditionals: Int = 0
var x244: Int = 0
while (x244 < x243) {  // begin fat loop x3035
val x245 = {
FixedPoint[Signed,B32,B0](x244)
}
val x250 = {
x245 + x119
}
val x256 = {
x250 * x242
}
val x257 = {
x256 * x246
}
val x258 = {
x257 * x50
}
var x262: Int = x247
if (x262 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x2962 = new Array[FixedPoint[Signed,B32,B0]](x262.toInt)
val x2998_data: Array[FixedPoint[Signed,B32,B0]] = x2962
var x2998_size: Int = 0
var x2998_conditionals: Int = 0
var x248: Int = 0
while (x248 < x247) {  // begin fat loop x2998
val x249 = {
FixedPoint[Signed,B32,B0](x248)
}
val x251 = {
x250 * x249
}
val x252 = {
x251 * x50
}
val x253 = {
x249 + x252
}
val x255 = {
x253 + x254
}
val x259 = {
x255 + x258
}
val x261 = x259
val x260 = x2998_data
val x2966 = x260(x248.toInt) = x261
x248 = x248 + 1
} // end fat loop x2998
val x260 = x2998_data
val x2998 = x260
val x304 = x2998
val x303 = x3035_data
val x3003 = x303(x244.toInt) = x304
x244 = x244 + 1
} // end fat loop x3035
val x303 = x3035_data
val x3035 = x303
var x354: Int = 0
if (x354 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3036 = new Array[FixedPoint[Signed,B32,B0]](x354.toInt)
var x3073_buf: Array[FixedPoint[Signed,B32,B0]] = x3036
var x3073_size: Int = 0
var x3073_conditionals: Int = 0
var x346: Int = 0
while (x346 < x243) {  // begin fat loop x3073
val x3072 = x3035(x346.toInt)
val x349 = x3072
val x350 = x349.length
var x348: Int = 0
while (x348 < x350) { //flatMap loop
val x351 = x349(x348.toInt)
val x352 = x3073_buf
val x353 = x351
if (true) {
val x3042 = x3073_size
val x3043 = x352.length
val x3044 = x3043 - 1
val x3045 = x3042 > x3044
val x3058 = {
def x3058thenb(): Unit = {
val x3046 = x3043 < 16
val x3050 = {
def x3050thenb(): Int = {
16
}
def x3050elseb(): Int = {
val x3047 = x3043 * 2
val x3048 = x3047 < 0
val x3049 = {
def x3049thenb(): Int = {
2147483647
}
def x3049elseb(): Int = {
x3047
}
if (x3048) {
x3049thenb()
} else { 
x3049elseb()
}
}
x3049
}
if (x3046) {
x3050thenb()
} else { 
x3050elseb()
}
}
if (x3050 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3051 = new Array[FixedPoint[Signed,B32,B0]](x3050.toInt)
val x3052 = System.arraycopy(x352,0.toInt,x3051,0.toInt,x3043.toInt)
val x3053 = x3051(x3042.toInt) = x353
val x3054 = x3073_buf = x3051
x3054
}
def x3058elseb(): Unit = {
val x3056 = x352(x3042.toInt) = x353
x3056
}
if (x3045) {
x3058thenb()
} else { 
x3058elseb()
}
}
x3073_size = x3073_size + 1
}
x3073_conditionals = x3073_conditionals + 1
x348 = x348 + 1
}
x346 = x346 + 1
} // end fat loop x3073
var x352: Array[FixedPoint[Signed,B32,B0]] = x3073_buf
x354 = x3073_conditionals
val x3060 = x352.length
val x3061 = x3060 > x354
val x3066 = {
def x3066thenb(): Unit = {
if (x354 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3062 = new Array[FixedPoint[Signed,B32,B0]](x354.toInt)
val x3063 = System.arraycopy(x352,0.toInt,x3062,0.toInt,x354.toInt)
val x3064 = x352 = x3062
x3064
}
if (x3061) {
x3066thenb()
}
}
val x3073 = x352
val x396 = x3073
val x395 = __act.x3226_data
val x3078 = x395(x241.toInt) = x396
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3226,rhs:activation_x3226): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3226,lhs:activation_x3226): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3226): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3226): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3226): Unit = {
var x395: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x3226_data
__act.x3226_data = null
__act.x3226 = x395
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3226 = {
val act: activation_x3226 = new activation_x3226
act
}

}
x3226_closure.loopStart = 0
x3226_closure.loopSize = x240
val alloc: activation_x3226 = x3226_closure.alloc(resourceInfo)
var x3226: activation_x3226 = null
if (resourceInfo.availableThreads <= 1) {
x3226 = x3226_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3226] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3226](x3226_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3226_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3226 = x3226_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3226
}}

/**********/

