#include "cpphelperFuncs.h"
void  kernel_x6198(resourceInfo_t *resourceInfo,maxjLmem  *x5357, cppDeliteArrayint32_t  *x6197) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x5357_wrAct;
      x5357_wrAct.param_size = x6197->length * sizeof(int32_t);
      x5357_wrAct.param_start = x5357->baseAddr;
      x5357_wrAct.instream_fromcpu = (const uint8_t*) x6197->data;
      Top_writeLMem_run(engine, &x5357_wrAct);

}

/**********/

