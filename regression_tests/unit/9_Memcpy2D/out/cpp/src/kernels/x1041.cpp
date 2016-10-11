//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1041 * kernel_x1041(resourceInfo_t *resourceInfo,int32_t  x2) {
class x1041_class{
public:
int32_t x2;

x1041_class(int32_t  _x2) {
x2 = _x2;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x2;
}

int64_t loopStart;
int64_t loopSize;
activation_x1041 *alloc(resourceInfo_t *resourceInfo) {
activation_x1041 * __act = new activation_x1041();;
int32_t x7 = (int32_t)(loopSize);
assert(x7 < (size_t)-1);
cppDeliteArrayint32_t *x1005 = new (resourceInfo) cppDeliteArrayint32_t(x7);
__act->x1041_data = x1005;
return __act;
}

activation_x1041 *main_par(resourceInfo_t *resourceInfo,activation_x1041 *__act,MultiLoopSync<activation_x1041*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1041 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1041 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1041 *main_seq(resourceInfo_t *resourceInfo,activation_x1041 *__act) {
activation_x1041 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1041 *processRange(resourceInfo_t *resourceInfo,activation_x1041 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1041 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1041 *init(resourceInfo_t *resourceInfo,activation_x1041 *__act,int32_t x3,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x3);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1041 *__act,int32_t x3) {
int32_t  x4 = (int32_t) (x3);
int32_t x6 = x4;
cppDeliteArrayint32_t *x5 = __act->x1041_data;
x5->update(x3, x6);
}

void combine(resourceInfo_t *resourceInfo,activation_x1041 *__act,activation_x1041 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1041 *__act,activation_x1041 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1041 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1041 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1041 *__act) {
cppDeliteArrayint32_t * x5 = __act->x1041_data;
__act->x1041 = x5;
}

activation_x1041 *initAct(resourceInfo_t *resourceInfo) {
activation_x1041 * act = new activation_x1041;
return act;
}

activation_x1041 *allocVal;
MultiLoopSync<activation_x1041*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1041_class *closure = (x1041_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1041_class *x1041_closure = new x1041_class(x2);
x1041_closure->loopStart = 0;
x1041_closure->loopSize = x2;
activation_x1041 * alloc = x1041_closure->alloc(resourceInfo);
activation_x1041 * x1041 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1041 = x1041_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1041*> * sync = new MultiLoopSync<activation_x1041*>(x1041_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1041_closure->allocVal = alloc;
x1041_closure->syncVal = sync;
submitWork(r->threadId, x1041_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1041_closure)));
i = i+1;
}
x1041 = x1041_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1041;
}

/**********/

