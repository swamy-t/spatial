//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5399 * kernel_x5399(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x5397) {
class x5399_class{
public:
int32_t x7;
cppDeliteArraycppDeliteArrayint32_t *x5397;

x5399_class(int32_t  _x7,cppDeliteArraycppDeliteArrayint32_t * _x5397) {
x7 = _x7;
x5397 = _x5397;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x7;
}

int64_t loopStart;
int64_t loopSize;
activation_x5399 *alloc(resourceInfo_t *resourceInfo) {
activation_x5399 * __act = new activation_x5399();;
// __act->x5399 stays null for now
return __act;
}

activation_x5399 *main_par(resourceInfo_t *resourceInfo,activation_x5399 *__act,MultiLoopSync<activation_x5399*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5399 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5399 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x5399 * currentAct = act;
while (j < localEnd) {
activation_x5399 * rhsAct = sync->get(j);
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

activation_x5399 *main_seq(resourceInfo_t *resourceInfo,activation_x5399 *__act) {
activation_x5399 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x5399 *processRange(resourceInfo_t *resourceInfo,activation_x5399 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5399 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5399 *init(resourceInfo_t *resourceInfo,activation_x5399 *__act,int32_t x664,bool isEmpty) {
activation_x5399 * __act2 = new activation_x5399();;
int32_t x672 = 0;
assert(x672 < (size_t)-1);
cppDeliteArrayint32_t *x5196 = new (resourceInfo) cppDeliteArrayint32_t(x672, resourceInfo);
__act2->x5399_buf = x5196;
if (!isEmpty) {
cppDeliteArrayint32_t *x5398 = x5397->apply(x664);
cppDeliteArrayint32_t *x667 = x5398;
int32_t x668 = x667->length;
int32_t  x666 = 0;
while (x666 < x668) { //flatMap loop
int32_t x669 = x667->apply(x666);
cppDeliteArrayint32_t *x670 = __act2->x5399_buf;
int32_t x671 = x669;
if (true) {
int32_t x5202 = __act2->x5399_size;
int32_t x5203 = x670->length;
int32_t x5204 = x5203 - 1;
bool x5205 = x5202 > x5204;
if (x5205) {
bool x5206 = x5203 < 16;
int32_t  x5210;
if (x5206) {
x5210 = 16;
} else {
int32_t x5207 = x5203 * 2;
bool x5208 = x5207 < 0;
int32_t  x5209;
if (x5208) {
x5209 = 2147483647;
} else {
x5209 = x5207;
}
x5210 = x5209;
}
assert(x5210 < (size_t)-1);
cppDeliteArrayint32_t *x5211 = new (resourceInfo) cppDeliteArrayint32_t(x5210, resourceInfo);
if((x670->data==x5211->data) && (0<0))
std::copy_backward(x670->data+0,x670->data+0+x5203,x5211->data+0+x5203);
else {
for (size_t s=0, d=0; s<0+x5203; s++, d++){
x5211->update(d, x670->apply(s));
}
}
x5211->update(x5202, x671);
__act2->x5399_buf = x5211;
} else {
x670->update(x5202, x671);
}
__act2->x5399_size = __act2->x5399_size + 1;
}
__act2->x5399_conditionals = __act2->x5399_conditionals + 1;
x666 = x666 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x5399 *__act,int32_t x664) {
cppDeliteArrayint32_t *x5398 = x5397->apply(x664);
cppDeliteArrayint32_t *x667 = x5398;
int32_t x668 = x667->length;
int32_t  x666 = 0;
while (x666 < x668) { //flatMap loop
int32_t x669 = x667->apply(x666);
cppDeliteArrayint32_t *x670 = __act->x5399_buf;
int32_t x671 = x669;
if (true) {
int32_t x5202 = __act->x5399_size;
int32_t x5203 = x670->length;
int32_t x5204 = x5203 - 1;
bool x5205 = x5202 > x5204;
if (x5205) {
bool x5206 = x5203 < 16;
int32_t  x5210;
if (x5206) {
x5210 = 16;
} else {
int32_t x5207 = x5203 * 2;
bool x5208 = x5207 < 0;
int32_t  x5209;
if (x5208) {
x5209 = 2147483647;
} else {
x5209 = x5207;
}
x5210 = x5209;
}
assert(x5210 < (size_t)-1);
cppDeliteArrayint32_t *x5211 = new (resourceInfo) cppDeliteArrayint32_t(x5210, resourceInfo);
if((x670->data==x5211->data) && (0<0))
std::copy_backward(x670->data+0,x670->data+0+x5203,x5211->data+0+x5203);
else {
for (size_t s=0, d=0; s<0+x5203; s++, d++){
x5211->update(d, x670->apply(s));
}
}
x5211->update(x5202, x671);
__act->x5399_buf = x5211;
} else {
x670->update(x5202, x671);
}
__act->x5399_size = __act->x5399_size + 1;
}
__act->x5399_conditionals = __act->x5399_conditionals + 1;
x666 = x666 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x5399 *__act,activation_x5399 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5399 *__act,activation_x5399 *lhs) {
__act->x5399_offset = lhs->x5399_offset+lhs->x5399_size;
__act->x5399_conditionals = __act->x5399_conditionals+lhs->x5399_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5399 *__act) {
if (__act->x5399_offset > 0) {
int32_t x672 = __act->x5399_offset + __act->x5399_size;
cppDeliteArrayint32_t *x670 = __act->x5399_buf;
assert(x672 < (size_t)-1);
cppDeliteArrayint32_t *x5228 = new (resourceInfo) cppDeliteArrayint32_t(x672);
__act->x5399_data_set(resourceInfo,x5228,__act->x5399_conditionals);
} else {
__act->x5399_data_set(resourceInfo,__act->x5399_buf,__act->x5399_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5399 *__act) {
if (__act->x5399_data != __act->x5399_buf) {
int32_t x672 = __act->x5399_size;
cppDeliteArrayint32_t *x675 = __act->x5399_buf;
cppDeliteArrayint32_t *x670 = __act->x5399_data;
int32_t x673 = 0;
int32_t x674 = __act->x5399_offset;
if((x675->data==x670->data) && (x673<x674))
std::copy_backward(x675->data+x673,x675->data+x673+x672,x670->data+x674+x672);
else {
for (size_t s=x673, d=x674; s<x673+x672; s++, d++){
x670->update(d, x675->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x5399 *__act) {
cppDeliteArrayint32_t * x670 = __act->x5399_data;
int32_t x672 = __act->x5399_conditionals;
int32_t x5220 = x670->length;
bool x5221 = x5220 > x672;
if (x5221) {
assert(x672 < (size_t)-1);
cppDeliteArrayint32_t *x5222 = new (resourceInfo) cppDeliteArrayint32_t(x672);
if((x670->data==x5222->data) && (0<0))
std::copy_backward(x670->data+0,x670->data+0+x672,x5222->data+0+x672);
else {
for (size_t s=0, d=0; s<0+x672; s++, d++){
x5222->update(d, x670->apply(s));
}
}
x670 = x5222;
} else {
}
__act->x5399 = x670;
}

activation_x5399 *initAct(resourceInfo_t *resourceInfo) {
activation_x5399 * act = new activation_x5399;
return act;
}

activation_x5399 *allocVal;
MultiLoopSync<activation_x5399*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5399_class *closure = (x5399_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5399_class *x5399_closure = new x5399_class(x7,x5397);
x5399_closure->loopStart = 0;
x5399_closure->loopSize = x7;
activation_x5399 * alloc = x5399_closure->alloc(resourceInfo);
activation_x5399 * x5399 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5399 = x5399_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5399*> * sync = new MultiLoopSync<activation_x5399*>(x5399_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5399_closure->allocVal = alloc;
x5399_closure->syncVal = sync;
submitWork(r->threadId, x5399_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5399_closure)));
i = i+1;
}
x5399 = x5399_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5399;
}

/**********/

