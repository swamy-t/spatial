//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5376x6178 * kernel_x5376x6178(resourceInfo_t *resourceInfo,int32_t  x9, int32_t  x11, cppDeliteArrayint32_t  *x5489) {
class x5376x6178_class{
public:
int32_t x9;
int32_t x11;
cppDeliteArrayint32_t *x5489;

x5376x6178_class(int32_t  _x9,int32_t  _x11,cppDeliteArrayint32_t * _x5489) {
x9 = _x9;
x11 = _x11;
x5489 = _x5489;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x9;
}

int64_t loopStart;
int64_t loopSize;
activation_x5376x6178 *alloc(resourceInfo_t *resourceInfo) {
activation_x5376x6178 * __act = new activation_x5376x6178();;
int32_t x14 = (int32_t)(loopSize);
assert(x14 < (size_t)-1);
cppDeliteArrayint32_t *x5340 = new (resourceInfo) cppDeliteArrayint32_t(x14);
__act->x5376_data = x5340;
int32_t x146 = (int32_t)(loopSize);
assert(x146 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x5490 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x146);
__act->x6178_data = x5490;
return __act;
}

activation_x5376x6178 *main_par(resourceInfo_t *resourceInfo,activation_x5376x6178 *__act,MultiLoopSync<activation_x5376x6178*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5376x6178 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5376x6178 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x5376x6178 *main_seq(resourceInfo_t *resourceInfo,activation_x5376x6178 *__act) {
activation_x5376x6178 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x5376x6178 *processRange(resourceInfo_t *resourceInfo,activation_x5376x6178 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5376x6178 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5376x6178 *init(resourceInfo_t *resourceInfo,activation_x5376x6178 *__act,int32_t x10,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x10);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x5376x6178 *__act,int32_t x10) {
int32_t x13 = x11;
cppDeliteArrayint32_t *x12 = __act->x5376_data;
x12->update(x10, x13);
cppDeliteArrayint32_t *x145 = x5489;
cppDeliteArraycppDeliteArrayint32_t *x144 = __act->x6178_data;
x144->update(x10, x145);
}

void combine(resourceInfo_t *resourceInfo,activation_x5376x6178 *__act,activation_x5376x6178 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5376x6178 *__act,activation_x5376x6178 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5376x6178 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5376x6178 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x5376x6178 *__act) {
cppDeliteArrayint32_t * x12 = __act->x5376_data;
__act->x5376 = x12;
cppDeliteArraycppDeliteArrayint32_t * x144 = __act->x6178_data;
__act->x6178 = x144;
}

activation_x5376x6178 *initAct(resourceInfo_t *resourceInfo) {
activation_x5376x6178 * act = new activation_x5376x6178;
return act;
}

activation_x5376x6178 *allocVal;
MultiLoopSync<activation_x5376x6178*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5376x6178_class *closure = (x5376x6178_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5376x6178_class *x5376x6178_closure = new x5376x6178_class(x9,x11,x5489);
x5376x6178_closure->loopStart = 0;
x5376x6178_closure->loopSize = x9;
activation_x5376x6178 * alloc = x5376x6178_closure->alloc(resourceInfo);
activation_x5376x6178 * x5376x6178 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5376x6178 = x5376x6178_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5376x6178*> * sync = new MultiLoopSync<activation_x5376x6178*>(x5376x6178_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5376x6178_closure->allocVal = alloc;
x5376x6178_closure->syncVal = sync;
submitWork(r->threadId, x5376x6178_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5376x6178_closure)));
i = i+1;
}
x5376x6178 = x5376x6178_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5376x6178;
}

/**********/

