package generated.scala
object kernel_x2798 {
def apply(resourceInfo:generated.scala.ResourceInfo,x5:FixedPoint[Signed,B32,B0],x2537:Array[FloatPoint[B24,B8]],x244:FixedPoint[Signed,B32,B0],x2529:Array[FixedPoint[Signed,B32,B0]],x2535:Array[FloatPoint[B24,B8]],x2536:Array[FloatPoint[B24,B8]],x147:FloatPoint[B24,B8]): Unit = {
val x2798 = {
{ 
val x257 = {
FloatPoint[B24,B8](0.toString)
}
val x2580 = {
Array.fill(x5.toInt)(x257)
}
val x262 = {
FixedPoint[Signed,B32,B0](512.toString)
}
val x2581 = {
scala.collection.mutable.Queue.fill(0.toInt)(x257)
}
val x265 = {
FixedPoint[Signed,B32,B0](1.toString)
}
val x2595 = {
{ 
val x2582 = {
for (i <- 0 until x5.toInt) { if (i + x244.toInt < x2537.length) x2581.enqueue( x2537(i + x244.toInt) ) else x2581.enqueue(x2537(0)) }
}
val x2583 = x244 until x5 by x265 par 4
val x2584 = Array(x2583)
for( x2584_vec0 <- x2584.apply(0.toInt)) {
  val x1994 = x2584_vec0.apply(0.toInt)
  val x1995 = x2584_vec0.apply(1.toInt)
  val x1996 = x2584_vec0.apply(2.toInt)
  val x1997 = x2584_vec0.apply(3.toInt)
val x2585 = {
if (4 < x2581.length) {

val first = x2581.front
Array.tabulate(4){i => if (x2581.nonEmpty) x2581.dequeue() else first }
}
else {
Array.tabulate(4){i => x2581.dequeue() }
}
}
val x2005 = Array(x1994,x1995,x1996,x1997)
val x2586 = {
x2585.apply(0)
}
val x2587 = {
x2585.apply(1)
}
val x2588 = {
x2585.apply(2)
}
val x2589 = {
x2585.apply(3)
}
val x2590 = Array(x2586,x2587,x2588,x2589)
val x2591 = {
x2590.zip(x2005).foreach{ case (v,a) => if (a.toInt < x2580.length) x2580(a.toInt) = v }
}
}
val x2593 = ()
()
 }
 
()
}
val x2596 = {
Array.fill(x5.toInt)(x257)
}
val x2597 = {
x2529.apply(0)
}
val x1668 = {
FixedPoint[Signed,B32,B0](192.toString)
}
val x2598 = x244 until x2597 by x1668 par 1
val x2599 = Array(x2598)
val x2600 = x244 until x5 by x265 par 4
val x2601 = Array(x2600)
val x2021 = x2596
for( x2599_vec0 <- x2599.apply(0.toInt)) {
  val x2029 = x2599_vec0.apply(0.toInt)
val x1674 = {
FixedPoint[Signed,B32,B0](73728.toString)
}
val x2602 = {
Array.fill(x1674.toInt)(x257)
}
val x2603 = {
Array.fill(x1668.toInt)(x257)
}
val x2642 = {
{ 
val x2604 = {
scala.collection.mutable.Queue.fill(0.toInt)(x257)
}
val x2605 = x244 until x1668 by x265 par 1
val x2606 = Array(x2605)
for( x2606_vec0 <- x2606.apply(0.toInt)) {
  val x2035 = x2606_vec0.apply(0.toInt)
val x2607 = {
Array(x244)
}
val x2610 = {
{ 
val x362 = {
true
}
val x2037 = {
x2029 + x2035
}
val x2038 = {
x2037 * x5
}
val x2608 = {
if (x362) x2607.update(0, x2038)
}
()
 }
 
()
}
val x2611 = {
x2607.apply(0)
}
val x2612 = {
for (i <- 0 until x5.toInt) { if (i + x2611.toInt < x2535.length) x2604.enqueue( x2535(i + x2611.toInt) ) else x2604.enqueue(x2535(0)) }
}
val x2613 = x244 until x5 by x265 par 4
val x2614 = Array(x2613)
for( x2614_vec0 <- x2614.apply(0.toInt)) {
  val x2046 = x2614_vec0.apply(0.toInt)
  val x2047 = x2614_vec0.apply(1.toInt)
  val x2048 = x2614_vec0.apply(2.toInt)
  val x2049 = x2614_vec0.apply(3.toInt)
val x2615 = {
if (4 < x2604.length) {

val first = x2604.front
Array.tabulate(4){i => if (x2604.nonEmpty) x2604.dequeue() else first }
}
else {
Array.tabulate(4){i => x2604.dequeue() }
}
}
val x2055 = {
x2035 * x5
}
val x2056 = {
x2055 + x2046
}
val x2057 = {
x2055 + x2047
}
val x2058 = {
x2055 + x2048
}
val x2059 = {
x2055 + x2049
}
val x2061 = Array(x2056,x2057,x2058,x2059)
val x2616 = {
x2615.apply(0)
}
val x2617 = {
x2615.apply(1)
}
val x2618 = {
x2615.apply(2)
}
val x2619 = {
x2615.apply(3)
}
val x2620 = Array(x2616,x2617,x2618,x2619)
val x2621 = {
x2620.zip(x2061).foreach{ case (v,a) => if (a.toInt < x2602.length) x2602(a.toInt) = v }
}
}
val x2623 = ()
}
val x2625 = ()
val x2626 = {
scala.collection.mutable.Queue.fill(0.toInt)(x257)
}
val x2640 = {
{ 
val x2627 = {
for (i <- 0 until x1668.toInt) { if (i + x2029.toInt < x2536.length) x2626.enqueue( x2536(i + x2029.toInt) ) else x2626.enqueue(x2536(0)) }
}
val x2628 = x244 until x1668 by x265 par 4
val x2629 = Array(x2628)
for( x2629_vec0 <- x2629.apply(0.toInt)) {
  val x2075 = x2629_vec0.apply(0.toInt)
  val x2076 = x2629_vec0.apply(1.toInt)
  val x2077 = x2629_vec0.apply(2.toInt)
  val x2078 = x2629_vec0.apply(3.toInt)
val x2630 = {
if (4 < x2626.length) {

val first = x2626.front
Array.tabulate(4){i => if (x2626.nonEmpty) x2626.dequeue() else first }
}
else {
Array.tabulate(4){i => x2626.dequeue() }
}
}
val x2085 = Array(x2075,x2076,x2077,x2078)
val x2631 = {
x2630.apply(0)
}
val x2632 = {
x2630.apply(1)
}
val x2633 = {
x2630.apply(2)
}
val x2634 = {
x2630.apply(3)
}
val x2635 = Array(x2631,x2632,x2633,x2634)
val x2636 = {
x2635.zip(x2085).foreach{ case (v,a) => if (a.toInt < x2603.length) x2603(a.toInt) = v }
}
}
val x2638 = ()
()
 }
 
()
}
()
 }
 
()
}
val x2643 = {
Array.fill(x5.toInt)(x257)
}
val x2644 = x244 until x1668 by x265 par 1
val x2645 = Array(x2644)
val x2646 = x244 until x5 by x265 par 4
val x2647 = Array(x2646)
val x2102 = x2643
for( x2645_vec0 <- x2645.apply(0.toInt)) {
  val x2110 = x2645_vec0.apply(0.toInt)
val x2648 = {
Array(x257)
}
val x2649 = {
Array.fill(x5.toInt)(x257)
}
val x2650 = {
Array(x257)
}
val x2651 = x244 until x5 by x265 par 4
val x2652 = Array(x2651)
val x2116 = x2650
for( x2652_vec0 <- x2652.apply(0.toInt)) {
  val x2124 = x2652_vec0.apply(0.toInt)
  val x2125 = x2652_vec0.apply(1.toInt)
  val x2126 = x2652_vec0.apply(2.toInt)
  val x2127 = x2652_vec0.apply(3.toInt)
val x2128 = {
x2110 * x5
}
val x2129 = {
x2128 + x2124
}
val x2130 = {
x2128 + x2125
}
val x2131 = {
x2128 + x2126
}
val x2132 = {
x2128 + x2127
}
val x2133 = Array(x2129,x2130,x2131,x2132)
val x2653 = {
x2133.map{addr => if (addr.toInt < x2602.length) x2602(addr.toInt) else x2602(0) }
}
val x2139 = Array(x2124,x2125,x2126,x2127)
val x2654 = {
x2139.map{addr => if (addr.toInt < x2580.length) x2580(addr.toInt) else x2580(0) }
}
val x2655 = {
x2116.apply(0)
}
val x362 = {
true
}
val x2656 = {
x2653.apply(0)
}
val x2657 = {
x2654.apply(0)
}
val x2658 = {
x2656 * x2657
}
val x2659 = {
x2653.apply(1)
}
val x2660 = {
x2654.apply(1)
}
val x2661 = {
x2659 * x2660
}
val x2662 = {
x2658 + x2661
}
val x2663 = {
x2653.apply(2)
}
val x2664 = {
x2654.apply(2)
}
val x2665 = {
x2663 * x2664
}
val x2666 = {
x2653.apply(3)
}
val x2667 = {
x2654.apply(3)
}
val x2668 = {
x2666 * x2667
}
val x2669 = {
x2665 + x2668
}
val x2670 = {
x2662 + x2669
}
val x2671 = {
x2670 + x2655
}
val x2672 = {
if (x362) x2116.update(0, x2671)
}
}
val x2674 = ()
val x2684 = {
{ 
val x2675 = {
x2603.apply(x2110.toInt)
}
val x2676 = {
x2650.apply(0)
}
val x362 = {
true
}
val x2677 = {
-x2676
}
val x2678 = {
FloatPoint.exp(x2677)
}
val x2679 = {
x2678 + x147
}
val x2680 = {
x147 / x2679
}
val x2681 = {
x2675 - x2680
}
val x2682 = {
if (x362) x2648.update(0, x2681)
}
()
 }
 
()
}
val x2685 = x244 until x5 by x265 par 4
val x2686 = Array(x2685)
for( x2686_vec0 <- x2686.apply(0.toInt)) {
  val x2183 = x2686_vec0.apply(0.toInt)
  val x2184 = x2686_vec0.apply(1.toInt)
  val x2185 = x2686_vec0.apply(2.toInt)
  val x2186 = x2686_vec0.apply(3.toInt)
val x2128 = {
x2110 * x5
}
val x2187 = {
x2128 + x2183
}
val x2188 = {
x2128 + x2184
}
val x2189 = {
x2128 + x2185
}
val x2190 = {
x2128 + x2186
}
val x2191 = Array(x2187,x2188,x2189,x2190)
val x2687 = {
x2191.map{addr => if (addr.toInt < x2602.length) x2602(addr.toInt) else x2602(0) }
}
val x2688 = {
x2648.apply(0)
}
val x2689 = {
x2648.apply(0)
}
val x2690 = {
x2648.apply(0)
}
val x2691 = {
x2648.apply(0)
}
val x2206 = Array(x2183,x2184,x2185,x2186)
val x2692 = {
x2687.apply(0)
}
val x2693 = {
x2692 - x2688
}
val x2694 = {
x2687.apply(1)
}
val x2695 = {
x2694 - x2689
}
val x2696 = {
x2687.apply(2)
}
val x2697 = {
x2696 - x2690
}
val x2698 = {
x2687.apply(3)
}
val x2699 = {
x2698 - x2691
}
val x2700 = Array(x2693,x2695,x2697,x2699)
val x2701 = {
x2700.zip(x2206).foreach{ case (v,a) => if (a.toInt < x2649.length) x2649(a.toInt) = v }
}
}
val x2703 = ()
for( x2647_vec0 <- x2647.apply(0.toInt)) {
  val x2216 = x2647_vec0.apply(0.toInt)
  val x2217 = x2647_vec0.apply(1.toInt)
  val x2218 = x2647_vec0.apply(2.toInt)
  val x2219 = x2647_vec0.apply(3.toInt)
val x2224 = Array(x2216,x2217,x2218,x2219)
val x2704 = {
x2224.map{addr => if (addr.toInt < x2649.length) x2649(addr.toInt) else x2649(0) }
}
val x2705 = {
x2224.map{addr => if (addr.toInt < x2102.length) x2102(addr.toInt) else x2102(0) }
}
val x2706 = {
x2705.apply(0)
}
val x2215 = {
x2110 < x1668
}
val x2220 = {
x2216 < x5
}
val x2239 = {
x2215 && x2220
}
val x2707 = {
x2704.apply(0)
}
val x2708 = {
if (x2239) x2707 else x257
}
val x2709 = {
x2708 + x2706
}
val x2710 = {
x2705.apply(1)
}
val x2221 = {
x2217 < x5
}
val x2242 = {
x2215 && x2221
}
val x2711 = {
x2704.apply(1)
}
val x2712 = {
if (x2242) x2711 else x257
}
val x2713 = {
x2712 + x2710
}
val x2714 = {
x2705.apply(2)
}
val x2222 = {
x2218 < x5
}
val x2245 = {
x2215 && x2222
}
val x2715 = {
x2704.apply(2)
}
val x2716 = {
if (x2245) x2715 else x257
}
val x2717 = {
x2716 + x2714
}
val x2718 = {
x2705.apply(3)
}
val x2223 = {
x2219 < x5
}
val x2248 = {
x2215 && x2223
}
val x2719 = {
x2704.apply(3)
}
val x2720 = {
if (x2248) x2719 else x257
}
val x2721 = {
x2720 + x2718
}
val x2722 = Array(x2709,x2713,x2717,x2721)
val x2723 = {
x2722.zip(x2224).foreach{ case (v,a) => if (a.toInt < x2102.length) x2102(a.toInt) = v }
}
}
val x2725 = ()
}
val x2727 = ()
for( x2601_vec0 <- x2601.apply(0.toInt)) {
  val x2260 = x2601_vec0.apply(0.toInt)
  val x2261 = x2601_vec0.apply(1.toInt)
  val x2262 = x2601_vec0.apply(2.toInt)
  val x2263 = x2601_vec0.apply(3.toInt)
val x2268 = Array(x2260,x2261,x2262,x2263)
val x2728 = {
x2268.map{addr => if (addr.toInt < x2643.length) x2643(addr.toInt) else x2643(0) }
}
val x2729 = {
x2268.map{addr => if (addr.toInt < x2021.length) x2021(addr.toInt) else x2021(0) }
}
val x2730 = {
x2729.apply(0)
}
val x2731 = {
x2728.apply(0)
}
val x2264 = {
x2260 < x5
}
val x2732 = {
x2029 < x2597
}
val x2733 = {
x2732 && x2264
}
val x2734 = {
if (x2733) x2731 else x257
}
val x2735 = {
x2734 + x2730
}
val x2736 = {
x2729.apply(1)
}
val x2737 = {
x2728.apply(1)
}
val x2265 = {
x2261 < x5
}
val x2738 = {
x2732 && x2265
}
val x2739 = {
if (x2738) x2737 else x257
}
val x2740 = {
x2739 + x2736
}
val x2741 = {
x2729.apply(2)
}
val x2742 = {
x2728.apply(2)
}
val x2266 = {
x2262 < x5
}
val x2743 = {
x2732 && x2266
}
val x2744 = {
if (x2743) x2742 else x257
}
val x2745 = {
x2744 + x2741
}
val x2746 = {
x2729.apply(3)
}
val x2747 = {
x2728.apply(3)
}
val x2267 = {
x2263 < x5
}
val x2748 = {
x2732 && x2267
}
val x2749 = {
if (x2748) x2747 else x257
}
val x2750 = {
x2749 + x2746
}
val x2751 = Array(x2735,x2740,x2745,x2750)
val x2752 = {
x2751.zip(x2268).foreach{ case (v,a) => if (a.toInt < x2021.length) x2021(a.toInt) = v }
}
}
val x2754 = ()
}
val x2756 = ()
val x2757 = {
Array.fill(x5.toInt)(x257)
}
val x2758 = x244 until x5 by x265 par 4
val x2759 = Array(x2758)
for( x2759_vec0 <- x2759.apply(0.toInt)) {
  val x2305 = x2759_vec0.apply(0.toInt)
  val x2306 = x2759_vec0.apply(1.toInt)
  val x2307 = x2759_vec0.apply(2.toInt)
  val x2308 = x2759_vec0.apply(3.toInt)
val x2309 = Array(x2305,x2306,x2307,x2308)
val x2760 = {
x2309.map{addr => if (addr.toInt < x2596.length) x2596(addr.toInt) else x2596(0) }
}
val x2761 = {
x2309.map{addr => if (addr.toInt < x2580.length) x2580(addr.toInt) else x2580(0) }
}
val x2762 = {
x2761.apply(0)
}
val x2763 = {
x2760.apply(0)
}
val x2764 = {
x2763 * x147
}
val x2765 = {
x2764 + x2762
}
val x2766 = {
x2761.apply(1)
}
val x2767 = {
x2760.apply(1)
}
val x2768 = {
x2767 * x147
}
val x2769 = {
x2768 + x2766
}
val x2770 = {
x2761.apply(2)
}
val x2771 = {
x2760.apply(2)
}
val x2772 = {
x2771 * x147
}
val x2773 = {
x2772 + x2770
}
val x2774 = {
x2761.apply(3)
}
val x2775 = {
x2760.apply(3)
}
val x2776 = {
x2775 * x147
}
val x2777 = {
x2776 + x2774
}
val x2778 = Array(x2765,x2769,x2773,x2777)
val x2779 = {
x2778.zip(x2309).foreach{ case (v,a) => if (a.toInt < x2757.length) x2757(a.toInt) = v }
}
}
val x2781 = ()
val x2782 = {
scala.collection.mutable.Queue.fill(0.toInt)(x257)
}
val x2796 = {
{ 
val x2783 = x244 until x5 by x265 par 4
val x2784 = Array(x2783)
for( x2784_vec0 <- x2784.apply(0.toInt)) {
  val x2339 = x2784_vec0.apply(0.toInt)
  val x2340 = x2784_vec0.apply(1.toInt)
  val x2341 = x2784_vec0.apply(2.toInt)
  val x2342 = x2784_vec0.apply(3.toInt)
val x2343 = Array(x2339,x2340,x2341,x2342)
val x2785 = {
x2343.map{addr => if (addr.toInt < x2757.length) x2757(addr.toInt) else x2757(0) }
}
val x2350 = {
x2339 < x5
}
val x2351 = {
x2340 < x5
}
val x2352 = {
x2341 < x5
}
val x2353 = {
x2342 < x5
}
val x2354 = Array(x2350,x2351,x2352,x2353)
val x2786 = {
x2785.apply(0)
}
val x2787 = {
x2785.apply(1)
}
val x2788 = {
x2785.apply(2)
}
val x2789 = {
x2785.apply(3)
}
val x2790 = Array(x2786,x2787,x2788,x2789)
val x2791 = {
x2790.zip(x2354).foreach{ case (v,e) => if (e) x2782.enqueue(v) }
}
}
val x2793 = ()
val x2794 = {
for (i <- 0 until x5.toInt) { if (i + x244.toInt < x2537.length) x2537(i + x244.toInt) = x2782.dequeue() }
}
()
 }
 
()
}
()
 }
 
()
}

x2798
}}

/**********/

