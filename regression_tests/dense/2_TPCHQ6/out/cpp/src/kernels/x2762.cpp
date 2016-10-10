#include "cpphelperFuncs.h"
void  kernel_x2762(resourceInfo_t *resourceInfo,maxjLmem  *x2757, cppDeliteArrayuint32_t  *x2670) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2757_wrAct;
      x2757_wrAct.param_size = x2670->length * sizeof(uint32_t);
      x2757_wrAct.param_start = x2757->baseAddr;
      x2757_wrAct.instream_fromcpu = (const uint8_t*) x2670->data;
      Top_writeLMem_run(engine, &x2757_wrAct);

}

/**********/

