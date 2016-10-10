//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2001 * kernel_x2001(resourceInfo_t *resourceInfo,int32_t  x1996, bool  x268, cppDeliteArraybool  *x1995) {
class x2001_class{
public:
int32_t x1996;
bool x268;
cppDeliteArraybool *x1995;

x2001_class(int32_t  _x1996,bool  _x268,cppDeliteArraybool * _x1995) {
x1996 = _x1996;
x268 = _x268;
x1995 = _x1995;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1996;
}

int64_t loopStart;
int64_t loopSize;
activation_x2001 *alloc(resourceInfo_t *resourceInfo) {
activation_x2001 * __act = new activation_x2001();;
__act->x2001_zero = x268;
return __act;
}

activation_x2001 *main_par(resourceInfo_t *resourceInfo,activation_x2001 *__act,MultiLoopSync<activation_x2001*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2001 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2001 * act = sync->get(localStart);
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

activation_x2001 *main_seq(resourceInfo_t *resourceInfo,activation_x2001 *__act) {
activation_x2001 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2001 *processRange(resourceInfo_t *resourceInfo,activation_x2001 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2001 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2001 *init(resourceInfo_t *resourceInfo,activation_x2001 *__act,int32_t x396,bool isEmpty) {
activation_x2001 * __act2 = new activation_x2001();;
__act2->x2001_zero = __act->x2001_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x2001 = __act2->x2001_zero;
if (!isEmpty) {
bool x1997 = x1995->apply(x396);
__act2->x2001 = x1997;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x2001 *__act,int32_t x396) {
bool x1997 = x1995->apply(x396);
bool x401 = __act->x2001;
bool x402 = x1997;
bool  x403 = x401 && x402;
__act->x2001 = x403;
}

void combine(resourceInfo_t *resourceInfo,activation_x2001 *__act,activation_x2001 *rhs) {
bool x401 = __act->x2001;
bool x402 = rhs->x2001;
if (x401 == __act->x2001_zero) {
__act->x2001 = x402;
}
else if (x402 != __act->x2001_zero) {
bool  x403 = x401 && x402;
__act->x2001 = x403;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2001 *__act,activation_x2001 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2001 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2001 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2001 *__act) {
}

activation_x2001 *initAct(resourceInfo_t *resourceInfo) {
activation_x2001 * act = new activation_x2001;
act->x2001_zero = x268;
return act;
}

activation_x2001 *allocVal;
MultiLoopSync<activation_x2001*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2001_class *closure = (x2001_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2001_class *x2001_closure = new x2001_class(x1996,x268,x1995);
x2001_closure->loopStart = 0;
x2001_closure->loopSize = x1996;
activation_x2001 * alloc = x2001_closure->alloc(resourceInfo);
activation_x2001 * x2001 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2001 = x2001_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2001*> * sync = new MultiLoopSync<activation_x2001*>(x2001_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2001_closure->allocVal = alloc;
x2001_closure->syncVal = sync;
submitWork(r->threadId, x2001_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2001_closure)));
i = i+1;
}
x2001 = x2001_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2001;
}

/**********/

