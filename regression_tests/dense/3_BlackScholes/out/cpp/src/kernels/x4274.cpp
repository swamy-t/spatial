#include "cpphelperFuncs.h"
void  kernel_x4274(resourceInfo_t *resourceInfo,maxjLmem  *x4033, cppDeliteArrayfloat  *x4230) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x4033_wrAct;
      x4033_wrAct.param_size = x4230->length * sizeof(float);
      x4033_wrAct.param_start = x4033->baseAddr;
      x4033_wrAct.instream_fromcpu = (const uint8_t*) x4230->data;
      Top_writeLMem_run(engine, &x4033_wrAct);

}

/**********/

