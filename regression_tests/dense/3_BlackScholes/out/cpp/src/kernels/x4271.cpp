#include "cpphelperFuncs.h"
void  kernel_x4271(resourceInfo_t *resourceInfo,maxjLmem  *x4030, cppDeliteArrayfloat  *x4113) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x4030_wrAct;
      x4030_wrAct.param_size = x4113->length * sizeof(float);
      x4030_wrAct.param_start = x4030->baseAddr;
      x4030_wrAct.instream_fromcpu = (const uint8_t*) x4113->data;
      Top_writeLMem_run(engine, &x4030_wrAct);

}

/**********/

