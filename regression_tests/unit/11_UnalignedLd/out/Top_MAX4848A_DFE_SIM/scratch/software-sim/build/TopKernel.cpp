#include "stdsimheader.h"
#include "TopKernel.h"

namespace maxcompilersim {

TopKernel::TopKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 32, 2, 0, 0, "",1)
, c_hw_fix_17_0_uns_bits((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00010l))))
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x0000009bl))))
, c_hw_fix_32_0_sgn_bits_1((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000001l))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000001l))))
, c_hw_fix_17_0_uns_bits_1((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00000l))))
, c_hw_fix_17_0_uns_bits_2((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00001l))))
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_16_0_uns_bits((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x000fl))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_fix_9_0_uns_bits((HWOffsetFix<9,0,UNSIGNED>(varint_u<9>(0x015l))))
, c_hw_fix_10_0_uns_bits((HWOffsetFix<10,0,UNSIGNED>(varint_u<10>(0x000l))))
, c_hw_fix_10_0_uns_bits_1((HWOffsetFix<10,0,UNSIGNED>(varint_u<10>(0x001l))))
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000060l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_2((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_16_0_uns_bits_1((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x0000l))))
, c_hw_bit_1_bits((HWRawBits<1>(varint_u<1>(0x0l))))
, c_hw_bit_15_bits((HWRawBits<15>(varint_u<15>(0x0001l))))
, c_hw_fix_8_0_uns_bits((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x01l))))
, c_hw_bit_8_bits((HWRawBits<8>(varint_u<8>(0x02l))))
, c_hw_bit_32_bits((HWRawBits<32>(varint_u<32>(0x00100000l))))
, c_hw_fix_8_0_uns_undef((HWOffsetFix<8,0,UNSIGNED>()))
, c_hw_bit_32_undef((HWRawBits<32>()))
, c_hw_fix_32_0_sgn_undef((HWOffsetFix<32,0,TWOSCOMPLEMENT>()))
, c_hw_fix_32_0_sgn_bits_2((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000000l))))
, c_hw_fix_32_0_uns_bits_1((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000000l))))
, c_hw_bit_1_undef((HWRawBits<1>()))
, c_hw_fix_8_0_uns_bits_1((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x00l))))
, c_hw_bit_8_bits_1((HWRawBits<8>(varint_u<8>(0x01l))))
, c_hw_bit_32_bits_1((HWRawBits<32>(varint_u<32>(0x00000000l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_32_0_uns_bits_2((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000005l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, m_sm_CounterChain827_sm(getDebugStreams(), 91)
, m_sm_CounterChain840_sm(getDebugStreams(), 103)
, m_sm_DRAM783_void825_inldSM(getDebugStreams(), 27)
, m_sm_mainSm(getDebugStreams(), 1)
, m_sm_pipe833_sm(getDebugStreams(), 88)
, m_sm_pipe847_sm(getDebugStreams(), 95)
, m_sm_void835_sm(getDebugStreams(), 19)
, m_sm_void837_sm(getDebugStreams(), 14)
, m_sm_void851_sm(getDebugStreams(), 110)
, m_sm_void853_sm(getDebugStreams(), 9)
{
  { // Node ID: 253 (NodeConstantRawBits)
    id253out_value = (c_hw_fix_17_0_uns_bits);
  }
  { // Node ID: 6 (NodeConstantRawBits)
    id6out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 91 (NodeStateMachine)
  }
  { // Node ID: 88 (NodeStateMachine)
  }
  { // Node ID: 103 (NodeStateMachine)
  }
  { // Node ID: 95 (NodeStateMachine)
  }
  { // Node ID: 113 (NodeConstantRawBits)
    id113out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 110 (NodeStateMachine)
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
  { // Node ID: 21 (NodeConstantRawBits)
    id21out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 19 (NodeStateMachine)
  }
  { // Node ID: 27 (NodeStateMachine)
  }
  { // Node ID: 252 (NodeConstantRawBits)
    id252out_value = (c_hw_fix_16_0_uns_bits);
  }
  { // Node ID: 246 (NodeConstantRawBits)
    id246out_value = (c_hw_fix_9_0_uns_bits);
  }
  { // Node ID: 251 (NodeConstantRawBits)
    id251out_value = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 250 (NodeConstantRawBits)
    id250out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 69 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM783_void825_in_cmd_force_disabled", Data(1));
  }
  { // Node ID: 175 (NodeConstantRawBits)
    id175out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 180 (NodeConstantRawBits)
    id180out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 56 (NodeConstantRawBits)
    id56out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 185 (NodeConstantRawBits)
    id185out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 189 (NodeConstantRawBits)
    id189out_value = (c_hw_bit_32_bits);
  }
  { // Node ID: 72 (NodeOutput)
    m_DRAM783_void825_in_cmd = registerOutput("DRAM783_void825_in_cmd",0 );
  }
  { // Node ID: 82 (NodeInputMappedReg)
    registerMappedRegister("io_DRAM783_void825_in_force_disabled", Data(1));
  }
  { // Node ID: 85 (NodeInput)
     m_DRAM783_void825_in =  registerInput("DRAM783_void825_in",0,5);
  }
  { // Node ID: 159 (NodeRAM)
    for(int i=0;i<155;i++)
      (id159sta_ram_store[(i)]) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 109 (NodeConstantRawBits)
    id109out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 117 (NodeOutputMappedReg)
    registerMappedRegister("argout784", Data(32), false);
  }
  { // Node ID: 249 (NodeConstantRawBits)
    id249out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 139 (NodeInputMappedReg)
    registerMappedRegister("io_intrCmd_force_disabled", Data(1));
  }
  { // Node ID: 194 (NodeConstantRawBits)
    id194out_value = (c_hw_bit_15_bits);
  }
  { // Node ID: 196 (NodeConstantRawBits)
    id196out_value = (c_hw_fix_8_0_uns_bits_1);
  }
  { // Node ID: 198 (NodeConstantRawBits)
    id198out_value = (c_hw_bit_8_bits_1);
  }
  { // Node ID: 199 (NodeConstantRawBits)
    id199out_value = (c_hw_bit_32_bits_1);
  }
  { // Node ID: 142 (NodeOutput)
    m_intrCmd = registerOutput("intrCmd",1 );
  }
  { // Node ID: 152 (NodeConstantRawBits)
    id152out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 153 (NodeOutputMappedReg)
    registerMappedRegister("cycles", Data(64), false);
  }
  { // Node ID: 155 (NodeInputMappedReg)
    registerMappedRegister("io_intrStream_force_disabled", Data(1));
  }
  { // Node ID: 154 (NodeConstantRawBits)
    id154out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 158 (NodeOutput)
    m_intrStream = registerOutput("intrStream",2 );
  }
  { // Node ID: 164 (NodeConstantRawBits)
    id164out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 248 (NodeConstantRawBits)
    id248out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 161 (NodeConstantRawBits)
    id161out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 165 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 247 (NodeConstantRawBits)
    id247out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 167 (NodeConstantRawBits)
    id167out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 170 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void TopKernel::resetComputation() {
  resetComputationAfterFlush();
}

void TopKernel::resetComputationAfterFlush() {
  { // Node ID: 91 (NodeStateMachine)

    m_sm_CounterChain827_sm.reset();
  }
  { // Node ID: 88 (NodeStateMachine)

    m_sm_pipe833_sm.reset();
  }
  { // Node ID: 103 (NodeStateMachine)

    m_sm_CounterChain840_sm.reset();
  }
  { // Node ID: 95 (NodeStateMachine)

    m_sm_pipe847_sm.reset();
  }
  { // Node ID: 110 (NodeStateMachine)

    m_sm_void851_sm.reset();
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_sm_en = id0out_en;

    m_sm_mainSm.reset();
  }
  { // Node ID: 9 (NodeStateMachine)

    m_sm_void853_sm.reset();
  }
  { // Node ID: 14 (NodeStateMachine)

    m_sm_void837_sm.reset();
  }
  { // Node ID: 19 (NodeStateMachine)

    m_sm_void835_sm.reset();
  }
  { // Node ID: 27 (NodeStateMachine)

    m_sm_DRAM783_void825_inldSM.reset();
  }
  { // Node ID: 45 (NodeCounterV1)

    (id45st_count) = (c_hw_fix_17_0_uns_bits_1);
  }
  { // Node ID: 230 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id230out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 214 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id214out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 215 (NodeFIFO)

    for(int i=0; i<20; i++)
    {
      id215out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 216 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id216out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 217 (NodeFIFO)

    for(int i=0; i<18; i++)
    {
      id217out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 218 (NodeFIFO)

    for(int i=0; i<19; i++)
    {
      id218out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 219 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id219out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 220 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id220out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 99 (NodeCounterV1)

    (id99st_count) = (c_hw_fix_10_0_uns_bits);
  }
  { // Node ID: 221 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id221out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 222 (NodeFIFO)

    for(int i=0; i<24; i++)
    {
      id222out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 223 (NodeFIFO)

    for(int i=0; i<23; i++)
    {
      id223out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 224 (NodeFIFO)

    for(int i=0; i<23; i++)
    {
      id224out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 225 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id225out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 226 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id226out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 227 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id227out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 119 (NodeCounterV1)

    (id119st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 228 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id228out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 229 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id229out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 231 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id231out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 69 (NodeInputMappedReg)
    id69out_io_DRAM783_void825_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM783_void825_in_cmd_force_disabled");
  }
  { // Node ID: 238 (NodeFIFO)

    for(int i=0; i<28; i++)
    {
      id238out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 244 (NodeFIFO)

    for(int i=0; i<3; i++)
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
  { // Node ID: 232 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id232out_output[i] = (c_hw_fix_8_0_uns_undef);
    }
  }
  { // Node ID: 82 (NodeInputMappedReg)
    id82out_io_DRAM783_void825_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM783_void825_in_force_disabled");
  }
  { // Node ID: 85 (NodeInput)

    (id85st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id85st_last_read_value) = (c_hw_bit_32_undef);
  }
  { // Node ID: 243 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id243out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 236 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id236out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 108 (NodeAccumulator)

    (id108st_hold_reg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id108out_accumulate[i] = (id108st_hold_reg);
    }
  }
  { // Node ID: 2 (NodeHold)

    (id2st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    for(int i=0; i<2; i++)
    {
      id2out_output[i] = (c_hw_fix_32_0_sgn_bits_2);
    }
  }
  { // Node ID: 239 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id239out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 139 (NodeInputMappedReg)
    id139out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 241 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id241out_output[i] = (c_hw_bit_1_undef);
    }
  }
  { // Node ID: 155 (NodeInputMappedReg)
    id155out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 162 (NodeCounterV1)

    (id162st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 168 (NodeCounterV1)

    (id168st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 170 (NodeInputMappedReg)
    id170out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_en = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("en");
  }
  { // Node ID: 69 (NodeInputMappedReg)
    id69out_io_DRAM783_void825_in_cmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM783_void825_in_cmd_force_disabled");
  }
  { // Node ID: 82 (NodeInputMappedReg)
    id82out_io_DRAM783_void825_in_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_DRAM783_void825_in_force_disabled");
  }
  { // Node ID: 139 (NodeInputMappedReg)
    id139out_io_intrCmd_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrCmd_force_disabled");
  }
  { // Node ID: 155 (NodeInputMappedReg)
    id155out_io_intrStream_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_intrStream_force_disabled");
  }
  { // Node ID: 170 (NodeInputMappedReg)
    id170out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void TopKernel::preExecute() {
  { // Node ID: 85 (NodeInput)
    if(((needsToReadInput(m_DRAM783_void825_in))&(((getFlushLevel())<((22l)+(5)))|(!(isFlushingActive()))))) {
      (id85st_last_read_value) = (readInput<HWRawBits<32> >(m_DRAM783_void825_in));
    }
    id85out_data = (id85st_last_read_value);
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
