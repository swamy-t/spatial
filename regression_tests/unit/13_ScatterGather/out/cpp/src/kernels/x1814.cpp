#include "cpphelperFuncs.h"
void  kernel_x1814(resourceInfo_t *resourceInfo,maxjLmem  *x1774, cppDeliteArrayint32_t  *x1813) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x1774_wrAct;
      x1774_wrAct.param_size = x1813->length * sizeof(int32_t);
      x1774_wrAct.param_start = x1774->baseAddr;
      x1774_wrAct.instream_fromcpu = (const uint8_t*) x1813->data;
      Top_writeLMem_run(engine, &x1774_wrAct);

}

/**********/

