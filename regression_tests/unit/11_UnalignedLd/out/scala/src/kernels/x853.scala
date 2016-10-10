package generated.scala
object kernel_x853 {
def apply(resourceInfo:generated.scala.ResourceInfo,x52:FixedPoint[Signed,B32,B0],x49:FixedPoint[Signed,B32,B0],x57:FixedPoint[Signed,B32,B0],x783:Array[FixedPoint[Signed,B32,B0]],x60:FixedPoint[Signed,B32,B0],x90:Boolean,x784:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x853 = {
{ 
val x823 = {
Array.fill(x52.toInt)(x49)
}
val x837 = {
{ 
val x824 = {
scala.collection.mutable.Queue.fill(0.toInt)(x49)
}
val x835 = {
{ 
val x825 = {
for (i <- 0 until x52.toInt) { if (i + x49.toInt < x783.length) x824.enqueue( x783(i + x49.toInt) ) else x824.enqueue(x783(0)) }
}
val x826 = x49 until x52 by x60 par 1
val x827 = Array(x826)
for( x827_vec0 <- x827.apply(0.toInt)) {
  val x687 = x827_vec0.apply(0.toInt)
val x828 = {
if (1 < x824.length) {

val first = x824.front
Array.tabulate(1){i => if (x824.nonEmpty) x824.dequeue() else first }
}
else {
Array.tabulate(1){i => x824.dequeue() }
}
}
val x691 = Array(x687)
val x829 = {
x828.apply(0)
}
val x830 = Array(x829)
val x831 = {
x830.zip(x691).foreach{ case (v,a) => if (a.toInt < x823.length) x823(a.toInt) = v }
}
}
val x833 = ()
()
 }
 
()
}
()
 }
 
()
}
val x838 = {
Array(x49)
}
val x839 = x49 until x52 by x60 par 1
val x840 = Array(x839)
val x703 = x838
for( x840_vec0 <- x840.apply(0.toInt)) {
  val x711 = x840_vec0.apply(0.toInt)
val x712 = Array(x711)
val x841 = {
x712.map{addr => if (addr.toInt < x823.length) x823(addr.toInt) else x823(0) }
}
val x842 = {
x703.apply(0)
}
val x843 = {
x841.apply(0)
}
val x844 = {
x843 + x842
}
val x845 = {
if (x90) x703.update(0, x844)
}
}
val x847 = ()
val x848 = {
x838.apply(0)
}
val x851 = {
{ 
val x849 = {
if (x90) x784.update(0, x848)
}
()
 }
 
()
}
()
 }
 
()
}

x853
}}

/**********/

