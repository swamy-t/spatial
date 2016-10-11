#include "cpphelperFuncs.h"
void  kernel_x1575(resourceInfo_t *resourceInfo,int32_t  x98, int32_t  x1570, int32_t  x101, cppDeliteArrayint32_t  *x1528) {
for(int32_t i=x98; i<x1570; i+=x101) {
int32_t x103 = i;
int32_t  x104 = (int32_t) x103;
int32_t x1571 = x1528->apply(x104);
string  x1572 = string_plus( convert_to_string< int32_t >(x1571), convert_to_string< string >(string(" ")));
std::cout << x1572;
}

}

/**********/

