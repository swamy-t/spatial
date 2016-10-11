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
int32_t xHx96 = kernel_x96(resourceInfo);
int32_t  * xHx1833 = kernel_x1833(resourceInfo,xHx96);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x1834(resourceInfo,xHx1833,xHx2);
int32_t xHx1835 = kernel_x1835(resourceInfo,xHx1833);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1835): Cannot generate
maxjLmem * xHx1836 = kernel_x1836(resourceInfo,xHx1835);
maxjLmem * xHx1837 = kernel_x1837(resourceInfo,xHx1835);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1837): Cannot generate
int32_t  * xHx1838 = kernel_x1838(resourceInfo,xHx96);
int32_t xHx3 = kernel_x3(resourceInfo,xHx2);
int32_t xHx51 = kernel_x51(resourceInfo);
activation_x1875x2125* xop_x1875x2125 = kernel_x1875x2125(resourceInfo,xHx3,xHx51);
cppDeliteArrayint32_t * xHx1875 = xop_x1875x2125->x1875;
cppDeliteArrayint32_t * xHx2125 = xop_x1875x2125->x2125;
kernel_x1876(resourceInfo,xHx1836,xHx1875);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1876): Cannot generate
kernel_x2126(resourceInfo,xHx1837,xHx2125);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2126): Cannot generate
int32_t xHx126 = kernel_x126(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x126): Cannot generate
bool xHx146 = kernel_x146(resourceInfo);
int32_t xHx159 = kernel_x159(resourceInfo);
//writeGetter(x146, x146, x1948, false) - primitive
// MaxJ writeFunctionCall(x1948) {
// Inputs(x1948) = List((x159,ConstFixPt,$minus), (x96,ConstFixPt,), (x1833,Argin_new,), (x1836,Offchip_new,apply), (x1837,Offchip_new,apply), (x126,ConstFixPt,scala_int_to_fixpt), (x146,ConstBit,Reduce), (x1838,Argout_new,))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx1833,(uint64_t*) xHx1838,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x1948(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x1948) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x1948): Cannot generate
int32_t xHx1949 = kernel_x1949(resourceInfo,xHx1838);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1949): Cannot generate
int32_t xHx160 = kernel_x160(resourceInfo,xHx2,xHx159);
// MaxJExecutableGenerator::makeNestedFunction(Free_x160): Cannot generate
activation_x2148* xop_x2148 = kernel_x2148(resourceInfo,xHx3,xHx1875,xHx2125);
cppDeliteArrayint32_t * xHx2148 = xop_x2148->x2148;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2148): Cannot generate
int32_t xHx161 = kernel_x161(resourceInfo,xHx160);
// MaxJExecutableGenerator::makeNestedFunction(Free_x161): Cannot generate
activation_x2150* xop_x2150 = kernel_x2150(resourceInfo,xHx3,xHx96,xHx2148);
int32_t xHx2150 = xop_x2150->x2150;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2150): Cannot generate
activation_x2129x2136* xop_x2129x2136 = kernel_x2129x2136(resourceInfo,xHx161,xHx51);
cppDeliteArrayint32_t * xHx2129 = xop_x2129x2136->x2129;
cppDeliteArrayint32_t * xHx2136 = xop_x2129x2136->x2136;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2129x2136): Cannot generate
activation_x2141* xop_x2141 = kernel_x2141(resourceInfo,xHx161,xHx2129,xHx2136);
cppDeliteArrayint32_t * xHx2141 = xop_x2141->x2141;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2141): Cannot generate
activation_x2143* xop_x2143 = kernel_x2143(resourceInfo,xHx161,xHx96,xHx2141);
int32_t xHx2143 = xop_x2143->x2143;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2143): Cannot generate
int32_t xHx2151 = kernel_x2151(resourceInfo,xHx2150,xHx2143);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2151): Cannot generate
string xHx2152 = kernel_x2152(resourceInfo,xHx2151);
kernel_x2153(resourceInfo,xHx2152);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2153): Cannot generate
string xHx2115 = kernel_x2115(resourceInfo,xHx1949);
kernel_x2154(resourceInfo,xHx2115);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2154): Cannot generate
bool xHx2155 = kernel_x2155(resourceInfo,xHx1949,xHx2151);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2155): Cannot generate
string xHx2156 = kernel_x2156(resourceInfo,xHx2155);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2156): Cannot generate
string xHx2157 = kernel_x2157(resourceInfo,xHx2156);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2157): Cannot generate
kernel_x2158(resourceInfo,xHx2157);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2158): Cannot generate
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
