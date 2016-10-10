//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1386 * kernel_x1386(resourceInfo_t *resourceInfo,int32_t  x1381, bool  x228, cppDeliteArraybool  *x1380) {
class x1386_class{
public:
int32_t x1381;
bool x228;
cppDeliteArraybool *x1380;

x1386_class(int32_t  _x1381,bool  _x228,cppDeliteArraybool * _x1380) {
x1381 = _x1381;
x228 = _x228;
x1380 = _x1380;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1381;
}

int64_t loopStart;
int64_t loopSize;
activation_x1386 *alloc(resourceInfo_t *resourceInfo) {
activation_x1386 * __act = new activation_x1386();;
__act->x1386_zero = x228;
return __act;
}

activation_x1386 *main_par(resourceInfo_t *resourceInfo,activation_x1386 *__act,MultiLoopSync<activation_x1386*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1386 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1386 * act = sync->get(localStart);
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

activation_x1386 *main_seq(resourceInfo_t *resourceInfo,activation_x1386 *__act) {
activation_x1386 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1386 *processRange(resourceInfo_t *resourceInfo,activation_x1386 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1386 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1386 *init(resourceInfo_t *resourceInfo,activation_x1386 *__act,int32_t x230,bool isEmpty) {
activation_x1386 * __act2 = new activation_x1386();;
__act2->x1386_zero = __act->x1386_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1386 = __act2->x1386_zero;
if (!isEmpty) {
bool x1382 = x1380->apply(x230);
__act2->x1386 = x1382;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x1386 *__act,int32_t x230) {
bool x1382 = x1380->apply(x230);
bool x235 = __act->x1386;
bool x236 = x1382;
bool  x237 = x235 && x236;
__act->x1386 = x237;
}

void combine(resourceInfo_t *resourceInfo,activation_x1386 *__act,activation_x1386 *rhs) {
bool x235 = __act->x1386;
bool x236 = rhs->x1386;
if (x235 == __act->x1386_zero) {
__act->x1386 = x236;
}
else if (x236 != __act->x1386_zero) {
bool  x237 = x235 && x236;
__act->x1386 = x237;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1386 *__act,activation_x1386 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1386 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1386 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1386 *__act) {
}

activation_x1386 *initAct(resourceInfo_t *resourceInfo) {
activation_x1386 * act = new activation_x1386;
act->x1386_zero = x228;
return act;
}

activation_x1386 *allocVal;
MultiLoopSync<activation_x1386*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1386_class *closure = (x1386_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1386_class *x1386_closure = new x1386_class(x1381,x228,x1380);
x1386_closure->loopStart = 0;
x1386_closure->loopSize = x1381;
activation_x1386 * alloc = x1386_closure->alloc(resourceInfo);
activation_x1386 * x1386 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1386 = x1386_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1386*> * sync = new MultiLoopSync<activation_x1386*>(x1386_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1386_closure->allocVal = alloc;
x1386_closure->syncVal = sync;
submitWork(r->threadId, x1386_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1386_closure)));
i = i+1;
}
x1386 = x1386_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1386;
}

/**********/

