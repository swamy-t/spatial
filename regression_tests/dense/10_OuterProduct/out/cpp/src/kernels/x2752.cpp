#include "cpphelperFuncs.h"
void  kernel_x2752(resourceInfo_t *resourceInfo,maxjLmem  *x2674, cppDeliteArrayint32_t  *x2751) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2674_wrAct;
      x2674_wrAct.param_size = x2751->length * sizeof(int32_t);
      x2674_wrAct.param_start = x2674->baseAddr;
      x2674_wrAct.instream_fromcpu = (const uint8_t*) x2751->data;
      Top_writeLMem_run(engine, &x2674_wrAct);

}

/**********/

