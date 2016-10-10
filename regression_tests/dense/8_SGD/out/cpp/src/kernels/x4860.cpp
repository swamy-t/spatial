#include "cpphelperFuncs.h"
void  kernel_x4860(resourceInfo_t *resourceInfo,int32_t  x286, int32_t  x4855, int32_t  x303, cppDeliteArrayint32_t  *x4493) {
for(int32_t i=x286; i<x4855; i+=x303) {
int32_t x864 = i;
int32_t  x865 = (int32_t) x864;
int32_t x4856 = x4493->apply(x865);
string  x4857 = string_plus( convert_to_string< int32_t >(x4856), convert_to_string< string >(string(" ")));
std::cout << x4857;
}

}

/**********/

