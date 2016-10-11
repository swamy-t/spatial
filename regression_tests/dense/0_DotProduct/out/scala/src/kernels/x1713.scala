package generated.scala
object kernel_x1713 {
def apply(resourceInfo:generated.scala.ResourceInfo,x98:FixedPoint[Signed,B32,B0],x1586:Array[FixedPoint[Signed,B32,B0]],x1025:FixedPoint[Signed,B32,B0],x101:FixedPoint[Signed,B32,B0],x146:FixedPoint[Signed,B32,B0],x1590:Array[FixedPoint[Signed,B32,B0]],x1591:Array[FixedPoint[Signed,B32,B0]],x192:Boolean,x1588:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x1713 = {
{ 
val x1594 = {
Array(x98)
}
val x1595 = {
x1586.apply(0)
}
val x1596 = x98 until x1595 by x1025 par 2
val x1597 = Array(x1596)
val x1598 = x98 until x101 by x101 par 1
val x1599 = Array(x1598)
val x1244 = x1594
for( x1597_vec0 <- x1597.apply(0.toInt)) {
  val x1252 = x1597_vec0.apply(0.toInt)
  val x1253 = x1597_vec0.apply(1.toInt)
val x1600 = {
Array.fill(x1025.toInt)(x98)
}
val x1601 = {
Array.fill(x1025.toInt)(x98)
}
val x1602 = {
Array.fill(x1025.toInt)(x98)
}
val x1603 = {
Array.fill(x1025.toInt)(x98)
}
val x1661 = {
{ 
val x1631 = {
{ 
val x1604 = {
scala.collection.mutable.Queue.fill(0.toInt)(x98)
}
val x1616 = {
{ 
val x1605 = {
for (i <- 0 until x1025.toInt) { if (i + x1252.toInt < x1590.length) x1604.enqueue( x1590(i + x1252.toInt) ) else x1604.enqueue(x1590(0)) }
}
val x1606 = x98 until x1025 by x101 par 2
val x1607 = Array(x1606)
for( x1607_vec0 <- x1607.apply(0.toInt)) {
  val x1262 = x1607_vec0.apply(0.toInt)
  val x1263 = x1607_vec0.apply(1.toInt)
val x1608 = {
if (2 < x1604.length) {

val first = x1604.front
Array.tabulate(2){i => if (x1604.nonEmpty) x1604.dequeue() else first }
}
else {
Array.tabulate(2){i => x1604.dequeue() }
}
}
val x1269 = Array(x1262,x1263)
val x1609 = {
x1608.apply(0)
}
val x1610 = {
x1608.apply(1)
}
val x1611 = Array(x1609,x1610)
val x1612 = {
x1611.zip(x1269).foreach{ case (v,a) => if (a.toInt < x1600.length) x1600(a.toInt) = v }
}
}
val x1614 = ()
()
 }
 
()
}
val x1617 = {
scala.collection.mutable.Queue.fill(0.toInt)(x98)
}
val x1629 = {
{ 
val x1618 = {
for (i <- 0 until x1025.toInt) { if (i + x1252.toInt < x1591.length) x1617.enqueue( x1591(i + x1252.toInt) ) else x1617.enqueue(x1591(0)) }
}
val x1619 = x98 until x1025 by x101 par 2
val x1620 = Array(x1619)
for( x1620_vec0 <- x1620.apply(0.toInt)) {
  val x1281 = x1620_vec0.apply(0.toInt)
  val x1282 = x1620_vec0.apply(1.toInt)
val x1621 = {
if (2 < x1617.length) {

val first = x1617.front
Array.tabulate(2){i => if (x1617.nonEmpty) x1617.dequeue() else first }
}
else {
Array.tabulate(2){i => x1617.dequeue() }
}
}
val x1287 = Array(x1281,x1282)
val x1622 = {
x1621.apply(0)
}
val x1623 = {
x1621.apply(1)
}
val x1624 = Array(x1622,x1623)
val x1625 = {
x1624.zip(x1287).foreach{ case (v,a) => if (a.toInt < x1602.length) x1602(a.toInt) = v }
}
}
val x1627 = ()
()
 }
 
()
}
()
 }
 
()
}
val x1659 = {
{ 
val x1632 = {
scala.collection.mutable.Queue.fill(0.toInt)(x98)
}
val x1644 = {
{ 
val x1633 = {
for (i <- 0 until x1025.toInt) { if (i + x1253.toInt < x1590.length) x1632.enqueue( x1590(i + x1253.toInt) ) else x1632.enqueue(x1590(0)) }
}
val x1634 = x98 until x1025 by x101 par 2
val x1635 = Array(x1634)
for( x1635_vec0 <- x1635.apply(0.toInt)) {
  val x1301 = x1635_vec0.apply(0.toInt)
  val x1302 = x1635_vec0.apply(1.toInt)
val x1636 = {
if (2 < x1632.length) {

val first = x1632.front
Array.tabulate(2){i => if (x1632.nonEmpty) x1632.dequeue() else first }
}
else {
Array.tabulate(2){i => x1632.dequeue() }
}
}
val x1307 = Array(x1301,x1302)
val x1637 = {
x1636.apply(0)
}
val x1638 = {
x1636.apply(1)
}
val x1639 = Array(x1637,x1638)
val x1640 = {
x1639.zip(x1307).foreach{ case (v,a) => if (a.toInt < x1601.length) x1601(a.toInt) = v }
}
}
val x1642 = ()
()
 }
 
()
}
val x1645 = {
scala.collection.mutable.Queue.fill(0.toInt)(x98)
}
val x1657 = {
{ 
val x1646 = {
for (i <- 0 until x1025.toInt) { if (i + x1253.toInt < x1591.length) x1645.enqueue( x1591(i + x1253.toInt) ) else x1645.enqueue(x1591(0)) }
}
val x1647 = x98 until x1025 by x101 par 2
val x1648 = Array(x1647)
for( x1648_vec0 <- x1648.apply(0.toInt)) {
  val x1319 = x1648_vec0.apply(0.toInt)
  val x1320 = x1648_vec0.apply(1.toInt)
val x1649 = {
if (2 < x1645.length) {

val first = x1645.front
Array.tabulate(2){i => if (x1645.nonEmpty) x1645.dequeue() else first }
}
else {
Array.tabulate(2){i => x1645.dequeue() }
}
}
val x1325 = Array(x1319,x1320)
val x1650 = {
x1649.apply(0)
}
val x1651 = {
x1649.apply(1)
}
val x1652 = Array(x1650,x1651)
val x1653 = {
x1652.zip(x1325).foreach{ case (v,a) => if (a.toInt < x1603.length) x1603(a.toInt) = v }
}
}
val x1655 = ()
()
 }
 
()
}
()
 }
 
()
}
()
 }
 
()
}
val x1662 = {
Array(x98)
}
val x1663 = {
Array(x98)
}
val x1664 = x98 until x1025 by x101 par 2
val x1665 = x98 until x1025 by x101 par 2
val x1666 = Array(x1664)
val x1667 = Array(x1665)
val x1697 = {
{ 
val x1343 = x1662
for( x1666_vec0 <- x1666.apply(0.toInt)) {
  val x1351 = x1666_vec0.apply(0.toInt)
  val x1352 = x1666_vec0.apply(1.toInt)
val x1353 = Array(x1351,x1352)
val x1668 = {
x1353.map{addr => if (addr.toInt < x1600.length) x1600(addr.toInt) else x1600(0) }
}
val x1669 = {
x1353.map{addr => if (addr.toInt < x1602.length) x1602(addr.toInt) else x1602(0) }
}
val x1670 = {
x1343.apply(0)
}
val x1671 = {
x1668.apply(0)
}
val x1672 = {
x1669.apply(0)
}
val x1673 = {
x1671 * x1672
}
val x1674 = {
x1668.apply(1)
}
val x1675 = {
x1669.apply(1)
}
val x1676 = {
x1674 * x1675
}
val x1677 = {
x1673 + x1676
}
val x1678 = {
x1677 + x1670
}
val x1679 = {
if (x192) x1343.update(0, x1678)
}
}
val x1681 = ()
val x1376 = x1663
for( x1667_vec0 <- x1667.apply(0.toInt)) {
  val x1384 = x1667_vec0.apply(0.toInt)
  val x1385 = x1667_vec0.apply(1.toInt)
val x1386 = Array(x1384,x1385)
val x1682 = {
x1386.map{addr => if (addr.toInt < x1601.length) x1601(addr.toInt) else x1601(0) }
}
val x1683 = {
x1386.map{addr => if (addr.toInt < x1603.length) x1603(addr.toInt) else x1603(0) }
}
val x1684 = {
x1376.apply(0)
}
val x1685 = {
x1682.apply(0)
}
val x1686 = {
x1683.apply(0)
}
val x1687 = {
x1685 * x1686
}
val x1688 = {
x1682.apply(1)
}
val x1689 = {
x1683.apply(1)
}
val x1690 = {
x1688 * x1689
}
val x1691 = {
x1687 + x1690
}
val x1692 = {
x1691 + x1684
}
val x1693 = {
if (x192) x1376.update(0, x1692)
}
}
val x1695 = ()
()
 }
 
()
}
val x1705 = {
{ 
val x1698 = {
x1662.apply(0)
}
val x1699 = {
x1663.apply(0)
}
val x1700 = {
x1594.apply(0)
}
val x1701 = {
x1698 + x1699
}
val x1702 = {
x1701 + x1700
}
val x1703 = {
if (x192) x1594.update(0, x1702)
}
()
 }
 
()
}
}
val x1707 = ()
val x1711 = {
{ 
val x1708 = {
x1594.apply(0)
}
val x1709 = {
if (x192) x1588.update(0, x1708)
}
()
 }
 
()
}
()
 }
 
()
}

x1713
}}

/**********/

