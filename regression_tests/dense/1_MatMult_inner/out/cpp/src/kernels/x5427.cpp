//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5427 * kernel_x5427(resourceInfo_t *resourceInfo,int32_t  x5424, bool  x876, cppDeliteArraybool  *x5423) {
class x5427_class{
public:
int32_t x5424;
bool x876;
cppDeliteArraybool *x5423;

x5427_class(int32_t  _x5424,bool  _x876,cppDeliteArraybool * _x5423) {
x5424 = _x5424;
x876 = _x876;
x5423 = _x5423;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x5424;
}

int64_t loopStart;
int64_t loopSize;
activation_x5427 *alloc(resourceInfo_t *resourceInfo) {
activation_x5427 * __act = new activation_x5427();;
__act->x5427_zero = x876;
return __act;
}

activation_x5427 *main_par(resourceInfo_t *resourceInfo,activation_x5427 *__act,MultiLoopSync<activation_x5427*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5427 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5427 * act = sync->get(localStart);
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

activation_x5427 *main_seq(resourceInfo_t *resourceInfo,activation_x5427 *__act) {
activation_x5427 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x5427 *processRange(resourceInfo_t *resourceInfo,activation_x5427 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5427 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5427 *init(resourceInfo_t *resourceInfo,activation_x5427 *__act,int32_t x878,bool isEmpty) {
activation_x5427 * __act2 = new activation_x5427();;
__act2->x5427_zero = __act->x5427_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x5427 = __act2->x5427_zero;
if (!isEmpty) {
bool x5425 = x5423->apply(x878);
__act2->x5427 = x5425;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x5427 *__act,int32_t x878) {
bool x5425 = x5423->apply(x878);
bool x883 = __act->x5427;
bool x884 = x5425;
bool  x885 = x883 && x884;
__act->x5427 = x885;
}

void combine(resourceInfo_t *resourceInfo,activation_x5427 *__act,activation_x5427 *rhs) {
bool x883 = __act->x5427;
bool x884 = rhs->x5427;
if (x883 == __act->x5427_zero) {
__act->x5427 = x884;
}
else if (x884 != __act->x5427_zero) {
bool  x885 = x883 && x884;
__act->x5427 = x885;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5427 *__act,activation_x5427 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5427 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5427 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x5427 *__act) {
}

activation_x5427 *initAct(resourceInfo_t *resourceInfo) {
activation_x5427 * act = new activation_x5427;
act->x5427_zero = x876;
return act;
}

activation_x5427 *allocVal;
MultiLoopSync<activation_x5427*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5427_class *closure = (x5427_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5427_class *x5427_closure = new x5427_class(x5424,x876,x5423);
x5427_closure->loopStart = 0;
x5427_closure->loopSize = x5424;
activation_x5427 * alloc = x5427_closure->alloc(resourceInfo);
activation_x5427 * x5427 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5427 = x5427_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5427*> * sync = new MultiLoopSync<activation_x5427*>(x5427_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5427_closure->allocVal = alloc;
x5427_closure->syncVal = sync;
submitWork(r->threadId, x5427_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5427_closure)));
i = i+1;
}
x5427 = x5427_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5427;
}

/**********/

