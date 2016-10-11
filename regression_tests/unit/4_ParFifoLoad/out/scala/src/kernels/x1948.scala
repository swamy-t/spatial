package generated.scala
object kernel_x1948 {
def apply(resourceInfo:generated.scala.ResourceInfo,x159:FixedPoint[Signed,B32,B0],x96:FixedPoint[Signed,B32,B0],x1833:Array[FixedPoint[Signed,B32,B0]],x1836:Array[FixedPoint[Signed,B32,B0]],x1837:Array[FixedPoint[Signed,B32,B0]],x126:FixedPoint[Signed,B32,B0],x146:Boolean,x1838:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x1948 = {
{ 
val x1915 = {
scala.collection.mutable.Queue.fill(0.toInt)(x96)
}
val x1916 = {
scala.collection.mutable.Queue.fill(0.toInt)(x96)
}
val x1917 = {
x1833.apply(0)
}
val x1918 = x96 until x1917 by x159 par 1
val x1919 = Array(x1918)
for( x1919_vec0 <- x1919.apply(0.toInt)) {
  val x1614 = x1919_vec0.apply(0.toInt)
val x1927 = {
{ 
val x1922 = {
{ 
val x1920 = {
for (i <- 0 until x159.toInt) { if (i + x1614.toInt < x1836.length) x1915.enqueue( x1836(i + x1614.toInt) ) else x1915.enqueue(x1836(0)) }
}
()
 }
 
()
}
val x1925 = {
{ 
val x1923 = {
for (i <- 0 until x159.toInt) { if (i + x1614.toInt < x1837.length) x1916.enqueue( x1837(i + x1614.toInt) ) else x1916.enqueue(x1837(0)) }
}
()
 }
 
()
}
()
 }
 
()
}
val x1928 = {
Array(x96)
}
val x1929 = x96 until x159 by x126 par 1
val x1930 = Array(x1929)
val x1626 = x1928
for( x1930_vec0 <- x1930.apply(0.toInt)) {
  val x1634 = x1930_vec0.apply(0.toInt)
val x1931 = {
if (1 < x1915.length) {

val first = x1915.front
Array.tabulate(1){i => if (x1915.nonEmpty) x1915.dequeue() else first }
}
else {
Array.tabulate(1){i => x1915.dequeue() }
}
}
val x1932 = {
if (1 < x1916.length) {

val first = x1916.front
Array.tabulate(1){i => if (x1916.nonEmpty) x1916.dequeue() else first }
}
else {
Array.tabulate(1){i => x1916.dequeue() }
}
}
val x1933 = {
x1626.apply(0)
}
val x1934 = {
x1931.apply(0)
}
val x1935 = {
x1932.apply(0)
}
val x1936 = {
x1934 * x1935
}
val x1937 = {
x1936 + x1933
}
val x1938 = {
if (x146) x1626.update(0, x1937)
}
}
val x1940 = ()
val x1944 = {
{ 
val x1941 = {
x1928.apply(0)
}
val x1942 = {
if (x146) x1838.update(0, x1941)
}
()
 }
 
()
}
}
val x1946 = ()
()
 }
 
()
}

x1948
}}

/**********/

