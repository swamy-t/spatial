#include "stdsimheader.h"
#include "TopKernel.h"

namespace maxcompilersim {

TopKernel::TopKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 11, 2, 0, 0, "",1)
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000060l))))
, c_hw_fix_32_0_sgn_bits_1((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000001l))))
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000060l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_2((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000001l))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_fix_32_0_sgn_undef((HWOffsetFix<32,0,TWOSCOMPLEMENT>()))
, c_hw_fix_5_0_uns_undef((HWOffsetFix<5,0,UNSIGNED>()))
, c_hw_bit_2_undef((HWRawBits<2>()))
, c_hw_fix_32_0_uns_bits_1((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000000l))))
, c_hw_bit_1_undef((HWRawBits<1>()))
, c_hw_bit_15_bits((HWRawBits<15>(varint_u<15>(0x0001l))))
, c_hw_fix_8_0_uns_bits((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x00l))))
, c_hw_bit_8_bits((HWRawBits<8>(varint_u<8>(0x01l))))
, c_hw_bit_32_bits((HWRawBits<32>(varint_u<32>(0x00000000l))))
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_32_0_uns_bits_2((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000005l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, m_sm_CounterChain457_sm(getDebugStreams(), 16)
, m_sm_mainSm(getDebugStreams(), 1)
, m_sm_pipe469_sm(getDebugStreams(), 13)
, m_sm_void474_sm(getDebugStreams(), 59)
, m_sm_void476_sm(getDebugStreams(), 8)
{
  { // Node ID: 5 (NodeConstantRawBits)
    id5out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 62 (NodeConstantRawBits)
    id62out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 59 (NodeStateMachine)
  }
  { // Node ID: 183 (NodeConstantRawBits)
    id183out_value = (c_hw_fix_33_0_uns_bits);
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
  { // Node ID: 16 (NodeStateMachine)
  }
  { // Node ID: 3 (NodeInputMappedReg)
    registerMappedRegister("argin451", Data(32));
  }
  { // Node ID: 2 (NodeInputMappedReg)
    registerMappedRegister("argin450", Data(32));
  }
  { // Node ID: 116 (NodeRAM)
    for(int i=0;i<24;i++)
      (id116sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 117 (NodeRAM)
    for(int i=0;i<24;i++)
      (id117sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 118 (NodeRAM)
    for(int i=0;i<24;i++)
      (id118sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 119 (NodeRAM)
    for(int i=0;i<24;i++)
      (id119sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 74 (NodeOutputMappedReg)
    registerMappedRegister("argout452", Data(32), false);
  }
  { // Node ID: 182 (NodeConstantRawBits)
    id182out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 96 (NodeInputMappedReg)
    registerMappedRegister("io_intrCmd_force_disabled", Data(1));
  }
  { // Node ID: 136 (NodeConstantRawBits)
    id136out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 138 (NodeConstantRawBits)
    id138out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 140 (NodeConstantRawBits)
    id140out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 141 (NodeConstantRawBits)
    id141out_value = (c_hw_bit_32_bits);
  }
  { // Node ID: 99 (NodeOutput)
    m_intrCmd = registerOutput("intrCmd",0 );
  }
  { // Node ID: 109 (NodeConstantRawBits)
    id109out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 110 (NodeOutputMappedReg)
    registerMappedRegister("cycles", Data(64), false);
  }
  { // Node ID: 112 (NodeInputMappedReg)
    registerMappedRegister("io_intrStream_force_disabled", Data(1));
  }
  { // Node ID: 111 (NodeConstantRawBits)
    id111out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 115 (NodeOutput)
    m_intrStream = registerOutput("intrStream",1 );
  }
  { // Node ID: 124 (NodeConstantRawBits)
    id124out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 181 (NodeConstantRawBits)
    id181out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 121 (NodeConstantRawBits)
    id121out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 125 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 180 (NodeConstantRawBits)
    id180out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 127 (NodeConstantRawBits)
    id127out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 130 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void TopKernel::resetComputation() {
  resetComputationAfterFlush();
}

void TopKernel::resetComputationAfterFlush() {
  { // Node ID: 59 (NodeStateMachine)

    m_sm_void474_sm.reset();
  }
  { // Node ID: 76 (NodeCounterV1)

    (id76st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_sm_en = id0out_en;

    m_sm_mainSm.reset();
  }
  { // Node ID: 8 (NodeStateMachine)

    m_sm_void476_sm.reset();
  }
  { // Node ID: 13 (NodeStateMachine)

    m_sm_pipe469_sm.reset();
  }
  { // Node ID: 16 (NodeStateMachine)

    m_sm_CounterChain457_sm.reset();
  }
  { // Node ID: 154 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id154out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
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
  { // Node ID: 161 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id161out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 174 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id174out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_argin451 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin451");
  }
  { // Node ID: 163 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id163out_output[i] = (c_hw_fix_5_0_uns_undef);
    }
  }
  { // Node ID: 162 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id162out_output[i] = (c_hw_bit_2_undef);
    }
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin450 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin450");
  }
  { // Node ID: 164 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id164out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 166 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id166out_output[i] = (c_hw_fix_5_0_uns_undef);
    }
  }
  { // Node ID: 165 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id165out_output[i] = (c_hw_bit_2_undef);
    }
  }
  { // Node ID: 169 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id169out_output[i] = (c_hw_fix_5_0_uns_undef);
    }
  }
  { // Node ID: 168 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id168out_output[i] = (c_hw_bit_2_undef);
    }
  }
  { // Node ID: 172 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id172out_output[i] = (c_hw_fix_5_0_uns_undef);
    }
  }
  { // Node ID: 171 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id171out_output[i] = (c_hw_bit_2_undef);
    }
  }
  { // Node ID: 179 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id179out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 96 (NodeInputMappedReg)
    id96out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 177 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id177out_output[i] = (c_hw_bit_1_undef);
    }
  }
  { // Node ID: 112 (NodeInputMappedReg)
    id112out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 122 (NodeCounterV1)

    (id122st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 128 (NodeCounterV1)

    (id128st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 130 (NodeInputMappedReg)
    id130out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_argin451 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin451");
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_argin450 = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("argin450");
  }
  { // Node ID: 96 (NodeInputMappedReg)
    id96out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 112 (NodeInputMappedReg)
    id112out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 130 (NodeInputMappedReg)
    id130out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
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
