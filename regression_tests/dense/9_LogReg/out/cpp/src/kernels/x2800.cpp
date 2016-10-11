#include "cpphelperFuncs.h"
void  kernel_x2800(resourceInfo_t *resourceInfo,maxjLmem  *x2537, cppDeliteArrayfloat  *x2799) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x2537_rdAct;
      x2537_rdAct.param_size = x2799->length *sizeof(float);
      x2537_rdAct.param_start = x2537->baseAddr;
      x2537_rdAct.outstream_tocpu = (uint8_t*) x2799->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x2537_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

