//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x1773 * kernel_x1773(resourceInfo_t *resourceInfo,int32_t  x125, int32_t  x124) {
// a *thin* loop follows: x1773
class x1773_class{
public:
int32_t x125;
int32_t x124;

x1773_class(int32_t  _x125,int32_t  _x124) {
x125 = _x125;
x124 = _x124;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x125;
}

int64_t loopStart;
int64_t loopSize;
activation_x1773 *alloc(resourceInfo_t *resourceInfo) {
activation_x1773 * __act = new activation_x1773();;
int32_t x131 = (int32_t)(loopSize);
assert(x131 < (size_t)-1);
cppDeliteArrayint32_t *x1737 = new (resourceInfo) cppDeliteArrayint32_t(x131);
__act->x1773_data = x1737;
return __act;
}

activation_x1773 *main_par(resourceInfo_t *resourceInfo,activation_x1773 *__act,MultiLoopSync<activation_x1773*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1773 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1773 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1773 *main_seq(resourceInfo_t *resourceInfo,activation_x1773 *__act) {
activation_x1773 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1773 *processRange(resourceInfo_t *resourceInfo,activation_x1773 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1773 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1773 *init(resourceInfo_t *resourceInfo,activation_x1773 *__act,int32_t x126,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x126);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1773 *__act,int32_t x126) {
int32_t  x1735 = (int32_t) rand() % x124;
int32_t x130 = x1735;
cppDeliteArrayint32_t *x129 = __act->x1773_data;
x129->update(x126, x130);
}

void combine(resourceInfo_t *resourceInfo,activation_x1773 *__act,activation_x1773 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1773 *__act,activation_x1773 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1773 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1773 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1773 *__act) {
cppDeliteArrayint32_t * x129 = __act->x1773_data;
__act->x1773 = x129;
}

activation_x1773 *initAct(resourceInfo_t *resourceInfo) {
activation_x1773 * act = new activation_x1773;
return act;
}

activation_x1773 *allocVal;
MultiLoopSync<activation_x1773*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1773_class *closure = (x1773_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1773_class *x1773_closure = new x1773_class(x125,x124);
x1773_closure->loopStart = 0;
x1773_closure->loopSize = x125;
activation_x1773 * alloc = x1773_closure->alloc(resourceInfo);
activation_x1773 * x1773 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1773 = x1773_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1773*> * sync = new MultiLoopSync<activation_x1773*>(x1773_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1773_closure->allocVal = alloc;
x1773_closure->syncVal = sync;
submitWork(r->threadId, x1773_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1773_closure)));
i = i+1;
}
x1773 = x1773_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1773;
}

/**********/

