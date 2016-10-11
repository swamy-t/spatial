#include "cpphelperFuncs.h"
void  kernel_x1251(resourceInfo_t *resourceInfo,int32_t  x49, int32_t  x2, int32_t  x71, cppDeliteArrayint32_t  *x1246) {
for(int32_t i=x49; i<x2; i+=x71) {
int32_t x150 = i;
int32_t  x151 = (int32_t) x150;
int32_t x1247 = x1246->apply(x151);
string  x1248 = string_plus( convert_to_string< int32_t >(x1247), convert_to_string< string >(string(" ")));
std::cout << x1248;
}

}

/**********/

