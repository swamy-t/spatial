#include "cpphelperFuncs.h"
void  kernel_x1331(resourceInfo_t *resourceInfo,int32_t  x53, int32_t  x3, int32_t  x72, cppDeliteArrayint32_t  *x1326) {
for(int32_t i=x53; i<x3; i+=x72) {
int32_t x163 = i;
int32_t  x164 = (int32_t) x163;
int32_t x1327 = x1326->apply(x164);
string  x1328 = string_plus( convert_to_string< int32_t >(x1327), convert_to_string< string >(string(" ")));
std::cout << x1328;
}

}

/**********/

