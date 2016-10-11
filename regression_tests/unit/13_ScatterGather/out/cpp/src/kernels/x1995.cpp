//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1995 * kernel_x1995(resourceInfo_t *resourceInfo,int32_t  x1947, cppDeliteArrayint32_t  *x1854, cppDeliteArrayint32_t  *x1939) {
class x1995_class{
public:
int32_t x1947;
cppDeliteArrayint32_t *x1854;
cppDeliteArrayint32_t *x1939;

x1995_class(int32_t  _x1947,cppDeliteArrayint32_t * _x1854,cppDeliteArrayint32_t * _x1939) {
x1947 = _x1947;
x1854 = _x1854;
x1939 = _x1939;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1947;
}

int64_t loopStart;
int64_t loopSize;
activation_x1995 *alloc(resourceInfo_t *resourceInfo) {
activation_x1995 * __act = new activation_x1995();;
int32_t x354 = (int32_t)(loopSize);
assert(x354 < (size_t)-1);
cppDeliteArraybool *x1959 = new (resourceInfo) cppDeliteArraybool(x354);
__act->x1995_data = x1959;
return __act;
}

activation_x1995 *main_par(resourceInfo_t *resourceInfo,activation_x1995 *__act,MultiLoopSync<activation_x1995*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1995 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1995 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1995 *main_seq(resourceInfo_t *resourceInfo,activation_x1995 *__act) {
activation_x1995 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1995 *processRange(resourceInfo_t *resourceInfo,activation_x1995 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1995 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1995 *init(resourceInfo_t *resourceInfo,activation_x1995 *__act,int32_t x347,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x347);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1995 *__act,int32_t x347) {
int32_t x1955 = x1854->apply(x347);
int32_t x1956 = x1939->apply(x347);
bool  x1957 = x1955 == x1956;
bool x353 = x1957;
cppDeliteArraybool *x352 = __act->x1995_data;
x352->update(x347, x353);
}

void combine(resourceInfo_t *resourceInfo,activation_x1995 *__act,activation_x1995 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1995 *__act,activation_x1995 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1995 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1995 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1995 *__act) {
cppDeliteArraybool * x352 = __act->x1995_data;
__act->x1995 = x352;
}

activation_x1995 *initAct(resourceInfo_t *resourceInfo) {
activation_x1995 * act = new activation_x1995;
return act;
}

activation_x1995 *allocVal;
MultiLoopSync<activation_x1995*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1995_class *closure = (x1995_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1995_class *x1995_closure = new x1995_class(x1947,x1854,x1939);
x1995_closure->loopStart = 0;
x1995_closure->loopSize = x1947;
activation_x1995 * alloc = x1995_closure->alloc(resourceInfo);
activation_x1995 * x1995 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1995 = x1995_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1995*> * sync = new MultiLoopSync<activation_x1995*>(x1995_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1995_closure->allocVal = alloc;
x1995_closure->syncVal = sync;
submitWork(r->threadId, x1995_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1995_closure)));
i = i+1;
}
x1995 = x1995_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1995;
}

/**********/

