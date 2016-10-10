//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1939 * kernel_x1939(resourceInfo_t *resourceInfo,int32_t  x125, cppDeliteArrayint32_t  *x1813, int32_t  x2, bool  x268, cppDeliteArrayint32_t  *x1773, int32_t  x177) {
class x1939_class{
public:
int32_t x125;
cppDeliteArrayint32_t *x1813;
int32_t x2;
bool x268;
cppDeliteArrayint32_t *x1773;
int32_t x177;

x1939_class(int32_t  _x125,cppDeliteArrayint32_t * _x1813,int32_t  _x2,bool  _x268,cppDeliteArrayint32_t * _x1773,int32_t  _x177) {
x125 = _x125;
x1813 = _x1813;
x2 = _x2;
x268 = _x268;
x1773 = _x1773;
x177 = _x177;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x125;
}

int64_t loopStart;
int64_t loopSize;
activation_x1939 *alloc(resourceInfo_t *resourceInfo) {
activation_x1939 * __act = new activation_x1939();;
int32_t x283 = (int32_t)(loopSize);
assert(x283 < (size_t)-1);
cppDeliteArrayint32_t *x1903 = new (resourceInfo) cppDeliteArrayint32_t(x283);
__act->x1939_data = x1903;
return __act;
}

activation_x1939 *main_par(resourceInfo_t *resourceInfo,activation_x1939 *__act,MultiLoopSync<activation_x1939*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1939 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1939 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1939 *main_seq(resourceInfo_t *resourceInfo,activation_x1939 *__act) {
activation_x1939 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1939 *processRange(resourceInfo_t *resourceInfo,activation_x1939 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1939 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1939 *init(resourceInfo_t *resourceInfo,activation_x1939 *__act,int32_t x220,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x220);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1939 *__act,int32_t x220) {
int32_t  x221 = (int32_t) (x220);
int32_t  x227 = x2;
assert(x227 < (size_t)-1);
cppDeliteArraybool *x1859 = new (resourceInfo) cppDeliteArraybool(x227, resourceInfo);
cppDeliteArraybool * x1895_data = x1859;
int32_t  x1895_size = 0;
int32_t  x1895_conditionals = 0;
int32_t  x222 = 0;
while (x222 < x2) {  // begin fat loop x1895
int32_t x1857 = x1813->apply(x222);
bool  x1858 = x1857 == x221;
bool x226 = x1858;
cppDeliteArraybool *x225 = x1895_data;
x225->update(x222, x226);
x222 = x222 + 1;
} // end fat loop x1895
cppDeliteArraybool *x225 = x1895_data;
cppDeliteArraybool *x1895 = x225;
bool  x1899_zero = x268;
bool  x1899 = x1899_zero;
int32_t  x269 = 0;
if (x2 > 0) { // prerun fat loop x1899
bool x1896 = x1895->apply(x269);
x1899 = x1896;
}
x269 = 1;
while (x269 < x2) {  // begin fat loop x1899
bool x1896 = x1895->apply(x269);
bool x273 = x1899;
bool x274 = x1896;
bool  x275 = x273 || x274;
x1899 = x275;
x269 = x269 + 1;
} // end fat loop x1899
bool  x1900 = x1899;
int32_t  x1902;
if (x1900) {
int32_t  x278 = (int32_t) x221;
int32_t x1901 = x1773->apply(x278);
x1902 = x1901;
} else {
x1902 = x177;
}
int32_t x282 = x1902;
cppDeliteArrayint32_t *x281 = __act->x1939_data;
x281->update(x220, x282);
}

void combine(resourceInfo_t *resourceInfo,activation_x1939 *__act,activation_x1939 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1939 *__act,activation_x1939 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1939 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1939 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1939 *__act) {
cppDeliteArrayint32_t * x281 = __act->x1939_data;
__act->x1939 = x281;
}

activation_x1939 *initAct(resourceInfo_t *resourceInfo) {
activation_x1939 * act = new activation_x1939;
return act;
}

activation_x1939 *allocVal;
MultiLoopSync<activation_x1939*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1939_class *closure = (x1939_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1939_class *x1939_closure = new x1939_class(x125,x1813,x2,x268,x1773,x177);
x1939_closure->loopStart = 0;
x1939_closure->loopSize = x125;
activation_x1939 * alloc = x1939_closure->alloc(resourceInfo);
activation_x1939 * x1939 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1939 = x1939_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1939*> * sync = new MultiLoopSync<activation_x1939*>(x1939_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1939_closure->allocVal = alloc;
x1939_closure->syncVal = sync;
submitWork(r->threadId, x1939_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1939_closure)));
i = i+1;
}
x1939 = x1939_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1939;
}

/**********/

