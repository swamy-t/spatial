//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1153 * kernel_x1153(resourceInfo_t *resourceInfo,int32_t  x1148, bool  x201, cppDeliteArraybool  *x1147) {
class x1153_class{
public:
int32_t x1148;
bool x201;
cppDeliteArraybool *x1147;

x1153_class(int32_t  _x1148,bool  _x201,cppDeliteArraybool * _x1147) {
x1148 = _x1148;
x201 = _x201;
x1147 = _x1147;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1148;
}

int64_t loopStart;
int64_t loopSize;
activation_x1153 *alloc(resourceInfo_t *resourceInfo) {
activation_x1153 * __act = new activation_x1153();;
__act->x1153_zero = x201;
return __act;
}

activation_x1153 *main_par(resourceInfo_t *resourceInfo,activation_x1153 *__act,MultiLoopSync<activation_x1153*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1153 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1153 * act = sync->get(localStart);
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

activation_x1153 *main_seq(resourceInfo_t *resourceInfo,activation_x1153 *__act) {
activation_x1153 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1153 *processRange(resourceInfo_t *resourceInfo,activation_x1153 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1153 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1153 *init(resourceInfo_t *resourceInfo,activation_x1153 *__act,int32_t x203,bool isEmpty) {
activation_x1153 * __act2 = new activation_x1153();;
__act2->x1153_zero = __act->x1153_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x1153 = __act2->x1153_zero;
if (!isEmpty) {
bool x1149 = x1147->apply(x203);
__act2->x1153 = x1149;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x1153 *__act,int32_t x203) {
bool x1149 = x1147->apply(x203);
bool x208 = __act->x1153;
bool x209 = x1149;
bool  x210 = x208 && x209;
__act->x1153 = x210;
}

void combine(resourceInfo_t *resourceInfo,activation_x1153 *__act,activation_x1153 *rhs) {
bool x208 = __act->x1153;
bool x209 = rhs->x1153;
if (x208 == __act->x1153_zero) {
__act->x1153 = x209;
}
else if (x209 != __act->x1153_zero) {
bool  x210 = x208 && x209;
__act->x1153 = x210;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1153 *__act,activation_x1153 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1153 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1153 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1153 *__act) {
}

activation_x1153 *initAct(resourceInfo_t *resourceInfo) {
activation_x1153 * act = new activation_x1153;
act->x1153_zero = x201;
return act;
}

activation_x1153 *allocVal;
MultiLoopSync<activation_x1153*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1153_class *closure = (x1153_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1153_class *x1153_closure = new x1153_class(x1148,x201,x1147);
x1153_closure->loopStart = 0;
x1153_closure->loopSize = x1148;
activation_x1153 * alloc = x1153_closure->alloc(resourceInfo);
activation_x1153 * x1153 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1153 = x1153_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1153*> * sync = new MultiLoopSync<activation_x1153*>(x1153_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1153_closure->allocVal = alloc;
x1153_closure->syncVal = sync;
submitWork(r->threadId, x1153_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1153_closure)));
i = i+1;
}
x1153 = x1153_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1153;
}

/**********/

