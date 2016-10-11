#include "cpphelperFuncs.h"
void  kernel_x6207(resourceInfo_t *resourceInfo,maxjLmem  *x5360, cppDeliteArrayint32_t  *x6206) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x5360_wrAct;
      x5360_wrAct.param_size = x6206->length * sizeof(int32_t);
      x5360_wrAct.param_start = x5360->baseAddr;
      x5360_wrAct.instream_fromcpu = (const uint8_t*) x6206->data;
      Top_writeLMem_run(engine, &x5360_wrAct);

}

/**********/

