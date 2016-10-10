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
int32_t  kernel_x285(resourceInfo_t *resourceInfo);
int32_t  * kernel_x4578(resourceInfo_t *resourceInfo,int32_t  x285);
int32_t  * kernel_x4579(resourceInfo_t *resourceInfo,int32_t  x285);
int32_t  * kernel_x4580(resourceInfo_t *resourceInfo,int32_t  x285);
string  kernel_x1(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x2(resourceInfo_t *resourceInfo,string  x1);
void  kernel_x4581(resourceInfo_t *resourceInfo,int32_t   *x4578, int32_t  x2);
string  kernel_x3(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x4(resourceInfo_t *resourceInfo,string  x3);
void  kernel_x4582(resourceInfo_t *resourceInfo,int32_t   *x4579, int32_t  x4);
string  kernel_x5(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x6(resourceInfo_t *resourceInfo,string  x5);
void  kernel_x4583(resourceInfo_t *resourceInfo,int32_t   *x4580, int32_t  x6);
int32_t  kernel_x4584(resourceInfo_t *resourceInfo,int32_t   *x4578);
int32_t  kernel_x4585(resourceInfo_t *resourceInfo,int32_t   *x4580);
int32_t  kernel_x4586(resourceInfo_t *resourceInfo,int32_t  x4584, int32_t  x4585);
maxjLmem * kernel_x4587(resourceInfo_t *resourceInfo,int32_t  x4586);
int32_t  kernel_x4588(resourceInfo_t *resourceInfo,int32_t   *x4579);
int32_t  kernel_x4589(resourceInfo_t *resourceInfo,int32_t  x4585, int32_t  x4588);
maxjLmem * kernel_x4590(resourceInfo_t *resourceInfo,int32_t  x4589);
int32_t  kernel_x4591(resourceInfo_t *resourceInfo,int32_t  x4584, int32_t  x4588);
maxjLmem * kernel_x4592(resourceInfo_t *resourceInfo,int32_t  x4591);
int32_t  kernel_x7(resourceInfo_t *resourceInfo,int32_t  x2);
int32_t  kernel_x9(resourceInfo_t *resourceInfo,int32_t  x6);
int32_t  kernel_x11(resourceInfo_t *resourceInfo);
int32_t  kernel_x99(resourceInfo_t *resourceInfo,int32_t  x4);
activation_x4742 * kernel_x4742(resourceInfo_t *resourceInfo,int32_t  x99, int32_t  x11);
activation_x4629x5380 * kernel_x4629x5380(resourceInfo_t *resourceInfo,int32_t  x9, int32_t  x11, cppDeliteArrayint32_t  *x4742);
activation_x4666 * kernel_x4666(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArrayint32_t  *x4629);
activation_x4704 * kernel_x4704(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x4666);
void  kernel_x4705(resourceInfo_t *resourceInfo,maxjLmem  *x4587, cppDeliteArrayint32_t  *x4704);
activation_x5382 * kernel_x5382(resourceInfo_t *resourceInfo,int32_t  x9, cppDeliteArraycppDeliteArrayint32_t  *x5380);
void  kernel_x5383(resourceInfo_t *resourceInfo,maxjLmem  *x4590, cppDeliteArrayint32_t  *x5382);
int32_t  kernel_x3194(resourceInfo_t *resourceInfo);
int32_t  kernel_x3195(resourceInfo_t *resourceInfo);
int32_t  kernel_x3197(resourceInfo_t *resourceInfo);
int32_t  kernel_x3199(resourceInfo_t *resourceInfo);
int32_t  kernel_x333(resourceInfo_t *resourceInfo);
bool  kernel_x422(resourceInfo_t *resourceInfo);
void  kernel_x5033(resourceInfo_t *resourceInfo,int32_t   *x4578, int32_t   *x4579, int32_t  x285, int32_t  x3194, int32_t  x3195, int32_t   *x4580, int32_t  x3197, int32_t  x3199, int32_t  x333, int32_t  x11, int32_t  x4585, bool  x422, maxjLmem  *x4587, int32_t  x4588, maxjLmem  *x4590, maxjLmem  *x4592);
int32_t  kernel_x5034(resourceInfo_t *resourceInfo,int32_t  x4591);
cppDeliteArrayint32_t * kernel_x5035(resourceInfo_t *resourceInfo,int32_t  x5034);
void  kernel_x5036(resourceInfo_t *resourceInfo,maxjLmem  *x4592, cppDeliteArrayint32_t  *x5035);
activation_x5397 * kernel_x5397(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x4666, cppDeliteArraycppDeliteArrayint32_t  *x5380, int32_t  x9, int32_t  x285, int32_t  x99);
activation_x5399 * kernel_x5399(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x5397);
int32_t  kernel_x5400(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x5399);
activation_x5404 * kernel_x5404(resourceInfo_t *resourceInfo,int32_t  x5400, cppDeliteArrayint32_t  *x5399);
activation_x5406 * kernel_x5406(resourceInfo_t *resourceInfo,int32_t  x5400, int32_t  x285, cppDeliteArrayint32_t  *x5404);
string  kernel_x5407(resourceInfo_t *resourceInfo,int32_t  x5406);
void  kernel_x5408(resourceInfo_t *resourceInfo,string  x5407);
int32_t  kernel_x5279(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x5035);
activation_x5411 * kernel_x5411(resourceInfo_t *resourceInfo,int32_t  x5279, cppDeliteArrayint32_t  *x5035);
int32_t  kernel_x5412(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x5411);
activation_x5415 * kernel_x5415(resourceInfo_t *resourceInfo,int32_t  x5412, int32_t  x285, cppDeliteArrayint32_t  *x5411);
string  kernel_x5416(resourceInfo_t *resourceInfo,int32_t  x5415);
void  kernel_x5417(resourceInfo_t *resourceInfo,string  x5416);
activation_x5423 * kernel_x5423(resourceInfo_t *resourceInfo,int32_t  x5279, cppDeliteArrayint32_t  *x5035, cppDeliteArrayint32_t  *x5399);
int32_t  kernel_x5424(resourceInfo_t *resourceInfo,cppDeliteArraybool  *x5423);
bool  kernel_x876(resourceInfo_t *resourceInfo);
activation_x5427 * kernel_x5427(resourceInfo_t *resourceInfo,int32_t  x5424, bool  x876, cppDeliteArraybool  *x5423);
string  kernel_x5428(resourceInfo_t *resourceInfo,bool  x5427);
string  kernel_x5429(resourceInfo_t *resourceInfo,string  x5428);
void  kernel_x5430(resourceInfo_t *resourceInfo,string  x5429);
