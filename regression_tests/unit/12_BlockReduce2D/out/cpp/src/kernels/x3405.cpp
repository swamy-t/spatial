//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3405 * kernel_x3405(resourceInfo_t *resourceInfo,int32_t  x5, int32_t  x4, int32_t  x8) {
class x3405_class{
public:
int32_t x5;
int32_t x4;
int32_t x8;

x3405_class(int32_t  _x5,int32_t  _x4,int32_t  _x8) {
x5 = _x5;
x4 = _x4;
x8 = _x8;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x5;
}

int64_t loopStart;
int64_t loopSize;
activation_x3405 *alloc(resourceInfo_t *resourceInfo) {
activation_x3405 * __act = new activation_x3405();;
int32_t x58 = (int32_t)(loopSize);
assert(x58 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x3369 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x58);
__act->x3405_data = x3369;
return __act;
}

activation_x3405 *main_par(resourceInfo_t *resourceInfo,activation_x3405 *__act,MultiLoopSync<activation_x3405*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3405 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3405 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x3405 *main_seq(resourceInfo_t *resourceInfo,activation_x3405 *__act) {
activation_x3405 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3405 *processRange(resourceInfo_t *resourceInfo,activation_x3405 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3405 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3405 *init(resourceInfo_t *resourceInfo,activation_x3405 *__act,int32_t x6,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x6);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x3405 *__act,int32_t x6) {
int32_t  x7 = (int32_t) (x6);
int32_t  x11 = x7 * x4;
int32_t  x15 = x8;
assert(x15 < (size_t)-1);
cppDeliteArrayint32_t *x3332 = new (resourceInfo) cppDeliteArrayint32_t(x15, resourceInfo);
cppDeliteArrayint32_t * x3368_data = x3332;
int32_t  x3368_size = 0;
int32_t  x3368_conditionals = 0;
int32_t  x9 = 0;
while (x9 < x8) {  // begin fat loop x3368
int32_t  x10 = (int32_t) (x9);
int32_t  x12 = x11 + x10;
int32_t x14 = x12;
cppDeliteArrayint32_t *x13 = x3368_data;
x13->update(x9, x14);
x9 = x9 + 1;
} // end fat loop x3368
cppDeliteArrayint32_t *x13 = x3368_data;
cppDeliteArrayint32_t *x3368 = x13;
cppDeliteArrayint32_t *x57 = x3368;
cppDeliteArraycppDeliteArrayint32_t *x56 = __act->x3405_data;
x56->update(x6, x57);
}

void combine(resourceInfo_t *resourceInfo,activation_x3405 *__act,activation_x3405 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3405 *__act,activation_x3405 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3405 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3405 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3405 *__act) {
cppDeliteArraycppDeliteArrayint32_t * x56 = __act->x3405_data;
__act->x3405 = x56;
}

activation_x3405 *initAct(resourceInfo_t *resourceInfo) {
activation_x3405 * act = new activation_x3405;
return act;
}

activation_x3405 *allocVal;
MultiLoopSync<activation_x3405*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3405_class *closure = (x3405_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3405_class *x3405_closure = new x3405_class(x5,x4,x8);
x3405_closure->loopStart = 0;
x3405_closure->loopSize = x5;
activation_x3405 * alloc = x3405_closure->alloc(resourceInfo);
activation_x3405 * x3405 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3405 = x3405_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3405*> * sync = new MultiLoopSync<activation_x3405*>(x3405_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3405_closure->allocVal = alloc;
x3405_closure->syncVal = sync;
submitWork(r->threadId, x3405_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3405_closure)));
i = i+1;
}
x3405 = x3405_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3405;
}

/**********/

