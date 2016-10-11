//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1873 * kernel_x1873(resourceInfo_t *resourceInfo,int32_t  x1868, int32_t  x53, cppDeliteArrayint32_t  *x1852) {
class x1873_class{
public:
int32_t x1868;
int32_t x53;
cppDeliteArrayint32_t *x1852;

x1873_class(int32_t  _x1868,int32_t  _x53,cppDeliteArrayint32_t * _x1852) {
x1868 = _x1868;
x53 = _x53;
x1852 = _x1852;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1868;
}

int64_t loopStart;
int64_t loopSize;
activation_x1873 *alloc(resourceInfo_t *resourceInfo) {
activation_x1873 * __act = new activation_x1873();;
__act->x1873_zero = x53;
return __act;
}

activation_x1873 *main_par(resourceInfo_t *resourceInfo,activation_x1873 *__act,MultiLoopSync<activation_x1873*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1873 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1873 * act = sync->get(localStart);
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

activation_x1873 *main_seq(resourceInfo_t *resourceInfo,activation_x1873 *__act) {
activation_x1873 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1873 *processRange(resourceInfo_t *resourceInfo,activation_x1873 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1873 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1873 *init(resourceInfo_t *resourceInfo,activation_x1873 *__act,int32_t x254,bool isEmpty) {
activation_x1873 * __act2 = new activation_x1873();;
__act2->x1873_zero = __act->x1873_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1873 = __act2->x1873_zero;
if (!isEmpty) {
int32_t x1869 = x1852->apply(x254);
__act2->x1873 = x1869;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x1873 *__act,int32_t x254) {
int32_t x1869 = x1852->apply(x254);
int32_t x259 = __act->x1873;
int32_t x260 = x1869;
int32_t  x261 = x259 + x260;
__act->x1873 = x261;
}

void combine(resourceInfo_t *resourceInfo,activation_x1873 *__act,activation_x1873 *rhs) {
int32_t x259 = __act->x1873;
int32_t x260 = rhs->x1873;
if (x259 == __act->x1873_zero) {
__act->x1873 = x260;
}
else if (x260 != __act->x1873_zero) {
int32_t  x261 = x259 + x260;
__act->x1873 = x261;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1873 *__act,activation_x1873 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1873 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1873 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1873 *__act) {
}

activation_x1873 *initAct(resourceInfo_t *resourceInfo) {
activation_x1873 * act = new activation_x1873;
act->x1873_zero = x53;
return act;
}

activation_x1873 *allocVal;
MultiLoopSync<activation_x1873*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1873_class *closure = (x1873_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1873_class *x1873_closure = new x1873_class(x1868,x53,x1852);
x1873_closure->loopStart = 0;
x1873_closure->loopSize = x1868;
activation_x1873 * alloc = x1873_closure->alloc(resourceInfo);
activation_x1873 * x1873 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1873 = x1873_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1873*> * sync = new MultiLoopSync<activation_x1873*>(x1873_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1873_closure->allocVal = alloc;
x1873_closure->syncVal = sync;
submitWork(r->threadId, x1873_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1873_closure)));
i = i+1;
}
x1873 = x1873_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1873;
}

/**********/

