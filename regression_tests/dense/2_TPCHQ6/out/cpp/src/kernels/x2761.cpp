#include "cpphelperFuncs.h"
void  kernel_x2761(resourceInfo_t *resourceInfo,maxjLmem  *x2756, cppDeliteArrayuint32_t  *x2631) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2756_wrAct;
      x2756_wrAct.param_size = x2631->length * sizeof(uint32_t);
      x2756_wrAct.param_start = x2756->baseAddr;
      x2756_wrAct.instream_fromcpu = (const uint8_t*) x2631->data;
      Top_writeLMem_run(engine, &x2756_wrAct);

}

/**********/

