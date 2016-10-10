//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1754 * kernel_x1754(resourceInfo_t *resourceInfo,int32_t  x1569, cppDeliteArrayint32_t  *x1528, cppDeliteArrayint32_t  *x1567) {
class x1754_class{
public:
int32_t x1569;
cppDeliteArrayint32_t *x1528;
cppDeliteArrayint32_t *x1567;

x1754_class(int32_t  _x1569,cppDeliteArrayint32_t * _x1528,cppDeliteArrayint32_t * _x1567) {
x1569 = _x1569;
x1528 = _x1528;
x1567 = _x1567;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1569;
}

int64_t loopStart;
int64_t loopSize;
activation_x1754 *alloc(resourceInfo_t *resourceInfo) {
activation_x1754 * __act = new activation_x1754();;
int32_t x225 = (int32_t)(loopSize);
assert(x225 < (size_t)-1);
cppDeliteArrayint32_t *x1718 = new (resourceInfo) cppDeliteArrayint32_t(x225);
__act->x1754_data = x1718;
return __act;
}

activation_x1754 *main_par(resourceInfo_t *resourceInfo,activation_x1754 *__act,MultiLoopSync<activation_x1754*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1754 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1754 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1754 *main_seq(resourceInfo_t *resourceInfo,activation_x1754 *__act) {
activation_x1754 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1754 *processRange(resourceInfo_t *resourceInfo,activation_x1754 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1754 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1754 *init(resourceInfo_t *resourceInfo,activation_x1754 *__act,int32_t x219,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x219);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1754 *__act,int32_t x219) {
int32_t x1715 = x1528->apply(x219);
int32_t x1716 = x1567->apply(x219);
int32_t  x1717 = x1715 * x1716;
int32_t x224 = x1717;
cppDeliteArrayint32_t *x223 = __act->x1754_data;
x223->update(x219, x224);
}

void combine(resourceInfo_t *resourceInfo,activation_x1754 *__act,activation_x1754 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1754 *__act,activation_x1754 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1754 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1754 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1754 *__act) {
cppDeliteArrayint32_t * x223 = __act->x1754_data;
__act->x1754 = x223;
}

activation_x1754 *initAct(resourceInfo_t *resourceInfo) {
activation_x1754 * act = new activation_x1754;
return act;
}

activation_x1754 *allocVal;
MultiLoopSync<activation_x1754*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1754_class *closure = (x1754_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1754_class *x1754_closure = new x1754_class(x1569,x1528,x1567);
x1754_closure->loopStart = 0;
x1754_closure->loopSize = x1569;
activation_x1754 * alloc = x1754_closure->alloc(resourceInfo);
activation_x1754 * x1754 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1754 = x1754_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1754*> * sync = new MultiLoopSync<activation_x1754*>(x1754_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1754_closure->allocVal = alloc;
x1754_closure->syncVal = sync;
submitWork(r->threadId, x1754_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1754_closure)));
i = i+1;
}
x1754 = x1754_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1754;
}

/**********/

