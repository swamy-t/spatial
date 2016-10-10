#ifndef TOPKERNEL_H_
#define TOPKERNEL_H_

// #include "KernelManagerBlockSync.h"

#include "StateMachine_impl_K_TopKernel_CounterChain4374_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain4377_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain4386_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain4402_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain4414_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain4417_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain4437_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain4440_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain4460_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain4462_sm.h"
#include "StateMachine_impl_K_TopKernel_CounterChain4479_sm.h"
#include "StateMachine_impl_K_TopKernel_DRAM4323_void4384_inldSM.h"
#include "StateMachine_impl_K_TopKernel_DRAM4324_void4400_inldSM.h"
#include "StateMachine_impl_K_TopKernel_DRAM4325_void4486_outldSM.h"
#include "StateMachine_impl_K_TopKernel_mainSm.h"
#include "StateMachine_impl_K_TopKernel_metapipe4396_FixedPoint36450_1.h"
#include "StateMachine_impl_K_TopKernel_metapipe4396_FixedPoint36451_2.h"
#include "StateMachine_impl_K_TopKernel_metapipe4396_sm.h"
#include "StateMachine_impl_K_TopKernel_metapipe4435_FixedPoint36890_1.h"
#include "StateMachine_impl_K_TopKernel_metapipe4435_sm.h"
#include "StateMachine_impl_K_TopKernel_metapipe4458_FixedPoint37320_1.h"
#include "StateMachine_impl_K_TopKernel_metapipe4458_sm.h"
#include "StateMachine_impl_K_TopKernel_metapipe4474_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe4394_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe4408_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe4427_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe4450_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe4472_sm.h"
#include "StateMachine_impl_K_TopKernel_pipe4485_sm.h"
#include "StateMachine_impl_K_TopKernel_reg4378_0.h"
#include "StateMachine_impl_K_TopKernel_reg4378_1.h"
#include "StateMachine_impl_K_TopKernel_reg4415_1.h"
#include "StateMachine_impl_K_TopKernel_reg4438_1.h"
#include "StateMachine_impl_K_TopKernel_seq4476_sm.h"
#include "StateMachine_impl_K_TopKernel_void4381_sm.h"
#include "StateMachine_impl_K_TopKernel_void4398_sm.h"
#include "StateMachine_impl_K_TopKernel_void4410_sm.h"
#include "StateMachine_impl_K_TopKernel_void4412_sm.h"
#include "StateMachine_impl_K_TopKernel_void4433_sm.h"
#include "StateMachine_impl_K_TopKernel_void4456_sm.h"
#include "StateMachine_impl_K_TopKernel_void4488_sm.h"
#include "StateMachine_impl_K_TopKernel_void4490_sm.h"

