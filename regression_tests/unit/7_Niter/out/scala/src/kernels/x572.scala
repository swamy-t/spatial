package generated.scala
object kernel_x572 {
def apply(resourceInfo:generated.scala.ResourceInfo,x549:Array[FixedPoint[Signed,B32,B0]],x4:FixedPoint[Signed,B32,B0],x3:FixedPoint[Signed,B32,B0],x15:FixedPoint[Signed,B32,B0],x31:Boolean,x550:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x572 = {
{ 
val x570 = {
{ 
val x552 = {
x549.apply(0)
}
val x553 = x4 until x552 by x3 par 1
val x554 = Array(x553)
for( x554_vec0 <- x554.apply(0.toInt)) {
  val x427 = x554_vec0.apply(0.toInt)
val x555 = {
Array(x4)
}
val x556 = x4 until x3 by x15 par 8
val x557 = Array(x556)
val x431 = x555
for( x557_vec0 <- x557.apply(0.toInt)) {
  val x439 = x557_vec0.apply(0.toInt)
  val x440 = x557_vec0.apply(1.toInt)
  val x441 = x557_vec0.apply(2.toInt)
  val x442 = x557_vec0.apply(3.toInt)
  val x443 = x557_vec0.apply(4.toInt)
  val x444 = x557_vec0.apply(5.toInt)
  val x445 = x557_vec0.apply(6.toInt)
  val x446 = x557_vec0.apply(7.toInt)
val x558 = {
x431.apply(0)
}
val x447 = {
x427 + x439
}
val x448 = {
x427 + x440
}
val x471 = {
x447 + x448
}
val x449 = {
x427 + x441
}
val x450 = {
x427 + x442
}
val x472 = {
x449 + x450
}
val x475 = {
x471 + x472
}
val x451 = {
x427 + x443
}
val x452 = {
x427 + x444
}
val x473 = {
x451 + x452
}
val x453 = {
x427 + x445
}
val x454 = {
x427 + x446
}
val x474 = {
x453 + x454
}
val x476 = {
x473 + x474
}
val x477 = {
x475 + x476
}
val x559 = {
x477 + x558
}
val x560 = {
if (x31) x431.update(0, x559)
}
}
val x562 = ()
val x566 = {
{ 
val x563 = {
x555.apply(0)
}
val x564 = {
if (x31) x550.update(0, x563)
}
()
 }
 
()
}
}
val x568 = ()
()
 }
 
()
}
()
 }
 
()
}

x572
}}

/**********/

