//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x4191 * kernel_x4191(resourceInfo_t *resourceInfo,int32_t  x14) {
// a *thin* loop follows: x4191
class x4191_class{
public:
int32_t x14;

x4191_class(int32_t  _x14) {
x14 = _x14;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x14;
}

int64_t loopStart;
int64_t loopSize;
activation_x4191 *alloc(resourceInfo_t *resourceInfo) {
activation_x4191 * __act = new activation_x4191();;
int32_t x159 = (int32_t)(loopSize);
assert(x159 < (size_t)-1);
cppDeliteArrayfloat *x4155 = new (resourceInfo) cppDeliteArrayfloat(x159);
__act->x4191_data = x4155;
return __act;
}

activation_x4191 *main_par(resourceInfo_t *resourceInfo,activation_x4191 *__act,MultiLoopSync<activation_x4191*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4191 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4191 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4191 *main_seq(resourceInfo_t *resourceInfo,activation_x4191 *__act) {
activation_x4191 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4191 *processRange(resourceInfo_t *resourceInfo,activation_x4191 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4191 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4191 *init(resourceInfo_t *resourceInfo,activation_x4191 *__act,int32_t x154,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x154);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4191 *__act,int32_t x154) {
float  x4153 = (float) rand() / (float) RAND_MAX;
float x158 = x4153;
cppDeliteArrayfloat *x157 = __act->x4191_data;
x157->update(x154, x158);
}

void combine(resourceInfo_t *resourceInfo,activation_x4191 *__act,activation_x4191 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4191 *__act,activation_x4191 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4191 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4191 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4191 *__act) {
cppDeliteArrayfloat * x157 = __act->x4191_data;
__act->x4191 = x157;
}

activation_x4191 *initAct(resourceInfo_t *resourceInfo) {
activation_x4191 * act = new activation_x4191;
return act;
}

activation_x4191 *allocVal;
MultiLoopSync<activation_x4191*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4191_class *closure = (x4191_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4191_class *x4191_closure = new x4191_class(x14);
x4191_closure->loopStart = 0;
x4191_closure->loopSize = x14;
activation_x4191 * alloc = x4191_closure->alloc(resourceInfo);
activation_x4191 * x4191 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4191 = x4191_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4191*> * sync = new MultiLoopSync<activation_x4191*>(x4191_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4191_closure->allocVal = alloc;
x4191_closure->syncVal = sync;
submitWork(r->threadId, x4191_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4191_closure)));
i = i+1;
}
x4191 = x4191_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4191;
}

/**********/

