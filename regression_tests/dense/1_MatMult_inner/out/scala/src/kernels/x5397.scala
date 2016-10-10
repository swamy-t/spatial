package generated.scala
//activation record for fat loop
final class activation_x5397 {
var left_act: activation_x5397 = _
var x5397: Array[Array[FixedPoint[Signed,B32,B0]]] = _
var x5397_data: Array[Array[FixedPoint[Signed,B32,B0]]] = _
}
object activation_x5397 {
}
object kernel_x5397 {
def apply(resourceInfo:generated.scala.ResourceInfo,x7:Int,x4666:Array[Array[FixedPoint[Signed,B32,B0]]],x5380:Array[Array[FixedPoint[Signed,B32,B0]]],x9:Int,x285:FixedPoint[Signed,B32,B0],x99:Int): activation_x5397 = {
val x5397_closure = new generated.scala.DeliteOpMultiLoop[activation_x5397] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x7
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x5397 = {
val __act: activation_x5397 = new activation_x5397()
val x623 = (loopSize).asInstanceOf[Int]
if (x623 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5159 = new Array[Array[FixedPoint[Signed,B32,B0]]](x623.toInt)
__act.x5397_data = x5159
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5397,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x5397]): activation_x5397 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x5397 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x5397 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5397): activation_x5397 = {
val act: activation_x5397 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5397,start:Long,end:Long): activation_x5397 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x5397 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5397,x469:Int,isEmpty:Boolean): activation_x5397 = {
if (!isEmpty) {
process(resourceInfo,__act,x469)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5397,x469:Int): Unit = {
val x470 = {
FixedPoint[Signed,B32,B0](x469)
}
val x471 = {
x470.toInt
}
val x5037 = x4666(x471.toInt)
val x5038 = x5037.length
var x580: Int = x99
if (x580 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5122 = new Array[FixedPoint[Signed,B32,B0]](x580.toInt)
val x5394_data: Array[FixedPoint[Signed,B32,B0]] = x5122
var x5394_size: Int = 0
var x5394_conditionals: Int = 0
var x473: Int = 0
while (x473 < x99) {  // begin fat loop x5394
val x474 = {
FixedPoint[Signed,B32,B0](x473)
}
val x477 = {
x474.toInt
}
var x481: Int = x9
if (x481 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5041 = new Array[FixedPoint[Signed,B32,B0]](x481.toInt)
val x5388_data: Array[FixedPoint[Signed,B32,B0]] = x5041
var x5388_size: Int = 0
var x5388_conditionals: Int = 0
var x475: Int = 0
while (x475 < x9) {  // begin fat loop x5388
val x5386 = x5380(x475.toInt)
val x5387 = x5386(x477.toInt)
val x480 = x5387
val x479 = x5388_data
val x5045 = x479(x475.toInt) = x480
x475 = x475 + 1
} // end fat loop x5388
val x479 = x5388_data
val x5388 = x479
var x529: Int = x5038
if (x529 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x5081 = new Array[FixedPoint[Signed,B32,B0]](x529.toInt)
val x5391_data: Array[FixedPoint[Signed,B32,B0]] = x5081
var x5391_size: Int = 0
var x5391_conditionals: Int = 0
var x523: Int = 0
while (x523 < x5038) {  // begin fat loop x5391
val x5078 = x5037(x523.toInt)
val x5389 = x5388(x523.toInt)
val x5390 = {
x5078 * x5389
}
val x528 = x5390
val x527 = x5391_data
val x5085 = x527(x523.toInt) = x528
x523 = x523 + 1
} // end fat loop x5391
val x527 = x5391_data
val x5391 = x527
val x5393_zero: FixedPoint[Signed,B32,B0] = x285
var x5393: FixedPoint[Signed,B32,B0] = x5393_zero
var x570: Int = 0
if (x5038 > 0) { // prerun fat loop x5393
val x5392 = x5391(x570.toInt)
x5393 = x5392
}
x570 = 1
while (x570 < x5038) {  // begin fat loop x5393
val x5392 = x5391(x570.toInt)
val x574 = x5393
val x575 = x5392
val x576 = {
x574 + x575
}
x5393 = x576
x570 = x570 + 1
} // end fat loop x5393
val x579 = x5393
val x578 = x5394_data
val x5126 = x578(x473.toInt) = x579
x473 = x473 + 1
} // end fat loop x5394
val x578 = x5394_data
val x5394 = x578
val x622 = x5394
val x621 = __act.x5397_data
val x5163 = x621(x469.toInt) = x622
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5397,rhs:activation_x5397): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5397,lhs:activation_x5397): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5397): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5397): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x5397): Unit = {
var x621: Array[Array[FixedPoint[Signed,B32,B0]]] = __act.x5397_data
__act.x5397_data = null
__act.x5397 = x621
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x5397 = {
val act: activation_x5397 = new activation_x5397
act
}

}
x5397_closure.loopStart = 0
x5397_closure.loopSize = x7
val alloc: activation_x5397 = x5397_closure.alloc(resourceInfo)
var x5397: activation_x5397 = null
if (resourceInfo.availableThreads <= 1) {
x5397 = x5397_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x5397] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x5397](x5397_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x5397_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x5397 = x5397_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x5397
}}

/**********/

