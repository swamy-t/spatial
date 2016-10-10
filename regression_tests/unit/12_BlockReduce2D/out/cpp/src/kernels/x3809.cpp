//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3809 * kernel_x3809(resourceInfo_t *resourceInfo,int32_t  x3804, bool  x865, cppDeliteArraybool  *x3803) {
class x3809_class{
public:
int32_t x3804;
bool x865;
cppDeliteArraybool *x3803;

x3809_class(int32_t  _x3804,bool  _x865,cppDeliteArraybool * _x3803) {
x3804 = _x3804;
x865 = _x865;
x3803 = _x3803;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3804;
}

int64_t loopStart;
int64_t loopSize;
activation_x3809 *alloc(resourceInfo_t *resourceInfo) {
activation_x3809 * __act = new activation_x3809();;
__act->x3809_zero = x865;
return __act;
}

activation_x3809 *main_par(resourceInfo_t *resourceInfo,activation_x3809 *__act,MultiLoopSync<activation_x3809*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3809 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3809 * act = sync->get(localStart);
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

activation_x3809 *main_seq(resourceInfo_t *resourceInfo,activation_x3809 *__act) {
activation_x3809 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3809 *processRange(resourceInfo_t *resourceInfo,activation_x3809 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3809 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3809 *init(resourceInfo_t *resourceInfo,activation_x3809 *__act,int32_t x867,bool isEmpty) {
activation_x3809 * __act2 = new activation_x3809();;
__act2->x3809_zero = __act->x3809_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x3809 = __act2->x3809_zero;
if (!isEmpty) {
bool x3805 = x3803->apply(x867);
__act2->x3809 = x3805;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x3809 *__act,int32_t x867) {
bool x3805 = x3803->apply(x867);
bool x872 = __act->x3809;
bool x873 = x3805;
bool  x874 = x872 && x873;
__act->x3809 = x874;
}

void combine(resourceInfo_t *resourceInfo,activation_x3809 *__act,activation_x3809 *rhs) {
bool x872 = __act->x3809;
bool x873 = rhs->x3809;
if (x872 == __act->x3809_zero) {
__act->x3809 = x873;
}
else if (x873 != __act->x3809_zero) {
bool  x874 = x872 && x873;
__act->x3809 = x874;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3809 *__act,activation_x3809 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3809 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3809 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3809 *__act) {
}

activation_x3809 *initAct(resourceInfo_t *resourceInfo) {
activation_x3809 * act = new activation_x3809;
act->x3809_zero = x865;
return act;
}

activation_x3809 *allocVal;
MultiLoopSync<activation_x3809*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3809_class *closure = (x3809_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3809_class *x3809_closure = new x3809_class(x3804,x865,x3803);
x3809_closure->loopStart = 0;
x3809_closure->loopSize = x3804;
activation_x3809 * alloc = x3809_closure->alloc(resourceInfo);
activation_x3809 * x3809 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3809 = x3809_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3809*> * sync = new MultiLoopSync<activation_x3809*>(x3809_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3809_closure->allocVal = alloc;
x3809_closure->syncVal = sync;
submitWork(r->threadId, x3809_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3809_closure)));
i = i+1;
}
x3809 = x3809_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3809;
}

/**********/

