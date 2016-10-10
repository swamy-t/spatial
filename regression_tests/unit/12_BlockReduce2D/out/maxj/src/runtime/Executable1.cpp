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
int32_t xHx197 = kernel_x197(resourceInfo);
int32_t  * xHx3323 = kernel_x3323(resourceInfo,xHx197);
string xHx1 = kernel_x1(resourceInfo,xHx0);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x3324(resourceInfo,xHx3323,xHx2);
int32_t  * xHx3325 = kernel_x3325(resourceInfo,xHx197);
string xHx3 = kernel_x3(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3): Cannot generate
int32_t xHx4 = kernel_x4(resourceInfo,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4): Cannot generate
kernel_x3326(resourceInfo,xHx3325,xHx4);
int32_t xHx3327 = kernel_x3327(resourceInfo,xHx3323);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3327): Cannot generate
int32_t xHx3328 = kernel_x3328(resourceInfo,xHx3325);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3328): Cannot generate
int32_t xHx3329 = kernel_x3329(resourceInfo,xHx3327,xHx3328);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3329): Cannot generate
maxjLmem * xHx3330 = kernel_x3330(resourceInfo,xHx3329);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3330): Cannot generate
int32_t xHx888 = kernel_x888(resourceInfo);
maxjLmem * xHx3331 = kernel_x3331(resourceInfo,xHx888);
int32_t xHx5 = kernel_x5(resourceInfo,xHx2);
int32_t xHx8 = kernel_x8(resourceInfo,xHx4);
activation_x3405* xop_x3405 = kernel_x3405(resourceInfo,xHx5,xHx4,xHx8);
cppDeliteArraycppDeliteArrayint32_t * xHx3405 = xop_x3405->x3405;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3405): Cannot generate
activation_x3443* xop_x3443 = kernel_x3443(resourceInfo,xHx5,xHx3405);
cppDeliteArrayint32_t * xHx3443 = xop_x3443->x3443;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3443): Cannot generate
kernel_x3444(resourceInfo,xHx3330,xHx3443);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3444): Cannot generate
int32_t xHx206 = kernel_x206(resourceInfo);
int32_t xHx218 = kernel_x218(resourceInfo);
int32_t xHx231 = kernel_x231(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x231): Cannot generate
bool xHx299 = kernel_x299(resourceInfo);
//writeGetter(x299, x299, x3513, false) - primitive
// MaxJ writeFunctionCall(x3513) {
// Inputs(x3513) = List((x888,ConstFixPt,getMem), (x197,ConstFixPt,), (x3323,Argin_new,), (x3325,Argin_new,), (x206,ConstFixPt,scala_int_to_fixpt), (x218,ConstFixPt,Fold), (x231,ConstFixPt,$colon$eq), (x3328,Reg_read,regFixToFix), (x299,ConstBit,$colon$eq), (x3330,Offchip_new,apply), (x3331,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx3323, *xHx3325,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x3513(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x3513) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x3513): Cannot generate
int32_t xHx1055 = kernel_x1055(resourceInfo,xHx888);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1055): Cannot generate
cppDeliteArrayint32_t * xHx3514 = kernel_x3514(resourceInfo,xHx1055);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3514): Cannot generate
kernel_x3515(resourceInfo,xHx3331,xHx3514);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3515): Cannot generate
kernel_x3516(resourceInfo);
int32_t xHx311 = kernel_x311(resourceInfo,xHx2,xHx206);
// MaxJExecutableGenerator::makeNestedFunction(Free_x311): Cannot generate
int32_t xHx312 = kernel_x312(resourceInfo,xHx4,xHx206);
// MaxJExecutableGenerator::makeNestedFunction(Free_x312): Cannot generate
int32_t xHx314 = kernel_x314(resourceInfo,xHx206);
int32_t xHx405 = kernel_x405(resourceInfo,xHx311);
// MaxJExecutableGenerator::makeNestedFunction(Free_x405): Cannot generate
int32_t xHx451 = kernel_x451(resourceInfo,xHx312);
activation_x3707* xop_x3707 = kernel_x3707(resourceInfo,xHx314,xHx206,xHx312,xHx451,xHx405,xHx197);
cppDeliteArraycppDeliteArrayint32_t * xHx3707 = xop_x3707->x3707;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3707): Cannot generate
activation_x3745* xop_x3745 = kernel_x3745(resourceInfo,xHx314,xHx3707);
cppDeliteArrayint32_t * xHx3745 = xop_x3745->x3745;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3745): Cannot generate
int32_t xHx3746 = kernel_x3746(resourceInfo,xHx3745);
int32_t xHx3747 = kernel_x3747(resourceInfo,xHx3746);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3747): Cannot generate
kernel_x3752(resourceInfo,xHx197,xHx3747,xHx218,xHx3745);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3752): Cannot generate
kernel_x3753(resourceInfo);
kernel_x3754(resourceInfo);
int32_t xHx3755 = kernel_x3755(resourceInfo,xHx3514);
int32_t xHx3756 = kernel_x3756(resourceInfo,xHx3755);
kernel_x3761(resourceInfo,xHx197,xHx3756,xHx218,xHx3514);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3761): Cannot generate
kernel_x3762(resourceInfo);
activation_x3803* xop_x3803 = kernel_x3803(resourceInfo,xHx3755,xHx3514,xHx3745);
cppDeliteArraybool * xHx3803 = xop_x3803->x3803;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3803): Cannot generate
int32_t xHx3804 = kernel_x3804(resourceInfo,xHx3803);
bool xHx865 = kernel_x865(resourceInfo);
activation_x3809* xop_x3809 = kernel_x3809(resourceInfo,xHx3804,xHx865,xHx3803);
bool xHx3809 = xop_x3809->x3809;
// MaxJExecutableGenerator::makeNestedFunction(Free_x3809): Cannot generate
string xHx3810 = kernel_x3810(resourceInfo,xHx3809);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3810): Cannot generate
string xHx3811 = kernel_x3811(resourceInfo,xHx3810);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3811): Cannot generate
kernel_x3812(resourceInfo,xHx3811);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3812): Cannot generate
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
