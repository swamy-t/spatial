package generated.scala
object kernel_x476 {
def apply(resourceInfo:generated.scala.ResourceInfo,x33:FixedPoint[Signed,B32,B0],x5:FixedPoint[Signed,B32,B0],x13:FixedPoint[Signed,B32,B0],x450:Array[FixedPoint[Signed,B32,B0]],x451:Array[FixedPoint[Signed,B32,B0]],x452:Array[FixedPoint[Signed,B32,B0]],x26:Boolean): Unit = {
val x476 = {
{ 
val x455 = {
Array.fill(x33.toInt)(x5)
}
val x456 = x5 until x33 by x13 par 4
val x457 = Array(x456)
for( x457_vec0 <- x457.apply(0.toInt)) {
  val x373 = x457_vec0.apply(0.toInt)
  val x374 = x457_vec0.apply(1.toInt)
  val x375 = x457_vec0.apply(2.toInt)
  val x376 = x457_vec0.apply(3.toInt)
val x458 = {
x450.apply(0)
}
val x459 = {
x450.apply(0)
}
val x460 = {
x450.apply(0)
}
val x461 = {
x450.apply(0)
}
val x387 = Array(x373,x374,x375,x376)
val x462 = {
x458 * x373
}
val x463 = {
x459 * x374
}
val x464 = {
x460 * x375
}
val x465 = {
x461 * x376
}
val x466 = Array(x462,x463,x464,x465)
val x467 = {
x466.zip(x387).foreach{ case (v,a) => if (a.toInt < x455.length) x455(a.toInt) = v }
}
}
val x469 = ()
val x474 = {
{ 
val x470 = {
x451.apply(0)
}
val x471 = {
x455.apply(x470.toInt)
}
val x472 = {
if (x26) x452.update(0, x471)
}
()
 }
 
()
}
()
 }
 
()
}

x476
}}

/**********/

