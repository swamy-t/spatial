//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x4074 * kernel_x4074(resourceInfo_t *resourceInfo,int32_t  x14, uint32_t  x16) {
// a *thin* loop follows: x4074
class x4074_class{
public:
int32_t x14;
uint32_t x16;

x4074_class(int32_t  _x14,uint32_t  _x16) {
x14 = _x14;
x16 = _x16;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x14;
}

int64_t loopStart;
int64_t loopSize;
activation_x4074 *alloc(resourceInfo_t *resourceInfo) {
activation_x4074 * __act = new activation_x4074();;
int32_t x21 = (int32_t)(loopSize);
assert(x21 < (size_t)-1);
cppDeliteArrayuint32_t *x4038 = new (resourceInfo) cppDeliteArrayuint32_t(x21);
__act->x4074_data = x4038;
return __act;
}

activation_x4074 *main_par(resourceInfo_t *resourceInfo,activation_x4074 *__act,MultiLoopSync<activation_x4074*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4074 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4074 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4074 *main_seq(resourceInfo_t *resourceInfo,activation_x4074 *__act) {
activation_x4074 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4074 *processRange(resourceInfo_t *resourceInfo,activation_x4074 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4074 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4074 *init(resourceInfo_t *resourceInfo,activation_x4074 *__act,int32_t x15,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x15);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4074 *__act,int32_t x15) {
uint32_t  x4036 = (uint32_t) rand() % x16;
uint32_t x20 = x4036;
cppDeliteArrayuint32_t *x19 = __act->x4074_data;
x19->update(x15, x20);
}

void combine(resourceInfo_t *resourceInfo,activation_x4074 *__act,activation_x4074 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4074 *__act,activation_x4074 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4074 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4074 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4074 *__act) {
cppDeliteArrayuint32_t * x19 = __act->x4074_data;
__act->x4074 = x19;
}

activation_x4074 *initAct(resourceInfo_t *resourceInfo) {
activation_x4074 * act = new activation_x4074;
return act;
}

activation_x4074 *allocVal;
MultiLoopSync<activation_x4074*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4074_class *closure = (x4074_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4074_class *x4074_closure = new x4074_class(x14,x16);
x4074_closure->loopStart = 0;
x4074_closure->loopSize = x14;
activation_x4074 * alloc = x4074_closure->alloc(resourceInfo);
activation_x4074 * x4074 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4074 = x4074_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4074*> * sync = new MultiLoopSync<activation_x4074*>(x4074_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4074_closure->allocVal = alloc;
x4074_closure->syncVal = sync;
submitWork(r->threadId, x4074_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4074_closure)));
i = i+1;
}
x4074 = x4074_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4074;
}

/**********/

