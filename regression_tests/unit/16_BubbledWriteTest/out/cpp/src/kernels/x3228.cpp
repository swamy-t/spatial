//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3228 * kernel_x3228(resourceInfo_t *resourceInfo,int32_t  x240, cppDeliteArraycppDeliteArrayint32_t  *x3226) {
class x3228_class{
public:
int32_t x240;
cppDeliteArraycppDeliteArrayint32_t *x3226;

x3228_class(int32_t  _x240,cppDeliteArraycppDeliteArrayint32_t * _x3226) {
x240 = _x240;
x3226 = _x3226;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x240;
}

int64_t loopStart;
int64_t loopSize;
activation_x3228 *alloc(resourceInfo_t *resourceInfo) {
activation_x3228 * __act = new activation_x3228();;
// __act->x3228 stays null for now
return __act;
}

activation_x3228 *main_par(resourceInfo_t *resourceInfo,activation_x3228 *__act,MultiLoopSync<activation_x3228*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3228 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3228 * act = sync->get(localStart);
//post combine
if (tid != 0) postCombine(resourceInfo,act,sync->getP(tid-1));
int32_t  j = localStart+1;
activation_x3228 * currentAct = act;
while (j < localEnd) {
activation_x3228 * rhsAct = sync->get(j);
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

activation_x3228 *main_seq(resourceInfo_t *resourceInfo,activation_x3228 *__act) {
activation_x3228 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
postProcInit(resourceInfo,act);
postProcess(resourceInfo,act);
finalize(resourceInfo,act);
return act;
}

activation_x3228 *processRange(resourceInfo_t *resourceInfo,activation_x3228 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3228 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3228 *init(resourceInfo_t *resourceInfo,activation_x3228 *__act,int32_t x438,bool isEmpty) {
activation_x3228 * __act2 = new activation_x3228();;
int32_t x446 = 0;
assert(x446 < (size_t)-1);
cppDeliteArrayint32_t *x3111 = new (resourceInfo) cppDeliteArrayint32_t(x446, resourceInfo);
__act2->x3228_buf = x3111;
if (!isEmpty) {
cppDeliteArrayint32_t *x3227 = x3226->apply(x438);
cppDeliteArrayint32_t *x441 = x3227;
int32_t x442 = x441->length;
int32_t  x440 = 0;
while (x440 < x442) { //flatMap loop
int32_t x443 = x441->apply(x440);
cppDeliteArrayint32_t *x444 = __act2->x3228_buf;
int32_t x445 = x443;
if (true) {
int32_t x3117 = __act2->x3228_size;
int32_t x3118 = x444->length;
int32_t x3119 = x3118 - 1;
bool x3120 = x3117 > x3119;
if (x3120) {
bool x3121 = x3118 < 16;
int32_t  x3125;
if (x3121) {
x3125 = 16;
} else {
int32_t x3122 = x3118 * 2;
bool x3123 = x3122 < 0;
int32_t  x3124;
if (x3123) {
x3124 = 2147483647;
} else {
x3124 = x3122;
}
x3125 = x3124;
}
assert(x3125 < (size_t)-1);
cppDeliteArrayint32_t *x3126 = new (resourceInfo) cppDeliteArrayint32_t(x3125, resourceInfo);
if((x444->data==x3126->data) && (0<0))
std::copy_backward(x444->data+0,x444->data+0+x3118,x3126->data+0+x3118);
else {
for (size_t s=0, d=0; s<0+x3118; s++, d++){
x3126->update(d, x444->apply(s));
}
}
x3126->update(x3117, x445);
__act2->x3228_buf = x3126;
} else {
x444->update(x3117, x445);
}
__act2->x3228_size = __act2->x3228_size + 1;
}
__act2->x3228_conditionals = __act2->x3228_conditionals + 1;
x440 = x440 + 1;
}
}
return __act2;
}

void process(resourceInfo_t *resourceInfo,activation_x3228 *__act,int32_t x438) {
cppDeliteArrayint32_t *x3227 = x3226->apply(x438);
cppDeliteArrayint32_t *x441 = x3227;
int32_t x442 = x441->length;
int32_t  x440 = 0;
while (x440 < x442) { //flatMap loop
int32_t x443 = x441->apply(x440);
cppDeliteArrayint32_t *x444 = __act->x3228_buf;
int32_t x445 = x443;
if (true) {
int32_t x3117 = __act->x3228_size;
int32_t x3118 = x444->length;
int32_t x3119 = x3118 - 1;
bool x3120 = x3117 > x3119;
if (x3120) {
bool x3121 = x3118 < 16;
int32_t  x3125;
if (x3121) {
x3125 = 16;
} else {
int32_t x3122 = x3118 * 2;
bool x3123 = x3122 < 0;
int32_t  x3124;
if (x3123) {
x3124 = 2147483647;
} else {
x3124 = x3122;
}
x3125 = x3124;
}
assert(x3125 < (size_t)-1);
cppDeliteArrayint32_t *x3126 = new (resourceInfo) cppDeliteArrayint32_t(x3125, resourceInfo);
if((x444->data==x3126->data) && (0<0))
std::copy_backward(x444->data+0,x444->data+0+x3118,x3126->data+0+x3118);
else {
for (size_t s=0, d=0; s<0+x3118; s++, d++){
x3126->update(d, x444->apply(s));
}
}
x3126->update(x3117, x445);
__act->x3228_buf = x3126;
} else {
x444->update(x3117, x445);
}
__act->x3228_size = __act->x3228_size + 1;
}
__act->x3228_conditionals = __act->x3228_conditionals + 1;
x440 = x440 + 1;
}
}

void combine(resourceInfo_t *resourceInfo,activation_x3228 *__act,activation_x3228 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3228 *__act,activation_x3228 *lhs) {
__act->x3228_offset = lhs->x3228_offset+lhs->x3228_size;
__act->x3228_conditionals = __act->x3228_conditionals+lhs->x3228_conditionals;
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3228 *__act) {
if (__act->x3228_offset > 0) {
int32_t x446 = __act->x3228_offset + __act->x3228_size;
cppDeliteArrayint32_t *x444 = __act->x3228_buf;
assert(x446 < (size_t)-1);
cppDeliteArrayint32_t *x3143 = new (resourceInfo) cppDeliteArrayint32_t(x446);
__act->x3228_data_set(resourceInfo,x3143,__act->x3228_conditionals);
} else {
__act->x3228_data_set(resourceInfo,__act->x3228_buf,__act->x3228_conditionals);
}
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3228 *__act) {
if (__act->x3228_data != __act->x3228_buf) {
int32_t x446 = __act->x3228_size;
cppDeliteArrayint32_t *x449 = __act->x3228_buf;
cppDeliteArrayint32_t *x444 = __act->x3228_data;
int32_t x447 = 0;
int32_t x448 = __act->x3228_offset;
if((x449->data==x444->data) && (x447<x448))
std::copy_backward(x449->data+x447,x449->data+x447+x446,x444->data+x448+x446);
else {
for (size_t s=x447, d=x448; s<x447+x446; s++, d++){
x444->update(d, x449->apply(s));
}
}
}
}

void finalize(resourceInfo_t *resourceInfo,activation_x3228 *__act) {
cppDeliteArrayint32_t * x444 = __act->x3228_data;
int32_t x446 = __act->x3228_conditionals;
int32_t x3135 = x444->length;
bool x3136 = x3135 > x446;
if (x3136) {
assert(x446 < (size_t)-1);
cppDeliteArrayint32_t *x3137 = new (resourceInfo) cppDeliteArrayint32_t(x446);
if((x444->data==x3137->data) && (0<0))
std::copy_backward(x444->data+0,x444->data+0+x446,x3137->data+0+x446);
else {
for (size_t s=0, d=0; s<0+x446; s++, d++){
x3137->update(d, x444->apply(s));
}
}
x444 = x3137;
} else {
}
__act->x3228 = x444;
}

activation_x3228 *initAct(resourceInfo_t *resourceInfo) {
activation_x3228 * act = new activation_x3228;
return act;
}

activation_x3228 *allocVal;
MultiLoopSync<activation_x3228*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3228_class *closure = (x3228_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3228_class *x3228_closure = new x3228_class(x240,x3226);
x3228_closure->loopStart = 0;
x3228_closure->loopSize = x240;
activation_x3228 * alloc = x3228_closure->alloc(resourceInfo);
activation_x3228 * x3228 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3228 = x3228_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3228*> * sync = new MultiLoopSync<activation_x3228*>(x3228_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3228_closure->allocVal = alloc;
x3228_closure->syncVal = sync;
submitWork(r->threadId, x3228_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3228_closure)));
i = i+1;
}
x3228 = x3228_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3228;
}

/**********/

