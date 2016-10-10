#include "cpphelperFuncs.h"
void  kernel_x1360(resourceInfo_t *resourceInfo,int32_t  x49, int32_t  x1355, int32_t  x62, cppDeliteArrayint32_t  *x1307) {
for(int32_t i=x49; i<x1355; i+=x62) {
int32_t x189 = i;
int32_t  x190 = (int32_t) x189;
int32_t x1356 = x1307->apply(x190);
string  x1357 = string_plus( convert_to_string< int32_t >(x1356), convert_to_string< string >(string(" ")));
std::cout << x1357;
}

}

/**********/

