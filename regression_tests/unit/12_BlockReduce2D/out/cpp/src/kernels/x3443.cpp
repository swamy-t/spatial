//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3443 * kernel_x3443(resourceInfo_t *resourceInfo,int32_t  x5, cppDeliteArraycppDeliteArrayint32_t  *x3405) {
class x3443_class{
public:
int32_t x5;
cppDeliteArraycppDeliteArrayint32_t *x3405;

x3443_class(int32_t  _x5,cppDeliteArraycppDeliteArrayint32_t * _x3405) {
x5 = _x5;
x3405 = _x3405;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x5;
}

int64_t loopStart;
int64_t loopSize;
activation_x3443 *alloc(resourceInfo_t *resourceInfo) {
activation_x3443 * __act = new activation_x3443();;
// __act->x3443 stays null for now
return __act;
}

activation_x3443 *main_par(resourceInfo_t *resourceInfo,activation_x3443 *__act,MultiLoopSync<activation_x3443*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3443 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3443 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x3443 * currentAct = act;
while (j < localEnd) {
activation_x3443 * rhsAct = sync->get(j);
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

activation_x3443 *main_seq(resourceInfo_t *resourceInfo,activation_x3443 *__act) {
activation_x3443 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x3443 *processRange(resourceInfo_t *resourceInfo,activation_x3443 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3443 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3443 *init(resourceInfo_t *resourceInfo,activation_x3443 *__act,int32_t x148,bool isEmpty) {
activation_x3443 * __act2 = new activation_x3443();;
int32_t x156 = 0;
assert(x156 < (size_t)-1);
cppDeliteArrayint32_t *x3406 = new (resourceInfo) cppDeliteArrayint32_t(x156, resourceInfo);
__act2->x3443_buf = x3406;
if (!isEmpty) {
cppDeliteArrayint32_t *x3442 = x3405->apply(x148);
cppDeliteArrayint32_t *x151 = x3442;
int32_t x152 = x151->length;
int32_t  x150 = 0;
while (x150 < x152) { //flatMap loop
int32_t x153 = x151->apply(x150);
cppDeliteArrayint32_t *x154 = __act2->x3443_buf;
int32_t x155 = x153;
if (true) {
int32_t x3412 = __act2->x3443_size;
int32_t x3413 = x154->length;
int32_t x3414 = x3413 - 1;
bool x3415 = x3412 > x3414;
if (x3415) {
bool x3416 = x3413 < 16;
int32_t  x3420;
if (x3416) {
x3420 = 16;
} else {
int32_t x3417 = x3413 * 2;
bool x3418 = x3417 < 0;
int32_t  x3419;
if (x3418) {
x3419 = 2147483647;
} else {
x3419 = x3417;
}
x3420 = x3419;
}
assert(x3420 < (size_t)-1);
cppDeliteArrayint32_t *x3421 = new (resourceInfo) cppDeliteArrayint32_t(x3420, resourceInfo);
if((x154->data==x3421->data) && (0<0))
std::copy_backward(x154->data+0,x154->data+0+x3413,x3421->data+0+x3413);
else {
for (size_t s=0, d=0; s<0+x3413; s++, d++){
x3421->update(d, x154->apply(s));
}
}
x3421->update(x3412, x155);
__act2->x3443_buf = x3421;
} else {
x154->update(x3412, x155);
}
__act2->x3443_size = __act2->x3443_size + 1;
}
__act2->x3443_conditionals = __act2->x3443_conditionals + 1;
x150 = x150 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x3443 *__act,int32_t x148) {
cppDeliteArrayint32_t *x3442 = x3405->apply(x148);
cppDeliteArrayint32_t *x151 = x3442;
int32_t x152 = x151->length;
int32_t  x150 = 0;
while (x150 < x152) { //flatMap loop
int32_t x153 = x151->apply(x150);
cppDeliteArrayint32_t *x154 = __act->x3443_buf;
int32_t x155 = x153;
if (true) {
int32_t x3412 = __act->x3443_size;
int32_t x3413 = x154->length;
int32_t x3414 = x3413 - 1;
bool x3415 = x3412 > x3414;
if (x3415) {
bool x3416 = x3413 < 16;
int32_t  x3420;
if (x3416) {
x3420 = 16;
} else {
int32_t x3417 = x3413 * 2;
bool x3418 = x3417 < 0;
int32_t  x3419;
if (x3418) {
x3419 = 2147483647;
} else {
x3419 = x3417;
}
x3420 = x3419;
}
assert(x3420 < (size_t)-1);
cppDeliteArrayint32_t *x3421 = new (resourceInfo) cppDeliteArrayint32_t(x3420, resourceInfo);
if((x154->data==x3421->data) && (0<0))
std::copy_backward(x154->data+0,x154->data+0+x3413,x3421->data+0+x3413);
else {
for (size_t s=0, d=0; s<0+x3413; s++, d++){
x3421->update(d, x154->apply(s));
}
}
x3421->update(x3412, x155);
__act->x3443_buf = x3421;
} else {
x154->update(x3412, x155);
}
__act->x3443_size = __act->x3443_size + 1;
}
__act->x3443_conditionals = __act->x3443_conditionals + 1;
x150 = x150 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x3443 *__act,activation_x3443 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3443 *__act,activation_x3443 *lhs) {
__act->x3443_offset = lhs->x3443_offset+lhs->x3443_size;
__act->x3443_conditionals = __act->x3443_conditionals+lhs->x3443_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3443 *__act) {
if (__act->x3443_offset > 0) {
int32_t x156 = __act->x3443_offset + __act->x3443_size;
cppDeliteArrayint32_t *x154 = __act->x3443_buf;
assert(x156 < (size_t)-1);
cppDeliteArrayint32_t *x3438 = new (resourceInfo) cppDeliteArrayint32_t(x156);
__act->x3443_data_set(resourceInfo,x3438,__act->x3443_conditionals);
} else {
__act->x3443_data_set(resourceInfo,__act->x3443_buf,__act->x3443_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3443 *__act) {
if (__act->x3443_data != __act->x3443_buf) {
int32_t x156 = __act->x3443_size;
cppDeliteArrayint32_t *x159 = __act->x3443_buf;
cppDeliteArrayint32_t *x154 = __act->x3443_data;
int32_t x157 = 0;
int32_t x158 = __act->x3443_offset;
if((x159->data==x154->data) && (x157<x158))
std::copy_backward(x159->data+x157,x159->data+x157+x156,x154->data+x158+x156);
else {
for (size_t s=x157, d=x158; s<x157+x156; s++, d++){
x154->update(d, x159->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x3443 *__act) {
cppDeliteArrayint32_t * x154 = __act->x3443_data;
int32_t x156 = __act->x3443_conditionals;
int32_t x3430 = x154->length;
bool x3431 = x3430 > x156;
if (x3431) {
assert(x156 < (size_t)-1);
cppDeliteArrayint32_t *x3432 = new (resourceInfo) cppDeliteArrayint32_t(x156);
if((x154->data==x3432->data) && (0<0))
std::copy_backward(x154->data+0,x154->data+0+x156,x3432->data+0+x156);
else {
for (size_t s=0, d=0; s<0+x156; s++, d++){
x3432->update(d, x154->apply(s));
}
}
x154 = x3432;
} else {
}
__act->x3443 = x154;
}

activation_x3443 *initAct(resourceInfo_t *resourceInfo) {
activation_x3443 * act = new activation_x3443;
return act;
}

activation_x3443 *allocVal;
MultiLoopSync<activation_x3443*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3443_class *closure = (x3443_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3443_class *x3443_closure = new x3443_class(x5,x3405);
x3443_closure->loopStart = 0;
x3443_closure->loopSize = x5;
activation_x3443 * alloc = x3443_closure->alloc(resourceInfo);
activation_x3443 * x3443 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3443 = x3443_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3443*> * sync = new MultiLoopSync<activation_x3443*>(x3443_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3443_closure->allocVal = alloc;
x3443_closure->syncVal = sync;
submitWork(r->threadId, x3443_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3443_closure)));
i = i+1;
}
x3443 = x3443_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3443;
}

/**********/

