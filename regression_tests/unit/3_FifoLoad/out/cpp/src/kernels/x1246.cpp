//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1246 * kernel_x1246(resourceInfo_t *resourceInfo,int32_t  x3, cppDeliteArrayint32_t  *x1171) {
class x1246_class{
public:
int32_t x3;
cppDeliteArrayint32_t *x1171;

x1246_class(int32_t  _x3,cppDeliteArrayint32_t * _x1171) {
x3 = _x3;
x1171 = _x1171;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x1246 *alloc(resourceInfo_t *resourceInfo) {
activation_x1246 * __act = new activation_x1246();;
int32_t x107 = (int32_t)(loopSize);
assert(x107 < (size_t)-1);
cppDeliteArrayint32_t *x1210 = new (resourceInfo) cppDeliteArrayint32_t(x107);
__act->x1246_data = x1210;
return __act;
}

activation_x1246 *main_par(resourceInfo_t *resourceInfo,activation_x1246 *__act,MultiLoopSync<activation_x1246*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1246 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1246 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1246 *main_seq(resourceInfo_t *resourceInfo,activation_x1246 *__act) {
activation_x1246 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1246 *processRange(resourceInfo_t *resourceInfo,activation_x1246 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1246 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1246 *init(resourceInfo_t *resourceInfo,activation_x1246 *__act,int32_t x103,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x103);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1246 *__act,int32_t x103) {
int32_t x1209 = x1171->apply(x103);
int32_t x106 = x1209;
cppDeliteArrayint32_t *x105 = __act->x1246_data;
x105->update(x103, x106);
}

void combine(resourceInfo_t *resourceInfo,activation_x1246 *__act,activation_x1246 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1246 *__act,activation_x1246 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1246 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1246 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1246 *__act) {
cppDeliteArrayint32_t * x105 = __act->x1246_data;
__act->x1246 = x105;
}

activation_x1246 *initAct(resourceInfo_t *resourceInfo) {
activation_x1246 * act = new activation_x1246;
return act;
}

activation_x1246 *allocVal;
MultiLoopSync<activation_x1246*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1246_class *closure = (x1246_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1246_class *x1246_closure = new x1246_class(x3,x1171);
x1246_closure->loopStart = 0;
x1246_closure->loopSize = x3;
activation_x1246 * alloc = x1246_closure->alloc(resourceInfo);
activation_x1246 * x1246 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1246 = x1246_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1246*> * sync = new MultiLoopSync<activation_x1246*>(x1246_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1246_closure->allocVal = alloc;
x1246_closure->syncVal = sync;
submitWork(r->threadId, x1246_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1246_closure)));
i = i+1;
}
x1246 = x1246_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1246;
}

/**********/

