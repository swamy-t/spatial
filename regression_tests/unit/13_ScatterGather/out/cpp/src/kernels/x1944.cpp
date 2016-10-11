#include "cpphelperFuncs.h"
void  kernel_x1944(resourceInfo_t *resourceInfo,int32_t  x177, int32_t  x325, int32_t  x52, cppDeliteArrayint32_t  *x1939) {
for(int32_t i=x177; i<x325; i+=x52) {
int32_t x327 = i;
int32_t  x328 = (int32_t) x327;
int32_t x1940 = x1939->apply(x328);
string  x1941 = string_plus( convert_to_string< int32_t >(x1940), convert_to_string< string >(string(" ")));
std::cout << x1941;
}

}

/**********/

