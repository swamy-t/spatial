#include "stdsimheader.h"
#include "TopKernel.h"

namespace maxcompilersim {

TopKernel::TopKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 66, 2, 38, 0, "",1)
, c_hw_fix_17_0_uns_bits((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00010l))))
, c_hw_fix_17_0_uns_bits_1((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00000l))))
, c_hw_fix_17_0_uns_bits_2((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00001l))))
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_16_0_uns_bits((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x000fl))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000001l))))
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000060l))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
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
, m_sm_CounterChain1176_sm(getDebugStreams(), 19)
, m_sm_CounterChain1182_sm(getDebugStreams(), 86)
, m_sm_CounterChain1191_sm(getDebugStreams(), 98)
, m_sm_DRAM1133_void1177_inldSM(getDebugStreams(), 30)
, m_sm_DRAM1134_void1198_outldSM(getDebugStreams(), 104)
, m_sm_mainSm(getDebugStreams(), 1)
, m_sm_pipe1188_sm(getDebugStreams(), 83)
, m_sm_pipe1197_sm(getDebugStreams(), 95)
, m_sm_seq1202_sm(getDebugStreams(), 12)
, m_sm_void1179_sm(getDebugStreams(), 22)
, m_sm_void1200_sm(getDebugStreams(), 90)
, m_sm_void1204_sm(getDebugStreams(), 7)
{
  { // Node ID: 290 (NodeConstantRawBits)
    id290out_value = (c_hw_fix_17_0_uns_bits);
  }
  { // Node ID: 30 (NodeStateMachine)
  }
  { // Node ID: 289 (NodeConstantRawBits)
    id289out_value = (c_hw_fix_16_0_uns_bits);
  }
  { // Node ID: 24 (NodeConstantRawBits)
    id24out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 22 (NodeStateMachine)
  }
  { // Node ID: 4 (NodeConstantRawBits)
    id4out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 83 (NodeStateMachine)
  }
  { // Node ID: 86 (NodeStateMachine)
  }
  { // Node ID: 12 (NodeStateMachine)
  }
  { // Node ID: 98 (NodeStateMachine)
  }
  { // Node ID: 95 (NodeStateMachine)
  }
  { // Node ID: 104 (NodeStateMachine)
  }
  { // Node ID: 92 (NodeConstantRawBits)
    id92out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 90 (NodeStateMachine)
  }
  { // Node ID: 288 (NodeConstantRawBits)
    id288out_value = (c_hw_fix_17_0_uns_bits_3);
  }
  { // Node ID: 287 (NodeConstantRawBits)
    id287out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 286 (NodeConstantRawBits)
    id286out_value = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("en", Data(1));
  }
  { // Node ID: 1 (NodeStateMachine)
  }
  { // Node ID: 9 (NodeConstantRawBits)
    id9out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 7 (NodeStateMachine)
  }
  { // Node ID: 2 (NodeInputMappedReg)
    registerMappedRegister("argin1130", Data(32));
  }
  { // Node ID: 208 (NodeConstantRawBits)
    id208out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 285 (NodeConstantRawBits)
    id285out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 64 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1133_void1177_in_cmd_force_disabled", Data(1));
  }
  { // Node ID: 209 (NodeConstantRawBits)
    id209out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 214 (NodeConstantRawBits)
    id214out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 51 (NodeConstantRawBits)
    id51out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 219 (NodeConstantRawBits)
    id219out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 284 (NodeConstantRawBits)
    id284out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 19 (NodeStateMachine)
  }
  { // Node ID: 283 (NodeConstantRawBits)
    id283out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 67 (NodeOutput)
    m_DRAM1133_void1177_in_cmd = registerOutput("DRAM1133_void1177_in_cmd",0 );
  }
  { // Node ID: 282 (NodeConstantRawBits)
    id282out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 136 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1134_void1198_out_cmd_force_disabled", Data(1));
  }
  { // Node ID: 220 (NodeConstantRawBits)
    id220out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 225 (NodeConstantRawBits)
    id225out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 123 (NodeConstantRawBits)
    id123out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 230 (NodeConstantRawBits)
    id230out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 281 (NodeConstantRawBits)
    id281out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 280 (NodeConstantRawBits)
    id280out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 139 (NodeOutput)
    m_DRAM1134_void1198_out_cmd = registerOutput("DRAM1134_void1198_out_cmd",1 );
  }
  { // Node ID: 149 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1134_void1198_out_force_disabled", Data(1));
  }
  { // Node ID: 77 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1133_void1177_in_force_disabled", Data(1));
  }
  { // Node ID: 80 (NodeInput)
     m_DRAM1133_void1177_in =  registerInput("DRAM1133_void1177_in",0,5);
  }
  { // Node ID: 195 (NodeRAM)
    for(int i=0;i<96;i++)
      (id195sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 152 (NodeOutput)
    m_DRAM1134_void1198_out = registerOutput("DRAM1134_void1198_out",2 );
  }
  { // Node ID: 279 (NodeConstantRawBits)
    id279out_value = (c_hw_fix_32_0_uns_bits_3);
  }
  { // Node ID: 175 (NodeInputMappedReg)
    registerMappedRegister("io_intrCmd_force_disabled", Data(1));
  }
  { // Node ID: 235 (NodeConstantRawBits)
    id235out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 237 (NodeConstantRawBits)
    id237out_value = (c_hw_fix_8_0_uns_bits_1);
  }
  { // Node ID: 239 (NodeConstantRawBits)
    id239out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 240 (NodeConstantRawBits)
    id240out_value = (c_hw_bit_32_bits);
  }
  { // Node ID: 178 (NodeOutput)
    m_intrCmd = registerOutput("intrCmd",3 );
  }
  { // Node ID: 188 (NodeConstantRawBits)
    id188out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 189 (NodeOutputMappedReg)
    registerMappedRegister("cycles", Data(64), false);
  }
  { // Node ID: 191 (NodeInputMappedReg)
    registerMappedRegister("io_intrStream_force_disabled", Data(1));
  }
  { // Node ID: 190 (NodeConstantRawBits)
    id190out_value = (c_hw_fix_32_0_uns_bits_4);
  }
  { // Node ID: 194 (NodeOutput)
    m_intrStream = registerOutput("intrStream",4 );
  }
  { // Node ID: 200 (NodeConstantRawBits)
    id200out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 278 (NodeConstantRawBits)
    id278out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 197 (NodeConstantRawBits)
    id197out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 201 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 277 (NodeConstantRawBits)
    id277out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 203 (NodeConstantRawBits)
    id203out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 206 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void TopKernel::resetComputation() {
  resetComputationAfterFlush();
}

void TopKernel::resetComputationAfterFlush() {
  { // Node ID: 30 (NodeStateMachine)

    m_sm_DRAM1133_void1177_inldSM.reset();
  }
  { // Node ID: 40 (NodeCounterV1)

    (id40st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 22 (NodeStateMachine)

    m_sm_void1179_sm.reset();
  }
  { // Node ID: 83 (NodeStateMachine)

    m_sm_pipe1188_sm.reset();
  }
  { // Node ID: 249 (NodeFIFO)

    for(int i=0; i<55; i++)
    {
      id249out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 86 (NodeStateMachine)

    m_sm_CounterChain1182_sm.reset();
  }
  { // Node ID: 250 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id250out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 251 (NodeFIFO)

    for(int i=0; i<55; i++)
    {
      id251out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 12 (NodeStateMachine)

    m_sm_seq1202_sm.reset();
  }
  { // Node ID: 252 (NodeFIFO)

    for(int i=0; i<55; i++)
    {
      id252out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 98 (NodeStateMachine)

    m_sm_CounterChain1191_sm.reset();
  }
  { // Node ID: 95 (NodeStateMachine)

    m_sm_pipe1197_sm.reset();
  }
  { // Node ID: 253 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id253out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 254 (NodeFIFO)

    for(int i=0; i<60; i++)
    {
      id254out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 255 (NodeFIFO)

    for(int i=0; i<59; i++)
    {
      id255out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 104 (NodeStateMachine)

    m_sm_DRAM1134_void1198_outldSM.reset();
  }
  { // Node ID: 90 (NodeStateMachine)

    m_sm_void1200_sm.reset();
  }
  { // Node ID: 256 (NodeFIFO)

    for(int i=0; i<59; i++)
    {
      id256out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 113 (NodeCounterV1)

    (id113st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 257 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id257out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 260 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id260out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 155 (NodeCounterV1)

    (id155st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_sm_en = id0out_en;

    m_sm_mainSm.reset();
  }
  { // Node ID: 258 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id258out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 7 (NodeStateMachine)

    m_sm_void1204_sm.reset();
  }
  { // Node ID: 259 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id259out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 261 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id261out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin1130 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin1130");
  }
  { // Node ID: 262 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id262out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 263 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id263out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 264 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id264out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 64 (NodeInputMappedReg)
    id64out_io_DRAM1133_void1177_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1133_void1177_in_cmd_force_disabled");
  }
  { // Node ID: 265 (NodeFIFO)

    for(int i=0; i<35; i++)
    {
      id265out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 19 (NodeStateMachine)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id19in_max0 = id2out_argin1130;

    m_sm_CounterChain1176_sm.reset();
  }
  { // Node ID: 266 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id266out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 136 (NodeInputMappedReg)
    id136out_io_DRAM1134_void1198_out_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1134_void1198_out_cmd_force_disabled");
  }
  { // Node ID: 267 (NodeFIFO)

    for(int i=0; i<36; i++)
    {
      id267out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 149 (NodeInputMappedReg)
    id149out_io_DRAM1134_void1198_out_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1134_void1198_out_force_disabled");
  }
  { // Node ID: 271 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id271out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 269 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id269out_output[i] = (c_hw_fix_7_0_uns_undef);
    }
  }
  { // Node ID: 77 (NodeInputMappedReg)
    id77out_io_DRAM1133_void1177_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1133_void1177_in_force_disabled");
  }
  { // Node ID: 80 (NodeInput)

    (id80st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id80st_last_read_value) = (c_hw_bit_32_undef);
  }
  { // Node ID: 270 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id270out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 276 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id276out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 175 (NodeInputMappedReg)
    id175out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 274 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id274out_output[i] = (c_hw_bit_1_undef);
    }
  }
  { // Node ID: 191 (NodeInputMappedReg)
    id191out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 198 (NodeCounterV1)

    (id198st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 204 (NodeCounterV1)

    (id204st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 206 (NodeInputMappedReg)
    id206out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin1130 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin1130");
  }
  { // Node ID: 64 (NodeInputMappedReg)
    id64out_io_DRAM1133_void1177_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1133_void1177_in_cmd_force_disabled");
  }
  { // Node ID: 136 (NodeInputMappedReg)
    id136out_io_DRAM1134_void1198_out_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1134_void1198_out_cmd_force_disabled");
  }
  { // Node ID: 149 (NodeInputMappedReg)
    id149out_io_DRAM1134_void1198_out_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1134_void1198_out_force_disabled");
  }
  { // Node ID: 77 (NodeInputMappedReg)
    id77out_io_DRAM1133_void1177_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1133_void1177_in_force_disabled");
  }
  { // Node ID: 175 (NodeInputMappedReg)
    id175out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 191 (NodeInputMappedReg)
    id191out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 206 (NodeInputMappedReg)
    id206out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::preExecute() {
  { // Node ID: 80 (NodeInput)
    if(((needsToReadInput(m_DRAM1133_void1177_in))&(((getFlushLevel())<((59l)+(5)))|(!(isFlushingActive()))))) {
      (id80st_last_read_value) = (readInput<HWRawBits<32> >(m_DRAM1133_void1177_in));
    }
    id80out_data = (id80st_last_read_value);
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
