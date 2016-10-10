//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6261 * kernel_x6261(resourceInfo_t *resourceInfo,int32_t  x6234, cppDeliteArrayint32_t  *x5834, cppDeliteArrayint32_t  *x6224) {
class x6261_class{
public:
int32_t x6234;
cppDeliteArrayint32_t *x5834;
cppDeliteArrayint32_t *x6224;

x6261_class(int32_t  _x6234,cppDeliteArrayint32_t * _x5834,cppDeliteArrayint32_t * _x6224) {
x6234 = _x6234;
x5834 = _x5834;
x6224 = _x6224;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6234;
}

int64_t loopStart;
int64_t loopSize;
activation_x6261 *alloc(resourceInfo_t *resourceInfo) {
activation_x6261 * __act = new activation_x6261();;
int32_t x1024 = (int32_t)(loopSize);
assert(x1024 < (size_t)-1);
cppDeliteArraybool *x6146 = new (resourceInfo) cppDeliteArraybool(x1024);
__act->x6261_data = x6146;
return __act;
}

activation_x6261 *main_par(resourceInfo_t *resourceInfo,activation_x6261 *__act,MultiLoopSync<activation_x6261*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6261 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6261 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x6261 *main_seq(resourceInfo_t *resourceInfo,activation_x6261 *__act) {
activation_x6261 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6261 *processRange(resourceInfo_t *resourceInfo,activation_x6261 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6261 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6261 *init(resourceInfo_t *resourceInfo,activation_x6261 *__act,int32_t x1017,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x1017);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x6261 *__act,int32_t x1017) {
int32_t x6142 = x5834->apply(x1017);
int32_t x6256 = x6224->apply(x1017);
bool  x6257 = x6142 == x6256;
bool x1023 = x6257;
cppDeliteArraybool *x1022 = __act->x6261_data;
x1022->update(x1017, x1023);
}

void combine(resourceInfo_t *resourceInfo,activation_x6261 *__act,activation_x6261 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6261 *__act,activation_x6261 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6261 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6261 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6261 *__act) {
cppDeliteArraybool * x1022 = __act->x6261_data;
__act->x6261 = x1022;
}

activation_x6261 *initAct(resourceInfo_t *resourceInfo) {
activation_x6261 * act = new activation_x6261;
return act;
}

activation_x6261 *allocVal;
MultiLoopSync<activation_x6261*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6261_class *closure = (x6261_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6261_class *x6261_closure = new x6261_class(x6234,x5834,x6224);
x6261_closure->loopStart = 0;
x6261_closure->loopSize = x6234;
activation_x6261 * alloc = x6261_closure->alloc(resourceInfo);
activation_x6261 * x6261 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6261 = x6261_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6261*> * sync = new MultiLoopSync<activation_x6261*>(x6261_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6261_closure->allocVal = alloc;
x6261_closure->syncVal = sync;
submitWork(r->threadId, x6261_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6261_closure)));
i = i+1;
}
x6261 = x6261_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6261;
}

/**********/

