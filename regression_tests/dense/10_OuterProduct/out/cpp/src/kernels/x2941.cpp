//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2941 * kernel_x2941(resourceInfo_t *resourceInfo,int32_t  x5, cppDeliteArraycppDeliteArrayint32_t  *x2903) {
class x2941_class{
public:
int32_t x5;
cppDeliteArraycppDeliteArrayint32_t *x2903;

x2941_class(int32_t  _x5,cppDeliteArraycppDeliteArrayint32_t * _x2903) {
x5 = _x5;
x2903 = _x2903;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x5;
}

int64_t loopStart;
int64_t loopSize;
activation_x2941 *alloc(resourceInfo_t *resourceInfo) {
activation_x2941 * __act = new activation_x2941();;
// __act->x2941 stays null for now
return __act;
}

activation_x2941 *main_par(resourceInfo_t *resourceInfo,activation_x2941 *__act,MultiLoopSync<activation_x2941*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2941 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2941 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x2941 * currentAct = act;
while (j < localEnd) {
activation_x2941 * rhsAct = sync->get(j);
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

activation_x2941 *main_seq(resourceInfo_t *resourceInfo,activation_x2941 *__act) {
activation_x2941 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x2941 *processRange(resourceInfo_t *resourceInfo,activation_x2941 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2941 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2941 *init(resourceInfo_t *resourceInfo,activation_x2941 *__act,int32_t x306,bool isEmpty) {
activation_x2941 * __act2 = new activation_x2941();;
int32_t x314 = 0;
assert(x314 < (size_t)-1);
cppDeliteArrayint32_t *x2904 = new (resourceInfo) cppDeliteArrayint32_t(x314, resourceInfo);
__act2->x2941_buf = x2904;
if (!isEmpty) {
cppDeliteArrayint32_t *x2940 = x2903->apply(x306);
cppDeliteArrayint32_t *x309 = x2940;
int32_t x310 = x309->length;
int32_t  x308 = 0;
while (x308 < x310) { //flatMap loop
int32_t x311 = x309->apply(x308);
cppDeliteArrayint32_t *x312 = __act2->x2941_buf;
int32_t x313 = x311;
if (true) {
int32_t x2910 = __act2->x2941_size;
int32_t x2911 = x312->length;
int32_t x2912 = x2911 - 1;
bool x2913 = x2910 > x2912;
if (x2913) {
bool x2914 = x2911 < 16;
int32_t  x2918;
if (x2914) {
x2918 = 16;
} else {
int32_t x2915 = x2911 * 2;
bool x2916 = x2915 < 0;
int32_t  x2917;
if (x2916) {
x2917 = 2147483647;
} else {
x2917 = x2915;
}
x2918 = x2917;
}
assert(x2918 < (size_t)-1);
cppDeliteArrayint32_t *x2919 = new (resourceInfo) cppDeliteArrayint32_t(x2918, resourceInfo);
if((x312->data==x2919->data) && (0<0))
std::copy_backward(x312->data+0,x312->data+0+x2911,x2919->data+0+x2911);
else {
for (size_t s=0, d=0; s<0+x2911; s++, d++){
x2919->update(d, x312->apply(s));
}
}
x2919->update(x2910, x313);
__act2->x2941_buf = x2919;
} else {
x312->update(x2910, x313);
}
__act2->x2941_size = __act2->x2941_size + 1;
}
__act2->x2941_conditionals = __act2->x2941_conditionals + 1;
x308 = x308 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x2941 *__act,int32_t x306) {
cppDeliteArrayint32_t *x2940 = x2903->apply(x306);
cppDeliteArrayint32_t *x309 = x2940;
int32_t x310 = x309->length;
int32_t  x308 = 0;
while (x308 < x310) { //flatMap loop
int32_t x311 = x309->apply(x308);
cppDeliteArrayint32_t *x312 = __act->x2941_buf;
int32_t x313 = x311;
if (true) {
int32_t x2910 = __act->x2941_size;
int32_t x2911 = x312->length;
int32_t x2912 = x2911 - 1;
bool x2913 = x2910 > x2912;
if (x2913) {
bool x2914 = x2911 < 16;
int32_t  x2918;
if (x2914) {
x2918 = 16;
} else {
int32_t x2915 = x2911 * 2;
bool x2916 = x2915 < 0;
int32_t  x2917;
if (x2916) {
x2917 = 2147483647;
} else {
x2917 = x2915;
}
x2918 = x2917;
}
assert(x2918 < (size_t)-1);
cppDeliteArrayint32_t *x2919 = new (resourceInfo) cppDeliteArrayint32_t(x2918, resourceInfo);
if((x312->data==x2919->data) && (0<0))
std::copy_backward(x312->data+0,x312->data+0+x2911,x2919->data+0+x2911);
else {
for (size_t s=0, d=0; s<0+x2911; s++, d++){
x2919->update(d, x312->apply(s));
}
}
x2919->update(x2910, x313);
__act->x2941_buf = x2919;
} else {
x312->update(x2910, x313);
}
__act->x2941_size = __act->x2941_size + 1;
}
__act->x2941_conditionals = __act->x2941_conditionals + 1;
x308 = x308 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x2941 *__act,activation_x2941 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2941 *__act,activation_x2941 *lhs) {
__act->x2941_offset = lhs->x2941_offset+lhs->x2941_size;
__act->x2941_conditionals = __act->x2941_conditionals+lhs->x2941_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2941 *__act) {
if (__act->x2941_offset > 0) {
int32_t x314 = __act->x2941_offset + __act->x2941_size;
cppDeliteArrayint32_t *x312 = __act->x2941_buf;
assert(x314 < (size_t)-1);
cppDeliteArrayint32_t *x2936 = new (resourceInfo) cppDeliteArrayint32_t(x314);
__act->x2941_data_set(resourceInfo,x2936,__act->x2941_conditionals);
} else {
__act->x2941_data_set(resourceInfo,__act->x2941_buf,__act->x2941_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2941 *__act) {
if (__act->x2941_data != __act->x2941_buf) {
int32_t x314 = __act->x2941_size;
cppDeliteArrayint32_t *x317 = __act->x2941_buf;
cppDeliteArrayint32_t *x312 = __act->x2941_data;
int32_t x315 = 0;
int32_t x316 = __act->x2941_offset;
if((x317->data==x312->data) && (x315<x316))
std::copy_backward(x317->data+x315,x317->data+x315+x314,x312->data+x316+x314);
else {
for (size_t s=x315, d=x316; s<x315+x314; s++, d++){
x312->update(d, x317->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x2941 *__act) {
cppDeliteArrayint32_t * x312 = __act->x2941_data;
int32_t x314 = __act->x2941_conditionals;
int32_t x2928 = x312->length;
bool x2929 = x2928 > x314;
if (x2929) {
assert(x314 < (size_t)-1);
cppDeliteArrayint32_t *x2930 = new (resourceInfo) cppDeliteArrayint32_t(x314);
if((x312->data==x2930->data) && (0<0))
std::copy_backward(x312->data+0,x312->data+0+x314,x2930->data+0+x314);
else {
for (size_t s=0, d=0; s<0+x314; s++, d++){
x2930->update(d, x312->apply(s));
}
}
x312 = x2930;
} else {
}
__act->x2941 = x312;
}

activation_x2941 *initAct(resourceInfo_t *resourceInfo) {
activation_x2941 * act = new activation_x2941;
return act;
}

activation_x2941 *allocVal;
MultiLoopSync<activation_x2941*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2941_class *closure = (x2941_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2941_class *x2941_closure = new x2941_class(x5,x2903);
x2941_closure->loopStart = 0;
x2941_closure->loopSize = x5;
activation_x2941 * alloc = x2941_closure->alloc(resourceInfo);
activation_x2941 * x2941 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2941 = x2941_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2941*> * sync = new MultiLoopSync<activation_x2941*>(x2941_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2941_closure->allocVal = alloc;
x2941_closure->syncVal = sync;
submitWork(r->threadId, x2941_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2941_closure)));
i = i+1;
}
x2941 = x2941_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2941;
}

/**********/

