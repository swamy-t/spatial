package generated.scala
//activation record for fat loop
final class activation_x1939 {
var left_act: activation_x1939 = _
var x1939: Array[FixedPoint[Signed,B32,B0]] = _
var x1939_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1939 {
}
object kernel_x1939 {
def apply(resourceInfo:generated.scala.ResourceInfo,x125:Int,x1813:Array[FixedPoint[Signed,B32,B0]],x2:Int,x268:Boolean,x1773:Array[FixedPoint[Signed,B32,B0]],x177:FixedPoint[Signed,B32,B0]): activation_x1939 = {
val x1939_closure = new generated.scala.DeliteOpMultiLoop[activation_x1939] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x125
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1939 = {
val __act: activation_x1939 = new activation_x1939()
val x283 = (loopSize).asInstanceOf[Int]
if (x283 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1903 = new Array[FixedPoint[Signed,B32,B0]](x283.toInt)
__act.x1939_data = x1903
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1939,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1939]): activation_x1939 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1939 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1939 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1939): activation_x1939 = {
val act: activation_x1939 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1939,start:Long,end:Long): activation_x1939 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1939 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1939,x220:Int,isEmpty:Boolean): activation_x1939 = {
if (!isEmpty) {
process(resourceInfo,__act,x220)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1939,x220:Int): Unit = {
val x221 = {
FixedPoint[Signed,B32,B0](x220)
}
var x227: Int = x2
if (x227 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1859 = new Array[Boolean](x227.toInt)
val x1895_data: Array[Boolean] = x1859
var x1895_size: Int = 0
var x1895_conditionals: Int = 0
var x222: Int = 0
while (x222 < x2) {  // begin fat loop x1895
val x1857 = x1813(x222.toInt)
val x1858 = {
x1857 == x221
}
val x226 = x1858
val x225 = x1895_data
val x1863 = x225(x222.toInt) = x226
x222 = x222 + 1
} // end fat loop x1895
val x225 = x1895_data
val x1895 = x225
val x1899_zero: Boolean = x268
var x1899: Boolean = x1899_zero
var x269: Int = 0
if (x2 > 0) { // prerun fat loop x1899
val x1896 = x1895(x269.toInt)
x1899 = x1896
}
x269 = 1
while (x269 < x2) {  // begin fat loop x1899
val x1896 = x1895(x269.toInt)
val x273 = x1899
val x274 = x1896
val x275 = {
x273 || x274
}
x1899 = x275
x269 = x269 + 1
} // end fat loop x1899
val x1900 = {
x1899
}
val x1902 = {
def x1902thenb(): FixedPoint[Signed,B32,B0] = {
val x278 = {
x221.toInt
}
val x1901 = x1773(x278.toInt)
x1901
}
def x1902elseb(): FixedPoint[Signed,B32,B0] = {
x177
}
if (x1900) {
x1902thenb()
} else { 
x1902elseb()
}
}
val x282 = x1902
val x281 = __act.x1939_data
val x1907 = x281(x220.toInt) = x282
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1939,rhs:activation_x1939): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1939,lhs:activation_x1939): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1939): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1939): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1939): Unit = {
var x281: Array[FixedPoint[Signed,B32,B0]] = __act.x1939_data
__act.x1939_data = null
__act.x1939 = x281
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1939 = {
val act: activation_x1939 = new activation_x1939
act
}

}
x1939_closure.loopStart = 0
x1939_closure.loopSize = x125
val alloc: activation_x1939 = x1939_closure.alloc(resourceInfo)
var x1939: activation_x1939 = null
if (resourceInfo.availableThreads <= 1) {
x1939 = x1939_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1939] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1939](x1939_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1939_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1939 = x1939_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1939
}}

/**********/

