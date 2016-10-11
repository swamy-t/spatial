package generated.scala
object kernel_x1306 {
def apply(resourceInfo:generated.scala.ResourceInfo,x54:FixedPoint[Signed,B32,B0],x49:FixedPoint[Signed,B32,B0],x1217:Array[FixedPoint[Signed,B32,B0]],x62:FixedPoint[Signed,B32,B0],x71:FixedPoint[Signed,B32,B0],x1220:Array[FixedPoint[Signed,B32,B0]],x1221:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x1306 = {
{ 
val x1260 = {
Array.fill(x54.toInt)(x49)
}
val x1261 = {
x1217.apply(0)
}
val x1262 = x49 until x1261 by x54 par 1
val x1263 = Array(x1262)
val x1264 = x49 until x54 by x62 par 1
val x1265 = Array(x1264)
val x1046 = x1260
for( x1263_vec0 <- x1263.apply(0.toInt)) {
  val x1054 = x1263_vec0.apply(0.toInt)
val x1266 = {
Array.fill(x54.toInt)(x49)
}
val x1267 = {
scala.collection.mutable.Queue.fill(0.toInt)(x49)
}
val x1278 = {
{ 
val x1268 = {
for (i <- 0 until x54.toInt) { if (i + x1054.toInt < x1220.length) x1267.enqueue( x1220(i + x1054.toInt) ) else x1267.enqueue(x1220(0)) }
}
val x1269 = x49 until x54 by x62 par 1
val x1270 = Array(x1269)
for( x1270_vec0 <- x1270.apply(0.toInt)) {
  val x1060 = x1270_vec0.apply(0.toInt)
val x1271 = {
if (1 < x1267.length) {

val first = x1267.front
Array.tabulate(1){i => if (x1267.nonEmpty) x1267.dequeue() else first }
}
else {
Array.tabulate(1){i => x1267.dequeue() }
}
}
val x1064 = Array(x1060)
val x1272 = {
x1271.apply(0)
}
val x1273 = Array(x1272)
val x1274 = {
x1273.zip(x1064).foreach{ case (v,a) => if (a.toInt < x1266.length) x1266(a.toInt) = v }
}
}
val x1276 = ()
()
 }
 
()
}
for( x1265_vec0 <- x1265.apply(0.toInt)) {
  val x1073 = x1265_vec0.apply(0.toInt)
val x1075 = Array(x1073)
val x1279 = {
x1075.map{addr => if (addr.toInt < x1266.length) x1266(addr.toInt) else x1266(0) }
}
val x1280 = {
x1075.map{addr => if (addr.toInt < x1046.length) x1046(addr.toInt) else x1046(0) }
}
val x1281 = {
x1280.apply(0)
}
val x1282 = {
x1279.apply(0)
}
val x1074 = {
x1073 < x54
}
val x1283 = {
x1054 < x1261
}
val x1284 = {
x1283 && x1074
}
val x1285 = {
if (x1284) x1282 else x49
}
val x1286 = {
x1285 + x1281
}
val x1287 = Array(x1286)
val x1288 = {
x1287.zip(x1075).foreach{ case (v,a) => if (a.toInt < x1046.length) x1046(a.toInt) = v }
}
}
val x1290 = ()
}
val x1292 = ()
val x1293 = {
scala.collection.mutable.Queue.fill(0.toInt)(x49)
}
val x1304 = {
{ 
val x1294 = x49 until x54 by x62 par 1
val x1295 = Array(x1294)
for( x1295_vec0 <- x1295.apply(0.toInt)) {
  val x1094 = x1295_vec0.apply(0.toInt)
val x1095 = Array(x1094)
val x1296 = {
x1095.map{addr => if (addr.toInt < x1260.length) x1260(addr.toInt) else x1260(0) }
}
val x1099 = {
x1094 < x54
}
val x1100 = Array(x1099)
val x1297 = {
x1296.apply(0)
}
val x1298 = Array(x1297)
val x1299 = {
x1298.zip(x1100).foreach{ case (v,e) => if (e) x1293.enqueue(v) }
}
}
val x1301 = ()
val x1302 = {
for (i <- 0 until x54.toInt) { if (i + x49.toInt < x1221.length) x1221(i + x49.toInt) = x1293.dequeue() }
}
()
 }
 
()
}
()
 }
 
()
}

x1306
}}

/**********/

