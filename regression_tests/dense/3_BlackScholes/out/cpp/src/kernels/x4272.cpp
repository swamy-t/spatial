#include "cpphelperFuncs.h"
void  kernel_x4272(resourceInfo_t *resourceInfo,maxjLmem  *x4031, cppDeliteArrayfloat  *x4152) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x4031_wrAct;
      x4031_wrAct.param_size = x4152->length * sizeof(float);
      x4031_wrAct.param_start = x4031->baseAddr;
      x4031_wrAct.instream_fromcpu = (const uint8_t*) x4152->data;
      Top_writeLMem_run(engine, &x4031_wrAct);

}

/**********/

