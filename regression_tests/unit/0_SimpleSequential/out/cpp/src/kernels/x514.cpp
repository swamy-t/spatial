//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x514 * kernel_x514(resourceInfo_t *resourceInfo,int32_t  x34, int32_t  x2) {
class x514_class{
public:
int32_t x34;
int32_t x2;

x514_class(int32_t  _x34,int32_t  _x2) {
x34 = _x34;
x2 = _x2;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x34;
}

int64_t loopStart;
int64_t loopSize;
activation_x514 *alloc(resourceInfo_t *resourceInfo) {
activation_x514 * __act = new activation_x514();;
int32_t x40 = (int32_t)(loopSize);
assert(x40 < (size_t)-1);
cppDeliteArrayint32_t *x478 = new (resourceInfo) cppDeliteArrayint32_t(x40);
__act->x514_data = x478;
return __act;
}

activation_x514 *main_par(resourceInfo_t *resourceInfo,activation_x514 *__act,MultiLoopSync<activation_x514*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x514 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x514 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x514 *main_seq(resourceInfo_t *resourceInfo,activation_x514 *__act) {
activation_x514 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x514 *processRange(resourceInfo_t *resourceInfo,activation_x514 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x514 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x514 *init(resourceInfo_t *resourceInfo,activation_x514 *__act,int32_t x35,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x35);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x514 *__act,int32_t x35) {
int32_t  x36 = (int32_t) (x35);
int32_t  x37 = x2 * x36;
int32_t x39 = x37;
cppDeliteArrayint32_t *x38 = __act->x514_data;
x38->update(x35, x39);
}

void combine(resourceInfo_t *resourceInfo,activation_x514 *__act,activation_x514 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x514 *__act,activation_x514 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x514 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x514 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x514 *__act) {
cppDeliteArrayint32_t * x38 = __act->x514_data;
__act->x514 = x38;
}

activation_x514 *initAct(resourceInfo_t *resourceInfo) {
activation_x514 * act = new activation_x514;
return act;
}

activation_x514 *allocVal;
MultiLoopSync<activation_x514*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x514_class *closure = (x514_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x514_class *x514_closure = new x514_class(x34,x2);
x514_closure->loopStart = 0;
x514_closure->loopSize = x34;
activation_x514 * alloc = x514_closure->alloc(resourceInfo);
activation_x514 * x514 = NULL;
if (resourceInfo->availableThreads <= 1) {
x514 = x514_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x514*> * sync = new MultiLoopSync<activation_x514*>(x514_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x514_closure->allocVal = alloc;
x514_closure->syncVal = sync;
submitWork(r->threadId, x514_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x514_closure)));
i = i+1;
}
x514 = x514_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x514;
}

/**********/

