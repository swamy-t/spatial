//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2713 * kernel_x2713(resourceInfo_t *resourceInfo,int32_t  x5) {
class x2713_class{
public:
int32_t x5;

x2713_class(int32_t  _x5) {
x5 = _x5;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x5;
}

int64_t loopStart;
int64_t loopSize;
activation_x2713 *alloc(resourceInfo_t *resourceInfo) {
activation_x2713 * __act = new activation_x2713();;
int32_t x10 = (int32_t)(loopSize);
assert(x10 < (size_t)-1);
cppDeliteArrayint32_t *x2677 = new (resourceInfo) cppDeliteArrayint32_t(x10);
__act->x2713_data = x2677;
return __act;
}

activation_x2713 *main_par(resourceInfo_t *resourceInfo,activation_x2713 *__act,MultiLoopSync<activation_x2713*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2713 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2713 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2713 *main_seq(resourceInfo_t *resourceInfo,activation_x2713 *__act) {
activation_x2713 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2713 *processRange(resourceInfo_t *resourceInfo,activation_x2713 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2713 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2713 *init(resourceInfo_t *resourceInfo,activation_x2713 *__act,int32_t x6,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x6);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2713 *__act,int32_t x6) {
int32_t  x7 = (int32_t) (x6);
int32_t x9 = x7;
cppDeliteArrayint32_t *x8 = __act->x2713_data;
x8->update(x6, x9);
}

void combine(resourceInfo_t *resourceInfo,activation_x2713 *__act,activation_x2713 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2713 *__act,activation_x2713 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2713 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2713 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2713 *__act) {
cppDeliteArrayint32_t * x8 = __act->x2713_data;
__act->x2713 = x8;
}

activation_x2713 *initAct(resourceInfo_t *resourceInfo) {
activation_x2713 * act = new activation_x2713;
return act;
}

activation_x2713 *allocVal;
MultiLoopSync<activation_x2713*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2713_class *closure = (x2713_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2713_class *x2713_closure = new x2713_class(x5);
x2713_closure->loopStart = 0;
x2713_closure->loopSize = x5;
activation_x2713 * alloc = x2713_closure->alloc(resourceInfo);
activation_x2713 * x2713 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2713 = x2713_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2713*> * sync = new MultiLoopSync<activation_x2713*>(x2713_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2713_closure->allocVal = alloc;
x2713_closure->syncVal = sync;
submitWork(r->threadId, x2713_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2713_closure)));
i = i+1;
}
x2713 = x2713_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2713;
}

/**********/

