//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1958x1980 * kernel_x1958x1980(resourceInfo_t *resourceInfo,int32_t  x6, int32_t  x53, cppDeliteArrayint32_t  *x1954, cppDeliteArrayint32_t  *x1916) {
class x1958x1980_class{
public:
int32_t x6;
int32_t x53;
cppDeliteArrayint32_t *x1954;
cppDeliteArrayint32_t *x1916;

x1958x1980_class(int32_t  _x6,int32_t  _x53,cppDeliteArrayint32_t * _x1954,cppDeliteArrayint32_t * _x1916) {
x6 = _x6;
x53 = _x53;
x1954 = _x1954;
x1916 = _x1916;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x6;
}

int64_t loopStart;
int64_t loopSize;
activation_x1958x1980 *alloc(resourceInfo_t *resourceInfo) {
activation_x1958x1980 * __act = new activation_x1958x1980();;
__act->x1958_zero = x53;
__act->x1980_zero = x53;
return __act;
}

activation_x1958x1980 *main_par(resourceInfo_t *resourceInfo,activation_x1958x1980 *__act,MultiLoopSync<activation_x1958x1980*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1958x1980 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1958x1980 * act = sync->get(localStart);
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

activation_x1958x1980 *main_seq(resourceInfo_t *resourceInfo,activation_x1958x1980 *__act) {
activation_x1958x1980 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1958x1980 *processRange(resourceInfo_t *resourceInfo,activation_x1958x1980 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1958x1980 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1958x1980 *init(resourceInfo_t *resourceInfo,activation_x1958x1980 *__act,int32_t x318,bool isEmpty) {
activation_x1958x1980 * __act2 = new activation_x1958x1980();;
__act2->x1958_zero = __act->x1958_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1958 = __act2->x1958_zero;
__act2->x1980_zero = __act->x1980_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1980 = __act2->x1980_zero;
if (!isEmpty) {
int32_t x1955 = x1954->apply(x318);
int32_t x1979 = x1916->apply(x318);
__act2->x1958 = x1955;
__act2->x1980 = x1979;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x1958x1980 *__act,int32_t x318) {
int32_t x1955 = x1954->apply(x318);
int32_t x1979 = x1916->apply(x318);
int32_t x322 = __act->x1958;
int32_t x323 = x1955;
int32_t  x324 = x322 + x323;
__act->x1958 = x324;
int32_t x339 = __act->x1980;
int32_t x340 = x1979;
int32_t  x341 = x339 + x340;
__act->x1980 = x341;
}

void combine(resourceInfo_t *resourceInfo,activation_x1958x1980 *__act,activation_x1958x1980 *rhs) {
int32_t x322 = __act->x1958;
int32_t x323 = rhs->x1958;
if (x322 == __act->x1958_zero) {
__act->x1958 = x323;
}
else if (x323 != __act->x1958_zero) {
int32_t  x324 = x322 + x323;
__act->x1958 = x324;
}
int32_t x339 = __act->x1980;
int32_t x340 = rhs->x1980;
if (x339 == __act->x1980_zero) {
__act->x1980 = x340;
}
else if (x340 != __act->x1980_zero) {
int32_t  x341 = x339 + x340;
__act->x1980 = x341;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1958x1980 *__act,activation_x1958x1980 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1958x1980 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1958x1980 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1958x1980 *__act) {
}

activation_x1958x1980 *initAct(resourceInfo_t *resourceInfo) {
activation_x1958x1980 * act = new activation_x1958x1980;
act->x1958_zero = x53;
act->x1980_zero = x53;
return act;
}

activation_x1958x1980 *allocVal;
MultiLoopSync<activation_x1958x1980*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1958x1980_class *closure = (x1958x1980_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1958x1980_class *x1958x1980_closure = new x1958x1980_class(x6,x53,x1954,x1916);
x1958x1980_closure->loopStart = 0;
x1958x1980_closure->loopSize = x6;
activation_x1958x1980 * alloc = x1958x1980_closure->alloc(resourceInfo);
activation_x1958x1980 * x1958x1980 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1958x1980 = x1958x1980_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1958x1980*> * sync = new MultiLoopSync<activation_x1958x1980*>(x1958x1980_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1958x1980_closure->allocVal = alloc;
x1958x1980_closure->syncVal = sync;
submitWork(r->threadId, x1958x1980_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1958x1980_closure)));
i = i+1;
}
x1958x1980 = x1958x1980_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1958x1980;
}

/**********/

