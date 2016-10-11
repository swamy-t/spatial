#include "cpphelperFuncs.h"
void  kernel_x1853(resourceInfo_t *resourceInfo,maxjLmem  *x1716, cppDeliteArrayint32_t  *x1852) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x1716_rdAct;
      x1716_rdAct.param_size = x1852->length *sizeof(int32_t);
      x1716_rdAct.param_start = x1716->baseAddr;
      x1716_rdAct.outstream_tocpu = (uint8_t*) x1852->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x1716_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

