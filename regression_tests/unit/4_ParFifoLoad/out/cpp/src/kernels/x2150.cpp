//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2150 * kernel_x2150(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x96, cppDeliteArrayint32_t  *x2148) {
class x2150_class{
public:
int32_t x3;
int32_t x96;
cppDeliteArrayint32_t *x2148;

x2150_class(int32_t  _x3,int32_t  _x96,cppDeliteArrayint32_t * _x2148) {
x3 = _x3;
x96 = _x96;
x2148 = _x2148;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x2150 *alloc(resourceInfo_t *resourceInfo) {
activation_x2150 * __act = new activation_x2150();;
__act->x2150_zero = x96;
return __act;
}

activation_x2150 *main_par(resourceInfo_t *resourceInfo,activation_x2150 *__act,MultiLoopSync<activation_x2150*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2150 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2150 * act = sync->get(localStart);
//combine local
int32_t  i = localStart+1;
while (i < localEnd) {
combine(resourceInfo,act,sync->get(i));
i = i+1;
}
//combine remote
int32_t  half = tid;
int32_t  step = 1;
while ((half % 2 == 0) && (tid + step < numThreads)) {
combine(resourceInfo,act,sync->getC(tid+step));
half = half / 2;
step = step * 2;
}
sync->setC(tid,act);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2150 *main_seq(resourceInfo_t *resourceInfo,activation_x2150 *__act) {
activation_x2150 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2150 *processRange(resourceInfo_t *resourceInfo,activation_x2150 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2150 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2150 *init(resourceInfo_t *resourceInfo,activation_x2150 *__act,int32_t x300,bool isEmpty) {
activation_x2150 * __act2 = new activation_x2150();;
__act2->x2150_zero = __act->x2150_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x2150 = __act2->x2150_zero;
if (!isEmpty) {
int32_t x2149 = x2148->apply(x300);
__act2->x2150 = x2149;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x2150 *__act,int32_t x300) {
int32_t x2149 = x2148->apply(x300);
int32_t x304 = __act->x2150;
int32_t x305 = x2149;
int32_t  x306 = x304 + x305;
__act->x2150 = x306;
}

void combine(resourceInfo_t *resourceInfo,activation_x2150 *__act,activation_x2150 *rhs) {
int32_t x304 = __act->x2150;
int32_t x305 = rhs->x2150;
if (x304 == __act->x2150_zero) {
__act->x2150 = x305;
}
else if (x305 != __act->x2150_zero) {
int32_t  x306 = x304 + x305;
__act->x2150 = x306;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2150 *__act,activation_x2150 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2150 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2150 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2150 *__act) {
}

activation_x2150 *initAct(resourceInfo_t *resourceInfo) {
activation_x2150 * act = new activation_x2150;
act->x2150_zero = x96;
return act;
}

activation_x2150 *allocVal;
MultiLoopSync<activation_x2150*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2150_class *closure = (x2150_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2150_class *x2150_closure = new x2150_class(x3,x96,x2148);
x2150_closure->loopStart = 0;
x2150_closure->loopSize = x3;
activation_x2150 * alloc = x2150_closure->alloc(resourceInfo);
activation_x2150 * x2150 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2150 = x2150_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2150*> * sync = new MultiLoopSync<activation_x2150*>(x2150_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2150_closure->allocVal = alloc;
x2150_closure->syncVal = sync;
submitWork(r->threadId, x2150_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2150_closure)));
i = i+1;
}
x2150 = x2150_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2150;
}

/**********/

