#include "cpphelperFuncs.h"
void  kernel_x2763(resourceInfo_t *resourceInfo,maxjLmem  *x2758, cppDeliteArrayint32_t  *x2710) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2758_wrAct;
      x2758_wrAct.param_size = x2710->length * sizeof(int32_t);
      x2758_wrAct.param_start = x2758->baseAddr;
      x2758_wrAct.instream_fromcpu = (const uint8_t*) x2710->data;
      Top_writeLMem_run(engine, &x2758_wrAct);

}

/**********/

