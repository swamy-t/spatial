//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6220 * kernel_x6220(resourceInfo_t *resourceInfo,int32_t  x6217, cppDeliteArrayint32_t  *x5835) {
class x6220_class{
public:
int32_t x6217;
cppDeliteArrayint32_t *x5835;

x6220_class(int32_t  _x6217,cppDeliteArrayint32_t * _x5835) {
x6217 = _x6217;
x5835 = _x5835;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6217;
}

int64_t loopStart;
int64_t loopSize;
activation_x6220 *alloc(resourceInfo_t *resourceInfo) {
activation_x6220 * __act = new activation_x6220();;
int32_t x992 = (int32_t)(loopSize);
assert(x992 < (size_t)-1);
cppDeliteArrayint32_t *x6082 = new (resourceInfo) cppDeliteArrayint32_t(x992);
__act->x6220_data = x6082;
return __act;
}

activation_x6220 *main_par(resourceInfo_t *resourceInfo,activation_x6220 *__act,MultiLoopSync<activation_x6220*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6220 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6220 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x6220 *main_seq(resourceInfo_t *resourceInfo,activation_x6220 *__act) {
activation_x6220 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6220 *processRange(resourceInfo_t *resourceInfo,activation_x6220 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6220 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6220 *init(resourceInfo_t *resourceInfo,activation_x6220 *__act,int32_t x987,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x987);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x6220 *__act,int32_t x987) {
int32_t x6080 = x5835->apply(x987);
int32_t x991 = x6080;
cppDeliteArrayint32_t *x990 = __act->x6220_data;
x990->update(x987, x991);
}

void combine(resourceInfo_t *resourceInfo,activation_x6220 *__act,activation_x6220 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6220 *__act,activation_x6220 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6220 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6220 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6220 *__act) {
cppDeliteArrayint32_t * x990 = __act->x6220_data;
__act->x6220 = x990;
}

activation_x6220 *initAct(resourceInfo_t *resourceInfo) {
activation_x6220 * act = new activation_x6220;
return act;
}

activation_x6220 *allocVal;
MultiLoopSync<activation_x6220*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6220_class *closure = (x6220_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6220_class *x6220_closure = new x6220_class(x6217,x5835);
x6220_closure->loopStart = 0;
x6220_closure->loopSize = x6217;
activation_x6220 * alloc = x6220_closure->alloc(resourceInfo);
activation_x6220 * x6220 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6220 = x6220_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6220*> * sync = new MultiLoopSync<activation_x6220*>(x6220_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6220_closure->allocVal = alloc;
x6220_closure->syncVal = sync;
submitWork(r->threadId, x6220_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6220_closure)));
i = i+1;
}
x6220 = x6220_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6220;
}

/**********/

