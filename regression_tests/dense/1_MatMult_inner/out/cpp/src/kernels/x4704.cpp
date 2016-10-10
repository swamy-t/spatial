//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x4704 * kernel_x4704(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x4666) {
class x4704_class{
public:
int32_t x7;
cppDeliteArraycppDeliteArrayint32_t *x4666;

x4704_class(int32_t  _x7,cppDeliteArraycppDeliteArrayint32_t * _x4666) {
x7 = _x7;
x4666 = _x4666;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x7;
}

int64_t loopStart;
int64_t loopSize;
activation_x4704 *alloc(resourceInfo_t *resourceInfo) {
activation_x4704 * __act = new activation_x4704();;
// __act->x4704 stays null for now
return __act;
}

activation_x4704 *main_par(resourceInfo_t *resourceInfo,activation_x4704 *__act,MultiLoopSync<activation_x4704*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4704 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4704 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x4704 * currentAct = act;
while (j < localEnd) {
activation_x4704 * rhsAct = sync->get(j);
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

activation_x4704 *main_seq(resourceInfo_t *resourceInfo,activation_x4704 *__act) {
activation_x4704 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x4704 *processRange(resourceInfo_t *resourceInfo,activation_x4704 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4704 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4704 *init(resourceInfo_t *resourceInfo,activation_x4704 *__act,int32_t x187,bool isEmpty) {
activation_x4704 * __act2 = new activation_x4704();;
int32_t x195 = 0;
assert(x195 < (size_t)-1);
cppDeliteArrayint32_t *x4667 = new (resourceInfo) cppDeliteArrayint32_t(x195, resourceInfo);
__act2->x4704_buf = x4667;
if (!isEmpty) {
cppDeliteArrayint32_t *x4703 = x4666->apply(x187);
cppDeliteArrayint32_t *x190 = x4703;
int32_t x191 = x190->length;
int32_t  x189 = 0;
while (x189 < x191) { //flatMap loop
int32_t x192 = x190->apply(x189);
cppDeliteArrayint32_t *x193 = __act2->x4704_buf;
int32_t x194 = x192;
if (true) {
int32_t x4673 = __act2->x4704_size;
int32_t x4674 = x193->length;
int32_t x4675 = x4674 - 1;
bool x4676 = x4673 > x4675;
if (x4676) {
bool x4677 = x4674 < 16;
int32_t  x4681;
if (x4677) {
x4681 = 16;
} else {
int32_t x4678 = x4674 * 2;
bool x4679 = x4678 < 0;
int32_t  x4680;
if (x4679) {
x4680 = 2147483647;
} else {
x4680 = x4678;
}
x4681 = x4680;
}
assert(x4681 < (size_t)-1);
cppDeliteArrayint32_t *x4682 = new (resourceInfo) cppDeliteArrayint32_t(x4681, resourceInfo);
if((x193->data==x4682->data) && (0<0))
std::copy_backward(x193->data+0,x193->data+0+x4674,x4682->data+0+x4674);
else {
for (size_t s=0, d=0; s<0+x4674; s++, d++){
x4682->update(d, x193->apply(s));
}
}
x4682->update(x4673, x194);
__act2->x4704_buf = x4682;
} else {
x193->update(x4673, x194);
}
__act2->x4704_size = __act2->x4704_size + 1;
}
__act2->x4704_conditionals = __act2->x4704_conditionals + 1;
x189 = x189 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x4704 *__act,int32_t x187) {
cppDeliteArrayint32_t *x4703 = x4666->apply(x187);
cppDeliteArrayint32_t *x190 = x4703;
int32_t x191 = x190->length;
int32_t  x189 = 0;
while (x189 < x191) { //flatMap loop
int32_t x192 = x190->apply(x189);
cppDeliteArrayint32_t *x193 = __act->x4704_buf;
int32_t x194 = x192;
if (true) {
int32_t x4673 = __act->x4704_size;
int32_t x4674 = x193->length;
int32_t x4675 = x4674 - 1;
bool x4676 = x4673 > x4675;
if (x4676) {
bool x4677 = x4674 < 16;
int32_t  x4681;
if (x4677) {
x4681 = 16;
} else {
int32_t x4678 = x4674 * 2;
bool x4679 = x4678 < 0;
int32_t  x4680;
if (x4679) {
x4680 = 2147483647;
} else {
x4680 = x4678;
}
x4681 = x4680;
}
assert(x4681 < (size_t)-1);
cppDeliteArrayint32_t *x4682 = new (resourceInfo) cppDeliteArrayint32_t(x4681, resourceInfo);
if((x193->data==x4682->data) && (0<0))
std::copy_backward(x193->data+0,x193->data+0+x4674,x4682->data+0+x4674);
else {
for (size_t s=0, d=0; s<0+x4674; s++, d++){
x4682->update(d, x193->apply(s));
}
}
x4682->update(x4673, x194);
__act->x4704_buf = x4682;
} else {
x193->update(x4673, x194);
}
__act->x4704_size = __act->x4704_size + 1;
}
__act->x4704_conditionals = __act->x4704_conditionals + 1;
x189 = x189 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x4704 *__act,activation_x4704 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4704 *__act,activation_x4704 *lhs) {
__act->x4704_offset = lhs->x4704_offset+lhs->x4704_size;
__act->x4704_conditionals = __act->x4704_conditionals+lhs->x4704_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4704 *__act) {
if (__act->x4704_offset > 0) {
int32_t x195 = __act->x4704_offset + __act->x4704_size;
cppDeliteArrayint32_t *x193 = __act->x4704_buf;
assert(x195 < (size_t)-1);
cppDeliteArrayint32_t *x4699 = new (resourceInfo) cppDeliteArrayint32_t(x195);
__act->x4704_data_set(resourceInfo,x4699,__act->x4704_conditionals);
} else {
__act->x4704_data_set(resourceInfo,__act->x4704_buf,__act->x4704_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4704 *__act) {
if (__act->x4704_data != __act->x4704_buf) {
int32_t x195 = __act->x4704_size;
cppDeliteArrayint32_t *x198 = __act->x4704_buf;
cppDeliteArrayint32_t *x193 = __act->x4704_data;
int32_t x196 = 0;
int32_t x197 = __act->x4704_offset;
if((x198->data==x193->data) && (x196<x197))
std::copy_backward(x198->data+x196,x198->data+x196+x195,x193->data+x197+x195);
else {
for (size_t s=x196, d=x197; s<x196+x195; s++, d++){
x193->update(d, x198->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x4704 *__act) {
cppDeliteArrayint32_t * x193 = __act->x4704_data;
int32_t x195 = __act->x4704_conditionals;
int32_t x4691 = x193->length;
bool x4692 = x4691 > x195;
if (x4692) {
assert(x195 < (size_t)-1);
cppDeliteArrayint32_t *x4693 = new (resourceInfo) cppDeliteArrayint32_t(x195);
if((x193->data==x4693->data) && (0<0))
std::copy_backward(x193->data+0,x193->data+0+x195,x4693->data+0+x195);
else {
for (size_t s=0, d=0; s<0+x195; s++, d++){
x4693->update(d, x193->apply(s));
}
}
x193 = x4693;
} else {
}
__act->x4704 = x193;
}

activation_x4704 *initAct(resourceInfo_t *resourceInfo) {
activation_x4704 * act = new activation_x4704;
return act;
}

activation_x4704 *allocVal;
MultiLoopSync<activation_x4704*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4704_class *closure = (x4704_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4704_class *x4704_closure = new x4704_class(x7,x4666);
x4704_closure->loopStart = 0;
x4704_closure->loopSize = x7;
activation_x4704 * alloc = x4704_closure->alloc(resourceInfo);
activation_x4704 * x4704 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4704 = x4704_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4704*> * sync = new MultiLoopSync<activation_x4704*>(x4704_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4704_closure->allocVal = alloc;
x4704_closure->syncVal = sync;
submitWork(r->threadId, x4704_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4704_closure)));
i = i+1;
}
x4704 = x4704_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4704;
}

/**********/

