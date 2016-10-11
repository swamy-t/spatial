//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x2710 * kernel_x2710(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x102) {
// a *thin* loop follows: x2710
class x2710_class{
public:
int32_t x3;
int32_t x102;

x2710_class(int32_t  _x3,int32_t  _x102) {
x3 = _x3;
x102 = _x102;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x2710 *alloc(resourceInfo_t *resourceInfo) {
activation_x2710 * __act = new activation_x2710();;
int32_t x107 = (int32_t)(loopSize);
assert(x107 < (size_t)-1);
cppDeliteArrayint32_t *x2674 = new (resourceInfo) cppDeliteArrayint32_t(x107);
__act->x2710_data = x2674;
return __act;
}

activation_x2710 *main_par(resourceInfo_t *resourceInfo,activation_x2710 *__act,MultiLoopSync<activation_x2710*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2710 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2710 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2710 *main_seq(resourceInfo_t *resourceInfo,activation_x2710 *__act) {
activation_x2710 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2710 *processRange(resourceInfo_t *resourceInfo,activation_x2710 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2710 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2710 *init(resourceInfo_t *resourceInfo,activation_x2710 *__act,int32_t x100,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x100);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2710 *__act,int32_t x100) {
int32_t  x2671 = (int32_t) rand();
int32_t  x2672 = x2671 / x102;
int32_t x106 = x2672;
cppDeliteArrayint32_t *x105 = __act->x2710_data;
x105->update(x100, x106);
}

void combine(resourceInfo_t *resourceInfo,activation_x2710 *__act,activation_x2710 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2710 *__act,activation_x2710 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2710 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2710 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2710 *__act) {
cppDeliteArrayint32_t * x105 = __act->x2710_data;
__act->x2710 = x105;
}

activation_x2710 *initAct(resourceInfo_t *resourceInfo) {
activation_x2710 * act = new activation_x2710;
return act;
}

activation_x2710 *allocVal;
MultiLoopSync<activation_x2710*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2710_class *closure = (x2710_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2710_class *x2710_closure = new x2710_class(x3,x102);
x2710_closure->loopStart = 0;
x2710_closure->loopSize = x3;
activation_x2710 * alloc = x2710_closure->alloc(resourceInfo);
activation_x2710 * x2710 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2710 = x2710_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2710*> * sync = new MultiLoopSync<activation_x2710*>(x2710_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2710_closure->allocVal = alloc;
x2710_closure->syncVal = sync;
submitWork(r->threadId, x2710_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2710_closure)));
i = i+1;
}
x2710 = x2710_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2710;
}

/**********/

