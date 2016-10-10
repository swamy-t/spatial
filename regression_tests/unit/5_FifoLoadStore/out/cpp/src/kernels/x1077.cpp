#include "cpphelperFuncs.h"
void  kernel_x1077(resourceInfo_t *resourceInfo,maxjLmem  *x1037, cppDeliteArrayint32_t  *x1076) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x1037_wrAct;
      x1037_wrAct.param_size = x1076->length * sizeof(int32_t);
      x1037_wrAct.param_start = x1037->baseAddr;
      x1037_wrAct.instream_fromcpu = (const uint8_t*) x1076->data;
      Top_writeLMem_run(engine, &x1037_wrAct);

}

/**********/

