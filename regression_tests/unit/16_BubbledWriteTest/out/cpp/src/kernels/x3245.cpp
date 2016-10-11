//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3245 * kernel_x3245(resourceInfo_t *resourceInfo,int32_t  x3229, cppDeliteArrayint32_t  *x2959, cppDeliteArrayint32_t  *x3228) {
class x3245_class{
public:
int32_t x3229;
cppDeliteArrayint32_t *x2959;
cppDeliteArrayint32_t *x3228;

x3245_class(int32_t  _x3229,cppDeliteArrayint32_t * _x2959,cppDeliteArrayint32_t * _x3228) {
x3229 = _x3229;
x2959 = _x2959;
x3228 = _x3228;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3229;
}

int64_t loopStart;
int64_t loopSize;
activation_x3245 *alloc(resourceInfo_t *resourceInfo) {
activation_x3245 * __act = new activation_x3245();;
int32_t x518 = (int32_t)(loopSize);
assert(x518 < (size_t)-1);
cppDeliteArraybool *x3170 = new (resourceInfo) cppDeliteArraybool(x518);
__act->x3245_data = x3170;
return __act;
}

activation_x3245 *main_par(resourceInfo_t *resourceInfo,activation_x3245 *__act,MultiLoopSync<activation_x3245*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3245 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3245 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x3245 *main_seq(resourceInfo_t *resourceInfo,activation_x3245 *__act) {
activation_x3245 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3245 *processRange(resourceInfo_t *resourceInfo,activation_x3245 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3245 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3245 *init(resourceInfo_t *resourceInfo,activation_x3245 *__act,int32_t x511,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x511);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x3245 *__act,int32_t x511) {
int32_t x3166 = x2959->apply(x511);
int32_t x3240 = x3228->apply(x511);
bool  x3241 = x3240 == x3166;
bool x517 = x3241;
cppDeliteArraybool *x516 = __act->x3245_data;
x516->update(x511, x517);
}

void combine(resourceInfo_t *resourceInfo,activation_x3245 *__act,activation_x3245 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3245 *__act,activation_x3245 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3245 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3245 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3245 *__act) {
cppDeliteArraybool * x516 = __act->x3245_data;
__act->x3245 = x516;
}

activation_x3245 *initAct(resourceInfo_t *resourceInfo) {
activation_x3245 * act = new activation_x3245;
return act;
}

activation_x3245 *allocVal;
MultiLoopSync<activation_x3245*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3245_class *closure = (x3245_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3245_class *x3245_closure = new x3245_class(x3229,x2959,x3228);
x3245_closure->loopStart = 0;
x3245_closure->loopSize = x3229;
activation_x3245 * alloc = x3245_closure->alloc(resourceInfo);
activation_x3245 * x3245 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3245 = x3245_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3245*> * sync = new MultiLoopSync<activation_x3245*>(x3245_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3245_closure->allocVal = alloc;
x3245_closure->syncVal = sync;
submitWork(r->threadId, x3245_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3245_closure)));
i = i+1;
}
x3245 = x3245_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3245;
}

/**********/

