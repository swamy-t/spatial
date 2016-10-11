#include "cpphelperFuncs.h"
void  kernel_x760(resourceInfo_t *resourceInfo,int32_t  x53, int32_t  x3, int32_t  x65, cppDeliteArrayint32_t  *x745) {
for(int32_t i=x53; i<x3; i+=x65) {
int32_t x67 = i;
int32_t  x68 = (int32_t) x67;
int32_t x756 = x745->apply(x68);
string  x757 = string_plus( convert_to_string< int32_t >(x756), convert_to_string< string >(string(" ")));
std::cout << x757;
}

}

/**********/

