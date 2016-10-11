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
int32_t  * xHx1217 = kernel_x1217(resourceInfo,xHx49);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x1218(resourceInfo,xHx1217,xHx2);
int32_t xHx1219 = kernel_x1219(resourceInfo,xHx1217);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1219): Cannot generate
maxjLmem * xHx1220 = kernel_x1220(resourceInfo,xHx1219);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1220): Cannot generate
int32_t xHx54 = kernel_x54(resourceInfo);
maxjLmem * xHx1221 = kernel_x1221(resourceInfo,xHx54);
int32_t xHx3 = kernel_x3(resourceInfo,xHx2);
activation_x1258* xop_x1258 = kernel_x1258(resourceInfo,xHx3);
cppDeliteArrayint32_t * xHx1258 = xop_x1258->x1258;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1258): Cannot generate
kernel_x1259(resourceInfo,xHx1220,xHx1258);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1259): Cannot generate
int32_t xHx62 = kernel_x62(resourceInfo);
int32_t xHx71 = kernel_x71(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x71): Cannot generate
// MaxJ writeFunctionCall(x1306) {
// Inputs(x1306) = List((x54,ConstFixPt,scala_int_to_fixpt), (x49,ConstFixPt,), (x1217,Argin_new,), (x62,ConstFixPt,Fold), (x71,ConstFixPt,$colon$eq), (x1220,Offchip_new,apply), (x1221,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx1217,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x1306(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x1306) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x1306): Cannot generate
int32_t xHx118 = kernel_x118(resourceInfo,xHx54);
cppDeliteArrayint32_t * xHx1307 = kernel_x1307(resourceInfo,xHx118);
kernel_x1308(resourceInfo,xHx1221,xHx1307);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1308): Cannot generate
kernel_x1309(resourceInfo);
int32_t xHx121 = kernel_x121(resourceInfo,xHx2,xHx54);
// MaxJExecutableGenerator::makeNestedFunction(Free_x121): Cannot generate
int32_t xHx124 = kernel_x124(resourceInfo);
int32_t xHx175 = kernel_x175(resourceInfo,xHx118);
int32_t xHx122 = kernel_x122(resourceInfo,xHx121,xHx62);
int32_t xHx123 = kernel_x123(resourceInfo,xHx121,xHx122);
// MaxJExecutableGenerator::makeNestedFunction(Free_x123): Cannot generate
int32_t xHx125 = kernel_x125(resourceInfo,xHx123,xHx124);
// MaxJExecutableGenerator::makeNestedFunction(Free_x125): Cannot generate
int32_t xHx126 = kernel_x126(resourceInfo,xHx125,xHx54);
// MaxJExecutableGenerator::makeNestedFunction(Free_x126): Cannot generate
activation_x1346* xop_x1346 = kernel_x1346(resourceInfo,xHx118,xHx121,xHx126);
cppDeliteArrayint32_t * xHx1346 = xop_x1346->x1346;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1346): Cannot generate
kernel_x1351(resourceInfo,xHx49,xHx175,xHx62,xHx1346);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1351): Cannot generate
kernel_x1352(resourceInfo);
kernel_x1353(resourceInfo);
int32_t xHx1354 = kernel_x1354(resourceInfo,xHx1307);
int32_t xHx1355 = kernel_x1355(resourceInfo,xHx1354);
kernel_x1360(resourceInfo,xHx49,xHx1355,xHx62,xHx1307);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1360): Cannot generate
kernel_x1361(resourceInfo);
activation_x1402* xop_x1402 = kernel_x1402(resourceInfo,xHx1354,xHx1307,xHx1346);
cppDeliteArraybool * xHx1402 = xop_x1402->x1402;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1402): Cannot generate
int32_t xHx1403 = kernel_x1403(resourceInfo,xHx1402);
bool xHx245 = kernel_x245(resourceInfo);
activation_x1408* xop_x1408 = kernel_x1408(resourceInfo,xHx1403,xHx245,xHx1402);
bool xHx1408 = xop_x1408->x1408;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1408): Cannot generate
string xHx1409 = kernel_x1409(resourceInfo,xHx1408);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1409): Cannot generate
string xHx1410 = kernel_x1410(resourceInfo,xHx1409);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1410): Cannot generate
kernel_x1411(resourceInfo,xHx1410);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1411): Cannot generate
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
