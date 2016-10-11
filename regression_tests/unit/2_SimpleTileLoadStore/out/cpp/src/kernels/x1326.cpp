//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1326 * kernel_x1326(resourceInfo_t *resourceInfo,int32_t  x4, cppDeliteArrayint32_t  *x1236, int32_t  x2) {
class x1326_class{
public:
int32_t x4;
cppDeliteArrayint32_t *x1236;
int32_t x2;

x1326_class(int32_t  _x4,cppDeliteArrayint32_t * _x1236,int32_t  _x2) {
x4 = _x4;
x1236 = _x1236;
x2 = _x2;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x4;
}

int64_t loopStart;
int64_t loopSize;
activation_x1326 *alloc(resourceInfo_t *resourceInfo) {
activation_x1326 * __act = new activation_x1326();;
int32_t x120 = (int32_t)(loopSize);
assert(x120 < (size_t)-1);
cppDeliteArrayint32_t *x1290 = new (resourceInfo) cppDeliteArrayint32_t(x120);
__act->x1326_data = x1290;
return __act;
}

activation_x1326 *main_par(resourceInfo_t *resourceInfo,activation_x1326 *__act,MultiLoopSync<activation_x1326*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1326 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1326 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1326 *main_seq(resourceInfo_t *resourceInfo,activation_x1326 *__act) {
activation_x1326 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1326 *processRange(resourceInfo_t *resourceInfo,activation_x1326 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1326 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1326 *init(resourceInfo_t *resourceInfo,activation_x1326 *__act,int32_t x115,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x115);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1326 *__act,int32_t x115) {
int32_t x1288 = x1236->apply(x115);
int32_t  x1289 = x1288 * x2;
int32_t x119 = x1289;
cppDeliteArrayint32_t *x118 = __act->x1326_data;
x118->update(x115, x119);
}

void combine(resourceInfo_t *resourceInfo,activation_x1326 *__act,activation_x1326 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1326 *__act,activation_x1326 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1326 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1326 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1326 *__act) {
cppDeliteArrayint32_t * x118 = __act->x1326_data;
__act->x1326 = x118;
}

activation_x1326 *initAct(resourceInfo_t *resourceInfo) {
activation_x1326 * act = new activation_x1326;
return act;
}

activation_x1326 *allocVal;
MultiLoopSync<activation_x1326*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1326_class *closure = (x1326_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1326_class *x1326_closure = new x1326_class(x4,x1236,x2);
x1326_closure->loopStart = 0;
x1326_closure->loopSize = x4;
activation_x1326 * alloc = x1326_closure->alloc(resourceInfo);
activation_x1326 * x1326 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1326 = x1326_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1326*> * sync = new MultiLoopSync<activation_x1326*>(x1326_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1326_closure->allocVal = alloc;
x1326_closure->syncVal = sync;
submitWork(r->threadId, x1326_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1326_closure)));
i = i+1;
}
x1326 = x1326_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1326;
}

/**********/

