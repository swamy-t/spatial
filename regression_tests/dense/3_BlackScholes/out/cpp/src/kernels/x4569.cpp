#include "cpphelperFuncs.h"
void  kernel_x4569(resourceInfo_t *resourceInfo,maxjLmem  *x4035, cppDeliteArrayfloat  *x4568) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x4035_rdAct;
      x4035_rdAct.param_size = x4568->length *sizeof(float);
      x4035_rdAct.param_start = x4035->baseAddr;
      x4035_rdAct.outstream_tocpu = (uint8_t*) x4568->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x4035_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

