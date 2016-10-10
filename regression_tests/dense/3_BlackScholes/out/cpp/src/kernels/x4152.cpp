//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x4152 * kernel_x4152(resourceInfo_t *resourceInfo,int32_t  x14) {
// a *thin* loop follows: x4152
class x4152_class{
public:
int32_t x14;

x4152_class(int32_t  _x14) {
x14 = _x14;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x14;
}

int64_t loopStart;
int64_t loopSize;
activation_x4152 *alloc(resourceInfo_t *resourceInfo) {
activation_x4152 * __act = new activation_x4152();;
int32_t x113 = (int32_t)(loopSize);
assert(x113 < (size_t)-1);
cppDeliteArrayfloat *x4116 = new (resourceInfo) cppDeliteArrayfloat(x113);
__act->x4152_data = x4116;
return __act;
}

activation_x4152 *main_par(resourceInfo_t *resourceInfo,activation_x4152 *__act,MultiLoopSync<activation_x4152*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4152 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4152 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4152 *main_seq(resourceInfo_t *resourceInfo,activation_x4152 *__act) {
activation_x4152 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4152 *processRange(resourceInfo_t *resourceInfo,activation_x4152 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4152 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4152 *init(resourceInfo_t *resourceInfo,activation_x4152 *__act,int32_t x108,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x108);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4152 *__act,int32_t x108) {
float  x4114 = (float) rand() / (float) RAND_MAX;
float x112 = x4114;
cppDeliteArrayfloat *x111 = __act->x4152_data;
x111->update(x108, x112);
}

void combine(resourceInfo_t *resourceInfo,activation_x4152 *__act,activation_x4152 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4152 *__act,activation_x4152 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4152 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4152 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4152 *__act) {
cppDeliteArrayfloat * x111 = __act->x4152_data;
__act->x4152 = x111;
}

activation_x4152 *initAct(resourceInfo_t *resourceInfo) {
activation_x4152 * act = new activation_x4152;
return act;
}

activation_x4152 *allocVal;
MultiLoopSync<activation_x4152*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4152_class *closure = (x4152_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4152_class *x4152_closure = new x4152_class(x14);
x4152_closure->loopStart = 0;
x4152_closure->loopSize = x14;
activation_x4152 * alloc = x4152_closure->alloc(resourceInfo);
activation_x4152 * x4152 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4152 = x4152_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4152*> * sync = new MultiLoopSync<activation_x4152*>(x4152_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4152_closure->allocVal = alloc;
x4152_closure->syncVal = sync;
submitWork(r->threadId, x4152_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4152_closure)));
i = i+1;
}
x4152 = x4152_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4152;
}

/**********/

