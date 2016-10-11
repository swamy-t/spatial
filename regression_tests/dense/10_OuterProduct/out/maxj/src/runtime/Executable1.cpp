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
int32_t xHx99 = kernel_x99(resourceInfo);
int32_t  * xHx2667 = kernel_x2667(resourceInfo,xHx99);
int32_t  * xHx2668 = kernel_x2668(resourceInfo,xHx99);
string xHx1 = kernel_x1(resourceInfo,xHx0);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
int32_t xHx5 = kernel_x5(resourceInfo,xHx2);
int32_t xHx97 = kernel_x97(resourceInfo,xHx5);
kernel_x2669(resourceInfo,xHx2667,xHx97);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2669): Cannot generate
string xHx3 = kernel_x3(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3): Cannot generate
int32_t xHx4 = kernel_x4(resourceInfo,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4): Cannot generate
int32_t xHx51 = kernel_x51(resourceInfo,xHx4);
int32_t xHx98 = kernel_x98(resourceInfo,xHx51);
kernel_x2670(resourceInfo,xHx2668,xHx98);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2670): Cannot generate
int32_t xHx2671 = kernel_x2671(resourceInfo,xHx2667);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2671): Cannot generate
maxjLmem * xHx2672 = kernel_x2672(resourceInfo,xHx2671);
int32_t xHx2673 = kernel_x2673(resourceInfo,xHx2668);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2673): Cannot generate
maxjLmem * xHx2674 = kernel_x2674(resourceInfo,xHx2673);
int32_t xHx2675 = kernel_x2675(resourceInfo,xHx2671,xHx2673);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2675): Cannot generate
maxjLmem * xHx2676 = kernel_x2676(resourceInfo,xHx2675);
activation_x2713* xop_x2713 = kernel_x2713(resourceInfo,xHx5);
cppDeliteArrayint32_t * xHx2713 = xop_x2713->x2713;
kernel_x2714(resourceInfo,xHx2672,xHx2713);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2714): Cannot generate
int32_t xHx53 = kernel_x53(resourceInfo);
activation_x2751* xop_x2751 = kernel_x2751(resourceInfo,xHx51,xHx53);
cppDeliteArrayint32_t * xHx2751 = xop_x2751->x2751;
kernel_x2752(resourceInfo,xHx2674,xHx2751);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2752): Cannot generate
int32_t xHx131 = kernel_x131(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x131): Cannot generate
int32_t xHx1879 = kernel_x1879(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1879): Cannot generate
int32_t xHx1881 = kernel_x1881(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1881): Cannot generate
bool xHx197 = kernel_x197(resourceInfo);
//writeGetter(x197, x197, x2823, false) - primitive
// MaxJ writeFunctionCall(x2823) {
// Inputs(x2823) = List((x2667,Argin_new,), (x2668,Argin_new,), (x99,ConstFixPt,), (x1879,ConstFixPt,stage_int_to_fixpt), (x1881,ConstFixPt,apply), (x131,ConstFixPt,$colon$eq), (x2672,Offchip_new,apply), (x53,ConstFixPt,scala_int_to_fixpt), (x2674,Offchip_new,apply), (x2673,Reg_read,regFixToFix), (x197,ConstBit,$colon$eq), (x2676,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx2667, *xHx2668,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x2823(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x2823) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x2823): Cannot generate
int32_t xHx2824 = kernel_x2824(resourceInfo,xHx2675);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2824): Cannot generate
cppDeliteArrayint32_t * xHx2825 = kernel_x2825(resourceInfo,xHx2824);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2825): Cannot generate
kernel_x2826(resourceInfo,xHx2676,xHx2825);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2826): Cannot generate
activation_x2903* xop_x2903 = kernel_x2903(resourceInfo,xHx5,xHx2713,xHx2751,xHx51);
cppDeliteArraycppDeliteArrayint32_t * xHx2903 = xop_x2903->x2903;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2903): Cannot generate
activation_x2941* xop_x2941 = kernel_x2941(resourceInfo,xHx5,xHx2903);
cppDeliteArrayint32_t * xHx2941 = xop_x2941->x2941;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2941): Cannot generate
int32_t xHx2942 = kernel_x2942(resourceInfo,xHx2941);
activation_x2980* xop_x2980 = kernel_x2980(resourceInfo,xHx2942,xHx2941);
cppDeliteArrayint32_t * xHx2980 = xop_x2980->x2980;
activation_x2984* xop_x2984 = kernel_x2984(resourceInfo,xHx2942,xHx99,xHx2980);
int32_t xHx2984 = xop_x2984->x2984;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2984): Cannot generate
string xHx2985 = kernel_x2985(resourceInfo,xHx2984);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2985): Cannot generate
kernel_x2986(resourceInfo,xHx2985);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2986): Cannot generate
int32_t xHx2987 = kernel_x2987(resourceInfo,xHx2825);
activation_x3026* xop_x3026 = kernel_x3026(resourceInfo,xHx2987,xHx2825);
cppDeliteArrayint32_t * xHx3026 = xop_x3026->x3026;
int32_t xHx3027 = kernel_x3027(resourceInfo,xHx3026);
activation_x3032* xop_x3032 = kernel_x3032(resourceInfo,xHx3027,xHx99,xHx3026);
int32_t xHx3032 = xop_x3032->x3032;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3032): Cannot generate
string xHx3033 = kernel_x3033(resourceInfo,xHx3032);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3033): Cannot generate
kernel_x3034(resourceInfo,xHx3033);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3034): Cannot generate
int32_t xHx470 = kernel_x470(resourceInfo,xHx2,xHx4);
// MaxJExecutableGenerator::makeNestedFunction(Free_x470): Cannot generate
kernel_x3040(resourceInfo,xHx99,xHx470,xHx53,xHx2825,xHx2941);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3040): Cannot generate
activation_x3081* xop_x3081 = kernel_x3081(resourceInfo,xHx2987,xHx2825,xHx2941);
cppDeliteArraybool * xHx3081 = xop_x3081->x3081;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3081): Cannot generate
int32_t xHx3082 = kernel_x3082(resourceInfo,xHx3081);
bool xHx528 = kernel_x528(resourceInfo);
activation_x3087* xop_x3087 = kernel_x3087(resourceInfo,xHx3082,xHx528,xHx3081);
bool xHx3087 = xop_x3087->x3087;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3087): Cannot generate
string xHx3088 = kernel_x3088(resourceInfo,xHx3087);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3088): Cannot generate
string xHx3089 = kernel_x3089(resourceInfo,xHx3088);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3089): Cannot generate
kernel_x3090(resourceInfo,xHx3089);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3090): Cannot generate
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
