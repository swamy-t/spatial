#include "cpphelperFuncs.h"
void  kernel_x2578(resourceInfo_t *resourceInfo,maxjLmem  *x2536, cppDeliteArrayfloat  *x2488) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2536_wrAct;
      x2536_wrAct.param_size = x2488->length * sizeof(float);
      x2536_wrAct.param_start = x2536->baseAddr;
      x2536_wrAct.instream_fromcpu = (const uint8_t*) x2488->data;
      Top_writeLMem_run(engine, &x2536_wrAct);

}

/**********/

