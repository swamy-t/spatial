#include "cpphelperFuncs.h"
void  kernel_x4270(resourceInfo_t *resourceInfo,maxjLmem  *x4029, cppDeliteArrayuint32_t  *x4074) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x4029_wrAct;
      x4029_wrAct.param_size = x4074->length * sizeof(uint32_t);
      x4029_wrAct.param_start = x4029->baseAddr;
      x4029_wrAct.instream_fromcpu = (const uint8_t*) x4074->data;
      Top_writeLMem_run(engine, &x4029_wrAct);

}

/**********/

