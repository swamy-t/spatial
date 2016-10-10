package generated.scala
object kernel_x2609 {
def apply(resourceInfo:generated.scala.ResourceInfo,x189:FixedPoint[Signed,B32,B0],x102:FixedPoint[Signed,B32,B0],x1:FixedPoint[Signed,B32,B0],x113:FixedPoint[Signed,B32,B0],x2474:Array[FixedPoint[Signed,B32,B0]],x116:FixedPoint[Signed,B32,B0],x127:FixedPoint[Signed,B32,B0],x167:Boolean,x2476:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x2609 = {
{ 
val x2553 = {
Array.fill(x189.toInt)(x102)
}
val x2554 = {
Array.fill(x189.toInt)(x102)
}
val x2555 = x102 until x1 by x189 par 1
val x2556 = Array(x2555)
for( x2556_vec0 <- x2556.apply(0.toInt)) {
  val x2131 = x2556_vec0.apply(0.toInt)
val x2557 = {
scala.collection.mutable.Queue.fill(0.toInt)(x102)
}
val x2568 = {
{ 
val x2558 = {
for (i <- 0 until x189.toInt) { if (i + x2131.toInt < x2474.length) x2557.enqueue( x2474(i + x2131.toInt) ) else x2557.enqueue(x2474(0)) }
}
val x2559 = x102 until x189 by x116 par 1
val x2560 = Array(x2559)
for( x2560_vec0 <- x2560.apply(0.toInt)) {
  val x2136 = x2560_vec0.apply(0.toInt)
val x2561 = {
if (1 < x2557.length) {

val first = x2557.front
Array.tabulate(1){i => if (x2557.nonEmpty) x2557.dequeue() else first }
}
else {
Array.tabulate(1){i => x2557.dequeue() }
}
}
val x2140 = Array(x2136)
val x2562 = {
x2561.apply(0)
}
val x2563 = Array(x2562)
val x2564 = {
x2563.zip(x2140).foreach{ case (v,a) => if (a.toInt < x2553.length) x2553(a.toInt) = v }
}
}
val x2566 = ()
()
 }
 
()
}
val x2569 = x102 until x127 by x116 par 1
val x2570 = Array(x2569)
for( x2570_vec0 <- x2570.apply(0.toInt)) {
  val x2149 = x2570_vec0.apply(0.toInt)
val x2571 = x102 until x116 by x116 par 1
val x2572 = Array(x2571)
val x2573 = x102 until x189 by x116 par 1
val x2574 = Array(x2573)
val x2154 = x2553
for( x2572_vec0 <- x2572.apply(0.toInt)) {
  val x2162 = x2572_vec0.apply(0.toInt)
for( x2574_vec0 <- x2574.apply(0.toInt)) {
  val x2164 = x2574_vec0.apply(0.toInt)
val x2166 = Array(x2164)
val x2575 = {
x2166.map{addr => if (addr.toInt < x2554.length) x2554(addr.toInt) else x2554(0) }
}
val x2576 = {
x2166.map{addr => if (addr.toInt < x2154.length) x2154(addr.toInt) else x2154(0) }
}
val x2577 = {
x2576.apply(0)
}
val x2163 = {
x2162 < x116
}
val x2165 = {
x2164 < x189
}
val x2172 = {
x2163 && x2165
}
val x2578 = {
x2575.apply(0)
}
val x2579 = {
if (x2172) x2578 else x102
}
val x2580 = {
x2579 + x2577
}
val x2581 = Array(x2580)
val x2582 = {
x2581.zip(x2166).foreach{ case (v,a) => if (a.toInt < x2154.length) x2154(a.toInt) = v }
}
}
val x2584 = ()
}
val x2586 = ()
val x2587 = {
scala.collection.mutable.Queue.fill(0.toInt)(x102)
}
val x2603 = {
{ 
val x2588 = x102 until x189 by x116 par 1
val x2589 = Array(x2588)
for( x2589_vec0 <- x2589.apply(0.toInt)) {
  val x2185 = x2589_vec0.apply(0.toInt)
val x2186 = Array(x2185)
val x2590 = {
x2186.map{addr => if (addr.toInt < x2553.length) x2553(addr.toInt) else x2553(0) }
}
val x2190 = {
x2185 < x189
}
val x2191 = Array(x2190)
val x2591 = {
x2590.apply(0)
}
val x2592 = Array(x2591)
val x2593 = {
x2592.zip(x2191).foreach{ case (v,e) => if (e) x2587.enqueue(v) }
}
}
val x2595 = ()
val x2596 = {
Array(x102)
}
val x2599 = {
{ 
val x2197 = {
x2131 * x127
}
val x2198 = {
x2149 * x189
}
val x2199 = {
x2197 + x2198
}
val x2597 = {
if (x167) x2596.update(0, x2199)
}
()
 }
 
()
}
val x2600 = {
x2596.apply(0)
}
val x2601 = {
for (i <- 0 until x189.toInt) { if (i + x2600.toInt < x2476.length) x2476(i + x2600.toInt) = x2587.dequeue() }
}
()
 }
 
()
}
}
val x2605 = ()
}
val x2607 = ()
()
 }
 
()
}

x2609
}}

/**********/

