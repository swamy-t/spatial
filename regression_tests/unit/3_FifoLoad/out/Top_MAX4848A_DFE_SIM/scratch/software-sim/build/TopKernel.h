#ifndef TOPKERNEL_H_
#define TOPKERNEL_H_

// #include "KernelManagerBlockSync.h"

#include "StateMachine_impl_K_TopKernel_CounterChain1176_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain1182_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain1191_sm.h"
#include "StateMachine_impl_K_TopKernel_DRAM1133_void1177_inldSM.h"
#include "StateMachine_impl_K_TopKernel_DRAM1134_void1198_outldSM.h"
#include "StateMachine_impl_K_TopKernel_mainSm.h"
#include "StateMachine_impl_K_TopKernel_pipe1188_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe1197_sm.h"
#include "StateMachine_impl_K_TopKernel_seq1202_sm.h"
#include "StateMachine_impl_K_TopKernel_void1179_sm.h"
#include "StateMachine_impl_K_TopKernel_void1200_sm.h"
#include "StateMachine_impl_K_TopKernel_void1204_sm.h"



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
  state_machine::Kernel_TopKernel_CounterChain1176_sm m_sm_CounterChain1176_sm;
  state_machine::Kernel_TopKernel_CounterChain1182_sm m_sm_CounterChain1182_sm;
  state_machine::Kernel_TopKernel_CounterChain1191_sm m_sm_CounterChain1191_sm;
  state_machine::Kernel_TopKernel_DRAM1133_void1177_inldSM m_sm_DRAM1133_void1177_inldSM;
  state_machine::Kernel_TopKernel_DRAM1134_void1198_outldSM m_sm_DRAM1134_void1198_outldSM;
  state_machine::Kernel_TopKernel_mainSm m_sm_mainSm;
  state_machine::Kernel_TopKernel_pipe1188_sm m_sm_pipe1188_sm;
  state_machine::Kernel_TopKernel_pipe1197_sm m_sm_pipe1197_sm;
  state_machine::Kernel_TopKernel_seq1202_sm m_sm_seq1202_sm;
  state_machine::Kernel_TopKernel_void1179_sm m_sm_void1179_sm;
  state_machine::Kernel_TopKernel_void1200_sm m_sm_void1200_sm;
  state_machine::Kernel_TopKernel_void1204_sm m_sm_void1204_sm;

  t_port_number m_DRAM1133_void1177_in_cmd;
  t_port_number m_DRAM1134_void1198_out_cmd;
  t_port_number m_DRAM1133_void1177_in;
  t_port_number m_DRAM1134_void1198_out;
  t_port_number m_intrCmd;
  t_port_number m_intrStream;
  HWOffsetFix<17,0,UNSIGNED> id290out_value;

  HWOffsetFix<1,0,UNSIGNED> id30out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id30out_sm_done;

  HWOffsetFix<16,0,UNSIGNED> id40out_count;
  HWOffsetFix<1,0,UNSIGNED> id40out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id40st_count;

  HWOffsetFix<16,0,UNSIGNED> id289out_value;

  HWOffsetFix<1,0,UNSIGNED> id42out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id24out_value;

  HWOffsetFix<1,0,UNSIGNED> id22out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id22out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id22out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id22out_sm_last;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id4out_value;

  HWOffsetFix<1,0,UNSIGNED> id83out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id83out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id83out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id83out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id249out_output[55];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id86out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id86out_done;
  HWOffsetFix<1,0,UNSIGNED> id86out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id250out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id251out_output[55];

  HWOffsetFix<1,0,UNSIGNED> id12out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id12out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id12out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id12out_s2_en;
  HWOffsetFix<1,0,UNSIGNED> id12out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id252out_output[55];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id98out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id98out_done;
  HWOffsetFix<1,0,UNSIGNED> id98out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id95out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id95out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id95out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id95out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id253out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id254out_output[60];

  HWOffsetFix<1,0,UNSIGNED> id255out_output[59];

  HWOffsetFix<1,0,UNSIGNED> id104out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id104out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id92out_value;

  HWOffsetFix<1,0,UNSIGNED> id90out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id90out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id90out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id90out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id90out_sm_last;

  HWOffsetFix<1,0,UNSIGNED> id256out_output[59];

  HWOffsetFix<17,0,UNSIGNED> id288out_value;

  HWOffsetFix<16,0,UNSIGNED> id113out_count;
  HWOffsetFix<1,0,UNSIGNED> id113out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id113st_count;

  HWOffsetFix<16,0,UNSIGNED> id287out_value;

  HWOffsetFix<1,0,UNSIGNED> id115out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id257out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id260out_output[2];

  HWOffsetFix<33,0,UNSIGNED> id286out_value;

  HWOffsetFix<32,0,UNSIGNED> id155out_count;
  HWOffsetFix<1,0,UNSIGNED> id155out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id155st_count;

  HWOffsetFix<1,0,UNSIGNED> id0out_en;

  HWOffsetFix<64,0,UNSIGNED> id1out_cycles;
  HWOffsetFix<1,0,UNSIGNED> id1out_intr_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_run_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id258out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id9out_value;

  HWOffsetFix<1,0,UNSIGNED> id7out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id7out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id7out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id259out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id261out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_argin1130;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id208out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id17out_result[39];

  HWOffsetFix<1,0,UNSIGNED> id262out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id263out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id264out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id285out_value;

  HWOffsetFix<1,0,UNSIGNED> id45out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id46out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id64out_io_DRAM1133_void1177_in_cmd_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id265out_output[35];

  HWRawBits<1> id209out_value;

  HWRawBits<15> id214out_value;

  HWOffsetFix<8,0,UNSIGNED> id51out_value;

  HWRawBits<8> id219out_value;

  HWOffsetFix<32,0,UNSIGNED> id284out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id19out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id19out_done;
  HWOffsetFix<1,0,UNSIGNED> id19out_saturated;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id283out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id33out_result[39];

  HWOffsetFix<32,0,UNSIGNED> id36out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id266out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id282out_value;

  HWOffsetFix<1,0,UNSIGNED> id118out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id119out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id136out_io_DRAM1134_void1198_out_cmd_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id267out_output[36];

  HWRawBits<1> id220out_value;

  HWRawBits<15> id225out_value;

  HWOffsetFix<8,0,UNSIGNED> id123out_value;

  HWRawBits<8> id230out_value;

  HWOffsetFix<32,0,UNSIGNED> id281out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id280out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id107out_result[39];

  HWOffsetFix<32,0,UNSIGNED> id110out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id149out_io_DRAM1134_void1198_out_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id271out_output[3];

  HWOffsetFix<7,0,UNSIGNED> id269out_output[6];

  HWOffsetFix<1,0,UNSIGNED> id77out_io_DRAM1133_void1177_in_force_disabled;

  HWRawBits<32> id80out_data;

  HWOffsetFix<1,0,UNSIGNED> id80st_read_next_cycle;
  HWRawBits<32> id80st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id270out_output[6];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id195out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id195sta_ram_store[96];

  std::string format_string_TopKernel_1 (const char* _format_arg_format_string);
  HWOffsetFix<1,0,UNSIGNED> id276out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id279out_value;

  HWOffsetFix<1,0,UNSIGNED> id158out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id159out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id175out_io_intrCmd_force_disabled;

  HWRawBits<1> id274out_output[2];

  HWRawBits<15> id235out_value;

  HWOffsetFix<8,0,UNSIGNED> id237out_value;

  HWRawBits<8> id239out_value;

  HWRawBits<32> id240out_value;

  HWOffsetFix<1,0,UNSIGNED> id188out_value;

  HWOffsetFix<1,0,UNSIGNED> id191out_io_intrStream_force_disabled;

  HWOffsetFix<32,0,UNSIGNED> id190out_value;

  HWOffsetFix<1,0,UNSIGNED> id200out_value;

  HWOffsetFix<1,0,UNSIGNED> id278out_value;

  HWOffsetFix<49,0,UNSIGNED> id197out_value;

  HWOffsetFix<48,0,UNSIGNED> id198out_count;
  HWOffsetFix<1,0,UNSIGNED> id198out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id198st_count;

  HWOffsetFix<1,0,UNSIGNED> id277out_value;

  HWOffsetFix<49,0,UNSIGNED> id203out_value;

  HWOffsetFix<48,0,UNSIGNED> id204out_count;
  HWOffsetFix<1,0,UNSIGNED> id204out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id204st_count;

  HWOffsetFix<48,0,UNSIGNED> id206out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id207out_result[2];

  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_1;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_3;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_2;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits_2;
  const HWRawBits<1> c_hw_bit_1_bits;
  const HWRawBits<15> c_hw_bit_15_bits;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits;
  const HWRawBits<8> c_hw_bit_8_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_2;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_undef;
  const HWRawBits<32> c_hw_bit_32_undef;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_undef;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_3;
  const HWRawBits<1> c_hw_bit_1_undef;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits_1;
  const HWRawBits<32> c_hw_bit_32_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_4;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* TOPKERNEL_H_ */
