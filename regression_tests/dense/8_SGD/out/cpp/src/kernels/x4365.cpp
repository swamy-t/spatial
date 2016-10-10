#include "cpphelperFuncs.h"
void  kernel_x4365(resourceInfo_t *resourceInfo,maxjLmem  *x4323, cppDeliteArrayint32_t  *x4364) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x4323_wrAct;
      x4323_wrAct.param_size = x4364->length * sizeof(int32_t);
      x4323_wrAct.param_start = x4323->baseAddr;
      x4323_wrAct.instream_fromcpu = (const uint8_t*) x4364->data;
      Top_writeLMem_run(engine, &x4323_wrAct);

}

/**********/

