#include "stdsimheader.h"
#include "TopKernel.h"

namespace maxcompilersim {

TopKernel::TopKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 71, 2, 0, 0, "",1)
, c_hw_fix_17_0_uns_bits((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00010l))))
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000060l))))
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000060l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_2((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000001l))))
, c_hw_fix_32_0_uns_bits_1((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000060l))))
, c_hw_fix_17_0_uns_bits_1((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00000l))))
, c_hw_fix_17_0_uns_bits_2((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00001l))))
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_16_0_uns_bits((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x000fl))))
, c_hw_fix_32_0_sgn_bits_1((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000001l))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_fix_17_0_uns_bits_3((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00002l))))
, c_hw_fix_16_0_uns_bits_1((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x0001l))))
, c_hw_fix_16_0_uns_bits_2((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x0000l))))
, c_hw_bit_1_bits((HWRawBits<1>(varint_u<1>(0x0l))))
, c_hw_bit_15_bits((HWRawBits<15>(varint_u<15>(0x0001l))))
, c_hw_fix_8_0_uns_bits((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x01l))))
, c_hw_bit_8_bits((HWRawBits<8>(varint_u<8>(0x01l))))
, c_hw_fix_32_0_uns_bits_2((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00100000l))))
, c_hw_fix_2_0_uns_bits((HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(0x0l))))
, c_hw_fix_32_0_sgn_undef((HWOffsetFix<32,0,TWOSCOMPLEMENT>()))
, c_hw_fix_32_0_sgn_bits_2((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000000l))))
, c_hw_fix_32_0_uns_bits_3((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00200000l))))
, c_hw_fix_14_0_uns_undef((HWOffsetFix<14,0,UNSIGNED>()))
, c_hw_bit_32_undef((HWRawBits<32>()))
, c_hw_fix_32_0_uns_bits_4((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000000l))))
, c_hw_fix_8_0_uns_bits_1((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x00l))))
, c_hw_bit_32_bits((HWRawBits<32>(varint_u<32>(0x00000000l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_32_0_uns_bits_5((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000005l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, m_sm_CounterChain1045_sm(getDebugStreams(), 79)
, m_sm_CounterChain1049_sm(getDebugStreams(), 89)
, m_sm_CounterChain1057_sm(getDebugStreams(), 178)
, m_sm_CounterChain1068_sm(getDebugStreams(), 194)
, m_sm_CounterChain1070_sm(getDebugStreams(), 216)
, m_sm_DRAM1003_void1055_inldSM(getDebugStreams(), 122)
, m_sm_DRAM1004_void1082_outldSM(getDebugStreams(), 238)
, m_sm_mainSm(getDebugStreams(), 1)
, m_sm_metapipe1065_FixedPoint8740_1(getDebugStreams(), 92)
, m_sm_metapipe1065_FixedPoint8741_2(getDebugStreams(), 100)
, m_sm_metapipe1065_sm(getDebugStreams(), 82)
, m_sm_metapipe1084_FixedPoint9020_1(getDebugStreams(), 197)
, m_sm_metapipe1084_FixedPoint9021_2(getDebugStreams(), 205)
, m_sm_metapipe1084_sm(getDebugStreams(), 187)
, m_sm_pipe1063_sm(getDebugStreams(), 175)
, m_sm_pipe1076_sm(getDebugStreams(), 213)
, m_sm_reg1050_0(getDebugStreams(), 2)
, m_sm_reg1077_0(getDebugStreams(), 29)
, m_sm_seq1086_sm(getDebugStreams(), 67)
, m_sm_void1053_sm(getDebugStreams(), 108)
, m_sm_void1080_sm(getDebugStreams(), 227)
, m_sm_void1088_sm(getDebugStreams(), 62)
{
  { // Node ID: 512 (NodeConstantRawBits)
    id512out_value = (c_hw_fix_17_0_uns_bits);
  }
  { // Node ID: 57 (NodeConstantRawBits)
    id57out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 175 (NodeStateMachine)
  }
  { // Node ID: 508 (NodeConstantRawBits)
    id508out_value = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("en", Data(1));
  }
  { // Node ID: 1 (NodeStateMachine)
  }
  { // Node ID: 64 (NodeConstantRawBits)
    id64out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 62 (NodeStateMachine)
  }
  { // Node ID: 361 (NodeConstantRawBits)
    id361out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 67 (NodeStateMachine)
  }
  { // Node ID: 365 (NodeConstantRawBits)
    id365out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 82 (NodeStateMachine)
  }
  { // Node ID: 122 (NodeStateMachine)
  }
  { // Node ID: 511 (NodeConstantRawBits)
    id511out_value = (c_hw_fix_16_0_uns_bits);
  }
  { // Node ID: 111 (NodeConstantRawBits)
    id111out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 108 (NodeStateMachine)
  }
  { // Node ID: 178 (NodeStateMachine)
  }
  { // Node ID: 238 (NodeStateMachine)
  }
  { // Node ID: 353 (NodeConstantRawBits)
    id353out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 187 (NodeStateMachine)
  }
  { // Node ID: 213 (NodeStateMachine)
  }
  { // Node ID: 216 (NodeStateMachine)
  }
  { // Node ID: 230 (NodeConstantRawBits)
    id230out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 227 (NodeStateMachine)
  }
  { // Node ID: 510 (NodeConstantRawBits)
    id510out_value = (c_hw_fix_17_0_uns_bits_3);
  }
  { // Node ID: 509 (NodeConstantRawBits)
    id509out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 507 (NodeConstantRawBits)
    id507out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 156 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1003_void1055_in_cmd_force_disabled", Data(1));
  }
  { // Node ID: 366 (NodeConstantRawBits)
    id366out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 371 (NodeConstantRawBits)
    id371out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 143 (NodeConstantRawBits)
    id143out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 376 (NodeConstantRawBits)
    id376out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 506 (NodeConstantRawBits)
    id506out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 291 (NodeConstantRawBits)
    id291out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 290 (NodeConstantRawBits)
    id290out_value = (c_hw_fix_2_0_uns_bits);
  }
  { // Node ID: 3 (NodeConstantRawBits)
    id3out_value = (c_hw_fix_1_0_uns_bits);
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
  { // Node ID: 4 (NodeConstantRawBits)
    id4out_value = (c_hw_fix_1_0_uns_bits);
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
  { // Node ID: 2 (NodeStateMachine)
  }
  { // Node ID: 289 (NodeConstantRawBits)
    id289out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 79 (NodeStateMachine)
  }
  { // Node ID: 89 (NodeStateMachine)
  }
  { // Node ID: 288 (NodeConstantRawBits)
    id288out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 118 (NodeConstantRawBits)
    id118out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 505 (NodeConstantRawBits)
    id505out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 159 (NodeOutput)
    m_DRAM1003_void1055_in_cmd = registerOutput("DRAM1003_void1055_in_cmd",0 );
  }
  { // Node ID: 504 (NodeConstantRawBits)
    id504out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 270 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1004_void1082_out_cmd_force_disabled", Data(1));
  }
  { // Node ID: 377 (NodeConstantRawBits)
    id377out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 382 (NodeConstantRawBits)
    id382out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 257 (NodeConstantRawBits)
    id257out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 387 (NodeConstantRawBits)
    id387out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 503 (NodeConstantRawBits)
    id503out_value = (c_hw_fix_32_0_uns_bits_3);
  }
  { // Node ID: 295 (NodeConstantRawBits)
    id295out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 294 (NodeConstantRawBits)
    id294out_value = (c_hw_fix_2_0_uns_bits);
  }
  { // Node ID: 30 (NodeConstantRawBits)
    id30out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 32 (NodeConstantRawBits)
    id32out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 34 (NodeConstantRawBits)
    id34out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 36 (NodeConstantRawBits)
    id36out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 38 (NodeConstantRawBits)
    id38out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 40 (NodeConstantRawBits)
    id40out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 31 (NodeConstantRawBits)
    id31out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 33 (NodeConstantRawBits)
    id33out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 35 (NodeConstantRawBits)
    id35out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 37 (NodeConstantRawBits)
    id37out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 39 (NodeConstantRawBits)
    id39out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 41 (NodeConstantRawBits)
    id41out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 29 (NodeStateMachine)
  }
  { // Node ID: 293 (NodeConstantRawBits)
    id293out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 197 (NodeStateMachine)
  }
  { // Node ID: 194 (NodeStateMachine)
  }
  { // Node ID: 204 (NodeConstantRawBits)
    id204out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 292 (NodeConstantRawBits)
    id292out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 237 (NodeConstantRawBits)
    id237out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 502 (NodeConstantRawBits)
    id502out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 273 (NodeOutput)
    m_DRAM1004_void1082_out_cmd = registerOutput("DRAM1004_void1082_out_cmd",1 );
  }
  { // Node ID: 283 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1004_void1082_out_force_disabled", Data(1));
  }
  { // Node ID: 100 (NodeStateMachine)
  }
  { // Node ID: 92 (NodeStateMachine)
  }
  { // Node ID: 99 (NodeConstantRawBits)
    id99out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 107 (NodeConstantRawBits)
    id107out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 169 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1003_void1055_in_force_disabled", Data(1));
  }
  { // Node ID: 172 (NodeInput)
     m_DRAM1003_void1055_in =  registerInput("DRAM1003_void1055_in",0,5);
  }
  { // Node ID: 337 (NodeRAM)
    for(int i=0;i<9216;i++)
      (id337sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 286 (NodeOutput)
    m_DRAM1004_void1082_out = registerOutput("DRAM1004_void1082_out",2 );
  }
  { // Node ID: 501 (NodeConstantRawBits)
    id501out_value = (c_hw_fix_32_0_uns_bits_4);
  }
  { // Node ID: 317 (NodeInputMappedReg)
    registerMappedRegister("io_intrCmd_force_disabled", Data(1));
  }
  { // Node ID: 392 (NodeConstantRawBits)
    id392out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 394 (NodeConstantRawBits)
    id394out_value = (c_hw_fix_8_0_uns_bits_1);
  }
  { // Node ID: 396 (NodeConstantRawBits)
    id396out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 397 (NodeConstantRawBits)
    id397out_value = (c_hw_bit_32_bits);
  }
  { // Node ID: 320 (NodeOutput)
    m_intrCmd = registerOutput("intrCmd",3 );
  }
  { // Node ID: 330 (NodeConstantRawBits)
    id330out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 331 (NodeOutputMappedReg)
    registerMappedRegister("cycles", Data(64), false);
  }
  { // Node ID: 333 (NodeInputMappedReg)
    registerMappedRegister("io_intrStream_force_disabled", Data(1));
  }
  { // Node ID: 332 (NodeConstantRawBits)
    id332out_value = (c_hw_fix_32_0_uns_bits_5);
  }
  { // Node ID: 336 (NodeOutput)
    m_intrStream = registerOutput("intrStream",4 );
  }
  { // Node ID: 342 (NodeConstantRawBits)
    id342out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 500 (NodeConstantRawBits)
    id500out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 339 (NodeConstantRawBits)
    id339out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 343 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 499 (NodeConstantRawBits)
    id499out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 345 (NodeConstantRawBits)
    id345out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 348 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void TopKernel::resetComputation() {
  resetComputationAfterFlush();
}

void TopKernel::resetComputationAfterFlush() {
  { // Node ID: 175 (NodeStateMachine)

    m_sm_pipe1063_sm.reset();
  }
  { // Node ID: 297 (NodeCounterV1)

    (id297st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_sm_en = id0out_en;

    m_sm_mainSm.reset();
  }
  { // Node ID: 62 (NodeStateMachine)

    m_sm_void1088_sm.reset();
  }
  { // Node ID: 67 (NodeStateMachine)

    m_sm_seq1086_sm.reset();
  }
  { // Node ID: 82 (NodeStateMachine)

    m_sm_metapipe1065_sm.reset();
  }
  { // Node ID: 122 (NodeStateMachine)

    m_sm_DRAM1003_void1055_inldSM.reset();
  }
  { // Node ID: 132 (NodeCounterV1)

    (id132st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 108 (NodeStateMachine)

    m_sm_void1053_sm.reset();
  }
  { // Node ID: 430 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id430out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 431 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id431out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 449 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id449out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 450 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id450out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 432 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id432out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 178 (NodeStateMachine)

    m_sm_CounterChain1057_sm.reset();
  }
  { // Node ID: 433 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id433out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 434 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id434out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 435 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id435out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 447 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id447out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 238 (NodeStateMachine)

    m_sm_DRAM1004_void1082_outldSM.reset();
  }
  { // Node ID: 187 (NodeStateMachine)

    m_sm_metapipe1084_sm.reset();
  }
  { // Node ID: 213 (NodeStateMachine)

    m_sm_pipe1076_sm.reset();
  }
  { // Node ID: 216 (NodeStateMachine)

    m_sm_CounterChain1070_sm.reset();
  }
  { // Node ID: 437 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id437out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 438 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id438out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 471 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id471out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 494 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id494out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 227 (NodeStateMachine)

    m_sm_void1080_sm.reset();
  }
  { // Node ID: 439 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id439out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 440 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id440out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 443 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id443out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 247 (NodeCounterV1)

    (id247st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 441 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id441out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 448 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id448out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 446 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id446out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 444 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id444out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 445 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id445out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 451 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id451out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 156 (NodeInputMappedReg)
    id156out_io_DRAM1003_void1055_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1003_void1055_in_cmd_force_disabled");
  }
  { // Node ID: 464 (NodeFIFO)

    for(int i=0; i<43; i++)
    {
      id464out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 492 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id492out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 491 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id491out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 454 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id454out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 455 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id455out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 2 (NodeStateMachine)

    m_sm_reg1050_0.reset();
  }
  { // Node ID: 463 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id463out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 79 (NodeStateMachine)

    m_sm_CounterChain1045_sm.reset();
  }
  { // Node ID: 89 (NodeStateMachine)

    m_sm_CounterChain1049_sm.reset();
  }
  { // Node ID: 461 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id461out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 19 (NodeHold)

    (id19st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id19out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 24 (NodeHold)

    (id24st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id24out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 465 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id465out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 270 (NodeInputMappedReg)
    id270out_io_DRAM1004_void1082_out_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1004_void1082_out_cmd_force_disabled");
  }
  { // Node ID: 476 (NodeFIFO)

    for(int i=0; i<42; i++)
    {
      id476out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 495 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id495out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 467 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id467out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 468 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id468out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 496 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id496out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 29 (NodeStateMachine)

    m_sm_reg1077_0.reset();
  }
  { // Node ID: 475 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id475out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 197 (NodeStateMachine)

    m_sm_metapipe1084_FixedPoint9020_1.reset();
  }
  { // Node ID: 472 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id472out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 194 (NodeStateMachine)

    m_sm_CounterChain1068_sm.reset();
  }
  { // Node ID: 202 (NodeHold)

    (id202st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id202out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 200 (NodeHold)

    (id200st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id200out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 46 (NodeHold)

    (id46st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id46out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 51 (NodeHold)

    (id51st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id51out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 477 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id477out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 283 (NodeInputMappedReg)
    id283out_io_DRAM1004_void1082_out_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1004_void1082_out_force_disabled");
  }
  { // Node ID: 487 (NodeFIFO)

    for(int i=0; i<65; i++)
    {
      id487out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 100 (NodeStateMachine)

    m_sm_metapipe1065_FixedPoint8741_2.reset();
  }
  { // Node ID: 482 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id482out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 92 (NodeStateMachine)

    m_sm_metapipe1065_FixedPoint8740_1.reset();
  }
  { // Node ID: 480 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id480out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 97 (NodeHold)

    (id97st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id97out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 95 (NodeHold)

    (id95st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id95out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 105 (NodeHold)

    (id105st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id105out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 103 (NodeHold)

    (id103st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id103out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 484 (NodeFIFO)

    for(int i=0; i<62; i++)
    {
      id484out_output[i] = (c_hw_fix_14_0_uns_undef);
    }
  }
  { // Node ID: 483 (NodeFIFO)

    for(int i=0; i<58; i++)
    {
      id483out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 169 (NodeInputMappedReg)
    id169out_io_DRAM1003_void1055_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1003_void1055_in_force_disabled");
  }
  { // Node ID: 172 (NodeInput)

    (id172st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id172st_last_read_value) = (c_hw_bit_32_undef);
  }
  { // Node ID: 493 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id493out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 486 (NodeFIFO)

    for(int i=0; i<65; i++)
    {
      id486out_output[i] = (c_hw_fix_14_0_uns_undef);
    }
  }
  { // Node ID: 497 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id497out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 317 (NodeInputMappedReg)
    id317out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 498 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id498out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 333 (NodeInputMappedReg)
    id333out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 340 (NodeCounterV1)

    (id340st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 346 (NodeCounterV1)

    (id346st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 348 (NodeInputMappedReg)
    id348out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 156 (NodeInputMappedReg)
    id156out_io_DRAM1003_void1055_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1003_void1055_in_cmd_force_disabled");
  }
  { // Node ID: 270 (NodeInputMappedReg)
    id270out_io_DRAM1004_void1082_out_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1004_void1082_out_cmd_force_disabled");
  }
  { // Node ID: 283 (NodeInputMappedReg)
    id283out_io_DRAM1004_void1082_out_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1004_void1082_out_force_disabled");
  }
  { // Node ID: 169 (NodeInputMappedReg)
    id169out_io_DRAM1003_void1055_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1003_void1055_in_force_disabled");
  }
  { // Node ID: 317 (NodeInputMappedReg)
    id317out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 333 (NodeInputMappedReg)
    id333out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 348 (NodeInputMappedReg)
    id348out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::preExecute() {
  { // Node ID: 172 (NodeInput)
    if(((needsToReadInput(m_DRAM1003_void1055_in))&(((getFlushLevel())<((64l)+(5)))|(!(isFlushingActive()))))) {
      (id172st_last_read_value) = (readInput<HWRawBits<32> >(m_DRAM1003_void1055_in));
    }
    id172out_data = (id172st_last_read_value);
  }
}

void TopKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "TopKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int TopKernel::getFlushLevelStart() {
  return ((1l)+(3l));
}

}
