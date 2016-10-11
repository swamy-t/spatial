#include "cpphelperFuncs.h"
void  kernel_x6208(resourceInfo_t *resourceInfo,maxjLmem  *x5360, cppDeliteArrayint32_t  *x5834) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x5360_rdAct;
      x5360_rdAct.param_size = x5834->length *sizeof(int32_t);
      x5360_rdAct.param_start = x5360->baseAddr;
      x5360_rdAct.outstream_tocpu = (uint8_t*) x5834->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x5360_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

