#include "cpphelperFuncs.h"
void  kernel_x3048(resourceInfo_t *resourceInfo,int32_t  x195, int32_t  x402, int32_t  x216, cppDeliteArraybool  *x3043) {
for(int32_t i=x195; i<x402; i+=x216) {
int32_t x404 = i;
int32_t  x405 = (int32_t) x404;
bool x3044 = x3043->apply(x405);
string  x3045 = string_plus( convert_to_string< bool >(x3044), convert_to_string< string >(string(" ")));
std::cout << x3045;
}

}

/**********/

