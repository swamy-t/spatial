//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x4533 * kernel_x4533(resourceInfo_t *resourceInfo,int32_t  x6) {
class x4533_class{
public:
int32_t x6;

x4533_class(int32_t  _x6) {
x6 = _x6;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6;
}

int64_t loopStart;
int64_t loopSize;
activation_x4533 *alloc(resourceInfo_t *resourceInfo) {
activation_x4533 * __act = new activation_x4533();;
int32_t x149 = (int32_t)(loopSize);
assert(x149 < (size_t)-1);
cppDeliteArrayint32_t *x4497 = new (resourceInfo) cppDeliteArrayint32_t(x149);
__act->x4533_data = x4497;
return __act;
}

activation_x4533 *main_par(resourceInfo_t *resourceInfo,activation_x4533 *__act,MultiLoopSync<activation_x4533*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4533 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4533 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4533 *main_seq(resourceInfo_t *resourceInfo,activation_x4533 *__act) {
activation_x4533 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4533 *processRange(resourceInfo_t *resourceInfo,activation_x4533 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4533 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4533 *init(resourceInfo_t *resourceInfo,activation_x4533 *__act,int32_t x145,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x145);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4533 *__act,int32_t x145) {
int32_t  x146 = (int32_t) (x145);
int32_t x148 = x146;
cppDeliteArrayint32_t *x147 = __act->x4533_data;
x147->update(x145, x148);
}

void combine(resourceInfo_t *resourceInfo,activation_x4533 *__act,activation_x4533 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4533 *__act,activation_x4533 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4533 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4533 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4533 *__act) {
cppDeliteArrayint32_t * x147 = __act->x4533_data;
__act->x4533 = x147;
}

activation_x4533 *initAct(resourceInfo_t *resourceInfo) {
activation_x4533 * act = new activation_x4533;
return act;
}

activation_x4533 *allocVal;
MultiLoopSync<activation_x4533*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4533_class *closure = (x4533_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4533_class *x4533_closure = new x4533_class(x6);
x4533_closure->loopStart = 0;
x4533_closure->loopSize = x6;
activation_x4533 * alloc = x4533_closure->alloc(resourceInfo);
activation_x4533 * x4533 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4533 = x4533_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4533*> * sync = new MultiLoopSync<activation_x4533*>(x4533_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4533_closure->allocVal = alloc;
x4533_closure->syncVal = sync;
submitWork(r->threadId, x4533_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4533_closure)));
i = i+1;
}
x4533 = x4533_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4533;
}

/**********/

