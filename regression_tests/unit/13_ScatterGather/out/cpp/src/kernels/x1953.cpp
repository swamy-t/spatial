#include "cpphelperFuncs.h"
void  kernel_x1953(resourceInfo_t *resourceInfo,int32_t  x177, int32_t  x1948, int32_t  x52, cppDeliteArrayint32_t  *x1854) {
for(int32_t i=x177; i<x1948; i+=x52) {
int32_t x339 = i;
int32_t  x340 = (int32_t) x339;
int32_t x1949 = x1854->apply(x340);
string  x1950 = string_plus( convert_to_string< int32_t >(x1949), convert_to_string< string >(string(" ")));
std::cout << x1950;
}

}

/**********/

