package generated.scala
object kernel_x1204 {
def apply(resourceInfo:generated.scala.ResourceInfo,x805:FixedPoint[Signed,B32,B0],x49:FixedPoint[Signed,B32,B0],x1130:Array[FixedPoint[Signed,B32,B0]],x1133:Array[FixedPoint[Signed,B32,B0]],x71:FixedPoint[Signed,B32,B0],x82:FixedPoint[Signed,B32,B0],x1134:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x1204 = {
{ 
val x1173 = {
scala.collection.mutable.Queue.fill(0.toInt)(x49)
}
val x1174 = {
x1130.apply(0)
}
val x1175 = x49 until x1174 by x805 par 1
val x1176 = Array(x1175)
for( x1176_vec0 <- x1176.apply(0.toInt)) {
  val x987 = x1176_vec0.apply(0.toInt)
val x1179 = {
{ 
val x1177 = {
for (i <- 0 until x805.toInt) { if (i + x987.toInt < x1133.length) x1173.enqueue( x1133(i + x987.toInt) ) else x1173.enqueue(x1133(0)) }
}
()
 }
 
()
}
val x1180 = {
Array.fill(x805.toInt)(x49)
}
val x1181 = x49 until x805 by x71 par 1
val x1182 = Array(x1181)
for( x1182_vec0 <- x1182.apply(0.toInt)) {
  val x994 = x1182_vec0.apply(0.toInt)
val x1183 = {
if (1 < x1173.length) {

val first = x1173.front
Array.tabulate(1){i => if (x1173.nonEmpty) x1173.dequeue() else first }
}
else {
Array.tabulate(1){i => x1173.dequeue() }
}
}
val x998 = Array(x994)
val x1184 = {
x1183.apply(0)
}
val x1185 = Array(x1184)
val x1186 = {
x1185.zip(x998).foreach{ case (v,a) => if (a.toInt < x1180.length) x1180(a.toInt) = v }
}
}
val x1188 = ()
val x1189 = {
scala.collection.mutable.Queue.fill(0.toInt)(x49)
}
val x1200 = {
{ 
val x1190 = x49 until x805 by x71 par 1
val x1191 = Array(x1190)
for( x1191_vec0 <- x1191.apply(0.toInt)) {
  val x1006 = x1191_vec0.apply(0.toInt)
val x1007 = Array(x1006)
val x1192 = {
x1007.map{addr => if (addr.toInt < x1180.length) x1180(addr.toInt) else x1180(0) }
}
val x1011 = {
x1006 < x805
}
val x1012 = Array(x1011)
val x1193 = {
x1192.apply(0)
}
val x1194 = Array(x1193)
val x1195 = {
x1194.zip(x1012).foreach{ case (v,e) => if (e) x1189.enqueue(v) }
}
}
val x1197 = ()
val x1198 = {
for (i <- 0 until x805.toInt) { if (i + x987.toInt < x1134.length) x1134(i + x987.toInt) = x1189.dequeue() }
}
()
 }
 
()
}
}
val x1202 = ()
()
 }
 
()
}

x1204
}}

/**********/

