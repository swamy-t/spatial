//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x4364 * kernel_x4364(resourceInfo_t *resourceInfo,int32_t  x4326, cppDeliteArraycppDeliteArrayint32_t  *x4279) {
class x4364_class{
public:
int32_t x4326;
cppDeliteArraycppDeliteArrayint32_t *x4279;

x4364_class(int32_t  _x4326,cppDeliteArraycppDeliteArrayint32_t * _x4279) {
x4326 = _x4326;
x4279 = _x4279;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x4326;
}

int64_t loopStart;
int64_t loopSize;
activation_x4364 *alloc(resourceInfo_t *resourceInfo) {
activation_x4364 * __act = new activation_x4364();;
// __act->x4364 stays null for now
return __act;
}

activation_x4364 *main_par(resourceInfo_t *resourceInfo,activation_x4364 *__act,MultiLoopSync<activation_x4364*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4364 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4364 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x4364 * currentAct = act;
while (j < localEnd) {
activation_x4364 * rhsAct = sync->get(j);
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

activation_x4364 *main_seq(resourceInfo_t *resourceInfo,activation_x4364 *__act) {
activation_x4364 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x4364 *processRange(resourceInfo_t *resourceInfo,activation_x4364 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4364 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4364 *init(resourceInfo_t *resourceInfo,activation_x4364 *__act,int32_t x237,bool isEmpty) {
activation_x4364 * __act2 = new activation_x4364();;
int32_t x245 = 0;
assert(x245 < (size_t)-1);
cppDeliteArrayint32_t *x4327 = new (resourceInfo) cppDeliteArrayint32_t(x245, resourceInfo);
__act2->x4364_buf = x4327;
if (!isEmpty) {
cppDeliteArrayint32_t *x4363 = x4279->apply(x237);
cppDeliteArrayint32_t *x240 = x4363;
int32_t x241 = x240->length;
int32_t  x239 = 0;
while (x239 < x241) { //flatMap loop
int32_t x242 = x240->apply(x239);
cppDeliteArrayint32_t *x243 = __act2->x4364_buf;
int32_t x244 = x242;
if (true) {
int32_t x4333 = __act2->x4364_size;
int32_t x4334 = x243->length;
int32_t x4335 = x4334 - 1;
bool x4336 = x4333 > x4335;
if (x4336) {
bool x4337 = x4334 < 16;
int32_t  x4341;
if (x4337) {
x4341 = 16;
} else {
int32_t x4338 = x4334 * 2;
bool x4339 = x4338 < 0;
int32_t  x4340;
if (x4339) {
x4340 = 2147483647;
} else {
x4340 = x4338;
}
x4341 = x4340;
}
assert(x4341 < (size_t)-1);
cppDeliteArrayint32_t *x4342 = new (resourceInfo) cppDeliteArrayint32_t(x4341, resourceInfo);
if((x243->data==x4342->data) && (0<0))
std::copy_backward(x243->data+0,x243->data+0+x4334,x4342->data+0+x4334);
else {
for (size_t s=0, d=0; s<0+x4334; s++, d++){
x4342->update(d, x243->apply(s));
}
}
x4342->update(x4333, x244);
__act2->x4364_buf = x4342;
} else {
x243->update(x4333, x244);
}
__act2->x4364_size = __act2->x4364_size + 1;
}
__act2->x4364_conditionals = __act2->x4364_conditionals + 1;
x239 = x239 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x4364 *__act,int32_t x237) {
cppDeliteArrayint32_t *x4363 = x4279->apply(x237);
cppDeliteArrayint32_t *x240 = x4363;
int32_t x241 = x240->length;
int32_t  x239 = 0;
while (x239 < x241) { //flatMap loop
int32_t x242 = x240->apply(x239);
cppDeliteArrayint32_t *x243 = __act->x4364_buf;
int32_t x244 = x242;
if (true) {
int32_t x4333 = __act->x4364_size;
int32_t x4334 = x243->length;
int32_t x4335 = x4334 - 1;
bool x4336 = x4333 > x4335;
if (x4336) {
bool x4337 = x4334 < 16;
int32_t  x4341;
if (x4337) {
x4341 = 16;
} else {
int32_t x4338 = x4334 * 2;
bool x4339 = x4338 < 0;
int32_t  x4340;
if (x4339) {
x4340 = 2147483647;
} else {
x4340 = x4338;
}
x4341 = x4340;
}
assert(x4341 < (size_t)-1);
cppDeliteArrayint32_t *x4342 = new (resourceInfo) cppDeliteArrayint32_t(x4341, resourceInfo);
if((x243->data==x4342->data) && (0<0))
std::copy_backward(x243->data+0,x243->data+0+x4334,x4342->data+0+x4334);
else {
for (size_t s=0, d=0; s<0+x4334; s++, d++){
x4342->update(d, x243->apply(s));
}
}
x4342->update(x4333, x244);
__act->x4364_buf = x4342;
} else {
x243->update(x4333, x244);
}
__act->x4364_size = __act->x4364_size + 1;
}
__act->x4364_conditionals = __act->x4364_conditionals + 1;
x239 = x239 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x4364 *__act,activation_x4364 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4364 *__act,activation_x4364 *lhs) {
__act->x4364_offset = lhs->x4364_offset+lhs->x4364_size;
__act->x4364_conditionals = __act->x4364_conditionals+lhs->x4364_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4364 *__act) {
if (__act->x4364_offset > 0) {
int32_t x245 = __act->x4364_offset + __act->x4364_size;
cppDeliteArrayint32_t *x243 = __act->x4364_buf;
assert(x245 < (size_t)-1);
cppDeliteArrayint32_t *x4359 = new (resourceInfo) cppDeliteArrayint32_t(x245);
__act->x4364_data_set(resourceInfo,x4359,__act->x4364_conditionals);
} else {
__act->x4364_data_set(resourceInfo,__act->x4364_buf,__act->x4364_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4364 *__act) {
if (__act->x4364_data != __act->x4364_buf) {
int32_t x245 = __act->x4364_size;
cppDeliteArrayint32_t *x248 = __act->x4364_buf;
cppDeliteArrayint32_t *x243 = __act->x4364_data;
int32_t x246 = 0;
int32_t x247 = __act->x4364_offset;
if((x248->data==x243->data) && (x246<x247))
std::copy_backward(x248->data+x246,x248->data+x246+x245,x243->data+x247+x245);
else {
for (size_t s=x246, d=x247; s<x246+x245; s++, d++){
x243->update(d, x248->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x4364 *__act) {
cppDeliteArrayint32_t * x243 = __act->x4364_data;
int32_t x245 = __act->x4364_conditionals;
int32_t x4351 = x243->length;
bool x4352 = x4351 > x245;
if (x4352) {
assert(x245 < (size_t)-1);
cppDeliteArrayint32_t *x4353 = new (resourceInfo) cppDeliteArrayint32_t(x245);
if((x243->data==x4353->data) && (0<0))
std::copy_backward(x243->data+0,x243->data+0+x245,x4353->data+0+x245);
else {
for (size_t s=0, d=0; s<0+x245; s++, d++){
x4353->update(d, x243->apply(s));
}
}
x243 = x4353;
} else {
}
__act->x4364 = x243;
}

activation_x4364 *initAct(resourceInfo_t *resourceInfo) {
activation_x4364 * act = new activation_x4364;
return act;
}

activation_x4364 *allocVal;
MultiLoopSync<activation_x4364*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4364_class *closure = (x4364_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4364_class *x4364_closure = new x4364_class(x4326,x4279);
x4364_closure->loopStart = 0;
x4364_closure->loopSize = x4326;
activation_x4364 * alloc = x4364_closure->alloc(resourceInfo);
activation_x4364 * x4364 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4364 = x4364_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4364*> * sync = new MultiLoopSync<activation_x4364*>(x4364_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4364_closure->allocVal = alloc;
x4364_closure->syncVal = sync;
submitWork(r->threadId, x4364_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4364_closure)));
i = i+1;
}
x4364 = x4364_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4364;
}

/**********/

