//activation record for thin loop
#include "cpphelperFuncs.h"
activation_x4279 * kernel_x4279(resourceInfo_t *resourceInfo,int32_t  x6, int32_t  x9) {
// a *thin* loop follows: x4279
class x4279_class{
public:
int32_t x6;
int32_t x9;

x4279_class(int32_t  _x6,int32_t  _x9) {
x6 = _x6;
x9 = _x9;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6;
}

int64_t loopStart;
int64_t loopSize;
activation_x4279 *alloc(resourceInfo_t *resourceInfo) {
activation_x4279 * __act = new activation_x4279();;
int32_t x58 = (int32_t)(loopSize);
assert(x58 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x4243 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x58);
__act->x4279_data = x4243;
return __act;
}

activation_x4279 *main_par(resourceInfo_t *resourceInfo,activation_x4279 *__act,MultiLoopSync<activation_x4279*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4279 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4279 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4279 *main_seq(resourceInfo_t *resourceInfo,activation_x4279 *__act) {
activation_x4279 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4279 *processRange(resourceInfo_t *resourceInfo,activation_x4279 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4279 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4279 *init(resourceInfo_t *resourceInfo,activation_x4279 *__act,int32_t x7,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x7);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4279 *__act,int32_t x7) {
// a *thin* loop follows: x4241
int32_t  x14 = x6;
assert(x14 < (size_t)-1);
cppDeliteArrayint32_t *x4205 = new (resourceInfo) cppDeliteArrayint32_t(x14, resourceInfo);
cppDeliteArrayint32_t * x4241_data = x4205;
int32_t  x4241_size = 0;
int32_t  x4241_conditionals = 0;
int32_t  x8 = 0;
while (x8 < x6) {  // begin fat loop x4241
int32_t  x4203 = (int32_t) rand() % x9;
int32_t x13 = x4203;
cppDeliteArrayint32_t *x12 = x4241_data;
x12->update(x8, x13);
x8 = x8 + 1;
} // end fat loop x4241
cppDeliteArrayint32_t *x12 = x4241_data;
cppDeliteArrayint32_t *x4241 = x12;
cppDeliteArrayint32_t *x57 = x4241;
cppDeliteArraycppDeliteArrayint32_t *x56 = __act->x4279_data;
x56->update(x7, x57);
}

void combine(resourceInfo_t *resourceInfo,activation_x4279 *__act,activation_x4279 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4279 *__act,activation_x4279 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4279 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4279 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4279 *__act) {
cppDeliteArraycppDeliteArrayint32_t * x56 = __act->x4279_data;
__act->x4279 = x56;
}

activation_x4279 *initAct(resourceInfo_t *resourceInfo) {
activation_x4279 * act = new activation_x4279;
return act;
}

activation_x4279 *allocVal;
MultiLoopSync<activation_x4279*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4279_class *closure = (x4279_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4279_class *x4279_closure = new x4279_class(x6,x9);
x4279_closure->loopStart = 0;
x4279_closure->loopSize = x6;
activation_x4279 * alloc = x4279_closure->alloc(resourceInfo);
activation_x4279 * x4279 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4279 = x4279_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4279*> * sync = new MultiLoopSync<activation_x4279*>(x4279_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4279_closure->allocVal = alloc;
x4279_closure->syncVal = sync;
submitWork(r->threadId, x4279_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4279_closure)));
i = i+1;
}
x4279 = x4279_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4279;
}

/**********/

