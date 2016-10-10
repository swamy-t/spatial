#include "cpphelperFuncs.h"
void  kernel_x1593(resourceInfo_t *resourceInfo,maxjLmem  *x1591, cppDeliteArrayint32_t  *x1567) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x1591_wrAct;
      x1591_wrAct.param_size = x1567->length * sizeof(int32_t);
      x1591_wrAct.param_start = x1591->baseAddr;
      x1591_wrAct.instream_fromcpu = (const uint8_t*) x1567->data;
      Top_writeLMem_run(engine, &x1591_wrAct);

}

/**********/

