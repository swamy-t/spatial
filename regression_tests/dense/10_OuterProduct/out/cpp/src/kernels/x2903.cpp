//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2903 * kernel_x2903(resourceInfo_t *resourceInfo,int32_t  x5, cppDeliteArrayint32_t  *x2713, cppDeliteArrayint32_t  *x2751, int32_t  x51) {
class x2903_class{
public:
int32_t x5;
cppDeliteArrayint32_t *x2713;
cppDeliteArrayint32_t *x2751;
int32_t x51;

x2903_class(int32_t  _x5,cppDeliteArrayint32_t * _x2713,cppDeliteArrayint32_t * _x2751,int32_t  _x51) {
x5 = _x5;
x2713 = _x2713;
x2751 = _x2751;
x51 = _x51;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x5;
}

int64_t loopStart;
int64_t loopSize;
activation_x2903 *alloc(resourceInfo_t *resourceInfo) {
activation_x2903 * __act = new activation_x2903();;
int32_t x265 = (int32_t)(loopSize);
assert(x265 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x2867 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x265);
__act->x2903_data = x2867;
return __act;
}

activation_x2903 *main_par(resourceInfo_t *resourceInfo,activation_x2903 *__act,MultiLoopSync<activation_x2903*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2903 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2903 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2903 *main_seq(resourceInfo_t *resourceInfo,activation_x2903 *__act) {
activation_x2903 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2903 *processRange(resourceInfo_t *resourceInfo,activation_x2903 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2903 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2903 *init(resourceInfo_t *resourceInfo,activation_x2903 *__act,int32_t x211,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x211);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2903 *__act,int32_t x211) {
int32_t  x212 = (int32_t) (x211);
int32_t  x215 = (int32_t) x212;
int32_t x2827 = x2713->apply(x215);
int32_t  x222 = x51;
assert(x222 < (size_t)-1);
cppDeliteArrayint32_t *x2830 = new (resourceInfo) cppDeliteArrayint32_t(x222, resourceInfo);
cppDeliteArrayint32_t * x2866_data = x2830;
int32_t  x2866_size = 0;
int32_t  x2866_conditionals = 0;
int32_t  x213 = 0;
while (x213 < x51) {  // begin fat loop x2866
int32_t  x214 = (int32_t) (x213);
int32_t  x217 = (int32_t) x214;
int32_t x2828 = x2751->apply(x217);
int32_t  x2829 = x2827 * x2828;
int32_t x221 = x2829;
cppDeliteArrayint32_t *x220 = x2866_data;
x220->update(x213, x221);
x213 = x213 + 1;
} // end fat loop x2866
cppDeliteArrayint32_t *x220 = x2866_data;
cppDeliteArrayint32_t *x2866 = x220;
cppDeliteArrayint32_t *x264 = x2866;
cppDeliteArraycppDeliteArrayint32_t *x263 = __act->x2903_data;
x263->update(x211, x264);
}

void combine(resourceInfo_t *resourceInfo,activation_x2903 *__act,activation_x2903 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2903 *__act,activation_x2903 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2903 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2903 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2903 *__act) {
cppDeliteArraycppDeliteArrayint32_t * x263 = __act->x2903_data;
__act->x2903 = x263;
}

activation_x2903 *initAct(resourceInfo_t *resourceInfo) {
activation_x2903 * act = new activation_x2903;
return act;
}

activation_x2903 *allocVal;
MultiLoopSync<activation_x2903*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2903_class *closure = (x2903_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2903_class *x2903_closure = new x2903_class(x5,x2713,x2751,x51);
x2903_closure->loopStart = 0;
x2903_closure->loopSize = x5;
activation_x2903 * alloc = x2903_closure->alloc(resourceInfo);
activation_x2903 * x2903 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2903 = x2903_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2903*> * sync = new MultiLoopSync<activation_x2903*>(x2903_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2903_closure->allocVal = alloc;
x2903_closure->syncVal = sync;
submitWork(r->threadId, x2903_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2903_closure)));
i = i+1;
}
x2903 = x2903_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2903;
}

/**********/

