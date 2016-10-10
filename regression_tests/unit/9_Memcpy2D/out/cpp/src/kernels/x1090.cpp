#include "cpphelperFuncs.h"
void  kernel_x1090(resourceInfo_t *resourceInfo,maxjLmem  *x1004, cppDeliteArrayint32_t  *x1089) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x1004_rdAct;
      x1004_rdAct.param_size = x1089->length *sizeof(int32_t);
      x1004_rdAct.param_start = x1004->baseAddr;
      x1004_rdAct.outstream_tocpu = (uint8_t*) x1089->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x1004_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

