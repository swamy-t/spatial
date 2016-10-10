#ifndef TOPKERNEL_H_
#define TOPKERNEL_H_

// #include "KernelManagerBlockSync.h"

#include "StateMachine_impl_K_TopKernel_CounterChain554_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain557_sm.h"
#include "StateMachine_impl_K_TopKernel_mainSm.h"
#include "StateMachine_impl_K_TopKernel_pipe562_sm.h"
#include "StateMachine_impl_K_TopKernel_seq568_sm.h"
#include "StateMachine_impl_K_TopKernel_void566_sm.h"
#include "StateMachine_impl_K_TopKernel_void570_sm.h"
#include "StateMachine_impl_K_TopKernel_void572_sm.h"



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
  state_machine::Kernel_TopKernel_CounterChain554_sm m_sm_CounterChain554_sm;
  state_machine::Kernel_TopKernel_CounterChain557_sm m_sm_CounterChain557_sm;
  state_machine::Kernel_TopKernel_mainSm m_sm_mainSm;
  state_machine::Kernel_TopKernel_pipe562_sm m_sm_pipe562_sm;
  state_machine::Kernel_TopKernel_seq568_sm m_sm_seq568_sm;
  state_machine::Kernel_TopKernel_void566_sm m_sm_void566_sm;
  state_machine::Kernel_TopKernel_void570_sm m_sm_void570_sm;
  state_machine::Kernel_TopKernel_void572_sm m_sm_void572_sm;

  t_port_number m_intrCmd;
  t_port_number m_intrStream;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id37out_counter0;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id37out_counter0_extension0;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id37out_counter0_extension1;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id37out_counter0_extension2;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id37out_counter0_extension3;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id37out_counter0_extension4;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id37out_counter0_extension5;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id37out_counter0_extension6;
  HWOffsetFix<1,0,UNSIGNED> id37out_done;
  HWOffsetFix<1,0,UNSIGNED> id37out_saturated;

  HWOffsetFix<33,0,UNSIGNED> id195out_value;

  HWOffsetFix<32,0,UNSIGNED> id66out_count;
  HWOffsetFix<1,0,UNSIGNED> id66out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id66st_count;

  HWOffsetFix<1,0,UNSIGNED> id0out_en;

  HWOffsetFix<64,0,UNSIGNED> id1out_cycles;
  HWOffsetFix<1,0,UNSIGNED> id1out_intr_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_run_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id11out_value;

  HWOffsetFix<1,0,UNSIGNED> id9out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id9out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id9out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id16out_value;

  HWOffsetFix<1,0,UNSIGNED> id14out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id14out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id14out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id19out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id19out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id19out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id19out_sm_done;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id5out_value;

  HWOffsetFix<1,0,UNSIGNED> id29out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id29out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id29out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id29out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id147out_output[2];

  HWOffsetFix<9,0,UNSIGNED> id191out_value;

  HWOffsetFix<9,0,UNSIGNED> id33out_count;
  HWOffsetFix<1,0,UNSIGNED> id33out_wrap;

  HWOffsetFix<10,0,UNSIGNED> id33st_count;

  HWOffsetFix<1,0,UNSIGNED> id36out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id148out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id182out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id150out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id154out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id60out_value;

  HWOffsetFix<1,0,UNSIGNED> id57out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id57out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id57out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id57out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id151out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id152out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id153out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_argin549;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id118out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id24out_result[39];

  HWOffsetFix<1,0,UNSIGNED> id155out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id156out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id157out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id158out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id177out_output[12];

  HWOffsetFix<1,0,UNSIGNED> id183out_output[9];

  HWOffsetFix<1,0,UNSIGNED> id184out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id159out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id160out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id26out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id26out_done;
  HWOffsetFix<1,0,UNSIGNED> id26out_saturated;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id129out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id161out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id162out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id130out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id163out_output[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id186out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id131out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id165out_output[4];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id187out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id132out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id167out_output[5];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id188out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id133out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id169out_output[6];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id189out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id134out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id171out_output[7];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id190out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id135out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id173out_output[8];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id136out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id39out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id175out_output[9];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id40out_accumulate[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id40st_hold_reg;
  HWOffsetFix<1,0,UNSIGNED> id40st_clear_reg;

  HWOffsetFix<1,0,UNSIGNED> id41out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id3out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id3st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id185out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id194out_value;

  HWOffsetFix<1,0,UNSIGNED> id69out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id70out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id86out_io_intrCmd_force_disabled;

  HWRawBits<1> id180out_output[2];

  HWRawBits<15> id123out_value;

  HWOffsetFix<8,0,UNSIGNED> id125out_value;

  HWRawBits<8> id127out_value;

  HWRawBits<32> id128out_value;

  HWOffsetFix<1,0,UNSIGNED> id99out_value;

  HWOffsetFix<1,0,UNSIGNED> id102out_io_intrStream_force_disabled;

  HWOffsetFix<32,0,UNSIGNED> id101out_value;

  HWOffsetFix<1,0,UNSIGNED> id110out_value;

  HWOffsetFix<1,0,UNSIGNED> id193out_value;

  HWOffsetFix<49,0,UNSIGNED> id107out_value;

  HWOffsetFix<48,0,UNSIGNED> id108out_count;
  HWOffsetFix<1,0,UNSIGNED> id108out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id108st_count;

  HWOffsetFix<1,0,UNSIGNED> id192out_value;

  HWOffsetFix<49,0,UNSIGNED> id113out_value;

  HWOffsetFix<48,0,UNSIGNED> id114out_count;
  HWOffsetFix<1,0,UNSIGNED> id114out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id114st_count;

  HWOffsetFix<48,0,UNSIGNED> id116out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id117out_result[2];

  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWOffsetFix<9,0,UNSIGNED> c_hw_fix_9_0_uns_bits;
  const HWOffsetFix<10,0,UNSIGNED> c_hw_fix_10_0_uns_bits;
  const HWOffsetFix<10,0,UNSIGNED> c_hw_fix_10_0_uns_bits_1;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_undef;
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
