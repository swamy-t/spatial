#ifndef TOPKERNEL_H_
#define TOPKERNEL_H_

// #include "KernelManagerBlockSync.h"

#include "StateMachine_impl_K_TopKernel_mainSm.h"
#include "StateMachine_impl_K_TopKernel_void750_sm.h"
#include "StateMachine_impl_K_TopKernel_void752_sm.h"



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
  state_machine::Kernel_TopKernel_mainSm m_sm_mainSm;
  state_machine::Kernel_TopKernel_void750_sm m_sm_void750_sm;
  state_machine::Kernel_TopKernel_void752_sm m_sm_void752_sm;

  t_port_number m_intrCmd;
  t_port_number m_intrStream;
  HWOffsetFix<33,0,UNSIGNED> id101out_value;

  HWOffsetFix<32,0,UNSIGNED> id21out_count;
  HWOffsetFix<1,0,UNSIGNED> id21out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id21st_count;

  HWOffsetFix<1,0,UNSIGNED> id0out_en;

  HWOffsetFix<64,0,UNSIGNED> id1out_cycles;
  HWOffsetFix<1,0,UNSIGNED> id1out_intr_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_run_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id9out_value;

  HWOffsetFix<1,0,UNSIGNED> id7out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id7out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id7out_sm_done;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id15out_value;

  HWOffsetFix<1,0,UNSIGNED> id12out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id12out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id12out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id12out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id87out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id88out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id89out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id90out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id92out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id4out_value;

  HWOffsetFix<1,0,UNSIGNED> id97out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id100out_value;

  HWOffsetFix<1,0,UNSIGNED> id24out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id25out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id41out_io_intrCmd_force_disabled;

  HWRawBits<1> id95out_output[2];

  HWRawBits<15> id77out_value;

  HWOffsetFix<8,0,UNSIGNED> id79out_value;

  HWRawBits<8> id81out_value;

  HWRawBits<32> id82out_value;

  HWOffsetFix<1,0,UNSIGNED> id54out_value;

  HWOffsetFix<1,0,UNSIGNED> id57out_io_intrStream_force_disabled;

  HWOffsetFix<32,0,UNSIGNED> id56out_value;

  HWOffsetFix<1,0,UNSIGNED> id65out_value;

  HWOffsetFix<1,0,UNSIGNED> id99out_value;

  HWOffsetFix<49,0,UNSIGNED> id62out_value;

  HWOffsetFix<48,0,UNSIGNED> id63out_count;
  HWOffsetFix<1,0,UNSIGNED> id63out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id63st_count;

  HWOffsetFix<1,0,UNSIGNED> id98out_value;

  HWOffsetFix<49,0,UNSIGNED> id68out_value;

  HWOffsetFix<48,0,UNSIGNED> id69out_count;
  HWOffsetFix<1,0,UNSIGNED> id69out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id69st_count;

  HWOffsetFix<48,0,UNSIGNED> id71out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id72out_result[2];

  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_1;
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
