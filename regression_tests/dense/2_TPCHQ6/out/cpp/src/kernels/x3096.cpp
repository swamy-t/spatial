//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3096 * kernel_x3096(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x195, cppDeliteArrayint32_t  *x3092) {
class x3096_class{
public:
int32_t x3;
int32_t x195;
cppDeliteArrayint32_t *x3092;

x3096_class(int32_t  _x3,int32_t  _x195,cppDeliteArrayint32_t * _x3092) {
x3 = _x3;
x195 = _x195;
x3092 = _x3092;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x3096 *alloc(resourceInfo_t *resourceInfo) {
activation_x3096 * __act = new activation_x3096();;
__act->x3096_zero = x195;
return __act;
}

activation_x3096 *main_par(resourceInfo_t *resourceInfo,activation_x3096 *__act,MultiLoopSync<activation_x3096*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3096 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3096 * act = sync->get(localStart);
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

activation_x3096 *main_seq(resourceInfo_t *resourceInfo,activation_x3096 *__act) {
activation_x3096 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3096 *processRange(resourceInfo_t *resourceInfo,activation_x3096 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3096 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3096 *init(resourceInfo_t *resourceInfo,activation_x3096 *__act,int32_t x464,bool isEmpty) {
activation_x3096 * __act2 = new activation_x3096();;
__act2->x3096_zero = __act->x3096_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x3096 = __act2->x3096_zero;
if (!isEmpty) {
int32_t x3093 = x3092->apply(x464);
__act2->x3096 = x3093;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x3096 *__act,int32_t x464) {
int32_t x3093 = x3092->apply(x464);
int32_t x468 = __act->x3096;
int32_t x469 = x3093;
int32_t  x470 = x468 + x469;
__act->x3096 = x470;
}

void combine(resourceInfo_t *resourceInfo,activation_x3096 *__act,activation_x3096 *rhs) {
int32_t x468 = __act->x3096;
int32_t x469 = rhs->x3096;
if (x468 == __act->x3096_zero) {
__act->x3096 = x469;
}
else if (x469 != __act->x3096_zero) {
int32_t  x470 = x468 + x469;
__act->x3096 = x470;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3096 *__act,activation_x3096 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3096 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3096 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3096 *__act) {
}

activation_x3096 *initAct(resourceInfo_t *resourceInfo) {
activation_x3096 * act = new activation_x3096;
act->x3096_zero = x195;
return act;
}

activation_x3096 *allocVal;
MultiLoopSync<activation_x3096*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3096_class *closure = (x3096_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3096_class *x3096_closure = new x3096_class(x3,x195,x3092);
x3096_closure->loopStart = 0;
x3096_closure->loopSize = x3;
activation_x3096 * alloc = x3096_closure->alloc(resourceInfo);
activation_x3096 * x3096 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3096 = x3096_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3096*> * sync = new MultiLoopSync<activation_x3096*>(x3096_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3096_closure->allocVal = alloc;
x3096_closure->syncVal = sync;
submitWork(r->threadId, x3096_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3096_closure)));
i = i+1;
}
x3096 = x3096_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3096;
}

/**********/

