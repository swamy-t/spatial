package generated.scala
object kernel_x5832 {
def apply(resourceInfo:generated.scala.ResourceInfo,x5345:Array[FixedPoint[Signed,B32,B0]],x5346:Array[FixedPoint[Signed,B32,B0]],x189:FixedPoint[Signed,B32,B0],x3930:FixedPoint[Signed,B32,B0],x3931:FixedPoint[Signed,B32,B0],x3933:FixedPoint[Signed,B32,B0],x461:FixedPoint[Signed,B32,B0],x11:FixedPoint[Signed,B32,B0],x5355:FixedPoint[Signed,B32,B0],x620:Boolean,x5360:Array[FixedPoint[Signed,B32,B0]],x5347:Array[FixedPoint[Signed,B32,B0]],x3935:FixedPoint[Signed,B32,B0],x5352:FixedPoint[Signed,B32,B0],x5354:Array[FixedPoint[Signed,B32,B0]],x5357:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x5832 = {
{ 
val x5700 = {
x5345.apply(0)
}
val x5701 = {
x5346.apply(0)
}
val x5702 = x189 until x5700 by x3930 par 1
val x5703 = x189 until x5701 by x3931 par 1
val x5704 = Array(x5702, x5703)
for( x5704_vec0 <- x5704.apply(0.toInt)) {
  val x4787 = x5704_vec0.apply(0.toInt)
for( x5704_vec1 <- x5704.apply(1.toInt)) {
  val x4788 = x5704_vec1.apply(0.toInt)
val x5705 = {
Array.fill(x3933.toInt)(x189)
}
val x5706 = {
scala.collection.mutable.Queue.fill(0.toInt)(x189)
}
val x5707 = x189 until x3930 by x11 par 1
val x5708 = Array(x5707)
for( x5708_vec0 <- x5708.apply(0.toInt)) {
  val x4793 = x5708_vec0.apply(0.toInt)
val x5709 = {
Array(x189)
}
val x5714 = {
{ 
val x4795 = {
x4787 + x4793
}
val x5710 = {
x4795 * x5355
}
val x5711 = {
x5710 + x4788
}
val x5712 = {
if (x620) x5709.update(0, x5711)
}
()
 }
 
()
}
val x5715 = {
x5709.apply(0)
}
val x5716 = {
for (i <- 0 until x3931.toInt) { if (i + x5715.toInt < x5360.length) x5706.enqueue( x5360(i + x5715.toInt) ) else x5706.enqueue(x5360(0)) }
}
val x5717 = x189 until x3931 by x11 par 1
val x5718 = Array(x5717)
for( x5718_vec0 <- x5718.apply(0.toInt)) {
  val x4805 = x5718_vec0.apply(0.toInt)
val x5719 = {
if (1 < x5706.length) {

val first = x5706.front
Array.tabulate(1){i => if (x5706.nonEmpty) x5706.dequeue() else first }
}
else {
Array.tabulate(1){i => x5706.dequeue() }
}
}
val x4808 = {
x4793 * x3931
}
val x4809 = {
x4808 + x4805
}
val x4811 = Array(x4809)
val x5720 = {
x5719.apply(0)
}
val x5721 = Array(x5720)
val x5722 = {
x5721.zip(x4811).foreach{ case (v,a) => if (a.toInt < x5705.length) x5705(a.toInt) = v }
}
}
val x5724 = ()
}
val x5726 = ()
val x5727 = {
x5347.apply(0)
}
val x5728 = x189 until x5727 by x3931 par 1
val x5729 = Array(x5728)
for( x5729_vec0 <- x5729.apply(0.toInt)) {
  val x4821 = x5729_vec0.apply(0.toInt)
val x5730 = {
Array.fill(x3933.toInt)(x189)
}
val x5731 = {
Array.fill(x3935.toInt)(x189)
}
val x5775 = {
{ 
val x5732 = {
scala.collection.mutable.Queue.fill(0.toInt)(x189)
}
val x5733 = x189 until x3930 by x11 par 1
val x5734 = Array(x5733)
for( x5734_vec0 <- x5734.apply(0.toInt)) {
  val x4827 = x5734_vec0.apply(0.toInt)
val x5735 = {
Array(x189)
}
val x5740 = {
{ 
val x4829 = {
x4787 + x4827
}
val x5736 = {
x4829 * x5352
}
val x5737 = {
x5736 + x4821
}
val x5738 = {
if (x620) x5735.update(0, x5737)
}
()
 }
 
()
}
val x5741 = {
x5735.apply(0)
}
val x5742 = {
for (i <- 0 until x3931.toInt) { if (i + x5741.toInt < x5354.length) x5732.enqueue( x5354(i + x5741.toInt) ) else x5732.enqueue(x5354(0)) }
}
val x5743 = x189 until x3931 by x11 par 1
val x5744 = Array(x5743)
for( x5744_vec0 <- x5744.apply(0.toInt)) {
  val x4839 = x5744_vec0.apply(0.toInt)
val x5745 = {
if (1 < x5732.length) {

val first = x5732.front
Array.tabulate(1){i => if (x5732.nonEmpty) x5732.dequeue() else first }
}
else {
Array.tabulate(1){i => x5732.dequeue() }
}
}
val x4842 = {
x4827 * x3931
}
val x4843 = {
x4842 + x4839
}
val x4845 = Array(x4843)
val x5746 = {
x5745.apply(0)
}
val x5747 = Array(x5746)
val x5748 = {
x5747.zip(x4845).foreach{ case (v,a) => if (a.toInt < x5730.length) x5730(a.toInt) = v }
}
}
val x5750 = ()
}
val x5752 = ()
val x5753 = {
scala.collection.mutable.Queue.fill(0.toInt)(x189)
}
val x5754 = x189 until x3931 by x11 par 1
val x5755 = Array(x5754)
for( x5755_vec0 <- x5755.apply(0.toInt)) {
  val x4855 = x5755_vec0.apply(0.toInt)
val x5756 = {
Array(x189)
}
val x5761 = {
{ 
val x4857 = {
x4821 + x4855
}
val x5757 = {
x4857 * x5355
}
val x5758 = {
x5757 + x4788
}
val x5759 = {
if (x620) x5756.update(0, x5758)
}
()
 }
 
()
}
val x5762 = {
x5756.apply(0)
}
val x5763 = {
for (i <- 0 until x3931.toInt) { if (i + x5762.toInt < x5357.length) x5753.enqueue( x5357(i + x5762.toInt) ) else x5753.enqueue(x5357(0)) }
}
val x5764 = x189 until x3931 by x11 par 1
val x5765 = Array(x5764)
for( x5765_vec0 <- x5765.apply(0.toInt)) {
  val x4867 = x5765_vec0.apply(0.toInt)
val x5766 = {
if (1 < x5753.length) {

val first = x5753.front
Array.tabulate(1){i => if (x5753.nonEmpty) x5753.dequeue() else first }
}
else {
Array.tabulate(1){i => x5753.dequeue() }
}
}
val x4870 = {
x4855 * x3931
}
val x4871 = {
x4870 + x4867
}
val x4873 = Array(x4871)
val x5767 = {
x5766.apply(0)
}
val x5768 = Array(x5767)
val x5769 = {
x5768.zip(x4873).foreach{ case (v,a) => if (a.toInt < x5731.length) x5731(a.toInt) = v }
}
}
val x5771 = ()
}
val x5773 = ()
()
 }
 
()
}
val x5776 = x189 until x3931 by x11 par 1
val x5777 = Array(x5776)
val x5778 = x189 until x3930 by x11 par 1
val x5779 = x189 until x3931 by x11 par 1
val x5780 = Array(x5778, x5779)
val x4887 = x5705
for( x5777_vec0 <- x5777.apply(0.toInt)) {
  val x4895 = x5777_vec0.apply(0.toInt)
val x5781 = {
Array.fill(x3933.toInt)(x189)
}
val x5782 = x189 until x3930 by x11 par 1
val x5783 = x189 until x3931 by x11 par 1
val x5784 = Array(x5782, x5783)
for( x5784_vec0 <- x5784.apply(0.toInt)) {
  val x4900 = x5784_vec0.apply(0.toInt)
for( x5784_vec1 <- x5784.apply(1.toInt)) {
  val x4901 = x5784_vec1.apply(0.toInt)
val x4902 = {
x4900 * x3931
}
val x4903 = {
x4902 + x4895
}
val x4904 = Array(x4903)
val x5785 = {
x4904.map{addr => if (addr.toInt < x5730.length) x5730(addr.toInt) else x5730(0) }
}
val x4907 = {
x4895 * x3931
}
val x4908 = {
x4907 + x4901
}
val x4909 = Array(x4908)
val x5786 = {
x4909.map{addr => if (addr.toInt < x5731.length) x5731(addr.toInt) else x5731(0) }
}
val x4912 = {
x4902 + x4901
}
val x4915 = Array(x4912)
val x5787 = {
x5785.apply(0)
}
val x5788 = {
x5786.apply(0)
}
val x5789 = {
x5787 * x5788
}
val x5790 = Array(x5789)
val x5791 = {
x5790.zip(x4915).foreach{ case (v,a) => if (a.toInt < x5781.length) x5781(a.toInt) = v }
}
}}
val x5793 = ()
for( x5780_vec0 <- x5780.apply(0.toInt)) {
  val x4922 = x5780_vec0.apply(0.toInt)
for( x5780_vec1 <- x5780.apply(1.toInt)) {
  val x4923 = x5780_vec1.apply(0.toInt)
val x4926 = {
x4922 * x3931
}
val x4927 = {
x4926 + x4923
}
val x4928 = Array(x4927)
val x5794 = {
x4928.map{addr => if (addr.toInt < x5781.length) x5781(addr.toInt) else x5781(0) }
}
val x5795 = {
x4928.map{addr => if (addr.toInt < x4887.length) x4887(addr.toInt) else x4887(0) }
}
val x5796 = {
x5795.apply(0)
}
val x4921 = {
x4895 < x3931
}
val x4924 = {
x4922 < x3930
}
val x4925 = {
x4923 < x3931
}
val x4934 = {
x4924 && x4925
}
val x4935 = {
x4921 && x4934
}
val x5797 = {
x5794.apply(0)
}
val x5798 = {
if (x4935) x5797 else x189
}
val x5799 = {
x5798 + x5796
}
val x5800 = Array(x5799)
val x5801 = {
x5800.zip(x4928).foreach{ case (v,a) => if (a.toInt < x4887.length) x4887(a.toInt) = v }
}
}}
val x5803 = ()
}
val x5805 = ()
val x5806 = {
scala.collection.mutable.Queue.fill(0.toInt)(x189)
}
val x5807 = x189 until x3930 by x11 par 1
val x5808 = Array(x5807)
for( x5808_vec0 <- x5808.apply(0.toInt)) {
  val x4948 = x5808_vec0.apply(0.toInt)
val x5809 = x189 until x3931 by x11 par 1
val x5810 = Array(x5809)
for( x5810_vec0 <- x5810.apply(0.toInt)) {
  val x4951 = x5810_vec0.apply(0.toInt)
val x4952 = {
x4948 * x3931
}
val x4953 = {
x4952 + x4951
}
val x4954 = Array(x4953)
val x5811 = {
x4954.map{addr => if (addr.toInt < x5705.length) x5705(addr.toInt) else x5705(0) }
}
val x4958 = {
x4951 < x3931
}
val x4959 = Array(x4958)
val x5812 = {
x5811.apply(0)
}
val x5813 = Array(x5812)
val x5814 = {
x5813.zip(x4959).foreach{ case (v,e) => if (e) x5806.enqueue(v) }
}
}
val x5816 = ()
val x5817 = {
Array(x189)
}
val x5822 = {
{ 
val x4965 = {
x4787 + x4948
}
val x5818 = {
x4965 * x5355
}
val x5819 = {
x5818 + x4788
}
val x5820 = {
if (x620) x5817.update(0, x5819)
}
()
 }
 
()
}
val x5823 = {
x5817.apply(0)
}
val x5824 = {
for (i <- 0 until x3931.toInt) { if (i + x5823.toInt < x5360.length) x5360(i + x5823.toInt) = x5806.dequeue() }
}
}
val x5826 = ()
}
val x5828 = ()
}}
val x5830 = ()
()
 }
 
()
}

x5832
}}

/**********/

