#include "cpphelperFuncs.h"
void  kernel_x2872(resourceInfo_t *resourceInfo,maxjLmem  *x2475, cppDeliteArrayint32_t  *x2871) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2475_wrAct;
      x2475_wrAct.param_size = x2871->length * sizeof(int32_t);
      x2475_wrAct.param_start = x2475->baseAddr;
      x2475_wrAct.instream_fromcpu = (const uint8_t*) x2871->data;
      Top_writeLMem_run(engine, &x2475_wrAct);

}

/**********/

