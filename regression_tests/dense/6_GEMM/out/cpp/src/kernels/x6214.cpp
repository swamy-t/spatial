//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6214 * kernel_x6214(resourceInfo_t *resourceInfo,int32_t  x6208, int32_t  x189, cppDeliteArrayint32_t  *x6212) {
class x6214_class{
public:
int32_t x6208;
int32_t x189;
cppDeliteArrayint32_t *x6212;

x6214_class(int32_t  _x6208,int32_t  _x189,cppDeliteArrayint32_t * _x6212) {
x6208 = _x6208;
x189 = _x189;
x6212 = _x6212;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6208;
}

int64_t loopStart;
int64_t loopSize;
activation_x6214 *alloc(resourceInfo_t *resourceInfo) {
activation_x6214 * __act = new activation_x6214();;
__act->x6214_zero = x189;
return __act;
}

activation_x6214 *main_par(resourceInfo_t *resourceInfo,activation_x6214 *__act,MultiLoopSync<activation_x6214*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6214 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6214 * act = sync->get(localStart);
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

activation_x6214 *main_seq(resourceInfo_t *resourceInfo,activation_x6214 *__act) {
activation_x6214 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6214 *processRange(resourceInfo_t *resourceInfo,activation_x6214 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6214 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6214 *init(resourceInfo_t *resourceInfo,activation_x6214 *__act,int32_t x976,bool isEmpty) {
activation_x6214 * __act2 = new activation_x6214();;
__act2->x6214_zero = __act->x6214_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x6214 = __act2->x6214_zero;
if (!isEmpty) {
int32_t x6213 = x6212->apply(x976);
__act2->x6214 = x6213;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x6214 *__act,int32_t x976) {
int32_t x6213 = x6212->apply(x976);
int32_t x980 = __act->x6214;
int32_t x981 = x6213;
int32_t  x982 = x980 + x981;
__act->x6214 = x982;
}

void combine(resourceInfo_t *resourceInfo,activation_x6214 *__act,activation_x6214 *rhs) {
int32_t x980 = __act->x6214;
int32_t x981 = rhs->x6214;
if (x980 == __act->x6214_zero) {
__act->x6214 = x981;
}
else if (x981 != __act->x6214_zero) {
int32_t  x982 = x980 + x981;
__act->x6214 = x982;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6214 *__act,activation_x6214 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6214 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6214 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6214 *__act) {
}

activation_x6214 *initAct(resourceInfo_t *resourceInfo) {
activation_x6214 * act = new activation_x6214;
act->x6214_zero = x189;
return act;
}

activation_x6214 *allocVal;
MultiLoopSync<activation_x6214*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6214_class *closure = (x6214_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6214_class *x6214_closure = new x6214_class(x6208,x189,x6212);
x6214_closure->loopStart = 0;
x6214_closure->loopSize = x6208;
activation_x6214 * alloc = x6214_closure->alloc(resourceInfo);
activation_x6214 * x6214 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6214 = x6214_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6214*> * sync = new MultiLoopSync<activation_x6214*>(x6214_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6214_closure->allocVal = alloc;
x6214_closure->syncVal = sync;
submitWork(r->threadId, x6214_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6214_closure)));
i = i+1;
}
x6214 = x6214_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6214;
}

/**********/

