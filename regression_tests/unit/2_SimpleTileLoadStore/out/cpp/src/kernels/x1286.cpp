#include "cpphelperFuncs.h"
void  kernel_x1286(resourceInfo_t *resourceInfo,maxjLmem  *x1199, cppDeliteArrayint32_t  *x1285) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x1199_rdAct;
      x1199_rdAct.param_size = x1285->length *sizeof(int32_t);
      x1199_rdAct.param_start = x1199->baseAddr;
      x1199_rdAct.outstream_tocpu = (uint8_t*) x1285->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x1199_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

