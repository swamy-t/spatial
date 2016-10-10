#include "cpphelperFuncs.h"
void  kernel_x4366(resourceInfo_t *resourceInfo,maxjLmem  *x4324, cppDeliteArrayint32_t  *x4318) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x4324_wrAct;
      x4324_wrAct.param_size = x4318->length * sizeof(int32_t);
      x4324_wrAct.param_start = x4324->baseAddr;
      x4324_wrAct.instream_fromcpu = (const uint8_t*) x4318->data;
      Top_writeLMem_run(engine, &x4324_wrAct);

}

/**********/

