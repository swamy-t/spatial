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
uint32_t xHx5 = kernel_x5(resourceInfo);
uint32_t xHx7 = kernel_x7(resourceInfo);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
int32_t xHx3 = kernel_x3(resourceInfo,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3): Cannot generate
activation_x2631* xop_x2631 = kernel_x2631(resourceInfo,xHx3,xHx5,xHx7);
cppDeliteArrayuint32_t * xHx2631 = xop_x2631->x2631;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2631): Cannot generate
uint32_t xHx54 = kernel_x54(resourceInfo);
activation_x2670* xop_x2670 = kernel_x2670(resourceInfo,xHx3,xHx54);
cppDeliteArrayuint32_t * xHx2670 = xop_x2670->x2670;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2670): Cannot generate
int32_t xHx102 = kernel_x102(resourceInfo);
activation_x2710* xop_x2710 = kernel_x2710(resourceInfo,xHx3,xHx102);
cppDeliteArrayint32_t * xHx2710 = xop_x2710->x2710;
activation_x2750* xop_x2750 = kernel_x2750(resourceInfo,xHx3,xHx102);
cppDeliteArrayint32_t * xHx2750 = xop_x2750->x2750;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2750): Cannot generate
int32_t xHx195 = kernel_x195(resourceInfo);
int32_t  * xHx2751 = kernel_x2751(resourceInfo,xHx195);
int32_t xHx2752 = kernel_x2752(resourceInfo,xHx2631);
int32_t xHx2753 = kernel_x2753(resourceInfo,xHx2752);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2753): Cannot generate
kernel_x2754(resourceInfo,xHx2751,xHx2753);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2754): Cannot generate
int32_t xHx2755 = kernel_x2755(resourceInfo,xHx2751);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2755): Cannot generate
maxjLmem * xHx2756 = kernel_x2756(resourceInfo,xHx2755);
maxjLmem * xHx2757 = kernel_x2757(resourceInfo,xHx2755);
maxjLmem * xHx2758 = kernel_x2758(resourceInfo,xHx2755);
maxjLmem * xHx2759 = kernel_x2759(resourceInfo,xHx2755);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2759): Cannot generate
int32_t  * xHx2760 = kernel_x2760(resourceInfo,xHx195);
kernel_x2761(resourceInfo,xHx2756,xHx2631);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2761): Cannot generate
kernel_x2762(resourceInfo,xHx2757,xHx2670);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2762): Cannot generate
kernel_x2763(resourceInfo,xHx2758,xHx2710);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2763): Cannot generate
kernel_x2764(resourceInfo,xHx2759,xHx2750);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2764): Cannot generate
int32_t xHx1778 = kernel_x1778(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1778): Cannot generate
int32_t xHx216 = kernel_x216(resourceInfo);
uint32_t xHx221 = kernel_x221(resourceInfo);
int32_t xHx229 = kernel_x229(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x229): Cannot generate
uint32_t xHx295 = kernel_x295(resourceInfo);
int32_t xHx300 = kernel_x300(resourceInfo);
uint32_t xHx303 = kernel_x303(resourceInfo);
bool xHx316 = kernel_x316(resourceInfo);
//writeGetter(x316, x316, x2992, false) - primitive
// MaxJ writeFunctionCall(x2992) {
// Inputs(x2992) = List((x195,ConstFixPt,), (x2751,Argin_new,), (x1778,ConstFixPt,stage_int_to_fixpt), (x216,ConstFixPt,Fold), (x221,ConstFixPt,apply), (x229,ConstFixPt,$colon$eq), (x2756,Offchip_new,apply), (x2757,Offchip_new,apply), (x2758,Offchip_new,apply), (x2759,Offchip_new,apply), (x295,ConstFixPt,$less), (x300,ConstFixPt,$less$eq), (x303,ConstFixPt,$less), (x316,ConstBit,Reduce), (x2760,Argout_new,))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx2751,(uint64_t*) xHx2760,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x2992(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x2992) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x2992): Cannot generate
int32_t xHx2993 = kernel_x2993(resourceInfo,xHx2760);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2993): Cannot generate
kernel_x2994(resourceInfo);
activation_x3043* xop_x3043 = kernel_x3043(resourceInfo,xHx3,xHx2631,xHx221,xHx295,xHx2670,xHx303,xHx2710,xHx195,xHx300);
cppDeliteArraybool * xHx3043 = xop_x3043->x3043;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3043): Cannot generate
int32_t xHx402 = kernel_x402(resourceInfo,xHx3);
kernel_x3048(resourceInfo,xHx195,xHx402,xHx216,xHx3043);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3048): Cannot generate
kernel_x3049(resourceInfo);
activation_x3092* xop_x3092 = kernel_x3092(resourceInfo,xHx3,xHx3043,xHx2750,xHx2710,xHx195);
cppDeliteArrayint32_t * xHx3092 = xop_x3092->x3092;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3092): Cannot generate
activation_x3096* xop_x3096 = kernel_x3096(resourceInfo,xHx3,xHx195,xHx3092);
int32_t xHx3096 = xop_x3096->x3096;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3096): Cannot generate
string xHx3097 = kernel_x3097(resourceInfo,xHx3096);
kernel_x3098(resourceInfo,xHx3097);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3098): Cannot generate
string xHx3099 = kernel_x3099(resourceInfo,xHx2993);
kernel_x3100(resourceInfo,xHx3099);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3100): Cannot generate
bool xHx3101 = kernel_x3101(resourceInfo,xHx3096,xHx2993);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3101): Cannot generate
string xHx3102 = kernel_x3102(resourceInfo,xHx3101);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3102): Cannot generate
string xHx3103 = kernel_x3103(resourceInfo,xHx3102);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3103): Cannot generate
kernel_x3104(resourceInfo,xHx3103);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3104): Cannot generate
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
