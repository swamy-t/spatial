#include "cpphelperFuncs.h"
void  kernel_x1259(resourceInfo_t *resourceInfo,maxjLmem  *x1220, cppDeliteArrayint32_t  *x1258) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x1220_wrAct;
      x1220_wrAct.param_size = x1258->length * sizeof(int32_t);
      x1220_wrAct.param_start = x1220->baseAddr;
      x1220_wrAct.instream_fromcpu = (const uint8_t*) x1258->data;
      Top_writeLMem_run(engine, &x1220_wrAct);

}

/**********/

