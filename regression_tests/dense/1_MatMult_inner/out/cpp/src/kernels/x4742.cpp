//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x4742 * kernel_x4742(resourceInfo_t *resourceInfo,int32_t  x99, int32_t  x11) {
class x4742_class{
public:
int32_t x99;
int32_t x11;

x4742_class(int32_t  _x99,int32_t  _x11) {
x99 = _x99;
x11 = _x11;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x99;
}

int64_t loopStart;
int64_t loopSize;
activation_x4742 *alloc(resourceInfo_t *resourceInfo) {
activation_x4742 * __act = new activation_x4742();;
int32_t x103 = (int32_t)(loopSize);
assert(x103 < (size_t)-1);
cppDeliteArrayint32_t *x4706 = new (resourceInfo) cppDeliteArrayint32_t(x103);
__act->x4742_data = x4706;
return __act;
}

activation_x4742 *main_par(resourceInfo_t *resourceInfo,activation_x4742 *__act,MultiLoopSync<activation_x4742*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4742 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4742 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4742 *main_seq(resourceInfo_t *resourceInfo,activation_x4742 *__act) {
activation_x4742 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4742 *processRange(resourceInfo_t *resourceInfo,activation_x4742 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4742 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4742 *init(resourceInfo_t *resourceInfo,activation_x4742 *__act,int32_t x100,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x100);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4742 *__act,int32_t x100) {
int32_t x102 = x11;
cppDeliteArrayint32_t *x101 = __act->x4742_data;
x101->update(x100, x102);
}

void combine(resourceInfo_t *resourceInfo,activation_x4742 *__act,activation_x4742 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4742 *__act,activation_x4742 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4742 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4742 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4742 *__act) {
cppDeliteArrayint32_t * x101 = __act->x4742_data;
__act->x4742 = x101;
}

activation_x4742 *initAct(resourceInfo_t *resourceInfo) {
activation_x4742 * act = new activation_x4742;
return act;
}

activation_x4742 *allocVal;
MultiLoopSync<activation_x4742*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4742_class *closure = (x4742_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4742_class *x4742_closure = new x4742_class(x99,x11);
x4742_closure->loopStart = 0;
x4742_closure->loopSize = x99;
activation_x4742 * alloc = x4742_closure->alloc(resourceInfo);
activation_x4742 * x4742 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4742 = x4742_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4742*> * sync = new MultiLoopSync<activation_x4742*>(x4742_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4742_closure->allocVal = alloc;
x4742_closure->syncVal = sync;
submitWork(r->threadId, x4742_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4742_closure)));
i = i+1;
}
x4742 = x4742_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4742;
}

/**********/

