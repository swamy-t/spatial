#include "cppDeliteStructs.h"
#include "cppDeliteArrays.h"
#include "cppHashMap.h"
#include "DeliteFileInputStream.h"
#include "DeliteFileOutputStream.h"
#include "cppDeliteVariables.h"

#ifndef __activation_x3405__
#define __activation_x3405__
class activation_x3405 {
public:
activation_x3405 *left_act;
cppDeliteArraycppDeliteArrayint32_t *x3405;
cppDeliteArraycppDeliteArrayint32_t *x3405_data;
};
#endif
#ifndef __activation_x3443__
#define __activation_x3443__
class activation_x3443 {
public:
activation_x3443 *left_act;
cppDeliteArrayint32_t *x3443;
cppDeliteArrayint32_t *x3443_data;
cppDeliteArrayint32_t *x3443_buf;
int32_t x3443_size;
int32_t x3443_offset;
int32_t x3443_conditionals;
void x3443_data_set(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t *xs,int32_t cs) {
x3443_data = xs;
x3443_conditionals = cs;
if (left_act != NULL)
left_act->x3443_data_set(resourceInfo,xs,cs);
}

};
#endif
#ifndef __activation_x3707__
#define __activation_x3707__
class activation_x3707 {
public:
activation_x3707 *left_act;
cppDeliteArraycppDeliteArrayint32_t *x3707;
cppDeliteArraycppDeliteArrayint32_t *x3707_data;
};
#endif
#ifndef __activation_x3745__
#define __activation_x3745__
class activation_x3745 {
public:
activation_x3745 *left_act;
cppDeliteArrayint32_t *x3745;
cppDeliteArrayint32_t *x3745_data;
cppDeliteArrayint32_t *x3745_buf;
int32_t x3745_size;
int32_t x3745_offset;
int32_t x3745_conditionals;
void x3745_data_set(resourceInfo_t *resourceInfo,cppDeliteArrayint32_t *xs,int32_t cs) {
x3745_data = xs;
x3745_conditionals = cs;
if (left_act != NULL)
left_act->x3745_data_set(resourceInfo,xs,cs);
}

};
#endif
#ifndef __activation_x3803__
#define __activation_x3803__
class activation_x3803 {
public:
activation_x3803 *left_act;
cppDeliteArraybool *x3803;
cppDeliteArraybool *x3803_data;
};
#endif
#ifndef __activation_x3809__
#define __activation_x3809__
class activation_x3809 {
public:
activation_x3809 *left_act;
bool x3809;
bool x3809_zero;
};
#endif
