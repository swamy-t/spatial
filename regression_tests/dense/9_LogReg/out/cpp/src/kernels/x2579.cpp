#include "cpphelperFuncs.h"
void  kernel_x2579(resourceInfo_t *resourceInfo,maxjLmem  *x2537, cppDeliteArrayfloat  *x2528) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2537_wrAct;
      x2537_wrAct.param_size = x2528->length * sizeof(float);
      x2537_wrAct.param_start = x2537->baseAddr;
      x2537_wrAct.instream_fromcpu = (const uint8_t*) x2528->data;
      Top_writeLMem_run(engine, &x2537_wrAct);

}

/**********/

