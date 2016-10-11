package generated.scala
object kernel_x821 {
def apply(resourceInfo:generated.scala.ResourceInfo,x50:FixedPoint[Signed,B32,B0],x720:Array[FixedPoint[Signed,B32,B0]],x724:Array[FixedPoint[Signed,B32,B0]],x721:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x821 = {
{ 
val x819 = {
{ 
val x763 = {
Array(x50)
}
val x764 = {
x720.apply(0)
}
val x488 = {
FixedPoint[Signed,B32,B0](96.toString)
}
val x765 = x50 until x764 by x488 par 1
val x766 = Array(x765)
val x63 = {
FixedPoint[Signed,B32,B0](1.toString)
}
val x767 = x50 until x63 by x63 par 1
val x768 = Array(x767)
val x591 = x763
for( x766_vec0 <- x766.apply(0.toInt)) {
  val x599 = x766_vec0.apply(0.toInt)
val x769 = {
Array.fill(x488.toInt)(x50)
}
val x72 = {
FixedPoint[Signed,B32,B0](512.toString)
}
val x770 = {
scala.collection.mutable.Queue.fill(0.toInt)(x50)
}
val x781 = {
{ 
val x771 = {
for (i <- 0 until x488.toInt) { if (i + x599.toInt < x724.length) x770.enqueue( x724(i + x599.toInt) ) else x770.enqueue(x724(0)) }
}
val x772 = x50 until x488 by x63 par 1
val x773 = Array(x772)
for( x773_vec0 <- x773.apply(0.toInt)) {
  val x605 = x773_vec0.apply(0.toInt)
val x774 = {
if (1 < x770.length) {

val first = x770.front
Array.tabulate(1){i => if (x770.nonEmpty) x770.dequeue() else first }
}
else {
Array.tabulate(1){i => x770.dequeue() }
}
}
val x609 = Array(x605)
val x775 = {
x774.apply(0)
}
val x776 = Array(x775)
val x777 = {
x776.zip(x609).foreach{ case (v,a) => if (a.toInt < x769.length) x769(a.toInt) = v }
}
}
val x779 = ()
()
 }
 
()
}
val x782 = {
Array(x50)
}
val x783 = x50 until x488 by x63 par 8
val x784 = Array(x783)
val x619 = x782
for( x784_vec0 <- x784.apply(0.toInt)) {
  val x627 = x784_vec0.apply(0.toInt)
  val x628 = x784_vec0.apply(1.toInt)
  val x629 = x784_vec0.apply(2.toInt)
  val x630 = x784_vec0.apply(3.toInt)
  val x631 = x784_vec0.apply(4.toInt)
  val x632 = x784_vec0.apply(5.toInt)
  val x633 = x784_vec0.apply(6.toInt)
  val x634 = x784_vec0.apply(7.toInt)
val x635 = Array(x627,x628,x629,x630,x631,x632,x633,x634)
val x785 = {
x635.map{addr => if (addr.toInt < x769.length) x769(addr.toInt) else x769(0) }
}
val x786 = {
x619.apply(0)
}
val x101 = {
true
}
val x787 = {
x785.apply(0)
}
val x788 = {
x785.apply(1)
}
val x789 = {
x787 + x788
}
val x790 = {
x785.apply(2)
}
val x791 = {
x785.apply(3)
}
val x792 = {
x790 + x791
}
val x793 = {
x789 + x792
}
val x794 = {
x785.apply(4)
}
val x795 = {
x785.apply(5)
}
val x796 = {
x794 + x795
}
val x797 = {
x785.apply(6)
}
val x798 = {
x785.apply(7)
}
val x799 = {
x797 + x798
}
val x800 = {
x796 + x799
}
val x801 = {
x793 + x800
}
val x802 = {
x801 + x786
}
val x803 = {
if (x101) x619.update(0, x802)
}
}
val x805 = ()
val x811 = {
{ 
val x806 = {
x782.apply(0)
}
val x807 = {
x763.apply(0)
}
val x101 = {
true
}
val x808 = {
x806 + x807
}
val x809 = {
if (x101) x763.update(0, x808)
}
()
 }
 
()
}
}
val x813 = ()
val x817 = {
{ 
val x814 = {
x763.apply(0)
}
val x101 = {
true
}
val x815 = {
if (x101) x721.update(0, x814)
}
()
 }
 
()
}
()
 }
 
()
}
()
 }
 
()
}

x821
}}

/**********/

