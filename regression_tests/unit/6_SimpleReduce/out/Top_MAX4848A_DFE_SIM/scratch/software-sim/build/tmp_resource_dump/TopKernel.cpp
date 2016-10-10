#include "stdsimheader.h"
#include "TopKernel.h"

namespace maxcompilersim {

TopKernel::TopKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 10, 2, 0, 0, "",1)
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000060l))))
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000060l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_2((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000001l))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_fix_9_0_uns_bits((HWOffsetFix<9,0,UNSIGNED>(varint_u<9>(0x000l))))
, c_hw_fix_10_0_uns_bits((HWOffsetFix<10,0,UNSIGNED>(varint_u<10>(0x000l))))
, c_hw_fix_10_0_uns_bits_1((HWOffsetFix<10,0,UNSIGNED>(varint_u<10>(0x001l))))
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
, m_sm_CounterChain474_sm(getDebugStreams(), 21)
, m_sm_mainSm(getDebugStreams(), 1)
, m_sm_pipe481_sm(getDebugStreams(), 13)
, m_sm_void485_sm(getDebugStreams(), 27)
, m_sm_void487_sm(getDebugStreams(), 8)
{
  { // Node ID: 5 (NodeConstantRawBits)
    id5out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 21 (NodeStateMachine)
  }
  { // Node ID: 133 (NodeConstantRawBits)
    id133out_value = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("en", Data(1));
  }
  { // Node ID: 1 (NodeStateMachine)
  }
  { // Node ID: 10 (NodeConstantRawBits)
    id10out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 8 (NodeStateMachine)
  }
  { // Node ID: 13 (NodeStateMachine)
  }
  { // Node ID: 129 (NodeConstantRawBits)
    id129out_value = (c_hw_fix_9_0_uns_bits);
  }
  { // Node ID: 30 (NodeConstantRawBits)
    id30out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 27 (NodeStateMachine)
  }
  { // Node ID: 2 (NodeInputMappedReg)
    registerMappedRegister("argin469", Data(32));
  }
  { // Node ID: 25 (NodeConstantRawBits)
    id25out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 34 (NodeOutputMappedReg)
    registerMappedRegister("argout470", Data(32), false);
  }
  { // Node ID: 132 (NodeConstantRawBits)
    id132out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 56 (NodeInputMappedReg)
    registerMappedRegister("io_intrCmd_force_disabled", Data(1));
  }
  { // Node ID: 92 (NodeConstantRawBits)
    id92out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 94 (NodeConstantRawBits)
    id94out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 96 (NodeConstantRawBits)
    id96out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 97 (NodeConstantRawBits)
    id97out_value = (c_hw_bit_32_bits);
  }
  { // Node ID: 59 (NodeOutput)
    m_intrCmd = registerOutput("intrCmd",0 );
  }
  { // Node ID: 69 (NodeConstantRawBits)
    id69out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 70 (NodeOutputMappedReg)
    registerMappedRegister("cycles", Data(64), false);
  }
  { // Node ID: 72 (NodeInputMappedReg)
    registerMappedRegister("io_intrStream_force_disabled", Data(1));
  }
  { // Node ID: 71 (NodeConstantRawBits)
    id71out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 75 (NodeOutput)
    m_intrStream = registerOutput("intrStream",1 );
  }
  { // Node ID: 80 (NodeConstantRawBits)
    id80out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 131 (NodeConstantRawBits)
    id131out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 77 (NodeConstantRawBits)
    id77out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 81 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 130 (NodeConstantRawBits)
    id130out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 83 (NodeConstantRawBits)
    id83out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 86 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void TopKernel::resetComputation() {
  resetComputationAfterFlush();
}

void TopKernel::resetComputationAfterFlush() {
  { // Node ID: 21 (NodeStateMachine)

    m_sm_CounterChain474_sm.reset();
  }
  { // Node ID: 36 (NodeCounterV1)

    (id36st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_sm_en = id0out_en;

    m_sm_mainSm.reset();
  }
  { // Node ID: 8 (NodeStateMachine)

    m_sm_void487_sm.reset();
  }
  { // Node ID: 13 (NodeStateMachine)

    m_sm_pipe481_sm.reset();
  }
  { // Node ID: 108 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id108out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 17 (NodeCounterV1)

    (id17st_count) = (c_hw_fix_10_0_uns_bits);
  }
  { // Node ID: 125 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id125out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 110 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id110out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 115 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id115out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 27 (NodeStateMachine)

    m_sm_void485_sm.reset();
  }
  { // Node ID: 111 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id111out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 112 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id112out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 113 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id113out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 114 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id114out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 116 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id116out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 120 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id120out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 126 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id126out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 127 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id127out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin469 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin469");
  }
  { // Node ID: 118 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id118out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 24 (NodeAccumulator)

    (id24st_hold_reg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id24out_accumulate[i] = (id24st_hold_reg);
    }
  }
  { // Node ID: 3 (NodeHold)

    (id3st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id3out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 128 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id128out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 56 (NodeInputMappedReg)
    id56out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 123 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id123out_output[i] = (c_hw_bit_1_undef);
    }
  }
  { // Node ID: 72 (NodeInputMappedReg)
    id72out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 78 (NodeCounterV1)

    (id78st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 84 (NodeCounterV1)

    (id84st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 86 (NodeInputMappedReg)
    id86out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin469 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin469");
  }
  { // Node ID: 56 (NodeInputMappedReg)
    id56out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 72 (NodeInputMappedReg)
    id72out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 86 (NodeInputMappedReg)
    id86out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
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
