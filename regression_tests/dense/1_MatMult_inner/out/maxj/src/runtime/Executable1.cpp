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
int32_t xHx285 = kernel_x285(resourceInfo);
int32_t  * xHx4578 = kernel_x4578(resourceInfo,xHx285);
int32_t  * xHx4579 = kernel_x4579(resourceInfo,xHx285);
int32_t  * xHx4580 = kernel_x4580(resourceInfo,xHx285);
string xHx1 = kernel_x1(resourceInfo,xHx0);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x4581(resourceInfo,xHx4578,xHx2);
string xHx3 = kernel_x3(resourceInfo,xHx0);
int32_t xHx4 = kernel_x4(resourceInfo,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4): Cannot generate
kernel_x4582(resourceInfo,xHx4579,xHx4);
string xHx5 = kernel_x5(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5): Cannot generate
int32_t xHx6 = kernel_x6(resourceInfo,xHx5);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6): Cannot generate
kernel_x4583(resourceInfo,xHx4580,xHx6);
int32_t xHx4584 = kernel_x4584(resourceInfo,xHx4578);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4584): Cannot generate
int32_t xHx4585 = kernel_x4585(resourceInfo,xHx4580);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4585): Cannot generate
int32_t xHx4586 = kernel_x4586(resourceInfo,xHx4584,xHx4585);
maxjLmem * xHx4587 = kernel_x4587(resourceInfo,xHx4586);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4587): Cannot generate
int32_t xHx4588 = kernel_x4588(resourceInfo,xHx4579);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4588): Cannot generate
int32_t xHx4589 = kernel_x4589(resourceInfo,xHx4585,xHx4588);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4589): Cannot generate
maxjLmem * xHx4590 = kernel_x4590(resourceInfo,xHx4589);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4590): Cannot generate
int32_t xHx4591 = kernel_x4591(resourceInfo,xHx4584,xHx4588);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4591): Cannot generate
maxjLmem * xHx4592 = kernel_x4592(resourceInfo,xHx4591);
int32_t xHx11 = kernel_x11(resourceInfo);
int32_t xHx7 = kernel_x7(resourceInfo,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x7): Cannot generate
int32_t xHx9 = kernel_x9(resourceInfo,xHx6);
// MaxJExecutableGenerator::makeNestedFunction(Free_x9): Cannot generate
int32_t xHx99 = kernel_x99(resourceInfo,xHx4);
// MaxJExecutableGenerator::makeNestedFunction(Free_x99): Cannot generate
activation_x4742* xop_x4742 = kernel_x4742(resourceInfo,xHx99,xHx11);
cppDeliteArrayint32_t * xHx4742 = xop_x4742->x4742;
activation_x4629x5380* xop_x4629x5380 = kernel_x4629x5380(resourceInfo,xHx9,xHx11,xHx4742);
cppDeliteArrayint32_t * xHx4629 = xop_x4629x5380->x4629;
cppDeliteArraycppDeliteArrayint32_t * xHx5380 = xop_x4629x5380->x5380;
// MaxJExecutableGenerator::makeNestedFunction(Free_x4629x5380): Cannot generate
activation_x4666* xop_x4666 = kernel_x4666(resourceInfo,xHx7,xHx4629);
cppDeliteArraycppDeliteArrayint32_t * xHx4666 = xop_x4666->x4666;
// MaxJExecutableGenerator::makeNestedFunction(Free_x4666): Cannot generate
activation_x4704* xop_x4704 = kernel_x4704(resourceInfo,xHx7,xHx4666);
cppDeliteArrayint32_t * xHx4704 = xop_x4704->x4704;
kernel_x4705(resourceInfo,xHx4587,xHx4704);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4705): Cannot generate
activation_x5382* xop_x5382 = kernel_x5382(resourceInfo,xHx9,xHx5380);
cppDeliteArrayint32_t * xHx5382 = xop_x5382->x5382;
kernel_x5383(resourceInfo,xHx4590,xHx5382);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5383): Cannot generate
int32_t xHx3194 = kernel_x3194(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3194): Cannot generate
int32_t xHx3195 = kernel_x3195(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3195): Cannot generate
int32_t xHx3197 = kernel_x3197(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3197): Cannot generate
int32_t xHx3199 = kernel_x3199(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3199): Cannot generate
int32_t xHx333 = kernel_x333(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x333): Cannot generate
bool xHx422 = kernel_x422(resourceInfo);
//writeGetter(x422, x422, x5033, false) - primitive
// MaxJ writeFunctionCall(x5033) {
// Inputs(x5033) = List((x4578,Argin_new,), (x4579,Argin_new,), (x285,ConstFixPt,), (x3194,ConstFixPt,stage_int_to_fixpt), (x3195,ConstFixPt,stage_int_to_fixpt), (x4580,Argin_new,), (x3197,ConstFixPt,apply), (x3199,ConstFixPt,apply), (x333,ConstFixPt,$colon$eq), (x11,ConstFixPt,scala_int_to_fixpt), (x4585,Reg_read,regFixToFix), (x422,ConstBit,Reduce), (x4587,Offchip_new,apply), (x4588,Reg_read,regFixToFix), (x4590,Offchip_new,apply), (x4592,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx4578, *xHx4579, *xHx4580,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x5033(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x5033) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x5033): Cannot generate
int32_t xHx5034 = kernel_x5034(resourceInfo,xHx4591);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5034): Cannot generate
cppDeliteArrayint32_t * xHx5035 = kernel_x5035(resourceInfo,xHx5034);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5035): Cannot generate
kernel_x5036(resourceInfo,xHx4592,xHx5035);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5036): Cannot generate
activation_x5397* xop_x5397 = kernel_x5397(resourceInfo,xHx7,xHx4666,xHx5380,xHx9,xHx285,xHx99);
cppDeliteArraycppDeliteArrayint32_t * xHx5397 = xop_x5397->x5397;
// MaxJExecutableGenerator::makeNestedFunction(Free_x5397): Cannot generate
activation_x5399* xop_x5399 = kernel_x5399(resourceInfo,xHx7,xHx5397);
cppDeliteArrayint32_t * xHx5399 = xop_x5399->x5399;
// MaxJExecutableGenerator::makeNestedFunction(Free_x5399): Cannot generate
int32_t xHx5400 = kernel_x5400(resourceInfo,xHx5399);
activation_x5404* xop_x5404 = kernel_x5404(resourceInfo,xHx5400,xHx5399);
cppDeliteArrayint32_t * xHx5404 = xop_x5404->x5404;
activation_x5406* xop_x5406 = kernel_x5406(resourceInfo,xHx5400,xHx285,xHx5404);
int32_t xHx5406 = xop_x5406->x5406;
// MaxJExecutableGenerator::makeNestedFunction(Free_x5406): Cannot generate
string xHx5407 = kernel_x5407(resourceInfo,xHx5406);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5407): Cannot generate
kernel_x5408(resourceInfo,xHx5407);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5408): Cannot generate
int32_t xHx5279 = kernel_x5279(resourceInfo,xHx5035);
activation_x5411* xop_x5411 = kernel_x5411(resourceInfo,xHx5279,xHx5035);
cppDeliteArrayint32_t * xHx5411 = xop_x5411->x5411;
int32_t xHx5412 = kernel_x5412(resourceInfo,xHx5411);
activation_x5415* xop_x5415 = kernel_x5415(resourceInfo,xHx5412,xHx285,xHx5411);
int32_t xHx5415 = xop_x5415->x5415;
// MaxJExecutableGenerator::makeNestedFunction(Free_x5415): Cannot generate
string xHx5416 = kernel_x5416(resourceInfo,xHx5415);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5416): Cannot generate
kernel_x5417(resourceInfo,xHx5416);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5417): Cannot generate
activation_x5423* xop_x5423 = kernel_x5423(resourceInfo,xHx5279,xHx5035,xHx5399);
cppDeliteArraybool * xHx5423 = xop_x5423->x5423;
// MaxJExecutableGenerator::makeNestedFunction(Free_x5423): Cannot generate
int32_t xHx5424 = kernel_x5424(resourceInfo,xHx5423);
bool xHx876 = kernel_x876(resourceInfo);
activation_x5427* xop_x5427 = kernel_x5427(resourceInfo,xHx5424,xHx876,xHx5423);
bool xHx5427 = xop_x5427->x5427;
// MaxJExecutableGenerator::makeNestedFunction(Free_x5427): Cannot generate
string xHx5428 = kernel_x5428(resourceInfo,xHx5427);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5428): Cannot generate
string xHx5429 = kernel_x5429(resourceInfo,xHx5428);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5429): Cannot generate
kernel_x5430(resourceInfo,xHx5429);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5430): Cannot generate
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
