//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5415 * kernel_x5415(resourceInfo_t *resourceInfo,int32_t  x5412, int32_t  x285, cppDeliteArrayint32_t  *x5411) {
class x5415_class{
public:
int32_t x5412;
int32_t x285;
cppDeliteArrayint32_t *x5411;

x5415_class(int32_t  _x5412,int32_t  _x285,cppDeliteArrayint32_t * _x5411) {
x5412 = _x5412;
x285 = _x285;
x5411 = _x5411;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x5412;
}

int64_t loopStart;
int64_t loopSize;
activation_x5415 *alloc(resourceInfo_t *resourceInfo) {
activation_x5415 * __act = new activation_x5415();;
__act->x5415_zero = x285;
return __act;
}

activation_x5415 *main_par(resourceInfo_t *resourceInfo,activation_x5415 *__act,MultiLoopSync<activation_x5415*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5415 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5415 * act = sync->get(localStart);
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

activation_x5415 *main_seq(resourceInfo_t *resourceInfo,activation_x5415 *__act) {
activation_x5415 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x5415 *processRange(resourceInfo_t *resourceInfo,activation_x5415 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5415 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5415 *init(resourceInfo_t *resourceInfo,activation_x5415 *__act,int32_t x817,bool isEmpty) {
activation_x5415 * __act2 = new activation_x5415();;
__act2->x5415_zero = __act->x5415_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x5415 = __act2->x5415_zero;
if (!isEmpty) {
int32_t x5413 = x5411->apply(x817);
__act2->x5415 = x5413;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x5415 *__act,int32_t x817) {
int32_t x5413 = x5411->apply(x817);
int32_t x822 = __act->x5415;
int32_t x823 = x5413;
int32_t  x824 = x822 + x823;
__act->x5415 = x824;
}

void combine(resourceInfo_t *resourceInfo,activation_x5415 *__act,activation_x5415 *rhs) {
int32_t x822 = __act->x5415;
int32_t x823 = rhs->x5415;
if (x822 == __act->x5415_zero) {
__act->x5415 = x823;
}
else if (x823 != __act->x5415_zero) {
int32_t  x824 = x822 + x823;
__act->x5415 = x824;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5415 *__act,activation_x5415 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5415 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5415 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x5415 *__act) {
}

activation_x5415 *initAct(resourceInfo_t *resourceInfo) {
activation_x5415 * act = new activation_x5415;
act->x5415_zero = x285;
return act;
}

activation_x5415 *allocVal;
MultiLoopSync<activation_x5415*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5415_class *closure = (x5415_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5415_class *x5415_closure = new x5415_class(x5412,x285,x5411);
x5415_closure->loopStart = 0;
x5415_closure->loopSize = x5412;
activation_x5415 * alloc = x5415_closure->alloc(resourceInfo);
activation_x5415 * x5415 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5415 = x5415_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5415*> * sync = new MultiLoopSync<activation_x5415*>(x5415_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5415_closure->allocVal = alloc;
x5415_closure->syncVal = sync;
submitWork(r->threadId, x5415_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5415_closure)));
i = i+1;
}
x5415 = x5415_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5415;
}

/**********/

