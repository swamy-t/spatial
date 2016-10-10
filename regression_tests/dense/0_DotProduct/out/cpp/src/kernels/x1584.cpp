#include "cpphelperFuncs.h"
void  kernel_x1584(resourceInfo_t *resourceInfo,int32_t  x98, int32_t  x1579, int32_t  x101, cppDeliteArrayint32_t  *x1567) {
for(int32_t i=x98; i<x1579; i+=x101) {
int32_t x115 = i;
int32_t  x116 = (int32_t) x115;
int32_t x1580 = x1567->apply(x116);
string  x1581 = string_plus( convert_to_string< int32_t >(x1580), convert_to_string< string >(string(" ")));
std::cout << x1581;
}

}

/**********/

