//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x4753 * kernel_x4753(resourceInfo_t *resourceInfo,int32_t  x4701, cppDeliteArrayfloat  *x4568, float  x412, cppDeliteArrayfloat  *x4693) {
class x4753_class{
public:
int32_t x4701;
cppDeliteArrayfloat *x4568;
float x412;
cppDeliteArrayfloat *x4693;

x4753_class(int32_t  _x4701,cppDeliteArrayfloat * _x4568,float  _x412,cppDeliteArrayfloat * _x4693) {
x4701 = _x4701;
x4568 = _x4568;
x412 = _x412;
x4693 = _x4693;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x4701;
}

int64_t loopStart;
int64_t loopSize;
activation_x4753 *alloc(resourceInfo_t *resourceInfo) {
activation_x4753 * __act = new activation_x4753();;
int32_t x689 = (int32_t)(loopSize);
assert(x689 < (size_t)-1);
cppDeliteArraybool *x4717 = new (resourceInfo) cppDeliteArraybool(x689);
__act->x4753_data = x4717;
return __act;
}

activation_x4753 *main_par(resourceInfo_t *resourceInfo,activation_x4753 *__act,MultiLoopSync<activation_x4753*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4753 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4753 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4753 *main_seq(resourceInfo_t *resourceInfo,activation_x4753 *__act) {
activation_x4753 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4753 *processRange(resourceInfo_t *resourceInfo,activation_x4753 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4753 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4753 *init(resourceInfo_t *resourceInfo,activation_x4753 *__act,int32_t x678,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x678);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4753 *__act,int32_t x678) {
float x4709 = x4568->apply(x678);
float  x4710 = x4709 + x412;
float x4711 = x4693->apply(x678);
bool  x4712 = x4711 < x4710;
float  x4713 = x4709 - x412;
bool  x4714 = x4713 < x4711;
bool  x4715 = x4712 && x4714;
bool x688 = x4715;
cppDeliteArraybool *x687 = __act->x4753_data;
x687->update(x678, x688);
}

void combine(resourceInfo_t *resourceInfo,activation_x4753 *__act,activation_x4753 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4753 *__act,activation_x4753 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4753 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4753 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4753 *__act) {
cppDeliteArraybool * x687 = __act->x4753_data;
__act->x4753 = x687;
}

activation_x4753 *initAct(resourceInfo_t *resourceInfo) {
activation_x4753 * act = new activation_x4753;
return act;
}

activation_x4753 *allocVal;
MultiLoopSync<activation_x4753*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4753_class *closure = (x4753_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4753_class *x4753_closure = new x4753_class(x4701,x4568,x412,x4693);
x4753_closure->loopStart = 0;
x4753_closure->loopSize = x4701;
activation_x4753 * alloc = x4753_closure->alloc(resourceInfo);
activation_x4753 * x4753 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4753 = x4753_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4753*> * sync = new MultiLoopSync<activation_x4753*>(x4753_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4753_closure->allocVal = alloc;
x4753_closure->syncVal = sync;
submitWork(r->threadId, x4753_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4753_closure)));
i = i+1;
}
x4753 = x4753_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4753;
}

/**********/

