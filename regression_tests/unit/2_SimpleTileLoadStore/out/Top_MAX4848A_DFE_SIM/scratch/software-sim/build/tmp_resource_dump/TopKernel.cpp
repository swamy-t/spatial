#include "stdsimheader.h"
#include "TopKernel.h"

namespace maxcompilersim {

TopKernel::TopKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 70, 2, 38, 0, "",1)
, c_hw_fix_17_0_uns_bits((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00010l))))
, c_hw_fix_17_0_uns_bits_1((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00000l))))
, c_hw_fix_17_0_uns_bits_2((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00001l))))
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_16_0_uns_bits((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x000fl))))
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000060l))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000001l))))
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
, c_hw_fix_32_0_uns_bits_1((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00100000l))))
, c_hw_fix_32_0_uns_bits_2((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00200000l))))
, c_hw_fix_7_0_uns_undef((HWOffsetFix<7,0,UNSIGNED>()))
, c_hw_bit_32_undef((HWRawBits<32>()))
, c_hw_fix_32_0_sgn_undef((HWOffsetFix<32,0,TWOSCOMPLEMENT>()))
, c_hw_fix_32_0_uns_bits_3((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000000l))))
, c_hw_bit_1_undef((HWRawBits<1>()))
, c_hw_fix_8_0_uns_bits_1((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x00l))))
, c_hw_bit_32_bits((HWRawBits<32>(varint_u<32>(0x00000000l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_32_0_uns_bits_4((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000005l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, m_sm_CounterChain1245_sm(getDebugStreams(), 21)
, m_sm_CounterChain1249_sm(getDebugStreams(), 88)
, m_sm_CounterChain1260_sm(getDebugStreams(), 95)
, m_sm_CounterChain1271_sm(getDebugStreams(), 110)
, m_sm_DRAM1198_void1247_inldSM(getDebugStreams(), 32)
, m_sm_DRAM1199_void1278_outldSM(getDebugStreams(), 116)
, m_sm_mainSm(getDebugStreams(), 1)
, m_sm_pipe1255_sm(getDebugStreams(), 85)
, m_sm_pipe1268_sm(getDebugStreams(), 92)
, m_sm_pipe1277_sm(getDebugStreams(), 107)
, m_sm_seq1282_sm(getDebugStreams(), 14)
, m_sm_void1257_sm(getDebugStreams(), 24)
, m_sm_void1280_sm(getDebugStreams(), 102)
, m_sm_void1284_sm(getDebugStreams(), 9)
{
  { // Node ID: 314 (NodeConstantRawBits)
    id314out_value = (c_hw_fix_17_0_uns_bits);
  }
  { // Node ID: 32 (NodeStateMachine)
  }
  { // Node ID: 313 (NodeConstantRawBits)
    id313out_value = (c_hw_fix_16_0_uns_bits);
  }
  { // Node ID: 8 (NodeConstantRawBits)
    id8out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 88 (NodeStateMachine)
  }
  { // Node ID: 85 (NodeStateMachine)
  }
  { // Node ID: 26 (NodeConstantRawBits)
    id26out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 24 (NodeStateMachine)
  }
  { // Node ID: 92 (NodeStateMachine)
  }
  { // Node ID: 95 (NodeStateMachine)
  }
  { // Node ID: 14 (NodeStateMachine)
  }
  { // Node ID: 110 (NodeStateMachine)
  }
  { // Node ID: 107 (NodeStateMachine)
  }
  { // Node ID: 116 (NodeStateMachine)
  }
  { // Node ID: 104 (NodeConstantRawBits)
    id104out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 102 (NodeStateMachine)
  }
  { // Node ID: 312 (NodeConstantRawBits)
    id312out_value = (c_hw_fix_17_0_uns_bits_3);
  }
  { // Node ID: 311 (NodeConstantRawBits)
    id311out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 310 (NodeConstantRawBits)
    id310out_value = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("en", Data(1));
  }
  { // Node ID: 1 (NodeStateMachine)
  }
  { // Node ID: 11 (NodeConstantRawBits)
    id11out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 9 (NodeStateMachine)
  }
  { // Node ID: 2 (NodeInputMappedReg)
    registerMappedRegister("argin1238", Data(32));
  }
  { // Node ID: 221 (NodeConstantRawBits)
    id221out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 309 (NodeConstantRawBits)
    id309out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 66 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1198_void1247_in_cmd_force_disabled", Data(1));
  }
  { // Node ID: 222 (NodeConstantRawBits)
    id222out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 227 (NodeConstantRawBits)
    id227out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 53 (NodeConstantRawBits)
    id53out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 232 (NodeConstantRawBits)
    id232out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 308 (NodeConstantRawBits)
    id308out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 21 (NodeStateMachine)
  }
  { // Node ID: 307 (NodeConstantRawBits)
    id307out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 69 (NodeOutput)
    m_DRAM1198_void1247_in_cmd = registerOutput("DRAM1198_void1247_in_cmd",0 );
  }
  { // Node ID: 306 (NodeConstantRawBits)
    id306out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 148 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1199_void1278_out_cmd_force_disabled", Data(1));
  }
  { // Node ID: 233 (NodeConstantRawBits)
    id233out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 238 (NodeConstantRawBits)
    id238out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 135 (NodeConstantRawBits)
    id135out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 243 (NodeConstantRawBits)
    id243out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 305 (NodeConstantRawBits)
    id305out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 304 (NodeConstantRawBits)
    id304out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 151 (NodeOutput)
    m_DRAM1199_void1278_out_cmd = registerOutput("DRAM1199_void1278_out_cmd",1 );
  }
  { // Node ID: 161 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1199_void1278_out_force_disabled", Data(1));
  }
  { // Node ID: 79 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1198_void1247_in_force_disabled", Data(1));
  }
  { // Node ID: 82 (NodeInput)
     m_DRAM1198_void1247_in =  registerInput("DRAM1198_void1247_in",0,5);
  }
  { // Node ID: 207 (NodeRAM)
    for(int i=0;i<96;i++)
      (id207sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 3 (NodeInputMappedReg)
    registerMappedRegister("argin1239", Data(32));
  }
  { // Node ID: 208 (NodeRAM)
    for(int i=0;i<96;i++)
      (id208sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 164 (NodeOutput)
    m_DRAM1199_void1278_out = registerOutput("DRAM1199_void1278_out",2 );
  }
  { // Node ID: 303 (NodeConstantRawBits)
    id303out_value = (c_hw_fix_32_0_uns_bits_3);
  }
  { // Node ID: 187 (NodeInputMappedReg)
    registerMappedRegister("io_intrCmd_force_disabled", Data(1));
  }
  { // Node ID: 248 (NodeConstantRawBits)
    id248out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 250 (NodeConstantRawBits)
    id250out_value = (c_hw_fix_8_0_uns_bits_1);
  }
  { // Node ID: 252 (NodeConstantRawBits)
    id252out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 253 (NodeConstantRawBits)
    id253out_value = (c_hw_bit_32_bits);
  }
  { // Node ID: 190 (NodeOutput)
    m_intrCmd = registerOutput("intrCmd",3 );
  }
  { // Node ID: 200 (NodeConstantRawBits)
    id200out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 201 (NodeOutputMappedReg)
    registerMappedRegister("cycles", Data(64), false);
  }
  { // Node ID: 203 (NodeInputMappedReg)
    registerMappedRegister("io_intrStream_force_disabled", Data(1));
  }
  { // Node ID: 202 (NodeConstantRawBits)
    id202out_value = (c_hw_fix_32_0_uns_bits_4);
  }
  { // Node ID: 206 (NodeOutput)
    m_intrStream = registerOutput("intrStream",4 );
  }
  { // Node ID: 213 (NodeConstantRawBits)
    id213out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 302 (NodeConstantRawBits)
    id302out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 210 (NodeConstantRawBits)
    id210out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 214 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 301 (NodeConstantRawBits)
    id301out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 216 (NodeConstantRawBits)
    id216out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 219 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void TopKernel::resetComputation() {
  resetComputationAfterFlush();
}

void TopKernel::resetComputationAfterFlush() {
  { // Node ID: 32 (NodeStateMachine)

    m_sm_DRAM1198_void1247_inldSM.reset();
  }
  { // Node ID: 42 (NodeCounterV1)

    (id42st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 88 (NodeStateMachine)

    m_sm_CounterChain1249_sm.reset();
  }
  { // Node ID: 85 (NodeStateMachine)

    m_sm_pipe1255_sm.reset();
  }
  { // Node ID: 266 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id266out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 267 (NodeFIFO)

    for(int i=0; i<55; i++)
    {
      id267out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 268 (NodeFIFO)

    for(int i=0; i<54; i++)
    {
      id268out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 24 (NodeStateMachine)

    m_sm_void1257_sm.reset();
  }
  { // Node ID: 269 (NodeFIFO)

    for(int i=0; i<54; i++)
    {
      id269out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 92 (NodeStateMachine)

    m_sm_pipe1268_sm.reset();
  }
  { // Node ID: 270 (NodeFIFO)

    for(int i=0; i<60; i++)
    {
      id270out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 95 (NodeStateMachine)

    m_sm_CounterChain1260_sm.reset();
  }
  { // Node ID: 271 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id271out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 272 (NodeFIFO)

    for(int i=0; i<60; i++)
    {
      id272out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 14 (NodeStateMachine)

    m_sm_seq1282_sm.reset();
  }
  { // Node ID: 273 (NodeFIFO)

    for(int i=0; i<60; i++)
    {
      id273out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 110 (NodeStateMachine)

    m_sm_CounterChain1271_sm.reset();
  }
  { // Node ID: 107 (NodeStateMachine)

    m_sm_pipe1277_sm.reset();
  }
  { // Node ID: 274 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id274out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 275 (NodeFIFO)

    for(int i=0; i<64; i++)
    {
      id275out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 276 (NodeFIFO)

    for(int i=0; i<63; i++)
    {
      id276out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 116 (NodeStateMachine)

    m_sm_DRAM1199_void1278_outldSM.reset();
  }
  { // Node ID: 102 (NodeStateMachine)

    m_sm_void1280_sm.reset();
  }
  { // Node ID: 277 (NodeFIFO)

    for(int i=0; i<63; i++)
    {
      id277out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 125 (NodeCounterV1)

    (id125st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 278 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id278out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 281 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id281out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 167 (NodeCounterV1)

    (id167st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_sm_en = id0out_en;

    m_sm_mainSm.reset();
  }
  { // Node ID: 279 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id279out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 9 (NodeStateMachine)

    m_sm_void1284_sm.reset();
  }
  { // Node ID: 280 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id280out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 282 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id282out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin1238 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin1238");
  }
  { // Node ID: 283 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id283out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 284 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id284out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 285 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id285out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 66 (NodeInputMappedReg)
    id66out_io_DRAM1198_void1247_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1198_void1247_in_cmd_force_disabled");
  }
  { // Node ID: 286 (NodeFIFO)

    for(int i=0; i<35; i++)
    {
      id286out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 21 (NodeStateMachine)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_max0 = id2out_argin1238;

    m_sm_CounterChain1245_sm.reset();
  }
  { // Node ID: 287 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id287out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 148 (NodeInputMappedReg)
    id148out_io_DRAM1199_void1278_out_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1199_void1278_out_cmd_force_disabled");
  }
  { // Node ID: 288 (NodeFIFO)

    for(int i=0; i<36; i++)
    {
      id288out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 161 (NodeInputMappedReg)
    id161out_io_DRAM1199_void1278_out_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1199_void1278_out_force_disabled");
  }
  { // Node ID: 294 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id294out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 292 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id292out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 290 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id290out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 79 (NodeInputMappedReg)
    id79out_io_DRAM1198_void1247_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1198_void1247_in_force_disabled");
  }
  { // Node ID: 82 (NodeInput)

    (id82st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id82st_last_read_value) = (c_hw_bit_32_undef);
  }
  { // Node ID: 299 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id299out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_argin1239 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin1239");
  }
  { // Node ID: 293 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id293out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 300 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id300out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 187 (NodeInputMappedReg)
    id187out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 297 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id297out_output[i] = (c_hw_bit_1_undef);
    }
  }
  { // Node ID: 203 (NodeInputMappedReg)
    id203out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 211 (NodeCounterV1)

    (id211st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 217 (NodeCounterV1)

    (id217st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 219 (NodeInputMappedReg)
    id219out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin1238 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin1238");
  }
  { // Node ID: 66 (NodeInputMappedReg)
    id66out_io_DRAM1198_void1247_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1198_void1247_in_cmd_force_disabled");
  }
  { // Node ID: 148 (NodeInputMappedReg)
    id148out_io_DRAM1199_void1278_out_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1199_void1278_out_cmd_force_disabled");
  }
  { // Node ID: 161 (NodeInputMappedReg)
    id161out_io_DRAM1199_void1278_out_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1199_void1278_out_force_disabled");
  }
  { // Node ID: 79 (NodeInputMappedReg)
    id79out_io_DRAM1198_void1247_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1198_void1247_in_force_disabled");
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_argin1239 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin1239");
  }
  { // Node ID: 187 (NodeInputMappedReg)
    id187out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 203 (NodeInputMappedReg)
    id203out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 219 (NodeInputMappedReg)
    id219out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::preExecute() {
  { // Node ID: 82 (NodeInput)
    if(((needsToReadInput(m_DRAM1198_void1247_in))&(((getFlushLevel())<((59l)+(5)))|(!(isFlushingActive()))))) {
      (id82st_last_read_value) = (readInput<HWRawBits<32> >(m_DRAM1198_void1247_in));
    }
    id82out_data = (id82st_last_read_value);
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
