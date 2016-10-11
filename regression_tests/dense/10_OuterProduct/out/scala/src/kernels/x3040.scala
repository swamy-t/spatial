package generated.scala
object kernel_x3040 {
def apply(resourceInfo:generated.scala.ResourceInfo,x99:FixedPoint[Signed,B32,B0],x470:FixedPoint[Signed,B32,B0],x53:FixedPoint[Signed,B32,B0],x2825:Array[FixedPoint[Signed,B32,B0]],x2941:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x3040 = {
var i = x99
while (i < x470) {
{ 
val x472 = i
()
val x473 = {
x472.toInt
}
val x3035 = x2825(x473.toInt)
val x3036 = x2941(x473.toInt)
val x3037 = {
x3035 == x3036
}
val x3038 = {
assert(x3037)
}
()
 }
 
i += x53
}
}

x3040
}}

/**********/

