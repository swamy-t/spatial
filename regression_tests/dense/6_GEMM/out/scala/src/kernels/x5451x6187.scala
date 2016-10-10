package generated.scala
//activation record for fat loop
final class activation_x5451x6187 {
var left_act: activation_x5451x6187 = _
var x5451: Array[FixedPoint[Signed,B32,B0]] = _
var x5451_data: Array[FixedPoint[Signed,B32,B0]] = _
var x5451_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x5451_size: Int = _
var x5451_offset: Int = _
var x5451_conditionals: Int = _
def x5451_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x5451_data = xs
x5451_conditionals = cs
if (left_act ne null)
left_act.x5451_data_set(resourceInfo,xs,cs)
}

var x6187: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x6187_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x5451x6187 {
}
object kernel_x5451x6187 {
def apply(resourceInfo:generated.scala.ResourceInfo,x7:Int,x6186:Array[FixedPoint[Signed,B32,B0]],x5413:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x5451x6187 = {
val x5451x6187_closure = new generated.scala.DeliteOpMultiLoop[activation_x5451x6187] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x7
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5451x6187 = {
val __act: activation_x5451x6187 = new activation_x5451x6187()
// __act.x5451 stays null for now
val x235 = (loopSize).asInstanceOf[Int]
if (x235 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5603 = new Array[Array[FixedPoint[Signed,B32,B0]]](x235.toInt)
__act.x6187_data = x5603
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5451x6187,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5451x6187]): activation_x5451x6187 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5451x6187 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5451x6187 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x5451x6187 = act
while (j < localEnd) {
val rhsAct: activation_x5451x6187 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5451x6187): activation_x5451x6187 = {
val act: activation_x5451x6187 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5451x6187,start:Long,end:Long): activation_x5451x6187 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5451x6187 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5451x6187,x276:Int,isEmpty:Boolean): activation_x5451x6187 = {
val __act2: activation_x5451x6187 = new activation_x5451x6187()
val x284 = 0
if (x284 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5414 = new Array[FixedPoint[Signed,B32,B0]](x284.toInt)
__act2.x5451_buf = x5414
__act2.x6187_data = __act.x6187_data
if (!isEmpty) {
val x5450 = x5413(x276.toInt)
val x279 = x5450
val x280 = x279.length
var x278: Int = 0
while (x278 < x280) { //flatMap loop
val x281 = x279(x278.toInt)
val x282 = __act2.x5451_buf
val x283 = x281
if (true) {
val x5420 = __act2.x5451_size
val x5421 = x282.length
val x5422 = x5421 - 1
val x5423 = x5420 > x5422
val x5436 = {
def x5436thenb(): Unit = {
val x5424 = x5421 < 16
val x5428 = {
def x5428thenb(): Int = {
16
}
def x5428elseb(): Int = {
val x5425 = x5421 * 2
val x5426 = x5425 < 0
val x5427 = {
def x5427thenb(): Int = {
2147483647
}
def x5427elseb(): Int = {
x5425
}
if (x5426) {
x5427thenb()
} else { 
x5427elseb()
}
}
x5427
}
if (x5424) {
x5428thenb()
} else { 
x5428elseb()
}
}
if (x5428 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5429 = new Array[FixedPoint[Signed,B32,B0]](x5428.toInt)
val x5430 = System.arraycopy(x282,0.toInt,x5429,0.toInt,x5421.toInt)
val x5431 = x5429(x5420.toInt) = x283
val x5432 = __act2.x5451_buf = x5429
x5432
}
def x5436elseb(): Unit = {
val x5434 = x282(x5420.toInt) = x283
x5434
}
if (x5423) {
x5436thenb()
} else { 
x5436elseb()
}
}
__act2.x5451_size = __act2.x5451_size + 1
}
__act2.x5451_conditionals = __act2.x5451_conditionals + 1
x278 = x278 + 1
}
val x234 = x6186
val x233 = __act2.x6187_data
val x6182 = x233(x276.toInt) = x234
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5451x6187,x276:Int): Unit = {
val x5450 = x5413(x276.toInt)
val x279 = x5450
val x280 = x279.length
var x278: Int = 0
while (x278 < x280) { //flatMap loop
val x281 = x279(x278.toInt)
val x282 = __act.x5451_buf
val x283 = x281
if (true) {
val x5420 = __act.x5451_size
val x5421 = x282.length
val x5422 = x5421 - 1
val x5423 = x5420 > x5422
val x5436 = {
def x5436thenb(): Unit = {
val x5424 = x5421 < 16
val x5428 = {
def x5428thenb(): Int = {
16
}
def x5428elseb(): Int = {
val x5425 = x5421 * 2
val x5426 = x5425 < 0
val x5427 = {
def x5427thenb(): Int = {
2147483647
}
def x5427elseb(): Int = {
x5425
}
if (x5426) {
x5427thenb()
} else { 
x5427elseb()
}
}
x5427
}
if (x5424) {
x5428thenb()
} else { 
x5428elseb()
}
}
if (x5428 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5429 = new Array[FixedPoint[Signed,B32,B0]](x5428.toInt)
val x5430 = System.arraycopy(x282,0.toInt,x5429,0.toInt,x5421.toInt)
val x5431 = x5429(x5420.toInt) = x283
val x5432 = __act.x5451_buf = x5429
x5432
}
def x5436elseb(): Unit = {
val x5434 = x282(x5420.toInt) = x283
x5434
}
if (x5423) {
x5436thenb()
} else { 
x5436elseb()
}
}
__act.x5451_size = __act.x5451_size + 1
}
__act.x5451_conditionals = __act.x5451_conditionals + 1
x278 = x278 + 1
}
val x234 = x6186
val x233 = __act.x6187_data
val x6182 = x233(x276.toInt) = x234
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5451x6187,rhs:activation_x5451x6187): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5451x6187,lhs:activation_x5451x6187): Unit = {
__act.x5451_offset = lhs.x5451_offset+lhs.x5451_size
__act.x5451_conditionals = __act.x5451_conditionals+lhs.x5451_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5451x6187): Unit = {
if (__act.x5451_offset > 0) {
val x284 = __act.x5451_offset + __act.x5451_size
val x282 = __act.x5451_buf
if (x284 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5446 = new Array[FixedPoint[Signed,B32,B0]](x284.toInt)
__act.x5451_data_set(resourceInfo,x5446,__act.x5451_conditionals)
} else {
__act.x5451_data_set(resourceInfo,__act.x5451_buf,__act.x5451_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5451x6187): Unit = {
if (__act.x5451_data ne __act.x5451_buf) {
val x284 = __act.x5451_size
val x287 = __act.x5451_buf
val x282 = __act.x5451_data
val x285 = 0
val x286 = __act.x5451_offset
val x5448 = System.arraycopy(x287,x285.toInt,x282,x286.toInt,x284.toInt)
}
__act.x5451_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5451x6187): Unit = {
var x282: Array[FixedPoint[Signed,B32,B0]] = __act.x5451_data
__act.x5451_data = null
val x284 = __act.x5451_conditionals
val x5438 = x282.length
val x5439 = x5438 > x284
val x5444 = {
def x5444thenb(): Unit = {
if (x284 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5440 = new Array[FixedPoint[Signed,B32,B0]](x284.toInt)
val x5441 = System.arraycopy(x282,0.toInt,x5440,0.toInt,x284.toInt)
val x5442 = x282 = x5440
x5442
}
if (x5439) {
x5444thenb()
}
}
__act.x5451 = x282
var x233: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x6187_data
__act.x6187_data = null
__act.x6187 = x233
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5451x6187 = {
val act: activation_x5451x6187 = new activation_x5451x6187
act
}

}
x5451x6187_closure.loopStart = 0
x5451x6187_closure.loopSize = x7
val alloc: activation_x5451x6187 = x5451x6187_closure.alloc(resourceInfo)
var x5451x6187: activation_x5451x6187 = null
if (resourceInfo.availableThreads <= 1) {
x5451x6187 = x5451x6187_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5451x6187] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5451x6187](x5451x6187_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5451x6187_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5451x6187 = x5451x6187_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5451x6187
}}

/**********/

