//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1197 * kernel_x1197(resourceInfo_t *resourceInfo,int32_t  x1192, bool  x194, cppDeliteArraybool  *x1191) {
class x1197_class{
public:
int32_t x1192;
bool x194;
cppDeliteArraybool *x1191;

x1197_class(int32_t  _x1192,bool  _x194,cppDeliteArraybool * _x1191) {
x1192 = _x1192;
x194 = _x194;
x1191 = _x1191;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1192;
}

int64_t loopStart;
int64_t loopSize;
activation_x1197 *alloc(resourceInfo_t *resourceInfo) {
activation_x1197 * __act = new activation_x1197();;
__act->x1197_zero = x194;
return __act;
}

activation_x1197 *main_par(resourceInfo_t *resourceInfo,activation_x1197 *__act,MultiLoopSync<activation_x1197*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1197 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1197 * act = sync->get(localStart);
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

activation_x1197 *main_seq(resourceInfo_t *resourceInfo,activation_x1197 *__act) {
activation_x1197 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1197 *processRange(resourceInfo_t *resourceInfo,activation_x1197 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1197 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1197 *init(resourceInfo_t *resourceInfo,activation_x1197 *__act,int32_t x196,bool isEmpty) {
activation_x1197 * __act2 = new activation_x1197();;
__act2->x1197_zero = __act->x1197_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1197 = __act2->x1197_zero;
if (!isEmpty) {
bool x1193 = x1191->apply(x196);
__act2->x1197 = x1193;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x1197 *__act,int32_t x196) {
bool x1193 = x1191->apply(x196);
bool x201 = __act->x1197;
bool x202 = x1193;
bool  x203 = x201 && x202;
__act->x1197 = x203;
}

void combine(resourceInfo_t *resourceInfo,activation_x1197 *__act,activation_x1197 *rhs) {
bool x201 = __act->x1197;
bool x202 = rhs->x1197;
if (x201 == __act->x1197_zero) {
__act->x1197 = x202;
}
else if (x202 != __act->x1197_zero) {
bool  x203 = x201 && x202;
__act->x1197 = x203;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1197 *__act,activation_x1197 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1197 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1197 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1197 *__act) {
}

activation_x1197 *initAct(resourceInfo_t *resourceInfo) {
activation_x1197 * act = new activation_x1197;
act->x1197_zero = x194;
return act;
}

activation_x1197 *allocVal;
MultiLoopSync<activation_x1197*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1197_class *closure = (x1197_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1197_class *x1197_closure = new x1197_class(x1192,x194,x1191);
x1197_closure->loopStart = 0;
x1197_closure->loopSize = x1192;
activation_x1197 * alloc = x1197_closure->alloc(resourceInfo);
activation_x1197 * x1197 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1197 = x1197_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1197*> * sync = new MultiLoopSync<activation_x1197*>(x1197_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1197_closure->allocVal = alloc;
x1197_closure->syncVal = sync;
submitWork(r->threadId, x1197_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1197_closure)));
i = i+1;
}
x1197 = x1197_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1197;
}

/**********/

