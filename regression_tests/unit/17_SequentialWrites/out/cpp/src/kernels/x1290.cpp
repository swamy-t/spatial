//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1290 * kernel_x1290(resourceInfo_t *resourceInfo,int32_t  x4) {
class x1290_class{
public:
int32_t x4;

x1290_class(int32_t  _x4) {
x4 = _x4;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x4;
}

int64_t loopStart;
int64_t loopSize;
activation_x1290 *alloc(resourceInfo_t *resourceInfo) {
activation_x1290 * __act = new activation_x1290();;
int32_t x9 = (int32_t)(loopSize);
assert(x9 < (size_t)-1);
cppDeliteArrayint32_t *x1254 = new (resourceInfo) cppDeliteArrayint32_t(x9);
__act->x1290_data = x1254;
return __act;
}

activation_x1290 *main_par(resourceInfo_t *resourceInfo,activation_x1290 *__act,MultiLoopSync<activation_x1290*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1290 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1290 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1290 *main_seq(resourceInfo_t *resourceInfo,activation_x1290 *__act) {
activation_x1290 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1290 *processRange(resourceInfo_t *resourceInfo,activation_x1290 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1290 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1290 *init(resourceInfo_t *resourceInfo,activation_x1290 *__act,int32_t x5,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x5);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1290 *__act,int32_t x5) {
int32_t  x6 = (int32_t) (x5);
int32_t x8 = x6;
cppDeliteArrayint32_t *x7 = __act->x1290_data;
x7->update(x5, x8);
}

void combine(resourceInfo_t *resourceInfo,activation_x1290 *__act,activation_x1290 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1290 *__act,activation_x1290 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1290 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1290 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1290 *__act) {
cppDeliteArrayint32_t * x7 = __act->x1290_data;
__act->x1290 = x7;
}

activation_x1290 *initAct(resourceInfo_t *resourceInfo) {
activation_x1290 * act = new activation_x1290;
return act;
}

activation_x1290 *allocVal;
MultiLoopSync<activation_x1290*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1290_class *closure = (x1290_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1290_class *x1290_closure = new x1290_class(x4);
x1290_closure->loopStart = 0;
x1290_closure->loopSize = x4;
activation_x1290 * alloc = x1290_closure->alloc(resourceInfo);
activation_x1290 * x1290 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1290 = x1290_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1290*> * sync = new MultiLoopSync<activation_x1290*>(x1290_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1290_closure->allocVal = alloc;
x1290_closure->syncVal = sync;
submitWork(r->threadId, x1290_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1290_closure)));
i = i+1;
}
x1290 = x1290_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1290;
}

/**********/

