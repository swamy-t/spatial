//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x2448 * kernel_x2448(resourceInfo_t *resourceInfo,int32_t  x3, float  x8, int32_t  x6) {
// a *thin* loop follows: x2448
class x2448_class{
public:
int32_t x3;
float x8;
int32_t x6;

x2448_class(int32_t  _x3,float  _x8,int32_t  _x6) {
x3 = _x3;
x8 = _x8;
x6 = _x6;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x2448 *alloc(resourceInfo_t *resourceInfo) {
activation_x2448 * __act = new activation_x2448();;
int32_t x58 = (int32_t)(loopSize);
assert(x58 < (size_t)-1);
cppDeliteArraycppDeliteArrayfloat *x2412 = new (resourceInfo) cppDeliteArraycppDeliteArrayfloat(x58);
__act->x2448_data = x2412;
return __act;
}

activation_x2448 *main_par(resourceInfo_t *resourceInfo,activation_x2448 *__act,MultiLoopSync<activation_x2448*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2448 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2448 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2448 *main_seq(resourceInfo_t *resourceInfo,activation_x2448 *__act) {
activation_x2448 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2448 *processRange(resourceInfo_t *resourceInfo,activation_x2448 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2448 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2448 *init(resourceInfo_t *resourceInfo,activation_x2448 *__act,int32_t x4,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x4);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2448 *__act,int32_t x4) {
// a *thin* loop follows: x2410
int32_t  x14 = x6;
assert(x14 < (size_t)-1);
cppDeliteArrayfloat *x2374 = new (resourceInfo) cppDeliteArrayfloat(x14, resourceInfo);
cppDeliteArrayfloat * x2410_data = x2374;
int32_t  x2410_size = 0;
int32_t  x2410_conditionals = 0;
int32_t  x7 = 0;
while (x7 < x6) {  // begin fat loop x2410
float  x2371 = (float) rand() / (float) RAND_MAX;
float  x2372 = x2371 * x8;
float x13 = x2372;
cppDeliteArrayfloat *x12 = x2410_data;
x12->update(x7, x13);
x7 = x7 + 1;
} // end fat loop x2410
cppDeliteArrayfloat *x12 = x2410_data;
cppDeliteArrayfloat *x2410 = x12;
cppDeliteArrayfloat *x57 = x2410;
cppDeliteArraycppDeliteArrayfloat *x56 = __act->x2448_data;
x56->update(x4, x57);
}

void combine(resourceInfo_t *resourceInfo,activation_x2448 *__act,activation_x2448 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2448 *__act,activation_x2448 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2448 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2448 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2448 *__act) {
cppDeliteArraycppDeliteArrayfloat * x56 = __act->x2448_data;
__act->x2448 = x56;
}

activation_x2448 *initAct(resourceInfo_t *resourceInfo) {
activation_x2448 * act = new activation_x2448;
return act;
}

activation_x2448 *allocVal;
MultiLoopSync<activation_x2448*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2448_class *closure = (x2448_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2448_class *x2448_closure = new x2448_class(x3,x8,x6);
x2448_closure->loopStart = 0;
x2448_closure->loopSize = x3;
activation_x2448 * alloc = x2448_closure->alloc(resourceInfo);
activation_x2448 * x2448 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2448 = x2448_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2448*> * sync = new MultiLoopSync<activation_x2448*>(x2448_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2448_closure->allocVal = alloc;
x2448_closure->syncVal = sync;
submitWork(r->threadId, x2448_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2448_closure)));
i = i+1;
}
x2448 = x2448_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2448;
}

/**********/

