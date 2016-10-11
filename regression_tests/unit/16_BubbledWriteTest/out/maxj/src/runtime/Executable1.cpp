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
// MaxJExecutableGenerator::makeNestedFunction(Free_x0): Cannot generate
int32_t xHx1 = kernel_x1(resourceInfo);
maxjLmem * xHx2772 = kernel_x2772(resourceInfo,xHx1);
maxjLmem * xHx2773 = kernel_x2773(resourceInfo,xHx1);
int32_t xHx97 = kernel_x97(resourceInfo);
maxjLmem * xHx2774 = kernel_x2774(resourceInfo,xHx97);
int32_t xHx246 = kernel_x246(resourceInfo);
maxjLmem * xHx2775 = kernel_x2775(resourceInfo,xHx246);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2775): Cannot generate
maxjLmem * xHx2776 = kernel_x2776(resourceInfo,xHx246);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2776): Cannot generate
maxjLmem * xHx2777 = kernel_x2777(resourceInfo,xHx246);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2777): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
int32_t xHx50 = kernel_x50(resourceInfo);
activation_x2814x3220* xop_x2814x3220 = kernel_x2814x3220(resourceInfo,xHx2,xHx50);
cppDeliteArrayint32_t * xHx2814 = xop_x2814x3220->x2814;
cppDeliteArrayint32_t * xHx3220 = xop_x2814x3220->x3220;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2814x3220): Cannot generate
kernel_x2815(resourceInfo,xHx2772,xHx2814);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2815): Cannot generate
kernel_x3221(resourceInfo,xHx2773,xHx3220);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3221): Cannot generate
int32_t xHx105 = kernel_x105(resourceInfo);
int32_t xHx116 = kernel_x116(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x116): Cannot generate
int32_t xHx119 = kernel_x119(resourceInfo);
int32_t xHx143 = kernel_x143(resourceInfo);
bool xHx180 = kernel_x180(resourceInfo);
//writeGetter(x180, x180, x2958, false) - primitive
// MaxJ writeFunctionCall(x2958) {
// Inputs(x2958) = List((x246,ConstFixPt,scala_int_to_fixpt), (x105,ConstFixPt,apply), (x1,ConstFixPt,scala_int_to_fixpt), (x116,ConstFixPt,$colon$eq), (x2772,Offchip_new,apply), (x119,ConstFixPt,$colon$eq), (x2773,Offchip_new,apply), (x143,ConstFixPt,scala_int_to_fixpt), (x2776,Offchip_new,apply), (x2775,Offchip_new,apply), (x2777,Offchip_new,apply), (x180,ConstBit,$colon$eq), (x2774,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = {&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x2958(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x2958) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x2958): Cannot generate
int32_t xHx237 = kernel_x237(resourceInfo,xHx97);
// MaxJExecutableGenerator::makeNestedFunction(Free_x237): Cannot generate
cppDeliteArrayint32_t * xHx2959 = kernel_x2959(resourceInfo,xHx237);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2959): Cannot generate
kernel_x2960(resourceInfo,xHx2774,xHx2959);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2960): Cannot generate
kernel_x2961(resourceInfo);
int32_t xHx240 = kernel_x240(resourceInfo,xHx50);
int32_t xHx243 = kernel_x243(resourceInfo,xHx143);
// MaxJExecutableGenerator::makeNestedFunction(Free_x243): Cannot generate
int32_t xHx247 = kernel_x247(resourceInfo,xHx246);
activation_x3226* xop_x3226 = kernel_x3226(resourceInfo,xHx240,xHx119,xHx50,xHx246,xHx247,xHx243);
cppDeliteArraycppDeliteArrayint32_t * xHx3226 = xop_x3226->x3226;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3226): Cannot generate
activation_x3228* xop_x3228 = kernel_x3228(resourceInfo,xHx240,xHx3226);
cppDeliteArrayint32_t * xHx3228 = xop_x3228->x3228;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3228): Cannot generate
int32_t xHx3229 = kernel_x3229(resourceInfo,xHx3228);
int32_t xHx3230 = kernel_x3230(resourceInfo,xHx3229);
kernel_x3235(resourceInfo,xHx105,xHx3230,xHx119,xHx3228);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3235): Cannot generate
kernel_x3236(resourceInfo);
kernel_x3237(resourceInfo);
int32_t xHx3158 = kernel_x3158(resourceInfo,xHx2959);
int32_t xHx3159 = kernel_x3159(resourceInfo,xHx3158);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3159): Cannot generate
kernel_x3238(resourceInfo,xHx105,xHx3159,xHx119,xHx2959);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3238): Cannot generate
kernel_x3239(resourceInfo);
activation_x3245* xop_x3245 = kernel_x3245(resourceInfo,xHx3229,xHx2959,xHx3228);
cppDeliteArraybool * xHx3245 = xop_x3245->x3245;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3245): Cannot generate
int32_t xHx3246 = kernel_x3246(resourceInfo,xHx3245);
bool xHx559 = kernel_x559(resourceInfo);
activation_x3249* xop_x3249 = kernel_x3249(resourceInfo,xHx3246,xHx559,xHx3245);
bool xHx3249 = xop_x3249->x3249;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3249): Cannot generate
string xHx3250 = kernel_x3250(resourceInfo,xHx3249);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3250): Cannot generate
string xHx3251 = kernel_x3251(resourceInfo,xHx3250);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3251): Cannot generate
kernel_x3252(resourceInfo,xHx3251);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3252): Cannot generate
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
