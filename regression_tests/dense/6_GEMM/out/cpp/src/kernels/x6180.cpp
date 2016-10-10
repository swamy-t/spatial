//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6180 * kernel_x6180(resourceInfo_t *resourceInfo,int32_t  x9, cppDeliteArraycppDeliteArrayint32_t  *x6178) {
class x6180_class{
public:
int32_t x9;
cppDeliteArraycppDeliteArrayint32_t *x6178;

x6180_class(int32_t  _x9,cppDeliteArraycppDeliteArrayint32_t * _x6178) {
x9 = _x9;
x6178 = _x6178;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x9;
}

int64_t loopStart;
int64_t loopSize;
activation_x6180 *alloc(resourceInfo_t *resourceInfo) {
activation_x6180 * __act = new activation_x6180();;
// __act->x6180 stays null for now
return __act;
}

activation_x6180 *main_par(resourceInfo_t *resourceInfo,activation_x6180 *__act,MultiLoopSync<activation_x6180*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6180 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6180 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x6180 * currentAct = act;
while (j < localEnd) {
activation_x6180 * rhsAct = sync->get(j);
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

activation_x6180 *main_seq(resourceInfo_t *resourceInfo,activation_x6180 *__act) {
activation_x6180 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x6180 *processRange(resourceInfo_t *resourceInfo,activation_x6180 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6180 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6180 *init(resourceInfo_t *resourceInfo,activation_x6180 *__act,int32_t x325,bool isEmpty) {
activation_x6180 * __act2 = new activation_x6180();;
int32_t x333 = 0;
assert(x333 < (size_t)-1);
cppDeliteArrayint32_t *x5527 = new (resourceInfo) cppDeliteArrayint32_t(x333, resourceInfo);
__act2->x6180_buf = x5527;
if (!isEmpty) {
cppDeliteArrayint32_t *x6179 = x6178->apply(x325);
cppDeliteArrayint32_t *x328 = x6179;
int32_t x329 = x328->length;
int32_t  x327 = 0;
while (x327 < x329) { //flatMap loop
int32_t x330 = x328->apply(x327);
cppDeliteArrayint32_t *x331 = __act2->x6180_buf;
int32_t x332 = x330;
if (true) {
int32_t x5533 = __act2->x6180_size;
int32_t x5534 = x331->length;
int32_t x5535 = x5534 - 1;
bool x5536 = x5533 > x5535;
if (x5536) {
bool x5537 = x5534 < 16;
int32_t  x5541;
if (x5537) {
x5541 = 16;
} else {
int32_t x5538 = x5534 * 2;
bool x5539 = x5538 < 0;
int32_t  x5540;
if (x5539) {
x5540 = 2147483647;
} else {
x5540 = x5538;
}
x5541 = x5540;
}
assert(x5541 < (size_t)-1);
cppDeliteArrayint32_t *x5542 = new (resourceInfo) cppDeliteArrayint32_t(x5541, resourceInfo);
if((x331->data==x5542->data) && (0<0))
std::copy_backward(x331->data+0,x331->data+0+x5534,x5542->data+0+x5534);
else {
for (size_t s=0, d=0; s<0+x5534; s++, d++){
x5542->update(d, x331->apply(s));
}
}
x5542->update(x5533, x332);
__act2->x6180_buf = x5542;
} else {
x331->update(x5533, x332);
}
__act2->x6180_size = __act2->x6180_size + 1;
}
__act2->x6180_conditionals = __act2->x6180_conditionals + 1;
x327 = x327 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x6180 *__act,int32_t x325) {
cppDeliteArrayint32_t *x6179 = x6178->apply(x325);
cppDeliteArrayint32_t *x328 = x6179;
int32_t x329 = x328->length;
int32_t  x327 = 0;
while (x327 < x329) { //flatMap loop
int32_t x330 = x328->apply(x327);
cppDeliteArrayint32_t *x331 = __act->x6180_buf;
int32_t x332 = x330;
if (true) {
int32_t x5533 = __act->x6180_size;
int32_t x5534 = x331->length;
int32_t x5535 = x5534 - 1;
bool x5536 = x5533 > x5535;
if (x5536) {
bool x5537 = x5534 < 16;
int32_t  x5541;
if (x5537) {
x5541 = 16;
} else {
int32_t x5538 = x5534 * 2;
bool x5539 = x5538 < 0;
int32_t  x5540;
if (x5539) {
x5540 = 2147483647;
} else {
x5540 = x5538;
}
x5541 = x5540;
}
assert(x5541 < (size_t)-1);
cppDeliteArrayint32_t *x5542 = new (resourceInfo) cppDeliteArrayint32_t(x5541, resourceInfo);
if((x331->data==x5542->data) && (0<0))
std::copy_backward(x331->data+0,x331->data+0+x5534,x5542->data+0+x5534);
else {
for (size_t s=0, d=0; s<0+x5534; s++, d++){
x5542->update(d, x331->apply(s));
}
}
x5542->update(x5533, x332);
__act->x6180_buf = x5542;
} else {
x331->update(x5533, x332);
}
__act->x6180_size = __act->x6180_size + 1;
}
__act->x6180_conditionals = __act->x6180_conditionals + 1;
x327 = x327 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x6180 *__act,activation_x6180 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6180 *__act,activation_x6180 *lhs) {
__act->x6180_offset = lhs->x6180_offset+lhs->x6180_size;
__act->x6180_conditionals = __act->x6180_conditionals+lhs->x6180_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6180 *__act) {
if (__act->x6180_offset > 0) {
int32_t x333 = __act->x6180_offset + __act->x6180_size;
cppDeliteArrayint32_t *x331 = __act->x6180_buf;
assert(x333 < (size_t)-1);
cppDeliteArrayint32_t *x5559 = new (resourceInfo) cppDeliteArrayint32_t(x333);
__act->x6180_data_set(resourceInfo,x5559,__act->x6180_conditionals);
} else {
__act->x6180_data_set(resourceInfo,__act->x6180_buf,__act->x6180_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6180 *__act) {
if (__act->x6180_data != __act->x6180_buf) {
int32_t x333 = __act->x6180_size;
cppDeliteArrayint32_t *x336 = __act->x6180_buf;
cppDeliteArrayint32_t *x331 = __act->x6180_data;
int32_t x334 = 0;
int32_t x335 = __act->x6180_offset;
if((x336->data==x331->data) && (x334<x335))
std::copy_backward(x336->data+x334,x336->data+x334+x333,x331->data+x335+x333);
else {
for (size_t s=x334, d=x335; s<x334+x333; s++, d++){
x331->update(d, x336->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x6180 *__act) {
cppDeliteArrayint32_t * x331 = __act->x6180_data;
int32_t x333 = __act->x6180_conditionals;
int32_t x5551 = x331->length;
bool x5552 = x5551 > x333;
if (x5552) {
assert(x333 < (size_t)-1);
cppDeliteArrayint32_t *x5553 = new (resourceInfo) cppDeliteArrayint32_t(x333);
if((x331->data==x5553->data) && (0<0))
std::copy_backward(x331->data+0,x331->data+0+x333,x5553->data+0+x333);
else {
for (size_t s=0, d=0; s<0+x333; s++, d++){
x5553->update(d, x331->apply(s));
}
}
x331 = x5553;
} else {
}
__act->x6180 = x331;
}

activation_x6180 *initAct(resourceInfo_t *resourceInfo) {
activation_x6180 * act = new activation_x6180;
return act;
}

activation_x6180 *allocVal;
MultiLoopSync<activation_x6180*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6180_class *closure = (x6180_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6180_class *x6180_closure = new x6180_class(x9,x6178);
x6180_closure->loopStart = 0;
x6180_closure->loopSize = x9;
activation_x6180 * alloc = x6180_closure->alloc(resourceInfo);
activation_x6180 * x6180 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6180 = x6180_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6180*> * sync = new MultiLoopSync<activation_x6180*>(x6180_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6180_closure->allocVal = alloc;
x6180_closure->syncVal = sync;
submitWork(r->threadId, x6180_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6180_closure)));
i = i+1;
}
x6180 = x6180_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6180;
}

/**********/

