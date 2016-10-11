package generated.scala
object kernel_x1853 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1:FixedPoint[Signed,B32,B0],x177:FixedPoint[Signed,B32,B0],x179:FixedPoint[Signed,B32,B0],x189:FixedPoint[Signed,B32,B0],x1774:Array[FixedPoint[Signed,B32,B0]],x52:FixedPoint[Signed,B32,B0],x1775:Array[FixedPoint[Signed,B32,B0]],x1776:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x1853 = {
{ 
val x1816 = {
Array.fill(x1.toInt)(x177)
}
val x1817 = x177 until x1 by x179 par 1
val x1818 = Array(x1817)
for( x1818_vec0 <- x1818.apply(0.toInt)) {
  val x1530 = x1818_vec0.apply(0.toInt)
val x1819 = {
Array.fill(x1.toInt)(x177)
}
val x1836 = {
{ 
val x1820 = {
scala.collection.mutable.Queue.fill(0.toInt)(x177)
}
val x1834 = {
{ 
val x1821 = {
for (i <- 0 until x179.toInt) { if (i + x1530.toInt < x1774.length) x1820.enqueue( x1774(i + x1530.toInt) ) else x1820.enqueue(x1774(0)) }
}
val x1822 = x177 until x179 by x52 par 4
val x1823 = Array(x1822)
for( x1823_vec0 <- x1823.apply(0.toInt)) {
  val x1536 = x1823_vec0.apply(0.toInt)
  val x1537 = x1823_vec0.apply(1.toInt)
  val x1538 = x1823_vec0.apply(2.toInt)
  val x1539 = x1823_vec0.apply(3.toInt)
val x1824 = {
if (4 < x1820.length) {

val first = x1820.front
Array.tabulate(4){i => if (x1820.nonEmpty) x1820.dequeue() else first }
}
else {
Array.tabulate(4){i => x1820.dequeue() }
}
}
val x1547 = Array(x1536,x1537,x1538,x1539)
val x1825 = {
x1824.apply(0)
}
val x1826 = {
x1824.apply(1)
}
val x1827 = {
x1824.apply(2)
}
val x1828 = {
x1824.apply(3)
}
val x1829 = Array(x1825,x1826,x1827,x1828)
val x1830 = {
x1829.zip(x1547).foreach{ case (v,a) => if (a.toInt < x1816.length) x1816(a.toInt) = v }
}
}
val x1832 = ()
()
 }
 
()
}
()
 }
 
()
}
val x1841 = {
{ 
val x1839 = {
{ 
val x1837 = {
for (x1559 <- 0 until x179.toInt) { if (x1559 < x1819.length && x1559 < x1816.length && x1816(x1559).toInt < x1775.length) x1819(x1559) = x1775( x1816(x1559).toInt ) }
}
()
 }
 
()
}
()
 }
 
()
}
val x1849 = {
{ 
val x1847 = {
{ 
val x1842 = {
for (x1566 <- 0 until x179.toInt) { if (x1566 < x1816.length && x1816(x1566).toInt < x1776.length) x1776( x1816(x1566).toInt ) = x1819(x1566) }
}
val x1843 = {
for (x1568 <- 0 until x179.toInt) { if (x1568 < x1816.length && x1816(x1568).toInt < x1776.length) x1776( x1816(x1568).toInt ) = x1819(x1568) }
}
val x1844 = {
for (x1570 <- 0 until x179.toInt) { if (x1570 < x1816.length && x1816(x1570).toInt < x1776.length) x1776( x1816(x1570).toInt ) = x1819(x1570) }
}
val x1845 = {
for (x1572 <- 0 until x179.toInt) { if (x1572 < x1816.length && x1816(x1572).toInt < x1776.length) x1776( x1816(x1572).toInt ) = x1819(x1572) }
}
()
 }
 
()
}
()
 }
 
()
}
}
val x1851 = ()
()
 }
 
()
}

x1853
}}

/**********/

