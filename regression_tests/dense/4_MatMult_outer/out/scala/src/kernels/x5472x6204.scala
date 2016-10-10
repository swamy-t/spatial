package generated.scala
//activation record for fat loop
final class activation_x5472x6204 {
var left_act: activation_x5472x6204 = _
var x5472: Array[FixedPoint[Signed,B32,B0]] = _
var x5472_data: Array[FixedPoint[Signed,B32,B0]] = _
var x5472_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x5472_size: Int = _
var x5472_offset: Int = _
var x5472_conditionals: Int = _
def x5472_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x5472_data = xs
x5472_conditionals = cs
if (left_act ne null)
left_act.x5472_data_set(resourceInfo,xs,cs)
}

var x6204: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x6204_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x5472x6204 {
}
object kernel_x5472x6204 {
def apply(resourceInfo:generated.scala.ResourceInfo,x7:Int,x6203:Array[FixedPoint[Signed,B32,B0]],x5434:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x5472x6204 = {
val x5472x6204_closure = new generated.scala.DeliteOpMultiLoop[activation_x5472x6204] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x7
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5472x6204 = {
val __act: activation_x5472x6204 = new activation_x5472x6204()
// __act.x5472 stays null for now
val x235 = (loopSize).asInstanceOf[Int]
if (x235 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5624 = new Array[Array[FixedPoint[Signed,B32,B0]]](x235.toInt)
__act.x6204_data = x5624
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5472x6204,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5472x6204]): activation_x5472x6204 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5472x6204 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5472x6204 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x5472x6204 = act
while (j < localEnd) {
val rhsAct: activation_x5472x6204 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5472x6204): activation_x5472x6204 = {
val act: activation_x5472x6204 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5472x6204,start:Long,end:Long): activation_x5472x6204 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5472x6204 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5472x6204,x276:Int,isEmpty:Boolean): activation_x5472x6204 = {
val __act2: activation_x5472x6204 = new activation_x5472x6204()
val x284 = 0
if (x284 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5435 = new Array[FixedPoint[Signed,B32,B0]](x284.toInt)
__act2.x5472_buf = x5435
__act2.x6204_data = __act.x6204_data
if (!isEmpty) {
val x5471 = x5434(x276.toInt)
val x279 = x5471
val x280 = x279.length
var x278: Int = 0
while (x278 < x280) { //flatMap loop
val x281 = x279(x278.toInt)
val x282 = __act2.x5472_buf
val x283 = x281
if (true) {
val x5441 = __act2.x5472_size
val x5442 = x282.length
val x5443 = x5442 - 1
val x5444 = x5441 > x5443
val x5457 = {
def x5457thenb(): Unit = {
val x5445 = x5442 < 16
val x5449 = {
def x5449thenb(): Int = {
16
}
def x5449elseb(): Int = {
val x5446 = x5442 * 2
val x5447 = x5446 < 0
val x5448 = {
def x5448thenb(): Int = {
2147483647
}
def x5448elseb(): Int = {
x5446
}
if (x5447) {
x5448thenb()
} else { 
x5448elseb()
}
}
x5448
}
if (x5445) {
x5449thenb()
} else { 
x5449elseb()
}
}
if (x5449 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5450 = new Array[FixedPoint[Signed,B32,B0]](x5449.toInt)
val x5451 = System.arraycopy(x282,0.toInt,x5450,0.toInt,x5442.toInt)
val x5452 = x5450(x5441.toInt) = x283
val x5453 = __act2.x5472_buf = x5450
x5453
}
def x5457elseb(): Unit = {
val x5455 = x282(x5441.toInt) = x283
x5455
}
if (x5444) {
x5457thenb()
} else { 
x5457elseb()
}
}
__act2.x5472_size = __act2.x5472_size + 1
}
__act2.x5472_conditionals = __act2.x5472_conditionals + 1
x278 = x278 + 1
}
val x234 = x6203
val x233 = __act2.x6204_data
val x6199 = x233(x276.toInt) = x234
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5472x6204,x276:Int): Unit = {
val x5471 = x5434(x276.toInt)
val x279 = x5471
val x280 = x279.length
var x278: Int = 0
while (x278 < x280) { //flatMap loop
val x281 = x279(x278.toInt)
val x282 = __act.x5472_buf
val x283 = x281
if (true) {
val x5441 = __act.x5472_size
val x5442 = x282.length
val x5443 = x5442 - 1
val x5444 = x5441 > x5443
val x5457 = {
def x5457thenb(): Unit = {
val x5445 = x5442 < 16
val x5449 = {
def x5449thenb(): Int = {
16
}
def x5449elseb(): Int = {
val x5446 = x5442 * 2
val x5447 = x5446 < 0
val x5448 = {
def x5448thenb(): Int = {
2147483647
}
def x5448elseb(): Int = {
x5446
}
if (x5447) {
x5448thenb()
} else { 
x5448elseb()
}
}
x5448
}
if (x5445) {
x5449thenb()
} else { 
x5449elseb()
}
}
if (x5449 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5450 = new Array[FixedPoint[Signed,B32,B0]](x5449.toInt)
val x5451 = System.arraycopy(x282,0.toInt,x5450,0.toInt,x5442.toInt)
val x5452 = x5450(x5441.toInt) = x283
val x5453 = __act.x5472_buf = x5450
x5453
}
def x5457elseb(): Unit = {
val x5455 = x282(x5441.toInt) = x283
x5455
}
if (x5444) {
x5457thenb()
} else { 
x5457elseb()
}
}
__act.x5472_size = __act.x5472_size + 1
}
__act.x5472_conditionals = __act.x5472_conditionals + 1
x278 = x278 + 1
}
val x234 = x6203
val x233 = __act.x6204_data
val x6199 = x233(x276.toInt) = x234
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5472x6204,rhs:activation_x5472x6204): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5472x6204,lhs:activation_x5472x6204): Unit = {
__act.x5472_offset = lhs.x5472_offset+lhs.x5472_size
__act.x5472_conditionals = __act.x5472_conditionals+lhs.x5472_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5472x6204): Unit = {
if (__act.x5472_offset > 0) {
val x284 = __act.x5472_offset + __act.x5472_size
val x282 = __act.x5472_buf
if (x284 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5467 = new Array[FixedPoint[Signed,B32,B0]](x284.toInt)
__act.x5472_data_set(resourceInfo,x5467,__act.x5472_conditionals)
} else {
__act.x5472_data_set(resourceInfo,__act.x5472_buf,__act.x5472_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5472x6204): Unit = {
if (__act.x5472_data ne __act.x5472_buf) {
val x284 = __act.x5472_size
val x287 = __act.x5472_buf
val x282 = __act.x5472_data
val x285 = 0
val x286 = __act.x5472_offset
val x5469 = System.arraycopy(x287,x285.toInt,x282,x286.toInt,x284.toInt)
}
__act.x5472_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5472x6204): Unit = {
var x282: Array[FixedPoint[Signed,B32,B0]] = __act.x5472_data
__act.x5472_data = null
val x284 = __act.x5472_conditionals
val x5459 = x282.length
val x5460 = x5459 > x284
val x5465 = {
def x5465thenb(): Unit = {
if (x284 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5461 = new Array[FixedPoint[Signed,B32,B0]](x284.toInt)
val x5462 = System.arraycopy(x282,0.toInt,x5461,0.toInt,x284.toInt)
val x5463 = x282 = x5461
x5463
}
if (x5460) {
x5465thenb()
}
}
__act.x5472 = x282
var x233: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x6204_data
__act.x6204_data = null
__act.x6204 = x233
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5472x6204 = {
val act: activation_x5472x6204 = new activation_x5472x6204
act
}

}
x5472x6204_closure.loopStart = 0
x5472x6204_closure.loopSize = x7
val alloc: activation_x5472x6204 = x5472x6204_closure.alloc(resourceInfo)
var x5472x6204: activation_x5472x6204 = null
if (resourceInfo.availableThreads <= 1) {
x5472x6204 = x5472x6204_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5472x6204] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5472x6204](x5472x6204_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5472x6204_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5472x6204 = x5472x6204_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5472x6204
}}

/**********/

