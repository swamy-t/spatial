//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1402 * kernel_x1402(resourceInfo_t *resourceInfo,int32_t  x1354, cppDeliteArrayint32_t  *x1307, cppDeliteArrayint32_t  *x1346) {
class x1402_class{
public:
int32_t x1354;
cppDeliteArrayint32_t *x1307;
cppDeliteArrayint32_t *x1346;

x1402_class(int32_t  _x1354,cppDeliteArrayint32_t * _x1307,cppDeliteArrayint32_t * _x1346) {
x1354 = _x1354;
x1307 = _x1307;
x1346 = _x1346;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1354;
}

int64_t loopStart;
int64_t loopSize;
activation_x1402 *alloc(resourceInfo_t *resourceInfo) {
activation_x1402 * __act = new activation_x1402();;
int32_t x204 = (int32_t)(loopSize);
assert(x204 < (size_t)-1);
cppDeliteArraybool *x1366 = new (resourceInfo) cppDeliteArraybool(x204);
__act->x1402_data = x1366;
return __act;
}

activation_x1402 *main_par(resourceInfo_t *resourceInfo,activation_x1402 *__act,MultiLoopSync<activation_x1402*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1402 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1402 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1402 *main_seq(resourceInfo_t *resourceInfo,activation_x1402 *__act) {
activation_x1402 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1402 *processRange(resourceInfo_t *resourceInfo,activation_x1402 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1402 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1402 *init(resourceInfo_t *resourceInfo,activation_x1402 *__act,int32_t x197,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x197);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1402 *__act,int32_t x197) {
int32_t x1362 = x1307->apply(x197);
int32_t x1363 = x1346->apply(x197);
bool  x1364 = x1362 == x1363;
bool x203 = x1364;
cppDeliteArraybool *x202 = __act->x1402_data;
x202->update(x197, x203);
}

void combine(resourceInfo_t *resourceInfo,activation_x1402 *__act,activation_x1402 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1402 *__act,activation_x1402 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1402 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1402 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1402 *__act) {
cppDeliteArraybool * x202 = __act->x1402_data;
__act->x1402 = x202;
}

activation_x1402 *initAct(resourceInfo_t *resourceInfo) {
activation_x1402 * act = new activation_x1402;
return act;
}

activation_x1402 *allocVal;
MultiLoopSync<activation_x1402*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1402_class *closure = (x1402_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1402_class *x1402_closure = new x1402_class(x1354,x1307,x1346);
x1402_closure->loopStart = 0;
x1402_closure->loopSize = x1354;
activation_x1402 * alloc = x1402_closure->alloc(resourceInfo);
activation_x1402 * x1402 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1402 = x1402_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1402*> * sync = new MultiLoopSync<activation_x1402*>(x1402_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1402_closure->allocVal = alloc;
x1402_closure->syncVal = sync;
submitWork(r->threadId, x1402_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1402_closure)));
i = i+1;
}
x1402 = x1402_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1402;
}

/**********/

