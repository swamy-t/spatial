#include "cpphelperFuncs.h"
void  kernel_x2889(resourceInfo_t *resourceInfo,int32_t  x102, int32_t  x2810, int32_t  x116, cppDeliteArrayint32_t  *x2610) {
for(int32_t i=x102; i<x2810; i+=x116) {
int32_t x446 = i;
int32_t  x447 = (int32_t) x446;
int32_t x2811 = x2610->apply(x447);
string  x2812 = string_plus( convert_to_string< int32_t >(x2811), convert_to_string< string >(string(" ")));
std::cout << x2812;
}

}

/**********/

