//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1136 * kernel_x1136(resourceInfo_t *resourceInfo,int32_t  x2, cppDeliteArrayint32_t  *x1076) {
class x1136_class{
public:
int32_t x2;
cppDeliteArrayint32_t *x1076;

x1136_class(int32_t  _x2,cppDeliteArrayint32_t * _x1076) {
x2 = _x2;
x1076 = _x1076;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x2;
}

int64_t loopStart;
int64_t loopSize;
activation_x1136 *alloc(resourceInfo_t *resourceInfo) {
activation_x1136 * __act = new activation_x1136();;
int32_t x86 = (int32_t)(loopSize);
assert(x86 < (size_t)-1);
cppDeliteArrayint32_t *x1100 = new (resourceInfo) cppDeliteArrayint32_t(x86);
__act->x1136_data = x1100;
return __act;
}

activation_x1136 *main_par(resourceInfo_t *resourceInfo,activation_x1136 *__act,MultiLoopSync<activation_x1136*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1136 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1136 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1136 *main_seq(resourceInfo_t *resourceInfo,activation_x1136 *__act) {
activation_x1136 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1136 *processRange(resourceInfo_t *resourceInfo,activation_x1136 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1136 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1136 *init(resourceInfo_t *resourceInfo,activation_x1136 *__act,int32_t x82,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x82);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1136 *__act,int32_t x82) {
int32_t x1099 = x1076->apply(x82);
int32_t x85 = x1099;
cppDeliteArrayint32_t *x84 = __act->x1136_data;
x84->update(x82, x85);
}

void combine(resourceInfo_t *resourceInfo,activation_x1136 *__act,activation_x1136 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1136 *__act,activation_x1136 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1136 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1136 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1136 *__act) {
cppDeliteArrayint32_t * x84 = __act->x1136_data;
__act->x1136 = x84;
}

activation_x1136 *initAct(resourceInfo_t *resourceInfo) {
activation_x1136 * act = new activation_x1136;
return act;
}

activation_x1136 *allocVal;
MultiLoopSync<activation_x1136*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1136_class *closure = (x1136_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1136_class *x1136_closure = new x1136_class(x2,x1076);
x1136_closure->loopStart = 0;
x1136_closure->loopSize = x2;
activation_x1136 * alloc = x1136_closure->alloc(resourceInfo);
activation_x1136 * x1136 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1136 = x1136_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1136*> * sync = new MultiLoopSync<activation_x1136*>(x1136_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1136_closure->allocVal = alloc;
x1136_closure->syncVal = sync;
submitWork(r->threadId, x1136_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1136_closure)));
i = i+1;
}
x1136 = x1136_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1136;
}

/**********/

