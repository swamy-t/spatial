#include "cpphelperFuncs.h"
void  kernel_x6191(resourceInfo_t *resourceInfo,maxjLmem  *x5339, cppDeliteArrayint32_t  *x5835) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x5339_rdAct;
      x5339_rdAct.param_size = x5835->length *sizeof(int32_t);
      x5339_rdAct.param_start = x5339->baseAddr;
      x5339_rdAct.outstream_tocpu = (uint8_t*) x5835->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x5339_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

