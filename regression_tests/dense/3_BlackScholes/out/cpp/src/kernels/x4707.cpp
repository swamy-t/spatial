#include "cpphelperFuncs.h"
void  kernel_x4707(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x4702, int32_t  x319, cppDeliteArrayfloat  *x4568) {
for(int32_t i=x3; i<x4702; i+=x319) {
int32_t x670 = i;
int32_t  x671 = (int32_t) x670;
float x4703 = x4568->apply(x671);
string  x4704 = string_plus( convert_to_string< float >(x4703), convert_to_string< string >(string(" ")));
std::cout << x4704;
}

}

/**********/

