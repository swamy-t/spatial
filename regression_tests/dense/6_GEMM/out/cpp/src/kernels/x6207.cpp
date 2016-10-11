//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6207 * kernel_x6207(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x6205) {
class x6207_class{
public:
int32_t x7;
cppDeliteArraycppDeliteArrayint32_t *x6205;

x6207_class(int32_t  _x7,cppDeliteArraycppDeliteArrayint32_t * _x6205) {
x7 = _x7;
x6205 = _x6205;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x7;
}

int64_t loopStart;
int64_t loopSize;
activation_x6207 *alloc(resourceInfo_t *resourceInfo) {
activation_x6207 * __act = new activation_x6207();;
// __act->x6207 stays null for now
return __act;
}

activation_x6207 *main_par(resourceInfo_t *resourceInfo,activation_x6207 *__act,MultiLoopSync<activation_x6207*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6207 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6207 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x6207 * currentAct = act;
while (j < localEnd) {
activation_x6207 * rhsAct = sync->get(j);
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

activation_x6207 *main_seq(resourceInfo_t *resourceInfo,activation_x6207 *__act) {
activation_x6207 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x6207 *processRange(resourceInfo_t *resourceInfo,activation_x6207 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6207 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6207 *init(resourceInfo_t *resourceInfo,activation_x6207 *__act,int32_t x881,bool isEmpty) {
activation_x6207 * __act2 = new activation_x6207();;
int32_t x889 = 0;
assert(x889 < (size_t)-1);
cppDeliteArrayint32_t *x5996 = new (resourceInfo) cppDeliteArrayint32_t(x889, resourceInfo);
__act2->x6207_buf = x5996;
if (!isEmpty) {
cppDeliteArrayint32_t *x6206 = x6205->apply(x881);
cppDeliteArrayint32_t *x884 = x6206;
int32_t x885 = x884->length;
int32_t  x883 = 0;
while (x883 < x885) { //flatMap loop
int32_t x886 = x884->apply(x883);
cppDeliteArrayint32_t *x887 = __act2->x6207_buf;
int32_t x888 = x886;
if (true) {
int32_t x6002 = __act2->x6207_size;
int32_t x6003 = x887->length;
int32_t x6004 = x6003 - 1;
bool x6005 = x6002 > x6004;
if (x6005) {
bool x6006 = x6003 < 16;
int32_t  x6010;
if (x6006) {
x6010 = 16;
} else {
int32_t x6007 = x6003 * 2;
bool x6008 = x6007 < 0;
int32_t  x6009;
if (x6008) {
x6009 = 2147483647;
} else {
x6009 = x6007;
}
x6010 = x6009;
}
assert(x6010 < (size_t)-1);
cppDeliteArrayint32_t *x6011 = new (resourceInfo) cppDeliteArrayint32_t(x6010, resourceInfo);
if((x887->data==x6011->data) && (0<0))
std::copy_backward(x887->data+0,x887->data+0+x6003,x6011->data+0+x6003);
else {
for (size_t s=0, d=0; s<0+x6003; s++, d++){
x6011->update(d, x887->apply(s));
}
}
x6011->update(x6002, x888);
__act2->x6207_buf = x6011;
} else {
x887->update(x6002, x888);
}
__act2->x6207_size = __act2->x6207_size + 1;
}
__act2->x6207_conditionals = __act2->x6207_conditionals + 1;
x883 = x883 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x6207 *__act,int32_t x881) {
cppDeliteArrayint32_t *x6206 = x6205->apply(x881);
cppDeliteArrayint32_t *x884 = x6206;
int32_t x885 = x884->length;
int32_t  x883 = 0;
while (x883 < x885) { //flatMap loop
int32_t x886 = x884->apply(x883);
cppDeliteArrayint32_t *x887 = __act->x6207_buf;
int32_t x888 = x886;
if (true) {
int32_t x6002 = __act->x6207_size;
int32_t x6003 = x887->length;
int32_t x6004 = x6003 - 1;
bool x6005 = x6002 > x6004;
if (x6005) {
bool x6006 = x6003 < 16;
int32_t  x6010;
if (x6006) {
x6010 = 16;
} else {
int32_t x6007 = x6003 * 2;
bool x6008 = x6007 < 0;
int32_t  x6009;
if (x6008) {
x6009 = 2147483647;
} else {
x6009 = x6007;
}
x6010 = x6009;
}
assert(x6010 < (size_t)-1);
cppDeliteArrayint32_t *x6011 = new (resourceInfo) cppDeliteArrayint32_t(x6010, resourceInfo);
if((x887->data==x6011->data) && (0<0))
std::copy_backward(x887->data+0,x887->data+0+x6003,x6011->data+0+x6003);
else {
for (size_t s=0, d=0; s<0+x6003; s++, d++){
x6011->update(d, x887->apply(s));
}
}
x6011->update(x6002, x888);
__act->x6207_buf = x6011;
} else {
x887->update(x6002, x888);
}
__act->x6207_size = __act->x6207_size + 1;
}
__act->x6207_conditionals = __act->x6207_conditionals + 1;
x883 = x883 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x6207 *__act,activation_x6207 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6207 *__act,activation_x6207 *lhs) {
__act->x6207_offset = lhs->x6207_offset+lhs->x6207_size;
__act->x6207_conditionals = __act->x6207_conditionals+lhs->x6207_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6207 *__act) {
if (__act->x6207_offset > 0) {
int32_t x889 = __act->x6207_offset + __act->x6207_size;
cppDeliteArrayint32_t *x887 = __act->x6207_buf;
assert(x889 < (size_t)-1);
cppDeliteArrayint32_t *x6028 = new (resourceInfo) cppDeliteArrayint32_t(x889);
__act->x6207_data_set(resourceInfo,x6028,__act->x6207_conditionals);
} else {
__act->x6207_data_set(resourceInfo,__act->x6207_buf,__act->x6207_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6207 *__act) {
if (__act->x6207_data != __act->x6207_buf) {
int32_t x889 = __act->x6207_size;
cppDeliteArrayint32_t *x892 = __act->x6207_buf;
cppDeliteArrayint32_t *x887 = __act->x6207_data;
int32_t x890 = 0;
int32_t x891 = __act->x6207_offset;
if((x892->data==x887->data) && (x890<x891))
std::copy_backward(x892->data+x890,x892->data+x890+x889,x887->data+x891+x889);
else {
for (size_t s=x890, d=x891; s<x890+x889; s++, d++){
x887->update(d, x892->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x6207 *__act) {
cppDeliteArrayint32_t * x887 = __act->x6207_data;
int32_t x889 = __act->x6207_conditionals;
int32_t x6020 = x887->length;
bool x6021 = x6020 > x889;
if (x6021) {
assert(x889 < (size_t)-1);
cppDeliteArrayint32_t *x6022 = new (resourceInfo) cppDeliteArrayint32_t(x889);
if((x887->data==x6022->data) && (0<0))
std::copy_backward(x887->data+0,x887->data+0+x889,x6022->data+0+x889);
else {
for (size_t s=0, d=0; s<0+x889; s++, d++){
x6022->update(d, x887->apply(s));
}
}
x887 = x6022;
} else {
}
__act->x6207 = x887;
}

activation_x6207 *initAct(resourceInfo_t *resourceInfo) {
activation_x6207 * act = new activation_x6207;
return act;
}

activation_x6207 *allocVal;
MultiLoopSync<activation_x6207*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6207_class *closure = (x6207_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6207_class *x6207_closure = new x6207_class(x7,x6205);
x6207_closure->loopStart = 0;
x6207_closure->loopSize = x7;
activation_x6207 * alloc = x6207_closure->alloc(resourceInfo);
activation_x6207 * x6207 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6207 = x6207_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6207*> * sync = new MultiLoopSync<activation_x6207*>(x6207_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6207_closure->allocVal = alloc;
x6207_closure->syncVal = sync;
submitWork(r->threadId, x6207_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6207_closure)));
i = i+1;
}
x6207 = x6207_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6207;
}

/**********/

