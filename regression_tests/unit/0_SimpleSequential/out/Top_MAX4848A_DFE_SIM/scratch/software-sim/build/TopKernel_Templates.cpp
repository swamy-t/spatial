#include "stdsimheader.h"
//#include "TopKernel.h"
//#include "HWTypes.h"
//#include "KernelManagerBlockSync.h"

using namespace maxcompilersim;

// Templated Types used in the kernel
template class HWOffsetFix<32,0,TWOSCOMPLEMENT>;
template class HWRawBits<1>;
template class HWRawBits<40>;
template class HWRawBits<63>;
template class HWOffsetFix<48,0,UNSIGNED>;
template class HWOffsetFix<49,0,UNSIGNED>;
template class HWRawBits<8>;
template class HWOffsetFix<33,0,UNSIGNED>;
template class HWRawBits<48>;
template class HWRawBits<15>;
template class HWOffsetFix<32,0,UNSIGNED>;
template class HWOffsetFix<2,0,UNSIGNED>;
template class HWRawBits<64>;
template class HWRawBits<5>;
template class HWOffsetFix<1,0,UNSIGNED>;
template class HWRawBits<32>;
template class HWRawBits<2>;
template class HWOffsetFix<64,0,UNSIGNED>;
template class HWOffsetFix<8,0,UNSIGNED>;
template class HWOffsetFix<5,0,UNSIGNED>;
// add. templates from the default formatter 


// Templated Methods/Functions
template HWOffsetFix<1,0,UNSIGNED>and_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a, const HWOffsetFix<1,0,UNSIGNED> &b );
template HWRawBits<2> slice<0,2>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a);
template void KernelManagerBlockSync::setMappedRegValue< HWOffsetFix<64,0,UNSIGNED> >(const std::string &name, const HWOffsetFix<64,0,UNSIGNED> & value);
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<48,0,UNSIGNED> &a, const HWOffsetFix<48,0,UNSIGNED> &b );
template HWOffsetFix<32,0,UNSIGNED> cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<33,0,UNSIGNED> &a);
template HWOffsetFix<48,0,UNSIGNED> cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<49,0,UNSIGNED> &a);
template HWRawBits<2> cast_fixed2bits<>(const HWOffsetFix<2,0,UNSIGNED> &a);
template void KernelManagerBlockSync::writeOutput< HWRawBits<64> >(const t_port_number port_number, const HWRawBits<64> &value);
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<32,0,UNSIGNED> &a, const HWOffsetFix<32,0,UNSIGNED> &b );
template HWOffsetFix<1,0,UNSIGNED>not_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a );
template HWRawBits<48> cat<>(const HWRawBits<8> &a, const HWRawBits<40> &b);
template void KernelManagerBlockSync::setMappedRegValue< HWOffsetFix<32,0,TWOSCOMPLEMENT> >(const std::string &name, const HWOffsetFix<32,0,TWOSCOMPLEMENT> & value);
template HWRawBits<5> slice<2,5>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a);
template HWOffsetFix<49,0,UNSIGNED>add_fixed <49,0,UNSIGNED,TRUNCATE,49,0,UNSIGNED,49,0,UNSIGNED, false>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b );
template HWRawBits<1> cast_fixed2bits<>(const HWOffsetFix<1,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<1,0,UNSIGNED> >(const std::string &name);
template HWOffsetFix<5,0,UNSIGNED> cast_bits2fixed<5,0,UNSIGNED>(const HWRawBits<5> &a);
template HWRawBits<63> cat<>(const HWRawBits<15> &a, const HWRawBits<48> &b);
template HWRawBits<8> cast_fixed2bits<>(const HWOffsetFix<8,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<33,0,UNSIGNED> &a, const HWOffsetFix<33,0,UNSIGNED> &b );
template HWOffsetFix<48,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name);
template HWRawBits<64> cat<>(const HWRawBits<1> &a, const HWRawBits<63> &b);
template HWOffsetFix<33,0,UNSIGNED>add_fixed <33,0,UNSIGNED,TRUNCATE,33,0,UNSIGNED,33,0,UNSIGNED, false>(const HWOffsetFix<33,0,UNSIGNED> &a, const HWOffsetFix<33,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWRawBits<40> cat<>(const HWRawBits<8> &a, const HWRawBits<32> &b);
template HWOffsetFix<2,0,UNSIGNED> cast_bits2fixed<2,0,UNSIGNED>(const HWRawBits<2> &a);
template void KernelManagerBlockSync::writeOutput< HWOffsetFix<32,0,UNSIGNED> >(const t_port_number port_number, const HWOffsetFix<32,0,UNSIGNED> &value);
template HWOffsetFix<32,0,TWOSCOMPLEMENT>mul_fixed <32,0,TWOSCOMPLEMENT,TONEAR,32,0,TWOSCOMPLEMENT,32,0,TWOSCOMPLEMENT, false>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWOffsetFix<32,0,TWOSCOMPLEMENT> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<32,0,TWOSCOMPLEMENT> >(const std::string &name);
template void KernelManagerBlockSync::setMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name, const HWOffsetFix<48,0,UNSIGNED> & value);


// Additional Code
std::string TopKernel::format_string_TopKernel_1 (const char* _format_arg_format_string)
{return ( boost::format(_format_arg_format_string)).str();}
std::string TopKernel::format_string_TopKernel_2 (const char* _format_arg_format_string)
{return ( boost::format(_format_arg_format_string)).str();}
std::string TopKernel::format_string_TopKernel_3 (const char* _format_arg_format_string)
{return ( boost::format(_format_arg_format_string)).str();}
std::string TopKernel::format_string_TopKernel_4 (const char* _format_arg_format_string)
{return ( boost::format(_format_arg_format_string)).str();}

