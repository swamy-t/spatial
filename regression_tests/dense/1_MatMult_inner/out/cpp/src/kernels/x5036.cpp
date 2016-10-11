#include "cpphelperFuncs.h"
void  kernel_x5036(resourceInfo_t *resourceInfo,maxjLmem  *x4592, cppDeliteArrayint32_t  *x5035) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x4592_rdAct;
      x4592_rdAct.param_size = x5035->length *sizeof(int32_t);
      x4592_rdAct.param_start = x4592->baseAddr;
      x4592_rdAct.outstream_tocpu = (uint8_t*) x5035->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x4592_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

