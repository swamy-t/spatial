//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5406 * kernel_x5406(resourceInfo_t *resourceInfo,int32_t  x5400, int32_t  x285, cppDeliteArrayint32_t  *x5404) {
class x5406_class{
public:
int32_t x5400;
int32_t x285;
cppDeliteArrayint32_t *x5404;

x5406_class(int32_t  _x5400,int32_t  _x285,cppDeliteArrayint32_t * _x5404) {
x5400 = _x5400;
x285 = _x285;
x5404 = _x5404;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x5400;
}

int64_t loopStart;
int64_t loopSize;
activation_x5406 *alloc(resourceInfo_t *resourceInfo) {
activation_x5406 * __act = new activation_x5406();;
__act->x5406_zero = x285;
return __act;
}

activation_x5406 *main_par(resourceInfo_t *resourceInfo,activation_x5406 *__act,MultiLoopSync<activation_x5406*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5406 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5406 * act = sync->get(localStart);
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

activation_x5406 *main_seq(resourceInfo_t *resourceInfo,activation_x5406 *__act) {
activation_x5406 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x5406 *processRange(resourceInfo_t *resourceInfo,activation_x5406 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5406 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5406 *init(resourceInfo_t *resourceInfo,activation_x5406 *__act,int32_t x759,bool isEmpty) {
activation_x5406 * __act2 = new activation_x5406();;
__act2->x5406_zero = __act->x5406_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x5406 = __act2->x5406_zero;
if (!isEmpty) {
int32_t x5405 = x5404->apply(x759);
__act2->x5406 = x5405;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x5406 *__act,int32_t x759) {
int32_t x5405 = x5404->apply(x759);
int32_t x763 = __act->x5406;
int32_t x764 = x5405;
int32_t  x765 = x763 + x764;
__act->x5406 = x765;
}

void combine(resourceInfo_t *resourceInfo,activation_x5406 *__act,activation_x5406 *rhs) {
int32_t x763 = __act->x5406;
int32_t x764 = rhs->x5406;
if (x763 == __act->x5406_zero) {
__act->x5406 = x764;
}
else if (x764 != __act->x5406_zero) {
int32_t  x765 = x763 + x764;
__act->x5406 = x765;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5406 *__act,activation_x5406 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5406 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5406 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x5406 *__act) {
}

activation_x5406 *initAct(resourceInfo_t *resourceInfo) {
activation_x5406 * act = new activation_x5406;
act->x5406_zero = x285;
return act;
}

activation_x5406 *allocVal;
MultiLoopSync<activation_x5406*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5406_class *closure = (x5406_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5406_class *x5406_closure = new x5406_class(x5400,x285,x5404);
x5406_closure->loopStart = 0;
x5406_closure->loopSize = x5400;
activation_x5406 * alloc = x5406_closure->alloc(resourceInfo);
activation_x5406 * x5406 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5406 = x5406_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5406*> * sync = new MultiLoopSync<activation_x5406*>(x5406_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5406_closure->allocVal = alloc;
x5406_closure->syncVal = sync;
submitWork(r->threadId, x5406_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5406_closure)));
i = i+1;
}
x5406 = x5406_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5406;
}

/**********/

