package generated.scala
object kernel_x1095 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1:FixedPoint[Signed,B32,B0],x50:FixedPoint[Signed,B32,B0],x1037:Array[FixedPoint[Signed,B32,B0]],x1038:Array[FixedPoint[Signed,B32,B0]],x66:FixedPoint[Signed,B32,B0],x1039:Array[FixedPoint[Signed,B32,B0]],x72:Boolean): Unit = {
val x1095 = {
{ 
val x1078 = {
scala.collection.mutable.Queue.fill(0.toInt)(x50)
}
val x1093 = {
{ 
val x1086 = {
{ 
val x1081 = {
{ 
val x1079 = {
for (i <- 0 until x1.toInt) { if (i + x50.toInt < x1037.length) x1078.enqueue( x1037(i + x50.toInt) ) else x1078.enqueue(x1037(0)) }
}
()
 }
 
()
}
val x1084 = {
{ 
val x1082 = {
for (i <- 0 until x1.toInt) { if (i + x50.toInt < x1038.length) x1038(i + x50.toInt) = x1078.dequeue() }
}
()
 }
 
()
}
()
 }
 
()
}
val x1087 = x50 until x1 by x66 par 1
val x1088 = Array(x1087)
for( x1088_vec0 <- x1088.apply(0.toInt)) {
  val x922 = x1088_vec0.apply(0.toInt)
val x1089 = {
if (x72) x1039.update(0, x922)
}
}
val x1091 = ()
()
 }
 
()
}
()
 }
 
()
}

x1095
}}

/**********/

