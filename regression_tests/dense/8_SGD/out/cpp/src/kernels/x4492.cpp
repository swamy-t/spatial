#include "cpphelperFuncs.h"
void  kernel_x4492(resourceInfo_t *resourceInfo,maxjLmem  *x4325, cppDeliteArrayint32_t  *x4491) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x4325_rdAct;
      x4325_rdAct.param_size = x4491->length *sizeof(int32_t);
      x4325_rdAct.param_start = x4325->baseAddr;
      x4325_rdAct.outstream_tocpu = (uint8_t*) x4491->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x4325_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

