//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5451x6187 * kernel_x5451x6187(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArrayint32_t  *x6186, cppDeliteArraycppDeliteArrayint32_t  *x5413) {
class x5451x6187_class{
public:
int32_t x7;
cppDeliteArrayint32_t *x6186;
cppDeliteArraycppDeliteArrayint32_t *x5413;

x5451x6187_class(int32_t  _x7,cppDeliteArrayint32_t * _x6186,cppDeliteArraycppDeliteArrayint32_t * _x5413) {
x7 = _x7;
x6186 = _x6186;
x5413 = _x5413;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x7;
}

int64_t loopStart;
int64_t loopSize;
activation_x5451x6187 *alloc(resourceInfo_t *resourceInfo) {
activation_x5451x6187 * __act = new activation_x5451x6187();;
// __act->x5451 stays null for now
int32_t x235 = (int32_t)(loopSize);
assert(x235 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x5603 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x235);
__act->x6187_data = x5603;
return __act;
}

activation_x5451x6187 *main_par(resourceInfo_t *resourceInfo,activation_x5451x6187 *__act,MultiLoopSync<activation_x5451x6187*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5451x6187 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5451x6187 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x5451x6187 * currentAct = act;
while (j < localEnd) {
activation_x5451x6187 * rhsAct = sync->get(j);
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

activation_x5451x6187 *main_seq(resourceInfo_t *resourceInfo,activation_x5451x6187 *__act) {
activation_x5451x6187 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x5451x6187 *processRange(resourceInfo_t *resourceInfo,activation_x5451x6187 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5451x6187 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5451x6187 *init(resourceInfo_t *resourceInfo,activation_x5451x6187 *__act,int32_t x276,bool isEmpty) {
activation_x5451x6187 * __act2 = new activation_x5451x6187();;
int32_t x284 = 0;
assert(x284 < (size_t)-1);
cppDeliteArrayint32_t *x5414 = new (resourceInfo) cppDeliteArrayint32_t(x284, resourceInfo);
__act2->x5451_buf = x5414;
__act2->x6187_data = __act->x6187_data;
if (!isEmpty) {
cppDeliteArrayint32_t *x5450 = x5413->apply(x276);
cppDeliteArrayint32_t *x279 = x5450;
int32_t x280 = x279->length;
int32_t  x278 = 0;
while (x278 < x280) { //flatMap loop
int32_t x281 = x279->apply(x278);
cppDeliteArrayint32_t *x282 = __act2->x5451_buf;
int32_t x283 = x281;
if (true) {
int32_t x5420 = __act2->x5451_size;
int32_t x5421 = x282->length;
int32_t x5422 = x5421 - 1;
bool x5423 = x5420 > x5422;
if (x5423) {
bool x5424 = x5421 < 16;
int32_t  x5428;
if (x5424) {
x5428 = 16;
} else {
int32_t x5425 = x5421 * 2;
bool x5426 = x5425 < 0;
int32_t  x5427;
if (x5426) {
x5427 = 2147483647;
} else {
x5427 = x5425;
}
x5428 = x5427;
}
assert(x5428 < (size_t)-1);
cppDeliteArrayint32_t *x5429 = new (resourceInfo) cppDeliteArrayint32_t(x5428, resourceInfo);
if((x282->data==x5429->data) && (0<0))
std::copy_backward(x282->data+0,x282->data+0+x5421,x5429->data+0+x5421);
else {
for (size_t s=0, d=0; s<0+x5421; s++, d++){
x5429->update(d, x282->apply(s));
}
}
x5429->update(x5420, x283);
__act2->x5451_buf = x5429;
} else {
x282->update(x5420, x283);
}
__act2->x5451_size = __act2->x5451_size + 1;
}
__act2->x5451_conditionals = __act2->x5451_conditionals + 1;
x278 = x278 + 1;
}
cppDeliteArrayint32_t *x234 = x6186;
cppDeliteArraycppDeliteArrayint32_t *x233 = __act2->x6187_data;
x233->update(x276, x234);
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x5451x6187 *__act,int32_t x276) {
cppDeliteArrayint32_t *x5450 = x5413->apply(x276);
cppDeliteArrayint32_t *x279 = x5450;
int32_t x280 = x279->length;
int32_t  x278 = 0;
while (x278 < x280) { //flatMap loop
int32_t x281 = x279->apply(x278);
cppDeliteArrayint32_t *x282 = __act->x5451_buf;
int32_t x283 = x281;
if (true) {
int32_t x5420 = __act->x5451_size;
int32_t x5421 = x282->length;
int32_t x5422 = x5421 - 1;
bool x5423 = x5420 > x5422;
if (x5423) {
bool x5424 = x5421 < 16;
int32_t  x5428;
if (x5424) {
x5428 = 16;
} else {
int32_t x5425 = x5421 * 2;
bool x5426 = x5425 < 0;
int32_t  x5427;
if (x5426) {
x5427 = 2147483647;
} else {
x5427 = x5425;
}
x5428 = x5427;
}
assert(x5428 < (size_t)-1);
cppDeliteArrayint32_t *x5429 = new (resourceInfo) cppDeliteArrayint32_t(x5428, resourceInfo);
if((x282->data==x5429->data) && (0<0))
std::copy_backward(x282->data+0,x282->data+0+x5421,x5429->data+0+x5421);
else {
for (size_t s=0, d=0; s<0+x5421; s++, d++){
x5429->update(d, x282->apply(s));
}
}
x5429->update(x5420, x283);
__act->x5451_buf = x5429;
} else {
x282->update(x5420, x283);
}
__act->x5451_size = __act->x5451_size + 1;
}
__act->x5451_conditionals = __act->x5451_conditionals + 1;
x278 = x278 + 1;
}
cppDeliteArrayint32_t *x234 = x6186;
cppDeliteArraycppDeliteArrayint32_t *x233 = __act->x6187_data;
x233->update(x276, x234);
}

void combine(resourceInfo_t *resourceInfo,activation_x5451x6187 *__act,activation_x5451x6187 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5451x6187 *__act,activation_x5451x6187 *lhs) {
__act->x5451_offset = lhs->x5451_offset+lhs->x5451_size;
__act->x5451_conditionals = __act->x5451_conditionals+lhs->x5451_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5451x6187 *__act) {
if (__act->x5451_offset > 0) {
int32_t x284 = __act->x5451_offset + __act->x5451_size;
cppDeliteArrayint32_t *x282 = __act->x5451_buf;
assert(x284 < (size_t)-1);
cppDeliteArrayint32_t *x5446 = new (resourceInfo) cppDeliteArrayint32_t(x284);
__act->x5451_data_set(resourceInfo,x5446,__act->x5451_conditionals);
} else {
__act->x5451_data_set(resourceInfo,__act->x5451_buf,__act->x5451_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5451x6187 *__act) {
if (__act->x5451_data != __act->x5451_buf) {
int32_t x284 = __act->x5451_size;
cppDeliteArrayint32_t *x287 = __act->x5451_buf;
cppDeliteArrayint32_t *x282 = __act->x5451_data;
int32_t x285 = 0;
int32_t x286 = __act->x5451_offset;
if((x287->data==x282->data) && (x285<x286))
std::copy_backward(x287->data+x285,x287->data+x285+x284,x282->data+x286+x284);
else {
for (size_t s=x285, d=x286; s<x285+x284; s++, d++){
x282->update(d, x287->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x5451x6187 *__act) {
cppDeliteArrayint32_t * x282 = __act->x5451_data;
int32_t x284 = __act->x5451_conditionals;
int32_t x5438 = x282->length;
bool x5439 = x5438 > x284;
if (x5439) {
assert(x284 < (size_t)-1);
cppDeliteArrayint32_t *x5440 = new (resourceInfo) cppDeliteArrayint32_t(x284);
if((x282->data==x5440->data) && (0<0))
std::copy_backward(x282->data+0,x282->data+0+x284,x5440->data+0+x284);
else {
for (size_t s=0, d=0; s<0+x284; s++, d++){
x5440->update(d, x282->apply(s));
}
}
x282 = x5440;
} else {
}
__act->x5451 = x282;
cppDeliteArraycppDeliteArrayint32_t * x233 = __act->x6187_data;
__act->x6187 = x233;
}

activation_x5451x6187 *initAct(resourceInfo_t *resourceInfo) {
activation_x5451x6187 * act = new activation_x5451x6187;
return act;
}

activation_x5451x6187 *allocVal;
MultiLoopSync<activation_x5451x6187*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5451x6187_class *closure = (x5451x6187_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5451x6187_class *x5451x6187_closure = new x5451x6187_class(x7,x6186,x5413);
x5451x6187_closure->loopStart = 0;
x5451x6187_closure->loopSize = x7;
activation_x5451x6187 * alloc = x5451x6187_closure->alloc(resourceInfo);
activation_x5451x6187 * x5451x6187 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5451x6187 = x5451x6187_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5451x6187*> * sync = new MultiLoopSync<activation_x5451x6187*>(x5451x6187_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5451x6187_closure->allocVal = alloc;
x5451x6187_closure->syncVal = sync;
submitWork(r->threadId, x5451x6187_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5451x6187_closure)));
i = i+1;
}
x5451x6187 = x5451x6187_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5451x6187;
}

/**********/

