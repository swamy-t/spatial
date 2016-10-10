//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2143 * kernel_x2143(resourceInfo_t *resourceInfo,int32_t  x161, int32_t  x96, cppDeliteArrayint32_t  *x2141) {
class x2143_class{
public:
int32_t x161;
int32_t x96;
cppDeliteArrayint32_t *x2141;

x2143_class(int32_t  _x161,int32_t  _x96,cppDeliteArrayint32_t * _x2141) {
x161 = _x161;
x96 = _x96;
x2141 = _x2141;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x161;
}

int64_t loopStart;
int64_t loopSize;
activation_x2143 *alloc(resourceInfo_t *resourceInfo) {
activation_x2143 * __act = new activation_x2143();;
__act->x2143_zero = x96;
return __act;
}

activation_x2143 *main_par(resourceInfo_t *resourceInfo,activation_x2143 *__act,MultiLoopSync<activation_x2143*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2143 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2143 * act = sync->get(localStart);
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

activation_x2143 *main_seq(resourceInfo_t *resourceInfo,activation_x2143 *__act) {
activation_x2143 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2143 *processRange(resourceInfo_t *resourceInfo,activation_x2143 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2143 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2143 *init(resourceInfo_t *resourceInfo,activation_x2143 *__act,int32_t x355,bool isEmpty) {
activation_x2143 * __act2 = new activation_x2143();;
__act2->x2143_zero = __act->x2143_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x2143 = __act2->x2143_zero;
if (!isEmpty) {
int32_t x2142 = x2141->apply(x355);
__act2->x2143 = x2142;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x2143 *__act,int32_t x355) {
int32_t x2142 = x2141->apply(x355);
int32_t x359 = __act->x2143;
int32_t x360 = x2142;
int32_t  x361 = x359 + x360;
__act->x2143 = x361;
}

void combine(resourceInfo_t *resourceInfo,activation_x2143 *__act,activation_x2143 *rhs) {
int32_t x359 = __act->x2143;
int32_t x360 = rhs->x2143;
if (x359 == __act->x2143_zero) {
__act->x2143 = x360;
}
else if (x360 != __act->x2143_zero) {
int32_t  x361 = x359 + x360;
__act->x2143 = x361;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2143 *__act,activation_x2143 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2143 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2143 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2143 *__act) {
}

activation_x2143 *initAct(resourceInfo_t *resourceInfo) {
activation_x2143 * act = new activation_x2143;
act->x2143_zero = x96;
return act;
}

activation_x2143 *allocVal;
MultiLoopSync<activation_x2143*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2143_class *closure = (x2143_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2143_class *x2143_closure = new x2143_class(x161,x96,x2141);
x2143_closure->loopStart = 0;
x2143_closure->loopSize = x161;
activation_x2143 * alloc = x2143_closure->alloc(resourceInfo);
activation_x2143 * x2143 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2143 = x2143_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2143*> * sync = new MultiLoopSync<activation_x2143*>(x2143_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2143_closure->allocVal = alloc;
x2143_closure->syncVal = sync;
submitWork(r->threadId, x2143_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2143_closure)));
i = i+1;
}
x2143 = x2143_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2143;
}

/**********/

