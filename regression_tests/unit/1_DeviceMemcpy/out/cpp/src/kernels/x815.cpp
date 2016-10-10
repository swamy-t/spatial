//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x815 * kernel_x815(resourceInfo_t *resourceInfo,int32_t  x810, bool  x132, cppDeliteArraybool  *x809) {
class x815_class{
public:
int32_t x810;
bool x132;
cppDeliteArraybool *x809;

x815_class(int32_t  _x810,bool  _x132,cppDeliteArraybool * _x809) {
x810 = _x810;
x132 = _x132;
x809 = _x809;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x810;
}

int64_t loopStart;
int64_t loopSize;
activation_x815 *alloc(resourceInfo_t *resourceInfo) {
activation_x815 * __act = new activation_x815();;
__act->x815_zero = x132;
return __act;
}

activation_x815 *main_par(resourceInfo_t *resourceInfo,activation_x815 *__act,MultiLoopSync<activation_x815*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x815 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x815 * act = sync->get(localStart);
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

activation_x815 *main_seq(resourceInfo_t *resourceInfo,activation_x815 *__act) {
activation_x815 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x815 *processRange(resourceInfo_t *resourceInfo,activation_x815 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x815 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x815 *init(resourceInfo_t *resourceInfo,activation_x815 *__act,int32_t x134,bool isEmpty) {
activation_x815 * __act2 = new activation_x815();;
__act2->x815_zero = __act->x815_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x815 = __act2->x815_zero;
if (!isEmpty) {
bool x811 = x809->apply(x134);
__act2->x815 = x811;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x815 *__act,int32_t x134) {
bool x811 = x809->apply(x134);
bool x139 = __act->x815;
bool x140 = x811;
bool  x141 = x139 && x140;
__act->x815 = x141;
}

void combine(resourceInfo_t *resourceInfo,activation_x815 *__act,activation_x815 *rhs) {
bool x139 = __act->x815;
bool x140 = rhs->x815;
if (x139 == __act->x815_zero) {
__act->x815 = x140;
}
else if (x140 != __act->x815_zero) {
bool  x141 = x139 && x140;
__act->x815 = x141;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x815 *__act,activation_x815 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x815 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x815 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x815 *__act) {
}

activation_x815 *initAct(resourceInfo_t *resourceInfo) {
activation_x815 * act = new activation_x815;
act->x815_zero = x132;
return act;
}

activation_x815 *allocVal;
MultiLoopSync<activation_x815*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x815_class *closure = (x815_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x815_class *x815_closure = new x815_class(x810,x132,x809);
x815_closure->loopStart = 0;
x815_closure->loopSize = x810;
activation_x815 * alloc = x815_closure->alloc(resourceInfo);
activation_x815 * x815 = NULL;
if (resourceInfo->availableThreads <= 1) {
x815 = x815_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x815*> * sync = new MultiLoopSync<activation_x815*>(x815_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x815_closure->allocVal = alloc;
x815_closure->syncVal = sync;
submitWork(r->threadId, x815_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x815_closure)));
i = i+1;
}
x815 = x815_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x815;
}

/**********/

