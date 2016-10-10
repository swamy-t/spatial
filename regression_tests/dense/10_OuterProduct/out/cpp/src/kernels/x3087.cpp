//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3087 * kernel_x3087(resourceInfo_t *resourceInfo,int32_t  x3082, bool  x528, cppDeliteArraybool  *x3081) {
class x3087_class{
public:
int32_t x3082;
bool x528;
cppDeliteArraybool *x3081;

x3087_class(int32_t  _x3082,bool  _x528,cppDeliteArraybool * _x3081) {
x3082 = _x3082;
x528 = _x528;
x3081 = _x3081;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3082;
}

int64_t loopStart;
int64_t loopSize;
activation_x3087 *alloc(resourceInfo_t *resourceInfo) {
activation_x3087 * __act = new activation_x3087();;
__act->x3087_zero = x528;
return __act;
}

activation_x3087 *main_par(resourceInfo_t *resourceInfo,activation_x3087 *__act,MultiLoopSync<activation_x3087*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3087 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3087 * act = sync->get(localStart);
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

activation_x3087 *main_seq(resourceInfo_t *resourceInfo,activation_x3087 *__act) {
activation_x3087 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3087 *processRange(resourceInfo_t *resourceInfo,activation_x3087 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3087 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3087 *init(resourceInfo_t *resourceInfo,activation_x3087 *__act,int32_t x530,bool isEmpty) {
activation_x3087 * __act2 = new activation_x3087();;
__act2->x3087_zero = __act->x3087_zero;
if (isEmpty) // stripping the first iter: only initialize to zero if empty
__act2->x3087 = __act2->x3087_zero;
if (!isEmpty) {
bool x3083 = x3081->apply(x530);
__act2->x3087 = x3083;
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x3087 *__act,int32_t x530) {
bool x3083 = x3081->apply(x530);
bool x535 = __act->x3087;
bool x536 = x3083;
bool  x537 = x535 && x536;
__act->x3087 = x537;
}

void combine(resourceInfo_t *resourceInfo,activation_x3087 *__act,activation_x3087 *rhs) {
bool x535 = __act->x3087;
bool x536 = rhs->x3087;
if (x535 == __act->x3087_zero) {
__act->x3087 = x536;
}
else if (x536 != __act->x3087_zero) {
bool  x537 = x535 && x536;
__act->x3087 = x537;
}
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3087 *__act,activation_x3087 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3087 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3087 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3087 *__act) {
}

activation_x3087 *initAct(resourceInfo_t *resourceInfo) {
activation_x3087 * act = new activation_x3087;
act->x3087_zero = x528;
return act;
}

activation_x3087 *allocVal;
MultiLoopSync<activation_x3087*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3087_class *closure = (x3087_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3087_class *x3087_closure = new x3087_class(x3082,x528,x3081);
x3087_closure->loopStart = 0;
x3087_closure->loopSize = x3082;
activation_x3087 * alloc = x3087_closure->alloc(resourceInfo);
activation_x3087 * x3087 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3087 = x3087_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3087*> * sync = new MultiLoopSync<activation_x3087*>(x3087_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3087_closure->allocVal = alloc;
x3087_closure->syncVal = sync;
submitWork(r->threadId, x3087_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3087_closure)));
i = i+1;
}
x3087 = x3087_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3087;
}

/**********/

