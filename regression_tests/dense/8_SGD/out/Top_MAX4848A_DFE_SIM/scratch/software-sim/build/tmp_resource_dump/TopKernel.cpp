#include "stdsimheader.h"
#include "TopKernel.h"

namespace maxcompilersim {

TopKernel::TopKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 125, 2, 0, 0, "",1)
, c_hw_fix_17_0_uns_bits((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00010l))))
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000060l))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000001l))))
, c_hw_fix_32_0_sgn_bits_1((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000001l))))
, c_hw_fix_32_0_uns_bits_1((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000060l))))
, c_hw_fix_17_0_uns_bits_1((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00000l))))
, c_hw_fix_17_0_uns_bits_2((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00001l))))
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_16_0_uns_bits((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x000fl))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_fix_9_0_uns_bits((HWOffsetFix<9,0,UNSIGNED>(varint_u<9>(0x03al))))
, c_hw_fix_10_0_uns_bits((HWOffsetFix<10,0,UNSIGNED>(varint_u<10>(0x000l))))
, c_hw_fix_10_0_uns_bits_1((HWOffsetFix<10,0,UNSIGNED>(varint_u<10>(0x001l))))
, c_hw_fix_32_0_sgn_undef((HWOffsetFix<32,0,TWOSCOMPLEMENT>()))
, c_hw_fix_9_0_uns_bits_1((HWOffsetFix<9,0,UNSIGNED>(varint_u<9>(0x039l))))
, c_hw_fix_17_0_uns_bits_3((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00002l))))
, c_hw_fix_16_0_uns_bits_1((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x0001l))))
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000060l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_2((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_16_0_uns_bits_2((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x0000l))))
, c_hw_bit_1_bits((HWRawBits<1>(varint_u<1>(0x0l))))
, c_hw_bit_15_bits((HWRawBits<15>(varint_u<15>(0x0001l))))
, c_hw_fix_8_0_uns_bits((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x01l))))
, c_hw_bit_8_bits((HWRawBits<8>(varint_u<8>(0x01l))))
, c_hw_fix_32_0_uns_bits_2((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00100000l))))
, c_hw_fix_2_0_uns_bits((HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(0x0l))))
, c_hw_fix_32_0_sgn_bits_2((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000000l))))
, c_hw_bit_32_bits((HWRawBits<32>(varint_u<32>(0x00200000l))))
, c_hw_bit_32_bits_1((HWRawBits<32>(varint_u<32>(0x00300000l))))
, c_hw_fix_7_0_uns_undef((HWOffsetFix<7,0,UNSIGNED>()))
, c_hw_fix_14_0_uns_undef((HWOffsetFix<14,0,UNSIGNED>()))
, c_hw_bit_32_undef((HWRawBits<32>()))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_32_0_uns_bits_3((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000000l))))
, c_hw_fix_8_0_uns_bits_1((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x00l))))
, c_hw_bit_32_bits_2((HWRawBits<32>(varint_u<32>(0x00000000l))))
, c_hw_fix_32_0_uns_bits_4((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000005l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, m_sm_CounterChain4374_sm(getDebugStreams(), 136)
, m_sm_CounterChain4377_sm(getDebugStreams(), 153)
, m_sm_CounterChain4386_sm(getDebugStreams(), 241)
, m_sm_CounterChain4402_sm(getDebugStreams(), 317)
, m_sm_CounterChain4414_sm(getDebugStreams(), 328)
, m_sm_CounterChain4417_sm(getDebugStreams(), 347)
, m_sm_CounterChain4437_sm(getDebugStreams(), 380)
, m_sm_CounterChain4440_sm(getDebugStreams(), 399)
, m_sm_CounterChain4460_sm(getDebugStreams(), 430)
, m_sm_CounterChain4462_sm(getDebugStreams(), 435)
, m_sm_CounterChain4479_sm(getDebugStreams(), 470)
, m_sm_DRAM4323_void4384_inldSM(getDebugStreams(), 185)
, m_sm_DRAM4324_void4400_inldSM(getDebugStreams(), 261)
, m_sm_DRAM4325_void4486_outldSM(getDebugStreams(), 476)
, m_sm_mainSm(getDebugStreams(), 1)
, m_sm_metapipe4396_FixedPoint36450_1(getDebugStreams(), 156)
, m_sm_metapipe4396_FixedPoint36451_2(getDebugStreams(), 164)
, m_sm_metapipe4396_sm(getDebugStreams(), 146)
, m_sm_metapipe4435_FixedPoint36890_1(getDebugStreams(), 331)
, m_sm_metapipe4435_sm(getDebugStreams(), 321)
, m_sm_metapipe4458_FixedPoint37320_1(getDebugStreams(), 383)
, m_sm_metapipe4458_sm(getDebugStreams(), 373)
, m_sm_metapipe4474_sm(getDebugStreams(), 423)
, m_sm_pipe4394_sm(getDebugStreams(), 238)
, m_sm_pipe4408_sm(getDebugStreams(), 314)
, m_sm_pipe4427_sm(getDebugStreams(), 339)
, m_sm_pipe4450_sm(getDebugStreams(), 391)
, m_sm_pipe4472_sm(getDebugStreams(), 432)
, m_sm_pipe4485_sm(getDebugStreams(), 467)
, m_sm_reg4378_0(getDebugStreams(), 4)
, m_sm_reg4378_1(getDebugStreams(), 31)
, m_sm_reg4415_1(getDebugStreams(), 63)
, m_sm_reg4438_1(getDebugStreams(), 90)
, m_sm_seq4476_sm(getDebugStreams(), 129)
, m_sm_void4381_sm(getDebugStreams(), 172)
, m_sm_void4398_sm(getDebugStreams(), 141)
, m_sm_void4410_sm(getDebugStreams(), 253)
, m_sm_void4412_sm(getDebugStreams(), 139)
, m_sm_void4433_sm(getDebugStreams(), 362)
, m_sm_void4456_sm(getDebugStreams(), 414)
, m_sm_void4488_sm(getDebugStreams(), 462)
, m_sm_void4490_sm(getDebugStreams(), 124)
{
  { // Node ID: 927 (NodeConstantRawBits)
    id927out_value = (c_hw_fix_17_0_uns_bits);
  }
  { // Node ID: 121 (NodeConstantRawBits)
    id121out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 238 (NodeStateMachine)
  }
  { // Node ID: 261 (NodeStateMachine)
  }
  { // Node ID: 317 (NodeStateMachine)
  }
  { // Node ID: 314 (NodeStateMachine)
  }
  { // Node ID: 255 (NodeConstantRawBits)
    id255out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 253 (NodeStateMachine)
  }
  { // Node ID: 347 (NodeStateMachine)
  }
  { // Node ID: 339 (NodeStateMachine)
  }
  { // Node ID: 365 (NodeConstantRawBits)
    id365out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 362 (NodeStateMachine)
  }
  { // Node ID: 610 (NodeConstantRawBits)
    id610out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 321 (NodeStateMachine)
  }
  { // Node ID: 399 (NodeStateMachine)
  }
  { // Node ID: 391 (NodeStateMachine)
  }
  { // Node ID: 417 (NodeConstantRawBits)
    id417out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 414 (NodeStateMachine)
  }
  { // Node ID: 614 (NodeConstantRawBits)
    id614out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 373 (NodeStateMachine)
  }
  { // Node ID: 432 (NodeStateMachine)
  }
  { // Node ID: 618 (NodeConstantRawBits)
    id618out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 423 (NodeStateMachine)
  }
  { // Node ID: 470 (NodeStateMachine)
  }
  { // Node ID: 467 (NodeStateMachine)
  }
  { // Node ID: 464 (NodeConstantRawBits)
    id464out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 462 (NodeStateMachine)
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("en", Data(1));
  }
  { // Node ID: 1 (NodeStateMachine)
  }
  { // Node ID: 126 (NodeConstantRawBits)
    id126out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 124 (NodeStateMachine)
  }
  { // Node ID: 2 (NodeInputMappedReg)
    registerMappedRegister("argin4320", Data(32));
  }
  { // Node ID: 129 (NodeStateMachine)
  }
  { // Node ID: 139 (NodeStateMachine)
  }
  { // Node ID: 143 (NodeConstantRawBits)
    id143out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 141 (NodeStateMachine)
  }
  { // Node ID: 623 (NodeConstantRawBits)
    id623out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 146 (NodeStateMachine)
  }
  { // Node ID: 185 (NodeStateMachine)
  }
  { // Node ID: 926 (NodeConstantRawBits)
    id926out_value = (c_hw_fix_16_0_uns_bits);
  }
  { // Node ID: 175 (NodeConstantRawBits)
    id175out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 172 (NodeStateMachine)
  }
  { // Node ID: 241 (NodeStateMachine)
  }
  { // Node ID: 925 (NodeConstantRawBits)
    id925out_value = (c_hw_fix_17_0_uns_bits);
  }
  { // Node ID: 924 (NodeConstantRawBits)
    id924out_value = (c_hw_fix_16_0_uns_bits);
  }
  { // Node ID: 911 (NodeConstantRawBits)
    id911out_value = (c_hw_fix_9_0_uns_bits);
  }
  { // Node ID: 912 (NodeConstantRawBits)
    id912out_value = (c_hw_fix_9_0_uns_bits_1);
  }
  { // Node ID: 435 (NodeStateMachine)
  }
  { // Node ID: 923 (NodeConstantRawBits)
    id923out_value = (c_hw_fix_17_0_uns_bits_3);
  }
  { // Node ID: 476 (NodeStateMachine)
  }
  { // Node ID: 922 (NodeConstantRawBits)
    id922out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 921 (NodeConstantRawBits)
    id921out_value = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 920 (NodeConstantRawBits)
    id920out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 219 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM4323_void4384_in_cmd_force_disabled", Data(1));
  }
  { // Node ID: 624 (NodeConstantRawBits)
    id624out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 629 (NodeConstantRawBits)
    id629out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 206 (NodeConstantRawBits)
    id206out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 634 (NodeConstantRawBits)
    id634out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 919 (NodeConstantRawBits)
    id919out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 537 (NodeConstantRawBits)
    id537out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 536 (NodeConstantRawBits)
    id536out_value = (c_hw_fix_2_0_uns_bits);
  }
  { // Node ID: 5 (NodeConstantRawBits)
    id5out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 7 (NodeConstantRawBits)
    id7out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 9 (NodeConstantRawBits)
    id9out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 11 (NodeConstantRawBits)
    id11out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 13 (NodeConstantRawBits)
    id13out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 15 (NodeConstantRawBits)
    id15out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 6 (NodeConstantRawBits)
    id6out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 8 (NodeConstantRawBits)
    id8out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 10 (NodeConstantRawBits)
    id10out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 12 (NodeConstantRawBits)
    id12out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 14 (NodeConstantRawBits)
    id14out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 16 (NodeConstantRawBits)
    id16out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 4 (NodeStateMachine)
  }
  { // Node ID: 535 (NodeConstantRawBits)
    id535out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 153 (NodeStateMachine)
  }
  { // Node ID: 534 (NodeConstantRawBits)
    id534out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 180 (NodeConstantRawBits)
    id180out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 918 (NodeConstantRawBits)
    id918out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 222 (NodeOutput)
    m_DRAM4323_void4384_in_cmd = registerOutput("DRAM4323_void4384_in_cmd",0 );
  }
  { // Node ID: 917 (NodeConstantRawBits)
    id917out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 295 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM4324_void4400_in_cmd_force_disabled", Data(1));
  }
  { // Node ID: 635 (NodeConstantRawBits)
    id635out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 640 (NodeConstantRawBits)
    id640out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 282 (NodeConstantRawBits)
    id282out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 645 (NodeConstantRawBits)
    id645out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 649 (NodeConstantRawBits)
    id649out_value = (c_hw_bit_32_bits);
  }
  { // Node ID: 298 (NodeOutput)
    m_DRAM4324_void4400_in_cmd = registerOutput("DRAM4324_void4400_in_cmd",1 );
  }
  { // Node ID: 916 (NodeConstantRawBits)
    id916out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 508 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM4325_void4486_out_cmd_force_disabled", Data(1));
  }
  { // Node ID: 650 (NodeConstantRawBits)
    id650out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 655 (NodeConstantRawBits)
    id655out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 495 (NodeConstantRawBits)
    id495out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 660 (NodeConstantRawBits)
    id660out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 664 (NodeConstantRawBits)
    id664out_value = (c_hw_bit_32_bits_1);
  }
  { // Node ID: 511 (NodeOutput)
    m_DRAM4325_void4486_out_cmd = registerOutput("DRAM4325_void4486_out_cmd",2 );
  }
  { // Node ID: 521 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM4325_void4486_out_force_disabled", Data(1));
  }
  { // Node ID: 383 (NodeStateMachine)
  }
  { // Node ID: 380 (NodeStateMachine)
  }
  { // Node ID: 390 (NodeConstantRawBits)
    id390out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 533 (NodeConstantRawBits)
    id533out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 532 (NodeConstantRawBits)
    id532out_value = (c_hw_fix_2_0_uns_bits);
  }
  { // Node ID: 91 (NodeConstantRawBits)
    id91out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 93 (NodeConstantRawBits)
    id93out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 95 (NodeConstantRawBits)
    id95out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 97 (NodeConstantRawBits)
    id97out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 99 (NodeConstantRawBits)
    id99out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 101 (NodeConstantRawBits)
    id101out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 92 (NodeConstantRawBits)
    id92out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 94 (NodeConstantRawBits)
    id94out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 96 (NodeConstantRawBits)
    id96out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 98 (NodeConstantRawBits)
    id98out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 100 (NodeConstantRawBits)
    id100out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 102 (NodeConstantRawBits)
    id102out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 90 (NodeStateMachine)
  }
  { // Node ID: 531 (NodeConstantRawBits)
    id531out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 164 (NodeStateMachine)
  }
  { // Node ID: 156 (NodeStateMachine)
  }
  { // Node ID: 163 (NodeConstantRawBits)
    id163out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 171 (NodeConstantRawBits)
    id171out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 232 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM4323_void4384_in_force_disabled", Data(1));
  }
  { // Node ID: 235 (NodeInput)
     m_DRAM4323_void4384_in =  registerInput("DRAM4323_void4384_in",0,5);
  }
  { // Node ID: 588 (NodeRAM)
    for(int i=0;i<9216;i++)
      (id588sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 331 (NodeStateMachine)
  }
  { // Node ID: 328 (NodeStateMachine)
  }
  { // Node ID: 338 (NodeConstantRawBits)
    id338out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 529 (NodeConstantRawBits)
    id529out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 528 (NodeConstantRawBits)
    id528out_value = (c_hw_fix_2_0_uns_bits);
  }
  { // Node ID: 64 (NodeConstantRawBits)
    id64out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 66 (NodeConstantRawBits)
    id66out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 68 (NodeConstantRawBits)
    id68out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 70 (NodeConstantRawBits)
    id70out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 72 (NodeConstantRawBits)
    id72out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 74 (NodeConstantRawBits)
    id74out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 65 (NodeConstantRawBits)
    id65out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 67 (NodeConstantRawBits)
    id67out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 69 (NodeConstantRawBits)
    id69out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 71 (NodeConstantRawBits)
    id71out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 73 (NodeConstantRawBits)
    id73out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 75 (NodeConstantRawBits)
    id75out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 63 (NodeStateMachine)
  }
  { // Node ID: 527 (NodeConstantRawBits)
    id527out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 587 (NodeRAM)
    for(int i=0;i<9216;i++)
      (id587sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 591 (NodeRAM)
    for(int i=0;i<96;i++)
      (id591sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 526 (NodeConstantRawBits)
    id526out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 360 (NodeConstantRawBits)
    id360out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 308 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM4324_void4400_in_force_disabled", Data(1));
  }
  { // Node ID: 311 (NodeInput)
     m_DRAM4324_void4400_in =  registerInput("DRAM4324_void4400_in",1,5);
  }
  { // Node ID: 589 (NodeRAM)
    for(int i=0;i<96;i++)
      (id589sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 594 (NodeRAM)
    for(int i=0;i<96;i++)
      (id594sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 530 (NodeConstantRawBits)
    id530out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 412 (NodeConstantRawBits)
    id412out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 3 (NodeInputMappedReg)
    registerMappedRegister("argin4319", Data(32));
  }
  { // Node ID: 590 (NodeRAM)
    for(int i=0;i<96;i++)
      (id590sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 592 (NodeRAM)
    for(int i=0;i<96;i++)
      (id592sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 120 (NodeConstantRawBits)
    id120out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 430 (NodeStateMachine)
  }
  { // Node ID: 593 (NodeRAM)
    for(int i=0;i<96;i++)
      (id593sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 524 (NodeOutput)
    m_DRAM4325_void4486_out = registerOutput("DRAM4325_void4486_out",3 );
  }
  { // Node ID: 915 (NodeConstantRawBits)
    id915out_value = (c_hw_fix_32_0_uns_bits_3);
  }
  { // Node ID: 567 (NodeInputMappedReg)
    registerMappedRegister("io_intrCmd_force_disabled", Data(1));
  }
  { // Node ID: 669 (NodeConstantRawBits)
    id669out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 671 (NodeConstantRawBits)
    id671out_value = (c_hw_fix_8_0_uns_bits_1);
  }
  { // Node ID: 673 (NodeConstantRawBits)
    id673out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 674 (NodeConstantRawBits)
    id674out_value = (c_hw_bit_32_bits_2);
  }
  { // Node ID: 570 (NodeOutput)
    m_intrCmd = registerOutput("intrCmd",4 );
  }
  { // Node ID: 580 (NodeConstantRawBits)
    id580out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 581 (NodeOutputMappedReg)
    registerMappedRegister("cycles", Data(64), false);
  }
  { // Node ID: 583 (NodeInputMappedReg)
    registerMappedRegister("io_intrStream_force_disabled", Data(1));
  }
  { // Node ID: 582 (NodeConstantRawBits)
    id582out_value = (c_hw_fix_32_0_uns_bits_4);
  }
  { // Node ID: 586 (NodeOutput)
    m_intrStream = registerOutput("intrStream",5 );
  }
  { // Node ID: 599 (NodeConstantRawBits)
    id599out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 914 (NodeConstantRawBits)
    id914out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 596 (NodeConstantRawBits)
    id596out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 600 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 913 (NodeConstantRawBits)
    id913out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 602 (NodeConstantRawBits)
    id602out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 605 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void TopKernel::resetComputation() {
  resetComputationAfterFlush();
}

void TopKernel::resetComputationAfterFlush() {
  { // Node ID: 238 (NodeStateMachine)

    m_sm_pipe4394_sm.reset();
  }
  { // Node ID: 261 (NodeStateMachine)

    m_sm_DRAM4324_void4400_inldSM.reset();
  }
  { // Node ID: 317 (NodeStateMachine)

    m_sm_CounterChain4402_sm.reset();
  }
  { // Node ID: 314 (NodeStateMachine)

    m_sm_pipe4408_sm.reset();
  }
  { // Node ID: 253 (NodeStateMachine)

    m_sm_void4410_sm.reset();
  }
  { // Node ID: 347 (NodeStateMachine)

    m_sm_CounterChain4417_sm.reset();
  }
  { // Node ID: 339 (NodeStateMachine)

    m_sm_pipe4427_sm.reset();
  }
  { // Node ID: 362 (NodeStateMachine)

    m_sm_void4433_sm.reset();
  }
  { // Node ID: 321 (NodeStateMachine)

    m_sm_metapipe4435_sm.reset();
  }
  { // Node ID: 399 (NodeStateMachine)

    m_sm_CounterChain4440_sm.reset();
  }
  { // Node ID: 391 (NodeStateMachine)

    m_sm_pipe4450_sm.reset();
  }
  { // Node ID: 414 (NodeStateMachine)

    m_sm_void4456_sm.reset();
  }
  { // Node ID: 373 (NodeStateMachine)

    m_sm_metapipe4458_sm.reset();
  }
  { // Node ID: 432 (NodeStateMachine)

    m_sm_pipe4472_sm.reset();
  }
  { // Node ID: 423 (NodeStateMachine)

    m_sm_metapipe4474_sm.reset();
  }
  { // Node ID: 470 (NodeStateMachine)

    m_sm_CounterChain4479_sm.reset();
  }
  { // Node ID: 467 (NodeStateMachine)

    m_sm_pipe4485_sm.reset();
  }
  { // Node ID: 462 (NodeStateMachine)

    m_sm_void4488_sm.reset();
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_sm_en = id0out_en;

    m_sm_mainSm.reset();
  }
  { // Node ID: 124 (NodeStateMachine)

    m_sm_void4490_sm.reset();
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin4320 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin4320");
  }
  { // Node ID: 129 (NodeStateMachine)

    m_sm_seq4476_sm.reset();
  }
  { // Node ID: 139 (NodeStateMachine)

    m_sm_void4412_sm.reset();
  }
  { // Node ID: 141 (NodeStateMachine)

    m_sm_void4398_sm.reset();
  }
  { // Node ID: 146 (NodeStateMachine)

    m_sm_metapipe4396_sm.reset();
  }
  { // Node ID: 185 (NodeStateMachine)

    m_sm_DRAM4323_void4384_inldSM.reset();
  }
  { // Node ID: 195 (NodeCounterV1)

    (id195st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 172 (NodeStateMachine)

    m_sm_void4381_sm.reset();
  }
  { // Node ID: 754 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id754out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 755 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id755out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 801 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id801out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 802 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id802out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 756 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id756out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 241 (NodeStateMachine)

    m_sm_CounterChain4386_sm.reset();
  }
  { // Node ID: 757 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id757out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 758 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id758out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 759 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id759out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 800 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id800out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 760 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id760out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 271 (NodeCounterV1)

    (id271st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 761 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id761out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 762 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id762out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 763 (NodeFIFO)

    for(int i=0; i<63; i++)
    {
      id763out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 764 (NodeFIFO)

    for(int i=0; i<62; i++)
    {
      id764out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 765 (NodeFIFO)

    for(int i=0; i<62; i++)
    {
      id765out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 766 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id766out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 767 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id767out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 768 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id768out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 343 (NodeCounterV1)

    (id343st_count) = (c_hw_fix_10_0_uns_bits);
  }
  { // Node ID: 769 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id769out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 838 (NodeFIFO)

    for(int i=0; i<59; i++)
    {
      id838out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 895 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id895out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 896 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id896out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 771 (NodeFIFO)

    for(int i=0; i<60; i++)
    {
      id771out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 772 (NodeFIFO)

    for(int i=0; i<60; i++)
    {
      id772out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 773 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id773out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 774 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id774out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 775 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id775out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 776 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id776out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 395 (NodeCounterV1)

    (id395st_count) = (c_hw_fix_10_0_uns_bits);
  }
  { // Node ID: 777 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id777out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 778 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id778out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 779 (NodeFIFO)

    for(int i=0; i<60; i++)
    {
      id779out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 780 (NodeFIFO)

    for(int i=0; i<59; i++)
    {
      id780out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 781 (NodeFIFO)

    for(int i=0; i<59; i++)
    {
      id781out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 782 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id782out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 783 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id783out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 784 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id784out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 785 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id785out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 786 (NodeFIFO)

    for(int i=0; i<22; i++)
    {
      id786out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 435 (NodeStateMachine)

    m_sm_CounterChain4462_sm.reset();
  }
  { // Node ID: 787 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id787out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 788 (NodeFIFO)

    for(int i=0; i<22; i++)
    {
      id788out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 789 (NodeFIFO)

    for(int i=0; i<22; i++)
    {
      id789out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 790 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id790out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 791 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id791out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 792 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id792out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 793 (NodeFIFO)

    for(int i=0; i<62; i++)
    {
      id793out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 794 (NodeFIFO)

    for(int i=0; i<61; i++)
    {
      id794out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 795 (NodeFIFO)

    for(int i=0; i<61; i++)
    {
      id795out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 476 (NodeStateMachine)

    m_sm_DRAM4325_void4486_outldSM.reset();
  }
  { // Node ID: 485 (NodeCounterV1)

    (id485st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 796 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id796out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 797 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id797out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 547 (NodeCounterV1)

    (id547st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 798 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id798out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 799 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id799out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 803 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id803out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 219 (NodeInputMappedReg)
    id219out_io_DRAM4323_void4384_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM4323_void4384_in_cmd_force_disabled");
  }
  { // Node ID: 809 (NodeFIFO)

    for(int i=0; i<40; i++)
    {
      id809out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 4 (NodeStateMachine)

    m_sm_reg4378_0.reset();
  }
  { // Node ID: 808 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id808out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 153 (NodeStateMachine)

    m_sm_CounterChain4377_sm.reset();
  }
  { // Node ID: 21 (NodeHold)

    (id21st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id21out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 26 (NodeHold)

    (id26st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id26out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 810 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id810out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 295 (NodeInputMappedReg)
    id295out_io_DRAM4324_void4400_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM4324_void4400_in_cmd_force_disabled");
  }
  { // Node ID: 811 (NodeFIFO)

    for(int i=0; i<43; i++)
    {
      id811out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 812 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id812out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 508 (NodeInputMappedReg)
    id508out_io_DRAM4325_void4486_out_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM4325_void4486_out_cmd_force_disabled");
  }
  { // Node ID: 521 (NodeInputMappedReg)
    id521out_io_DRAM4325_void4486_out_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM4325_void4486_out_force_disabled");
  }
  { // Node ID: 889 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id889out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 875 (NodeFIFO)

    for(int i=0; i<41; i++)
    {
      id875out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 888 (NodeFIFO)

    for(int i=0; i<21; i++)
    {
      id888out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 815 (NodeFIFO)

    for(int i=0; i<60; i++)
    {
      id815out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 383 (NodeStateMachine)

    m_sm_metapipe4458_FixedPoint37320_1.reset();
  }
  { // Node ID: 821 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id821out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 903 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id903out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 819 (NodeFIFO)

    for(int i=0; i<62; i++)
    {
      id819out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 380 (NodeStateMachine)

    m_sm_CounterChain4437_sm.reset();
  }
  { // Node ID: 388 (NodeHold)

    (id388st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id388out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 386 (NodeHold)

    (id386st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id386out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 876 (NodeFIFO)

    for(int i=0; i<18; i++)
    {
      id876out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 904 (NodeFIFO)

    for(int i=0; i<14; i++)
    {
      id904out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 905 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id905out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 906 (NodeFIFO)

    for(int i=0; i<16; i++)
    {
      id906out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 907 (NodeFIFO)

    for(int i=0; i<17; i++)
    {
      id907out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 908 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id908out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 909 (NodeFIFO)

    for(int i=0; i<73; i++)
    {
      id909out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 90 (NodeStateMachine)

    m_sm_reg4438_1.reset();
  }
  { // Node ID: 872 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id872out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 164 (NodeStateMachine)

    m_sm_metapipe4396_FixedPoint36451_2.reset();
  }
  { // Node ID: 833 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id833out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 156 (NodeStateMachine)

    m_sm_metapipe4396_FixedPoint36450_1.reset();
  }
  { // Node ID: 831 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id831out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 829 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id829out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 161 (NodeHold)

    (id161st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id161out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 159 (NodeHold)

    (id159st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id159out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 169 (NodeHold)

    (id169st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id169out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 167 (NodeHold)

    (id167st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id167out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 835 (NodeFIFO)

    for(int i=0; i<59; i++)
    {
      id835out_output[i] = (c_hw_fix_14_0_uns_undef);
    }
  }
  { // Node ID: 834 (NodeFIFO)

    for(int i=0; i<55; i++)
    {
      id834out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 232 (NodeInputMappedReg)
    id232out_io_DRAM4323_void4384_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM4323_void4384_in_force_disabled");
  }
  { // Node ID: 235 (NodeInput)

    (id235st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id235st_last_read_value) = (c_hw_bit_32_undef);
  }
  { // Node ID: 893 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id893out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 867 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id867out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 837 (NodeFIFO)

    for(int i=0; i<59; i++)
    {
      id837out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 331 (NodeStateMachine)

    m_sm_metapipe4435_FixedPoint36890_1.reset();
  }
  { // Node ID: 843 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id843out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 841 (NodeFIFO)

    for(int i=0; i<61; i++)
    {
      id841out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 328 (NodeStateMachine)

    m_sm_CounterChain4414_sm.reset();
  }
  { // Node ID: 336 (NodeHold)

    (id336st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id336out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 334 (NodeHold)

    (id334st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id334out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 864 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id864out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 897 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id897out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 898 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id898out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 899 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id899out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 900 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id900out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 901 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id901out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 902 (NodeFIFO)

    for(int i=0; i<65; i++)
    {
      id902out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 63 (NodeStateMachine)

    m_sm_reg4415_1.reset();
  }
  { // Node ID: 858 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id858out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 849 (NodeFIFO)

    for(int i=0; i<59; i++)
    {
      id849out_output[i] = (c_hw_fix_14_0_uns_undef);
    }
  }
  { // Node ID: 853 (NodeFIFO)

    for(int i=0; i<21; i++)
    {
      id853out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 852 (NodeFIFO)

    for(int i=0; i<61; i++)
    {
      id852out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 854 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id854out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 856 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id856out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 359 (NodeAccumulator)

    (id359st_hold_reg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id359out_accumulate[i] = (id359st_hold_reg);
    }
  }
  { // Node ID: 80 (NodeHold)

    (id80st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id80out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 85 (NodeHold)

    (id85st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id85out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 859 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id859out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 308 (NodeInputMappedReg)
    id308out_io_DRAM4324_void4400_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM4324_void4400_in_force_disabled");
  }
  { // Node ID: 311 (NodeInput)

    (id311st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id311st_last_read_value) = (c_hw_bit_32_undef);
  }
  { // Node ID: 894 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id894out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 861 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id861out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 865 (NodeFIFO)

    for(int i=0; i<67; i++)
    {
      id865out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 866 (NodeFIFO)

    for(int i=0; i<11; i++)
    {
      id866out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 870 (NodeFIFO)

    for(int i=0; i<15; i++)
    {
      id870out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 411 (NodeAccumulator)

    (id411st_hold_reg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id411out_accumulate[i] = (id411st_hold_reg);
    }
  }
  { // Node ID: 107 (NodeHold)

    (id107st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id107out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 112 (NodeHold)

    (id112st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id112out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_argin4319 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin4319");
  }
  { // Node ID: 877 (NodeFIFO)

    for(int i=0; i<76; i++)
    {
      id877out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 878 (NodeFIFO)

    for(int i=0; i<18; i++)
    {
      id878out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 882 (NodeFIFO)

    for(int i=0; i<21; i++)
    {
      id882out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 885 (NodeFIFO)

    for(int i=0; i<18; i++)
    {
      id885out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 883 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id883out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 430 (NodeStateMachine)

    m_sm_CounterChain4460_sm.reset();
  }
  { // Node ID: 884 (NodeFIFO)

    for(int i=0; i<22; i++)
    {
      id884out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 886 (NodeFIFO)

    for(int i=0; i<58; i++)
    {
      id886out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 890 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id890out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 567 (NodeInputMappedReg)
    id567out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 910 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id910out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 583 (NodeInputMappedReg)
    id583out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 597 (NodeCounterV1)

    (id597st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 603 (NodeCounterV1)

    (id603st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 605 (NodeInputMappedReg)
    id605out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin4320 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin4320");
  }
  { // Node ID: 219 (NodeInputMappedReg)
    id219out_io_DRAM4323_void4384_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM4323_void4384_in_cmd_force_disabled");
  }
  { // Node ID: 295 (NodeInputMappedReg)
    id295out_io_DRAM4324_void4400_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM4324_void4400_in_cmd_force_disabled");
  }
  { // Node ID: 508 (NodeInputMappedReg)
    id508out_io_DRAM4325_void4486_out_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM4325_void4486_out_cmd_force_disabled");
  }
  { // Node ID: 521 (NodeInputMappedReg)
    id521out_io_DRAM4325_void4486_out_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM4325_void4486_out_force_disabled");
  }
  { // Node ID: 232 (NodeInputMappedReg)
    id232out_io_DRAM4323_void4384_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM4323_void4384_in_force_disabled");
  }
  { // Node ID: 308 (NodeInputMappedReg)
    id308out_io_DRAM4324_void4400_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM4324_void4400_in_force_disabled");
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_argin4319 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin4319");
  }
  { // Node ID: 567 (NodeInputMappedReg)
    id567out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 583 (NodeInputMappedReg)
    id583out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 605 (NodeInputMappedReg)
    id605out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::preExecute() {
  { // Node ID: 235 (NodeInput)
    if(((needsToReadInput(m_DRAM4323_void4384_in))&(((getFlushLevel())<((61l)+(5)))|(!(isFlushingActive()))))) {
      (id235st_last_read_value) = (readInput<HWRawBits<32> >(m_DRAM4323_void4384_in));
    }
    id235out_data = (id235st_last_read_value);
  }
  { // Node ID: 311 (NodeInput)
    if(((needsToReadInput(m_DRAM4324_void4400_in))&(((getFlushLevel())<((66l)+(5)))|(!(isFlushingActive()))))) {
      (id311st_last_read_value) = (readInput<HWRawBits<32> >(m_DRAM4324_void4400_in));
    }
    id311out_data = (id311st_last_read_value);
  }
}

void TopKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "TopKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  TopKernelBlock1Vars blk1 = execute0();
  execute1(blk1);
}

int TopKernel::getFlushLevelStart() {
  return ((1l)+(3l));
}

}
