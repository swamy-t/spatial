//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1408 * kernel_x1408(resourceInfo_t *resourceInfo,int32_t  x1403, bool  x245, cppDeliteArraybool  *x1402) {
class x1408_class{
public:
int32_t x1403;
bool x245;
cppDeliteArraybool *x1402;

x1408_class(int32_t  _x1403,bool  _x245,cppDeliteArraybool * _x1402) {
x1403 = _x1403;
x245 = _x245;
x1402 = _x1402;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1403;
}

int64_t loopStart;
int64_t loopSize;
activation_x1408 *alloc(resourceInfo_t *resourceInfo) {
activation_x1408 * __act = new activation_x1408();;
__act->x1408_zero = x245;
return __act;
}

activation_x1408 *main_par(resourceInfo_t *resourceInfo,activation_x1408 *__act,MultiLoopSync<activation_x1408*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1408 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1408 * act = sync->get(localStart);
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

activation_x1408 *main_seq(resourceInfo_t *resourceInfo,activation_x1408 *__act) {
activation_x1408 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1408 *processRange(resourceInfo_t *resourceInfo,activation_x1408 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1408 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1408 *init(resourceInfo_t *resourceInfo,activation_x1408 *__act,int32_t x247,bool isEmpty) {
activation_x1408 * __act2 = new activation_x1408();;
__act2->x1408_zero = __act->x1408_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1408 = __act2->x1408_zero;
if (!isEmpty) {
bool x1404 = x1402->apply(x247);
__act2->x1408 = x1404;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x1408 *__act,int32_t x247) {
bool x1404 = x1402->apply(x247);
bool x252 = __act->x1408;
bool x253 = x1404;
bool  x254 = x252 && x253;
__act->x1408 = x254;
}

void combine(resourceInfo_t *resourceInfo,activation_x1408 *__act,activation_x1408 *rhs) {
bool x252 = __act->x1408;
bool x253 = rhs->x1408;
if (x252 == __act->x1408_zero) {
__act->x1408 = x253;
}
else if (x253 != __act->x1408_zero) {
bool  x254 = x252 && x253;
__act->x1408 = x254;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1408 *__act,activation_x1408 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1408 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1408 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1408 *__act) {
}

activation_x1408 *initAct(resourceInfo_t *resourceInfo) {
activation_x1408 * act = new activation_x1408;
act->x1408_zero = x245;
return act;
}

activation_x1408 *allocVal;
MultiLoopSync<activation_x1408*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1408_class *closure = (x1408_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1408_class *x1408_closure = new x1408_class(x1403,x245,x1402);
x1408_closure->loopStart = 0;
x1408_closure->loopSize = x1403;
activation_x1408 * alloc = x1408_closure->alloc(resourceInfo);
activation_x1408 * x1408 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1408 = x1408_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1408*> * sync = new MultiLoopSync<activation_x1408*>(x1408_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1408_closure->allocVal = alloc;
x1408_closure->syncVal = sync;
submitWork(r->threadId, x1408_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1408_closure)));
i = i+1;
}
x1408 = x1408_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1408;
}

/**********/

