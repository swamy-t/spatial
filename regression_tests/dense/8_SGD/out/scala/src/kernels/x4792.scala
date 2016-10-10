package generated.scala
object kernel_x4792 {
def apply(resourceInfo:generated.scala.ResourceInfo,x286:FixedPoint[Signed,B32,B0],x4:FixedPoint[Signed,B32,B0],x303:FixedPoint[Signed,B32,B0],x4279:Array[Array[FixedPoint[Signed,B32,B0]]],x4493:Array[FixedPoint[Signed,B32,B0]],x4326:Int,x4533:Array[FixedPoint[Signed,B32,B0]],x4318:Array[FixedPoint[Signed,B32,B0]],x6:Int,x2:FixedPoint[Signed,B32,B0],x5:FixedPoint[Signed,B32,B0]): Unit = {
val x4792 = {
var i = x286
while (i < x4) {
{ 
val x472 = i
()
var x538: Int = x4326
if (x538 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4584 = new Array[FixedPoint[Signed,B32,B0]](x538.toInt)
val x4620_data: Array[FixedPoint[Signed,B32,B0]] = x4584
var x4620_size: Int = 0
var x4620_conditionals: Int = 0
var x473: Int = 0
while (x473 < x4326) {  // begin fat loop x4620
val x4534 = x4279(x473.toInt)
val x4535 = x4534.length
var x484: Int = x4535
if (x484 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4540 = new Array[FixedPoint[Signed,B32,B0]](x484.toInt)
val x4576_data: Array[FixedPoint[Signed,B32,B0]] = x4540
var x4576_size: Int = 0
var x4576_conditionals: Int = 0
var x477: Int = 0
while (x477 < x4535) {  // begin fat loop x4576
val x4536 = x4493(x477.toInt)
val x4537 = x4534(x477.toInt)
val x4538 = {
x4537 * x4536
}
val x483 = x4538
val x482 = x4576_data
val x4544 = x482(x477.toInt) = x483
x477 = x477 + 1
} // end fat loop x4576
val x482 = x4576_data
val x4576 = x482
val x4577 = x4576.length
val x4582_zero: FixedPoint[Signed,B32,B0] = x286
var x4582: FixedPoint[Signed,B32,B0] = x4582_zero
var x526: Int = 0
if (x4577 > 0) { // prerun fat loop x4582
val x4578 = x4576(x526.toInt)
x4582 = x4578
}
x526 = 1
while (x526 < x4577) {  // begin fat loop x4582
val x4578 = x4576(x526.toInt)
val x531 = x4582
val x532 = x4578
val x533 = {
x531 + x532
}
x4582 = x533
x526 = x526 + 1
} // end fat loop x4582
val x537 = x4582
val x536 = x4620_data
val x4588 = x536(x473.toInt) = x537
x473 = x473 + 1
} // end fat loop x4620
val x536 = x4620_data
val x4620 = x536
val x4621 = x4620.length
var x586: Int = x4621
if (x586 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4625 = new Array[FixedPoint[Signed,B32,B0]](x586.toInt)
val x4661_data: Array[FixedPoint[Signed,B32,B0]] = x4625
var x4661_size: Int = 0
var x4661_conditionals: Int = 0
var x580: Int = 0
while (x580 < x4621) {  // begin fat loop x4661
val x4622 = x4620(x580.toInt)
val x4623 = x4318(x580.toInt)
val x4624 = {
x4622 - x4623
}
val x585 = x4624
val x584 = x4661_data
val x4629 = x584(x580.toInt) = x585
x580 = x580 + 1
} // end fat loop x4661
val x584 = x4661_data
val x4661 = x584
var x733: Int = x6
if (x733 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4747 = new Array[FixedPoint[Signed,B32,B0]](x733.toInt)
val x4783_data: Array[FixedPoint[Signed,B32,B0]] = x4747
var x4783_size: Int = 0
var x4783_conditionals: Int = 0
var x627: Int = 0
while (x627 < x6) {  // begin fat loop x4783
val x4662 = x4533(x627.toInt)
val x4663 = {
x4662.toInt
}
var x635: Int = x4326
if (x635 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4666 = new Array[FixedPoint[Signed,B32,B0]](x635.toInt)
val x4702_data: Array[FixedPoint[Signed,B32,B0]] = x4666
var x4702_size: Int = 0
var x4702_conditionals: Int = 0
var x629: Int = 0
while (x629 < x4326) {  // begin fat loop x4702
val x4664 = x4279(x629.toInt)
val x4665 = x4664(x4663.toInt)
val x634 = x4665
val x633 = x4702_data
val x4670 = x633(x629.toInt) = x634
x629 = x629 + 1
} // end fat loop x4702
val x633 = x4702_data
val x4702 = x633
var x682: Int = x4326
if (x682 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x4706 = new Array[FixedPoint[Signed,B32,B0]](x682.toInt)
val x4742_data: Array[FixedPoint[Signed,B32,B0]] = x4706
var x4742_size: Int = 0
var x4742_conditionals: Int = 0
var x676: Int = 0
while (x676 < x4326) {  // begin fat loop x4742
val x4703 = x4702(x676.toInt)
val x4704 = x4661(x676.toInt)
val x4705 = {
x4703 * x4704
}
val x681 = x4705
val x680 = x4742_data
val x4710 = x680(x676.toInt) = x681
x676 = x676 + 1
} // end fat loop x4742
val x680 = x4742_data
val x4742 = x680
val x4746_zero: FixedPoint[Signed,B32,B0] = x286
var x4746: FixedPoint[Signed,B32,B0] = x4746_zero
var x723: Int = 0
if (x4326 > 0) { // prerun fat loop x4746
val x4743 = x4742(x723.toInt)
x4746 = x4743
}
x723 = 1
while (x723 < x4326) {  // begin fat loop x4746
val x4743 = x4742(x723.toInt)
val x727 = x4746
val x728 = x4743
val x729 = {
x727 + x728
}
x4746 = x729
x723 = x723 + 1
} // end fat loop x4746
val x732 = x4746
val x731 = x4783_data
val x4751 = x731(x627.toInt) = x732
x627 = x627 + 1
} // end fat loop x4783
val x731 = x4783_data
val x4783 = x731
val x4790 = {
var i = x286
while (i < x5) {
{ 
val x774 = i
()
val x775 = {
x774.toInt
}
val x4784 = x4493(x775.toInt)
val x4785 = x4783(x775.toInt)
val x4786 = {
x4785 * x2
}
val x4787 = {
x4786 + x4784
}
val x4788 = x4493(x775.toInt) = x4787
()
 }
 
i += x303
}
}
()
 }
 
i += x303
}
}

x4792
}}

/**********/

