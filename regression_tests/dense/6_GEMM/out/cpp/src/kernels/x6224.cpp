//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6224 * kernel_x6224(resourceInfo_t *resourceInfo,int32_t  x6221, int32_t  x189, cppDeliteArrayint32_t  *x6220) {
class x6224_class{
public:
int32_t x6221;
int32_t x189;
cppDeliteArrayint32_t *x6220;

x6224_class(int32_t  _x6221,int32_t  _x189,cppDeliteArrayint32_t * _x6220) {
x6221 = _x6221;
x189 = _x189;
x6220 = _x6220;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6221;
}

int64_t loopStart;
int64_t loopSize;
activation_x6224 *alloc(resourceInfo_t *resourceInfo) {
activation_x6224 * __act = new activation_x6224();;
__act->x6224_zero = x189;
return __act;
}

activation_x6224 *main_par(resourceInfo_t *resourceInfo,activation_x6224 *__act,MultiLoopSync<activation_x6224*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6224 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6224 * act = sync->get(localStart);
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

activation_x6224 *main_seq(resourceInfo_t *resourceInfo,activation_x6224 *__act) {
activation_x6224 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6224 *processRange(resourceInfo_t *resourceInfo,activation_x6224 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6224 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6224 *init(resourceInfo_t *resourceInfo,activation_x6224 *__act,int32_t x1034,bool isEmpty) {
activation_x6224 * __act2 = new activation_x6224();;
__act2->x6224_zero = __act->x6224_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x6224 = __act2->x6224_zero;
if (!isEmpty) {
int32_t x6222 = x6220->apply(x1034);
__act2->x6224 = x6222;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x6224 *__act,int32_t x1034) {
int32_t x6222 = x6220->apply(x1034);
int32_t x1039 = __act->x6224;
int32_t x1040 = x6222;
int32_t  x1041 = x1039 + x1040;
__act->x6224 = x1041;
}

void combine(resourceInfo_t *resourceInfo,activation_x6224 *__act,activation_x6224 *rhs) {
int32_t x1039 = __act->x6224;
int32_t x1040 = rhs->x6224;
if (x1039 == __act->x6224_zero) {
__act->x6224 = x1040;
}
else if (x1040 != __act->x6224_zero) {
int32_t  x1041 = x1039 + x1040;
__act->x6224 = x1041;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6224 *__act,activation_x6224 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6224 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6224 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6224 *__act) {
}

activation_x6224 *initAct(resourceInfo_t *resourceInfo) {
activation_x6224 * act = new activation_x6224;
act->x6224_zero = x189;
return act;
}

activation_x6224 *allocVal;
MultiLoopSync<activation_x6224*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6224_class *closure = (x6224_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6224_class *x6224_closure = new x6224_class(x6221,x189,x6220);
x6224_closure->loopStart = 0;
x6224_closure->loopSize = x6221;
activation_x6224 * alloc = x6224_closure->alloc(resourceInfo);
activation_x6224 * x6224 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6224 = x6224_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6224*> * sync = new MultiLoopSync<activation_x6224*>(x6224_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6224_closure->allocVal = alloc;
x6224_closure->syncVal = sync;
submitWork(r->threadId, x6224_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6224_closure)));
i = i+1;
}
x6224 = x6224_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6224;
}

/**********/

