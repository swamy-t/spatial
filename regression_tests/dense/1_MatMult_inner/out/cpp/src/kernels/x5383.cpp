#include "cpphelperFuncs.h"
void  kernel_x5383(resourceInfo_t *resourceInfo,maxjLmem  *x4590, cppDeliteArrayint32_t  *x5382) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x4590_wrAct;
      x4590_wrAct.param_size = x5382->length * sizeof(int32_t);
      x4590_wrAct.param_start = x4590->baseAddr;
      x4590_wrAct.instream_fromcpu = (const uint8_t*) x5382->data;
      Top_writeLMem_run(engine, &x4590_wrAct);

}

/**********/

