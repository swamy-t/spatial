package generated.scala
//activation record for fat loop
final class activation_x6205 {
var left_act: activation_x6205 = _
var x6205: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x6205_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x6205 {
}
object kernel_x6205 {
def apply(resourceInfo:generated.scala.ResourceInfo,x7:Int,x5413:Array[Array[FixedPoint[Signed,B32,B0]]],x6178:Array[Array[FixedPoint[Signed,B32,B0]]],x9:Int,x189:FixedPoint[Signed,B32,B0],x99:Int): activation_x6205 = {
val x6205_closure = new generated.scala.DeliteOpMultiLoop[activation_x6205] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x7
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x6205 = {
val __act: activation_x6205 = new activation_x6205()
val x840 = (loopSize).asInstanceOf[Int]
if (x840 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5959 = new Array[Array[FixedPoint[Signed,B32,B0]]](x840.toInt)
__act.x6205_data = x5959
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6205,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x6205]): activation_x6205 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x6205 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x6205 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6205): activation_x6205 = {
val act: activation_x6205 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6205,start:Long,end:Long): activation_x6205 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x6205 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6205,x686:Int,isEmpty:Boolean): activation_x6205 = {
if (!isEmpty) {
process(resourceInfo,__act,x686)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6205,x686:Int): Unit = {
val x687 = {
FixedPoint[Signed,B32,B0](x686)
}
val x688 = {
x687.toInt
}
val x5837 = x5413(x688.toInt)
val x5838 = x5837.length
var x797: Int = x99
if (x797 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5922 = new Array[FixedPoint[Signed,B32,B0]](x797.toInt)
val x6202_data: Array[FixedPoint[Signed,B32,B0]] = x5922
var x6202_size: Int = 0
var x6202_conditionals: Int = 0
var x690: Int = 0
while (x690 < x99) {  // begin fat loop x6202
val x691 = {
FixedPoint[Signed,B32,B0](x690)
}
val x694 = {
x691.toInt
}
var x698: Int = x9
if (x698 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5841 = new Array[FixedPoint[Signed,B32,B0]](x698.toInt)
val x6196_data: Array[FixedPoint[Signed,B32,B0]] = x5841
var x6196_size: Int = 0
var x6196_conditionals: Int = 0
var x692: Int = 0
while (x692 < x9) {  // begin fat loop x6196
val x6194 = x6178(x692.toInt)
val x6195 = x6194(x694.toInt)
val x697 = x6195
val x696 = x6196_data
val x5845 = x696(x692.toInt) = x697
x692 = x692 + 1
} // end fat loop x6196
val x696 = x6196_data
val x6196 = x696
var x746: Int = x5838
if (x746 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5881 = new Array[FixedPoint[Signed,B32,B0]](x746.toInt)
val x6199_data: Array[FixedPoint[Signed,B32,B0]] = x5881
var x6199_size: Int = 0
var x6199_conditionals: Int = 0
var x740: Int = 0
while (x740 < x5838) {  // begin fat loop x6199
val x5878 = x5837(x740.toInt)
val x6197 = x6196(x740.toInt)
val x6198 = {
x5878 * x6197
}
val x745 = x6198
val x744 = x6199_data
val x5885 = x744(x740.toInt) = x745
x740 = x740 + 1
} // end fat loop x6199
val x744 = x6199_data
val x6199 = x744
val x6201_zero: FixedPoint[Signed,B32,B0] = x189
var x6201: FixedPoint[Signed,B32,B0] = x6201_zero
var x787: Int = 0
if (x5838 > 0) { // prerun fat loop x6201
val x6200 = x6199(x787.toInt)
x6201 = x6200
}
x787 = 1
while (x787 < x5838) {  // begin fat loop x6201
val x6200 = x6199(x787.toInt)
val x791 = x6201
val x792 = x6200
val x793 = {
x791 + x792
}
x6201 = x793
x787 = x787 + 1
} // end fat loop x6201
val x796 = x6201
val x795 = x6202_data
val x5926 = x795(x690.toInt) = x796
x690 = x690 + 1
} // end fat loop x6202
val x795 = x6202_data
val x6202 = x795
val x839 = x6202
val x838 = __act.x6205_data
val x5963 = x838(x686.toInt) = x839
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6205,rhs:activation_x6205): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6205,lhs:activation_x6205): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6205): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6205): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x6205): Unit = {
var x838: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x6205_data
__act.x6205_data = null
__act.x6205 = x838
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x6205 = {
val act: activation_x6205 = new activation_x6205
act
}

}
x6205_closure.loopStart = 0
x6205_closure.loopSize = x7
val alloc: activation_x6205 = x6205_closure.alloc(resourceInfo)
var x6205: activation_x6205 = null
if (resourceInfo.availableThreads <= 1) {
x6205 = x6205_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x6205] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x6205](x6205_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x6205_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x6205 = x6205_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x6205
}}

/**********/

