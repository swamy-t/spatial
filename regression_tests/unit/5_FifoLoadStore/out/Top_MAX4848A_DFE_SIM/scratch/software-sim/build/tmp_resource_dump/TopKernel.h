#ifndef TOPKERNEL_H_
#define TOPKERNEL_H_

// #include "KernelManagerBlockSync.h"

#include "StateMachine_impl_K_TopKernel_CounterChain1088_sm.h"
#include "StateMachine_impl_K_TopKernel_DRAM1037_void1079_inldSM.h"
#include "StateMachine_impl_K_TopKernel_DRAM1038_void1082_outldSM.h"
#include "StateMachine_impl_K_TopKernel_mainSm.h"
#include "StateMachine_impl_K_TopKernel_pipe1091_sm.h"
#include "StateMachine_impl_K_TopKernel_void1081_sm.h"
#include "StateMachine_impl_K_TopKernel_void1084_sm.h"
#include "StateMachine_impl_K_TopKernel_void1086_sm.h"
#include "StateMachine_impl_K_TopKernel_void1093_sm.h"
#include "StateMachine_impl_K_TopKernel_void1095_sm.h"



namespace maxcompilersim {

class TopKernel : public KernelManagerBlockSync {
public:
  TopKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  state_machine::Kernel_TopKernel_CounterChain1088_sm m_sm_CounterChain1088_sm;
  state_machine::Kernel_TopKernel_DRAM1037_void1079_inldSM m_sm_DRAM1037_void1079_inldSM;
  state_machine::Kernel_TopKernel_DRAM1038_void1082_outldSM m_sm_DRAM1038_void1082_outldSM;
  state_machine::Kernel_TopKernel_mainSm m_sm_mainSm;
  state_machine::Kernel_TopKernel_pipe1091_sm m_sm_pipe1091_sm;
  state_machine::Kernel_TopKernel_void1081_sm m_sm_void1081_sm;
  state_machine::Kernel_TopKernel_void1084_sm m_sm_void1084_sm;
  state_machine::Kernel_TopKernel_void1086_sm m_sm_void1086_sm;
  state_machine::Kernel_TopKernel_void1093_sm m_sm_void1093_sm;
  state_machine::Kernel_TopKernel_void1095_sm m_sm_void1095_sm;

  t_port_number m_DRAM1037_void1079_in_cmd;
  t_port_number m_DRAM1038_void1082_out_cmd;
  t_port_number m_DRAM1037_void1079_in;
  t_port_number m_DRAM1038_void1082_out;
  t_port_number m_intrCmd;
  t_port_number m_intrStream;
  HWOffsetFix<17,0,UNSIGNED> id269out_value;

  HWOffsetFix<1,0,UNSIGNED> id84out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id84out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id81out_value;

  HWOffsetFix<1,0,UNSIGNED> id79out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id79out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id79out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id79out_sm_last;

  HWOffsetFix<33,0,UNSIGNED> id265out_value;

  HWOffsetFix<32,0,UNSIGNED> id142out_count;
  HWOffsetFix<1,0,UNSIGNED> id142out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id142st_count;

  HWOffsetFix<1,0,UNSIGNED> id0out_en;

  HWOffsetFix<64,0,UNSIGNED> id1out_cycles;
  HWOffsetFix<1,0,UNSIGNED> id1out_intr_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_run_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id8out_value;

  HWOffsetFix<1,0,UNSIGNED> id6out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id6out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id6out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id11out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id11out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id11out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id15out_value;

  HWOffsetFix<1,0,UNSIGNED> id13out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id13out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id13out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id13out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id20out_value;

  HWOffsetFix<1,0,UNSIGNED> id18out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id18out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id18out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id18out_sm_last;

  HWOffsetFix<1,0,UNSIGNED> id26out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id26out_sm_done;

  HWOffsetFix<16,0,UNSIGNED> id36out_count;
  HWOffsetFix<1,0,UNSIGNED> id36out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id36st_count;

  HWOffsetFix<16,0,UNSIGNED> id268out_value;

  HWOffsetFix<1,0,UNSIGNED> id38out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id248out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id238out_output[2];

