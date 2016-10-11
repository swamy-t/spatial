//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x4230 * kernel_x4230(resourceInfo_t *resourceInfo,int32_t  x14) {
// a *thin* loop follows: x4230
class x4230_class{
public:
int32_t x14;

x4230_class(int32_t  _x14) {
x14 = _x14;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x14;
}

int64_t loopStart;
int64_t loopSize;
activation_x4230 *alloc(resourceInfo_t *resourceInfo) {
activation_x4230 * __act = new activation_x4230();;
int32_t x205 = (int32_t)(loopSize);
assert(x205 < (size_t)-1);
cppDeliteArrayfloat *x4194 = new (resourceInfo) cppDeliteArrayfloat(x205);
__act->x4230_data = x4194;
return __act;
}

activation_x4230 *main_par(resourceInfo_t *resourceInfo,activation_x4230 *__act,MultiLoopSync<activation_x4230*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4230 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4230 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4230 *main_seq(resourceInfo_t *resourceInfo,activation_x4230 *__act) {
activation_x4230 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4230 *processRange(resourceInfo_t *resourceInfo,activation_x4230 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4230 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4230 *init(resourceInfo_t *resourceInfo,activation_x4230 *__act,int32_t x200,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x200);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4230 *__act,int32_t x200) {
float  x4192 = (float) rand() / (float) RAND_MAX;
float x204 = x4192;
cppDeliteArrayfloat *x203 = __act->x4230_data;
x203->update(x200, x204);
}

void combine(resourceInfo_t *resourceInfo,activation_x4230 *__act,activation_x4230 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4230 *__act,activation_x4230 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4230 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4230 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4230 *__act) {
cppDeliteArrayfloat * x203 = __act->x4230_data;
__act->x4230 = x203;
}

activation_x4230 *initAct(resourceInfo_t *resourceInfo) {
activation_x4230 * act = new activation_x4230;
return act;
}

activation_x4230 *allocVal;
MultiLoopSync<activation_x4230*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4230_class *closure = (x4230_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4230_class *x4230_closure = new x4230_class(x14);
x4230_closure->loopStart = 0;
x4230_closure->loopSize = x14;
activation_x4230 * alloc = x4230_closure->alloc(resourceInfo);
activation_x4230 * x4230 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4230 = x4230_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4230*> * sync = new MultiLoopSync<activation_x4230*>(x4230_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4230_closure->allocVal = alloc;
x4230_closure->syncVal = sync;
submitWork(r->threadId, x4230_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4230_closure)));
i = i+1;
}
x4230 = x4230_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4230;
}

/**********/