#include "TopKernel_exec1.h"


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
  state_machine::Kernel_TopKernel_CounterChain4374_sm m_sm_CounterChain4374_sm;
  state_machine::Kernel_TopKernel_CounterChain4377_sm m_sm_CounterChain4377_sm;
  state_machine::Kernel_TopKernel_CounterChain4386_sm m_sm_CounterChain4386_sm;
  state_machine::Kernel_TopKernel_CounterChain4402_sm m_sm_CounterChain4402_sm;
  state_machine::Kernel_TopKernel_CounterChain4414_sm m_sm_CounterChain4414_sm;
  state_machine::Kernel_TopKernel_CounterChain4417_sm m_sm_CounterChain4417_sm;
  state_machine::Kernel_TopKernel_CounterChain4437_sm m_sm_CounterChain4437_sm;
  state_machine::Kernel_TopKernel_CounterChain4440_sm m_sm_CounterChain4440_sm;
  state_machine::Kernel_TopKernel_CounterChain4460_sm m_sm_CounterChain4460_sm;
  state_machine::Kernel_TopKernel_CounterChain4462_sm m_sm_CounterChain4462_sm;
  state_machine::Kernel_TopKernel_CounterChain4479_sm m_sm_CounterChain4479_sm;
  state_machine::Kernel_TopKernel_DRAM4323_void4384_inldSM m_sm_DRAM4323_void4384_inldSM;
  state_machine::Kernel_TopKernel_DRAM4324_void4400_inldSM m_sm_DRAM4324_void4400_inldSM;
  state_machine::Kernel_TopKernel_DRAM4325_void4486_outldSM m_sm_DRAM4325_void4486_outldSM;
  state_machine::Kernel_TopKernel_mainSm m_sm_mainSm;
  state_machine::Kernel_TopKernel_metapipe4396_FixedPoint36450_1 m_sm_metapipe4396_FixedPoint36450_1;
  state_machine::Kernel_TopKernel_metapipe4396_FixedPoint36451_2 m_sm_metapipe4396_FixedPoint36451_2;
  state_machine::Kernel_TopKernel_metapipe4396_sm m_sm_metapipe4396_sm;
  state_machine::Kernel_TopKernel_metapipe4435_FixedPoint36890_1 m_sm_metapipe4435_FixedPoint36890_1;
  state_machine::Kernel_TopKernel_metapipe4435_sm m_sm_metapipe4435_sm;
  state_machine::Kernel_TopKernel_metapipe4458_FixedPoint37320_1 m_sm_metapipe4458_FixedPoint37320_1;
  state_machine::Kernel_TopKernel_metapipe4458_sm m_sm_metapipe4458_sm;
  state_machine::Kernel_TopKernel_metapipe4474_sm m_sm_metapipe4474_sm;
  state_machine::Kernel_TopKernel_pipe4394_sm m_sm_pipe4394_sm;
  state_machine::Kernel_TopKernel_pipe4408_sm m_sm_pipe4408_sm;
  state_machine::Kernel_TopKernel_pipe4427_sm m_sm_pipe4427_sm;
  state_machine::Kernel_TopKernel_pipe4450_sm m_sm_pipe4450_sm;
  state_machine::Kernel_TopKernel_pipe4472_sm m_sm_pipe4472_sm;
  state_machine::Kernel_TopKernel_pipe4485_sm m_sm_pipe4485_sm;
  state_machine::Kernel_TopKernel_reg4378_0 m_sm_reg4378_0;
  state_machine::Kernel_TopKernel_reg4378_1 m_sm_reg4378_1;
  state_machine::Kernel_TopKernel_reg4415_1 m_sm_reg4415_1;
  state_machine::Kernel_TopKernel_reg4438_1 m_sm_reg4438_1;
  state_machine::Kernel_TopKernel_seq4476_sm m_sm_seq4476_sm;
  state_machine::Kernel_TopKernel_void4381_sm m_sm_void4381_sm;
  state_machine::Kernel_TopKernel_void4398_sm m_sm_void4398_sm;
  state_machine::Kernel_TopKernel_void4410_sm m_sm_void4410_sm;
  state_machine::Kernel_TopKernel_void4412_sm m_sm_void4412_sm;
  state_machine::Kernel_TopKernel_void4433_sm m_sm_void4433_sm;
  state_machine::Kernel_TopKernel_void4456_sm m_sm_void4456_sm;
  state_machine::Kernel_TopKernel_void4488_sm m_sm_void4488_sm;
  state_machine::Kernel_TopKernel_void4490_sm m_sm_void4490_sm;

  t_port_number m_DRAM4323_void4384_in_cmd;
  t_port_number m_DRAM4324_void4400_in_cmd;
  t_port_number m_DRAM4325_void4486_out_cmd;
  t_port_number m_DRAM4323_void4384_in;
  t_port_number m_DRAM4324_void4400_in;
  t_port_number m_DRAM4325_void4486_out;
  t_port_number m_intrCmd;
  t_port_number m_intrStream;
  HWOffsetFix<17,0,UNSIGNED> id927out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id121out_value;

  HWOffsetFix<1,0,UNSIGNED> id238out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id238out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id238out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id238out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id261out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id261out_sm_done;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id317out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id317out_done;
  HWOffsetFix<1,0,UNSIGNED> id317out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id314out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id314out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id314out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id314out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id255out_value;

  HWOffsetFix<1,0,UNSIGNED> id253out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id253out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id253out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id253out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id253out_sm_last;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id347out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id347out_done;
  HWOffsetFix<1,0,UNSIGNED> id347out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id339out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id339out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id339out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id339out_sm_done;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id365out_value;

  HWOffsetFix<1,0,UNSIGNED> id362out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id362out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id362out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id362out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id610out_value;

  HWOffsetFix<1,0,UNSIGNED> id321out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id321out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id321out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id321out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id321out_sm_last;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id399out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id399out_done;
  HWOffsetFix<1,0,UNSIGNED> id399out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id391out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id391out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id391out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id391out_sm_done;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id417out_value;

  HWOffsetFix<1,0,UNSIGNED> id414out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id414out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id414out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id414out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id614out_value;

  HWOffsetFix<1,0,UNSIGNED> id373out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id373out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id373out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id373out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id373out_sm_last;

  HWOffsetFix<1,0,UNSIGNED> id432out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id432out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id432out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id432out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id618out_value;

  HWOffsetFix<1,0,UNSIGNED> id423out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id423out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id423out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id423out_sm_last;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id470out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id470out_done;
  HWOffsetFix<1,0,UNSIGNED> id470out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id467out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id467out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id467out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id467out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id464out_value;

  HWOffsetFix<1,0,UNSIGNED> id462out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id462out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id462out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id462out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id462out_sm_last;

  HWOffsetFix<1,0,UNSIGNED> id0out_en;

  HWOffsetFix<64,0,UNSIGNED> id1out_cycles;
  HWOffsetFix<1,0,UNSIGNED> id1out_intr_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_run_en;
  HWOffsetFix<1,0,UNSIGNED> id1out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id126out_value;

  HWOffsetFix<1,0,UNSIGNED> id124out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id124out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id124out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id124out_sm_done;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_argin4320;

  HWOffsetFix<1,0,UNSIGNED> id129out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id129out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id129out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id129out_s2_en;
  HWOffsetFix<1,0,UNSIGNED> id129out_s3_en;
  HWOffsetFix<1,0,UNSIGNED> id129out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id139out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id139out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id139out_sm_done;

  HWOffsetFix<32,0,UNSIGNED> id143out_value;

  HWOffsetFix<1,0,UNSIGNED> id141out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id141out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id141out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id141out_sm_last;

  HWOffsetFix<32,0,UNSIGNED> id623out_value;

  HWOffsetFix<1,0,UNSIGNED> id146out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id146out_s0_en;
  HWOffsetFix<1,0,UNSIGNED> id146out_s1_en;
  HWOffsetFix<1,0,UNSIGNED> id146out_s2_en;
  HWOffsetFix<1,0,UNSIGNED> id146out_sm_done;
  HWOffsetFix<1,0,UNSIGNED> id146out_sm_last;

  HWOffsetFix<1,0,UNSIGNED> id185out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id185out_sm_done;

  HWOffsetFix<16,0,UNSIGNED> id195out_count;
  HWOffsetFix<1,0,UNSIGNED> id195out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id195st_count;

  HWOffsetFix<16,0,UNSIGNED> id926out_value;

  HWOffsetFix<1,0,UNSIGNED> id197out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id175out_value;

  HWOffsetFix<1,0,UNSIGNED> id172out_ctr_en;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id172out_ctr_maxOut_0;
  HWOffsetFix<1,0,UNSIGNED> id172out_rst_en;
  HWOffsetFix<1,0,UNSIGNED> id172out_sm_done;

  HWOffsetFix<1,0,UNSIGNED> id754out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id755out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id801out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id802out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id756out_output[4];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id241out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id241out_done;
  HWOffsetFix<1,0,UNSIGNED> id241out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id757out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id758out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id759out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id800out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id760out_output[2];

  HWOffsetFix<17,0,UNSIGNED> id925out_value;

  HWOffsetFix<16,0,UNSIGNED> id271out_count;
  HWOffsetFix<1,0,UNSIGNED> id271out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id271st_count;

  HWOffsetFix<16,0,UNSIGNED> id924out_value;

  HWOffsetFix<1,0,UNSIGNED> id273out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id761out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id762out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id763out_output[63];

  HWOffsetFix<1,0,UNSIGNED> id764out_output[62];

  HWOffsetFix<1,0,UNSIGNED> id765out_output[62];

  HWOffsetFix<1,0,UNSIGNED> id766out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id767out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id768out_output[2];

  HWOffsetFix<9,0,UNSIGNED> id911out_value;

  HWOffsetFix<9,0,UNSIGNED> id343out_count;
  HWOffsetFix<1,0,UNSIGNED> id343out_wrap;

  HWOffsetFix<10,0,UNSIGNED> id343st_count;

  HWOffsetFix<1,0,UNSIGNED> id346out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id769out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id838out_output[59];

  HWOffsetFix<1,0,UNSIGNED> id895out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id896out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id771out_output[60];

  HWOffsetFix<1,0,UNSIGNED> id772out_output[60];

  HWOffsetFix<1,0,UNSIGNED> id773out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id774out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id775out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id776out_output[2];

  HWOffsetFix<9,0,UNSIGNED> id912out_value;

  HWOffsetFix<9,0,UNSIGNED> id395out_count;
  HWOffsetFix<1,0,UNSIGNED> id395out_wrap;

  HWOffsetFix<10,0,UNSIGNED> id395st_count;

  HWOffsetFix<1,0,UNSIGNED> id777out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id398out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id778out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id779out_output[60];

  HWOffsetFix<1,0,UNSIGNED> id780out_output[59];

  HWOffsetFix<1,0,UNSIGNED> id781out_output[59];

  HWOffsetFix<1,0,UNSIGNED> id782out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id783out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id784out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id785out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id786out_output[22];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id435out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id435out_done;
  HWOffsetFix<1,0,UNSIGNED> id435out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id787out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id788out_output[22];

  HWOffsetFix<1,0,UNSIGNED> id789out_output[22];

  HWOffsetFix<1,0,UNSIGNED> id790out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id791out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id792out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id793out_output[62];

  HWOffsetFix<1,0,UNSIGNED> id794out_output[61];

  HWOffsetFix<1,0,UNSIGNED> id795out_output[61];

  HWOffsetFix<17,0,UNSIGNED> id923out_value;

  HWOffsetFix<1,0,UNSIGNED> id476out_memStart;
  HWOffsetFix<1,0,UNSIGNED> id476out_sm_done;

  HWOffsetFix<16,0,UNSIGNED> id485out_count;
  HWOffsetFix<1,0,UNSIGNED> id485out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id485st_count;

  HWOffsetFix<16,0,UNSIGNED> id922out_value;

  HWOffsetFix<1,0,UNSIGNED> id487out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id796out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id797out_output[2];

  HWOffsetFix<33,0,UNSIGNED> id921out_value;

  HWOffsetFix<32,0,UNSIGNED> id547out_count;
  HWOffsetFix<1,0,UNSIGNED> id547out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id547st_count;

  HWOffsetFix<1,0,UNSIGNED> id798out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id799out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id803out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id920out_value;

  HWOffsetFix<1,0,UNSIGNED> id200out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id201out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id219out_io_DRAM4323_void4384_in_cmd_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id809out_output[40];

  HWRawBits<1> id624out_value;

  HWRawBits<15> id629out_value;

  HWOffsetFix<8,0,UNSIGNED> id206out_value;

  HWRawBits<8> id634out_value;

  HWOffsetFix<32,0,UNSIGNED> id919out_value;

  HWOffsetFix<1,0,UNSIGNED> id537out_value;

  HWOffsetFix<2,0,UNSIGNED> id536out_value;

  HWOffsetFix<1,0,UNSIGNED> id5out_value;

  HWOffsetFix<1,0,UNSIGNED> id7out_value;

  HWOffsetFix<1,0,UNSIGNED> id9out_value;

  HWOffsetFix<1,0,UNSIGNED> id11out_value;

  HWOffsetFix<1,0,UNSIGNED> id13out_value;

  HWOffsetFix<1,0,UNSIGNED> id15out_value;

  HWOffsetFix<1,0,UNSIGNED> id6out_value;

  HWOffsetFix<1,0,UNSIGNED> id8out_value;

  HWOffsetFix<1,0,UNSIGNED> id10out_value;

  HWOffsetFix<1,0,UNSIGNED> id12out_value;

  HWOffsetFix<1,0,UNSIGNED> id14out_value;

  HWOffsetFix<1,0,UNSIGNED> id16out_value;

  HWOffsetFix<2,0,UNSIGNED> id4out_curBuf0;
  HWOffsetFix<2,0,UNSIGNED> id4out_curBuf1;

  HWOffsetFix<1,0,UNSIGNED> id808out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id535out_value;

  HWOffsetFix<1,0,UNSIGNED> id20out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id153out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id153out_done;
  HWOffsetFix<1,0,UNSIGNED> id153out_saturated;

  HWOffsetFix<34,5,TWOSCOMPLEMENT> id677out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id534out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id18out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id180out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id21out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id21st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id25out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id23out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id26out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id26st_holdreg;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id918out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id188out_result[39];

  HWOffsetFix<32,0,UNSIGNED> id191out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id810out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id917out_value;

  HWOffsetFix<1,0,UNSIGNED> id276out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id277out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id295out_io_DRAM4324_void4400_in_cmd_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id811out_output[43];

  HWRawBits<1> id635out_value;

  HWRawBits<15> id640out_value;

  HWOffsetFix<8,0,UNSIGNED> id282out_value;

  HWRawBits<8> id645out_value;

  HWRawBits<32> id649out_value;

  HWOffsetFix<1,0,UNSIGNED> id812out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id916out_value;

  HWOffsetFix<1,0,UNSIGNED> id490out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id491out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id508out_io_DRAM4325_void4486_out_cmd_force_disabled;

  HWRawBits<1> id650out_value;

  HWRawBits<15> id655out_value;

  HWOffsetFix<8,0,UNSIGNED> id495out_value;

  HWRawBits<8> id660out_value;

  HWRawBits<32> id664out_value;

  HWOffsetFix<1,0,UNSIGNED> id521out_io_DRAM4325_void4486_out_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id889out_output[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id875out_output[41];

  HWOffsetFix<7,0,UNSIGNED> id888out_output[21];

  HWOffsetFix<1,0,UNSIGNED> id815out_output[60];

  HWOffsetFix<1,0,UNSIGNED> id383out_curBuf;

  HWOffsetFix<1,0,UNSIGNED> id821out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id387out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id903out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id819out_output[62];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id380out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id380out_done;
  HWOffsetFix<1,0,UNSIGNED> id380out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id390out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id388out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id388st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id385out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id386out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id386st_holdreg;

  HWOffsetFix<7,0,UNSIGNED> id876out_output[18];

  HWOffsetFix<1,0,UNSIGNED> id533out_value;

  HWOffsetFix<2,0,UNSIGNED> id532out_value;

  HWOffsetFix<1,0,UNSIGNED> id904out_output[14];

  HWOffsetFix<1,0,UNSIGNED> id905out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id906out_output[16];

  HWOffsetFix<1,0,UNSIGNED> id91out_value;

  HWOffsetFix<1,0,UNSIGNED> id93out_value;

  HWOffsetFix<1,0,UNSIGNED> id95out_value;

  HWOffsetFix<1,0,UNSIGNED> id97out_value;

  HWOffsetFix<1,0,UNSIGNED> id99out_value;

  HWOffsetFix<1,0,UNSIGNED> id101out_value;

  HWOffsetFix<1,0,UNSIGNED> id907out_output[17];

  HWOffsetFix<1,0,UNSIGNED> id908out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id909out_output[73];

  HWOffsetFix<1,0,UNSIGNED> id92out_value;

  HWOffsetFix<1,0,UNSIGNED> id94out_value;

  HWOffsetFix<1,0,UNSIGNED> id96out_value;

  HWOffsetFix<1,0,UNSIGNED> id98out_value;

  HWOffsetFix<1,0,UNSIGNED> id100out_value;

  HWOffsetFix<1,0,UNSIGNED> id102out_value;

  HWOffsetFix<2,0,UNSIGNED> id90out_curBuf0;
  HWOffsetFix<2,0,UNSIGNED> id90out_curBuf1;

  HWOffsetFix<1,0,UNSIGNED> id872out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id531out_value;

  HWOffsetFix<1,0,UNSIGNED> id106out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id164out_curBuf;

  HWOffsetFix<1,0,UNSIGNED> id833out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id168out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id156out_curBuf;

  HWOffsetFix<1,0,UNSIGNED> id831out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id160out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id829out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id163out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id161out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id161st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id158out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id159out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id159st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id171out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id169out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id169st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id166out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id167out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id167st_holdreg;

  HWOffsetFix<34,5,TWOSCOMPLEMENT> id681out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id251out_result[2];

  HWOffsetFix<14,0,UNSIGNED> id835out_output[59];

  HWOffsetFix<1,0,UNSIGNED> id834out_output[55];

  HWOffsetFix<1,0,UNSIGNED> id232out_io_DRAM4323_void4384_in_force_disabled;

  HWRawBits<32> id235out_data;

  HWOffsetFix<1,0,UNSIGNED> id235st_read_next_cycle;
  HWRawBits<32> id235st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id893out_output[6];

  HWOffsetFix<34,5,TWOSCOMPLEMENT> id685out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id405out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id588out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id588sta_ram_store[9216];

  std::string format_string_TopKernel_1 (const char* _format_arg_format_string);
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id867out_output[9];

  HWOffsetFix<1,0,UNSIGNED> id837out_output[59];

  HWOffsetFix<1,0,UNSIGNED> id331out_curBuf;

  HWOffsetFix<1,0,UNSIGNED> id843out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id335out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id841out_output[61];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id328out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id328out_done;
  HWOffsetFix<1,0,UNSIGNED> id328out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id338out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id336out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id336st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id333out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id334out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id334st_holdreg;

  HWOffsetFix<7,0,UNSIGNED> id864out_output[10];

  HWOffsetFix<1,0,UNSIGNED> id529out_value;

  HWOffsetFix<2,0,UNSIGNED> id528out_value;

  HWOffsetFix<1,0,UNSIGNED> id897out_output[6];

  HWOffsetFix<1,0,UNSIGNED> id898out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id899out_output[9];

  HWOffsetFix<1,0,UNSIGNED> id64out_value;

  HWOffsetFix<1,0,UNSIGNED> id66out_value;

  HWOffsetFix<1,0,UNSIGNED> id68out_value;

  HWOffsetFix<1,0,UNSIGNED> id70out_value;

  HWOffsetFix<1,0,UNSIGNED> id72out_value;

  HWOffsetFix<1,0,UNSIGNED> id74out_value;

  HWOffsetFix<1,0,UNSIGNED> id900out_output[8];

  HWOffsetFix<1,0,UNSIGNED> id901out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id902out_output[65];

  HWOffsetFix<1,0,UNSIGNED> id65out_value;

  HWOffsetFix<1,0,UNSIGNED> id67out_value;

  HWOffsetFix<1,0,UNSIGNED> id69out_value;

  HWOffsetFix<1,0,UNSIGNED> id71out_value;

  HWOffsetFix<1,0,UNSIGNED> id73out_value;

  HWOffsetFix<1,0,UNSIGNED> id75out_value;

  HWOffsetFix<2,0,UNSIGNED> id63out_curBuf0;
  HWOffsetFix<2,0,UNSIGNED> id63out_curBuf1;

  HWOffsetFix<1,0,UNSIGNED> id858out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id527out_value;

  HWOffsetFix<1,0,UNSIGNED> id79out_result[2];

  HWOffsetFix<34,5,TWOSCOMPLEMENT> id689out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id247out_result[2];

  HWOffsetFix<14,0,UNSIGNED> id849out_output[59];

  HWOffsetFix<34,5,TWOSCOMPLEMENT> id693out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id353out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id587out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id587sta_ram_store[9216];

  std::string format_string_TopKernel_2 (const char* _format_arg_format_string);
  HWOffsetFix<7,0,UNSIGNED> id853out_output[21];

  HWOffsetFix<1,0,UNSIGNED> id852out_output[61];

  HWOffsetFix<7,0,UNSIGNED> id854out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id591out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id591sta_ram_store[96];

  std::string format_string_TopKernel_3 (const char* _format_arg_format_string);
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id361out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id358out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id856out_output[6];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id359out_accumulate[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id359st_hold_reg;
  HWOffsetFix<1,0,UNSIGNED> id359st_clear_reg;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id526out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id77out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id360out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id80out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id80st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id84out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id82out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id85out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id85st_holdreg;

  HWOffsetFix<7,0,UNSIGNED> id859out_output[5];

  HWOffsetFix<1,0,UNSIGNED> id308out_io_DRAM4324_void4400_in_force_disabled;

  HWRawBits<32> id311out_data;

  HWOffsetFix<1,0,UNSIGNED> id311st_read_next_cycle;
  HWRawBits<32> id311st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id894out_output[5];

  HWOffsetFix<7,0,UNSIGNED> id861out_output[7];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id589out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id589sta_ram_store[96];

  std::string format_string_TopKernel_4 (const char* _format_arg_format_string);
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id371out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id368out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id865out_output[67];

  HWOffsetFix<7,0,UNSIGNED> id866out_output[11];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id594out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id594sta_ram_store[96];

  std::string format_string_TopKernel_5 (const char* _format_arg_format_string);
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id413out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id410out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id870out_output[15];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id411out_accumulate[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id411st_hold_reg;
  HWOffsetFix<1,0,UNSIGNED> id411st_clear_reg;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id530out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id104out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id412out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id107out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id107st_holdreg;

  HWOffsetFix<1,0,UNSIGNED> id111out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id109out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id112out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id112st_holdreg;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id3out_argin4319;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id421out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id420out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id877out_output[76];

  HWOffsetFix<7,0,UNSIGNED> id878out_output[18];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id590out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id590sta_ram_store[96];

  std::string format_string_TopKernel_6 (const char* _format_arg_format_string);
  HWOffsetFix<7,0,UNSIGNED> id882out_output[21];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id592out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id592sta_ram_store[96];

  std::string format_string_TopKernel_7 (const char* _format_arg_format_string);
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id885out_output[18];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id120out_value;

  HWOffsetFix<1,0,UNSIGNED> id883out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id430out_counter0;
  HWOffsetFix<1,0,UNSIGNED> id430out_done;
  HWOffsetFix<1,0,UNSIGNED> id430out_saturated;

  HWOffsetFix<1,0,UNSIGNED> id457out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id884out_output[22];

  HWOffsetFix<1,0,UNSIGNED> id458out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id459out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id886out_output[58];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id695out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id593out_doutb[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id593sta_ram_store[96];

  std::string format_string_TopKernel_8 (const char* _format_arg_format_string);
  HWOffsetFix<1,0,UNSIGNED> id890out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id915out_value;

  HWOffsetFix<1,0,UNSIGNED> id550out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id551out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id567out_io_intrCmd_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id910out_output[2];

  HWRawBits<15> id669out_value;

  HWOffsetFix<8,0,UNSIGNED> id671out_value;

  HWRawBits<8> id673out_value;

  HWRawBits<32> id674out_value;

  HWOffsetFix<1,0,UNSIGNED> id580out_value;

  HWOffsetFix<1,0,UNSIGNED> id583out_io_intrStream_force_disabled;

  HWOffsetFix<32,0,UNSIGNED> id582out_value;

  HWOffsetFix<1,0,UNSIGNED> id599out_value;

  HWOffsetFix<1,0,UNSIGNED> id914out_value;

  HWOffsetFix<49,0,UNSIGNED> id596out_value;

  HWOffsetFix<48,0,UNSIGNED> id597out_count;
  HWOffsetFix<1,0,UNSIGNED> id597out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id597st_count;

  HWOffsetFix<1,0,UNSIGNED> id913out_value;

  HWOffsetFix<49,0,UNSIGNED> id602out_value;

  HWOffsetFix<48,0,UNSIGNED> id603out_count;
  HWOffsetFix<1,0,UNSIGNED> id603out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id603st_count;

  HWOffsetFix<48,0,UNSIGNED> id605out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id606out_result[2];

  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_1;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWOffsetFix<9,0,UNSIGNED> c_hw_fix_9_0_uns_bits;
  const HWOffsetFix<10,0,UNSIGNED> c_hw_fix_10_0_uns_bits;
  const HWOffsetFix<10,0,UNSIGNED> c_hw_fix_10_0_uns_bits_1;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_undef;
  const HWOffsetFix<9,0,UNSIGNED> c_hw_fix_9_0_uns_bits_1;
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
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_2;
  const HWOffsetFix<2,0,UNSIGNED> c_hw_fix_2_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_2;
  const HWRawBits<32> c_hw_bit_32_bits;
  const HWRawBits<32> c_hw_bit_32_bits_1;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_undef;
  const HWOffsetFix<14,0,UNSIGNED> c_hw_fix_14_0_uns_undef;
  const HWRawBits<32> c_hw_bit_32_undef;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_3;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits_1;
  const HWRawBits<32> c_hw_bit_32_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_4;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  TopKernelBlock1Vars execute0();
  void execute1(const TopKernelBlock1Vars &in_vars);
};

}

#endif /* TOPKERNEL_H_ */
