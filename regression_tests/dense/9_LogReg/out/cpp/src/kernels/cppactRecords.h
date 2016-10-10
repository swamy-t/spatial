#include "cppDeliteStructs.h"
#include "cppDeliteArrays.h"
#include "cppHashMap.h"
#include "DeliteFileInputStream.h"
#include "DeliteFileOutputStream.h"
#include "cppDeliteVariables.h"

#ifndef __activation_x2448__
#define __activation_x2448__
class activation_x2448 {
public:
activation_x2448 *left_act;
cppDeliteArraycppDeliteArrayfloat *x2448;
cppDeliteArraycppDeliteArrayfloat *x2448_data;
};
#endif
#ifndef __activation_x2488__
#define __activation_x2488__
class activation_x2488 {
public:
activation_x2488 *left_act;
cppDeliteArrayfloat *x2488;
cppDeliteArrayfloat *x2488_data;
};
#endif
#ifndef __activation_x2528__
#define __activation_x2528__
class activation_x2528 {
public:
activation_x2528 *left_act;
cppDeliteArrayfloat *x2528;
cppDeliteArrayfloat *x2528_data;
};
#endif
#ifndef __activation_x2576__
#define __activation_x2576__
class activation_x2576 {
public:
activation_x2576 *left_act;
cppDeliteArrayfloat *x2576;
cppDeliteArrayfloat *x2576_data;
cppDeliteArrayfloat *x2576_buf;
int32_t x2576_size;
int32_t x2576_offset;
int32_t x2576_conditionals;
void x2576_data_set(resourceInfo_t *resourceInfo,cppDeliteArrayfloat *xs,int32_t cs) {
x2576_data = xs;
x2576_conditionals = cs;
if (left_act != NULL)
left_act->x2576_data_set(resourceInfo,xs,cs);
}

};
#endif
