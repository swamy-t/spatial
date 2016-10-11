package generated.scala
//activation record for fat loop
final class activation_x4364 {
var left_act: activation_x4364 = _
var x4364: Array[FixedPoint[Signed,B32,B0]] = _
var x4364_data: Array[FixedPoint[Signed,B32,B0]] = _
var x4364_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x4364_size: Int = _
var x4364_offset: Int = _
var x4364_conditionals: Int = _
def x4364_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x4364_data = xs
x4364_conditionals = cs
if (left_act ne null)
left_act.x4364_data_set(resourceInfo,xs,cs)
}

}
object activation_x4364 {
}
object kernel_x4364 {
def apply(resourceInfo:generated.scala.ResourceInfo,x4326:Int,x4279:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x4364 = {
val x4364_closure = new generated.scala.DeliteOpMultiLoop[activation_x4364] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x4326
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x4364 = {
val __act: activation_x4364 = new activation_x4364()
// __act.x4364 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4364,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x4364]): activation_x4364 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x4364 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x4364 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x4364 = act
while (j < localEnd) {
val rhsAct: activation_x4364 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4364): activation_x4364 = {
val act: activation_x4364 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4364,start:Long,end:Long): activation_x4364 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x4364 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4364,x237:Int,isEmpty:Boolean): activation_x4364 = {
val __act2: activation_x4364 = new activation_x4364()
val x245 = 0
if (x245 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4327 = new Array[FixedPoint[Signed,B32,B0]](x245.toInt)
__act2.x4364_buf = x4327
if (!isEmpty) {
val x4363 = x4279(x237.toInt)
val x240 = x4363
val x241 = x240.length
var x239: Int = 0
while (x239 < x241) { //flatMap loop
val x242 = x240(x239.toInt)
val x243 = __act2.x4364_buf
val x244 = x242
if (true) {
val x4333 = __act2.x4364_size
val x4334 = x243.length
val x4335 = x4334 - 1
val x4336 = x4333 > x4335
val x4349 = {
def x4349thenb(): Unit = {
val x4337 = x4334 < 16
val x4341 = {
def x4341thenb(): Int = {
16
}
def x4341elseb(): Int = {
val x4338 = x4334 * 2
val x4339 = x4338 < 0
val x4340 = {
def x4340thenb(): Int = {
2147483647
}
def x4340elseb(): Int = {
x4338
}
if (x4339) {
x4340thenb()
} else { 
x4340elseb()
}
}
x4340
}
if (x4337) {
x4341thenb()
} else { 
x4341elseb()
}
}
if (x4341 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4342 = new Array[FixedPoint[Signed,B32,B0]](x4341.toInt)
val x4343 = System.arraycopy(x243,0.toInt,x4342,0.toInt,x4334.toInt)
val x4344 = x4342(x4333.toInt) = x244
val x4345 = __act2.x4364_buf = x4342
x4345
}
def x4349elseb(): Unit = {
val x4347 = x243(x4333.toInt) = x244
x4347
}
if (x4336) {
x4349thenb()
} else { 
x4349elseb()
}
}
__act2.x4364_size = __act2.x4364_size + 1
}
__act2.x4364_conditionals = __act2.x4364_conditionals + 1
x239 = x239 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4364,x237:Int): Unit = {
val x4363 = x4279(x237.toInt)
val x240 = x4363
val x241 = x240.length
var x239: Int = 0
while (x239 < x241) { //flatMap loop
val x242 = x240(x239.toInt)
val x243 = __act.x4364_buf
val x244 = x242
if (true) {
val x4333 = __act.x4364_size
val x4334 = x243.length
val x4335 = x4334 - 1
val x4336 = x4333 > x4335
val x4349 = {
def x4349thenb(): Unit = {
val x4337 = x4334 < 16
val x4341 = {
def x4341thenb(): Int = {
16
}
def x4341elseb(): Int = {
val x4338 = x4334 * 2
val x4339 = x4338 < 0
val x4340 = {
def x4340thenb(): Int = {
2147483647
}
def x4340elseb(): Int = {
x4338
}
if (x4339) {
x4340thenb()
} else { 
x4340elseb()
}
}
x4340
}
if (x4337) {
x4341thenb()
} else { 
x4341elseb()
}
}
if (x4341 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4342 = new Array[FixedPoint[Signed,B32,B0]](x4341.toInt)
val x4343 = System.arraycopy(x243,0.toInt,x4342,0.toInt,x4334.toInt)
val x4344 = x4342(x4333.toInt) = x244
val x4345 = __act.x4364_buf = x4342
x4345
}
def x4349elseb(): Unit = {
val x4347 = x243(x4333.toInt) = x244
x4347
}
if (x4336) {
x4349thenb()
} else { 
x4349elseb()
}
}
__act.x4364_size = __act.x4364_size + 1
}
__act.x4364_conditionals = __act.x4364_conditionals + 1
x239 = x239 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4364,rhs:activation_x4364): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4364,lhs:activation_x4364): Unit = {
__act.x4364_offset = lhs.x4364_offset+lhs.x4364_size
__act.x4364_conditionals = __act.x4364_conditionals+lhs.x4364_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4364): Unit = {
if (__act.x4364_offset > 0) {
val x245 = __act.x4364_offset + __act.x4364_size
val x243 = __act.x4364_buf
if (x245 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4359 = new Array[FixedPoint[Signed,B32,B0]](x245.toInt)
__act.x4364_data_set(resourceInfo,x4359,__act.x4364_conditionals)
} else {
__act.x4364_data_set(resourceInfo,__act.x4364_buf,__act.x4364_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4364): Unit = {
if (__act.x4364_data ne __act.x4364_buf) {
val x245 = __act.x4364_size
val x248 = __act.x4364_buf
val x243 = __act.x4364_data
val x246 = 0
val x247 = __act.x4364_offset
val x4361 = System.arraycopy(x248,x246.toInt,x243,x247.toInt,x245.toInt)
}
__act.x4364_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4364): Unit = {
var x243: Array[FixedPoint[Signed,B32,B0]] = __act.x4364_data
__act.x4364_data = null
val x245 = __act.x4364_conditionals
val x4351 = x243.length
val x4352 = x4351 > x245
val x4357 = {
def x4357thenb(): Unit = {
if (x245 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4353 = new Array[FixedPoint[Signed,B32,B0]](x245.toInt)
val x4354 = System.arraycopy(x243,0.toInt,x4353,0.toInt,x245.toInt)
val x4355 = x243 = x4353
x4355
}
if (x4352) {
x4357thenb()
}
}
__act.x4364 = x243
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x4364 = {
val act: activation_x4364 = new activation_x4364
act
}

}
x4364_closure.loopStart = 0
x4364_closure.loopSize = x4326
val alloc: activation_x4364 = x4364_closure.alloc(resourceInfo)
var x4364: activation_x4364 = null
if (resourceInfo.availableThreads <= 1) {
x4364 = x4364_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x4364] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x4364](x4364_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x4364_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x4364 = x4364_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x4364
}}

/**********/

