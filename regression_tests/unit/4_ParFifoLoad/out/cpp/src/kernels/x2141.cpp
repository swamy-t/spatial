//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2141 * kernel_x2141(resourceInfo_t *resourceInfo,int32_t  x161, cppDeliteArrayint32_t  *x2129, cppDeliteArrayint32_t  *x2136) {
class x2141_class{
public:
int32_t x161;
cppDeliteArrayint32_t *x2129;
cppDeliteArrayint32_t *x2136;

x2141_class(int32_t  _x161,cppDeliteArrayint32_t * _x2129,cppDeliteArrayint32_t * _x2136) {
x161 = _x161;
x2129 = _x2129;
x2136 = _x2136;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x161;
}

int64_t loopStart;
int64_t loopSize;
activation_x2141 *alloc(resourceInfo_t *resourceInfo) {
activation_x2141 * __act = new activation_x2141();;
int32_t x314 = (int32_t)(loopSize);
assert(x314 < (size_t)-1);
cppDeliteArrayint32_t *x2071 = new (resourceInfo) cppDeliteArrayint32_t(x314);
__act->x2141_data = x2071;
return __act;
}

activation_x2141 *main_par(resourceInfo_t *resourceInfo,activation_x2141 *__act,MultiLoopSync<activation_x2141*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2141 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2141 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2141 *main_seq(resourceInfo_t *resourceInfo,activation_x2141 *__act) {
activation_x2141 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2141 *processRange(resourceInfo_t *resourceInfo,activation_x2141 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2141 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2141 *init(resourceInfo_t *resourceInfo,activation_x2141 *__act,int32_t x308,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x308);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2141 *__act,int32_t x308) {
int32_t x2130 = x2129->apply(x308);
int32_t x2137 = x2136->apply(x308);
int32_t  x2138 = x2130 * x2137;
int32_t x313 = x2138;
cppDeliteArrayint32_t *x312 = __act->x2141_data;
x312->update(x308, x313);
}

void combine(resourceInfo_t *resourceInfo,activation_x2141 *__act,activation_x2141 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2141 *__act,activation_x2141 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2141 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2141 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2141 *__act) {
cppDeliteArrayint32_t * x312 = __act->x2141_data;
__act->x2141 = x312;
}

activation_x2141 *initAct(resourceInfo_t *resourceInfo) {
activation_x2141 * act = new activation_x2141;
return act;
}

activation_x2141 *allocVal;
MultiLoopSync<activation_x2141*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2141_class *closure = (x2141_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2141_class *x2141_closure = new x2141_class(x161,x2129,x2136);
x2141_closure->loopStart = 0;
x2141_closure->loopSize = x161;
activation_x2141 * alloc = x2141_closure->alloc(resourceInfo);
activation_x2141 * x2141 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2141 = x2141_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2141*> * sync = new MultiLoopSync<activation_x2141*>(x2141_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2141_closure->allocVal = alloc;
x2141_closure->syncVal = sync;
submitWork(r->threadId, x2141_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2141_closure)));
i = i+1;
}
x2141 = x2141_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2141;
}

/**********/

