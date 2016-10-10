#include "cpphelperFuncs.h"
void  kernel_x3040(resourceInfo_t *resourceInfo,int32_t  x99, int32_t  x470, int32_t  x53, cppDeliteArrayint32_t  *x2825, cppDeliteArrayint32_t  *x2941) {
for(int32_t i=x99; i<x470; i+=x53) {
int32_t x472 = i;
int32_t  x473 = (int32_t) x472;
int32_t x3035 = x2825->apply(x473);
int32_t x3036 = x2941->apply(x473);
bool  x3037 = x3035 == x3036;
assert(x3037);
}

}

/**********/

