#include "cpphelperFuncs.h"
void  kernel_x766(resourceInfo_t *resourceInfo,int32_t  x53, int32_t  x3, int32_t  x65, cppDeliteArrayint32_t  *x753) {
for(int32_t i=x53; i<x3; i+=x65) {
int32_t x75 = i;
int32_t  x76 = (int32_t) x75;
int32_t x762 = x753->apply(x76);
string  x763 = string_plus( convert_to_string< int32_t >(x762), convert_to_string< string >(string(" ")));
std::cout << x763;
}

}

/**********/

