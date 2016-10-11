//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x4759 * kernel_x4759(resourceInfo_t *resourceInfo,int32_t  x4754, bool  x730, cppDeliteArraybool  *x4753) {
class x4759_class{
public:
int32_t x4754;
bool x730;
cppDeliteArraybool *x4753;

x4759_class(int32_t  _x4754,bool  _x730,cppDeliteArraybool * _x4753) {
x4754 = _x4754;
x730 = _x730;
x4753 = _x4753;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x4754;
}

int64_t loopStart;
int64_t loopSize;
activation_x4759 *alloc(resourceInfo_t *resourceInfo) {
activation_x4759 * __act = new activation_x4759();;
__act->x4759_zero = x730;
return __act;
}

activation_x4759 *main_par(resourceInfo_t *resourceInfo,activation_x4759 *__act,MultiLoopSync<activation_x4759*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4759 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4759 * act = sync->get(localStart);
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

activation_x4759 *main_seq(resourceInfo_t *resourceInfo,activation_x4759 *__act) {
activation_x4759 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4759 *processRange(resourceInfo_t *resourceInfo,activation_x4759 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4759 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4759 *init(resourceInfo_t *resourceInfo,activation_x4759 *__act,int32_t x732,bool isEmpty) {
activation_x4759 * __act2 = new activation_x4759();;
__act2->x4759_zero = __act->x4759_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x4759 = __act2->x4759_zero;
if (!isEmpty) {
bool x4755 = x4753->apply(x732);
__act2->x4759 = x4755;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x4759 *__act,int32_t x732) {
bool x4755 = x4753->apply(x732);
bool x737 = __act->x4759;
bool x738 = x4755;
bool  x739 = x737 && x738;
__act->x4759 = x739;
}

void combine(resourceInfo_t *resourceInfo,activation_x4759 *__act,activation_x4759 *rhs) {
bool x737 = __act->x4759;
bool x738 = rhs->x4759;
if (x737 == __act->x4759_zero) {
__act->x4759 = x738;
}
else if (x738 != __act->x4759_zero) {
bool  x739 = x737 && x738;
__act->x4759 = x739;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4759 *__act,activation_x4759 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4759 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4759 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4759 *__act) {
}

activation_x4759 *initAct(resourceInfo_t *resourceInfo) {
activation_x4759 * act = new activation_x4759;
act->x4759_zero = x730;
return act;
}

activation_x4759 *allocVal;
MultiLoopSync<activation_x4759*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4759_class *closure = (x4759_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4759_class *x4759_closure = new x4759_class(x4754,x730,x4753);
x4759_closure->loopStart = 0;
x4759_closure->loopSize = x4754;
activation_x4759 * alloc = x4759_closure->alloc(resourceInfo);
activation_x4759 * x4759 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4759 = x4759_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4759*> * sync = new MultiLoopSync<activation_x4759*>(x4759_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4759_closure->allocVal = alloc;
x4759_closure->syncVal = sync;
submitWork(r->threadId, x4759_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4759_closure)));
i = i+1;
}
x4759 = x4759_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4759;
}

/**********/

