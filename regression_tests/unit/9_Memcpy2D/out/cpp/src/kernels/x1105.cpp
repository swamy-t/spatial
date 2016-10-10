#include "cpphelperFuncs.h"
void  kernel_x1105(resourceInfo_t *resourceInfo,int32_t  x54, int32_t  x1100, int32_t  x73, cppDeliteArrayint32_t  *x1089) {
for(int32_t i=x54; i<x1100; i+=x73) {
int32_t x145 = i;
int32_t  x146 = (int32_t) x145;
int32_t x1101 = x1089->apply(x146);
string  x1102 = string_plus( convert_to_string< int32_t >(x1101), convert_to_string< string >(string(" ")));
std::cout << x1102;
}

}

/**********/

