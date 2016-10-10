#include "cpphelperFuncs.h"
void  kernel_x3221(resourceInfo_t *resourceInfo,maxjLmem  *x2773, cppDeliteArrayint32_t  *x3220) {

      // Transfer DRAM -> LMEM
      Top_writeLMem_actions_t x2773_wrAct;
      x2773_wrAct.param_size = x3220->length * sizeof(int32_t);
      x2773_wrAct.param_start = x2773->baseAddr;
      x2773_wrAct.instream_fromcpu = (const uint8_t*) x3220->data;
      Top_writeLMem_run(engine, &x2773_wrAct);

}

/**********/

