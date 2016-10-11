//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3249 * kernel_x3249(resourceInfo_t *resourceInfo,int32_t  x3246, bool  x559, cppDeliteArraybool  *x3245) {
class x3249_class{
public:
int32_t x3246;
bool x559;
cppDeliteArraybool *x3245;

x3249_class(int32_t  _x3246,bool  _x559,cppDeliteArraybool * _x3245) {
x3246 = _x3246;
x559 = _x559;
x3245 = _x3245;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3246;
}

int64_t loopStart;
int64_t loopSize;
activation_x3249 *alloc(resourceInfo_t *resourceInfo) {
activation_x3249 * __act = new activation_x3249();;
__act->x3249_zero = x559;
return __act;
}

activation_x3249 *main_par(resourceInfo_t *resourceInfo,activation_x3249 *__act,MultiLoopSync<activation_x3249*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3249 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3249 * act = sync->get(localStart);
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

activation_x3249 *main_seq(resourceInfo_t *resourceInfo,activation_x3249 *__act) {
activation_x3249 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3249 *processRange(resourceInfo_t *resourceInfo,activation_x3249 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3249 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3249 *init(resourceInfo_t *resourceInfo,activation_x3249 *__act,int32_t x561,bool isEmpty) {
activation_x3249 * __act2 = new activation_x3249();;
__act2->x3249_zero = __act->x3249_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x3249 = __act2->x3249_zero;
if (!isEmpty) {
bool x3247 = x3245->apply(x561);
__act2->x3249 = x3247;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x3249 *__act,int32_t x561) {
bool x3247 = x3245->apply(x561);
bool x566 = __act->x3249;
bool x567 = x3247;
bool  x568 = x566 && x567;
__act->x3249 = x568;
}

void combine(resourceInfo_t *resourceInfo,activation_x3249 *__act,activation_x3249 *rhs) {
bool x566 = __act->x3249;
bool x567 = rhs->x3249;
if (x566 == __act->x3249_zero) {
__act->x3249 = x567;
}
else if (x567 != __act->x3249_zero) {
bool  x568 = x566 && x567;
__act->x3249 = x568;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3249 *__act,activation_x3249 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3249 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3249 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3249 *__act) {
}

activation_x3249 *initAct(resourceInfo_t *resourceInfo) {
activation_x3249 * act = new activation_x3249;
act->x3249_zero = x559;
return act;
}

activation_x3249 *allocVal;
MultiLoopSync<activation_x3249*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3249_class *closure = (x3249_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3249_class *x3249_closure = new x3249_class(x3246,x559,x3245);
x3249_closure->loopStart = 0;
x3249_closure->loopSize = x3246;
activation_x3249 * alloc = x3249_closure->alloc(resourceInfo);
activation_x3249 * x3249 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3249 = x3249_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3249*> * sync = new MultiLoopSync<activation_x3249*>(x3249_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3249_closure->allocVal = alloc;
x3249_closure->syncVal = sync;
submitWork(r->threadId, x3249_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3249_closure)));
i = i+1;
}
x3249 = x3249_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3249;
}

/**********/

