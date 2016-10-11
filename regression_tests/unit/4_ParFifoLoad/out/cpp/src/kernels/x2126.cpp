#include "cpphelperFuncs.h"
void  kernel_x2126(resourceInfo_t *resourceInfo,maxjLmem  *x1837, cppDeliteArrayint32_t  *x2125) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x1837_wrAct;
      x1837_wrAct.param_size = x2125->length * sizeof(int32_t);
      x1837_wrAct.param_start = x1837->baseAddr;
      x1837_wrAct.instream_fromcpu = (const uint8_t*) x2125->data;
      Top_writeLMem_run(engine, &x1837_wrAct);

}

/**********/

