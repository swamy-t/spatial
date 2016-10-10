//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x1528 * kernel_x1528(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x5) {
// a *thin* loop follows: x1528
class x1528_class{
public:
int32_t x3;
int32_t x5;

x1528_class(int32_t  _x3,int32_t  _x5) {
x3 = _x3;
x5 = _x5;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x1528 *alloc(resourceInfo_t *resourceInfo) {
activation_x1528 * __act = new activation_x1528();;
int32_t x10 = (int32_t)(loopSize);
assert(x10 < (size_t)-1);
cppDeliteArrayint32_t *x1492 = new (resourceInfo) cppDeliteArrayint32_t(x10);
__act->x1528_data = x1492;
return __act;
}

activation_x1528 *main_par(resourceInfo_t *resourceInfo,activation_x1528 *__act,MultiLoopSync<activation_x1528*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1528 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1528 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1528 *main_seq(resourceInfo_t *resourceInfo,activation_x1528 *__act) {
activation_x1528 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1528 *processRange(resourceInfo_t *resourceInfo,activation_x1528 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1528 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1528 *init(resourceInfo_t *resourceInfo,activation_x1528 *__act,int32_t x4,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x4);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1528 *__act,int32_t x4) {
int32_t  x1490 = (int32_t) rand() % x5;
int32_t x9 = x1490;
cppDeliteArrayint32_t *x8 = __act->x1528_data;
x8->update(x4, x9);
}

void combine(resourceInfo_t *resourceInfo,activation_x1528 *__act,activation_x1528 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1528 *__act,activation_x1528 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1528 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1528 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1528 *__act) {
cppDeliteArrayint32_t * x8 = __act->x1528_data;
__act->x1528 = x8;
}

activation_x1528 *initAct(resourceInfo_t *resourceInfo) {
activation_x1528 * act = new activation_x1528;
return act;
}

activation_x1528 *allocVal;
MultiLoopSync<activation_x1528*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1528_class *closure = (x1528_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1528_class *x1528_closure = new x1528_class(x3,x5);
x1528_closure->loopStart = 0;
x1528_closure->loopSize = x3;
activation_x1528 * alloc = x1528_closure->alloc(resourceInfo);
activation_x1528 * x1528 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1528 = x1528_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1528*> * sync = new MultiLoopSync<activation_x1528*>(x1528_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1528_closure->allocVal = alloc;
x1528_closure->syncVal = sync;
submitWork(r->threadId, x1528_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1528_closure)));
i = i+1;
}
x1528 = x1528_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1528;
}

/**********/

