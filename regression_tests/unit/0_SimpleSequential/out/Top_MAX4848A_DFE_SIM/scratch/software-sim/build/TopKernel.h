#ifndef TOPKERNEL_H_
#define TOPKERNEL_H_

// #include "KernelManagerBlockSync.h"

#include "StateMachine_impl_K_TopKernel_CounterChain457_sm.h"
#include "StateMachine_impl_K_TopKernel_mainSm.h"
#include "StateMachine_impl_K_TopKernel_pipe469_sm.h"
#include "StateMachine_impl_K_TopKernel_void474_sm.h"
#include "StateMachine_impl_K_TopKernel_void476_sm.h"



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
  state_machine::Kernel_TopKernel_CounterChain457_sm m_sm_CounterChain457_sm;
  state_machine::Kernel_TopKernel_mainSm m_sm_mainSm;
  state_machine::Kernel_TopKernel_pipe469_sm m_sm_pipe469_sm;
  state_machine::Kernel_TopKernel_void474_sm m_sm_void474_sm;
  state_machine::Kernel_TopKernel_void476_sm m_sm_void476_sm;

  t_port_number m_intrCmd;
  t_port_number m_intrStream;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id5out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id62out_value;

  HWOffsetFix<1,0,UNSIGNED> id59out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id59out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id59out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id59out_sm_done;

  HWOffsetFix<33,0,UNSIGNED> id183out_value;

  HWOffsetFix<32,0,UNSIGNED> id76out_count;
  HWOffsetFix<1,0,UNSIGNED> id76out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id76st_count;

  HWOffsetFix<1,0,UNSIGNED> id0out_en;

  HWOffsetFix<64,0,UNSIGNED> id1out_cycles;
  HWOffsetFix<1,0,UNSIGNED> id1out_intr_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_run_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id10out_value;

  HWOffsetFix<1,0,UNSIGNED> id8out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id8out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id8out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id8out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id13out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id13out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id13out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id13out_sm_done;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id16out_counter0;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id16out_counter0_extension0;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id16out_counter0_extension1;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id16out_counter0_extension2;
  HWOffsetFix<1,0,UNSIGNED> id16out_done;
  HWOffsetFix<1,0,UNSIGNED> id16out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id154out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id155out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id156out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id157out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id158out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id159out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id160out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id161out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id174out_output[7];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id3out_argin451;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id28out_result[2];

  HWOffsetFix<5,0,UNSIGNED> id163out_output[3];

  HWRawBits<2> id162out_output[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_argin450;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id19out_result[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id20out_result[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id21out_result[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id22out_result[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id29out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id164out_output[4];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id116out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id116sta_ram_store[24];

  std::string format_string_TopKernel_1 (const char* _format_arg_format_string);
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id37out_result[2];

  HWOffsetFix<5,0,UNSIGNED> id166out_output[3];

  HWRawBits<2> id165out_output[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id38out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id117out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id117sta_ram_store[24];

  std::string format_string_TopKernel_2 (const char* _format_arg_format_string);
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id46out_result[2];

  HWOffsetFix<5,0,UNSIGNED> id169out_output[3];

  HWRawBits<2> id168out_output[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id47out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id118out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id118sta_ram_store[24];

  std::string format_string_TopKernel_3 (const char* _format_arg_format_string);
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id55out_result[2];

  HWOffsetFix<5,0,UNSIGNED> id172out_output[3];

  HWRawBits<2> id171out_output[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id56out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id119out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id119sta_ram_store[24];

  std::string format_string_TopKernel_4 (const char* _format_arg_format_string);
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id73out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id179out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id182out_value;

  HWOffsetFix<1,0,UNSIGNED> id79out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id80out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id96out_io_intrCmd_force_disabled;

  HWRawBits<1> id177out_output[2];

  HWRawBits<15> id136out_value;

  HWOffsetFix<8,0,UNSIGNED> id138out_value;

  HWRawBits<8> id140out_value;

  HWRawBits<32> id141out_value;

  HWOffsetFix<1,0,UNSIGNED> id109out_value;

  HWOffsetFix<1,0,UNSIGNED> id112out_io_intrStream_force_disabled;

  HWOffsetFix<32,0,UNSIGNED> id111out_value;

  HWOffsetFix<1,0,UNSIGNED> id124out_value;

  HWOffsetFix<1,0,UNSIGNED> id181out_value;

  HWOffsetFix<49,0,UNSIGNED> id121out_value;

  HWOffsetFix<48,0,UNSIGNED> id122out_count;
  HWOffsetFix<1,0,UNSIGNED> id122out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id122st_count;

  HWOffsetFix<1,0,UNSIGNED> id180out_value;

  HWOffsetFix<49,0,UNSIGNED> id127out_value;

  HWOffsetFix<48,0,UNSIGNED> id128out_count;
  HWOffsetFix<1,0,UNSIGNED> id128out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id128st_count;

  HWOffsetFix<48,0,UNSIGNED> id130out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id131out_result[2];

  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_undef;
  const HWOffsetFix<5,0,UNSIGNED> c_hw_fix_5_0_uns_undef;
  const HWRawBits<2> c_hw_bit_2_undef;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
  const HWRawBits<1> c_hw_bit_1_undef;
  const HWRawBits<15> c_hw_bit_15_bits;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits;
  const HWRawBits<8> c_hw_bit_8_bits;
  const HWRawBits<32> c_hw_bit_32_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_2;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* TOPKERNEL_H_ */
