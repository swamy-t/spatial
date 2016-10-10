#include "cpphelperFuncs.h"
void  kernel_x2886(resourceInfo_t *resourceInfo,int32_t  x102, int32_t  x2881, int32_t  x116, cppDeliteArrayint32_t  *x2879) {
for(int32_t i=x102; i<x2881; i+=x116) {
int32_t x434 = i;
int32_t  x435 = (int32_t) x434;
int32_t x2882 = x2879->apply(x435);
string  x2883 = string_plus( convert_to_string< int32_t >(x2882), convert_to_string< string >(string(" ")));
std::cout << x2883;
}

}

/**********/

