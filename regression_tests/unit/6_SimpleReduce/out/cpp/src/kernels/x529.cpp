//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x529 * kernel_x529(resourceInfo_t *resourceInfo,int32_t  x36, int32_t  x4, cppDeliteArrayint32_t  *x525) {
class x529_class{
public:
int32_t x36;
int32_t x4;
cppDeliteArrayint32_t *x525;

x529_class(int32_t  _x36,int32_t  _x4,cppDeliteArrayint32_t * _x525) {
x36 = _x36;
x4 = _x4;
x525 = _x525;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x36;
}

int64_t loopStart;
int64_t loopSize;
activation_x529 *alloc(resourceInfo_t *resourceInfo) {
activation_x529 * __act = new activation_x529();;
__act->x529_zero = x4;
return __act;
}

activation_x529 *main_par(resourceInfo_t *resourceInfo,activation_x529 *__act,MultiLoopSync<activation_x529*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x529 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x529 * act = sync->get(localStart);
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

activation_x529 *main_seq(resourceInfo_t *resourceInfo,activation_x529 *__act) {
activation_x529 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x529 *processRange(resourceInfo_t *resourceInfo,activation_x529 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x529 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x529 *init(resourceInfo_t *resourceInfo,activation_x529 *__act,int32_t x83,bool isEmpty) {
activation_x529 * __act2 = new activation_x529();;
__act2->x529_zero = __act->x529_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x529 = __act2->x529_zero;
if (!isEmpty) {
int32_t x526 = x525->apply(x83);
__act2->x529 = x526;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x529 *__act,int32_t x83) {
int32_t x526 = x525->apply(x83);
int32_t x87 = __act->x529;
int32_t x88 = x526;
int32_t  x89 = x87 + x88;
__act->x529 = x89;
}

void combine(resourceInfo_t *resourceInfo,activation_x529 *__act,activation_x529 *rhs) {
int32_t x87 = __act->x529;
int32_t x88 = rhs->x529;
if (x87 == __act->x529_zero) {
__act->x529 = x88;
}
else if (x88 != __act->x529_zero) {
int32_t  x89 = x87 + x88;
__act->x529 = x89;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x529 *__act,activation_x529 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x529 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x529 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x529 *__act) {
}

activation_x529 *initAct(resourceInfo_t *resourceInfo) {
activation_x529 * act = new activation_x529;
act->x529_zero = x4;
return act;
}

activation_x529 *allocVal;
MultiLoopSync<activation_x529*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x529_class *closure = (x529_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x529_class *x529_closure = new x529_class(x36,x4,x525);
x529_closure->loopStart = 0;
x529_closure->loopSize = x36;
activation_x529 * alloc = x529_closure->alloc(resourceInfo);
activation_x529 * x529 = NULL;
if (resourceInfo->availableThreads <= 1) {
x529 = x529_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x529*> * sync = new MultiLoopSync<activation_x529*>(x529_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x529_closure->allocVal = alloc;
x529_closure->syncVal = sync;
submitWork(r->threadId, x529_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x529_closure)));
i = i+1;
}
x529 = x529_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x529;
}

/**********/

