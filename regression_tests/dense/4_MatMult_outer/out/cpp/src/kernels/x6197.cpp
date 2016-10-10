//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6197 * kernel_x6197(resourceInfo_t *resourceInfo,int32_t  x9, cppDeliteArraycppDeliteArrayint32_t  *x6195) {
class x6197_class{
public:
int32_t x9;
cppDeliteArraycppDeliteArrayint32_t *x6195;

x6197_class(int32_t  _x9,cppDeliteArraycppDeliteArrayint32_t * _x6195) {
x9 = _x9;
x6195 = _x6195;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x9;
}

int64_t loopStart;
int64_t loopSize;
activation_x6197 *alloc(resourceInfo_t *resourceInfo) {
activation_x6197 * __act = new activation_x6197();;
// __act->x6197 stays null for now
return __act;
}

activation_x6197 *main_par(resourceInfo_t *resourceInfo,activation_x6197 *__act,MultiLoopSync<activation_x6197*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6197 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6197 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x6197 * currentAct = act;
while (j < localEnd) {
activation_x6197 * rhsAct = sync->get(j);
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

activation_x6197 *main_seq(resourceInfo_t *resourceInfo,activation_x6197 *__act) {
activation_x6197 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x6197 *processRange(resourceInfo_t *resourceInfo,activation_x6197 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6197 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6197 *init(resourceInfo_t *resourceInfo,activation_x6197 *__act,int32_t x325,bool isEmpty) {
activation_x6197 * __act2 = new activation_x6197();;
int32_t x333 = 0;
assert(x333 < (size_t)-1);
cppDeliteArrayint32_t *x5548 = new (resourceInfo) cppDeliteArrayint32_t(x333, resourceInfo);
__act2->x6197_buf = x5548;
if (!isEmpty) {
cppDeliteArrayint32_t *x6196 = x6195->apply(x325);
cppDeliteArrayint32_t *x328 = x6196;
int32_t x329 = x328->length;
int32_t  x327 = 0;
while (x327 < x329) { //flatMap loop
int32_t x330 = x328->apply(x327);
cppDeliteArrayint32_t *x331 = __act2->x6197_buf;
int32_t x332 = x330;
if (true) {
int32_t x5554 = __act2->x6197_size;
int32_t x5555 = x331->length;
int32_t x5556 = x5555 - 1;
bool x5557 = x5554 > x5556;
if (x5557) {
bool x5558 = x5555 < 16;
int32_t  x5562;
if (x5558) {
x5562 = 16;
} else {
int32_t x5559 = x5555 * 2;
bool x5560 = x5559 < 0;
int32_t  x5561;
if (x5560) {
x5561 = 2147483647;
} else {
x5561 = x5559;
}
x5562 = x5561;
}
assert(x5562 < (size_t)-1);
cppDeliteArrayint32_t *x5563 = new (resourceInfo) cppDeliteArrayint32_t(x5562, resourceInfo);
if((x331->data==x5563->data) && (0<0))
std::copy_backward(x331->data+0,x331->data+0+x5555,x5563->data+0+x5555);
else {
for (size_t s=0, d=0; s<0+x5555; s++, d++){
x5563->update(d, x331->apply(s));
}
}
x5563->update(x5554, x332);
__act2->x6197_buf = x5563;
} else {
x331->update(x5554, x332);
}
__act2->x6197_size = __act2->x6197_size + 1;
}
__act2->x6197_conditionals = __act2->x6197_conditionals + 1;
x327 = x327 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x6197 *__act,int32_t x325) {
cppDeliteArrayint32_t *x6196 = x6195->apply(x325);
cppDeliteArrayint32_t *x328 = x6196;
int32_t x329 = x328->length;
int32_t  x327 = 0;
while (x327 < x329) { //flatMap loop
int32_t x330 = x328->apply(x327);
cppDeliteArrayint32_t *x331 = __act->x6197_buf;
int32_t x332 = x330;
if (true) {
int32_t x5554 = __act->x6197_size;
int32_t x5555 = x331->length;
int32_t x5556 = x5555 - 1;
bool x5557 = x5554 > x5556;
if (x5557) {
bool x5558 = x5555 < 16;
int32_t  x5562;
if (x5558) {
x5562 = 16;
} else {
int32_t x5559 = x5555 * 2;
bool x5560 = x5559 < 0;
int32_t  x5561;
if (x5560) {
x5561 = 2147483647;
} else {
x5561 = x5559;
}
x5562 = x5561;
}
assert(x5562 < (size_t)-1);
cppDeliteArrayint32_t *x5563 = new (resourceInfo) cppDeliteArrayint32_t(x5562, resourceInfo);
if((x331->data==x5563->data) && (0<0))
std::copy_backward(x331->data+0,x331->data+0+x5555,x5563->data+0+x5555);
else {
for (size_t s=0, d=0; s<0+x5555; s++, d++){
x5563->update(d, x331->apply(s));
}
}
x5563->update(x5554, x332);
__act->x6197_buf = x5563;
} else {
x331->update(x5554, x332);
}
__act->x6197_size = __act->x6197_size + 1;
}
__act->x6197_conditionals = __act->x6197_conditionals + 1;
x327 = x327 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x6197 *__act,activation_x6197 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6197 *__act,activation_x6197 *lhs) {
__act->x6197_offset = lhs->x6197_offset+lhs->x6197_size;
__act->x6197_conditionals = __act->x6197_conditionals+lhs->x6197_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6197 *__act) {
if (__act->x6197_offset > 0) {
int32_t x333 = __act->x6197_offset + __act->x6197_size;
cppDeliteArrayint32_t *x331 = __act->x6197_buf;
assert(x333 < (size_t)-1);
cppDeliteArrayint32_t *x5580 = new (resourceInfo) cppDeliteArrayint32_t(x333);
__act->x6197_data_set(resourceInfo,x5580,__act->x6197_conditionals);
} else {
__act->x6197_data_set(resourceInfo,__act->x6197_buf,__act->x6197_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6197 *__act) {
if (__act->x6197_data != __act->x6197_buf) {
int32_t x333 = __act->x6197_size;
cppDeliteArrayint32_t *x336 = __act->x6197_buf;
cppDeliteArrayint32_t *x331 = __act->x6197_data;
int32_t x334 = 0;
int32_t x335 = __act->x6197_offset;
if((x336->data==x331->data) && (x334<x335))
std::copy_backward(x336->data+x334,x336->data+x334+x333,x331->data+x335+x333);
else {
for (size_t s=x334, d=x335; s<x334+x333; s++, d++){
x331->update(d, x336->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x6197 *__act) {
cppDeliteArrayint32_t * x331 = __act->x6197_data;
int32_t x333 = __act->x6197_conditionals;
int32_t x5572 = x331->length;
bool x5573 = x5572 > x333;
if (x5573) {
assert(x333 < (size_t)-1);
cppDeliteArrayint32_t *x5574 = new (resourceInfo) cppDeliteArrayint32_t(x333);
if((x331->data==x5574->data) && (0<0))
std::copy_backward(x331->data+0,x331->data+0+x333,x5574->data+0+x333);
else {
for (size_t s=0, d=0; s<0+x333; s++, d++){
x5574->update(d, x331->apply(s));
}
}
x331 = x5574;
} else {
}
__act->x6197 = x331;
}

activation_x6197 *initAct(resourceInfo_t *resourceInfo) {
activation_x6197 * act = new activation_x6197;
return act;
}

activation_x6197 *allocVal;
MultiLoopSync<activation_x6197*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6197_class *closure = (x6197_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6197_class *x6197_closure = new x6197_class(x9,x6195);
x6197_closure->loopStart = 0;
x6197_closure->loopSize = x9;
activation_x6197 * alloc = x6197_closure->alloc(resourceInfo);
activation_x6197 * x6197 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6197 = x6197_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6197*> * sync = new MultiLoopSync<activation_x6197*>(x6197_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6197_closure->allocVal = alloc;
x6197_closure->syncVal = sync;
submitWork(r->threadId, x6197_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6197_closure)));
i = i+1;
}
x6197 = x6197_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6197;
}

/**********/

