#ifndef __cppRefcppDeliteArraycppDeliteArrayfloat__
#define __cppRefcppDeliteArraycppDeliteArrayfloat__

#include "DeliteNamespaces.h"
class cppRefcppDeliteArraycppDeliteArrayfloat {
public:
  cppDeliteArraycppDeliteArrayfloat * data;

  cppRefcppDeliteArraycppDeliteArrayfloat(cppDeliteArraycppDeliteArrayfloat * _data) {
    data = _data;
  }

  cppDeliteArraycppDeliteArrayfloat * get(void) {
    return data;
  }

  void set(cppDeliteArraycppDeliteArrayfloat * newVal) {
      data = newVal;
  }
};

struct cppRefcppDeliteArraycppDeliteArrayfloatD {
  void operator()(cppRefcppDeliteArraycppDeliteArrayfloat *p) {
    //printf("cppRefcppDeliteArraycppDeliteArrayfloat: deleting %p\n",p);
  }
};

#endif
