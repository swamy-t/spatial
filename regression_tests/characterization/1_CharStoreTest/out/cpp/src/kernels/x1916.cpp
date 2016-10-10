//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1916 * kernel_x1916(resourceInfo_t *resourceInfo,int32_t  x6, int32_t  x4) {
class x1916_class{
public:
int32_t x6;
int32_t x4;

x1916_class(int32_t  _x6,int32_t  _x4) {
x6 = _x6;
x4 = _x4;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6;
}

int64_t loopStart;
int64_t loopSize;
activation_x1916 *alloc(resourceInfo_t *resourceInfo) {
activation_x1916 * __act = new activation_x1916();;
int32_t x12 = (int32_t)(loopSize);
assert(x12 < (size_t)-1);
cppDeliteArrayint32_t *x1880 = new (resourceInfo) cppDeliteArrayint32_t(x12);
__act->x1916_data = x1880;
return __act;
}

activation_x1916 *main_par(resourceInfo_t *resourceInfo,activation_x1916 *__act,MultiLoopSync<activation_x1916*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1916 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1916 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1916 *main_seq(resourceInfo_t *resourceInfo,activation_x1916 *__act) {
activation_x1916 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1916 *processRange(resourceInfo_t *resourceInfo,activation_x1916 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1916 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1916 *init(resourceInfo_t *resourceInfo,activation_x1916 *__act,int32_t x7,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x7);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1916 *__act,int32_t x7) {
int32_t  x8 = (int32_t) (x7);
int32_t  x9 = x8 + x4;
int32_t x11 = x9;
cppDeliteArrayint32_t *x10 = __act->x1916_data;
x10->update(x7, x11);
}

void combine(resourceInfo_t *resourceInfo,activation_x1916 *__act,activation_x1916 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1916 *__act,activation_x1916 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1916 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1916 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1916 *__act) {
cppDeliteArrayint32_t * x10 = __act->x1916_data;
__act->x1916 = x10;
}

activation_x1916 *initAct(resourceInfo_t *resourceInfo) {
activation_x1916 * act = new activation_x1916;
return act;
}

activation_x1916 *allocVal;
MultiLoopSync<activation_x1916*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1916_class *closure = (x1916_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1916_class *x1916_closure = new x1916_class(x6,x4);
x1916_closure->loopStart = 0;
x1916_closure->loopSize = x6;
activation_x1916 * alloc = x1916_closure->alloc(resourceInfo);
activation_x1916 * x1916 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1916 = x1916_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1916*> * sync = new MultiLoopSync<activation_x1916*>(x1916_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1916_closure->allocVal = alloc;
x1916_closure->syncVal = sync;
submitWork(r->threadId, x1916_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1916_closure)));
i = i+1;
}
x1916 = x1916_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1916;
}

/**********/

