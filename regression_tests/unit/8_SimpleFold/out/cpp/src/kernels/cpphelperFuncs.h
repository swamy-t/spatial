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
int32_t  kernel_x50(resourceInfo_t *resourceInfo);
int32_t  * kernel_x720(resourceInfo_t *resourceInfo,int32_t  x50);
int32_t  * kernel_x721(resourceInfo_t *resourceInfo,int32_t  x50);
string  kernel_x1(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x2(resourceInfo_t *resourceInfo,string  x1);
int32_t  kernel_x3(resourceInfo_t *resourceInfo,int32_t  x2);
int32_t  kernel_x49(resourceInfo_t *resourceInfo,int32_t  x3);
void  kernel_x722(resourceInfo_t *resourceInfo,int32_t   *x720, int32_t  x49);
int32_t  kernel_x723(resourceInfo_t *resourceInfo,int32_t   *x720);
maxjLmem * kernel_x724(resourceInfo_t *resourceInfo,int32_t  x723);
activation_x761 * kernel_x761(resourceInfo_t *resourceInfo,int32_t  x3);
void  kernel_x762(resourceInfo_t *resourceInfo,maxjLmem  *x724, cppDeliteArrayint32_t  *x761);
void  kernel_x821(resourceInfo_t *resourceInfo,int32_t  x50, int32_t   *x720, maxjLmem  *x724, int32_t   *x721);
int32_t  kernel_x822(resourceInfo_t *resourceInfo,int32_t   *x721);
activation_x826 * kernel_x826(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x50, cppDeliteArrayint32_t  *x761);
string  kernel_x827(resourceInfo_t *resourceInfo,int32_t  x826);
void  kernel_x828(resourceInfo_t *resourceInfo,string  x827);
string  kernel_x829(resourceInfo_t *resourceInfo,int32_t  x822);
void  kernel_x830(resourceInfo_t *resourceInfo,string  x829);
bool  kernel_x831(resourceInfo_t *resourceInfo,int32_t  x822, int32_t  x826);
string  kernel_x832(resourceInfo_t *resourceInfo,bool  x831);
string  kernel_x833(resourceInfo_t *resourceInfo,string  x832);
void  kernel_x834(resourceInfo_t *resourceInfo,string  x833);
