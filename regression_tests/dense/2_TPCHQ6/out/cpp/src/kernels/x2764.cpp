#include "cpphelperFuncs.h"
void  kernel_x2764(resourceInfo_t *resourceInfo,maxjLmem  *x2759, cppDeliteArrayint32_t  *x2750) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2759_wrAct;
      x2759_wrAct.param_size = x2750->length * sizeof(int32_t);
      x2759_wrAct.param_start = x2759->baseAddr;
      x2759_wrAct.instream_fromcpu = (const uint8_t*) x2750->data;
      Top_writeLMem_run(engine, &x2759_wrAct);

}

/**********/

