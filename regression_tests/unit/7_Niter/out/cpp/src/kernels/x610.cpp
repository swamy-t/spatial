//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x610 * kernel_x610(resourceInfo_t *resourceInfo,int32_t  x46) {
class x610_class{
public:
int32_t x46;

x610_class(int32_t  _x46) {
x46 = _x46;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x46;
}

int64_t loopStart;
int64_t loopSize;
activation_x610 *alloc(resourceInfo_t *resourceInfo) {
activation_x610 * __act = new activation_x610();;
int32_t x51 = (int32_t)(loopSize);
assert(x51 < (size_t)-1);
cppDeliteArrayint32_t *x574 = new (resourceInfo) cppDeliteArrayint32_t(x51);
__act->x610_data = x574;
return __act;
}

activation_x610 *main_par(resourceInfo_t *resourceInfo,activation_x610 *__act,MultiLoopSync<activation_x610*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x610 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x610 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x610 *main_seq(resourceInfo_t *resourceInfo,activation_x610 *__act) {
activation_x610 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x610 *processRange(resourceInfo_t *resourceInfo,activation_x610 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x610 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x610 *init(resourceInfo_t *resourceInfo,activation_x610 *__act,int32_t x47,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x47);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x610 *__act,int32_t x47) {
int32_t  x48 = (int32_t) (x47);
int32_t x50 = x48;
cppDeliteArrayint32_t *x49 = __act->x610_data;
x49->update(x47, x50);
}

void combine(resourceInfo_t *resourceInfo,activation_x610 *__act,activation_x610 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x610 *__act,activation_x610 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x610 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x610 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x610 *__act) {
cppDeliteArrayint32_t * x49 = __act->x610_data;
__act->x610 = x49;
}

activation_x610 *initAct(resourceInfo_t *resourceInfo) {
activation_x610 * act = new activation_x610;
return act;
}

activation_x610 *allocVal;
MultiLoopSync<activation_x610*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x610_class *closure = (x610_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x610_class *x610_closure = new x610_class(x46);
x610_closure->loopStart = 0;
x610_closure->loopSize = x46;
activation_x610 * alloc = x610_closure->alloc(resourceInfo);
activation_x610 * x610 = NULL;
if (resourceInfo->availableThreads <= 1) {
x610 = x610_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x610*> * sync = new MultiLoopSync<activation_x610*>(x610_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x610_closure->allocVal = alloc;
x610_closure->syncVal = sync;
submitWork(r->threadId, x610_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x610_closure)));
i = i+1;
}
x610 = x610_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x610;
}

/**********/

