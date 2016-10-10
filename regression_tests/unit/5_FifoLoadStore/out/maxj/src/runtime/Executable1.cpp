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
maxjLmem * xHx1037 = kernel_x1037(resourceInfo,xHx1);
maxjLmem * xHx1038 = kernel_x1038(resourceInfo,xHx1);
int32_t xHx50 = kernel_x50(resourceInfo);
int32_t  * xHx1039 = kernel_x1039(resourceInfo,xHx50);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1039): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
activation_x1076* xop_x1076 = kernel_x1076(resourceInfo,xHx2);
cppDeliteArrayint32_t * xHx1076 = xop_x1076->x1076;
kernel_x1077(resourceInfo,xHx1037,xHx1076);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1077): Cannot generate
int32_t xHx66 = kernel_x66(resourceInfo);
bool xHx72 = kernel_x72(resourceInfo);
//writeGetter(x72, x72, x1095, false) - primitive
// MaxJ writeFunctionCall(x1095) {
// Inputs(x1095) = List((x1,ConstFixPt,scala_int_to_fixpt), (x50,ConstFixPt,), (x1037,Offchip_new,apply), (x1038,Offchip_new,apply), (x66,ConstFixPt,scala_int_to_fixpt), (x1039,Argout_new,), (x72,ConstBit,$colon$eq))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = {(uint64_t*) xHx1039,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x1095(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x1095) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x1095): Cannot generate
cppDeliteArrayint32_t * xHx1096 = kernel_x1096(resourceInfo,xHx2);
kernel_x1097(resourceInfo,xHx1038,xHx1096);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1097): Cannot generate
kernel_x1098(resourceInfo);
activation_x1136* xop_x1136 = kernel_x1136(resourceInfo,xHx2,xHx1076);
cppDeliteArrayint32_t * xHx1136 = xop_x1136->x1136;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1136): Cannot generate
kernel_x1141(resourceInfo,xHx50,xHx1,xHx66,xHx1136);
kernel_x1142(resourceInfo);
kernel_x1143(resourceInfo);
kernel_x1148(resourceInfo,xHx50,xHx1,xHx66,xHx1096);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1148): Cannot generate
kernel_x1149(resourceInfo);
int32_t xHx1150 = kernel_x1150(resourceInfo,xHx1096);
activation_x1191* xop_x1191 = kernel_x1191(resourceInfo,xHx1150,xHx1096,xHx1136);
cppDeliteArraybool * xHx1191 = xop_x1191->x1191;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1191): Cannot generate
int32_t xHx1192 = kernel_x1192(resourceInfo,xHx1191);
bool xHx194 = kernel_x194(resourceInfo);
activation_x1197* xop_x1197 = kernel_x1197(resourceInfo,xHx1192,xHx194,xHx1191);
bool xHx1197 = xop_x1197->x1197;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1197): Cannot generate
string xHx1198 = kernel_x1198(resourceInfo,xHx1197);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1198): Cannot generate
string xHx1199 = kernel_x1199(resourceInfo,xHx1198);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1199): Cannot generate
kernel_x1200(resourceInfo,xHx1199);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1200): Cannot generate
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
