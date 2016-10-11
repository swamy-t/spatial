//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1346 * kernel_x1346(resourceInfo_t *resourceInfo,int32_t  x118, int32_t  x121, int32_t  x126) {
class x1346_class{
public:
int32_t x118;
int32_t x121;
int32_t x126;

x1346_class(int32_t  _x118,int32_t  _x121,int32_t  _x126) {
x118 = _x118;
x121 = _x121;
x126 = _x126;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x118;
}

int64_t loopStart;
int64_t loopSize;
activation_x1346 *alloc(resourceInfo_t *resourceInfo) {
activation_x1346 * __act = new activation_x1346();;
int32_t x133 = (int32_t)(loopSize);
assert(x133 < (size_t)-1);
cppDeliteArrayint32_t *x1310 = new (resourceInfo) cppDeliteArrayint32_t(x133);
__act->x1346_data = x1310;
return __act;
}

activation_x1346 *main_par(resourceInfo_t *resourceInfo,activation_x1346 *__act,MultiLoopSync<activation_x1346*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1346 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1346 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1346 *main_seq(resourceInfo_t *resourceInfo,activation_x1346 *__act) {
activation_x1346 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1346 *processRange(resourceInfo_t *resourceInfo,activation_x1346 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1346 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1346 *init(resourceInfo_t *resourceInfo,activation_x1346 *__act,int32_t x127,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x127);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1346 *__act,int32_t x127) {
int32_t  x128 = (int32_t) (x127);
int32_t  x129 = x128 * x121;
int32_t  x130 = x126 + x129;
int32_t x132 = x130;
cppDeliteArrayint32_t *x131 = __act->x1346_data;
x131->update(x127, x132);
}

void combine(resourceInfo_t *resourceInfo,activation_x1346 *__act,activation_x1346 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1346 *__act,activation_x1346 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1346 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1346 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1346 *__act) {
cppDeliteArrayint32_t * x131 = __act->x1346_data;
__act->x1346 = x131;
}

activation_x1346 *initAct(resourceInfo_t *resourceInfo) {
activation_x1346 * act = new activation_x1346;
return act;
}

activation_x1346 *allocVal;
MultiLoopSync<activation_x1346*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1346_class *closure = (x1346_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1346_class *x1346_closure = new x1346_class(x118,x121,x126);
x1346_closure->loopStart = 0;
x1346_closure->loopSize = x118;
activation_x1346 * alloc = x1346_closure->alloc(resourceInfo);
activation_x1346 * x1346 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1346 = x1346_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1346*> * sync = new MultiLoopSync<activation_x1346*>(x1346_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1346_closure->allocVal = alloc;
x1346_closure->syncVal = sync;
submitWork(r->threadId, x1346_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1346_closure)));
i = i+1;
}
x1346 = x1346_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1346;
}

/**********/

