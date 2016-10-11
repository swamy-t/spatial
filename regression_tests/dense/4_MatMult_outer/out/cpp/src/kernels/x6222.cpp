//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x6222 * kernel_x6222(resourceInfo_t *resourceInfo,int32_t  x7, cppDeliteArraycppDeliteArrayint32_t  *x5434, cppDeliteArraycppDeliteArrayint32_t  *x6195, int32_t  x9, int32_t  x189, int32_t  x99) {
class x6222_class{
public:
int32_t x7;
cppDeliteArraycppDeliteArrayint32_t *x5434;
cppDeliteArraycppDeliteArrayint32_t *x6195;
int32_t x9;
int32_t x189;
int32_t x99;

x6222_class(int32_t  _x7,cppDeliteArraycppDeliteArrayint32_t * _x5434,cppDeliteArraycppDeliteArrayint32_t * _x6195,int32_t  _x9,int32_t  _x189,int32_t  _x99) {
x7 = _x7;
x5434 = _x5434;
x6195 = _x6195;
x9 = _x9;
x189 = _x189;
x99 = _x99;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x7;
}

int64_t loopStart;
int64_t loopSize;
activation_x6222 *alloc(resourceInfo_t *resourceInfo) {
activation_x6222 * __act = new activation_x6222();;
int32_t x790 = (int32_t)(loopSize);
assert(x790 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x5958 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x790);
__act->x6222_data = x5958;
return __act;
}

activation_x6222 *main_par(resourceInfo_t *resourceInfo,activation_x6222 *__act,MultiLoopSync<activation_x6222*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x6222 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x6222 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x6222 *main_seq(resourceInfo_t *resourceInfo,activation_x6222 *__act) {
activation_x6222 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x6222 *processRange(resourceInfo_t *resourceInfo,activation_x6222 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x6222 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x6222 *init(resourceInfo_t *resourceInfo,activation_x6222 *__act,int32_t x636,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x636);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x6222 *__act,int32_t x636) {
int32_t  x637 = (int32_t) (x636);
int32_t  x638 = (int32_t) x637;
cppDeliteArrayint32_t *x5836 = x5434->apply(x638);
int32_t x5837 = x5836->length;
int32_t  x747 = x99;
assert(x747 < (size_t)-1);
cppDeliteArrayint32_t *x5921 = new (resourceInfo) cppDeliteArrayint32_t(x747, resourceInfo);
cppDeliteArrayint32_t * x6219_data = x5921;
int32_t  x6219_size = 0;
int32_t  x6219_conditionals = 0;
int32_t  x640 = 0;
while (x640 < x99) {  // begin fat loop x6219
int32_t  x641 = (int32_t) (x640);
int32_t  x644 = (int32_t) x641;
int32_t  x648 = x9;
assert(x648 < (size_t)-1);
cppDeliteArrayint32_t *x5840 = new (resourceInfo) cppDeliteArrayint32_t(x648, resourceInfo);
cppDeliteArrayint32_t * x6213_data = x5840;
int32_t  x6213_size = 0;
int32_t  x6213_conditionals = 0;
int32_t  x642 = 0;
while (x642 < x9) {  // begin fat loop x6213
cppDeliteArrayint32_t *x6211 = x6195->apply(x642);
int32_t x6212 = x6211->apply(x644);
int32_t x647 = x6212;
cppDeliteArrayint32_t *x646 = x6213_data;
x646->update(x642, x647);
x642 = x642 + 1;
} // end fat loop x6213
cppDeliteArrayint32_t *x646 = x6213_data;
cppDeliteArrayint32_t *x6213 = x646;
int32_t  x696 = x5837;
assert(x696 < (size_t)-1);
cppDeliteArrayint32_t *x5880 = new (resourceInfo) cppDeliteArrayint32_t(x696, resourceInfo);
cppDeliteArrayint32_t * x6216_data = x5880;
int32_t  x6216_size = 0;
int32_t  x6216_conditionals = 0;
int32_t  x690 = 0;
while (x690 < x5837) {  // begin fat loop x6216
int32_t x5877 = x5836->apply(x690);
int32_t x6214 = x6213->apply(x690);
int32_t  x6215 = x5877 * x6214;
int32_t x695 = x6215;
cppDeliteArrayint32_t *x694 = x6216_data;
x694->update(x690, x695);
x690 = x690 + 1;
} // end fat loop x6216
cppDeliteArrayint32_t *x694 = x6216_data;
cppDeliteArrayint32_t *x6216 = x694;
int32_t  x6218_zero = x189;
int32_t  x6218 = x6218_zero;
int32_t  x737 = 0;
if (x5837 > 0) { // prerun fat loop x6218
int32_t x6217 = x6216->apply(x737);
x6218 = x6217;
}
x737 = 1;
while (x737 < x5837) {  // begin fat loop x6218
int32_t x6217 = x6216->apply(x737);
int32_t x741 = x6218;
int32_t x742 = x6217;
int32_t  x743 = x741 + x742;
x6218 = x743;
x737 = x737 + 1;
} // end fat loop x6218
int32_t x746 = x6218;
cppDeliteArrayint32_t *x745 = x6219_data;
x745->update(x640, x746);
x640 = x640 + 1;
} // end fat loop x6219
cppDeliteArrayint32_t *x745 = x6219_data;
cppDeliteArrayint32_t *x6219 = x745;
cppDeliteArrayint32_t *x789 = x6219;
cppDeliteArraycppDeliteArrayint32_t *x788 = __act->x6222_data;
x788->update(x636, x789);
}

void combine(resourceInfo_t *resourceInfo,activation_x6222 *__act,activation_x6222 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x6222 *__act,activation_x6222 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x6222 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x6222 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x6222 *__act) {
cppDeliteArraycppDeliteArrayint32_t * x788 = __act->x6222_data;
__act->x6222 = x788;
}

activation_x6222 *initAct(resourceInfo_t *resourceInfo) {
activation_x6222 * act = new activation_x6222;
return act;
}

activation_x6222 *allocVal;
MultiLoopSync<activation_x6222*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x6222_class *closure = (x6222_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x6222_class *x6222_closure = new x6222_class(x7,x5434,x6195,x9,x189,x99);
x6222_closure->loopStart = 0;
x6222_closure->loopSize = x7;
activation_x6222 * alloc = x6222_closure->alloc(resourceInfo);
activation_x6222 * x6222 = NULL;
if (resourceInfo->availableThreads <= 1) {
x6222 = x6222_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x6222*> * sync = new MultiLoopSync<activation_x6222*>(x6222_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x6222_closure->allocVal = alloc;
x6222_closure->syncVal = sync;
submitWork(r->threadId, x6222_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x6222_closure)));
i = i+1;
}
x6222 = x6222_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x6222;
}

/**********/

