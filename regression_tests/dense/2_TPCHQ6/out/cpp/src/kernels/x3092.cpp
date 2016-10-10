//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3092 * kernel_x3092(resourceInfo_t *resourceInfo,int32_t  x3, cppDeliteArraybool  *x3043, cppDeliteArrayint32_t  *x2750, cppDeliteArrayint32_t  *x2710, int32_t  x195) {
class x3092_class{
public:
int32_t x3;
cppDeliteArraybool *x3043;
cppDeliteArrayint32_t *x2750;
cppDeliteArrayint32_t *x2710;
int32_t x195;

x3092_class(int32_t  _x3,cppDeliteArraybool * _x3043,cppDeliteArrayint32_t * _x2750,cppDeliteArrayint32_t * _x2710,int32_t  _x195) {
x3 = _x3;
x3043 = _x3043;
x2750 = _x2750;
x2710 = _x2710;
x195 = _x195;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x3092 *alloc(resourceInfo_t *resourceInfo) {
activation_x3092 * __act = new activation_x3092();;
int32_t x423 = (int32_t)(loopSize);
assert(x423 < (size_t)-1);
cppDeliteArrayint32_t *x3056 = new (resourceInfo) cppDeliteArrayint32_t(x423);
__act->x3092_data = x3056;
return __act;
}

activation_x3092 *main_par(resourceInfo_t *resourceInfo,activation_x3092 *__act,MultiLoopSync<activation_x3092*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3092 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3092 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x3092 *main_seq(resourceInfo_t *resourceInfo,activation_x3092 *__act) {
activation_x3092 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3092 *processRange(resourceInfo_t *resourceInfo,activation_x3092 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3092 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3092 *init(resourceInfo_t *resourceInfo,activation_x3092 *__act,int32_t x412,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x412);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x3092 *__act,int32_t x412) {
int32_t  x413 = (int32_t) (x412);
int32_t  x414 = (int32_t) x413;
bool x3050 = x3043->apply(x414);
bool  x3051 = x3050;
int32_t  x3055;
if (x3051) {
int32_t x3052 = x2750->apply(x414);
int32_t x3053 = x2710->apply(x414);
int32_t  x3054 = x3052 * x3053;
x3055 = x3054;
} else {
x3055 = x195;
}
int32_t x422 = x3055;
cppDeliteArrayint32_t *x421 = __act->x3092_data;
x421->update(x412, x422);
}

void combine(resourceInfo_t *resourceInfo,activation_x3092 *__act,activation_x3092 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3092 *__act,activation_x3092 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3092 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3092 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3092 *__act) {
cppDeliteArrayint32_t * x421 = __act->x3092_data;
__act->x3092 = x421;
}

activation_x3092 *initAct(resourceInfo_t *resourceInfo) {
activation_x3092 * act = new activation_x3092;
return act;
}

activation_x3092 *allocVal;
MultiLoopSync<activation_x3092*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3092_class *closure = (x3092_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3092_class *x3092_closure = new x3092_class(x3,x3043,x2750,x2710,x195);
x3092_closure->loopStart = 0;
x3092_closure->loopSize = x3;
activation_x3092 * alloc = x3092_closure->alloc(resourceInfo);
activation_x3092 * x3092 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3092 = x3092_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3092*> * sync = new MultiLoopSync<activation_x3092*>(x3092_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3092_closure->allocVal = alloc;
x3092_closure->syncVal = sync;
submitWork(r->threadId, x3092_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3092_closure)));
i = i+1;
}
x3092 = x3092_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3092;
}

/**********/

