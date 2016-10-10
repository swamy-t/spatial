//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2980 * kernel_x2980(resourceInfo_t *resourceInfo,int32_t  x2942, cppDeliteArrayint32_t  *x2941) {
class x2980_class{
public:
int32_t x2942;
cppDeliteArrayint32_t *x2941;

x2980_class(int32_t  _x2942,cppDeliteArrayint32_t * _x2941) {
x2942 = _x2942;
x2941 = _x2941;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x2942;
}

int64_t loopStart;
int64_t loopSize;
activation_x2980 *alloc(resourceInfo_t *resourceInfo) {
activation_x2980 * __act = new activation_x2980();;
int32_t x360 = (int32_t)(loopSize);
assert(x360 < (size_t)-1);
cppDeliteArrayint32_t *x2944 = new (resourceInfo) cppDeliteArrayint32_t(x360);
__act->x2980_data = x2944;
return __act;
}

activation_x2980 *main_par(resourceInfo_t *resourceInfo,activation_x2980 *__act,MultiLoopSync<activation_x2980*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2980 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2980 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2980 *main_seq(resourceInfo_t *resourceInfo,activation_x2980 *__act) {
activation_x2980 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2980 *processRange(resourceInfo_t *resourceInfo,activation_x2980 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2980 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2980 *init(resourceInfo_t *resourceInfo,activation_x2980 *__act,int32_t x356,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x356);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2980 *__act,int32_t x356) {
int32_t x2943 = x2941->apply(x356);
int32_t x359 = x2943;
cppDeliteArrayint32_t *x358 = __act->x2980_data;
x358->update(x356, x359);
}

void combine(resourceInfo_t *resourceInfo,activation_x2980 *__act,activation_x2980 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2980 *__act,activation_x2980 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2980 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2980 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2980 *__act) {
cppDeliteArrayint32_t * x358 = __act->x2980_data;
__act->x2980 = x358;
}

activation_x2980 *initAct(resourceInfo_t *resourceInfo) {
activation_x2980 * act = new activation_x2980;
return act;
}

activation_x2980 *allocVal;
MultiLoopSync<activation_x2980*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2980_class *closure = (x2980_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2980_class *x2980_closure = new x2980_class(x2942,x2941);
x2980_closure->loopStart = 0;
x2980_closure->loopSize = x2942;
activation_x2980 * alloc = x2980_closure->alloc(resourceInfo);
activation_x2980 * x2980 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2980 = x2980_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2980*> * sync = new MultiLoopSync<activation_x2980*>(x2980_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2980_closure->allocVal = alloc;
x2980_closure->syncVal = sync;
submitWork(r->threadId, x2980_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2980_closure)));
i = i+1;
}
x2980 = x2980_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2980;
}

/**********/

