#include "cpphelperFuncs.h"
void  kernel_x1042(resourceInfo_t *resourceInfo,maxjLmem  *x1003, cppDeliteArrayint32_t  *x1041) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x1003_wrAct;
      x1003_wrAct.param_size = x1041->length * sizeof(int32_t);
      x1003_wrAct.param_start = x1003->baseAddr;
      x1003_wrAct.instream_fromcpu = (const uint8_t*) x1041->data;
      Top_writeLMem_run(engine, &x1003_wrAct);

}

/**********/

