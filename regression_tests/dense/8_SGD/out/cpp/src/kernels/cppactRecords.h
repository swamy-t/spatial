#include "cppDeliteStructs.h"
#include "cppDeliteArrays.h"
#include "cppHashMap.h"
#include "DeliteFileInputStream.h"
#include "DeliteFileOutputStream.h"
#include "cppDeliteVariables.h"

#ifndef __activation_x4279__
#define __activation_x4279__
class activation_x4279 {
public:
activation_x4279 *left_act;
cppDeliteArraycppDeliteArrayint32_t *x4279;
cppDeliteArraycppDeliteArrayint32_t *x4279_data;
};
#endif
#ifndef __activation_x4318__
#define __activation_x4318__
class activation_x4318 {
public:
activation_x4318 *left_act;
cppDeliteArrayint32_t *x4318;
cppDeliteArrayint32_t *x4318_data;
};
#endif
#ifndef __activation_x4364__
#define __activation_x4364__
class activation_x4364 {
public:
activation_x4364 *left_act;
cppDeliteArrayint32_t *x4364;
cppDeliteArrayint32_t *x4364_data;
cppDeliteArrayint32_t *x4364_buf;
int32_t x4364_size;
int32_t x4364_offset;
int32_t x4364_conditionals;
void x4364_data_set(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t *xs,int32_t cs) {
x4364_data = xs;
x4364_conditionals = cs;
if (left_act != NULL)
left_act->x4364_data_set(resourceInfo,xs,cs);
}

};
#endif
#ifndef __activation_x4533__
#define __activation_x4533__
class activation_x4533 {
public:
activation_x4533 *left_act;
cppDeliteArrayint32_t *x4533;
cppDeliteArrayint32_t *x4533_data;
};
#endif
#ifndef __activation_x4838__
#define __activation_x4838__
class activation_x4838 {
public:
activation_x4838 *left_act;
cppDeliteArraybool *x4838;
cppDeliteArraybool *x4838_data;
};
#endif
#ifndef __activation_x4844__
#define __activation_x4844__
class activation_x4844 {
public:
activation_x4844 *left_act;
bool x4844;
bool x4844_zero;
};
#endif
