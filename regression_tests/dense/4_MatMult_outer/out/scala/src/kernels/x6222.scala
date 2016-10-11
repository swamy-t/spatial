package generated.scala
//activation record for fat loop
final class activation_x6222 {
var left_act: activation_x6222 = _
var x6222: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x6222_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x6222 {
}
object kernel_x6222 {
def apply(resourceInfo:generated.scala.ResourceInfo,x7:Int,x5434:Array[Array[FixedPoint[Signed,B32,B0]]],x6195:Array[Array[FixedPoint[Signed,B32,B0]]],x9:Int,x189:FixedPoint[Signed,B32,B0],x99:Int): activation_x6222 = {
val x6222_closure = new generated.scala.DeliteOpMultiLoop[activation_x6222] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x7
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6222 = {
val __act: activation_x6222 = new activation_x6222()
val x790 = (loopSize).asInstanceOf[Int]
if (x790 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5958 = new Array[Array[FixedPoint[Signed,B32,B0]]](x790.toInt)
__act.x6222_data = x5958
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6222,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6222]): activation_x6222 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6222 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6222 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6222): activation_x6222 = {
val act: activation_x6222 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6222,start:Long,end:Long): activation_x6222 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6222 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6222,x636:Int,isEmpty:Boolean): activation_x6222 = {
if (!isEmpty) {
process(resourceInfo,__act,x636)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6222,x636:Int): Unit = {
val x637 = {
FixedPoint[Signed,B32,B0](x636)
}
val x638 = {
x637.toInt
}
val x5836 = x5434(x638.toInt)
val x5837 = x5836.length
var x747: Int = x99
if (x747 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5921 = new Array[FixedPoint[Signed,B32,B0]](x747.toInt)
val x6219_data: Array[FixedPoint[Signed,B32,B0]] = x5921
var x6219_size: Int = 0
var x6219_conditionals: Int = 0
var x640: Int = 0
while (x640 < x99) {  // begin fat loop x6219
val x641 = {
FixedPoint[Signed,B32,B0](x640)
}
val x644 = {
x641.toInt
}
var x648: Int = x9
if (x648 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5840 = new Array[FixedPoint[Signed,B32,B0]](x648.toInt)
val x6213_data: Array[FixedPoint[Signed,B32,B0]] = x5840
var x6213_size: Int = 0
var x6213_conditionals: Int = 0
var x642: Int = 0
while (x642 < x9) {  // begin fat loop x6213
val x6211 = x6195(x642.toInt)
val x6212 = x6211(x644.toInt)
val x647 = x6212
val x646 = x6213_data
val x5844 = x646(x642.toInt) = x647
x642 = x642 + 1
} // end fat loop x6213
val x646 = x6213_data
val x6213 = x646
var x696: Int = x5837
if (x696 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5880 = new Array[FixedPoint[Signed,B32,B0]](x696.toInt)
val x6216_data: Array[FixedPoint[Signed,B32,B0]] = x5880
var x6216_size: Int = 0
var x6216_conditionals: Int = 0
var x690: Int = 0
while (x690 < x5837) {  // begin fat loop x6216
val x5877 = x5836(x690.toInt)
val x6214 = x6213(x690.toInt)
val x6215 = {
x5877 * x6214
}
val x695 = x6215
val x694 = x6216_data
val x5884 = x694(x690.toInt) = x695
x690 = x690 + 1
} // end fat loop x6216
val x694 = x6216_data
val x6216 = x694
val x6218_zero: FixedPoint[Signed,B32,B0] = x189
var x6218: FixedPoint[Signed,B32,B0] = x6218_zero
var x737: Int = 0
if (x5837 > 0) { // prerun fat loop x6218
val x6217 = x6216(x737.toInt)
x6218 = x6217
}
x737 = 1
while (x737 < x5837) {  // begin fat loop x6218
val x6217 = x6216(x737.toInt)
val x741 = x6218
val x742 = x6217
val x743 = {
x741 + x742
}
x6218 = x743
x737 = x737 + 1
} // end fat loop x6218
val x746 = x6218
val x745 = x6219_data
val x5925 = x745(x640.toInt) = x746
x640 = x640 + 1
} // end fat loop x6219
val x745 = x6219_data
val x6219 = x745
val x789 = x6219
val x788 = __act.x6222_data
val x5962 = x788(x636.toInt) = x789
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6222,rhs:activation_x6222): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6222,lhs:activation_x6222): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6222): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6222): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6222): Unit = {
var x788: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x6222_data
__act.x6222_data = null
__act.x6222 = x788
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6222 = {
val act: activation_x6222 = new activation_x6222
act
}

}
x6222_closure.loopStart = 0
x6222_closure.loopSize = x7
val alloc: activation_x6222 = x6222_closure.alloc(resourceInfo)
var x6222: activation_x6222 = null
if (resourceInfo.availableThreads <= 1) {
x6222 = x6222_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6222] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6222](x6222_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6222_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6222 = x6222_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6222
}}

/**********/

