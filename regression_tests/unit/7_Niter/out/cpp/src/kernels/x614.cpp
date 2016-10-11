//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x614 * kernel_x614(resourceInfo_t *resourceInfo,int32_t  x46, int32_t  x4, cppDeliteArrayint32_t  *x610) {
class x614_class{
public:
int32_t x46;
int32_t x4;
cppDeliteArrayint32_t *x610;

x614_class(int32_t  _x46,int32_t  _x4,cppDeliteArrayint32_t * _x610) {
x46 = _x46;
x4 = _x4;
x610 = _x610;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x46;
}

int64_t loopStart;
int64_t loopSize;
activation_x614 *alloc(resourceInfo_t *resourceInfo) {
activation_x614 * __act = new activation_x614();;
__act->x614_zero = x4;
return __act;
}

activation_x614 *main_par(resourceInfo_t *resourceInfo,activation_x614 *__act,MultiLoopSync<activation_x614*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x614 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x614 * act = sync->get(localStart);
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

activation_x614 *main_seq(resourceInfo_t *resourceInfo,activation_x614 *__act) {
activation_x614 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x614 *processRange(resourceInfo_t *resourceInfo,activation_x614 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x614 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x614 *init(resourceInfo_t *resourceInfo,activation_x614 *__act,int32_t x92,bool isEmpty) {
activation_x614 * __act2 = new activation_x614();;
__act2->x614_zero = __act->x614_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x614 = __act2->x614_zero;
if (!isEmpty) {
int32_t x611 = x610->apply(x92);
__act2->x614 = x611;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x614 *__act,int32_t x92) {
int32_t x611 = x610->apply(x92);
int32_t x96 = __act->x614;
int32_t x97 = x611;
int32_t  x98 = x96 + x97;
__act->x614 = x98;
}

void combine(resourceInfo_t *resourceInfo,activation_x614 *__act,activation_x614 *rhs) {
int32_t x96 = __act->x614;
int32_t x97 = rhs->x614;
if (x96 == __act->x614_zero) {
__act->x614 = x97;
}
else if (x97 != __act->x614_zero) {
int32_t  x98 = x96 + x97;
__act->x614 = x98;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x614 *__act,activation_x614 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x614 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x614 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x614 *__act) {
}

activation_x614 *initAct(resourceInfo_t *resourceInfo) {
activation_x614 * act = new activation_x614;
act->x614_zero = x4;
return act;
}

activation_x614 *allocVal;
MultiLoopSync<activation_x614*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x614_class *closure = (x614_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x614_class *x614_closure = new x614_class(x46,x4,x610);
x614_closure->loopStart = 0;
x614_closure->loopSize = x46;
activation_x614 * alloc = x614_closure->alloc(resourceInfo);
activation_x614 * x614 = NULL;
if (resourceInfo->availableThreads <= 1) {
x614 = x614_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x614*> * sync = new MultiLoopSync<activation_x614*>(x614_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x614_closure->allocVal = alloc;
x614_closure->syncVal = sync;
submitWork(r->threadId, x614_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x614_closure)));
i = i+1;
}
x614 = x614_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x614;
}

/**********/

