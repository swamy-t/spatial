#include "cpphelperFuncs.h"
void  kernel_x3444(resourceInfo_t *resourceInfo,maxjLmem  *x3330, cppDeliteArrayint32_t  *x3443) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x3330_wrAct;
      x3330_wrAct.param_size = x3443->length * sizeof(int32_t);
      x3330_wrAct.param_start = x3330->baseAddr;
      x3330_wrAct.instream_fromcpu = (const uint8_t*) x3443->data;
      Top_writeLMem_run(engine, &x3330_wrAct);

}

/**********/

