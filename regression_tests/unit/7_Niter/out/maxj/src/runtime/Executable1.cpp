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
int32_t xHx4 = kernel_x4(resourceInfo);
int32_t  * xHx549 = kernel_x549(resourceInfo,xHx4);
int32_t  * xHx550 = kernel_x550(resourceInfo,xHx4);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x551(resourceInfo,xHx549,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x551): Cannot generate
int32_t xHx15 = kernel_x15(resourceInfo);
int32_t xHx3 = kernel_x3(resourceInfo);
bool xHx31 = kernel_x31(resourceInfo);
//writeGetter(x31, x31, x572, false) - primitive
// MaxJ writeFunctionCall(x572) {
// Inputs(x572) = List((x549,Argin_new,), (x4,ConstFixPt,), (x3,ConstFixPt,scala_int_to_fixpt), (x15,ConstFixPt,infix_par), (x31,ConstBit,Reduce), (x550,Argout_new,))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx549,(uint64_t*) xHx550,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x572(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x572) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x572): Cannot generate
int32_t xHx573 = kernel_x573(resourceInfo,xHx550);
// MaxJExecutableGenerator::makeNestedFunction(Free_x573): Cannot generate
int32_t xHx100 = kernel_x100(resourceInfo,xHx2,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x100): Cannot generate
int32_t xHx103 = kernel_x103(resourceInfo);
int32_t xHx46 = kernel_x46(resourceInfo,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x46): Cannot generate
int32_t xHx101 = kernel_x101(resourceInfo,xHx100,xHx15);
// MaxJExecutableGenerator::makeNestedFunction(Free_x101): Cannot generate
activation_x610* xop_x610 = kernel_x610(resourceInfo,xHx46);
cppDeliteArrayint32_t * xHx610 = xop_x610->x610;
int32_t xHx102 = kernel_x102(resourceInfo,xHx100,xHx101);
// MaxJExecutableGenerator::makeNestedFunction(Free_x102): Cannot generate
activation_x614* xop_x614 = kernel_x614(resourceInfo,xHx46,xHx4,xHx610);
int32_t xHx614 = xop_x614->x614;
// MaxJExecutableGenerator::makeNestedFunction(Free_x614): Cannot generate
int32_t xHx104 = kernel_x104(resourceInfo,xHx102,xHx103);
// MaxJExecutableGenerator::makeNestedFunction(Free_x104): Cannot generate
int32_t xHx615 = kernel_x615(resourceInfo,xHx614,xHx104);
// MaxJExecutableGenerator::makeNestedFunction(Free_x615): Cannot generate
string xHx616 = kernel_x616(resourceInfo,xHx615);
kernel_x617(resourceInfo,xHx616);
// MaxJExecutableGenerator::makeNestedFunction(Free_x617): Cannot generate
string xHx618 = kernel_x618(resourceInfo,xHx573);
kernel_x619(resourceInfo,xHx618);
// MaxJExecutableGenerator::makeNestedFunction(Free_x619): Cannot generate
bool xHx620 = kernel_x620(resourceInfo,xHx615,xHx573);
// MaxJExecutableGenerator::makeNestedFunction(Free_x620): Cannot generate
string xHx621 = kernel_x621(resourceInfo,xHx620);
// MaxJExecutableGenerator::makeNestedFunction(Free_x621): Cannot generate
string xHx622 = kernel_x622(resourceInfo,xHx621);
// MaxJExecutableGenerator::makeNestedFunction(Free_x622): Cannot generate
kernel_x623(resourceInfo,xHx622);
// MaxJExecutableGenerator::makeNestedFunction(Free_x623): Cannot generate
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
