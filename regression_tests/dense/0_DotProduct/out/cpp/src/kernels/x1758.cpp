//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1758 * kernel_x1758(resourceInfo_t *resourceInfo,int32_t  x1569, int32_t  x98, cppDeliteArrayint32_t  *x1754) {
class x1758_class{
public:
int32_t x1569;
int32_t x98;
cppDeliteArrayint32_t *x1754;

x1758_class(int32_t  _x1569,int32_t  _x98,cppDeliteArrayint32_t * _x1754) {
x1569 = _x1569;
x98 = _x98;
x1754 = _x1754;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1569;
}

int64_t loopStart;
int64_t loopSize;
activation_x1758 *alloc(resourceInfo_t *resourceInfo) {
activation_x1758 * __act = new activation_x1758();;
__act->x1758_zero = x98;
return __act;
}

activation_x1758 *main_par(resourceInfo_t *resourceInfo,activation_x1758 *__act,MultiLoopSync<activation_x1758*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1758 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1758 * act = sync->get(localStart);
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

activation_x1758 *main_seq(resourceInfo_t *resourceInfo,activation_x1758 *__act) {
activation_x1758 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1758 *processRange(resourceInfo_t *resourceInfo,activation_x1758 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1758 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1758 *init(resourceInfo_t *resourceInfo,activation_x1758 *__act,int32_t x266,bool isEmpty) {
activation_x1758 * __act2 = new activation_x1758();;
__act2->x1758_zero = __act->x1758_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1758 = __act2->x1758_zero;
if (!isEmpty) {
int32_t x1755 = x1754->apply(x266);
__act2->x1758 = x1755;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x1758 *__act,int32_t x266) {
int32_t x1755 = x1754->apply(x266);
int32_t x270 = __act->x1758;
int32_t x271 = x1755;
int32_t  x272 = x270 + x271;
__act->x1758 = x272;
}

void combine(resourceInfo_t *resourceInfo,activation_x1758 *__act,activation_x1758 *rhs) {
int32_t x270 = __act->x1758;
int32_t x271 = rhs->x1758;
if (x270 == __act->x1758_zero) {
__act->x1758 = x271;
}
else if (x271 != __act->x1758_zero) {
int32_t  x272 = x270 + x271;
__act->x1758 = x272;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1758 *__act,activation_x1758 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1758 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1758 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1758 *__act) {
}

activation_x1758 *initAct(resourceInfo_t *resourceInfo) {
activation_x1758 * act = new activation_x1758;
act->x1758_zero = x98;
return act;
}

activation_x1758 *allocVal;
MultiLoopSync<activation_x1758*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1758_class *closure = (x1758_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1758_class *x1758_closure = new x1758_class(x1569,x98,x1754);
x1758_closure->loopStart = 0;
x1758_closure->loopSize = x1569;
activation_x1758 * alloc = x1758_closure->alloc(resourceInfo);
activation_x1758 * x1758 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1758 = x1758_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1758*> * sync = new MultiLoopSync<activation_x1758*>(x1758_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1758_closure->allocVal = alloc;
x1758_closure->syncVal = sync;
submitWork(r->threadId, x1758_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1758_closure)));
i = i+1;
}
x1758 = x1758_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1758;
}

/**********/