  HWOffsetFix<17,0,UNSIGNED> id267out_value;

  HWOffsetFix<16,0,UNSIGNED> id93out_count;
  HWOffsetFix<1,0,UNSIGNED> id93out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id93st_count;

  HWOffsetFix<16,0,UNSIGNED> id266out_value;

  HWOffsetFix<1,0,UNSIGNED> id95out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id239out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id240out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id241out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_value;

  HWOffsetFix<1,0,UNSIGNED> id134out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id134out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id134out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id134out_sm_done;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id137out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id137out_done;
  HWOffsetFix<1,0,UNSIGNED> id137out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id242out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id243out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id244out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id245out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id246out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id247out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id249out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id264out_value;

  HWOffsetFix<1,0,UNSIGNED> id41out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id42out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id60out_io_DRAM1037_void1079_in_cmd_force_disabled;

  HWRawBits<1> id194out_value;

  HWRawBits<15> id199out_value;

  HWOffsetFix<8,0,UNSIGNED> id47out_value;

  HWRawBits<8> id204out_value;

  HWRawBits<32> id208out_value;

  HWOffsetFix<1,0,UNSIGNED> id250out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id263out_value;

  HWOffsetFix<1,0,UNSIGNED> id98out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id99out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id116out_io_DRAM1038_void1082_out_cmd_force_disabled;

  HWRawBits<1> id209out_value;

  HWRawBits<15> id214out_value;

  HWOffsetFix<8,0,UNSIGNED> id103out_value;

  HWRawBits<8> id219out_value;

  HWRawBits<32> id223out_value;

  HWOffsetFix<1,0,UNSIGNED> id251out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id129out_io_DRAM1038_void1082_out_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id254out_output[23];

  HWOffsetFix<1,0,UNSIGNED> id73out_io_DRAM1037_void1079_in_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id253out_output[17];

  HWRawBits<32> id76out_data;

  HWOffsetFix<1,0,UNSIGNED> id76st_read_next_cycle;
  HWRawBits<32> id76st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id259out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id262out_value;

  HWOffsetFix<1,0,UNSIGNED> id145out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id146out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id162out_io_intrCmd_force_disabled;

  HWRawBits<1> id257out_output[2];

  HWRawBits<15> id228out_value;

  HWOffsetFix<8,0,UNSIGNED> id230out_value;

  HWRawBits<8> id232out_value;

  HWRawBits<32> id233out_value;

  HWOffsetFix<1,0,UNSIGNED> id175out_value;

  HWOffsetFix<1,0,UNSIGNED> id178out_io_intrStream_force_disabled;

  HWOffsetFix<32,0,UNSIGNED> id177out_value;

  HWOffsetFix<1,0,UNSIGNED> id186out_value;

  HWOffsetFix<1,0,UNSIGNED> id261out_value;

  HWOffsetFix<49,0,UNSIGNED> id183out_value;

  HWOffsetFix<48,0,UNSIGNED> id184out_count;
  HWOffsetFix<1,0,UNSIGNED> id184out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id184st_count;

  HWOffsetFix<1,0,UNSIGNED> id260out_value;

  HWOffsetFix<49,0,UNSIGNED> id189out_value;

  HWOffsetFix<48,0,UNSIGNED> id190out_count;
  HWOffsetFix<1,0,UNSIGNED> id190out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id190st_count;

  HWOffsetFix<48,0,UNSIGNED> id192out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id193out_result[2];

  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_2;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_1;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_3;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits_1;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits_2;
  const HWRawBits<1> c_hw_bit_1_bits;
  const HWRawBits<15> c_hw_bit_15_bits;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits;
  const HWRawBits<8> c_hw_bit_8_bits;
  const HWRawBits<32> c_hw_bit_32_bits;
  const HWRawBits<32> c_hw_bit_32_bits_1;
  const HWRawBits<32> c_hw_bit_32_undef;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
  const HWRawBits<1> c_hw_bit_1_undef;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits_1;
  const HWRawBits<8> c_hw_bit_8_bits_1;
  const HWRawBits<32> c_hw_bit_32_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_2;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* TOPKERNEL_H_ */
