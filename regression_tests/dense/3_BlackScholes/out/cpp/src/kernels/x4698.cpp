#include "cpphelperFuncs.h"
void  kernel_x4698(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x656, int32_t  x319, cppDeliteArrayfloat  *x4693) {
for(int32_t i=x3; i<x656; i+=x319) {
int32_t x658 = i;
int32_t  x659 = (int32_t) x658;
float x4694 = x4693->apply(x659);
string  x4695 = string_plus( convert_to_string< float >(x4694), convert_to_string< string >(string(" ")));
std::cout << x4695;
}

}

/**********/

