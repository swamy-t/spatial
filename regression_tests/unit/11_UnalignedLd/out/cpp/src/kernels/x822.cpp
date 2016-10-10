#include "cpphelperFuncs.h"
void  kernel_x822(resourceInfo_t *resourceInfo,maxjLmem  *x783, cppDeliteArrayint32_t  *x821) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x783_wrAct;
      x783_wrAct.param_size = x821->length * sizeof(int32_t);
      x783_wrAct.param_start = x783->baseAddr;
      x783_wrAct.instream_fromcpu = (const uint8_t*) x821->data;
      Top_writeLMem_run(engine, &x783_wrAct);

}

/**********/

