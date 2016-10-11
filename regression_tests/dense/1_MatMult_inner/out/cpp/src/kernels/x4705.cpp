#include "cpphelperFuncs.h"
void  kernel_x4705(resourceInfo_t *resourceInfo,maxjLmem  *x4587, cppDeliteArrayint32_t  *x4704) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x4587_wrAct;
      x4587_wrAct.param_size = x4704->length * sizeof(int32_t);
      x4587_wrAct.param_start = x4587->baseAddr;
      x4587_wrAct.instream_fromcpu = (const uint8_t*) x4704->data;
      Top_writeLMem_run(engine, &x4587_wrAct);

}

/**********/

