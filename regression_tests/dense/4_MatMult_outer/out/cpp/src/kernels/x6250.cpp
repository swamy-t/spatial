#include "cpphelperFuncs.h"
void  kernel_x6250(resourceInfo_t *resourceInfo,int32_t  x189, int32_t  x6245, int32_t  x11, cppDeliteArrayint32_t  *x6224) {
for(int32_t i=x189; i<x6245; i+=x11) {
int32_t x998 = i;
int32_t  x999 = (int32_t) x998;
int32_t x6246 = x6224->apply(x999);
string  x6247 = string_plus( convert_to_string< int32_t >(x6246), convert_to_string< string >(string(" ")));
std::cout << x6247;
}

}

/**********/

