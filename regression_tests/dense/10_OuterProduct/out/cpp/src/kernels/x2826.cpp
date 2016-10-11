#include "cpphelperFuncs.h"
void  kernel_x2826(resourceInfo_t *resourceInfo,maxjLmem  *x2676, cppDeliteArrayint32_t  *x2825) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x2676_rdAct;
      x2676_rdAct.param_size = x2825->length *sizeof(int32_t);
      x2676_rdAct.param_start = x2676->baseAddr;
      x2676_rdAct.outstream_tocpu = (uint8_t*) x2825->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x2676_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

