#include "cpphelperFuncs.h"
void  kernel_x2577(resourceInfo_t *resourceInfo,maxjLmem  *x2535, cppDeliteArrayfloat  *x2576) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2535_wrAct;
      x2535_wrAct.param_size = x2576->length * sizeof(float);
      x2535_wrAct.param_start = x2535->baseAddr;
      x2535_wrAct.instream_fromcpu = (const uint8_t*) x2576->data;
      Top_writeLMem_run(engine, &x2535_wrAct);

}

/**********/

