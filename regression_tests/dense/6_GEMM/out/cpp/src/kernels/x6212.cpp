//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6212 * kernel_x6212(resourceInfo_t *resourceInfo,int32_t  x6208, cppDeliteArrayint32_t  *x6207) {
class x6212_class{
public:
int32_t x6208;
cppDeliteArrayint32_t *x6207;

x6212_class(int32_t  _x6208,cppDeliteArrayint32_t * _x6207) {
x6208 = _x6208;
x6207 = _x6207;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6208;
}

int64_t loopStart;
int64_t loopSize;
activation_x6212 *alloc(resourceInfo_t *resourceInfo) {
activation_x6212 * __act = new activation_x6212();;
int32_t x935 = (int32_t)(loopSize);
assert(x935 < (size_t)-1);
cppDeliteArrayint32_t *x6036 = new (resourceInfo) cppDeliteArrayint32_t(x935);
__act->x6212_data = x6036;
return __act;
}

activation_x6212 *main_par(resourceInfo_t *resourceInfo,activation_x6212 *__act,MultiLoopSync<activation_x6212*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6212 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6212 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x6212 *main_seq(resourceInfo_t *resourceInfo,activation_x6212 *__act) {
activation_x6212 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6212 *processRange(resourceInfo_t *resourceInfo,activation_x6212 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6212 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6212 *init(resourceInfo_t *resourceInfo,activation_x6212 *__act,int32_t x931,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x931);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x6212 *__act,int32_t x931) {
int32_t x6209 = x6207->apply(x931);
int32_t x934 = x6209;
cppDeliteArrayint32_t *x933 = __act->x6212_data;
x933->update(x931, x934);
}

void combine(resourceInfo_t *resourceInfo,activation_x6212 *__act,activation_x6212 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6212 *__act,activation_x6212 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6212 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6212 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6212 *__act) {
cppDeliteArrayint32_t * x933 = __act->x6212_data;
__act->x6212 = x933;
}

activation_x6212 *initAct(resourceInfo_t *resourceInfo) {
activation_x6212 * act = new activation_x6212;
return act;
}

activation_x6212 *allocVal;
MultiLoopSync<activation_x6212*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6212_class *closure = (x6212_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6212_class *x6212_closure = new x6212_class(x6208,x6207);
x6212_closure->loopStart = 0;
x6212_closure->loopSize = x6208;
activation_x6212 * alloc = x6212_closure->alloc(resourceInfo);
activation_x6212 * x6212 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6212 = x6212_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6212*> * sync = new MultiLoopSync<activation_x6212*>(x6212_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6212_closure->allocVal = alloc;
x6212_closure->syncVal = sync;
submitWork(r->threadId, x6212_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6212_closure)));
i = i+1;
}
x6212 = x6212_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6212;
}

/**********/

