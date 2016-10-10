#include "cpphelperFuncs.h"
void  kernel_x2611(resourceInfo_t *resourceInfo,maxjLmem  *x2476, cppDeliteArrayint32_t  *x2610) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x2476_rdAct;
      x2476_rdAct.param_size = x2610->length *sizeof(int32_t);
      x2476_rdAct.param_start = x2476->baseAddr;
      x2476_rdAct.outstream_tocpu = (uint8_t*) x2610->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x2476_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

