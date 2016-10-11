#include "cpphelperFuncs.h"
void  kernel_x6181(resourceInfo_t *resourceInfo,maxjLmem  *x5338, cppDeliteArrayint32_t  *x6180) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x5338_wrAct;
      x5338_wrAct.param_size = x6180->length * sizeof(int32_t);
      x5338_wrAct.param_start = x5338->baseAddr;
      x5338_wrAct.instream_fromcpu = (const uint8_t*) x6180->data;
      Top_writeLMem_run(engine, &x5338_wrAct);

}

/**********/

