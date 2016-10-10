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
maxjLmem * xHx783 = kernel_x783(resourceInfo,xHx1);
int32_t xHx49 = kernel_x49(resourceInfo);
int32_t  * xHx784 = kernel_x784(resourceInfo,xHx49);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
activation_x821* xop_x821 = kernel_x821(resourceInfo,xHx2);
cppDeliteArrayint32_t * xHx821 = xop_x821->x821;
// MaxJExecutableGenerator::makeNestedFunction(Free_x821): Cannot generate
kernel_x822(resourceInfo,xHx783,xHx821);
// MaxJExecutableGenerator::makeNestedFunction(Free_x822): Cannot generate
int32_t xHx52 = kernel_x52(resourceInfo);
int32_t xHx57 = kernel_x57(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x57): Cannot generate
int32_t xHx60 = kernel_x60(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x60): Cannot generate
bool xHx90 = kernel_x90(resourceInfo);
//writeGetter(x90, x90, x853, false) - primitive
// MaxJ writeFunctionCall(x853) {
// Inputs(x853) = List((x52,ConstFixPt,scala_int_to_fixpt), (x49,ConstFixPt,), (x57,ConstFixPt,$colon$eq), (x783,Offchip_new,apply), (x60,ConstFixPt,$colon$eq), (x90,ConstBit,Reduce), (x784,Argout_new,))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = {(uint64_t*) xHx784,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x853(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x853) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x853): Cannot generate
int32_t xHx854 = kernel_x854(resourceInfo,xHx784);
// MaxJExecutableGenerator::makeNestedFunction(Free_x854): Cannot generate
int32_t xHx99 = kernel_x99(resourceInfo,xHx52);
// MaxJExecutableGenerator::makeNestedFunction(Free_x99): Cannot generate
activation_x891* xop_x891 = kernel_x891(resourceInfo,xHx99);
cppDeliteArrayint32_t * xHx891 = xop_x891->x891;
activation_x895* xop_x895 = kernel_x895(resourceInfo,xHx99,xHx49,xHx891);
int32_t xHx895 = xop_x895->x895;
// MaxJExecutableGenerator::makeNestedFunction(Free_x895): Cannot generate
string xHx896 = kernel_x896(resourceInfo,xHx895);
kernel_x897(resourceInfo,xHx896);
// MaxJExecutableGenerator::makeNestedFunction(Free_x897): Cannot generate
string xHx898 = kernel_x898(resourceInfo,xHx854);
kernel_x899(resourceInfo,xHx898);
// MaxJExecutableGenerator::makeNestedFunction(Free_x899): Cannot generate
bool xHx900 = kernel_x900(resourceInfo,xHx895,xHx854);
// MaxJExecutableGenerator::makeNestedFunction(Free_x900): Cannot generate
string xHx901 = kernel_x901(resourceInfo,xHx900);
// MaxJExecutableGenerator::makeNestedFunction(Free_x901): Cannot generate
string xHx902 = kernel_x902(resourceInfo,xHx901);
// MaxJExecutableGenerator::makeNestedFunction(Free_x902): Cannot generate
kernel_x903(resourceInfo,xHx902);
// MaxJExecutableGenerator::makeNestedFunction(Free_x903): Cannot generate
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
