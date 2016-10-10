#include "cpphelperFuncs.h"
void  kernel_x1172(resourceInfo_t *resourceInfo,maxjLmem  *x1133, cppDeliteArrayint32_t  *x1171) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x1133_wrAct;
      x1133_wrAct.param_size = x1171->length * sizeof(int32_t);
      x1133_wrAct.param_start = x1133->baseAddr;
      x1133_wrAct.instream_fromcpu = (const uint8_t*) x1171->data;
      Top_writeLMem_run(engine, &x1133_wrAct);

}

/**********/

