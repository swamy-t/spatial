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
int32_t xHx5 = kernel_x5(resourceInfo);
int32_t  * xHx450 = kernel_x450(resourceInfo,xHx5);
int32_t  * xHx451 = kernel_x451(resourceInfo,xHx5);
int32_t  * xHx452 = kernel_x452(resourceInfo,xHx5);
// MaxJExecutableGenerator::makeNestedFunction(Free_x452): Cannot generate
string xHx1 = kernel_x1(resourceInfo,xHx0);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x453(resourceInfo,xHx450,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x453): Cannot generate
string xHx3 = kernel_x3(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3): Cannot generate
int32_t xHx4 = kernel_x4(resourceInfo,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4): Cannot generate
kernel_x454(resourceInfo,xHx451,xHx4);
// MaxJExecutableGenerator::makeNestedFunction(Free_x454): Cannot generate
int32_t xHx13 = kernel_x13(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x13): Cannot generate
bool xHx26 = kernel_x26(resourceInfo);
int32_t xHx33 = kernel_x33(resourceInfo);
//writeGetter(x26, x26, x476, false) - primitive
// MaxJ writeFunctionCall(x476) {
// Inputs(x476) = List((x33,ConstFixPt,scala_int_to_fixpt), (x5,ConstFixPt,), (x13,ConstFixPt,scala_int_to_fixpt), (x450,Argin_new,), (x451,Argin_new,), (x452,Argout_new,), (x26,ConstBit,$colon$eq))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx450, *xHx451,(uint64_t*) xHx452,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x476(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x476) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x476): Cannot generate
int32_t xHx477 = kernel_x477(resourceInfo,xHx452);
// MaxJExecutableGenerator::makeNestedFunction(Free_x477): Cannot generate
int32_t xHx34 = kernel_x34(resourceInfo,xHx33);
// MaxJExecutableGenerator::makeNestedFunction(Free_x34): Cannot generate
int32_t xHx81 = kernel_x81(resourceInfo,xHx4);
// MaxJExecutableGenerator::makeNestedFunction(Free_x81): Cannot generate
activation_x514* xop_x514 = kernel_x514(resourceInfo,xHx34,xHx2);
cppDeliteArrayint32_t * xHx514 = xop_x514->x514;
// MaxJExecutableGenerator::makeNestedFunction(Free_x514): Cannot generate
int32_t xHx515 = kernel_x515(resourceInfo,xHx514,xHx81);
// MaxJExecutableGenerator::makeNestedFunction(Free_x515): Cannot generate
string xHx516 = kernel_x516(resourceInfo,xHx515);
kernel_x517(resourceInfo,xHx516);
// MaxJExecutableGenerator::makeNestedFunction(Free_x517): Cannot generate
string xHx518 = kernel_x518(resourceInfo,xHx477);
kernel_x519(resourceInfo,xHx518);
// MaxJExecutableGenerator::makeNestedFunction(Free_x519): Cannot generate
bool xHx520 = kernel_x520(resourceInfo,xHx477,xHx515);
// MaxJExecutableGenerator::makeNestedFunction(Free_x520): Cannot generate
string xHx521 = kernel_x521(resourceInfo,xHx520);
// MaxJExecutableGenerator::makeNestedFunction(Free_x521): Cannot generate
string xHx522 = kernel_x522(resourceInfo,xHx521);
// MaxJExecutableGenerator::makeNestedFunction(Free_x522): Cannot generate
kernel_x523(resourceInfo,xHx522);
// MaxJExecutableGenerator::makeNestedFunction(Free_x523): Cannot generate
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
