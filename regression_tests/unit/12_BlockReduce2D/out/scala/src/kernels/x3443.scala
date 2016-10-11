package generated.scala
//activation record for fat loop
final class activation_x3443 {
var left_act: activation_x3443 = _
var x3443: Array[FixedPoint[Signed,B32,B0]] = _
var x3443_data: Array[FixedPoint[Signed,B32,B0]] = _
var x3443_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x3443_size: Int = _
var x3443_offset: Int = _
var x3443_conditionals: Int = _
def x3443_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x3443_data = xs
x3443_conditionals = cs
if (left_act ne null)
left_act.x3443_data_set(resourceInfo,xs,cs)
}

}
object activation_x3443 {
}
object kernel_x3443 {
def apply(resourceInfo:generated.scala.ResourceInfo,x5:Int,x3405:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x3443 = {
val x3443_closure = new generated.scala.DeliteOpMultiLoop[activation_x3443] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x5
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3443 = {
val __act: activation_x3443 = new activation_x3443()
// __act.x3443 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3443,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3443]): activation_x3443 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3443 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3443 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x3443 = act
while (j < localEnd) {
val rhsAct: activation_x3443 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3443): activation_x3443 = {
val act: activation_x3443 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3443,start:Long,end:Long): activation_x3443 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3443 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3443,x148:Int,isEmpty:Boolean): activation_x3443 = {
val __act2: activation_x3443 = new activation_x3443()
val x156 = 0
if (x156 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3406 = new Array[FixedPoint[Signed,B32,B0]](x156.toInt)
__act2.x3443_buf = x3406
if (!isEmpty) {
val x3442 = x3405(x148.toInt)
val x151 = x3442
val x152 = x151.length
var x150: Int = 0
while (x150 < x152) { //flatMap loop
val x153 = x151(x150.toInt)
val x154 = __act2.x3443_buf
val x155 = x153
if (true) {
val x3412 = __act2.x3443_size
val x3413 = x154.length
val x3414 = x3413 - 1
val x3415 = x3412 > x3414
val x3428 = {
def x3428thenb(): Unit = {
val x3416 = x3413 < 16
val x3420 = {
def x3420thenb(): Int = {
16
}
def x3420elseb(): Int = {
val x3417 = x3413 * 2
val x3418 = x3417 < 0
val x3419 = {
def x3419thenb(): Int = {
2147483647
}
def x3419elseb(): Int = {
x3417
}
if (x3418) {
x3419thenb()
} else { 
x3419elseb()
}
}
x3419
}
if (x3416) {
x3420thenb()
} else { 
x3420elseb()
}
}
if (x3420 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3421 = new Array[FixedPoint[Signed,B32,B0]](x3420.toInt)
val x3422 = System.arraycopy(x154,0.toInt,x3421,0.toInt,x3413.toInt)
val x3423 = x3421(x3412.toInt) = x155
val x3424 = __act2.x3443_buf = x3421
x3424
}
def x3428elseb(): Unit = {
val x3426 = x154(x3412.toInt) = x155
x3426
}
if (x3415) {
x3428thenb()
} else { 
x3428elseb()
}
}
__act2.x3443_size = __act2.x3443_size + 1
}
__act2.x3443_conditionals = __act2.x3443_conditionals + 1
x150 = x150 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3443,x148:Int): Unit = {
val x3442 = x3405(x148.toInt)
val x151 = x3442
val x152 = x151.length
var x150: Int = 0
while (x150 < x152) { //flatMap loop
val x153 = x151(x150.toInt)
val x154 = __act.x3443_buf
val x155 = x153
if (true) {
val x3412 = __act.x3443_size
val x3413 = x154.length
val x3414 = x3413 - 1
val x3415 = x3412 > x3414
val x3428 = {
def x3428thenb(): Unit = {
val x3416 = x3413 < 16
val x3420 = {
def x3420thenb(): Int = {
16
}
def x3420elseb(): Int = {
val x3417 = x3413 * 2
val x3418 = x3417 < 0
val x3419 = {
def x3419thenb(): Int = {
2147483647
}
def x3419elseb(): Int = {
x3417
}
if (x3418) {
x3419thenb()
} else { 
x3419elseb()
}
}
x3419
}
if (x3416) {
x3420thenb()
} else { 
x3420elseb()
}
}
if (x3420 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3421 = new Array[FixedPoint[Signed,B32,B0]](x3420.toInt)
val x3422 = System.arraycopy(x154,0.toInt,x3421,0.toInt,x3413.toInt)
val x3423 = x3421(x3412.toInt) = x155
val x3424 = __act.x3443_buf = x3421
x3424
}
def x3428elseb(): Unit = {
val x3426 = x154(x3412.toInt) = x155
x3426
}
if (x3415) {
x3428thenb()
} else { 
x3428elseb()
}
}
__act.x3443_size = __act.x3443_size + 1
}
__act.x3443_conditionals = __act.x3443_conditionals + 1
x150 = x150 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3443,rhs:activation_x3443): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3443,lhs:activation_x3443): Unit = {
__act.x3443_offset = lhs.x3443_offset+lhs.x3443_size
__act.x3443_conditionals = __act.x3443_conditionals+lhs.x3443_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3443): Unit = {
if (__act.x3443_offset > 0) {
val x156 = __act.x3443_offset + __act.x3443_size
val x154 = __act.x3443_buf
if (x156 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3438 = new Array[FixedPoint[Signed,B32,B0]](x156.toInt)
__act.x3443_data_set(resourceInfo,x3438,__act.x3443_conditionals)
} else {
__act.x3443_data_set(resourceInfo,__act.x3443_buf,__act.x3443_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3443): Unit = {
if (__act.x3443_data ne __act.x3443_buf) {
val x156 = __act.x3443_size
val x159 = __act.x3443_buf
val x154 = __act.x3443_data
val x157 = 0
val x158 = __act.x3443_offset
val x3440 = System.arraycopy(x159,x157.toInt,x154,x158.toInt,x156.toInt)
}
__act.x3443_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3443): Unit = {
var x154: Array[FixedPoint[Signed,B32,B0]] = __act.x3443_data
__act.x3443_data = null
val x156 = __act.x3443_conditionals
val x3430 = x154.length
val x3431 = x3430 > x156
val x3436 = {
def x3436thenb(): Unit = {
if (x156 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3432 = new Array[FixedPoint[Signed,B32,B0]](x156.toInt)
val x3433 = System.arraycopy(x154,0.toInt,x3432,0.toInt,x156.toInt)
val x3434 = x154 = x3432
x3434
}
if (x3431) {
x3436thenb()
}
}
__act.x3443 = x154
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3443 = {
val act: activation_x3443 = new activation_x3443
act
}

}
x3443_closure.loopStart = 0
x3443_closure.loopSize = x5
val alloc: activation_x3443 = x3443_closure.alloc(resourceInfo)
var x3443: activation_x3443 = null
if (resourceInfo.availableThreads <= 1) {
x3443 = x3443_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3443] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3443](x3443_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3443_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3443 = x3443_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3443
}}

/**********/

