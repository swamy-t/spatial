#include "cpphelperFuncs.h"
void  kernel_x639(resourceInfo_t *resourceInfo,maxjLmem  *x601, cppDeliteArrayint32_t  *x638) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x601_wrAct;
      x601_wrAct.param_size = x638->length * sizeof(int32_t);
      x601_wrAct.param_start = x601->baseAddr;
      x601_wrAct.instream_fromcpu = (const uint8_t*) x638->data;
      Top_writeLMem_run(engine, &x601_wrAct);

}

/**********/

