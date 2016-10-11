#include "cpphelperFuncs.h"
void  kernel_x1815(resourceInfo_t *resourceInfo,maxjLmem  *x1775, cppDeliteArrayint32_t  *x1773) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x1775_wrAct;
      x1775_wrAct.param_size = x1773->length * sizeof(int32_t);
      x1775_wrAct.param_start = x1775->baseAddr;
      x1775_wrAct.instream_fromcpu = (const uint8_t*) x1773->data;
      Top_writeLMem_run(engine, &x1775_wrAct);

}

/**********/

