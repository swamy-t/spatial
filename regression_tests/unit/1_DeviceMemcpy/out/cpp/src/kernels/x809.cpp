//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x809 * kernel_x809(resourceInfo_t *resourceInfo,int32_t  x768, cppDeliteArrayint32_t  *x753, cppDeliteArrayint32_t  *x745) {
class x809_class{
public:
int32_t x768;
cppDeliteArrayint32_t *x753;
cppDeliteArrayint32_t *x745;

x809_class(int32_t  _x768,cppDeliteArrayint32_t * _x753,cppDeliteArrayint32_t * _x745) {
x768 = _x768;
x753 = _x753;
x745 = _x745;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x768;
}

int64_t loopStart;
int64_t loopSize;
activation_x809 *alloc(resourceInfo_t *resourceInfo) {
activation_x809 * __act = new activation_x809();;
int32_t x91 = (int32_t)(loopSize);
assert(x91 < (size_t)-1);
cppDeliteArraybool *x773 = new (resourceInfo) cppDeliteArraybool(x91);
__act->x809_data = x773;
return __act;
}

activation_x809 *main_par(resourceInfo_t *resourceInfo,activation_x809 *__act,MultiLoopSync<activation_x809*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x809 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x809 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x809 *main_seq(resourceInfo_t *resourceInfo,activation_x809 *__act) {
activation_x809 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x809 *processRange(resourceInfo_t *resourceInfo,activation_x809 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x809 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x809 *init(resourceInfo_t *resourceInfo,activation_x809 *__act,int32_t x84,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x84);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x809 *__act,int32_t x84) {
int32_t x769 = x753->apply(x84);
int32_t x770 = x745->apply(x84);
bool  x771 = x769 == x770;
bool x90 = x771;
cppDeliteArraybool *x89 = __act->x809_data;
x89->update(x84, x90);
}

void combine(resourceInfo_t *resourceInfo,activation_x809 *__act,activation_x809 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x809 *__act,activation_x809 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x809 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x809 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x809 *__act) {
cppDeliteArraybool * x89 = __act->x809_data;
__act->x809 = x89;
}

activation_x809 *initAct(resourceInfo_t *resourceInfo) {
activation_x809 * act = new activation_x809;
return act;
}

activation_x809 *allocVal;
MultiLoopSync<activation_x809*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x809_class *closure = (x809_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x809_class *x809_closure = new x809_class(x768,x753,x745);
x809_closure->loopStart = 0;
x809_closure->loopSize = x768;
activation_x809 * alloc = x809_closure->alloc(resourceInfo);
activation_x809 * x809 = NULL;
if (resourceInfo->availableThreads <= 1) {
x809 = x809_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x809*> * sync = new MultiLoopSync<activation_x809*>(x809_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x809_closure->allocVal = alloc;
x809_closure->syncVal = sync;
submitWork(r->threadId, x809_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x809_closure)));
i = i+1;
}
x809 = x809_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x809;
}

/**********/

