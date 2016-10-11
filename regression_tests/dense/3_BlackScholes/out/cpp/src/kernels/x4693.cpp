//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x4693 * kernel_x4693(resourceInfo_t *resourceInfo,int32_t  x14, cppDeliteArrayfloat  *x4113, cppDeliteArrayfloat  *x4152, cppDeliteArrayfloat  *x4269, cppDeliteArrayfloat  *x4191, cppDeliteArrayfloat  *x4230, float  x412, float  x423, float  x426, float  x429, float  x428, float  x437, float  x445, float  x443, float  x439, float  x441, float  x307, cppDeliteArrayuint32_t  *x4074, uint32_t  x305) {
class x4693_class{
public:
int32_t x14;
cppDeliteArrayfloat *x4113;
cppDeliteArrayfloat *x4152;
cppDeliteArrayfloat *x4269;
cppDeliteArrayfloat *x4191;
cppDeliteArrayfloat *x4230;
float x412;
float x423;
float x426;
float x429;
float x428;
float x437;
float x445;
float x443;
float x439;
float x441;
float x307;
cppDeliteArrayuint32_t *x4074;
uint32_t x305;

x4693_class(int32_t  _x14,cppDeliteArrayfloat * _x4113,cppDeliteArrayfloat * _x4152,cppDeliteArrayfloat * _x4269,cppDeliteArrayfloat * _x4191,cppDeliteArrayfloat * _x4230,float  _x412,float  _x423,float  _x426,float  _x429,float  _x428,float  _x437,float  _x445,float  _x443,float  _x439,float  _x441,float  _x307,cppDeliteArrayuint32_t * _x4074,uint32_t  _x305) {
x14 = _x14;
x4113 = _x4113;
x4152 = _x4152;
x4269 = _x4269;
x4191 = _x4191;
x4230 = _x4230;
x412 = _x412;
x423 = _x423;
x426 = _x426;
x429 = _x429;
x428 = _x428;
x437 = _x437;
x445 = _x445;
x443 = _x443;
x439 = _x439;
x441 = _x441;
x307 = _x307;
x4074 = _x4074;
x305 = _x305;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x14;
}

int64_t loopStart;
int64_t loopSize;
activation_x4693 *alloc(resourceInfo_t *resourceInfo) {
activation_x4693 * __act = new activation_x4693();;
int32_t x614 = (int32_t)(loopSize);
assert(x614 < (size_t)-1);
cppDeliteArrayfloat *x4657 = new (resourceInfo) cppDeliteArrayfloat(x614);
__act->x4693_data = x4657;
return __act;
}

activation_x4693 *main_par(resourceInfo_t *resourceInfo,activation_x4693 *__act,MultiLoopSync<activation_x4693*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x4693 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x4693 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x4693 *main_seq(resourceInfo_t *resourceInfo,activation_x4693 *__act) {
activation_x4693 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x4693 *processRange(resourceInfo_t *resourceInfo,activation_x4693 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x4693 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x4693 *init(resourceInfo_t *resourceInfo,activation_x4693 *__act,int32_t x523,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x523);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x4693 *__act,int32_t x523) {
int32_t  x524 = (int32_t) (x523);
int32_t  x525 = (int32_t) x524;
float x4571 = x4113->apply(x525);
float x4572 = x4152->apply(x525);
float  x4573 = x4571 / x4572;
float  x4574 = log(x4573);
float x4575 = x4269->apply(x525);
float x4576 = x4191->apply(x525);
float x4577 = x4230->apply(x525);
float  x4578 = x4577 * x4577;
float  x4579 = x4578 * x412;
float  x4580 = x4576 + x4579;
float  x4581 = x4580 * x4575;
float  x4582 = x4581 + x4574;
float  x4583 = sqrt(x4575);
float  x4584 = x4577 * x4583;
float  x4585 = x4584 * x4584;
float  x4586 = x4582 / x4585;
float  x4587 = abs(x4586);
float  x4588 = x4587 * x4587;
float  x4589 = x4588 * x423;
float  x4590 = exp(x4589);
float  x4591 = x4590 * x426;
float  x4592 = x4587 * x429;
float  x4593 = x4592 + x428;
float  x4594 = x428 / x4593;
float  x4595 = x4594 * x437;
float  x4596 = x4594 * x4594;
float  x4597 = x4596 * x4594;
float  x4598 = x4597 * x4594;
float  x4599 = x4598 * x4594;
float  x4600 = x4599 * x445;
float  x4601 = x4598 * x443;
float  x4602 = x4596 * x439;
float  x4603 = x4597 * x441;
float  x4604 = x4602 + x4603;
float  x4605 = x4604 + x4601;
float  x4606 = x4605 + x4600;
float  x4607 = x4606 + x4595;
float  x4608 = x4607 * x4591;
float  x4609 = -x4608;
float  x4610 = x4609 + x428;
bool  x4611 = x4586 < x307;
float  x4612 = (x4611) ? x4608 : x4610;
float  x4613 = x4571 * x4612;
float  x4614 = x4586 - x4584;
float  x4615 = abs(x4614);
float  x4616 = x4615 * x4615;
float  x4617 = x4616 * x423;
float  x4618 = exp(x4617);
float  x4619 = x4618 * x426;
float  x4620 = x4615 * x429;
float  x4621 = x4620 + x428;
float  x4622 = x428 / x4621;
float  x4623 = x4622 * x437;
float  x4624 = x4622 * x4622;
float  x4625 = x4624 * x4622;
float  x4626 = x4625 * x4622;
float  x4627 = x4626 * x4622;
float  x4628 = x4627 * x445;
float  x4629 = x4626 * x443;
float  x4630 = x4624 * x439;
float  x4631 = x4625 * x441;
float  x4632 = x4630 + x4631;
float  x4633 = x4632 + x4629;
float  x4634 = x4633 + x4628;
float  x4635 = x4634 + x4623;
float  x4636 = x4635 * x4619;
float  x4637 = -x4636;
float  x4638 = x4637 + x428;
bool  x4639 = x4614 < x307;
float  x4640 = (x4639) ? x4636 : x4638;
float  x4641 = -x4576;
float  x4642 = x4641 * x4575;
float  x4643 = exp(x4642);
float  x4644 = x4572 * x4643;
float  x4645 = x4644 * x4640;
float  x4646 = x4613 - x4645;
float  x4647 = -x4640;
float  x4648 = x4647 + x428;
float  x4649 = x4644 * x4648;
float  x4650 = -x4612;
float  x4651 = x4650 + x428;
float  x4652 = x4571 * x4651;
float  x4653 = x4649 - x4652;
uint32_t x4654 = x4074->apply(x525);
bool  x4655 = x4654 == x305;
float  x4656 = (x4655) ? x4653 : x4646;
float x613 = x4656;
cppDeliteArrayfloat *x612 = __act->x4693_data;
x612->update(x523, x613);
}

void combine(resourceInfo_t *resourceInfo,activation_x4693 *__act,activation_x4693 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x4693 *__act,activation_x4693 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x4693 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x4693 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x4693 *__act) {
cppDeliteArrayfloat * x612 = __act->x4693_data;
__act->x4693 = x612;
}

activation_x4693 *initAct(resourceInfo_t *resourceInfo) {
activation_x4693 * act = new activation_x4693;
return act;
}

activation_x4693 *allocVal;
MultiLoopSync<activation_x4693*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x4693_class *closure = (x4693_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x4693_class *x4693_closure = new x4693_class(x14,x4113,x4152,x4269,x4191,x4230,x412,x423,x426,x429,x428,x437,x445,x443,x439,x441,x307,x4074,x305);
x4693_closure->loopStart = 0;
x4693_closure->loopSize = x14;
activation_x4693 * alloc = x4693_closure->alloc(resourceInfo);
activation_x4693 * x4693 = NULL;
if (resourceInfo->availableThreads <= 1) {
x4693 = x4693_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x4693*> * sync = new MultiLoopSync<activation_x4693*>(x4693_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x4693_closure->allocVal = alloc;
x4693_closure->syncVal = sync;
submitWork(r->threadId, x4693_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x4693_closure)));
i = i+1;
}
x4693 = x4693_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x4693;
}

/**********/

