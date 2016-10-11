#ifndef TOPKERNEL_H_
#define TOPKERNEL_H_

// #include "KernelManagerBlockSync.h"

#include "StateMachine_impl_K_TopKernel_CounterChain827_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain840_sm.h"
#include "StateMachine_impl_K_TopKernel_DRAM783_void825_inldSM.h"
#include "StateMachine_impl_K_TopKernel_mainSm.h"
#include "StateMachine_impl_K_TopKernel_pipe833_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe847_sm.h"
#include "StateMachine_impl_K_TopKernel_void835_sm.h"
#include "StateMachine_impl_K_TopKernel_void837_sm.h"
#include "StateMachine_impl_K_TopKernel_void851_sm.h"
#include "StateMachine_impl_K_TopKernel_void853_sm.h"



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
  state_machine::Kernel_TopKernel_CounterChain827_sm m_sm_CounterChain827_sm;
  state_machine::Kernel_TopKernel_CounterChain840_sm m_sm_CounterChain840_sm;
  state_machine::Kernel_TopKernel_DRAM783_void825_inldSM m_sm_DRAM783_void825_inldSM;
  state_machine::Kernel_TopKernel_mainSm m_sm_mainSm;
  state_machine::Kernel_TopKernel_pipe833_sm m_sm_pipe833_sm;
  state_machine::Kernel_TopKernel_pipe847_sm m_sm_pipe847_sm;
  state_machine::Kernel_TopKernel_void835_sm m_sm_void835_sm;
  state_machine::Kernel_TopKernel_void837_sm m_sm_void837_sm;
  state_machine::Kernel_TopKernel_void851_sm m_sm_void851_sm;
  state_machine::Kernel_TopKernel_void853_sm m_sm_void853_sm;

  t_port_number m_DRAM783_void825_in_cmd;
  t_port_number m_DRAM783_void825_in;
  t_port_number m_intrCmd;
  t_port_number m_intrStream;
  HWOffsetFix<17,0,UNSIGNED> id253out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id6out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id91out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id91out_done;
  HWOffsetFix<1,0,UNSIGNED> id91out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id88out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id88out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id88out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id88out_sm_done;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id103out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id103out_done;
  HWOffsetFix<1,0,UNSIGNED> id103out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id95out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id95out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id95out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id95out_sm_done;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id113out_value;

  HWOffsetFix<1,0,UNSIGNED> id110out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id110out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id110out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id110out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id0out_en;

  HWOffsetFix<64,0,UNSIGNED> id1out_cycles;
  HWOffsetFix<1,0,UNSIGNED> id1out_intr_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_run_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id11out_value;

  HWOffsetFix<1,0,UNSIGNED> id9out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id9out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id9out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id9out_s2_en;
  HWOffsetFix<1,0,UNSIGNED> id9out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id16out_value;

  HWOffsetFix<1,0,UNSIGNED> id14out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id14out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id14out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id14out_sm_last;

  HWOffsetFix<32,0,UNSIGNED> id21out_value;

  HWOffsetFix<1,0,UNSIGNED> id19out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id19out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id19out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id19out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id19out_sm_last;

  HWOffsetFix<1,0,UNSIGNED> id27out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id27out_sm_done;

  HWOffsetFix<16,0,UNSIGNED> id45out_count;
  HWOffsetFix<1,0,UNSIGNED> id45out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id45st_count;

  HWOffsetFix<16,0,UNSIGNED> id252out_value;

  HWOffsetFix<1,0,UNSIGNED> id47out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id230out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id214out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id215out_output[20];

  HWOffsetFix<1,0,UNSIGNED> id216out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id217out_output[18];

  HWOffsetFix<1,0,UNSIGNED> id218out_output[19];

  HWOffsetFix<1,0,UNSIGNED> id219out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id220out_output[2];

  HWOffsetFix<9,0,UNSIGNED> id246out_value;

  HWOffsetFix<9,0,UNSIGNED> id99out_count;
  HWOffsetFix<1,0,UNSIGNED> id99out_wrap;

  HWOffsetFix<10,0,UNSIGNED> id99st_count;

  HWOffsetFix<1,0,UNSIGNED> id221out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id102out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id222out_output[24];

  HWOffsetFix<1,0,UNSIGNED> id223out_output[23];

  HWOffsetFix<1,0,UNSIGNED> id224out_output[23];

  HWOffsetFix<1,0,UNSIGNED> id225out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id226out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id227out_output[2];

  HWOffsetFix<33,0,UNSIGNED> id251out_value;

  HWOffsetFix<32,0,UNSIGNED> id119out_count;
  HWOffsetFix<1,0,UNSIGNED> id119out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id119st_count;

  HWOffsetFix<1,0,UNSIGNED> id228out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id229out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id231out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id250out_value;

  HWOffsetFix<1,0,UNSIGNED> id50out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id51out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id69out_io_DRAM783_void825_in_cmd_force_disabled;

  HWRawBits<1> id175out_value;

  HWRawBits<15> id180out_value;

  HWOffsetFix<8,0,UNSIGNED> id56out_value;

  HWRawBits<8> id185out_value;

  HWRawBits<32> id189out_value;

  HWOffsetFix<1,0,UNSIGNED> id238out_output[28];

  HWOffsetFix<1,0,UNSIGNED> id244out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id245out_output[2];

  HWOffsetFix<8,0,UNSIGNED> id232out_output[5];

  HWOffsetFix<1,0,UNSIGNED> id82out_io_DRAM783_void825_in_force_disabled;

  HWRawBits<32> id85out_data;

  HWOffsetFix<1,0,UNSIGNED> id85st_read_next_cycle;
  HWRawBits<32> id85st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id243out_output[5];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id159out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id159sta_ram_store[155];

  std::string format_string_TopKernel_1 (const char* _format_arg_format_string);
  HWOffsetFix<1,0,UNSIGNED> id107out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id236out_output[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id108out_accumulate[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id108st_hold_reg;
  HWOffsetFix<1,0,UNSIGNED> id108st_clear_reg;

  HWOffsetFix<1,0,UNSIGNED> id109out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id239out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id249out_value;

  HWOffsetFix<1,0,UNSIGNED> id122out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id123out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id139out_io_intrCmd_force_disabled;

  HWRawBits<1> id241out_output[2];

  HWRawBits<15> id194out_value;

  HWOffsetFix<8,0,UNSIGNED> id196out_value;

  HWRawBits<8> id198out_value;

  HWRawBits<32> id199out_value;

  HWOffsetFix<1,0,UNSIGNED> id152out_value;

  HWOffsetFix<1,0,UNSIGNED> id155out_io_intrStream_force_disabled;

  HWOffsetFix<32,0,UNSIGNED> id154out_value;

  HWOffsetFix<1,0,UNSIGNED> id164out_value;

  HWOffsetFix<1,0,UNSIGNED> id248out_value;

  HWOffsetFix<49,0,UNSIGNED> id161out_value;

  HWOffsetFix<48,0,UNSIGNED> id162out_count;
  HWOffsetFix<1,0,UNSIGNED> id162out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id162st_count;

  HWOffsetFix<1,0,UNSIGNED> id247out_value;

  HWOffsetFix<49,0,UNSIGNED> id167out_value;

  HWOffsetFix<48,0,UNSIGNED> id168out_count;
  HWOffsetFix<1,0,UNSIGNED> id168out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id168st_count;

  HWOffsetFix<48,0,UNSIGNED> id170out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id171out_result[2];

  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_1;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWOffsetFix<9,0,UNSIGNED> c_hw_fix_9_0_uns_bits;
  const HWOffsetFix<10,0,UNSIGNED> c_hw_fix_10_0_uns_bits;
  const HWOffsetFix<10,0,UNSIGNED> c_hw_fix_10_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_2;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits_1;
  const HWRawBits<1> c_hw_bit_1_bits;
  const HWRawBits<15> c_hw_bit_15_bits;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits;
  const HWRawBits<8> c_hw_bit_8_bits;
  const HWRawBits<32> c_hw_bit_32_bits;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_undef;
  const HWRawBits<32> c_hw_bit_32_undef;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_undef;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
  const HWRawBits<1> c_hw_bit_1_undef;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits_1;
  const HWRawBits<8> c_hw_bit_8_bits_1;
  const HWRawBits<32> c_hw_bit_32_bits_1;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_2;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* TOPKERNEL_H_ */
