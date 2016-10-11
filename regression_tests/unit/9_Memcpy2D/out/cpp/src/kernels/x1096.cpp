#include "cpphelperFuncs.h"
void  kernel_x1096(resourceInfo_t *resourceInfo,int32_t  x54, int32_t  x131, int32_t  x73, cppDeliteArrayint32_t  *x1041) {
for(int32_t i=x54; i<x131; i+=x73) {
int32_t x133 = i;
int32_t  x134 = (int32_t) x133;
int32_t x1092 = x1041->apply(x134);
string  x1093 = string_plus( convert_to_string< int32_t >(x1092), convert_to_string< string >(string(" ")));
std::cout << x1093;
}

}

/**********/

