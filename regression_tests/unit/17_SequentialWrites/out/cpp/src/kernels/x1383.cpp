//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1383 * kernel_x1383(resourceInfo_t *resourceInfo,int32_t  x4, int32_t  x132, int32_t  x129) {
class x1383_class{
public:
int32_t x4;
int32_t x132;
int32_t x129;

x1383_class(int32_t  _x4,int32_t  _x132,int32_t  _x129) {
x4 = _x4;
x132 = _x132;
x129 = _x129;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x4;
}

int64_t loopStart;
int64_t loopSize;
activation_x1383 *alloc(resourceInfo_t *resourceInfo) {
activation_x1383 * __act = new activation_x1383();;
int32_t x137 = (int32_t)(loopSize);
assert(x137 < (size_t)-1);
cppDeliteArrayint32_t *x1347 = new (resourceInfo) cppDeliteArrayint32_t(x137);
__act->x1383_data = x1347;
return __act;
}

activation_x1383 *main_par(resourceInfo_t *resourceInfo,activation_x1383 *__act,MultiLoopSync<activation_x1383*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1383 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1383 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1383 *main_seq(resourceInfo_t *resourceInfo,activation_x1383 *__act) {
activation_x1383 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1383 *processRange(resourceInfo_t *resourceInfo,activation_x1383 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1383 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1383 *init(resourceInfo_t *resourceInfo,activation_x1383 *__act,int32_t x130,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x130);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1383 *__act,int32_t x130) {
int32_t  x131 = (int32_t) (x130);
int32_t  x133 = x131 * x132;
int32_t  x134 = x129 + x133;
int32_t x136 = x134;
cppDeliteArrayint32_t *x135 = __act->x1383_data;
x135->update(x130, x136);
}

void combine(resourceInfo_t *resourceInfo,activation_x1383 *__act,activation_x1383 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1383 *__act,activation_x1383 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1383 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1383 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1383 *__act) {
cppDeliteArrayint32_t * x135 = __act->x1383_data;
__act->x1383 = x135;
}

activation_x1383 *initAct(resourceInfo_t *resourceInfo) {
activation_x1383 * act = new activation_x1383;
return act;
}

activation_x1383 *allocVal;
MultiLoopSync<activation_x1383*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1383_class *closure = (x1383_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1383_class *x1383_closure = new x1383_class(x4,x132,x129);
x1383_closure->loopStart = 0;
x1383_closure->loopSize = x4;
activation_x1383 * alloc = x1383_closure->alloc(resourceInfo);
activation_x1383 * x1383 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1383 = x1383_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1383*> * sync = new MultiLoopSync<activation_x1383*>(x1383_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1383_closure->allocVal = alloc;
x1383_closure->syncVal = sync;
submitWork(r->threadId, x1383_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1383_closure)));
i = i+1;
}
x1383 = x1383_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1383;
}

/**********/

