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
int32_t xHx1106 = kernel_x1106(resourceInfo);
maxjLmem * xHx5337 = kernel_x5337(resourceInfo,xHx1106);
maxjLmem * xHx5338 = kernel_x5338(resourceInfo,xHx1106);
maxjLmem * xHx5339 = kernel_x5339(resourceInfo,xHx1106);
string xHx1 = kernel_x1(resourceInfo,xHx0);
int32_t xHx11 = kernel_x11(resourceInfo);
int32_t xHx189 = kernel_x189(resourceInfo);
string xHx3 = kernel_x3(resourceInfo,xHx0);
string xHx5 = kernel_x5(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
int32_t xHx4 = kernel_x4(resourceInfo,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4): Cannot generate
int32_t xHx6 = kernel_x6(resourceInfo,xHx5);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6): Cannot generate
int32_t xHx7 = kernel_x7(resourceInfo,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x7): Cannot generate
int32_t xHx99 = kernel_x99(resourceInfo,xHx4);
// MaxJExecutableGenerator::makeNestedFunction(Free_x99): Cannot generate
int32_t xHx9 = kernel_x9(resourceInfo,xHx6);
// MaxJExecutableGenerator::makeNestedFunction(Free_x9): Cannot generate
activation_x5489x6186* xop_x5489x6186 = kernel_x5489x6186(resourceInfo,xHx99,xHx11,xHx189);
cppDeliteArrayint32_t * xHx5489 = xop_x5489x6186->x5489;
cppDeliteArrayint32_t * xHx6186 = xop_x5489x6186->x6186;
activation_x5376x6178* xop_x5376x6178 = kernel_x5376x6178(resourceInfo,xHx9,xHx11,xHx5489);
cppDeliteArrayint32_t * xHx5376 = xop_x5376x6178->x5376;
cppDeliteArraycppDeliteArrayint32_t * xHx6178 = xop_x5376x6178->x6178;
// MaxJExecutableGenerator::makeNestedFunction(Free_x5376x6178): Cannot generate
activation_x5413* xop_x5413 = kernel_x5413(resourceInfo,xHx7,xHx5376);
cppDeliteArraycppDeliteArrayint32_t * xHx5413 = xop_x5413->x5413;
// MaxJExecutableGenerator::makeNestedFunction(Free_x5413): Cannot generate
activation_x5451x6187* xop_x5451x6187 = kernel_x5451x6187(resourceInfo,xHx7,xHx6186,xHx5413);
cppDeliteArrayint32_t * xHx5451 = xop_x5451x6187->x5451;
cppDeliteArraycppDeliteArrayint32_t * xHx6187 = xop_x5451x6187->x6187;
// MaxJExecutableGenerator::makeNestedFunction(Free_x5451x6187): Cannot generate
kernel_x5452(resourceInfo,xHx5337,xHx5451);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5452): Cannot generate
activation_x6180* xop_x6180 = kernel_x6180(resourceInfo,xHx9,xHx6178);
cppDeliteArrayint32_t * xHx6180 = xop_x6180->x6180;
kernel_x6181(resourceInfo,xHx5338,xHx6180);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6181): Cannot generate
activation_x6189* xop_x6189 = kernel_x6189(resourceInfo,xHx7,xHx6187);
cppDeliteArrayint32_t * xHx6189 = xop_x6189->x6189;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6189): Cannot generate
kernel_x6190(resourceInfo,xHx5339,xHx6189);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6190): Cannot generate
int32_t xHx423 = kernel_x423(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x423): Cannot generate
int32_t xHx447 = kernel_x447(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x447): Cannot generate
bool xHx674 = kernel_x674(resourceInfo);
//writeGetter(x674, x674, x5834, false) - primitive
// MaxJ writeFunctionCall(x5834) {
// Inputs(x5834) = List((x1106,ConstFixPt,getMem), (x189,ConstFixPt,scala_int_to_fixpt), (x423,ConstFixPt,scala_int_to_fixpt), (x447,ConstFixPt,$colon$eq), (x11,ConstFixPt,scala_int_to_fixpt), (x674,ConstBit,$colon$eq), (x5337,Offchip_new,apply), (x5338,Offchip_new,apply), (x5339,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = {&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x5834(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x5834) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x5834): Cannot generate
int32_t xHx1587 = kernel_x1587(resourceInfo,xHx1106);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1587): Cannot generate
cppDeliteArrayint32_t * xHx5835 = kernel_x5835(resourceInfo,xHx1587);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5835): Cannot generate
kernel_x6191(resourceInfo,xHx5339,xHx5835);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6191): Cannot generate
activation_x6205* xop_x6205 = kernel_x6205(resourceInfo,xHx7,xHx5413,xHx6178,xHx9,xHx189,xHx99);
cppDeliteArraycppDeliteArrayint32_t * xHx6205 = xop_x6205->x6205;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6205): Cannot generate
activation_x6207* xop_x6207 = kernel_x6207(resourceInfo,xHx7,xHx6205);
cppDeliteArrayint32_t * xHx6207 = xop_x6207->x6207;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6207): Cannot generate
int32_t xHx6208 = kernel_x6208(resourceInfo,xHx6207);
activation_x6212* xop_x6212 = kernel_x6212(resourceInfo,xHx6208,xHx6207);
cppDeliteArrayint32_t * xHx6212 = xop_x6212->x6212;
activation_x6214* xop_x6214 = kernel_x6214(resourceInfo,xHx6208,xHx189,xHx6212);
int32_t xHx6214 = xop_x6214->x6214;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6214): Cannot generate
string xHx6215 = kernel_x6215(resourceInfo,xHx6214);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6215): Cannot generate
kernel_x6216(resourceInfo,xHx6215);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6216): Cannot generate
int32_t xHx6217 = kernel_x6217(resourceInfo,xHx5835);
activation_x6220* xop_x6220 = kernel_x6220(resourceInfo,xHx6217,xHx5835);
cppDeliteArrayint32_t * xHx6220 = xop_x6220->x6220;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6220): Cannot generate
int32_t xHx6221 = kernel_x6221(resourceInfo,xHx6220);
activation_x6224* xop_x6224 = kernel_x6224(resourceInfo,xHx6221,xHx189,xHx6220);
int32_t xHx6224 = xop_x6224->x6224;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6224): Cannot generate
string xHx6225 = kernel_x6225(resourceInfo,xHx6224);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6225): Cannot generate
kernel_x6226(resourceInfo,xHx6225);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6226): Cannot generate
activation_x6232* xop_x6232 = kernel_x6232(resourceInfo,xHx6208,xHx5835,xHx6207);
cppDeliteArraybool * xHx6232 = xop_x6232->x6232;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6232): Cannot generate
int32_t xHx6233 = kernel_x6233(resourceInfo,xHx6232);
bool xHx1093 = kernel_x1093(resourceInfo);
activation_x6236* xop_x6236 = kernel_x6236(resourceInfo,xHx6233,xHx1093,xHx6232);
bool xHx6236 = xop_x6236->x6236;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6236): Cannot generate
kernel_x6237(resourceInfo,xHx6236);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6237): Cannot generate
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
