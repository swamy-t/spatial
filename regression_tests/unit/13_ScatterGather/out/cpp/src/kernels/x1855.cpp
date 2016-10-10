#include "cpphelperFuncs.h"
void  kernel_x1855(resourceInfo_t *resourceInfo,maxjLmem  *x1776, cppDeliteArrayint32_t  *x1854) {

      // Transfer LMEM -> DRAM
      // (sizeInBytes, address, dstptr)
      Top_readLMem_actions_t x1776_rdAct;
      x1776_rdAct.param_size = x1854->length *sizeof(int32_t);
      x1776_rdAct.param_start = x1776->baseAddr;
      x1776_rdAct.outstream_tocpu = (uint8_t*) x1854->data;
      fprintf(stderr, "Starting FPGA -> CPU copy\n");
      Top_readLMem_run(engine, &x1776_rdAct);
      fprintf(stderr, "FPGA -> CPU copy done\n");

}

/**********/

