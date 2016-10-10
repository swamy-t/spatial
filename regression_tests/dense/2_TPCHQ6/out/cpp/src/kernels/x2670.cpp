//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x2670 * kernel_x2670(resourceInfo_t *resourceInfo,int32_t  x3, uint32_t  x54) {
// a *thin* loop follows: x2670
class x2670_class{
public:
int32_t x3;
uint32_t x54;

x2670_class(int32_t  _x3,uint32_t  _x54) {
x3 = _x3;
x54 = _x54;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x2670 *alloc(resourceInfo_t *resourceInfo) {
activation_x2670 * __act = new activation_x2670();;
int32_t x59 = (int32_t)(loopSize);
assert(x59 < (size_t)-1);
cppDeliteArrayuint32_t *x2634 = new (resourceInfo) cppDeliteArrayuint32_t(x59);
__act->x2670_data = x2634;
return __act;
}

activation_x2670 *main_par(resourceInfo_t *resourceInfo,activation_x2670 *__act,MultiLoopSync<activation_x2670*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2670 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2670 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2670 *main_seq(resourceInfo_t *resourceInfo,activation_x2670 *__act) {
activation_x2670 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2670 *processRange(resourceInfo_t *resourceInfo,activation_x2670 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2670 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2670 *init(resourceInfo_t *resourceInfo,activation_x2670 *__act,int32_t x53,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x53);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2670 *__act,int32_t x53) {
uint32_t  x2632 = (uint32_t) rand() % x54;
uint32_t x58 = x2632;
cppDeliteArrayuint32_t *x57 = __act->x2670_data;
x57->update(x53, x58);
}

void combine(resourceInfo_t *resourceInfo,activation_x2670 *__act,activation_x2670 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2670 *__act,activation_x2670 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2670 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2670 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2670 *__act) {
cppDeliteArrayuint32_t * x57 = __act->x2670_data;
__act->x2670 = x57;
}

activation_x2670 *initAct(resourceInfo_t *resourceInfo) {
activation_x2670 * act = new activation_x2670;
return act;
}

activation_x2670 *allocVal;
MultiLoopSync<activation_x2670*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2670_class *closure = (x2670_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2670_class *x2670_closure = new x2670_class(x3,x54);
x2670_closure->loopStart = 0;
x2670_closure->loopSize = x3;
activation_x2670 * alloc = x2670_closure->alloc(resourceInfo);
activation_x2670 * x2670 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2670 = x2670_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2670*> * sync = new MultiLoopSync<activation_x2670*>(x2670_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2670_closure->allocVal = alloc;
x2670_closure->syncVal = sync;
submitWork(r->threadId, x2670_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2670_closure)));
i = i+1;
}
x2670 = x2670_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2670;
}

/**********/

