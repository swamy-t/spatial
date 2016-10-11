//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1861 * kernel_x1861(resourceInfo_t *resourceInfo,int32_t  x1856, int32_t  x53, cppDeliteArrayint32_t  *x1848) {
class x1861_class{
public:
int32_t x1856;
int32_t x53;
cppDeliteArrayint32_t *x1848;

x1861_class(int32_t  _x1856,int32_t  _x53,cppDeliteArrayint32_t * _x1848) {
x1856 = _x1856;
x53 = _x53;
x1848 = _x1848;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1856;
}

int64_t loopStart;
int64_t loopSize;
activation_x1861 *alloc(resourceInfo_t *resourceInfo) {
activation_x1861 * __act = new activation_x1861();;
__act->x1861_zero = x53;
return __act;
}

activation_x1861 *main_par(resourceInfo_t *resourceInfo,activation_x1861 *__act,MultiLoopSync<activation_x1861*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1861 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1861 * act = sync->get(localStart);
//combine local
int32_t  i = localStart+1;
while (i < localEnd) {
combine(resourceInfo,act,sync->get(i));
i = i+1;
}
//combine remote
int32_t  half = tid;
int32_t  step = 1;
while ((half % 2 == 0) && (tid + step < numThreads)) {
combine(resourceInfo,act,sync->getC(tid+step));
half = half / 2;
step = step * 2;
}
sync->setC(tid,act);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1861 *main_seq(resourceInfo_t *resourceInfo,activation_x1861 *__act) {
activation_x1861 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1861 *processRange(resourceInfo_t *resourceInfo,activation_x1861 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1861 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1861 *init(resourceInfo_t *resourceInfo,activation_x1861 *__act,int32_t x234,bool isEmpty) {
activation_x1861 * __act2 = new activation_x1861();;
__act2->x1861_zero = __act->x1861_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1861 = __act2->x1861_zero;
if (!isEmpty) {
int32_t x1857 = x1848->apply(x234);
__act2->x1861 = x1857;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x1861 *__act,int32_t x234) {
int32_t x1857 = x1848->apply(x234);
int32_t x239 = __act->x1861;
int32_t x240 = x1857;
int32_t  x241 = x239 + x240;
__act->x1861 = x241;
}

void combine(resourceInfo_t *resourceInfo,activation_x1861 *__act,activation_x1861 *rhs) {
int32_t x239 = __act->x1861;
int32_t x240 = rhs->x1861;
if (x239 == __act->x1861_zero) {
__act->x1861 = x240;
}
else if (x240 != __act->x1861_zero) {
int32_t  x241 = x239 + x240;
__act->x1861 = x241;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1861 *__act,activation_x1861 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1861 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1861 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1861 *__act) {
}

activation_x1861 *initAct(resourceInfo_t *resourceInfo) {
activation_x1861 * act = new activation_x1861;
act->x1861_zero = x53;
return act;
}

activation_x1861 *allocVal;
MultiLoopSync<activation_x1861*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1861_class *closure = (x1861_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1861_class *x1861_closure = new x1861_class(x1856,x53,x1848);
x1861_closure->loopStart = 0;
x1861_closure->loopSize = x1856;
activation_x1861 * alloc = x1861_closure->alloc(resourceInfo);
activation_x1861 * x1861 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1861 = x1861_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1861*> * sync = new MultiLoopSync<activation_x1861*>(x1861_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1861_closure->allocVal = alloc;
x1861_closure->syncVal = sync;
submitWork(r->threadId, x1861_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1861_closure)));
i = i+1;
}
x1861 = x1861_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1861;
}

/**********/

