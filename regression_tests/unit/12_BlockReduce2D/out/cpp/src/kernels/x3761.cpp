#include "cpphelperFuncs.h"
void  kernel_x3761(resourceInfo_t *resourceInfo,int32_t  x197, int32_t  x3756, int32_t  x218, cppDeliteArrayint32_t  *x3514) {
for(int32_t i=x197; i<x3756; i+=x218) {
int32_t x809 = i;
int32_t  x810 = (int32_t) x809;
int32_t x3757 = x3514->apply(x810);
string  x3758 = string_plus( convert_to_string< int32_t >(x3757), convert_to_string< string >(string(" ")));
std::cout << x3758;
}

}

/**********/

