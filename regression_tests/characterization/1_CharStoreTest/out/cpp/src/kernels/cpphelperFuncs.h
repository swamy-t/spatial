#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <memory>
#include <float.h>
#include <jni.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include "cpptypes.h"
#include "cppactRecords.h"
#include "DeliteCpp.h"
int32_t  kernel_x53(resourceInfo_t *resourceInfo);
int32_t  * kernel_x1710(resourceInfo_t *resourceInfo,int32_t  x53);
int32_t  * kernel_x1711(resourceInfo_t *resourceInfo,int32_t  x53);
string  kernel_x1(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x2(resourceInfo_t *resourceInfo,string  x1);
void  kernel_x1712(resourceInfo_t *resourceInfo,int32_t   *x1710, int32_t  x2);
string  kernel_x3(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x4(resourceInfo_t *resourceInfo,string  x3);
void  kernel_x1713(resourceInfo_t *resourceInfo,int32_t   *x1711, int32_t  x4);
int32_t  kernel_x354(resourceInfo_t *resourceInfo);
maxjLmem * kernel_x1714(resourceInfo_t *resourceInfo,int32_t  x354);
maxjLmem * kernel_x1715(resourceInfo_t *resourceInfo,int32_t  x354);
maxjLmem * kernel_x1716(resourceInfo_t *resourceInfo,int32_t  x354);
maxjLmem * kernel_x1717(resourceInfo_t *resourceInfo,int32_t  x354);
int32_t  kernel_x66(resourceInfo_t *resourceInfo);
int32_t  kernel_x93(resourceInfo_t *resourceInfo);
int32_t  kernel_x99(resourceInfo_t *resourceInfo);
int32_t  kernel_x111(resourceInfo_t *resourceInfo);
int32_t  kernel_x58(resourceInfo_t *resourceInfo);
int32_t  kernel_x59(resourceInfo_t *resourceInfo);
bool  kernel_x131(resourceInfo_t *resourceInfo);
void  kernel_x1847(resourceInfo_t *resourceInfo,int32_t   *x1710, int32_t  x53, int32_t  x66, int32_t  x354, int32_t   *x1711, int32_t  x93, int32_t  x99, int32_t  x111, int32_t  x58, int32_t  x59, bool  x131, maxjLmem  *x1714, maxjLmem  *x1715, maxjLmem  *x1716, maxjLmem  *x1717);
int32_t  kernel_x467(resourceInfo_t *resourceInfo,int32_t  x354);
cppDeliteArrayint32_t * kernel_x1848(resourceInfo_t *resourceInfo,int32_t  x467);
void  kernel_x1849(resourceInfo_t *resourceInfo,maxjLmem  *x1714, cppDeliteArrayint32_t  *x1848);
cppDeliteArrayint32_t * kernel_x1850(resourceInfo_t *resourceInfo,int32_t  x467);
void  kernel_x1851(resourceInfo_t *resourceInfo,maxjLmem  *x1715, cppDeliteArrayint32_t  *x1850);
cppDeliteArrayint32_t * kernel_x1852(resourceInfo_t *resourceInfo,int32_t  x467);
void  kernel_x1853(resourceInfo_t *resourceInfo,maxjLmem  *x1716, cppDeliteArrayint32_t  *x1852);
cppDeliteArrayint32_t * kernel_x1854(resourceInfo_t *resourceInfo,int32_t  x467);
void  kernel_x1855(resourceInfo_t *resourceInfo,maxjLmem  *x1717, cppDeliteArrayint32_t  *x1854);
int32_t  kernel_x1856(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x1848);
int32_t  kernel_x1862(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x1850);
int32_t  kernel_x1868(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x1852);
int32_t  kernel_x1874(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x1854);
activation_x1873 * kernel_x1873(resourceInfo_t *resourceInfo,int32_t  x1868, int32_t  x53, cppDeliteArrayint32_t  *x1852);
activation_x1861 * kernel_x1861(resourceInfo_t *resourceInfo,int32_t  x1856, int32_t  x53, cppDeliteArrayint32_t  *x1848);
activation_x1867 * kernel_x1867(resourceInfo_t *resourceInfo,int32_t  x1862, int32_t  x53, cppDeliteArrayint32_t  *x1850);
activation_x1879 * kernel_x1879(resourceInfo_t *resourceInfo,int32_t  x1874, int32_t  x53, cppDeliteArrayint32_t  *x1854);
int32_t  kernel_x5(resourceInfo_t *resourceInfo);
int32_t  kernel_x6(resourceInfo_t *resourceInfo,int32_t  x5);
activation_x1916 * kernel_x1916(resourceInfo_t *resourceInfo,int32_t  x6, int32_t  x4);
activation_x1954 * kernel_x1954(resourceInfo_t *resourceInfo,int32_t  x6, cppDeliteArrayint32_t  *x1916);
activation_x1958x1980 * kernel_x1958x1980(resourceInfo_t *resourceInfo,int32_t  x6, int32_t  x53, cppDeliteArrayint32_t  *x1954, cppDeliteArrayint32_t  *x1916);
int32_t  kernel_x1959(resourceInfo_t *resourceInfo,int32_t  x1958, int32_t  x58);
int32_t  kernel_x1960(resourceInfo_t *resourceInfo,int32_t  x1959, int32_t  x59);
string  kernel_x1961(resourceInfo_t *resourceInfo,int32_t  x1960);
void  kernel_x1962(resourceInfo_t *resourceInfo,string  x1961);
int32_t  kernel_x1963(resourceInfo_t *resourceInfo,int32_t  x1861, int32_t  x1867);
int32_t  kernel_x1964(resourceInfo_t *resourceInfo,int32_t  x1963, int32_t  x1873);
int32_t  kernel_x1965(resourceInfo_t *resourceInfo,int32_t  x1964, int32_t  x1879);
string  kernel_x1966(resourceInfo_t *resourceInfo,int32_t  x1965);
void  kernel_x1967(resourceInfo_t *resourceInfo,string  x1966);
int32_t  kernel_x1981(resourceInfo_t *resourceInfo,int32_t  x1980, int32_t  x58);
int32_t  kernel_x1982(resourceInfo_t *resourceInfo,int32_t  x1981, int32_t  x59);
bool  kernel_x1983(resourceInfo_t *resourceInfo,int32_t  x1982, int32_t  x1965);
string  kernel_x1984(resourceInfo_t *resourceInfo,bool  x1983);
string  kernel_x1985(resourceInfo_t *resourceInfo,string  x1984);
void  kernel_x1986(resourceInfo_t *resourceInfo,string  x1985);
