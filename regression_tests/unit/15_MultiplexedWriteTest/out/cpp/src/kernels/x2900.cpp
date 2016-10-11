//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2900 * kernel_x2900(resourceInfo_t *resourceInfo,int32_t  x2897, bool  x502, cppDeliteArraybool  *x2896) {
class x2900_class{
public:
int32_t x2897;
bool x502;
cppDeliteArraybool *x2896;

x2900_class(int32_t  _x2897,bool  _x502,cppDeliteArraybool * _x2896) {
x2897 = _x2897;
x502 = _x502;
x2896 = _x2896;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x2897;
}

int64_t loopStart;
int64_t loopSize;
activation_x2900 *alloc(resourceInfo_t *resourceInfo) {
activation_x2900 * __act = new activation_x2900();;
__act->x2900_zero = x502;
return __act;
}

activation_x2900 *main_par(resourceInfo_t *resourceInfo,activation_x2900 *__act,MultiLoopSync<activation_x2900*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2900 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2900 * act = sync->get(localStart);
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

activation_x2900 *main_seq(resourceInfo_t *resourceInfo,activation_x2900 *__act) {
activation_x2900 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2900 *processRange(resourceInfo_t *resourceInfo,activation_x2900 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2900 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2900 *init(resourceInfo_t *resourceInfo,activation_x2900 *__act,int32_t x504,bool isEmpty) {
activation_x2900 * __act2 = new activation_x2900();;
__act2->x2900_zero = __act->x2900_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x2900 = __act2->x2900_zero;
if (!isEmpty) {
bool x2898 = x2896->apply(x504);
__act2->x2900 = x2898;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x2900 *__act,int32_t x504) {
bool x2898 = x2896->apply(x504);
bool x509 = __act->x2900;
bool x510 = x2898;
bool  x511 = x509 && x510;
__act->x2900 = x511;
}

void combine(resourceInfo_t *resourceInfo,activation_x2900 *__act,activation_x2900 *rhs) {
bool x509 = __act->x2900;
bool x510 = rhs->x2900;
if (x509 == __act->x2900_zero) {
__act->x2900 = x510;
}
else if (x510 != __act->x2900_zero) {
bool  x511 = x509 && x510;
__act->x2900 = x511;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2900 *__act,activation_x2900 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2900 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2900 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2900 *__act) {
}

activation_x2900 *initAct(resourceInfo_t *resourceInfo) {
activation_x2900 * act = new activation_x2900;
act->x2900_zero = x502;
return act;
}

activation_x2900 *allocVal;
MultiLoopSync<activation_x2900*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2900_class *closure = (x2900_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2900_class *x2900_closure = new x2900_class(x2897,x502,x2896);
x2900_closure->loopStart = 0;
x2900_closure->loopSize = x2897;
activation_x2900 * alloc = x2900_closure->alloc(resourceInfo);
activation_x2900 * x2900 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2900 = x2900_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2900*> * sync = new MultiLoopSync<activation_x2900*>(x2900_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2900_closure->allocVal = alloc;
x2900_closure->syncVal = sync;
submitWork(r->threadId, x2900_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2900_closure)));
i = i+1;
}
x2900 = x2900_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2900;
}

/**********/

