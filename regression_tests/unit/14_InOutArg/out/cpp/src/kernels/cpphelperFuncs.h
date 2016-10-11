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
int32_t  kernel_x1(resourceInfo_t *resourceInfo);
int32_t  * kernel_x123(resourceInfo_t *resourceInfo,int32_t  x1);
int32_t  * kernel_x124(resourceInfo_t *resourceInfo,int32_t  x1);
string  kernel_x4(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x5(resourceInfo_t *resourceInfo,string  x4);
void  kernel_x125(resourceInfo_t *resourceInfo,int32_t   *x123, int32_t  x5);
int32_t  kernel_x8(resourceInfo_t *resourceInfo);
void  kernel_x132(resourceInfo_t *resourceInfo,int32_t   *x123, int32_t  x8, int32_t   *x124);
int32_t  kernel_x133(resourceInfo_t *resourceInfo,int32_t   *x124);
int32_t  kernel_x17(resourceInfo_t *resourceInfo,int32_t  x5, int32_t  x8);
string  kernel_x18(resourceInfo_t *resourceInfo,int32_t  x17);
void  kernel_x134(resourceInfo_t *resourceInfo,string  x18);
string  kernel_x135(resourceInfo_t *resourceInfo,int32_t  x133);
void  kernel_x136(resourceInfo_t *resourceInfo,string  x135);
bool  kernel_x137(resourceInfo_t *resourceInfo,int32_t  x17, int32_t  x133);
string  kernel_x138(resourceInfo_t *resourceInfo,bool  x137);
string  kernel_x139(resourceInfo_t *resourceInfo,string  x138);
void  kernel_x140(resourceInfo_t *resourceInfo,string  x139);
