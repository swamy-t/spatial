//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1445 * kernel_x1445(resourceInfo_t *resourceInfo,int32_t  x1440, bool  x249, cppDeliteArraybool  *x1439) {
class x1445_class{
public:
int32_t x1440;
bool x249;
cppDeliteArraybool *x1439;

x1445_class(int32_t  _x1440,bool  _x249,cppDeliteArraybool * _x1439) {
x1440 = _x1440;
x249 = _x249;
x1439 = _x1439;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1440;
}

int64_t loopStart;
int64_t loopSize;
activation_x1445 *alloc(resourceInfo_t *resourceInfo) {
activation_x1445 * __act = new activation_x1445();;
__act->x1445_zero = x249;
return __act;
}

activation_x1445 *main_par(resourceInfo_t *resourceInfo,activation_x1445 *__act,MultiLoopSync<activation_x1445*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1445 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1445 * act = sync->get(localStart);
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

activation_x1445 *main_seq(resourceInfo_t *resourceInfo,activation_x1445 *__act) {
activation_x1445 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1445 *processRange(resourceInfo_t *resourceInfo,activation_x1445 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1445 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1445 *init(resourceInfo_t *resourceInfo,activation_x1445 *__act,int32_t x251,bool isEmpty) {
activation_x1445 * __act2 = new activation_x1445();;
__act2->x1445_zero = __act->x1445_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1445 = __act2->x1445_zero;
if (!isEmpty) {
bool x1441 = x1439->apply(x251);
__act2->x1445 = x1441;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x1445 *__act,int32_t x251) {
bool x1441 = x1439->apply(x251);
bool x256 = __act->x1445;
bool x257 = x1441;
bool  x258 = x256 && x257;
__act->x1445 = x258;
}

void combine(resourceInfo_t *resourceInfo,activation_x1445 *__act,activation_x1445 *rhs) {
bool x256 = __act->x1445;
bool x257 = rhs->x1445;
if (x256 == __act->x1445_zero) {
__act->x1445 = x257;
}
else if (x257 != __act->x1445_zero) {
bool  x258 = x256 && x257;
__act->x1445 = x258;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1445 *__act,activation_x1445 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1445 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1445 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1445 *__act) {
}

activation_x1445 *initAct(resourceInfo_t *resourceInfo) {
activation_x1445 * act = new activation_x1445;
act->x1445_zero = x249;
return act;
}

activation_x1445 *allocVal;
MultiLoopSync<activation_x1445*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1445_class *closure = (x1445_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1445_class *x1445_closure = new x1445_class(x1440,x249,x1439);
x1445_closure->loopStart = 0;
x1445_closure->loopSize = x1440;
activation_x1445 * alloc = x1445_closure->alloc(resourceInfo);
activation_x1445 * x1445 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1445 = x1445_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1445*> * sync = new MultiLoopSync<activation_x1445*>(x1445_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1445_closure->allocVal = alloc;
x1445_closure->syncVal = sync;
submitWork(r->threadId, x1445_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1445_closure)));
i = i+1;
}
x1445 = x1445_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1445;
}

/**********/

