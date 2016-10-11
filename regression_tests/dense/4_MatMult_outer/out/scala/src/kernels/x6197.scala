package generated.scala
//activation record for fat loop
final class activation_x6197 {
var left_act: activation_x6197 = _
var x6197: Array[FixedPoint[Signed,B32,B0]] = _
var x6197_data: Array[FixedPoint[Signed,B32,B0]] = _
var x6197_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x6197_size: Int = _
var x6197_offset: Int = _
var x6197_conditionals: Int = _
def x6197_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x6197_data = xs
x6197_conditionals = cs
if (left_act ne null)
left_act.x6197_data_set(resourceInfo,xs,cs)
}

}
object activation_x6197 {
}
object kernel_x6197 {
def apply(resourceInfo:generated.scala.ResourceInfo,x9:Int,x6195:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x6197 = {
val x6197_closure = new generated.scala.DeliteOpMultiLoop[activation_x6197] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x9
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6197 = {
val __act: activation_x6197 = new activation_x6197()
// __act.x6197 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6197,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6197]): activation_x6197 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6197 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6197 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x6197 = act
while (j < localEnd) {
val rhsAct: activation_x6197 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6197): activation_x6197 = {
val act: activation_x6197 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6197,start:Long,end:Long): activation_x6197 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6197 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6197,x325:Int,isEmpty:Boolean): activation_x6197 = {
val __act2: activation_x6197 = new activation_x6197()
val x333 = 0
if (x333 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5548 = new Array[FixedPoint[Signed,B32,B0]](x333.toInt)
__act2.x6197_buf = x5548
if (!isEmpty) {
val x6196 = x6195(x325.toInt)
val x328 = x6196
val x329 = x328.length
var x327: Int = 0
while (x327 < x329) { //flatMap loop
val x330 = x328(x327.toInt)
val x331 = __act2.x6197_buf
val x332 = x330
if (true) {
val x5554 = __act2.x6197_size
val x5555 = x331.length
val x5556 = x5555 - 1
val x5557 = x5554 > x5556
val x5570 = {
def x5570thenb(): Unit = {
val x5558 = x5555 < 16
val x5562 = {
def x5562thenb(): Int = {
16
}
def x5562elseb(): Int = {
val x5559 = x5555 * 2
val x5560 = x5559 < 0
val x5561 = {
def x5561thenb(): Int = {
2147483647
}
def x5561elseb(): Int = {
x5559
}
if (x5560) {
x5561thenb()
} else { 
x5561elseb()
}
}
x5561
}
if (x5558) {
x5562thenb()
} else { 
x5562elseb()
}
}
if (x5562 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5563 = new Array[FixedPoint[Signed,B32,B0]](x5562.toInt)
val x5564 = System.arraycopy(x331,0.toInt,x5563,0.toInt,x5555.toInt)
val x5565 = x5563(x5554.toInt) = x332
val x5566 = __act2.x6197_buf = x5563
x5566
}
def x5570elseb(): Unit = {
val x5568 = x331(x5554.toInt) = x332
x5568
}
if (x5557) {
x5570thenb()
} else { 
x5570elseb()
}
}
__act2.x6197_size = __act2.x6197_size + 1
}
__act2.x6197_conditionals = __act2.x6197_conditionals + 1
x327 = x327 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6197,x325:Int): Unit = {
val x6196 = x6195(x325.toInt)
val x328 = x6196
val x329 = x328.length
var x327: Int = 0
while (x327 < x329) { //flatMap loop
val x330 = x328(x327.toInt)
val x331 = __act.x6197_buf
val x332 = x330
if (true) {
val x5554 = __act.x6197_size
val x5555 = x331.length
val x5556 = x5555 - 1
val x5557 = x5554 > x5556
val x5570 = {
def x5570thenb(): Unit = {
val x5558 = x5555 < 16
val x5562 = {
def x5562thenb(): Int = {
16
}
def x5562elseb(): Int = {
val x5559 = x5555 * 2
val x5560 = x5559 < 0
val x5561 = {
def x5561thenb(): Int = {
2147483647
}
def x5561elseb(): Int = {
x5559
}
if (x5560) {
x5561thenb()
} else { 
x5561elseb()
}
}
x5561
}
if (x5558) {
x5562thenb()
} else { 
x5562elseb()
}
}
if (x5562 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5563 = new Array[FixedPoint[Signed,B32,B0]](x5562.toInt)
val x5564 = System.arraycopy(x331,0.toInt,x5563,0.toInt,x5555.toInt)
val x5565 = x5563(x5554.toInt) = x332
val x5566 = __act.x6197_buf = x5563
x5566
}
def x5570elseb(): Unit = {
val x5568 = x331(x5554.toInt) = x332
x5568
}
if (x5557) {
x5570thenb()
} else { 
x5570elseb()
}
}
__act.x6197_size = __act.x6197_size + 1
}
__act.x6197_conditionals = __act.x6197_conditionals + 1
x327 = x327 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6197,rhs:activation_x6197): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6197,lhs:activation_x6197): Unit = {
__act.x6197_offset = lhs.x6197_offset+lhs.x6197_size
__act.x6197_conditionals = __act.x6197_conditionals+lhs.x6197_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6197): Unit = {
if (__act.x6197_offset > 0) {
val x333 = __act.x6197_offset + __act.x6197_size
val x331 = __act.x6197_buf
if (x333 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5580 = new Array[FixedPoint[Signed,B32,B0]](x333.toInt)
__act.x6197_data_set(resourceInfo,x5580,__act.x6197_conditionals)
} else {
__act.x6197_data_set(resourceInfo,__act.x6197_buf,__act.x6197_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6197): Unit = {
if (__act.x6197_data ne __act.x6197_buf) {
val x333 = __act.x6197_size
val x336 = __act.x6197_buf
val x331 = __act.x6197_data
val x334 = 0
val x335 = __act.x6197_offset
val x5582 = System.arraycopy(x336,x334.toInt,x331,x335.toInt,x333.toInt)
}
__act.x6197_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6197): Unit = {
var x331: Array[FixedPoint[Signed,B32,B0]] = __act.x6197_data
__act.x6197_data = null
val x333 = __act.x6197_conditionals
val x5572 = x331.length
val x5573 = x5572 > x333
val x5578 = {
def x5578thenb(): Unit = {
if (x333 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5574 = new Array[FixedPoint[Signed,B32,B0]](x333.toInt)
val x5575 = System.arraycopy(x331,0.toInt,x5574,0.toInt,x333.toInt)
val x5576 = x331 = x5574
x5576
}
if (x5573) {
x5578thenb()
}
}
__act.x6197 = x331
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6197 = {
val act: activation_x6197 = new activation_x6197
act
}

}
x6197_closure.loopStart = 0
x6197_closure.loopSize = x9
val alloc: activation_x6197 = x6197_closure.alloc(resourceInfo)
var x6197: activation_x6197 = null
if (resourceInfo.availableThreads <= 1) {
x6197 = x6197_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6197] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6197](x6197_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6197_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6197 = x6197_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6197
}}

/**********/

