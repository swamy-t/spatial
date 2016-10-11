//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6206 * kernel_x6206(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x6204) {
class x6206_class{
public:
int32_t x7;
cppDeliteArraycppDeliteArrayint32_t *x6204;

x6206_class(int32_t  _x7,cppDeliteArraycppDeliteArrayint32_t * _x6204) {
x7 = _x7;
x6204 = _x6204;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x7;
}

int64_t loopStart;
int64_t loopSize;
activation_x6206 *alloc(resourceInfo_t *resourceInfo) {
activation_x6206 * __act = new activation_x6206();;
// __act->x6206 stays null for now
return __act;
}

activation_x6206 *main_par(resourceInfo_t *resourceInfo,activation_x6206 *__act,MultiLoopSync<activation_x6206*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6206 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6206 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x6206 * currentAct = act;
while (j < localEnd) {
activation_x6206 * rhsAct = sync->get(j);
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

activation_x6206 *main_seq(resourceInfo_t *resourceInfo,activation_x6206 *__act) {
activation_x6206 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x6206 *processRange(resourceInfo_t *resourceInfo,activation_x6206 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6206 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6206 *init(resourceInfo_t *resourceInfo,activation_x6206 *__act,int32_t x374,bool isEmpty) {
activation_x6206 * __act2 = new activation_x6206();;
int32_t x382 = 0;
assert(x382 < (size_t)-1);
cppDeliteArrayint32_t *x5661 = new (resourceInfo) cppDeliteArrayint32_t(x382, resourceInfo);
__act2->x6206_buf = x5661;
if (!isEmpty) {
cppDeliteArrayint32_t *x6205 = x6204->apply(x374);
cppDeliteArrayint32_t *x377 = x6205;
int32_t x378 = x377->length;
int32_t  x376 = 0;
while (x376 < x378) { //flatMap loop
int32_t x379 = x377->apply(x376);
cppDeliteArrayint32_t *x380 = __act2->x6206_buf;
int32_t x381 = x379;
if (true) {
int32_t x5667 = __act2->x6206_size;
int32_t x5668 = x380->length;
int32_t x5669 = x5668 - 1;
bool x5670 = x5667 > x5669;
if (x5670) {
bool x5671 = x5668 < 16;
int32_t  x5675;
if (x5671) {
x5675 = 16;
} else {
int32_t x5672 = x5668 * 2;
bool x5673 = x5672 < 0;
int32_t  x5674;
if (x5673) {
x5674 = 2147483647;
} else {
x5674 = x5672;
}
x5675 = x5674;
}
assert(x5675 < (size_t)-1);
cppDeliteArrayint32_t *x5676 = new (resourceInfo) cppDeliteArrayint32_t(x5675, resourceInfo);
if((x380->data==x5676->data) && (0<0))
std::copy_backward(x380->data+0,x380->data+0+x5668,x5676->data+0+x5668);
else {
for (size_t s=0, d=0; s<0+x5668; s++, d++){
x5676->update(d, x380->apply(s));
}
}
x5676->update(x5667, x381);
__act2->x6206_buf = x5676;
} else {
x380->update(x5667, x381);
}
__act2->x6206_size = __act2->x6206_size + 1;
}
__act2->x6206_conditionals = __act2->x6206_conditionals + 1;
x376 = x376 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x6206 *__act,int32_t x374) {
cppDeliteArrayint32_t *x6205 = x6204->apply(x374);
cppDeliteArrayint32_t *x377 = x6205;
int32_t x378 = x377->length;
int32_t  x376 = 0;
while (x376 < x378) { //flatMap loop
int32_t x379 = x377->apply(x376);
cppDeliteArrayint32_t *x380 = __act->x6206_buf;
int32_t x381 = x379;
if (true) {
int32_t x5667 = __act->x6206_size;
int32_t x5668 = x380->length;
int32_t x5669 = x5668 - 1;
bool x5670 = x5667 > x5669;
if (x5670) {
bool x5671 = x5668 < 16;
int32_t  x5675;
if (x5671) {
x5675 = 16;
} else {
int32_t x5672 = x5668 * 2;
bool x5673 = x5672 < 0;
int32_t  x5674;
if (x5673) {
x5674 = 2147483647;
} else {
x5674 = x5672;
}
x5675 = x5674;
}
assert(x5675 < (size_t)-1);
cppDeliteArrayint32_t *x5676 = new (resourceInfo) cppDeliteArrayint32_t(x5675, resourceInfo);
if((x380->data==x5676->data) && (0<0))
std::copy_backward(x380->data+0,x380->data+0+x5668,x5676->data+0+x5668);
else {
for (size_t s=0, d=0; s<0+x5668; s++, d++){
x5676->update(d, x380->apply(s));
}
}
x5676->update(x5667, x381);
__act->x6206_buf = x5676;
} else {
x380->update(x5667, x381);
}
__act->x6206_size = __act->x6206_size + 1;
}
__act->x6206_conditionals = __act->x6206_conditionals + 1;
x376 = x376 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x6206 *__act,activation_x6206 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6206 *__act,activation_x6206 *lhs) {
__act->x6206_offset = lhs->x6206_offset+lhs->x6206_size;
__act->x6206_conditionals = __act->x6206_conditionals+lhs->x6206_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6206 *__act) {
if (__act->x6206_offset > 0) {
int32_t x382 = __act->x6206_offset + __act->x6206_size;
cppDeliteArrayint32_t *x380 = __act->x6206_buf;
assert(x382 < (size_t)-1);
cppDeliteArrayint32_t *x5693 = new (resourceInfo) cppDeliteArrayint32_t(x382);
__act->x6206_data_set(resourceInfo,x5693,__act->x6206_conditionals);
} else {
__act->x6206_data_set(resourceInfo,__act->x6206_buf,__act->x6206_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6206 *__act) {
if (__act->x6206_data != __act->x6206_buf) {
int32_t x382 = __act->x6206_size;
cppDeliteArrayint32_t *x385 = __act->x6206_buf;
cppDeliteArrayint32_t *x380 = __act->x6206_data;
int32_t x383 = 0;
int32_t x384 = __act->x6206_offset;
if((x385->data==x380->data) && (x383<x384))
std::copy_backward(x385->data+x383,x385->data+x383+x382,x380->data+x384+x382);
else {
for (size_t s=x383, d=x384; s<x383+x382; s++, d++){
x380->update(d, x385->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x6206 *__act) {
cppDeliteArrayint32_t * x380 = __act->x6206_data;
int32_t x382 = __act->x6206_conditionals;
int32_t x5685 = x380->length;
bool x5686 = x5685 > x382;
if (x5686) {
assert(x382 < (size_t)-1);
cppDeliteArrayint32_t *x5687 = new (resourceInfo) cppDeliteArrayint32_t(x382);
if((x380->data==x5687->data) && (0<0))
std::copy_backward(x380->data+0,x380->data+0+x382,x5687->data+0+x382);
else {
for (size_t s=0, d=0; s<0+x382; s++, d++){
x5687->update(d, x380->apply(s));
}
}
x380 = x5687;
} else {
}
__act->x6206 = x380;
}

activation_x6206 *initAct(resourceInfo_t *resourceInfo) {
activation_x6206 * act = new activation_x6206;
return act;
}

activation_x6206 *allocVal;
MultiLoopSync<activation_x6206*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6206_class *closure = (x6206_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6206_class *x6206_closure = new x6206_class(x7,x6204);
x6206_closure->loopStart = 0;
x6206_closure->loopSize = x7;
activation_x6206 * alloc = x6206_closure->alloc(resourceInfo);
activation_x6206 * x6206 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6206 = x6206_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6206*> * sync = new MultiLoopSync<activation_x6206*>(x6206_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6206_closure->allocVal = alloc;
x6206_closure->syncVal = sync;
submitWork(r->threadId, x6206_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6206_closure)));
i = i+1;
}
x6206 = x6206_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6206;
}

/**********/

