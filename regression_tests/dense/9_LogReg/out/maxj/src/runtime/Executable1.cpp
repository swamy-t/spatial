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
int32_t xHx5 = kernel_x5(resourceInfo);
float xHx8 = kernel_x8(resourceInfo);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx6 = kernel_x6(resourceInfo,xHx5);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
int32_t xHx3 = kernel_x3(resourceInfo,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3): Cannot generate
activation_x2448* xop_x2448 = kernel_x2448(resourceInfo,xHx3,xHx8,xHx6);
cppDeliteArraycppDeliteArrayfloat * xHx2448 = xop_x2448->x2448;
activation_x2488* xop_x2488 = kernel_x2488(resourceInfo,xHx3,xHx8);
cppDeliteArrayfloat * xHx2488 = xop_x2488->x2488;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2488): Cannot generate
float xHx147 = kernel_x147(resourceInfo);
activation_x2528* xop_x2528 = kernel_x2528(resourceInfo,xHx6,xHx147);
cppDeliteArrayfloat * xHx2528 = xop_x2528->x2528;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2528): Cannot generate
int32_t xHx244 = kernel_x244(resourceInfo);
int32_t  * xHx2529 = kernel_x2529(resourceInfo,xHx244);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2529): Cannot generate
int32_t xHx2530 = kernel_x2530(resourceInfo,xHx2488);
int32_t xHx2531 = kernel_x2531(resourceInfo,xHx2530);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2531): Cannot generate
kernel_x2532(resourceInfo,xHx2529,xHx2531);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2532): Cannot generate
int32_t xHx2533 = kernel_x2533(resourceInfo,xHx2529);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2533): Cannot generate
int32_t xHx2534 = kernel_x2534(resourceInfo,xHx2533,xHx5);
maxjLmem * xHx2535 = kernel_x2535(resourceInfo,xHx2534);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2535): Cannot generate
maxjLmem * xHx2536 = kernel_x2536(resourceInfo,xHx2533);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2536): Cannot generate
maxjLmem * xHx2537 = kernel_x2537(resourceInfo,xHx5);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2537): Cannot generate
int32_t xHx2538 = kernel_x2538(resourceInfo,xHx2448);
activation_x2576* xop_x2576 = kernel_x2576(resourceInfo,xHx2538,xHx2448);
cppDeliteArrayfloat * xHx2576 = xop_x2576->x2576;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2576): Cannot generate
kernel_x2577(resourceInfo,xHx2535,xHx2576);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2577): Cannot generate
kernel_x2578(resourceInfo,xHx2536,xHx2488);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2578): Cannot generate
kernel_x2579(resourceInfo,xHx2537,xHx2528);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2579): Cannot generate
// MaxJ writeFunctionCall(x2798) {
// Inputs(x2798) = List((x5,ConstFixPt,scala_int_to_fixpt), (x2537,Offchip_new,apply), (x244,ConstFixPt,), (x2529,Argin_new,), (x2535,Offchip_new,apply), (x2536,Offchip_new,apply), (x147,ConstFltPt,random))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx2529,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x2798(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x2798) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x2798): Cannot generate
cppDeliteArrayfloat * xHx2799 = kernel_x2799(resourceInfo,xHx6);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2799): Cannot generate
kernel_x2800(resourceInfo,xHx2537,xHx2799);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2800): Cannot generate
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
