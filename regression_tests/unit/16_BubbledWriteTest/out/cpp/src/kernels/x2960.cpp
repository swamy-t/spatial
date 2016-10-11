#include "cpphelperFuncs.h"
void  kernel_x2960(resourceInfo_t *resourceInfo,maxjLmem  *x2774, cppDeliteArrayint32_t  *x2959) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x2774_rdAct;
      x2774_rdAct.param_size = x2959->length *sizeof(int32_t);
      x2774_rdAct.param_start = x2774->baseAddr;
      x2774_rdAct.outstream_tocpu = (uint8_t*) x2959->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x2774_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

