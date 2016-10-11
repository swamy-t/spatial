package generated.scala
object kernel_x1343 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:FixedPoint[Signed,B32,B0],x53:FixedPoint[Signed,B32,B0],x61:FixedPoint[Signed,B32,B0],x1250:Array[FixedPoint[Signed,B32,B0]],x64:FixedPoint[Signed,B32,B0],x75:FixedPoint[Signed,B32,B0],x1252:Array[FixedPoint[Signed,B32,B0]],x1251:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x1343 = {
{ 
val x1292 = {
Array.fill(x3.toInt)(x53)
}
val x1293 = {
scala.collection.mutable.Queue.fill(0.toInt)(x53)
}
val x1304 = {
{ 
val x1294 = {
for (i <- 0 until x3.toInt) { if (i + x53.toInt < x1250.length) x1293.enqueue( x1250(i + x53.toInt) ) else x1293.enqueue(x1250(0)) }
}
val x1295 = x53 until x3 by x64 par 1
val x1296 = Array(x1295)
for( x1296_vec0 <- x1296.apply(0.toInt)) {
  val x1068 = x1296_vec0.apply(0.toInt)
val x1297 = {
if (1 < x1293.length) {

val first = x1293.front
Array.tabulate(1){i => if (x1293.nonEmpty) x1293.dequeue() else first }
}
else {
Array.tabulate(1){i => x1293.dequeue() }
}
}
val x1072 = Array(x1068)
val x1298 = {
x1297.apply(0)
}
val x1299 = Array(x1298)
val x1300 = {
x1299.zip(x1072).foreach{ case (v,a) => if (a.toInt < x1292.length) x1292(a.toInt) = v }
}
}
val x1302 = ()
()
 }
 
()
}
val x1305 = x53 until x75 by x64 par 1
val x1306 = Array(x1305)
val x1307 = x53 until x3 by x64 par 1
val x1308 = Array(x1307)
val x1083 = x1292
for( x1306_vec0 <- x1306.apply(0.toInt)) {
  val x1091 = x1306_vec0.apply(0.toInt)
val x1309 = {
Array.fill(x3.toInt)(x53)
}
val x1310 = x53 until x3 by x64 par 1
val x1311 = Array(x1310)
for( x1311_vec0 <- x1311.apply(0.toInt)) {
  val x1095 = x1311_vec0.apply(0.toInt)
val x1312 = {
x1252.apply(0)
}
val x1099 = Array(x1095)
val x1313 = {
x1312 + x1095
}
val x1314 = Array(x1313)
val x1315 = {
x1314.zip(x1099).foreach{ case (v,a) => if (a.toInt < x1309.length) x1309(a.toInt) = v }
}
}
val x1317 = ()
for( x1308_vec0 <- x1308.apply(0.toInt)) {
  val x1106 = x1308_vec0.apply(0.toInt)
val x1108 = Array(x1106)
val x1318 = {
x1108.map{addr => if (addr.toInt < x1309.length) x1309(addr.toInt) else x1309(0) }
}
val x1319 = {
x1108.map{addr => if (addr.toInt < x1083.length) x1083(addr.toInt) else x1083(0) }
}
val x1320 = {
x1319.apply(0)
}
val x1105 = {
x1091 < x75
}
val x1107 = {
x1106 < x3
}
val x1114 = {
x1105 && x1107
}
val x1321 = {
x1318.apply(0)
}
val x1322 = {
if (x1114) x1321 else x53
}
val x1323 = {
x1322 + x1320
}
val x1324 = Array(x1323)
val x1325 = {
x1324.zip(x1108).foreach{ case (v,a) => if (a.toInt < x1083.length) x1083(a.toInt) = v }
}
}
val x1327 = ()
}
val x1329 = ()
val x1330 = {
scala.collection.mutable.Queue.fill(0.toInt)(x53)
}
val x1341 = {
{ 
val x1331 = x53 until x3 by x64 par 1
val x1332 = Array(x1331)
for( x1332_vec0 <- x1332.apply(0.toInt)) {
  val x1127 = x1332_vec0.apply(0.toInt)
val x1128 = Array(x1127)
val x1333 = {
x1128.map{addr => if (addr.toInt < x1292.length) x1292(addr.toInt) else x1292(0) }
}
val x1132 = {
x1127 < x3
}
val x1133 = Array(x1132)
val x1334 = {
x1333.apply(0)
}
val x1335 = Array(x1334)
val x1336 = {
x1335.zip(x1133).foreach{ case (v,e) => if (e) x1330.enqueue(v) }
}
}
val x1338 = ()
val x1339 = {
for (i <- 0 until x3.toInt) { if (i + x53.toInt < x1251.length) x1251(i + x53.toInt) = x1330.dequeue() }
}
()
 }
 
()
}
()
 }
 
()
}

x1343
}}

/**********/

