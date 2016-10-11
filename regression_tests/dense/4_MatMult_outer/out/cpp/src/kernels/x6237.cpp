//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6237 * kernel_x6237(resourceInfo_t *resourceInfo,int32_t  x6234, cppDeliteArrayint32_t  *x5834) {
class x6237_class{
public:
int32_t x6234;
cppDeliteArrayint32_t *x5834;

x6237_class(int32_t  _x6234,cppDeliteArrayint32_t * _x5834) {
x6234 = _x6234;
x5834 = _x5834;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6234;
}

int64_t loopStart;
int64_t loopSize;
activation_x6237 *alloc(resourceInfo_t *resourceInfo) {
activation_x6237 * __act = new activation_x6237();;
int32_t x942 = (int32_t)(loopSize);
assert(x942 < (size_t)-1);
cppDeliteArrayint32_t *x6081 = new (resourceInfo) cppDeliteArrayint32_t(x942);
__act->x6237_data = x6081;
return __act;
}

activation_x6237 *main_par(resourceInfo_t *resourceInfo,activation_x6237 *__act,MultiLoopSync<activation_x6237*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6237 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6237 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x6237 *main_seq(resourceInfo_t *resourceInfo,activation_x6237 *__act) {
activation_x6237 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6237 *processRange(resourceInfo_t *resourceInfo,activation_x6237 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6237 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6237 *init(resourceInfo_t *resourceInfo,activation_x6237 *__act,int32_t x937,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x937);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x6237 *__act,int32_t x937) {
int32_t x6079 = x5834->apply(x937);
int32_t x941 = x6079;
cppDeliteArrayint32_t *x940 = __act->x6237_data;
x940->update(x937, x941);
}

void combine(resourceInfo_t *resourceInfo,activation_x6237 *__act,activation_x6237 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6237 *__act,activation_x6237 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6237 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6237 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6237 *__act) {
cppDeliteArrayint32_t * x940 = __act->x6237_data;
__act->x6237 = x940;
}

activation_x6237 *initAct(resourceInfo_t *resourceInfo) {
activation_x6237 * act = new activation_x6237;
return act;
}

activation_x6237 *allocVal;
MultiLoopSync<activation_x6237*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6237_class *closure = (x6237_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6237_class *x6237_closure = new x6237_class(x6234,x5834);
x6237_closure->loopStart = 0;
x6237_closure->loopSize = x6234;
activation_x6237 * alloc = x6237_closure->alloc(resourceInfo);
activation_x6237 * x6237 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6237 = x6237_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6237*> * sync = new MultiLoopSync<activation_x6237*>(x6237_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6237_closure->allocVal = alloc;
x6237_closure->syncVal = sync;
submitWork(r->threadId, x6237_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6237_closure)));
i = i+1;
}
x6237 = x6237_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6237;
}

/**********/

