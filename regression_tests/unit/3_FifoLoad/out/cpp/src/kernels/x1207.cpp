#include "cpphelperFuncs.h"
void  kernel_x1207(resourceInfo_t *resourceInfo,maxjLmem  *x1134, cppDeliteArrayint32_t  *x1206) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x1134_rdAct;
      x1134_rdAct.param_size = x1206->length *sizeof(int32_t);
      x1134_rdAct.param_start = x1134->baseAddr;
      x1134_rdAct.outstream_tocpu = (uint8_t*) x1206->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x1134_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

