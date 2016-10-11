#include "cpphelperFuncs.h"
void  kernel_x4852(resourceInfo_t *resourceInfo,int32_t  x286, int32_t  x4847, int32_t  x303, cppDeliteArrayint32_t  *x4491) {
for(int32_t i=x286; i<x4847; i+=x303) {
int32_t x853 = i;
int32_t  x854 = (int32_t) x853;
int32_t x4848 = x4491->apply(x854);
string  x4849 = string_plus( convert_to_string< int32_t >(x4848), convert_to_string< string >(string(" ")));
std::cout << x4849;
}

}

/**********/

