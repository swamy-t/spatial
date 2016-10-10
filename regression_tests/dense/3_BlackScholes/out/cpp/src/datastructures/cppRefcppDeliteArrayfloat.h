#ifndef __cppRefcppDeliteArrayfloat__
#define __cppRefcppDeliteArrayfloat__

#include "DeliteNamespaces.h"
class cppRefcppDeliteArrayfloat {
public:
  cppDeliteArrayfloat * data;

  cppRefcppDeliteArrayfloat(cppDeliteArrayfloat * _data) {
    data = _data;
  }

  cppDeliteArrayfloat * get(void) {
    return data;
  }

  void set(cppDeliteArrayfloat * newVal) {
      data = newVal;
  }
};

struct cppRefcppDeliteArrayfloatD {
  void operator()(cppRefcppDeliteArrayfloat *p) {
    //printf("cppRefcppDeliteArrayfloat: deleting %p\n",p);
  }
};

#endif
