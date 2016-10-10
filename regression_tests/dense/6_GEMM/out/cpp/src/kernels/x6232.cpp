//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6232 * kernel_x6232(resourceInfo_t *resourceInfo,int32_t  x6208, cppDeliteArrayint32_t  *x5835, cppDeliteArrayint32_t  *x6207) {
class x6232_class{
public:
int32_t x6208;
cppDeliteArrayint32_t *x5835;
cppDeliteArrayint32_t *x6207;

x6232_class(int32_t  _x6208,cppDeliteArrayint32_t * _x5835,cppDeliteArrayint32_t * _x6207) {
x6208 = _x6208;
x5835 = _x5835;
x6207 = _x6207;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6208;
}

int64_t loopStart;
int64_t loopSize;
activation_x6232 *alloc(resourceInfo_t *resourceInfo) {
activation_x6232 * __act = new activation_x6232();;
int32_t x1052 = (int32_t)(loopSize);
assert(x1052 < (size_t)-1);
cppDeliteArraybool *x6131 = new (resourceInfo) cppDeliteArraybool(x1052);
__act->x6232_data = x6131;
return __act;
}

activation_x6232 *main_par(resourceInfo_t *resourceInfo,activation_x6232 *__act,MultiLoopSync<activation_x6232*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6232 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6232 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x6232 *main_seq(resourceInfo_t *resourceInfo,activation_x6232 *__act) {
activation_x6232 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6232 *processRange(resourceInfo_t *resourceInfo,activation_x6232 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6232 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6232 *init(resourceInfo_t *resourceInfo,activation_x6232 *__act,int32_t x1045,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x1045);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x6232 *__act,int32_t x1045) {
int32_t x6127 = x5835->apply(x1045);
int32_t x6227 = x6207->apply(x1045);
bool  x6228 = x6227 == x6127;
bool x1051 = x6228;
cppDeliteArraybool *x1050 = __act->x6232_data;
x1050->update(x1045, x1051);
}

void combine(resourceInfo_t *resourceInfo,activation_x6232 *__act,activation_x6232 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6232 *__act,activation_x6232 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6232 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6232 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6232 *__act) {
cppDeliteArraybool * x1050 = __act->x6232_data;
__act->x6232 = x1050;
}

activation_x6232 *initAct(resourceInfo_t *resourceInfo) {
activation_x6232 * act = new activation_x6232;
return act;
}

activation_x6232 *allocVal;
MultiLoopSync<activation_x6232*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6232_class *closure = (x6232_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6232_class *x6232_closure = new x6232_class(x6208,x5835,x6207);
x6232_closure->loopStart = 0;
x6232_closure->loopSize = x6208;
activation_x6232 * alloc = x6232_closure->alloc(resourceInfo);
activation_x6232 * x6232 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6232 = x6232_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6232*> * sync = new MultiLoopSync<activation_x6232*>(x6232_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6232_closure->allocVal = alloc;
x6232_closure->syncVal = sync;
submitWork(r->threadId, x6232_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6232_closure)));
i = i+1;
}
x6232 = x6232_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6232;
}

/**********/

