//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x826 * kernel_x826(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x50, cppDeliteArrayint32_t  *x761) {
class x826_class{
public:
int32_t x3;
int32_t x50;
cppDeliteArrayint32_t *x761;

x826_class(int32_t  _x3,int32_t  _x50,cppDeliteArrayint32_t * _x761) {
x3 = _x3;
x50 = _x50;
x761 = _x761;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x826 *alloc(resourceInfo_t *resourceInfo) {
activation_x826 * __act = new activation_x826();;
__act->x826_zero = x50;
return __act;
}

activation_x826 *main_par(resourceInfo_t *resourceInfo,activation_x826 *__act,MultiLoopSync<activation_x826*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x826 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x826 * act = sync->get(localStart);
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

activation_x826 *main_seq(resourceInfo_t *resourceInfo,activation_x826 *__act) {
activation_x826 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x826 *processRange(resourceInfo_t *resourceInfo,activation_x826 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x826 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x826 *init(resourceInfo_t *resourceInfo,activation_x826 *__act,int32_t x130,bool isEmpty) {
activation_x826 * __act2 = new activation_x826();;
__act2->x826_zero = __act->x826_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x826 = __act2->x826_zero;
if (!isEmpty) {
int32_t x823 = x761->apply(x130);
__act2->x826 = x823;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x826 *__act,int32_t x130) {
int32_t x823 = x761->apply(x130);
int32_t x134 = __act->x826;
int32_t x135 = x823;
int32_t  x136 = x134 + x135;
__act->x826 = x136;
}

void combine(resourceInfo_t *resourceInfo,activation_x826 *__act,activation_x826 *rhs) {
int32_t x134 = __act->x826;
int32_t x135 = rhs->x826;
if (x134 == __act->x826_zero) {
__act->x826 = x135;
}
else if (x135 != __act->x826_zero) {
int32_t  x136 = x134 + x135;
__act->x826 = x136;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x826 *__act,activation_x826 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x826 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x826 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x826 *__act) {
}

activation_x826 *initAct(resourceInfo_t *resourceInfo) {
activation_x826 * act = new activation_x826;
act->x826_zero = x50;
return act;
}

activation_x826 *allocVal;
MultiLoopSync<activation_x826*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x826_class *closure = (x826_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x826_class *x826_closure = new x826_class(x3,x50,x761);
x826_closure->loopStart = 0;
x826_closure->loopSize = x3;
activation_x826 * alloc = x826_closure->alloc(resourceInfo);
activation_x826 * x826 = NULL;
if (resourceInfo->availableThreads <= 1) {
x826 = x826_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x826*> * sync = new MultiLoopSync<activation_x826*>(x826_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x826_closure->allocVal = alloc;
x826_closure->syncVal = sync;
submitWork(r->threadId, x826_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x826_closure)));
i = i+1;
}
x826 = x826_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x826;
}

/**********/

