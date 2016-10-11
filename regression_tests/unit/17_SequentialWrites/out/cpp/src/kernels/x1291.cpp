#include "cpphelperFuncs.h"
void  kernel_x1291(resourceInfo_t *resourceInfo,maxjLmem  *x1250, cppDeliteArrayint32_t  *x1290) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x1250_wrAct;
      x1250_wrAct.param_size = x1290->length * sizeof(int32_t);
      x1250_wrAct.param_start = x1250->baseAddr;
      x1250_wrAct.instream_fromcpu = (const uint8_t*) x1290->data;
      Top_writeLMem_run(engine, &x1250_wrAct);

}

/**********/

