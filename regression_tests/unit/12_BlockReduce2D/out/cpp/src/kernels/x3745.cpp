//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3745 * kernel_x3745(resourceInfo_t *resourceInfo,int32_t  x314, cppDeliteArraycppDeliteArrayint32_t  *x3707) {
class x3745_class{
public:
int32_t x314;
cppDeliteArraycppDeliteArrayint32_t *x3707;

x3745_class(int32_t  _x314,cppDeliteArraycppDeliteArrayint32_t * _x3707) {
x314 = _x314;
x3707 = _x3707;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x314;
}

int64_t loopStart;
int64_t loopSize;
activation_x3745 *alloc(resourceInfo_t *resourceInfo) {
activation_x3745 * __act = new activation_x3745();;
// __act->x3745 stays null for now
return __act;
}

activation_x3745 *main_par(resourceInfo_t *resourceInfo,activation_x3745 *__act,MultiLoopSync<activation_x3745*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3745 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3745 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x3745 * currentAct = act;
while (j < localEnd) {
activation_x3745 * rhsAct = sync->get(j);
postCombine(resourceInfo,rhsAct,currentAct);
currentAct = rhsAct;
j = j+1;
}
if (tid == numThreads-1) postProcInit(resourceInfo,currentAct);
sync->setP(tid, currentAct);
sync->awaitBarrier();
//post process
int32_t  k = localStart;
while (k < localEnd) {
postProcess(resourceInfo,sync->get(k));
k = k+1;
}
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x3745 *main_seq(resourceInfo_t *resourceInfo,activation_x3745 *__act) {
activation_x3745 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x3745 *processRange(resourceInfo_t *resourceInfo,activation_x3745 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3745 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3745 *init(resourceInfo_t *resourceInfo,activation_x3745 *__act,int32_t x744,bool isEmpty) {
activation_x3745 * __act2 = new activation_x3745();;
int32_t x752 = 0;
assert(x752 < (size_t)-1);
cppDeliteArrayint32_t *x3708 = new (resourceInfo) cppDeliteArrayint32_t(x752, resourceInfo);
__act2->x3745_buf = x3708;
if (!isEmpty) {
cppDeliteArrayint32_t *x3744 = x3707->apply(x744);
cppDeliteArrayint32_t *x747 = x3744;
int32_t x748 = x747->length;
int32_t  x746 = 0;
while (x746 < x748) { //flatMap loop
int32_t x749 = x747->apply(x746);
cppDeliteArrayint32_t *x750 = __act2->x3745_buf;
int32_t x751 = x749;
if (true) {
int32_t x3714 = __act2->x3745_size;
int32_t x3715 = x750->length;
int32_t x3716 = x3715 - 1;
bool x3717 = x3714 > x3716;
if (x3717) {
bool x3718 = x3715 < 16;
int32_t  x3722;
if (x3718) {
x3722 = 16;
} else {
int32_t x3719 = x3715 * 2;
bool x3720 = x3719 < 0;
int32_t  x3721;
if (x3720) {
x3721 = 2147483647;
} else {
x3721 = x3719;
}
x3722 = x3721;
}
assert(x3722 < (size_t)-1);
cppDeliteArrayint32_t *x3723 = new (resourceInfo) cppDeliteArrayint32_t(x3722, resourceInfo);
if((x750->data==x3723->data) && (0<0))
std::copy_backward(x750->data+0,x750->data+0+x3715,x3723->data+0+x3715);
else {
for (size_t s=0, d=0; s<0+x3715; s++, d++){
x3723->update(d, x750->apply(s));
}
}
x3723->update(x3714, x751);
__act2->x3745_buf = x3723;
} else {
x750->update(x3714, x751);
}
__act2->x3745_size = __act2->x3745_size + 1;
}
__act2->x3745_conditionals = __act2->x3745_conditionals + 1;
x746 = x746 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x3745 *__act,int32_t x744) {
cppDeliteArrayint32_t *x3744 = x3707->apply(x744);
cppDeliteArrayint32_t *x747 = x3744;
int32_t x748 = x747->length;
int32_t  x746 = 0;
while (x746 < x748) { //flatMap loop
int32_t x749 = x747->apply(x746);
cppDeliteArrayint32_t *x750 = __act->x3745_buf;
int32_t x751 = x749;
if (true) {
int32_t x3714 = __act->x3745_size;
int32_t x3715 = x750->length;
int32_t x3716 = x3715 - 1;
bool x3717 = x3714 > x3716;
if (x3717) {
bool x3718 = x3715 < 16;
int32_t  x3722;
if (x3718) {
x3722 = 16;
} else {
int32_t x3719 = x3715 * 2;
bool x3720 = x3719 < 0;
int32_t  x3721;
if (x3720) {
x3721 = 2147483647;
} else {
x3721 = x3719;
}
x3722 = x3721;
}
assert(x3722 < (size_t)-1);
cppDeliteArrayint32_t *x3723 = new (resourceInfo) cppDeliteArrayint32_t(x3722, resourceInfo);
if((x750->data==x3723->data) && (0<0))
std::copy_backward(x750->data+0,x750->data+0+x3715,x3723->data+0+x3715);
else {
for (size_t s=0, d=0; s<0+x3715; s++, d++){
x3723->update(d, x750->apply(s));
}
}
x3723->update(x3714, x751);
__act->x3745_buf = x3723;
} else {
x750->update(x3714, x751);
}
__act->x3745_size = __act->x3745_size + 1;
}
__act->x3745_conditionals = __act->x3745_conditionals + 1;
x746 = x746 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x3745 *__act,activation_x3745 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3745 *__act,activation_x3745 *lhs) {
__act->x3745_offset = lhs->x3745_offset+lhs->x3745_size;
__act->x3745_conditionals = __act->x3745_conditionals+lhs->x3745_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3745 *__act) {
if (__act->x3745_offset > 0) {
int32_t x752 = __act->x3745_offset + __act->x3745_size;
cppDeliteArrayint32_t *x750 = __act->x3745_buf;
assert(x752 < (size_t)-1);
cppDeliteArrayint32_t *x3740 = new (resourceInfo) cppDeliteArrayint32_t(x752);
__act->x3745_data_set(resourceInfo,x3740,__act->x3745_conditionals);
} else {
__act->x3745_data_set(resourceInfo,__act->x3745_buf,__act->x3745_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3745 *__act) {
if (__act->x3745_data != __act->x3745_buf) {
int32_t x752 = __act->x3745_size;
cppDeliteArrayint32_t *x755 = __act->x3745_buf;
cppDeliteArrayint32_t *x750 = __act->x3745_data;
int32_t x753 = 0;
int32_t x754 = __act->x3745_offset;
if((x755->data==x750->data) && (x753<x754))
std::copy_backward(x755->data+x753,x755->data+x753+x752,x750->data+x754+x752);
else {
for (size_t s=x753, d=x754; s<x753+x752; s++, d++){
x750->update(d, x755->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x3745 *__act) {
cppDeliteArrayint32_t * x750 = __act->x3745_data;
int32_t x752 = __act->x3745_conditionals;
int32_t x3732 = x750->length;
bool x3733 = x3732 > x752;
if (x3733) {
assert(x752 < (size_t)-1);
cppDeliteArrayint32_t *x3734 = new (resourceInfo) cppDeliteArrayint32_t(x752);
if((x750->data==x3734->data) && (0<0))
std::copy_backward(x750->data+0,x750->data+0+x752,x3734->data+0+x752);
else {
for (size_t s=0, d=0; s<0+x752; s++, d++){
x3734->update(d, x750->apply(s));
}
}
x750 = x3734;
} else {
}
__act->x3745 = x750;
}

activation_x3745 *initAct(resourceInfo_t *resourceInfo) {
activation_x3745 * act = new activation_x3745;
return act;
}

activation_x3745 *allocVal;
MultiLoopSync<activation_x3745*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3745_class *closure = (x3745_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3745_class *x3745_closure = new x3745_class(x314,x3707);
x3745_closure->loopStart = 0;
x3745_closure->loopSize = x314;
activation_x3745 * alloc = x3745_closure->alloc(resourceInfo);
activation_x3745 * x3745 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3745 = x3745_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3745*> * sync = new MultiLoopSync<activation_x3745*>(x3745_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3745_closure->allocVal = alloc;
x3745_closure->syncVal = sync;
submitWork(r->threadId, x3745_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3745_closure)));
i = i+1;
}
x3745 = x3745_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3745;
}

/**********/

