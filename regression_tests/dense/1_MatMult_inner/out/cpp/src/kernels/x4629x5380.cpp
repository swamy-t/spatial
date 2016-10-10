//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x4629x5380 * kernel_x4629x5380(resourceInfo_t *resourceInfo,int32_t  x9, int32_t  x11, cppDeliteArrayint32_t  *x4742) {
class x4629x5380_class{
public:
int32_t x9;
int32_t x11;
cppDeliteArrayint32_t *x4742;

x4629x5380_class(int32_t  _x9,int32_t  _x11,cppDeliteArrayint32_t * _x4742) {
x9 = _x9;
x11 = _x11;
x4742 = _x4742;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x9;
}

int64_t loopStart;
int64_t loopSize;
activation_x4629x5380 *alloc(resourceInfo_t *resourceInfo) {
activation_x4629x5380 * __act = new activation_x4629x5380();;
int32_t x14 = (int32_t)(loopSize);
assert(x14 < (size_t)-1);
cppDeliteArrayint32_t *x4593 = new (resourceInfo) cppDeliteArrayint32_t(x14);
__act->x4629_data = x4593;
int32_t x146 = (int32_t)(loopSize);
assert(x146 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x4743 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x146);
__act->x5380_data = x4743;
return __act;
}

activation_x4629x5380 *main_par(resourceInfo_t *resourceInfo,activation_x4629x5380 *__act,MultiLoopSync<activation_x4629x5380*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4629x5380 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4629x5380 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4629x5380 *main_seq(resourceInfo_t *resourceInfo,activation_x4629x5380 *__act) {
activation_x4629x5380 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4629x5380 *processRange(resourceInfo_t *resourceInfo,activation_x4629x5380 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4629x5380 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4629x5380 *init(resourceInfo_t *resourceInfo,activation_x4629x5380 *__act,int32_t x10,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x10);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4629x5380 *__act,int32_t x10) {
int32_t x13 = x11;
cppDeliteArrayint32_t *x12 = __act->x4629_data;
x12->update(x10, x13);
cppDeliteArrayint32_t *x145 = x4742;
cppDeliteArraycppDeliteArrayint32_t *x144 = __act->x5380_data;
x144->update(x10, x145);
}

void combine(resourceInfo_t *resourceInfo,activation_x4629x5380 *__act,activation_x4629x5380 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4629x5380 *__act,activation_x4629x5380 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4629x5380 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4629x5380 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4629x5380 *__act) {
cppDeliteArrayint32_t * x12 = __act->x4629_data;
__act->x4629 = x12;
cppDeliteArraycppDeliteArrayint32_t * x144 = __act->x5380_data;
__act->x5380 = x144;
}

activation_x4629x5380 *initAct(resourceInfo_t *resourceInfo) {
activation_x4629x5380 * act = new activation_x4629x5380;
return act;
}

activation_x4629x5380 *allocVal;
MultiLoopSync<activation_x4629x5380*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4629x5380_class *closure = (x4629x5380_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4629x5380_class *x4629x5380_closure = new x4629x5380_class(x9,x11,x4742);
x4629x5380_closure->loopStart = 0;
x4629x5380_closure->loopSize = x9;
activation_x4629x5380 * alloc = x4629x5380_closure->alloc(resourceInfo);
activation_x4629x5380 * x4629x5380 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4629x5380 = x4629x5380_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4629x5380*> * sync = new MultiLoopSync<activation_x4629x5380*>(x4629x5380_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4629x5380_closure->allocVal = alloc;
x4629x5380_closure->syncVal = sync;
submitWork(r->threadId, x4629x5380_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4629x5380_closure)));
i = i+1;
}
x4629x5380 = x4629x5380_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4629x5380;
}

/**********/

