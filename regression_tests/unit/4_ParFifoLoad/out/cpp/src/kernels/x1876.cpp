#include "cpphelperFuncs.h"
void  kernel_x1876(resourceInfo_t *resourceInfo,maxjLmem  *x1836, cppDeliteArrayint32_t  *x1875) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x1836_wrAct;
      x1836_wrAct.param_size = x1875->length * sizeof(int32_t);
      x1836_wrAct.param_start = x1836->baseAddr;
      x1836_wrAct.instream_fromcpu = (const uint8_t*) x1875->data;
      Top_writeLMem_run(engine, &x1836_wrAct);

}

/**********/

