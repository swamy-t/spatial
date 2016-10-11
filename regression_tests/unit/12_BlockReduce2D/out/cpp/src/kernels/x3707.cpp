//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x3707 * kernel_x3707(resourceInfo_t *resourceInfo,int32_t  x314, int32_t  x206, int32_t  x312, int32_t  x451, int32_t  x405, int32_t  x197) {
class x3707_class{
public:
int32_t x314;
int32_t x206;
int32_t x312;
int32_t x451;
int32_t x405;
int32_t x197;

x3707_class(int32_t  _x314,int32_t  _x206,int32_t  _x312,int32_t  _x451,int32_t  _x405,int32_t  _x197) {
x314 = _x314;
x206 = _x206;
x312 = _x312;
x451 = _x451;
x405 = _x405;
x197 = _x197;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x314;
}

int64_t loopStart;
int64_t loopSize;
activation_x3707 *alloc(resourceInfo_t *resourceInfo) {
activation_x3707 * __act = new activation_x3707();;
int32_t x703 = (int32_t)(loopSize);
assert(x703 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x3671 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x703);
__act->x3707_data = x3671;
return __act;
}

activation_x3707 *main_par(resourceInfo_t *resourceInfo,activation_x3707 *__act,MultiLoopSync<activation_x3707*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x3707 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x3707 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x3707 *main_seq(resourceInfo_t *resourceInfo,activation_x3707 *__act) {
activation_x3707 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x3707 *processRange(resourceInfo_t *resourceInfo,activation_x3707 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x3707 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x3707 *init(resourceInfo_t *resourceInfo,activation_x3707 *__act,int32_t x497,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x497);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x3707 *__act,int32_t x497) {
int32_t  x498 = (int32_t) (x497);
int32_t  x505 = x498 * x206;
int32_t  x506 = x505 * x312;
int32_t  x660 = x314;
assert(x660 < (size_t)-1);
cppDeliteArrayint32_t *x3634 = new (resourceInfo) cppDeliteArrayint32_t(x660, resourceInfo);
cppDeliteArrayint32_t * x3670_data = x3634;
int32_t  x3670_size = 0;
int32_t  x3670_conditionals = 0;
int32_t  x499 = 0;
while (x499 < x314) {  // begin fat loop x3670
int32_t  x500 = (int32_t) (x499);
int32_t  x507 = x506 + x500;
int32_t  x559 = x405;
assert(x559 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x3554 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x559, resourceInfo);
cppDeliteArraycppDeliteArrayint32_t * x3590_data = x3554;
int32_t  x3590_size = 0;
int32_t  x3590_conditionals = 0;
int32_t  x501 = 0;
while (x501 < x405) {  // begin fat loop x3590
int32_t  x502 = (int32_t) (x501);
int32_t  x508 = x502 * x206;
int32_t  x509 = x508 * x312;
int32_t  x510 = x509 * x206;
int32_t  x511 = x507 + x510;
int32_t  x516 = x451;
assert(x516 < (size_t)-1);
cppDeliteArrayint32_t *x3517 = new (resourceInfo) cppDeliteArrayint32_t(x516, resourceInfo);
cppDeliteArrayint32_t * x3553_data = x3517;
int32_t  x3553_size = 0;
int32_t  x3553_conditionals = 0;
int32_t  x503 = 0;
while (x503 < x451) {  // begin fat loop x3553
int32_t  x504 = (int32_t) (x503);
int32_t  x512 = x504 * x206;
int32_t  x513 = x511 + x512;
int32_t x515 = x513;
cppDeliteArrayint32_t *x514 = x3553_data;
x514->update(x503, x515);
x503 = x503 + 1;
} // end fat loop x3553
cppDeliteArrayint32_t *x514 = x3553_data;
cppDeliteArrayint32_t *x3553 = x514;
cppDeliteArrayint32_t *x558 = x3553;
cppDeliteArraycppDeliteArrayint32_t *x557 = x3590_data;
x557->update(x501, x558);
x501 = x501 + 1;
} // end fat loop x3590
cppDeliteArraycppDeliteArrayint32_t *x557 = x3590_data;
cppDeliteArraycppDeliteArrayint32_t *x3590 = x557;
int32_t  x608 = 0;
assert(x608 < (size_t)-1);
cppDeliteArrayint32_t *x3591 = new (resourceInfo) cppDeliteArrayint32_t(x608, resourceInfo);
cppDeliteArrayint32_t * x3628_buf = x3591;
int32_t  x3628_size = 0;
int32_t  x3628_conditionals = 0;
int32_t  x600 = 0;
while (x600 < x405) {  // begin fat loop x3628
cppDeliteArrayint32_t *x3627 = x3590->apply(x600);
cppDeliteArrayint32_t *x603 = x3627;
int32_t x604 = x603->length;
int32_t  x602 = 0;
while (x602 < x604) { //flatMap loop
int32_t x605 = x603->apply(x602);
cppDeliteArrayint32_t *x606 = x3628_buf;
int32_t x607 = x605;
if (true) {
int32_t x3597 = x3628_size;
int32_t x3598 = x606->length;
int32_t x3599 = x3598 - 1;
bool x3600 = x3597 > x3599;
if (x3600) {
bool x3601 = x3598 < 16;
int32_t  x3605;
if (x3601) {
x3605 = 16;
} else {
int32_t x3602 = x3598 * 2;
bool x3603 = x3602 < 0;
int32_t  x3604;
if (x3603) {
x3604 = 2147483647;
} else {
x3604 = x3602;
}
x3605 = x3604;
}
assert(x3605 < (size_t)-1);
cppDeliteArrayint32_t *x3606 = new (resourceInfo) cppDeliteArrayint32_t(x3605, resourceInfo);
if((x606->data==x3606->data) && (0<0))
std::copy_backward(x606->data+0,x606->data+0+x3598,x3606->data+0+x3598);
else {
for (size_t s=0, d=0; s<0+x3598; s++, d++){
x3606->update(d, x606->apply(s));
}
}
x3606->update(x3597, x607);
x3628_buf = x3606;
} else {
x606->update(x3597, x607);
}
x3628_size = x3628_size + 1;
}
x3628_conditionals = x3628_conditionals + 1;
x602 = x602 + 1;
}
x600 = x600 + 1;
} // end fat loop x3628
cppDeliteArrayint32_t * x606 = x3628_buf;
x608 = x3628_conditionals;
int32_t x3615 = x606->length;
bool x3616 = x3615 > x608;
if (x3616) {
assert(x608 < (size_t)-1);
cppDeliteArrayint32_t *x3617 = new (resourceInfo) cppDeliteArrayint32_t(x608, resourceInfo);
if((x606->data==x3617->data) && (0<0))
std::copy_backward(x606->data+0,x606->data+0+x608,x3617->data+0+x608);
else {
for (size_t s=0, d=0; s<0+x608; s++, d++){
x3617->update(d, x606->apply(s));
}
}
x606 = x3617;
} else {
}
cppDeliteArrayint32_t *x3628 = x606;
int32_t x3629 = x3628->length;
int32_t  x3633_zero = x197;
int32_t  x3633 = x3633_zero;
int32_t  x650 = 0;
if (x3629 > 0) { // prerun fat loop x3633
int32_t x3630 = x3628->apply(x650);
x3633 = x3630;
}
x650 = 1;
while (x650 < x3629) {  // begin fat loop x3633
int32_t x3630 = x3628->apply(x650);
int32_t x654 = x3633;
int32_t x655 = x3630;
int32_t  x656 = x654 + x655;
x3633 = x656;
x650 = x650 + 1;
} // end fat loop x3633
int32_t x659 = x3633;
cppDeliteArrayint32_t *x658 = x3670_data;
x658->update(x499, x659);
x499 = x499 + 1;
} // end fat loop x3670
cppDeliteArrayint32_t *x658 = x3670_data;
cppDeliteArrayint32_t *x3670 = x658;
cppDeliteArrayint32_t *x702 = x3670;
cppDeliteArraycppDeliteArrayint32_t *x701 = __act->x3707_data;
x701->update(x497, x702);
}

void combine(resourceInfo_t *resourceInfo,activation_x3707 *__act,activation_x3707 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x3707 *__act,activation_x3707 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x3707 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x3707 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x3707 *__act) {
cppDeliteArraycppDeliteArrayint32_t * x701 = __act->x3707_data;
__act->x3707 = x701;
}

activation_x3707 *initAct(resourceInfo_t *resourceInfo) {
activation_x3707 * act = new activation_x3707;
return act;
}

activation_x3707 *allocVal;
MultiLoopSync<activation_x3707*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x3707_class *closure = (x3707_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x3707_class *x3707_closure = new x3707_class(x314,x206,x312,x451,x405,x197);
x3707_closure->loopStart = 0;
x3707_closure->loopSize = x314;
activation_x3707 * alloc = x3707_closure->alloc(resourceInfo);
activation_x3707 * x3707 = NULL;
if (resourceInfo->availableThreads <= 1) {
x3707 = x3707_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x3707*> * sync = new MultiLoopSync<activation_x3707*>(x3707_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x3707_closure->allocVal = alloc;
x3707_closure->syncVal = sync;
submitWork(r->threadId, x3707_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x3707_closure)));
i = i+1;
}
x3707 = x3707_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x3707;
}

/**********/

