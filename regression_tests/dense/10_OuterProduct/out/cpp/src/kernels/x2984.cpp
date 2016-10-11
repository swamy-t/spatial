//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2984 * kernel_x2984(resourceInfo_t *resourceInfo,int32_t  x2942, int32_t  x99, cppDeliteArrayint32_t  *x2980) {
class x2984_class{
public:
int32_t x2942;
int32_t x99;
cppDeliteArrayint32_t *x2980;

x2984_class(int32_t  _x2942,int32_t  _x99,cppDeliteArrayint32_t * _x2980) {
x2942 = _x2942;
x99 = _x99;
x2980 = _x2980;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x2942;
}

int64_t loopStart;
int64_t loopSize;
activation_x2984 *alloc(resourceInfo_t *resourceInfo) {
activation_x2984 * __act = new activation_x2984();;
__act->x2984_zero = x99;
return __act;
}

activation_x2984 *main_par(resourceInfo_t *resourceInfo,activation_x2984 *__act,MultiLoopSync<activation_x2984*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2984 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2984 * act = sync->get(localStart);
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

activation_x2984 *main_seq(resourceInfo_t *resourceInfo,activation_x2984 *__act) {
activation_x2984 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2984 *processRange(resourceInfo_t *resourceInfo,activation_x2984 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2984 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2984 *init(resourceInfo_t *resourceInfo,activation_x2984 *__act,int32_t x401,bool isEmpty) {
activation_x2984 * __act2 = new activation_x2984();;
__act2->x2984_zero = __act->x2984_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x2984 = __act2->x2984_zero;
if (!isEmpty) {
int32_t x2981 = x2980->apply(x401);
__act2->x2984 = x2981;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x2984 *__act,int32_t x401) {
int32_t x2981 = x2980->apply(x401);
int32_t x405 = __act->x2984;
int32_t x406 = x2981;
int32_t  x407 = x405 + x406;
__act->x2984 = x407;
}

void combine(resourceInfo_t *resourceInfo,activation_x2984 *__act,activation_x2984 *rhs) {
int32_t x405 = __act->x2984;
int32_t x406 = rhs->x2984;
if (x405 == __act->x2984_zero) {
__act->x2984 = x406;
}
else if (x406 != __act->x2984_zero) {
int32_t  x407 = x405 + x406;
__act->x2984 = x407;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2984 *__act,activation_x2984 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2984 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2984 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2984 *__act) {
}

activation_x2984 *initAct(resourceInfo_t *resourceInfo) {
activation_x2984 * act = new activation_x2984;
act->x2984_zero = x99;
return act;
}

activation_x2984 *allocVal;
MultiLoopSync<activation_x2984*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2984_class *closure = (x2984_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2984_class *x2984_closure = new x2984_class(x2942,x99,x2980);
x2984_closure->loopStart = 0;
x2984_closure->loopSize = x2942;
activation_x2984 * alloc = x2984_closure->alloc(resourceInfo);
activation_x2984 * x2984 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2984 = x2984_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2984*> * sync = new MultiLoopSync<activation_x2984*>(x2984_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2984_closure->allocVal = alloc;
x2984_closure->syncVal = sync;
submitWork(r->threadId, x2984_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2984_closure)));
i = i+1;
}
x2984 = x2984_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2984;
}

/**********/

