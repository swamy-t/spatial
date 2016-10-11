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
int32_t xHx49 = kernel_x49(resourceInfo);
int32_t  * xHx1130 = kernel_x1130(resourceInfo,xHx49);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x1131(resourceInfo,xHx1130,xHx2);
int32_t xHx1132 = kernel_x1132(resourceInfo,xHx1130);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1132): Cannot generate
maxjLmem * xHx1133 = kernel_x1133(resourceInfo,xHx1132);
maxjLmem * xHx1134 = kernel_x1134(resourceInfo,xHx1132);
int32_t xHx3 = kernel_x3(resourceInfo,xHx2);
activation_x1171* xop_x1171 = kernel_x1171(resourceInfo,xHx3);
cppDeliteArrayint32_t * xHx1171 = xop_x1171->x1171;
kernel_x1172(resourceInfo,xHx1133,xHx1171);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1172): Cannot generate
int32_t xHx71 = kernel_x71(resourceInfo);
int32_t xHx805 = kernel_x805(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x805): Cannot generate
int32_t xHx82 = kernel_x82(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x82): Cannot generate
// MaxJ writeFunctionCall(x1204) {
// Inputs(x1204) = List((x805,ConstFixPt,stage_int_to_fixpt), (x49,ConstFixPt,), (x1130,Argin_new,), (x1133,Offchip_new,apply), (x71,ConstFixPt,scala_int_to_fixpt), (x82,ConstFixPt,$colon$eq), (x1134,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx1130,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x1204(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x1204) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x1204): Cannot generate
int32_t xHx1205 = kernel_x1205(resourceInfo,xHx1132);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1205): Cannot generate
cppDeliteArrayint32_t * xHx1206 = kernel_x1206(resourceInfo,xHx1205);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1206): Cannot generate
kernel_x1207(resourceInfo,xHx1134,xHx1206);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1207): Cannot generate
kernel_x1208(resourceInfo);
activation_x1246* xop_x1246 = kernel_x1246(resourceInfo,xHx3,xHx1171);
cppDeliteArrayint32_t * xHx1246 = xop_x1246->x1246;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1246): Cannot generate
kernel_x1251(resourceInfo,xHx49,xHx2,xHx71,xHx1246);
kernel_x1252(resourceInfo);
kernel_x1257(resourceInfo,xHx49,xHx2,xHx71,xHx1206);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1257): Cannot generate
kernel_x1258(resourceInfo);
int32_t xHx1259 = kernel_x1259(resourceInfo,xHx1206);
activation_x1300* xop_x1300 = kernel_x1300(resourceInfo,xHx1259,xHx1206,xHx1246);
cppDeliteArraybool * xHx1300 = xop_x1300->x1300;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1300): Cannot generate
int32_t xHx1301 = kernel_x1301(resourceInfo,xHx1300);
bool xHx215 = kernel_x215(resourceInfo);
activation_x1306* xop_x1306 = kernel_x1306(resourceInfo,xHx1301,xHx215,xHx1300);
bool xHx1306 = xop_x1306->x1306;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1306): Cannot generate
string xHx1307 = kernel_x1307(resourceInfo,xHx1306);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1307): Cannot generate
string xHx1308 = kernel_x1308(resourceInfo,xHx1307);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1308): Cannot generate
kernel_x1309(resourceInfo,xHx1308);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1309): Cannot generate
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
