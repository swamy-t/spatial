#include "stdsimheader.h"
#include "TopKernel.h"

namespace maxcompilersim {

TopKernel::TopKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 69, 2, 38, 0, "",1)
, c_hw_fix_17_0_uns_bits((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00010l))))
, c_hw_fix_17_0_uns_bits_1((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00000l))))
, c_hw_fix_17_0_uns_bits_2((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00001l))))
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_16_0_uns_bits((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x000fl))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000001l))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000060l))))
, c_hw_fix_32_0_sgn_bits_1((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000001l))))
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000060l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_2((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_9_0_uns_bits((HWOffsetFix<9,0,UNSIGNED>(varint_u<9>(0x024l))))
, c_hw_fix_10_0_uns_bits((HWOffsetFix<10,0,UNSIGNED>(varint_u<10>(0x000l))))
, c_hw_fix_10_0_uns_bits_1((HWOffsetFix<10,0,UNSIGNED>(varint_u<10>(0x001l))))
, c_hw_fix_32_0_sgn_undef((HWOffsetFix<32,0,TWOSCOMPLEMENT>()))
, c_hw_fix_16_0_uns_bits_1((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x0000l))))
, c_hw_bit_1_bits((HWRawBits<1>(varint_u<1>(0x0l))))
, c_hw_bit_15_bits((HWRawBits<15>(varint_u<15>(0x0001l))))
, c_hw_fix_8_0_uns_bits((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x01l))))
, c_hw_bit_8_bits((HWRawBits<8>(varint_u<8>(0x01l))))
, c_hw_fix_32_0_uns_bits_1((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00100000l))))
, c_hw_fix_32_0_uns_bits_2((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00200000l))))
, c_hw_fix_2_0_uns_bits((HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(0x0l))))
, c_hw_bit_32_undef((HWRawBits<32>()))
, c_hw_fix_32_0_sgn_bits_2((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000000l))))
, c_hw_fix_32_0_uns_bits_3((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000000l))))
, c_hw_fix_8_0_uns_bits_1((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x00l))))
, c_hw_bit_32_bits((HWRawBits<32>(varint_u<32>(0x00000000l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_32_0_uns_bits_4((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000005l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, m_sm_CounterChain1919_sm(getDebugStreams(), 47)
, m_sm_CounterChain1930_sm(getDebugStreams(), 198)
, m_sm_DRAM1836_void1920_inldSM(getDebugStreams(), 76)
, m_sm_DRAM1837_void1923_inldSM(getDebugStreams(), 137)
, m_sm_mainSm(getDebugStreams(), 1)
, m_sm_metapipe1946_FixedPoint16140_1(getDebugStreams(), 50)
, m_sm_metapipe1946_FixedPoint16141_2(getDebugStreams(), 58)
, m_sm_metapipe1946_sm(getDebugStreams(), 40)
, m_sm_pipe1940_sm(getDebugStreams(), 190)
, m_sm_reg1928_1(getDebugStreams(), 3)
, m_sm_void1922_sm(getDebugStreams(), 68)
, m_sm_void1925_sm(getDebugStreams(), 129)
, m_sm_void1927_sm(getDebugStreams(), 66)
, m_sm_void1944_sm(getDebugStreams(), 204)
, m_sm_void1948_sm(getDebugStreams(), 35)
{
  { // Node ID: 372 (NodeConstantRawBits)
    id372out_value = (c_hw_fix_17_0_uns_bits);
  }
  { // Node ID: 76 (NodeStateMachine)
  }
  { // Node ID: 371 (NodeConstantRawBits)
    id371out_value = (c_hw_fix_16_0_uns_bits);
  }
  { // Node ID: 70 (NodeConstantRawBits)
    id70out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 68 (NodeStateMachine)
  }
  { // Node ID: 370 (NodeConstantRawBits)
    id370out_value = (c_hw_fix_17_0_uns_bits);
  }
  { // Node ID: 137 (NodeStateMachine)
  }
  { // Node ID: 369 (NodeConstantRawBits)
    id369out_value = (c_hw_fix_16_0_uns_bits);
  }
  { // Node ID: 131 (NodeConstantRawBits)
    id131out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 129 (NodeStateMachine)
  }
  { // Node ID: 198 (NodeStateMachine)
  }
  { // Node ID: 32 (NodeConstantRawBits)
    id32out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 190 (NodeStateMachine)
  }
  { // Node ID: 207 (NodeConstantRawBits)
    id207out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 204 (NodeStateMachine)
  }
  { // Node ID: 368 (NodeConstantRawBits)
    id368out_value = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("en", Data(1));
  }
  { // Node ID: 1 (NodeStateMachine)
  }
  { // Node ID: 37 (NodeConstantRawBits)
    id37out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 35 (NodeStateMachine)
  }
  { // Node ID: 40 (NodeStateMachine)
  }
  { // Node ID: 66 (NodeStateMachine)
  }
  { // Node ID: 358 (NodeConstantRawBits)
    id358out_value = (c_hw_fix_9_0_uns_bits);
  }
  { // Node ID: 2 (NodeInputMappedReg)
    registerMappedRegister("argin1833", Data(32));
  }
  { // Node ID: 269 (NodeConstantRawBits)
    id269out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 367 (NodeConstantRawBits)
    id367out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 110 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1836_void1920_in_cmd_force_disabled", Data(1));
  }
  { // Node ID: 270 (NodeConstantRawBits)
    id270out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 275 (NodeConstantRawBits)
    id275out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 97 (NodeConstantRawBits)
    id97out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 280 (NodeConstantRawBits)
    id280out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 366 (NodeConstantRawBits)
    id366out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 47 (NodeStateMachine)
  }
  { // Node ID: 365 (NodeConstantRawBits)
    id365out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 113 (NodeOutput)
    m_DRAM1836_void1920_in_cmd = registerOutput("DRAM1836_void1920_in_cmd",0 );
  }
  { // Node ID: 364 (NodeConstantRawBits)
    id364out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 171 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1837_void1923_in_cmd_force_disabled", Data(1));
  }
  { // Node ID: 281 (NodeConstantRawBits)
    id281out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 286 (NodeConstantRawBits)
    id286out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 158 (NodeConstantRawBits)
    id158out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 291 (NodeConstantRawBits)
    id291out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 363 (NodeConstantRawBits)
    id363out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 362 (NodeConstantRawBits)
    id362out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 174 (NodeOutput)
    m_DRAM1837_void1923_in_cmd = registerOutput("DRAM1837_void1923_in_cmd",1 );
  }
  { // Node ID: 215 (NodeConstantRawBits)
    id215out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 214 (NodeConstantRawBits)
    id214out_value = (c_hw_fix_2_0_uns_bits);
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
  { // Node ID: 3 (NodeStateMachine)
  }
  { // Node ID: 213 (NodeConstantRawBits)
    id213out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 123 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1836_void1920_in_force_disabled", Data(1));
  }
  { // Node ID: 126 (NodeInput)
     m_DRAM1836_void1920_in =  registerInput("DRAM1836_void1920_in",0,5);
  }
  { // Node ID: 184 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1837_void1923_in_force_disabled", Data(1));
  }
  { // Node ID: 187 (NodeInput)
     m_DRAM1837_void1923_in =  registerInput("DRAM1837_void1923_in",1,5);
  }
  { // Node ID: 212 (NodeConstantRawBits)
    id212out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 202 (NodeConstantRawBits)
    id202out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 211 (NodeOutputMappedReg)
    registerMappedRegister("argout1838", Data(32), false);
  }
  { // Node ID: 361 (NodeConstantRawBits)
    id361out_value = (c_hw_fix_32_0_uns_bits_3);
  }
  { // Node ID: 237 (NodeInputMappedReg)
    registerMappedRegister("io_intrCmd_force_disabled", Data(1));
  }
  { // Node ID: 296 (NodeConstantRawBits)
    id296out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 298 (NodeConstantRawBits)
    id298out_value = (c_hw_fix_8_0_uns_bits_1);
  }
  { // Node ID: 300 (NodeConstantRawBits)
    id300out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 301 (NodeConstantRawBits)
    id301out_value = (c_hw_bit_32_bits);
  }
  { // Node ID: 240 (NodeOutput)
    m_intrCmd = registerOutput("intrCmd",2 );
  }
  { // Node ID: 250 (NodeConstantRawBits)
    id250out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 251 (NodeOutputMappedReg)
    registerMappedRegister("cycles", Data(64), false);
  }
  { // Node ID: 253 (NodeInputMappedReg)
    registerMappedRegister("io_intrStream_force_disabled", Data(1));
  }
  { // Node ID: 252 (NodeConstantRawBits)
    id252out_value = (c_hw_fix_32_0_uns_bits_4);
  }
  { // Node ID: 256 (NodeOutput)
    m_intrStream = registerOutput("intrStream",3 );
  }
  { // Node ID: 261 (NodeConstantRawBits)
    id261out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 360 (NodeConstantRawBits)
    id360out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 258 (NodeConstantRawBits)
    id258out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 262 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 359 (NodeConstantRawBits)
    id359out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 264 (NodeConstantRawBits)
    id264out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 267 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void TopKernel::resetComputation() {
  resetComputationAfterFlush();
}

void TopKernel::resetComputationAfterFlush() {
  { // Node ID: 76 (NodeStateMachine)

    m_sm_DRAM1836_void1920_inldSM.reset();
  }
  { // Node ID: 86 (NodeCounterV1)

    (id86st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 68 (NodeStateMachine)

    m_sm_void1922_sm.reset();
  }
  { // Node ID: 137 (NodeStateMachine)

    m_sm_DRAM1837_void1923_inldSM.reset();
  }
  { // Node ID: 147 (NodeCounterV1)

    (id147st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 129 (NodeStateMachine)

    m_sm_void1925_sm.reset();
  }
  { // Node ID: 312 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id312out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 198 (NodeStateMachine)

    m_sm_CounterChain1930_sm.reset();
  }
  { // Node ID: 190 (NodeStateMachine)

    m_sm_pipe1940_sm.reset();
  }
  { // Node ID: 204 (NodeStateMachine)

    m_sm_void1944_sm.reset();
  }
  { // Node ID: 217 (NodeCounterV1)

    (id217st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_sm_en = id0out_en;

    m_sm_mainSm.reset();
  }
  { // Node ID: 35 (NodeStateMachine)

    m_sm_void1948_sm.reset();
  }
  { // Node ID: 40 (NodeStateMachine)

    m_sm_metapipe1946_sm.reset();
  }
  { // Node ID: 66 (NodeStateMachine)

    m_sm_void1927_sm.reset();
  }
  { // Node ID: 313 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id313out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 326 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id326out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 338 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id338out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 194 (NodeCounterV1)

    (id194st_count) = (c_hw_fix_10_0_uns_bits);
  }
  { // Node ID: 315 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id315out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 316 (NodeFIFO)

    for(int i=0; i<39; i++)
    {
      id316out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 317 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id317out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 318 (NodeFIFO)

    for(int i=0; i<37; i++)
    {
      id318out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 319 (NodeFIFO)

    for(int i=0; i<38; i++)
    {
      id319out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 320 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id320out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 321 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id321out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 322 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id322out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 325 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id325out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 323 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id323out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 324 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id324out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin1833 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin1833");
  }
  { // Node ID: 327 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id327out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 328 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id328out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 329 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id329out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 330 (NodeFIFO)

    for(int i=0; i<35; i++)
    {
      id330out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 110 (NodeInputMappedReg)
    id110out_io_DRAM1836_void1920_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1836_void1920_in_cmd_force_disabled");
  }
  { // Node ID: 47 (NodeStateMachine)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id47in_max0 = id2out_argin1833;

    m_sm_CounterChain1919_sm.reset();
  }
  { // Node ID: 331 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id331out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 332 (NodeFIFO)

    for(int i=0; i<35; i++)
    {
      id332out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 171 (NodeInputMappedReg)
    id171out_io_DRAM1837_void1923_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1837_void1923_in_cmd_force_disabled");
  }
  { // Node ID: 348 (NodeFIFO)

    for(int i=0; i<65; i++)
    {
      id348out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 352 (NodeFIFO)

    for(int i=0; i<24; i++)
    {
      id352out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 353 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id353out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 334 (NodeFIFO)

    for(int i=0; i<63; i++)
    {
      id334out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 356 (NodeFIFO)

    for(int i=0; i<26; i++)
    {
      id356out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 357 (NodeFIFO)

    for(int i=0; i<62; i++)
    {
      id357out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 3 (NodeStateMachine)

    m_sm_reg1928_1.reset();
  }
  { // Node ID: 347 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id347out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 339 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id339out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 340 (NodeFIFO)

    for(int i=0; i<16; i++)
    {
      id340out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 123 (NodeInputMappedReg)
    id123out_io_DRAM1836_void1920_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1836_void1920_in_force_disabled");
  }
  { // Node ID: 126 (NodeInput)

    (id126st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id126st_last_read_value) = (c_hw_bit_32_undef);
  }
  { // Node ID: 184 (NodeInputMappedReg)
    id184out_io_DRAM1837_void1923_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1837_void1923_in_force_disabled");
  }
  { // Node ID: 187 (NodeInput)

    (id187st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id187st_last_read_value) = (c_hw_bit_32_undef);
  }
  { // Node ID: 345 (NodeFIFO)

    for(int i=0; i<23; i++)
    {
      id345out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 201 (NodeAccumulator)

    (id201st_hold_reg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id201out_accumulate[i] = (id201st_hold_reg);
    }
  }
  { // Node ID: 20 (NodeHold)

    (id20st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id20out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 25 (NodeHold)

    (id25st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id25out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 354 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id354out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 237 (NodeInputMappedReg)
    id237out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 355 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id355out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 253 (NodeInputMappedReg)
    id253out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 259 (NodeCounterV1)

    (id259st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 265 (NodeCounterV1)

    (id265st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 267 (NodeInputMappedReg)
    id267out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin1833 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin1833");
  }
  { // Node ID: 110 (NodeInputMappedReg)
    id110out_io_DRAM1836_void1920_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1836_void1920_in_cmd_force_disabled");
  }
  { // Node ID: 171 (NodeInputMappedReg)
    id171out_io_DRAM1837_void1923_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1837_void1923_in_cmd_force_disabled");
  }
  { // Node ID: 123 (NodeInputMappedReg)
    id123out_io_DRAM1836_void1920_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1836_void1920_in_force_disabled");
  }
  { // Node ID: 184 (NodeInputMappedReg)
    id184out_io_DRAM1837_void1923_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1837_void1923_in_force_disabled");
  }
  { // Node ID: 237 (NodeInputMappedReg)
    id237out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 253 (NodeInputMappedReg)
    id253out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 267 (NodeInputMappedReg)
    id267out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::preExecute() {
  { // Node ID: 126 (NodeInput)
    if(((needsToReadInput(m_DRAM1836_void1920_in))&(((getFlushLevel())<((58l)+(5)))|(!(isFlushingActive()))))) {
      (id126st_last_read_value) = (readInput<HWRawBits<32> >(m_DRAM1836_void1920_in));
    }
    id126out_data = (id126st_last_read_value);
  }
  { // Node ID: 187 (NodeInput)
    if(((needsToReadInput(m_DRAM1837_void1923_in))&(((getFlushLevel())<((58l)+(5)))|(!(isFlushingActive()))))) {
      (id187st_last_read_value) = (readInput<HWRawBits<32> >(m_DRAM1837_void1923_in));
    }
    id187out_data = (id187st_last_read_value);
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
