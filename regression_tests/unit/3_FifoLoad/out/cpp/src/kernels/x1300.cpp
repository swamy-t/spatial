//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1300 * kernel_x1300(resourceInfo_t *resourceInfo,int32_t  x1259, cppDeliteArrayint32_t  *x1206, cppDeliteArrayint32_t  *x1246) {
class x1300_class{
public:
int32_t x1259;
cppDeliteArrayint32_t *x1206;
cppDeliteArrayint32_t *x1246;

x1300_class(int32_t  _x1259,cppDeliteArrayint32_t * _x1206,cppDeliteArrayint32_t * _x1246) {
x1259 = _x1259;
x1206 = _x1206;
x1246 = _x1246;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1259;
}

int64_t loopStart;
int64_t loopSize;
activation_x1300 *alloc(resourceInfo_t *resourceInfo) {
activation_x1300 * __act = new activation_x1300();;
int32_t x174 = (int32_t)(loopSize);
assert(x174 < (size_t)-1);
cppDeliteArraybool *x1264 = new (resourceInfo) cppDeliteArraybool(x174);
__act->x1300_data = x1264;
return __act;
}

activation_x1300 *main_par(resourceInfo_t *resourceInfo,activation_x1300 *__act,MultiLoopSync<activation_x1300*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1300 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1300 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1300 *main_seq(resourceInfo_t *resourceInfo,activation_x1300 *__act) {
activation_x1300 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1300 *processRange(resourceInfo_t *resourceInfo,activation_x1300 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1300 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1300 *init(resourceInfo_t *resourceInfo,activation_x1300 *__act,int32_t x167,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x167);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1300 *__act,int32_t x167) {
int32_t x1260 = x1206->apply(x167);
int32_t x1261 = x1246->apply(x167);
bool  x1262 = x1260 == x1261;
bool x173 = x1262;
cppDeliteArraybool *x172 = __act->x1300_data;
x172->update(x167, x173);
}

void combine(resourceInfo_t *resourceInfo,activation_x1300 *__act,activation_x1300 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1300 *__act,activation_x1300 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1300 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1300 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1300 *__act) {
cppDeliteArraybool * x172 = __act->x1300_data;
__act->x1300 = x172;
}

activation_x1300 *initAct(resourceInfo_t *resourceInfo) {
activation_x1300 * act = new activation_x1300;
return act;
}

activation_x1300 *allocVal;
MultiLoopSync<activation_x1300*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1300_class *closure = (x1300_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1300_class *x1300_closure = new x1300_class(x1259,x1206,x1246);
x1300_closure->loopStart = 0;
x1300_closure->loopSize = x1259;
activation_x1300 * alloc = x1300_closure->alloc(resourceInfo);
activation_x1300 * x1300 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1300 = x1300_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1300*> * sync = new MultiLoopSync<activation_x1300*>(x1300_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1300_closure->allocVal = alloc;
x1300_closure->syncVal = sync;
submitWork(r->threadId, x1300_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1300_closure)));
i = i+1;
}
x1300 = x1300_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1300;
}

/**********/

