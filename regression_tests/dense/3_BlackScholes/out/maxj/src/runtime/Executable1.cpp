#include <stdio.h>
#include <stdlib.h>
#include "cppSyncObjects.h"
#include "cpphelperFuncs.h"
#include "multiLoopHeaders.h"
#include <stdint.h>
#include <sys/time.h>
#include <MaxSLiCInterface.h>
max_engine_t *engine = 0;// MaxJ writeMethodHeader();
void DeliteApplication(int numThreads, cppDeliteArraystring * in0){
initializeAll(0, numThreads, 1, 0, 0ULL);
resourceInfo_t resourceInfo_stack = resourceInfos[0];
resourceInfo_t* resourceInfo = &resourceInfo_stack;
// Load max file from disk -> DRAM
max_file_t *maxfile = Top_init();
// Configure the FPGA
engine = max_load(maxfile, "local:*");
int burstSize = max_get_burst_size(maxfile, NULL);
printf("Burst size for architecture: %d bytes\n", burstSize);
cppDeliteArraystring * xHx0 = in0;
int32_t xHx3 = kernel_x3(resourceInfo);
int32_t  * xHx4026 = kernel_x4026(resourceInfo,xHx3);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x4027(resourceInfo,xHx4026,xHx2);
int32_t xHx4028 = kernel_x4028(resourceInfo,xHx4026);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4028): Cannot generate
maxjLmem * xHx4029 = kernel_x4029(resourceInfo,xHx4028);
maxjLmem * xHx4030 = kernel_x4030(resourceInfo,xHx4028);
maxjLmem * xHx4031 = kernel_x4031(resourceInfo,xHx4028);
maxjLmem * xHx4032 = kernel_x4032(resourceInfo,xHx4028);
maxjLmem * xHx4033 = kernel_x4033(resourceInfo,xHx4028);
maxjLmem * xHx4034 = kernel_x4034(resourceInfo,xHx4028);
maxjLmem * xHx4035 = kernel_x4035(resourceInfo,xHx4028);
int32_t xHx14 = kernel_x14(resourceInfo,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x14): Cannot generate
uint32_t xHx16 = kernel_x16(resourceInfo);
activation_x4074* xop_x4074 = kernel_x4074(resourceInfo,xHx14,xHx16);
cppDeliteArrayuint32_t * xHx4074 = xop_x4074->x4074;
// MaxJExecutableGenerator::makeNestedFunction(Free_x4074): Cannot generate
activation_x4113* xop_x4113 = kernel_x4113(resourceInfo,xHx14);
cppDeliteArrayfloat * xHx4113 = xop_x4113->x4113;
activation_x4152* xop_x4152 = kernel_x4152(resourceInfo,xHx14);
cppDeliteArrayfloat * xHx4152 = xop_x4152->x4152;
activation_x4191* xop_x4191 = kernel_x4191(resourceInfo,xHx14);
cppDeliteArrayfloat * xHx4191 = xop_x4191->x4191;
activation_x4230* xop_x4230 = kernel_x4230(resourceInfo,xHx14);
cppDeliteArrayfloat * xHx4230 = xop_x4230->x4230;
activation_x4269* xop_x4269 = kernel_x4269(resourceInfo,xHx14);
cppDeliteArrayfloat * xHx4269 = xop_x4269->x4269;
kernel_x4270(resourceInfo,xHx4029,xHx4074);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4270): Cannot generate
kernel_x4271(resourceInfo,xHx4030,xHx4113);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4271): Cannot generate
kernel_x4272(resourceInfo,xHx4031,xHx4152);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4272): Cannot generate
kernel_x4273(resourceInfo,xHx4032,xHx4191);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4273): Cannot generate
kernel_x4274(resourceInfo,xHx4033,xHx4230);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4274): Cannot generate
kernel_x4275(resourceInfo,xHx4034,xHx4269);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4275): Cannot generate
int32_t xHx2868 = kernel_x2868(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2868): Cannot generate
uint32_t xHx305 = kernel_x305(resourceInfo);
float xHx307 = kernel_x307(resourceInfo);
int32_t xHx316 = kernel_x316(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x316): Cannot generate
int32_t xHx319 = kernel_x319(resourceInfo);
float xHx412 = kernel_x412(resourceInfo);
float xHx423 = kernel_x423(resourceInfo);
float xHx426 = kernel_x426(resourceInfo);
float xHx428 = kernel_x428(resourceInfo);
float xHx429 = kernel_x429(resourceInfo);
float xHx437 = kernel_x437(resourceInfo);
float xHx439 = kernel_x439(resourceInfo);
float xHx441 = kernel_x441(resourceInfo);
float xHx443 = kernel_x443(resourceInfo);
float xHx445 = kernel_x445(resourceInfo);
// MaxJ writeFunctionCall(x4566) {
// Inputs(x4566) = List((x4026,Argin_new,), (x3,ConstFixPt,), (x2868,ConstFixPt,stage_int_to_fixpt), (x305,ConstFixPt,apply), (x307,ConstFltPt,apply), (x316,ConstFixPt,$colon$eq), (x4029,Offchip_new,apply), (x319,ConstFixPt,$colon$eq), (x4030,Offchip_new,apply), (x4031,Offchip_new,apply), (x4032,Offchip_new,apply), (x4033,Offchip_new,apply), (x4034,Offchip_new,apply), (x412,ConstFltPt,$times), (x423,ConstFltPt,$times), (x426,ConstFltPt,$times), (x429,ConstFltPt,$times), (x428,ConstFltPt,), (x437,ConstFltPt,$times), (x445,ConstFltPt,$times), (x443,ConstFltPt,$times), (x439,ConstFltPt,$times), (x441,ConstFltPt,$times), (x4035,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx4026,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x4566(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x4566) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x4566): Cannot generate
int32_t xHx4567 = kernel_x4567(resourceInfo,xHx4028);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4567): Cannot generate
cppDeliteArrayfloat * xHx4568 = kernel_x4568(resourceInfo,xHx4567);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4568): Cannot generate
kernel_x4569(resourceInfo,xHx4035,xHx4568);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4569): Cannot generate
kernel_x4570(resourceInfo);
activation_x4693* xop_x4693 = kernel_x4693(resourceInfo,xHx14,xHx4113,xHx4152,xHx4269,xHx4191,xHx4230,xHx412,xHx423,xHx426,xHx429,xHx428,xHx437,xHx445,xHx443,xHx439,xHx441,xHx307,xHx4074,xHx305);
cppDeliteArrayfloat * xHx4693 = xop_x4693->x4693;
// MaxJExecutableGenerator::makeNestedFunction(Free_x4693): Cannot generate
int32_t xHx656 = kernel_x656(resourceInfo,xHx14);
// MaxJExecutableGenerator::makeNestedFunction(Free_x656): Cannot generate
kernel_x4698(resourceInfo,xHx3,xHx656,xHx319,xHx4693);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4698): Cannot generate
kernel_x4699(resourceInfo);
kernel_x4700(resourceInfo);
int32_t xHx4701 = kernel_x4701(resourceInfo,xHx4568);
int32_t xHx4702 = kernel_x4702(resourceInfo,xHx4701);
kernel_x4707(resourceInfo,xHx3,xHx4702,xHx319,xHx4568);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4707): Cannot generate
kernel_x4708(resourceInfo);
activation_x4753* xop_x4753 = kernel_x4753(resourceInfo,xHx4701,xHx4568,xHx412,xHx4693);
cppDeliteArraybool * xHx4753 = xop_x4753->x4753;
// MaxJExecutableGenerator::makeNestedFunction(Free_x4753): Cannot generate
int32_t xHx4754 = kernel_x4754(resourceInfo,xHx4753);
bool xHx730 = kernel_x730(resourceInfo);
activation_x4759* xop_x4759 = kernel_x4759(resourceInfo,xHx4754,xHx730,xHx4753);
bool xHx4759 = xop_x4759->x4759;
// MaxJExecutableGenerator::makeNestedFunction(Free_x4759): Cannot generate
string xHx4760 = kernel_x4760(resourceInfo,xHx4759);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4760): Cannot generate
string xHx4761 = kernel_x4761(resourceInfo,xHx4760);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4761): Cannot generate
kernel_x4762(resourceInfo,xHx4761);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4762): Cannot generate
cppDeepCopy(resourceInfo);
// MaxJ writeMethodFooter();
max_unload(engine);
clearAll(numThreads, 1, 0, 0);
}

int main(int argc, char *argv[]) {
  cppDeliteArraystring *args = new cppDeliteArraystring(argc-1);
  for (int i=1; i<argc; i++) {
    args->update(i-1, *(new string(argv[i])));
  }
  int numThreads = 1;
  char *env_threads = getenv("DELITE_NUM_THREADS");
  if (env_threads != NULL) {
    numThreads = atoi(env_threads);
  } else {
    fprintf(stderr, "[WARNING]: DELITE_NUM_THREADS undefined, defaulting to 1\n");
  }
  fprintf(stderr, "Executing with %d thread(s)\n", numThreads);
  DeliteApplication(numThreads, args);
  return 0;
}
