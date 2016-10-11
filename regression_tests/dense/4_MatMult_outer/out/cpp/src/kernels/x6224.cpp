//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6224 * kernel_x6224(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x6222) {
class x6224_class{
public:
int32_t x7;
cppDeliteArraycppDeliteArrayint32_t *x6222;

x6224_class(int32_t  _x7,cppDeliteArraycppDeliteArrayint32_t * _x6222) {
x7 = _x7;
x6222 = _x6222;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x7;
}

int64_t loopStart;
int64_t loopSize;
activation_x6224 *alloc(resourceInfo_t *resourceInfo) {
activation_x6224 * __act = new activation_x6224();;
// __act->x6224 stays null for now
return __act;
}

activation_x6224 *main_par(resourceInfo_t *resourceInfo,activation_x6224 *__act,MultiLoopSync<activation_x6224*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6224 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6224 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x6224 * currentAct = act;
while (j < localEnd) {
activation_x6224 * rhsAct = sync->get(j);
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

activation_x6224 *main_seq(resourceInfo_t *resourceInfo,activation_x6224 *__act) {
activation_x6224 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x6224 *processRange(resourceInfo_t *resourceInfo,activation_x6224 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6224 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6224 *init(resourceInfo_t *resourceInfo,activation_x6224 *__act,int32_t x831,bool isEmpty) {
activation_x6224 * __act2 = new activation_x6224();;
int32_t x839 = 0;
assert(x839 < (size_t)-1);
cppDeliteArrayint32_t *x5995 = new (resourceInfo) cppDeliteArrayint32_t(x839, resourceInfo);
__act2->x6224_buf = x5995;
if (!isEmpty) {
cppDeliteArrayint32_t *x6223 = x6222->apply(x831);
cppDeliteArrayint32_t *x834 = x6223;
int32_t x835 = x834->length;
int32_t  x833 = 0;
while (x833 < x835) { //flatMap loop
int32_t x836 = x834->apply(x833);
cppDeliteArrayint32_t *x837 = __act2->x6224_buf;
int32_t x838 = x836;
if (true) {
int32_t x6001 = __act2->x6224_size;
int32_t x6002 = x837->length;
int32_t x6003 = x6002 - 1;
bool x6004 = x6001 > x6003;
if (x6004) {
bool x6005 = x6002 < 16;
int32_t  x6009;
if (x6005) {
x6009 = 16;
} else {
int32_t x6006 = x6002 * 2;
bool x6007 = x6006 < 0;
int32_t  x6008;
if (x6007) {
x6008 = 2147483647;
} else {
x6008 = x6006;
}
x6009 = x6008;
}
assert(x6009 < (size_t)-1);
cppDeliteArrayint32_t *x6010 = new (resourceInfo) cppDeliteArrayint32_t(x6009, resourceInfo);
if((x837->data==x6010->data) && (0<0))
std::copy_backward(x837->data+0,x837->data+0+x6002,x6010->data+0+x6002);
else {
for (size_t s=0, d=0; s<0+x6002; s++, d++){
x6010->update(d, x837->apply(s));
}
}
x6010->update(x6001, x838);
__act2->x6224_buf = x6010;
} else {
x837->update(x6001, x838);
}
__act2->x6224_size = __act2->x6224_size + 1;
}
__act2->x6224_conditionals = __act2->x6224_conditionals + 1;
x833 = x833 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x6224 *__act,int32_t x831) {
cppDeliteArrayint32_t *x6223 = x6222->apply(x831);
cppDeliteArrayint32_t *x834 = x6223;
int32_t x835 = x834->length;
int32_t  x833 = 0;
while (x833 < x835) { //flatMap loop
int32_t x836 = x834->apply(x833);
cppDeliteArrayint32_t *x837 = __act->x6224_buf;
int32_t x838 = x836;
if (true) {
int32_t x6001 = __act->x6224_size;
int32_t x6002 = x837->length;
int32_t x6003 = x6002 - 1;
bool x6004 = x6001 > x6003;
if (x6004) {
bool x6005 = x6002 < 16;
int32_t  x6009;
if (x6005) {
x6009 = 16;
} else {
int32_t x6006 = x6002 * 2;
bool x6007 = x6006 < 0;
int32_t  x6008;
if (x6007) {
x6008 = 2147483647;
} else {
x6008 = x6006;
}
x6009 = x6008;
}
assert(x6009 < (size_t)-1);
cppDeliteArrayint32_t *x6010 = new (resourceInfo) cppDeliteArrayint32_t(x6009, resourceInfo);
if((x837->data==x6010->data) && (0<0))
std::copy_backward(x837->data+0,x837->data+0+x6002,x6010->data+0+x6002);
else {
for (size_t s=0, d=0; s<0+x6002; s++, d++){
x6010->update(d, x837->apply(s));
}
}
x6010->update(x6001, x838);
__act->x6224_buf = x6010;
} else {
x837->update(x6001, x838);
}
__act->x6224_size = __act->x6224_size + 1;
}
__act->x6224_conditionals = __act->x6224_conditionals + 1;
x833 = x833 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x6224 *__act,activation_x6224 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6224 *__act,activation_x6224 *lhs) {
__act->x6224_offset = lhs->x6224_offset+lhs->x6224_size;
__act->x6224_conditionals = __act->x6224_conditionals+lhs->x6224_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6224 *__act) {
if (__act->x6224_offset > 0) {
int32_t x839 = __act->x6224_offset + __act->x6224_size;
cppDeliteArrayint32_t *x837 = __act->x6224_buf;
assert(x839 < (size_t)-1);
cppDeliteArrayint32_t *x6027 = new (resourceInfo) cppDeliteArrayint32_t(x839);
__act->x6224_data_set(resourceInfo,x6027,__act->x6224_conditionals);
} else {
__act->x6224_data_set(resourceInfo,__act->x6224_buf,__act->x6224_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6224 *__act) {
if (__act->x6224_data != __act->x6224_buf) {
int32_t x839 = __act->x6224_size;
cppDeliteArrayint32_t *x842 = __act->x6224_buf;
cppDeliteArrayint32_t *x837 = __act->x6224_data;
int32_t x840 = 0;
int32_t x841 = __act->x6224_offset;
if((x842->data==x837->data) && (x840<x841))
std::copy_backward(x842->data+x840,x842->data+x840+x839,x837->data+x841+x839);
else {
for (size_t s=x840, d=x841; s<x840+x839; s++, d++){
x837->update(d, x842->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x6224 *__act) {
cppDeliteArrayint32_t * x837 = __act->x6224_data;
int32_t x839 = __act->x6224_conditionals;
int32_t x6019 = x837->length;
bool x6020 = x6019 > x839;
if (x6020) {
assert(x839 < (size_t)-1);
cppDeliteArrayint32_t *x6021 = new (resourceInfo) cppDeliteArrayint32_t(x839);
if((x837->data==x6021->data) && (0<0))
std::copy_backward(x837->data+0,x837->data+0+x839,x6021->data+0+x839);
else {
for (size_t s=0, d=0; s<0+x839; s++, d++){
x6021->update(d, x837->apply(s));
}
}
x837 = x6021;
} else {
}
__act->x6224 = x837;
}

activation_x6224 *initAct(resourceInfo_t *resourceInfo) {
activation_x6224 * act = new activation_x6224;
return act;
}

activation_x6224 *allocVal;
MultiLoopSync<activation_x6224*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6224_class *closure = (x6224_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6224_class *x6224_closure = new x6224_class(x7,x6222);
x6224_closure->loopStart = 0;
x6224_closure->loopSize = x7;
activation_x6224 * alloc = x6224_closure->alloc(resourceInfo);
activation_x6224 * x6224 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6224 = x6224_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6224*> * sync = new MultiLoopSync<activation_x6224*>(x6224_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6224_closure->allocVal = alloc;
x6224_closure->syncVal = sync;
submitWork(r->threadId, x6224_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6224_closure)));
i = i+1;
}
x6224 = x6224_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6224;
}

/**********/

