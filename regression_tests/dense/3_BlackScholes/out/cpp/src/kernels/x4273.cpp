#include "cpphelperFuncs.h"
void  kernel_x4273(resourceInfo_t *resourceInfo,maxjLmem  *x4032, cppDeliteArrayfloat  *x4191) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x4032_wrAct;
      x4032_wrAct.param_size = x4191->length * sizeof(float);
      x4032_wrAct.param_start = x4032->baseAddr;
      x4032_wrAct.instream_fromcpu = (const uint8_t*) x4191->data;
      Top_writeLMem_run(engine, &x4032_wrAct);

}

/**********/

