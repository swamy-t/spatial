#include "cpphelperFuncs.h"
void  kernel_x2514(resourceInfo_t *resourceInfo,maxjLmem  *x2474, cppDeliteArrayint32_t  *x2513) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2474_wrAct;
      x2474_wrAct.param_size = x2513->length * sizeof(int32_t);
      x2474_wrAct.param_start = x2474->baseAddr;
      x2474_wrAct.instream_fromcpu = (const uint8_t*) x2513->data;
      Top_writeLMem_run(engine, &x2474_wrAct);

}

/**********/

