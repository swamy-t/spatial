//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1439 * kernel_x1439(resourceInfo_t *resourceInfo,int32_t  x1391, cppDeliteArrayint32_t  *x1344, cppDeliteArrayint32_t  *x1383) {
class x1439_class{
public:
int32_t x1391;
cppDeliteArrayint32_t *x1344;
cppDeliteArrayint32_t *x1383;

x1439_class(int32_t  _x1391,cppDeliteArrayint32_t * _x1344,cppDeliteArrayint32_t * _x1383) {
x1391 = _x1391;
x1344 = _x1344;
x1383 = _x1383;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1391;
}

int64_t loopStart;
int64_t loopSize;
activation_x1439 *alloc(resourceInfo_t *resourceInfo) {
activation_x1439 * __act = new activation_x1439();;
int32_t x208 = (int32_t)(loopSize);
assert(x208 < (size_t)-1);
cppDeliteArraybool *x1403 = new (resourceInfo) cppDeliteArraybool(x208);
__act->x1439_data = x1403;
return __act;
}

activation_x1439 *main_par(resourceInfo_t *resourceInfo,activation_x1439 *__act,MultiLoopSync<activation_x1439*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1439 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1439 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1439 *main_seq(resourceInfo_t *resourceInfo,activation_x1439 *__act) {
activation_x1439 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1439 *processRange(resourceInfo_t *resourceInfo,activation_x1439 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1439 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1439 *init(resourceInfo_t *resourceInfo,activation_x1439 *__act,int32_t x201,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x201);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1439 *__act,int32_t x201) {
int32_t x1399 = x1344->apply(x201);
int32_t x1400 = x1383->apply(x201);
bool  x1401 = x1399 == x1400;
bool x207 = x1401;
cppDeliteArraybool *x206 = __act->x1439_data;
x206->update(x201, x207);
}

void combine(resourceInfo_t *resourceInfo,activation_x1439 *__act,activation_x1439 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1439 *__act,activation_x1439 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1439 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1439 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1439 *__act) {
cppDeliteArraybool * x206 = __act->x1439_data;
__act->x1439 = x206;
}

activation_x1439 *initAct(resourceInfo_t *resourceInfo) {
activation_x1439 * act = new activation_x1439;
return act;
}

activation_x1439 *allocVal;
MultiLoopSync<activation_x1439*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1439_class *closure = (x1439_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1439_class *x1439_closure = new x1439_class(x1391,x1344,x1383);
x1439_closure->loopStart = 0;
x1439_closure->loopSize = x1391;
activation_x1439 * alloc = x1439_closure->alloc(resourceInfo);
activation_x1439 * x1439 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1439 = x1439_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1439*> * sync = new MultiLoopSync<activation_x1439*>(x1439_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1439_closure->allocVal = alloc;
x1439_closure->syncVal = sync;
submitWork(r->threadId, x1439_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1439_closure)));
i = i+1;
}
x1439 = x1439_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1439;
}

/**********/

