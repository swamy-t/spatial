//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3803 * kernel_x3803(resourceInfo_t *resourceInfo,int32_t  x3755, cppDeliteArrayint32_t  *x3514, cppDeliteArrayint32_t  *x3745) {
class x3803_class{
public:
int32_t x3755;
cppDeliteArrayint32_t *x3514;
cppDeliteArrayint32_t *x3745;

x3803_class(int32_t  _x3755,cppDeliteArrayint32_t * _x3514,cppDeliteArrayint32_t * _x3745) {
x3755 = _x3755;
x3514 = _x3514;
x3745 = _x3745;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3755;
}

int64_t loopStart;
int64_t loopSize;
activation_x3803 *alloc(resourceInfo_t *resourceInfo) {
activation_x3803 * __act = new activation_x3803();;
int32_t x824 = (int32_t)(loopSize);
assert(x824 < (size_t)-1);
cppDeliteArraybool *x3767 = new (resourceInfo) cppDeliteArraybool(x824);
__act->x3803_data = x3767;
return __act;
}

activation_x3803 *main_par(resourceInfo_t *resourceInfo,activation_x3803 *__act,MultiLoopSync<activation_x3803*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3803 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3803 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x3803 *main_seq(resourceInfo_t *resourceInfo,activation_x3803 *__act) {
activation_x3803 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3803 *processRange(resourceInfo_t *resourceInfo,activation_x3803 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3803 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3803 *init(resourceInfo_t *resourceInfo,activation_x3803 *__act,int32_t x817,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x817);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x3803 *__act,int32_t x817) {
int32_t x3763 = x3514->apply(x817);
int32_t x3764 = x3745->apply(x817);
bool  x3765 = x3763 == x3764;
bool x823 = x3765;
cppDeliteArraybool *x822 = __act->x3803_data;
x822->update(x817, x823);
}

void combine(resourceInfo_t *resourceInfo,activation_x3803 *__act,activation_x3803 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3803 *__act,activation_x3803 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3803 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3803 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3803 *__act) {
cppDeliteArraybool * x822 = __act->x3803_data;
__act->x3803 = x822;
}

activation_x3803 *initAct(resourceInfo_t *resourceInfo) {
activation_x3803 * act = new activation_x3803;
return act;
}

activation_x3803 *allocVal;
MultiLoopSync<activation_x3803*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3803_class *closure = (x3803_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3803_class *x3803_closure = new x3803_class(x3755,x3514,x3745);
x3803_closure->loopStart = 0;
x3803_closure->loopSize = x3755;
activation_x3803 * alloc = x3803_closure->alloc(resourceInfo);
activation_x3803 * x3803 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3803 = x3803_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3803*> * sync = new MultiLoopSync<activation_x3803*>(x3803_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3803_closure->allocVal = alloc;
x3803_closure->syncVal = sync;
submitWork(r->threadId, x3803_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3803_closure)));
i = i+1;
}
x3803 = x3803_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3803;
}

/**********/

