#include "cpphelperFuncs.h"
void  kernel_x3752(resourceInfo_t *resourceInfo,int32_t  x197, int32_t  x3747, int32_t  x218, cppDeliteArrayint32_t  *x3745) {
for(int32_t i=x197; i<x3747; i+=x218) {
int32_t x797 = i;
int32_t  x798 = (int32_t) x797;
int32_t x3748 = x3745->apply(x798);
string  x3749 = string_plus( convert_to_string< int32_t >(x3748), convert_to_string< string >(string(" ")));
std::cout << x3749;
}

}

/**********/

