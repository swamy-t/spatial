#include "cppDeliteStructs.h"
#include "cppDeliteArrays.h"
#include "cppHashMap.h"
#include "DeliteFileInputStream.h"
#include "DeliteFileOutputStream.h"
#include "cppDeliteVariables.h"

#ifndef __activation_x2814x3220__
#define __activation_x2814x3220__
class activation_x2814x3220 {
public:
activation_x2814x3220 *left_act;
cppDeliteArrayint32_t *x2814;
cppDeliteArrayint32_t *x2814_data;
cppDeliteArrayint32_t *x3220;
cppDeliteArrayint32_t *x3220_data;
};
#endif
#ifndef __activation_x3226__
#define __activation_x3226__
class activation_x3226 {
public:
activation_x3226 *left_act;
cppDeliteArraycppDeliteArrayint32_t *x3226;
cppDeliteArraycppDeliteArrayint32_t *x3226_data;
};
#endif
#ifndef __activation_x3228__
#define __activation_x3228__
class activation_x3228 {
public:
activation_x3228 *left_act;
cppDeliteArrayint32_t *x3228;
cppDeliteArrayint32_t *x3228_data;
cppDeliteArrayint32_t *x3228_buf;
int32_t x3228_size;
int32_t x3228_offset;
int32_t x3228_conditionals;
void x3228_data_set(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t *xs,int32_t cs) {
x3228_data = xs;
x3228_conditionals = cs;
if (left_act != NULL)
left_act->x3228_data_set(resourceInfo,xs,cs);
}

};
#endif
#ifndef __activation_x3245__
#define __activation_x3245__
class activation_x3245 {
public:
activation_x3245 *left_act;
cppDeliteArraybool *x3245;
cppDeliteArraybool *x3245_data;
};
#endif
#ifndef __activation_x3249__
#define __activation_x3249__
class activation_x3249 {
public:
activation_x3249 *left_act;
bool x3249;
bool x3249_zero;
};
#endif
