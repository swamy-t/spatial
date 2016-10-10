//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6265 * kernel_x6265(resourceInfo_t *resourceInfo,int32_t  x6262, bool  x1065, cppDeliteArraybool  *x6261) {
class x6265_class{
public:
int32_t x6262;
bool x1065;
cppDeliteArraybool *x6261;

x6265_class(int32_t  _x6262,bool  _x1065,cppDeliteArraybool * _x6261) {
x6262 = _x6262;
x1065 = _x1065;
x6261 = _x6261;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6262;
}

int64_t loopStart;
int64_t loopSize;
activation_x6265 *alloc(resourceInfo_t *resourceInfo) {
activation_x6265 * __act = new activation_x6265();;
__act->x6265_zero = x1065;
return __act;
}

activation_x6265 *main_par(resourceInfo_t *resourceInfo,activation_x6265 *__act,MultiLoopSync<activation_x6265*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6265 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6265 * act = sync->get(localStart);
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

activation_x6265 *main_seq(resourceInfo_t *resourceInfo,activation_x6265 *__act) {
activation_x6265 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6265 *processRange(resourceInfo_t *resourceInfo,activation_x6265 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6265 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6265 *init(resourceInfo_t *resourceInfo,activation_x6265 *__act,int32_t x1067,bool isEmpty) {
activation_x6265 * __act2 = new activation_x6265();;
__act2->x6265_zero = __act->x6265_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x6265 = __act2->x6265_zero;
if (!isEmpty) {
bool x6263 = x6261->apply(x1067);
__act2->x6265 = x6263;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x6265 *__act,int32_t x1067) {
bool x6263 = x6261->apply(x1067);
bool x1072 = __act->x6265;
bool x1073 = x6263;
bool  x1074 = x1072 && x1073;
__act->x6265 = x1074;
}

void combine(resourceInfo_t *resourceInfo,activation_x6265 *__act,activation_x6265 *rhs) {
bool x1072 = __act->x6265;
bool x1073 = rhs->x6265;
if (x1072 == __act->x6265_zero) {
__act->x6265 = x1073;
}
else if (x1073 != __act->x6265_zero) {
bool  x1074 = x1072 && x1073;
__act->x6265 = x1074;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6265 *__act,activation_x6265 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6265 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6265 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6265 *__act) {
}

activation_x6265 *initAct(resourceInfo_t *resourceInfo) {
activation_x6265 * act = new activation_x6265;
act->x6265_zero = x1065;
return act;
}

activation_x6265 *allocVal;
MultiLoopSync<activation_x6265*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6265_class *closure = (x6265_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6265_class *x6265_closure = new x6265_class(x6262,x1065,x6261);
x6265_closure->loopStart = 0;
x6265_closure->loopSize = x6262;
activation_x6265 * alloc = x6265_closure->alloc(resourceInfo);
activation_x6265 * x6265 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6265 = x6265_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6265*> * sync = new MultiLoopSync<activation_x6265*>(x6265_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6265_closure->allocVal = alloc;
x6265_closure->syncVal = sync;
submitWork(r->threadId, x6265_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6265_closure)));
i = i+1;
}
x6265 = x6265_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6265;
}

/**********/

