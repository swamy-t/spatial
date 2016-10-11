#include "stdsimheader.h"
#include "TopKernel.h"

namespace maxcompilersim {

TopKernel::TopKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 27, 2, 0, 0, "",1)
, c_hw_fix_17_0_uns_bits((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00010l))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000001l))))
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000060l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_2((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_17_0_uns_bits_1((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00000l))))
, c_hw_fix_17_0_uns_bits_2((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00001l))))
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_16_0_uns_bits((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x000fl))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_fix_17_0_uns_bits_3((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00002l))))
, c_hw_fix_16_0_uns_bits_1((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x0001l))))
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x000000c0l))))
, c_hw_fix_16_0_uns_bits_2((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x0000l))))
, c_hw_bit_1_bits((HWRawBits<1>(varint_u<1>(0x0l))))
, c_hw_bit_15_bits((HWRawBits<15>(varint_u<15>(0x0001l))))
, c_hw_fix_8_0_uns_bits((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x01l))))
, c_hw_bit_8_bits((HWRawBits<8>(varint_u<8>(0x02l))))
, c_hw_bit_32_bits((HWRawBits<32>(varint_u<32>(0x00100000l))))
, c_hw_bit_32_bits_1((HWRawBits<32>(varint_u<32>(0x00200000l))))
, c_hw_bit_32_undef((HWRawBits<32>()))
, c_hw_fix_32_0_uns_bits_1((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000000l))))
, c_hw_bit_1_undef((HWRawBits<1>()))
, c_hw_fix_8_0_uns_bits_1((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x00l))))
, c_hw_bit_8_bits_1((HWRawBits<8>(varint_u<8>(0x01l))))
, c_hw_bit_32_bits_2((HWRawBits<32>(varint_u<32>(0x00000000l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_32_0_uns_bits_2((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000005l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, m_sm_CounterChain1088_sm(getDebugStreams(), 137)
, m_sm_DRAM1037_void1079_inldSM(getDebugStreams(), 26)
, m_sm_DRAM1038_void1082_outldSM(getDebugStreams(), 84)
, m_sm_mainSm(getDebugStreams(), 1)
, m_sm_pipe1091_sm(getDebugStreams(), 134)
, m_sm_void1081_sm(getDebugStreams(), 18)
, m_sm_void1084_sm(getDebugStreams(), 79)
, m_sm_void1086_sm(getDebugStreams(), 13)
, m_sm_void1093_sm(getDebugStreams(), 11)
, m_sm_void1095_sm(getDebugStreams(), 6)
{
  { // Node ID: 269 (NodeConstantRawBits)
    id269out_value = (c_hw_fix_17_0_uns_bits);
  }
  { // Node ID: 84 (NodeStateMachine)
  }
  { // Node ID: 81 (NodeConstantRawBits)
    id81out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 79 (NodeStateMachine)
  }
  { // Node ID: 265 (NodeConstantRawBits)
    id265out_value = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("en", Data(1));
  }
  { // Node ID: 1 (NodeStateMachine)
  }
  { // Node ID: 8 (NodeConstantRawBits)
    id8out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 6 (NodeStateMachine)
  }
  { // Node ID: 11 (NodeStateMachine)
  }
  { // Node ID: 15 (NodeConstantRawBits)
    id15out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 13 (NodeStateMachine)
  }
  { // Node ID: 20 (NodeConstantRawBits)
    id20out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 18 (NodeStateMachine)
  }
  { // Node ID: 26 (NodeStateMachine)
  }
  { // Node ID: 268 (NodeConstantRawBits)
    id268out_value = (c_hw_fix_16_0_uns_bits);
  }
  { // Node ID: 267 (NodeConstantRawBits)
    id267out_value = (c_hw_fix_17_0_uns_bits_3);
  }
  { // Node ID: 266 (NodeConstantRawBits)
    id266out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 2 (NodeConstantRawBits)
    id2out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 134 (NodeStateMachine)
  }
  { // Node ID: 137 (NodeStateMachine)
  }
  { // Node ID: 264 (NodeConstantRawBits)
    id264out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 60 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1037_void1079_in_cmd_force_disabled", Data(1));
  }
  { // Node ID: 194 (NodeConstantRawBits)
    id194out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 199 (NodeConstantRawBits)
    id199out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 47 (NodeConstantRawBits)
    id47out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 204 (NodeConstantRawBits)
    id204out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 208 (NodeConstantRawBits)
    id208out_value = (c_hw_bit_32_bits);
  }
  { // Node ID: 63 (NodeOutput)
    m_DRAM1037_void1079_in_cmd = registerOutput("DRAM1037_void1079_in_cmd",0 );
  }
  { // Node ID: 263 (NodeConstantRawBits)
    id263out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 116 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1038_void1082_out_cmd_force_disabled", Data(1));
  }
  { // Node ID: 209 (NodeConstantRawBits)
    id209out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 214 (NodeConstantRawBits)
    id214out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 103 (NodeConstantRawBits)
    id103out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 219 (NodeConstantRawBits)
    id219out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 223 (NodeConstantRawBits)
    id223out_value = (c_hw_bit_32_bits_1);
  }
  { // Node ID: 119 (NodeOutput)
    m_DRAM1038_void1082_out_cmd = registerOutput("DRAM1038_void1082_out_cmd",1 );
  }
  { // Node ID: 129 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1038_void1082_out_force_disabled", Data(1));
  }
  { // Node ID: 73 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM1037_void1079_in_force_disabled", Data(1));
  }
  { // Node ID: 76 (NodeInput)
     m_DRAM1037_void1079_in =  registerInput("DRAM1037_void1079_in",0,5);
  }
  { // Node ID: 132 (NodeOutput)
    m_DRAM1038_void1082_out = registerOutput("DRAM1038_void1082_out",2 );
  }
  { // Node ID: 140 (NodeOutputMappedReg)
    registerMappedRegister("argout1039", Data(32), false);
  }
  { // Node ID: 262 (NodeConstantRawBits)
    id262out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 162 (NodeInputMappedReg)
    registerMappedRegister("io_intrCmd_force_disabled", Data(1));
  }
  { // Node ID: 228 (NodeConstantRawBits)
    id228out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 230 (NodeConstantRawBits)
    id230out_value = (c_hw_fix_8_0_uns_bits_1);
  }
  { // Node ID: 232 (NodeConstantRawBits)
    id232out_value = (c_hw_bit_8_bits_1);
  }
  { // Node ID: 233 (NodeConstantRawBits)
    id233out_value = (c_hw_bit_32_bits_2);
  }
  { // Node ID: 165 (NodeOutput)
    m_intrCmd = registerOutput("intrCmd",3 );
  }
  { // Node ID: 175 (NodeConstantRawBits)
    id175out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 176 (NodeOutputMappedReg)
    registerMappedRegister("cycles", Data(64), false);
  }
  { // Node ID: 178 (NodeInputMappedReg)
    registerMappedRegister("io_intrStream_force_disabled", Data(1));
  }
  { // Node ID: 177 (NodeConstantRawBits)
    id177out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 181 (NodeOutput)
    m_intrStream = registerOutput("intrStream",4 );
  }
  { // Node ID: 186 (NodeConstantRawBits)
    id186out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 261 (NodeConstantRawBits)
    id261out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 183 (NodeConstantRawBits)
    id183out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 187 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 260 (NodeConstantRawBits)
    id260out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 189 (NodeConstantRawBits)
    id189out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 192 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void TopKernel::resetComputation() {
  resetComputationAfterFlush();
}

void TopKernel::resetComputationAfterFlush() {
  { // Node ID: 84 (NodeStateMachine)

    m_sm_DRAM1038_void1082_outldSM.reset();
  }
  { // Node ID: 79 (NodeStateMachine)

    m_sm_void1084_sm.reset();
  }
  { // Node ID: 142 (NodeCounterV1)

    (id142st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_sm_en = id0out_en;

    m_sm_mainSm.reset();
  }
  { // Node ID: 6 (NodeStateMachine)

    m_sm_void1095_sm.reset();
  }
  { // Node ID: 11 (NodeStateMachine)

    m_sm_void1093_sm.reset();
  }
  { // Node ID: 13 (NodeStateMachine)

    m_sm_void1086_sm.reset();
  }
  { // Node ID: 18 (NodeStateMachine)

    m_sm_void1081_sm.reset();
  }
  { // Node ID: 26 (NodeStateMachine)

    m_sm_DRAM1037_void1079_inldSM.reset();
  }
  { // Node ID: 36 (NodeCounterV1)

    (id36st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 248 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id248out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 238 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id238out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 93 (NodeCounterV1)

    (id93st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 239 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id239out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 240 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id240out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 241 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id241out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 134 (NodeStateMachine)

    m_sm_pipe1091_sm.reset();
  }
  { // Node ID: 137 (NodeStateMachine)

    m_sm_CounterChain1088_sm.reset();
  }
  { // Node ID: 242 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id242out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 243 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id243out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 244 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id244out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 245 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id245out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 246 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id246out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 247 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id247out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 249 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id249out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 60 (NodeInputMappedReg)
    id60out_io_DRAM1037_void1079_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1037_void1079_in_cmd_force_disabled");
  }
  { // Node ID: 250 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id250out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 116 (NodeInputMappedReg)
    id116out_io_DRAM1038_void1082_out_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1038_void1082_out_cmd_force_disabled");
  }
  { // Node ID: 251 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id251out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 129 (NodeInputMappedReg)
    id129out_io_DRAM1038_void1082_out_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1038_void1082_out_force_disabled");
  }
  { // Node ID: 254 (NodeFIFO)

    for(int i=0; i<23; i++)
    {
      id254out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 73 (NodeInputMappedReg)
    id73out_io_DRAM1037_void1079_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1037_void1079_in_force_disabled");
  }
  { // Node ID: 253 (NodeFIFO)

    for(int i=0; i<17; i++)
    {
      id253out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 76 (NodeInput)

    (id76st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id76st_last_read_value) = (c_hw_bit_32_undef);
  }
  { // Node ID: 259 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id259out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 162 (NodeInputMappedReg)
    id162out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 257 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id257out_output[i] = (c_hw_bit_1_undef);
    }
  }
  { // Node ID: 178 (NodeInputMappedReg)
    id178out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 184 (NodeCounterV1)

    (id184st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 190 (NodeCounterV1)

    (id190st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 192 (NodeInputMappedReg)
    id192out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 60 (NodeInputMappedReg)
    id60out_io_DRAM1037_void1079_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1037_void1079_in_cmd_force_disabled");
  }
  { // Node ID: 116 (NodeInputMappedReg)
    id116out_io_DRAM1038_void1082_out_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1038_void1082_out_cmd_force_disabled");
  }
  { // Node ID: 129 (NodeInputMappedReg)
    id129out_io_DRAM1038_void1082_out_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1038_void1082_out_force_disabled");
  }
  { // Node ID: 73 (NodeInputMappedReg)
    id73out_io_DRAM1037_void1079_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM1037_void1079_in_force_disabled");
  }
  { // Node ID: 162 (NodeInputMappedReg)
    id162out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 178 (NodeInputMappedReg)
    id178out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 192 (NodeInputMappedReg)
    id192out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::preExecute() {
  { // Node ID: 76 (NodeInput)
    if(((needsToReadInput(m_DRAM1037_void1079_in))&(((getFlushLevel())<((22l)+(5)))|(!(isFlushingActive()))))) {
      (id76st_last_read_value) = (readInput<HWRawBits<32> >(m_DRAM1037_void1079_in));
    }
    id76out_data = (id76st_last_read_value);
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
