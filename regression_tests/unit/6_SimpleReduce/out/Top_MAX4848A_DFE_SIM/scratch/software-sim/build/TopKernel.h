#ifndef TOPKERNEL_H_
#define TOPKERNEL_H_

// #include "KernelManagerBlockSync.h"

#include "StateMachine_impl_K_TopKernel_CounterChain474_sm.h"
#include "StateMachine_impl_K_TopKernel_mainSm.h"
#include "StateMachine_impl_K_TopKernel_pipe481_sm.h"
#include "StateMachine_impl_K_TopKernel_void485_sm.h"
#include "StateMachine_impl_K_TopKernel_void487_sm.h"



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
  state_machine::Kernel_TopKernel_CounterChain474_sm m_sm_CounterChain474_sm;
  state_machine::Kernel_TopKernel_mainSm m_sm_mainSm;
  state_machine::Kernel_TopKernel_pipe481_sm m_sm_pipe481_sm;
  state_machine::Kernel_TopKernel_void485_sm m_sm_void485_sm;
  state_machine::Kernel_TopKernel_void487_sm m_sm_void487_sm;

  t_port_number m_intrCmd;
  t_port_number m_intrStream;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id5out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id21out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id21out_done;
  HWOffsetFix<1,0,UNSIGNED> id21out_saturated;

  HWOffsetFix<33,0,UNSIGNED> id133out_value;

  HWOffsetFix<32,0,UNSIGNED> id36out_count;
  HWOffsetFix<1,0,UNSIGNED> id36out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id36st_count;

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

  HWOffsetFix<1,0,UNSIGNED> id108out_output[2];

  HWOffsetFix<9,0,UNSIGNED> id129out_value;

  HWOffsetFix<9,0,UNSIGNED> id17out_count;
  HWOffsetFix<1,0,UNSIGNED> id17out_wrap;

  HWOffsetFix<10,0,UNSIGNED> id17st_count;

  HWOffsetFix<1,0,UNSIGNED> id20out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id125out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id110out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id115out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id30out_value;

  HWOffsetFix<1,0,UNSIGNED> id27out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id27out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id27out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id27out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id111out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id112out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id113out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id114out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id116out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id120out_output[6];

  HWOffsetFix<1,0,UNSIGNED> id126out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id127out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_argin469;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id26out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id23out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id118out_output[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id24out_accumulate[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id24st_hold_reg;
  HWOffsetFix<1,0,UNSIGNED> id24st_clear_reg;

  HWOffsetFix<1,0,UNSIGNED> id25out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id3out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id3st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id128out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id132out_value;

  HWOffsetFix<1,0,UNSIGNED> id39out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id40out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id56out_io_intrCmd_force_disabled;

  HWRawBits<1> id123out_output[2];

  HWRawBits<15> id92out_value;

  HWOffsetFix<8,0,UNSIGNED> id94out_value;

  HWRawBits<8> id96out_value;

  HWRawBits<32> id97out_value;

  HWOffsetFix<1,0,UNSIGNED> id69out_value;

  HWOffsetFix<1,0,UNSIGNED> id72out_io_intrStream_force_disabled;

  HWOffsetFix<32,0,UNSIGNED> id71out_value;

  HWOffsetFix<1,0,UNSIGNED> id80out_value;

  HWOffsetFix<1,0,UNSIGNED> id131out_value;

  HWOffsetFix<49,0,UNSIGNED> id77out_value;

  HWOffsetFix<48,0,UNSIGNED> id78out_count;
  HWOffsetFix<1,0,UNSIGNED> id78out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id78st_count;

  HWOffsetFix<1,0,UNSIGNED> id130out_value;

  HWOffsetFix<49,0,UNSIGNED> id83out_value;

  HWOffsetFix<48,0,UNSIGNED> id84out_count;
  HWOffsetFix<1,0,UNSIGNED> id84out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id84st_count;

  HWOffsetFix<48,0,UNSIGNED> id86out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id87out_result[2];

  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWOffsetFix<9,0,UNSIGNED> c_hw_fix_9_0_uns_bits;
  const HWOffsetFix<10,0,UNSIGNED> c_hw_fix_10_0_uns_bits;
  const HWOffsetFix<10,0,UNSIGNED> c_hw_fix_10_0_uns_bits_1;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_1;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
  const HWRawBits<1> c_hw_bit_1_undef;
  const HWRawBits<15> c_hw_bit_15_bits;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits;
  const HWRawBits<8> c_hw_bit_8_bits;
  const HWRawBits<32> c_hw_bit_32_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_2;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* TOPKERNEL_H_ */
