package generated.scala
//activation record for fat loop
final class activation_x6224 {
var left_act: activation_x6224 = _
var x6224: Array[FixedPoint[Signed,B32,B0]] = _
var x6224_data: Array[FixedPoint[Signed,B32,B0]] = _
var x6224_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x6224_size: Int = _
var x6224_offset: Int = _
var x6224_conditionals: Int = _
def x6224_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x6224_data = xs
x6224_conditionals = cs
if (left_act ne null)
left_act.x6224_data_set(resourceInfo,xs,cs)
}

}
object activation_x6224 {
}
object kernel_x6224 {
def apply(resourceInfo:generated.scala.ResourceInfo,x7:Int,x6222:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x6224 = {
val x6224_closure = new generated.scala.DeliteOpMultiLoop[activation_x6224] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x7
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6224 = {
val __act: activation_x6224 = new activation_x6224()
// __act.x6224 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6224]): activation_x6224 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6224 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6224 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x6224 = act
while (j < localEnd) {
val rhsAct: activation_x6224 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224): activation_x6224 = {
val act: activation_x6224 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224,start:Long,end:Long): activation_x6224 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6224 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224,x831:Int,isEmpty:Boolean): activation_x6224 = {
val __act2: activation_x6224 = new activation_x6224()
val x839 = 0
if (x839 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5995 = new Array[FixedPoint[Signed,B32,B0]](x839.toInt)
__act2.x6224_buf = x5995
if (!isEmpty) {
val x6223 = x6222(x831.toInt)
val x834 = x6223
val x835 = x834.length
var x833: Int = 0
while (x833 < x835) { //flatMap loop
val x836 = x834(x833.toInt)
val x837 = __act2.x6224_buf
val x838 = x836
if (true) {
val x6001 = __act2.x6224_size
val x6002 = x837.length
val x6003 = x6002 - 1
val x6004 = x6001 > x6003
val x6017 = {
def x6017thenb(): Unit = {
val x6005 = x6002 < 16
val x6009 = {
def x6009thenb(): Int = {
16
}
def x6009elseb(): Int = {
val x6006 = x6002 * 2
val x6007 = x6006 < 0
val x6008 = {
def x6008thenb(): Int = {
2147483647
}
def x6008elseb(): Int = {
x6006
}
if (x6007) {
x6008thenb()
} else { 
x6008elseb()
}
}
x6008
}
if (x6005) {
x6009thenb()
} else { 
x6009elseb()
}
}
if (x6009 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x6010 = new Array[FixedPoint[Signed,B32,B0]](x6009.toInt)
val x6011 = System.arraycopy(x837,0.toInt,x6010,0.toInt,x6002.toInt)
val x6012 = x6010(x6001.toInt) = x838
val x6013 = __act2.x6224_buf = x6010
x6013
}
def x6017elseb(): Unit = {
val x6015 = x837(x6001.toInt) = x838
x6015
}
if (x6004) {
x6017thenb()
} else { 
x6017elseb()
}
}
__act2.x6224_size = __act2.x6224_size + 1
}
__act2.x6224_conditionals = __act2.x6224_conditionals + 1
x833 = x833 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224,x831:Int): Unit = {
val x6223 = x6222(x831.toInt)
val x834 = x6223
val x835 = x834.length
var x833: Int = 0
while (x833 < x835) { //flatMap loop
val x836 = x834(x833.toInt)
val x837 = __act.x6224_buf
val x838 = x836
if (true) {
val x6001 = __act.x6224_size
val x6002 = x837.length
val x6003 = x6002 - 1
val x6004 = x6001 > x6003
val x6017 = {
def x6017thenb(): Unit = {
val x6005 = x6002 < 16
val x6009 = {
def x6009thenb(): Int = {
16
}
def x6009elseb(): Int = {
val x6006 = x6002 * 2
val x6007 = x6006 < 0
val x6008 = {
def x6008thenb(): Int = {
2147483647
}
def x6008elseb(): Int = {
x6006
}
if (x6007) {
x6008thenb()
} else { 
x6008elseb()
}
}
x6008
}
if (x6005) {
x6009thenb()
} else { 
x6009elseb()
}
}
if (x6009 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x6010 = new Array[FixedPoint[Signed,B32,B0]](x6009.toInt)
val x6011 = System.arraycopy(x837,0.toInt,x6010,0.toInt,x6002.toInt)
val x6012 = x6010(x6001.toInt) = x838
val x6013 = __act.x6224_buf = x6010
x6013
}
def x6017elseb(): Unit = {
val x6015 = x837(x6001.toInt) = x838
x6015
}
if (x6004) {
x6017thenb()
} else { 
x6017elseb()
}
}
__act.x6224_size = __act.x6224_size + 1
}
__act.x6224_conditionals = __act.x6224_conditionals + 1
x833 = x833 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224,rhs:activation_x6224): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224,lhs:activation_x6224): Unit = {
__act.x6224_offset = lhs.x6224_offset+lhs.x6224_size
__act.x6224_conditionals = __act.x6224_conditionals+lhs.x6224_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224): Unit = {
if (__act.x6224_offset > 0) {
val x839 = __act.x6224_offset + __act.x6224_size
val x837 = __act.x6224_buf
if (x839 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x6027 = new Array[FixedPoint[Signed,B32,B0]](x839.toInt)
__act.x6224_data_set(resourceInfo,x6027,__act.x6224_conditionals)
} else {
__act.x6224_data_set(resourceInfo,__act.x6224_buf,__act.x6224_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224): Unit = {
if (__act.x6224_data ne __act.x6224_buf) {
val x839 = __act.x6224_size
val x842 = __act.x6224_buf
val x837 = __act.x6224_data
val x840 = 0
val x841 = __act.x6224_offset
val x6029 = System.arraycopy(x842,x840.toInt,x837,x841.toInt,x839.toInt)
}
__act.x6224_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6224): Unit = {
var x837: Array[FixedPoint[Signed,B32,B0]] = __act.x6224_data
__act.x6224_data = null
val x839 = __act.x6224_conditionals
val x6019 = x837.length
val x6020 = x6019 > x839
val x6025 = {
def x6025thenb(): Unit = {
if (x839 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x6021 = new Array[FixedPoint[Signed,B32,B0]](x839.toInt)
val x6022 = System.arraycopy(x837,0.toInt,x6021,0.toInt,x839.toInt)
val x6023 = x837 = x6021
x6023
}
if (x6020) {
x6025thenb()
}
}
__act.x6224 = x837
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6224 = {
val act: activation_x6224 = new activation_x6224
act
}

}
x6224_closure.loopStart = 0
x6224_closure.loopSize = x7
val alloc: activation_x6224 = x6224_closure.alloc(resourceInfo)
var x6224: activation_x6224 = null
if (resourceInfo.availableThreads <= 1) {
x6224 = x6224_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6224] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6224](x6224_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6224_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6224 = x6224_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6224
}}

/**********/

