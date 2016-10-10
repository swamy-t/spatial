#ifndef TOPKERNEL_H_
#define TOPKERNEL_H_

// #include "KernelManagerBlockSync.h"

#include "StateMachine_impl_K_TopKernel_CounterChain1045_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain1049_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain1057_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain1068_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain1070_sm.h"
#include "StateMachine_impl_K_TopKernel_DRAM1003_void1055_inldSM.h"
#include "StateMachine_impl_K_TopKernel_DRAM1004_void1082_outldSM.h"
#include "StateMachine_impl_K_TopKernel_mainSm.h"
#include "StateMachine_impl_K_TopKernel_metapipe1065_FixedPoint8740_1.h"
#include "StateMachine_impl_K_TopKernel_metapipe1065_FixedPoint8741_2.h"
#include "StateMachine_impl_K_TopKernel_metapipe1065_sm.h"
#include "StateMachine_impl_K_TopKernel_metapipe1084_FixedPoint9020_1.h"
#include "StateMachine_impl_K_TopKernel_metapipe1084_FixedPoint9021_2.h"
#include "StateMachine_impl_K_TopKernel_metapipe1084_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe1063_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe1076_sm.h"
#include "StateMachine_impl_K_TopKernel_reg1050_0.h"
#include "StateMachine_impl_K_TopKernel_reg1077_0.h"
#include "StateMachine_impl_K_TopKernel_seq1086_sm.h"
#include "StateMachine_impl_K_TopKernel_void1053_sm.h"
#include "StateMachine_impl_K_TopKernel_void1080_sm.h"
#include "StateMachine_impl_K_TopKernel_void1088_sm.h"



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
  state_machine::Kernel_TopKernel_CounterChain1045_sm m_sm_CounterChain1045_sm;
  state_machine::Kernel_TopKernel_CounterChain1049_sm m_sm_CounterChain1049_sm;
  state_machine::Kernel_TopKernel_CounterChain1057_sm m_sm_CounterChain1057_sm;
  state_machine::Kernel_TopKernel_CounterChain1068_sm m_sm_CounterChain1068_sm;
  state_machine::Kernel_TopKernel_CounterChain1070_sm m_sm_CounterChain1070_sm;
  state_machine::Kernel_TopKernel_DRAM1003_void1055_inldSM m_sm_DRAM1003_void1055_inldSM;
  state_machine::Kernel_TopKernel_DRAM1004_void1082_outldSM m_sm_DRAM1004_void1082_outldSM;
  state_machine::Kernel_TopKernel_mainSm m_sm_mainSm;
  state_machine::Kernel_TopKernel_metapipe1065_FixedPoint8740_1 m_sm_metapipe1065_FixedPoint8740_1;
  state_machine::Kernel_TopKernel_metapipe1065_FixedPoint8741_2 m_sm_metapipe1065_FixedPoint8741_2;
  state_machine::Kernel_TopKernel_metapipe1065_sm m_sm_metapipe1065_sm;
  state_machine::Kernel_TopKernel_metapipe1084_FixedPoint9020_1 m_sm_metapipe1084_FixedPoint9020_1;
  state_machine::Kernel_TopKernel_metapipe1084_FixedPoint9021_2 m_sm_metapipe1084_FixedPoint9021_2;
  state_machine::Kernel_TopKernel_metapipe1084_sm m_sm_metapipe1084_sm;
  state_machine::Kernel_TopKernel_pipe1063_sm m_sm_pipe1063_sm;
  state_machine::Kernel_TopKernel_pipe1076_sm m_sm_pipe1076_sm;
  state_machine::Kernel_TopKernel_reg1050_0 m_sm_reg1050_0;
  state_machine::Kernel_TopKernel_reg1077_0 m_sm_reg1077_0;
  state_machine::Kernel_TopKernel_seq1086_sm m_sm_seq1086_sm;
  state_machine::Kernel_TopKernel_void1053_sm m_sm_void1053_sm;
  state_machine::Kernel_TopKernel_void1080_sm m_sm_void1080_sm;
  state_machine::Kernel_TopKernel_void1088_sm m_sm_void1088_sm;

  t_port_number m_DRAM1003_void1055_in_cmd;
  t_port_number m_DRAM1004_void1082_out_cmd;
  t_port_number m_DRAM1003_void1055_in;
  t_port_number m_DRAM1004_void1082_out;
  t_port_number m_intrCmd;
  t_port_number m_intrStream;
  HWOffsetFix<17,0,UNSIGNED> id512out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id57out_value;

  HWOffsetFix<1,0,UNSIGNED> id175out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id175out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id175out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id175out_sm_done;

  HWOffsetFix<33,0,UNSIGNED> id508out_value;

  HWOffsetFix<32,0,UNSIGNED> id297out_count;
  HWOffsetFix<1,0,UNSIGNED> id297out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id297st_count;

  HWOffsetFix<1,0,UNSIGNED> id0out_en;

  HWOffsetFix<64,0,UNSIGNED> id1out_cycles;
  HWOffsetFix<1,0,UNSIGNED> id1out_intr_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_run_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id64out_value;

  HWOffsetFix<1,0,UNSIGNED> id62out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id62out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id62out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id361out_value;

  HWOffsetFix<1,0,UNSIGNED> id67out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id67out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id67out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id67out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id365out_value;

  HWOffsetFix<1,0,UNSIGNED> id82out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id82out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id82out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id82out_s2_en;
  HWOffsetFix<1,0,UNSIGNED> id82out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id82out_sm_last;

  HWOffsetFix<1,0,UNSIGNED> id122out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id122out_sm_done;

  HWOffsetFix<16,0,UNSIGNED> id132out_count;
  HWOffsetFix<1,0,UNSIGNED> id132out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id132st_count;

  HWOffsetFix<16,0,UNSIGNED> id511out_value;

  HWOffsetFix<1,0,UNSIGNED> id134out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id111out_value;

  HWOffsetFix<1,0,UNSIGNED> id108out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id108out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id108out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id108out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id430out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id431out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id449out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id450out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id432out_output[4];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id178out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id178out_done;
  HWOffsetFix<1,0,UNSIGNED> id178out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id433out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id434out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id435out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id447out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id238out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id238out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id353out_value;

  HWOffsetFix<1,0,UNSIGNED> id187out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id187out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id187out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id187out_s2_en;
  HWOffsetFix<1,0,UNSIGNED> id187out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id187out_sm_last;

  HWOffsetFix<1,0,UNSIGNED> id213out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id213out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id213out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id213out_sm_done;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id216out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id216out_done;
  HWOffsetFix<1,0,UNSIGNED> id216out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id437out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id438out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id471out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id494out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id230out_value;

  HWOffsetFix<1,0,UNSIGNED> id227out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id227out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id227out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id227out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id439out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id440out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id443out_output[3];

  HWOffsetFix<17,0,UNSIGNED> id510out_value;

  HWOffsetFix<16,0,UNSIGNED> id247out_count;
  HWOffsetFix<1,0,UNSIGNED> id247out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id247st_count;

  HWOffsetFix<16,0,UNSIGNED> id509out_value;

  HWOffsetFix<1,0,UNSIGNED> id249out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id441out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id448out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id446out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id444out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id445out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id451out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id507out_value;

  HWOffsetFix<1,0,UNSIGNED> id137out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id138out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id156out_io_DRAM1003_void1055_in_cmd_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id464out_output[43];

  HWRawBits<1> id366out_value;

  HWRawBits<15> id371out_value;

  HWOffsetFix<8,0,UNSIGNED> id143out_value;

  HWRawBits<8> id376out_value;

  HWOffsetFix<32,0,UNSIGNED> id506out_value;

  HWOffsetFix<1,0,UNSIGNED> id291out_value;

  HWOffsetFix<2,0,UNSIGNED> id290out_value;

  HWOffsetFix<1,0,UNSIGNED> id492out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id491out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id3out_value;

  HWOffsetFix<1,0,UNSIGNED> id5out_value;

  HWOffsetFix<1,0,UNSIGNED> id7out_value;

  HWOffsetFix<1,0,UNSIGNED> id9out_value;

  HWOffsetFix<1,0,UNSIGNED> id11out_value;

  HWOffsetFix<1,0,UNSIGNED> id13out_value;

  HWOffsetFix<1,0,UNSIGNED> id454out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id455out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id4out_value;

  HWOffsetFix<1,0,UNSIGNED> id6out_value;

  HWOffsetFix<1,0,UNSIGNED> id8out_value;

  HWOffsetFix<1,0,UNSIGNED> id10out_value;

  HWOffsetFix<1,0,UNSIGNED> id12out_value;

  HWOffsetFix<1,0,UNSIGNED> id14out_value;

  HWOffsetFix<2,0,UNSIGNED> id2out_curBuf0;
  HWOffsetFix<2,0,UNSIGNED> id2out_curBuf1;

  HWOffsetFix<1,0,UNSIGNED> id463out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id289out_value;

  HWOffsetFix<1,0,UNSIGNED> id18out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id79out_counter0;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id79out_counter1;
  HWOffsetFix<1,0,UNSIGNED> id79out_done;
  HWOffsetFix<1,0,UNSIGNED> id79out_saturated;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id89out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id89out_done;
  HWOffsetFix<1,0,UNSIGNED> id89out_saturated;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id115out_result[2];

  HWOffsetFix<34,5,TWOSCOMPLEMENT> id400out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id461out_output[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id117out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id288out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id16out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id118out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id19out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id19st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id23out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id21out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id24out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id24st_holdreg;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id505out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id125out_result[39];

  HWOffsetFix<32,0,UNSIGNED> id128out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id465out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id504out_value;

  HWOffsetFix<1,0,UNSIGNED> id252out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id253out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id270out_io_DRAM1004_void1082_out_cmd_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id476out_output[42];

  HWRawBits<1> id377out_value;

  HWRawBits<15> id382out_value;

  HWOffsetFix<8,0,UNSIGNED> id257out_value;

  HWRawBits<8> id387out_value;

  HWOffsetFix<32,0,UNSIGNED> id503out_value;

  HWOffsetFix<1,0,UNSIGNED> id295out_value;

  HWOffsetFix<2,0,UNSIGNED> id294out_value;

  HWOffsetFix<1,0,UNSIGNED> id495out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id467out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id30out_value;

  HWOffsetFix<1,0,UNSIGNED> id32out_value;

  HWOffsetFix<1,0,UNSIGNED> id34out_value;

  HWOffsetFix<1,0,UNSIGNED> id36out_value;

  HWOffsetFix<1,0,UNSIGNED> id38out_value;

  HWOffsetFix<1,0,UNSIGNED> id40out_value;

  HWOffsetFix<1,0,UNSIGNED> id468out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id496out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id31out_value;

  HWOffsetFix<1,0,UNSIGNED> id33out_value;

  HWOffsetFix<1,0,UNSIGNED> id35out_value;

  HWOffsetFix<1,0,UNSIGNED> id37out_value;

  HWOffsetFix<1,0,UNSIGNED> id39out_value;

  HWOffsetFix<1,0,UNSIGNED> id41out_value;

  HWOffsetFix<2,0,UNSIGNED> id29out_curBuf0;
  HWOffsetFix<2,0,UNSIGNED> id29out_curBuf1;

  HWOffsetFix<1,0,UNSIGNED> id475out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id293out_value;

  HWOffsetFix<1,0,UNSIGNED> id45out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id197out_curBuf;

  HWOffsetFix<1,0,UNSIGNED> id472out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id201out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id194out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id194out_done;
  HWOffsetFix<1,0,UNSIGNED> id194out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id204out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id202out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id202st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id199out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id200out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id200st_holdreg;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id234out_result[2];

  HWOffsetFix<34,5,TWOSCOMPLEMENT> id404out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id236out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id292out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id43out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id237out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id46out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id46st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id50out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id48out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id51out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id51st_holdreg;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id502out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id241out_result[39];

  HWOffsetFix<32,0,UNSIGNED> id244out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id477out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id283out_io_DRAM1004_void1082_out_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id487out_output[65];

  HWOffsetFix<1,0,UNSIGNED> id100out_curBuf;

  HWOffsetFix<1,0,UNSIGNED> id482out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id104out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id92out_curBuf;

  HWOffsetFix<1,0,UNSIGNED> id480out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id96out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id99out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id97out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id97st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id94out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id95out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id95st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id107out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id105out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id105st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id102out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id103out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id103st_holdreg;

  HWOffsetFix<34,5,TWOSCOMPLEMENT> id408out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id185out_result[2];

  HWOffsetFix<14,0,UNSIGNED> id484out_output[62];

  HWOffsetFix<1,0,UNSIGNED> id483out_output[58];

  HWOffsetFix<1,0,UNSIGNED> id169out_io_DRAM1003_void1055_in_force_disabled;

  HWRawBits<32> id172out_data;

  HWOffsetFix<1,0,UNSIGNED> id172st_read_next_cycle;
  HWRawBits<32> id172st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id493out_output[6];

  HWOffsetFix<34,5,TWOSCOMPLEMENT> id412out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id223out_result[2];

  HWOffsetFix<14,0,UNSIGNED> id486out_output[65];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id337out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id337sta_ram_store[9216];

  std::string format_string_TopKernel_1 (const char* _format_arg_format_string);
  HWOffsetFix<1,0,UNSIGNED> id497out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id501out_value;

  HWOffsetFix<1,0,UNSIGNED> id300out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id301out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id317out_io_intrCmd_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id498out_output[2];

  HWRawBits<15> id392out_value;

  HWOffsetFix<8,0,UNSIGNED> id394out_value;

  HWRawBits<8> id396out_value;

  HWRawBits<32> id397out_value;

  HWOffsetFix<1,0,UNSIGNED> id330out_value;

  HWOffsetFix<1,0,UNSIGNED> id333out_io_intrStream_force_disabled;

  HWOffsetFix<32,0,UNSIGNED> id332out_value;

  HWOffsetFix<1,0,UNSIGNED> id342out_value;

  HWOffsetFix<1,0,UNSIGNED> id500out_value;

  HWOffsetFix<49,0,UNSIGNED> id339out_value;

  HWOffsetFix<48,0,UNSIGNED> id340out_count;
  HWOffsetFix<1,0,UNSIGNED> id340out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id340st_count;

  HWOffsetFix<1,0,UNSIGNED> id499out_value;

  HWOffsetFix<49,0,UNSIGNED> id345out_value;

  HWOffsetFix<48,0,UNSIGNED> id346out_count;
  HWOffsetFix<1,0,UNSIGNED> id346out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id346st_count;

  HWOffsetFix<48,0,UNSIGNED> id348out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id349out_result[2];

  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_1;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_1;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_3;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits_1;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits_2;
  const HWRawBits<1> c_hw_bit_1_bits;
  const HWRawBits<15> c_hw_bit_15_bits;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits;
  const HWRawBits<8> c_hw_bit_8_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_2;
  const HWOffsetFix<2,0,UNSIGNED> c_hw_fix_2_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_undef;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_3;
  const HWOffsetFix<14,0,UNSIGNED> c_hw_fix_14_0_uns_undef;
  const HWRawBits<32> c_hw_bit_32_undef;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_4;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits_1;
  const HWRawBits<32> c_hw_bit_32_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_5;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* TOPKERNEL_H_ */
