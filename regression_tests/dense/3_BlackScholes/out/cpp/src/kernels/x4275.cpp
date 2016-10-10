#include "cpphelperFuncs.h"
void  kernel_x4275(resourceInfo_t *resourceInfo,maxjLmem  *x4034, cppDeliteArrayfloat  *x4269) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x4034_wrAct;
      x4034_wrAct.param_size = x4269->length * sizeof(float);
      x4034_wrAct.param_start = x4034->baseAddr;
      x4034_wrAct.instream_fromcpu = (const uint8_t*) x4269->data;
      Top_writeLMem_run(engine, &x4034_wrAct);

}

/**********/

