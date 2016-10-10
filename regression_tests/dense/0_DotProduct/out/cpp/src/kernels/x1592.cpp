#include "cpphelperFuncs.h"
void  kernel_x1592(resourceInfo_t *resourceInfo,maxjLmem  *x1590, cppDeliteArrayint32_t  *x1528) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x1590_wrAct;
      x1590_wrAct.param_size = x1528->length * sizeof(int32_t);
      x1590_wrAct.param_start = x1590->baseAddr;
      x1590_wrAct.instream_fromcpu = (const uint8_t*) x1528->data;
      Top_writeLMem_run(engine, &x1590_wrAct);

}

/**********/

