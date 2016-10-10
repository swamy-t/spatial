#include "cpphelperFuncs.h"
void  kernel_x1351(resourceInfo_t *resourceInfo,int32_t  x49, int32_t  x175, int32_t  x62, cppDeliteArrayint32_t  *x1346) {
for(int32_t i=x49; i<x175; i+=x62) {
int32_t x177 = i;
int32_t  x178 = (int32_t) x177;
int32_t x1347 = x1346->apply(x178);
string  x1348 = string_plus( convert_to_string< int32_t >(x1347), convert_to_string< string >(string(" ")));
std::cout << x1348;
}

}

/**********/

