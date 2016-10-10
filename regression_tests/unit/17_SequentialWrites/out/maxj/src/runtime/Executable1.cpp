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
maxjLmem * xHx1250 = kernel_x1250(resourceInfo,xHx3);
maxjLmem * xHx1251 = kernel_x1251(resourceInfo,xHx3);
int32_t xHx53 = kernel_x53(resourceInfo);
int32_t  * xHx1252 = kernel_x1252(resourceInfo,xHx53);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x1253(resourceInfo,xHx1252,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1253): Cannot generate
int32_t xHx4 = kernel_x4(resourceInfo,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4): Cannot generate
activation_x1290* xop_x1290 = kernel_x1290(resourceInfo,xHx4);
cppDeliteArrayint32_t * xHx1290 = xop_x1290->x1290;
kernel_x1291(resourceInfo,xHx1250,xHx1290);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1291): Cannot generate
int32_t xHx61 = kernel_x61(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x61): Cannot generate
int32_t xHx64 = kernel_x64(resourceInfo);
int32_t xHx75 = kernel_x75(resourceInfo);
// MaxJ writeFunctionCall(x1343) {
// Inputs(x1343) = List((x3,ConstFixPt,scala_int_to_fixpt), (x53,ConstFixPt,), (x61,ConstFixPt,$colon$eq), (x1250,Offchip_new,apply), (x64,ConstFixPt,$colon$eq), (x75,ConstFixPt,scala_int_to_fixpt), (x1252,Argin_new,), (x1251,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx1252,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x1343(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x1343) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x1343): Cannot generate
cppDeliteArrayint32_t * xHx1344 = kernel_x1344(resourceInfo,xHx4);
kernel_x1345(resourceInfo,xHx1251,xHx1344);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1345): Cannot generate
kernel_x1346(resourceInfo);
int32_t xHx129 = kernel_x129(resourceInfo,xHx2,xHx75);
// MaxJExecutableGenerator::makeNestedFunction(Free_x129): Cannot generate
int32_t xHx132 = kernel_x132(resourceInfo);
int32_t xHx179 = kernel_x179(resourceInfo,xHx4);
activation_x1383* xop_x1383 = kernel_x1383(resourceInfo,xHx4,xHx132,xHx129);
cppDeliteArrayint32_t * xHx1383 = xop_x1383->x1383;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1383): Cannot generate
kernel_x1388(resourceInfo,xHx53,xHx179,xHx64,xHx1383);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1388): Cannot generate
kernel_x1389(resourceInfo);
kernel_x1390(resourceInfo);
int32_t xHx1391 = kernel_x1391(resourceInfo,xHx1344);
int32_t xHx1392 = kernel_x1392(resourceInfo,xHx1391);
kernel_x1397(resourceInfo,xHx53,xHx1392,xHx64,xHx1344);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1397): Cannot generate
kernel_x1398(resourceInfo);
activation_x1439* xop_x1439 = kernel_x1439(resourceInfo,xHx1391,xHx1344,xHx1383);
cppDeliteArraybool * xHx1439 = xop_x1439->x1439;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1439): Cannot generate
int32_t xHx1440 = kernel_x1440(resourceInfo,xHx1439);
bool xHx249 = kernel_x249(resourceInfo);
activation_x1445* xop_x1445 = kernel_x1445(resourceInfo,xHx1440,xHx249,xHx1439);
bool xHx1445 = xop_x1445->x1445;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1445): Cannot generate
string xHx1446 = kernel_x1446(resourceInfo,xHx1445);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1446): Cannot generate
string xHx1447 = kernel_x1447(resourceInfo,xHx1446);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1447): Cannot generate
kernel_x1448(resourceInfo,xHx1447);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1448): Cannot generate
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
