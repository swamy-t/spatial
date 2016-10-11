//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1879 * kernel_x1879(resourceInfo_t *resourceInfo,int32_t  x1874, int32_t  x53, cppDeliteArrayint32_t  *x1854) {
class x1879_class{
public:
int32_t x1874;
int32_t x53;
cppDeliteArrayint32_t *x1854;

x1879_class(int32_t  _x1874,int32_t  _x53,cppDeliteArrayint32_t * _x1854) {
x1874 = _x1874;
x53 = _x53;
x1854 = _x1854;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1874;
}

int64_t loopStart;
int64_t loopSize;
activation_x1879 *alloc(resourceInfo_t *resourceInfo) {
activation_x1879 * __act = new activation_x1879();;
__act->x1879_zero = x53;
return __act;
}

activation_x1879 *main_par(resourceInfo_t *resourceInfo,activation_x1879 *__act,MultiLoopSync<activation_x1879*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1879 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1879 * act = sync->get(localStart);
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

activation_x1879 *main_seq(resourceInfo_t *resourceInfo,activation_x1879 *__act) {
activation_x1879 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1879 *processRange(resourceInfo_t *resourceInfo,activation_x1879 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1879 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1879 *init(resourceInfo_t *resourceInfo,activation_x1879 *__act,int32_t x264,bool isEmpty) {
activation_x1879 * __act2 = new activation_x1879();;
__act2->x1879_zero = __act->x1879_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1879 = __act2->x1879_zero;
if (!isEmpty) {
int32_t x1875 = x1854->apply(x264);
__act2->x1879 = x1875;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x1879 *__act,int32_t x264) {
int32_t x1875 = x1854->apply(x264);
int32_t x269 = __act->x1879;
int32_t x270 = x1875;
int32_t  x271 = x269 + x270;
__act->x1879 = x271;
}

void combine(resourceInfo_t *resourceInfo,activation_x1879 *__act,activation_x1879 *rhs) {
int32_t x269 = __act->x1879;
int32_t x270 = rhs->x1879;
if (x269 == __act->x1879_zero) {
__act->x1879 = x270;
}
else if (x270 != __act->x1879_zero) {
int32_t  x271 = x269 + x270;
__act->x1879 = x271;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1879 *__act,activation_x1879 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1879 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1879 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1879 *__act) {
}

activation_x1879 *initAct(resourceInfo_t *resourceInfo) {
activation_x1879 * act = new activation_x1879;
act->x1879_zero = x53;
return act;
}

activation_x1879 *allocVal;
MultiLoopSync<activation_x1879*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1879_class *closure = (x1879_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1879_class *x1879_closure = new x1879_class(x1874,x53,x1854);
x1879_closure->loopStart = 0;
x1879_closure->loopSize = x1874;
activation_x1879 * alloc = x1879_closure->alloc(resourceInfo);
activation_x1879 * x1879 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1879 = x1879_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1879*> * sync = new MultiLoopSync<activation_x1879*>(x1879_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1879_closure->allocVal = alloc;
x1879_closure->syncVal = sync;
submitWork(r->threadId, x1879_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1879_closure)));
i = i+1;
}
x1879 = x1879_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1879;
}

/**********/

