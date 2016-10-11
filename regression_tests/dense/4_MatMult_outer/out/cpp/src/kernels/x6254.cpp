#include "cpphelperFuncs.h"
void  kernel_x6254(resourceInfo_t *resourceInfo,int32_t  x189, int32_t  x6253, int32_t  x11, cppDeliteArrayint32_t  *x5834) {
for(int32_t i=x189; i<x6253; i+=x11) {
int32_t x1009 = i;
int32_t  x1010 = (int32_t) x1009;
int32_t x6136 = x5834->apply(x1010);
string  x6137 = string_plus( convert_to_string< int32_t >(x6136), convert_to_string< string >(string(" ")));
std::cout << x6137;
}

}

/**********/

