package generated.scala
object kernel_x3513 {
def apply(resourceInfo:generated.scala.ResourceInfo,x888:FixedPoint[Signed,B32,B0],x197:FixedPoint[Signed,B32,B0],x3323:Array[FixedPoint[Signed,B32,B0]],x3325:Array[FixedPoint[Signed,B32,B0]],x206:FixedPoint[Signed,B32,B0],x218:FixedPoint[Signed,B32,B0],x231:FixedPoint[Signed,B32,B0],x3328:FixedPoint[Signed,B32,B0],x299:Boolean,x3330:Array[FixedPoint[Signed,B32,B0]],x3331:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x3513 = {
{ 
val x3445 = {
Array.fill(x888.toInt)(x197)
}
val x3446 = {
x3323.apply(0)
}
val x3447 = {
x3325.apply(0)
}
val x3448 = x197 until x3446 by x206 par 1
val x3449 = x197 until x3447 by x206 par 1
val x3450 = Array(x3448, x3449)
val x3451 = x197 until x206 by x218 par 1
val x3452 = x197 until x206 by x218 par 1
val x3453 = Array(x3451, x3452)
val x2925 = x3445
for( x3450_vec0 <- x3450.apply(0.toInt)) {
  val x2933 = x3450_vec0.apply(0.toInt)
for( x3450_vec1 <- x3450.apply(1.toInt)) {
  val x2934 = x3450_vec1.apply(0.toInt)
val x3454 = {
Array.fill(x888.toInt)(x197)
}
val x3455 = {
scala.collection.mutable.Queue.fill(0.toInt)(x197)
}
val x3456 = x197 until x206 by x218 par 1
val x3457 = Array(x3456)
for( x3457_vec0 <- x3457.apply(0.toInt)) {
  val x2939 = x3457_vec0.apply(0.toInt)
val x3458 = {
Array(x197)
}
val x3463 = {
{ 
val x2941 = {
x2933 + x2939
}
val x3459 = {
x2941 * x3328
}
val x3460 = {
x3459 + x2934
}
val x3461 = {
if (x299) x3458.update(0, x3460)
}
()
 }
 
()
}
val x3464 = {
x3458.apply(0)
}
val x3465 = {
for (i <- 0 until x206.toInt) { if (i + x3464.toInt < x3330.length) x3455.enqueue( x3330(i + x3464.toInt) ) else x3455.enqueue(x3330(0)) }
}
val x3466 = x197 until x206 by x218 par 1
val x3467 = Array(x3466)
for( x3467_vec0 <- x3467.apply(0.toInt)) {
  val x2951 = x3467_vec0.apply(0.toInt)
val x3468 = {
if (1 < x3455.length) {

val first = x3455.front
Array.tabulate(1){i => if (x3455.nonEmpty) x3455.dequeue() else first }
}
else {
Array.tabulate(1){i => x3455.dequeue() }
}
}
val x2954 = {
x2939 * x206
}
val x2955 = {
x2954 + x2951
}
val x2957 = Array(x2955)
val x3469 = {
x3468.apply(0)
}
val x3470 = Array(x3469)
val x3471 = {
x3470.zip(x2957).foreach{ case (v,a) => if (a.toInt < x3454.length) x3454(a.toInt) = v }
}
}
val x3473 = ()
}
val x3475 = ()
for( x3453_vec0 <- x3453.apply(0.toInt)) {
  val x2967 = x3453_vec0.apply(0.toInt)
for( x3453_vec1 <- x3453.apply(1.toInt)) {
  val x2968 = x3453_vec1.apply(0.toInt)
val x2971 = {
x2967 * x206
}
val x2972 = {
x2971 + x2968
}
val x2973 = Array(x2972)
val x3476 = {
x2973.map{addr => if (addr.toInt < x3454.length) x3454(addr.toInt) else x3454(0) }
}
val x3477 = {
x2973.map{addr => if (addr.toInt < x2925.length) x2925(addr.toInt) else x2925(0) }
}
val x3478 = {
x3477.apply(0)
}
val x3479 = {
x3476.apply(0)
}
val x2969 = {
x2967 < x206
}
val x2970 = {
x2968 < x206
}
val x2979 = {
x2969 && x2970
}
val x3480 = {
x2933 < x3446
}
val x3481 = {
x3480 && x2979
}
val x3482 = {
if (x3481) x3479 else x197
}
val x3483 = {
x3482 + x3478
}
val x3484 = Array(x3483)
val x3485 = {
x3484.zip(x2973).foreach{ case (v,a) => if (a.toInt < x2925.length) x2925(a.toInt) = v }
}
}}
val x3487 = ()
}}
val x3489 = ()
val x3490 = {
scala.collection.mutable.Queue.fill(0.toInt)(x197)
}
val x3491 = x197 until x206 by x218 par 1
val x3492 = Array(x3491)
for( x3492_vec0 <- x3492.apply(0.toInt)) {
  val x2994 = x3492_vec0.apply(0.toInt)
val x3493 = x197 until x206 by x218 par 1
val x3494 = Array(x3493)
val x3495 = {
Array(x197)
}
val x3498 = {
{ 
val x2998 = {
x2994 * x206
}
val x3496 = {
if (x299) x3495.update(0, x2998)
}
()
 }
 
()
}
val x3499 = {
x3495.apply(0)
}
val x3500 = {
x3495.apply(0)
}
for( x3494_vec0 <- x3494.apply(0.toInt)) {
  val x3004 = x3494_vec0.apply(0.toInt)
val x3501 = {
x3499 + x3004
}
val x3502 = Array(x3501)
val x3503 = {
x3502.map{addr => if (addr.toInt < x3445.length) x3445(addr.toInt) else x3445(0) }
}
val x3010 = {
x3004 < x206
}
val x3011 = Array(x3010)
val x3504 = {
x3503.apply(0)
}
val x3505 = Array(x3504)
val x3506 = {
x3505.zip(x3011).foreach{ case (v,e) => if (e) x3490.enqueue(v) }
}
}
val x3508 = ()
val x3509 = {
for (i <- 0 until x206.toInt) { if (i + x3500.toInt < x3331.length) x3331(i + x3500.toInt) = x3490.dequeue() }
}
}
val x3511 = ()
()
 }
 
()
}

x3513
}}

/**********/

