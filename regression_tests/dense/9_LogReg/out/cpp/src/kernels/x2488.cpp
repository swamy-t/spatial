//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x2488 * kernel_x2488(resourceInfo_t *resourceInfo,int32_t  x3, float  x8) {
// a *thin* loop follows: x2488
class x2488_class{
public:
int32_t x3;
float x8;

x2488_class(int32_t  _x3,float  _x8) {
x3 = _x3;
x8 = _x8;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x2488 *alloc(resourceInfo_t *resourceInfo) {
activation_x2488 * __act = new activation_x2488();;
int32_t x105 = (int32_t)(loopSize);
assert(x105 < (size_t)-1);
cppDeliteArrayfloat *x2452 = new (resourceInfo) cppDeliteArrayfloat(x105);
__act->x2488_data = x2452;
return __act;
}

activation_x2488 *main_par(resourceInfo_t *resourceInfo,activation_x2488 *__act,MultiLoopSync<activation_x2488*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2488 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2488 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2488 *main_seq(resourceInfo_t *resourceInfo,activation_x2488 *__act) {
activation_x2488 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2488 *processRange(resourceInfo_t *resourceInfo,activation_x2488 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2488 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2488 *init(resourceInfo_t *resourceInfo,activation_x2488 *__act,int32_t x99,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x99);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2488 *__act,int32_t x99) {
float  x2449 = (float) rand() / (float) RAND_MAX;
float  x2450 = x2449 * x8;
float x104 = x2450;
cppDeliteArrayfloat *x103 = __act->x2488_data;
x103->update(x99, x104);
}

void combine(resourceInfo_t *resourceInfo,activation_x2488 *__act,activation_x2488 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2488 *__act,activation_x2488 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2488 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2488 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2488 *__act) {
cppDeliteArrayfloat * x103 = __act->x2488_data;
__act->x2488 = x103;
}

activation_x2488 *initAct(resourceInfo_t *resourceInfo) {
activation_x2488 * act = new activation_x2488;
return act;
}

activation_x2488 *allocVal;
MultiLoopSync<activation_x2488*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2488_class *closure = (x2488_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2488_class *x2488_closure = new x2488_class(x3,x8);
x2488_closure->loopStart = 0;
x2488_closure->loopSize = x3;
activation_x2488 * alloc = x2488_closure->alloc(resourceInfo);
activation_x2488 * x2488 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2488 = x2488_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2488*> * sync = new MultiLoopSync<activation_x2488*>(x2488_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2488_closure->allocVal = alloc;
x2488_closure->syncVal = sync;
submitWork(r->threadId, x2488_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2488_closure)));
i = i+1;
}
x2488 = x2488_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2488;
}

/**********/

