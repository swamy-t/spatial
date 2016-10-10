//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2814x3220 * kernel_x2814x3220(resourceInfo_t *resourceInfo,int32_t  x2, int32_t  x50) {
class x2814x3220_class{
public:
int32_t x2;
int32_t x50;

x2814x3220_class(int32_t  _x2,int32_t  _x50) {
x2 = _x2;
x50 = _x50;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x2;
}

int64_t loopStart;
int64_t loopSize;
activation_x2814x3220 *alloc(resourceInfo_t *resourceInfo) {
activation_x2814x3220 * __act = new activation_x2814x3220();;
int32_t x7 = (int32_t)(loopSize);
assert(x7 < (size_t)-1);
cppDeliteArrayint32_t *x2778 = new (resourceInfo) cppDeliteArrayint32_t(x7);
__act->x2814_data = x2778;
int32_t x54 = (int32_t)(loopSize);
assert(x54 < (size_t)-1);
cppDeliteArrayint32_t *x2816 = new (resourceInfo) cppDeliteArrayint32_t(x54);
__act->x3220_data = x2816;
return __act;
}

activation_x2814x3220 *main_par(resourceInfo_t *resourceInfo,activation_x2814x3220 *__act,MultiLoopSync<activation_x2814x3220*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2814x3220 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2814x3220 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2814x3220 *main_seq(resourceInfo_t *resourceInfo,activation_x2814x3220 *__act) {
activation_x2814x3220 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2814x3220 *processRange(resourceInfo_t *resourceInfo,activation_x2814x3220 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2814x3220 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2814x3220 *init(resourceInfo_t *resourceInfo,activation_x2814x3220 *__act,int32_t x3,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x3);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2814x3220 *__act,int32_t x3) {
int32_t  x4 = (int32_t) (x3);
int32_t  x3217 = x4 * x50;
int32_t x6 = x4;
cppDeliteArrayint32_t *x5 = __act->x2814_data;
x5->update(x3, x6);
int32_t x53 = x3217;
cppDeliteArrayint32_t *x52 = __act->x3220_data;
x52->update(x3, x53);
}

void combine(resourceInfo_t *resourceInfo,activation_x2814x3220 *__act,activation_x2814x3220 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2814x3220 *__act,activation_x2814x3220 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2814x3220 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2814x3220 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2814x3220 *__act) {
cppDeliteArrayint32_t * x5 = __act->x2814_data;
__act->x2814 = x5;
cppDeliteArrayint32_t * x52 = __act->x3220_data;
__act->x3220 = x52;
}

activation_x2814x3220 *initAct(resourceInfo_t *resourceInfo) {
activation_x2814x3220 * act = new activation_x2814x3220;
return act;
}

activation_x2814x3220 *allocVal;
MultiLoopSync<activation_x2814x3220*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2814x3220_class *closure = (x2814x3220_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2814x3220_class *x2814x3220_closure = new x2814x3220_class(x2,x50);
x2814x3220_closure->loopStart = 0;
x2814x3220_closure->loopSize = x2;
activation_x2814x3220 * alloc = x2814x3220_closure->alloc(resourceInfo);
activation_x2814x3220 * x2814x3220 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2814x3220 = x2814x3220_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2814x3220*> * sync = new MultiLoopSync<activation_x2814x3220*>(x2814x3220_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2814x3220_closure->allocVal = alloc;
x2814x3220_closure->syncVal = sync;
submitWork(r->threadId, x2814x3220_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2814x3220_closure)));
i = i+1;
}
x2814x3220 = x2814x3220_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2814x3220;
}

/**********/

