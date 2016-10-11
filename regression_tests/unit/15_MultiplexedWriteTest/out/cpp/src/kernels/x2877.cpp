//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x2877 * kernel_x2877(resourceInfo_t *resourceInfo,int32_t  x183, int32_t  x116, int32_t  x50, int32_t  x189, int32_t  x190, int32_t  x186) {
class x2877_class{
public:
int32_t x183;
int32_t x116;
int32_t x50;
int32_t x189;
int32_t x190;
int32_t x186;

x2877_class(int32_t  _x183,int32_t  _x116,int32_t  _x50,int32_t  _x189,int32_t  _x190,int32_t  _x186) {
x183 = _x183;
x116 = _x116;
x50 = _x50;
x189 = _x189;
x190 = _x190;
x186 = _x186;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x183;
}

int64_t loopStart;
int64_t loopSize;
activation_x2877 *alloc(resourceInfo_t *resourceInfo) {
activation_x2877 * __act = new activation_x2877();;
int32_t x340 = (int32_t)(loopSize);
assert(x340 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x2725 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x340);
__act->x2877_data = x2725;
return __act;
}

activation_x2877 *main_par(resourceInfo_t *resourceInfo,activation_x2877 *__act,MultiLoopSync<activation_x2877*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x2877 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x2877 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x2877 *main_seq(resourceInfo_t *resourceInfo,activation_x2877 *__act) {
activation_x2877 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x2877 *processRange(resourceInfo_t *resourceInfo,activation_x2877 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x2877 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x2877 *init(resourceInfo_t *resourceInfo,activation_x2877 *__act,int32_t x184,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x184);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x2877 *__act,int32_t x184) {
int32_t  x185 = (int32_t) (x184);
int32_t  x197 = x185 * x189;
int32_t  x248 = x186;
assert(x248 < (size_t)-1);
cppDeliteArraycppDeliteArrayint32_t *x2650 = new (resourceInfo) cppDeliteArraycppDeliteArrayint32_t(x248, resourceInfo);
cppDeliteArraycppDeliteArrayint32_t * x2686_data = x2650;
int32_t  x2686_size = 0;
int32_t  x2686_conditionals = 0;
int32_t  x187 = 0;
while (x187 < x186) {  // begin fat loop x2686
int32_t  x188 = (int32_t) (x187);
int32_t  x193 = x188 + x116;
int32_t  x199 = x193 * x185;
int32_t  x200 = x199 * x189;
int32_t  x201 = x200 * x50;
int32_t  x205 = x190;
assert(x205 < (size_t)-1);
cppDeliteArrayint32_t *x2613 = new (resourceInfo) cppDeliteArrayint32_t(x205, resourceInfo);
cppDeliteArrayint32_t * x2649_data = x2613;
int32_t  x2649_size = 0;
int32_t  x2649_conditionals = 0;
int32_t  x191 = 0;
while (x191 < x190) {  // begin fat loop x2649
int32_t  x192 = (int32_t) (x191);
int32_t  x194 = x193 * x192;
int32_t  x195 = x194 * x50;
int32_t  x196 = x192 + x195;
int32_t  x198 = x196 + x197;
int32_t  x202 = x198 + x201;
int32_t x204 = x202;
cppDeliteArrayint32_t *x203 = x2649_data;
x203->update(x191, x204);
x191 = x191 + 1;
} // end fat loop x2649
cppDeliteArrayint32_t *x203 = x2649_data;
cppDeliteArrayint32_t *x2649 = x203;
cppDeliteArrayint32_t *x247 = x2649;
cppDeliteArraycppDeliteArrayint32_t *x246 = x2686_data;
x246->update(x187, x247);
x187 = x187 + 1;
} // end fat loop x2686
cppDeliteArraycppDeliteArrayint32_t *x246 = x2686_data;
cppDeliteArraycppDeliteArrayint32_t *x2686 = x246;
int32_t  x297 = 0;
assert(x297 < (size_t)-1);
cppDeliteArrayint32_t *x2687 = new (resourceInfo) cppDeliteArrayint32_t(x297, resourceInfo);
cppDeliteArrayint32_t * x2724_buf = x2687;
int32_t  x2724_size = 0;
int32_t  x2724_conditionals = 0;
int32_t  x289 = 0;
while (x289 < x186) {  // begin fat loop x2724
cppDeliteArrayint32_t *x2723 = x2686->apply(x289);
cppDeliteArrayint32_t *x292 = x2723;
int32_t x293 = x292->length;
int32_t  x291 = 0;
while (x291 < x293) { //flatMap loop
int32_t x294 = x292->apply(x291);
cppDeliteArrayint32_t *x295 = x2724_buf;
int32_t x296 = x294;
if (true) {
int32_t x2693 = x2724_size;
int32_t x2694 = x295->length;
int32_t x2695 = x2694 - 1;
bool x2696 = x2693 > x2695;
if (x2696) {
bool x2697 = x2694 < 16;
int32_t  x2701;
if (x2697) {
x2701 = 16;
} else {
int32_t x2698 = x2694 * 2;
bool x2699 = x2698 < 0;
int32_t  x2700;
if (x2699) {
x2700 = 2147483647;
} else {
x2700 = x2698;
}
x2701 = x2700;
}
assert(x2701 < (size_t)-1);
cppDeliteArrayint32_t *x2702 = new (resourceInfo) cppDeliteArrayint32_t(x2701, resourceInfo);
if((x295->data==x2702->data) && (0<0))
std::copy_backward(x295->data+0,x295->data+0+x2694,x2702->data+0+x2694);
else {
for (size_t s=0, d=0; s<0+x2694; s++, d++){
x2702->update(d, x295->apply(s));
}
}
x2702->update(x2693, x296);
x2724_buf = x2702;
} else {
x295->update(x2693, x296);
}
x2724_size = x2724_size + 1;
}
x2724_conditionals = x2724_conditionals + 1;
x291 = x291 + 1;
}
x289 = x289 + 1;
} // end fat loop x2724
cppDeliteArrayint32_t * x295 = x2724_buf;
x297 = x2724_conditionals;
int32_t x2711 = x295->length;
bool x2712 = x2711 > x297;
if (x2712) {
assert(x297 < (size_t)-1);
cppDeliteArrayint32_t *x2713 = new (resourceInfo) cppDeliteArrayint32_t(x297, resourceInfo);
if((x295->data==x2713->data) && (0<0))
std::copy_backward(x295->data+0,x295->data+0+x297,x2713->data+0+x297);
else {
for (size_t s=0, d=0; s<0+x297; s++, d++){
x2713->update(d, x295->apply(s));
}
}
x295 = x2713;
} else {
}
cppDeliteArrayint32_t *x2724 = x295;
cppDeliteArrayint32_t *x339 = x2724;
cppDeliteArraycppDeliteArrayint32_t *x338 = __act->x2877_data;
x338->update(x184, x339);
}

void combine(resourceInfo_t *resourceInfo,activation_x2877 *__act,activation_x2877 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x2877 *__act,activation_x2877 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x2877 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x2877 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x2877 *__act) {
cppDeliteArraycppDeliteArrayint32_t * x338 = __act->x2877_data;
__act->x2877 = x338;
}

activation_x2877 *initAct(resourceInfo_t *resourceInfo) {
activation_x2877 * act = new activation_x2877;
return act;
}

activation_x2877 *allocVal;
MultiLoopSync<activation_x2877*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x2877_class *closure = (x2877_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x2877_class *x2877_closure = new x2877_class(x183,x116,x50,x189,x190,x186);
x2877_closure->loopStart = 0;
x2877_closure->loopSize = x183;
activation_x2877 * alloc = x2877_closure->alloc(resourceInfo);
activation_x2877 * x2877 = NULL;
if (resourceInfo->availableThreads <= 1) {
x2877 = x2877_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x2877*> * sync = new MultiLoopSync<activation_x2877*>(x2877_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x2877_closure->allocVal = alloc;
x2877_closure->syncVal = sync;
submitWork(r->threadId, x2877_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x2877_closure)));
i = i+1;
}
x2877 = x2877_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x2877;
}

/**********/

