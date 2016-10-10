//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x4838 * kernel_x4838(resourceInfo_t *resourceInfo,int32_t  x4793, cppDeliteArrayint32_t  *x4493, cppDeliteArrayint32_t  *x4491, int32_t  x303) {
class x4838_class{
public:
int32_t x4793;
cppDeliteArrayint32_t *x4493;
cppDeliteArrayint32_t *x4491;
int32_t x303;

x4838_class(int32_t  _x4793,cppDeliteArrayint32_t * _x4493,cppDeliteArrayint32_t * _x4491,int32_t  _x303) {
x4793 = _x4793;
x4493 = _x4493;
x4491 = _x4491;
x303 = _x303;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x4793;
}

int64_t loopStart;
int64_t loopSize;
activation_x4838 *alloc(resourceInfo_t *resourceInfo) {
activation_x4838 * __act = new activation_x4838();;
int32_t x797 = (int32_t)(loopSize);
assert(x797 < (size_t)-1);
cppDeliteArraybool *x4802 = new (resourceInfo) cppDeliteArraybool(x797);
__act->x4838_data = x4802;
return __act;
}

activation_x4838 *main_par(resourceInfo_t *resourceInfo,activation_x4838 *__act,MultiLoopSync<activation_x4838*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4838 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4838 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4838 *main_seq(resourceInfo_t *resourceInfo,activation_x4838 *__act) {
activation_x4838 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4838 *processRange(resourceInfo_t *resourceInfo,activation_x4838 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4838 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4838 *init(resourceInfo_t *resourceInfo,activation_x4838 *__act,int32_t x786,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x786);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4838 *__act,int32_t x786) {
int32_t x4794 = x4493->apply(x786);
int32_t x4795 = x4491->apply(x786);
int32_t  x4796 = x4795 + x303;
bool  x4797 = x4794 < x4796;
int32_t  x4798 = x4795 - x303;
bool  x4799 = x4798 < x4794;
bool  x4800 = x4797 && x4799;
bool x796 = x4800;
cppDeliteArraybool *x795 = __act->x4838_data;
x795->update(x786, x796);
}

void combine(resourceInfo_t *resourceInfo,activation_x4838 *__act,activation_x4838 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4838 *__act,activation_x4838 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4838 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4838 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4838 *__act) {
cppDeliteArraybool * x795 = __act->x4838_data;
__act->x4838 = x795;
}

activation_x4838 *initAct(resourceInfo_t *resourceInfo) {
activation_x4838 * act = new activation_x4838;
return act;
}

activation_x4838 *allocVal;
MultiLoopSync<activation_x4838*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4838_class *closure = (x4838_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4838_class *x4838_closure = new x4838_class(x4793,x4493,x4491,x303);
x4838_closure->loopStart = 0;
x4838_closure->loopSize = x4793;
activation_x4838 * alloc = x4838_closure->alloc(resourceInfo);
activation_x4838 * x4838 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4838 = x4838_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4838*> * sync = new MultiLoopSync<activation_x4838*>(x4838_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4838_closure->allocVal = alloc;
x4838_closure->syncVal = sync;
submitWork(r->threadId, x4838_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4838_closure)));
i = i+1;
}
x4838 = x4838_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4838;
}

/**********/

