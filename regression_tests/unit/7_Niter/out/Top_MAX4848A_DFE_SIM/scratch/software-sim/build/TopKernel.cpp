#include "stdsimheader.h"
#include "TopKernel.h"

namespace maxcompilersim {

TopKernel::TopKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 16, 2, 38, 0, "",1)
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000060l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_2((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000001l))))
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000060l))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_fix_9_0_uns_bits((HWOffsetFix<9,0,UNSIGNED>(varint_u<9>(0x000l))))
, c_hw_fix_10_0_uns_bits((HWOffsetFix<10,0,UNSIGNED>(varint_u<10>(0x000l))))
, c_hw_fix_10_0_uns_bits_1((HWOffsetFix<10,0,UNSIGNED>(varint_u<10>(0x001l))))
, c_hw_fix_32_0_sgn_undef((HWOffsetFix<32,0,TWOSCOMPLEMENT>()))
, c_hw_fix_32_0_sgn_bits_1((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000001l))))
, c_hw_fix_32_0_sgn_bits_2((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000000l))))
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_32_0_uns_bits_1((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000000l))))
, c_hw_bit_1_undef((HWRawBits<1>()))
, c_hw_bit_15_bits((HWRawBits<15>(varint_u<15>(0x0001l))))
, c_hw_fix_8_0_uns_bits((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x00l))))
, c_hw_bit_8_bits((HWRawBits<8>(varint_u<8>(0x01l))))
, c_hw_bit_32_bits((HWRawBits<32>(varint_u<32>(0x00000000l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_32_0_uns_bits_2((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000005l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, m_sm_CounterChain554_sm(getDebugStreams(), 26)
, m_sm_CounterChain557_sm(getDebugStreams(), 37)
, m_sm_mainSm(getDebugStreams(), 1)
, m_sm_pipe562_sm(getDebugStreams(), 29)
, m_sm_seq568_sm(getDebugStreams(), 19)
, m_sm_void566_sm(getDebugStreams(), 57)
, m_sm_void570_sm(getDebugStreams(), 14)
, m_sm_void572_sm(getDebugStreams(), 9)
{
  { // Node ID: 37 (NodeStateMachine)
  }
  { // Node ID: 195 (NodeConstantRawBits)
    id195out_value = (c_hw_fix_33_0_uns_bits);
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
  { // Node ID: 16 (NodeConstantRawBits)
    id16out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 14 (NodeStateMachine)
  }
  { // Node ID: 19 (NodeStateMachine)
  }
  { // Node ID: 5 (NodeConstantRawBits)
    id5out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 29 (NodeStateMachine)
  }
  { // Node ID: 191 (NodeConstantRawBits)
    id191out_value = (c_hw_fix_9_0_uns_bits);
  }
  { // Node ID: 60 (NodeConstantRawBits)
    id60out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 57 (NodeStateMachine)
  }
  { // Node ID: 2 (NodeInputMappedReg)
    registerMappedRegister("argin549", Data(32));
  }
  { // Node ID: 118 (NodeConstantRawBits)
    id118out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 26 (NodeStateMachine)
  }
  { // Node ID: 41 (NodeConstantRawBits)
    id41out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 64 (NodeOutputMappedReg)
    registerMappedRegister("argout550", Data(32), false);
  }
  { // Node ID: 194 (NodeConstantRawBits)
    id194out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 86 (NodeInputMappedReg)
    registerMappedRegister("io_intrCmd_force_disabled", Data(1));
  }
  { // Node ID: 123 (NodeConstantRawBits)
    id123out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 125 (NodeConstantRawBits)
    id125out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 127 (NodeConstantRawBits)
    id127out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 128 (NodeConstantRawBits)
    id128out_value = (c_hw_bit_32_bits);
  }
  { // Node ID: 89 (NodeOutput)
    m_intrCmd = registerOutput("intrCmd",0 );
  }
  { // Node ID: 99 (NodeConstantRawBits)
    id99out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 100 (NodeOutputMappedReg)
    registerMappedRegister("cycles", Data(64), false);
  }
  { // Node ID: 102 (NodeInputMappedReg)
    registerMappedRegister("io_intrStream_force_disabled", Data(1));
  }
  { // Node ID: 101 (NodeConstantRawBits)
    id101out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 105 (NodeOutput)
    m_intrStream = registerOutput("intrStream",1 );
  }
  { // Node ID: 110 (NodeConstantRawBits)
    id110out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 193 (NodeConstantRawBits)
    id193out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 107 (NodeConstantRawBits)
    id107out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 111 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 192 (NodeConstantRawBits)
    id192out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 113 (NodeConstantRawBits)
    id113out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 116 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void TopKernel::resetComputation() {
  resetComputationAfterFlush();
}

void TopKernel::resetComputationAfterFlush() {
  { // Node ID: 37 (NodeStateMachine)

    m_sm_CounterChain557_sm.reset();
  }
  { // Node ID: 66 (NodeCounterV1)

    (id66st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_sm_en = id0out_en;

    m_sm_mainSm.reset();
  }
  { // Node ID: 9 (NodeStateMachine)

    m_sm_void572_sm.reset();
  }
  { // Node ID: 14 (NodeStateMachine)

    m_sm_void570_sm.reset();
  }
  { // Node ID: 19 (NodeStateMachine)

    m_sm_seq568_sm.reset();
  }
  { // Node ID: 29 (NodeStateMachine)

    m_sm_pipe562_sm.reset();
  }
  { // Node ID: 147 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id147out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 33 (NodeCounterV1)

    (id33st_count) = (c_hw_fix_10_0_uns_bits);
  }
  { // Node ID: 148 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id148out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 182 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id182out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 150 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id150out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 154 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id154out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 57 (NodeStateMachine)

    m_sm_void566_sm.reset();
  }
  { // Node ID: 151 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id151out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 152 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id152out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 153 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id153out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin549 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin549");
  }
  { // Node ID: 155 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id155out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 156 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id156out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 157 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id157out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 158 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id158out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 177 (NodeFIFO)

    for(int i=0; i<12; i++)
    {
      id177out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 183 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id183out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 184 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id184out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 159 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id159out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 160 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id160out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 26 (NodeStateMachine)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id26in_max0 = id2out_argin549;

    m_sm_CounterChain554_sm.reset();
  }
  { // Node ID: 161 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id161out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 162 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id162out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 163 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id163out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 186 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id186out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 165 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id165out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 187 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id187out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 167 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id167out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 188 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id188out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 169 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id169out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 189 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id189out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 171 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id171out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 190 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id190out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 173 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id173out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 175 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id175out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 40 (NodeAccumulator)

    (id40st_hold_reg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id40out_accumulate[i] = (id40st_hold_reg);
    }
  }
  { // Node ID: 3 (NodeHold)

    (id3st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id3out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 185 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id185out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 86 (NodeInputMappedReg)
    id86out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 180 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id180out_output[i] = (c_hw_bit_1_undef);
    }
  }
  { // Node ID: 102 (NodeInputMappedReg)
    id102out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 108 (NodeCounterV1)

    (id108st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 114 (NodeCounterV1)

    (id114st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 116 (NodeInputMappedReg)
    id116out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin549 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin549");
  }
  { // Node ID: 86 (NodeInputMappedReg)
    id86out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 102 (NodeInputMappedReg)
    id102out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 116 (NodeInputMappedReg)
    id116out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::preExecute() {
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
