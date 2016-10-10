package generated.scala
object kernel_x1088 {
def apply(resourceInfo:generated.scala.ResourceInfo,x54:FixedPoint[Signed,B32,B0],x48:FixedPoint[Signed,B32,B0],x1:FixedPoint[Signed,B32,B0],x71:FixedPoint[Signed,B32,B0],x73:FixedPoint[Signed,B32,B0],x116:Boolean,x1003:Array[FixedPoint[Signed,B32,B0]],x1004:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x1088 = {
{ 
val x1043 = x54 until x48 by x48 par 1
val x1044 = x54 until x48 by x48 par 1
val x1045 = Array(x1043, x1044)
for( x1045_vec0 <- x1045.apply(0.toInt)) {
  val x868 = x1045_vec0.apply(0.toInt)
for( x1045_vec1 <- x1045.apply(1.toInt)) {
  val x869 = x1045_vec1.apply(0.toInt)
val x1046 = {
Array.fill(x1.toInt)(x54)
}
val x1047 = {
scala.collection.mutable.Queue.fill(0.toInt)(x54)
}
val x1048 = x54 until x48 by x73 par 1
val x1049 = Array(x1048)
for( x1049_vec0 <- x1049.apply(0.toInt)) {
  val x874 = x1049_vec0.apply(0.toInt)
val x1050 = {
Array(x54)
}
val x1053 = {
{ 
val x876 = {
x868 + x874
}
val x877 = {
x876 * x48
}
val x878 = {
x877 + x869
}
val x1051 = {
if (x116) x1050.update(0, x878)
}
()
 }
 
()
}
val x1054 = {
x1050.apply(0)
}
val x1055 = {
for (i <- 0 until x48.toInt) { if (i + x1054.toInt < x1003.length) x1047.enqueue( x1003(i + x1054.toInt) ) else x1047.enqueue(x1003(0)) }
}
val x1056 = x54 until x48 by x73 par 1
val x1057 = Array(x1056)
for( x1057_vec0 <- x1057.apply(0.toInt)) {
  val x886 = x1057_vec0.apply(0.toInt)
val x1058 = {
if (1 < x1047.length) {

val first = x1047.front
Array.tabulate(1){i => if (x1047.nonEmpty) x1047.dequeue() else first }
}
else {
Array.tabulate(1){i => x1047.dequeue() }
}
}
val x889 = {
x874 * x48
}
val x890 = {
x889 + x886
}
val x892 = Array(x890)
val x1059 = {
x1058.apply(0)
}
val x1060 = Array(x1059)
val x1061 = {
x1060.zip(x892).foreach{ case (v,a) => if (a.toInt < x1046.length) x1046(a.toInt) = v }
}
}
val x1063 = ()
}
val x1065 = ()
val x1066 = {
scala.collection.mutable.Queue.fill(0.toInt)(x54)
}
val x1067 = x54 until x48 by x73 par 1
val x1068 = Array(x1067)
for( x1068_vec0 <- x1068.apply(0.toInt)) {
  val x902 = x1068_vec0.apply(0.toInt)
val x1069 = x54 until x48 by x73 par 1
val x1070 = Array(x1069)
for( x1070_vec0 <- x1070.apply(0.toInt)) {
  val x905 = x1070_vec0.apply(0.toInt)
val x906 = {
x902 * x48
}
val x907 = {
x906 + x905
}
val x908 = Array(x907)
val x1071 = {
x908.map{addr => if (addr.toInt < x1046.length) x1046(addr.toInt) else x1046(0) }
}
val x912 = {
x905 < x48
}
val x913 = Array(x912)
val x1072 = {
x1071.apply(0)
}
val x1073 = Array(x1072)
val x1074 = {
x1073.zip(x913).foreach{ case (v,e) => if (e) x1066.enqueue(v) }
}
}
val x1076 = ()
val x1077 = {
Array(x54)
}
val x1080 = {
{ 
val x919 = {
x868 + x902
}
val x920 = {
x919 * x48
}
val x921 = {
x920 + x869
}
val x1078 = {
if (x116) x1077.update(0, x921)
}
()
 }
 
()
}
val x1081 = {
x1077.apply(0)
}
val x1082 = {
for (i <- 0 until x48.toInt) { if (i + x1081.toInt < x1004.length) x1004(i + x1081.toInt) = x1066.dequeue() }
}
}
val x1084 = ()
}}
val x1086 = ()
()
 }
 
()
}

x1088
}}

/**********/

