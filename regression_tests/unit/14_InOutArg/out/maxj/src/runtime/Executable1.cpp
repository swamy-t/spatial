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
int32_t xHx1 = kernel_x1(resourceInfo);
int32_t  * xHx123 = kernel_x123(resourceInfo,xHx1);
int32_t  * xHx124 = kernel_x124(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x124): Cannot generate
string xHx4 = kernel_x4(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4): Cannot generate
int32_t xHx5 = kernel_x5(resourceInfo,xHx4);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5): Cannot generate
kernel_x125(resourceInfo,xHx123,xHx5);
// MaxJExecutableGenerator::makeNestedFunction(Free_x125): Cannot generate
int32_t xHx8 = kernel_x8(resourceInfo);
// MaxJ writeFunctionCall(x132) {
// Inputs(x132) = List((x123,Argin_new,), (x8,ConstFixPt,infix_$plus), (x124,Argout_new,))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx123,(uint64_t*) xHx124,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x132(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x132) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x132): Cannot generate
int32_t xHx133 = kernel_x133(resourceInfo,xHx124);
// MaxJExecutableGenerator::makeNestedFunction(Free_x133): Cannot generate
int32_t xHx17 = kernel_x17(resourceInfo,xHx5,xHx8);
// MaxJExecutableGenerator::makeNestedFunction(Free_x17): Cannot generate
string xHx18 = kernel_x18(resourceInfo,xHx17);
kernel_x134(resourceInfo,xHx18);
// MaxJExecutableGenerator::makeNestedFunction(Free_x134): Cannot generate
string xHx135 = kernel_x135(resourceInfo,xHx133);
kernel_x136(resourceInfo,xHx135);
// MaxJExecutableGenerator::makeNestedFunction(Free_x136): Cannot generate
bool xHx137 = kernel_x137(resourceInfo,xHx17,xHx133);
// MaxJExecutableGenerator::makeNestedFunction(Free_x137): Cannot generate
string xHx138 = kernel_x138(resourceInfo,xHx137);
// MaxJExecutableGenerator::makeNestedFunction(Free_x138): Cannot generate
string xHx139 = kernel_x139(resourceInfo,xHx138);
// MaxJExecutableGenerator::makeNestedFunction(Free_x139): Cannot generate
kernel_x140(resourceInfo,xHx139);
// MaxJExecutableGenerator::makeNestedFunction(Free_x140): Cannot generate
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
