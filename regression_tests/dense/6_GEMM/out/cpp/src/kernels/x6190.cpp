#include "cpphelperFuncs.h"
void  kernel_x6190(resourceInfo_t *resourceInfo,maxjLmem  *x5339, cppDeliteArrayint32_t  *x6189) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x5339_wrAct;
      x5339_wrAct.param_size = x6189->length * sizeof(int32_t);
      x5339_wrAct.param_start = x5339->baseAddr;
      x5339_wrAct.instream_fromcpu = (const uint8_t*) x6189->data;
      Top_writeLMem_run(engine, &x5339_wrAct);

}

/**********/

