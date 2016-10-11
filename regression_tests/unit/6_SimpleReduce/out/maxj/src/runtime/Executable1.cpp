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
cppDeliteArraystring * xHx1 = in0;
int32_t xHx4 = kernel_x4(resourceInfo);
int32_t  * xHx469 = kernel_x469(resourceInfo,xHx4);
int32_t  * xHx470 = kernel_x470(resourceInfo,xHx4);
string xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
int32_t xHx3 = kernel_x3(resourceInfo,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3): Cannot generate
kernel_x471(resourceInfo,xHx469,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x471): Cannot generate
int32_t xHx0 = kernel_x0(resourceInfo);
bool xHx27 = kernel_x27(resourceInfo);
int32_t xHx8 = kernel_x8(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x8): Cannot generate
//writeGetter(x27, x27, x487, false) - primitive
// MaxJ writeFunctionCall(x487) {
// Inputs(x487) = List((x4,ConstFixPt,), (x0,ConstFixPt,), (x8,ConstFixPt,scala_int_to_fixpt), (x469,Argin_new,), (x27,ConstBit,Reduce), (x470,Argout_new,))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx469,(uint64_t*) xHx470,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x487(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x487) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x487): Cannot generate
int32_t xHx488 = kernel_x488(resourceInfo,xHx470);
// MaxJExecutableGenerator::makeNestedFunction(Free_x488): Cannot generate
int32_t xHx36 = kernel_x36(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x36): Cannot generate
activation_x525* xop_x525 = kernel_x525(resourceInfo,xHx36,xHx3);
cppDeliteArrayint32_t * xHx525 = xop_x525->x525;
// MaxJExecutableGenerator::makeNestedFunction(Free_x525): Cannot generate
activation_x529* xop_x529 = kernel_x529(resourceInfo,xHx36,xHx4,xHx525);
int32_t xHx529 = xop_x529->x529;
// MaxJExecutableGenerator::makeNestedFunction(Free_x529): Cannot generate
string xHx530 = kernel_x530(resourceInfo,xHx529);
kernel_x531(resourceInfo,xHx530);
// MaxJExecutableGenerator::makeNestedFunction(Free_x531): Cannot generate
string xHx532 = kernel_x532(resourceInfo,xHx488);
kernel_x533(resourceInfo,xHx532);
// MaxJExecutableGenerator::makeNestedFunction(Free_x533): Cannot generate
bool xHx534 = kernel_x534(resourceInfo,xHx529,xHx488);
// MaxJExecutableGenerator::makeNestedFunction(Free_x534): Cannot generate
string xHx535 = kernel_x535(resourceInfo,xHx534);
// MaxJExecutableGenerator::makeNestedFunction(Free_x535): Cannot generate
string xHx536 = kernel_x536(resourceInfo,xHx535);
// MaxJExecutableGenerator::makeNestedFunction(Free_x536): Cannot generate
kernel_x537(resourceInfo,xHx536);
// MaxJExecutableGenerator::makeNestedFunction(Free_x537): Cannot generate
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
