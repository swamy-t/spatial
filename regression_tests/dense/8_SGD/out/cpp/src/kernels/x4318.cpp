//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x4318 * kernel_x4318(resourceInfo_t *resourceInfo,int32_t  x6, int32_t  x9) {
// a *thin* loop follows: x4318
class x4318_class{
public:
int32_t x6;
int32_t x9;

x4318_class(int32_t  _x6,int32_t  _x9) {
x6 = _x6;
x9 = _x9;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6;
}

int64_t loopStart;
int64_t loopSize;
activation_x4318 *alloc(resourceInfo_t *resourceInfo) {
activation_x4318 * __act = new activation_x4318();;
int32_t x104 = (int32_t)(loopSize);
assert(x104 < (size_t)-1);
cppDeliteArrayint32_t *x4282 = new (resourceInfo) cppDeliteArrayint32_t(x104);
__act->x4318_data = x4282;
return __act;
}

activation_x4318 *main_par(resourceInfo_t *resourceInfo,activation_x4318 *__act,MultiLoopSync<activation_x4318*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4318 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4318 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4318 *main_seq(resourceInfo_t *resourceInfo,activation_x4318 *__act) {
activation_x4318 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4318 *processRange(resourceInfo_t *resourceInfo,activation_x4318 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4318 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4318 *init(resourceInfo_t *resourceInfo,activation_x4318 *__act,int32_t x99,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x99);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4318 *__act,int32_t x99) {
int32_t  x4280 = (int32_t) rand() % x9;
int32_t x103 = x4280;
cppDeliteArrayint32_t *x102 = __act->x4318_data;
x102->update(x99, x103);
}

void combine(resourceInfo_t *resourceInfo,activation_x4318 *__act,activation_x4318 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4318 *__act,activation_x4318 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4318 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4318 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4318 *__act) {
cppDeliteArrayint32_t * x102 = __act->x4318_data;
__act->x4318 = x102;
}

activation_x4318 *initAct(resourceInfo_t *resourceInfo) {
activation_x4318 * act = new activation_x4318;
return act;
}

activation_x4318 *allocVal;
MultiLoopSync<activation_x4318*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4318_class *closure = (x4318_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4318_class *x4318_closure = new x4318_class(x6,x9);
x4318_closure->loopStart = 0;
x4318_closure->loopSize = x6;
activation_x4318 * alloc = x4318_closure->alloc(resourceInfo);
activation_x4318 * x4318 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4318 = x4318_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4318*> * sync = new MultiLoopSync<activation_x4318*>(x4318_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4318_closure->allocVal = alloc;
x4318_closure->syncVal = sync;
submitWork(r->threadId, x4318_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4318_closure)));
i = i+1;
}
x4318 = x4318_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4318;
}

/**********/

