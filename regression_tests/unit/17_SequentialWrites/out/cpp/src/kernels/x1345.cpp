#include "cpphelperFuncs.h"
void  kernel_x1345(resourceInfo_t *resourceInfo,maxjLmem  *x1251, cppDeliteArrayint32_t  *x1344) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x1251_rdAct;
      x1251_rdAct.param_size = x1344->length *sizeof(int32_t);
      x1251_rdAct.param_start = x1251->baseAddr;
      x1251_rdAct.outstream_tocpu = (uint8_t*) x1344->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x1251_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

