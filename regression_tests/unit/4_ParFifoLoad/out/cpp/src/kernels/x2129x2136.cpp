//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2129x2136 * kernel_x2129x2136(resourceInfo_t *resourceInfo,int32_t  x161, int32_t  x51) {
class x2129x2136_class{
public:
int32_t x161;
int32_t x51;

x2129x2136_class(int32_t  _x161,int32_t  _x51) {
x161 = _x161;
x51 = _x51;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x161;
}

int64_t loopStart;
int64_t loopSize;
activation_x2129x2136 *alloc(resourceInfo_t *resourceInfo) {
activation_x2129x2136 * __act = new activation_x2129x2136();;
int32_t x166 = (int32_t)(loopSize);
assert(x166 < (size_t)-1);
cppDeliteArrayint32_t *x1994 = new (resourceInfo) cppDeliteArrayint32_t(x166);
__act->x2129_data = x1994;
int32_t x212 = (int32_t)(loopSize);
assert(x212 < (size_t)-1);
cppDeliteArrayint32_t *x2031 = new (resourceInfo) cppDeliteArrayint32_t(x212);
__act->x2136_data = x2031;
return __act;
}

activation_x2129x2136 *main_par(resourceInfo_t *resourceInfo,activation_x2129x2136 *__act,MultiLoopSync<activation_x2129x2136*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2129x2136 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2129x2136 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2129x2136 *main_seq(resourceInfo_t *resourceInfo,activation_x2129x2136 *__act) {
activation_x2129x2136 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2129x2136 *processRange(resourceInfo_t *resourceInfo,activation_x2129x2136 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2129x2136 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2129x2136 *init(resourceInfo_t *resourceInfo,activation_x2129x2136 *__act,int32_t x162,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x162);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2129x2136 *__act,int32_t x162) {
int32_t  x163 = (int32_t) (x162);
int32_t  x2131 = x163 * x51;
int32_t x165 = x163;
cppDeliteArrayint32_t *x164 = __act->x2129_data;
x164->update(x162, x165);
int32_t x211 = x2131;
cppDeliteArrayint32_t *x210 = __act->x2136_data;
x210->update(x162, x211);
}

void combine(resourceInfo_t *resourceInfo,activation_x2129x2136 *__act,activation_x2129x2136 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2129x2136 *__act,activation_x2129x2136 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2129x2136 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2129x2136 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2129x2136 *__act) {
cppDeliteArrayint32_t * x164 = __act->x2129_data;
__act->x2129 = x164;
cppDeliteArrayint32_t * x210 = __act->x2136_data;
__act->x2136 = x210;
}

activation_x2129x2136 *initAct(resourceInfo_t *resourceInfo) {
activation_x2129x2136 * act = new activation_x2129x2136;
return act;
}

activation_x2129x2136 *allocVal;
MultiLoopSync<activation_x2129x2136*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2129x2136_class *closure = (x2129x2136_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2129x2136_class *x2129x2136_closure = new x2129x2136_class(x161,x51);
x2129x2136_closure->loopStart = 0;
x2129x2136_closure->loopSize = x161;
activation_x2129x2136 * alloc = x2129x2136_closure->alloc(resourceInfo);
activation_x2129x2136 * x2129x2136 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2129x2136 = x2129x2136_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2129x2136*> * sync = new MultiLoopSync<activation_x2129x2136*>(x2129x2136_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2129x2136_closure->allocVal = alloc;
x2129x2136_closure->syncVal = sync;
submitWork(r->threadId, x2129x2136_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2129x2136_closure)));
i = i+1;
}
x2129x2136 = x2129x2136_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2129x2136;
}

/**********/

