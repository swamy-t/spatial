#ifndef TOPKERNEL_H_
#define TOPKERNEL_H_

// #include "KernelManagerBlockSync.h"

#include "StateMachine_impl_K_TopKernel_CounterChain1245_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain1249_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain1260_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain1271_sm.h"
#include "StateMachine_impl_K_TopKernel_DRAM1198_void1247_inldSM.h"
#include "StateMachine_impl_K_TopKernel_DRAM1199_void1278_outldSM.h"
#include "StateMachine_impl_K_TopKernel_mainSm.h"
#include "StateMachine_impl_K_TopKernel_pipe1255_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe1268_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe1277_sm.h"
#include "StateMachine_impl_K_TopKernel_seq1282_sm.h"
#include "StateMachine_impl_K_TopKernel_void1257_sm.h"
#include "StateMachine_impl_K_TopKernel_void1280_sm.h"
#include "StateMachine_impl_K_TopKernel_void1284_sm.h"



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
  state_machine::Kernel_TopKernel_CounterChain1245_sm m_sm_CounterChain1245_sm;
  state_machine::Kernel_TopKernel_CounterChain1249_sm m_sm_CounterChain1249_sm;
  state_machine::Kernel_TopKernel_CounterChain1260_sm m_sm_CounterChain1260_sm;
  state_machine::Kernel_TopKernel_CounterChain1271_sm m_sm_CounterChain1271_sm;
  state_machine::Kernel_TopKernel_DRAM1198_void1247_inldSM m_sm_DRAM1198_void1247_inldSM;
  state_machine::Kernel_TopKernel_DRAM1199_void1278_outldSM m_sm_DRAM1199_void1278_outldSM;
  state_machine::Kernel_TopKernel_mainSm m_sm_mainSm;
  state_machine::Kernel_TopKernel_pipe1255_sm m_sm_pipe1255_sm;
  state_machine::Kernel_TopKernel_pipe1268_sm m_sm_pipe1268_sm;
  state_machine::Kernel_TopKernel_pipe1277_sm m_sm_pipe1277_sm;
  state_machine::Kernel_TopKernel_seq1282_sm m_sm_seq1282_sm;
  state_machine::Kernel_TopKernel_void1257_sm m_sm_void1257_sm;
  state_machine::Kernel_TopKernel_void1280_sm m_sm_void1280_sm;
  state_machine::Kernel_TopKernel_void1284_sm m_sm_void1284_sm;

  t_port_number m_DRAM1198_void1247_in_cmd;
  t_port_number m_DRAM1199_void1278_out_cmd;
  t_port_number m_DRAM1198_void1247_in;
  t_port_number m_DRAM1199_void1278_out;
  t_port_number m_intrCmd;
  t_port_number m_intrStream;
  HWOffsetFix<17,0,UNSIGNED> id314out_value;

  HWOffsetFix<1,0,UNSIGNED> id32out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id32out_sm_done;

  HWOffsetFix<16,0,UNSIGNED> id42out_count;
  HWOffsetFix<1,0,UNSIGNED> id42out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id42st_count;

  HWOffsetFix<16,0,UNSIGNED> id313out_value;

  HWOffsetFix<1,0,UNSIGNED> id44out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id8out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id88out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id88out_done;
  HWOffsetFix<1,0,UNSIGNED> id88out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id85out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id85out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id85out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id85out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id266out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id267out_output[55];

  HWOffsetFix<1,0,UNSIGNED> id268out_output[54];

  HWOffsetFix<32,0,UNSIGNED> id26out_value;

  HWOffsetFix<1,0,UNSIGNED> id24out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id24out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id24out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id24out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id24out_sm_last;

  HWOffsetFix<1,0,UNSIGNED> id269out_output[54];

  HWOffsetFix<1,0,UNSIGNED> id92out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id92out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id92out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id92out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id270out_output[60];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id95out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id95out_done;
  HWOffsetFix<1,0,UNSIGNED> id95out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id271out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id272out_output[60];

  HWOffsetFix<1,0,UNSIGNED> id14out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id14out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id14out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id14out_s2_en;
  HWOffsetFix<1,0,UNSIGNED> id14out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id273out_output[60];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id110out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id110out_done;
  HWOffsetFix<1,0,UNSIGNED> id110out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id107out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id107out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id107out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id107out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id274out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id275out_output[64];

  HWOffsetFix<1,0,UNSIGNED> id276out_output[63];

  HWOffsetFix<1,0,UNSIGNED> id116out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id116out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id104out_value;

  HWOffsetFix<1,0,UNSIGNED> id102out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id102out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id102out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id102out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id102out_sm_last;

  HWOffsetFix<1,0,UNSIGNED> id277out_output[63];

  HWOffsetFix<17,0,UNSIGNED> id312out_value;

  HWOffsetFix<16,0,UNSIGNED> id125out_count;
  HWOffsetFix<1,0,UNSIGNED> id125out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id125st_count;

  HWOffsetFix<16,0,UNSIGNED> id311out_value;

  HWOffsetFix<1,0,UNSIGNED> id127out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id278out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id281out_output[2];

  HWOffsetFix<33,0,UNSIGNED> id310out_value;

  HWOffsetFix<32,0,UNSIGNED> id167out_count;
  HWOffsetFix<1,0,UNSIGNED> id167out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id167st_count;

  HWOffsetFix<1,0,UNSIGNED> id0out_en;

  HWOffsetFix<64,0,UNSIGNED> id1out_cycles;
  HWOffsetFix<1,0,UNSIGNED> id1out_intr_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_run_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id279out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id11out_value;

  HWOffsetFix<1,0,UNSIGNED> id9out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id9out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id9out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id280out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id282out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_argin1238;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id221out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id19out_result[39];

  HWOffsetFix<1,0,UNSIGNED> id283out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id284out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id285out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id309out_value;

  HWOffsetFix<1,0,UNSIGNED> id47out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id48out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id66out_io_DRAM1198_void1247_in_cmd_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id286out_output[35];

  HWRawBits<1> id222out_value;

  HWRawBits<15> id227out_value;

  HWOffsetFix<8,0,UNSIGNED> id53out_value;

  HWRawBits<8> id232out_value;

  HWOffsetFix<32,0,UNSIGNED> id308out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id21out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id21out_done;
  HWOffsetFix<1,0,UNSIGNED> id21out_saturated;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id307out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id35out_result[39];

  HWOffsetFix<32,0,UNSIGNED> id38out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id287out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id306out_value;

  HWOffsetFix<1,0,UNSIGNED> id130out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id131out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id148out_io_DRAM1199_void1278_out_cmd_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id288out_output[36];

  HWRawBits<1> id233out_value;

  HWRawBits<15> id238out_value;

  HWOffsetFix<8,0,UNSIGNED> id135out_value;

  HWRawBits<8> id243out_value;

  HWOffsetFix<32,0,UNSIGNED> id305out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id304out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id119out_result[39];

  HWOffsetFix<32,0,UNSIGNED> id122out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id161out_io_DRAM1199_void1278_out_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id294out_output[3];

  HWOffsetFix<7,0,UNSIGNED> id292out_output[5];

  HWOffsetFix<7,0,UNSIGNED> id290out_output[5];

  HWOffsetFix<1,0,UNSIGNED> id79out_io_DRAM1198_void1247_in_force_disabled;

  HWRawBits<32> id82out_data;

  HWOffsetFix<1,0,UNSIGNED> id82st_read_next_cycle;
  HWRawBits<32> id82st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id299out_output[5];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id207out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id207sta_ram_store[96];

  std::string format_string_TopKernel_1 (const char* _format_arg_format_string);
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id3out_argin1239;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id100out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id293out_output[5];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id208out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id208sta_ram_store[96];

  std::string format_string_TopKernel_2 (const char* _format_arg_format_string);
  HWOffsetFix<1,0,UNSIGNED> id300out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id303out_value;

  HWOffsetFix<1,0,UNSIGNED> id170out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id171out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id187out_io_intrCmd_force_disabled;

  HWRawBits<1> id297out_output[2];

  HWRawBits<15> id248out_value;

  HWOffsetFix<8,0,UNSIGNED> id250out_value;

  HWRawBits<8> id252out_value;

  HWRawBits<32> id253out_value;

  HWOffsetFix<1,0,UNSIGNED> id200out_value;

  HWOffsetFix<1,0,UNSIGNED> id203out_io_intrStream_force_disabled;

  HWOffsetFix<32,0,UNSIGNED> id202out_value;

  HWOffsetFix<1,0,UNSIGNED> id213out_value;

  HWOffsetFix<1,0,UNSIGNED> id302out_value;

  HWOffsetFix<49,0,UNSIGNED> id210out_value;

  HWOffsetFix<48,0,UNSIGNED> id211out_count;
  HWOffsetFix<1,0,UNSIGNED> id211out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id211st_count;

  HWOffsetFix<1,0,UNSIGNED> id301out_value;

  HWOffsetFix<49,0,UNSIGNED> id216out_value;

  HWOffsetFix<48,0,UNSIGNED> id217out_count;
  HWOffsetFix<1,0,UNSIGNED> id217out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id217st_count;

  HWOffsetFix<48,0,UNSIGNED> id219out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id220out_result[2];

  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_1;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
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
