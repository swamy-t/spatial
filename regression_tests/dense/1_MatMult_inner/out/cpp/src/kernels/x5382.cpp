//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5382 * kernel_x5382(resourceInfo_t *resourceInfo,int32_t  x9, cppDeliteArraycppDeliteArrayint32_t  *x5380) {
class x5382_class{
public:
int32_t x9;
cppDeliteArraycppDeliteArrayint32_t *x5380;

x5382_class(int32_t  _x9,cppDeliteArraycppDeliteArrayint32_t * _x5380) {
x9 = _x9;
x5380 = _x5380;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x9;
}

int64_t loopStart;
int64_t loopSize;
activation_x5382 *alloc(resourceInfo_t *resourceInfo) {
activation_x5382 * __act = new activation_x5382();;
// __act->x5382 stays null for now
return __act;
}

activation_x5382 *main_par(resourceInfo_t *resourceInfo,activation_x5382 *__act,MultiLoopSync<activation_x5382*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5382 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5382 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x5382 * currentAct = act;
while (j < localEnd) {
activation_x5382 * rhsAct = sync->get(j);
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

activation_x5382 *main_seq(resourceInfo_t *resourceInfo,activation_x5382 *__act) {
activation_x5382 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x5382 *processRange(resourceInfo_t *resourceInfo,activation_x5382 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5382 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5382 *init(resourceInfo_t *resourceInfo,activation_x5382 *__act,int32_t x236,bool isEmpty) {
activation_x5382 * __act2 = new activation_x5382();;
int32_t x244 = 0;
assert(x244 < (size_t)-1);
cppDeliteArrayint32_t *x4780 = new (resourceInfo) cppDeliteArrayint32_t(x244, resourceInfo);
__act2->x5382_buf = x4780;
if (!isEmpty) {
cppDeliteArrayint32_t *x5381 = x5380->apply(x236);
cppDeliteArrayint32_t *x239 = x5381;
int32_t x240 = x239->length;
int32_t  x238 = 0;
while (x238 < x240) { //flatMap loop
int32_t x241 = x239->apply(x238);
cppDeliteArrayint32_t *x242 = __act2->x5382_buf;
int32_t x243 = x241;
if (true) {
int32_t x4786 = __act2->x5382_size;
int32_t x4787 = x242->length;
int32_t x4788 = x4787 - 1;
bool x4789 = x4786 > x4788;
if (x4789) {
bool x4790 = x4787 < 16;
int32_t  x4794;
if (x4790) {
x4794 = 16;
} else {
int32_t x4791 = x4787 * 2;
bool x4792 = x4791 < 0;
int32_t  x4793;
if (x4792) {
x4793 = 2147483647;
} else {
x4793 = x4791;
}
x4794 = x4793;
}
assert(x4794 < (size_t)-1);
cppDeliteArrayint32_t *x4795 = new (resourceInfo) cppDeliteArrayint32_t(x4794, resourceInfo);
if((x242->data==x4795->data) && (0<0))
std::copy_backward(x242->data+0,x242->data+0+x4787,x4795->data+0+x4787);
else {
for (size_t s=0, d=0; s<0+x4787; s++, d++){
x4795->update(d, x242->apply(s));
}
}
x4795->update(x4786, x243);
__act2->x5382_buf = x4795;
} else {
x242->update(x4786, x243);
}
__act2->x5382_size = __act2->x5382_size + 1;
}
__act2->x5382_conditionals = __act2->x5382_conditionals + 1;
x238 = x238 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x5382 *__act,int32_t x236) {
cppDeliteArrayint32_t *x5381 = x5380->apply(x236);
cppDeliteArrayint32_t *x239 = x5381;
int32_t x240 = x239->length;
int32_t  x238 = 0;
while (x238 < x240) { //flatMap loop
int32_t x241 = x239->apply(x238);
cppDeliteArrayint32_t *x242 = __act->x5382_buf;
int32_t x243 = x241;
if (true) {
int32_t x4786 = __act->x5382_size;
int32_t x4787 = x242->length;
int32_t x4788 = x4787 - 1;
bool x4789 = x4786 > x4788;
if (x4789) {
bool x4790 = x4787 < 16;
int32_t  x4794;
if (x4790) {
x4794 = 16;
} else {
int32_t x4791 = x4787 * 2;
bool x4792 = x4791 < 0;
int32_t  x4793;
if (x4792) {
x4793 = 2147483647;
} else {
x4793 = x4791;
}
x4794 = x4793;
}
assert(x4794 < (size_t)-1);
cppDeliteArrayint32_t *x4795 = new (resourceInfo) cppDeliteArrayint32_t(x4794, resourceInfo);
if((x242->data==x4795->data) && (0<0))
std::copy_backward(x242->data+0,x242->data+0+x4787,x4795->data+0+x4787);
else {
for (size_t s=0, d=0; s<0+x4787; s++, d++){
x4795->update(d, x242->apply(s));
}
}
x4795->update(x4786, x243);
__act->x5382_buf = x4795;
} else {
x242->update(x4786, x243);
}
__act->x5382_size = __act->x5382_size + 1;
}
__act->x5382_conditionals = __act->x5382_conditionals + 1;
x238 = x238 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x5382 *__act,activation_x5382 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5382 *__act,activation_x5382 *lhs) {
__act->x5382_offset = lhs->x5382_offset+lhs->x5382_size;
__act->x5382_conditionals = __act->x5382_conditionals+lhs->x5382_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5382 *__act) {
if (__act->x5382_offset > 0) {
int32_t x244 = __act->x5382_offset + __act->x5382_size;
cppDeliteArrayint32_t *x242 = __act->x5382_buf;
assert(x244 < (size_t)-1);
cppDeliteArrayint32_t *x4812 = new (resourceInfo) cppDeliteArrayint32_t(x244);
__act->x5382_data_set(resourceInfo,x4812,__act->x5382_conditionals);
} else {
__act->x5382_data_set(resourceInfo,__act->x5382_buf,__act->x5382_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5382 *__act) {
if (__act->x5382_data != __act->x5382_buf) {
int32_t x244 = __act->x5382_size;
cppDeliteArrayint32_t *x247 = __act->x5382_buf;
cppDeliteArrayint32_t *x242 = __act->x5382_data;
int32_t x245 = 0;
int32_t x246 = __act->x5382_offset;
if((x247->data==x242->data) && (x245<x246))
std::copy_backward(x247->data+x245,x247->data+x245+x244,x242->data+x246+x244);
else {
for (size_t s=x245, d=x246; s<x245+x244; s++, d++){
x242->update(d, x247->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x5382 *__act) {
cppDeliteArrayint32_t * x242 = __act->x5382_data;
int32_t x244 = __act->x5382_conditionals;
int32_t x4804 = x242->length;
bool x4805 = x4804 > x244;
if (x4805) {
assert(x244 < (size_t)-1);
cppDeliteArrayint32_t *x4806 = new (resourceInfo) cppDeliteArrayint32_t(x244);
if((x242->data==x4806->data) && (0<0))
std::copy_backward(x242->data+0,x242->data+0+x244,x4806->data+0+x244);
else {
for (size_t s=0, d=0; s<0+x244; s++, d++){
x4806->update(d, x242->apply(s));
}
}
x242 = x4806;
} else {
}
__act->x5382 = x242;
}

activation_x5382 *initAct(resourceInfo_t *resourceInfo) {
activation_x5382 * act = new activation_x5382;
return act;
}

activation_x5382 *allocVal;
MultiLoopSync<activation_x5382*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5382_class *closure = (x5382_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5382_class *x5382_closure = new x5382_class(x9,x5380);
x5382_closure->loopStart = 0;
x5382_closure->loopSize = x9;
activation_x5382 * alloc = x5382_closure->alloc(resourceInfo);
activation_x5382 * x5382 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5382 = x5382_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5382*> * sync = new MultiLoopSync<activation_x5382*>(x5382_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5382_closure->allocVal = alloc;
x5382_closure->syncVal = sync;
submitWork(r->threadId, x5382_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5382_closure)));
i = i+1;
}
x5382 = x5382_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5382;
}

/**********/

