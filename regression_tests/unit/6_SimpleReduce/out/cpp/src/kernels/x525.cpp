//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x525 * kernel_x525(resourceInfo_t *resourceInfo,int32_t  x36, int32_t  x3) {
class x525_class{
public:
int32_t x36;
int32_t x3;

x525_class(int32_t  _x36,int32_t  _x3) {
x36 = _x36;
x3 = _x3;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x36;
}

int64_t loopStart;
int64_t loopSize;
activation_x525 *alloc(resourceInfo_t *resourceInfo) {
activation_x525 * __act = new activation_x525();;
int32_t x42 = (int32_t)(loopSize);
assert(x42 < (size_t)-1);
cppDeliteArrayint32_t *x489 = new (resourceInfo) cppDeliteArrayint32_t(x42);
__act->x525_data = x489;
return __act;
}

activation_x525 *main_par(resourceInfo_t *resourceInfo,activation_x525 *__act,MultiLoopSync<activation_x525*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x525 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x525 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x525 *main_seq(resourceInfo_t *resourceInfo,activation_x525 *__act) {
activation_x525 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x525 *processRange(resourceInfo_t *resourceInfo,activation_x525 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x525 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x525 *init(resourceInfo_t *resourceInfo,activation_x525 *__act,int32_t x37,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x37);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x525 *__act,int32_t x37) {
int32_t  x38 = (int32_t) (x37);
int32_t  x39 = x3 * x38;
int32_t x41 = x39;
cppDeliteArrayint32_t *x40 = __act->x525_data;
x40->update(x37, x41);
}

void combine(resourceInfo_t *resourceInfo,activation_x525 *__act,activation_x525 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x525 *__act,activation_x525 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x525 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x525 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x525 *__act) {
cppDeliteArrayint32_t * x40 = __act->x525_data;
__act->x525 = x40;
}

activation_x525 *initAct(resourceInfo_t *resourceInfo) {
activation_x525 * act = new activation_x525;
return act;
}

activation_x525 *allocVal;
MultiLoopSync<activation_x525*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x525_class *closure = (x525_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x525_class *x525_closure = new x525_class(x36,x3);
x525_closure->loopStart = 0;
x525_closure->loopSize = x36;
activation_x525 * alloc = x525_closure->alloc(resourceInfo);
activation_x525 * x525 = NULL;
if (resourceInfo->availableThreads <= 1) {
x525 = x525_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x525*> * sync = new MultiLoopSync<activation_x525*>(x525_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x525_closure->allocVal = alloc;
x525_closure->syncVal = sync;
submitWork(r->threadId, x525_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x525_closure)));
i = i+1;
}
x525 = x525_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x525;
}

/**********/

