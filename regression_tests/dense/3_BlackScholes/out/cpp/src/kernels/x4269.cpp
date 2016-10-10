//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x4269 * kernel_x4269(resourceInfo_t *resourceInfo,int32_t  x14) {
// a *thin* loop follows: x4269
class x4269_class{
public:
int32_t x14;

x4269_class(int32_t  _x14) {
x14 = _x14;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x14;
}

int64_t loopStart;
int64_t loopSize;
activation_x4269 *alloc(resourceInfo_t *resourceInfo) {
activation_x4269 * __act = new activation_x4269();;
int32_t x251 = (int32_t)(loopSize);
assert(x251 < (size_t)-1);
cppDeliteArrayfloat *x4233 = new (resourceInfo) cppDeliteArrayfloat(x251);
__act->x4269_data = x4233;
return __act;
}

activation_x4269 *main_par(resourceInfo_t *resourceInfo,activation_x4269 *__act,MultiLoopSync<activation_x4269*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4269 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4269 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4269 *main_seq(resourceInfo_t *resourceInfo,activation_x4269 *__act) {
activation_x4269 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4269 *processRange(resourceInfo_t *resourceInfo,activation_x4269 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4269 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4269 *init(resourceInfo_t *resourceInfo,activation_x4269 *__act,int32_t x246,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x246);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4269 *__act,int32_t x246) {
float  x4231 = (float) rand() / (float) RAND_MAX;
float x250 = x4231;
cppDeliteArrayfloat *x249 = __act->x4269_data;
x249->update(x246, x250);
}

void combine(resourceInfo_t *resourceInfo,activation_x4269 *__act,activation_x4269 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4269 *__act,activation_x4269 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4269 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4269 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4269 *__act) {
cppDeliteArrayfloat * x249 = __act->x4269_data;
__act->x4269 = x249;
}

activation_x4269 *initAct(resourceInfo_t *resourceInfo) {
activation_x4269 * act = new activation_x4269;
return act;
}

activation_x4269 *allocVal;
MultiLoopSync<activation_x4269*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4269_class *closure = (x4269_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4269_class *x4269_closure = new x4269_class(x14);
x4269_closure->loopStart = 0;
x4269_closure->loopSize = x14;
activation_x4269 * alloc = x4269_closure->alloc(resourceInfo);
activation_x4269 * x4269 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4269 = x4269_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4269*> * sync = new MultiLoopSync<activation_x4269*>(x4269_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4269_closure->allocVal = alloc;
x4269_closure->syncVal = sync;
submitWork(r->threadId, x4269_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4269_closure)));
i = i+1;
}
x4269 = x4269_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4269;
}

/**********/

