#ifndef __cppReffloat__
#define __cppReffloat__

#include "DeliteNamespaces.h"
class cppReffloat {
public:
  float  data;

  cppReffloat(float  _data) {
    data = _data;
  }

  float  get(void) {
    return data;
  }

  void set(float  newVal) {
      data = newVal;
  }
};

struct cppReffloatD {
  void operator()(cppReffloat *p) {
    //printf("cppReffloat: deleting %p\n",p);
  }
};

#endif
