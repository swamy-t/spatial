#include "cpphelperFuncs.h"
void  kernel_x1337(resourceInfo_t *resourceInfo,int32_t  x53, int32_t  x3, int32_t  x72, cppDeliteArrayint32_t  *x1285) {
for(int32_t i=x53; i<x3; i+=x72) {
int32_t x171 = i;
int32_t  x172 = (int32_t) x171;
int32_t x1333 = x1285->apply(x172);
string  x1334 = string_plus( convert_to_string< int32_t >(x1333), convert_to_string< string >(string(" ")));
std::cout << x1334;
}

}

/**********/

