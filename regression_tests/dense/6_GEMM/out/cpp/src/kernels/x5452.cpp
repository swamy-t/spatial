#include "cpphelperFuncs.h"
void  kernel_x5452(resourceInfo_t *resourceInfo,maxjLmem  *x5337, cppDeliteArrayint32_t  *x5451) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x5337_wrAct;
      x5337_wrAct.param_size = x5451->length * sizeof(int32_t);
      x5337_wrAct.param_start = x5337->baseAddr;
      x5337_wrAct.instream_fromcpu = (const uint8_t*) x5451->data;
      Top_writeLMem_run(engine, &x5337_wrAct);

}

/**********/

