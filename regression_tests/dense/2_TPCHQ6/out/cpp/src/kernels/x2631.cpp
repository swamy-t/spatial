//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x2631 * kernel_x2631(resourceInfo_t *resourceInfo,int32_t  x3, uint32_t  x5, uint32_t  x7) {
// a *thin* loop follows: x2631
class x2631_class{
public:
int32_t x3;
uint32_t x5;
uint32_t x7;

x2631_class(int32_t  _x3,uint32_t  _x5,uint32_t  _x7) {
x3 = _x3;
x5 = _x5;
x7 = _x7;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x2631 *alloc(resourceInfo_t *resourceInfo) {
activation_x2631 * __act = new activation_x2631();;
int32_t x12 = (int32_t)(loopSize);
assert(x12 < (size_t)-1);
cppDeliteArrayuint32_t *x2595 = new (resourceInfo) cppDeliteArrayuint32_t(x12);
__act->x2631_data = x2595;
return __act;
}

activation_x2631 *main_par(resourceInfo_t *resourceInfo,activation_x2631 *__act,MultiLoopSync<activation_x2631*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2631 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2631 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2631 *main_seq(resourceInfo_t *resourceInfo,activation_x2631 *__act) {
activation_x2631 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2631 *processRange(resourceInfo_t *resourceInfo,activation_x2631 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2631 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2631 *init(resourceInfo_t *resourceInfo,activation_x2631 *__act,int32_t x4,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x4);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2631 *__act,int32_t x4) {
uint32_t  x2592 = (uint32_t) rand() % x5;
uint32_t  x2593 = x2592 + x7;
uint32_t x11 = x2593;
cppDeliteArrayuint32_t *x10 = __act->x2631_data;
x10->update(x4, x11);
}

void combine(resourceInfo_t *resourceInfo,activation_x2631 *__act,activation_x2631 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2631 *__act,activation_x2631 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2631 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2631 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2631 *__act) {
cppDeliteArrayuint32_t * x10 = __act->x2631_data;
__act->x2631 = x10;
}

activation_x2631 *initAct(resourceInfo_t *resourceInfo) {
activation_x2631 * act = new activation_x2631;
return act;
}

activation_x2631 *allocVal;
MultiLoopSync<activation_x2631*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2631_class *closure = (x2631_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2631_class *x2631_closure = new x2631_class(x3,x5,x7);
x2631_closure->loopStart = 0;
x2631_closure->loopSize = x3;
activation_x2631 * alloc = x2631_closure->alloc(resourceInfo);
activation_x2631 * x2631 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2631 = x2631_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2631*> * sync = new MultiLoopSync<activation_x2631*>(x2631_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2631_closure->allocVal = alloc;
x2631_closure->syncVal = sync;
submitWork(r->threadId, x2631_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2631_closure)));
i = i+1;
}
x2631 = x2631_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2631;
}

/**********/

