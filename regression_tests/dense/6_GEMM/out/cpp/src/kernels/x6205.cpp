//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6205 * kernel_x6205(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x5413, cppDeliteArraycppDeliteArrayint32_t  *x6178, int32_t  x9, int32_t  x189, int32_t  x99) {
class x6205_class{
public:
int32_t x7;
cppDeliteArraycppDeliteArrayint32_t *x5413;
cppDeliteArraycppDeliteArrayint32_t *x6178;
int32_t x9;
int32_t x189;
int32_t x99;

x6205_class(int32_t  _x7,cppDeliteArraycppDeliteArrayint32_t * _x5413,cppDeliteArraycppDeliteArrayint32_t * _x6178,int32_t  _x9,int32_t  _x189,int32_t  _x99) {
x7 = _x7;
x5413 = _x5413;
x6178 = _x6178;
x9 = _x9;
x189 = _x189;
x99 = _x99;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x7;
}

int64_t loopStart;
int64_t loopSize;
activation_x6205 *alloc(resourceInfo_t *resourceInfo) {
activation_x6205 * __act = new activation_x6205();;
int32_t x840 = (int32_t)(loopSize);
assert(x840 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x5959 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x840);
__act->x6205_data = x5959;
return __act;
}

activation_x6205 *main_par(resourceInfo_t *resourceInfo,activation_x6205 *__act,MultiLoopSync<activation_x6205*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6205 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6205 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x6205 *main_seq(resourceInfo_t *resourceInfo,activation_x6205 *__act) {
activation_x6205 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6205 *processRange(resourceInfo_t *resourceInfo,activation_x6205 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6205 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6205 *init(resourceInfo_t *resourceInfo,activation_x6205 *__act,int32_t x686,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x686);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x6205 *__act,int32_t x686) {
int32_t  x687 = (int32_t) (x686);
int32_t  x688 = (int32_t) x687;
cppDeliteArrayint32_t *x5837 = x5413->apply(x688);
int32_t x5838 = x5837->length;
int32_t  x797 = x99;
assert(x797 < (size_t)-1);
cppDeliteArrayint32_t *x5922 = new (resourceInfo) cppDeliteArrayint32_t(x797, resourceInfo);
cppDeliteArrayint32_t * x6202_data = x5922;
int32_t  x6202_size = 0;
int32_t  x6202_conditionals = 0;
int32_t  x690 = 0;
while (x690 < x99) {  // begin fat loop x6202
int32_t  x691 = (int32_t) (x690);
int32_t  x694 = (int32_t) x691;
int32_t  x698 = x9;
assert(x698 < (size_t)-1);
cppDeliteArrayint32_t *x5841 = new (resourceInfo) cppDeliteArrayint32_t(x698, resourceInfo);
cppDeliteArrayint32_t * x6196_data = x5841;
int32_t  x6196_size = 0;
int32_t  x6196_conditionals = 0;
int32_t  x692 = 0;
while (x692 < x9) {  // begin fat loop x6196
cppDeliteArrayint32_t *x6194 = x6178->apply(x692);
int32_t x6195 = x6194->apply(x694);
int32_t x697 = x6195;
cppDeliteArrayint32_t *x696 = x6196_data;
x696->update(x692, x697);
x692 = x692 + 1;
} // end fat loop x6196
cppDeliteArrayint32_t *x696 = x6196_data;
cppDeliteArrayint32_t *x6196 = x696;
int32_t  x746 = x5838;
assert(x746 < (size_t)-1);
cppDeliteArrayint32_t *x5881 = new (resourceInfo) cppDeliteArrayint32_t(x746, resourceInfo);
cppDeliteArrayint32_t * x6199_data = x5881;
int32_t  x6199_size = 0;
int32_t  x6199_conditionals = 0;
int32_t  x740 = 0;
while (x740 < x5838) {  // begin fat loop x6199
int32_t x5878 = x5837->apply(x740);
int32_t x6197 = x6196->apply(x740);
int32_t  x6198 = x5878 * x6197;
int32_t x745 = x6198;
cppDeliteArrayint32_t *x744 = x6199_data;
x744->update(x740, x745);
x740 = x740 + 1;
} // end fat loop x6199
cppDeliteArrayint32_t *x744 = x6199_data;
cppDeliteArrayint32_t *x6199 = x744;
int32_t  x6201_zero = x189;
int32_t  x6201 = x6201_zero;
int32_t  x787 = 0;
if (x5838 > 0) { // prerun fat loop x6201
int32_t x6200 = x6199->apply(x787);
x6201 = x6200;
}
x787 = 1;
while (x787 < x5838) {  // begin fat loop x6201
int32_t x6200 = x6199->apply(x787);
int32_t x791 = x6201;
int32_t x792 = x6200;
int32_t  x793 = x791 + x792;
x6201 = x793;
x787 = x787 + 1;
} // end fat loop x6201
int32_t x796 = x6201;
cppDeliteArrayint32_t *x795 = x6202_data;
x795->update(x690, x796);
x690 = x690 + 1;
} // end fat loop x6202
cppDeliteArrayint32_t *x795 = x6202_data;
cppDeliteArrayint32_t *x6202 = x795;
cppDeliteArrayint32_t *x839 = x6202;
cppDeliteArraycppDeliteArrayint32_t *x838 = __act->x6205_data;
x838->update(x686, x839);
}

void combine(resourceInfo_t *resourceInfo,activation_x6205 *__act,activation_x6205 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6205 *__act,activation_x6205 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6205 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6205 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6205 *__act) {
cppDeliteArraycppDeliteArrayint32_t * x838 = __act->x6205_data;
__act->x6205 = x838;
}

activation_x6205 *initAct(resourceInfo_t *resourceInfo) {
activation_x6205 * act = new activation_x6205;
return act;
}

activation_x6205 *allocVal;
MultiLoopSync<activation_x6205*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6205_class *closure = (x6205_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6205_class *x6205_closure = new x6205_class(x7,x5413,x6178,x9,x189,x99);
x6205_closure->loopStart = 0;
x6205_closure->loopSize = x7;
activation_x6205 * alloc = x6205_closure->alloc(resourceInfo);
activation_x6205 * x6205 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6205 = x6205_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6205*> * sync = new MultiLoopSync<activation_x6205*>(x6205_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6205_closure->allocVal = alloc;
x6205_closure->syncVal = sync;
submitWork(r->threadId, x6205_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6205_closure)));
i = i+1;
}
x6205 = x6205_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6205;
}

/**********/

