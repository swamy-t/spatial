#include "cppDeliteStructs.h"
#include "cppDeliteArrays.h"
#include "cppHashMap.h"
#include "DeliteFileInputStream.h"
#include "DeliteFileOutputStream.h"
#include "cppDeliteVariables.h"

#ifndef __activation_x2513x2871__
#define __activation_x2513x2871__
class activation_x2513x2871 {
public:
activation_x2513x2871 *left_act;
cppDeliteArrayint32_t *x2513;
cppDeliteArrayint32_t *x2513_data;
cppDeliteArrayint32_t *x2871;
cppDeliteArrayint32_t *x2871_data;
};
#endif
#ifndef __activation_x2877__
#define __activation_x2877__
class activation_x2877 {
public:
activation_x2877 *left_act;
cppDeliteArraycppDeliteArrayint32_t *x2877;
cppDeliteArraycppDeliteArrayint32_t *x2877_data;
};
#endif
#ifndef __activation_x2879__
#define __activation_x2879__
class activation_x2879 {
public:
activation_x2879 *left_act;
cppDeliteArrayint32_t *x2879;
cppDeliteArrayint32_t *x2879_data;
cppDeliteArrayint32_t *x2879_buf;
int32_t x2879_size;
int32_t x2879_offset;
int32_t x2879_conditionals;
void x2879_data_set(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t *xs,int32_t cs) {
x2879_data = xs;
x2879_conditionals = cs;
if (left_act != NULL)
left_act->x2879_data_set(resourceInfo,xs,cs);
}

};
#endif
#ifndef __activation_x2896__
#define __activation_x2896__
class activation_x2896 {
public:
activation_x2896 *left_act;
cppDeliteArraybool *x2896;
cppDeliteArraybool *x2896_data;
};
#endif
#ifndef __activation_x2900__
#define __activation_x2900__
class activation_x2900 {
public:
activation_x2900 *left_act;
bool x2900;
bool x2900_zero;
};
#endif
