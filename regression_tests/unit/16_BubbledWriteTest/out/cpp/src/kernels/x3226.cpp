//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3226 * kernel_x3226(resourceInfo_t *resourceInfo,int32_t  x240, int32_t  x119, int32_t  x50, int32_t  x246, int32_t  x247, int32_t  x243) {
class x3226_class{
public:
int32_t x240;
int32_t x119;
int32_t x50;
int32_t x246;
int32_t x247;
int32_t x243;

x3226_class(int32_t  _x240,int32_t  _x119,int32_t  _x50,int32_t  _x246,int32_t  _x247,int32_t  _x243) {
x240 = _x240;
x119 = _x119;
x50 = _x50;
x246 = _x246;
x247 = _x247;
x243 = _x243;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x240;
}

int64_t loopStart;
int64_t loopSize;
activation_x3226 *alloc(resourceInfo_t *resourceInfo) {
activation_x3226 * __act = new activation_x3226();;
int32_t x397 = (int32_t)(loopSize);
assert(x397 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x3074 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x397);
__act->x3226_data = x3074;
return __act;
}

activation_x3226 *main_par(resourceInfo_t *resourceInfo,activation_x3226 *__act,MultiLoopSync<activation_x3226*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3226 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3226 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x3226 *main_seq(resourceInfo_t *resourceInfo,activation_x3226 *__act) {
activation_x3226 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3226 *processRange(resourceInfo_t *resourceInfo,activation_x3226 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3226 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3226 *init(resourceInfo_t *resourceInfo,activation_x3226 *__act,int32_t x241,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x241);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x3226 *__act,int32_t x241) {
int32_t  x242 = (int32_t) (x241);
int32_t  x254 = x242 * x246;
int32_t  x305 = x243;
assert(x305 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x2999 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x305, resourceInfo);
cppDeliteArraycppDeliteArrayint32_t * x3035_data = x2999;
int32_t  x3035_size = 0;
int32_t  x3035_conditionals = 0;
int32_t  x244 = 0;
while (x244 < x243) {  // begin fat loop x3035
int32_t  x245 = (int32_t) (x244);
int32_t  x250 = x245 + x119;
int32_t  x256 = x250 * x242;
int32_t  x257 = x256 * x246;
int32_t  x258 = x257 * x50;
int32_t  x262 = x247;
assert(x262 < (size_t)-1);
cppDeliteArrayint32_t *x2962 = new (resourceInfo) cppDeliteArrayint32_t(x262, resourceInfo);
cppDeliteArrayint32_t * x2998_data = x2962;
int32_t  x2998_size = 0;
int32_t  x2998_conditionals = 0;
int32_t  x248 = 0;
while (x248 < x247) {  // begin fat loop x2998
int32_t  x249 = (int32_t) (x248);
int32_t  x251 = x250 * x249;
int32_t  x252 = x251 * x50;
int32_t  x253 = x249 + x252;
int32_t  x255 = x253 + x254;
int32_t  x259 = x255 + x258;
int32_t x261 = x259;
cppDeliteArrayint32_t *x260 = x2998_data;
x260->update(x248, x261);
x248 = x248 + 1;
} // end fat loop x2998
cppDeliteArrayint32_t *x260 = x2998_data;
cppDeliteArrayint32_t *x2998 = x260;
cppDeliteArrayint32_t *x304 = x2998;
cppDeliteArraycppDeliteArrayint32_t *x303 = x3035_data;
x303->update(x244, x304);
x244 = x244 + 1;
} // end fat loop x3035
cppDeliteArraycppDeliteArrayint32_t *x303 = x3035_data;
cppDeliteArraycppDeliteArrayint32_t *x3035 = x303;
int32_t  x354 = 0;
assert(x354 < (size_t)-1);
cppDeliteArrayint32_t *x3036 = new (resourceInfo) cppDeliteArrayint32_t(x354, resourceInfo);
cppDeliteArrayint32_t * x3073_buf = x3036;
int32_t  x3073_size = 0;
int32_t  x3073_conditionals = 0;
int32_t  x346 = 0;
while (x346 < x243) {  // begin fat loop x3073
cppDeliteArrayint32_t *x3072 = x3035->apply(x346);
cppDeliteArrayint32_t *x349 = x3072;
int32_t x350 = x349->length;
int32_t  x348 = 0;
while (x348 < x350) { //flatMap loop
int32_t x351 = x349->apply(x348);
cppDeliteArrayint32_t *x352 = x3073_buf;
int32_t x353 = x351;
if (true) {
int32_t x3042 = x3073_size;
int32_t x3043 = x352->length;
int32_t x3044 = x3043 - 1;
bool x3045 = x3042 > x3044;
if (x3045) {
bool x3046 = x3043 < 16;
int32_t  x3050;
if (x3046) {
x3050 = 16;
} else {
int32_t x3047 = x3043 * 2;
bool x3048 = x3047 < 0;
int32_t  x3049;
if (x3048) {
x3049 = 2147483647;
} else {
x3049 = x3047;
}
x3050 = x3049;
}
assert(x3050 < (size_t)-1);
cppDeliteArrayint32_t *x3051 = new (resourceInfo) cppDeliteArrayint32_t(x3050, resourceInfo);
if((x352->data==x3051->data) && (0<0))
std::copy_backward(x352->data+0,x352->data+0+x3043,x3051->data+0+x3043);
else {
for (size_t s=0, d=0; s<0+x3043; s++, d++){
x3051->update(d, x352->apply(s));
}
}
x3051->update(x3042, x353);
x3073_buf = x3051;
} else {
x352->update(x3042, x353);
}
x3073_size = x3073_size + 1;
}
x3073_conditionals = x3073_conditionals + 1;
x348 = x348 + 1;
}
x346 = x346 + 1;
} // end fat loop x3073
cppDeliteArrayint32_t * x352 = x3073_buf;
x354 = x3073_conditionals;
int32_t x3060 = x352->length;
bool x3061 = x3060 > x354;
if (x3061) {
assert(x354 < (size_t)-1);
cppDeliteArrayint32_t *x3062 = new (resourceInfo) cppDeliteArrayint32_t(x354, resourceInfo);
if((x352->data==x3062->data) && (0<0))
std::copy_backward(x352->data+0,x352->data+0+x354,x3062->data+0+x354);
else {
for (size_t s=0, d=0; s<0+x354; s++, d++){
x3062->update(d, x352->apply(s));
}
}
x352 = x3062;
} else {
}
cppDeliteArrayint32_t *x3073 = x352;
cppDeliteArrayint32_t *x396 = x3073;
cppDeliteArraycppDeliteArrayint32_t *x395 = __act->x3226_data;
x395->update(x241, x396);
}

void combine(resourceInfo_t *resourceInfo,activation_x3226 *__act,activation_x3226 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3226 *__act,activation_x3226 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3226 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3226 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3226 *__act) {
cppDeliteArraycppDeliteArrayint32_t * x395 = __act->x3226_data;
__act->x3226 = x395;
}

activation_x3226 *initAct(resourceInfo_t *resourceInfo) {
activation_x3226 * act = new activation_x3226;
return act;
}

activation_x3226 *allocVal;
MultiLoopSync<activation_x3226*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3226_class *closure = (x3226_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3226_class *x3226_closure = new x3226_class(x240,x119,x50,x246,x247,x243);
x3226_closure->loopStart = 0;
x3226_closure->loopSize = x240;
activation_x3226 * alloc = x3226_closure->alloc(resourceInfo);
activation_x3226 * x3226 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3226 = x3226_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3226*> * sync = new MultiLoopSync<activation_x3226*>(x3226_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3226_closure->allocVal = alloc;
x3226_closure->syncVal = sync;
submitWork(r->threadId, x3226_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3226_closure)));
i = i+1;
}
x3226 = x3226_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3226;
}

/**********/

