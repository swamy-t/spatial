package generated.scala
//activation record for fat loop
final class activation_x6207 {
var left_act: activation_x6207 = _
var x6207: Array[FixedPoint[Signed,B32,B0]] = _
var x6207_data: Array[FixedPoint[Signed,B32,B0]] = _
var x6207_buf: Array[FixedPoint[Signed,B32,B0]] = _
var x6207_size: Int = _
var x6207_offset: Int = _
var x6207_conditionals: Int = _
def x6207_data_set(resourceInfo:generated.scala.ResourceInfo,xs:Array[FixedPoint[Signed,B32,B0]],cs:Int): Unit = {
x6207_data = xs
x6207_conditionals = cs
if (left_act ne null)
left_act.x6207_data_set(resourceInfo,xs,cs)
}

}
object activation_x6207 {
}
object kernel_x6207 {
def apply(resourceInfo:generated.scala.ResourceInfo,x7:Int,x6205:Array[Array[FixedPoint[Signed,B32,B0]]]): activation_x6207 = {
val x6207_closure = new generated.scala.DeliteOpMultiLoop[activation_x6207] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x7
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6207 = {
val __act: activation_x6207 = new activation_x6207()
// __act.x6207 stays null for now
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6207,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6207]): activation_x6207 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6207 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6207 = sync.get(localStart)
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync.getP(tid-1))
var j: Int = localStart+1
var currentAct: activation_x6207 = act
while (j < localEnd) {
val rhsAct: activation_x6207 = sync.get(j)
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

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6207): activation_x6207 = {
val act: activation_x6207 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
postProcInit(resourceInfo,act)
postProcess(resourceInfo,act)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6207,start:Long,end:Long): activation_x6207 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6207 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6207,x881:Int,isEmpty:Boolean): activation_x6207 = {
val __act2: activation_x6207 = new activation_x6207()
val x889 = 0
if (x889 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5996 = new Array[FixedPoint[Signed,B32,B0]](x889.toInt)
__act2.x6207_buf = x5996
if (!isEmpty) {
val x6206 = x6205(x881.toInt)
val x884 = x6206
val x885 = x884.length
var x883: Int = 0
while (x883 < x885) { //flatMap loop
val x886 = x884(x883.toInt)
val x887 = __act2.x6207_buf
val x888 = x886
if (true) {
val x6002 = __act2.x6207_size
val x6003 = x887.length
val x6004 = x6003 - 1
val x6005 = x6002 > x6004
val x6018 = {
def x6018thenb(): Unit = {
val x6006 = x6003 < 16
val x6010 = {
def x6010thenb(): Int = {
16
}
def x6010elseb(): Int = {
val x6007 = x6003 * 2
val x6008 = x6007 < 0
val x6009 = {
def x6009thenb(): Int = {
2147483647
}
def x6009elseb(): Int = {
x6007
}
if (x6008) {
x6009thenb()
} else { 
x6009elseb()
}
}
x6009
}
if (x6006) {
x6010thenb()
} else { 
x6010elseb()
}
}
if (x6010 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x6011 = new Array[FixedPoint[Signed,B32,B0]](x6010.toInt)
val x6012 = System.arraycopy(x887,0.toInt,x6011,0.toInt,x6003.toInt)
val x6013 = x6011(x6002.toInt) = x888
val x6014 = __act2.x6207_buf = x6011
x6014
}
def x6018elseb(): Unit = {
val x6016 = x887(x6002.toInt) = x888
x6016
}
if (x6005) {
x6018thenb()
} else { 
x6018elseb()
}
}
__act2.x6207_size = __act2.x6207_size + 1
}
__act2.x6207_conditionals = __act2.x6207_conditionals + 1
x883 = x883 + 1
}
}
__act2
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6207,x881:Int): Unit = {
val x6206 = x6205(x881.toInt)
val x884 = x6206
val x885 = x884.length
var x883: Int = 0
while (x883 < x885) { //flatMap loop
val x886 = x884(x883.toInt)
val x887 = __act.x6207_buf
val x888 = x886
if (true) {
val x6002 = __act.x6207_size
val x6003 = x887.length
val x6004 = x6003 - 1
val x6005 = x6002 > x6004
val x6018 = {
def x6018thenb(): Unit = {
val x6006 = x6003 < 16
val x6010 = {
def x6010thenb(): Int = {
16
}
def x6010elseb(): Int = {
val x6007 = x6003 * 2
val x6008 = x6007 < 0
val x6009 = {
def x6009thenb(): Int = {
2147483647
}
def x6009elseb(): Int = {
x6007
}
if (x6008) {
x6009thenb()
} else { 
x6009elseb()
}
}
x6009
}
if (x6006) {
x6010thenb()
} else { 
x6010elseb()
}
}
if (x6010 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x6011 = new Array[FixedPoint[Signed,B32,B0]](x6010.toInt)
val x6012 = System.arraycopy(x887,0.toInt,x6011,0.toInt,x6003.toInt)
val x6013 = x6011(x6002.toInt) = x888
val x6014 = __act.x6207_buf = x6011
x6014
}
def x6018elseb(): Unit = {
val x6016 = x887(x6002.toInt) = x888
x6016
}
if (x6005) {
x6018thenb()
} else { 
x6018elseb()
}
}
__act.x6207_size = __act.x6207_size + 1
}
__act.x6207_conditionals = __act.x6207_conditionals + 1
x883 = x883 + 1
}
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6207,rhs:activation_x6207): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6207,lhs:activation_x6207): Unit = {
__act.x6207_offset = lhs.x6207_offset+lhs.x6207_size
__act.x6207_conditionals = __act.x6207_conditionals+lhs.x6207_conditionals
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6207): Unit = {
if (__act.x6207_offset > 0) {
val x889 = __act.x6207_offset + __act.x6207_size
val x887 = __act.x6207_buf
if (x889 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x6028 = new Array[FixedPoint[Signed,B32,B0]](x889.toInt)
__act.x6207_data_set(resourceInfo,x6028,__act.x6207_conditionals)
} else {
__act.x6207_data_set(resourceInfo,__act.x6207_buf,__act.x6207_conditionals)
}
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6207): Unit = {
if (__act.x6207_data ne __act.x6207_buf) {
val x889 = __act.x6207_size
val x892 = __act.x6207_buf
val x887 = __act.x6207_data
val x890 = 0
val x891 = __act.x6207_offset
val x6030 = System.arraycopy(x892,x890.toInt,x887,x891.toInt,x889.toInt)
}
__act.x6207_buf = null
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6207): Unit = {
var x887: Array[FixedPoint[Signed,B32,B0]] = __act.x6207_data
__act.x6207_data = null
val x889 = __act.x6207_conditionals
val x6020 = x887.length
val x6021 = x6020 > x889
val x6026 = {
def x6026thenb(): Unit = {
if (x889 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x6022 = new Array[FixedPoint[Signed,B32,B0]](x889.toInt)
val x6023 = System.arraycopy(x887,0.toInt,x6022,0.toInt,x889.toInt)
val x6024 = x887 = x6022
x6024
}
if (x6021) {
x6026thenb()
}
}
__act.x6207 = x887
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6207 = {
val act: activation_x6207 = new activation_x6207
act
}

}
x6207_closure.loopStart = 0
x6207_closure.loopSize = x7
val alloc: activation_x6207 = x6207_closure.alloc(resourceInfo)
var x6207: activation_x6207 = null
if (resourceInfo.availableThreads <= 1) {
x6207 = x6207_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6207] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6207](x6207_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6207_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6207 = x6207_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6207
}}

/**********/

