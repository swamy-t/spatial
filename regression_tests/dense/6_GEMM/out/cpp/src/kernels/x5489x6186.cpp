//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5489x6186 * kernel_x5489x6186(resourceInfo_t *resourceInfo,int32_t  x99, int32_t  x11, int32_t  x189) {
class x5489x6186_class{
public:
int32_t x99;
int32_t x11;
int32_t x189;

x5489x6186_class(int32_t  _x99,int32_t  _x11,int32_t  _x189) {
x99 = _x99;
x11 = _x11;
x189 = _x189;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x99;
}

int64_t loopStart;
int64_t loopSize;
activation_x5489x6186 *alloc(resourceInfo_t *resourceInfo) {
activation_x5489x6186 * __act = new activation_x5489x6186();;
int32_t x103 = (int32_t)(loopSize);
assert(x103 < (size_t)-1);
cppDeliteArrayint32_t *x5453 = new (resourceInfo) cppDeliteArrayint32_t(x103);
__act->x5489_data = x5453;
int32_t x192 = (int32_t)(loopSize);
assert(x192 < (size_t)-1);
cppDeliteArrayint32_t *x5566 = new (resourceInfo) cppDeliteArrayint32_t(x192);
__act->x6186_data = x5566;
return __act;
}

activation_x5489x6186 *main_par(resourceInfo_t *resourceInfo,activation_x5489x6186 *__act,MultiLoopSync<activation_x5489x6186*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5489x6186 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5489x6186 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x5489x6186 *main_seq(resourceInfo_t *resourceInfo,activation_x5489x6186 *__act) {
activation_x5489x6186 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x5489x6186 *processRange(resourceInfo_t *resourceInfo,activation_x5489x6186 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5489x6186 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5489x6186 *init(resourceInfo_t *resourceInfo,activation_x5489x6186 *__act,int32_t x100,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x100);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x5489x6186 *__act,int32_t x100) {
int32_t x102 = x11;
cppDeliteArrayint32_t *x101 = __act->x5489_data;
x101->update(x100, x102);
int32_t x191 = x189;
cppDeliteArrayint32_t *x190 = __act->x6186_data;
x190->update(x100, x191);
}

void combine(resourceInfo_t *resourceInfo,activation_x5489x6186 *__act,activation_x5489x6186 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5489x6186 *__act,activation_x5489x6186 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5489x6186 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5489x6186 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x5489x6186 *__act) {
cppDeliteArrayint32_t * x101 = __act->x5489_data;
__act->x5489 = x101;
cppDeliteArrayint32_t * x190 = __act->x6186_data;
__act->x6186 = x190;
}

activation_x5489x6186 *initAct(resourceInfo_t *resourceInfo) {
activation_x5489x6186 * act = new activation_x5489x6186;
return act;
}

activation_x5489x6186 *allocVal;
MultiLoopSync<activation_x5489x6186*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5489x6186_class *closure = (x5489x6186_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5489x6186_class *x5489x6186_closure = new x5489x6186_class(x99,x11,x189);
x5489x6186_closure->loopStart = 0;
x5489x6186_closure->loopSize = x99;
activation_x5489x6186 * alloc = x5489x6186_closure->alloc(resourceInfo);
activation_x5489x6186 * x5489x6186 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5489x6186 = x5489x6186_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5489x6186*> * sync = new MultiLoopSync<activation_x5489x6186*>(x5489x6186_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5489x6186_closure->allocVal = alloc;
x5489x6186_closure->syncVal = sync;
submitWork(r->threadId, x5489x6186_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5489x6186_closure)));
i = i+1;
}
x5489x6186 = x5489x6186_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5489x6186;
}

/**********/

