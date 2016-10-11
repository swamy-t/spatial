//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5472x6204 * kernel_x5472x6204(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArrayint32_t  *x6203, cppDeliteArraycppDeliteArrayint32_t  *x5434) {
class x5472x6204_class{
public:
int32_t x7;
cppDeliteArrayint32_t *x6203;
cppDeliteArraycppDeliteArrayint32_t *x5434;

x5472x6204_class(int32_t  _x7,cppDeliteArrayint32_t * _x6203,cppDeliteArraycppDeliteArrayint32_t * _x5434) {
x7 = _x7;
x6203 = _x6203;
x5434 = _x5434;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x7;
}

int64_t loopStart;
int64_t loopSize;
activation_x5472x6204 *alloc(resourceInfo_t *resourceInfo) {
activation_x5472x6204 * __act = new activation_x5472x6204();;
// __act->x5472 stays null for now
int32_t x235 = (int32_t)(loopSize);
assert(x235 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x5624 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x235);
__act->x6204_data = x5624;
return __act;
}

activation_x5472x6204 *main_par(resourceInfo_t *resourceInfo,activation_x5472x6204 *__act,MultiLoopSync<activation_x5472x6204*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5472x6204 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5472x6204 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x5472x6204 * currentAct = act;
while (j < localEnd) {
activation_x5472x6204 * rhsAct = sync->get(j);
postCombine(resourceInfo,rhsAct,currentAct);
currentAct = rhsAct;
j = j+1;
}
if (tid == numThreads-1) postProcInit(resourceInfo,currentAct);
sync->setP(tid, currentAct);
sync->awaitBarrier();
//post process
int32_t  k = localStart;
while (k < localEnd) {
postProcess(resourceInfo,sync->get(k));
k = k+1;
}
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x5472x6204 *main_seq(resourceInfo_t *resourceInfo,activation_x5472x6204 *__act) {
activation_x5472x6204 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x5472x6204 *processRange(resourceInfo_t *resourceInfo,activation_x5472x6204 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5472x6204 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5472x6204 *init(resourceInfo_t *resourceInfo,activation_x5472x6204 *__act,int32_t x276,bool isEmpty) {
activation_x5472x6204 * __act2 = new activation_x5472x6204();;
int32_t x284 = 0;
assert(x284 < (size_t)-1);
cppDeliteArrayint32_t *x5435 = new (resourceInfo) cppDeliteArrayint32_t(x284, resourceInfo);
__act2->x5472_buf = x5435;
__act2->x6204_data = __act->x6204_data;
if (!isEmpty) {
cppDeliteArrayint32_t *x5471 = x5434->apply(x276);
cppDeliteArrayint32_t *x279 = x5471;
int32_t x280 = x279->length;
int32_t  x278 = 0;
while (x278 < x280) { //flatMap loop
int32_t x281 = x279->apply(x278);
cppDeliteArrayint32_t *x282 = __act2->x5472_buf;
int32_t x283 = x281;
if (true) {
int32_t x5441 = __act2->x5472_size;
int32_t x5442 = x282->length;
int32_t x5443 = x5442 - 1;
bool x5444 = x5441 > x5443;
if (x5444) {
bool x5445 = x5442 < 16;
int32_t  x5449;
if (x5445) {
x5449 = 16;
} else {
int32_t x5446 = x5442 * 2;
bool x5447 = x5446 < 0;
int32_t  x5448;
if (x5447) {
x5448 = 2147483647;
} else {
x5448 = x5446;
}
x5449 = x5448;
}
assert(x5449 < (size_t)-1);
cppDeliteArrayint32_t *x5450 = new (resourceInfo) cppDeliteArrayint32_t(x5449, resourceInfo);
if((x282->data==x5450->data) && (0<0))
std::copy_backward(x282->data+0,x282->data+0+x5442,x5450->data+0+x5442);
else {
for (size_t s=0, d=0; s<0+x5442; s++, d++){
x5450->update(d, x282->apply(s));
}
}
x5450->update(x5441, x283);
__act2->x5472_buf = x5450;
} else {
x282->update(x5441, x283);
}
__act2->x5472_size = __act2->x5472_size + 1;
}
__act2->x5472_conditionals = __act2->x5472_conditionals + 1;
x278 = x278 + 1;
}
cppDeliteArrayint32_t *x234 = x6203;
cppDeliteArraycppDeliteArrayint32_t *x233 = __act2->x6204_data;
x233->update(x276, x234);
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x5472x6204 *__act,int32_t x276) {
cppDeliteArrayint32_t *x5471 = x5434->apply(x276);
cppDeliteArrayint32_t *x279 = x5471;
int32_t x280 = x279->length;
int32_t  x278 = 0;
while (x278 < x280) { //flatMap loop
int32_t x281 = x279->apply(x278);
cppDeliteArrayint32_t *x282 = __act->x5472_buf;
int32_t x283 = x281;
if (true) {
int32_t x5441 = __act->x5472_size;
int32_t x5442 = x282->length;
int32_t x5443 = x5442 - 1;
bool x5444 = x5441 > x5443;
if (x5444) {
bool x5445 = x5442 < 16;
int32_t  x5449;
if (x5445) {
x5449 = 16;
} else {
int32_t x5446 = x5442 * 2;
bool x5447 = x5446 < 0;
int32_t  x5448;
if (x5447) {
x5448 = 2147483647;
} else {
x5448 = x5446;
}
x5449 = x5448;
}
assert(x5449 < (size_t)-1);
cppDeliteArrayint32_t *x5450 = new (resourceInfo) cppDeliteArrayint32_t(x5449, resourceInfo);
if((x282->data==x5450->data) && (0<0))
std::copy_backward(x282->data+0,x282->data+0+x5442,x5450->data+0+x5442);
else {
for (size_t s=0, d=0; s<0+x5442; s++, d++){
x5450->update(d, x282->apply(s));
}
}
x5450->update(x5441, x283);
__act->x5472_buf = x5450;
} else {
x282->update(x5441, x283);
}
__act->x5472_size = __act->x5472_size + 1;
}
__act->x5472_conditionals = __act->x5472_conditionals + 1;
x278 = x278 + 1;
}
cppDeliteArrayint32_t *x234 = x6203;
cppDeliteArraycppDeliteArrayint32_t *x233 = __act->x6204_data;
x233->update(x276, x234);
}

void combine(resourceInfo_t *resourceInfo,activation_x5472x6204 *__act,activation_x5472x6204 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5472x6204 *__act,activation_x5472x6204 *lhs) {
__act->x5472_offset = lhs->x5472_offset+lhs->x5472_size;
__act->x5472_conditionals = __act->x5472_conditionals+lhs->x5472_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5472x6204 *__act) {
if (__act->x5472_offset > 0) {
int32_t x284 = __act->x5472_offset + __act->x5472_size;
cppDeliteArrayint32_t *x282 = __act->x5472_buf;
assert(x284 < (size_t)-1);
cppDeliteArrayint32_t *x5467 = new (resourceInfo) cppDeliteArrayint32_t(x284);
__act->x5472_data_set(resourceInfo,x5467,__act->x5472_conditionals);
} else {
__act->x5472_data_set(resourceInfo,__act->x5472_buf,__act->x5472_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5472x6204 *__act) {
if (__act->x5472_data != __act->x5472_buf) {
int32_t x284 = __act->x5472_size;
cppDeliteArrayint32_t *x287 = __act->x5472_buf;
cppDeliteArrayint32_t *x282 = __act->x5472_data;
int32_t x285 = 0;
int32_t x286 = __act->x5472_offset;
if((x287->data==x282->data) && (x285<x286))
std::copy_backward(x287->data+x285,x287->data+x285+x284,x282->data+x286+x284);
else {
for (size_t s=x285, d=x286; s<x285+x284; s++, d++){
x282->update(d, x287->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x5472x6204 *__act) {
cppDeliteArrayint32_t * x282 = __act->x5472_data;
int32_t x284 = __act->x5472_conditionals;
int32_t x5459 = x282->length;
bool x5460 = x5459 > x284;
if (x5460) {
assert(x284 < (size_t)-1);
cppDeliteArrayint32_t *x5461 = new (resourceInfo) cppDeliteArrayint32_t(x284);
if((x282->data==x5461->data) && (0<0))
std::copy_backward(x282->data+0,x282->data+0+x284,x5461->data+0+x284);
else {
for (size_t s=0, d=0; s<0+x284; s++, d++){
x5461->update(d, x282->apply(s));
}
}
x282 = x5461;
} else {
}
__act->x5472 = x282;
cppDeliteArraycppDeliteArrayint32_t * x233 = __act->x6204_data;
__act->x6204 = x233;
}

activation_x5472x6204 *initAct(resourceInfo_t *resourceInfo) {
activation_x5472x6204 * act = new activation_x5472x6204;
return act;
}

activation_x5472x6204 *allocVal;
MultiLoopSync<activation_x5472x6204*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5472x6204_class *closure = (x5472x6204_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5472x6204_class *x5472x6204_closure = new x5472x6204_class(x7,x6203,x5434);
x5472x6204_closure->loopStart = 0;
x5472x6204_closure->loopSize = x7;
activation_x5472x6204 * alloc = x5472x6204_closure->alloc(resourceInfo);
activation_x5472x6204 * x5472x6204 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5472x6204 = x5472x6204_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5472x6204*> * sync = new MultiLoopSync<activation_x5472x6204*>(x5472x6204_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5472x6204_closure->allocVal = alloc;
x5472x6204_closure->syncVal = sync;
submitWork(r->threadId, x5472x6204_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5472x6204_closure)));
i = i+1;
}
x5472x6204 = x5472x6204_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5472x6204;
}

/**********/

