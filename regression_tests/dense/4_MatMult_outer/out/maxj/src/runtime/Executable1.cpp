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
int32_t xHx189 = kernel_x189(resourceInfo);
int32_t  * xHx5345 = kernel_x5345(resourceInfo,xHx189);
int32_t  * xHx5346 = kernel_x5346(resourceInfo,xHx189);
int32_t  * xHx5347 = kernel_x5347(resourceInfo,xHx189);
string xHx1 = kernel_x1(resourceInfo,xHx0);
int32_t xHx2 = kernel_x2(resourceInfo,xHx1);
// MaxJExecutableGenerator::makeNestedFunction(Free_x2): Cannot generate
kernel_x5348(resourceInfo,xHx5345,xHx2);
string xHx3 = kernel_x3(resourceInfo,xHx0);
int32_t xHx4 = kernel_x4(resourceInfo,xHx3);
// MaxJExecutableGenerator::makeNestedFunction(Free_x4): Cannot generate
kernel_x5349(resourceInfo,xHx5346,xHx4);
string xHx5 = kernel_x5(resourceInfo,xHx0);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5): Cannot generate
int32_t xHx6 = kernel_x6(resourceInfo,xHx5);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6): Cannot generate
kernel_x5350(resourceInfo,xHx5347,xHx6);
int32_t xHx5351 = kernel_x5351(resourceInfo,xHx5345);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5351): Cannot generate
int32_t xHx5352 = kernel_x5352(resourceInfo,xHx5347);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5352): Cannot generate
int32_t xHx5353 = kernel_x5353(resourceInfo,xHx5351,xHx5352);
maxjLmem * xHx5354 = kernel_x5354(resourceInfo,xHx5353);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5354): Cannot generate
int32_t xHx5355 = kernel_x5355(resourceInfo,xHx5346);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5355): Cannot generate
int32_t xHx5356 = kernel_x5356(resourceInfo,xHx5352,xHx5355);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5356): Cannot generate
maxjLmem * xHx5357 = kernel_x5357(resourceInfo,xHx5356);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5357): Cannot generate
int32_t xHx5358 = kernel_x5358(resourceInfo,xHx5351,xHx5355);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5358): Cannot generate
maxjLmem * xHx5359 = kernel_x5359(resourceInfo,xHx5358);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5359): Cannot generate
maxjLmem * xHx5360 = kernel_x5360(resourceInfo,xHx5358);
int32_t xHx11 = kernel_x11(resourceInfo);
int32_t xHx7 = kernel_x7(resourceInfo,xHx2);
// MaxJExecutableGenerator::makeNestedFunction(Free_x7): Cannot generate
int32_t xHx9 = kernel_x9(resourceInfo,xHx6);
// MaxJExecutableGenerator::makeNestedFunction(Free_x9): Cannot generate
int32_t xHx99 = kernel_x99(resourceInfo,xHx4);
// MaxJExecutableGenerator::makeNestedFunction(Free_x99): Cannot generate
activation_x5510x6203* xop_x5510x6203 = kernel_x5510x6203(resourceInfo,xHx99,xHx11,xHx189);
cppDeliteArrayint32_t * xHx5510 = xop_x5510x6203->x5510;
cppDeliteArrayint32_t * xHx6203 = xop_x5510x6203->x6203;
activation_x5397x6195* xop_x5397x6195 = kernel_x5397x6195(resourceInfo,xHx9,xHx11,xHx5510);
cppDeliteArrayint32_t * xHx5397 = xop_x5397x6195->x5397;
cppDeliteArraycppDeliteArrayint32_t * xHx6195 = xop_x5397x6195->x6195;
// MaxJExecutableGenerator::makeNestedFunction(Free_x5397x6195): Cannot generate
activation_x5434* xop_x5434 = kernel_x5434(resourceInfo,xHx7,xHx5397);
cppDeliteArraycppDeliteArrayint32_t * xHx5434 = xop_x5434->x5434;
// MaxJExecutableGenerator::makeNestedFunction(Free_x5434): Cannot generate
activation_x5472x6204* xop_x5472x6204 = kernel_x5472x6204(resourceInfo,xHx7,xHx6203,xHx5434);
cppDeliteArrayint32_t * xHx5472 = xop_x5472x6204->x5472;
cppDeliteArraycppDeliteArrayint32_t * xHx6204 = xop_x5472x6204->x6204;
// MaxJExecutableGenerator::makeNestedFunction(Free_x5472x6204): Cannot generate
kernel_x5473(resourceInfo,xHx5354,xHx5472);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5473): Cannot generate
activation_x6197* xop_x6197 = kernel_x6197(resourceInfo,xHx9,xHx6195);
cppDeliteArrayint32_t * xHx6197 = xop_x6197->x6197;
kernel_x6198(resourceInfo,xHx5357,xHx6197);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6198): Cannot generate
activation_x6206* xop_x6206 = kernel_x6206(resourceInfo,xHx7,xHx6204);
cppDeliteArrayint32_t * xHx6206 = xop_x6206->x6206;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6206): Cannot generate
kernel_x6207(resourceInfo,xHx5360,xHx6206);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6207): Cannot generate
int32_t xHx3930 = kernel_x3930(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3930): Cannot generate
int32_t xHx3931 = kernel_x3931(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3931): Cannot generate
int32_t xHx3933 = kernel_x3933(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3933): Cannot generate
int32_t xHx3935 = kernel_x3935(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x3935): Cannot generate
int32_t xHx461 = kernel_x461(resourceInfo);
// MaxJExecutableGenerator::makeNestedFunction(Free_x461): Cannot generate
bool xHx620 = kernel_x620(resourceInfo);
//writeGetter(x620, x620, x5832, false) - primitive
// MaxJ writeFunctionCall(x5832) {
// Inputs(x5832) = List((x5345,Argin_new,), (x5346,Argin_new,), (x189,ConstFixPt,scala_int_to_fixpt), (x3930,ConstFixPt,stage_int_to_fixpt), (x3931,ConstFixPt,stage_int_to_fixpt), (x3933,ConstFixPt,apply), (x461,ConstFixPt,$colon$eq), (x11,ConstFixPt,scala_int_to_fixpt), (x5355,Reg_read,regFixToFix), (x620,ConstBit,$colon$eq), (x5360,Offchip_new,apply), (x5347,Argin_new,), (x3935,ConstFixPt,apply), (x5352,Reg_read,regFixToFix), (x5354,Offchip_new,apply), (x5357,Offchip_new,apply))
struct timeval t1, t2;
uint64_t Top_cycles = 0;
Top_actions_t runAct;
runAct = { *xHx5345, *xHx5346, *xHx5347,&Top_cycles};
gettimeofday(&t1, 0);
Top_run(engine, &runAct); // kernel_x5832(engine, &runAct);
gettimeofday(&t2, 0);
double elapsed = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;
fprintf(stderr, "Kernel done, elapsed time = %lf\n", elapsed/1000000);
fprintf(stderr, "Kernel done, cycles = %lu\n", Top_cycles);
// MaxJ writeFunctionCall(x5832) }
// MaxJExecutableGenerator::makeNestedFunction(Free_x5832): Cannot generate
int32_t xHx5833 = kernel_x5833(resourceInfo,xHx5358);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5833): Cannot generate
cppDeliteArrayint32_t * xHx5834 = kernel_x5834(resourceInfo,xHx5833);
// MaxJExecutableGenerator::makeNestedFunction(Free_x5834): Cannot generate
kernel_x6208(resourceInfo,xHx5360,xHx5834);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6208): Cannot generate
activation_x6222* xop_x6222 = kernel_x6222(resourceInfo,xHx7,xHx5434,xHx6195,xHx9,xHx189,xHx99);
cppDeliteArraycppDeliteArrayint32_t * xHx6222 = xop_x6222->x6222;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6222): Cannot generate
activation_x6224* xop_x6224 = kernel_x6224(resourceInfo,xHx7,xHx6222);
cppDeliteArrayint32_t * xHx6224 = xop_x6224->x6224;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6224): Cannot generate
int32_t xHx6225 = kernel_x6225(resourceInfo,xHx6224);
activation_x6229* xop_x6229 = kernel_x6229(resourceInfo,xHx6225,xHx6224);
cppDeliteArrayint32_t * xHx6229 = xop_x6229->x6229;
activation_x6231* xop_x6231 = kernel_x6231(resourceInfo,xHx6225,xHx189,xHx6229);
int32_t xHx6231 = xop_x6231->x6231;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6231): Cannot generate
string xHx6232 = kernel_x6232(resourceInfo,xHx6231);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6232): Cannot generate
kernel_x6233(resourceInfo,xHx6232);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6233): Cannot generate
int32_t xHx6234 = kernel_x6234(resourceInfo,xHx5834);
activation_x6237* xop_x6237 = kernel_x6237(resourceInfo,xHx6234,xHx5834);
cppDeliteArrayint32_t * xHx6237 = xop_x6237->x6237;
int32_t xHx6238 = kernel_x6238(resourceInfo,xHx6237);
activation_x6241* xop_x6241 = kernel_x6241(resourceInfo,xHx6238,xHx189,xHx6237);
int32_t xHx6241 = xop_x6241->x6241;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6241): Cannot generate
string xHx6242 = kernel_x6242(resourceInfo,xHx6241);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6242): Cannot generate
kernel_x6243(resourceInfo,xHx6242);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6243): Cannot generate
kernel_x6244(resourceInfo);
int32_t xHx6245 = kernel_x6245(resourceInfo,xHx6225);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6245): Cannot generate
kernel_x6250(resourceInfo,xHx189,xHx6245,xHx11,xHx6224);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6250): Cannot generate
kernel_x6251(resourceInfo);
kernel_x6252(resourceInfo);
int32_t xHx6253 = kernel_x6253(resourceInfo,xHx6234);
kernel_x6254(resourceInfo,xHx189,xHx6253,xHx11,xHx5834);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6254): Cannot generate
kernel_x6255(resourceInfo);
activation_x6261* xop_x6261 = kernel_x6261(resourceInfo,xHx6234,xHx5834,xHx6224);
cppDeliteArraybool * xHx6261 = xop_x6261->x6261;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6261): Cannot generate
int32_t xHx6262 = kernel_x6262(resourceInfo,xHx6261);
bool xHx1065 = kernel_x1065(resourceInfo);
activation_x6265* xop_x6265 = kernel_x6265(resourceInfo,xHx6262,xHx1065,xHx6261);
bool xHx6265 = xop_x6265->x6265;
// MaxJExecutableGenerator::makeNestedFunction(Free_x6265): Cannot generate
string xHx6266 = kernel_x6266(resourceInfo,xHx6265);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6266): Cannot generate
string xHx6267 = kernel_x6267(resourceInfo,xHx6266);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6267): Cannot generate
kernel_x6268(resourceInfo,xHx6267);
// MaxJExecutableGenerator::makeNestedFunction(Free_x6268): Cannot generate
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
