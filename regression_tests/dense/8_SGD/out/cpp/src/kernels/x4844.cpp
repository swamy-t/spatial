//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x4844 * kernel_x4844(resourceInfo_t *resourceInfo,int32_t  x4839, bool  x838, cppDeliteArraybool  *x4838) {
class x4844_class{
public:
int32_t x4839;
bool x838;
cppDeliteArraybool *x4838;

x4844_class(int32_t  _x4839,bool  _x838,cppDeliteArraybool * _x4838) {
x4839 = _x4839;
x838 = _x838;
x4838 = _x4838;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x4839;
}

int64_t loopStart;
int64_t loopSize;
activation_x4844 *alloc(resourceInfo_t *resourceInfo) {
activation_x4844 * __act = new activation_x4844();;
__act->x4844_zero = x838;
return __act;
}

activation_x4844 *main_par(resourceInfo_t *resourceInfo,activation_x4844 *__act,MultiLoopSync<activation_x4844*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4844 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4844 * act = sync->get(localStart);
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

activation_x4844 *main_seq(resourceInfo_t *resourceInfo,activation_x4844 *__act) {
activation_x4844 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4844 *processRange(resourceInfo_t *resourceInfo,activation_x4844 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4844 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4844 *init(resourceInfo_t *resourceInfo,activation_x4844 *__act,int32_t x840,bool isEmpty) {
activation_x4844 * __act2 = new activation_x4844();;
__act2->x4844_zero = __act->x4844_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x4844 = __act2->x4844_zero;
if (!isEmpty) {
bool x4840 = x4838->apply(x840);
__act2->x4844 = x4840;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x4844 *__act,int32_t x840) {
bool x4840 = x4838->apply(x840);
bool x845 = __act->x4844;
bool x846 = x4840;
bool  x847 = x845 && x846;
__act->x4844 = x847;
}

void combine(resourceInfo_t *resourceInfo,activation_x4844 *__act,activation_x4844 *rhs) {
bool x845 = __act->x4844;
bool x846 = rhs->x4844;
if (x845 == __act->x4844_zero) {
__act->x4844 = x846;
}
else if (x846 != __act->x4844_zero) {
bool  x847 = x845 && x846;
__act->x4844 = x847;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4844 *__act,activation_x4844 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4844 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4844 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4844 *__act) {
}

activation_x4844 *initAct(resourceInfo_t *resourceInfo) {
activation_x4844 * act = new activation_x4844;
act->x4844_zero = x838;
return act;
}

activation_x4844 *allocVal;
MultiLoopSync<activation_x4844*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4844_class *closure = (x4844_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4844_class *x4844_closure = new x4844_class(x4839,x838,x4838);
x4844_closure->loopStart = 0;
x4844_closure->loopSize = x4839;
activation_x4844 * alloc = x4844_closure->alloc(resourceInfo);
activation_x4844 * x4844 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4844 = x4844_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4844*> * sync = new MultiLoopSync<activation_x4844*>(x4844_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4844_closure->allocVal = alloc;
x4844_closure->syncVal = sync;
submitWork(r->threadId, x4844_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4844_closure)));
i = i+1;
}
x4844 = x4844_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4844;
}

/**********/

