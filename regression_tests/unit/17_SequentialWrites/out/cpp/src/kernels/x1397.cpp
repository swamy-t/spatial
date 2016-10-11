#include "cpphelperFuncs.h"
void  kernel_x1397(resourceInfo_t *resourceInfo,int32_t  x53, int32_t  x1392, int32_t  x64, cppDeliteArrayint32_t  *x1344) {
for(int32_t i=x53; i<x1392; i+=x64) {
int32_t x193 = i;
int32_t  x194 = (int32_t) x193;
int32_t x1393 = x1344->apply(x194);
string  x1394 = string_plus( convert_to_string< int32_t >(x1393), convert_to_string< string >(string(" ")));
std::cout << x1394;
}

}

/**********/

