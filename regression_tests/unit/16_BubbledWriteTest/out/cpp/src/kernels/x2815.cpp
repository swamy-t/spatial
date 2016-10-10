#include "cpphelperFuncs.h"
void  kernel_x2815(resourceInfo_t *resourceInfo,maxjLmem  *x2772, cppDeliteArrayint32_t  *x2814) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2772_wrAct;
      x2772_wrAct.param_size = x2814->length * sizeof(int32_t);
      x2772_wrAct.param_start = x2772->baseAddr;
      x2772_wrAct.instream_fromcpu = (const uint8_t*) x2814->data;
      Top_writeLMem_run(engine, &x2772_wrAct);

}

/**********/

