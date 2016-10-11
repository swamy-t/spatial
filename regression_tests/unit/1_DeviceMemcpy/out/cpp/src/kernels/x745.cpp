//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x745 * kernel_x745(resourceInfo_t *resourceInfo,int32_t  x4, int32_t  x2) {
class x745_class{
public:
int32_t x4;
int32_t x2;

x745_class(int32_t  _x4,int32_t  _x2) {
x4 = _x4;
x2 = _x2;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x4;
}

int64_t loopStart;
int64_t loopSize;
activation_x745 *alloc(resourceInfo_t *resourceInfo) {
activation_x745 * __act = new activation_x745();;
int32_t x10 = (int32_t)(loopSize);
assert(x10 < (size_t)-1);
cppDeliteArrayint32_t *x709 = new (resourceInfo) cppDeliteArrayint32_t(x10);
__act->x745_data = x709;
return __act;
}

activation_x745 *main_par(resourceInfo_t *resourceInfo,activation_x745 *__act,MultiLoopSync<activation_x745*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x745 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x745 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x745 *main_seq(resourceInfo_t *resourceInfo,activation_x745 *__act) {
activation_x745 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x745 *processRange(resourceInfo_t *resourceInfo,activation_x745 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x745 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x745 *init(resourceInfo_t *resourceInfo,activation_x745 *__act,int32_t x5,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x5);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x745 *__act,int32_t x5) {
int32_t  x6 = (int32_t) (x5);
int32_t  x7 = x6 * x2;
int32_t x9 = x7;
cppDeliteArrayint32_t *x8 = __act->x745_data;
x8->update(x5, x9);
}

void combine(resourceInfo_t *resourceInfo,activation_x745 *__act,activation_x745 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x745 *__act,activation_x745 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x745 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x745 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x745 *__act) {
cppDeliteArrayint32_t * x8 = __act->x745_data;
__act->x745 = x8;
}

activation_x745 *initAct(resourceInfo_t *resourceInfo) {
activation_x745 * act = new activation_x745;
return act;
}

activation_x745 *allocVal;
MultiLoopSync<activation_x745*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x745_class *closure = (x745_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x745_class *x745_closure = new x745_class(x4,x2);
x745_closure->loopStart = 0;
x745_closure->loopSize = x4;
activation_x745 * alloc = x745_closure->alloc(resourceInfo);
activation_x745 * x745 = NULL;
if (resourceInfo->availableThreads <= 1) {
x745 = x745_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x745*> * sync = new MultiLoopSync<activation_x745*>(x745_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x745_closure->allocVal = alloc;
x745_closure->syncVal = sync;
submitWork(r->threadId, x745_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x745_closure)));
i = i+1;
}
x745 = x745_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x745;
}

/**********/

