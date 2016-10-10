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
int32_t  * xHx720 = kernel_x720(resourceInfo,xHx50);
int32_t  * xHx721 = kernel_x721(resourceInfo,xHx50);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
int32_t xHx3 = kernel_x3(resourceInfo,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3): Cannot generate
int32_t xHx49 = kernel_x49(resourceInfo,xHx3);
kernel_x722(resourceInfo,xHx720,xHx49);
// MaxJExecutableGenerator::makeNestedFunction(Free_x722): Cannot generate
int32_t xHx723 = kernel_x723(resourceInfo,xHx720);
// MaxJExecutableGenerator::makeNestedFunction(Free_x723): Cannot generate
maxjLmem * xHx724 = kernel_x724(resourceInfo,xHx723);
// MaxJExecutableGenerator::makeNestedFunction(Free_x724): Cannot generate
activation_x761* xop_x761 = kernel_x761(resourceInfo,xHx3);
cppDeliteArrayint32_t * xHx761 = xop_x761->x761;
kernel_x762(resourceInfo,xHx724,xHx761);
// MaxJExecutableGenerator::makeNestedFunction(Free_x762): Cannot generate
// MaxJ writeFunctionCall(x821) {
// Inputs(x821) = List((x50,ConstFixPt,), (x720,Argin_new,), (x724,Offchip_new,apply), (x721,Argout_new,))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx720,(uint64_t*) xHx721,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x821(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x821) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x821): Cannot generate
int32_t xHx822 = kernel_x822(resourceInfo,xHx721);
// MaxJExecutableGenerator::makeNestedFunction(Free_x822): Cannot generate
activation_x826* xop_x826 = kernel_x826(resourceInfo,xHx3,xHx50,xHx761);
int32_t xHx826 = xop_x826->x826;
// MaxJExecutableGenerator::makeNestedFunction(Free_x826): Cannot generate
string xHx827 = kernel_x827(resourceInfo,xHx826);
kernel_x828(resourceInfo,xHx827);
// MaxJExecutableGenerator::makeNestedFunction(Free_x828): Cannot generate
string xHx829 = kernel_x829(resourceInfo,xHx822);
kernel_x830(resourceInfo,xHx829);
// MaxJExecutableGenerator::makeNestedFunction(Free_x830): Cannot generate
bool xHx831 = kernel_x831(resourceInfo,xHx822,xHx826);
// MaxJExecutableGenerator::makeNestedFunction(Free_x831): Cannot generate
string xHx832 = kernel_x832(resourceInfo,xHx831);
// MaxJExecutableGenerator::makeNestedFunction(Free_x832): Cannot generate
string xHx833 = kernel_x833(resourceInfo,xHx832);
// MaxJExecutableGenerator::makeNestedFunction(Free_x833): Cannot generate
kernel_x834(resourceInfo,xHx833);
// MaxJExecutableGenerator::makeNestedFunction(Free_x834): Cannot generate
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
