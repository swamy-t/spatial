#include "cpphelperFuncs.h"
void  kernel_x762(resourceInfo_t *resourceInfo,maxjLmem  *x724, cppDeliteArrayint32_t  *x761) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x724_wrAct;
      x724_wrAct.param_size = x761->length * sizeof(int32_t);
      x724_wrAct.param_start = x724->baseAddr;
      x724_wrAct.instream_fromcpu = (const uint8_t*) x761->data;
      Top_writeLMem_run(engine, &x724_wrAct);

}

/**********/

