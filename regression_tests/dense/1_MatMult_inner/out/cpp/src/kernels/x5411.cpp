//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5411 * kernel_x5411(resourceInfo_t *resourceInfo,int32_t  x5279, cppDeliteArrayint32_t  *x5035) {
class x5411_class{
public:
int32_t x5279;
cppDeliteArrayint32_t *x5035;

x5411_class(int32_t  _x5279,cppDeliteArrayint32_t * _x5035) {
x5279 = _x5279;
x5035 = _x5035;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x5279;
}

int64_t loopStart;
int64_t loopSize;
activation_x5411 *alloc(resourceInfo_t *resourceInfo) {
activation_x5411 * __act = new activation_x5411();;
int32_t x775 = (int32_t)(loopSize);
assert(x775 < (size_t)-1);
cppDeliteArrayint32_t *x5282 = new (resourceInfo) cppDeliteArrayint32_t(x775);
__act->x5411_data = x5282;
return __act;
}

activation_x5411 *main_par(resourceInfo_t *resourceInfo,activation_x5411 *__act,MultiLoopSync<activation_x5411*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5411 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5411 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x5411 *main_seq(resourceInfo_t *resourceInfo,activation_x5411 *__act) {
activation_x5411 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x5411 *processRange(resourceInfo_t *resourceInfo,activation_x5411 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5411 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5411 *init(resourceInfo_t *resourceInfo,activation_x5411 *__act,int32_t x770,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x770);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x5411 *__act,int32_t x770) {
int32_t x5280 = x5035->apply(x770);
int32_t x774 = x5280;
cppDeliteArrayint32_t *x773 = __act->x5411_data;
x773->update(x770, x774);
}

void combine(resourceInfo_t *resourceInfo,activation_x5411 *__act,activation_x5411 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5411 *__act,activation_x5411 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5411 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5411 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x5411 *__act) {
cppDeliteArrayint32_t * x773 = __act->x5411_data;
__act->x5411 = x773;
}

activation_x5411 *initAct(resourceInfo_t *resourceInfo) {
activation_x5411 * act = new activation_x5411;
return act;
}

activation_x5411 *allocVal;
MultiLoopSync<activation_x5411*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5411_class *closure = (x5411_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5411_class *x5411_closure = new x5411_class(x5279,x5035);
x5411_closure->loopStart = 0;
x5411_closure->loopSize = x5279;
activation_x5411 * alloc = x5411_closure->alloc(resourceInfo);
activation_x5411 * x5411 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5411 = x5411_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5411*> * sync = new MultiLoopSync<activation_x5411*>(x5411_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5411_closure->allocVal = alloc;
x5411_closure->syncVal = sync;
submitWork(r->threadId, x5411_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5411_closure)));
i = i+1;
}
x5411 = x5411_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5411;
}

/**********/

