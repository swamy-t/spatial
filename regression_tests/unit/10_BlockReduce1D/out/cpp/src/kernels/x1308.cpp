#include "cpphelperFuncs.h"
void  kernel_x1308(resourceInfo_t *resourceInfo,maxjLmem  *x1221, cppDeliteArrayint32_t  *x1307) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x1221_rdAct;
      x1221_rdAct.param_size = x1307->length *sizeof(int32_t);
      x1221_rdAct.param_start = x1221->baseAddr;
      x1221_rdAct.outstream_tocpu = (uint8_t*) x1307->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x1221_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

