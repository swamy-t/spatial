package generated.scala
object kernel_x2958 {
def apply(resourceInfo:generated.scala.ResourceInfo,x246:FixedPoint[Signed,B32,B0],x105:FixedPoint[Signed,B32,B0],x1:FixedPoint[Signed,B32,B0],x116:FixedPoint[Signed,B32,B0],x2772:Array[FixedPoint[Signed,B32,B0]],x119:FixedPoint[Signed,B32,B0],x2773:Array[FixedPoint[Signed,B32,B0]],x143:FixedPoint[Signed,B32,B0],x2776:Array[FixedPoint[Signed,B32,B0]],x2775:Array[FixedPoint[Signed,B32,B0]],x2777:Array[FixedPoint[Signed,B32,B0]],x180:Boolean,x2774:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x2958 = {
{ 
val x2854 = {
Array.fill(x246.toInt)(x105)
}
val x2855 = {
Array.fill(x246.toInt)(x105)
}
val x2856 = x105 until x1 by x246 par 1
val x2857 = Array(x2856)
for( x2857_vec0 <- x2857.apply(0.toInt)) {
  val x2363 = x2857_vec0.apply(0.toInt)
val x2858 = {
scala.collection.mutable.Queue.fill(0.toInt)(x105)
}
val x2869 = {
{ 
val x2859 = {
for (i <- 0 until x246.toInt) { if (i + x2363.toInt < x2772.length) x2858.enqueue( x2772(i + x2363.toInt) ) else x2858.enqueue(x2772(0)) }
}
val x2860 = x105 until x246 by x119 par 1
val x2861 = Array(x2860)
for( x2861_vec0 <- x2861.apply(0.toInt)) {
  val x2368 = x2861_vec0.apply(0.toInt)
val x2862 = {
if (1 < x2858.length) {

val first = x2858.front
Array.tabulate(1){i => if (x2858.nonEmpty) x2858.dequeue() else first }
}
else {
Array.tabulate(1){i => x2858.dequeue() }
}
}
val x2372 = Array(x2368)
val x2863 = {
x2862.apply(0)
}
val x2864 = Array(x2863)
val x2865 = {
x2864.zip(x2372).foreach{ case (v,a) => if (a.toInt < x2854.length) x2854(a.toInt) = v }
}
}
val x2867 = ()
()
 }
 
()
}
val x2870 = {
scala.collection.mutable.Queue.fill(0.toInt)(x105)
}
val x2881 = {
{ 
val x2871 = {
for (i <- 0 until x246.toInt) { if (i + x2363.toInt < x2773.length) x2870.enqueue( x2773(i + x2363.toInt) ) else x2870.enqueue(x2773(0)) }
}
val x2872 = x105 until x246 by x119 par 1
val x2873 = Array(x2872)
for( x2873_vec0 <- x2873.apply(0.toInt)) {
  val x2383 = x2873_vec0.apply(0.toInt)
val x2874 = {
if (1 < x2870.length) {

val first = x2870.front
Array.tabulate(1){i => if (x2870.nonEmpty) x2870.dequeue() else first }
}
else {
Array.tabulate(1){i => x2870.dequeue() }
}
}
val x2387 = Array(x2383)
val x2875 = {
x2874.apply(0)
}
val x2876 = Array(x2875)
val x2877 = {
x2876.zip(x2387).foreach{ case (v,a) => if (a.toInt < x2855.length) x2855(a.toInt) = v }
}
}
val x2879 = ()
()
 }
 
()
}
val x2882 = x105 until x143 by x119 par 1
val x2883 = Array(x2882)
for( x2883_vec0 <- x2883.apply(0.toInt)) {
  val x2396 = x2883_vec0.apply(0.toInt)
val x2884 = x105 until x119 by x119 par 1
val x2885 = Array(x2884)
val x2886 = x105 until x246 by x119 par 1
val x2887 = Array(x2886)
val x2401 = x2854
for( x2885_vec0 <- x2885.apply(0.toInt)) {
  val x2409 = x2885_vec0.apply(0.toInt)
for( x2887_vec0 <- x2887.apply(0.toInt)) {
  val x2411 = x2887_vec0.apply(0.toInt)
val x2413 = Array(x2411)
val x2888 = {
x2413.map{addr => if (addr.toInt < x2855.length) x2855(addr.toInt) else x2855(0) }
}
val x2889 = {
x2413.map{addr => if (addr.toInt < x2401.length) x2401(addr.toInt) else x2401(0) }
}
val x2890 = {
x2889.apply(0)
}
val x2410 = {
x2409 < x119
}
val x2412 = {
x2411 < x246
}
val x2419 = {
x2410 && x2412
}
val x2891 = {
x2888.apply(0)
}
val x2892 = {
if (x2419) x2891 else x105
}
val x2893 = {
x2892 + x2890
}
val x2894 = Array(x2893)
val x2895 = {
x2894.zip(x2413).foreach{ case (v,a) => if (a.toInt < x2401.length) x2401(a.toInt) = v }
}
}
val x2897 = ()
}
val x2899 = ()
val x2900 = {
scala.collection.mutable.Queue.fill(0.toInt)(x105)
}
val x2911 = {
{ 
val x2901 = x105 until x246 by x119 par 1
val x2902 = Array(x2901)
for( x2902_vec0 <- x2902.apply(0.toInt)) {
  val x2432 = x2902_vec0.apply(0.toInt)
val x2433 = Array(x2432)
val x2903 = {
x2433.map{addr => if (addr.toInt < x2855.length) x2855(addr.toInt) else x2855(0) }
}
val x2437 = {
x2432 < x246
}
val x2438 = Array(x2437)
val x2904 = {
x2903.apply(0)
}
val x2905 = Array(x2904)
val x2906 = {
x2905.zip(x2438).foreach{ case (v,e) => if (e) x2900.enqueue(v) }
}
}
val x2908 = ()
val x2909 = {
for (i <- 0 until x246.toInt) { if (i + x105.toInt < x2776.length) x2776(i + x105.toInt) = x2900.dequeue() }
}
()
 }
 
()
}
val x2912 = {
scala.collection.mutable.Queue.fill(0.toInt)(x105)
}
val x2923 = {
{ 
val x2913 = x105 until x246 by x119 par 1
val x2914 = Array(x2913)
for( x2914_vec0 <- x2914.apply(0.toInt)) {
  val x2449 = x2914_vec0.apply(0.toInt)
val x2450 = Array(x2449)
val x2915 = {
x2450.map{addr => if (addr.toInt < x2854.length) x2854(addr.toInt) else x2854(0) }
}
val x2454 = {
x2449 < x246
}
val x2455 = Array(x2454)
val x2916 = {
x2915.apply(0)
}
val x2917 = Array(x2916)
val x2918 = {
x2917.zip(x2455).foreach{ case (v,e) => if (e) x2912.enqueue(v) }
}
}
val x2920 = ()
val x2921 = {
for (i <- 0 until x246.toInt) { if (i + x105.toInt < x2775.length) x2775(i + x105.toInt) = x2912.dequeue() }
}
()
 }
 
()
}
val x2924 = {
scala.collection.mutable.Queue.fill(0.toInt)(x105)
}
val x2935 = {
{ 
val x2925 = x105 until x246 by x119 par 1
val x2926 = Array(x2925)
for( x2926_vec0 <- x2926.apply(0.toInt)) {
  val x2466 = x2926_vec0.apply(0.toInt)
val x2467 = Array(x2466)
val x2927 = {
x2467.map{addr => if (addr.toInt < x2855.length) x2855(addr.toInt) else x2855(0) }
}
val x2471 = {
x2466 < x246
}
val x2472 = Array(x2471)
val x2928 = {
x2927.apply(0)
}
val x2929 = Array(x2928)
val x2930 = {
x2929.zip(x2472).foreach{ case (v,e) => if (e) x2924.enqueue(v) }
}
}
val x2932 = ()
val x2933 = {
for (i <- 0 until x246.toInt) { if (i + x105.toInt < x2777.length) x2777(i + x105.toInt) = x2924.dequeue() }
}
()
 }
 
()
}
val x2936 = {
scala.collection.mutable.Queue.fill(0.toInt)(x105)
}
val x2952 = {
{ 
val x2937 = x105 until x246 by x119 par 1
val x2938 = Array(x2937)
for( x2938_vec0 <- x2938.apply(0.toInt)) {
  val x2483 = x2938_vec0.apply(0.toInt)
val x2484 = Array(x2483)
val x2939 = {
x2484.map{addr => if (addr.toInt < x2854.length) x2854(addr.toInt) else x2854(0) }
}
val x2488 = {
x2483 < x246
}
val x2489 = Array(x2488)
val x2940 = {
x2939.apply(0)
}
val x2941 = Array(x2940)
val x2942 = {
x2941.zip(x2489).foreach{ case (v,e) => if (e) x2936.enqueue(v) }
}
}
val x2944 = ()
val x2945 = {
Array(x105)
}
val x2948 = {
{ 
val x2495 = {
x2363 * x143
}
val x2496 = {
x2396 * x246
}
val x2497 = {
x2495 + x2496
}
val x2946 = {
if (x180) x2945.update(0, x2497)
}
()
 }
 
()
}
val x2949 = {
x2945.apply(0)
}
val x2950 = {
for (i <- 0 until x246.toInt) { if (i + x2949.toInt < x2774.length) x2774(i + x2949.toInt) = x2936.dequeue() }
}
()
 }
 
()
}
}
val x2954 = ()
}
val x2956 = ()
()
 }
 
()
}

x2958
}}

/**********/

