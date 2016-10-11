//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x891 * kernel_x891(resourceInfo_t *resourceInfo,int32_t  x99) {
class x891_class{
public:
int32_t x99;

x891_class(int32_t  _x99) {
x99 = _x99;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x99;
}

int64_t loopStart;
int64_t loopSize;
activation_x891 *alloc(resourceInfo_t *resourceInfo) {
activation_x891 * __act = new activation_x891();;
int32_t x104 = (int32_t)(loopSize);
assert(x104 < (size_t)-1);
cppDeliteArrayint32_t *x855 = new (resourceInfo) cppDeliteArrayint32_t(x104);
__act->x891_data = x855;
return __act;
}

activation_x891 *main_par(resourceInfo_t *resourceInfo,activation_x891 *__act,MultiLoopSync<activation_x891*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x891 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x891 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x891 *main_seq(resourceInfo_t *resourceInfo,activation_x891 *__act) {
activation_x891 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x891 *processRange(resourceInfo_t *resourceInfo,activation_x891 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x891 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x891 *init(resourceInfo_t *resourceInfo,activation_x891 *__act,int32_t x100,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x100);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x891 *__act,int32_t x100) {
int32_t  x101 = (int32_t) (x100);
int32_t x103 = x101;
cppDeliteArrayint32_t *x102 = __act->x891_data;
x102->update(x100, x103);
}

void combine(resourceInfo_t *resourceInfo,activation_x891 *__act,activation_x891 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x891 *__act,activation_x891 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x891 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x891 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x891 *__act) {
cppDeliteArrayint32_t * x102 = __act->x891_data;
__act->x891 = x102;
}

activation_x891 *initAct(resourceInfo_t *resourceInfo) {
activation_x891 * act = new activation_x891;
return act;
}

activation_x891 *allocVal;
MultiLoopSync<activation_x891*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x891_class *closure = (x891_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x891_class *x891_closure = new x891_class(x99);
x891_closure->loopStart = 0;
x891_closure->loopSize = x99;
activation_x891 * alloc = x891_closure->alloc(resourceInfo);
activation_x891 * x891 = NULL;
if (resourceInfo->availableThreads <= 1) {
x891 = x891_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x891*> * sync = new MultiLoopSync<activation_x891*>(x891_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x891_closure->allocVal = alloc;
x891_closure->syncVal = sync;
submitWork(r->threadId, x891_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x891_closure)));
i = i+1;
}
x891 = x891_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x891;
}

/**********/

