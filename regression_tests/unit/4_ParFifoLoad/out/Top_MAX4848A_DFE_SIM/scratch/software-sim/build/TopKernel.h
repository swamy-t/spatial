#ifndef TOPKERNEL_H_
#define TOPKERNEL_H_

// #include "KernelManagerBlockSync.h"

#include "StateMachine_impl_K_TopKernel_CounterChain1919_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain1930_sm.h"
#include "StateMachine_impl_K_TopKernel_DRAM1836_void1920_inldSM.h"
#include "StateMachine_impl_K_TopKernel_DRAM1837_void1923_inldSM.h"
#include "StateMachine_impl_K_TopKernel_mainSm.h"
#include "StateMachine_impl_K_TopKernel_metapipe1946_FixedPoint16140_1.h"
#include "StateMachine_impl_K_TopKernel_metapipe1946_FixedPoint16141_2.h"
#include "StateMachine_impl_K_TopKernel_metapipe1946_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe1940_sm.h"
#include "StateMachine_impl_K_TopKernel_reg1928_1.h"
#include "StateMachine_impl_K_TopKernel_void1922_sm.h"
#include "StateMachine_impl_K_TopKernel_void1925_sm.h"
#include "StateMachine_impl_K_TopKernel_void1927_sm.h"
#include "StateMachine_impl_K_TopKernel_void1944_sm.h"
#include "StateMachine_impl_K_TopKernel_void1948_sm.h"



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
  state_machine::Kernel_TopKernel_CounterChain1919_sm m_sm_CounterChain1919_sm;
  state_machine::Kernel_TopKernel_CounterChain1930_sm m_sm_CounterChain1930_sm;
  state_machine::Kernel_TopKernel_DRAM1836_void1920_inldSM m_sm_DRAM1836_void1920_inldSM;
  state_machine::Kernel_TopKernel_DRAM1837_void1923_inldSM m_sm_DRAM1837_void1923_inldSM;
  state_machine::Kernel_TopKernel_mainSm m_sm_mainSm;
  state_machine::Kernel_TopKernel_metapipe1946_FixedPoint16140_1 m_sm_metapipe1946_FixedPoint16140_1;
  state_machine::Kernel_TopKernel_metapipe1946_FixedPoint16141_2 m_sm_metapipe1946_FixedPoint16141_2;
  state_machine::Kernel_TopKernel_metapipe1946_sm m_sm_metapipe1946_sm;
  state_machine::Kernel_TopKernel_pipe1940_sm m_sm_pipe1940_sm;
  state_machine::Kernel_TopKernel_reg1928_1 m_sm_reg1928_1;
  state_machine::Kernel_TopKernel_void1922_sm m_sm_void1922_sm;
  state_machine::Kernel_TopKernel_void1925_sm m_sm_void1925_sm;
  state_machine::Kernel_TopKernel_void1927_sm m_sm_void1927_sm;
  state_machine::Kernel_TopKernel_void1944_sm m_sm_void1944_sm;
  state_machine::Kernel_TopKernel_void1948_sm m_sm_void1948_sm;

  t_port_number m_DRAM1836_void1920_in_cmd;
  t_port_number m_DRAM1837_void1923_in_cmd;
  t_port_number m_DRAM1836_void1920_in;
  t_port_number m_DRAM1837_void1923_in;
  t_port_number m_intrCmd;
  t_port_number m_intrStream;
  HWOffsetFix<17,0,UNSIGNED> id372out_value;

  HWOffsetFix<1,0,UNSIGNED> id76out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id76out_sm_done;

  HWOffsetFix<16,0,UNSIGNED> id86out_count;
  HWOffsetFix<1,0,UNSIGNED> id86out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id86st_count;

  HWOffsetFix<16,0,UNSIGNED> id371out_value;

  HWOffsetFix<1,0,UNSIGNED> id88out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id70out_value;

  HWOffsetFix<1,0,UNSIGNED> id68out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id68out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id68out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id68out_sm_last;

  HWOffsetFix<17,0,UNSIGNED> id370out_value;

  HWOffsetFix<1,0,UNSIGNED> id137out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id137out_sm_done;

  HWOffsetFix<16,0,UNSIGNED> id147out_count;
  HWOffsetFix<1,0,UNSIGNED> id147out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id147st_count;

  HWOffsetFix<16,0,UNSIGNED> id369out_value;

  HWOffsetFix<1,0,UNSIGNED> id149out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id131out_value;

  HWOffsetFix<1,0,UNSIGNED> id129out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id129out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id129out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id129out_sm_last;

  HWOffsetFix<1,0,UNSIGNED> id312out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id198out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id198out_done;
  HWOffsetFix<1,0,UNSIGNED> id198out_saturated;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id32out_value;

  HWOffsetFix<1,0,UNSIGNED> id190out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id190out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id190out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id190out_sm_done;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id207out_value;

  HWOffsetFix<1,0,UNSIGNED> id204out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id204out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id204out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id204out_sm_done;

  HWOffsetFix<33,0,UNSIGNED> id368out_value;

  HWOffsetFix<32,0,UNSIGNED> id217out_count;
  HWOffsetFix<1,0,UNSIGNED> id217out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id217st_count;

  HWOffsetFix<1,0,UNSIGNED> id0out_en;

  HWOffsetFix<64,0,UNSIGNED> id1out_cycles;
  HWOffsetFix<1,0,UNSIGNED> id1out_intr_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_run_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id37out_value;

  HWOffsetFix<1,0,UNSIGNED> id35out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id35out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id35out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id40out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id40out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id40out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id40out_s2_en;
  HWOffsetFix<1,0,UNSIGNED> id40out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id40out_sm_last;

  HWOffsetFix<1,0,UNSIGNED> id66out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id66out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id66out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id313out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id326out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id338out_output[2];

  HWOffsetFix<9,0,UNSIGNED> id358out_value;

  HWOffsetFix<9,0,UNSIGNED> id194out_count;
  HWOffsetFix<1,0,UNSIGNED> id194out_wrap;

  HWOffsetFix<10,0,UNSIGNED> id194st_count;

  HWOffsetFix<1,0,UNSIGNED> id197out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id315out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id316out_output[39];

  HWOffsetFix<1,0,UNSIGNED> id317out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id318out_output[37];

  HWOffsetFix<1,0,UNSIGNED> id319out_output[38];

  HWOffsetFix<1,0,UNSIGNED> id320out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id321out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id322out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id325out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id323out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id324out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_argin1833;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id269out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id45out_result[39];

  HWOffsetFix<1,0,UNSIGNED> id327out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id328out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id329out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id367out_value;

  HWOffsetFix<1,0,UNSIGNED> id91out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id92out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id330out_output[35];

  HWOffsetFix<1,0,UNSIGNED> id110out_io_DRAM1836_void1920_in_cmd_force_disabled;

  HWRawBits<1> id270out_value;

  HWRawBits<15> id275out_value;

  HWOffsetFix<8,0,UNSIGNED> id97out_value;

  HWRawBits<8> id280out_value;

  HWOffsetFix<32,0,UNSIGNED> id366out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id47out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id47out_done;
  HWOffsetFix<1,0,UNSIGNED> id47out_saturated;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id365out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id79out_result[39];

  HWOffsetFix<32,0,UNSIGNED> id82out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id331out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id364out_value;

  HWOffsetFix<1,0,UNSIGNED> id152out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id153out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id332out_output[35];

  HWOffsetFix<1,0,UNSIGNED> id171out_io_DRAM1837_void1923_in_cmd_force_disabled;

  HWRawBits<1> id281out_value;

  HWRawBits<15> id286out_value;

  HWOffsetFix<8,0,UNSIGNED> id158out_value;

  HWRawBits<8> id291out_value;

  HWOffsetFix<32,0,UNSIGNED> id363out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id362out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id140out_result[39];

  HWOffsetFix<32,0,UNSIGNED> id143out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id348out_output[65];

  HWOffsetFix<1,0,UNSIGNED> id215out_value;

  HWOffsetFix<2,0,UNSIGNED> id214out_value;

  HWOffsetFix<1,0,UNSIGNED> id352out_output[24];

  HWOffsetFix<1,0,UNSIGNED> id353out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id334out_output[63];

  HWOffsetFix<1,0,UNSIGNED> id4out_value;

  HWOffsetFix<1,0,UNSIGNED> id6out_value;

  HWOffsetFix<1,0,UNSIGNED> id8out_value;

  HWOffsetFix<1,0,UNSIGNED> id10out_value;

  HWOffsetFix<1,0,UNSIGNED> id12out_value;

  HWOffsetFix<1,0,UNSIGNED> id14out_value;

  HWOffsetFix<1,0,UNSIGNED> id356out_output[26];

  HWOffsetFix<1,0,UNSIGNED> id357out_output[62];

  HWOffsetFix<1,0,UNSIGNED> id5out_value;

  HWOffsetFix<1,0,UNSIGNED> id7out_value;

  HWOffsetFix<1,0,UNSIGNED> id9out_value;

  HWOffsetFix<1,0,UNSIGNED> id11out_value;

  HWOffsetFix<1,0,UNSIGNED> id13out_value;

  HWOffsetFix<1,0,UNSIGNED> id15out_value;

  HWOffsetFix<2,0,UNSIGNED> id3out_curBuf0;
  HWOffsetFix<2,0,UNSIGNED> id3out_curBuf1;

  HWOffsetFix<1,0,UNSIGNED> id347out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id213out_value;

  HWOffsetFix<1,0,UNSIGNED> id19out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id339out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id196out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id340out_output[16];

  HWOffsetFix<1,0,UNSIGNED> id123out_io_DRAM1836_void1920_in_force_disabled;

  HWRawBits<32> id126out_data;

  HWOffsetFix<1,0,UNSIGNED> id126st_read_next_cycle;
  HWRawBits<32> id126st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id184out_io_DRAM1837_void1923_in_force_disabled;

  HWRawBits<32> id187out_data;

  HWOffsetFix<1,0,UNSIGNED> id187st_read_next_cycle;
  HWRawBits<32> id187st_last_read_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id203out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id200out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id345out_output[23];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id201out_accumulate[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id201st_hold_reg;
  HWOffsetFix<1,0,UNSIGNED> id201st_clear_reg;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id212out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id17out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id202out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id20out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id20st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id24out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id22out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id25out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id25st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id354out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id361out_value;

  HWOffsetFix<1,0,UNSIGNED> id220out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id221out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id237out_io_intrCmd_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id355out_output[2];

  HWRawBits<15> id296out_value;

  HWOffsetFix<8,0,UNSIGNED> id298out_value;

  HWRawBits<8> id300out_value;

  HWRawBits<32> id301out_value;

  HWOffsetFix<1,0,UNSIGNED> id250out_value;

  HWOffsetFix<1,0,UNSIGNED> id253out_io_intrStream_force_disabled;

  HWOffsetFix<32,0,UNSIGNED> id252out_value;

  HWOffsetFix<1,0,UNSIGNED> id261out_value;

  HWOffsetFix<1,0,UNSIGNED> id360out_value;

  HWOffsetFix<49,0,UNSIGNED> id258out_value;

  HWOffsetFix<48,0,UNSIGNED> id259out_count;
  HWOffsetFix<1,0,UNSIGNED> id259out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id259st_count;

  HWOffsetFix<1,0,UNSIGNED> id359out_value;

  HWOffsetFix<49,0,UNSIGNED> id264out_value;

  HWOffsetFix<48,0,UNSIGNED> id265out_count;
  HWOffsetFix<1,0,UNSIGNED> id265out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id265st_count;

  HWOffsetFix<48,0,UNSIGNED> id267out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id268out_result[2];

  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_1;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_2;
  const HWOffsetFix<9,0,UNSIGNED> c_hw_fix_9_0_uns_bits;
  const HWOffsetFix<10,0,UNSIGNED> c_hw_fix_10_0_uns_bits;
  const HWOffsetFix<10,0,UNSIGNED> c_hw_fix_10_0_uns_bits_1;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_undef;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits_1;
  const HWRawBits<1> c_hw_bit_1_bits;
  const HWRawBits<15> c_hw_bit_15_bits;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits;
  const HWRawBits<8> c_hw_bit_8_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_2;
  const HWOffsetFix<2,0,UNSIGNED> c_hw_fix_2_0_uns_bits;
  const HWRawBits<32> c_hw_bit_32_undef;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_3;
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
