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
int32_t xHx53 = kernel_x53(resourceInfo);
int32_t  * xHx1710 = kernel_x1710(resourceInfo,xHx53);
int32_t  * xHx1711 = kernel_x1711(resourceInfo,xHx53);
string xHx1 = kernel_x1(resourceInfo,xHx0);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x1712(resourceInfo,xHx1710,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1712): Cannot generate
string xHx3 = kernel_x3(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3): Cannot generate
int32_t xHx4 = kernel_x4(resourceInfo,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4): Cannot generate
kernel_x1713(resourceInfo,xHx1711,xHx4);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1713): Cannot generate
int32_t xHx354 = kernel_x354(resourceInfo);
maxjLmem * xHx1714 = kernel_x1714(resourceInfo,xHx354);
maxjLmem * xHx1715 = kernel_x1715(resourceInfo,xHx354);
maxjLmem * xHx1716 = kernel_x1716(resourceInfo,xHx354);
maxjLmem * xHx1717 = kernel_x1717(resourceInfo,xHx354);
int32_t xHx111 = kernel_x111(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x111): Cannot generate
bool xHx131 = kernel_x131(resourceInfo);
int32_t xHx58 = kernel_x58(resourceInfo);
int32_t xHx59 = kernel_x59(resourceInfo);
int32_t xHx66 = kernel_x66(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x66): Cannot generate
int32_t xHx93 = kernel_x93(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x93): Cannot generate
int32_t xHx99 = kernel_x99(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x99): Cannot generate
//writeGetter(x131, x131, x1847, false) - primitive
// MaxJ writeFunctionCall(x1847) {
// Inputs(x1847) = List((x1710,Argin_new,), (x53,ConstFixPt,), (x66,ConstFixPt,scala_int_to_fixpt), (x354,ConstFixPt,getMem), (x1711,Argin_new,), (x93,ConstFixPt,infix_$plus), (x99,ConstFixPt,infix_$plus), (x111,ConstFixPt,$colon$eq), (x58,ConstFixPt,scala_int_to_fixpt), (x59,ConstFixPt,scala_int_to_fixpt), (x131,ConstBit,$colon$eq), (x1714,Offchip_new,apply), (x1715,Offchip_new,apply), (x1716,Offchip_new,apply), (x1717,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx1710, *xHx1711,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x1847(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x1847) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x1847): Cannot generate
int32_t xHx467 = kernel_x467(resourceInfo,xHx354);
// MaxJExecutableGenerator::makeNestedFunction(Free_x467): Cannot generate
cppDeliteArrayint32_t * xHx1848 = kernel_x1848(resourceInfo,xHx467);
kernel_x1849(resourceInfo,xHx1714,xHx1848);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1849): Cannot generate
cppDeliteArrayint32_t * xHx1850 = kernel_x1850(resourceInfo,xHx467);
kernel_x1851(resourceInfo,xHx1715,xHx1850);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1851): Cannot generate
cppDeliteArrayint32_t * xHx1852 = kernel_x1852(resourceInfo,xHx467);
kernel_x1853(resourceInfo,xHx1716,xHx1852);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1853): Cannot generate
cppDeliteArrayint32_t * xHx1854 = kernel_x1854(resourceInfo,xHx467);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1854): Cannot generate
kernel_x1855(resourceInfo,xHx1717,xHx1854);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1855): Cannot generate
int32_t xHx1856 = kernel_x1856(resourceInfo,xHx1848);
int32_t xHx1862 = kernel_x1862(resourceInfo,xHx1850);
int32_t xHx1868 = kernel_x1868(resourceInfo,xHx1852);
int32_t xHx1874 = kernel_x1874(resourceInfo,xHx1854);
activation_x1861* xop_x1861 = kernel_x1861(resourceInfo,xHx1856,xHx53,xHx1848);
int32_t xHx1861 = xop_x1861->x1861;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1861): Cannot generate
activation_x1867* xop_x1867 = kernel_x1867(resourceInfo,xHx1862,xHx53,xHx1850);
int32_t xHx1867 = xop_x1867->x1867;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1867): Cannot generate
activation_x1873* xop_x1873 = kernel_x1873(resourceInfo,xHx1868,xHx53,xHx1852);
int32_t xHx1873 = xop_x1873->x1873;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1873): Cannot generate
activation_x1879* xop_x1879 = kernel_x1879(resourceInfo,xHx1874,xHx53,xHx1854);
int32_t xHx1879 = xop_x1879->x1879;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1879): Cannot generate
int32_t xHx5 = kernel_x5(resourceInfo);
int32_t xHx6 = kernel_x6(resourceInfo,xHx5);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6): Cannot generate
activation_x1916* xop_x1916 = kernel_x1916(resourceInfo,xHx6,xHx4);
cppDeliteArrayint32_t * xHx1916 = xop_x1916->x1916;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1916): Cannot generate
activation_x1954* xop_x1954 = kernel_x1954(resourceInfo,xHx6,xHx1916);
cppDeliteArrayint32_t * xHx1954 = xop_x1954->x1954;
activation_x1958x1980* xop_x1958x1980 = kernel_x1958x1980(resourceInfo,xHx6,xHx53,xHx1954,xHx1916);
int32_t xHx1958 = xop_x1958x1980->x1958;
int32_t xHx1980 = xop_x1958x1980->x1980;
// MaxJExecutableGenerator::makeNestedFunction(Free_x1958x1980): Cannot generate
int32_t xHx1959 = kernel_x1959(resourceInfo,xHx1958,xHx58);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1959): Cannot generate
int32_t xHx1960 = kernel_x1960(resourceInfo,xHx1959,xHx59);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1960): Cannot generate
string xHx1961 = kernel_x1961(resourceInfo,xHx1960);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1961): Cannot generate
kernel_x1962(resourceInfo,xHx1961);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1962): Cannot generate
int32_t xHx1963 = kernel_x1963(resourceInfo,xHx1861,xHx1867);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1963): Cannot generate
int32_t xHx1964 = kernel_x1964(resourceInfo,xHx1963,xHx1873);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1964): Cannot generate
int32_t xHx1965 = kernel_x1965(resourceInfo,xHx1964,xHx1879);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1965): Cannot generate
string xHx1966 = kernel_x1966(resourceInfo,xHx1965);
kernel_x1967(resourceInfo,xHx1966);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1967): Cannot generate
int32_t xHx1981 = kernel_x1981(resourceInfo,xHx1980,xHx58);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1981): Cannot generate
int32_t xHx1982 = kernel_x1982(resourceInfo,xHx1981,xHx59);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1982): Cannot generate
bool xHx1983 = kernel_x1983(resourceInfo,xHx1982,xHx1965);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1983): Cannot generate
string xHx1984 = kernel_x1984(resourceInfo,xHx1983);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1984): Cannot generate
string xHx1985 = kernel_x1985(resourceInfo,xHx1984);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1985): Cannot generate
kernel_x1986(resourceInfo,xHx1985);
// MaxJExecutableGenerator::makeNestedFunction(Free_x1986): Cannot generate
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
