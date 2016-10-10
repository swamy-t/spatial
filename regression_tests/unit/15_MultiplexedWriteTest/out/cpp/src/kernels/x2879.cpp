//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2879 * kernel_x2879(resourceInfo_t *resourceInfo,int32_t  x183, cppDeliteArraycppDeliteArrayint32_t  *x2877) {
class x2879_class{
public:
int32_t x183;
cppDeliteArraycppDeliteArrayint32_t *x2877;

x2879_class(int32_t  _x183,cppDeliteArraycppDeliteArrayint32_t * _x2877) {
x183 = _x183;
x2877 = _x2877;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x183;
}

int64_t loopStart;
int64_t loopSize;
activation_x2879 *alloc(resourceInfo_t *resourceInfo) {
activation_x2879 * __act = new activation_x2879();;
// __act->x2879 stays null for now
return __act;
}

activation_x2879 *main_par(resourceInfo_t *resourceInfo,activation_x2879 *__act,MultiLoopSync<activation_x2879*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2879 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2879 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x2879 * currentAct = act;
while (j < localEnd) {
activation_x2879 * rhsAct = sync->get(j);
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

activation_x2879 *main_seq(resourceInfo_t *resourceInfo,activation_x2879 *__act) {
activation_x2879 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x2879 *processRange(resourceInfo_t *resourceInfo,activation_x2879 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2879 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2879 *init(resourceInfo_t *resourceInfo,activation_x2879 *__act,int32_t x381,bool isEmpty) {
activation_x2879 * __act2 = new activation_x2879();;
int32_t x389 = 0;
assert(x389 < (size_t)-1);
cppDeliteArrayint32_t *x2762 = new (resourceInfo) cppDeliteArrayint32_t(x389, resourceInfo);
__act2->x2879_buf = x2762;
if (!isEmpty) {
cppDeliteArrayint32_t *x2878 = x2877->apply(x381);
cppDeliteArrayint32_t *x384 = x2878;
int32_t x385 = x384->length;
int32_t  x383 = 0;
while (x383 < x385) { //flatMap loop
int32_t x386 = x384->apply(x383);
cppDeliteArrayint32_t *x387 = __act2->x2879_buf;
int32_t x388 = x386;
if (true) {
int32_t x2768 = __act2->x2879_size;
int32_t x2769 = x387->length;
int32_t x2770 = x2769 - 1;
bool x2771 = x2768 > x2770;
if (x2771) {
bool x2772 = x2769 < 16;
int32_t  x2776;
if (x2772) {
x2776 = 16;
} else {
int32_t x2773 = x2769 * 2;
bool x2774 = x2773 < 0;
int32_t  x2775;
if (x2774) {
x2775 = 2147483647;
} else {
x2775 = x2773;
}
x2776 = x2775;
}
assert(x2776 < (size_t)-1);
cppDeliteArrayint32_t *x2777 = new (resourceInfo) cppDeliteArrayint32_t(x2776, resourceInfo);
if((x387->data==x2777->data) && (0<0))
std::copy_backward(x387->data+0,x387->data+0+x2769,x2777->data+0+x2769);
else {
for (size_t s=0, d=0; s<0+x2769; s++, d++){
x2777->update(d, x387->apply(s));
}
}
x2777->update(x2768, x388);
__act2->x2879_buf = x2777;
} else {
x387->update(x2768, x388);
}
__act2->x2879_size = __act2->x2879_size + 1;
}
__act2->x2879_conditionals = __act2->x2879_conditionals + 1;
x383 = x383 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x2879 *__act,int32_t x381) {
cppDeliteArrayint32_t *x2878 = x2877->apply(x381);
cppDeliteArrayint32_t *x384 = x2878;
int32_t x385 = x384->length;
int32_t  x383 = 0;
while (x383 < x385) { //flatMap loop
int32_t x386 = x384->apply(x383);
cppDeliteArrayint32_t *x387 = __act->x2879_buf;
int32_t x388 = x386;
if (true) {
int32_t x2768 = __act->x2879_size;
int32_t x2769 = x387->length;
int32_t x2770 = x2769 - 1;
bool x2771 = x2768 > x2770;
if (x2771) {
bool x2772 = x2769 < 16;
int32_t  x2776;
if (x2772) {
x2776 = 16;
} else {
int32_t x2773 = x2769 * 2;
bool x2774 = x2773 < 0;
int32_t  x2775;
if (x2774) {
x2775 = 2147483647;
} else {
x2775 = x2773;
}
x2776 = x2775;
}
assert(x2776 < (size_t)-1);
cppDeliteArrayint32_t *x2777 = new (resourceInfo) cppDeliteArrayint32_t(x2776, resourceInfo);
if((x387->data==x2777->data) && (0<0))
std::copy_backward(x387->data+0,x387->data+0+x2769,x2777->data+0+x2769);
else {
for (size_t s=0, d=0; s<0+x2769; s++, d++){
x2777->update(d, x387->apply(s));
}
}
x2777->update(x2768, x388);
__act->x2879_buf = x2777;
} else {
x387->update(x2768, x388);
}
__act->x2879_size = __act->x2879_size + 1;
}
__act->x2879_conditionals = __act->x2879_conditionals + 1;
x383 = x383 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x2879 *__act,activation_x2879 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2879 *__act,activation_x2879 *lhs) {
__act->x2879_offset = lhs->x2879_offset+lhs->x2879_size;
__act->x2879_conditionals = __act->x2879_conditionals+lhs->x2879_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2879 *__act) {
if (__act->x2879_offset > 0) {
int32_t x389 = __act->x2879_offset + __act->x2879_size;
cppDeliteArrayint32_t *x387 = __act->x2879_buf;
assert(x389 < (size_t)-1);
cppDeliteArrayint32_t *x2794 = new (resourceInfo) cppDeliteArrayint32_t(x389);
__act->x2879_data_set(resourceInfo,x2794,__act->x2879_conditionals);
} else {
__act->x2879_data_set(resourceInfo,__act->x2879_buf,__act->x2879_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2879 *__act) {
if (__act->x2879_data != __act->x2879_buf) {
int32_t x389 = __act->x2879_size;
cppDeliteArrayint32_t *x392 = __act->x2879_buf;
cppDeliteArrayint32_t *x387 = __act->x2879_data;
int32_t x390 = 0;
int32_t x391 = __act->x2879_offset;
if((x392->data==x387->data) && (x390<x391))
std::copy_backward(x392->data+x390,x392->data+x390+x389,x387->data+x391+x389);
else {
for (size_t s=x390, d=x391; s<x390+x389; s++, d++){
x387->update(d, x392->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x2879 *__act) {
cppDeliteArrayint32_t * x387 = __act->x2879_data;
int32_t x389 = __act->x2879_conditionals;
int32_t x2786 = x387->length;
bool x2787 = x2786 > x389;
if (x2787) {
assert(x389 < (size_t)-1);
cppDeliteArrayint32_t *x2788 = new (resourceInfo) cppDeliteArrayint32_t(x389);
if((x387->data==x2788->data) && (0<0))
std::copy_backward(x387->data+0,x387->data+0+x389,x2788->data+0+x389);
else {
for (size_t s=0, d=0; s<0+x389; s++, d++){
x2788->update(d, x387->apply(s));
}
}
x387 = x2788;
} else {
}
__act->x2879 = x387;
}

activation_x2879 *initAct(resourceInfo_t *resourceInfo) {
activation_x2879 * act = new activation_x2879;
return act;
}

activation_x2879 *allocVal;
MultiLoopSync<activation_x2879*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2879_class *closure = (x2879_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2879_class *x2879_closure = new x2879_class(x183,x2877);
x2879_closure->loopStart = 0;
x2879_closure->loopSize = x183;
activation_x2879 * alloc = x2879_closure->alloc(resourceInfo);
activation_x2879 * x2879 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2879 = x2879_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2879*> * sync = new MultiLoopSync<activation_x2879*>(x2879_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2879_closure->allocVal = alloc;
x2879_closure->syncVal = sync;
submitWork(r->threadId, x2879_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2879_closure)));
i = i+1;
}
x2879 = x2879_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2879;
}

/**********/

