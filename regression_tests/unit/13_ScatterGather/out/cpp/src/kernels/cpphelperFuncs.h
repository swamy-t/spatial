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
int32_t  kernel_x124(resourceInfo_t *resourceInfo);
int32_t  kernel_x125(resourceInfo_t *resourceInfo,int32_t  x124);
activation_x1773 * kernel_x1773(resourceInfo_t *resourceInfo,int32_t  x125, int32_t  x124);
int32_t  kernel_x1(resourceInfo_t *resourceInfo);
maxjLmem * kernel_x1774(resourceInfo_t *resourceInfo,int32_t  x1);
maxjLmem * kernel_x1775(resourceInfo_t *resourceInfo,int32_t  x124);
maxjLmem * kernel_x1776(resourceInfo_t *resourceInfo,int32_t  x124);
int32_t  kernel_x2(resourceInfo_t *resourceInfo,int32_t  x1);
int32_t  kernel_x5(resourceInfo_t *resourceInfo);
int32_t  kernel_x8(resourceInfo_t *resourceInfo);
int32_t  kernel_x9(resourceInfo_t *resourceInfo);
int32_t  kernel_x12(resourceInfo_t *resourceInfo);
int32_t  kernel_x13(resourceInfo_t *resourceInfo);
int32_t  kernel_x16(resourceInfo_t *resourceInfo);
int32_t  kernel_x17(resourceInfo_t *resourceInfo);
int32_t  kernel_x20(resourceInfo_t *resourceInfo);
int32_t  kernel_x21(resourceInfo_t *resourceInfo);
int32_t  kernel_x24(resourceInfo_t *resourceInfo);
int32_t  kernel_x25(resourceInfo_t *resourceInfo);
int32_t  kernel_x28(resourceInfo_t *resourceInfo);
int32_t  kernel_x29(resourceInfo_t *resourceInfo);
int32_t  kernel_x32(resourceInfo_t *resourceInfo);
int32_t  kernel_x33(resourceInfo_t *resourceInfo);
int32_t  kernel_x36(resourceInfo_t *resourceInfo);
int32_t  kernel_x37(resourceInfo_t *resourceInfo);
int32_t  kernel_x40(resourceInfo_t *resourceInfo);
int32_t  kernel_x41(resourceInfo_t *resourceInfo);
int32_t  kernel_x44(resourceInfo_t *resourceInfo);
int32_t  kernel_x45(resourceInfo_t *resourceInfo);
int32_t  kernel_x48(resourceInfo_t *resourceInfo);
int32_t  kernel_x49(resourceInfo_t *resourceInfo);
int32_t  kernel_x52(resourceInfo_t *resourceInfo);
int32_t  kernel_x53(resourceInfo_t *resourceInfo);
int32_t  kernel_x56(resourceInfo_t *resourceInfo);
int32_t  kernel_x57(resourceInfo_t *resourceInfo);
int32_t  kernel_x60(resourceInfo_t *resourceInfo);
int32_t  kernel_x63(resourceInfo_t *resourceInfo);
int32_t  kernel_x64(resourceInfo_t *resourceInfo);
activation_x1813 * kernel_x1813(resourceInfo_t *resourceInfo,int32_t  x2, int32_t  x5, int32_t  x9, int32_t  x13, int32_t  x17, int32_t  x21, int32_t  x25, int32_t  x29, int32_t  x33, int32_t  x37, int32_t  x41, int32_t  x45, int32_t  x49, int32_t  x53, int32_t  x57, int32_t  x60, int32_t  x64, int32_t  x63, int32_t  x20, int32_t  x56, int32_t  x52, int32_t  x48, int32_t  x44, int32_t  x40, int32_t  x36, int32_t  x32, int32_t  x28, int32_t  x24, int32_t  x16, int32_t  x12, int32_t  x8);
void  kernel_x1814(resourceInfo_t *resourceInfo,maxjLmem  *x1774, cppDeliteArrayint32_t  *x1813);
void  kernel_x1815(resourceInfo_t *resourceInfo,maxjLmem  *x1775, cppDeliteArrayint32_t  *x1773);
int32_t  kernel_x177(resourceInfo_t *resourceInfo);
int32_t  kernel_x179(resourceInfo_t *resourceInfo);
int32_t  kernel_x189(resourceInfo_t *resourceInfo);
void  kernel_x1853(resourceInfo_t *resourceInfo,int32_t  x1, int32_t  x177, int32_t  x179, int32_t  x189, maxjLmem  *x1774, int32_t  x52, maxjLmem  *x1775, maxjLmem  *x1776);
cppDeliteArrayint32_t * kernel_x1854(resourceInfo_t *resourceInfo,int32_t  x125);
void  kernel_x1855(resourceInfo_t *resourceInfo,maxjLmem  *x1776, cppDeliteArrayint32_t  *x1854);
void  kernel_x1856(resourceInfo_t *resourceInfo);
int32_t  kernel_x325(resourceInfo_t *resourceInfo,int32_t  x125);
bool  kernel_x268(resourceInfo_t *resourceInfo);
activation_x1939 * kernel_x1939(resourceInfo_t *resourceInfo,int32_t  x125, cppDeliteArrayint32_t  *x1813, int32_t  x2, bool  x268, cppDeliteArrayint32_t  *x1773, int32_t  x177);
void  kernel_x1944(resourceInfo_t *resourceInfo,int32_t  x177, int32_t  x325, int32_t  x52, cppDeliteArrayint32_t  *x1939);
void  kernel_x1945(resourceInfo_t *resourceInfo);
void  kernel_x1946(resourceInfo_t *resourceInfo);
int32_t  kernel_x1947(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x1854);
int32_t  kernel_x1948(resourceInfo_t *resourceInfo,int32_t  x1947);
void  kernel_x1953(resourceInfo_t *resourceInfo,int32_t  x177, int32_t  x1948, int32_t  x52, cppDeliteArrayint32_t  *x1854);
void  kernel_x1954(resourceInfo_t *resourceInfo);
activation_x1995 * kernel_x1995(resourceInfo_t *resourceInfo,int32_t  x1947, cppDeliteArrayint32_t  *x1854, cppDeliteArrayint32_t  *x1939);
int32_t  kernel_x1996(resourceInfo_t *resourceInfo,cppDeliteArraybool  *x1995);
activation_x2001 * kernel_x2001(resourceInfo_t *resourceInfo,int32_t  x1996, bool  x268, cppDeliteArraybool  *x1995);
string  kernel_x2002(resourceInfo_t *resourceInfo,bool  x2001);
string  kernel_x2003(resourceInfo_t *resourceInfo,string  x2002);
void  kernel_x2004(resourceInfo_t *resourceInfo,string  x2003);
