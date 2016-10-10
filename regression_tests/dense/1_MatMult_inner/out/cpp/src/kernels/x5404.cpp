//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5404 * kernel_x5404(resourceInfo_t *resourceInfo,int32_t  x5400, cppDeliteArrayint32_t  *x5399) {
class x5404_class{
public:
int32_t x5400;
cppDeliteArrayint32_t *x5399;

x5404_class(int32_t  _x5400,cppDeliteArrayint32_t * _x5399) {
x5400 = _x5400;
x5399 = _x5399;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x5400;
}

int64_t loopStart;
int64_t loopSize;
activation_x5404 *alloc(resourceInfo_t *resourceInfo) {
activation_x5404 * __act = new activation_x5404();;
int32_t x718 = (int32_t)(loopSize);
assert(x718 < (size_t)-1);
cppDeliteArrayint32_t *x5236 = new (resourceInfo) cppDeliteArrayint32_t(x718);
__act->x5404_data = x5236;
return __act;
}

activation_x5404 *main_par(resourceInfo_t *resourceInfo,activation_x5404 *__act,MultiLoopSync<activation_x5404*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5404 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5404 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x5404 *main_seq(resourceInfo_t *resourceInfo,activation_x5404 *__act) {
activation_x5404 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x5404 *processRange(resourceInfo_t *resourceInfo,activation_x5404 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5404 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5404 *init(resourceInfo_t *resourceInfo,activation_x5404 *__act,int32_t x714,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x714);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x5404 *__act,int32_t x714) {
int32_t x5401 = x5399->apply(x714);
int32_t x717 = x5401;
cppDeliteArrayint32_t *x716 = __act->x5404_data;
x716->update(x714, x717);
}

void combine(resourceInfo_t *resourceInfo,activation_x5404 *__act,activation_x5404 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5404 *__act,activation_x5404 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5404 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5404 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x5404 *__act) {
cppDeliteArrayint32_t * x716 = __act->x5404_data;
__act->x5404 = x716;
}

activation_x5404 *initAct(resourceInfo_t *resourceInfo) {
activation_x5404 * act = new activation_x5404;
return act;
}

activation_x5404 *allocVal;
MultiLoopSync<activation_x5404*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5404_class *closure = (x5404_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5404_class *x5404_closure = new x5404_class(x5400,x5399);
x5404_closure->loopStart = 0;
x5404_closure->loopSize = x5400;
activation_x5404 * alloc = x5404_closure->alloc(resourceInfo);
activation_x5404 * x5404 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5404 = x5404_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5404*> * sync = new MultiLoopSync<activation_x5404*>(x5404_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5404_closure->allocVal = alloc;
x5404_closure->syncVal = sync;
submitWork(r->threadId, x5404_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5404_closure)));
i = i+1;
}
x5404 = x5404_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5404;
}

/**********/

