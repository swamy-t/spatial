//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1954 * kernel_x1954(resourceInfo_t *resourceInfo,int32_t  x6, cppDeliteArrayint32_t  *x1916) {
class x1954_class{
public:
int32_t x6;
cppDeliteArrayint32_t *x1916;

x1954_class(int32_t  _x6,cppDeliteArrayint32_t * _x1916) {
x6 = _x6;
x1916 = _x1916;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6;
}

int64_t loopStart;
int64_t loopSize;
activation_x1954 *alloc(resourceInfo_t *resourceInfo) {
activation_x1954 * __act = new activation_x1954();;
int32_t x277 = (int32_t)(loopSize);
assert(x277 < (size_t)-1);
cppDeliteArrayint32_t *x1918 = new (resourceInfo) cppDeliteArrayint32_t(x277);
__act->x1954_data = x1918;
return __act;
}

activation_x1954 *main_par(resourceInfo_t *resourceInfo,activation_x1954 *__act,MultiLoopSync<activation_x1954*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1954 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1954 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1954 *main_seq(resourceInfo_t *resourceInfo,activation_x1954 *__act) {
activation_x1954 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1954 *processRange(resourceInfo_t *resourceInfo,activation_x1954 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1954 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1954 *init(resourceInfo_t *resourceInfo,activation_x1954 *__act,int32_t x273,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x273);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1954 *__act,int32_t x273) {
int32_t x1917 = x1916->apply(x273);
int32_t x276 = x1917;
cppDeliteArrayint32_t *x275 = __act->x1954_data;
x275->update(x273, x276);
}

void combine(resourceInfo_t *resourceInfo,activation_x1954 *__act,activation_x1954 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1954 *__act,activation_x1954 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1954 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1954 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1954 *__act) {
cppDeliteArrayint32_t * x275 = __act->x1954_data;
__act->x1954 = x275;
}

activation_x1954 *initAct(resourceInfo_t *resourceInfo) {
activation_x1954 * act = new activation_x1954;
return act;
}

activation_x1954 *allocVal;
MultiLoopSync<activation_x1954*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1954_class *closure = (x1954_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1954_class *x1954_closure = new x1954_class(x6,x1916);
x1954_closure->loopStart = 0;
x1954_closure->loopSize = x6;
activation_x1954 * alloc = x1954_closure->alloc(resourceInfo);
activation_x1954 * x1954 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1954 = x1954_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1954*> * sync = new MultiLoopSync<activation_x1954*>(x1954_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1954_closure->allocVal = alloc;
x1954_closure->syncVal = sync;
submitWork(r->threadId, x1954_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1954_closure)));
i = i+1;
}
x1954 = x1954_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1954;
}

/**********/

