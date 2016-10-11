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
maxjLmem * xHx708 = kernel_x708(resourceInfo,xHx3);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx4 = kernel_x4(resourceInfo,xHx3);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
activation_x745* xop_x745 = kernel_x745(resourceInfo,xHx4,xHx2);
cppDeliteArrayint32_t * xHx745 = xop_x745->x745;
// MaxJExecutableGenerator::makeNestedFunction(Free_x745): Cannot generate
kernel_x746(resourceInfo,xHx708,xHx745);
int32_t xHx53 = kernel_x53(resourceInfo);
int32_t  * xHx747 = kernel_x747(resourceInfo,xHx53);
// MaxJExecutableGenerator::makeNestedFunction(Free_x747): Cannot generate
int32_t xHx55 = kernel_x55(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x55): Cannot generate
bool xHx56 = kernel_x56(resourceInfo);
//writeGetter(x56, x56, x752, false) - primitive
// MaxJ writeFunctionCall(x752) {
// Inputs(x752) = List((x747,Argout_new,), (x55,ConstFixPt,scala_int_to_fixpt), (x56,ConstBit,$colon$eq))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = {(uint64_t*) xHx747,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x752(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x752) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x752): Cannot generate
cppDeliteArrayint32_t * xHx753 = kernel_x753(resourceInfo,xHx4);
// MaxJExecutableGenerator::makeNestedFunction(Free_x753): Cannot generate
kernel_x754(resourceInfo,xHx708,xHx753);
// MaxJExecutableGenerator::makeNestedFunction(Free_x754): Cannot generate
kernel_x755(resourceInfo);
int32_t xHx65 = kernel_x65(resourceInfo);
kernel_x760(resourceInfo,xHx53,xHx3,xHx65,xHx745);
kernel_x761(resourceInfo);
kernel_x766(resourceInfo,xHx53,xHx3,xHx65,xHx753);
// MaxJExecutableGenerator::makeNestedFunction(Free_x766): Cannot generate
kernel_x767(resourceInfo);
int32_t xHx768 = kernel_x768(resourceInfo,xHx753);
activation_x809* xop_x809 = kernel_x809(resourceInfo,xHx768,xHx753,xHx745);
cppDeliteArraybool * xHx809 = xop_x809->x809;
// MaxJExecutableGenerator::makeNestedFunction(Free_x809): Cannot generate
int32_t xHx810 = kernel_x810(resourceInfo,xHx809);
bool xHx132 = kernel_x132(resourceInfo);
activation_x815* xop_x815 = kernel_x815(resourceInfo,xHx810,xHx132,xHx809);
bool xHx815 = xop_x815->x815;
// MaxJExecutableGenerator::makeNestedFunction(Free_x815): Cannot generate
string xHx816 = kernel_x816(resourceInfo,xHx815);
// MaxJExecutableGenerator::makeNestedFunction(Free_x816): Cannot generate
string xHx817 = kernel_x817(resourceInfo,xHx816);
// MaxJExecutableGenerator::makeNestedFunction(Free_x817): Cannot generate
kernel_x818(resourceInfo,xHx817);
// MaxJExecutableGenerator::makeNestedFunction(Free_x818): Cannot generate
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
