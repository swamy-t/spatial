#include "cpphelperFuncs.h"
void  kernel_x1851(resourceInfo_t *resourceInfo,maxjLmem  *x1715, cppDeliteArrayint32_t  *x1850) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x1715_rdAct;
      x1715_rdAct.param_size = x1850->length *sizeof(int32_t);
      x1715_rdAct.param_start = x1715->baseAddr;
      x1715_rdAct.outstream_tocpu = (uint8_t*) x1850->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x1715_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

