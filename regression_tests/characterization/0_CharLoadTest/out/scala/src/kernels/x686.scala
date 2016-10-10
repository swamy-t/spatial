package generated.scala
object kernel_x686 {
def apply(resourceInfo:generated.scala.ResourceInfo,x598:Array[FixedPoint[Signed,B32,B0]],x50:FixedPoint[Signed,B32,B0],x3:FixedPoint[Signed,B32,B0],x601:Array[FixedPoint[Signed,B32,B0]],x599:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x686 = {
{ 
val x640 = {
x598.apply(0)
}
val x60 = {
FixedPoint[Signed,B32,B0](1.toString)
}
val x641 = x50 until x640 by x60 par 1
val x642 = Array(x641)
for( x642_vec0 <- x642.apply(0.toInt)) {
  val x542 = x642_vec0.apply(0.toInt)
val x643 = {
Array.fill(x3.toInt)(x50)
}
val x669 = {
{ 
val x667 = {
{ 
val x74 = {
FixedPoint[Signed,B32,B0](512.toString)
}
val x644 = {
scala.collection.mutable.Queue.fill(0.toInt)(x50)
}
val x67 = {
FixedPoint[Signed,B32,B0](192.toString)
}
val x645 = x50 until x67 by x60 par 1
val x646 = Array(x645)
for( x646_vec0 <- x646.apply(0.toInt)) {
  val x547 = x646_vec0.apply(0.toInt)
val x647 = {
Array(x50)
}
val x70 = {
FixedPoint[Signed,B32,B0](1920.toString)
}
val x650 = {
{ 
val x108 = {
true
}
val x549 = {
x547 * x70
}
val x648 = {
if (x108) x647.update(0, x549)
}
()
 }
 
()
}
val x651 = {
x647.apply(0)
}
val x652 = {
x647.apply(0)
}
val x653 = {
for (i <- 0 until x70.toInt) { if (i + x651.toInt < x601.length) x644.enqueue( x601(i + x651.toInt) ) else x644.enqueue(x601(0)) }
}
val x654 = x50 until x70 by x60 par 1
val x655 = Array(x654)
for( x655_vec0 <- x655.apply(0.toInt)) {
  val x558 = x655_vec0.apply(0.toInt)
val x656 = {
if (1 < x644.length) {

val first = x644.front
Array.tabulate(1){i => if (x644.nonEmpty) x644.dequeue() else first }
}
else {
Array.tabulate(1){i => x644.dequeue() }
}
}
val x657 = {
x656.apply(0)
}
val x658 = Array(x657)
val x659 = {
x652 + x558
}
val x660 = Array(x659)
val x661 = {
x658.zip(x660).foreach{ case (v,a) => if (a.toInt < x643.length) x643(a.toInt) = v }
}
}
val x663 = ()
}
val x665 = ()
()
 }
 
()
}
()
 }
 
()
}
val x682 = {
{ 
val x680 = {
{ 
val x670 = {
Array(x50)
}
val x674 = {
{ 
val x671 = {
x643.apply(x50.toInt)
}
val x108 = {
true
}
val x672 = {
if (x108) x670.update(0, x671)
}
()
 }
 
()
}
val x675 = {
x670.apply(0)
}
val x678 = {
{ 
val x108 = {
true
}
val x676 = {
if (x108) x599.update(0, x675)
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
}
val x684 = ()
()
 }
 
()
}

x686
}}

/**********/

