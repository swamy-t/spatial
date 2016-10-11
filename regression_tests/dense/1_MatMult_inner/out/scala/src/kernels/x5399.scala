package generated.scala
//activation record for fat loop
final class activation_x5399 {
var left_act: activation_x5399 = _
var x5399: Array[FixedPoint[Signed,B32,B0]] = _
var x5399_data: Array[FixedPoint[Signed,B32,B0]] = _
var x5399_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x5399_size: Int = _
var x5399_offset: Int = _
var x5399_conditionals: Int = _
def x5399_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x5399_data = xs
x5399_conditionals = cs
if (left_act ne null)
left_act.x5399_data_set(resourceInfo,xs,cs)
}

}
object activation_x5399 {
}
object kernel_x5399 {
def apply(resourceInfo:generated.scala.ResourceInfo,x7:Int,x5397:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x5399 = {
val x5399_closure = new generated.scala.DeliteOpMultiLoop[activation_x5399] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x7
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5399 = {
val __act: activation_x5399 = new activation_x5399()
// __act.x5399 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5399,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5399]): activation_x5399 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5399 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5399 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x5399 = act
while (j < localEnd) {
val rhsAct: activation_x5399 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5399): activation_x5399 = {
val act: activation_x5399 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5399,start:Long,end:Long): activation_x5399 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5399 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5399,x664:Int,isEmpty:Boolean): activation_x5399 = {
val __act2: activation_x5399 = new activation_x5399()
val x672 = 0
if (x672 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5196 = new Array[FixedPoint[Signed,B32,B0]](x672.toInt)
__act2.x5399_buf = x5196
if (!isEmpty) {
val x5398 = x5397(x664.toInt)
val x667 = x5398
val x668 = x667.length
var x666: Int = 0
while (x666 < x668) { //flatMap loop
val x669 = x667(x666.toInt)
val x670 = __act2.x5399_buf
val x671 = x669
if (true) {
val x5202 = __act2.x5399_size
val x5203 = x670.length
val x5204 = x5203 - 1
val x5205 = x5202 > x5204
val x5218 = {
def x5218thenb(): Unit = {
val x5206 = x5203 < 16
val x5210 = {
def x5210thenb(): Int = {
16
}
def x5210elseb(): Int = {
val x5207 = x5203 * 2
val x5208 = x5207 < 0
val x5209 = {
def x5209thenb(): Int = {
2147483647
}
def x5209elseb(): Int = {
x5207
}
if (x5208) {
x5209thenb()
} else { 
x5209elseb()
}
}
x5209
}
if (x5206) {
x5210thenb()
} else { 
x5210elseb()
}
}
if (x5210 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5211 = new Array[FixedPoint[Signed,B32,B0]](x5210.toInt)
val x5212 = System.arraycopy(x670,0.toInt,x5211,0.toInt,x5203.toInt)
val x5213 = x5211(x5202.toInt) = x671
val x5214 = __act2.x5399_buf = x5211
x5214
}
def x5218elseb(): Unit = {
val x5216 = x670(x5202.toInt) = x671
x5216
}
if (x5205) {
x5218thenb()
} else { 
x5218elseb()
}
}
__act2.x5399_size = __act2.x5399_size + 1
}
__act2.x5399_conditionals = __act2.x5399_conditionals + 1
x666 = x666 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5399,x664:Int): Unit = {
val x5398 = x5397(x664.toInt)
val x667 = x5398
val x668 = x667.length
var x666: Int = 0
while (x666 < x668) { //flatMap loop
val x669 = x667(x666.toInt)
val x670 = __act.x5399_buf
val x671 = x669
if (true) {
val x5202 = __act.x5399_size
val x5203 = x670.length
val x5204 = x5203 - 1
val x5205 = x5202 > x5204
val x5218 = {
def x5218thenb(): Unit = {
val x5206 = x5203 < 16
val x5210 = {
def x5210thenb(): Int = {
16
}
def x5210elseb(): Int = {
val x5207 = x5203 * 2
val x5208 = x5207 < 0
val x5209 = {
def x5209thenb(): Int = {
2147483647
}
def x5209elseb(): Int = {
x5207
}
if (x5208) {
x5209thenb()
} else { 
x5209elseb()
}
}
x5209
}
if (x5206) {
x5210thenb()
} else { 
x5210elseb()
}
}
if (x5210 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5211 = new Array[FixedPoint[Signed,B32,B0]](x5210.toInt)
val x5212 = System.arraycopy(x670,0.toInt,x5211,0.toInt,x5203.toInt)
val x5213 = x5211(x5202.toInt) = x671
val x5214 = __act.x5399_buf = x5211
x5214
}
def x5218elseb(): Unit = {
val x5216 = x670(x5202.toInt) = x671
x5216
}
if (x5205) {
x5218thenb()
} else { 
x5218elseb()
}
}
__act.x5399_size = __act.x5399_size + 1
}
__act.x5399_conditionals = __act.x5399_conditionals + 1
x666 = x666 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5399,rhs:activation_x5399): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5399,lhs:activation_x5399): Unit = {
__act.x5399_offset = lhs.x5399_offset+lhs.x5399_size
__act.x5399_conditionals = __act.x5399_conditionals+lhs.x5399_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5399): Unit = {
if (__act.x5399_offset > 0) {
val x672 = __act.x5399_offset + __act.x5399_size
val x670 = __act.x5399_buf
if (x672 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5228 = new Array[FixedPoint[Signed,B32,B0]](x672.toInt)
__act.x5399_data_set(resourceInfo,x5228,__act.x5399_conditionals)
} else {
__act.x5399_data_set(resourceInfo,__act.x5399_buf,__act.x5399_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5399): Unit = {
if (__act.x5399_data ne __act.x5399_buf) {
val x672 = __act.x5399_size
val x675 = __act.x5399_buf
val x670 = __act.x5399_data
val x673 = 0
val x674 = __act.x5399_offset
val x5230 = System.arraycopy(x675,x673.toInt,x670,x674.toInt,x672.toInt)
}
__act.x5399_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5399): Unit = {
var x670: Array[FixedPoint[Signed,B32,B0]] = __act.x5399_data
__act.x5399_data = null
val x672 = __act.x5399_conditionals
val x5220 = x670.length
val x5221 = x5220 > x672
val x5226 = {
def x5226thenb(): Unit = {
if (x672 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5222 = new Array[FixedPoint[Signed,B32,B0]](x672.toInt)
val x5223 = System.arraycopy(x670,0.toInt,x5222,0.toInt,x672.toInt)
val x5224 = x670 = x5222
x5224
}
if (x5221) {
x5226thenb()
}
}
__act.x5399 = x670
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5399 = {
val act: activation_x5399 = new activation_x5399
act
}

}
x5399_closure.loopStart = 0
x5399_closure.loopSize = x7
val alloc: activation_x5399 = x5399_closure.alloc(resourceInfo)
var x5399: activation_x5399 = null
if (resourceInfo.availableThreads <= 1) {
x5399 = x5399_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5399] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5399](x5399_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5399_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5399 = x5399_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5399
}}

/**********/

