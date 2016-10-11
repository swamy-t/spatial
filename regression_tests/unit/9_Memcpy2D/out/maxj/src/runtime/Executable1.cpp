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
maxjLmem * xHx1003 = kernel_x1003(resourceInfo,xHx1);
maxjLmem * xHx1004 = kernel_x1004(resourceInfo,xHx1);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
activation_x1041* xop_x1041 = kernel_x1041(resourceInfo,xHx2);
cppDeliteArrayint32_t * xHx1041 = xop_x1041->x1041;
kernel_x1042(resourceInfo,xHx1003,xHx1041);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1042): Cannot generate
bool xHx116 = kernel_x116(resourceInfo);
int32_t xHx48 = kernel_x48(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x48): Cannot generate
int32_t xHx54 = kernel_x54(resourceInfo);
int32_t xHx71 = kernel_x71(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x71): Cannot generate
int32_t xHx73 = kernel_x73(resourceInfo);
//writeGetter(x116, x116, x1088, false) - primitive
// MaxJ writeFunctionCall(x1088) {
// Inputs(x1088) = List((x54,ConstFixPt,infix_by), (x48,ConstFixPt,scala_int_to_fixpt), (x1,ConstFixPt,scala_int_to_fixpt), (x71,ConstFixPt,$colon$eq), (x73,ConstFixPt,$colon$eq), (x116,ConstBit,$colon$eq), (x1003,Offchip_new,apply), (x1004,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = {&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x1088(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x1088) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x1088): Cannot generate
cppDeliteArrayint32_t * xHx1089 = kernel_x1089(resourceInfo,xHx2);
kernel_x1090(resourceInfo,xHx1004,xHx1089);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1090): Cannot generate
kernel_x1091(resourceInfo);
int32_t xHx131 = kernel_x131(resourceInfo,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x131): Cannot generate
kernel_x1096(resourceInfo,xHx54,xHx131,xHx73,xHx1041);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1096): Cannot generate
kernel_x1097(resourceInfo);
kernel_x1098(resourceInfo);
int32_t xHx1099 = kernel_x1099(resourceInfo,xHx1089);
int32_t xHx1100 = kernel_x1100(resourceInfo,xHx1099);
kernel_x1105(resourceInfo,xHx54,xHx1100,xHx73,xHx1089);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1105): Cannot generate
kernel_x1106(resourceInfo);
activation_x1147* xop_x1147 = kernel_x1147(resourceInfo,xHx1099,xHx1089,xHx1041);
cppDeliteArraybool * xHx1147 = xop_x1147->x1147;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1147): Cannot generate
int32_t xHx1148 = kernel_x1148(resourceInfo,xHx1147);
bool xHx201 = kernel_x201(resourceInfo);
activation_x1153* xop_x1153 = kernel_x1153(resourceInfo,xHx1148,xHx201,xHx1147);
bool xHx1153 = xop_x1153->x1153;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1153): Cannot generate
string xHx1154 = kernel_x1154(resourceInfo,xHx1153);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1154): Cannot generate
string xHx1155 = kernel_x1155(resourceInfo,xHx1154);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1155): Cannot generate
kernel_x1156(resourceInfo,xHx1155);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1156): Cannot generate
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
