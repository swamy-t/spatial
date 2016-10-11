//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x761 * kernel_x761(resourceInfo_t *resourceInfo,int32_t  x3) {
class x761_class{
public:
int32_t x3;

x761_class(int32_t  _x3) {
x3 = _x3;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x761 *alloc(resourceInfo_t *resourceInfo) {
activation_x761 * __act = new activation_x761();;
int32_t x8 = (int32_t)(loopSize);
assert(x8 < (size_t)-1);
cppDeliteArrayint32_t *x725 = new (resourceInfo) cppDeliteArrayint32_t(x8);
__act->x761_data = x725;
return __act;
}

activation_x761 *main_par(resourceInfo_t *resourceInfo,activation_x761 *__act,MultiLoopSync<activation_x761*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x761 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x761 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x761 *main_seq(resourceInfo_t *resourceInfo,activation_x761 *__act) {
activation_x761 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x761 *processRange(resourceInfo_t *resourceInfo,activation_x761 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x761 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x761 *init(resourceInfo_t *resourceInfo,activation_x761 *__act,int32_t x4,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x4);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x761 *__act,int32_t x4) {
int32_t  x5 = (int32_t) (x4);
int32_t x7 = x5;
cppDeliteArrayint32_t *x6 = __act->x761_data;
x6->update(x4, x7);
}

void combine(resourceInfo_t *resourceInfo,activation_x761 *__act,activation_x761 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x761 *__act,activation_x761 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x761 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x761 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x761 *__act) {
cppDeliteArrayint32_t * x6 = __act->x761_data;
__act->x761 = x6;
}

activation_x761 *initAct(resourceInfo_t *resourceInfo) {
activation_x761 * act = new activation_x761;
return act;
}

activation_x761 *allocVal;
MultiLoopSync<activation_x761*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x761_class *closure = (x761_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x761_class *x761_closure = new x761_class(x3);
x761_closure->loopStart = 0;
x761_closure->loopSize = x3;
activation_x761 * alloc = x761_closure->alloc(resourceInfo);
activation_x761 * x761 = NULL;
if (resourceInfo->availableThreads <= 1) {
x761 = x761_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x761*> * sync = new MultiLoopSync<activation_x761*>(x761_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x761_closure->allocVal = alloc;
x761_closure->syncVal = sync;
submitWork(r->threadId, x761_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x761_closure)));
i = i+1;
}
x761 = x761_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x761;
}

/**********/

