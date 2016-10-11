#include "cpphelperFuncs.h"
void  kernel_x5473(resourceInfo_t *resourceInfo,maxjLmem  *x5354, cppDeliteArrayint32_t  *x5472) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x5354_wrAct;
      x5354_wrAct.param_size = x5472->length * sizeof(int32_t);
      x5354_wrAct.param_start = x5354->baseAddr;
      x5354_wrAct.instream_fromcpu = (const uint8_t*) x5472->data;
      Top_writeLMem_run(engine, &x5354_wrAct);

}

/**********/

