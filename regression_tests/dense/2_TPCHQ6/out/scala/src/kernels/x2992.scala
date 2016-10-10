package generated.scala
object kernel_x2992 {
def apply(resourceInfo:generated.scala.ResourceInfo,x195:FixedPoint[Signed,B32,B0],x2751:Array[FixedPoint[Signed,B32,B0]],x1778:FixedPoint[Signed,B32,B0],x216:FixedPoint[Signed,B32,B0],x221:FixedPoint[Unsign,B32,B0],x229:FixedPoint[Signed,B32,B0],x2756:Array[FixedPoint[Unsign,B32,B0]],x2757:Array[FixedPoint[Unsign,B32,B0]],x2758:Array[FixedPoint[Signed,B32,B0]],x2759:Array[FixedPoint[Signed,B32,B0]],x295:FixedPoint[Unsign,B32,B0],x300:FixedPoint[Signed,B32,B0],x303:FixedPoint[Unsign,B32,B0],x316:Boolean,x2760:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x2992 = {
{ 
val x2765 = {
Array(x195)
}
val x2766 = {
x2751.apply(0)
}
val x2767 = x195 until x2766 by x1778 par 2
val x2768 = Array(x2767)
val x2769 = x195 until x216 by x216 par 1
val x2770 = Array(x2769)
val x2159 = x2765
for( x2768_vec0 <- x2768.apply(0.toInt)) {
  val x2167 = x2768_vec0.apply(0.toInt)
  val x2168 = x2768_vec0.apply(1.toInt)
val x2771 = {
Array.fill(x1778.toInt)(x221)
}
val x2772 = {
Array.fill(x1778.toInt)(x221)
}
val x2773 = {
Array.fill(x1778.toInt)(x221)
}
val x2774 = {
Array.fill(x1778.toInt)(x221)
}
val x2775 = {
Array.fill(x1778.toInt)(x195)
}
val x2776 = {
Array.fill(x1778.toInt)(x195)
}
val x2777 = {
Array.fill(x1778.toInt)(x195)
}
val x2778 = {
Array.fill(x1778.toInt)(x195)
}
val x2888 = {
{ 
val x2832 = {
{ 
val x2779 = {
scala.collection.mutable.Queue.fill(0.toInt)(x221)
}
val x2791 = {
{ 
val x2780 = {
for (i <- 0 until x1778.toInt) { if (i + x2167.toInt < x2756.length) x2779.enqueue( x2756(i + x2167.toInt) ) else x2779.enqueue(x2756(0)) }
}
val x2781 = x195 until x1778 by x216 par 2
val x2782 = Array(x2781)
for( x2782_vec0 <- x2782.apply(0.toInt)) {
  val x2181 = x2782_vec0.apply(0.toInt)
  val x2182 = x2782_vec0.apply(1.toInt)
val x2783 = {
if (2 < x2779.length) {

val first = x2779.front
Array.tabulate(2){i => if (x2779.nonEmpty) x2779.dequeue() else first }
}
else {
Array.tabulate(2){i => x2779.dequeue() }
}
}
val x2188 = Array(x2181,x2182)
val x2784 = {
x2783.apply(0)
}
val x2785 = {
x2783.apply(1)
}
val x2786 = Array(x2784,x2785)
val x2787 = {
x2786.zip(x2188).foreach{ case (v,a) => if (a.toInt < x2771.length) x2771(a.toInt) = v }
}
}
val x2789 = ()
()
 }
 
()
}
val x2792 = {
scala.collection.mutable.Queue.fill(0.toInt)(x221)
}
val x2804 = {
{ 
val x2793 = {
for (i <- 0 until x1778.toInt) { if (i + x2167.toInt < x2757.length) x2792.enqueue( x2757(i + x2167.toInt) ) else x2792.enqueue(x2757(0)) }
}
val x2794 = x195 until x1778 by x216 par 2
val x2795 = Array(x2794)
for( x2795_vec0 <- x2795.apply(0.toInt)) {
  val x2200 = x2795_vec0.apply(0.toInt)
  val x2201 = x2795_vec0.apply(1.toInt)
val x2796 = {
if (2 < x2792.length) {

val first = x2792.front
Array.tabulate(2){i => if (x2792.nonEmpty) x2792.dequeue() else first }
}
else {
Array.tabulate(2){i => x2792.dequeue() }
}
}
val x2206 = Array(x2200,x2201)
val x2797 = {
x2796.apply(0)
}
val x2798 = {
x2796.apply(1)
}
val x2799 = Array(x2797,x2798)
val x2800 = {
x2799.zip(x2206).foreach{ case (v,a) => if (a.toInt < x2773.length) x2773(a.toInt) = v }
}
}
val x2802 = ()
()
 }
 
()
}
val x2805 = {
scala.collection.mutable.Queue.fill(0.toInt)(x195)
}
val x2817 = {
{ 
val x2806 = {
for (i <- 0 until x1778.toInt) { if (i + x2167.toInt < x2758.length) x2805.enqueue( x2758(i + x2167.toInt) ) else x2805.enqueue(x2758(0)) }
}
val x2807 = x195 until x1778 by x216 par 2
val x2808 = Array(x2807)
for( x2808_vec0 <- x2808.apply(0.toInt)) {
  val x2218 = x2808_vec0.apply(0.toInt)
  val x2219 = x2808_vec0.apply(1.toInt)
val x2809 = {
if (2 < x2805.length) {

val first = x2805.front
Array.tabulate(2){i => if (x2805.nonEmpty) x2805.dequeue() else first }
}
else {
Array.tabulate(2){i => x2805.dequeue() }
}
}
val x2224 = Array(x2218,x2219)
val x2810 = {
x2809.apply(0)
}
val x2811 = {
x2809.apply(1)
}
val x2812 = Array(x2810,x2811)
val x2813 = {
x2812.zip(x2224).foreach{ case (v,a) => if (a.toInt < x2775.length) x2775(a.toInt) = v }
}
}
val x2815 = ()
()
 }
 
()
}
val x2818 = {
scala.collection.mutable.Queue.fill(0.toInt)(x195)
}
val x2830 = {
{ 
val x2819 = {
for (i <- 0 until x1778.toInt) { if (i + x2167.toInt < x2759.length) x2818.enqueue( x2759(i + x2167.toInt) ) else x2818.enqueue(x2759(0)) }
}
val x2820 = x195 until x1778 by x216 par 2
val x2821 = Array(x2820)
for( x2821_vec0 <- x2821.apply(0.toInt)) {
  val x2236 = x2821_vec0.apply(0.toInt)
  val x2237 = x2821_vec0.apply(1.toInt)
val x2822 = {
if (2 < x2818.length) {

val first = x2818.front
Array.tabulate(2){i => if (x2818.nonEmpty) x2818.dequeue() else first }
}
else {
Array.tabulate(2){i => x2818.dequeue() }
}
}
val x2242 = Array(x2236,x2237)
val x2823 = {
x2822.apply(0)
}
val x2824 = {
x2822.apply(1)
}
val x2825 = Array(x2823,x2824)
val x2826 = {
x2825.zip(x2242).foreach{ case (v,a) => if (a.toInt < x2777.length) x2777(a.toInt) = v }
}
}
val x2828 = ()
()
 }
 
()
}
()
 }
 
()
}
val x2886 = {
{ 
val x2833 = {
scala.collection.mutable.Queue.fill(0.toInt)(x221)
}
val x2845 = {
{ 
val x2834 = {
for (i <- 0 until x1778.toInt) { if (i + x2168.toInt < x2756.length) x2833.enqueue( x2756(i + x2168.toInt) ) else x2833.enqueue(x2756(0)) }
}
val x2835 = x195 until x1778 by x216 par 2
val x2836 = Array(x2835)
for( x2836_vec0 <- x2836.apply(0.toInt)) {
  val x2256 = x2836_vec0.apply(0.toInt)
  val x2257 = x2836_vec0.apply(1.toInt)
val x2837 = {
if (2 < x2833.length) {

val first = x2833.front
Array.tabulate(2){i => if (x2833.nonEmpty) x2833.dequeue() else first }
}
else {
Array.tabulate(2){i => x2833.dequeue() }
}
}
val x2262 = Array(x2256,x2257)
val x2838 = {
x2837.apply(0)
}
val x2839 = {
x2837.apply(1)
}
val x2840 = Array(x2838,x2839)
val x2841 = {
x2840.zip(x2262).foreach{ case (v,a) => if (a.toInt < x2772.length) x2772(a.toInt) = v }
}
}
val x2843 = ()
()
 }
 
()
}
val x2846 = {
scala.collection.mutable.Queue.fill(0.toInt)(x221)
}
val x2858 = {
{ 
val x2847 = {
for (i <- 0 until x1778.toInt) { if (i + x2168.toInt < x2757.length) x2846.enqueue( x2757(i + x2168.toInt) ) else x2846.enqueue(x2757(0)) }
}
val x2848 = x195 until x1778 by x216 par 2
val x2849 = Array(x2848)
for( x2849_vec0 <- x2849.apply(0.toInt)) {
  val x2274 = x2849_vec0.apply(0.toInt)
  val x2275 = x2849_vec0.apply(1.toInt)
val x2850 = {
if (2 < x2846.length) {

val first = x2846.front
Array.tabulate(2){i => if (x2846.nonEmpty) x2846.dequeue() else first }
}
else {
Array.tabulate(2){i => x2846.dequeue() }
}
}
val x2280 = Array(x2274,x2275)
val x2851 = {
x2850.apply(0)
}
val x2852 = {
x2850.apply(1)
}
val x2853 = Array(x2851,x2852)
val x2854 = {
x2853.zip(x2280).foreach{ case (v,a) => if (a.toInt < x2774.length) x2774(a.toInt) = v }
}
}
val x2856 = ()
()
 }
 
()
}
val x2859 = {
scala.collection.mutable.Queue.fill(0.toInt)(x195)
}
val x2871 = {
{ 
val x2860 = {
for (i <- 0 until x1778.toInt) { if (i + x2168.toInt < x2758.length) x2859.enqueue( x2758(i + x2168.toInt) ) else x2859.enqueue(x2758(0)) }
}
val x2861 = x195 until x1778 by x216 par 2
val x2862 = Array(x2861)
for( x2862_vec0 <- x2862.apply(0.toInt)) {
  val x2292 = x2862_vec0.apply(0.toInt)
  val x2293 = x2862_vec0.apply(1.toInt)
val x2863 = {
if (2 < x2859.length) {

val first = x2859.front
Array.tabulate(2){i => if (x2859.nonEmpty) x2859.dequeue() else first }
}
else {
Array.tabulate(2){i => x2859.dequeue() }
}
}
val x2298 = Array(x2292,x2293)
val x2864 = {
x2863.apply(0)
}
val x2865 = {
x2863.apply(1)
}
val x2866 = Array(x2864,x2865)
val x2867 = {
x2866.zip(x2298).foreach{ case (v,a) => if (a.toInt < x2776.length) x2776(a.toInt) = v }
}
}
val x2869 = ()
()
 }
 
()
}
val x2872 = {
scala.collection.mutable.Queue.fill(0.toInt)(x195)
}
val x2884 = {
{ 
val x2873 = {
for (i <- 0 until x1778.toInt) { if (i + x2168.toInt < x2759.length) x2872.enqueue( x2759(i + x2168.toInt) ) else x2872.enqueue(x2759(0)) }
}
val x2874 = x195 until x1778 by x216 par 2
val x2875 = Array(x2874)
for( x2875_vec0 <- x2875.apply(0.toInt)) {
  val x2310 = x2875_vec0.apply(0.toInt)
  val x2311 = x2875_vec0.apply(1.toInt)
val x2876 = {
if (2 < x2872.length) {

val first = x2872.front
Array.tabulate(2){i => if (x2872.nonEmpty) x2872.dequeue() else first }
}
else {
Array.tabulate(2){i => x2872.dequeue() }
}
}
val x2316 = Array(x2310,x2311)
val x2877 = {
x2876.apply(0)
}
val x2878 = {
x2876.apply(1)
}
val x2879 = Array(x2877,x2878)
val x2880 = {
x2879.zip(x2316).foreach{ case (v,a) => if (a.toInt < x2778.length) x2778(a.toInt) = v }
}
}
val x2882 = ()
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
val x2889 = {
Array(x195)
}
val x2890 = {
Array(x195)
}
val x2891 = x195 until x1778 by x216 par 2
val x2892 = x195 until x1778 by x216 par 2
val x2893 = Array(x2891)
val x2894 = Array(x2892)
val x2976 = {
{ 
val x2334 = x2889
for( x2893_vec0 <- x2893.apply(0.toInt)) {
  val x2342 = x2893_vec0.apply(0.toInt)
  val x2343 = x2893_vec0.apply(1.toInt)
val x2344 = Array(x2342,x2343)
val x2895 = {
x2344.map{addr => if (addr.toInt < x2771.length) x2771(addr.toInt) else x2771(0) }
}
val x2896 = {
x2344.map{addr => if (addr.toInt < x2775.length) x2775(addr.toInt) else x2775(0) }
}
val x2897 = {
x2344.map{addr => if (addr.toInt < x2773.length) x2773(addr.toInt) else x2773(0) }
}
val x2898 = {
x2344.map{addr => if (addr.toInt < x2777.length) x2777(addr.toInt) else x2777(0) }
}
val x2899 = {
x2334.apply(0)
}
val x2900 = {
x2895.apply(0)
}
val x2901 = {
x221 < x2900
}
val x2902 = {
x2900 < x295
}
val x2903 = {
x2901 && x2902
}
val x2904 = {
x2896.apply(0)
}
val x2905 = {
x195 <= x2904
}
val x2906 = {
x2903 && x2905
}
val x2907 = {
x2904 <= x300
}
val x2908 = {
x2906 && x2907
}
val x2909 = {
x2897.apply(0)
}
val x2910 = {
x2909 < x303
}
val x2911 = {
x2908 && x2910
}
val x2912 = {
x2898.apply(0)
}
val x2913 = {
x2912 * x2904
}
val x2914 = {
if (x2911) x2913 else x195
}
val x2915 = {
x2895.apply(1)
}
val x2916 = {
x221 < x2915
}
val x2917 = {
x2915 < x295
}
val x2918 = {
x2916 && x2917
}
val x2919 = {
x2896.apply(1)
}
val x2920 = {
x195 <= x2919
}
val x2921 = {
x2918 && x2920
}
val x2922 = {
x2919 <= x300
}
val x2923 = {
x2921 && x2922
}
val x2924 = {
x2897.apply(1)
}
val x2925 = {
x2924 < x303
}
val x2926 = {
x2923 && x2925
}
val x2927 = {
x2898.apply(1)
}
val x2928 = {
x2927 * x2919
}
val x2929 = {
if (x2926) x2928 else x195
}
val x2930 = {
x2914 + x2929
}
val x2931 = {
x2930 + x2899
}
val x2932 = {
if (x316) x2334.update(0, x2931)
}
}
val x2934 = ()
val x2393 = x2890
for( x2894_vec0 <- x2894.apply(0.toInt)) {
  val x2401 = x2894_vec0.apply(0.toInt)
  val x2402 = x2894_vec0.apply(1.toInt)
val x2403 = Array(x2401,x2402)
val x2935 = {
x2403.map{addr => if (addr.toInt < x2772.length) x2772(addr.toInt) else x2772(0) }
}
val x2936 = {
x2403.map{addr => if (addr.toInt < x2776.length) x2776(addr.toInt) else x2776(0) }
}
val x2937 = {
x2403.map{addr => if (addr.toInt < x2774.length) x2774(addr.toInt) else x2774(0) }
}
val x2938 = {
x2403.map{addr => if (addr.toInt < x2778.length) x2778(addr.toInt) else x2778(0) }
}
val x2939 = {
x2393.apply(0)
}
val x2940 = {
x2935.apply(0)
}
val x2941 = {
x221 < x2940
}
val x2942 = {
x2940 < x295
}
val x2943 = {
x2941 && x2942
}
val x2944 = {
x2936.apply(0)
}
val x2945 = {
x195 <= x2944
}
val x2946 = {
x2943 && x2945
}
val x2947 = {
x2944 <= x300
}
val x2948 = {
x2946 && x2947
}
val x2949 = {
x2937.apply(0)
}
val x2950 = {
x2949 < x303
}
val x2951 = {
x2948 && x2950
}
val x2952 = {
x2938.apply(0)
}
val x2953 = {
x2952 * x2944
}
val x2954 = {
if (x2951) x2953 else x195
}
val x2955 = {
x2935.apply(1)
}
val x2956 = {
x221 < x2955
}
val x2957 = {
x2955 < x295
}
val x2958 = {
x2956 && x2957
}
val x2959 = {
x2936.apply(1)
}
val x2960 = {
x195 <= x2959
}
val x2961 = {
x2958 && x2960
}
val x2962 = {
x2959 <= x300
}
val x2963 = {
x2961 && x2962
}
val x2964 = {
x2937.apply(1)
}
val x2965 = {
x2964 < x303
}
val x2966 = {
x2963 && x2965
}
val x2967 = {
x2938.apply(1)
}
val x2968 = {
x2967 * x2959
}
val x2969 = {
if (x2966) x2968 else x195
}
val x2970 = {
x2954 + x2969
}
val x2971 = {
x2970 + x2939
}
val x2972 = {
if (x316) x2393.update(0, x2971)
}
}
val x2974 = ()
()
 }
 
()
}
val x2984 = {
{ 
val x2977 = {
x2889.apply(0)
}
val x2978 = {
x2890.apply(0)
}
val x2979 = {
x2765.apply(0)
}
val x2980 = {
x2977 + x2978
}
val x2981 = {
x2980 + x2979
}
val x2982 = {
if (x316) x2765.update(0, x2981)
}
()
 }
 
()
}
}
val x2986 = ()
val x2990 = {
{ 
val x2987 = {
x2765.apply(0)
}
val x2988 = {
if (x316) x2760.update(0, x2987)
}
()
 }
 
()
}
()
 }
 
()
}

x2992
}}

/**********/

