//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2896 * kernel_x2896(resourceInfo_t *resourceInfo,int32_t  x2880, cppDeliteArrayint32_t  *x2610, cppDeliteArrayint32_t  *x2879) {
class x2896_class{
public:
int32_t x2880;
cppDeliteArrayint32_t *x2610;
cppDeliteArrayint32_t *x2879;

x2896_class(int32_t  _x2880,cppDeliteArrayint32_t * _x2610,cppDeliteArrayint32_t * _x2879) {
x2880 = _x2880;
x2610 = _x2610;
x2879 = _x2879;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x2880;
}

int64_t loopStart;
int64_t loopSize;
activation_x2896 *alloc(resourceInfo_t *resourceInfo) {
activation_x2896 * __act = new activation_x2896();;
int32_t x461 = (int32_t)(loopSize);
assert(x461 < (size_t)-1);
cppDeliteArraybool *x2821 = new (resourceInfo) cppDeliteArraybool(x461);
__act->x2896_data = x2821;
return __act;
}

activation_x2896 *main_par(resourceInfo_t *resourceInfo,activation_x2896 *__act,MultiLoopSync<activation_x2896*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2896 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2896 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2896 *main_seq(resourceInfo_t *resourceInfo,activation_x2896 *__act) {
activation_x2896 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2896 *processRange(resourceInfo_t *resourceInfo,activation_x2896 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2896 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2896 *init(resourceInfo_t *resourceInfo,activation_x2896 *__act,int32_t x454,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x454);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2896 *__act,int32_t x454) {
int32_t x2817 = x2610->apply(x454);
int32_t x2891 = x2879->apply(x454);
bool  x2892 = x2891 == x2817;
bool x460 = x2892;
cppDeliteArraybool *x459 = __act->x2896_data;
x459->update(x454, x460);
}

void combine(resourceInfo_t *resourceInfo,activation_x2896 *__act,activation_x2896 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2896 *__act,activation_x2896 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2896 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2896 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2896 *__act) {
cppDeliteArraybool * x459 = __act->x2896_data;
__act->x2896 = x459;
}

activation_x2896 *initAct(resourceInfo_t *resourceInfo) {
activation_x2896 * act = new activation_x2896;
return act;
}

activation_x2896 *allocVal;
MultiLoopSync<activation_x2896*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2896_class *closure = (x2896_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2896_class *x2896_closure = new x2896_class(x2880,x2610,x2879);
x2896_closure->loopStart = 0;
x2896_closure->loopSize = x2880;
activation_x2896 * alloc = x2896_closure->alloc(resourceInfo);
activation_x2896 * x2896 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2896 = x2896_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2896*> * sync = new MultiLoopSync<activation_x2896*>(x2896_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2896_closure->allocVal = alloc;
x2896_closure->syncVal = sync;
submitWork(r->threadId, x2896_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2896_closure)));
i = i+1;
}
x2896 = x2896_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2896;
}

/**********/

