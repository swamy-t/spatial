//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1867 * kernel_x1867(resourceInfo_t *resourceInfo,int32_t  x1862, int32_t  x53, cppDeliteArrayint32_t  *x1850) {
class x1867_class{
public:
int32_t x1862;
int32_t x53;
cppDeliteArrayint32_t *x1850;

x1867_class(int32_t  _x1862,int32_t  _x53,cppDeliteArrayint32_t * _x1850) {
x1862 = _x1862;
x53 = _x53;
x1850 = _x1850;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1862;
}

int64_t loopStart;
int64_t loopSize;
activation_x1867 *alloc(resourceInfo_t *resourceInfo) {
activation_x1867 * __act = new activation_x1867();;
__act->x1867_zero = x53;
return __act;
}

activation_x1867 *main_par(resourceInfo_t *resourceInfo,activation_x1867 *__act,MultiLoopSync<activation_x1867*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1867 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1867 * act = sync->get(localStart);
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

activation_x1867 *main_seq(resourceInfo_t *resourceInfo,activation_x1867 *__act) {
activation_x1867 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1867 *processRange(resourceInfo_t *resourceInfo,activation_x1867 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1867 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1867 *init(resourceInfo_t *resourceInfo,activation_x1867 *__act,int32_t x244,bool isEmpty) {
activation_x1867 * __act2 = new activation_x1867();;
__act2->x1867_zero = __act->x1867_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1867 = __act2->x1867_zero;
if (!isEmpty) {
int32_t x1863 = x1850->apply(x244);
__act2->x1867 = x1863;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x1867 *__act,int32_t x244) {
int32_t x1863 = x1850->apply(x244);
int32_t x249 = __act->x1867;
int32_t x250 = x1863;
int32_t  x251 = x249 + x250;
__act->x1867 = x251;
}

void combine(resourceInfo_t *resourceInfo,activation_x1867 *__act,activation_x1867 *rhs) {
int32_t x249 = __act->x1867;
int32_t x250 = rhs->x1867;
if (x249 == __act->x1867_zero) {
__act->x1867 = x250;
}
else if (x250 != __act->x1867_zero) {
int32_t  x251 = x249 + x250;
__act->x1867 = x251;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1867 *__act,activation_x1867 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1867 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1867 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1867 *__act) {
}

activation_x1867 *initAct(resourceInfo_t *resourceInfo) {
activation_x1867 * act = new activation_x1867;
act->x1867_zero = x53;
return act;
}

activation_x1867 *allocVal;
MultiLoopSync<activation_x1867*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1867_class *closure = (x1867_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1867_class *x1867_closure = new x1867_class(x1862,x53,x1850);
x1867_closure->loopStart = 0;
x1867_closure->loopSize = x1862;
activation_x1867 * alloc = x1867_closure->alloc(resourceInfo);
activation_x1867 * x1867 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1867 = x1867_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1867*> * sync = new MultiLoopSync<activation_x1867*>(x1867_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1867_closure->allocVal = alloc;
x1867_closure->syncVal = sync;
submitWork(r->threadId, x1867_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1867_closure)));
i = i+1;
}
x1867 = x1867_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1867;
}

/**********/

