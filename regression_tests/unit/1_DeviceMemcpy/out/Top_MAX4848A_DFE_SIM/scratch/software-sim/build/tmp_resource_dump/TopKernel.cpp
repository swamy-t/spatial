#include "stdsimheader.h"
#include "TopKernel.h"

namespace maxcompilersim {

TopKernel::TopKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 7, 2, 0, 0, "",1)
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000060l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_2((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000001l))))
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000001l))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_fix_32_0_sgn_bits_1((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x0000000al))))
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
, m_sm_mainSm(getDebugStreams(), 1)
, m_sm_void750_sm(getDebugStreams(), 12)
, m_sm_void752_sm(getDebugStreams(), 7)
{
  { // Node ID: 101 (NodeConstantRawBits)
    id101out_value = (c_hw_fix_33_0_uns_bits);
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
  { // Node ID: 15 (NodeConstantRawBits)
    id15out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 12 (NodeStateMachine)
  }
  { // Node ID: 4 (NodeConstantRawBits)
    id4out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 19 (NodeOutputMappedReg)
    registerMappedRegister("argout747", Data(32), false);
  }
  { // Node ID: 100 (NodeConstantRawBits)
    id100out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 41 (NodeInputMappedReg)
    registerMappedRegister("io_intrCmd_force_disabled", Data(1));
  }
  { // Node ID: 77 (NodeConstantRawBits)
    id77out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 79 (NodeConstantRawBits)
    id79out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 81 (NodeConstantRawBits)
    id81out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 82 (NodeConstantRawBits)
    id82out_value = (c_hw_bit_32_bits);
  }
  { // Node ID: 44 (NodeOutput)
    m_intrCmd = registerOutput("intrCmd",0 );
  }
  { // Node ID: 54 (NodeConstantRawBits)
    id54out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 55 (NodeOutputMappedReg)
    registerMappedRegister("cycles", Data(64), false);
  }
  { // Node ID: 57 (NodeInputMappedReg)
    registerMappedRegister("io_intrStream_force_disabled", Data(1));
  }
  { // Node ID: 56 (NodeConstantRawBits)
    id56out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 60 (NodeOutput)
    m_intrStream = registerOutput("intrStream",1 );
  }
  { // Node ID: 65 (NodeConstantRawBits)
    id65out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 99 (NodeConstantRawBits)
    id99out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 62 (NodeConstantRawBits)
    id62out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 66 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 98 (NodeConstantRawBits)
    id98out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 68 (NodeConstantRawBits)
    id68out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 71 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void TopKernel::resetComputation() {
  resetComputationAfterFlush();
}

void TopKernel::resetComputationAfterFlush() {
  { // Node ID: 21 (NodeCounterV1)

    (id21st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_sm_en = id0out_en;

    m_sm_mainSm.reset();
  }
  { // Node ID: 7 (NodeStateMachine)

    m_sm_void752_sm.reset();
  }
  { // Node ID: 12 (NodeStateMachine)

    m_sm_void750_sm.reset();
  }
  { // Node ID: 87 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id87out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 88 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id88out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 89 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id89out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 90 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id90out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 92 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id92out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 97 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id97out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 41 (NodeInputMappedReg)
    id41out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 95 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id95out_output[i] = (c_hw_bit_1_undef);
    }
  }
  { // Node ID: 57 (NodeInputMappedReg)
    id57out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 63 (NodeCounterV1)

    (id63st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 69 (NodeCounterV1)

    (id69st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 71 (NodeInputMappedReg)
    id71out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 41 (NodeInputMappedReg)
    id41out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 57 (NodeInputMappedReg)
    id57out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 71 (NodeInputMappedReg)
    id71out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
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
