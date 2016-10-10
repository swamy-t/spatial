//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1875x2125 * kernel_x1875x2125(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x51) {
class x1875x2125_class{
public:
int32_t x3;
int32_t x51;

x1875x2125_class(int32_t  _x3,int32_t  _x51) {
x3 = _x3;
x51 = _x51;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x1875x2125 *alloc(resourceInfo_t *resourceInfo) {
activation_x1875x2125 * __act = new activation_x1875x2125();;
int32_t x8 = (int32_t)(loopSize);
assert(x8 < (size_t)-1);
cppDeliteArrayint32_t *x1839 = new (resourceInfo) cppDeliteArrayint32_t(x8);
__act->x1875_data = x1839;
int32_t x55 = (int32_t)(loopSize);
assert(x55 < (size_t)-1);
cppDeliteArrayint32_t *x1877 = new (resourceInfo) cppDeliteArrayint32_t(x55);
__act->x2125_data = x1877;
return __act;
}

activation_x1875x2125 *main_par(resourceInfo_t *resourceInfo,activation_x1875x2125 *__act,MultiLoopSync<activation_x1875x2125*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1875x2125 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1875x2125 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1875x2125 *main_seq(resourceInfo_t *resourceInfo,activation_x1875x2125 *__act) {
activation_x1875x2125 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1875x2125 *processRange(resourceInfo_t *resourceInfo,activation_x1875x2125 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1875x2125 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1875x2125 *init(resourceInfo_t *resourceInfo,activation_x1875x2125 *__act,int32_t x4,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x4);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1875x2125 *__act,int32_t x4) {
int32_t  x5 = (int32_t) (x4);
int32_t  x2122 = x5 * x51;
int32_t x7 = x5;
cppDeliteArrayint32_t *x6 = __act->x1875_data;
x6->update(x4, x7);
int32_t x54 = x2122;
cppDeliteArrayint32_t *x53 = __act->x2125_data;
x53->update(x4, x54);
}

void combine(resourceInfo_t *resourceInfo,activation_x1875x2125 *__act,activation_x1875x2125 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1875x2125 *__act,activation_x1875x2125 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1875x2125 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1875x2125 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1875x2125 *__act) {
cppDeliteArrayint32_t * x6 = __act->x1875_data;
__act->x1875 = x6;
cppDeliteArrayint32_t * x53 = __act->x2125_data;
__act->x2125 = x53;
}

activation_x1875x2125 *initAct(resourceInfo_t *resourceInfo) {
activation_x1875x2125 * act = new activation_x1875x2125;
return act;
}

activation_x1875x2125 *allocVal;
MultiLoopSync<activation_x1875x2125*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1875x2125_class *closure = (x1875x2125_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1875x2125_class *x1875x2125_closure = new x1875x2125_class(x3,x51);
x1875x2125_closure->loopStart = 0;
x1875x2125_closure->loopSize = x3;
activation_x1875x2125 * alloc = x1875x2125_closure->alloc(resourceInfo);
activation_x1875x2125 * x1875x2125 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1875x2125 = x1875x2125_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1875x2125*> * sync = new MultiLoopSync<activation_x1875x2125*>(x1875x2125_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1875x2125_closure->allocVal = alloc;
x1875x2125_closure->syncVal = sync;
submitWork(r->threadId, x1875x2125_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1875x2125_closure)));
i = i+1;
}
x1875x2125 = x1875x2125_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1875x2125;
}

/**********/

