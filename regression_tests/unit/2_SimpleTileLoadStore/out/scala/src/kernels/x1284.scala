package generated.scala
object kernel_x1284 {
def apply(resourceInfo:generated.scala.ResourceInfo,x849:FixedPoint[Signed,B32,B0],x53:FixedPoint[Signed,B32,B0],x1238:Array[FixedPoint[Signed,B32,B0]],x69:FixedPoint[Signed,B32,B0],x1198:Array[FixedPoint[Signed,B32,B0]],x72:FixedPoint[Signed,B32,B0],x1239:Array[FixedPoint[Signed,B32,B0]],x1199:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x1284 = {
{ 
val x1242 = {
Array.fill(x849.toInt)(x53)
}
val x1243 = {
x1238.apply(0)
}
val x1244 = x53 until x1243 by x849 par 1
val x1245 = Array(x1244)
for( x1245_vec0 <- x1245.apply(0.toInt)) {
  val x1041 = x1245_vec0.apply(0.toInt)
val x1246 = {
scala.collection.mutable.Queue.fill(0.toInt)(x53)
}
val x1257 = {
{ 
val x1247 = {
for (i <- 0 until x849.toInt) { if (i + x1041.toInt < x1198.length) x1246.enqueue( x1198(i + x1041.toInt) ) else x1246.enqueue(x1198(0)) }
}
val x1248 = x53 until x849 by x72 par 1
val x1249 = Array(x1248)
for( x1249_vec0 <- x1249.apply(0.toInt)) {
  val x1046 = x1249_vec0.apply(0.toInt)
val x1250 = {
if (1 < x1246.length) {

val first = x1246.front
Array.tabulate(1){i => if (x1246.nonEmpty) x1246.dequeue() else first }
}
else {
Array.tabulate(1){i => x1246.dequeue() }
}
}
val x1050 = Array(x1046)
val x1251 = {
x1250.apply(0)
}
val x1252 = Array(x1251)
val x1253 = {
x1252.zip(x1050).foreach{ case (v,a) => if (a.toInt < x1242.length) x1242(a.toInt) = v }
}
}
val x1255 = ()
()
 }
 
()
}
val x1258 = {
Array.fill(x849.toInt)(x53)
}
val x1259 = x53 until x849 by x72 par 1
val x1260 = Array(x1259)
for( x1260_vec0 <- x1260.apply(0.toInt)) {
  val x1060 = x1260_vec0.apply(0.toInt)
val x1061 = Array(x1060)
val x1261 = {
x1061.map{addr => if (addr.toInt < x1242.length) x1242(addr.toInt) else x1242(0) }
}
val x1262 = {
x1239.apply(0)
}
val x1263 = {
x1261.apply(0)
}
val x1264 = {
x1263 * x1262
}
val x1265 = Array(x1264)
val x1266 = {
x1265.zip(x1061).foreach{ case (v,a) => if (a.toInt < x1258.length) x1258(a.toInt) = v }
}
}
val x1268 = ()
val x1269 = {
scala.collection.mutable.Queue.fill(0.toInt)(x53)
}
val x1280 = {
{ 
val x1270 = x53 until x849 by x72 par 1
val x1271 = Array(x1270)
for( x1271_vec0 <- x1271.apply(0.toInt)) {
  val x1074 = x1271_vec0.apply(0.toInt)
val x1075 = Array(x1074)
val x1272 = {
x1075.map{addr => if (addr.toInt < x1258.length) x1258(addr.toInt) else x1258(0) }
}
val x1079 = {
x1074 < x849
}
val x1080 = Array(x1079)
val x1273 = {
x1272.apply(0)
}
val x1274 = Array(x1273)
val x1275 = {
x1274.zip(x1080).foreach{ case (v,e) => if (e) x1269.enqueue(v) }
}
}
val x1277 = ()
val x1278 = {
for (i <- 0 until x849.toInt) { if (i + x1041.toInt < x1199.length) x1199(i + x1041.toInt) = x1269.dequeue() }
}
()
 }
 
()
}
}
val x1282 = ()
()
 }
 
()
}

x1284
}}

/**********/

