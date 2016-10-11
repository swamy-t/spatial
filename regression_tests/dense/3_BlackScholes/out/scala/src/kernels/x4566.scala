package generated.scala
object kernel_x4566 {
def apply(resourceInfo:generated.scala.ResourceInfo,x4026:Array[FixedPoint[Signed,B32,B0]],x3:FixedPoint[Signed,B32,B0],x2868:FixedPoint[Signed,B32,B0],x305:FixedPoint[Unsign,B32,B0],x307:FloatPoint[B24,B8],x316:FixedPoint[Signed,B32,B0],x4029:Array[FixedPoint[Unsign,B32,B0]],x319:FixedPoint[Signed,B32,B0],x4030:Array[FloatPoint[B24,B8]],x4031:Array[FloatPoint[B24,B8]],x4032:Array[FloatPoint[B24,B8]],x4033:Array[FloatPoint[B24,B8]],x4034:Array[FloatPoint[B24,B8]],x412:FloatPoint[B24,B8],x423:FloatPoint[B24,B8],x426:FloatPoint[B24,B8],x429:FloatPoint[B24,B8],x428:FloatPoint[B24,B8],x437:FloatPoint[B24,B8],x445:FloatPoint[B24,B8],x443:FloatPoint[B24,B8],x439:FloatPoint[B24,B8],x441:FloatPoint[B24,B8],x4035:Array[FloatPoint[B24,B8]]): Unit = {
val x4566 = {
{ 
val x4276 = {
x4026.apply(0)
}
val x4277 = x3 until x4276 by x2868 par 1
val x4278 = Array(x4277)
for( x4278_vec0 <- x4278.apply(0.toInt)) {
  val x3496 = x4278_vec0.apply(0.toInt)
val x4279 = {
Array.fill(x2868.toInt)(x305)
}
val x4280 = {
Array.fill(x2868.toInt)(x307)
}
val x4281 = {
Array.fill(x2868.toInt)(x307)
}
val x4282 = {
Array.fill(x2868.toInt)(x307)
}
val x4283 = {
Array.fill(x2868.toInt)(x307)
}
val x4284 = {
Array.fill(x2868.toInt)(x307)
}
val x4364 = {
{ 
val x4285 = {
scala.collection.mutable.Queue.fill(0.toInt)(x305)
}
val x4297 = {
{ 
val x4286 = {
for (i <- 0 until x2868.toInt) { if (i + x3496.toInt < x4029.length) x4285.enqueue( x4029(i + x3496.toInt) ) else x4285.enqueue(x4029(0)) }
}
val x4287 = x3 until x2868 by x319 par 2
val x4288 = Array(x4287)
for( x4288_vec0 <- x4288.apply(0.toInt)) {
  val x3507 = x4288_vec0.apply(0.toInt)
  val x3508 = x4288_vec0.apply(1.toInt)
val x4289 = {
if (2 < x4285.length) {

val first = x4285.front
Array.tabulate(2){i => if (x4285.nonEmpty) x4285.dequeue() else first }
}
else {
Array.tabulate(2){i => x4285.dequeue() }
}
}
val x3514 = Array(x3507,x3508)
val x4290 = {
x4289.apply(0)
}
val x4291 = {
x4289.apply(1)
}
val x4292 = Array(x4290,x4291)
val x4293 = {
x4292.zip(x3514).foreach{ case (v,a) => if (a.toInt < x4279.length) x4279(a.toInt) = v }
}
}
val x4295 = ()
()
 }
 
()
}
val x4298 = {
scala.collection.mutable.Queue.fill(0.toInt)(x307)
}
val x4310 = {
{ 
val x4299 = {
for (i <- 0 until x2868.toInt) { if (i + x3496.toInt < x4030.length) x4298.enqueue( x4030(i + x3496.toInt) ) else x4298.enqueue(x4030(0)) }
}
val x4300 = x3 until x2868 by x319 par 2
val x4301 = Array(x4300)
for( x4301_vec0 <- x4301.apply(0.toInt)) {
  val x3526 = x4301_vec0.apply(0.toInt)
  val x3527 = x4301_vec0.apply(1.toInt)
val x4302 = {
if (2 < x4298.length) {

val first = x4298.front
Array.tabulate(2){i => if (x4298.nonEmpty) x4298.dequeue() else first }
}
else {
Array.tabulate(2){i => x4298.dequeue() }
}
}
val x3532 = Array(x3526,x3527)
val x4303 = {
x4302.apply(0)
}
val x4304 = {
x4302.apply(1)
}
val x4305 = Array(x4303,x4304)
val x4306 = {
x4305.zip(x3532).foreach{ case (v,a) => if (a.toInt < x4280.length) x4280(a.toInt) = v }
}
}
val x4308 = ()
()
 }
 
()
}
val x4311 = {
scala.collection.mutable.Queue.fill(0.toInt)(x307)
}
val x4323 = {
{ 
val x4312 = {
for (i <- 0 until x2868.toInt) { if (i + x3496.toInt < x4031.length) x4311.enqueue( x4031(i + x3496.toInt) ) else x4311.enqueue(x4031(0)) }
}
val x4313 = x3 until x2868 by x319 par 2
val x4314 = Array(x4313)
for( x4314_vec0 <- x4314.apply(0.toInt)) {
  val x3544 = x4314_vec0.apply(0.toInt)
  val x3545 = x4314_vec0.apply(1.toInt)
val x4315 = {
if (2 < x4311.length) {

val first = x4311.front
Array.tabulate(2){i => if (x4311.nonEmpty) x4311.dequeue() else first }
}
else {
Array.tabulate(2){i => x4311.dequeue() }
}
}
val x3550 = Array(x3544,x3545)
val x4316 = {
x4315.apply(0)
}
val x4317 = {
x4315.apply(1)
}
val x4318 = Array(x4316,x4317)
val x4319 = {
x4318.zip(x3550).foreach{ case (v,a) => if (a.toInt < x4281.length) x4281(a.toInt) = v }
}
}
val x4321 = ()
()
 }
 
()
}
val x4324 = {
scala.collection.mutable.Queue.fill(0.toInt)(x307)
}
val x4336 = {
{ 
val x4325 = {
for (i <- 0 until x2868.toInt) { if (i + x3496.toInt < x4032.length) x4324.enqueue( x4032(i + x3496.toInt) ) else x4324.enqueue(x4032(0)) }
}
val x4326 = x3 until x2868 by x319 par 2
val x4327 = Array(x4326)
for( x4327_vec0 <- x4327.apply(0.toInt)) {
  val x3562 = x4327_vec0.apply(0.toInt)
  val x3563 = x4327_vec0.apply(1.toInt)
val x4328 = {
if (2 < x4324.length) {

val first = x4324.front
Array.tabulate(2){i => if (x4324.nonEmpty) x4324.dequeue() else first }
}
else {
Array.tabulate(2){i => x4324.dequeue() }
}
}
val x3568 = Array(x3562,x3563)
val x4329 = {
x4328.apply(0)
}
val x4330 = {
x4328.apply(1)
}
val x4331 = Array(x4329,x4330)
val x4332 = {
x4331.zip(x3568).foreach{ case (v,a) => if (a.toInt < x4282.length) x4282(a.toInt) = v }
}
}
val x4334 = ()
()
 }
 
()
}
val x4337 = {
scala.collection.mutable.Queue.fill(0.toInt)(x307)
}
val x4349 = {
{ 
val x4338 = {
for (i <- 0 until x2868.toInt) { if (i + x3496.toInt < x4033.length) x4337.enqueue( x4033(i + x3496.toInt) ) else x4337.enqueue(x4033(0)) }
}
val x4339 = x3 until x2868 by x319 par 2
val x4340 = Array(x4339)
for( x4340_vec0 <- x4340.apply(0.toInt)) {
  val x3580 = x4340_vec0.apply(0.toInt)
  val x3581 = x4340_vec0.apply(1.toInt)
val x4341 = {
if (2 < x4337.length) {

val first = x4337.front
Array.tabulate(2){i => if (x4337.nonEmpty) x4337.dequeue() else first }
}
else {
Array.tabulate(2){i => x4337.dequeue() }
}
}
val x3586 = Array(x3580,x3581)
val x4342 = {
x4341.apply(0)
}
val x4343 = {
x4341.apply(1)
}
val x4344 = Array(x4342,x4343)
val x4345 = {
x4344.zip(x3586).foreach{ case (v,a) => if (a.toInt < x4283.length) x4283(a.toInt) = v }
}
}
val x4347 = ()
()
 }
 
()
}
val x4350 = {
scala.collection.mutable.Queue.fill(0.toInt)(x307)
}
val x4362 = {
{ 
val x4351 = {
for (i <- 0 until x2868.toInt) { if (i + x3496.toInt < x4034.length) x4350.enqueue( x4034(i + x3496.toInt) ) else x4350.enqueue(x4034(0)) }
}
val x4352 = x3 until x2868 by x319 par 2
val x4353 = Array(x4352)
for( x4353_vec0 <- x4353.apply(0.toInt)) {
  val x3598 = x4353_vec0.apply(0.toInt)
  val x3599 = x4353_vec0.apply(1.toInt)
val x4354 = {
if (2 < x4350.length) {

val first = x4350.front
Array.tabulate(2){i => if (x4350.nonEmpty) x4350.dequeue() else first }
}
else {
Array.tabulate(2){i => x4350.dequeue() }
}
}
val x3604 = Array(x3598,x3599)
val x4355 = {
x4354.apply(0)
}
val x4356 = {
x4354.apply(1)
}
val x4357 = Array(x4355,x4356)
val x4358 = {
x4357.zip(x3604).foreach{ case (v,a) => if (a.toInt < x4284.length) x4284(a.toInt) = v }
}
}
val x4360 = ()
()
 }
 
()
}
()
 }
 
()
}
val x4365 = {
Array.fill(x2868.toInt)(x307)
}
val x4366 = x3 until x2868 by x319 par 2
val x4367 = Array(x4366)
for( x4367_vec0 <- x4367.apply(0.toInt)) {
  val x3617 = x4367_vec0.apply(0.toInt)
  val x3618 = x4367_vec0.apply(1.toInt)
val x3619 = Array(x3617,x3618)
val x4368 = {
x3619.map{addr => if (addr.toInt < x4280.length) x4280(addr.toInt) else x4280(0) }
}
val x4369 = {
x3619.map{addr => if (addr.toInt < x4281.length) x4281(addr.toInt) else x4281(0) }
}
val x4370 = {
x3619.map{addr => if (addr.toInt < x4282.length) x4282(addr.toInt) else x4282(0) }
}
val x4371 = {
x3619.map{addr => if (addr.toInt < x4283.length) x4283(addr.toInt) else x4283(0) }
}
val x4372 = {
x3619.map{addr => if (addr.toInt < x4284.length) x4284(addr.toInt) else x4284(0) }
}
val x4373 = {
x3619.map{addr => if (addr.toInt < x4279.length) x4279(addr.toInt) else x4279(0) }
}
val x4374 = {
x4368.apply(0)
}
val x4375 = {
x4369.apply(0)
}
val x4376 = {
x4374 / x4375
}
val x4377 = {
FloatPoint.log(x4376)
}
val x4378 = {
x4372.apply(0)
}
val x4379 = {
x4370.apply(0)
}
val x4380 = {
x4371.apply(0)
}
val x4381 = {
x4380 * x4380
}
val x4382 = {
x4381 * x412
}
val x4383 = {
x4379 + x4382
}
val x4384 = {
x4383 * x4378
}
val x4385 = {
x4384 + x4377
}
val x4386 = {
FloatPoint.sqrt(x4378)
}
val x4387 = {
x4380 * x4386
}
val x4388 = {
x4387 * x4387
}
val x4389 = {
x4385 / x4388
}
val x4390 = {
FloatPoint.abs(x4389)
}
val x4391 = {
x4390 * x4390
}
val x4392 = {
x4391 * x423
}
val x4393 = {
FloatPoint.exp(x4392)
}
val x4394 = {
x4393 * x426
}
val x4395 = {
x4390 * x429
}
val x4396 = {
x4395 + x428
}
val x4397 = {
x428 / x4396
}
val x4398 = {
x4397 * x437
}
val x4399 = {
x4397 * x4397
}
val x4400 = {
x4399 * x4397
}
val x4401 = {
x4400 * x4397
}
val x4402 = {
x4401 * x4397
}
val x4403 = {
x4402 * x445
}
val x4404 = {
x4401 * x443
}
val x4405 = {
x4399 * x439
}
val x4406 = {
x4400 * x441
}
val x4407 = {
x4405 + x4406
}
val x4408 = {
x4407 + x4404
}
val x4409 = {
x4408 + x4403
}
val x4410 = {
x4409 + x4398
}
val x4411 = {
x4410 * x4394
}
val x4412 = {
-x4411
}
val x4413 = {
x4412 + x428
}
val x4414 = {
x4389 < x307
}
val x4415 = {
if (x4414) x4411 else x4413
}
val x4416 = {
x4374 * x4415
}
val x4417 = {
x4389 - x4387
}
val x4418 = {
FloatPoint.abs(x4417)
}
val x4419 = {
x4418 * x4418
}
val x4420 = {
x4419 * x423
}
val x4421 = {
FloatPoint.exp(x4420)
}
val x4422 = {
x4421 * x426
}
val x4423 = {
x4418 * x429
}
val x4424 = {
x4423 + x428
}
val x4425 = {
x428 / x4424
}
val x4426 = {
x4425 * x437
}
val x4427 = {
x4425 * x4425
}
val x4428 = {
x4427 * x4425
}
val x4429 = {
x4428 * x4425
}
val x4430 = {
x4429 * x4425
}
val x4431 = {
x4430 * x445
}
val x4432 = {
x4429 * x443
}
val x4433 = {
x4427 * x439
}
val x4434 = {
x4428 * x441
}
val x4435 = {
x4433 + x4434
}
val x4436 = {
x4435 + x4432
}
val x4437 = {
x4436 + x4431
}
val x4438 = {
x4437 + x4426
}
val x4439 = {
x4438 * x4422
}
val x4440 = {
-x4439
}
val x4441 = {
x4440 + x428
}
val x4442 = {
x4417 < x307
}
val x4443 = {
if (x4442) x4439 else x4441
}
val x4444 = {
-x4379
}
val x4445 = {
x4444 * x4378
}
val x4446 = {
FloatPoint.exp(x4445)
}
val x4447 = {
x4375 * x4446
}
val x4448 = {
x4447 * x4443
}
val x4449 = {
x4416 - x4448
}
val x4450 = {
-x4443
}
val x4451 = {
x4450 + x428
}
val x4452 = {
x4447 * x4451
}
val x4453 = {
-x4415
}
val x4454 = {
x4453 + x428
}
val x4455 = {
x4374 * x4454
}
val x4456 = {
x4452 - x4455
}
val x4457 = {
x4373.apply(0)
}
val x4458 = {
x4457 == x305
}
val x4459 = {
if (x4458) x4456 else x4449
}
val x4460 = {
x4368.apply(1)
}
val x4461 = {
x4369.apply(1)
}
val x4462 = {
x4460 / x4461
}
val x4463 = {
FloatPoint.log(x4462)
}
val x4464 = {
x4372.apply(1)
}
val x4465 = {
x4370.apply(1)
}
val x4466 = {
x4371.apply(1)
}
val x4467 = {
x4466 * x4466
}
val x4468 = {
x4467 * x412
}
val x4469 = {
x4465 + x4468
}
val x4470 = {
x4469 * x4464
}
val x4471 = {
x4470 + x4463
}
val x4472 = {
FloatPoint.sqrt(x4464)
}
val x4473 = {
x4466 * x4472
}
val x4474 = {
x4473 * x4473
}
val x4475 = {
x4471 / x4474
}
val x4476 = {
FloatPoint.abs(x4475)
}
val x4477 = {
x4476 * x4476
}
val x4478 = {
x4477 * x423
}
val x4479 = {
FloatPoint.exp(x4478)
}
val x4480 = {
x4479 * x426
}
val x4481 = {
x4476 * x429
}
val x4482 = {
x4481 + x428
}
val x4483 = {
x428 / x4482
}
val x4484 = {
x4483 * x437
}
val x4485 = {
x4483 * x4483
}
val x4486 = {
x4485 * x4483
}
val x4487 = {
x4486 * x4483
}
val x4488 = {
x4487 * x4483
}
val x4489 = {
x4488 * x445
}
val x4490 = {
x4487 * x443
}
val x4491 = {
x4485 * x439
}
val x4492 = {
x4486 * x441
}
val x4493 = {
x4491 + x4492
}
val x4494 = {
x4493 + x4490
}
val x4495 = {
x4494 + x4489
}
val x4496 = {
x4495 + x4484
}
val x4497 = {
x4496 * x4480
}
val x4498 = {
-x4497
}
val x4499 = {
x4498 + x428
}
val x4500 = {
x4475 < x307
}
val x4501 = {
if (x4500) x4497 else x4499
}
val x4502 = {
x4460 * x4501
}
val x4503 = {
x4475 - x4473
}
val x4504 = {
FloatPoint.abs(x4503)
}
val x4505 = {
x4504 * x4504
}
val x4506 = {
x4505 * x423
}
val x4507 = {
FloatPoint.exp(x4506)
}
val x4508 = {
x4507 * x426
}
val x4509 = {
x4504 * x429
}
val x4510 = {
x4509 + x428
}
val x4511 = {
x428 / x4510
}
val x4512 = {
x4511 * x437
}
val x4513 = {
x4511 * x4511
}
val x4514 = {
x4513 * x4511
}
val x4515 = {
x4514 * x4511
}
val x4516 = {
x4515 * x4511
}
val x4517 = {
x4516 * x445
}
val x4518 = {
x4515 * x443
}
val x4519 = {
x4513 * x439
}
val x4520 = {
x4514 * x441
}
val x4521 = {
x4519 + x4520
}
val x4522 = {
x4521 + x4518
}
val x4523 = {
x4522 + x4517
}
val x4524 = {
x4523 + x4512
}
val x4525 = {
x4524 * x4508
}
val x4526 = {
-x4525
}
val x4527 = {
x4526 + x428
}
val x4528 = {
x4503 < x307
}
val x4529 = {
if (x4528) x4525 else x4527
}
val x4530 = {
-x4465
}
val x4531 = {
x4530 * x4464
}
val x4532 = {
FloatPoint.exp(x4531)
}
val x4533 = {
x4461 * x4532
}
val x4534 = {
x4533 * x4529
}
val x4535 = {
x4502 - x4534
}
val x4536 = {
-x4529
}
val x4537 = {
x4536 + x428
}
val x4538 = {
x4533 * x4537
}
val x4539 = {
-x4501
}
val x4540 = {
x4539 + x428
}
val x4541 = {
x4460 * x4540
}
val x4542 = {
x4538 - x4541
}
val x4543 = {
x4373.apply(1)
}
val x4544 = {
x4543 == x305
}
val x4545 = {
if (x4544) x4542 else x4535
}
val x4546 = Array(x4459,x4545)
val x4547 = {
x4546.zip(x3619).foreach{ case (v,a) => if (a.toInt < x4365.length) x4365(a.toInt) = v }
}
}
val x4549 = ()
val x4550 = {
scala.collection.mutable.Queue.fill(0.toInt)(x307)
}
val x4562 = {
{ 
val x4551 = x3 until x2868 by x319 par 2
val x4552 = Array(x4551)
for( x4552_vec0 <- x4552.apply(0.toInt)) {
  val x3807 = x4552_vec0.apply(0.toInt)
  val x3808 = x4552_vec0.apply(1.toInt)
val x3809 = Array(x3807,x3808)
val x4553 = {
x3809.map{addr => if (addr.toInt < x4365.length) x4365(addr.toInt) else x4365(0) }
}
val x3814 = {
x3807 < x2868
}
val x3815 = {
x3808 < x2868
}
val x3816 = Array(x3814,x3815)
val x4554 = {
x4553.apply(0)
}
val x4555 = {
x4553.apply(1)
}
val x4556 = Array(x4554,x4555)
val x4557 = {
x4556.zip(x3816).foreach{ case (v,e) => if (e) x4550.enqueue(v) }
}
}
val x4559 = ()
val x4560 = {
for (i <- 0 until x2868.toInt) { if (i + x3496.toInt < x4035.length) x4035(i + x3496.toInt) = x4550.dequeue() }
}
()
 }
 
()
}
}
val x4564 = ()
()
 }
 
()
}

x4566
}}

/**********/

