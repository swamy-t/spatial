package generated.scala
object kernel_x487 {
def apply(resourceInfo:generated.scala.ResourceInfo,x4:FixedPoint[Signed,B32,B0],x0:FixedPoint[Signed,B32,B0],x8:FixedPoint[Signed,B32,B0],x469:Array[FixedPoint[Signed,B32,B0]],x27:Boolean,x470:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x487 = {
{ 
val x472 = {
Array(x4)
}
val x473 = x4 until x0 by x8 par 1
val x474 = Array(x473)
val x390 = x472
for( x474_vec0 <- x474.apply(0.toInt)) {
  val x398 = x474_vec0.apply(0.toInt)
val x475 = {
x469.apply(0)
}
val x476 = {
x390.apply(0)
}
val x477 = {
x475 * x398
}
val x478 = {
x477 + x476
}
val x479 = {
if (x27) x390.update(0, x478)
}
}
val x481 = ()
val x482 = {
x472.apply(0)
}
val x485 = {
{ 
val x483 = {
if (x27) x470.update(0, x482)
}
()
 }
 
()
}
()
 }
 
()
}

x487
}}

/**********/

