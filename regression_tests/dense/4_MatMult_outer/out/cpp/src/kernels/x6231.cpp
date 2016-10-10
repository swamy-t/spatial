//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6231 * kernel_x6231(resourceInfo_t *resourceInfo,int32_t  x6225, int32_t  x189, cppDeliteArrayint32_t  *x6229) {
class x6231_class{
public:
int32_t x6225;
int32_t x189;
cppDeliteArrayint32_t *x6229;

x6231_class(int32_t  _x6225,int32_t  _x189,cppDeliteArrayint32_t * _x6229) {
x6225 = _x6225;
x189 = _x189;
x6229 = _x6229;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6225;
}

int64_t loopStart;
int64_t loopSize;
activation_x6231 *alloc(resourceInfo_t *resourceInfo) {
activation_x6231 * __act = new activation_x6231();;
__act->x6231_zero = x189;
return __act;
}

activation_x6231 *main_par(resourceInfo_t *resourceInfo,activation_x6231 *__act,MultiLoopSync<activation_x6231*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6231 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6231 * act = sync->get(localStart);
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

activation_x6231 *main_seq(resourceInfo_t *resourceInfo,activation_x6231 *__act) {
activation_x6231 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6231 *processRange(resourceInfo_t *resourceInfo,activation_x6231 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6231 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6231 *init(resourceInfo_t *resourceInfo,activation_x6231 *__act,int32_t x926,bool isEmpty) {
activation_x6231 * __act2 = new activation_x6231();;
__act2->x6231_zero = __act->x6231_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x6231 = __act2->x6231_zero;
if (!isEmpty) {
int32_t x6230 = x6229->apply(x926);
__act2->x6231 = x6230;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x6231 *__act,int32_t x926) {
int32_t x6230 = x6229->apply(x926);
int32_t x930 = __act->x6231;
int32_t x931 = x6230;
int32_t  x932 = x930 + x931;
__act->x6231 = x932;
}

void combine(resourceInfo_t *resourceInfo,activation_x6231 *__act,activation_x6231 *rhs) {
int32_t x930 = __act->x6231;
int32_t x931 = rhs->x6231;
if (x930 == __act->x6231_zero) {
__act->x6231 = x931;
}
else if (x931 != __act->x6231_zero) {
int32_t  x932 = x930 + x931;
__act->x6231 = x932;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6231 *__act,activation_x6231 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6231 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6231 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6231 *__act) {
}

activation_x6231 *initAct(resourceInfo_t *resourceInfo) {
activation_x6231 * act = new activation_x6231;
act->x6231_zero = x189;
return act;
}

activation_x6231 *allocVal;
MultiLoopSync<activation_x6231*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6231_class *closure = (x6231_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6231_class *x6231_closure = new x6231_class(x6225,x189,x6229);
x6231_closure->loopStart = 0;
x6231_closure->loopSize = x6225;
activation_x6231 * alloc = x6231_closure->alloc(resourceInfo);
activation_x6231 * x6231 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6231 = x6231_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6231*> * sync = new MultiLoopSync<activation_x6231*>(x6231_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6231_closure->allocVal = alloc;
x6231_closure->syncVal = sync;
submitWork(r->threadId, x6231_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6231_closure)));
i = i+1;
}
x6231 = x6231_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6231;
}

/**********/

