#include "cpphelperFuncs.h"
void  kernel_x1148(resourceInfo_t *resourceInfo,int32_t  x50, int32_t  x1, int32_t  x66, cppDeliteArrayint32_t  *x1096) {
for(int32_t i=x50; i<x1; i+=x66) {
int32_t x137 = i;
int32_t  x138 = (int32_t) x137;
int32_t x1144 = x1096->apply(x138);
string  x1145 = string_plus( convert_to_string< int32_t >(x1144), convert_to_string< string >(string(" ")));
std::cout << x1145;
}

}

/**********/

