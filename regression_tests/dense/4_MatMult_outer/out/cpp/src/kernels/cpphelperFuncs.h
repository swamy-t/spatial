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
int32_t  kernel_x189(resourceInfo_t *resourceInfo);
int32_t  * kernel_x5345(resourceInfo_t *resourceInfo,int32_t  x189);
int32_t  * kernel_x5346(resourceInfo_t *resourceInfo,int32_t  x189);
int32_t  * kernel_x5347(resourceInfo_t *resourceInfo,int32_t  x189);
string  kernel_x1(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x2(resourceInfo_t *resourceInfo,string  x1);
void  kernel_x5348(resourceInfo_t *resourceInfo,int32_t   *x5345, int32_t  x2);
string  kernel_x3(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x4(resourceInfo_t *resourceInfo,string  x3);
void  kernel_x5349(resourceInfo_t *resourceInfo,int32_t   *x5346, int32_t  x4);
string  kernel_x5(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x6(resourceInfo_t *resourceInfo,string  x5);
void  kernel_x5350(resourceInfo_t *resourceInfo,int32_t   *x5347, int32_t  x6);
int32_t  kernel_x5351(resourceInfo_t *resourceInfo,int32_t   *x5345);
int32_t  kernel_x5352(resourceInfo_t *resourceInfo,int32_t   *x5347);
int32_t  kernel_x5353(resourceInfo_t *resourceInfo,int32_t  x5351, int32_t  x5352);
maxjLmem * kernel_x5354(resourceInfo_t *resourceInfo,int32_t  x5353);
int32_t  kernel_x5355(resourceInfo_t *resourceInfo,int32_t   *x5346);
int32_t  kernel_x5356(resourceInfo_t *resourceInfo,int32_t  x5352, int32_t  x5355);
maxjLmem * kernel_x5357(resourceInfo_t *resourceInfo,int32_t  x5356);
int32_t  kernel_x5358(resourceInfo_t *resourceInfo,int32_t  x5351, int32_t  x5355);
maxjLmem * kernel_x5359(resourceInfo_t *resourceInfo,int32_t  x5358);
maxjLmem * kernel_x5360(resourceInfo_t *resourceInfo,int32_t  x5358);
int32_t  kernel_x7(resourceInfo_t *resourceInfo,int32_t  x2);
int32_t  kernel_x11(resourceInfo_t *resourceInfo);
int32_t  kernel_x99(resourceInfo_t *resourceInfo,int32_t  x4);
activation_x5510x6203 * kernel_x5510x6203(resourceInfo_t *resourceInfo,int32_t  x99, int32_t  x11, int32_t  x189);
int32_t  kernel_x9(resourceInfo_t *resourceInfo,int32_t  x6);
activation_x5397x6195 * kernel_x5397x6195(resourceInfo_t *resourceInfo,int32_t  x9, int32_t  x11, cppDeliteArrayint32_t  *x5510);
activation_x5434 * kernel_x5434(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArrayint32_t  *x5397);
activation_x5472x6204 * kernel_x5472x6204(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArrayint32_t  *x6203, cppDeliteArraycppDeliteArrayint32_t  *x5434);
void  kernel_x5473(resourceInfo_t *resourceInfo,maxjLmem  *x5354, cppDeliteArrayint32_t  *x5472);
activation_x6197 * kernel_x6197(resourceInfo_t *resourceInfo,int32_t  x9, cppDeliteArraycppDeliteArrayint32_t  *x6195);
void  kernel_x6198(resourceInfo_t *resourceInfo,maxjLmem  *x5357, cppDeliteArrayint32_t  *x6197);
activation_x6206 * kernel_x6206(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x6204);
void  kernel_x6207(resourceInfo_t *resourceInfo,maxjLmem  *x5360, cppDeliteArrayint32_t  *x6206);
int32_t  kernel_x3930(resourceInfo_t *resourceInfo);
int32_t  kernel_x3931(resourceInfo_t *resourceInfo);
int32_t  kernel_x3933(resourceInfo_t *resourceInfo);
int32_t  kernel_x461(resourceInfo_t *resourceInfo);
bool  kernel_x620(resourceInfo_t *resourceInfo);
int32_t  kernel_x3935(resourceInfo_t *resourceInfo);
void  kernel_x5832(resourceInfo_t *resourceInfo,int32_t   *x5345, int32_t   *x5346, int32_t  x189, int32_t  x3930, int32_t  x3931, int32_t  x3933, int32_t  x461, int32_t  x11, int32_t  x5355, bool  x620, maxjLmem  *x5360, int32_t   *x5347, int32_t  x3935, int32_t  x5352, maxjLmem  *x5354, maxjLmem  *x5357);
int32_t  kernel_x5833(resourceInfo_t *resourceInfo,int32_t  x5358);
cppDeliteArrayint32_t * kernel_x5834(resourceInfo_t *resourceInfo,int32_t  x5833);
void  kernel_x6208(resourceInfo_t *resourceInfo,maxjLmem  *x5360, cppDeliteArrayint32_t  *x5834);
activation_x6222 * kernel_x6222(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x5434, cppDeliteArraycppDeliteArrayint32_t  *x6195, int32_t  x9, int32_t  x189, int32_t  x99);
activation_x6224 * kernel_x6224(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x6222);
int32_t  kernel_x6225(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x6224);
activation_x6229 * kernel_x6229(resourceInfo_t *resourceInfo,int32_t  x6225, cppDeliteArrayint32_t  *x6224);
activation_x6231 * kernel_x6231(resourceInfo_t *resourceInfo,int32_t  x6225, int32_t  x189, cppDeliteArrayint32_t  *x6229);
string  kernel_x6232(resourceInfo_t *resourceInfo,int32_t  x6231);
void  kernel_x6233(resourceInfo_t *resourceInfo,string  x6232);
int32_t  kernel_x6234(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x5834);
activation_x6237 * kernel_x6237(resourceInfo_t *resourceInfo,int32_t  x6234, cppDeliteArrayint32_t  *x5834);
int32_t  kernel_x6238(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t  *x6237);
activation_x6241 * kernel_x6241(resourceInfo_t *resourceInfo,int32_t  x6238, int32_t  x189, cppDeliteArrayint32_t  *x6237);
string  kernel_x6242(resourceInfo_t *resourceInfo,int32_t  x6241);
void  kernel_x6243(resourceInfo_t *resourceInfo,string  x6242);
void  kernel_x6244(resourceInfo_t *resourceInfo);
int32_t  kernel_x6245(resourceInfo_t *resourceInfo,int32_t  x6225);
void  kernel_x6250(resourceInfo_t *resourceInfo,int32_t  x189, int32_t  x6245, int32_t  x11, cppDeliteArrayint32_t  *x6224);
void  kernel_x6251(resourceInfo_t *resourceInfo);
void  kernel_x6252(resourceInfo_t *resourceInfo);
int32_t  kernel_x6253(resourceInfo_t *resourceInfo,int32_t  x6234);
void  kernel_x6254(resourceInfo_t *resourceInfo,int32_t  x189, int32_t  x6253, int32_t  x11, cppDeliteArrayint32_t  *x5834);
void  kernel_x6255(resourceInfo_t *resourceInfo);
activation_x6261 * kernel_x6261(resourceInfo_t *resourceInfo,int32_t  x6234, cppDeliteArrayint32_t  *x5834, cppDeliteArrayint32_t  *x6224);
int32_t  kernel_x6262(resourceInfo_t *resourceInfo,cppDeliteArraybool  *x6261);
bool  kernel_x1065(resourceInfo_t *resourceInfo);
activation_x6265 * kernel_x6265(resourceInfo_t *resourceInfo,int32_t  x6262, bool  x1065, cppDeliteArraybool  *x6261);
string  kernel_x6266(resourceInfo_t *resourceInfo,bool  x6265);
string  kernel_x6267(resourceInfo_t *resourceInfo,string  x6266);
void  kernel_x6268(resourceInfo_t *resourceInfo,string  x6267);
