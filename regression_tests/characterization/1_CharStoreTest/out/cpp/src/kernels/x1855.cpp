#include "cpphelperFuncs.h"
void  kernel_x1855(resourceInfo_t *resourceInfo,maxjLmem  *x1717, cppDeliteArrayint32_t  *x1854) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x1717_rdAct;
      x1717_rdAct.param_size = x1854->length *sizeof(int32_t);
      x1717_rdAct.param_start = x1717->baseAddr;
      x1717_rdAct.outstream_tocpu = (uint8_t*) x1854->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x1717_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

