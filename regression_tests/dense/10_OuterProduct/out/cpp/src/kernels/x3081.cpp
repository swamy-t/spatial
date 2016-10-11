//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3081 * kernel_x3081(resourceInfo_t *resourceInfo,int32_t  x2987, cppDeliteArrayint32_t  *x2825, cppDeliteArrayint32_t  *x2941) {
class x3081_class{
public:
int32_t x2987;
cppDeliteArrayint32_t *x2825;
cppDeliteArrayint32_t *x2941;

x3081_class(int32_t  _x2987,cppDeliteArrayint32_t * _x2825,cppDeliteArrayint32_t * _x2941) {
x2987 = _x2987;
x2825 = _x2825;
x2941 = _x2941;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x2987;
}

int64_t loopStart;
int64_t loopSize;
activation_x3081 *alloc(resourceInfo_t *resourceInfo) {
activation_x3081 * __act = new activation_x3081();;
int32_t x487 = (int32_t)(loopSize);
assert(x487 < (size_t)-1);
cppDeliteArraybool *x3045 = new (resourceInfo) cppDeliteArraybool(x487);
__act->x3081_data = x3045;
return __act;
}

activation_x3081 *main_par(resourceInfo_t *resourceInfo,activation_x3081 *__act,MultiLoopSync<activation_x3081*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3081 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3081 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x3081 *main_seq(resourceInfo_t *resourceInfo,activation_x3081 *__act) {
activation_x3081 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3081 *processRange(resourceInfo_t *resourceInfo,activation_x3081 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3081 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3081 *init(resourceInfo_t *resourceInfo,activation_x3081 *__act,int32_t x480,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x480);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x3081 *__act,int32_t x480) {
int32_t x3041 = x2825->apply(x480);
int32_t x3042 = x2941->apply(x480);
bool  x3043 = x3041 == x3042;
bool x486 = x3043;
cppDeliteArraybool *x485 = __act->x3081_data;
x485->update(x480, x486);
}

void combine(resourceInfo_t *resourceInfo,activation_x3081 *__act,activation_x3081 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3081 *__act,activation_x3081 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3081 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3081 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3081 *__act) {
cppDeliteArraybool * x485 = __act->x3081_data;
__act->x3081 = x485;
}

activation_x3081 *initAct(resourceInfo_t *resourceInfo) {
activation_x3081 * act = new activation_x3081;
return act;
}

activation_x3081 *allocVal;
MultiLoopSync<activation_x3081*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3081_class *closure = (x3081_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3081_class *x3081_closure = new x3081_class(x2987,x2825,x2941);
x3081_closure->loopStart = 0;
x3081_closure->loopSize = x2987;
activation_x3081 * alloc = x3081_closure->alloc(resourceInfo);
activation_x3081 * x3081 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3081 = x3081_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3081*> * sync = new MultiLoopSync<activation_x3081*>(x3081_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3081_closure->allocVal = alloc;
x3081_closure->syncVal = sync;
submitWork(r->threadId, x3081_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3081_closure)));
i = i+1;
}
x3081 = x3081_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3081;
}

/**********/

