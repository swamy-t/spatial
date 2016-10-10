//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6229 * kernel_x6229(resourceInfo_t *resourceInfo,int32_t  x6225, cppDeliteArrayint32_t  *x6224) {
class x6229_class{
public:
int32_t x6225;
cppDeliteArrayint32_t *x6224;

x6229_class(int32_t  _x6225,cppDeliteArrayint32_t * _x6224) {
x6225 = _x6225;
x6224 = _x6224;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6225;
}

int64_t loopStart;
int64_t loopSize;
activation_x6229 *alloc(resourceInfo_t *resourceInfo) {
activation_x6229 * __act = new activation_x6229();;
int32_t x885 = (int32_t)(loopSize);
assert(x885 < (size_t)-1);
cppDeliteArrayint32_t *x6035 = new (resourceInfo) cppDeliteArrayint32_t(x885);
__act->x6229_data = x6035;
return __act;
}

activation_x6229 *main_par(resourceInfo_t *resourceInfo,activation_x6229 *__act,MultiLoopSync<activation_x6229*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6229 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6229 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x6229 *main_seq(resourceInfo_t *resourceInfo,activation_x6229 *__act) {
activation_x6229 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6229 *processRange(resourceInfo_t *resourceInfo,activation_x6229 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6229 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6229 *init(resourceInfo_t *resourceInfo,activation_x6229 *__act,int32_t x881,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x881);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x6229 *__act,int32_t x881) {
int32_t x6226 = x6224->apply(x881);
int32_t x884 = x6226;
cppDeliteArrayint32_t *x883 = __act->x6229_data;
x883->update(x881, x884);
}

void combine(resourceInfo_t *resourceInfo,activation_x6229 *__act,activation_x6229 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6229 *__act,activation_x6229 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6229 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6229 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6229 *__act) {
cppDeliteArrayint32_t * x883 = __act->x6229_data;
__act->x6229 = x883;
}

activation_x6229 *initAct(resourceInfo_t *resourceInfo) {
activation_x6229 * act = new activation_x6229;
return act;
}

activation_x6229 *allocVal;
MultiLoopSync<activation_x6229*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6229_class *closure = (x6229_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6229_class *x6229_closure = new x6229_class(x6225,x6224);
x6229_closure->loopStart = 0;
x6229_closure->loopSize = x6225;
activation_x6229 * alloc = x6229_closure->alloc(resourceInfo);
activation_x6229 * x6229 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6229 = x6229_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6229*> * sync = new MultiLoopSync<activation_x6229*>(x6229_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6229_closure->allocVal = alloc;
x6229_closure->syncVal = sync;
submitWork(r->threadId, x6229_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6229_closure)));
i = i+1;
}
x6229 = x6229_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6229;
}

/**********/

