//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2576 * kernel_x2576(resourceInfo_t *resourceInfo,int32_t  x2538, cppDeliteArraycppDeliteArrayfloat  *x2448) {
class x2576_class{
public:
int32_t x2538;
cppDeliteArraycppDeliteArrayfloat *x2448;

x2576_class(int32_t  _x2538,cppDeliteArraycppDeliteArrayfloat * _x2448) {
x2538 = _x2538;
x2448 = _x2448;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x2538;
}

int64_t loopStart;
int64_t loopSize;
activation_x2576 *alloc(resourceInfo_t *resourceInfo) {
activation_x2576 * __act = new activation_x2576();;
// __act->x2576 stays null for now
return __act;
}

activation_x2576 *main_par(resourceInfo_t *resourceInfo,activation_x2576 *__act,MultiLoopSync<activation_x2576*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2576 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2576 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x2576 * currentAct = act;
while (j < localEnd) {
activation_x2576 * rhsAct = sync->get(j);
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

activation_x2576 *main_seq(resourceInfo_t *resourceInfo,activation_x2576 *__act) {
activation_x2576 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x2576 *processRange(resourceInfo_t *resourceInfo,activation_x2576 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2576 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2576 *init(resourceInfo_t *resourceInfo,activation_x2576 *__act,int32_t x195,bool isEmpty) {
activation_x2576 * __act2 = new activation_x2576();;
int32_t x203 = 0;
assert(x203 < (size_t)-1);
cppDeliteArrayfloat *x2539 = new (resourceInfo) cppDeliteArrayfloat(x203, resourceInfo);
__act2->x2576_buf = x2539;
if (!isEmpty) {
cppDeliteArrayfloat *x2575 = x2448->apply(x195);
cppDeliteArrayfloat *x198 = x2575;
int32_t x199 = x198->length;
int32_t  x197 = 0;
while (x197 < x199) { //flatMap loop
float x200 = x198->apply(x197);
cppDeliteArrayfloat *x201 = __act2->x2576_buf;
float x202 = x200;
if (true) {
int32_t x2545 = __act2->x2576_size;
int32_t x2546 = x201->length;
int32_t x2547 = x2546 - 1;
bool x2548 = x2545 > x2547;
if (x2548) {
bool x2549 = x2546 < 16;
int32_t  x2553;
if (x2549) {
x2553 = 16;
} else {
int32_t x2550 = x2546 * 2;
bool x2551 = x2550 < 0;
int32_t  x2552;
if (x2551) {
x2552 = 2147483647;
} else {
x2552 = x2550;
}
x2553 = x2552;
}
assert(x2553 < (size_t)-1);
cppDeliteArrayfloat *x2554 = new (resourceInfo) cppDeliteArrayfloat(x2553, resourceInfo);
if((x201->data==x2554->data) && (0<0))
std::copy_backward(x201->data+0,x201->data+0+x2546,x2554->data+0+x2546);
else {
for (size_t s=0, d=0; s<0+x2546; s++, d++){
x2554->update(d, x201->apply(s));
}
}
x2554->update(x2545, x202);
__act2->x2576_buf = x2554;
} else {
x201->update(x2545, x202);
}
__act2->x2576_size = __act2->x2576_size + 1;
}
__act2->x2576_conditionals = __act2->x2576_conditionals + 1;
x197 = x197 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x2576 *__act,int32_t x195) {
cppDeliteArrayfloat *x2575 = x2448->apply(x195);
cppDeliteArrayfloat *x198 = x2575;
int32_t x199 = x198->length;
int32_t  x197 = 0;
while (x197 < x199) { //flatMap loop
float x200 = x198->apply(x197);
cppDeliteArrayfloat *x201 = __act->x2576_buf;
float x202 = x200;
if (true) {
int32_t x2545 = __act->x2576_size;
int32_t x2546 = x201->length;
int32_t x2547 = x2546 - 1;
bool x2548 = x2545 > x2547;
if (x2548) {
bool x2549 = x2546 < 16;
int32_t  x2553;
if (x2549) {
x2553 = 16;
} else {
int32_t x2550 = x2546 * 2;
bool x2551 = x2550 < 0;
int32_t  x2552;
if (x2551) {
x2552 = 2147483647;
} else {
x2552 = x2550;
}
x2553 = x2552;
}
assert(x2553 < (size_t)-1);
cppDeliteArrayfloat *x2554 = new (resourceInfo) cppDeliteArrayfloat(x2553, resourceInfo);
if((x201->data==x2554->data) && (0<0))
std::copy_backward(x201->data+0,x201->data+0+x2546,x2554->data+0+x2546);
else {
for (size_t s=0, d=0; s<0+x2546; s++, d++){
x2554->update(d, x201->apply(s));
}
}
x2554->update(x2545, x202);
__act->x2576_buf = x2554;
} else {
x201->update(x2545, x202);
}
__act->x2576_size = __act->x2576_size + 1;
}
__act->x2576_conditionals = __act->x2576_conditionals + 1;
x197 = x197 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x2576 *__act,activation_x2576 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2576 *__act,activation_x2576 *lhs) {
__act->x2576_offset = lhs->x2576_offset+lhs->x2576_size;
__act->x2576_conditionals = __act->x2576_conditionals+lhs->x2576_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2576 *__act) {
if (__act->x2576_offset > 0) {
int32_t x203 = __act->x2576_offset + __act->x2576_size;
cppDeliteArrayfloat *x201 = __act->x2576_buf;
assert(x203 < (size_t)-1);
cppDeliteArrayfloat *x2571 = new (resourceInfo) cppDeliteArrayfloat(x203);
__act->x2576_data_set(resourceInfo,x2571,__act->x2576_conditionals);
} else {
__act->x2576_data_set(resourceInfo,__act->x2576_buf,__act->x2576_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2576 *__act) {
if (__act->x2576_data != __act->x2576_buf) {
int32_t x203 = __act->x2576_size;
cppDeliteArrayfloat *x206 = __act->x2576_buf;
cppDeliteArrayfloat *x201 = __act->x2576_data;
int32_t x204 = 0;
int32_t x205 = __act->x2576_offset;
if((x206->data==x201->data) && (x204<x205))
std::copy_backward(x206->data+x204,x206->data+x204+x203,x201->data+x205+x203);
else {
for (size_t s=x204, d=x205; s<x204+x203; s++, d++){
x201->update(d, x206->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x2576 *__act) {
cppDeliteArrayfloat * x201 = __act->x2576_data;
int32_t x203 = __act->x2576_conditionals;
int32_t x2563 = x201->length;
bool x2564 = x2563 > x203;
if (x2564) {
assert(x203 < (size_t)-1);
cppDeliteArrayfloat *x2565 = new (resourceInfo) cppDeliteArrayfloat(x203);
if((x201->data==x2565->data) && (0<0))
std::copy_backward(x201->data+0,x201->data+0+x203,x2565->data+0+x203);
else {
for (size_t s=0, d=0; s<0+x203; s++, d++){
x2565->update(d, x201->apply(s));
}
}
x201 = x2565;
} else {
}
__act->x2576 = x201;
}

activation_x2576 *initAct(resourceInfo_t *resourceInfo) {
activation_x2576 * act = new activation_x2576;
return act;
}

activation_x2576 *allocVal;
MultiLoopSync<activation_x2576*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2576_class *closure = (x2576_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2576_class *x2576_closure = new x2576_class(x2538,x2448);
x2576_closure->loopStart = 0;
x2576_closure->loopSize = x2538;
activation_x2576 * alloc = x2576_closure->alloc(resourceInfo);
activation_x2576 * x2576 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2576 = x2576_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2576*> * sync = new MultiLoopSync<activation_x2576*>(x2576_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2576_closure->allocVal = alloc;
x2576_closure->syncVal = sync;
submitWork(r->threadId, x2576_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2576_closure)));
i = i+1;
}
x2576 = x2576_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2576;
}

/**********/

