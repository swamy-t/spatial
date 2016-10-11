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
int32_t xHx50 = kernel_x50(resourceInfo);
int32_t  * xHx598 = kernel_x598(resourceInfo,xHx50);
int32_t  * xHx599 = kernel_x599(resourceInfo,xHx50);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x600(resourceInfo,xHx598,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x600): Cannot generate
int32_t xHx3 = kernel_x3(resourceInfo);
maxjLmem * xHx601 = kernel_x601(resourceInfo,xHx3);
int32_t xHx4 = kernel_x4(resourceInfo,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4): Cannot generate
activation_x638* xop_x638 = kernel_x638(resourceInfo,xHx4);
cppDeliteArrayint32_t * xHx638 = xop_x638->x638;
// MaxJExecutableGenerator::makeNestedFunction(Free_x638): Cannot generate
kernel_x639(resourceInfo,xHx601,xHx638);
// MaxJExecutableGenerator::makeNestedFunction(Free_x639): Cannot generate
// MaxJ writeFunctionCall(x686) {
// Inputs(x686) = List((x598,Argin_new,), (x50,ConstFixPt,), (x3,ConstFixPt,scala_int_to_fixpt), (x601,Offchip_new,apply), (x599,Argout_new,))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx598,(uint64_t*) xHx599,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x686(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x686) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x686): Cannot generate
int32_t xHx687 = kernel_x687(resourceInfo,xHx599);
// MaxJExecutableGenerator::makeNestedFunction(Free_x687): Cannot generate
kernel_x688(resourceInfo,xHx687);
bool xHx689 = kernel_x689(resourceInfo,xHx687,xHx50);
// MaxJExecutableGenerator::makeNestedFunction(Free_x689): Cannot generate
string xHx690 = kernel_x690(resourceInfo,xHx689);
// MaxJExecutableGenerator::makeNestedFunction(Free_x690): Cannot generate
string xHx691 = kernel_x691(resourceInfo,xHx690);
// MaxJExecutableGenerator::makeNestedFunction(Free_x691): Cannot generate
kernel_x692(resourceInfo,xHx691);
// MaxJExecutableGenerator::makeNestedFunction(Free_x692): Cannot generate
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
