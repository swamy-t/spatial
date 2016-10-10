#include "cpphelperFuncs.h"
void  kernel_x3238(resourceInfo_t *resourceInfo,int32_t  x105, int32_t  x3159, int32_t  x119, cppDeliteArrayint32_t  *x2959) {
for(int32_t i=x105; i<x3159; i+=x119) {
int32_t x503 = i;
int32_t  x504 = (int32_t) x503;
int32_t x3160 = x2959->apply(x504);
string  x3161 = string_plus( convert_to_string< int32_t >(x3160), convert_to_string< string >(string(" ")));
std::cout << x3161;
}

}

/**********/

