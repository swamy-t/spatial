#include "cpphelperFuncs.h"
void  kernel_x1097(resourceInfo_t *resourceInfo,maxjLmem  *x1038, cppDeliteArrayint32_t  *x1096) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x1038_rdAct;
      x1038_rdAct.param_size = x1096->length *sizeof(int32_t);
      x1038_rdAct.param_start = x1038->baseAddr;
      x1038_rdAct.outstream_tocpu = (uint8_t*) x1096->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x1038_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

