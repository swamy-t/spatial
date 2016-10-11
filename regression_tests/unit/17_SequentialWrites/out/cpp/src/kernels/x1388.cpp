#include "cpphelperFuncs.h"
void  kernel_x1388(resourceInfo_t *resourceInfo,int32_t  x53, int32_t  x179, int32_t  x64, cppDeliteArrayint32_t  *x1383) {
for(int32_t i=x53; i<x179; i+=x64) {
int32_t x181 = i;
int32_t  x182 = (int32_t) x181;
int32_t x1384 = x1383->apply(x182);
string  x1385 = string_plus( convert_to_string< int32_t >(x1384), convert_to_string< string >(string(" ")));
std::cout << x1385;
}

}

/**********/

