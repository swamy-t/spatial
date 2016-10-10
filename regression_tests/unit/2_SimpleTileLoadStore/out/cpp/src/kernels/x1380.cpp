//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1380 * kernel_x1380(resourceInfo_t *resourceInfo,int32_t  x1339, cppDeliteArrayint32_t  *x1285, cppDeliteArrayint32_t  *x1326) {
class x1380_class{
public:
int32_t x1339;
cppDeliteArrayint32_t *x1285;
cppDeliteArrayint32_t *x1326;

x1380_class(int32_t  _x1339,cppDeliteArrayint32_t * _x1285,cppDeliteArrayint32_t * _x1326) {
x1339 = _x1339;
x1285 = _x1285;
x1326 = _x1326;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x1339;
}

int64_t loopStart;
int64_t loopSize;
activation_x1380 *alloc(resourceInfo_t *resourceInfo) {
activation_x1380 * __act = new activation_x1380();;
int32_t x187 = (int32_t)(loopSize);
assert(x187 < (size_t)-1);
cppDeliteArraybool *x1344 = new (resourceInfo) cppDeliteArraybool(x187);
__act->x1380_data = x1344;
return __act;
}

activation_x1380 *main_par(resourceInfo_t *resourceInfo,activation_x1380 *__act,MultiLoopSync<activation_x1380*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1380 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1380 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1380 *main_seq(resourceInfo_t *resourceInfo,activation_x1380 *__act) {
activation_x1380 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1380 *processRange(resourceInfo_t *resourceInfo,activation_x1380 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1380 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1380 *init(resourceInfo_t *resourceInfo,activation_x1380 *__act,int32_t x180,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x180);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1380 *__act,int32_t x180) {
int32_t x1340 = x1285->apply(x180);
int32_t x1341 = x1326->apply(x180);
bool  x1342 = x1340 == x1341;
bool x186 = x1342;
cppDeliteArraybool *x185 = __act->x1380_data;
x185->update(x180, x186);
}

void combine(resourceInfo_t *resourceInfo,activation_x1380 *__act,activation_x1380 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1380 *__act,activation_x1380 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1380 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1380 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1380 *__act) {
cppDeliteArraybool * x185 = __act->x1380_data;
__act->x1380 = x185;
}

activation_x1380 *initAct(resourceInfo_t *resourceInfo) {
activation_x1380 * act = new activation_x1380;
return act;
}

activation_x1380 *allocVal;
MultiLoopSync<activation_x1380*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1380_class *closure = (x1380_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1380_class *x1380_closure = new x1380_class(x1339,x1285,x1326);
x1380_closure->loopStart = 0;
x1380_closure->loopSize = x1339;
activation_x1380 * alloc = x1380_closure->alloc(resourceInfo);
activation_x1380 * x1380 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1380 = x1380_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1380*> * sync = new MultiLoopSync<activation_x1380*>(x1380_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1380_closure->allocVal = alloc;
x1380_closure->syncVal = sync;
submitWork(r->threadId, x1380_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1380_closure)));
i = i+1;
}
x1380 = x1380_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1380;
}

/**********/

