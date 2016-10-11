//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2751 * kernel_x2751(resourceInfo_t *resourceInfo,int32_t  x51, int32_t  x53) {
class x2751_class{
public:
int32_t x51;
int32_t x53;

x2751_class(int32_t  _x51,int32_t  _x53) {
x51 = _x51;
x53 = _x53;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x51;
}

int64_t loopStart;
int64_t loopSize;
activation_x2751 *alloc(resourceInfo_t *resourceInfo) {
activation_x2751 * __act = new activation_x2751();;
int32_t x56 = (int32_t)(loopSize);
assert(x56 < (size_t)-1);
cppDeliteArrayint32_t *x2715 = new (resourceInfo) cppDeliteArrayint32_t(x56);
__act->x2751_data = x2715;
return __act;
}

activation_x2751 *main_par(resourceInfo_t *resourceInfo,activation_x2751 *__act,MultiLoopSync<activation_x2751*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2751 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2751 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2751 *main_seq(resourceInfo_t *resourceInfo,activation_x2751 *__act) {
activation_x2751 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2751 *processRange(resourceInfo_t *resourceInfo,activation_x2751 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2751 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2751 *init(resourceInfo_t *resourceInfo,activation_x2751 *__act,int32_t x52,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x52);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2751 *__act,int32_t x52) {
int32_t x55 = x53;
cppDeliteArrayint32_t *x54 = __act->x2751_data;
x54->update(x52, x55);
}

void combine(resourceInfo_t *resourceInfo,activation_x2751 *__act,activation_x2751 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2751 *__act,activation_x2751 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2751 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2751 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2751 *__act) {
cppDeliteArrayint32_t * x54 = __act->x2751_data;
__act->x2751 = x54;
}

activation_x2751 *initAct(resourceInfo_t *resourceInfo) {
activation_x2751 * act = new activation_x2751;
return act;
}

activation_x2751 *allocVal;
MultiLoopSync<activation_x2751*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2751_class *closure = (x2751_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2751_class *x2751_closure = new x2751_class(x51,x53);
x2751_closure->loopStart = 0;
x2751_closure->loopSize = x51;
activation_x2751 * alloc = x2751_closure->alloc(resourceInfo);
activation_x2751 * x2751 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2751 = x2751_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2751*> * sync = new MultiLoopSync<activation_x2751*>(x2751_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2751_closure->allocVal = alloc;
x2751_closure->syncVal = sync;
submitWork(r->threadId, x2751_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2751_closure)));
i = i+1;
}
x2751 = x2751_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2751;
}

/**********/

