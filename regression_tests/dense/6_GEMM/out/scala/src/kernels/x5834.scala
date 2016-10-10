package generated.scala
object kernel_x5834 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1106:FixedPoint[Signed,B32,B0],x189:FixedPoint[Signed,B32,B0],x423:FixedPoint[Signed,B32,B0],x447:FixedPoint[Signed,B32,B0],x11:FixedPoint[Signed,B32,B0],x674:Boolean,x5337:Array[FixedPoint[Signed,B32,B0]],x5338:Array[FixedPoint[Signed,B32,B0]],x5339:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x5834 = {
{ 
val x5679 = {
Array.fill(x1106.toInt)(x189)
}
val x5680 = x189 until x423 by x423 par 1
val x5681 = Array(x5680)
for( x5681_vec0 <- x5681.apply(0.toInt)) {
  val x4737 = x5681_vec0.apply(0.toInt)
val x5682 = {
Array.fill(x1106.toInt)(x189)
}
val x5683 = {
Array.fill(x1106.toInt)(x189)
}
val x5723 = {
{ 
val x5684 = {
scala.collection.mutable.Queue.fill(0.toInt)(x189)
}
val x5685 = x189 until x423 by x11 par 1
val x5686 = Array(x5685)
for( x5686_vec0 <- x5686.apply(0.toInt)) {
  val x4743 = x5686_vec0.apply(0.toInt)
val x5687 = {
Array(x189)
}
val x5690 = {
{ 
val x4745 = {
x4743 * x423
}
val x4746 = {
x4745 + x4737
}
val x5688 = {
if (x674) x5687.update(0, x4746)
}
()
 }
 
()
}
val x5691 = {
x5687.apply(0)
}
val x5692 = {
for (i <- 0 until x423.toInt) { if (i + x5691.toInt < x5337.length) x5684.enqueue( x5337(i + x5691.toInt) ) else x5684.enqueue(x5337(0)) }
}
val x5693 = x189 until x423 by x11 par 1
val x5694 = Array(x5693)
for( x5694_vec0 <- x5694.apply(0.toInt)) {
  val x4754 = x5694_vec0.apply(0.toInt)
val x5695 = {
if (1 < x5684.length) {

val first = x5684.front
Array.tabulate(1){i => if (x5684.nonEmpty) x5684.dequeue() else first }
}
else {
Array.tabulate(1){i => x5684.dequeue() }
}
}
val x4745 = {
x4743 * x423
}
val x4757 = {
x4745 + x4754
}
val x4759 = Array(x4757)
val x5696 = {
x5695.apply(0)
}
val x5697 = Array(x5696)
val x5698 = {
x5697.zip(x4759).foreach{ case (v,a) => if (a.toInt < x5682.length) x5682(a.toInt) = v }
}
}
val x5700 = ()
}
val x5702 = ()
val x5703 = {
scala.collection.mutable.Queue.fill(0.toInt)(x189)
}
val x5704 = x189 until x423 by x11 par 1
val x5705 = Array(x5704)
for( x5705_vec0 <- x5705.apply(0.toInt)) {
  val x4769 = x5705_vec0.apply(0.toInt)
val x5706 = {
Array(x189)
}
val x5709 = {
{ 
val x4771 = {
x4737 + x4769
}
val x4772 = {
x4771 * x423
}
val x5707 = {
if (x674) x5706.update(0, x4772)
}
()
 }
 
()
}
val x5710 = {
x5706.apply(0)
}
val x5711 = {
for (i <- 0 until x423.toInt) { if (i + x5710.toInt < x5338.length) x5703.enqueue( x5338(i + x5710.toInt) ) else x5703.enqueue(x5338(0)) }
}
val x5712 = x189 until x423 by x11 par 1
val x5713 = Array(x5712)
for( x5713_vec0 <- x5713.apply(0.toInt)) {
  val x4780 = x5713_vec0.apply(0.toInt)
val x5714 = {
if (1 < x5703.length) {

val first = x5703.front
Array.tabulate(1){i => if (x5703.nonEmpty) x5703.dequeue() else first }
}
else {
Array.tabulate(1){i => x5703.dequeue() }
}
}
val x4783 = {
x4769 * x423
}
val x4784 = {
x4783 + x4780
}
val x4786 = Array(x4784)
val x5715 = {
x5714.apply(0)
}
val x5716 = Array(x5715)
val x5717 = {
x5716.zip(x4786).foreach{ case (v,a) => if (a.toInt < x5683.length) x5683(a.toInt) = v }
}
}
val x5719 = ()
}
val x5721 = ()
()
 }
 
()
}
val x5724 = x189 until x423 by x423 par 1
val x5725 = Array(x5724)
for( x5725_vec0 <- x5725.apply(0.toInt)) {
  val x4797 = x5725_vec0.apply(0.toInt)
val x5726 = {
Array.fill(x1106.toInt)(x189)
}
val x5727 = {
Array.fill(x1106.toInt)(x189)
}
val x5728 = x189 until x423 by x11 par 1
val x5729 = x189 until x423 by x11 par 1
val x5730 = Array(x5728, x5729)
for( x5730_vec0 <- x5730.apply(0.toInt)) {
  val x4803 = x5730_vec0.apply(0.toInt)
for( x5730_vec1 <- x5730.apply(1.toInt)) {
  val x4804 = x5730_vec1.apply(0.toInt)
val x4805 = {
x4797 + x4803
}
val x4806 = {
x4805 * x423
}
val x4807 = {
x4806 + x4804
}
val x4808 = Array(x4807)
val x5731 = {
x4808.map{addr => if (addr.toInt < x5682.length) x5682(addr.toInt) else x5682(0) }
}
val x4811 = {
x4803 * x423
}
val x4812 = {
x4811 + x4804
}
val x4814 = Array(x4812)
val x5732 = {
x5731.apply(0)
}
val x5733 = Array(x5732)
val x5734 = {
x5733.zip(x4814).foreach{ case (v,a) => if (a.toInt < x5726.length) x5726(a.toInt) = v }
}
}}
val x5736 = ()
val x5737 = x189 until x423 by x423 par 1
val x5738 = Array(x5737)
for( x5738_vec0 <- x5738.apply(0.toInt)) {
  val x4821 = x5738_vec0.apply(0.toInt)
val x5739 = x189 until x423 by x11 par 1
val x5740 = x189 until x423 by x11 par 1
val x5741 = Array(x5739, x5740)
for( x5741_vec0 <- x5741.apply(0.toInt)) {
  val x4825 = x5741_vec0.apply(0.toInt)
for( x5741_vec1 <- x5741.apply(1.toInt)) {
  val x4826 = x5741_vec1.apply(0.toInt)
val x4827 = {
x4821 + x4826
}
val x4828 = {
x4825 * x423
}
val x4829 = {
x4828 + x4827
}
val x4830 = Array(x4829)
val x5742 = {
x4830.map{addr => if (addr.toInt < x5683.length) x5683(addr.toInt) else x5683(0) }
}
val x4833 = {
x4828 + x4826
}
val x4835 = Array(x4833)
val x5743 = {
x5742.apply(0)
}
val x5744 = Array(x5743)
val x5745 = {
x5744.zip(x4835).foreach{ case (v,a) => if (a.toInt < x5727.length) x5727(a.toInt) = v }
}
}}
val x5747 = ()
val x5748 = {
Array.fill(x1106.toInt)(x189)
}
val x5749 = {
Array.fill(x1106.toInt)(x189)
}
val x5750 = x189 until x423 by x423 par 1
val x5751 = Array(x5750)
for( x5751_vec0 <- x5751.apply(0.toInt)) {
  val x4844 = x5751_vec0.apply(0.toInt)
val x5752 = x189 until x423 by x11 par 1
val x5753 = x189 until x423 by x11 par 1
val x5754 = Array(x5752, x5753)
for( x5754_vec0 <- x5754.apply(0.toInt)) {
  val x4848 = x5754_vec0.apply(0.toInt)
for( x5754_vec1 <- x5754.apply(1.toInt)) {
  val x4849 = x5754_vec1.apply(0.toInt)
val x4850 = {
x4821 + x4849
}
val x4851 = {
x4797 + x4844
}
val x4852 = {
x4851 + x4848
}
val x4853 = {
x4852 * x423
}
val x4854 = {
x4853 + x4850
}
val x4855 = Array(x4854)
val x5755 = {
x4855.map{addr => if (addr.toInt < x5679.length) x5679(addr.toInt) else x5679(0) }
}
val x4858 = {
x4848 * x423
}
val x4859 = {
x4858 + x4849
}
val x4861 = Array(x4859)
val x5756 = {
x5755.apply(0)
}
val x5757 = Array(x5756)
val x5758 = {
x5757.zip(x4861).foreach{ case (v,a) => if (a.toInt < x5748.length) x5748(a.toInt) = v }
}
}}
val x5760 = ()
val x5761 = x189 until x423 by x11 par 1
val x5762 = Array(x5761)
val x5763 = x189 until x423 by x11 par 1
val x5764 = x189 until x423 by x11 par 1
val x5765 = Array(x5763, x5764)
val x4871 = x5749
for( x5762_vec0 <- x5762.apply(0.toInt)) {
  val x4879 = x5762_vec0.apply(0.toInt)
val x5766 = {
Array.fill(x1106.toInt)(x189)
}
val x5767 = x189 until x423 by x11 par 1
val x5768 = x189 until x423 by x11 par 1
val x5769 = Array(x5767, x5768)
for( x5769_vec0 <- x5769.apply(0.toInt)) {
  val x4884 = x5769_vec0.apply(0.toInt)
for( x5769_vec1 <- x5769.apply(1.toInt)) {
  val x4885 = x5769_vec1.apply(0.toInt)
val x4886 = {
x4884 * x423
}
val x4887 = {
x4886 + x4879
}
val x4888 = Array(x4887)
val x5770 = {
x4888.map{addr => if (addr.toInt < x5726.length) x5726(addr.toInt) else x5726(0) }
}
val x4891 = {
x4879 * x423
}
val x4892 = {
x4891 + x4885
}
val x4893 = Array(x4892)
val x5771 = {
x4893.map{addr => if (addr.toInt < x5727.length) x5727(addr.toInt) else x5727(0) }
}
val x5772 = {
x4893.map{addr => if (addr.toInt < x5748.length) x5748(addr.toInt) else x5748(0) }
}
val x4898 = {
x4886 + x4885
}
val x4902 = Array(x4898)
val x5773 = {
x5772.apply(0)
}
val x5774 = {
x5770.apply(0)
}
val x5775 = {
x5771.apply(0)
}
val x5776 = {
x5774 * x5775
}
val x5777 = {
x5776 + x5773
}
val x5778 = Array(x5777)
val x5779 = {
x5778.zip(x4902).foreach{ case (v,a) => if (a.toInt < x5766.length) x5766(a.toInt) = v }
}
}}
val x5781 = ()
for( x5765_vec0 <- x5765.apply(0.toInt)) {
  val x4909 = x5765_vec0.apply(0.toInt)
for( x5765_vec1 <- x5765.apply(1.toInt)) {
  val x4910 = x5765_vec1.apply(0.toInt)
val x4913 = {
x4909 * x423
}
val x4914 = {
x4913 + x4910
}
val x4915 = Array(x4914)
val x5782 = {
x4915.map{addr => if (addr.toInt < x5766.length) x5766(addr.toInt) else x5766(0) }
}
val x5783 = {
x4915.map{addr => if (addr.toInt < x4871.length) x4871(addr.toInt) else x4871(0) }
}
val x5784 = {
x5783.apply(0)
}
val x4908 = {
x4879 < x423
}
val x4911 = {
x4909 < x423
}
val x4912 = {
x4910 < x423
}
val x4921 = {
x4911 && x4912
}
val x4922 = {
x4908 && x4921
}
val x5785 = {
x5782.apply(0)
}
val x5786 = {
if (x4922) x5785 else x189
}
val x5787 = {
x5786 + x5784
}
val x5788 = Array(x5787)
val x5789 = {
x5788.zip(x4915).foreach{ case (v,a) => if (a.toInt < x4871.length) x4871(a.toInt) = v }
}
}}
val x5791 = ()
}
val x5793 = ()
val x5794 = x189 until x423 by x11 par 1
val x5795 = x189 until x423 by x11 par 1
val x5796 = Array(x5794, x5795)
for( x5796_vec0 <- x5796.apply(0.toInt)) {
  val x4935 = x5796_vec0.apply(0.toInt)
for( x5796_vec1 <- x5796.apply(1.toInt)) {
  val x4936 = x5796_vec1.apply(0.toInt)
val x4937 = {
x4935 * x423
}
val x4938 = {
x4937 + x4936
}
val x4939 = Array(x4938)
val x5797 = {
x4939.map{addr => if (addr.toInt < x5749.length) x5749(addr.toInt) else x5749(0) }
}
val x4942 = {
x4821 + x4936
}
val x4851 = {
x4797 + x4844
}
val x4943 = {
x4851 + x4935
}
val x4944 = {
x4943 * x423
}
val x4945 = {
x4944 + x4942
}
val x4947 = Array(x4945)
val x5798 = {
x5797.apply(0)
}
val x5799 = Array(x5798)
val x5800 = {
x5799.zip(x4947).foreach{ case (v,a) => if (a.toInt < x5679.length) x5679(a.toInt) = v }
}
}}
val x5802 = ()
}
val x5804 = ()
}
val x5806 = ()
}
val x5808 = ()
}
val x5810 = ()
val x5811 = {
scala.collection.mutable.Queue.fill(0.toInt)(x189)
}
val x5812 = x189 until x423 by x11 par 1
val x5813 = Array(x5812)
for( x5813_vec0 <- x5813.apply(0.toInt)) {
  val x4967 = x5813_vec0.apply(0.toInt)
val x5814 = x189 until x423 by x11 par 1
val x5815 = Array(x5814)
val x5816 = {
Array(x189)
}
val x5819 = {
{ 
val x4971 = {
x4967 * x423
}
val x5817 = {
if (x674) x5816.update(0, x4971)
}
()
 }
 
()
}
val x5820 = {
x5816.apply(0)
}
val x5821 = {
x5816.apply(0)
}
for( x5815_vec0 <- x5815.apply(0.toInt)) {
  val x4977 = x5815_vec0.apply(0.toInt)
val x5822 = {
x5820 + x4977
}
val x5823 = Array(x5822)
val x5824 = {
x5823.map{addr => if (addr.toInt < x5679.length) x5679(addr.toInt) else x5679(0) }
}
val x4983 = {
x4977 < x423
}
val x4984 = Array(x4983)
val x5825 = {
x5824.apply(0)
}
val x5826 = Array(x5825)
val x5827 = {
x5826.zip(x4984).foreach{ case (v,e) => if (e) x5811.enqueue(v) }
}
}
val x5829 = ()
val x5830 = {
for (i <- 0 until x423.toInt) { if (i + x5821.toInt < x5339.length) x5339(i + x5821.toInt) = x5811.dequeue() }
}
}
val x5832 = ()
()
 }
 
()
}

x5834
}}

/**********/

