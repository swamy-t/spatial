//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1147 * kernel_x1147(resourceInfo_t *resourceInfo,int32_t  x1099, cppDeliteArrayint32_t  *x1089, cppDeliteArrayint32_t  *x1041) {
class x1147_class{
public:
int32_t x1099;
cppDeliteArrayint32_t *x1089;
cppDeliteArrayint32_t *x1041;

x1147_class(int32_t  _x1099,cppDeliteArrayint32_t * _x1089,cppDeliteArrayint32_t * _x1041) {
x1099 = _x1099;
x1089 = _x1089;
x1041 = _x1041;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1099;
}

int64_t loopStart;
int64_t loopSize;
activation_x1147 *alloc(resourceInfo_t *resourceInfo) {
activation_x1147 * __act = new activation_x1147();;
int32_t x160 = (int32_t)(loopSize);
assert(x160 < (size_t)-1);
cppDeliteArraybool *x1111 = new (resourceInfo) cppDeliteArraybool(x160);
__act->x1147_data = x1111;
return __act;
}

activation_x1147 *main_par(resourceInfo_t *resourceInfo,activation_x1147 *__act,MultiLoopSync<activation_x1147*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1147 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1147 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1147 *main_seq(resourceInfo_t *resourceInfo,activation_x1147 *__act) {
activation_x1147 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1147 *processRange(resourceInfo_t *resourceInfo,activation_x1147 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1147 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1147 *init(resourceInfo_t *resourceInfo,activation_x1147 *__act,int32_t x153,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x153);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1147 *__act,int32_t x153) {
int32_t x1107 = x1089->apply(x153);
int32_t x1108 = x1041->apply(x153);
bool  x1109 = x1107 == x1108;
bool x159 = x1109;
cppDeliteArraybool *x158 = __act->x1147_data;
x158->update(x153, x159);
}

void combine(resourceInfo_t *resourceInfo,activation_x1147 *__act,activation_x1147 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1147 *__act,activation_x1147 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1147 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1147 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1147 *__act) {
cppDeliteArraybool * x158 = __act->x1147_data;
__act->x1147 = x158;
}

activation_x1147 *initAct(resourceInfo_t *resourceInfo) {
activation_x1147 * act = new activation_x1147;
return act;
}

activation_x1147 *allocVal;
MultiLoopSync<activation_x1147*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1147_class *closure = (x1147_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1147_class *x1147_closure = new x1147_class(x1099,x1089,x1041);
x1147_closure->loopStart = 0;
x1147_closure->loopSize = x1099;
activation_x1147 * alloc = x1147_closure->alloc(resourceInfo);
activation_x1147 * x1147 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1147 = x1147_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1147*> * sync = new MultiLoopSync<activation_x1147*>(x1147_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1147_closure->allocVal = alloc;
x1147_closure->syncVal = sync;
submitWork(r->threadId, x1147_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1147_closure)));
i = i+1;
}
x1147 = x1147_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1147;
}

/**********/

