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
int32_t xHx9 = kernel_x9(resourceInfo);
int32_t xHx6 = kernel_x6(resourceInfo,xHx5);
activation_x4279* xop_x4279 = kernel_x4279(resourceInfo,xHx6,xHx9);
cppDeliteArraycppDeliteArrayint32_t * xHx4279 = xop_x4279->x4279;
activation_x4318* xop_x4318 = kernel_x4318(resourceInfo,xHx6,xHx9);
cppDeliteArrayint32_t * xHx4318 = xop_x4318->x4318;
// MaxJExecutableGenerator::makeNestedFunction(Free_x4318): Cannot generate
int32_t xHx286 = kernel_x286(resourceInfo);
int32_t  * xHx4319 = kernel_x4319(resourceInfo,xHx286);
int32_t  * xHx4320 = kernel_x4320(resourceInfo,xHx286);
string xHx1 = kernel_x1(resourceInfo,xHx0);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x4321(resourceInfo,xHx4319,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4321): Cannot generate
string xHx3 = kernel_x3(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3): Cannot generate
int32_t xHx4 = kernel_x4(resourceInfo,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4): Cannot generate
kernel_x4322(resourceInfo,xHx4320,xHx4);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4322): Cannot generate
int32_t xHx996 = kernel_x996(resourceInfo);
maxjLmem * xHx4323 = kernel_x4323(resourceInfo,xHx996);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4323): Cannot generate
maxjLmem * xHx4324 = kernel_x4324(resourceInfo,xHx5);
maxjLmem * xHx4325 = kernel_x4325(resourceInfo,xHx5);
int32_t xHx4326 = kernel_x4326(resourceInfo,xHx4279);
activation_x4364* xop_x4364 = kernel_x4364(resourceInfo,xHx4326,xHx4279);
cppDeliteArrayint32_t * xHx4364 = xop_x4364->x4364;
kernel_x4365(resourceInfo,xHx4323,xHx4364);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4365): Cannot generate
kernel_x4366(resourceInfo,xHx4324,xHx4318);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4366): Cannot generate
int32_t xHx303 = kernel_x303(resourceInfo);
int32_t xHx312 = kernel_x312(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x312): Cannot generate
bool xHx381 = kernel_x381(resourceInfo);
//writeGetter(x381, x381, x4490, false) - primitive
// MaxJ writeFunctionCall(x4490) {
// Inputs(x4490) = List((x996,ConstFixPt,apply), (x286,ConstFixPt,), (x5,ConstFixPt,scala_int_to_fixpt), (x4320,Argin_new,), (x303,ConstFixPt,scala_int_to_fixpt), (x312,ConstFixPt,$colon$eq), (x381,ConstBit,Reduce), (x4323,Offchip_new,apply), (x4324,Offchip_new,apply), (x4319,Argin_new,), (x4325,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx4320, *xHx4319,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x4490(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x4490) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x4490): Cannot generate
cppDeliteArrayint32_t * xHx4491 = kernel_x4491(resourceInfo,xHx6);
kernel_x4492(resourceInfo,xHx4325,xHx4491);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4492): Cannot generate
cppDeliteArrayint32_t * xHx4493 = kernel_x4493(resourceInfo,xHx6);
kernel_x4496(resourceInfo,xHx286,xHx5,xHx303,xHx4493);
activation_x4533* xop_x4533 = kernel_x4533(resourceInfo,xHx6);
cppDeliteArrayint32_t * xHx4533 = xop_x4533->x4533;
kernel_x4792(resourceInfo,xHx286,xHx4,xHx303,xHx4279,xHx4493,xHx4326,xHx4533,xHx4318,xHx6,xHx2,xHx5);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4792): Cannot generate
int32_t xHx4793 = kernel_x4793(resourceInfo,xHx4493);
activation_x4838* xop_x4838 = kernel_x4838(resourceInfo,xHx4793,xHx4493,xHx4491,xHx303);
cppDeliteArraybool * xHx4838 = xop_x4838->x4838;
int32_t xHx4839 = kernel_x4839(resourceInfo,xHx4838);
kernel_x4845(resourceInfo);
int32_t xHx4846 = kernel_x4846(resourceInfo,xHx4491);
int32_t xHx4847 = kernel_x4847(resourceInfo,xHx4846);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4847): Cannot generate
kernel_x4852(resourceInfo,xHx286,xHx4847,xHx303,xHx4491);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4852): Cannot generate
kernel_x4853(resourceInfo);
kernel_x4854(resourceInfo);
int32_t xHx4855 = kernel_x4855(resourceInfo,xHx4793);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4855): Cannot generate
kernel_x4860(resourceInfo,xHx286,xHx4855,xHx303,xHx4493);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4860): Cannot generate
kernel_x4861(resourceInfo);
bool xHx838 = kernel_x838(resourceInfo);
activation_x4844* xop_x4844 = kernel_x4844(resourceInfo,xHx4839,xHx838,xHx4838);
bool xHx4844 = xop_x4844->x4844;
// MaxJExecutableGenerator::makeNestedFunction(Free_x4844): Cannot generate
string xHx4862 = kernel_x4862(resourceInfo,xHx4844);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4862): Cannot generate
string xHx4863 = kernel_x4863(resourceInfo,xHx4862);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4863): Cannot generate
kernel_x4864(resourceInfo,xHx4863);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4864): Cannot generate
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
