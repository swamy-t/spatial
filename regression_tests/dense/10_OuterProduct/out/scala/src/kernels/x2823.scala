package generated.scala
object kernel_x2823 {
def apply(resourceInfo:generated.scala.ResourceInfo,x2667:Array[FixedPoint[Signed,B32,B0]],x2668:Array[FixedPoint[Signed,B32,B0]],x99:FixedPoint[Signed,B32,B0],x1879:FixedPoint[Signed,B32,B0],x1881:FixedPoint[Signed,B32,B0],x131:FixedPoint[Signed,B32,B0],x2672:Array[FixedPoint[Signed,B32,B0]],x53:FixedPoint[Signed,B32,B0],x2674:Array[FixedPoint[Signed,B32,B0]],x2673:FixedPoint[Signed,B32,B0],x197:Boolean,x2676:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x2823 = {
{ 
val x2753 = {
x2667.apply(0)
}
val x2754 = {
x2668.apply(0)
}
val x2755 = x99 until x2753 by x1879 par 1
val x2756 = x99 until x2754 by x1879 par 1
val x2757 = Array(x2755, x2756)
for( x2757_vec0 <- x2757.apply(0.toInt)) {
  val x2307 = x2757_vec0.apply(0.toInt)
for( x2757_vec1 <- x2757.apply(1.toInt)) {
  val x2308 = x2757_vec1.apply(0.toInt)
val x2758 = {
Array.fill(x1879.toInt)(x99)
}
val x2759 = {
Array.fill(x1879.toInt)(x99)
}
val x2760 = {
Array.fill(x1881.toInt)(x99)
}
val x2786 = {
{ 
val x2761 = {
scala.collection.mutable.Queue.fill(0.toInt)(x99)
}
val x2772 = {
{ 
val x2762 = {
for (i <- 0 until x1879.toInt) { if (i + x2307.toInt < x2672.length) x2761.enqueue( x2672(i + x2307.toInt) ) else x2761.enqueue(x2672(0)) }
}
val x2763 = x99 until x1879 by x53 par 1
val x2764 = Array(x2763)
for( x2764_vec0 <- x2764.apply(0.toInt)) {
  val x2316 = x2764_vec0.apply(0.toInt)
val x2765 = {
if (1 < x2761.length) {

val first = x2761.front
Array.tabulate(1){i => if (x2761.nonEmpty) x2761.dequeue() else first }
}
else {
Array.tabulate(1){i => x2761.dequeue() }
}
}
val x2320 = Array(x2316)
val x2766 = {
x2765.apply(0)
}
val x2767 = Array(x2766)
val x2768 = {
x2767.zip(x2320).foreach{ case (v,a) => if (a.toInt < x2758.length) x2758(a.toInt) = v }
}
}
val x2770 = ()
()
 }
 
()
}
val x2773 = {
scala.collection.mutable.Queue.fill(0.toInt)(x99)
}
val x2784 = {
{ 
val x2774 = {
for (i <- 0 until x1879.toInt) { if (i + x2308.toInt < x2674.length) x2773.enqueue( x2674(i + x2308.toInt) ) else x2773.enqueue(x2674(0)) }
}
val x2775 = x99 until x1879 by x53 par 1
val x2776 = Array(x2775)
for( x2776_vec0 <- x2776.apply(0.toInt)) {
  val x2331 = x2776_vec0.apply(0.toInt)
val x2777 = {
if (1 < x2773.length) {

val first = x2773.front
Array.tabulate(1){i => if (x2773.nonEmpty) x2773.dequeue() else first }
}
else {
Array.tabulate(1){i => x2773.dequeue() }
}
}
val x2335 = Array(x2331)
val x2778 = {
x2777.apply(0)
}
val x2779 = Array(x2778)
val x2780 = {
x2779.zip(x2335).foreach{ case (v,a) => if (a.toInt < x2759.length) x2759(a.toInt) = v }
}
}
val x2782 = ()
()
 }
 
()
}
()
 }
 
()
}
val x2787 = x99 until x1879 by x53 par 1
val x2788 = x99 until x1879 by x53 par 1
val x2789 = Array(x2787, x2788)
for( x2789_vec0 <- x2789.apply(0.toInt)) {
  val x2347 = x2789_vec0.apply(0.toInt)
for( x2789_vec1 <- x2789.apply(1.toInt)) {
  val x2348 = x2789_vec1.apply(0.toInt)
val x2349 = Array(x2347)
val x2790 = {
x2349.map{addr => if (addr.toInt < x2758.length) x2758(addr.toInt) else x2758(0) }
}
val x2352 = Array(x2348)
val x2791 = {
x2352.map{addr => if (addr.toInt < x2759.length) x2759(addr.toInt) else x2759(0) }
}
val x2355 = {
x2347 * x1879
}
val x2356 = {
x2355 + x2348
}
val x2359 = Array(x2356)
val x2792 = {
x2790.apply(0)
}
val x2793 = {
x2791.apply(0)
}
val x2794 = {
x2792 * x2793
}
val x2795 = Array(x2794)
val x2796 = {
x2795.zip(x2359).foreach{ case (v,a) => if (a.toInt < x2760.length) x2760(a.toInt) = v }
}
}}
val x2798 = ()
val x2799 = {
scala.collection.mutable.Queue.fill(0.toInt)(x99)
}
val x2800 = x99 until x1879 by x53 par 1
val x2801 = Array(x2800)
for( x2801_vec0 <- x2801.apply(0.toInt)) {
  val x2367 = x2801_vec0.apply(0.toInt)
val x2802 = x99 until x1879 by x53 par 1
val x2803 = Array(x2802)
for( x2803_vec0 <- x2803.apply(0.toInt)) {
  val x2370 = x2803_vec0.apply(0.toInt)
val x2371 = {
x2367 * x1879
}
val x2372 = {
x2371 + x2370
}
val x2373 = Array(x2372)
val x2804 = {
x2373.map{addr => if (addr.toInt < x2760.length) x2760(addr.toInt) else x2760(0) }
}
val x2377 = {
x2370 < x1879
}
val x2378 = Array(x2377)
val x2805 = {
x2804.apply(0)
}
val x2806 = Array(x2805)
val x2807 = {
x2806.zip(x2378).foreach{ case (v,e) => if (e) x2799.enqueue(v) }
}
}
val x2809 = ()
val x2810 = {
Array(x99)
}
val x2815 = {
{ 
val x2384 = {
x2307 + x2367
}
val x2811 = {
x2384 * x2673
}
val x2812 = {
x2811 + x2308
}
val x2813 = {
if (x197) x2810.update(0, x2812)
}
()
 }
 
()
}
val x2816 = {
x2810.apply(0)
}
val x2817 = {
for (i <- 0 until x1879.toInt) { if (i + x2816.toInt < x2676.length) x2676(i + x2816.toInt) = x2799.dequeue() }
}
}
val x2819 = ()
}}
val x2821 = ()
()
 }
 
()
}

x2823
}}

/**********/

