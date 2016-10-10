package generated.scala
//activation record for fat loop
final class activation_x4693 {
var left_act: activation_x4693 = _
var x4693: Array[FloatPoint[B24,B8]] = _
var x4693_data: Array[FloatPoint[B24,B8]] = _
}
object activation_x4693 {
}
object kernel_x4693 {
def apply(resourceInfo:generated.scala.ResourceInfo,x14:Int,x4113:Array[FloatPoint[B24,B8]],x4152:Array[FloatPoint[B24,B8]],x4269:Array[FloatPoint[B24,B8]],x4191:Array[FloatPoint[B24,B8]],x4230:Array[FloatPoint[B24,B8]],x412:FloatPoint[B24,B8],x423:FloatPoint[B24,B8],x426:FloatPoint[B24,B8],x429:FloatPoint[B24,B8],x428:FloatPoint[B24,B8],x437:FloatPoint[B24,B8],x445:FloatPoint[B24,B8],x443:FloatPoint[B24,B8],x439:FloatPoint[B24,B8],x441:FloatPoint[B24,B8],x307:FloatPoint[B24,B8],x4074:Array[FixedPoint[Unsign,B32,B0]],x305:FixedPoint[Unsign,B32,B0]): activation_x4693 = {
val x4693_closure = new generated.scala.DeliteOpMultiLoop[activation_x4693] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x14
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x4693 = {
val __act: activation_x4693 = new activation_x4693()
val x614 = (loopSize).asInstanceOf[Int]
if (x614 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4657 = new Array[FloatPoint[B24,B8]](x614.toInt)
__act.x4693_data = x4657
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4693,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x4693]): activation_x4693 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x4693 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x4693 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4693): activation_x4693 = {
val act: activation_x4693 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4693,start:Long,end:Long): activation_x4693 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x4693 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4693,x523:Int,isEmpty:Boolean): activation_x4693 = {
if (!isEmpty) {
process(resourceInfo,__act,x523)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4693,x523:Int): Unit = {
val x524 = {
FixedPoint[Signed,B32,B0](x523)
}
val x525 = {
x524.toInt
}
val x4571 = x4113(x525.toInt)
val x4572 = x4152(x525.toInt)
val x4573 = {
x4571 / x4572
}
val x4574 = {
FloatPoint.log(x4573)
}
val x4575 = x4269(x525.toInt)
val x4576 = x4191(x525.toInt)
val x4577 = x4230(x525.toInt)
val x4578 = {
x4577 * x4577
}
val x4579 = {
x4578 * x412
}
val x4580 = {
x4576 + x4579
}
val x4581 = {
x4580 * x4575
}
val x4582 = {
x4581 + x4574
}
val x4583 = {
FloatPoint.sqrt(x4575)
}
val x4584 = {
x4577 * x4583
}
val x4585 = {
x4584 * x4584
}
val x4586 = {
x4582 / x4585
}
val x4587 = {
FloatPoint.abs(x4586)
}
val x4588 = {
x4587 * x4587
}
val x4589 = {
x4588 * x423
}
val x4590 = {
FloatPoint.exp(x4589)
}
val x4591 = {
x4590 * x426
}
val x4592 = {
x4587 * x429
}
val x4593 = {
x4592 + x428
}
val x4594 = {
x428 / x4593
}
val x4595 = {
x4594 * x437
}
val x4596 = {
x4594 * x4594
}
val x4597 = {
x4596 * x4594
}
val x4598 = {
x4597 * x4594
}
val x4599 = {
x4598 * x4594
}
val x4600 = {
x4599 * x445
}
val x4601 = {
x4598 * x443
}
val x4602 = {
x4596 * x439
}
val x4603 = {
x4597 * x441
}
val x4604 = {
x4602 + x4603
}
val x4605 = {
x4604 + x4601
}
val x4606 = {
x4605 + x4600
}
val x4607 = {
x4606 + x4595
}
val x4608 = {
x4607 * x4591
}
val x4609 = {
-x4608
}
val x4610 = {
x4609 + x428
}
val x4611 = {
x4586 < x307
}
val x4612 = {
if (x4611) x4608 else x4610
}
val x4613 = {
x4571 * x4612
}
val x4614 = {
x4586 - x4584
}
val x4615 = {
FloatPoint.abs(x4614)
}
val x4616 = {
x4615 * x4615
}
val x4617 = {
x4616 * x423
}
val x4618 = {
FloatPoint.exp(x4617)
}
val x4619 = {
x4618 * x426
}
val x4620 = {
x4615 * x429
}
val x4621 = {
x4620 + x428
}
val x4622 = {
x428 / x4621
}
val x4623 = {
x4622 * x437
}
val x4624 = {
x4622 * x4622
}
val x4625 = {
x4624 * x4622
}
val x4626 = {
x4625 * x4622
}
val x4627 = {
x4626 * x4622
}
val x4628 = {
x4627 * x445
}
val x4629 = {
x4626 * x443
}
val x4630 = {
x4624 * x439
}
val x4631 = {
x4625 * x441
}
val x4632 = {
x4630 + x4631
}
val x4633 = {
x4632 + x4629
}
val x4634 = {
x4633 + x4628
}
val x4635 = {
x4634 + x4623
}
val x4636 = {
x4635 * x4619
}
val x4637 = {
-x4636
}
val x4638 = {
x4637 + x428
}
val x4639 = {
x4614 < x307
}
val x4640 = {
if (x4639) x4636 else x4638
}
val x4641 = {
-x4576
}
val x4642 = {
x4641 * x4575
}
val x4643 = {
FloatPoint.exp(x4642)
}
val x4644 = {
x4572 * x4643
}
val x4645 = {
x4644 * x4640
}
val x4646 = {
x4613 - x4645
}
val x4647 = {
-x4640
}
val x4648 = {
x4647 + x428
}
val x4649 = {
x4644 * x4648
}
val x4650 = {
-x4612
}
val x4651 = {
x4650 + x428
}
val x4652 = {
x4571 * x4651
}
val x4653 = {
x4649 - x4652
}
val x4654 = x4074(x525.toInt)
val x4655 = {
x4654 == x305
}
val x4656 = {
if (x4655) x4653 else x4646
}
val x613 = x4656
val x612 = __act.x4693_data
val x4661 = x612(x523.toInt) = x613
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4693,rhs:activation_x4693): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4693,lhs:activation_x4693): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4693): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4693): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x4693): Unit = {
var x612: Array[FloatPoint[B24,B8]] = __act.x4693_data
__act.x4693_data = null
__act.x4693 = x612
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x4693 = {
val act: activation_x4693 = new activation_x4693
act
}

}
x4693_closure.loopStart = 0
x4693_closure.loopSize = x14
val alloc: activation_x4693 = x4693_closure.alloc(resourceInfo)
var x4693: activation_x4693 = null
if (resourceInfo.availableThreads <= 1) {
x4693 = x4693_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x4693] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x4693](x4693_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x4693_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x4693 = x4693_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x4693
}}

/**********/

