package generated.scala
object kernel_x1847 {
def apply(resourceInfo:generated.scala.ResourceInfo,x1710:Array[FixedPoint[Signed,B32,B0]],x53:FixedPoint[Signed,B32,B0],x66:FixedPoint[Signed,B32,B0],x354:FixedPoint[Signed,B32,B0],x1711:Array[FixedPoint[Signed,B32,B0]],x93:FixedPoint[Signed,B32,B0],x99:FixedPoint[Signed,B32,B0],x111:FixedPoint[Signed,B32,B0],x58:FixedPoint[Signed,B32,B0],x59:FixedPoint[Signed,B32,B0],x131:Boolean,x1714:Array[FixedPoint[Signed,B32,B0]],x1715:Array[FixedPoint[Signed,B32,B0]],x1716:Array[FixedPoint[Signed,B32,B0]],x1717:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x1847 = {
{ 
val x1718 = {
x1710.apply(0)
}
val x1719 = x53 until x1718 by x66 par 1
val x1720 = Array(x1719)
for( x1720_vec0 <- x1720.apply(0.toInt)) {
  val x1367 = x1720_vec0.apply(0.toInt)
val x1721 = {
Array.fill(x354.toInt)(x53)
}
val x1722 = {
Array.fill(x354.toInt)(x53)
}
val x1723 = {
Array.fill(x354.toInt)(x53)
}
val x1724 = {
Array.fill(x354.toInt)(x53)
}
val x1745 = {
{ 
val x1728 = {
{ 
val x1725 = {
x1711.apply(0)
}
val x1726 = {
x1721.update(x53.toInt, x1725)
}
()
 }
 
()
}
val x1733 = {
{ 
val x1729 = {
x1711.apply(0)
}
val x1730 = {
x1729 + x66
}
val x1731 = {
x1722.update(x53.toInt, x1730)
}
()
 }
 
()
}
val x1738 = {
{ 
val x1734 = {
x1711.apply(0)
}
val x1735 = {
x1734 + x93
}
val x1736 = {
x1723.update(x53.toInt, x1735)
}
()
 }
 
()
}
val x1743 = {
{ 
val x1739 = {
x1711.apply(0)
}
val x1740 = {
x1739 + x99
}
val x1741 = {
x1724.update(x53.toInt, x1740)
}
()
 }
 
()
}
()
 }
 
()
}
val x1843 = {
{ 
val x1769 = {
{ 
val x1746 = {
scala.collection.mutable.Queue.fill(0.toInt)(x53)
}
val x1747 = x53 until x58 by x66 par 1
val x1748 = Array(x1747)
for( x1748_vec0 <- x1748.apply(0.toInt)) {
  val x1396 = x1748_vec0.apply(0.toInt)
val x1749 = x53 until x59 by x66 par 4
val x1750 = Array(x1749)
for( x1750_vec0 <- x1750.apply(0.toInt)) {
  val x1399 = x1750_vec0.apply(0.toInt)
  val x1400 = x1750_vec0.apply(1.toInt)
  val x1401 = x1750_vec0.apply(2.toInt)
  val x1402 = x1750_vec0.apply(3.toInt)
val x1403 = {
x1396 * x59
}
val x1404 = {
x1403 + x1399
}
val x1405 = {
x1403 + x1400
}
val x1406 = {
x1403 + x1401
}
val x1407 = {
x1403 + x1402
}
val x1408 = Array(x1404,x1405,x1406,x1407)
val x1751 = {
x1408.map{addr => if (addr.toInt < x1721.length) x1721(addr.toInt) else x1721(0) }
}
val x1415 = {
x1399 < x59
}
val x1416 = {
x1400 < x59
}
val x1417 = {
x1401 < x59
}
val x1418 = {
x1402 < x59
}
val x1419 = Array(x1415,x1416,x1417,x1418)
val x1752 = {
x1751.apply(0)
}
val x1753 = {
x1751.apply(1)
}
val x1754 = {
x1751.apply(2)
}
val x1755 = {
x1751.apply(3)
}
val x1756 = Array(x1752,x1753,x1754,x1755)
val x1757 = {
x1756.zip(x1419).foreach{ case (v,e) => if (e) x1746.enqueue(v) }
}
}
val x1759 = ()
val x1760 = {
Array(x53)
}
val x1763 = {
{ 
val x1403 = {
x1396 * x59
}
val x1761 = {
if (x131) x1760.update(0, x1403)
}
()
 }
 
()
}
val x1764 = {
x1760.apply(0)
}
val x1765 = {
for (i <- 0 until x59.toInt) { if (i + x1764.toInt < x1714.length) x1714(i + x1764.toInt) = x1746.dequeue() }
}
}
val x1767 = ()
()
 }
 
()
}
val x1793 = {
{ 
val x1770 = {
scala.collection.mutable.Queue.fill(0.toInt)(x53)
}
val x1771 = x53 until x58 by x66 par 1
val x1772 = Array(x1771)
for( x1772_vec0 <- x1772.apply(0.toInt)) {
  val x1441 = x1772_vec0.apply(0.toInt)
val x1773 = x53 until x59 by x66 par 4
val x1774 = Array(x1773)
for( x1774_vec0 <- x1774.apply(0.toInt)) {
  val x1444 = x1774_vec0.apply(0.toInt)
  val x1445 = x1774_vec0.apply(1.toInt)
  val x1446 = x1774_vec0.apply(2.toInt)
  val x1447 = x1774_vec0.apply(3.toInt)
val x1448 = {
x1441 * x59
}
val x1449 = {
x1448 + x1444
}
val x1450 = {
x1448 + x1445
}
val x1451 = {
x1448 + x1446
}
val x1452 = {
x1448 + x1447
}
val x1453 = Array(x1449,x1450,x1451,x1452)
val x1775 = {
x1453.map{addr => if (addr.toInt < x1722.length) x1722(addr.toInt) else x1722(0) }
}
val x1460 = {
x1444 < x59
}
val x1461 = {
x1445 < x59
}
val x1462 = {
x1446 < x59
}
val x1463 = {
x1447 < x59
}
val x1464 = Array(x1460,x1461,x1462,x1463)
val x1776 = {
x1775.apply(0)
}
val x1777 = {
x1775.apply(1)
}
val x1778 = {
x1775.apply(2)
}
val x1779 = {
x1775.apply(3)
}
val x1780 = Array(x1776,x1777,x1778,x1779)
val x1781 = {
x1780.zip(x1464).foreach{ case (v,e) => if (e) x1770.enqueue(v) }
}
}
val x1783 = ()
val x1784 = {
Array(x53)
}
val x1787 = {
{ 
val x1448 = {
x1441 * x59
}
val x1785 = {
if (x131) x1784.update(0, x1448)
}
()
 }
 
()
}
val x1788 = {
x1784.apply(0)
}
val x1789 = {
for (i <- 0 until x59.toInt) { if (i + x1788.toInt < x1715.length) x1715(i + x1788.toInt) = x1770.dequeue() }
}
}
val x1791 = ()
()
 }
 
()
}
val x1817 = {
{ 
val x1794 = {
scala.collection.mutable.Queue.fill(0.toInt)(x53)
}
val x1795 = x53 until x58 by x66 par 1
val x1796 = Array(x1795)
for( x1796_vec0 <- x1796.apply(0.toInt)) {
  val x1486 = x1796_vec0.apply(0.toInt)
val x1797 = x53 until x59 by x66 par 4
val x1798 = Array(x1797)
for( x1798_vec0 <- x1798.apply(0.toInt)) {
  val x1489 = x1798_vec0.apply(0.toInt)
  val x1490 = x1798_vec0.apply(1.toInt)
  val x1491 = x1798_vec0.apply(2.toInt)
  val x1492 = x1798_vec0.apply(3.toInt)
val x1493 = {
x1486 * x59
}
val x1494 = {
x1493 + x1489
}
val x1495 = {
x1493 + x1490
}
val x1496 = {
x1493 + x1491
}
val x1497 = {
x1493 + x1492
}
val x1498 = Array(x1494,x1495,x1496,x1497)
val x1799 = {
x1498.map{addr => if (addr.toInt < x1723.length) x1723(addr.toInt) else x1723(0) }
}
val x1505 = {
x1489 < x59
}
val x1506 = {
x1490 < x59
}
val x1507 = {
x1491 < x59
}
val x1508 = {
x1492 < x59
}
val x1509 = Array(x1505,x1506,x1507,x1508)
val x1800 = {
x1799.apply(0)
}
val x1801 = {
x1799.apply(1)
}
val x1802 = {
x1799.apply(2)
}
val x1803 = {
x1799.apply(3)
}
val x1804 = Array(x1800,x1801,x1802,x1803)
val x1805 = {
x1804.zip(x1509).foreach{ case (v,e) => if (e) x1794.enqueue(v) }
}
}
val x1807 = ()
val x1808 = {
Array(x53)
}
val x1811 = {
{ 
val x1493 = {
x1486 * x59
}
val x1809 = {
if (x131) x1808.update(0, x1493)
}
()
 }
 
()
}
val x1812 = {
x1808.apply(0)
}
val x1813 = {
for (i <- 0 until x59.toInt) { if (i + x1812.toInt < x1716.length) x1716(i + x1812.toInt) = x1794.dequeue() }
}
}
val x1815 = ()
()
 }
 
()
}
val x1841 = {
{ 
val x1818 = {
scala.collection.mutable.Queue.fill(0.toInt)(x53)
}
val x1819 = x53 until x58 by x66 par 1
val x1820 = Array(x1819)
for( x1820_vec0 <- x1820.apply(0.toInt)) {
  val x1531 = x1820_vec0.apply(0.toInt)
val x1821 = x53 until x59 by x66 par 4
val x1822 = Array(x1821)
for( x1822_vec0 <- x1822.apply(0.toInt)) {
  val x1534 = x1822_vec0.apply(0.toInt)
  val x1535 = x1822_vec0.apply(1.toInt)
  val x1536 = x1822_vec0.apply(2.toInt)
  val x1537 = x1822_vec0.apply(3.toInt)
val x1538 = {
x1531 * x59
}
val x1539 = {
x1538 + x1534
}
val x1540 = {
x1538 + x1535
}
val x1541 = {
x1538 + x1536
}
val x1542 = {
x1538 + x1537
}
val x1543 = Array(x1539,x1540,x1541,x1542)
val x1823 = {
x1543.map{addr => if (addr.toInt < x1724.length) x1724(addr.toInt) else x1724(0) }
}
val x1550 = {
x1534 < x59
}
val x1551 = {
x1535 < x59
}
val x1552 = {
x1536 < x59
}
val x1553 = {
x1537 < x59
}
val x1554 = Array(x1550,x1551,x1552,x1553)
val x1824 = {
x1823.apply(0)
}
val x1825 = {
x1823.apply(1)
}
val x1826 = {
x1823.apply(2)
}
val x1827 = {
x1823.apply(3)
}
val x1828 = Array(x1824,x1825,x1826,x1827)
val x1829 = {
x1828.zip(x1554).foreach{ case (v,e) => if (e) x1818.enqueue(v) }
}
}
val x1831 = ()
val x1832 = {
Array(x53)
}
val x1835 = {
{ 
val x1538 = {
x1531 * x59
}
val x1833 = {
if (x131) x1832.update(0, x1538)
}
()
 }
 
()
}
val x1836 = {
x1832.apply(0)
}
val x1837 = {
for (i <- 0 until x59.toInt) { if (i + x1836.toInt < x1717.length) x1717(i + x1836.toInt) = x1818.dequeue() }
}
}
val x1839 = ()
()
 }
 
()
}
()
 }
 
()
}
}
val x1845 = ()
()
 }
 
()
}

x1847
}}

/**********/

