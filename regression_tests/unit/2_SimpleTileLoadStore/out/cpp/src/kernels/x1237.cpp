#include "cpphelperFuncs.h"
void  kernel_x1237(resourceInfo_t *resourceInfo,maxjLmem  *x1198, cppDeliteArrayint32_t  *x1236) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x1198_wrAct;
      x1198_wrAct.param_size = x1236->length * sizeof(int32_t);
      x1198_wrAct.param_start = x1198->baseAddr;
      x1198_wrAct.instream_fromcpu = (const uint8_t*) x1236->data;
      Top_writeLMem_run(engine, &x1198_wrAct);

}

/**********/

