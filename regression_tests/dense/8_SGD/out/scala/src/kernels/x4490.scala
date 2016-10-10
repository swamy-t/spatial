package generated.scala
object kernel_x4490 {
def apply(resourceInfo:generated.scala.ResourceInfo,x996:FixedPoint[Signed,B32,B0],x286:FixedPoint[Signed,B32,B0],x5:FixedPoint[Signed,B32,B0],x4320:Array[FixedPoint[Signed,B32,B0]],x303:FixedPoint[Signed,B32,B0],x312:FixedPoint[Signed,B32,B0],x381:Boolean,x4323:Array[FixedPoint[Signed,B32,B0]],x4324:Array[FixedPoint[Signed,B32,B0]],x4319:Array[FixedPoint[Signed,B32,B0]],x4325:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x4490 = {
{ 
val x4367 = {
Array.fill(x996.toInt)(x286)
}
val x4368 = {
Array.fill(x5.toInt)(x286)
}
val x4369 = {
Array.fill(x5.toInt)(x286)
}
val x4370 = {
Array.fill(x5.toInt)(x286)
}
val x4371 = {
Array.fill(x5.toInt)(x286)
}
val x4372 = {
x4320.apply(0)
}
val x4373 = x286 until x4372 by x303 par 1
val x4374 = Array(x4373)
for( x4374_vec0 <- x4374.apply(0.toInt)) {
  val x3641 = x4374_vec0.apply(0.toInt)
val x4412 = {
{ 
val x4398 = {
{ 
val x4375 = {
scala.collection.mutable.Queue.fill(0.toInt)(x286)
}
val x4376 = x286 until x5 by x303 par 1
val x4377 = Array(x4376)
for( x4377_vec0 <- x4377.apply(0.toInt)) {
  val x3645 = x4377_vec0.apply(0.toInt)
val x4378 = {
Array(x286)
}
val x4381 = {
{ 
val x3647 = {
x3645 * x5
}
val x4379 = {
if (x381) x4378.update(0, x3647)
}
()
 }
 
()
}
val x4382 = {
x4378.apply(0)
}
val x4383 = {
x4378.apply(0)
}
val x4384 = {
for (i <- 0 until x5.toInt) { if (i + x4382.toInt < x4323.length) x4375.enqueue( x4323(i + x4382.toInt) ) else x4375.enqueue(x4323(0)) }
}
val x4385 = x286 until x5 by x303 par 1
val x4386 = Array(x4385)
for( x4386_vec0 <- x4386.apply(0.toInt)) {
  val x3656 = x4386_vec0.apply(0.toInt)
val x4387 = {
if (1 < x4375.length) {

val first = x4375.front
Array.tabulate(1){i => if (x4375.nonEmpty) x4375.dequeue() else first }
}
else {
Array.tabulate(1){i => x4375.dequeue() }
}
}
val x4388 = {
x4387.apply(0)
}
val x4389 = Array(x4388)
val x4390 = {
x4383 + x3656
}
val x4391 = Array(x4390)
val x4392 = {
x4389.zip(x4391).foreach{ case (v,a) => if (a.toInt < x4367.length) x4367(a.toInt) = v }
}
}
val x4394 = ()
}
val x4396 = ()
()
 }
 
()
}
val x4399 = {
scala.collection.mutable.Queue.fill(0.toInt)(x286)
}
val x4410 = {
{ 
val x4400 = {
for (i <- 0 until x5.toInt) { if (i + x286.toInt < x4324.length) x4399.enqueue( x4324(i + x286.toInt) ) else x4399.enqueue(x4324(0)) }
}
val x4401 = x286 until x5 by x303 par 1
val x4402 = Array(x4401)
for( x4402_vec0 <- x4402.apply(0.toInt)) {
  val x3674 = x4402_vec0.apply(0.toInt)
val x4403 = {
if (1 < x4399.length) {

val first = x4399.front
Array.tabulate(1){i => if (x4399.nonEmpty) x4399.dequeue() else first }
}
else {
Array.tabulate(1){i => x4399.dequeue() }
}
}
val x3678 = Array(x3674)
val x4404 = {
x4403.apply(0)
}
val x4405 = Array(x4404)
val x4406 = {
x4405.zip(x3678).foreach{ case (v,a) => if (a.toInt < x4368.length) x4368(a.toInt) = v }
}
}
val x4408 = ()
()
 }
 
()
}
()
 }
 
()
}
val x4413 = x286 until x5 by x303 par 1
val x4414 = Array(x4413)
for( x4414_vec0 <- x4414.apply(0.toInt)) {
  val x3689 = x4414_vec0.apply(0.toInt)
val x4415 = {
Array(x286)
}
val x4416 = x286 until x5 by x303 par 1
val x4417 = Array(x4416)
val x3693 = x4415
for( x4417_vec0 <- x4417.apply(0.toInt)) {
  val x3701 = x4417_vec0.apply(0.toInt)
val x3702 = {
x3689 * x5
}
val x3703 = {
x3702 + x3701
}
val x3704 = Array(x3703)
val x4418 = {
x3704.map{addr => if (addr.toInt < x4367.length) x4367(addr.toInt) else x4367(0) }
}
val x3707 = Array(x3701)
val x4419 = {
x3707.map{addr => if (addr.toInt < x4370.length) x4370(addr.toInt) else x4370(0) }
}
val x4420 = {
x3693.apply(0)
}
val x4421 = {
x4418.apply(0)
}
val x4422 = {
x4419.apply(0)
}
val x4423 = {
x4421 * x4422
}
val x4424 = {
x4423 + x4420
}
val x4425 = {
if (x381) x3693.update(0, x4424)
}
}
val x4427 = ()
val x4428 = {
x4415.apply(0)
}
val x4433 = {
{ 
val x4429 = {
x4368.apply(x3689.toInt)
}
val x4430 = {
x4428 - x4429
}
val x4431 = {
x4371.update(x3689.toInt, x4430)
}
()
 }
 
()
}
}
val x4435 = ()
val x4436 = x286 until x5 by x303 par 1
val x4437 = Array(x4436)
for( x4437_vec0 <- x4437.apply(0.toInt)) {
  val x3732 = x4437_vec0.apply(0.toInt)
val x4438 = {
Array(x286)
}
val x4439 = x286 until x5 by x303 par 1
val x4440 = Array(x4439)
val x3736 = x4438
for( x4440_vec0 <- x4440.apply(0.toInt)) {
  val x3744 = x4440_vec0.apply(0.toInt)
val x3745 = {
x3744 * x5
}
val x3746 = {
x3745 + x3732
}
val x3747 = Array(x3746)
val x4441 = {
x3747.map{addr => if (addr.toInt < x4367.length) x4367(addr.toInt) else x4367(0) }
}
val x3750 = Array(x3744)
val x4442 = {
x3750.map{addr => if (addr.toInt < x4371.length) x4371(addr.toInt) else x4371(0) }
}
val x4443 = {
x3736.apply(0)
}
val x4444 = {
x4441.apply(0)
}
val x4445 = {
x4442.apply(0)
}
val x4446 = {
x4444 * x4445
}
val x4447 = {
x4446 + x4443
}
val x4448 = {
if (x381) x3736.update(0, x4447)
}
}
val x4450 = ()
val x4451 = {
x4438.apply(0)
}
val x4452 = {
x4319.apply(0)
}
val x4456 = {
{ 
val x4453 = {
x4451 * x4452
}
val x4454 = {
x4369.update(x3732.toInt, x4453)
}
()
 }
 
()
}
}
val x4458 = ()
val x4459 = x286 until x303 by x303 par 1
val x4460 = Array(x4459)
val x4461 = x286 until x5 by x303 par 1
val x4462 = Array(x4461)
val x3777 = x4370
for( x4460_vec0 <- x4460.apply(0.toInt)) {
  val x3785 = x4460_vec0.apply(0.toInt)
for( x4462_vec0 <- x4462.apply(0.toInt)) {
  val x3787 = x4462_vec0.apply(0.toInt)
val x3789 = Array(x3787)
val x4463 = {
x3789.map{addr => if (addr.toInt < x4369.length) x4369(addr.toInt) else x4369(0) }
}
val x4464 = {
x3789.map{addr => if (addr.toInt < x3777.length) x3777(addr.toInt) else x3777(0) }
}
val x4465 = {
x4464.apply(0)
}
val x3786 = {
x3785 < x303
}
val x3788 = {
x3787 < x5
}
val x3795 = {
x3786 && x3788
}
val x4466 = {
x4463.apply(0)
}
val x4467 = {
if (x3795) x4466 else x286
}
val x4468 = {
x4467 + x4465
}
val x4469 = Array(x4468)
val x4470 = {
x4469.zip(x3789).foreach{ case (v,a) => if (a.toInt < x3777.length) x3777(a.toInt) = v }
}
}
val x4472 = ()
}
val x4474 = ()
}
val x4476 = ()
val x4477 = {
scala.collection.mutable.Queue.fill(0.toInt)(x286)
}
val x4488 = {
{ 
val x4478 = x286 until x5 by x303 par 1
val x4479 = Array(x4478)
for( x4479_vec0 <- x4479.apply(0.toInt)) {
  val x3811 = x4479_vec0.apply(0.toInt)
val x3812 = Array(x3811)
val x4480 = {
x3812.map{addr => if (addr.toInt < x4370.length) x4370(addr.toInt) else x4370(0) }
}
val x3816 = {
x3811 < x5
}
val x3817 = Array(x3816)
val x4481 = {
x4480.apply(0)
}
val x4482 = Array(x4481)
val x4483 = {
x4482.zip(x3817).foreach{ case (v,e) => if (e) x4477.enqueue(v) }
}
}
val x4485 = ()
val x4486 = {
for (i <- 0 until x5.toInt) { if (i + x286.toInt < x4325.length) x4325(i + x286.toInt) = x4477.dequeue() }
}
()
 }
 
()
}
()
 }
 
()
}

x4490
}}

/**********/

