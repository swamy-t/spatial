#include "cpphelperFuncs.h"
void  kernel_x3515(resourceInfo_t *resourceInfo,maxjLmem  *x3331, cppDeliteArrayint32_t  *x3514) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x3331_rdAct;
      x3331_rdAct.param_size = x3514->length *sizeof(int32_t);
      x3331_rdAct.param_start = x3331->baseAddr;
      x3331_rdAct.outstream_tocpu = (uint8_t*) x3514->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x3331_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

