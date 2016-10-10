//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1191 * kernel_x1191(resourceInfo_t *resourceInfo,int32_t  x1150, cppDeliteArrayint32_t  *x1096, cppDeliteArrayint32_t  *x1136) {
class x1191_class{
public:
int32_t x1150;
cppDeliteArrayint32_t *x1096;
cppDeliteArrayint32_t *x1136;

x1191_class(int32_t  _x1150,cppDeliteArrayint32_t * _x1096,cppDeliteArrayint32_t * _x1136) {
x1150 = _x1150;
x1096 = _x1096;
x1136 = _x1136;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1150;
}

int64_t loopStart;
int64_t loopSize;
activation_x1191 *alloc(resourceInfo_t *resourceInfo) {
activation_x1191 * __act = new activation_x1191();;
int32_t x153 = (int32_t)(loopSize);
assert(x153 < (size_t)-1);
cppDeliteArraybool *x1155 = new (resourceInfo) cppDeliteArraybool(x153);
__act->x1191_data = x1155;
return __act;
}

activation_x1191 *main_par(resourceInfo_t *resourceInfo,activation_x1191 *__act,MultiLoopSync<activation_x1191*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1191 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1191 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1191 *main_seq(resourceInfo_t *resourceInfo,activation_x1191 *__act) {
activation_x1191 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1191 *processRange(resourceInfo_t *resourceInfo,activation_x1191 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1191 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1191 *init(resourceInfo_t *resourceInfo,activation_x1191 *__act,int32_t x146,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x146);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1191 *__act,int32_t x146) {
int32_t x1151 = x1096->apply(x146);
int32_t x1152 = x1136->apply(x146);
bool  x1153 = x1151 == x1152;
bool x152 = x1153;
cppDeliteArraybool *x151 = __act->x1191_data;
x151->update(x146, x152);
}

void combine(resourceInfo_t *resourceInfo,activation_x1191 *__act,activation_x1191 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1191 *__act,activation_x1191 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1191 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1191 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1191 *__act) {
cppDeliteArraybool * x151 = __act->x1191_data;
__act->x1191 = x151;
}

activation_x1191 *initAct(resourceInfo_t *resourceInfo) {
activation_x1191 * act = new activation_x1191;
return act;
}

activation_x1191 *allocVal;
MultiLoopSync<activation_x1191*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1191_class *closure = (x1191_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1191_class *x1191_closure = new x1191_class(x1150,x1096,x1136);
x1191_closure->loopStart = 0;
x1191_closure->loopSize = x1150;
activation_x1191 * alloc = x1191_closure->alloc(resourceInfo);
activation_x1191 * x1191 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1191 = x1191_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1191*> * sync = new MultiLoopSync<activation_x1191*>(x1191_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1191_closure->allocVal = alloc;
x1191_closure->syncVal = sync;
submitWork(r->threadId, x1191_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1191_closure)));
i = i+1;
}
x1191 = x1191_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1191;
}

/**********/

