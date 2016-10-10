#include "cpphelperFuncs.h"
void  kernel_x1849(resourceInfo_t *resourceInfo,maxjLmem  *x1714, cppDeliteArrayint32_t  *x1848) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x1714_rdAct;
      x1714_rdAct.param_size = x1848->length *sizeof(int32_t);
      x1714_rdAct.param_start = x1714->baseAddr;
      x1714_rdAct.outstream_tocpu = (uint8_t*) x1848->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x1714_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

