#ifndef __cppRefuint32_t__
#define __cppRefuint32_t__

#include "DeliteNamespaces.h"
class cppRefuint32_t {
public:
  uint32_t  data;

  cppRefuint32_t(uint32_t  _data) {
    data = _data;
  }

  uint32_t  get(void) {
    return data;
  }

  void set(uint32_t  newVal) {
      data = newVal;
  }
};

struct cppRefuint32_tD {
  void operator()(cppRefuint32_t *p) {
    //printf("cppRefuint32_t: deleting %p\n",p);
  }
};

#endif
