//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6189 * kernel_x6189(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x6187) {
class x6189_class{
public:
int32_t x7;
cppDeliteArraycppDeliteArrayint32_t *x6187;

x6189_class(int32_t  _x7,cppDeliteArraycppDeliteArrayint32_t * _x6187) {
x7 = _x7;
x6187 = _x6187;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x7;
}

int64_t loopStart;
int64_t loopSize;
activation_x6189 *alloc(resourceInfo_t *resourceInfo) {
activation_x6189 * __act = new activation_x6189();;
// __act->x6189 stays null for now
return __act;
}

activation_x6189 *main_par(resourceInfo_t *resourceInfo,activation_x6189 *__act,MultiLoopSync<activation_x6189*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6189 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6189 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x6189 * currentAct = act;
while (j < localEnd) {
activation_x6189 * rhsAct = sync->get(j);
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

activation_x6189 *main_seq(resourceInfo_t *resourceInfo,activation_x6189 *__act) {
activation_x6189 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x6189 *processRange(resourceInfo_t *resourceInfo,activation_x6189 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6189 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6189 *init(resourceInfo_t *resourceInfo,activation_x6189 *__act,int32_t x374,bool isEmpty) {
activation_x6189 * __act2 = new activation_x6189();;
int32_t x382 = 0;
assert(x382 < (size_t)-1);
cppDeliteArrayint32_t *x5640 = new (resourceInfo) cppDeliteArrayint32_t(x382, resourceInfo);
__act2->x6189_buf = x5640;
if (!isEmpty) {
cppDeliteArrayint32_t *x6188 = x6187->apply(x374);
cppDeliteArrayint32_t *x377 = x6188;
int32_t x378 = x377->length;
int32_t  x376 = 0;
while (x376 < x378) { //flatMap loop
int32_t x379 = x377->apply(x376);
cppDeliteArrayint32_t *x380 = __act2->x6189_buf;
int32_t x381 = x379;
if (true) {
int32_t x5646 = __act2->x6189_size;
int32_t x5647 = x380->length;
int32_t x5648 = x5647 - 1;
bool x5649 = x5646 > x5648;
if (x5649) {
bool x5650 = x5647 < 16;
int32_t  x5654;
if (x5650) {
x5654 = 16;
} else {
int32_t x5651 = x5647 * 2;
bool x5652 = x5651 < 0;
int32_t  x5653;
if (x5652) {
x5653 = 2147483647;
} else {
x5653 = x5651;
}
x5654 = x5653;
}
assert(x5654 < (size_t)-1);
cppDeliteArrayint32_t *x5655 = new (resourceInfo) cppDeliteArrayint32_t(x5654, resourceInfo);
if((x380->data==x5655->data) && (0<0))
std::copy_backward(x380->data+0,x380->data+0+x5647,x5655->data+0+x5647);
else {
for (size_t s=0, d=0; s<0+x5647; s++, d++){
x5655->update(d, x380->apply(s));
}
}
x5655->update(x5646, x381);
__act2->x6189_buf = x5655;
} else {
x380->update(x5646, x381);
}
__act2->x6189_size = __act2->x6189_size + 1;
}
__act2->x6189_conditionals = __act2->x6189_conditionals + 1;
x376 = x376 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x6189 *__act,int32_t x374) {
cppDeliteArrayint32_t *x6188 = x6187->apply(x374);
cppDeliteArrayint32_t *x377 = x6188;
int32_t x378 = x377->length;
int32_t  x376 = 0;
while (x376 < x378) { //flatMap loop
int32_t x379 = x377->apply(x376);
cppDeliteArrayint32_t *x380 = __act->x6189_buf;
int32_t x381 = x379;
if (true) {
int32_t x5646 = __act->x6189_size;
int32_t x5647 = x380->length;
int32_t x5648 = x5647 - 1;
bool x5649 = x5646 > x5648;
if (x5649) {
bool x5650 = x5647 < 16;
int32_t  x5654;
if (x5650) {
x5654 = 16;
} else {
int32_t x5651 = x5647 * 2;
bool x5652 = x5651 < 0;
int32_t  x5653;
if (x5652) {
x5653 = 2147483647;
} else {
x5653 = x5651;
}
x5654 = x5653;
}
assert(x5654 < (size_t)-1);
cppDeliteArrayint32_t *x5655 = new (resourceInfo) cppDeliteArrayint32_t(x5654, resourceInfo);
if((x380->data==x5655->data) && (0<0))
std::copy_backward(x380->data+0,x380->data+0+x5647,x5655->data+0+x5647);
else {
for (size_t s=0, d=0; s<0+x5647; s++, d++){
x5655->update(d, x380->apply(s));
}
}
x5655->update(x5646, x381);
__act->x6189_buf = x5655;
} else {
x380->update(x5646, x381);
}
__act->x6189_size = __act->x6189_size + 1;
}
__act->x6189_conditionals = __act->x6189_conditionals + 1;
x376 = x376 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x6189 *__act,activation_x6189 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6189 *__act,activation_x6189 *lhs) {
__act->x6189_offset = lhs->x6189_offset+lhs->x6189_size;
__act->x6189_conditionals = __act->x6189_conditionals+lhs->x6189_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6189 *__act) {
if (__act->x6189_offset > 0) {
int32_t x382 = __act->x6189_offset + __act->x6189_size;
cppDeliteArrayint32_t *x380 = __act->x6189_buf;
assert(x382 < (size_t)-1);
cppDeliteArrayint32_t *x5672 = new (resourceInfo) cppDeliteArrayint32_t(x382);
__act->x6189_data_set(resourceInfo,x5672,__act->x6189_conditionals);
} else {
__act->x6189_data_set(resourceInfo,__act->x6189_buf,__act->x6189_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6189 *__act) {
if (__act->x6189_data != __act->x6189_buf) {
int32_t x382 = __act->x6189_size;
cppDeliteArrayint32_t *x385 = __act->x6189_buf;
cppDeliteArrayint32_t *x380 = __act->x6189_data;
int32_t x383 = 0;
int32_t x384 = __act->x6189_offset;
if((x385->data==x380->data) && (x383<x384))
std::copy_backward(x385->data+x383,x385->data+x383+x382,x380->data+x384+x382);
else {
for (size_t s=x383, d=x384; s<x383+x382; s++, d++){
x380->update(d, x385->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x6189 *__act) {
cppDeliteArrayint32_t * x380 = __act->x6189_data;
int32_t x382 = __act->x6189_conditionals;
int32_t x5664 = x380->length;
bool x5665 = x5664 > x382;
if (x5665) {
assert(x382 < (size_t)-1);
cppDeliteArrayint32_t *x5666 = new (resourceInfo) cppDeliteArrayint32_t(x382);
if((x380->data==x5666->data) && (0<0))
std::copy_backward(x380->data+0,x380->data+0+x382,x5666->data+0+x382);
else {
for (size_t s=0, d=0; s<0+x382; s++, d++){
x5666->update(d, x380->apply(s));
}
}
x380 = x5666;
} else {
}
__act->x6189 = x380;
}

activation_x6189 *initAct(resourceInfo_t *resourceInfo) {
activation_x6189 * act = new activation_x6189;
return act;
}

activation_x6189 *allocVal;
MultiLoopSync<activation_x6189*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6189_class *closure = (x6189_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6189_class *x6189_closure = new x6189_class(x7,x6187);
x6189_closure->loopStart = 0;
x6189_closure->loopSize = x7;
activation_x6189 * alloc = x6189_closure->alloc(resourceInfo);
activation_x6189 * x6189 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6189 = x6189_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6189*> * sync = new MultiLoopSync<activation_x6189*>(x6189_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6189_closure->allocVal = alloc;
x6189_closure->syncVal = sync;
submitWork(r->threadId, x6189_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6189_closure)));
i = i+1;
}
x6189 = x6189_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6189;
}

/**********/

