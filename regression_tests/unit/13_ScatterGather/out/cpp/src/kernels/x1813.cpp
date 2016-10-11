//activation record for fat loop
#include "cpphelperFuncs.h"
activation_x1813 * kernel_x1813(resourceInfo_t *resourceInfo,int32_t  x2, int32_t  x5, int32_t  x9, int32_t  x13, int32_t  x17, int32_t  x21, int32_t  x25, int32_t  x29, int32_t  x33, int32_t  x37, int32_t  x41, int32_t  x45, int32_t  x49, int32_t  x53, int32_t  x57, int32_t  x60, int32_t  x64, int32_t  x63, int32_t  x20, int32_t  x56, int32_t  x52, int32_t  x48, int32_t  x44, int32_t  x40, int32_t  x36, int32_t  x32, int32_t  x28, int32_t  x24, int32_t  x16, int32_t  x12, int32_t  x8) {
class x1813_class{
public:
int32_t x2;
int32_t x5;
int32_t x9;
int32_t x13;
int32_t x17;
int32_t x21;
int32_t x25;
int32_t x29;
int32_t x33;
int32_t x37;
int32_t x41;
int32_t x45;
int32_t x49;
int32_t x53;
int32_t x57;
int32_t x60;
int32_t x64;
int32_t x63;
int32_t x20;
int32_t x56;
int32_t x52;
int32_t x48;
int32_t x44;
int32_t x40;
int32_t x36;
int32_t x32;
int32_t x28;
int32_t x24;
int32_t x16;
int32_t x12;
int32_t x8;

x1813_class(int32_t  _x2,int32_t  _x5,int32_t  _x9,int32_t  _x13,int32_t  _x17,int32_t  _x21,int32_t  _x25,int32_t  _x29,int32_t  _x33,int32_t  _x37,int32_t  _x41,int32_t  _x45,int32_t  _x49,int32_t  _x53,int32_t  _x57,int32_t  _x60,int32_t  _x64,int32_t  _x63,int32_t  _x20,int32_t  _x56,int32_t  _x52,int32_t  _x48,int32_t  _x44,int32_t  _x40,int32_t  _x36,int32_t  _x32,int32_t  _x28,int32_t  _x24,int32_t  _x16,int32_t  _x12,int32_t  _x8) {
x2 = _x2;
x5 = _x5;
x9 = _x9;
x13 = _x13;
x17 = _x17;
x21 = _x21;
x25 = _x25;
x29 = _x29;
x33 = _x33;
x37 = _x37;
x41 = _x41;
x45 = _x45;
x49 = _x49;
x53 = _x53;
x57 = _x57;
x60 = _x60;
x64 = _x64;
x63 = _x63;
x20 = _x20;
x56 = _x56;
x52 = _x52;
x48 = _x48;
x44 = _x44;
x40 = _x40;
x36 = _x36;
x32 = _x32;
x28 = _x28;
x24 = _x24;
x16 = _x16;
x12 = _x12;
x8 = _x8;
}

int64_t size(resourceInfo_t *resourceInfo) {
return x2;
}

int64_t loopStart;
int64_t loopSize;
activation_x1813 *alloc(resourceInfo_t *resourceInfo) {
activation_x1813 * __act = new activation_x1813();;
int32_t x83 = (int32_t)(loopSize);
assert(x83 < (size_t)-1);
cppDeliteArrayint32_t *x1777 = new (resourceInfo) cppDeliteArrayint32_t(x83);
__act->x1813_data = x1777;
return __act;
}

activation_x1813 *main_par(resourceInfo_t *resourceInfo,activation_x1813 *__act,MultiLoopSync<activation_x1813*> *sync) {
int32_t  tid = resourceInfo->groupId;
int32_t  numThreads = resourceInfo->groupSize;
//process local
int32_t  numChunks = sync->numChunks();
int32_t  dIdx = tid;
while (dIdx < numChunks) {
int64_t  start = loopStart + loopSize*dIdx/numChunks;
int64_t  end = loopStart + loopSize*(dIdx+1)/numChunks;
activation_x1813 * act = processRange(resourceInfo,__act,start,end);
sync->set(dIdx,act);
dIdx = sync->getNextChunkIdx();
}
int32_t  localStart = tid*numChunks/numThreads;
int32_t  localEnd = (tid+1)*numChunks/numThreads;
activation_x1813 * act = sync->get(localStart);
sync->awaitBarrier();
if (tid == 0) {
finalize(resourceInfo,act);
}
return act;
}

activation_x1813 *main_seq(resourceInfo_t *resourceInfo,activation_x1813 *__act) {
activation_x1813 * act = processRange(resourceInfo,__act,loopStart,loopStart+loopSize);
finalize(resourceInfo,act);
return act;
}

activation_x1813 *processRange(resourceInfo_t *resourceInfo,activation_x1813 *__act,int64_t start,int64_t end) {
bool  isEmpty = end-start <= 0;
int32_t  idx = (int32_t)(start);
activation_x1813 * __act2 = init(resourceInfo,__act,idx,isEmpty);
idx = idx + 1;
while (idx < end) {
process(resourceInfo,__act2,idx);
idx = idx + 1;
}
return __act2;
}

activation_x1813 *init(resourceInfo_t *resourceInfo,activation_x1813 *__act,int32_t x3,bool isEmpty) {
if (!isEmpty) {
process(resourceInfo,__act,x3);
}
return __act;
}

void process(resourceInfo_t *resourceInfo,activation_x1813 *__act,int32_t x3) {
int32_t  x4 = (int32_t) (x3);
bool  x6 = x4 == x5;
bool  x7 = x6;
int32_t  x80;
if (x7) {
x80 = x8;
} else {
bool  x10 = x4 == x9;
bool  x11 = x10;
int32_t  x79;
if (x11) {
x79 = x12;
} else {
bool  x14 = x4 == x13;
bool  x15 = x14;
int32_t  x78;
if (x15) {
x78 = x16;
} else {
bool  x18 = x4 == x17;
bool  x19 = x18;
int32_t  x77;
if (x19) {
x77 = x20;
} else {
bool  x22 = x4 == x21;
bool  x23 = x22;
int32_t  x76;
if (x23) {
x76 = x24;
} else {
bool  x26 = x4 == x25;
bool  x27 = x26;
int32_t  x75;
if (x27) {
x75 = x28;
} else {
bool  x30 = x4 == x29;
bool  x31 = x30;
int32_t  x74;
if (x31) {
x74 = x32;
} else {
bool  x34 = x4 == x33;
bool  x35 = x34;
int32_t  x73;
if (x35) {
x73 = x36;
} else {
bool  x38 = x4 == x37;
bool  x39 = x38;
int32_t  x72;
if (x39) {
x72 = x40;
} else {
bool  x42 = x4 == x41;
bool  x43 = x42;
int32_t  x71;
if (x43) {
x71 = x44;
} else {
bool  x46 = x4 == x45;
bool  x47 = x46;
int32_t  x70;
if (x47) {
x70 = x48;
} else {
bool  x50 = x4 == x49;
bool  x51 = x50;
int32_t  x69;
if (x51) {
x69 = x52;
} else {
bool  x54 = x4 == x53;
bool  x55 = x54;
int32_t  x68;
if (x55) {
x68 = x56;
} else {
bool  x58 = x4 == x57;
bool  x59 = x58;
int32_t  x67;
if (x59) {
x67 = x20;
} else {
bool  x61 = x4 == x60;
bool  x62 = x61;
int32_t  x66;
if (x62) {
x66 = x63;
} else {
int32_t  x65 = x4 * x64;
x66 = x65;
}
x67 = x66;
}
x68 = x67;
}
x69 = x68;
}
x70 = x69;
}
x71 = x70;
}
x72 = x71;
}
x73 = x72;
}
x74 = x73;
}
x75 = x74;
}
x76 = x75;
}
x77 = x76;
}
x78 = x77;
}
x79 = x78;
}
x80 = x79;
}
int32_t x82 = x80;
cppDeliteArrayint32_t *x81 = __act->x1813_data;
x81->update(x3, x82);
}

void combine(resourceInfo_t *resourceInfo,activation_x1813 *__act,activation_x1813 *rhs) {
}

void postCombine(resourceInfo_t *resourceInfo,activation_x1813 *__act,activation_x1813 *lhs) {
__act->left_act = lhs;
}

void postProcInit(resourceInfo_t *resourceInfo,activation_x1813 *__act) {
}

void postProcess(resourceInfo_t *resourceInfo,activation_x1813 *__act) {
}

void finalize(resourceInfo_t *resourceInfo,activation_x1813 *__act) {
cppDeliteArrayint32_t * x81 = __act->x1813_data;
__act->x1813 = x81;
}

activation_x1813 *initAct(resourceInfo_t *resourceInfo) {
activation_x1813 * act = new activation_x1813;
return act;
}

activation_x1813 *allocVal;
MultiLoopSync<activation_x1813*> *syncVal;
static void* launchFunc(void* arg) {
std::pair<resourceInfo_t*,void*>* in = (std::pair<resourceInfo_t*,void*>*)arg;
x1813_class *closure = (x1813_class *)in->second;
closure->main_par(in->first, closure->allocVal, closure->syncVal);
}
};
x1813_class *x1813_closure = new x1813_class(x2,x5,x9,x13,x17,x21,x25,x29,x33,x37,x41,x45,x49,x53,x57,x60,x64,x63,x20,x56,x52,x48,x44,x40,x36,x32,x28,x24,x16,x12,x8);
x1813_closure->loopStart = 0;
x1813_closure->loopSize = x2;
activation_x1813 * alloc = x1813_closure->alloc(resourceInfo);
activation_x1813 * x1813 = NULL;
if (resourceInfo->availableThreads <= 1) {
x1813 = x1813_closure->main_seq(resourceInfo,alloc);
} else {
MultiLoopSync<activation_x1813*> * sync = new MultiLoopSync<activation_x1813*>(x1813_closure->loopSize,0,resourceInfo);;
int32_t  i = 1;
while (i < sync->numThreads()) {
resourceInfo_t * r = sync->getThreadResource(i);
x1813_closure->allocVal = alloc;
x1813_closure->syncVal = sync;
submitWork(r->threadId, x1813_closure->launchFunc, (void*)(new std::pair<resourceInfo_t*,void*>(r,x1813_closure)));
i = i+1;
}
x1813 = x1813_closure->main_par(sync->getThreadResource(0),alloc,sync);
}

return x1813;
}

/**********/

