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
int32_t xHx124 = kernel_x124(resourceInfo);
int32_t xHx125 = kernel_x125(resourceInfo,xHx124);
activation_x1773* xop_x1773 = kernel_x1773(resourceInfo,xHx125,xHx124);
cppDeliteArrayint32_t * xHx1773 = xop_x1773->x1773;
int32_t xHx1 = kernel_x1(resourceInfo);
maxjLmem * xHx1774 = kernel_x1774(resourceInfo,xHx1);
maxjLmem * xHx1775 = kernel_x1775(resourceInfo,xHx124);
maxjLmem * xHx1776 = kernel_x1776(resourceInfo,xHx124);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1776): Cannot generate
int32_t xHx12 = kernel_x12(resourceInfo);
int32_t xHx13 = kernel_x13(resourceInfo);
int32_t xHx16 = kernel_x16(resourceInfo);
int32_t xHx17 = kernel_x17(resourceInfo);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
int32_t xHx20 = kernel_x20(resourceInfo);
int32_t xHx21 = kernel_x21(resourceInfo);
int32_t xHx24 = kernel_x24(resourceInfo);
int32_t xHx25 = kernel_x25(resourceInfo);
int32_t xHx28 = kernel_x28(resourceInfo);
int32_t xHx29 = kernel_x29(resourceInfo);
int32_t xHx32 = kernel_x32(resourceInfo);
int32_t xHx33 = kernel_x33(resourceInfo);
int32_t xHx36 = kernel_x36(resourceInfo);
int32_t xHx37 = kernel_x37(resourceInfo);
int32_t xHx40 = kernel_x40(resourceInfo);
int32_t xHx41 = kernel_x41(resourceInfo);
int32_t xHx44 = kernel_x44(resourceInfo);
int32_t xHx45 = kernel_x45(resourceInfo);
int32_t xHx48 = kernel_x48(resourceInfo);
int32_t xHx49 = kernel_x49(resourceInfo);
int32_t xHx5 = kernel_x5(resourceInfo);
int32_t xHx52 = kernel_x52(resourceInfo);
int32_t xHx53 = kernel_x53(resourceInfo);
int32_t xHx56 = kernel_x56(resourceInfo);
int32_t xHx57 = kernel_x57(resourceInfo);
int32_t xHx60 = kernel_x60(resourceInfo);
int32_t xHx63 = kernel_x63(resourceInfo);
int32_t xHx64 = kernel_x64(resourceInfo);
int32_t xHx8 = kernel_x8(resourceInfo);
int32_t xHx9 = kernel_x9(resourceInfo);
activation_x1813* xop_x1813 = kernel_x1813(resourceInfo,xHx2,xHx5,xHx9,xHx13,xHx17,xHx21,xHx25,xHx29,xHx33,xHx37,xHx41,xHx45,xHx49,xHx53,xHx57,xHx60,xHx64,xHx63,xHx20,xHx56,xHx52,xHx48,xHx44,xHx40,xHx36,xHx32,xHx28,xHx24,xHx16,xHx12,xHx8);
cppDeliteArrayint32_t * xHx1813 = xop_x1813->x1813;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1813): Cannot generate
kernel_x1814(resourceInfo,xHx1774,xHx1813);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1814): Cannot generate
kernel_x1815(resourceInfo,xHx1775,xHx1773);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1815): Cannot generate
int32_t xHx177 = kernel_x177(resourceInfo);
int32_t xHx179 = kernel_x179(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x179): Cannot generate
int32_t xHx189 = kernel_x189(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x189): Cannot generate
// MaxJ writeFunctionCall(x1853) {
// Inputs(x1853) = List((x1,ConstFixPt,scala_int_to_fixpt), (x177,ConstFixPt,apply), (x179,ConstFixPt,scala_int_to_fixpt), (x189,ConstFixPt,$colon$eq), (x1774,Offchip_new,apply), (x52,ConstFixPt,scala_int_to_fixpt), (x1775,Offchip_new,apply), (x1776,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = {&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x1853(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x1853) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x1853): Cannot generate
cppDeliteArrayint32_t * xHx1854 = kernel_x1854(resourceInfo,xHx125);
kernel_x1855(resourceInfo,xHx1776,xHx1854);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1855): Cannot generate
kernel_x1856(resourceInfo);
bool xHx268 = kernel_x268(resourceInfo);
int32_t xHx325 = kernel_x325(resourceInfo,xHx125);
activation_x1939* xop_x1939 = kernel_x1939(resourceInfo,xHx125,xHx1813,xHx2,xHx268,xHx1773,xHx177);
cppDeliteArrayint32_t * xHx1939 = xop_x1939->x1939;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1939): Cannot generate
kernel_x1944(resourceInfo,xHx177,xHx325,xHx52,xHx1939);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1944): Cannot generate
kernel_x1945(resourceInfo);
kernel_x1946(resourceInfo);
int32_t xHx1947 = kernel_x1947(resourceInfo,xHx1854);
int32_t xHx1948 = kernel_x1948(resourceInfo,xHx1947);
kernel_x1953(resourceInfo,xHx177,xHx1948,xHx52,xHx1854);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1953): Cannot generate
kernel_x1954(resourceInfo);
activation_x1995* xop_x1995 = kernel_x1995(resourceInfo,xHx1947,xHx1854,xHx1939);
cppDeliteArraybool * xHx1995 = xop_x1995->x1995;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1995): Cannot generate
int32_t xHx1996 = kernel_x1996(resourceInfo,xHx1995);
activation_x2001* xop_x2001 = kernel_x2001(resourceInfo,xHx1996,xHx268,xHx1995);
bool xHx2001 = xop_x2001->x2001;
// MaxJExecutableGenerator::makeNestedFunction(Free_x2001): Cannot generate
string xHx2002 = kernel_x2002(resourceInfo,xHx2001);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2002): Cannot generate
string xHx2003 = kernel_x2003(resourceInfo,xHx2002);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2003): Cannot generate
kernel_x2004(resourceInfo,xHx2003);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2004): Cannot generate
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
