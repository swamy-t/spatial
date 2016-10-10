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
int32_t xHx5 = kernel_x5(resourceInfo);
string xHx1 = kernel_x1(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1): Cannot generate
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
int32_t xHx3 = kernel_x3(resourceInfo,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3): Cannot generate
activation_x1528* xop_x1528 = kernel_x1528(resourceInfo,xHx3,xHx5);
cppDeliteArrayint32_t * xHx1528 = xop_x1528->x1528;
activation_x1567* xop_x1567 = kernel_x1567(resourceInfo,xHx3,xHx5);
cppDeliteArrayint32_t * xHx1567 = xop_x1567->x1567;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1567): Cannot generate
kernel_x1568(resourceInfo);
int32_t xHx101 = kernel_x101(resourceInfo);
int32_t xHx1569 = kernel_x1569(resourceInfo,xHx1528);
int32_t xHx98 = kernel_x98(resourceInfo);
int32_t xHx1570 = kernel_x1570(resourceInfo,xHx1569);
kernel_x1575(resourceInfo,xHx98,xHx1570,xHx101,xHx1528);
kernel_x1576(resourceInfo);
kernel_x1577(resourceInfo);
int32_t xHx1578 = kernel_x1578(resourceInfo,xHx1567);
int32_t xHx1579 = kernel_x1579(resourceInfo,xHx1578);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1579): Cannot generate
kernel_x1584(resourceInfo,xHx98,xHx1579,xHx101,xHx1567);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1584): Cannot generate
kernel_x1585(resourceInfo);
int32_t  * xHx1586 = kernel_x1586(resourceInfo,xHx98);
kernel_x1587(resourceInfo,xHx1586,xHx1570);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1587): Cannot generate
int32_t  * xHx1588 = kernel_x1588(resourceInfo,xHx98);
int32_t xHx1589 = kernel_x1589(resourceInfo,xHx1586);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1589): Cannot generate
maxjLmem * xHx1590 = kernel_x1590(resourceInfo,xHx1589);
maxjLmem * xHx1591 = kernel_x1591(resourceInfo,xHx1589);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1591): Cannot generate
kernel_x1592(resourceInfo,xHx1590,xHx1528);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1592): Cannot generate
kernel_x1593(resourceInfo,xHx1591,xHx1567);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1593): Cannot generate
int32_t xHx1025 = kernel_x1025(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1025): Cannot generate
int32_t xHx146 = kernel_x146(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x146): Cannot generate
bool xHx192 = kernel_x192(resourceInfo);
//writeGetter(x192, x192, x1713, false) - primitive
// MaxJ writeFunctionCall(x1713) {
// Inputs(x1713) = List((x98,ConstFixPt,scala_int_to_fixpt), (x1586,Argin_new,), (x1025,ConstFixPt,stage_int_to_fixpt), (x101,ConstFixPt,infix_until), (x146,ConstFixPt,$colon$eq), (x1590,Offchip_new,apply), (x1591,Offchip_new,apply), (x192,ConstBit,Reduce), (x1588,Argout_new,))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx1586,(uint64_t*) xHx1588,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x1713(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x1713) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x1713): Cannot generate
int32_t xHx1714 = kernel_x1714(resourceInfo,xHx1588);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1714): Cannot generate
activation_x1754* xop_x1754 = kernel_x1754(resourceInfo,xHx1569,xHx1528,xHx1567);
cppDeliteArrayint32_t * xHx1754 = xop_x1754->x1754;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1754): Cannot generate
activation_x1758* xop_x1758 = kernel_x1758(resourceInfo,xHx1569,xHx98,xHx1754);
int32_t xHx1758 = xop_x1758->x1758;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1758): Cannot generate
string xHx1759 = kernel_x1759(resourceInfo,xHx1758);
kernel_x1760(resourceInfo,xHx1759);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1760): Cannot generate
string xHx1761 = kernel_x1761(resourceInfo,xHx1714);
kernel_x1762(resourceInfo,xHx1761);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1762): Cannot generate
bool xHx1763 = kernel_x1763(resourceInfo,xHx1758,xHx1714);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1763): Cannot generate
string xHx1764 = kernel_x1764(resourceInfo,xHx1763);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1764): Cannot generate
string xHx1765 = kernel_x1765(resourceInfo,xHx1764);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1765): Cannot generate
kernel_x1766(resourceInfo,xHx1765);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1766): Cannot generate
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
