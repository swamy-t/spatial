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
int32_t  kernel_x5(resourceInfo_t *resourceInfo);
int32_t  kernel_x6(resourceInfo_t *resourceInfo,int32_t  x5);
int32_t  kernel_x9(resourceInfo_t *resourceInfo);
activation_x4279 * kernel_x4279(resourceInfo_t *resourceInfo,int32_t  x6, int32_t  x9);
activation_x4318 * kernel_x4318(resourceInfo_t *resourceInfo,int32_t  x6, int32_t  x9);
int32_t  kernel_x286(resourceInfo_t *resourceInfo);
int32_t  * kernel_x4319(resourceInfo_t *resourceInfo,int32_t  x286);
int32_t  * kernel_x4320(resourceInfo_t *resourceInfo,int32_t  x286);
string  kernel_x1(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x2(resourceInfo_t *resourceInfo,string  x1);
void  kernel_x4321(resourceInfo_t *resourceInfo,int32_t   *x4319, int32_t  x2);
string  kernel_x3(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x4(resourceInfo_t *resourceInfo,string  x3);
void  kernel_x4322(resourceInfo_t *resourceInfo,int32_t   *x4320, int32_t  x4);
int32_t  kernel_x996(resourceInfo_t *resourceInfo);
maxjLmem * kernel_x4323(resourceInfo_t *resourceInfo,int32_t  x996);
maxjLmem * kernel_x4324(resourceInfo_t *resourceInfo,int32_t  x5);
maxjLmem * kernel_x4325(resourceInfo_t *resourceInfo,int32_t  x5);
int32_t  kernel_x4326(resourceInfo_t *resourceInfo,cppDeliteArraycppDeliteArrayint32_t  *x4279);
activation_x4364 * kernel_x4364(resourceInfo_t *resourceInfo,int32_t  x4326, cppDeliteArraycppDeliteArrayint32_t  *x4279);
void  kernel_x4365(resourceInfo_t *resourceInfo,maxjLmem  *x4323, cppDeliteArrayint32_t  *x4364);
void  kernel_x4366(resourceInfo_t *resourceInfo,maxjLmem  *x4324, cppDeliteArrayint32_t  *x4318);
int32_t  kernel_x303(resourceInfo_t *resourceInfo);
int32_t  kernel_x312(resourceInfo_t *resourceInfo);
bool  kernel_x381(resourceInfo_t *resourceInfo);
void  kernel_x4490(resourceInfo_t *resourceInfo,int32_t  x996, int32_t  x286, int32_t  x5, int32_t   *x4320, int32_t  x303, int32_t  x312, bool  x381, maxjLmem  *x4323, maxjLmem  *x4324, int32_t   *x4319, maxjLmem  *x4325);
cppDeliteArrayint32_t * kernel_x4491(resourceInfo_t *resourceInfo,int32_t  x6);
void  kernel_x4492(resourceInfo_t *resourceInfo,maxjLmem  *x4325, cppDeliteArrayint32_t  *x4491);
cppDeliteArrayint32_t * kernel_x4493(resourceInfo_t *resourceInfo,int32_t  x6);
void  kernel_x4496(resourceInfo_t *resourceInfo,int32_t  x286, int32_t  x5, int32_t  x303, cppDeliteArrayint32_t  *x4493);
activation_x4533 * kernel_x4533(resourceInfo_t *resourceInfo,int32_t  x6);
void  kernel_x4792(resourceInfo_t *resourceInfo,int32_t  x286, int32_t  x4, int32_t  x303, cppDeliteArraycppDeliteArrayint32_t  *x4279, cppDeliteArrayint32_t  *x4493, int32_t  x4326, cppDeliteArrayint32_t  *x4533, cppDeliteArrayint32_t  *x4318, int32_t  x6, int32_t  x2, int32_t  x5);
int32_t  kernel_x4793(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x4493);
activation_x4838 * kernel_x4838(resourceInfo_t *resourceInfo,int32_t  x4793, cppDeliteArrayint32_t  *x4493, cppDeliteArrayint32_t  *x4491, int32_t  x303);
int32_t  kernel_x4839(resourceInfo_t *resourceInfo,cppDeliteArraybool  *x4838);
void  kernel_x4845(resourceInfo_t *resourceInfo);
int32_t  kernel_x4846(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x4491);
int32_t  kernel_x4847(resourceInfo_t *resourceInfo,int32_t  x4846);
void  kernel_x4852(resourceInfo_t *resourceInfo,int32_t  x286, int32_t  x4847, int32_t  x303, cppDeliteArrayint32_t  *x4491);
void  kernel_x4853(resourceInfo_t *resourceInfo);
void  kernel_x4854(resourceInfo_t *resourceInfo);
int32_t  kernel_x4855(resourceInfo_t *resourceInfo,int32_t  x4793);
void  kernel_x4860(resourceInfo_t *resourceInfo,int32_t  x286, int32_t  x4855, int32_t  x303, cppDeliteArrayint32_t  *x4493);
void  kernel_x4861(resourceInfo_t *resourceInfo);
bool  kernel_x838(resourceInfo_t *resourceInfo);
activation_x4844 * kernel_x4844(resourceInfo_t *resourceInfo,int32_t  x4839, bool  x838, cppDeliteArraybool  *x4838);
string  kernel_x4862(resourceInfo_t *resourceInfo,bool  x4844);
string  kernel_x4863(resourceInfo_t *resourceInfo,string  x4862);
void  kernel_x4864(resourceInfo_t *resourceInfo,string  x4863);
