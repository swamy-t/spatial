#include "cpphelperFuncs.h"
void  kernel_x1257(resourceInfo_t *resourceInfo,int32_t  x49, int32_t  x2, int32_t  x71, cppDeliteArrayint32_t  *x1206) {
for(int32_t i=x49; i<x2; i+=x71) {
int32_t x158 = i;
int32_t  x159 = (int32_t) x158;
int32_t x1253 = x1206->apply(x159);
string  x1254 = string_plus( convert_to_string< int32_t >(x1253), convert_to_string< string >(string(" ")));
std::cout << x1254;
}

}

/**********/

