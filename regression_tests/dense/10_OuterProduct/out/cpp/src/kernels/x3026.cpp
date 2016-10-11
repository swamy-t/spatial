//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3026 * kernel_x3026(resourceInfo_t *resourceInfo,int32_t  x2987, cppDeliteArrayint32_t  *x2825) {
class x3026_class{
public:
int32_t x2987;
cppDeliteArrayint32_t *x2825;

x3026_class(int32_t  _x2987,cppDeliteArrayint32_t * _x2825) {
x2987 = _x2987;
x2825 = _x2825;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x2987;
}

int64_t loopStart;
int64_t loopSize;
activation_x3026 *alloc(resourceInfo_t *resourceInfo) {
activation_x3026 * __act = new activation_x3026();;
int32_t x417 = (int32_t)(loopSize);
assert(x417 < (size_t)-1);
cppDeliteArrayint32_t *x2990 = new (resourceInfo) cppDeliteArrayint32_t(x417);
__act->x3026_data = x2990;
return __act;
}

activation_x3026 *main_par(resourceInfo_t *resourceInfo,activation_x3026 *__act,MultiLoopSync<activation_x3026*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3026 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3026 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x3026 *main_seq(resourceInfo_t *resourceInfo,activation_x3026 *__act) {
activation_x3026 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3026 *processRange(resourceInfo_t *resourceInfo,activation_x3026 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3026 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3026 *init(resourceInfo_t *resourceInfo,activation_x3026 *__act,int32_t x412,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x412);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x3026 *__act,int32_t x412) {
int32_t x2988 = x2825->apply(x412);
int32_t x416 = x2988;
cppDeliteArrayint32_t *x415 = __act->x3026_data;
x415->update(x412, x416);
}

void combine(resourceInfo_t *resourceInfo,activation_x3026 *__act,activation_x3026 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3026 *__act,activation_x3026 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3026 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3026 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3026 *__act) {
cppDeliteArrayint32_t * x415 = __act->x3026_data;
__act->x3026 = x415;
}

activation_x3026 *initAct(resourceInfo_t *resourceInfo) {
activation_x3026 * act = new activation_x3026;
return act;
}

activation_x3026 *allocVal;
MultiLoopSync<activation_x3026*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3026_class *closure = (x3026_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3026_class *x3026_closure = new x3026_class(x2987,x2825);
x3026_closure->loopStart = 0;
x3026_closure->loopSize = x2987;
activation_x3026 * alloc = x3026_closure->alloc(resourceInfo);
activation_x3026 * x3026 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3026 = x3026_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3026*> * sync = new MultiLoopSync<activation_x3026*>(x3026_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3026_closure->allocVal = alloc;
x3026_closure->syncVal = sync;
submitWork(r->threadId, x3026_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3026_closure)));
i = i+1;
}
x3026 = x3026_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3026;
}

/**********/

