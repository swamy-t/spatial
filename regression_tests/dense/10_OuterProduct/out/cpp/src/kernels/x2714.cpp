#include "cpphelperFuncs.h"
void  kernel_x2714(resourceInfo_t *resourceInfo,maxjLmem  *x2672, cppDeliteArrayint32_t  *x2713) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2672_wrAct;
      x2672_wrAct.param_size = x2713->length * sizeof(int32_t);
      x2672_wrAct.param_start = x2672->baseAddr;
      x2672_wrAct.instream_fromcpu = (const uint8_t*) x2713->data;
      Top_writeLMem_run(engine, &x2672_wrAct);

}

/**********/

