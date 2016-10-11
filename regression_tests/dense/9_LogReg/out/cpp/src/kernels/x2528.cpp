//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x2528 * kernel_x2528(resourceInfo_t *resourceInfo,int32_t  x6, float  x147) {
// a *thin* loop follows: x2528
class x2528_class{
public:
int32_t x6;
float x147;

x2528_class(int32_t  _x6,float  _x147) {
x6 = _x6;
x147 = _x147;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6;
}

int64_t loopStart;
int64_t loopSize;
activation_x2528 *alloc(resourceInfo_t *resourceInfo) {
activation_x2528 * __act = new activation_x2528();;
int32_t x153 = (int32_t)(loopSize);
assert(x153 < (size_t)-1);
cppDeliteArrayfloat *x2492 = new (resourceInfo) cppDeliteArrayfloat(x153);
__act->x2528_data = x2492;
return __act;
}

activation_x2528 *main_par(resourceInfo_t *resourceInfo,activation_x2528 *__act,MultiLoopSync<activation_x2528*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2528 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2528 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2528 *main_seq(resourceInfo_t *resourceInfo,activation_x2528 *__act) {
activation_x2528 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2528 *processRange(resourceInfo_t *resourceInfo,activation_x2528 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2528 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2528 *init(resourceInfo_t *resourceInfo,activation_x2528 *__act,int32_t x146,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x146);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2528 *__act,int32_t x146) {
float  x2489 = (float) rand() / (float) RAND_MAX;
float  x2490 = x2489 * x147;
float x152 = x2490;
cppDeliteArrayfloat *x151 = __act->x2528_data;
x151->update(x146, x152);
}

void combine(resourceInfo_t *resourceInfo,activation_x2528 *__act,activation_x2528 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2528 *__act,activation_x2528 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2528 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2528 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2528 *__act) {
cppDeliteArrayfloat * x151 = __act->x2528_data;
__act->x2528 = x151;
}

activation_x2528 *initAct(resourceInfo_t *resourceInfo) {
activation_x2528 * act = new activation_x2528;
return act;
}

activation_x2528 *allocVal;
MultiLoopSync<activation_x2528*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2528_class *closure = (x2528_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2528_class *x2528_closure = new x2528_class(x6,x147);
x2528_closure->loopStart = 0;
x2528_closure->loopSize = x6;
activation_x2528 * alloc = x2528_closure->alloc(resourceInfo);
activation_x2528 * x2528 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2528 = x2528_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2528*> * sync = new MultiLoopSync<activation_x2528*>(x2528_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2528_closure->allocVal = alloc;
x2528_closure->syncVal = sync;
submitWork(r->threadId, x2528_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2528_closure)));
i = i+1;
}
x2528 = x2528_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2528;
}

/**********/

