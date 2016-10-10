//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6241 * kernel_x6241(resourceInfo_t *resourceInfo,int32_t  x6238, int32_t  x189, cppDeliteArrayint32_t  *x6237) {
class x6241_class{
public:
int32_t x6238;
int32_t x189;
cppDeliteArrayint32_t *x6237;

x6241_class(int32_t  _x6238,int32_t  _x189,cppDeliteArrayint32_t * _x6237) {
x6238 = _x6238;
x189 = _x189;
x6237 = _x6237;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6238;
}

int64_t loopStart;
int64_t loopSize;
activation_x6241 *alloc(resourceInfo_t *resourceInfo) {
activation_x6241 * __act = new activation_x6241();;
__act->x6241_zero = x189;
return __act;
}

activation_x6241 *main_par(resourceInfo_t *resourceInfo,activation_x6241 *__act,MultiLoopSync<activation_x6241*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6241 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6241 * act = sync->get(localStart);
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

activation_x6241 *main_seq(resourceInfo_t *resourceInfo,activation_x6241 *__act) {
activation_x6241 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6241 *processRange(resourceInfo_t *resourceInfo,activation_x6241 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6241 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6241 *init(resourceInfo_t *resourceInfo,activation_x6241 *__act,int32_t x984,bool isEmpty) {
activation_x6241 * __act2 = new activation_x6241();;
__act2->x6241_zero = __act->x6241_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x6241 = __act2->x6241_zero;
if (!isEmpty) {
int32_t x6239 = x6237->apply(x984);
__act2->x6241 = x6239;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x6241 *__act,int32_t x984) {
int32_t x6239 = x6237->apply(x984);
int32_t x989 = __act->x6241;
int32_t x990 = x6239;
int32_t  x991 = x989 + x990;
__act->x6241 = x991;
}

void combine(resourceInfo_t *resourceInfo,activation_x6241 *__act,activation_x6241 *rhs) {
int32_t x989 = __act->x6241;
int32_t x990 = rhs->x6241;
if (x989 == __act->x6241_zero) {
__act->x6241 = x990;
}
else if (x990 != __act->x6241_zero) {
int32_t  x991 = x989 + x990;
__act->x6241 = x991;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6241 *__act,activation_x6241 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6241 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6241 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6241 *__act) {
}

activation_x6241 *initAct(resourceInfo_t *resourceInfo) {
activation_x6241 * act = new activation_x6241;
act->x6241_zero = x189;
return act;
}

activation_x6241 *allocVal;
MultiLoopSync<activation_x6241*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6241_class *closure = (x6241_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6241_class *x6241_closure = new x6241_class(x6238,x189,x6237);
x6241_closure->loopStart = 0;
x6241_closure->loopSize = x6238;
activation_x6241 * alloc = x6241_closure->alloc(resourceInfo);
activation_x6241 * x6241 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6241 = x6241_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6241*> * sync = new MultiLoopSync<activation_x6241*>(x6241_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6241_closure->allocVal = alloc;
x6241_closure->syncVal = sync;
submitWork(r->threadId, x6241_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6241_closure)));
i = i+1;
}
x6241 = x6241_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6241;
}

/**********/

