//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1306 * kernel_x1306(resourceInfo_t *resourceInfo,int32_t  x1301, bool  x215, cppDeliteArraybool  *x1300) {
class x1306_class{
public:
int32_t x1301;
bool x215;
cppDeliteArraybool *x1300;

x1306_class(int32_t  _x1301,bool  _x215,cppDeliteArraybool * _x1300) {
x1301 = _x1301;
x215 = _x215;
x1300 = _x1300;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1301;
}

int64_t loopStart;
int64_t loopSize;
activation_x1306 *alloc(resourceInfo_t *resourceInfo) {
activation_x1306 * __act = new activation_x1306();;
__act->x1306_zero = x215;
return __act;
}

activation_x1306 *main_par(resourceInfo_t *resourceInfo,activation_x1306 *__act,MultiLoopSync<activation_x1306*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1306 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1306 * act = sync->get(localStart);
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

activation_x1306 *main_seq(resourceInfo_t *resourceInfo,activation_x1306 *__act) {
activation_x1306 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1306 *processRange(resourceInfo_t *resourceInfo,activation_x1306 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1306 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1306 *init(resourceInfo_t *resourceInfo,activation_x1306 *__act,int32_t x217,bool isEmpty) {
activation_x1306 * __act2 = new activation_x1306();;
__act2->x1306_zero = __act->x1306_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1306 = __act2->x1306_zero;
if (!isEmpty) {
bool x1302 = x1300->apply(x217);
__act2->x1306 = x1302;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x1306 *__act,int32_t x217) {
bool x1302 = x1300->apply(x217);
bool x222 = __act->x1306;
bool x223 = x1302;
bool  x224 = x222 && x223;
__act->x1306 = x224;
}

void combine(resourceInfo_t *resourceInfo,activation_x1306 *__act,activation_x1306 *rhs) {
bool x222 = __act->x1306;
bool x223 = rhs->x1306;
if (x222 == __act->x1306_zero) {
__act->x1306 = x223;
}
else if (x223 != __act->x1306_zero) {
bool  x224 = x222 && x223;
__act->x1306 = x224;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1306 *__act,activation_x1306 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1306 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1306 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1306 *__act) {
}

activation_x1306 *initAct(resourceInfo_t *resourceInfo) {
activation_x1306 * act = new activation_x1306;
act->x1306_zero = x215;
return act;
}

activation_x1306 *allocVal;
MultiLoopSync<activation_x1306*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1306_class *closure = (x1306_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1306_class *x1306_closure = new x1306_class(x1301,x215,x1300);
x1306_closure->loopStart = 0;
x1306_closure->loopSize = x1301;
activation_x1306 * alloc = x1306_closure->alloc(resourceInfo);
activation_x1306 * x1306 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1306 = x1306_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1306*> * sync = new MultiLoopSync<activation_x1306*>(x1306_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1306_closure->allocVal = alloc;
x1306_closure->syncVal = sync;
submitWork(r->threadId, x1306_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1306_closure)));
i = i+1;
}
x1306 = x1306_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1306;
}

/**********/

