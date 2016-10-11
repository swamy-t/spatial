//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5423 * kernel_x5423(resourceInfo_t *resourceInfo,int32_t  x5279, cppDeliteArrayint32_t  *x5035, cppDeliteArrayint32_t  *x5399) {
class x5423_class{
public:
int32_t x5279;
cppDeliteArrayint32_t *x5035;
cppDeliteArrayint32_t *x5399;

x5423_class(int32_t  _x5279,cppDeliteArrayint32_t * _x5035,cppDeliteArrayint32_t * _x5399) {
x5279 = _x5279;
x5035 = _x5035;
x5399 = _x5399;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x5279;
}

int64_t loopStart;
int64_t loopSize;
activation_x5423 *alloc(resourceInfo_t *resourceInfo) {
activation_x5423 * __act = new activation_x5423();;
int32_t x835 = (int32_t)(loopSize);
assert(x835 < (size_t)-1);
cppDeliteArraybool *x5331 = new (resourceInfo) cppDeliteArraybool(x835);
__act->x5423_data = x5331;
return __act;
}

activation_x5423 *main_par(resourceInfo_t *resourceInfo,activation_x5423 *__act,MultiLoopSync<activation_x5423*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5423 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5423 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x5423 *main_seq(resourceInfo_t *resourceInfo,activation_x5423 *__act) {
activation_x5423 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x5423 *processRange(resourceInfo_t *resourceInfo,activation_x5423 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5423 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5423 *init(resourceInfo_t *resourceInfo,activation_x5423 *__act,int32_t x828,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x828);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x5423 *__act,int32_t x828) {
int32_t x5327 = x5035->apply(x828);
int32_t x5418 = x5399->apply(x828);
bool  x5419 = x5327 == x5418;
bool x834 = x5419;
cppDeliteArraybool *x833 = __act->x5423_data;
x833->update(x828, x834);
}

void combine(resourceInfo_t *resourceInfo,activation_x5423 *__act,activation_x5423 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5423 *__act,activation_x5423 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5423 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5423 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x5423 *__act) {
cppDeliteArraybool * x833 = __act->x5423_data;
__act->x5423 = x833;
}

activation_x5423 *initAct(resourceInfo_t *resourceInfo) {
activation_x5423 * act = new activation_x5423;
return act;
}

activation_x5423 *allocVal;
MultiLoopSync<activation_x5423*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5423_class *closure = (x5423_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5423_class *x5423_closure = new x5423_class(x5279,x5035,x5399);
x5423_closure->loopStart = 0;
x5423_closure->loopSize = x5279;
activation_x5423 * alloc = x5423_closure->alloc(resourceInfo);
activation_x5423 * x5423 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5423 = x5423_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5423*> * sync = new MultiLoopSync<activation_x5423*>(x5423_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5423_closure->allocVal = alloc;
x5423_closure->syncVal = sync;
submitWork(r->threadId, x5423_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5423_closure)));
i = i+1;
}
x5423 = x5423_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5423;
}

/**********/

