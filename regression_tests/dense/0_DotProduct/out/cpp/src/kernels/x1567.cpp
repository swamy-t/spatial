//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x1567 * kernel_x1567(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x5) {
// a *thin* loop follows: x1567
class x1567_class{
public:
int32_t x3;
int32_t x5;

x1567_class(int32_t  _x3,int32_t  _x5) {
x3 = _x3;
x5 = _x5;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x1567 *alloc(resourceInfo_t *resourceInfo) {
activation_x1567 * __act = new activation_x1567();;
int32_t x56 = (int32_t)(loopSize);
assert(x56 < (size_t)-1);
cppDeliteArrayint32_t *x1531 = new (resourceInfo) cppDeliteArrayint32_t(x56);
__act->x1567_data = x1531;
return __act;
}

activation_x1567 *main_par(resourceInfo_t *resourceInfo,activation_x1567 *__act,MultiLoopSync<activation_x1567*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1567 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1567 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1567 *main_seq(resourceInfo_t *resourceInfo,activation_x1567 *__act) {
activation_x1567 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1567 *processRange(resourceInfo_t *resourceInfo,activation_x1567 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1567 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1567 *init(resourceInfo_t *resourceInfo,activation_x1567 *__act,int32_t x51,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x51);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1567 *__act,int32_t x51) {
int32_t  x1529 = (int32_t) rand() % x5;
int32_t x55 = x1529;
cppDeliteArrayint32_t *x54 = __act->x1567_data;
x54->update(x51, x55);
}

void combine(resourceInfo_t *resourceInfo,activation_x1567 *__act,activation_x1567 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1567 *__act,activation_x1567 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1567 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1567 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1567 *__act) {
cppDeliteArrayint32_t * x54 = __act->x1567_data;
__act->x1567 = x54;
}

activation_x1567 *initAct(resourceInfo_t *resourceInfo) {
activation_x1567 * act = new activation_x1567;
return act;
}

activation_x1567 *allocVal;
MultiLoopSync<activation_x1567*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1567_class *closure = (x1567_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1567_class *x1567_closure = new x1567_class(x3,x5);
x1567_closure->loopStart = 0;
x1567_closure->loopSize = x3;
activation_x1567 * alloc = x1567_closure->alloc(resourceInfo);
activation_x1567 * x1567 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1567 = x1567_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1567*> * sync = new MultiLoopSync<activation_x1567*>(x1567_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1567_closure->allocVal = alloc;
x1567_closure->syncVal = sync;
submitWork(r->threadId, x1567_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1567_closure)));
i = i+1;
}
x1567 = x1567_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1567;
}

/**********/

