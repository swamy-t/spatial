//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x5397 * kernel_x5397(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x4666, cppDeliteArraycppDeliteArrayint32_t  *x5380, int32_t  x9, int32_t  x285, int32_t  x99) {
class x5397_class{
public:
int32_t x7;
cppDeliteArraycppDeliteArrayint32_t *x4666;
cppDeliteArraycppDeliteArrayint32_t *x5380;
int32_t x9;
int32_t x285;
int32_t x99;

x5397_class(int32_t  _x7,cppDeliteArraycppDeliteArrayint32_t * _x4666,cppDeliteArraycppDeliteArrayint32_t * _x5380,int32_t  _x9,int32_t  _x285,int32_t  _x99) {
x7 = _x7;
x4666 = _x4666;
x5380 = _x5380;
x9 = _x9;
x285 = _x285;
x99 = _x99;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x7;
}

int64_t loopStart;
int64_t loopSize;
activation_x5397 *alloc(resourceInfo_t *resourceInfo) {
activation_x5397 * __act = new activation_x5397();;
int32_t x623 = (int32_t)(loopSize);
assert(x623 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x5159 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x623);
__act->x5397_data = x5159;
return __act;
}

activation_x5397 *main_par(resourceInfo_t *resourceInfo,activation_x5397 *__act,MultiLoopSync<activation_x5397*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x5397 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x5397 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x5397 *main_seq(resourceInfo_t *resourceInfo,activation_x5397 *__act) {
activation_x5397 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x5397 *processRange(resourceInfo_t *resourceInfo,activation_x5397 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x5397 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x5397 *init(resourceInfo_t *resourceInfo,activation_x5397 *__act,int32_t x469,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x469);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x5397 *__act,int32_t x469) {
int32_t  x470 = (int32_t) (x469);
int32_t  x471 = (int32_t) x470;
cppDeliteArrayint32_t *x5037 = x4666->apply(x471);
int32_t x5038 = x5037->length;
int32_t  x580 = x99;
assert(x580 < (size_t)-1);
cppDeliteArrayint32_t *x5122 = new (resourceInfo) cppDeliteArrayint32_t(x580, resourceInfo);
cppDeliteArrayint32_t * x5394_data = x5122;
int32_t  x5394_size = 0;
int32_t  x5394_conditionals = 0;
int32_t  x473 = 0;
while (x473 < x99) {  // begin fat loop x5394
int32_t  x474 = (int32_t) (x473);
int32_t  x477 = (int32_t) x474;
int32_t  x481 = x9;
assert(x481 < (size_t)-1);
cppDeliteArrayint32_t *x5041 = new (resourceInfo) cppDeliteArrayint32_t(x481, resourceInfo);
cppDeliteArrayint32_t * x5388_data = x5041;
int32_t  x5388_size = 0;
int32_t  x5388_conditionals = 0;
int32_t  x475 = 0;
while (x475 < x9) {  // begin fat loop x5388
cppDeliteArrayint32_t *x5386 = x5380->apply(x475);
int32_t x5387 = x5386->apply(x477);
int32_t x480 = x5387;
cppDeliteArrayint32_t *x479 = x5388_data;
x479->update(x475, x480);
x475 = x475 + 1;
} // end fat loop x5388
cppDeliteArrayint32_t *x479 = x5388_data;
cppDeliteArrayint32_t *x5388 = x479;
int32_t  x529 = x5038;
assert(x529 < (size_t)-1);
cppDeliteArrayint32_t *x5081 = new (resourceInfo) cppDeliteArrayint32_t(x529, resourceInfo);
cppDeliteArrayint32_t * x5391_data = x5081;
int32_t  x5391_size = 0;
int32_t  x5391_conditionals = 0;
int32_t  x523 = 0;
while (x523 < x5038) {  // begin fat loop x5391
int32_t x5078 = x5037->apply(x523);
int32_t x5389 = x5388->apply(x523);
int32_t  x5390 = x5078 * x5389;
int32_t x528 = x5390;
cppDeliteArrayint32_t *x527 = x5391_data;
x527->update(x523, x528);
x523 = x523 + 1;
} // end fat loop x5391
cppDeliteArrayint32_t *x527 = x5391_data;
cppDeliteArrayint32_t *x5391 = x527;
int32_t  x5393_zero = x285;
int32_t  x5393 = x5393_zero;
int32_t  x570 = 0;
if (x5038 > 0) { // prerun fat loop x5393
int32_t x5392 = x5391->apply(x570);
x5393 = x5392;
}
x570 = 1;
while (x570 < x5038) {  // begin fat loop x5393
int32_t x5392 = x5391->apply(x570);
int32_t x574 = x5393;
int32_t x575 = x5392;
int32_t  x576 = x574 + x575;
x5393 = x576;
x570 = x570 + 1;
} // end fat loop x5393
int32_t x579 = x5393;
cppDeliteArrayint32_t *x578 = x5394_data;
x578->update(x473, x579);
x473 = x473 + 1;
} // end fat loop x5394
cppDeliteArrayint32_t *x578 = x5394_data;
cppDeliteArrayint32_t *x5394 = x578;
cppDeliteArrayint32_t *x622 = x5394;
cppDeliteArraycppDeliteArrayint32_t *x621 = __act->x5397_data;
x621->update(x469, x622);
}

void combine(resourceInfo_t *resourceInfo,activation_x5397 *__act,activation_x5397 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x5397 *__act,activation_x5397 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x5397 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x5397 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x5397 *__act) {
cppDeliteArraycppDeliteArrayint32_t * x621 = __act->x5397_data;
__act->x5397 = x621;
}

activation_x5397 *initAct(resourceInfo_t *resourceInfo) {
activation_x5397 * act = new activation_x5397;
return act;
}

activation_x5397 *allocVal;
MultiLoopSync<activation_x5397*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x5397_class *closure = (x5397_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x5397_class *x5397_closure = new x5397_class(x7,x4666,x5380,x9,x285,x99);
x5397_closure->loopStart = 0;
x5397_closure->loopSize = x7;
activation_x5397 * alloc = x5397_closure->alloc(resourceInfo);
activation_x5397 * x5397 = NULL;
if (resourceInfo->availableThreads <= 1) {
x5397 = x5397_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x5397*> * sync = new MultiLoopSync<activation_x5397*>(x5397_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x5397_closure->allocVal = alloc;
x5397_closure->syncVal = sync;
submitWork(r->threadId, x5397_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x5397_closure)));
i = i+1;
}
x5397 = x5397_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x5397;
}

/**********/

