//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2148 * kernel_x2148(resourceInfo_t *resourceInfo,int32_t  x3, cppDeliteArrayint32_t  *x1875, cppDeliteArrayint32_t  *x2125) {
class x2148_class{
public:
int32_t x3;
cppDeliteArrayint32_t *x1875;
cppDeliteArrayint32_t *x2125;

x2148_class(int32_t  _x3,cppDeliteArrayint32_t * _x1875,cppDeliteArrayint32_t * _x2125) {
x3 = _x3;
x1875 = _x1875;
x2125 = _x2125;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x2148 *alloc(resourceInfo_t *resourceInfo) {
activation_x2148 * __act = new activation_x2148();;
int32_t x259 = (int32_t)(loopSize);
assert(x259 < (size_t)-1);
cppDeliteArrayint32_t *x1953 = new (resourceInfo) cppDeliteArrayint32_t(x259);
__act->x2148_data = x1953;
return __act;
}

activation_x2148 *main_par(resourceInfo_t *resourceInfo,activation_x2148 *__act,MultiLoopSync<activation_x2148*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2148 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2148 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2148 *main_seq(resourceInfo_t *resourceInfo,activation_x2148 *__act) {
activation_x2148 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2148 *processRange(resourceInfo_t *resourceInfo,activation_x2148 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2148 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2148 *init(resourceInfo_t *resourceInfo,activation_x2148 *__act,int32_t x253,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x253);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2148 *__act,int32_t x253) {
int32_t x1950 = x1875->apply(x253);
int32_t x2144 = x2125->apply(x253);
int32_t  x2145 = x1950 * x2144;
int32_t x258 = x2145;
cppDeliteArrayint32_t *x257 = __act->x2148_data;
x257->update(x253, x258);
}

void combine(resourceInfo_t *resourceInfo,activation_x2148 *__act,activation_x2148 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2148 *__act,activation_x2148 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2148 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2148 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2148 *__act) {
cppDeliteArrayint32_t * x257 = __act->x2148_data;
__act->x2148 = x257;
}

activation_x2148 *initAct(resourceInfo_t *resourceInfo) {
activation_x2148 * act = new activation_x2148;
return act;
}

activation_x2148 *allocVal;
MultiLoopSync<activation_x2148*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2148_class *closure = (x2148_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2148_class *x2148_closure = new x2148_class(x3,x1875,x2125);
x2148_closure->loopStart = 0;
x2148_closure->loopSize = x3;
activation_x2148 * alloc = x2148_closure->alloc(resourceInfo);
activation_x2148 * x2148 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2148 = x2148_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2148*> * sync = new MultiLoopSync<activation_x2148*>(x2148_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2148_closure->allocVal = alloc;
x2148_closure->syncVal = sync;
submitWork(r->threadId, x2148_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2148_closure)));
i = i+1;
}
x2148 = x2148_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2148;
}

/**********/

