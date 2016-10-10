#ifndef __cppRefcppDeliteArrayuint32_t__
#define __cppRefcppDeliteArrayuint32_t__

#include "DeliteNamespaces.h"
class cppRefcppDeliteArrayuint32_t {
public:
  cppDeliteArrayuint32_t * data;

  cppRefcppDeliteArrayuint32_t(cppDeliteArrayuint32_t * _data) {
    data = _data;
  }

  cppDeliteArrayuint32_t * get(void) {
    return data;
  }

  void set(cppDeliteArrayuint32_t * newVal) {
      data = newVal;
  }
};

struct cppRefcppDeliteArrayuint32_tD {
  void operator()(cppRefcppDeliteArrayuint32_t *p) {
    //printf("cppRefcppDeliteArrayuint32_t: deleting %p\n",p);
  }
};

#endif
