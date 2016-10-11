//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3043 * kernel_x3043(resourceInfo_t *resourceInfo,int32_t  x3, cppDeliteArrayuint32_t  *x2631, uint32_t  x221, uint32_t  x295, cppDeliteArrayuint32_t  *x2670, uint32_t  x303, cppDeliteArrayint32_t  *x2710, int32_t  x195, int32_t  x300) {
class x3043_class{
public:
int32_t x3;
cppDeliteArrayuint32_t *x2631;
uint32_t x221;
uint32_t x295;
cppDeliteArrayuint32_t *x2670;
uint32_t x303;
cppDeliteArrayint32_t *x2710;
int32_t x195;
int32_t x300;

x3043_class(int32_t  _x3,cppDeliteArrayuint32_t * _x2631,uint32_t  _x221,uint32_t  _x295,cppDeliteArrayuint32_t * _x2670,uint32_t  _x303,cppDeliteArrayint32_t * _x2710,int32_t  _x195,int32_t  _x300) {
x3 = _x3;
x2631 = _x2631;
x221 = _x221;
x295 = _x295;
x2670 = _x2670;
x303 = _x303;
x2710 = _x2710;
x195 = _x195;
x300 = _x300;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x3;
}

int64_t loopStart;
int64_t loopSize;
activation_x3043 *alloc(resourceInfo_t *resourceInfo) {
activation_x3043 * __act = new activation_x3043();;
int32_t x360 = (int32_t)(loopSize);
assert(x360 < (size_t)-1);
cppDeliteArraybool *x3007 = new (resourceInfo) cppDeliteArraybool(x360);
__act->x3043_data = x3007;
return __act;
}

activation_x3043 *main_par(resourceInfo_t *resourceInfo,activation_x3043 *__act,MultiLoopSync<activation_x3043*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3043 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3043 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x3043 *main_seq(resourceInfo_t *resourceInfo,activation_x3043 *__act) {
activation_x3043 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3043 *processRange(resourceInfo_t *resourceInfo,activation_x3043 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3043 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3043 *init(resourceInfo_t *resourceInfo,activation_x3043 *__act,int32_t x343,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x343);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x3043 *__act,int32_t x343) {
int32_t  x344 = (int32_t) (x343);
int32_t  x345 = (int32_t) x344;
uint32_t x2995 = x2631->apply(x345);
bool  x2996 = x221 < x2995;
bool  x2997 = x2995 < x295;
bool  x2998 = x2996 && x2997;
uint32_t x2999 = x2670->apply(x345);
bool  x3000 = x2999 < x303;
bool  x3001 = x2998 && x3000;
int32_t x3002 = x2710->apply(x345);
bool  x3003 = x195 <= x3002;
bool  x3004 = x3001 && x3003;
bool  x3005 = x3002 <= x300;
bool  x3006 = x3004 && x3005;
bool x359 = x3006;
cppDeliteArraybool *x358 = __act->x3043_data;
x358->update(x343, x359);
}

void combine(resourceInfo_t *resourceInfo,activation_x3043 *__act,activation_x3043 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3043 *__act,activation_x3043 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3043 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3043 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3043 *__act) {
cppDeliteArraybool * x358 = __act->x3043_data;
__act->x3043 = x358;
}

activation_x3043 *initAct(resourceInfo_t *resourceInfo) {
activation_x3043 * act = new activation_x3043;
return act;
}

activation_x3043 *allocVal;
MultiLoopSync<activation_x3043*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3043_class *closure = (x3043_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3043_class *x3043_closure = new x3043_class(x3,x2631,x221,x295,x2670,x303,x2710,x195,x300);
x3043_closure->loopStart = 0;
x3043_closure->loopSize = x3;
activation_x3043 * alloc = x3043_closure->alloc(resourceInfo);
activation_x3043 * x3043 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3043 = x3043_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3043*> * sync = new MultiLoopSync<activation_x3043*>(x3043_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3043_closure->allocVal = alloc;
x3043_closure->syncVal = sync;
submitWork(r->threadId, x3043_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3043_closure)));
i = i+1;
}
x3043 = x3043_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3043;
}

/**********/

