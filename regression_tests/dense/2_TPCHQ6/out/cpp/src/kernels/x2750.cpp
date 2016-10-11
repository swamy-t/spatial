//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x2750 * kernel_x2750(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x102) {
// a *thin* loop follows: x2750
class x2750_class{
public:
int32_t x3;
int32_t x102;

x2750_class(int32_t  _x3,int32_t  _x102) {
x3 = _x3;
x102 = _x102;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x2750 *alloc(resourceInfo_t *resourceInfo) {
activation_x2750 * __act = new activation_x2750();;
int32_t x154 = (int32_t)(loopSize);
assert(x154 < (size_t)-1);
cppDeliteArrayint32_t *x2714 = new (resourceInfo) cppDeliteArrayint32_t(x154);
__act->x2750_data = x2714;
return __act;
}

activation_x2750 *main_par(resourceInfo_t *resourceInfo,activation_x2750 *__act,MultiLoopSync<activation_x2750*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2750 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2750 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2750 *main_seq(resourceInfo_t *resourceInfo,activation_x2750 *__act) {
activation_x2750 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2750 *processRange(resourceInfo_t *resourceInfo,activation_x2750 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2750 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2750 *init(resourceInfo_t *resourceInfo,activation_x2750 *__act,int32_t x148,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x148);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2750 *__act,int32_t x148) {
int32_t  x2711 = (int32_t) rand();
int32_t  x2712 = x2711 / x102;
int32_t x153 = x2712;
cppDeliteArrayint32_t *x152 = __act->x2750_data;
x152->update(x148, x153);
}

void combine(resourceInfo_t *resourceInfo,activation_x2750 *__act,activation_x2750 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2750 *__act,activation_x2750 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2750 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2750 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2750 *__act) {
cppDeliteArrayint32_t * x152 = __act->x2750_data;
__act->x2750 = x152;
}

activation_x2750 *initAct(resourceInfo_t *resourceInfo) {
activation_x2750 * act = new activation_x2750;
return act;
}

activation_x2750 *allocVal;
MultiLoopSync<activation_x2750*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2750_class *closure = (x2750_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2750_class *x2750_closure = new x2750_class(x3,x102);
x2750_closure->loopStart = 0;
x2750_closure->loopSize = x3;
activation_x2750 * alloc = x2750_closure->alloc(resourceInfo);
activation_x2750 * x2750 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2750 = x2750_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2750*> * sync = new MultiLoopSync<activation_x2750*>(x2750_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2750_closure->allocVal = alloc;
x2750_closure->syncVal = sync;
submitWork(r->threadId, x2750_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2750_closure)));
i = i+1;
}
x2750 = x2750_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2750;
}

/**********/

