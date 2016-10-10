#include "cpphelperFuncs.h"
void  kernel_x1141(resourceInfo_t *resourceInfo,int32_t  x50, int32_t  x1, int32_t  x66, cppDeliteArrayint32_t  *x1136) {
for(int32_t i=x50; i<x1; i+=x66) {
int32_t x128 = i;
int32_t  x129 = (int32_t) x128;
int32_t x1137 = x1136->apply(x129);
string  x1138 = string_plus( convert_to_string< int32_t >(x1137), convert_to_string< string >(string(" ")));
std::cout << x1138;
}

}

/**********/

