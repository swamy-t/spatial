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
maxjLmem * xHx2474 = kernel_x2474(resourceInfo,xHx1);
maxjLmem * xHx2475 = kernel_x2475(resourceInfo,xHx1);
int32_t xHx97 = kernel_x97(resourceInfo);
maxjLmem * xHx2476 = kernel_x2476(resourceInfo,xHx97);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
int32_t xHx50 = kernel_x50(resourceInfo);
activation_x2513x2871* xop_x2513x2871 = kernel_x2513x2871(resourceInfo,xHx2,xHx50);
cppDeliteArrayint32_t * xHx2513 = xop_x2513x2871->x2513;
cppDeliteArrayint32_t * xHx2871 = xop_x2513x2871->x2871;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2513x2871): Cannot generate
kernel_x2514(resourceInfo,xHx2474,xHx2513);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2514): Cannot generate
kernel_x2872(resourceInfo,xHx2475,xHx2871);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2872): Cannot generate
int32_t xHx102 = kernel_x102(resourceInfo);
int32_t xHx113 = kernel_x113(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x113): Cannot generate
int32_t xHx116 = kernel_x116(resourceInfo);
int32_t xHx127 = kernel_x127(resourceInfo);
bool xHx167 = kernel_x167(resourceInfo);
int32_t xHx189 = kernel_x189(resourceInfo);
//writeGetter(x167, x167, x2609, false) - primitive
// MaxJ writeFunctionCall(x2609) {
// Inputs(x2609) = List((x189,ConstFixPt,scala_int_to_fixpt), (x102,ConstFixPt,apply), (x1,ConstFixPt,scala_int_to_fixpt), (x113,ConstFixPt,$colon$eq), (x2474,Offchip_new,apply), (x116,ConstFixPt,$colon$eq), (x127,ConstFixPt,scala_int_to_fixpt), (x167,ConstBit,$colon$eq), (x2476,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = {&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x2609(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x2609) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x2609): Cannot generate
int32_t xHx180 = kernel_x180(resourceInfo,xHx97);
// MaxJExecutableGenerator::makeNestedFunction(Free_x180): Cannot generate
cppDeliteArrayint32_t * xHx2610 = kernel_x2610(resourceInfo,xHx180);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2610): Cannot generate
kernel_x2611(resourceInfo,xHx2476,xHx2610);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2611): Cannot generate
kernel_x2612(resourceInfo);
int32_t xHx183 = kernel_x183(resourceInfo,xHx50);
int32_t xHx186 = kernel_x186(resourceInfo,xHx127);
// MaxJExecutableGenerator::makeNestedFunction(Free_x186): Cannot generate
int32_t xHx190 = kernel_x190(resourceInfo,xHx189);
activation_x2877* xop_x2877 = kernel_x2877(resourceInfo,xHx183,xHx116,xHx50,xHx189,xHx190,xHx186);
cppDeliteArraycppDeliteArrayint32_t * xHx2877 = xop_x2877->x2877;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2877): Cannot generate
activation_x2879* xop_x2879 = kernel_x2879(resourceInfo,xHx183,xHx2877);
cppDeliteArrayint32_t * xHx2879 = xop_x2879->x2879;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2879): Cannot generate
int32_t xHx2880 = kernel_x2880(resourceInfo,xHx2879);
int32_t xHx2881 = kernel_x2881(resourceInfo,xHx2880);
kernel_x2886(resourceInfo,xHx102,xHx2881,xHx116,xHx2879);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2886): Cannot generate
kernel_x2887(resourceInfo);
kernel_x2888(resourceInfo);
int32_t xHx2809 = kernel_x2809(resourceInfo,xHx2610);
int32_t xHx2810 = kernel_x2810(resourceInfo,xHx2809);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2810): Cannot generate
kernel_x2889(resourceInfo,xHx102,xHx2810,xHx116,xHx2610);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2889): Cannot generate
kernel_x2890(resourceInfo);
activation_x2896* xop_x2896 = kernel_x2896(resourceInfo,xHx2880,xHx2610,xHx2879);
cppDeliteArraybool * xHx2896 = xop_x2896->x2896;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2896): Cannot generate
int32_t xHx2897 = kernel_x2897(resourceInfo,xHx2896);
bool xHx502 = kernel_x502(resourceInfo);
activation_x2900* xop_x2900 = kernel_x2900(resourceInfo,xHx2897,xHx502,xHx2896);
bool xHx2900 = xop_x2900->x2900;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2900): Cannot generate
string xHx2901 = kernel_x2901(resourceInfo,xHx2900);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2901): Cannot generate
string xHx2902 = kernel_x2902(resourceInfo,xHx2901);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2902): Cannot generate
kernel_x2903(resourceInfo,xHx2902);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2903): Cannot generate
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
