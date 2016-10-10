#include "cpphelperFuncs.h"
void  kernel_x746(resourceInfo_t *resourceInfo,maxjLmem  *x708, cppDeliteArrayint32_t  *x745) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x708_wrAct;
      x708_wrAct.param_size = x745->length * sizeof(int32_t);
      x708_wrAct.param_start = x708->baseAddr;
      x708_wrAct.instream_fromcpu = (const uint8_t*) x745->data;
      Top_writeLMem_run(engine, &x708_wrAct);

}

/**********/

