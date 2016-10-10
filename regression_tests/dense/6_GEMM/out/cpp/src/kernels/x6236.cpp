//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6236 * kernel_x6236(resourceInfo_t *resourceInfo,int32_t  x6233, bool  x1093, cppDeliteArraybool  *x6232) {
class x6236_class{
public:
int32_t x6233;
bool x1093;
cppDeliteArraybool *x6232;

x6236_class(int32_t  _x6233,bool  _x1093,cppDeliteArraybool * _x6232) {
x6233 = _x6233;
x1093 = _x1093;
x6232 = _x6232;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6233;
}

int64_t loopStart;
int64_t loopSize;
activation_x6236 *alloc(resourceInfo_t *resourceInfo) {
activation_x6236 * __act = new activation_x6236();;
__act->x6236_zero = x1093;
return __act;
}

activation_x6236 *main_par(resourceInfo_t *resourceInfo,activation_x6236 *__act,MultiLoopSync<activation_x6236*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6236 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6236 * act = sync->get(localStart);
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

activation_x6236 *main_seq(resourceInfo_t *resourceInfo,activation_x6236 *__act) {
activation_x6236 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6236 *processRange(resourceInfo_t *resourceInfo,activation_x6236 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6236 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6236 *init(resourceInfo_t *resourceInfo,activation_x6236 *__act,int32_t x1095,bool isEmpty) {
activation_x6236 * __act2 = new activation_x6236();;
__act2->x6236_zero = __act->x6236_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x6236 = __act2->x6236_zero;
if (!isEmpty) {
bool x6234 = x6232->apply(x1095);
__act2->x6236 = x6234;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x6236 *__act,int32_t x1095) {
bool x6234 = x6232->apply(x1095);
bool x1100 = __act->x6236;
bool x1101 = x6234;
bool  x1102 = x1100 && x1101;
__act->x6236 = x1102;
}

void combine(resourceInfo_t *resourceInfo,activation_x6236 *__act,activation_x6236 *rhs) {
bool x1100 = __act->x6236;
bool x1101 = rhs->x6236;
if (x1100 == __act->x6236_zero) {
__act->x6236 = x1101;
}
else if (x1101 != __act->x6236_zero) {
bool  x1102 = x1100 && x1101;
__act->x6236 = x1102;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6236 *__act,activation_x6236 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6236 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6236 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6236 *__act) {
}

activation_x6236 *initAct(resourceInfo_t *resourceInfo) {
activation_x6236 * act = new activation_x6236;
act->x6236_zero = x1093;
return act;
}

activation_x6236 *allocVal;
MultiLoopSync<activation_x6236*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6236_class *closure = (x6236_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6236_class *x6236_closure = new x6236_class(x6233,x1093,x6232);
x6236_closure->loopStart = 0;
x6236_closure->loopSize = x6233;
activation_x6236 * alloc = x6236_closure->alloc(resourceInfo);
activation_x6236 * x6236 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6236 = x6236_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6236*> * sync = new MultiLoopSync<activation_x6236*>(x6236_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6236_closure->allocVal = alloc;
x6236_closure->syncVal = sync;
submitWork(r->threadId, x6236_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6236_closure)));
i = i+1;
}
x6236 = x6236_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6236;
}

/**********/

