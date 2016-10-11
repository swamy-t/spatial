#include "cpphelperFuncs.h"
void  kernel_x3235(resourceInfo_t *resourceInfo,int32_t  x105, int32_t  x3230, int32_t  x119, cppDeliteArrayint32_t  *x3228) {
for(int32_t i=x105; i<x3230; i+=x119) {
int32_t x491 = i;
int32_t  x492 = (int32_t) x491;
int32_t x3231 = x3228->apply(x492);
string  x3232 = string_plus( convert_to_string< int32_t >(x3231), convert_to_string< string >(string(" ")));
std::cout << x3232;
}

}

/**********/

