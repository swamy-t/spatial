//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x638 * kernel_x638(resourceInfo_t *resourceInfo,int32_t  x4) {
class x638_class{
public:
int32_t x4;

x638_class(int32_t  _x4) {
x4 = _x4;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x4;
}

int64_t loopStart;
int64_t loopSize;
activation_x638 *alloc(resourceInfo_t *resourceInfo) {
activation_x638 * __act = new activation_x638();;
int32_t x9 = (int32_t)(loopSize);
assert(x9 < (size_t)-1);
cppDeliteArrayint32_t *x602 = new (resourceInfo) cppDeliteArrayint32_t(x9);
__act->x638_data = x602;
return __act;
}

activation_x638 *main_par(resourceInfo_t *resourceInfo,activation_x638 *__act,MultiLoopSync<activation_x638*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x638 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x638 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x638 *main_seq(resourceInfo_t *resourceInfo,activation_x638 *__act) {
activation_x638 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x638 *processRange(resourceInfo_t *resourceInfo,activation_x638 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x638 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x638 *init(resourceInfo_t *resourceInfo,activation_x638 *__act,int32_t x5,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x5);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x638 *__act,int32_t x5) {
int32_t  x6 = (int32_t) (x5);
int32_t x8 = x6;
cppDeliteArrayint32_t *x7 = __act->x638_data;
x7->update(x5, x8);
}

void combine(resourceInfo_t *resourceInfo,activation_x638 *__act,activation_x638 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x638 *__act,activation_x638 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x638 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x638 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x638 *__act) {
cppDeliteArrayint32_t * x7 = __act->x638_data;
__act->x638 = x7;
}

activation_x638 *initAct(resourceInfo_t *resourceInfo) {
activation_x638 * act = new activation_x638;
return act;
}

activation_x638 *allocVal;
MultiLoopSync<activation_x638*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x638_class *closure = (x638_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x638_class *x638_closure = new x638_class(x4);
x638_closure->loopStart = 0;
x638_closure->loopSize = x4;
activation_x638 * alloc = x638_closure->alloc(resourceInfo);
activation_x638 * x638 = NULL;
if (resourceInfo->availableThreads <= 1) {
x638 = x638_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x638*> * sync = new MultiLoopSync<activation_x638*>(x638_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x638_closure->allocVal = alloc;
x638_closure->syncVal = sync;
submitWork(r->threadId, x638_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x638_closure)));
i = i+1;
}
x638 = x638_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x638;
}

/**********/

