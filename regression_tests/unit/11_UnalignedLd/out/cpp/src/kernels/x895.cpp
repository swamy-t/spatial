//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x895 * kernel_x895(resourceInfo_t *resourceInfo,int32_t  x99, int32_t  x49, cppDeliteArrayint32_t  *x891) {
class x895_class{
public:
int32_t x99;
int32_t x49;
cppDeliteArrayint32_t *x891;

x895_class(int32_t  _x99,int32_t  _x49,cppDeliteArrayint32_t * _x891) {
x99 = _x99;
x49 = _x49;
x891 = _x891;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x99;
}

int64_t loopStart;
int64_t loopSize;
activation_x895 *alloc(resourceInfo_t *resourceInfo) {
activation_x895 * __act = new activation_x895();;
__act->x895_zero = x49;
return __act;
}

activation_x895 *main_par(resourceInfo_t *resourceInfo,activation_x895 *__act,MultiLoopSync<activation_x895*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x895 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x895 * act = sync->get(localStart);
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

activation_x895 *main_seq(resourceInfo_t *resourceInfo,activation_x895 *__act) {
activation_x895 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x895 *processRange(resourceInfo_t *resourceInfo,activation_x895 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x895 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x895 *init(resourceInfo_t *resourceInfo,activation_x895 *__act,int32_t x145,bool isEmpty) {
activation_x895 * __act2 = new activation_x895();;
__act2->x895_zero = __act->x895_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x895 = __act2->x895_zero;
if (!isEmpty) {
int32_t x892 = x891->apply(x145);
__act2->x895 = x892;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x895 *__act,int32_t x145) {
int32_t x892 = x891->apply(x145);
int32_t x149 = __act->x895;
int32_t x150 = x892;
int32_t  x151 = x149 + x150;
__act->x895 = x151;
}

void combine(resourceInfo_t *resourceInfo,activation_x895 *__act,activation_x895 *rhs) {
int32_t x149 = __act->x895;
int32_t x150 = rhs->x895;
if (x149 == __act->x895_zero) {
__act->x895 = x150;
}
else if (x150 != __act->x895_zero) {
int32_t  x151 = x149 + x150;
__act->x895 = x151;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x895 *__act,activation_x895 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x895 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x895 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x895 *__act) {
}

activation_x895 *initAct(resourceInfo_t *resourceInfo) {
activation_x895 * act = new activation_x895;
act->x895_zero = x49;
return act;
}

activation_x895 *allocVal;
MultiLoopSync<activation_x895*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x895_class *closure = (x895_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x895_class *x895_closure = new x895_class(x99,x49,x891);
x895_closure->loopStart = 0;
x895_closure->loopSize = x99;
activation_x895 * alloc = x895_closure->alloc(resourceInfo);
activation_x895 * x895 = NULL;
if (resourceInfo->availableThreads <= 1) {
x895 = x895_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x895*> * sync = new MultiLoopSync<activation_x895*>(x895_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x895_closure->allocVal = alloc;
x895_closure->syncVal = sync;
submitWork(r->threadId, x895_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x895_closure)));
i = i+1;
}
x895 = x895_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x895;
}

/**********/

