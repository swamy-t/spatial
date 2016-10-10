#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "TopKernel_exec1.h"
//#include "TopKernel.h"

namespace maxcompilersim {

TopKernelBlock1Vars TopKernel::execute0() {
  { // Node ID: 927 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id198out_output;

  { // Node ID: 198 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id198in_input = id197out_result[getCycle()%2];

    id198out_output = id198in_input;
  }
  { // Node ID: 121 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 238 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id238in_ctr_done = id757out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id238in_rst_done = id758out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id238in_sm_en = id759out_output[getCycle()%4];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id238in_sm_maxIn_0 = id121out_value;

    m_sm_pipe4394_sm.inputdata_ctr_done = id238in_ctr_done.getBitString();
    m_sm_pipe4394_sm.inputdata_rst_done = id238in_rst_done.getBitString();
    m_sm_pipe4394_sm.inputdata_sm_en = id238in_sm_en.getBitString();
    m_sm_pipe4394_sm.inputdata_sm_maxIn_0 = id238in_sm_maxIn_0.getBitString();
    m_sm_pipe4394_sm.execute(true);
    id238out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4394_sm.outputdata_ctr_en));
    id238out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe4394_sm.outputdata_ctr_maxOut_0) ));
    id238out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4394_sm.outputdata_rst_en));
    id238out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4394_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id728out_output;

  { // Node ID: 728 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id728in_input = id238out_sm_done;

    id728out_output = id728in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id142out_output;

  { // Node ID: 142 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id142in_input = id760out_output[getCycle()%2];

    id142out_output = id142in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id274out_output;

  { // Node ID: 274 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id274in_input = id273out_result[getCycle()%2];

    id274out_output = id274in_input;
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 261 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id261in_memDone = id274out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id261in_sm_en = id761out_output[getCycle()%2];

    m_sm_DRAM4324_void4400_inldSM.inputdata_memDone = id261in_memDone.getBitString();
    m_sm_DRAM4324_void4400_inldSM.inputdata_sm_en = id261in_sm_en.getBitString();
    m_sm_DRAM4324_void4400_inldSM.execute(true);
    id261out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM4324_void4400_inldSM.outputdata_memStart));
    id261out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM4324_void4400_inldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id262out_output;

  { // Node ID: 262 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id262in_input = id261out_sm_done;

    id262out_output = id262in_input;
  }
  if ( (getFillLevel() >= (67l)))
  { // Node ID: 317 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id317in_en = id762out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id317in_max0 = id121out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id317in_reset = id763out_output[getCycle()%63];

    m_sm_CounterChain4402_sm.inputdata_en = id317in_en.getBitString();
    m_sm_CounterChain4402_sm.inputdata_max0 = id317in_max0.getBitString();
    m_sm_CounterChain4402_sm.inputdata_reset = id317in_reset.getBitString();
    m_sm_CounterChain4402_sm.execute(true);
    id317out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain4402_sm.outputdata_counter0) ));
    id317out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4402_sm.outputdata_done));
    id317out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4402_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id318out_output;

  { // Node ID: 318 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id318in_input = id317out_done;

    id318out_output = id318in_input;
  }
  if ( (getFillLevel() >= (66l)))
  { // Node ID: 314 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id314in_ctr_done = id318out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id314in_rst_done = id764out_output[getCycle()%62];
    const HWOffsetFix<1,0,UNSIGNED> &id314in_sm_en = id765out_output[getCycle()%62];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id314in_sm_maxIn_0 = id121out_value;

    m_sm_pipe4408_sm.inputdata_ctr_done = id314in_ctr_done.getBitString();
    m_sm_pipe4408_sm.inputdata_rst_done = id314in_rst_done.getBitString();
    m_sm_pipe4408_sm.inputdata_sm_en = id314in_sm_en.getBitString();
    m_sm_pipe4408_sm.inputdata_sm_maxIn_0 = id314in_sm_maxIn_0.getBitString();
    m_sm_pipe4408_sm.execute(true);
    id314out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4408_sm.outputdata_ctr_en));
    id314out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe4408_sm.outputdata_ctr_maxOut_0) ));
    id314out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4408_sm.outputdata_rst_en));
    id314out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4408_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id730out_output;

  { // Node ID: 730 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id730in_input = id314out_sm_done;

    id730out_output = id730in_input;
  }
  { // Node ID: 255 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 253 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id253in_s0_done = id262out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id253in_s1_done = id730out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id253in_sm_en = id766out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id253in_sm_numIter = id255out_value;

    m_sm_void4410_sm.inputdata_s0_done = id253in_s0_done.getBitString();
    m_sm_void4410_sm.inputdata_s1_done = id253in_s1_done.getBitString();
    m_sm_void4410_sm.inputdata_sm_en = id253in_sm_en.getBitString();
    m_sm_void4410_sm.inputdata_sm_numIter = id253in_sm_numIter.getBitString();
    m_sm_void4410_sm.execute(true);
    id253out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4410_sm.outputdata_rst_en));
    id253out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4410_sm.outputdata_s0_en));
    id253out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4410_sm.outputdata_s1_en));
    id253out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4410_sm.outputdata_sm_done));
    id253out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4410_sm.outputdata_sm_last));
  }
  HWOffsetFix<1,0,UNSIGNED> id254out_output;

  { // Node ID: 254 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id254in_input = id253out_sm_done;

    id254out_output = id254in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id140out_output;

  { // Node ID: 140 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id140in_input = id767out_output[getCycle()%2];

    id140out_output = id140in_input;
  }
  if ( (getFillLevel() >= (65l)))
  { // Node ID: 347 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id347in_en = id346out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id347in_max0 = id769out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id347in_reset = id896out_output[getCycle()%2];

    m_sm_CounterChain4417_sm.inputdata_en = id347in_en.getBitString();
    m_sm_CounterChain4417_sm.inputdata_max0 = id347in_max0.getBitString();
    m_sm_CounterChain4417_sm.inputdata_reset = id347in_reset.getBitString();
    m_sm_CounterChain4417_sm.execute(true);
    id347out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain4417_sm.outputdata_counter0) ));
    id347out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4417_sm.outputdata_done));
    id347out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4417_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id348out_output;

  { // Node ID: 348 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id348in_input = id347out_done;

    id348out_output = id348in_input;
  }
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 339 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id339in_ctr_done = id348out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id339in_rst_done = id771out_output[getCycle()%60];
    const HWOffsetFix<1,0,UNSIGNED> &id339in_sm_en = id772out_output[getCycle()%60];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id339in_sm_maxIn_0 = id121out_value;

    m_sm_pipe4427_sm.inputdata_ctr_done = id339in_ctr_done.getBitString();
    m_sm_pipe4427_sm.inputdata_rst_done = id339in_rst_done.getBitString();
    m_sm_pipe4427_sm.inputdata_sm_en = id339in_sm_en.getBitString();
    m_sm_pipe4427_sm.inputdata_sm_maxIn_0 = id339in_sm_maxIn_0.getBitString();
    m_sm_pipe4427_sm.execute(true);
    id339out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4427_sm.outputdata_ctr_en));
    id339out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe4427_sm.outputdata_ctr_maxOut_0) ));
    id339out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4427_sm.outputdata_rst_en));
    id339out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4427_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id733out_output;

  { // Node ID: 733 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id733in_input = id339out_sm_done;

    id733out_output = id733in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id366out_output;

  { // Node ID: 366 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id366in_input = id773out_output[getCycle()%2];

    id366out_output = id366in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id734out_output;

  { // Node ID: 734 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id734in_input = id774out_output[getCycle()%2];

    id734out_output = id734in_input;
  }
  { // Node ID: 365 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 362 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id362in_ctr_done = id366out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id362in_rst_done = id734out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id362in_sm_en = id775out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id362in_sm_maxIn_0 = id365out_value;

    m_sm_void4433_sm.inputdata_ctr_done = id362in_ctr_done.getBitString();
    m_sm_void4433_sm.inputdata_rst_done = id362in_rst_done.getBitString();
    m_sm_void4433_sm.inputdata_sm_en = id362in_sm_en.getBitString();
    m_sm_void4433_sm.inputdata_sm_maxIn_0 = id362in_sm_maxIn_0.getBitString();
    m_sm_void4433_sm.execute(true);
    id362out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4433_sm.outputdata_ctr_en));
    id362out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_void4433_sm.outputdata_ctr_maxOut_0) ));
    id362out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4433_sm.outputdata_rst_en));
    id362out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4433_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id735out_output;

  { // Node ID: 735 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id735in_input = id362out_sm_done;

    id735out_output = id735in_input;
  }
  { // Node ID: 610 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 321 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id321in_s0_done = id733out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id321in_s1_done = id735out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id321in_sm_en = id776out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id321in_sm_numIter = id610out_value;

    m_sm_metapipe4435_sm.inputdata_s0_done = id321in_s0_done.getBitString();
    m_sm_metapipe4435_sm.inputdata_s1_done = id321in_s1_done.getBitString();
    m_sm_metapipe4435_sm.inputdata_sm_en = id321in_sm_en.getBitString();
    m_sm_metapipe4435_sm.inputdata_sm_numIter = id321in_sm_numIter.getBitString();
    m_sm_metapipe4435_sm.execute(true);
    id321out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4435_sm.outputdata_rst_en));
    id321out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4435_sm.outputdata_s0_en));
    id321out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4435_sm.outputdata_s1_en));
    id321out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4435_sm.outputdata_sm_done));
    id321out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4435_sm.outputdata_sm_last));
  }
  HWOffsetFix<1,0,UNSIGNED> id322out_output;

  { // Node ID: 322 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id322in_input = id321out_sm_done;

    id322out_output = id322in_input;
  }
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 399 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id399in_en = id398out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id399in_max0 = id778out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id399in_reset = id779out_output[getCycle()%60];

    m_sm_CounterChain4440_sm.inputdata_en = id399in_en.getBitString();
    m_sm_CounterChain4440_sm.inputdata_max0 = id399in_max0.getBitString();
    m_sm_CounterChain4440_sm.inputdata_reset = id399in_reset.getBitString();
    m_sm_CounterChain4440_sm.execute(true);
    id399out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain4440_sm.outputdata_counter0) ));
    id399out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4440_sm.outputdata_done));
    id399out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4440_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id400out_output;

  { // Node ID: 400 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id400in_input = id399out_done;

    id400out_output = id400in_input;
  }
  if ( (getFillLevel() >= (63l)))
  { // Node ID: 391 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id391in_ctr_done = id400out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id391in_rst_done = id780out_output[getCycle()%59];
    const HWOffsetFix<1,0,UNSIGNED> &id391in_sm_en = id781out_output[getCycle()%59];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id391in_sm_maxIn_0 = id121out_value;

    m_sm_pipe4450_sm.inputdata_ctr_done = id391in_ctr_done.getBitString();
    m_sm_pipe4450_sm.inputdata_rst_done = id391in_rst_done.getBitString();
    m_sm_pipe4450_sm.inputdata_sm_en = id391in_sm_en.getBitString();
    m_sm_pipe4450_sm.inputdata_sm_maxIn_0 = id391in_sm_maxIn_0.getBitString();
    m_sm_pipe4450_sm.execute(true);
    id391out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4450_sm.outputdata_ctr_en));
    id391out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe4450_sm.outputdata_ctr_maxOut_0) ));
    id391out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4450_sm.outputdata_rst_en));
    id391out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4450_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id738out_output;

  { // Node ID: 738 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id738in_input = id391out_sm_done;

    id738out_output = id738in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id418out_output;

  { // Node ID: 418 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id418in_input = id782out_output[getCycle()%2];

    id418out_output = id418in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id739out_output;

  { // Node ID: 739 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id739in_input = id783out_output[getCycle()%2];

    id739out_output = id739in_input;
  }
  { // Node ID: 417 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 414 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id414in_ctr_done = id418out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id414in_rst_done = id739out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id414in_sm_en = id784out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id414in_sm_maxIn_0 = id417out_value;

    m_sm_void4456_sm.inputdata_ctr_done = id414in_ctr_done.getBitString();
    m_sm_void4456_sm.inputdata_rst_done = id414in_rst_done.getBitString();
    m_sm_void4456_sm.inputdata_sm_en = id414in_sm_en.getBitString();
    m_sm_void4456_sm.inputdata_sm_maxIn_0 = id414in_sm_maxIn_0.getBitString();
    m_sm_void4456_sm.execute(true);
    id414out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4456_sm.outputdata_ctr_en));
    id414out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_void4456_sm.outputdata_ctr_maxOut_0) ));
    id414out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4456_sm.outputdata_rst_en));
    id414out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4456_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id740out_output;

  { // Node ID: 740 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id740in_input = id414out_sm_done;

    id740out_output = id740in_input;
  }
  { // Node ID: 614 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 373 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id373in_s0_done = id738out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id373in_s1_done = id740out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id373in_sm_en = id785out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id373in_sm_numIter = id614out_value;

    m_sm_metapipe4458_sm.inputdata_s0_done = id373in_s0_done.getBitString();
    m_sm_metapipe4458_sm.inputdata_s1_done = id373in_s1_done.getBitString();
    m_sm_metapipe4458_sm.inputdata_sm_en = id373in_sm_en.getBitString();
    m_sm_metapipe4458_sm.inputdata_sm_numIter = id373in_sm_numIter.getBitString();
    m_sm_metapipe4458_sm.execute(true);
    id373out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4458_sm.outputdata_rst_en));
    id373out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4458_sm.outputdata_s0_en));
    id373out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4458_sm.outputdata_s1_en));
    id373out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4458_sm.outputdata_sm_done));
    id373out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4458_sm.outputdata_sm_last));
  }
  HWOffsetFix<1,0,UNSIGNED> id374out_output;

  { // Node ID: 374 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id374in_input = id373out_sm_done;

    id374out_output = id374in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id436out_output;

  { // Node ID: 436 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id436in_input = id787out_output[getCycle()%2];

    id436out_output = id436in_input;
  }
  if ( (getFillLevel() >= (26l)))
  { // Node ID: 432 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id432in_ctr_done = id436out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id432in_rst_done = id788out_output[getCycle()%22];
    const HWOffsetFix<1,0,UNSIGNED> &id432in_sm_en = id789out_output[getCycle()%22];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id432in_sm_maxIn_0 = id121out_value;

    m_sm_pipe4472_sm.inputdata_ctr_done = id432in_ctr_done.getBitString();
    m_sm_pipe4472_sm.inputdata_rst_done = id432in_rst_done.getBitString();
    m_sm_pipe4472_sm.inputdata_sm_en = id432in_sm_en.getBitString();
    m_sm_pipe4472_sm.inputdata_sm_maxIn_0 = id432in_sm_maxIn_0.getBitString();
    m_sm_pipe4472_sm.execute(true);
    id432out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4472_sm.outputdata_ctr_en));
    id432out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe4472_sm.outputdata_ctr_maxOut_0) ));
    id432out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4472_sm.outputdata_rst_en));
    id432out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4472_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id742out_output;

  { // Node ID: 742 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id742in_input = id432out_sm_done;

    id742out_output = id742in_input;
  }
  { // Node ID: 618 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 423 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id423in_s0_done = id742out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id423in_sm_en = id790out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id423in_sm_numIter = id618out_value;

    m_sm_metapipe4474_sm.inputdata_s0_done = id423in_s0_done.getBitString();
    m_sm_metapipe4474_sm.inputdata_sm_en = id423in_sm_en.getBitString();
    m_sm_metapipe4474_sm.inputdata_sm_numIter = id423in_sm_numIter.getBitString();
    m_sm_metapipe4474_sm.execute(true);
    id423out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4474_sm.outputdata_rst_en));
    id423out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4474_sm.outputdata_s0_en));
    id423out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4474_sm.outputdata_sm_done));
    id423out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4474_sm.outputdata_sm_last));
  }
  HWOffsetFix<1,0,UNSIGNED> id424out_output;

  { // Node ID: 424 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id424in_input = id423out_sm_done;

    id424out_output = id424in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id130out_output;

  { // Node ID: 130 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id130in_input = id791out_output[getCycle()%2];

    id130out_output = id130in_input;
  }
  if ( (getFillLevel() >= (66l)))
  { // Node ID: 470 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id470in_en = id792out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id470in_max0 = id121out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id470in_reset = id793out_output[getCycle()%62];

    m_sm_CounterChain4479_sm.inputdata_en = id470in_en.getBitString();
    m_sm_CounterChain4479_sm.inputdata_max0 = id470in_max0.getBitString();
    m_sm_CounterChain4479_sm.inputdata_reset = id470in_reset.getBitString();
    m_sm_CounterChain4479_sm.execute(true);
    id470out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain4479_sm.outputdata_counter0) ));
    id470out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4479_sm.outputdata_done));
    id470out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4479_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id471out_output;

  { // Node ID: 471 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id471in_input = id470out_done;

    id471out_output = id471in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id743out_output;

  { // Node ID: 743 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id743in_input = id794out_output[getCycle()%61];

    id743out_output = id743in_input;
  }
  if ( (getFillLevel() >= (65l)))
  { // Node ID: 467 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id467in_ctr_done = id471out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id467in_rst_done = id743out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id467in_sm_en = id795out_output[getCycle()%61];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id467in_sm_maxIn_0 = id121out_value;

    m_sm_pipe4485_sm.inputdata_ctr_done = id467in_ctr_done.getBitString();
    m_sm_pipe4485_sm.inputdata_rst_done = id467in_rst_done.getBitString();
    m_sm_pipe4485_sm.inputdata_sm_en = id467in_sm_en.getBitString();
    m_sm_pipe4485_sm.inputdata_sm_maxIn_0 = id467in_sm_maxIn_0.getBitString();
    m_sm_pipe4485_sm.execute(true);
    id467out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4485_sm.outputdata_ctr_en));
    id467out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe4485_sm.outputdata_ctr_maxOut_0) ));
    id467out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4485_sm.outputdata_rst_en));
    id467out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe4485_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id744out_output;

  { // Node ID: 744 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id744in_input = id467out_sm_done;

    id744out_output = id744in_input;
  }
  { // Node ID: 464 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 462 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id462in_s0_done = id744out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id462in_s1_done = id796out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id462in_sm_en = id797out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id462in_sm_numIter = id464out_value;

    m_sm_void4488_sm.inputdata_s0_done = id462in_s0_done.getBitString();
    m_sm_void4488_sm.inputdata_s1_done = id462in_s1_done.getBitString();
    m_sm_void4488_sm.inputdata_sm_en = id462in_sm_en.getBitString();
    m_sm_void4488_sm.inputdata_sm_numIter = id462in_sm_numIter.getBitString();
    m_sm_void4488_sm.execute(true);
    id462out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4488_sm.outputdata_rst_en));
    id462out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4488_sm.outputdata_s0_en));
    id462out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4488_sm.outputdata_s1_en));
    id462out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4488_sm.outputdata_sm_done));
    id462out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4488_sm.outputdata_sm_last));
  }
  HWOffsetFix<1,0,UNSIGNED> id463out_output;

  { // Node ID: 463 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id463in_input = id462out_sm_done;

    id463out_output = id463in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id548out_output;

  { // Node ID: 548 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id548in_input = id798out_output[getCycle()%2];

    id548out_output = id548in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id125out_output;

  { // Node ID: 125 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id125in_input = id799out_output[getCycle()%2];

    id125out_output = id125in_input;
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_intr_done = id548out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id1in_run_done = id125out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id1in_sm_en = id0out_en;

    m_sm_mainSm.inputdata_intr_done = id1in_intr_done.getBitString();
    m_sm_mainSm.inputdata_run_done = id1in_run_done.getBitString();
    m_sm_mainSm.inputdata_sm_en = id1in_sm_en.getBitString();
    m_sm_mainSm.execute(true);
    id1out_cycles = (HWOffsetFix<64,0,UNSIGNED>(m_sm_mainSm.outputdata_cycles));
    id1out_intr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_mainSm.outputdata_intr_en));
    id1out_run_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_mainSm.outputdata_run_en));
    id1out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_mainSm.outputdata_sm_done));
  }
  { // Node ID: 126 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 124 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id124in_s0_done = id130out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id124in_s1_done = id463out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id124in_sm_en = id1out_run_en;
    const HWOffsetFix<32,0,UNSIGNED> &id124in_sm_numIter = id126out_value;

    m_sm_void4490_sm.inputdata_s0_done = id124in_s0_done.getBitString();
    m_sm_void4490_sm.inputdata_s1_done = id124in_s1_done.getBitString();
    m_sm_void4490_sm.inputdata_sm_en = id124in_sm_en.getBitString();
    m_sm_void4490_sm.inputdata_sm_numIter = id124in_sm_numIter.getBitString();
    m_sm_void4490_sm.execute(true);
    id124out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4490_sm.outputdata_rst_en));
    id124out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4490_sm.outputdata_s0_en));
    id124out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4490_sm.outputdata_s1_en));
    id124out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4490_sm.outputdata_sm_done));
  }
  { // Node ID: 2 (NodeInputMappedReg)
  }
  HWOffsetFix<32,0,UNSIGNED> id135out_o;

  { // Node ID: 135 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id135in_i = id2out_argin4320;

    id135out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id135in_i));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 129 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id129in_s0_done = id140out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id129in_s1_done = id322out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id129in_s2_done = id374out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id129in_s3_done = id424out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id129in_sm_en = id124out_s0_en;
    const HWOffsetFix<32,0,UNSIGNED> &id129in_sm_numIter = id135out_o;

    m_sm_seq4476_sm.inputdata_s0_done = id129in_s0_done.getBitString();
    m_sm_seq4476_sm.inputdata_s1_done = id129in_s1_done.getBitString();
    m_sm_seq4476_sm.inputdata_s2_done = id129in_s2_done.getBitString();
    m_sm_seq4476_sm.inputdata_s3_done = id129in_s3_done.getBitString();
    m_sm_seq4476_sm.inputdata_sm_en = id129in_sm_en.getBitString();
    m_sm_seq4476_sm.inputdata_sm_numIter = id129in_sm_numIter.getBitString();
    m_sm_seq4476_sm.execute(true);
    id129out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq4476_sm.outputdata_rst_en));
    id129out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq4476_sm.outputdata_s0_en));
    id129out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq4476_sm.outputdata_s1_en));
    id129out_s2_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq4476_sm.outputdata_s2_en));
    id129out_s3_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq4476_sm.outputdata_s3_en));
    id129out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq4476_sm.outputdata_sm_done));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 139 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id139in_s0_done = id142out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id139in_s1_done = id254out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id139in_sm_en = id129out_s0_en;

    m_sm_void4412_sm.inputdata_s0_done = id139in_s0_done.getBitString();
    m_sm_void4412_sm.inputdata_s1_done = id139in_s1_done.getBitString();
    m_sm_void4412_sm.inputdata_sm_en = id139in_sm_en.getBitString();
    m_sm_void4412_sm.execute(true);
    id139out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4412_sm.outputdata_s0_en));
    id139out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4412_sm.outputdata_s1_en));
    id139out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4412_sm.outputdata_sm_done));
  }
  { // Node ID: 143 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 141 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id141in_s0_done = id800out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id141in_sm_en = id139out_s0_en;
    const HWOffsetFix<32,0,UNSIGNED> &id141in_sm_numIter = id143out_value;

    m_sm_void4398_sm.inputdata_s0_done = id141in_s0_done.getBitString();
    m_sm_void4398_sm.inputdata_sm_en = id141in_sm_en.getBitString();
    m_sm_void4398_sm.inputdata_sm_numIter = id141in_sm_numIter.getBitString();
    m_sm_void4398_sm.execute(true);
    id141out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4398_sm.outputdata_rst_en));
    id141out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4398_sm.outputdata_s0_en));
    id141out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4398_sm.outputdata_sm_done));
    id141out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4398_sm.outputdata_sm_last));
  }
  { // Node ID: 623 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 146 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id146in_s0_done = id801out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id146in_s1_done = id802out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id146in_s2_done = id728out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id146in_sm_en = id141out_s0_en;
    const HWOffsetFix<32,0,UNSIGNED> &id146in_sm_numIter = id623out_value;

    m_sm_metapipe4396_sm.inputdata_s0_done = id146in_s0_done.getBitString();
    m_sm_metapipe4396_sm.inputdata_s1_done = id146in_s1_done.getBitString();
    m_sm_metapipe4396_sm.inputdata_s2_done = id146in_s2_done.getBitString();
    m_sm_metapipe4396_sm.inputdata_sm_en = id146in_sm_en.getBitString();
    m_sm_metapipe4396_sm.inputdata_sm_numIter = id146in_sm_numIter.getBitString();
    m_sm_metapipe4396_sm.execute(true);
    id146out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4396_sm.outputdata_rst_en));
    id146out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4396_sm.outputdata_s0_en));
    id146out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4396_sm.outputdata_s1_en));
    id146out_s2_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4396_sm.outputdata_s2_en));
    id146out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4396_sm.outputdata_sm_done));
    id146out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4396_sm.outputdata_sm_last));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 185 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id185in_memDone = id198out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id185in_sm_en = id146out_s1_en;

    m_sm_DRAM4323_void4384_inldSM.inputdata_memDone = id185in_memDone.getBitString();
    m_sm_DRAM4323_void4384_inldSM.inputdata_sm_en = id185in_sm_en.getBitString();
    m_sm_DRAM4323_void4384_inldSM.execute(true);
    id185out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM4323_void4384_inldSM.outputdata_memStart));
    id185out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM4323_void4384_inldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id186out_output;

  { // Node ID: 186 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id186in_input = id185out_sm_done;

    id186out_output = id186in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id193out_output;

  { // Node ID: 193 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id193in_input = id186out_output;

    id193out_output = id193in_input;
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 195 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id195in_enable = id185out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id195in_max = id927out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id195in_userReset = id193out_output;

    HWOffsetFix<17,0,UNSIGNED> id195x_1;
    HWOffsetFix<1,0,UNSIGNED> id195x_2;
    HWOffsetFix<1,0,UNSIGNED> id195x_3;
    HWOffsetFix<1,0,UNSIGNED> id195x_4;
    HWOffsetFix<17,0,UNSIGNED> id195x_5e_1t_1e_1;

    id195out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id195st_count)));
    (id195x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id195st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id195x_2) = (gt_fixed((id195x_1),id195in_max));
    (id195x_3) = (and_fixed(id195in_enable,(not_fixed((id195x_2)))));
    (id195x_4) = (c_hw_fix_1_0_uns_bits);
    id195out_wrap = (id195x_4);
    if((id195in_userReset.getValueAsBool())) {
      (id195st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id195x_3).getValueAsBool())) {
        if(((id195x_4).getValueAsBool())) {
          (id195st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id195x_5e_1t_1e_1) = (id195x_1);
          (id195st_count) = (id195x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 926 (NodeConstantRawBits)
  }
  { // Node ID: 197 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id197in_a = id195out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id197in_b = id926out_value;

    id197out_result[(getCycle()+1)%2] = (eq_fixed(id197in_a,id197in_b));
  }
  { // Node ID: 175 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 172 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id172in_ctr_done = id754out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id172in_rst_done = id755out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id172in_sm_en = id146out_s0_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id172in_sm_maxIn_0 = id175out_value;

    m_sm_void4381_sm.inputdata_ctr_done = id172in_ctr_done.getBitString();
    m_sm_void4381_sm.inputdata_rst_done = id172in_rst_done.getBitString();
    m_sm_void4381_sm.inputdata_sm_en = id172in_sm_en.getBitString();
    m_sm_void4381_sm.inputdata_sm_maxIn_0 = id172in_sm_maxIn_0.getBitString();
    m_sm_void4381_sm.execute(true);
    id172out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4381_sm.outputdata_ctr_en));
    id172out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_void4381_sm.outputdata_ctr_maxOut_0) ));
    id172out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4381_sm.outputdata_rst_en));
    id172out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void4381_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id176out_output;

  { // Node ID: 176 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id176in_input = id172out_ctr_en;

    id176out_output = id176in_input;
  }
  { // Node ID: 754 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id754in_input = id176out_output;

    id754out_output[(getCycle()+1)%2] = id754in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id725out_output;

  { // Node ID: 725 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id725in_input = id172out_rst_en;

    id725out_output = id725in_input;
  }
  { // Node ID: 755 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id755in_input = id725out_output;

    id755out_output[(getCycle()+1)%2] = id755in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id726out_output;

  { // Node ID: 726 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id726in_input = id172out_sm_done;

    id726out_output = id726in_input;
  }
  { // Node ID: 801 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id801in_input = id726out_output;

    id801out_output[(getCycle()+1)%2] = id801in_input;
  }
  { // Node ID: 802 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id802in_input = id186out_output;

    id802out_output[(getCycle()+1)%2] = id802in_input;
  }
  { // Node ID: 756 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id756in_input = id728out_output;

    id756out_output[(getCycle()+3)%4] = id756in_input;
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 241 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id241in_en = id238out_ctr_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id241in_max0 = id238out_ctr_maxOut_0;
    const HWOffsetFix<1,0,UNSIGNED> &id241in_reset = id756out_output[getCycle()%4];

    m_sm_CounterChain4386_sm.inputdata_en = id241in_en.getBitString();
    m_sm_CounterChain4386_sm.inputdata_max0 = id241in_max0.getBitString();
    m_sm_CounterChain4386_sm.inputdata_reset = id241in_reset.getBitString();
    m_sm_CounterChain4386_sm.execute(true);
    id241out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain4386_sm.outputdata_counter0) ));
    id241out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4386_sm.outputdata_done));
    id241out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4386_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id242out_output;

  { // Node ID: 242 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id242in_input = id241out_done;

    id242out_output = id242in_input;
  }
  { // Node ID: 757 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id757in_input = id242out_output;

    id757out_output[(getCycle()+1)%2] = id757in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id727out_output;

  { // Node ID: 727 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id727in_input = id238out_rst_en;

    id727out_output = id727in_input;
  }
  { // Node ID: 758 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id758in_input = id727out_output;

    id758out_output[(getCycle()+3)%4] = id758in_input;
  }
  { // Node ID: 759 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id759in_input = id146out_s2_en;

    id759out_output[(getCycle()+3)%4] = id759in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id147out_output;

  { // Node ID: 147 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id147in_input = id146out_sm_done;

    id147out_output = id147in_input;
  }
  { // Node ID: 800 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id800in_input = id147out_output;

    id800out_output[(getCycle()+1)%2] = id800in_input;
  }
  { // Node ID: 760 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id760in_input = id141out_sm_done;

    id760out_output[(getCycle()+1)%2] = id760in_input;
  }
  { // Node ID: 925 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id269out_output;

  { // Node ID: 269 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id269in_input = id262out_output;

    id269out_output = id269in_input;
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 271 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id271in_enable = id261out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id271in_max = id925out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id271in_userReset = id269out_output;

    HWOffsetFix<17,0,UNSIGNED> id271x_1;
    HWOffsetFix<1,0,UNSIGNED> id271x_2;
    HWOffsetFix<1,0,UNSIGNED> id271x_3;
    HWOffsetFix<1,0,UNSIGNED> id271x_4;
    HWOffsetFix<17,0,UNSIGNED> id271x_5e_1t_1e_1;

    id271out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id271st_count)));
    (id271x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id271st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id271x_2) = (gt_fixed((id271x_1),id271in_max));
    (id271x_3) = (and_fixed(id271in_enable,(not_fixed((id271x_2)))));
    (id271x_4) = (c_hw_fix_1_0_uns_bits);
    id271out_wrap = (id271x_4);
    if((id271in_userReset.getValueAsBool())) {
      (id271st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id271x_3).getValueAsBool())) {
        if(((id271x_4).getValueAsBool())) {
          (id271st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id271x_5e_1t_1e_1) = (id271x_1);
          (id271st_count) = (id271x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 924 (NodeConstantRawBits)
  }
  { // Node ID: 273 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id273in_a = id271out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id273in_b = id924out_value;

    id273out_result[(getCycle()+1)%2] = (eq_fixed(id273in_a,id273in_b));
  }
  { // Node ID: 761 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id761in_input = id253out_s0_en;

    id761out_output[(getCycle()+1)%2] = id761in_input;
  }
  { // Node ID: 762 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id762in_input = id314out_ctr_en;

    id762out_output[(getCycle()+1)%2] = id762in_input;
  }
  { // Node ID: 763 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id763in_input = id730out_output;

    id763out_output[(getCycle()+62)%63] = id763in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id729out_output;

  { // Node ID: 729 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id729in_input = id314out_rst_en;

    id729out_output = id729in_input;
  }
  { // Node ID: 764 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id764in_input = id729out_output;

    id764out_output[(getCycle()+61)%62] = id764in_input;
  }
  { // Node ID: 765 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id765in_input = id253out_s1_en;

    id765out_output[(getCycle()+61)%62] = id765in_input;
  }
  { // Node ID: 766 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id766in_input = id139out_s1_en;

    id766out_output[(getCycle()+1)%2] = id766in_input;
  }
  { // Node ID: 767 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id767in_input = id139out_sm_done;

    id767out_output[(getCycle()+1)%2] = id767in_input;
  }
  { // Node ID: 768 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id768in_input = id339out_ctr_en;

    id768out_output[(getCycle()+1)%2] = id768in_input;
  }
  { // Node ID: 911 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (65l)))
  { // Node ID: 343 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id343in_enable = id768out_output[getCycle()%2];
    const HWOffsetFix<9,0,UNSIGNED> &id343in_max = id911out_value;

    HWOffsetFix<10,0,UNSIGNED> id343x_1;
    HWOffsetFix<1,0,UNSIGNED> id343x_2;
    HWOffsetFix<1,0,UNSIGNED> id343x_3;
    HWOffsetFix<10,0,UNSIGNED> id343x_4t_1e_1;

    id343out_count = (cast_fixed2fixed<9,0,UNSIGNED,TRUNCATE>((id343st_count)));
    (id343x_1) = (add_fixed<10,0,UNSIGNED,TRUNCATE>((id343st_count),(c_hw_fix_10_0_uns_bits_1)));
    (id343x_2) = (gte_fixed((id343x_1),(cast_fixed2fixed<10,0,UNSIGNED,TRUNCATE>(id343in_max))));
    (id343x_3) = (and_fixed((id343x_2),id343in_enable));
    id343out_wrap = (id343x_3);
    if((id343in_enable.getValueAsBool())) {
      if(((id343x_3).getValueAsBool())) {
        (id343st_count) = (c_hw_fix_10_0_uns_bits);
      }
      else {
        (id343x_4t_1e_1) = (id343x_1);
        (id343st_count) = (id343x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id344out_output;

  { // Node ID: 344 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id344in_input = id343out_wrap;

    id344out_output = id344in_input;
  }
  { // Node ID: 346 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id346in_a = id339out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id346in_b = id344out_output;

    HWOffsetFix<1,0,UNSIGNED> id346x_1;

    (id346x_1) = (and_fixed(id346in_a,id346in_b));
    id346out_result[(getCycle()+1)%2] = (id346x_1);
  }
  { // Node ID: 769 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id769in_input = id339out_ctr_maxOut_0;

    id769out_output[(getCycle()+1)%2] = id769in_input;
  }
  { // Node ID: 838 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id838in_input = id733out_output;

    id838out_output[(getCycle()+58)%59] = id838in_input;
  }
  { // Node ID: 895 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id895in_input = id838out_output[getCycle()%59];

    id895out_output[(getCycle()+1)%2] = id895in_input;
  }
  { // Node ID: 896 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id896in_input = id895out_output[getCycle()%2];

    id896out_output[(getCycle()+1)%2] = id896in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id732out_output;

  { // Node ID: 732 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id732in_input = id339out_rst_en;

    id732out_output = id732in_input;
  }
  { // Node ID: 771 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id771in_input = id732out_output;

    id771out_output[(getCycle()+59)%60] = id771in_input;
  }
  { // Node ID: 772 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id772in_input = id321out_s0_en;

    id772out_output[(getCycle()+59)%60] = id772in_input;
  }
  { // Node ID: 773 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id773in_input = id362out_ctr_en;

    id773out_output[(getCycle()+1)%2] = id773in_input;
  }
  { // Node ID: 774 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id774in_input = id362out_rst_en;

    id774out_output[(getCycle()+1)%2] = id774in_input;
  }
  { // Node ID: 775 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id775in_input = id321out_s1_en;

    id775out_output[(getCycle()+1)%2] = id775in_input;
  }
  { // Node ID: 776 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id776in_input = id129out_s1_en;

    id776out_output[(getCycle()+1)%2] = id776in_input;
  }
  { // Node ID: 912 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (63l)))
  { // Node ID: 395 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id395in_enable = id391out_ctr_en;
    const HWOffsetFix<9,0,UNSIGNED> &id395in_max = id912out_value;

    HWOffsetFix<10,0,UNSIGNED> id395x_1;
    HWOffsetFix<1,0,UNSIGNED> id395x_2;
    HWOffsetFix<1,0,UNSIGNED> id395x_3;
    HWOffsetFix<10,0,UNSIGNED> id395x_4t_1e_1;

    id395out_count = (cast_fixed2fixed<9,0,UNSIGNED,TRUNCATE>((id395st_count)));
    (id395x_1) = (add_fixed<10,0,UNSIGNED,TRUNCATE>((id395st_count),(c_hw_fix_10_0_uns_bits_1)));
    (id395x_2) = (gte_fixed((id395x_1),(cast_fixed2fixed<10,0,UNSIGNED,TRUNCATE>(id395in_max))));
    (id395x_3) = (and_fixed((id395x_2),id395in_enable));
    id395out_wrap = (id395x_3);
    if((id395in_enable.getValueAsBool())) {
      if(((id395x_3).getValueAsBool())) {
        (id395st_count) = (c_hw_fix_10_0_uns_bits);
      }
      else {
        (id395x_4t_1e_1) = (id395x_1);
        (id395st_count) = (id395x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id396out_output;

  { // Node ID: 396 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id396in_input = id395out_wrap;

    id396out_output = id396in_input;
  }
  { // Node ID: 777 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id777in_input = id396out_output;

    id777out_output[(getCycle()+1)%2] = id777in_input;
  }
  { // Node ID: 398 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id398in_a = id391out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id398in_b = id777out_output[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id398x_1;

    (id398x_1) = (and_fixed(id398in_a,id398in_b));
    id398out_result[(getCycle()+1)%2] = (id398x_1);
  }
  { // Node ID: 778 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id778in_input = id391out_ctr_maxOut_0;

    id778out_output[(getCycle()+1)%2] = id778in_input;
  }
  { // Node ID: 779 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id779in_input = id738out_output;

    id779out_output[(getCycle()+59)%60] = id779in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id737out_output;

  { // Node ID: 737 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id737in_input = id391out_rst_en;

    id737out_output = id737in_input;
  }
  { // Node ID: 780 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id780in_input = id737out_output;

    id780out_output[(getCycle()+58)%59] = id780in_input;
  }
  { // Node ID: 781 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id781in_input = id373out_s0_en;

    id781out_output[(getCycle()+58)%59] = id781in_input;
  }
  { // Node ID: 782 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id782in_input = id414out_ctr_en;

    id782out_output[(getCycle()+1)%2] = id782in_input;
  }
  { // Node ID: 783 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id783in_input = id414out_rst_en;

    id783out_output[(getCycle()+1)%2] = id783in_input;
  }
  { // Node ID: 784 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id784in_input = id373out_s1_en;

    id784out_output[(getCycle()+1)%2] = id784in_input;
  }
  { // Node ID: 785 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id785in_input = id129out_s2_en;

    id785out_output[(getCycle()+1)%2] = id785in_input;
  }
  { // Node ID: 786 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id786in_input = id742out_output;

    id786out_output[(getCycle()+21)%22] = id786in_input;
  }
  if ( (getFillLevel() >= (26l)))
  { // Node ID: 435 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id435in_en = id432out_ctr_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id435in_max0 = id432out_ctr_maxOut_0;
    const HWOffsetFix<1,0,UNSIGNED> &id435in_reset = id786out_output[getCycle()%22];

    m_sm_CounterChain4462_sm.inputdata_en = id435in_en.getBitString();
    m_sm_CounterChain4462_sm.inputdata_max0 = id435in_max0.getBitString();
    m_sm_CounterChain4462_sm.inputdata_reset = id435in_reset.getBitString();
    m_sm_CounterChain4462_sm.execute(true);
    id435out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain4462_sm.outputdata_counter0) ));
    id435out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4462_sm.outputdata_done));
    id435out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4462_sm.outputdata_saturated));
  }
  { // Node ID: 787 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id787in_input = id435out_done;

    id787out_output[(getCycle()+1)%2] = id787in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id741out_output;

  { // Node ID: 741 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id741in_input = id432out_rst_en;

    id741out_output = id741in_input;
  }
  { // Node ID: 788 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id788in_input = id741out_output;

    id788out_output[(getCycle()+21)%22] = id788in_input;
  }
  { // Node ID: 789 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id789in_input = id423out_s0_en;

    id789out_output[(getCycle()+21)%22] = id789in_input;
  }
  { // Node ID: 790 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id790in_input = id129out_s3_en;

    id790out_output[(getCycle()+1)%2] = id790in_input;
  }
  { // Node ID: 791 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id791in_input = id129out_sm_done;

    id791out_output[(getCycle()+1)%2] = id791in_input;
  }
  { // Node ID: 792 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id792in_input = id467out_ctr_en;

    id792out_output[(getCycle()+1)%2] = id792in_input;
  }
  { // Node ID: 793 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id793in_input = id744out_output;

    id793out_output[(getCycle()+61)%62] = id793in_input;
  }
  { // Node ID: 794 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id794in_input = id467out_rst_en;

    id794out_output[(getCycle()+60)%61] = id794in_input;
  }
  { // Node ID: 795 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id795in_input = id462out_s0_en;

    id795out_output[(getCycle()+60)%61] = id795in_input;
  }
  { // Node ID: 923 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id488out_output;

  { // Node ID: 488 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id488in_input = id487out_result[getCycle()%2];

    id488out_output = id488in_input;
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 476 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id476in_memDone = id488out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id476in_sm_en = id462out_s1_en;

    m_sm_DRAM4325_void4486_outldSM.inputdata_memDone = id476in_memDone.getBitString();
    m_sm_DRAM4325_void4486_outldSM.inputdata_sm_en = id476in_sm_en.getBitString();
    m_sm_DRAM4325_void4486_outldSM.execute(true);
    id476out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM4325_void4486_outldSM.outputdata_memStart));
    id476out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM4325_void4486_outldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id477out_output;

  { // Node ID: 477 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id477in_input = id476out_sm_done;

    id477out_output = id477in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id483out_output;

  { // Node ID: 483 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id483in_input = id477out_output;

    id483out_output = id483in_input;
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 485 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id485in_enable = id476out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id485in_max = id923out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id485in_userReset = id483out_output;

    HWOffsetFix<17,0,UNSIGNED> id485x_1;
    HWOffsetFix<1,0,UNSIGNED> id485x_2;
    HWOffsetFix<1,0,UNSIGNED> id485x_3;
    HWOffsetFix<1,0,UNSIGNED> id485x_4;
    HWOffsetFix<17,0,UNSIGNED> id485x_5e_1t_1e_1;

    id485out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id485st_count)));
    (id485x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id485st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id485x_2) = (gt_fixed((id485x_1),id485in_max));
    (id485x_3) = (and_fixed(id485in_enable,(not_fixed((id485x_2)))));
    (id485x_4) = (c_hw_fix_1_0_uns_bits);
    id485out_wrap = (id485x_4);
    if((id485in_userReset.getValueAsBool())) {
      (id485st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id485x_3).getValueAsBool())) {
        if(((id485x_4).getValueAsBool())) {
          (id485st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id485x_5e_1t_1e_1) = (id485x_1);
          (id485st_count) = (id485x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 922 (NodeConstantRawBits)
  }
  { // Node ID: 487 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id487in_a = id485out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id487in_b = id922out_value;

    id487out_result[(getCycle()+1)%2] = (eq_fixed(id487in_a,id487in_b));
  }
  { // Node ID: 796 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id796in_input = id477out_output;

    id796out_output[(getCycle()+1)%2] = id796in_input;
  }
  { // Node ID: 797 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id797in_input = id124out_s1_en;

    id797out_output[(getCycle()+1)%2] = id797in_input;
  }
  { // Node ID: 921 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 547 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id547in_enable = id1out_intr_en;
    const HWOffsetFix<33,0,UNSIGNED> &id547in_max = id921out_value;

    HWOffsetFix<33,0,UNSIGNED> id547x_1;
    HWOffsetFix<1,0,UNSIGNED> id547x_2;
    HWOffsetFix<1,0,UNSIGNED> id547x_3;
    HWOffsetFix<33,0,UNSIGNED> id547x_4t_1e_1;

    id547out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id547st_count)));
    (id547x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id547st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id547x_2) = (gte_fixed((id547x_1),id547in_max));
    (id547x_3) = (and_fixed((id547x_2),id547in_enable));
    id547out_wrap = (id547x_3);
    if((id547in_enable.getValueAsBool())) {
      if(((id547x_3).getValueAsBool())) {
        (id547st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id547x_4t_1e_1) = (id547x_1);
        (id547st_count) = (id547x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 798 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id798in_input = id547out_wrap;

    id798out_output[(getCycle()+1)%2] = id798in_input;
  }
  { // Node ID: 799 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id799in_input = id124out_sm_done;

    id799out_output[(getCycle()+1)%2] = id799in_input;
  }
  { // Node ID: 803 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id803in_input = id185out_memStart;

    id803out_output[(getCycle()+1)%2] = id803in_input;
  }
  { // Node ID: 920 (NodeConstantRawBits)
  }
  { // Node ID: 200 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id200in_a = id195out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id200in_b = id920out_value;

    id200out_result[(getCycle()+1)%2] = (eq_fixed(id200in_a,id200in_b));
  }
  { // Node ID: 201 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id201in_a = id803out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id201in_b = id200out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id201x_1;

    (id201x_1) = (and_fixed(id201in_a,id201in_b));
    id201out_result[(getCycle()+1)%2] = (id201x_1);
  }
  { // Node ID: 219 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id220out_result;

  { // Node ID: 220 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id220in_a = id219out_io_DRAM4323_void4384_in_cmd_force_disabled;

    id220out_result = (not_fixed(id220in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id221out_result;

  { // Node ID: 221 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id221in_a = id201out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id221in_b = id220out_result;

    HWOffsetFix<1,0,UNSIGNED> id221x_1;

    (id221x_1) = (and_fixed(id221in_a,id221in_b));
    id221out_result = (id221x_1);
  }
  { // Node ID: 809 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id809in_input = id221out_result;

    id809out_output[(getCycle()+39)%40] = id809in_input;
  }
  { // Node ID: 624 (NodeConstantRawBits)
  }
  { // Node ID: 629 (NodeConstantRawBits)
  }
  { // Node ID: 206 (NodeConstantRawBits)
  }
  HWRawBits<8> id226out_output;

  { // Node ID: 226 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id226in_input = id206out_value;

    id226out_output = (cast_fixed2bits(id226in_input));
  }
  { // Node ID: 634 (NodeConstantRawBits)
  }
  { // Node ID: 919 (NodeConstantRawBits)
  }
  { // Node ID: 537 (NodeConstantRawBits)
  }
  { // Node ID: 536 (NodeConstantRawBits)
  }
  { // Node ID: 5 (NodeConstantRawBits)
  }
  { // Node ID: 7 (NodeConstantRawBits)
  }
  { // Node ID: 9 (NodeConstantRawBits)
  }
  { // Node ID: 11 (NodeConstantRawBits)
  }
  { // Node ID: 13 (NodeConstantRawBits)
  }
  { // Node ID: 15 (NodeConstantRawBits)
  }
  { // Node ID: 6 (NodeConstantRawBits)
  }
  { // Node ID: 8 (NodeConstantRawBits)
  }
  { // Node ID: 10 (NodeConstantRawBits)
  }
  { // Node ID: 12 (NodeConstantRawBits)
  }
  { // Node ID: 14 (NodeConstantRawBits)
  }
  { // Node ID: 16 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 4 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id4in_broadcast = id537out_value;
    const HWOffsetFix<2,0,UNSIGNED> &id4in_numBlanks = id536out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageDone0 = id801out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageDone1 = id802out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageDone2 = id5out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageDone3 = id7out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageDone4 = id9out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageDone5 = id11out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageDone6 = id13out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageDone7 = id15out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageEn0 = id146out_s0_en;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageEn1 = id146out_s1_en;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageEn2 = id6out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageEn3 = id8out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageEn4 = id10out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageEn5 = id12out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageEn6 = id14out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id4in_stageEn7 = id16out_value;

    m_sm_reg4378_0.inputdata_broadcast = id4in_broadcast.getBitString();
    m_sm_reg4378_0.inputdata_numBlanks = id4in_numBlanks.getBitString();
    m_sm_reg4378_0.inputdata_stageDone0 = id4in_stageDone0.getBitString();
    m_sm_reg4378_0.inputdata_stageDone1 = id4in_stageDone1.getBitString();
    m_sm_reg4378_0.inputdata_stageDone2 = id4in_stageDone2.getBitString();
    m_sm_reg4378_0.inputdata_stageDone3 = id4in_stageDone3.getBitString();
    m_sm_reg4378_0.inputdata_stageDone4 = id4in_stageDone4.getBitString();
    m_sm_reg4378_0.inputdata_stageDone5 = id4in_stageDone5.getBitString();
    m_sm_reg4378_0.inputdata_stageDone6 = id4in_stageDone6.getBitString();
    m_sm_reg4378_0.inputdata_stageDone7 = id4in_stageDone7.getBitString();
    m_sm_reg4378_0.inputdata_stageEn0 = id4in_stageEn0.getBitString();
    m_sm_reg4378_0.inputdata_stageEn1 = id4in_stageEn1.getBitString();
    m_sm_reg4378_0.inputdata_stageEn2 = id4in_stageEn2.getBitString();
    m_sm_reg4378_0.inputdata_stageEn3 = id4in_stageEn3.getBitString();
    m_sm_reg4378_0.inputdata_stageEn4 = id4in_stageEn4.getBitString();
    m_sm_reg4378_0.inputdata_stageEn5 = id4in_stageEn5.getBitString();
    m_sm_reg4378_0.inputdata_stageEn6 = id4in_stageEn6.getBitString();
    m_sm_reg4378_0.inputdata_stageEn7 = id4in_stageEn7.getBitString();
    m_sm_reg4378_0.execute(true);
    id4out_curBuf0 = (HWOffsetFix<2,0,UNSIGNED>(m_sm_reg4378_0.outputdata_curBuf0));
    id4out_curBuf1 = (HWOffsetFix<2,0,UNSIGNED>(m_sm_reg4378_0.outputdata_curBuf1));
  }
  HWOffsetFix<1,0,UNSIGNED> id29out_o;

  { // Node ID: 29 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id29in_i = id4out_curBuf1;

    id29out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id29in_i));
  }
  { // Node ID: 808 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id808in_input = id29out_o;

    id808out_output[(getCycle()+2)%3] = id808in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id19out_o;

  { // Node ID: 19 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id19in_i = id4out_curBuf0;

    id19out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id19in_i));
  }
  { // Node ID: 535 (NodeConstantRawBits)
  }
  { // Node ID: 20 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id20in_sel = id19out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id20in_option0 = id801out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id20in_option1 = id535out_value;

    HWOffsetFix<1,0,UNSIGNED> id20x_1;

    switch((id20in_sel.getValueAsLong())) {
      case 0l:
        id20x_1 = id20in_option0;
        break;
      case 1l:
        id20x_1 = id20in_option1;
        break;
      default:
        id20x_1 = (c_hw_fix_1_0_uns_undef);
        break;
    }
    id20out_result[(getCycle()+1)%2] = (id20x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id17out_o;

  { // Node ID: 17 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id17in_i = id4out_curBuf0;

    id17out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id17in_i));
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 153 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id153in_en = id726out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id153in_max0 = id121out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id153in_reset = id147out_output;

    m_sm_CounterChain4377_sm.inputdata_en = id153in_en.getBitString();
    m_sm_CounterChain4377_sm.inputdata_max0 = id153in_max0.getBitString();
    m_sm_CounterChain4377_sm.inputdata_reset = id153in_reset.getBitString();
    m_sm_CounterChain4377_sm.execute(true);
    id153out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain4377_sm.outputdata_counter0) ));
    id153out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4377_sm.outputdata_done));
    id153out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4377_sm.outputdata_saturated));
  }
  HWOffsetFix<32,5,TWOSCOMPLEMENT> id675out_output;

  { // Node ID: 675 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id675in_input = id153out_counter0;

    id675out_output = (cast_bits2fixed<32,5,TWOSCOMPLEMENT>((cast_fixed2bits(id675in_input))));
  }
  HWOffsetFix<32,6,TWOSCOMPLEMENT> id676out_output;

  { // Node ID: 676 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id676in_input = id153out_counter0;

    id676out_output = (cast_bits2fixed<32,6,TWOSCOMPLEMENT>((cast_fixed2bits(id676in_input))));
  }
  { // Node ID: 677 (NodeAdd)
    const HWOffsetFix<32,5,TWOSCOMPLEMENT> &id677in_a = id675out_output;
    const HWOffsetFix<32,6,TWOSCOMPLEMENT> &id677in_b = id676out_output;

    id677out_result[(getCycle()+1)%2] = (add_fixed<34,5,TWOSCOMPLEMENT,TONEAR>(id677in_a,id677in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id678out_o;

  { // Node ID: 678 (NodeCast)
    const HWOffsetFix<34,5,TWOSCOMPLEMENT> &id678in_i = id677out_result[getCycle()%2];

    id678out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id678in_i));
  }
  { // Node ID: 534 (NodeConstantRawBits)
  }
  { // Node ID: 18 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id18in_sel = id17out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id18in_option0 = id678out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id18in_option1 = id534out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id18x_1;

    switch((id18in_sel.getValueAsLong())) {
      case 0l:
        id18x_1 = id18in_option0;
        break;
      case 1l:
        id18x_1 = id18in_option1;
        break;
      default:
        id18x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id18out_result[(getCycle()+1)%2] = (id18x_1);
  }
  { // Node ID: 180 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 21 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id21in_load = id20out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_input = id18out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id21in_user_reset = id180out_value;

    if((id21in_user_reset.getValueAsBool())) {
      (id21st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id21in_load.getValueAsBool())) {
        (id21st_holdreg) = id21in_input;
      }
    }
    id21out_output[(getCycle()+1)%2] = (id21st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id24out_o;

  { // Node ID: 24 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id24in_i = id4out_curBuf1;

    id24out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id24in_i));
  }
  { // Node ID: 25 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id25in_sel = id24out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id25in_option0 = id801out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id25in_option1 = id535out_value;

    HWOffsetFix<1,0,UNSIGNED> id25x_1;

    switch((id25in_sel.getValueAsLong())) {
      case 0l:
        id25x_1 = id25in_option0;
        break;
      case 1l:
        id25x_1 = id25in_option1;
        break;
      default:
        id25x_1 = (c_hw_fix_1_0_uns_undef);
        break;
    }
    id25out_result[(getCycle()+1)%2] = (id25x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id22out_o;

  { // Node ID: 22 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id22in_i = id4out_curBuf1;

    id22out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id22in_i));
  }
  { // Node ID: 23 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id23in_sel = id22out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id23in_option0 = id678out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id23in_option1 = id534out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id23x_1;

    switch((id23in_sel.getValueAsLong())) {
      case 0l:
        id23x_1 = id23in_option0;
        break;
      case 1l:
        id23x_1 = id23in_option1;
        break;
      default:
        id23x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id23out_result[(getCycle()+1)%2] = (id23x_1);
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 26 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id26in_load = id25out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id26in_input = id23out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id26in_user_reset = id180out_value;

    if((id26in_user_reset.getValueAsBool())) {
      (id26st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id26in_load.getValueAsBool())) {
        (id26st_holdreg) = id26in_input;
      }
    }
    id26out_output[(getCycle()+1)%2] = (id26st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id30out_result;

  { // Node ID: 30 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id30in_sel = id808out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id30in_option0 = id21out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id30in_option1 = id26out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id30x_1;

    switch((id30in_sel.getValueAsLong())) {
      case 0l:
        id30x_1 = id30in_option0;
        break;
      case 1l:
        id30x_1 = id30in_option1;
        break;
      default:
        id30x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id30out_result = (id30x_1);
  }
  { // Node ID: 918 (NodeConstantRawBits)
  }
  { // Node ID: 188 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id188in_a = id30out_result;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id188in_b = id918out_value;

    id188out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id188in_a,id188in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id189out_o;

  { // Node ID: 189 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id189in_i = id188out_result[getCycle()%39];

    id189out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id189in_i));
  }
  { // Node ID: 191 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id191in_a = id919out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id191in_b = id189out_o;

    id191out_result[(getCycle()+1)%2] = (add_fixed<32,0,UNSIGNED,TONEAR>(id191in_a,id191in_b));
  }
  HWRawBits<32> id223out_output;

  { // Node ID: 223 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id223in_input = id191out_result[getCycle()%2];

    id223out_output = (cast_fixed2bits(id223in_input));
  }
  HWRawBits<40> id225out_result;

  { // Node ID: 225 (NodeCat)
    const HWRawBits<8> &id225in_in0 = id634out_value;
    const HWRawBits<32> &id225in_in1 = id223out_output;

    id225out_result = (cat(id225in_in0,id225in_in1));
  }
  HWRawBits<48> id227out_result;

  { // Node ID: 227 (NodeCat)
    const HWRawBits<8> &id227in_in0 = id226out_output;
    const HWRawBits<40> &id227in_in1 = id225out_result;

    id227out_result = (cat(id227in_in0,id227in_in1));
  }
  HWRawBits<63> id229out_result;

  { // Node ID: 229 (NodeCat)
    const HWRawBits<15> &id229in_in0 = id629out_value;
    const HWRawBits<48> &id229in_in1 = id227out_result;

    id229out_result = (cat(id229in_in0,id229in_in1));
  }
  HWRawBits<64> id231out_result;

  { // Node ID: 231 (NodeCat)
    const HWRawBits<1> &id231in_in0 = id624out_value;
    const HWRawBits<63> &id231in_in1 = id229out_result;

    id231out_result = (cat(id231in_in0,id231in_in1));
  }
  if ( (getFillLevel() >= (45l)) && (getFlushLevel() < (45l)|| !isFlushingActive() ))
  { // Node ID: 222 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id222in_output_control = id809out_output[getCycle()%40];
    const HWRawBits<64> &id222in_data = id231out_result;

    bool id222x_1;

    (id222x_1) = ((id222in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(45l))&(isFlushingActive()))));
    if((id222x_1)) {
      writeOutput(m_DRAM4323_void4384_in_cmd, id222in_data);
    }
  }
  { // Node ID: 810 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id810in_input = id261out_memStart;

    id810out_output[(getCycle()+1)%2] = id810in_input;
  }
  { // Node ID: 917 (NodeConstantRawBits)
  }
  { // Node ID: 276 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id276in_a = id271out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id276in_b = id917out_value;

    id276out_result[(getCycle()+1)%2] = (eq_fixed(id276in_a,id276in_b));
  }
  { // Node ID: 277 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id277in_a = id810out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id277in_b = id276out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id277x_1;

    (id277x_1) = (and_fixed(id277in_a,id277in_b));
    id277out_result[(getCycle()+1)%2] = (id277x_1);
  }
  { // Node ID: 295 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id296out_result;

  { // Node ID: 296 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id296in_a = id295out_io_DRAM4324_void4400_in_cmd_force_disabled;

    id296out_result = (not_fixed(id296in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id297out_result;

  { // Node ID: 297 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id297in_a = id277out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id297in_b = id296out_result;

    HWOffsetFix<1,0,UNSIGNED> id297x_1;

    (id297x_1) = (and_fixed(id297in_a,id297in_b));
    id297out_result = (id297x_1);
  }
  { // Node ID: 811 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id811in_input = id297out_result;

    id811out_output[(getCycle()+42)%43] = id811in_input;
  }
  { // Node ID: 635 (NodeConstantRawBits)
  }
  { // Node ID: 640 (NodeConstantRawBits)
  }
  { // Node ID: 282 (NodeConstantRawBits)
  }
  HWRawBits<8> id302out_output;

  { // Node ID: 302 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id302in_input = id282out_value;

    id302out_output = (cast_fixed2bits(id302in_input));
  }
  { // Node ID: 645 (NodeConstantRawBits)
  }
  { // Node ID: 649 (NodeConstantRawBits)
  }
  HWRawBits<40> id301out_result;

  { // Node ID: 301 (NodeCat)
    const HWRawBits<8> &id301in_in0 = id645out_value;
    const HWRawBits<32> &id301in_in1 = id649out_value;

    id301out_result = (cat(id301in_in0,id301in_in1));
  }
  HWRawBits<48> id303out_result;

  { // Node ID: 303 (NodeCat)
    const HWRawBits<8> &id303in_in0 = id302out_output;
    const HWRawBits<40> &id303in_in1 = id301out_result;

    id303out_result = (cat(id303in_in0,id303in_in1));
  }
  HWRawBits<63> id305out_result;

  { // Node ID: 305 (NodeCat)
    const HWRawBits<15> &id305in_in0 = id640out_value;
    const HWRawBits<48> &id305in_in1 = id303out_result;

    id305out_result = (cat(id305in_in0,id305in_in1));
  }
  HWRawBits<64> id307out_result;

  { // Node ID: 307 (NodeCat)
    const HWRawBits<1> &id307in_in0 = id635out_value;
    const HWRawBits<63> &id307in_in1 = id305out_result;

    id307out_result = (cat(id307in_in0,id307in_in1));
  }
  if ( (getFillLevel() >= (50l)) && (getFlushLevel() < (50l)|| !isFlushingActive() ))
  { // Node ID: 298 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id298in_output_control = id811out_output[getCycle()%43];
    const HWRawBits<64> &id298in_data = id307out_result;

    bool id298x_1;

    (id298x_1) = ((id298in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(50l))&(isFlushingActive()))));
    if((id298x_1)) {
      writeOutput(m_DRAM4324_void4400_in_cmd, id298in_data);
    }
  }
  { // Node ID: 812 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id812in_input = id476out_memStart;

    id812out_output[(getCycle()+1)%2] = id812in_input;
  }
  { // Node ID: 916 (NodeConstantRawBits)
  }
  { // Node ID: 490 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id490in_a = id485out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id490in_b = id916out_value;

    id490out_result[(getCycle()+1)%2] = (eq_fixed(id490in_a,id490in_b));
  }
  { // Node ID: 491 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id491in_a = id812out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id491in_b = id490out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id491x_1;

    (id491x_1) = (and_fixed(id491in_a,id491in_b));
    id491out_result[(getCycle()+1)%2] = (id491x_1);
  }
  { // Node ID: 508 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id509out_result;

  { // Node ID: 509 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id509in_a = id508out_io_DRAM4325_void4486_out_cmd_force_disabled;

    id509out_result = (not_fixed(id509in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id510out_result;

  { // Node ID: 510 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id510in_a = id491out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id510in_b = id509out_result;

    HWOffsetFix<1,0,UNSIGNED> id510x_1;

    (id510x_1) = (and_fixed(id510in_a,id510in_b));
    id510out_result = (id510x_1);
  }
  { // Node ID: 650 (NodeConstantRawBits)
  }
  { // Node ID: 655 (NodeConstantRawBits)
  }
  { // Node ID: 495 (NodeConstantRawBits)
  }
  HWRawBits<8> id515out_output;

  { // Node ID: 515 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id515in_input = id495out_value;

    id515out_output = (cast_fixed2bits(id515in_input));
  }
  { // Node ID: 660 (NodeConstantRawBits)
  }
  { // Node ID: 664 (NodeConstantRawBits)
  }
  HWRawBits<40> id514out_result;

  { // Node ID: 514 (NodeCat)
    const HWRawBits<8> &id514in_in0 = id660out_value;
    const HWRawBits<32> &id514in_in1 = id664out_value;

    id514out_result = (cat(id514in_in0,id514in_in1));
  }
  HWRawBits<48> id516out_result;

  { // Node ID: 516 (NodeCat)
    const HWRawBits<8> &id516in_in0 = id515out_output;
    const HWRawBits<40> &id516in_in1 = id514out_result;

    id516out_result = (cat(id516in_in0,id516in_in1));
  }
  HWRawBits<63> id518out_result;

  { // Node ID: 518 (NodeCat)
    const HWRawBits<15> &id518in_in0 = id655out_value;
    const HWRawBits<48> &id518in_in1 = id516out_result;

    id518out_result = (cat(id518in_in0,id518in_in1));
  }
  HWRawBits<64> id520out_result;

  { // Node ID: 520 (NodeCat)
    const HWRawBits<1> &id520in_in0 = id650out_value;
    const HWRawBits<63> &id520in_in1 = id518out_result;

    id520out_result = (cat(id520in_in0,id520in_in1));
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 511 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id511in_output_control = id510out_result;
    const HWRawBits<64> &id511in_data = id520out_result;

    bool id511x_1;

    (id511x_1) = ((id511in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id511x_1)) {
      writeOutput(m_DRAM4325_void4486_out_cmd, id511in_data);
    }
  }
  { // Node ID: 521 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id522out_result;

  { // Node ID: 522 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id522in_a = id521out_io_DRAM4325_void4486_out_force_disabled;

    id522out_result = (not_fixed(id522in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id523out_result;

  { // Node ID: 523 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id523in_a = id792out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id523in_b = id522out_result;

    HWOffsetFix<1,0,UNSIGNED> id523x_1;

    (id523x_1) = (and_fixed(id523in_a,id523in_b));
    id523out_result = (id523x_1);
  }
  { // Node ID: 889 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id889in_input = id523out_result;

    id889out_output[(getCycle()+2)%3] = id889in_input;
  }
  { // Node ID: 875 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id875in_input = id435out_counter0;

    id875out_output[(getCycle()+40)%41] = id875in_input;
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id745out_output;

  { // Node ID: 745 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id745in_input = id875out_output[getCycle()%41];

    id745out_output = id745in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id456out_o;

  { // Node ID: 456 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id456in_i = id745out_output;

    id456out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id456in_i));
  }
  { // Node ID: 888 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id888in_input = id456out_o;

    id888out_output[(getCycle()+20)%21] = id888in_input;
  }
  { // Node ID: 815 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id815in_input = id740out_output;

    id815out_output[(getCycle()+59)%60] = id815in_input;
  }
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 383 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id383in_r_done = id815out_output[getCycle()%60];
    const HWOffsetFix<1,0,UNSIGNED> &id383in_w_done = id779out_output[getCycle()%60];

    m_sm_metapipe4458_FixedPoint37320_1.inputdata_r_done = id383in_r_done.getBitString();
    m_sm_metapipe4458_FixedPoint37320_1.inputdata_w_done = id383in_w_done.getBitString();
    m_sm_metapipe4458_FixedPoint37320_1.execute(true);
    id383out_curBuf = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4458_FixedPoint37320_1.outputdata_curBuf));
  }
  { // Node ID: 821 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id821in_input = id383out_curBuf;

    id821out_output[(getCycle()+2)%3] = id821in_input;
  }
  { // Node ID: 387 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id387in_a = id383out_curBuf;
    const HWOffsetFix<1,0,UNSIGNED> &id387in_b = id779out_output[getCycle()%60];

    HWOffsetFix<1,0,UNSIGNED> id387x_1;

    (id387x_1) = (and_fixed(id387in_a,id387in_b));
    id387out_result[(getCycle()+1)%2] = (id387x_1);
  }
  { // Node ID: 903 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id903in_input = id779out_output[getCycle()%60];

    id903out_output[(getCycle()+1)%2] = id903in_input;
  }
  { // Node ID: 819 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id819in_input = id374out_output;

    id819out_output[(getCycle()+61)%62] = id819in_input;
  }
  if ( (getFillLevel() >= (65l)))
  { // Node ID: 380 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id380in_en = id903out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id380in_max0 = id121out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id380in_reset = id819out_output[getCycle()%62];

    m_sm_CounterChain4437_sm.inputdata_en = id380in_en.getBitString();
    m_sm_CounterChain4437_sm.inputdata_max0 = id380in_max0.getBitString();
    m_sm_CounterChain4437_sm.inputdata_reset = id380in_reset.getBitString();
    m_sm_CounterChain4437_sm.execute(true);
    id380out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain4437_sm.outputdata_counter0) ));
    id380out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4437_sm.outputdata_done));
    id380out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4437_sm.outputdata_saturated));
  }
  { // Node ID: 390 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (65l)))
  { // Node ID: 388 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id388in_load = id387out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id388in_input = id380out_counter0;
    const HWOffsetFix<1,0,UNSIGNED> &id388in_user_reset = id390out_value;

    if((id388in_user_reset.getValueAsBool())) {
      (id388st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id388in_load.getValueAsBool())) {
        (id388st_holdreg) = id388in_input;
      }
    }
    id388out_output[(getCycle()+1)%2] = (id388st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id384out_result;

  { // Node ID: 384 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id384in_a = id383out_curBuf;

    id384out_result = (not_fixed(id384in_a));
  }
  { // Node ID: 385 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id385in_a = id384out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id385in_b = id779out_output[getCycle()%60];

    HWOffsetFix<1,0,UNSIGNED> id385x_1;

    (id385x_1) = (and_fixed(id385in_a,id385in_b));
    id385out_result[(getCycle()+1)%2] = (id385x_1);
  }
  if ( (getFillLevel() >= (65l)))
  { // Node ID: 386 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id386in_load = id385out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id386in_input = id380out_counter0;
    const HWOffsetFix<1,0,UNSIGNED> &id386in_user_reset = id390out_value;

    if((id386in_user_reset.getValueAsBool())) {
      (id386st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id386in_load.getValueAsBool())) {
        (id386st_holdreg) = id386in_input;
      }
    }
    id386out_output[(getCycle()+1)%2] = (id386st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id389out_result;

  { // Node ID: 389 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id389in_sel = id821out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id389in_option0 = id388out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id389in_option1 = id386out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id389x_1;

    switch((id389in_sel.getValueAsLong())) {
      case 0l:
        id389x_1 = id389in_option0;
        break;
      case 1l:
        id389x_1 = id389in_option1;
        break;
      default:
        id389x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id389out_result = (id389x_1);
  }
  HWOffsetFix<7,0,UNSIGNED> id422out_o;

  { // Node ID: 422 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id422in_i = id389out_result;

    id422out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id422in_i));
  }
  { // Node ID: 876 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id876in_input = id422out_o;

    id876out_output[(getCycle()+17)%18] = id876in_input;
  }
  { // Node ID: 533 (NodeConstantRawBits)
  }
  { // Node ID: 532 (NodeConstantRawBits)
  }
  { // Node ID: 904 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id904in_input = id903out_output[getCycle()%2];

    id904out_output[(getCycle()+13)%14] = id904in_input;
  }
  { // Node ID: 905 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id905in_input = id904out_output[getCycle()%14];

    id905out_output[(getCycle()+1)%2] = id905in_input;
  }
  { // Node ID: 906 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id906in_input = id815out_output[getCycle()%60];

    id906out_output[(getCycle()+15)%16] = id906in_input;
  }
  { // Node ID: 91 (NodeConstantRawBits)
  }
  { // Node ID: 93 (NodeConstantRawBits)
  }
  { // Node ID: 95 (NodeConstantRawBits)
  }
  { // Node ID: 97 (NodeConstantRawBits)
  }
  { // Node ID: 99 (NodeConstantRawBits)
  }
  { // Node ID: 101 (NodeConstantRawBits)
  }
  { // Node ID: 907 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id907in_input = id781out_output[getCycle()%59];

    id907out_output[(getCycle()+16)%17] = id907in_input;
  }
  { // Node ID: 908 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id908in_input = id784out_output[getCycle()%2];

    id908out_output[(getCycle()+1)%2] = id908in_input;
  }
  { // Node ID: 909 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id909in_input = id908out_output[getCycle()%2];

    id909out_output[(getCycle()+72)%73] = id909in_input;
  }
  { // Node ID: 92 (NodeConstantRawBits)
  }
  { // Node ID: 94 (NodeConstantRawBits)
  }
  { // Node ID: 96 (NodeConstantRawBits)
  }
  { // Node ID: 98 (NodeConstantRawBits)
  }
  { // Node ID: 100 (NodeConstantRawBits)
  }
  { // Node ID: 102 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (79l)))
  { // Node ID: 90 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id90in_broadcast = id533out_value;
    const HWOffsetFix<2,0,UNSIGNED> &id90in_numBlanks = id532out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageDone0 = id905out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageDone1 = id906out_output[getCycle()%16];
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageDone2 = id91out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageDone3 = id93out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageDone4 = id95out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageDone5 = id97out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageDone6 = id99out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageDone7 = id101out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageEn0 = id907out_output[getCycle()%17];
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageEn1 = id909out_output[getCycle()%73];
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageEn2 = id92out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageEn3 = id94out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageEn4 = id96out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageEn5 = id98out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageEn6 = id100out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_stageEn7 = id102out_value;

    m_sm_reg4438_1.inputdata_broadcast = id90in_broadcast.getBitString();
    m_sm_reg4438_1.inputdata_numBlanks = id90in_numBlanks.getBitString();
    m_sm_reg4438_1.inputdata_stageDone0 = id90in_stageDone0.getBitString();
    m_sm_reg4438_1.inputdata_stageDone1 = id90in_stageDone1.getBitString();
    m_sm_reg4438_1.inputdata_stageDone2 = id90in_stageDone2.getBitString();
    m_sm_reg4438_1.inputdata_stageDone3 = id90in_stageDone3.getBitString();
    m_sm_reg4438_1.inputdata_stageDone4 = id90in_stageDone4.getBitString();
    m_sm_reg4438_1.inputdata_stageDone5 = id90in_stageDone5.getBitString();
    m_sm_reg4438_1.inputdata_stageDone6 = id90in_stageDone6.getBitString();
    m_sm_reg4438_1.inputdata_stageDone7 = id90in_stageDone7.getBitString();
    m_sm_reg4438_1.inputdata_stageEn0 = id90in_stageEn0.getBitString();
    m_sm_reg4438_1.inputdata_stageEn1 = id90in_stageEn1.getBitString();
    m_sm_reg4438_1.inputdata_stageEn2 = id90in_stageEn2.getBitString();
    m_sm_reg4438_1.inputdata_stageEn3 = id90in_stageEn3.getBitString();
    m_sm_reg4438_1.inputdata_stageEn4 = id90in_stageEn4.getBitString();
    m_sm_reg4438_1.inputdata_stageEn5 = id90in_stageEn5.getBitString();
    m_sm_reg4438_1.inputdata_stageEn6 = id90in_stageEn6.getBitString();
    m_sm_reg4438_1.inputdata_stageEn7 = id90in_stageEn7.getBitString();
    m_sm_reg4438_1.execute(true);
    id90out_curBuf0 = (HWOffsetFix<2,0,UNSIGNED>(m_sm_reg4438_1.outputdata_curBuf0));
    id90out_curBuf1 = (HWOffsetFix<2,0,UNSIGNED>(m_sm_reg4438_1.outputdata_curBuf1));
  }
  HWOffsetFix<1,0,UNSIGNED> id115out_o;

  { // Node ID: 115 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id115in_i = id90out_curBuf1;

    id115out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id115in_i));
  }
  { // Node ID: 872 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id872in_input = id115out_o;

    id872out_output[(getCycle()+2)%3] = id872in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id105out_o;

  { // Node ID: 105 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id105in_i = id90out_curBuf0;

    id105out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id105in_i));
  }
  { // Node ID: 531 (NodeConstantRawBits)
  }
  { // Node ID: 106 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id106in_sel = id105out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id106in_option0 = id905out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id106in_option1 = id531out_value;

    HWOffsetFix<1,0,UNSIGNED> id106x_1;

    switch((id106in_sel.getValueAsLong())) {
      case 0l:
        id106x_1 = id106in_option0;
        break;
      case 1l:
        id106x_1 = id106in_option1;
        break;
      default:
        id106x_1 = (c_hw_fix_1_0_uns_undef);
        break;
    }
    id106out_result[(getCycle()+1)%2] = (id106x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id103out_o;

  { // Node ID: 103 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id103in_i = id90out_curBuf0;

    id103out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id103in_i));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 164 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id164in_r_done = id728out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id164in_w_done = id802out_output[getCycle()%2];

    m_sm_metapipe4396_FixedPoint36451_2.inputdata_r_done = id164in_r_done.getBitString();
    m_sm_metapipe4396_FixedPoint36451_2.inputdata_w_done = id164in_w_done.getBitString();
    m_sm_metapipe4396_FixedPoint36451_2.execute(true);
    id164out_curBuf = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4396_FixedPoint36451_2.outputdata_curBuf));
  }
  { // Node ID: 833 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id833in_input = id164out_curBuf;

    id833out_output[(getCycle()+2)%3] = id833in_input;
  }
  { // Node ID: 168 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id168in_a = id164out_curBuf;
    const HWOffsetFix<1,0,UNSIGNED> &id168in_b = id802out_output[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id168x_1;

    (id168x_1) = (and_fixed(id168in_a,id168in_b));
    id168out_result[(getCycle()+1)%2] = (id168x_1);
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 156 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id156in_r_done = id186out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id156in_w_done = id726out_output;

    m_sm_metapipe4396_FixedPoint36450_1.inputdata_r_done = id156in_r_done.getBitString();
    m_sm_metapipe4396_FixedPoint36450_1.inputdata_w_done = id156in_w_done.getBitString();
    m_sm_metapipe4396_FixedPoint36450_1.execute(true);
    id156out_curBuf = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4396_FixedPoint36450_1.outputdata_curBuf));
  }
  { // Node ID: 831 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id831in_input = id156out_curBuf;

    id831out_output[(getCycle()+2)%3] = id831in_input;
  }
  { // Node ID: 160 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id160in_a = id156out_curBuf;
    const HWOffsetFix<1,0,UNSIGNED> &id160in_b = id726out_output;

    HWOffsetFix<1,0,UNSIGNED> id160x_1;

    (id160x_1) = (and_fixed(id160in_a,id160in_b));
    id160out_result[(getCycle()+1)%2] = (id160x_1);
  }
  { // Node ID: 829 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id829in_input = id153out_counter0;

    id829out_output[(getCycle()+1)%2] = id829in_input;
  }
  { // Node ID: 163 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 161 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id161in_load = id160out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id161in_input = id829out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id161in_user_reset = id163out_value;

    if((id161in_user_reset.getValueAsBool())) {
      (id161st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id161in_load.getValueAsBool())) {
        (id161st_holdreg) = id161in_input;
      }
    }
    id161out_output[(getCycle()+1)%2] = (id161st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id157out_result;

  { // Node ID: 157 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id157in_a = id156out_curBuf;

    id157out_result = (not_fixed(id157in_a));
  }
  { // Node ID: 158 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id158in_a = id157out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id158in_b = id726out_output;

    HWOffsetFix<1,0,UNSIGNED> id158x_1;

    (id158x_1) = (and_fixed(id158in_a,id158in_b));
    id158out_result[(getCycle()+1)%2] = (id158x_1);
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 159 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id159in_load = id158out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id159in_input = id829out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id159in_user_reset = id163out_value;

    if((id159in_user_reset.getValueAsBool())) {
      (id159st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id159in_load.getValueAsBool())) {
        (id159st_holdreg) = id159in_input;
      }
    }
    id159out_output[(getCycle()+1)%2] = (id159st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id162out_result;

  { // Node ID: 162 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id162in_sel = id831out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id162in_option0 = id161out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id162in_option1 = id159out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id162x_1;

    switch((id162in_sel.getValueAsLong())) {
      case 0l:
        id162x_1 = id162in_option0;
        break;
      case 1l:
        id162x_1 = id162in_option1;
        break;
      default:
        id162x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id162out_result = (id162x_1);
  }
  { // Node ID: 171 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 169 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id169in_load = id168out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id169in_input = id162out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id169in_user_reset = id171out_value;

    if((id169in_user_reset.getValueAsBool())) {
      (id169st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id169in_load.getValueAsBool())) {
        (id169st_holdreg) = id169in_input;
      }
    }
    id169out_output[(getCycle()+1)%2] = (id169st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id165out_result;

  { // Node ID: 165 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id165in_a = id164out_curBuf;

    id165out_result = (not_fixed(id165in_a));
  }
  { // Node ID: 166 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id166in_a = id165out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id166in_b = id802out_output[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id166x_1;

    (id166x_1) = (and_fixed(id166in_a,id166in_b));
    id166out_result[(getCycle()+1)%2] = (id166x_1);
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 167 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id167in_load = id166out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id167in_input = id162out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id167in_user_reset = id171out_value;

    if((id167in_user_reset.getValueAsBool())) {
      (id167st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id167in_load.getValueAsBool())) {
        (id167st_holdreg) = id167in_input;
      }
    }
    id167out_output[(getCycle()+1)%2] = (id167st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id170out_result;

  { // Node ID: 170 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id170in_sel = id833out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id170in_option0 = id169out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id170in_option1 = id167out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id170x_1;

    switch((id170in_sel.getValueAsLong())) {
      case 0l:
        id170x_1 = id170in_option0;
        break;
      case 1l:
        id170x_1 = id170in_option1;
        break;
      default:
        id170x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id170out_result = (id170x_1);
  }
  HWOffsetFix<32,5,TWOSCOMPLEMENT> id679out_output;

  { // Node ID: 679 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id679in_input = id170out_result;

    id679out_output = (cast_bits2fixed<32,5,TWOSCOMPLEMENT>((cast_fixed2bits(id679in_input))));
  }
  HWOffsetFix<32,6,TWOSCOMPLEMENT> id680out_output;

  { // Node ID: 680 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id680in_input = id170out_result;

    id680out_output = (cast_bits2fixed<32,6,TWOSCOMPLEMENT>((cast_fixed2bits(id680in_input))));
  }
  { // Node ID: 681 (NodeAdd)
    const HWOffsetFix<32,5,TWOSCOMPLEMENT> &id681in_a = id679out_output;
    const HWOffsetFix<32,6,TWOSCOMPLEMENT> &id681in_b = id680out_output;

    id681out_result[(getCycle()+1)%2] = (add_fixed<34,5,TWOSCOMPLEMENT,TONEAR>(id681in_a,id681in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id682out_o;

  { // Node ID: 682 (NodeCast)
    const HWOffsetFix<34,5,TWOSCOMPLEMENT> &id682in_i = id681out_result[getCycle()%2];

    id682out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id682in_i));
  }
  { // Node ID: 251 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id251in_a = id682out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id251in_b = id241out_counter0;

    id251out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id251in_a,id251in_b));
  }
  HWOffsetFix<14,0,UNSIGNED> id252out_o;

  { // Node ID: 252 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id252in_i = id251out_result[getCycle()%2];

    id252out_o = (cast_fixed2fixed<14,0,UNSIGNED,TONEAR>(id252in_i));
  }
  { // Node ID: 835 (NodeFIFO)
    const HWOffsetFix<14,0,UNSIGNED> &id835in_input = id252out_o;

    id835out_output[(getCycle()+58)%59] = id835in_input;
  }
  { // Node ID: 834 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id834in_input = id238out_ctr_en;

    id834out_output[(getCycle()+54)%55] = id834in_input;
  }
  { // Node ID: 232 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id233out_result;

  { // Node ID: 233 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id233in_a = id232out_io_DRAM4323_void4384_in_force_disabled;

    id233out_result = (not_fixed(id233in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id234out_result;

  { // Node ID: 234 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id234in_a = id834out_output[getCycle()%55];
    const HWOffsetFix<1,0,UNSIGNED> &id234in_b = id233out_result;

    HWOffsetFix<1,0,UNSIGNED> id234x_1;

    (id234x_1) = (and_fixed(id234in_a,id234in_b));
    id234out_result = (id234x_1);
  }
  if ( (getFillLevel() >= (61l)))
  { // Node ID: 235 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id235in_enable = id234out_result;

    (id235st_read_next_cycle) = ((id235in_enable.getValueAsBool())&(!(((getFlushLevel())>=(61l))&(isFlushingActive()))));
    queueReadRequest(m_DRAM4323_void4384_in, id235st_read_next_cycle.getValueAsBool());
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id237out_output;

  { // Node ID: 237 (NodeReinterpret)
    const HWRawBits<32> &id237in_input = id235out_data;

    id237out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id237in_input));
  }
  { // Node ID: 893 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id893in_input = id834out_output[getCycle()%55];

    id893out_output[(getCycle()+5)%6] = id893in_input;
  }
  HWOffsetFix<32,5,TWOSCOMPLEMENT> id683out_output;

  { // Node ID: 683 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id683in_input = id399out_counter0;

    id683out_output = (cast_bits2fixed<32,5,TWOSCOMPLEMENT>((cast_fixed2bits(id683in_input))));
  }
  HWOffsetFix<32,6,TWOSCOMPLEMENT> id684out_output;

  { // Node ID: 684 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id684in_input = id399out_counter0;

    id684out_output = (cast_bits2fixed<32,6,TWOSCOMPLEMENT>((cast_fixed2bits(id684in_input))));
  }
  { // Node ID: 685 (NodeAdd)
    const HWOffsetFix<32,5,TWOSCOMPLEMENT> &id685in_a = id683out_output;
    const HWOffsetFix<32,6,TWOSCOMPLEMENT> &id685in_b = id684out_output;

    id685out_result[(getCycle()+1)%2] = (add_fixed<34,5,TWOSCOMPLEMENT,TONEAR>(id685in_a,id685in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id686out_o;

  { // Node ID: 686 (NodeCast)
    const HWOffsetFix<34,5,TWOSCOMPLEMENT> &id686in_i = id685out_result[getCycle()%2];

    id686out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id686in_i));
  }
  { // Node ID: 405 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id405in_a = id686out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id405in_b = id380out_counter0;

    id405out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id405in_a,id405in_b));
  }
  HWOffsetFix<14,0,UNSIGNED> id407out_o;

  { // Node ID: 407 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id407in_i = id405out_result[getCycle()%2];

    id407out_o = (cast_fixed2fixed<14,0,UNSIGNED,TONEAR>(id407in_i));
  }
  if ( (getFillLevel() >= (66l)))
  { // Node ID: 588 (NodeRAM)
    const bool id588_inputvalid = !(isFlushingActive() && getFlushLevel() >= (66l));
    const HWOffsetFix<14,0,UNSIGNED> &id588in_addrA = id835out_output[getCycle()%59];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id588in_dina = id237out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id588in_wea = id893out_output[getCycle()%6];
    const HWOffsetFix<14,0,UNSIGNED> &id588in_addrB = id407out_o;

    long id588x_1;
    long id588x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id588x_3;

    (id588x_1) = (id588in_addrA.getValueAsLong());
    (id588x_2) = (id588in_addrB.getValueAsLong());
    switch(((long)((id588x_2)<(9216l)))) {
      case 0l:
        id588x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id588x_3 = (id588sta_ram_store[(id588x_2)]);
        break;
      default:
        id588x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id588out_doutb[(getCycle()+2)%3] = (id588x_3);
    if(((id588in_wea.getValueAsBool())&id588_inputvalid)) {
      if(((id588x_1)<(9216l))) {
        (id588sta_ram_store[(id588x_1)]) = id588in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_1("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 588) on port A, ram depth is 9216.")));
      }
    }
  }
  { // Node ID: 867 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id867in_input = id588out_doutb[getCycle()%3];

    id867out_output[(getCycle()+8)%9] = id867in_input;
  }
  { // Node ID: 837 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id837in_input = id735out_output;

    id837out_output[(getCycle()+58)%59] = id837in_input;
  }
  if ( (getFillLevel() >= (63l)))
  { // Node ID: 331 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id331in_r_done = id837out_output[getCycle()%59];
    const HWOffsetFix<1,0,UNSIGNED> &id331in_w_done = id838out_output[getCycle()%59];

    m_sm_metapipe4435_FixedPoint36890_1.inputdata_r_done = id331in_r_done.getBitString();
    m_sm_metapipe4435_FixedPoint36890_1.inputdata_w_done = id331in_w_done.getBitString();
    m_sm_metapipe4435_FixedPoint36890_1.execute(true);
    id331out_curBuf = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe4435_FixedPoint36890_1.outputdata_curBuf));
  }
  { // Node ID: 843 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id843in_input = id331out_curBuf;

    id843out_output[(getCycle()+2)%3] = id843in_input;
  }
  { // Node ID: 335 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id335in_a = id331out_curBuf;
    const HWOffsetFix<1,0,UNSIGNED> &id335in_b = id838out_output[getCycle()%59];

    HWOffsetFix<1,0,UNSIGNED> id335x_1;

    (id335x_1) = (and_fixed(id335in_a,id335in_b));
    id335out_result[(getCycle()+1)%2] = (id335x_1);
  }
  { // Node ID: 841 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id841in_input = id322out_output;

    id841out_output[(getCycle()+60)%61] = id841in_input;
  }
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 328 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id328in_en = id895out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id328in_max0 = id121out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id328in_reset = id841out_output[getCycle()%61];

    m_sm_CounterChain4414_sm.inputdata_en = id328in_en.getBitString();
    m_sm_CounterChain4414_sm.inputdata_max0 = id328in_max0.getBitString();
    m_sm_CounterChain4414_sm.inputdata_reset = id328in_reset.getBitString();
    m_sm_CounterChain4414_sm.execute(true);
    id328out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain4414_sm.outputdata_counter0) ));
    id328out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4414_sm.outputdata_done));
    id328out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4414_sm.outputdata_saturated));
  }
  { // Node ID: 338 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 336 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id336in_load = id335out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id336in_input = id328out_counter0;
    const HWOffsetFix<1,0,UNSIGNED> &id336in_user_reset = id338out_value;

    if((id336in_user_reset.getValueAsBool())) {
      (id336st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id336in_load.getValueAsBool())) {
        (id336st_holdreg) = id336in_input;
      }
    }
    id336out_output[(getCycle()+1)%2] = (id336st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id332out_result;

  { // Node ID: 332 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id332in_a = id331out_curBuf;

    id332out_result = (not_fixed(id332in_a));
  }
  { // Node ID: 333 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id333in_a = id332out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id333in_b = id838out_output[getCycle()%59];

    HWOffsetFix<1,0,UNSIGNED> id333x_1;

    (id333x_1) = (and_fixed(id333in_a,id333in_b));
    id333out_result[(getCycle()+1)%2] = (id333x_1);
  }
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 334 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id334in_load = id333out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id334in_input = id328out_counter0;
    const HWOffsetFix<1,0,UNSIGNED> &id334in_user_reset = id338out_value;

    if((id334in_user_reset.getValueAsBool())) {
      (id334st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id334in_load.getValueAsBool())) {
        (id334st_holdreg) = id334in_input;
      }
    }
    id334out_output[(getCycle()+1)%2] = (id334st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id337out_result;

  { // Node ID: 337 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id337in_sel = id843out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id337in_option0 = id336out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id337in_option1 = id334out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id337x_1;

    switch((id337in_sel.getValueAsLong())) {
      case 0l:
        id337x_1 = id337in_option0;
        break;
      case 1l:
        id337x_1 = id337in_option1;
        break;
      default:
        id337x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id337out_result = (id337x_1);
  }
  HWOffsetFix<7,0,UNSIGNED> id372out_o;

  { // Node ID: 372 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id372in_i = id337out_result;

    id372out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id372in_i));
  }
  { // Node ID: 864 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id864in_input = id372out_o;

    id864out_output[(getCycle()+9)%10] = id864in_input;
  }
  { // Node ID: 529 (NodeConstantRawBits)
  }
  { // Node ID: 528 (NodeConstantRawBits)
  }
  { // Node ID: 897 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id897in_input = id896out_output[getCycle()%2];

    id897out_output[(getCycle()+5)%6] = id897in_input;
  }
  { // Node ID: 898 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id898in_input = id897out_output[getCycle()%6];

    id898out_output[(getCycle()+1)%2] = id898in_input;
  }
  { // Node ID: 899 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id899in_input = id837out_output[getCycle()%59];

    id899out_output[(getCycle()+8)%9] = id899in_input;
  }
  { // Node ID: 64 (NodeConstantRawBits)
  }
  { // Node ID: 66 (NodeConstantRawBits)
  }
  { // Node ID: 68 (NodeConstantRawBits)
  }
  { // Node ID: 70 (NodeConstantRawBits)
  }
  { // Node ID: 72 (NodeConstantRawBits)
  }
  { // Node ID: 74 (NodeConstantRawBits)
  }
  { // Node ID: 900 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id900in_input = id772out_output[getCycle()%60];

    id900out_output[(getCycle()+7)%8] = id900in_input;
  }
  { // Node ID: 901 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id901in_input = id775out_output[getCycle()%2];

    id901out_output[(getCycle()+1)%2] = id901in_input;
  }
  { // Node ID: 902 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id902in_input = id901out_output[getCycle()%2];

    id902out_output[(getCycle()+64)%65] = id902in_input;
  }
  { // Node ID: 65 (NodeConstantRawBits)
  }
  { // Node ID: 67 (NodeConstantRawBits)
  }
  { // Node ID: 69 (NodeConstantRawBits)
  }
  { // Node ID: 71 (NodeConstantRawBits)
  }
  { // Node ID: 73 (NodeConstantRawBits)
  }
  { // Node ID: 75 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (71l)))
  { // Node ID: 63 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id63in_broadcast = id529out_value;
    const HWOffsetFix<2,0,UNSIGNED> &id63in_numBlanks = id528out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageDone0 = id898out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageDone1 = id899out_output[getCycle()%9];
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageDone2 = id64out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageDone3 = id66out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageDone4 = id68out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageDone5 = id70out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageDone6 = id72out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageDone7 = id74out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageEn0 = id900out_output[getCycle()%8];
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageEn1 = id902out_output[getCycle()%65];
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageEn2 = id65out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageEn3 = id67out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageEn4 = id69out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageEn5 = id71out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageEn6 = id73out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id63in_stageEn7 = id75out_value;

    m_sm_reg4415_1.inputdata_broadcast = id63in_broadcast.getBitString();
    m_sm_reg4415_1.inputdata_numBlanks = id63in_numBlanks.getBitString();
    m_sm_reg4415_1.inputdata_stageDone0 = id63in_stageDone0.getBitString();
    m_sm_reg4415_1.inputdata_stageDone1 = id63in_stageDone1.getBitString();
    m_sm_reg4415_1.inputdata_stageDone2 = id63in_stageDone2.getBitString();
    m_sm_reg4415_1.inputdata_stageDone3 = id63in_stageDone3.getBitString();
    m_sm_reg4415_1.inputdata_stageDone4 = id63in_stageDone4.getBitString();
    m_sm_reg4415_1.inputdata_stageDone5 = id63in_stageDone5.getBitString();
    m_sm_reg4415_1.inputdata_stageDone6 = id63in_stageDone6.getBitString();
    m_sm_reg4415_1.inputdata_stageDone7 = id63in_stageDone7.getBitString();
    m_sm_reg4415_1.inputdata_stageEn0 = id63in_stageEn0.getBitString();
    m_sm_reg4415_1.inputdata_stageEn1 = id63in_stageEn1.getBitString();
    m_sm_reg4415_1.inputdata_stageEn2 = id63in_stageEn2.getBitString();
    m_sm_reg4415_1.inputdata_stageEn3 = id63in_stageEn3.getBitString();
    m_sm_reg4415_1.inputdata_stageEn4 = id63in_stageEn4.getBitString();
    m_sm_reg4415_1.inputdata_stageEn5 = id63in_stageEn5.getBitString();
    m_sm_reg4415_1.inputdata_stageEn6 = id63in_stageEn6.getBitString();
    m_sm_reg4415_1.inputdata_stageEn7 = id63in_stageEn7.getBitString();
    m_sm_reg4415_1.execute(true);
    id63out_curBuf0 = (HWOffsetFix<2,0,UNSIGNED>(m_sm_reg4415_1.outputdata_curBuf0));
    id63out_curBuf1 = (HWOffsetFix<2,0,UNSIGNED>(m_sm_reg4415_1.outputdata_curBuf1));
  }
  HWOffsetFix<1,0,UNSIGNED> id88out_o;

  { // Node ID: 88 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id88in_i = id63out_curBuf1;

    id88out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id88in_i));
  }
  { // Node ID: 858 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id858in_input = id88out_o;

    id858out_output[(getCycle()+2)%3] = id858in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id78out_o;

  { // Node ID: 78 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id78in_i = id63out_curBuf0;

    id78out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id78in_i));
  }
  { // Node ID: 527 (NodeConstantRawBits)
  }
  { // Node ID: 79 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id79in_sel = id78out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id79in_option0 = id898out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id79in_option1 = id527out_value;

    HWOffsetFix<1,0,UNSIGNED> id79x_1;

    switch((id79in_sel.getValueAsLong())) {
      case 0l:
        id79x_1 = id79in_option0;
        break;
      case 1l:
        id79x_1 = id79in_option1;
        break;
      default:
        id79x_1 = (c_hw_fix_1_0_uns_undef);
        break;
    }
    id79out_result[(getCycle()+1)%2] = (id79x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id76out_o;

  { // Node ID: 76 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id76in_i = id63out_curBuf0;

    id76out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id76in_i));
  }
  HWOffsetFix<32,5,TWOSCOMPLEMENT> id687out_output;

  { // Node ID: 687 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id687in_input = id170out_result;

    id687out_output = (cast_bits2fixed<32,5,TWOSCOMPLEMENT>((cast_fixed2bits(id687in_input))));
  }
  HWOffsetFix<32,6,TWOSCOMPLEMENT> id688out_output;

  { // Node ID: 688 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id688in_input = id170out_result;

    id688out_output = (cast_bits2fixed<32,6,TWOSCOMPLEMENT>((cast_fixed2bits(id688in_input))));
  }
  { // Node ID: 689 (NodeAdd)
    const HWOffsetFix<32,5,TWOSCOMPLEMENT> &id689in_a = id687out_output;
    const HWOffsetFix<32,6,TWOSCOMPLEMENT> &id689in_b = id688out_output;

    id689out_result[(getCycle()+1)%2] = (add_fixed<34,5,TWOSCOMPLEMENT,TONEAR>(id689in_a,id689in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id690out_o;

  { // Node ID: 690 (NodeCast)
    const HWOffsetFix<34,5,TWOSCOMPLEMENT> &id690in_i = id689out_result[getCycle()%2];

    id690out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id690in_i));
  }
  { // Node ID: 247 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id247in_a = id690out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id247in_b = id241out_counter0;

    id247out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id247in_a,id247in_b));
  }
  HWOffsetFix<14,0,UNSIGNED> id248out_o;

  { // Node ID: 248 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id248in_i = id247out_result[getCycle()%2];

    id248out_o = (cast_fixed2fixed<14,0,UNSIGNED,TONEAR>(id248in_i));
  }
  { // Node ID: 849 (NodeFIFO)
    const HWOffsetFix<14,0,UNSIGNED> &id849in_input = id248out_o;

    id849out_output[(getCycle()+58)%59] = id849in_input;
  }
  HWOffsetFix<32,5,TWOSCOMPLEMENT> id691out_output;

  { // Node ID: 691 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id691in_input = id328out_counter0;

    id691out_output = (cast_bits2fixed<32,5,TWOSCOMPLEMENT>((cast_fixed2bits(id691in_input))));
  }
  HWOffsetFix<32,6,TWOSCOMPLEMENT> id692out_output;

  { // Node ID: 692 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id692in_input = id328out_counter0;

    id692out_output = (cast_bits2fixed<32,6,TWOSCOMPLEMENT>((cast_fixed2bits(id692in_input))));
  }
  { // Node ID: 693 (NodeAdd)
    const HWOffsetFix<32,5,TWOSCOMPLEMENT> &id693in_a = id691out_output;
    const HWOffsetFix<32,6,TWOSCOMPLEMENT> &id693in_b = id692out_output;

    id693out_result[(getCycle()+1)%2] = (add_fixed<34,5,TWOSCOMPLEMENT,TONEAR>(id693in_a,id693in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id694out_o;

  { // Node ID: 694 (NodeCast)
    const HWOffsetFix<34,5,TWOSCOMPLEMENT> &id694in_i = id693out_result[getCycle()%2];

    id694out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id694in_i));
  }
  { // Node ID: 353 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id353in_a = id694out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id353in_b = id347out_counter0;

    id353out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id353in_a,id353in_b));
  }
  HWOffsetFix<14,0,UNSIGNED> id355out_o;

  { // Node ID: 355 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id355in_i = id353out_result[getCycle()%2];

    id355out_o = (cast_fixed2fixed<14,0,UNSIGNED,TONEAR>(id355in_i));
  }
  if ( (getFillLevel() >= (66l)))
  { // Node ID: 587 (NodeRAM)
    const bool id587_inputvalid = !(isFlushingActive() && getFlushLevel() >= (66l));
    const HWOffsetFix<14,0,UNSIGNED> &id587in_addrA = id849out_output[getCycle()%59];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id587in_dina = id237out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id587in_wea = id893out_output[getCycle()%6];
    const HWOffsetFix<14,0,UNSIGNED> &id587in_addrB = id355out_o;

    long id587x_1;
    long id587x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id587x_3;

    (id587x_1) = (id587in_addrA.getValueAsLong());
    (id587x_2) = (id587in_addrB.getValueAsLong());
    switch(((long)((id587x_2)<(9216l)))) {
      case 0l:
        id587x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id587x_3 = (id587sta_ram_store[(id587x_2)]);
        break;
      default:
        id587x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id587out_doutb[(getCycle()+2)%3] = (id587x_3);
    if(((id587in_wea.getValueAsBool())&id587_inputvalid)) {
      if(((id587x_1)<(9216l))) {
        (id587sta_ram_store[(id587x_1)]) = id587in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_2("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 587) on port A, ram depth is 9216.")));
      }
    }
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id746out_output;

  { // Node ID: 746 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id746in_input = id875out_output[getCycle()%41];

    id746out_output = id746in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id446out_o;

  { // Node ID: 446 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id446in_i = id746out_output;

    id446out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id446in_i));
  }
  { // Node ID: 853 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id853in_input = id446out_o;

    id853out_output[(getCycle()+20)%21] = id853in_input;
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id747out_output;

  { // Node ID: 747 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id747in_input = id695out_result[getCycle()%2];

    id747out_output = id747in_input;
  }
  { // Node ID: 852 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id852in_input = id432out_ctr_en;

    id852out_output[(getCycle()+60)%61] = id852in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id748out_output;

  { // Node ID: 748 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id748in_input = id852out_output[getCycle()%61];

    id748out_output = id748in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id357out_o;

  { // Node ID: 357 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id357in_i = id347out_counter0;

    id357out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id357in_i));
  }
  { // Node ID: 854 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id854in_input = id357out_o;

    id854out_output[(getCycle()+1)%2] = id854in_input;
  }
  if ( (getFillLevel() >= (66l)))
  { // Node ID: 591 (NodeRAM)
    const bool id591_inputvalid = !(isFlushingActive() && getFlushLevel() >= (66l));
    const HWOffsetFix<7,0,UNSIGNED> &id591in_addrA = id853out_output[getCycle()%21];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id591in_dina = id747out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id591in_wea = id748out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id591in_addrB = id854out_output[getCycle()%2];

    long id591x_1;
    long id591x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id591x_3;

    (id591x_1) = (id591in_addrA.getValueAsLong());
    (id591x_2) = (id591in_addrB.getValueAsLong());
    switch(((long)((id591x_2)<(96l)))) {
      case 0l:
        id591x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id591x_3 = (id591sta_ram_store[(id591x_2)]);
        break;
      default:
        id591x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id591out_doutb[(getCycle()+2)%3] = (id591x_3);
    if(((id591in_wea.getValueAsBool())&id591_inputvalid)) {
      if(((id591x_1)<(96l))) {
        (id591sta_ram_store[(id591x_1)]) = id591in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_3("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 591) on port A, ram depth is 96.")));
      }
    }
  }
  { // Node ID: 361 (NodeMul)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id361in_a = id587out_doutb[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id361in_b = id591out_doutb[getCycle()%3];

    id361out_result[(getCycle()+2)%3] = (mul_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id361in_a,id361in_b));
  }
  { // Node ID: 358 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id358in_a = id339out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id358in_b = id344out_output;

    HWOffsetFix<1,0,UNSIGNED> id358x_1;

    (id358x_1) = (and_fixed(id358in_a,id358in_b));
    id358out_result[(getCycle()+1)%2] = (id358x_1);
  }
  { // Node ID: 856 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id856in_input = id358out_result[getCycle()%2];

    id856out_output[(getCycle()+5)%6] = id856in_input;
  }
  if ( (getFillLevel() >= (70l)))
  { // Node ID: 359 (NodeAccumulator)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id359in_summand = id361out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id359in_clearAccumulate = id897out_output[getCycle()%6];
    const HWOffsetFix<1,0,UNSIGNED> &id359in_enable = id856out_output[getCycle()%6];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id359x_1;

    (id359x_1) = id359in_summand;
    if(((id359st_clear_reg).getValueAsBool())) {
      if((id359in_enable.getValueAsBool())) {
        (id359st_hold_reg) = (id359x_1);
      }
      else {
        (id359st_hold_reg) = (c_hw_fix_32_0_sgn_bits_2);
      }
    }
    else {
      if((id359in_enable.getValueAsBool())) {
        (id359st_hold_reg) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((id359st_hold_reg),(id359x_1)));
      }
    }
    id359out_accumulate[(getCycle()+1)%2] = (id359st_hold_reg);
    (id359st_clear_reg) = id359in_clearAccumulate;
  }
  { // Node ID: 526 (NodeConstantRawBits)
  }
  { // Node ID: 77 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id77in_sel = id76out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id77in_option0 = id359out_accumulate[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id77in_option1 = id526out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id77x_1;

    switch((id77in_sel.getValueAsLong())) {
      case 0l:
        id77x_1 = id77in_option0;
        break;
      case 1l:
        id77x_1 = id77in_option1;
        break;
      default:
        id77x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id77out_result[(getCycle()+1)%2] = (id77x_1);
  }
  { // Node ID: 360 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (72l)))
  { // Node ID: 80 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id80in_load = id79out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id80in_input = id77out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id80in_user_reset = id360out_value;

    if((id80in_user_reset.getValueAsBool())) {
      (id80st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id80in_load.getValueAsBool())) {
        (id80st_holdreg) = id80in_input;
      }
    }
    id80out_output[(getCycle()+1)%2] = (id80st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id83out_o;

  { // Node ID: 83 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id83in_i = id63out_curBuf1;

    id83out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id83in_i));
  }
  { // Node ID: 84 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id84in_sel = id83out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id84in_option0 = id898out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id84in_option1 = id527out_value;

    HWOffsetFix<1,0,UNSIGNED> id84x_1;

    switch((id84in_sel.getValueAsLong())) {
      case 0l:
        id84x_1 = id84in_option0;
        break;
      case 1l:
        id84x_1 = id84in_option1;
        break;
      default:
        id84x_1 = (c_hw_fix_1_0_uns_undef);
        break;
    }
    id84out_result[(getCycle()+1)%2] = (id84x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id81out_o;

  { // Node ID: 81 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id81in_i = id63out_curBuf1;

    id81out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id81in_i));
  }
  { // Node ID: 82 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id82in_sel = id81out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id82in_option0 = id359out_accumulate[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id82in_option1 = id526out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id82x_1;

    switch((id82in_sel.getValueAsLong())) {
      case 0l:
        id82x_1 = id82in_option0;
        break;
      case 1l:
        id82x_1 = id82in_option1;
        break;
      default:
        id82x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id82out_result[(getCycle()+1)%2] = (id82x_1);
  }
  if ( (getFillLevel() >= (72l)))
  { // Node ID: 85 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id85in_load = id84out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id85in_input = id82out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id85in_user_reset = id360out_value;

    if((id85in_user_reset.getValueAsBool())) {
      (id85st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id85in_load.getValueAsBool())) {
        (id85st_holdreg) = id85in_input;
      }
    }
    id85out_output[(getCycle()+1)%2] = (id85st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id89out_result;

  { // Node ID: 89 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id89in_sel = id858out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id89in_option0 = id80out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id89in_option1 = id85out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id89x_1;

    switch((id89in_sel.getValueAsLong())) {
      case 0l:
        id89x_1 = id89in_option0;
        break;
      case 1l:
        id89x_1 = id89in_option1;
        break;
      default:
        id89x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id89out_result = (id89x_1);
  }
  HWOffsetFix<7,0,UNSIGNED> id320out_o;

  { // Node ID: 320 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id320in_i = id317out_counter0;

    id320out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id320in_i));
  }
  { // Node ID: 859 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id859in_input = id320out_o;

    id859out_output[(getCycle()+4)%5] = id859in_input;
  }
  { // Node ID: 308 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id309out_result;

  { // Node ID: 309 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id309in_a = id308out_io_DRAM4324_void4400_in_force_disabled;

    id309out_result = (not_fixed(id309in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id310out_result;

  { // Node ID: 310 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id310in_a = id314out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id310in_b = id309out_result;

    HWOffsetFix<1,0,UNSIGNED> id310x_1;

    (id310x_1) = (and_fixed(id310in_a,id310in_b));
    id310out_result = (id310x_1);
  }
  if ( (getFillLevel() >= (66l)))
  { // Node ID: 311 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id311in_enable = id310out_result;

    (id311st_read_next_cycle) = ((id311in_enable.getValueAsBool())&(!(((getFlushLevel())>=(66l))&(isFlushingActive()))));
    queueReadRequest(m_DRAM4324_void4400_in, id311st_read_next_cycle.getValueAsBool());
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id313out_output;

  { // Node ID: 313 (NodeReinterpret)
    const HWRawBits<32> &id313in_input = id311out_data;

    id313out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id313in_input));
  }
  { // Node ID: 894 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id894in_input = id762out_output[getCycle()%2];

    id894out_output[(getCycle()+4)%5] = id894in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id370out_o;

  { // Node ID: 370 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id370in_i = id337out_result;

    id370out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id370in_i));
  }
  { // Node ID: 861 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id861in_input = id370out_o;

    id861out_output[(getCycle()+6)%7] = id861in_input;
  }
  if ( (getFillLevel() >= (71l)))
  { // Node ID: 589 (NodeRAM)
    const bool id589_inputvalid = !(isFlushingActive() && getFlushLevel() >= (71l));
    const HWOffsetFix<7,0,UNSIGNED> &id589in_addrA = id859out_output[getCycle()%5];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id589in_dina = id313out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id589in_wea = id894out_output[getCycle()%5];
    const HWOffsetFix<7,0,UNSIGNED> &id589in_addrB = id861out_output[getCycle()%7];

    long id589x_1;
    long id589x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id589x_3;

    (id589x_1) = (id589in_addrA.getValueAsLong());
    (id589x_2) = (id589in_addrB.getValueAsLong());
    switch(((long)((id589x_2)<(96l)))) {
      case 0l:
        id589x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id589x_3 = (id589sta_ram_store[(id589x_2)]);
        break;
      default:
        id589x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id589out_doutb[(getCycle()+2)%3] = (id589x_3);
    if(((id589in_wea.getValueAsBool())&id589_inputvalid)) {
      if(((id589x_1)<(96l))) {
        (id589sta_ram_store[(id589x_1)]) = id589in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_4("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 589) on port A, ram depth is 96.")));
      }
    }
  }
  { // Node ID: 371 (NodeSub)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id371in_a = id89out_result;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id371in_b = id589out_doutb[getCycle()%3];

    id371out_result[(getCycle()+1)%2] = (sub_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id371in_a,id371in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id367out_result;

  { // Node ID: 367 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id367in_a = id774out_output[getCycle()%2];

    id367out_result = (not_fixed(id367in_a));
  }
  { // Node ID: 368 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id368in_a = id901out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id368in_b = id367out_result;

    HWOffsetFix<1,0,UNSIGNED> id368x_1;

    (id368x_1) = (and_fixed(id368in_a,id368in_b));
    id368out_result[(getCycle()+1)%2] = (id368x_1);
  }
  { // Node ID: 865 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id865in_input = id368out_result[getCycle()%2];

    id865out_output[(getCycle()+66)%67] = id865in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id409out_o;

  { // Node ID: 409 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id409in_i = id399out_counter0;

    id409out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id409in_i));
  }
  { // Node ID: 866 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id866in_input = id409out_o;

    id866out_output[(getCycle()+10)%11] = id866in_input;
  }
  if ( (getFillLevel() >= (74l)))
  { // Node ID: 594 (NodeRAM)
    const bool id594_inputvalid = !(isFlushingActive() && getFlushLevel() >= (74l));
    const HWOffsetFix<7,0,UNSIGNED> &id594in_addrA = id864out_output[getCycle()%10];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id594in_dina = id371out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id594in_wea = id865out_output[getCycle()%67];
    const HWOffsetFix<7,0,UNSIGNED> &id594in_addrB = id866out_output[getCycle()%11];

    long id594x_1;
    long id594x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id594x_3;

    (id594x_1) = (id594in_addrA.getValueAsLong());
    (id594x_2) = (id594in_addrB.getValueAsLong());
    switch(((long)((id594x_2)<(96l)))) {
      case 0l:
        id594x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id594x_3 = (id594sta_ram_store[(id594x_2)]);
        break;
      default:
        id594x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id594out_doutb[(getCycle()+2)%3] = (id594x_3);
    if(((id594in_wea.getValueAsBool())&id594_inputvalid)) {
      if(((id594x_1)<(96l))) {
        (id594sta_ram_store[(id594x_1)]) = id594in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_5("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 594) on port A, ram depth is 96.")));
      }
    }
  }
  { // Node ID: 413 (NodeMul)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id413in_a = id867out_output[getCycle()%9];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id413in_b = id594out_doutb[getCycle()%3];

    id413out_result[(getCycle()+2)%3] = (mul_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id413in_a,id413in_b));
  }
  { // Node ID: 410 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id410in_a = id391out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id410in_b = id777out_output[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id410x_1;

    (id410x_1) = (and_fixed(id410in_a,id410in_b));
    id410out_result[(getCycle()+1)%2] = (id410x_1);
  }
  { // Node ID: 870 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id870in_input = id410out_result[getCycle()%2];

    id870out_output[(getCycle()+14)%15] = id870in_input;
  }
  if ( (getFillLevel() >= (78l)))
  { // Node ID: 411 (NodeAccumulator)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id411in_summand = id413out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id411in_clearAccumulate = id904out_output[getCycle()%14];
    const HWOffsetFix<1,0,UNSIGNED> &id411in_enable = id870out_output[getCycle()%15];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id411x_1;

    (id411x_1) = id411in_summand;
    if(((id411st_clear_reg).getValueAsBool())) {
      if((id411in_enable.getValueAsBool())) {
        (id411st_hold_reg) = (id411x_1);
      }
      else {
        (id411st_hold_reg) = (c_hw_fix_32_0_sgn_bits_2);
      }
    }
    else {
      if((id411in_enable.getValueAsBool())) {
        (id411st_hold_reg) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((id411st_hold_reg),(id411x_1)));
      }
    }
    id411out_accumulate[(getCycle()+1)%2] = (id411st_hold_reg);
    (id411st_clear_reg) = id411in_clearAccumulate;
  }
  { // Node ID: 530 (NodeConstantRawBits)
  }
  { // Node ID: 104 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id104in_sel = id103out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id104in_option0 = id411out_accumulate[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id104in_option1 = id530out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id104x_1;

    switch((id104in_sel.getValueAsLong())) {
      case 0l:
        id104x_1 = id104in_option0;
        break;
      case 1l:
        id104x_1 = id104in_option1;
        break;
      default:
        id104x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id104out_result[(getCycle()+1)%2] = (id104x_1);
  }
  { // Node ID: 412 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (80l)))
  { // Node ID: 107 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id107in_load = id106out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id107in_input = id104out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id107in_user_reset = id412out_value;

    if((id107in_user_reset.getValueAsBool())) {
      (id107st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id107in_load.getValueAsBool())) {
        (id107st_holdreg) = id107in_input;
      }
    }
    id107out_output[(getCycle()+1)%2] = (id107st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id110out_o;

  { // Node ID: 110 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id110in_i = id90out_curBuf1;

    id110out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id110in_i));
  }
  { // Node ID: 111 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id111in_sel = id110out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id111in_option0 = id905out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id111in_option1 = id531out_value;

    HWOffsetFix<1,0,UNSIGNED> id111x_1;

    switch((id111in_sel.getValueAsLong())) {
      case 0l:
        id111x_1 = id111in_option0;
        break;
      case 1l:
        id111x_1 = id111in_option1;
        break;
      default:
        id111x_1 = (c_hw_fix_1_0_uns_undef);
        break;
    }
    id111out_result[(getCycle()+1)%2] = (id111x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id108out_o;

  { // Node ID: 108 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id108in_i = id90out_curBuf1;

    id108out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id108in_i));
  }
  { // Node ID: 109 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id109in_sel = id108out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id109in_option0 = id411out_accumulate[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id109in_option1 = id530out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id109x_1;

    switch((id109in_sel.getValueAsLong())) {
      case 0l:
        id109x_1 = id109in_option0;
        break;
      case 1l:
        id109x_1 = id109in_option1;
        break;
      default:
        id109x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id109out_result[(getCycle()+1)%2] = (id109x_1);
  }
  if ( (getFillLevel() >= (80l)))
  { // Node ID: 112 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id112in_load = id111out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id112in_input = id109out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id112in_user_reset = id412out_value;

    if((id112in_user_reset.getValueAsBool())) {
      (id112st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id112in_load.getValueAsBool())) {
        (id112st_holdreg) = id112in_input;
      }
    }
    id112out_output[(getCycle()+1)%2] = (id112st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id116out_result;

  { // Node ID: 116 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id116in_sel = id872out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id116in_option0 = id107out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id116in_option1 = id112out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id116x_1;

    switch((id116in_sel.getValueAsLong())) {
      case 0l:
        id116x_1 = id116in_option0;
        break;
      case 1l:
        id116x_1 = id116in_option1;
        break;
      default:
        id116x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id116out_result = (id116x_1);
  }
  { // Node ID: 3 (NodeInputMappedReg)
  }
  { // Node ID: 421 (NodeMul)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id421in_a = id116out_result;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id421in_b = id3out_argin4319;

    id421out_result[(getCycle()+2)%3] = (mul_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id421in_a,id421in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id419out_result;

  { // Node ID: 419 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id419in_a = id783out_output[getCycle()%2];

    id419out_result = (not_fixed(id419in_a));
  }
  { // Node ID: 420 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id420in_a = id908out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id420in_b = id419out_result;

    HWOffsetFix<1,0,UNSIGNED> id420x_1;

    (id420x_1) = (and_fixed(id420in_a,id420in_b));
    id420out_result[(getCycle()+1)%2] = (id420x_1);
  }
  { // Node ID: 877 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id877in_input = id420out_result[getCycle()%2];

    id877out_output[(getCycle()+75)%76] = id877in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id439out_o;

  { // Node ID: 439 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id439in_i = id875out_output[getCycle()%41];

    id439out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id439in_i));
  }
  { // Node ID: 878 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id878in_input = id439out_o;

    id878out_output[(getCycle()+17)%18] = id878in_input;
  }
  if ( (getFillLevel() >= (83l)))
  { // Node ID: 590 (NodeRAM)
    const bool id590_inputvalid = !(isFlushingActive() && getFlushLevel() >= (83l));
    const HWOffsetFix<7,0,UNSIGNED> &id590in_addrA = id876out_output[getCycle()%18];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id590in_dina = id421out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id590in_wea = id877out_output[getCycle()%76];
    const HWOffsetFix<7,0,UNSIGNED> &id590in_addrB = id878out_output[getCycle()%18];

    long id590x_1;
    long id590x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id590x_3;

    (id590x_1) = (id590in_addrA.getValueAsLong());
    (id590x_2) = (id590in_addrB.getValueAsLong());
    switch(((long)((id590x_2)<(96l)))) {
      case 0l:
        id590x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id590x_3 = (id590sta_ram_store[(id590x_2)]);
        break;
      default:
        id590x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id590out_doutb[(getCycle()+2)%3] = (id590x_3);
    if(((id590in_wea.getValueAsBool())&id590_inputvalid)) {
      if(((id590x_1)<(96l))) {
        (id590sta_ram_store[(id590x_1)]) = id590in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_6("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 590) on port A, ram depth is 96.")));
      }
    }
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id749out_output;

  { // Node ID: 749 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id749in_input = id875out_output[getCycle()%41];

    id749out_output = id749in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id451out_o;

  { // Node ID: 451 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id451in_i = id749out_output;

    id451out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id451in_i));
  }
  { // Node ID: 882 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id882in_input = id451out_o;

    id882out_output[(getCycle()+20)%21] = id882in_input;
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id750out_output;

  { // Node ID: 750 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id750in_input = id695out_result[getCycle()%2];

    id750out_output = id750in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id751out_output;

  { // Node ID: 751 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id751in_input = id852out_output[getCycle()%61];

    id751out_output = id751in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id441out_o;

  { // Node ID: 441 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id441in_i = id875out_output[getCycle()%41];

    id441out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id441in_i));
  }
  if ( (getFillLevel() >= (66l)))
  { // Node ID: 592 (NodeRAM)
    const bool id592_inputvalid = !(isFlushingActive() && getFlushLevel() >= (66l));
    const HWOffsetFix<7,0,UNSIGNED> &id592in_addrA = id882out_output[getCycle()%21];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id592in_dina = id750out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id592in_wea = id751out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id592in_addrB = id441out_o;

    long id592x_1;
    long id592x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id592x_3;

    (id592x_1) = (id592in_addrA.getValueAsLong());
    (id592x_2) = (id592in_addrB.getValueAsLong());
    switch(((long)((id592x_2)<(96l)))) {
      case 0l:
        id592x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id592x_3 = (id592sta_ram_store[(id592x_2)]);
        break;
      default:
        id592x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id592out_doutb[(getCycle()+2)%3] = (id592x_3);
    if(((id592in_wea.getValueAsBool())&id592_inputvalid)) {
      if(((id592x_1)<(96l))) {
        (id592sta_ram_store[(id592x_1)]) = id592in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_7("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 592) on port A, ram depth is 96.")));
      }
    }
  }
  { // Node ID: 885 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id885in_input = id592out_doutb[getCycle()%3];

    id885out_output[(getCycle()+17)%18] = id885in_input;
  }
  { // Node ID: 120 (NodeConstantRawBits)
  }
  { // Node ID: 883 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id883in_input = id424out_output;

    id883out_output[(getCycle()+1)%2] = id883in_input;
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 430 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id430in_en = id742out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id430in_max0 = id120out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id430in_reset = id883out_output[getCycle()%2];

    m_sm_CounterChain4460_sm.inputdata_en = id430in_en.getBitString();
    m_sm_CounterChain4460_sm.inputdata_max0 = id430in_max0.getBitString();
    m_sm_CounterChain4460_sm.inputdata_reset = id430in_reset.getBitString();
    m_sm_CounterChain4460_sm.execute(true);
    id430out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain4460_sm.outputdata_counter0) ));
    id430out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4460_sm.outputdata_done));
    id430out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain4460_sm.outputdata_saturated));
  }
  { // Node ID: 457 (NodeLt)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id457in_a = id430out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id457in_b = id120out_value;

    id457out_result[(getCycle()+1)%2] = (lt_fixed(id457in_a,id457in_b));
  }
  { // Node ID: 884 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id884in_input = id457out_result[getCycle()%2];

    id884out_output[(getCycle()+21)%22] = id884in_input;
  }
  { // Node ID: 458 (NodeLt)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id458in_a = id435out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id458in_b = id121out_value;

    id458out_result[(getCycle()+1)%2] = (lt_fixed(id458in_a,id458in_b));
  }
  { // Node ID: 459 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id459in_a = id884out_output[getCycle()%22];
    const HWOffsetFix<1,0,UNSIGNED> &id459in_b = id458out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id459x_1;

    (id459x_1) = (and_fixed(id459in_a,id459in_b));
    id459out_result[(getCycle()+1)%2] = (id459x_1);
  }
  { // Node ID: 886 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id886in_input = id459out_result[getCycle()%2];

    id886out_output[(getCycle()+57)%58] = id886in_input;
  }
  { // Node ID: 695 (NodeCondAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id695in_a = id590out_doutb[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id695in_b = id885out_output[getCycle()%18];
    const HWOffsetFix<1,0,UNSIGNED> &id695in_conda = id886out_output[getCycle()%58];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id695x_1;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id695x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id695x_3;

    switch((id695in_conda.getValueAsLong())) {
      case 0l:
        id695x_1 = (c_hw_fix_32_0_sgn_bits_2);
        break;
      case 1l:
        id695x_1 = id695in_a;
        break;
      default:
        id695x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    switch(((c_hw_fix_1_0_uns_bits_1).getValueAsLong())) {
      case 0l:
        id695x_2 = (c_hw_fix_32_0_sgn_bits_2);
        break;
      case 1l:
        id695x_2 = id695in_b;
        break;
      default:
        id695x_2 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    (id695x_3) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((id695x_1),(id695x_2)));
    id695out_result[(getCycle()+1)%2] = (id695x_3);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id752out_output;

  { // Node ID: 752 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id752in_input = id695out_result[getCycle()%2];

    id752out_output = id752in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id753out_output;

  { // Node ID: 753 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id753in_input = id852out_output[getCycle()%61];

    id753out_output = id753in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id474out_o;

  { // Node ID: 474 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id474in_i = id470out_counter0;

    id474out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id474in_i));
  }
  if ( (getFillLevel() >= (66l)))
  { // Node ID: 593 (NodeRAM)
    const bool id593_inputvalid = !(isFlushingActive() && getFlushLevel() >= (66l));
    const HWOffsetFix<7,0,UNSIGNED> &id593in_addrA = id888out_output[getCycle()%21];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id593in_dina = id752out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id593in_wea = id753out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id593in_addrB = id474out_o;

    long id593x_1;
    long id593x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id593x_3;

    (id593x_1) = (id593in_addrA.getValueAsLong());
    (id593x_2) = (id593in_addrB.getValueAsLong());
    switch(((long)((id593x_2)<(96l)))) {
      case 0l:
        id593x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id593x_3 = (id593sta_ram_store[(id593x_2)]);
        break;
      default:
        id593x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id593out_doutb[(getCycle()+2)%3] = (id593x_3);
    if(((id593in_wea.getValueAsBool())&id593_inputvalid)) {
      if(((id593x_1)<(96l))) {
        (id593sta_ram_store[(id593x_1)]) = id593in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_8("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 593) on port A, ram depth is 96.")));
      }
    }
  }
  HWRawBits<32> id525out_output;

  { // Node ID: 525 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id525in_input = id593out_doutb[getCycle()%3];

    id525out_output = (cast_fixed2bits(id525in_input));
  }
  if ( (getFillLevel() >= (68l)) && (getFlushLevel() < (68l)|| !isFlushingActive() ))
  { // Node ID: 524 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id524in_output_control = id889out_output[getCycle()%3];
    const HWRawBits<32> &id524in_data = id525out_output;

    bool id524x_1;

    (id524x_1) = ((id524in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(68l))&(isFlushingActive()))));
    if((id524x_1)) {
      writeOutput(m_DRAM4325_void4486_out, id524in_data);
    }
  }
  { // Node ID: 890 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id890in_input = id1out_intr_en;

    id890out_output[(getCycle()+1)%2] = id890in_input;
  }
  { // Node ID: 915 (NodeConstantRawBits)
  }
  { // Node ID: 550 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id550in_a = id547out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id550in_b = id915out_value;

    id550out_result[(getCycle()+1)%2] = (eq_fixed(id550in_a,id550in_b));
  }
  { // Node ID: 551 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id551in_a = id890out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id551in_b = id550out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id551x_1;

    (id551x_1) = (and_fixed(id551in_a,id551in_b));
    id551out_result[(getCycle()+1)%2] = (id551x_1);
  }
  { // Node ID: 567 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id568out_result;

  { // Node ID: 568 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id568in_a = id567out_io_intrCmd_force_disabled;

    id568out_result = (not_fixed(id568in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id569out_result;

  { // Node ID: 569 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id569in_a = id551out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id569in_b = id568out_result;

    HWOffsetFix<1,0,UNSIGNED> id569x_1;

    (id569x_1) = (and_fixed(id569in_a,id569in_b));
    id569out_result = (id569x_1);
  }

  TopKernelBlock1Vars out_vars;
  out_vars.id1out_cycles = id1out_cycles;
  out_vars.id569out_result = id569out_result;
  return out_vars;
};

};
