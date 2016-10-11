#include "cpphelperFuncs.h"
cppDeliteArrayint32_t * kernel_x1206(resourceInfo_t *resourceInfo,int32_t  x1205) {
assert(x1205 < (size_t)-1);
cppDeliteArrayint32_t *x1206 = new (resourceInfo) cppDeliteArrayint32_t(x1205, resourceInfo);

return x1206;
}

/**********/

