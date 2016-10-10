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
int32_t xHx3 = kernel_x3(resourceInfo);
maxjLmem * xHx1198 = kernel_x1198(resourceInfo,xHx3);
maxjLmem * xHx1199 = kernel_x1199(resourceInfo,xHx3);
int32_t xHx4 = kernel_x4(resourceInfo,xHx3);
activation_x1236* xop_x1236 = kernel_x1236(resourceInfo,xHx4);
cppDeliteArrayint32_t * xHx1236 = xop_x1236->x1236;
kernel_x1237(resourceInfo,xHx1198,xHx1236);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1237): Cannot generate
int32_t xHx53 = kernel_x53(resourceInfo);
int32_t  * xHx1238 = kernel_x1238(resourceInfo,xHx53);
int32_t  * xHx1239 = kernel_x1239(resourceInfo,xHx53);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x1240(resourceInfo,xHx1239,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1240): Cannot generate
kernel_x1241(resourceInfo,xHx1238,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1241): Cannot generate
int32_t xHx69 = kernel_x69(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x69): Cannot generate
int32_t xHx72 = kernel_x72(resourceInfo);
int32_t xHx849 = kernel_x849(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x849): Cannot generate
// MaxJ writeFunctionCall(x1284) {
// Inputs(x1284) = List((x849,ConstFixPt,stage_int_to_fixpt), (x53,ConstFixPt,), (x1238,Argin_new,), (x69,ConstFixPt,$colon$eq), (x1198,Offchip_new,apply), (x72,ConstFixPt,$colon$eq), (x1239,Argin_new,), (x1199,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx1238, *xHx1239,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x1284(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x1284) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x1284): Cannot generate
cppDeliteArrayint32_t * xHx1285 = kernel_x1285(resourceInfo,xHx4);
kernel_x1286(resourceInfo,xHx1199,xHx1285);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1286): Cannot generate
kernel_x1287(resourceInfo);
activation_x1326* xop_x1326 = kernel_x1326(resourceInfo,xHx4,xHx1236,xHx2);
cppDeliteArrayint32_t * xHx1326 = xop_x1326->x1326;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1326): Cannot generate
kernel_x1331(resourceInfo,xHx53,xHx3,xHx72,xHx1326);
kernel_x1332(resourceInfo);
kernel_x1337(resourceInfo,xHx53,xHx3,xHx72,xHx1285);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1337): Cannot generate
kernel_x1338(resourceInfo);
int32_t xHx1339 = kernel_x1339(resourceInfo,xHx1285);
activation_x1380* xop_x1380 = kernel_x1380(resourceInfo,xHx1339,xHx1285,xHx1326);
cppDeliteArraybool * xHx1380 = xop_x1380->x1380;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1380): Cannot generate
int32_t xHx1381 = kernel_x1381(resourceInfo,xHx1380);
bool xHx228 = kernel_x228(resourceInfo);
activation_x1386* xop_x1386 = kernel_x1386(resourceInfo,xHx1381,xHx228,xHx1380);
bool xHx1386 = xop_x1386->x1386;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1386): Cannot generate
string xHx1387 = kernel_x1387(resourceInfo,xHx1386);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1387): Cannot generate
string xHx1388 = kernel_x1388(resourceInfo,xHx1387);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1388): Cannot generate
kernel_x1389(resourceInfo,xHx1388);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1389): Cannot generate
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
