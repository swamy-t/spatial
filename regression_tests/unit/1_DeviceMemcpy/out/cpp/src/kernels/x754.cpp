#include "cpphelperFuncs.h"
void  kernel_x754(resourceInfo_t *resourceInfo,maxjLmem  *x708, cppDeliteArrayint32_t  *x753) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x708_rdAct;
      x708_rdAct.param_size = x753->length *sizeof(int32_t);
      x708_rdAct.param_start = x708->baseAddr;
      x708_rdAct.outstream_tocpu = (uint8_t*) x753->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x708_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

