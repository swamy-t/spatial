//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x4666 * kernel_x4666(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArrayint32_t  *x4629) {
class x4666_class{
public:
int32_t x7;
cppDeliteArrayint32_t *x4629;

x4666_class(int32_t  _x7,cppDeliteArrayint32_t * _x4629) {
x7 = _x7;
x4629 = _x4629;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x7;
}

int64_t loopStart;
int64_t loopSize;
activation_x4666 *alloc(resourceInfo_t *resourceInfo) {
activation_x4666 * __act = new activation_x4666();;
int32_t x57 = (int32_t)(loopSize);
assert(x57 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x4630 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x57);
__act->x4666_data = x4630;
return __act;
}

activation_x4666 *main_par(resourceInfo_t *resourceInfo,activation_x4666 *__act,MultiLoopSync<activation_x4666*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4666 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4666 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4666 *main_seq(resourceInfo_t *resourceInfo,activation_x4666 *__act) {
activation_x4666 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4666 *processRange(resourceInfo_t *resourceInfo,activation_x4666 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4666 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4666 *init(resourceInfo_t *resourceInfo,activation_x4666 *__act,int32_t x8,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x8);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4666 *__act,int32_t x8) {
cppDeliteArrayint32_t *x56 = x4629;
cppDeliteArraycppDeliteArrayint32_t *x55 = __act->x4666_data;
x55->update(x8, x56);
}

void combine(resourceInfo_t *resourceInfo,activation_x4666 *__act,activation_x4666 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4666 *__act,activation_x4666 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4666 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4666 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4666 *__act) {
cppDeliteArraycppDeliteArrayint32_t * x55 = __act->x4666_data;
__act->x4666 = x55;
}

activation_x4666 *initAct(resourceInfo_t *resourceInfo) {
activation_x4666 * act = new activation_x4666;
return act;
}

activation_x4666 *allocVal;
MultiLoopSync<activation_x4666*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4666_class *closure = (x4666_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4666_class *x4666_closure = new x4666_class(x7,x4629);
x4666_closure->loopStart = 0;
x4666_closure->loopSize = x7;
activation_x4666 * alloc = x4666_closure->alloc(resourceInfo);
activation_x4666 * x4666 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4666 = x4666_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4666*> * sync = new MultiLoopSync<activation_x4666*>(x4666_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4666_closure->allocVal = alloc;
x4666_closure->syncVal = sync;
submitWork(r->threadId, x4666_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4666_closure)));
i = i+1;
}
x4666 = x4666_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4666;
}

/**********/

