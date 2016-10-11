//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3032 * kernel_x3032(resourceInfo_t *resourceInfo,int32_t  x3027, int32_t  x99, cppDeliteArrayint32_t  *x3026) {
class x3032_class{
public:
int32_t x3027;
int32_t x99;
cppDeliteArrayint32_t *x3026;

x3032_class(int32_t  _x3027,int32_t  _x99,cppDeliteArrayint32_t * _x3026) {
x3027 = _x3027;
x99 = _x99;
x3026 = _x3026;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3027;
}

int64_t loopStart;
int64_t loopSize;
activation_x3032 *alloc(resourceInfo_t *resourceInfo) {
activation_x3032 * __act = new activation_x3032();;
__act->x3032_zero = x99;
return __act;
}

activation_x3032 *main_par(resourceInfo_t *resourceInfo,activation_x3032 *__act,MultiLoopSync<activation_x3032*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3032 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3032 * act = sync->get(localStart);
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

activation_x3032 *main_seq(resourceInfo_t *resourceInfo,activation_x3032 *__act) {
activation_x3032 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3032 *processRange(resourceInfo_t *resourceInfo,activation_x3032 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3032 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3032 *init(resourceInfo_t *resourceInfo,activation_x3032 *__act,int32_t x459,bool isEmpty) {
activation_x3032 * __act2 = new activation_x3032();;
__act2->x3032_zero = __act->x3032_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x3032 = __act2->x3032_zero;
if (!isEmpty) {
int32_t x3028 = x3026->apply(x459);
__act2->x3032 = x3028;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x3032 *__act,int32_t x459) {
int32_t x3028 = x3026->apply(x459);
int32_t x464 = __act->x3032;
int32_t x465 = x3028;
int32_t  x466 = x464 + x465;
__act->x3032 = x466;
}

void combine(resourceInfo_t *resourceInfo,activation_x3032 *__act,activation_x3032 *rhs) {
int32_t x464 = __act->x3032;
int32_t x465 = rhs->x3032;
if (x464 == __act->x3032_zero) {
__act->x3032 = x465;
}
else if (x465 != __act->x3032_zero) {
int32_t  x466 = x464 + x465;
__act->x3032 = x466;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3032 *__act,activation_x3032 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3032 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3032 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3032 *__act) {
}

activation_x3032 *initAct(resourceInfo_t *resourceInfo) {
activation_x3032 * act = new activation_x3032;
act->x3032_zero = x99;
return act;
}

activation_x3032 *allocVal;
MultiLoopSync<activation_x3032*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3032_class *closure = (x3032_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3032_class *x3032_closure = new x3032_class(x3027,x99,x3026);
x3032_closure->loopStart = 0;
x3032_closure->loopSize = x3027;
activation_x3032 * alloc = x3032_closure->alloc(resourceInfo);
activation_x3032 * x3032 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3032 = x3032_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3032*> * sync = new MultiLoopSync<activation_x3032*>(x3032_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3032_closure->allocVal = alloc;
x3032_closure->syncVal = sync;
submitWork(r->threadId, x3032_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3032_closure)));
i = i+1;
}
x3032 = x3032_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3032;
}

/**********/

