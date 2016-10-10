#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "TopKernel.h"

namespace maxcompilersim {

void TopKernel::execute0() {
  { // Node ID: 512 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id135out_output;

  { // Node ID: 135 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id135in_input = id134out_result[getCycle()%2];

    id135out_output = id135in_input;
  }
  { // Node ID: 57 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 175 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id175in_ctr_done = id433out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id175in_rst_done = id434out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id175in_sm_en = id435out_output[getCycle()%4];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id175in_sm_maxIn_0 = id57out_value;

    m_sm_pipe1063_sm.inputdata_ctr_done = id175in_ctr_done.getBitString();
    m_sm_pipe1063_sm.inputdata_rst_done = id175in_rst_done.getBitString();
    m_sm_pipe1063_sm.inputdata_sm_en = id175in_sm_en.getBitString();
    m_sm_pipe1063_sm.inputdata_sm_maxIn_0 = id175in_sm_maxIn_0.getBitString();
    m_sm_pipe1063_sm.execute(true);
    id175out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1063_sm.outputdata_ctr_en));
    id175out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe1063_sm.outputdata_ctr_maxOut_0) ));
    id175out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1063_sm.outputdata_rst_en));
    id175out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1063_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id425out_output;

  { // Node ID: 425 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id425in_input = id175out_sm_done;

    id425out_output = id425in_input;
  }
  { // Node ID: 508 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 297 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id297in_enable = id444out_output[getCycle()%2];
    const HWOffsetFix<33,0,UNSIGNED> &id297in_max = id508out_value;

    HWOffsetFix<33,0,UNSIGNED> id297x_1;
    HWOffsetFix<1,0,UNSIGNED> id297x_2;
    HWOffsetFix<1,0,UNSIGNED> id297x_3;
    HWOffsetFix<33,0,UNSIGNED> id297x_4t_1e_1;

    id297out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id297st_count)));
    (id297x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id297st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id297x_2) = (gte_fixed((id297x_1),id297in_max));
    (id297x_3) = (and_fixed((id297x_2),id297in_enable));
    id297out_wrap = (id297x_3);
    if((id297in_enable.getValueAsBool())) {
      if(((id297x_3).getValueAsBool())) {
        (id297st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id297x_4t_1e_1) = (id297x_1);
        (id297st_count) = (id297x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id298out_output;

  { // Node ID: 298 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id298in_input = id297out_wrap;

    id298out_output = id298in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id63out_output;

  { // Node ID: 63 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id63in_input = id445out_output[getCycle()%2];

    id63out_output = id63in_input;
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_intr_done = id298out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id1in_run_done = id63out_output;
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
  { // Node ID: 64 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 62 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id62in_s0_done = id446out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id62in_sm_en = id1out_run_en;
    const HWOffsetFix<32,0,UNSIGNED> &id62in_sm_numIter = id64out_value;

    m_sm_void1088_sm.inputdata_s0_done = id62in_s0_done.getBitString();
    m_sm_void1088_sm.inputdata_sm_en = id62in_sm_en.getBitString();
    m_sm_void1088_sm.inputdata_sm_numIter = id62in_sm_numIter.getBitString();
    m_sm_void1088_sm.execute(true);
    id62out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1088_sm.outputdata_rst_en));
    id62out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1088_sm.outputdata_s0_en));
    id62out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1088_sm.outputdata_sm_done));
  }
  { // Node ID: 361 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 67 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id67in_s0_done = id447out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id67in_s1_done = id448out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id67in_sm_en = id62out_s0_en;
    const HWOffsetFix<32,0,UNSIGNED> &id67in_sm_numIter = id361out_value;

    m_sm_seq1086_sm.inputdata_s0_done = id67in_s0_done.getBitString();
    m_sm_seq1086_sm.inputdata_s1_done = id67in_s1_done.getBitString();
    m_sm_seq1086_sm.inputdata_sm_en = id67in_sm_en.getBitString();
    m_sm_seq1086_sm.inputdata_sm_numIter = id67in_sm_numIter.getBitString();
    m_sm_seq1086_sm.execute(true);
    id67out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1086_sm.outputdata_rst_en));
    id67out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1086_sm.outputdata_s0_en));
    id67out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1086_sm.outputdata_s1_en));
    id67out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1086_sm.outputdata_sm_done));
  }
  { // Node ID: 365 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 82 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id82in_s0_done = id449out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id82in_s1_done = id450out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id82in_s2_done = id425out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id82in_sm_en = id67out_s0_en;
    const HWOffsetFix<32,0,UNSIGNED> &id82in_sm_numIter = id365out_value;

    m_sm_metapipe1065_sm.inputdata_s0_done = id82in_s0_done.getBitString();
    m_sm_metapipe1065_sm.inputdata_s1_done = id82in_s1_done.getBitString();
    m_sm_metapipe1065_sm.inputdata_s2_done = id82in_s2_done.getBitString();
    m_sm_metapipe1065_sm.inputdata_sm_en = id82in_sm_en.getBitString();
    m_sm_metapipe1065_sm.inputdata_sm_numIter = id82in_sm_numIter.getBitString();
    m_sm_metapipe1065_sm.execute(true);
    id82out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1065_sm.outputdata_rst_en));
    id82out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1065_sm.outputdata_s0_en));
    id82out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1065_sm.outputdata_s1_en));
    id82out_s2_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1065_sm.outputdata_s2_en));
    id82out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1065_sm.outputdata_sm_done));
    id82out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1065_sm.outputdata_sm_last));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 122 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id122in_memDone = id135out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id122in_sm_en = id82out_s1_en;

    m_sm_DRAM1003_void1055_inldSM.inputdata_memDone = id122in_memDone.getBitString();
    m_sm_DRAM1003_void1055_inldSM.inputdata_sm_en = id122in_sm_en.getBitString();
    m_sm_DRAM1003_void1055_inldSM.execute(true);
    id122out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1003_void1055_inldSM.outputdata_memStart));
    id122out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1003_void1055_inldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id123out_output;

  { // Node ID: 123 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id123in_input = id122out_sm_done;

    id123out_output = id123in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id130out_output;

  { // Node ID: 130 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id130in_input = id123out_output;

    id130out_output = id130in_input;
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 132 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id132in_enable = id122out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id132in_max = id512out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id132in_userReset = id130out_output;

    HWOffsetFix<17,0,UNSIGNED> id132x_1;
    HWOffsetFix<1,0,UNSIGNED> id132x_2;
    HWOffsetFix<1,0,UNSIGNED> id132x_3;
    HWOffsetFix<1,0,UNSIGNED> id132x_4;
    HWOffsetFix<17,0,UNSIGNED> id132x_5e_1t_1e_1;

    id132out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id132st_count)));
    (id132x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id132st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id132x_2) = (gt_fixed((id132x_1),id132in_max));
    (id132x_3) = (and_fixed(id132in_enable,(not_fixed((id132x_2)))));
    (id132x_4) = (c_hw_fix_1_0_uns_bits);
    id132out_wrap = (id132x_4);
    if((id132in_userReset.getValueAsBool())) {
      (id132st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id132x_3).getValueAsBool())) {
        if(((id132x_4).getValueAsBool())) {
          (id132st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id132x_5e_1t_1e_1) = (id132x_1);
          (id132st_count) = (id132x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 511 (NodeConstantRawBits)
  }
  { // Node ID: 134 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id134in_a = id132out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id134in_b = id511out_value;

    id134out_result[(getCycle()+1)%2] = (eq_fixed(id134in_a,id134in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id112out_output;

  { // Node ID: 112 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id112in_input = id430out_output[getCycle()%2];

    id112out_output = id112in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id422out_output;

  { // Node ID: 422 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id422in_input = id431out_output[getCycle()%2];

    id422out_output = id422in_input;
  }
  { // Node ID: 111 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 108 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id108in_ctr_done = id112out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id108in_rst_done = id422out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id108in_sm_en = id82out_s0_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id108in_sm_maxIn_0 = id111out_value;

    m_sm_void1053_sm.inputdata_ctr_done = id108in_ctr_done.getBitString();
    m_sm_void1053_sm.inputdata_rst_done = id108in_rst_done.getBitString();
    m_sm_void1053_sm.inputdata_sm_en = id108in_sm_en.getBitString();
    m_sm_void1053_sm.inputdata_sm_maxIn_0 = id108in_sm_maxIn_0.getBitString();
    m_sm_void1053_sm.execute(true);
    id108out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1053_sm.outputdata_ctr_en));
    id108out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_void1053_sm.outputdata_ctr_maxOut_0) ));
    id108out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1053_sm.outputdata_rst_en));
    id108out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1053_sm.outputdata_sm_done));
  }
  { // Node ID: 430 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id430in_input = id108out_ctr_en;

    id430out_output[(getCycle()+1)%2] = id430in_input;
  }
  { // Node ID: 431 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id431in_input = id108out_rst_en;

    id431out_output[(getCycle()+1)%2] = id431in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id423out_output;

  { // Node ID: 423 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id423in_input = id108out_sm_done;

    id423out_output = id423in_input;
  }
  { // Node ID: 449 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id449in_input = id423out_output;

    id449out_output[(getCycle()+1)%2] = id449in_input;
  }
  { // Node ID: 450 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id450in_input = id123out_output;

    id450out_output[(getCycle()+1)%2] = id450in_input;
  }
  { // Node ID: 432 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id432in_input = id425out_output;

    id432out_output[(getCycle()+3)%4] = id432in_input;
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 178 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id178in_en = id175out_ctr_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id178in_max0 = id175out_ctr_maxOut_0;
    const HWOffsetFix<1,0,UNSIGNED> &id178in_reset = id432out_output[getCycle()%4];

    m_sm_CounterChain1057_sm.inputdata_en = id178in_en.getBitString();
    m_sm_CounterChain1057_sm.inputdata_max0 = id178in_max0.getBitString();
    m_sm_CounterChain1057_sm.inputdata_reset = id178in_reset.getBitString();
    m_sm_CounterChain1057_sm.execute(true);
    id178out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1057_sm.outputdata_counter0) ));
    id178out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1057_sm.outputdata_done));
    id178out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1057_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id179out_output;

  { // Node ID: 179 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id179in_input = id178out_done;

    id179out_output = id179in_input;
  }
  { // Node ID: 433 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id433in_input = id179out_output;

    id433out_output[(getCycle()+1)%2] = id433in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id424out_output;

  { // Node ID: 424 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id424in_input = id175out_rst_en;

    id424out_output = id424in_input;
  }
  { // Node ID: 434 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id434in_input = id424out_output;

    id434out_output[(getCycle()+3)%4] = id434in_input;
  }
  { // Node ID: 435 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id435in_input = id82out_s2_en;

    id435out_output[(getCycle()+3)%4] = id435in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id83out_output;

  { // Node ID: 83 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id83in_input = id82out_sm_done;

    id83out_output = id83in_input;
  }
  { // Node ID: 447 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id447in_input = id83out_output;

    id447out_output[(getCycle()+1)%2] = id447in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id217out_output;

  { // Node ID: 217 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id217in_input = id437out_output[getCycle()%2];

    id217out_output = id217in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id426out_output;

  { // Node ID: 426 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id426in_input = id438out_output[getCycle()%3];

    id426out_output = id426in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id250out_output;

  { // Node ID: 250 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id250in_input = id249out_result[getCycle()%2];

    id250out_output = id250in_input;
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 238 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id238in_memDone = id250out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id238in_sm_en = id441out_output[getCycle()%2];

    m_sm_DRAM1004_void1082_outldSM.inputdata_memDone = id238in_memDone.getBitString();
    m_sm_DRAM1004_void1082_outldSM.inputdata_sm_en = id238in_sm_en.getBitString();
    m_sm_DRAM1004_void1082_outldSM.execute(true);
    id238out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1004_void1082_outldSM.outputdata_memStart));
    id238out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1004_void1082_outldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id239out_output;

  { // Node ID: 239 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id239in_input = id238out_sm_done;

    id239out_output = id239in_input;
  }
  { // Node ID: 353 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 187 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id187in_s0_done = id494out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id187in_s1_done = id443out_output[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id187in_s2_done = id239out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id187in_sm_en = id67out_s1_en;
    const HWOffsetFix<32,0,UNSIGNED> &id187in_sm_numIter = id353out_value;

    m_sm_metapipe1084_sm.inputdata_s0_done = id187in_s0_done.getBitString();
    m_sm_metapipe1084_sm.inputdata_s1_done = id187in_s1_done.getBitString();
    m_sm_metapipe1084_sm.inputdata_s2_done = id187in_s2_done.getBitString();
    m_sm_metapipe1084_sm.inputdata_sm_en = id187in_sm_en.getBitString();
    m_sm_metapipe1084_sm.inputdata_sm_numIter = id187in_sm_numIter.getBitString();
    m_sm_metapipe1084_sm.execute(true);
    id187out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1084_sm.outputdata_rst_en));
    id187out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1084_sm.outputdata_s0_en));
    id187out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1084_sm.outputdata_s1_en));
    id187out_s2_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1084_sm.outputdata_s2_en));
    id187out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1084_sm.outputdata_sm_done));
    id187out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1084_sm.outputdata_sm_last));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 213 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id213in_ctr_done = id217out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id213in_rst_done = id426out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id213in_sm_en = id187out_s0_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id213in_sm_maxIn_0 = id57out_value;

    m_sm_pipe1076_sm.inputdata_ctr_done = id213in_ctr_done.getBitString();
    m_sm_pipe1076_sm.inputdata_rst_done = id213in_rst_done.getBitString();
    m_sm_pipe1076_sm.inputdata_sm_en = id213in_sm_en.getBitString();
    m_sm_pipe1076_sm.inputdata_sm_maxIn_0 = id213in_sm_maxIn_0.getBitString();
    m_sm_pipe1076_sm.execute(true);
    id213out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1076_sm.outputdata_ctr_en));
    id213out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe1076_sm.outputdata_ctr_maxOut_0) ));
    id213out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1076_sm.outputdata_rst_en));
    id213out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1076_sm.outputdata_sm_done));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 216 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id216in_en = id213out_ctr_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id216in_max0 = id213out_ctr_maxOut_0;
    const HWOffsetFix<1,0,UNSIGNED> &id216in_reset = id494out_output[getCycle()%2];

    m_sm_CounterChain1070_sm.inputdata_en = id216in_en.getBitString();
    m_sm_CounterChain1070_sm.inputdata_max0 = id216in_max0.getBitString();
    m_sm_CounterChain1070_sm.inputdata_reset = id216in_reset.getBitString();
    m_sm_CounterChain1070_sm.execute(true);
    id216out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1070_sm.outputdata_counter0) ));
    id216out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1070_sm.outputdata_done));
    id216out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1070_sm.outputdata_saturated));
  }
  { // Node ID: 437 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id437in_input = id216out_done;

    id437out_output[(getCycle()+1)%2] = id437in_input;
  }
  { // Node ID: 438 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id438in_input = id213out_rst_en;

    id438out_output[(getCycle()+2)%3] = id438in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id427out_output;

  { // Node ID: 427 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id427in_input = id213out_sm_done;

    id427out_output = id427in_input;
  }
  { // Node ID: 471 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id471in_input = id427out_output;

    id471out_output[(getCycle()+1)%2] = id471in_input;
  }
  { // Node ID: 494 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id494in_input = id471out_output[getCycle()%2];

    id494out_output[(getCycle()+1)%2] = id494in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id231out_output;

  { // Node ID: 231 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id231in_input = id439out_output[getCycle()%2];

    id231out_output = id231in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id428out_output;

  { // Node ID: 428 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id428in_input = id440out_output[getCycle()%3];

    id428out_output = id428in_input;
  }
  { // Node ID: 230 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 227 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id227in_ctr_done = id231out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id227in_rst_done = id428out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id227in_sm_en = id187out_s1_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id227in_sm_maxIn_0 = id230out_value;

    m_sm_void1080_sm.inputdata_ctr_done = id227in_ctr_done.getBitString();
    m_sm_void1080_sm.inputdata_rst_done = id227in_rst_done.getBitString();
    m_sm_void1080_sm.inputdata_sm_en = id227in_sm_en.getBitString();
    m_sm_void1080_sm.inputdata_sm_maxIn_0 = id227in_sm_maxIn_0.getBitString();
    m_sm_void1080_sm.execute(true);
    id227out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1080_sm.outputdata_ctr_en));
    id227out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_void1080_sm.outputdata_ctr_maxOut_0) ));
    id227out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1080_sm.outputdata_rst_en));
    id227out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1080_sm.outputdata_sm_done));
  }
  { // Node ID: 439 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id439in_input = id227out_ctr_en;

    id439out_output[(getCycle()+1)%2] = id439in_input;
  }
  { // Node ID: 440 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id440in_input = id227out_rst_en;

    id440out_output[(getCycle()+2)%3] = id440in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id429out_output;

  { // Node ID: 429 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id429in_input = id227out_sm_done;

    id429out_output = id429in_input;
  }
  { // Node ID: 443 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id443in_input = id429out_output;

    id443out_output[(getCycle()+2)%3] = id443in_input;
  }
  { // Node ID: 510 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id245out_output;

  { // Node ID: 245 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id245in_input = id239out_output;

    id245out_output = id245in_input;
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 247 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id247in_enable = id238out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id247in_max = id510out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id247in_userReset = id245out_output;

    HWOffsetFix<17,0,UNSIGNED> id247x_1;
    HWOffsetFix<1,0,UNSIGNED> id247x_2;
    HWOffsetFix<1,0,UNSIGNED> id247x_3;
    HWOffsetFix<1,0,UNSIGNED> id247x_4;
    HWOffsetFix<17,0,UNSIGNED> id247x_5e_1t_1e_1;

    id247out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id247st_count)));
    (id247x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id247st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id247x_2) = (gt_fixed((id247x_1),id247in_max));
    (id247x_3) = (and_fixed(id247in_enable,(not_fixed((id247x_2)))));
    (id247x_4) = (c_hw_fix_1_0_uns_bits);
    id247out_wrap = (id247x_4);
    if((id247in_userReset.getValueAsBool())) {
      (id247st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id247x_3).getValueAsBool())) {
        if(((id247x_4).getValueAsBool())) {
          (id247st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id247x_5e_1t_1e_1) = (id247x_1);
          (id247st_count) = (id247x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 509 (NodeConstantRawBits)
  }
  { // Node ID: 249 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id249in_a = id247out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id249in_b = id509out_value;

    id249out_result[(getCycle()+1)%2] = (eq_fixed(id249in_a,id249in_b));
  }
  { // Node ID: 441 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id441in_input = id187out_s2_en;

    id441out_output[(getCycle()+1)%2] = id441in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id188out_output;

  { // Node ID: 188 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id188in_input = id187out_sm_done;

    id188out_output = id188in_input;
  }
  { // Node ID: 448 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id448in_input = id188out_output;

    id448out_output[(getCycle()+1)%2] = id448in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id68out_output;

  { // Node ID: 68 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id68in_input = id67out_sm_done;

    id68out_output = id68in_input;
  }
  { // Node ID: 446 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id446in_input = id68out_output;

    id446out_output[(getCycle()+1)%2] = id446in_input;
  }
  { // Node ID: 444 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id444in_input = id1out_intr_en;

    id444out_output[(getCycle()+1)%2] = id444in_input;
  }
  { // Node ID: 445 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id445in_input = id62out_sm_done;

    id445out_output[(getCycle()+1)%2] = id445in_input;
  }
  { // Node ID: 451 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id451in_input = id122out_memStart;

    id451out_output[(getCycle()+1)%2] = id451in_input;
  }
  { // Node ID: 507 (NodeConstantRawBits)
  }
  { // Node ID: 137 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id137in_a = id132out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id137in_b = id507out_value;

    id137out_result[(getCycle()+1)%2] = (eq_fixed(id137in_a,id137in_b));
  }
  { // Node ID: 138 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id138in_a = id451out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id138in_b = id137out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id138x_1;

    (id138x_1) = (and_fixed(id138in_a,id138in_b));
    id138out_result[(getCycle()+1)%2] = (id138x_1);
  }
  { // Node ID: 156 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id157out_result;

  { // Node ID: 157 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id157in_a = id156out_io_DRAM1003_void1055_in_cmd_force_disabled;

    id157out_result = (not_fixed(id157in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id158out_result;

  { // Node ID: 158 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id158in_a = id138out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id158in_b = id157out_result;

    HWOffsetFix<1,0,UNSIGNED> id158x_1;

    (id158x_1) = (and_fixed(id158in_a,id158in_b));
    id158out_result = (id158x_1);
  }
  { // Node ID: 464 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id464in_input = id158out_result;

    id464out_output[(getCycle()+42)%43] = id464in_input;
  }
  { // Node ID: 366 (NodeConstantRawBits)
  }
  { // Node ID: 371 (NodeConstantRawBits)
  }
  { // Node ID: 143 (NodeConstantRawBits)
  }
  HWRawBits<8> id163out_output;

  { // Node ID: 163 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id163in_input = id143out_value;

    id163out_output = (cast_fixed2bits(id163in_input));
  }
  { // Node ID: 376 (NodeConstantRawBits)
  }
  { // Node ID: 506 (NodeConstantRawBits)
  }
  { // Node ID: 291 (NodeConstantRawBits)
  }
  { // Node ID: 290 (NodeConstantRawBits)
  }
  { // Node ID: 492 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id492in_input = id449out_output[getCycle()%2];

    id492out_output[(getCycle()+3)%4] = id492in_input;
  }
  { // Node ID: 491 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id491in_input = id450out_output[getCycle()%2];

    id491out_output[(getCycle()+3)%4] = id491in_input;
  }
  { // Node ID: 3 (NodeConstantRawBits)
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
  { // Node ID: 454 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id454in_input = id82out_s0_en;

    id454out_output[(getCycle()+3)%4] = id454in_input;
  }
  { // Node ID: 455 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id455in_input = id82out_s1_en;

    id455out_output[(getCycle()+3)%4] = id455in_input;
  }
  { // Node ID: 4 (NodeConstantRawBits)
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
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 2 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id2in_broadcast = id291out_value;
    const HWOffsetFix<2,0,UNSIGNED> &id2in_numBlanks = id290out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageDone0 = id492out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageDone1 = id491out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageDone2 = id3out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageDone3 = id5out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageDone4 = id7out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageDone5 = id9out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageDone6 = id11out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageDone7 = id13out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageEn0 = id454out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageEn1 = id455out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageEn2 = id4out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageEn3 = id6out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageEn4 = id8out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageEn5 = id10out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageEn6 = id12out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id2in_stageEn7 = id14out_value;

    m_sm_reg1050_0.inputdata_broadcast = id2in_broadcast.getBitString();
    m_sm_reg1050_0.inputdata_numBlanks = id2in_numBlanks.getBitString();
    m_sm_reg1050_0.inputdata_stageDone0 = id2in_stageDone0.getBitString();
    m_sm_reg1050_0.inputdata_stageDone1 = id2in_stageDone1.getBitString();
    m_sm_reg1050_0.inputdata_stageDone2 = id2in_stageDone2.getBitString();
    m_sm_reg1050_0.inputdata_stageDone3 = id2in_stageDone3.getBitString();
    m_sm_reg1050_0.inputdata_stageDone4 = id2in_stageDone4.getBitString();
    m_sm_reg1050_0.inputdata_stageDone5 = id2in_stageDone5.getBitString();
    m_sm_reg1050_0.inputdata_stageDone6 = id2in_stageDone6.getBitString();
    m_sm_reg1050_0.inputdata_stageDone7 = id2in_stageDone7.getBitString();
    m_sm_reg1050_0.inputdata_stageEn0 = id2in_stageEn0.getBitString();
    m_sm_reg1050_0.inputdata_stageEn1 = id2in_stageEn1.getBitString();
    m_sm_reg1050_0.inputdata_stageEn2 = id2in_stageEn2.getBitString();
    m_sm_reg1050_0.inputdata_stageEn3 = id2in_stageEn3.getBitString();
    m_sm_reg1050_0.inputdata_stageEn4 = id2in_stageEn4.getBitString();
    m_sm_reg1050_0.inputdata_stageEn5 = id2in_stageEn5.getBitString();
    m_sm_reg1050_0.inputdata_stageEn6 = id2in_stageEn6.getBitString();
    m_sm_reg1050_0.inputdata_stageEn7 = id2in_stageEn7.getBitString();
    m_sm_reg1050_0.execute(true);
    id2out_curBuf0 = (HWOffsetFix<2,0,UNSIGNED>(m_sm_reg1050_0.outputdata_curBuf0));
    id2out_curBuf1 = (HWOffsetFix<2,0,UNSIGNED>(m_sm_reg1050_0.outputdata_curBuf1));
  }
  HWOffsetFix<1,0,UNSIGNED> id27out_o;

  { // Node ID: 27 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id27in_i = id2out_curBuf1;

    id27out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id27in_i));
  }
  { // Node ID: 463 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id463in_input = id27out_o;

    id463out_output[(getCycle()+2)%3] = id463in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id17out_o;

  { // Node ID: 17 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id17in_i = id2out_curBuf0;

    id17out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id17in_i));
  }
  { // Node ID: 289 (NodeConstantRawBits)
  }
  { // Node ID: 18 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id18in_sel = id17out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id18in_option0 = id492out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id18in_option1 = id289out_value;

    HWOffsetFix<1,0,UNSIGNED> id18x_1;

    switch((id18in_sel.getValueAsLong())) {
      case 0l:
        id18x_1 = id18in_option0;
        break;
      case 1l:
        id18x_1 = id18in_option1;
        break;
      default:
        id18x_1 = (c_hw_fix_1_0_uns_undef);
        break;
    }
    id18out_result[(getCycle()+1)%2] = (id18x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id15out_o;

  { // Node ID: 15 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id15in_i = id2out_curBuf0;

    id15out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id15in_i));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 79 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id79in_en = id448out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id79in_max0 = id57out_value;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id79in_max1 = id57out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id79in_reset = id446out_output[getCycle()%2];

    m_sm_CounterChain1045_sm.inputdata_en = id79in_en.getBitString();
    m_sm_CounterChain1045_sm.inputdata_max0 = id79in_max0.getBitString();
    m_sm_CounterChain1045_sm.inputdata_max1 = id79in_max1.getBitString();
    m_sm_CounterChain1045_sm.inputdata_reset = id79in_reset.getBitString();
    m_sm_CounterChain1045_sm.execute(true);
    id79out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1045_sm.outputdata_counter0) ));
    id79out_counter1 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1045_sm.outputdata_counter1) ));
    id79out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1045_sm.outputdata_done));
    id79out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1045_sm.outputdata_saturated));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 89 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id89in_en = id449out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id89in_max0 = id57out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id89in_reset = id447out_output[getCycle()%2];

    m_sm_CounterChain1049_sm.inputdata_en = id89in_en.getBitString();
    m_sm_CounterChain1049_sm.inputdata_max0 = id89in_max0.getBitString();
    m_sm_CounterChain1049_sm.inputdata_reset = id89in_reset.getBitString();
    m_sm_CounterChain1049_sm.execute(true);
    id89out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1049_sm.outputdata_counter0) ));
    id89out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1049_sm.outputdata_done));
    id89out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1049_sm.outputdata_saturated));
  }
  { // Node ID: 115 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id115in_a = id79out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id115in_b = id89out_counter0;

    id115out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id115in_a,id115in_b));
  }
  HWOffsetFix<32,5,TWOSCOMPLEMENT> id398out_output;

  { // Node ID: 398 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id398in_input = id115out_result[getCycle()%2];

    id398out_output = (cast_bits2fixed<32,5,TWOSCOMPLEMENT>((cast_fixed2bits(id398in_input))));
  }
  HWOffsetFix<32,6,TWOSCOMPLEMENT> id399out_output;

  { // Node ID: 399 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id399in_input = id115out_result[getCycle()%2];

    id399out_output = (cast_bits2fixed<32,6,TWOSCOMPLEMENT>((cast_fixed2bits(id399in_input))));
  }
  { // Node ID: 400 (NodeAdd)
    const HWOffsetFix<32,5,TWOSCOMPLEMENT> &id400in_a = id398out_output;
    const HWOffsetFix<32,6,TWOSCOMPLEMENT> &id400in_b = id399out_output;

    id400out_result[(getCycle()+1)%2] = (add_fixed<34,5,TWOSCOMPLEMENT,TONEAR>(id400in_a,id400in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id401out_o;

  { // Node ID: 401 (NodeCast)
    const HWOffsetFix<34,5,TWOSCOMPLEMENT> &id401in_i = id400out_result[getCycle()%2];

    id401out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id401in_i));
  }
  { // Node ID: 461 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id461in_input = id79out_counter1;

    id461out_output[(getCycle()+2)%3] = id461in_input;
  }
  { // Node ID: 117 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id117in_a = id401out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id117in_b = id461out_output[getCycle()%3];

    id117out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id117in_a,id117in_b));
  }
  { // Node ID: 288 (NodeConstantRawBits)
  }
  { // Node ID: 16 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id16in_sel = id15out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id16in_option0 = id117out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id16in_option1 = id288out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id16x_1;

    switch((id16in_sel.getValueAsLong())) {
      case 0l:
        id16x_1 = id16in_option0;
        break;
      case 1l:
        id16x_1 = id16in_option1;
        break;
      default:
        id16x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id16out_result[(getCycle()+1)%2] = (id16x_1);
  }
  { // Node ID: 118 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (8l)))
  { // Node ID: 19 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id19in_load = id18out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id19in_input = id16out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id19in_user_reset = id118out_value;

    if((id19in_user_reset.getValueAsBool())) {
      (id19st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id19in_load.getValueAsBool())) {
        (id19st_holdreg) = id19in_input;
      }
    }
    id19out_output[(getCycle()+1)%2] = (id19st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id22out_o;

  { // Node ID: 22 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id22in_i = id2out_curBuf1;

    id22out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id22in_i));
  }
  { // Node ID: 23 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id23in_sel = id22out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id23in_option0 = id492out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id23in_option1 = id289out_value;

    HWOffsetFix<1,0,UNSIGNED> id23x_1;

    switch((id23in_sel.getValueAsLong())) {
      case 0l:
        id23x_1 = id23in_option0;
        break;
      case 1l:
        id23x_1 = id23in_option1;
        break;
      default:
        id23x_1 = (c_hw_fix_1_0_uns_undef);
        break;
    }
    id23out_result[(getCycle()+1)%2] = (id23x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id20out_o;

  { // Node ID: 20 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id20in_i = id2out_curBuf1;

    id20out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id20in_i));
  }
  { // Node ID: 21 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id21in_sel = id20out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_option0 = id117out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_option1 = id288out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id21x_1;

    switch((id21in_sel.getValueAsLong())) {
      case 0l:
        id21x_1 = id21in_option0;
        break;
      case 1l:
        id21x_1 = id21in_option1;
        break;
      default:
        id21x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id21out_result[(getCycle()+1)%2] = (id21x_1);
  }
  if ( (getFillLevel() >= (8l)))
  { // Node ID: 24 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id24in_load = id23out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id24in_input = id21out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id24in_user_reset = id118out_value;

    if((id24in_user_reset.getValueAsBool())) {
      (id24st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id24in_load.getValueAsBool())) {
        (id24st_holdreg) = id24in_input;
      }
    }
    id24out_output[(getCycle()+1)%2] = (id24st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id28out_result;

  { // Node ID: 28 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id28in_sel = id463out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id28in_option0 = id19out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id28in_option1 = id24out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id28x_1;

    switch((id28in_sel.getValueAsLong())) {
      case 0l:
        id28x_1 = id28in_option0;
        break;
      case 1l:
        id28x_1 = id28in_option1;
        break;
      default:
        id28x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id28out_result = (id28x_1);
  }
  { // Node ID: 505 (NodeConstantRawBits)
  }
  { // Node ID: 125 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id125in_a = id28out_result;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id125in_b = id505out_value;

    id125out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id125in_a,id125in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id126out_o;

  { // Node ID: 126 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id126in_i = id125out_result[getCycle()%39];

    id126out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id126in_i));
  }
  { // Node ID: 128 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id128in_a = id506out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id128in_b = id126out_o;

    id128out_result[(getCycle()+1)%2] = (add_fixed<32,0,UNSIGNED,TONEAR>(id128in_a,id128in_b));
  }
  HWRawBits<32> id160out_output;

  { // Node ID: 160 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id160in_input = id128out_result[getCycle()%2];

    id160out_output = (cast_fixed2bits(id160in_input));
  }
  HWRawBits<40> id162out_result;

  { // Node ID: 162 (NodeCat)
    const HWRawBits<8> &id162in_in0 = id376out_value;
    const HWRawBits<32> &id162in_in1 = id160out_output;

    id162out_result = (cat(id162in_in0,id162in_in1));
  }
  HWRawBits<48> id164out_result;

  { // Node ID: 164 (NodeCat)
    const HWRawBits<8> &id164in_in0 = id163out_output;
    const HWRawBits<40> &id164in_in1 = id162out_result;

    id164out_result = (cat(id164in_in0,id164in_in1));
  }
  HWRawBits<63> id166out_result;

  { // Node ID: 166 (NodeCat)
    const HWRawBits<15> &id166in_in0 = id371out_value;
    const HWRawBits<48> &id166in_in1 = id164out_result;

    id166out_result = (cat(id166in_in0,id166in_in1));
  }
  HWRawBits<64> id168out_result;

  { // Node ID: 168 (NodeCat)
    const HWRawBits<1> &id168in_in0 = id366out_value;
    const HWRawBits<63> &id168in_in1 = id166out_result;

    id168out_result = (cat(id168in_in0,id168in_in1));
  }
  if ( (getFillLevel() >= (48l)) && (getFlushLevel() < (48l)|| !isFlushingActive() ))
  { // Node ID: 159 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id159in_output_control = id464out_output[getCycle()%43];
    const HWRawBits<64> &id159in_data = id168out_result;

    bool id159x_1;

    (id159x_1) = ((id159in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(48l))&(isFlushingActive()))));
    if((id159x_1)) {
      writeOutput(m_DRAM1003_void1055_in_cmd, id159in_data);
    }
  }
  { // Node ID: 465 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id465in_input = id238out_memStart;

    id465out_output[(getCycle()+1)%2] = id465in_input;
  }
  { // Node ID: 504 (NodeConstantRawBits)
  }
  { // Node ID: 252 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id252in_a = id247out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id252in_b = id504out_value;

    id252out_result[(getCycle()+1)%2] = (eq_fixed(id252in_a,id252in_b));
  }
  { // Node ID: 253 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id253in_a = id465out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id253in_b = id252out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id253x_1;

    (id253x_1) = (and_fixed(id253in_a,id253in_b));
    id253out_result[(getCycle()+1)%2] = (id253x_1);
  }
  { // Node ID: 270 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id271out_result;

  { // Node ID: 271 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id271in_a = id270out_io_DRAM1004_void1082_out_cmd_force_disabled;

    id271out_result = (not_fixed(id271in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id272out_result;

  { // Node ID: 272 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id272in_a = id253out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id272in_b = id271out_result;

    HWOffsetFix<1,0,UNSIGNED> id272x_1;

    (id272x_1) = (and_fixed(id272in_a,id272in_b));
    id272out_result = (id272x_1);
  }
  { // Node ID: 476 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id476in_input = id272out_result;

    id476out_output[(getCycle()+41)%42] = id476in_input;
  }
  { // Node ID: 377 (NodeConstantRawBits)
  }
  { // Node ID: 382 (NodeConstantRawBits)
  }
  { // Node ID: 257 (NodeConstantRawBits)
  }
  HWRawBits<8> id277out_output;

  { // Node ID: 277 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id277in_input = id257out_value;

    id277out_output = (cast_fixed2bits(id277in_input));
  }
  { // Node ID: 387 (NodeConstantRawBits)
  }
  { // Node ID: 503 (NodeConstantRawBits)
  }
  { // Node ID: 295 (NodeConstantRawBits)
  }
  { // Node ID: 294 (NodeConstantRawBits)
  }
  { // Node ID: 495 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id495in_input = id443out_output[getCycle()%3];

    id495out_output[(getCycle()+3)%4] = id495in_input;
  }
  { // Node ID: 467 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id467in_input = id239out_output;

    id467out_output[(getCycle()+3)%4] = id467in_input;
  }
  { // Node ID: 30 (NodeConstantRawBits)
  }
  { // Node ID: 32 (NodeConstantRawBits)
  }
  { // Node ID: 34 (NodeConstantRawBits)
  }
  { // Node ID: 36 (NodeConstantRawBits)
  }
  { // Node ID: 38 (NodeConstantRawBits)
  }
  { // Node ID: 40 (NodeConstantRawBits)
  }
  { // Node ID: 468 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id468in_input = id187out_s1_en;

    id468out_output[(getCycle()+3)%4] = id468in_input;
  }
  { // Node ID: 496 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id496in_input = id441out_output[getCycle()%2];

    id496out_output[(getCycle()+2)%3] = id496in_input;
  }
  { // Node ID: 31 (NodeConstantRawBits)
  }
  { // Node ID: 33 (NodeConstantRawBits)
  }
  { // Node ID: 35 (NodeConstantRawBits)
  }
  { // Node ID: 37 (NodeConstantRawBits)
  }
  { // Node ID: 39 (NodeConstantRawBits)
  }
  { // Node ID: 41 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 29 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id29in_broadcast = id295out_value;
    const HWOffsetFix<2,0,UNSIGNED> &id29in_numBlanks = id294out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageDone0 = id495out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageDone1 = id467out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageDone2 = id30out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageDone3 = id32out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageDone4 = id34out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageDone5 = id36out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageDone6 = id38out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageDone7 = id40out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageEn0 = id468out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageEn1 = id496out_output[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageEn2 = id31out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageEn3 = id33out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageEn4 = id35out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageEn5 = id37out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageEn6 = id39out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_stageEn7 = id41out_value;

    m_sm_reg1077_0.inputdata_broadcast = id29in_broadcast.getBitString();
    m_sm_reg1077_0.inputdata_numBlanks = id29in_numBlanks.getBitString();
    m_sm_reg1077_0.inputdata_stageDone0 = id29in_stageDone0.getBitString();
    m_sm_reg1077_0.inputdata_stageDone1 = id29in_stageDone1.getBitString();
    m_sm_reg1077_0.inputdata_stageDone2 = id29in_stageDone2.getBitString();
    m_sm_reg1077_0.inputdata_stageDone3 = id29in_stageDone3.getBitString();
    m_sm_reg1077_0.inputdata_stageDone4 = id29in_stageDone4.getBitString();
    m_sm_reg1077_0.inputdata_stageDone5 = id29in_stageDone5.getBitString();
    m_sm_reg1077_0.inputdata_stageDone6 = id29in_stageDone6.getBitString();
    m_sm_reg1077_0.inputdata_stageDone7 = id29in_stageDone7.getBitString();
    m_sm_reg1077_0.inputdata_stageEn0 = id29in_stageEn0.getBitString();
    m_sm_reg1077_0.inputdata_stageEn1 = id29in_stageEn1.getBitString();
    m_sm_reg1077_0.inputdata_stageEn2 = id29in_stageEn2.getBitString();
    m_sm_reg1077_0.inputdata_stageEn3 = id29in_stageEn3.getBitString();
    m_sm_reg1077_0.inputdata_stageEn4 = id29in_stageEn4.getBitString();
    m_sm_reg1077_0.inputdata_stageEn5 = id29in_stageEn5.getBitString();
    m_sm_reg1077_0.inputdata_stageEn6 = id29in_stageEn6.getBitString();
    m_sm_reg1077_0.inputdata_stageEn7 = id29in_stageEn7.getBitString();
    m_sm_reg1077_0.execute(true);
    id29out_curBuf0 = (HWOffsetFix<2,0,UNSIGNED>(m_sm_reg1077_0.outputdata_curBuf0));
    id29out_curBuf1 = (HWOffsetFix<2,0,UNSIGNED>(m_sm_reg1077_0.outputdata_curBuf1));
  }
  HWOffsetFix<1,0,UNSIGNED> id54out_o;

  { // Node ID: 54 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id54in_i = id29out_curBuf1;

    id54out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id54in_i));
  }
  { // Node ID: 475 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id475in_input = id54out_o;

    id475out_output[(getCycle()+2)%3] = id475in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id44out_o;

  { // Node ID: 44 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id44in_i = id29out_curBuf0;

    id44out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id44in_i));
  }
  { // Node ID: 293 (NodeConstantRawBits)
  }
  { // Node ID: 45 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id45in_sel = id44out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id45in_option0 = id495out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id45in_option1 = id293out_value;

    HWOffsetFix<1,0,UNSIGNED> id45x_1;

    switch((id45in_sel.getValueAsLong())) {
      case 0l:
        id45x_1 = id45in_option0;
        break;
      case 1l:
        id45x_1 = id45in_option1;
        break;
      default:
        id45x_1 = (c_hw_fix_1_0_uns_undef);
        break;
    }
    id45out_result[(getCycle()+1)%2] = (id45x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id42out_o;

  { // Node ID: 42 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id42in_i = id29out_curBuf0;

    id42out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id42in_i));
  }
  if ( (getFillLevel() >= (2l)))
  { // Node ID: 197 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id197in_r_done = id429out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id197in_w_done = id427out_output;

    m_sm_metapipe1084_FixedPoint9020_1.inputdata_r_done = id197in_r_done.getBitString();
    m_sm_metapipe1084_FixedPoint9020_1.inputdata_w_done = id197in_w_done.getBitString();
    m_sm_metapipe1084_FixedPoint9020_1.execute(true);
    id197out_curBuf = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1084_FixedPoint9020_1.outputdata_curBuf));
  }
  { // Node ID: 472 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id472in_input = id197out_curBuf;

    id472out_output[(getCycle()+2)%3] = id472in_input;
  }
  { // Node ID: 201 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id201in_a = id197out_curBuf;
    const HWOffsetFix<1,0,UNSIGNED> &id201in_b = id427out_output;

    HWOffsetFix<1,0,UNSIGNED> id201x_1;

    (id201x_1) = (and_fixed(id201in_a,id201in_b));
    id201out_result[(getCycle()+1)%2] = (id201x_1);
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 194 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id194in_en = id471out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id194in_max0 = id57out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id194in_reset = id188out_output;

    m_sm_CounterChain1068_sm.inputdata_en = id194in_en.getBitString();
    m_sm_CounterChain1068_sm.inputdata_max0 = id194in_max0.getBitString();
    m_sm_CounterChain1068_sm.inputdata_reset = id194in_reset.getBitString();
    m_sm_CounterChain1068_sm.execute(true);
    id194out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1068_sm.outputdata_counter0) ));
    id194out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1068_sm.outputdata_done));
    id194out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1068_sm.outputdata_saturated));
  }
  { // Node ID: 204 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 202 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id202in_load = id201out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id202in_input = id194out_counter0;
    const HWOffsetFix<1,0,UNSIGNED> &id202in_user_reset = id204out_value;

    if((id202in_user_reset.getValueAsBool())) {
      (id202st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id202in_load.getValueAsBool())) {
        (id202st_holdreg) = id202in_input;
      }
    }
    id202out_output[(getCycle()+1)%2] = (id202st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id198out_result;

  { // Node ID: 198 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id198in_a = id197out_curBuf;

    id198out_result = (not_fixed(id198in_a));
  }
  { // Node ID: 199 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id199in_a = id198out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id199in_b = id427out_output;

    HWOffsetFix<1,0,UNSIGNED> id199x_1;

    (id199x_1) = (and_fixed(id199in_a,id199in_b));
    id199out_result[(getCycle()+1)%2] = (id199x_1);
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 200 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id200in_load = id199out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id200in_input = id194out_counter0;
    const HWOffsetFix<1,0,UNSIGNED> &id200in_user_reset = id204out_value;

    if((id200in_user_reset.getValueAsBool())) {
      (id200st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id200in_load.getValueAsBool())) {
        (id200st_holdreg) = id200in_input;
      }
    }
    id200out_output[(getCycle()+1)%2] = (id200st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id203out_result;

  { // Node ID: 203 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id203in_sel = id472out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id203in_option0 = id202out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id203in_option1 = id200out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id203x_1;

    switch((id203in_sel.getValueAsLong())) {
      case 0l:
        id203x_1 = id203in_option0;
        break;
      case 1l:
        id203x_1 = id203in_option1;
        break;
      default:
        id203x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id203out_result = (id203x_1);
  }
  { // Node ID: 234 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id234in_a = id79out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id234in_b = id203out_result;

    id234out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id234in_a,id234in_b));
  }
  HWOffsetFix<32,5,TWOSCOMPLEMENT> id402out_output;

  { // Node ID: 402 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id402in_input = id234out_result[getCycle()%2];

    id402out_output = (cast_bits2fixed<32,5,TWOSCOMPLEMENT>((cast_fixed2bits(id402in_input))));
  }
  HWOffsetFix<32,6,TWOSCOMPLEMENT> id403out_output;

  { // Node ID: 403 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id403in_input = id234out_result[getCycle()%2];

    id403out_output = (cast_bits2fixed<32,6,TWOSCOMPLEMENT>((cast_fixed2bits(id403in_input))));
  }
  { // Node ID: 404 (NodeAdd)
    const HWOffsetFix<32,5,TWOSCOMPLEMENT> &id404in_a = id402out_output;
    const HWOffsetFix<32,6,TWOSCOMPLEMENT> &id404in_b = id403out_output;

    id404out_result[(getCycle()+1)%2] = (add_fixed<34,5,TWOSCOMPLEMENT,TONEAR>(id404in_a,id404in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id405out_o;

  { // Node ID: 405 (NodeCast)
    const HWOffsetFix<34,5,TWOSCOMPLEMENT> &id405in_i = id404out_result[getCycle()%2];

    id405out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id405in_i));
  }
  { // Node ID: 236 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id236in_a = id405out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id236in_b = id461out_output[getCycle()%3];

    id236out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id236in_a,id236in_b));
  }
  { // Node ID: 292 (NodeConstantRawBits)
  }
  { // Node ID: 43 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id43in_sel = id42out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id43in_option0 = id236out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id43in_option1 = id292out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id43x_1;

    switch((id43in_sel.getValueAsLong())) {
      case 0l:
        id43x_1 = id43in_option0;
        break;
      case 1l:
        id43x_1 = id43in_option1;
        break;
      default:
        id43x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id43out_result[(getCycle()+1)%2] = (id43x_1);
  }
  { // Node ID: 237 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (8l)))
  { // Node ID: 46 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id46in_load = id45out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id46in_input = id43out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id46in_user_reset = id237out_value;

    if((id46in_user_reset.getValueAsBool())) {
      (id46st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id46in_load.getValueAsBool())) {
        (id46st_holdreg) = id46in_input;
      }
    }
    id46out_output[(getCycle()+1)%2] = (id46st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id49out_o;

  { // Node ID: 49 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id49in_i = id29out_curBuf1;

    id49out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id49in_i));
  }
  { // Node ID: 50 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id50in_sel = id49out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id50in_option0 = id495out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id50in_option1 = id293out_value;

    HWOffsetFix<1,0,UNSIGNED> id50x_1;

    switch((id50in_sel.getValueAsLong())) {
      case 0l:
        id50x_1 = id50in_option0;
        break;
      case 1l:
        id50x_1 = id50in_option1;
        break;
      default:
        id50x_1 = (c_hw_fix_1_0_uns_undef);
        break;
    }
    id50out_result[(getCycle()+1)%2] = (id50x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id47out_o;

  { // Node ID: 47 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id47in_i = id29out_curBuf1;

    id47out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id47in_i));
  }
  { // Node ID: 48 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id48in_sel = id47out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id48in_option0 = id236out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id48in_option1 = id292out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id48x_1;

    switch((id48in_sel.getValueAsLong())) {
      case 0l:
        id48x_1 = id48in_option0;
        break;
      case 1l:
        id48x_1 = id48in_option1;
        break;
      default:
        id48x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id48out_result[(getCycle()+1)%2] = (id48x_1);
  }
  if ( (getFillLevel() >= (8l)))
  { // Node ID: 51 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id51in_load = id50out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id51in_input = id48out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id51in_user_reset = id237out_value;

    if((id51in_user_reset.getValueAsBool())) {
      (id51st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id51in_load.getValueAsBool())) {
        (id51st_holdreg) = id51in_input;
      }
    }
    id51out_output[(getCycle()+1)%2] = (id51st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id55out_result;

  { // Node ID: 55 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id55in_sel = id475out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id55in_option0 = id46out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id55in_option1 = id51out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id55x_1;

    switch((id55in_sel.getValueAsLong())) {
      case 0l:
        id55x_1 = id55in_option0;
        break;
      case 1l:
        id55x_1 = id55in_option1;
        break;
      default:
        id55x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id55out_result = (id55x_1);
  }
  { // Node ID: 502 (NodeConstantRawBits)
  }
  { // Node ID: 241 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id241in_a = id55out_result;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id241in_b = id502out_value;

    id241out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id241in_a,id241in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id242out_o;

  { // Node ID: 242 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id242in_i = id241out_result[getCycle()%39];

    id242out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id242in_i));
  }
  { // Node ID: 244 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id244in_a = id503out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id244in_b = id242out_o;

    id244out_result[(getCycle()+1)%2] = (add_fixed<32,0,UNSIGNED,TONEAR>(id244in_a,id244in_b));
  }
  HWRawBits<32> id274out_output;

  { // Node ID: 274 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id274in_input = id244out_result[getCycle()%2];

    id274out_output = (cast_fixed2bits(id274in_input));
  }
  HWRawBits<40> id276out_result;

  { // Node ID: 276 (NodeCat)
    const HWRawBits<8> &id276in_in0 = id387out_value;
    const HWRawBits<32> &id276in_in1 = id274out_output;

    id276out_result = (cat(id276in_in0,id276in_in1));
  }
  HWRawBits<48> id278out_result;

  { // Node ID: 278 (NodeCat)
    const HWRawBits<8> &id278in_in0 = id277out_output;
    const HWRawBits<40> &id278in_in1 = id276out_result;

    id278out_result = (cat(id278in_in0,id278in_in1));
  }
  HWRawBits<63> id280out_result;

  { // Node ID: 280 (NodeCat)
    const HWRawBits<15> &id280in_in0 = id382out_value;
    const HWRawBits<48> &id280in_in1 = id278out_result;

    id280out_result = (cat(id280in_in0,id280in_in1));
  }
  HWRawBits<64> id282out_result;

  { // Node ID: 282 (NodeCat)
    const HWRawBits<1> &id282in_in0 = id377out_value;
    const HWRawBits<63> &id282in_in1 = id280out_result;

    id282out_result = (cat(id282in_in0,id282in_in1));
  }
  if ( (getFillLevel() >= (48l)) && (getFlushLevel() < (48l)|| !isFlushingActive() ))
  { // Node ID: 273 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id273in_output_control = id476out_output[getCycle()%42];
    const HWRawBits<64> &id273in_data = id282out_result;

    bool id273x_1;

    (id273x_1) = ((id273in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(48l))&(isFlushingActive()))));
    if((id273x_1)) {
      writeOutput(m_DRAM1004_void1082_out_cmd, id273in_data);
    }
  }
  { // Node ID: 477 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id477in_input = id213out_ctr_en;

    id477out_output[(getCycle()+3)%4] = id477in_input;
  }
  { // Node ID: 283 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id284out_result;

  { // Node ID: 284 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id284in_a = id283out_io_DRAM1004_void1082_out_force_disabled;

    id284out_result = (not_fixed(id284in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id285out_result;

  { // Node ID: 285 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id285in_a = id477out_output[getCycle()%4];
    const HWOffsetFix<1,0,UNSIGNED> &id285in_b = id284out_result;

    HWOffsetFix<1,0,UNSIGNED> id285x_1;

    (id285x_1) = (and_fixed(id285in_a,id285in_b));
    id285out_result = (id285x_1);
  }
  { // Node ID: 487 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id487in_input = id285out_result;

    id487out_output[(getCycle()+64)%65] = id487in_input;
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 100 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id100in_r_done = id425out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id100in_w_done = id450out_output[getCycle()%2];

    m_sm_metapipe1065_FixedPoint8741_2.inputdata_r_done = id100in_r_done.getBitString();
    m_sm_metapipe1065_FixedPoint8741_2.inputdata_w_done = id100in_w_done.getBitString();
    m_sm_metapipe1065_FixedPoint8741_2.execute(true);
    id100out_curBuf = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1065_FixedPoint8741_2.outputdata_curBuf));
  }
  { // Node ID: 482 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id482in_input = id100out_curBuf;

    id482out_output[(getCycle()+2)%3] = id482in_input;
  }
  { // Node ID: 104 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id104in_a = id100out_curBuf;
    const HWOffsetFix<1,0,UNSIGNED> &id104in_b = id450out_output[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id104x_1;

    (id104x_1) = (and_fixed(id104in_a,id104in_b));
    id104out_result[(getCycle()+1)%2] = (id104x_1);
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 92 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id92in_r_done = id123out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id92in_w_done = id423out_output;

    m_sm_metapipe1065_FixedPoint8740_1.inputdata_r_done = id92in_r_done.getBitString();
    m_sm_metapipe1065_FixedPoint8740_1.inputdata_w_done = id92in_w_done.getBitString();
    m_sm_metapipe1065_FixedPoint8740_1.execute(true);
    id92out_curBuf = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1065_FixedPoint8740_1.outputdata_curBuf));
  }
  { // Node ID: 480 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id480in_input = id92out_curBuf;

    id480out_output[(getCycle()+2)%3] = id480in_input;
  }
  { // Node ID: 96 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id96in_a = id92out_curBuf;
    const HWOffsetFix<1,0,UNSIGNED> &id96in_b = id423out_output;

    HWOffsetFix<1,0,UNSIGNED> id96x_1;

    (id96x_1) = (and_fixed(id96in_a,id96in_b));
    id96out_result[(getCycle()+1)%2] = (id96x_1);
  }
  { // Node ID: 99 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 97 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id97in_load = id96out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id97in_input = id89out_counter0;
    const HWOffsetFix<1,0,UNSIGNED> &id97in_user_reset = id99out_value;

    if((id97in_user_reset.getValueAsBool())) {
      (id97st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id97in_load.getValueAsBool())) {
        (id97st_holdreg) = id97in_input;
      }
    }
    id97out_output[(getCycle()+1)%2] = (id97st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id93out_result;

  { // Node ID: 93 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id93in_a = id92out_curBuf;

    id93out_result = (not_fixed(id93in_a));
  }
  { // Node ID: 94 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id94in_a = id93out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id94in_b = id423out_output;

    HWOffsetFix<1,0,UNSIGNED> id94x_1;

    (id94x_1) = (and_fixed(id94in_a,id94in_b));
    id94out_result[(getCycle()+1)%2] = (id94x_1);
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 95 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id95in_load = id94out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id95in_input = id89out_counter0;
    const HWOffsetFix<1,0,UNSIGNED> &id95in_user_reset = id99out_value;

    if((id95in_user_reset.getValueAsBool())) {
      (id95st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id95in_load.getValueAsBool())) {
        (id95st_holdreg) = id95in_input;
      }
    }
    id95out_output[(getCycle()+1)%2] = (id95st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id98out_result;

  { // Node ID: 98 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id98in_sel = id480out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id98in_option0 = id97out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id98in_option1 = id95out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id98x_1;

    switch((id98in_sel.getValueAsLong())) {
      case 0l:
        id98x_1 = id98in_option0;
        break;
      case 1l:
        id98x_1 = id98in_option1;
        break;
      default:
        id98x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id98out_result = (id98x_1);
  }
  { // Node ID: 107 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 105 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id105in_load = id104out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id105in_input = id98out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id105in_user_reset = id107out_value;

    if((id105in_user_reset.getValueAsBool())) {
      (id105st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id105in_load.getValueAsBool())) {
        (id105st_holdreg) = id105in_input;
      }
    }
    id105out_output[(getCycle()+1)%2] = (id105st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id101out_result;

  { // Node ID: 101 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id101in_a = id100out_curBuf;

    id101out_result = (not_fixed(id101in_a));
  }
  { // Node ID: 102 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id102in_a = id101out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id102in_b = id450out_output[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id102x_1;

    (id102x_1) = (and_fixed(id102in_a,id102in_b));
    id102out_result[(getCycle()+1)%2] = (id102x_1);
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 103 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id103in_load = id102out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id103in_input = id98out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id103in_user_reset = id107out_value;

    if((id103in_user_reset.getValueAsBool())) {
      (id103st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id103in_load.getValueAsBool())) {
        (id103st_holdreg) = id103in_input;
      }
    }
    id103out_output[(getCycle()+1)%2] = (id103st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id106out_result;

  { // Node ID: 106 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id106in_sel = id482out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id106in_option0 = id105out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id106in_option1 = id103out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id106x_1;

    switch((id106in_sel.getValueAsLong())) {
      case 0l:
        id106x_1 = id106in_option0;
        break;
      case 1l:
        id106x_1 = id106in_option1;
        break;
      default:
        id106x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id106out_result = (id106x_1);
  }
  HWOffsetFix<32,5,TWOSCOMPLEMENT> id406out_output;

  { // Node ID: 406 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id406in_input = id106out_result;

    id406out_output = (cast_bits2fixed<32,5,TWOSCOMPLEMENT>((cast_fixed2bits(id406in_input))));
  }
  HWOffsetFix<32,6,TWOSCOMPLEMENT> id407out_output;

  { // Node ID: 407 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id407in_input = id106out_result;

    id407out_output = (cast_bits2fixed<32,6,TWOSCOMPLEMENT>((cast_fixed2bits(id407in_input))));
  }
  { // Node ID: 408 (NodeAdd)
    const HWOffsetFix<32,5,TWOSCOMPLEMENT> &id408in_a = id406out_output;
    const HWOffsetFix<32,6,TWOSCOMPLEMENT> &id408in_b = id407out_output;

    id408out_result[(getCycle()+1)%2] = (add_fixed<34,5,TWOSCOMPLEMENT,TONEAR>(id408in_a,id408in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id409out_o;

  { // Node ID: 409 (NodeCast)
    const HWOffsetFix<34,5,TWOSCOMPLEMENT> &id409in_i = id408out_result[getCycle()%2];

    id409out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id409in_i));
  }
  { // Node ID: 185 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id185in_a = id409out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id185in_b = id178out_counter0;

    id185out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id185in_a,id185in_b));
  }
  HWOffsetFix<14,0,UNSIGNED> id186out_o;

  { // Node ID: 186 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id186in_i = id185out_result[getCycle()%2];

    id186out_o = (cast_fixed2fixed<14,0,UNSIGNED,TONEAR>(id186in_i));
  }
  { // Node ID: 484 (NodeFIFO)
    const HWOffsetFix<14,0,UNSIGNED> &id484in_input = id186out_o;

    id484out_output[(getCycle()+61)%62] = id484in_input;
  }
  { // Node ID: 483 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id483in_input = id175out_ctr_en;

    id483out_output[(getCycle()+57)%58] = id483in_input;
  }
  { // Node ID: 169 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id170out_result;

  { // Node ID: 170 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id170in_a = id169out_io_DRAM1003_void1055_in_force_disabled;

    id170out_result = (not_fixed(id170in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id171out_result;

  { // Node ID: 171 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id171in_a = id483out_output[getCycle()%58];
    const HWOffsetFix<1,0,UNSIGNED> &id171in_b = id170out_result;

    HWOffsetFix<1,0,UNSIGNED> id171x_1;

    (id171x_1) = (and_fixed(id171in_a,id171in_b));
    id171out_result = (id171x_1);
  }
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 172 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id172in_enable = id171out_result;

    (id172st_read_next_cycle) = ((id172in_enable.getValueAsBool())&(!(((getFlushLevel())>=(64l))&(isFlushingActive()))));
    queueReadRequest(m_DRAM1003_void1055_in, id172st_read_next_cycle.getValueAsBool());
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id174out_output;

  { // Node ID: 174 (NodeReinterpret)
    const HWRawBits<32> &id174in_input = id172out_data;

    id174out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id174in_input));
  }
  { // Node ID: 493 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id493in_input = id483out_output[getCycle()%58];

    id493out_output[(getCycle()+5)%6] = id493in_input;
  }
  HWOffsetFix<32,5,TWOSCOMPLEMENT> id410out_output;

  { // Node ID: 410 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id410in_input = id194out_counter0;

    id410out_output = (cast_bits2fixed<32,5,TWOSCOMPLEMENT>((cast_fixed2bits(id410in_input))));
  }
  HWOffsetFix<32,6,TWOSCOMPLEMENT> id411out_output;

  { // Node ID: 411 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id411in_input = id194out_counter0;

    id411out_output = (cast_bits2fixed<32,6,TWOSCOMPLEMENT>((cast_fixed2bits(id411in_input))));
  }
  { // Node ID: 412 (NodeAdd)
    const HWOffsetFix<32,5,TWOSCOMPLEMENT> &id412in_a = id410out_output;
    const HWOffsetFix<32,6,TWOSCOMPLEMENT> &id412in_b = id411out_output;

    id412out_result[(getCycle()+1)%2] = (add_fixed<34,5,TWOSCOMPLEMENT,TONEAR>(id412in_a,id412in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id413out_o;

  { // Node ID: 413 (NodeCast)
    const HWOffsetFix<34,5,TWOSCOMPLEMENT> &id413in_i = id412out_result[getCycle()%2];

    id413out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id413in_i));
  }
  { // Node ID: 223 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id223in_a = id413out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id223in_b = id216out_counter0;

    id223out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id223in_a,id223in_b));
  }
  HWOffsetFix<14,0,UNSIGNED> id225out_o;

  { // Node ID: 225 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id225in_i = id223out_result[getCycle()%2];

    id225out_o = (cast_fixed2fixed<14,0,UNSIGNED,TONEAR>(id225in_i));
  }
  { // Node ID: 486 (NodeFIFO)
    const HWOffsetFix<14,0,UNSIGNED> &id486in_input = id225out_o;

    id486out_output[(getCycle()+64)%65] = id486in_input;
  }
  if ( (getFillLevel() >= (69l)))
  { // Node ID: 337 (NodeRAM)
    const bool id337_inputvalid = !(isFlushingActive() && getFlushLevel() >= (69l));
    const HWOffsetFix<14,0,UNSIGNED> &id337in_addrA = id484out_output[getCycle()%62];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id337in_dina = id174out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id337in_wea = id493out_output[getCycle()%6];
    const HWOffsetFix<14,0,UNSIGNED> &id337in_addrB = id486out_output[getCycle()%65];

    long id337x_1;
    long id337x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id337x_3;

    (id337x_1) = (id337in_addrA.getValueAsLong());
    (id337x_2) = (id337in_addrB.getValueAsLong());
    switch(((long)((id337x_2)<(9216l)))) {
      case 0l:
        id337x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id337x_3 = (id337sta_ram_store[(id337x_2)]);
        break;
      default:
        id337x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id337out_doutb[(getCycle()+2)%3] = (id337x_3);
    if(((id337in_wea.getValueAsBool())&id337_inputvalid)) {
      if(((id337x_1)<(9216l))) {
        (id337sta_ram_store[(id337x_1)]) = id337in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_1("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 337) on port A, ram depth is 9216.")));
      }
    }
  }
  HWRawBits<32> id287out_output;

  { // Node ID: 287 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id287in_input = id337out_doutb[getCycle()%3];

    id287out_output = (cast_fixed2bits(id287in_input));
  }
  if ( (getFillLevel() >= (71l)) && (getFlushLevel() < (71l)|| !isFlushingActive() ))
  { // Node ID: 286 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id286in_output_control = id487out_output[getCycle()%65];
    const HWRawBits<32> &id286in_data = id287out_output;

    bool id286x_1;

    (id286x_1) = ((id286in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(71l))&(isFlushingActive()))));
    if((id286x_1)) {
      writeOutput(m_DRAM1004_void1082_out, id286in_data);
    }
  }
  { // Node ID: 497 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id497in_input = id444out_output[getCycle()%2];

    id497out_output[(getCycle()+1)%2] = id497in_input;
  }
  { // Node ID: 501 (NodeConstantRawBits)
  }
  { // Node ID: 300 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id300in_a = id297out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id300in_b = id501out_value;

    id300out_result[(getCycle()+1)%2] = (eq_fixed(id300in_a,id300in_b));
  }
  { // Node ID: 301 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id301in_a = id497out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id301in_b = id300out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id301x_1;

    (id301x_1) = (and_fixed(id301in_a,id301in_b));
    id301out_result[(getCycle()+1)%2] = (id301x_1);
  }
  { // Node ID: 317 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id318out_result;

  { // Node ID: 318 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id318in_a = id317out_io_intrCmd_force_disabled;

    id318out_result = (not_fixed(id318in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id319out_result;

  { // Node ID: 319 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id319in_a = id301out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id319in_b = id318out_result;

    HWOffsetFix<1,0,UNSIGNED> id319x_1;

    (id319x_1) = (and_fixed(id319in_a,id319in_b));
    id319out_result = (id319x_1);
  }
  { // Node ID: 498 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id498in_input = id497out_output[getCycle()%2];

    id498out_output[(getCycle()+1)%2] = id498in_input;
  }
  HWRawBits<1> id328out_output;

  { // Node ID: 328 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id328in_input = id498out_output[getCycle()%2];

    id328out_output = (cast_fixed2bits(id328in_input));
  }
  { // Node ID: 392 (NodeConstantRawBits)
  }
  { // Node ID: 394 (NodeConstantRawBits)
  }
  HWRawBits<8> id324out_output;

  { // Node ID: 324 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id324in_input = id394out_value;

    id324out_output = (cast_fixed2bits(id324in_input));
  }
  { // Node ID: 396 (NodeConstantRawBits)
  }
  { // Node ID: 397 (NodeConstantRawBits)
  }
  HWRawBits<40> id323out_result;

  { // Node ID: 323 (NodeCat)
    const HWRawBits<8> &id323in_in0 = id396out_value;
    const HWRawBits<32> &id323in_in1 = id397out_value;

    id323out_result = (cat(id323in_in0,id323in_in1));
  }
  HWRawBits<48> id325out_result;

  { // Node ID: 325 (NodeCat)
    const HWRawBits<8> &id325in_in0 = id324out_output;
    const HWRawBits<40> &id325in_in1 = id323out_result;

    id325out_result = (cat(id325in_in0,id325in_in1));
  }
  HWRawBits<63> id327out_result;

  { // Node ID: 327 (NodeCat)
    const HWRawBits<15> &id327in_in0 = id392out_value;
    const HWRawBits<48> &id327in_in1 = id325out_result;

    id327out_result = (cat(id327in_in0,id327in_in1));
  }
  HWRawBits<64> id329out_result;

  { // Node ID: 329 (NodeCat)
    const HWRawBits<1> &id329in_in0 = id328out_output;
    const HWRawBits<63> &id329in_in1 = id327out_result;

    id329out_result = (cat(id329in_in0,id329in_in1));
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 320 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id320in_output_control = id319out_result;
    const HWRawBits<64> &id320in_data = id329out_result;

    bool id320x_1;

    (id320x_1) = ((id320in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id320x_1)) {
      writeOutput(m_intrCmd, id320in_data);
    }
  }
  { // Node ID: 330 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 331 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id331in_load = id330out_value;
    const HWOffsetFix<64,0,UNSIGNED> &id331in_data = id1out_cycles;

    bool id331x_1;

    (id331x_1) = ((id331in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id331x_1)) {
      setMappedRegValue("cycles", id331in_data);
    }
  }
  { // Node ID: 333 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id334out_result;

  { // Node ID: 334 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id334in_a = id333out_io_intrStream_force_disabled;

    id334out_result = (not_fixed(id334in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id335out_result;

  { // Node ID: 335 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id335in_a = id498out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id335in_b = id334out_result;

    HWOffsetFix<1,0,UNSIGNED> id335x_1;

    (id335x_1) = (and_fixed(id335in_a,id335in_b));
    id335out_result = (id335x_1);
  }
  { // Node ID: 332 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 336 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id336in_output_control = id335out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id336in_data = id332out_value;

    bool id336x_1;

    (id336x_1) = ((id336in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id336x_1)) {
      writeOutput(m_intrStream, id336in_data);
    }
  }
  { // Node ID: 342 (NodeConstantRawBits)
  }
  { // Node ID: 500 (NodeConstantRawBits)
  }
  { // Node ID: 339 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (70l)))
  { // Node ID: 340 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id340in_enable = id500out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id340in_max = id339out_value;

    HWOffsetFix<49,0,UNSIGNED> id340x_1;
    HWOffsetFix<1,0,UNSIGNED> id340x_2;
    HWOffsetFix<1,0,UNSIGNED> id340x_3;
    HWOffsetFix<49,0,UNSIGNED> id340x_4t_1e_1;

    id340out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id340st_count)));
    (id340x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id340st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id340x_2) = (gte_fixed((id340x_1),id340in_max));
    (id340x_3) = (and_fixed((id340x_2),id340in_enable));
    id340out_wrap = (id340x_3);
    if((id340in_enable.getValueAsBool())) {
      if(((id340x_3).getValueAsBool())) {
        (id340st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id340x_4t_1e_1) = (id340x_1);
        (id340st_count) = (id340x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id341out_output;

  { // Node ID: 341 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id341in_input = id340out_count;

    id341out_output = id341in_input;
  }
  if ( (getFillLevel() >= (71l)) && (getFlushLevel() < (71l)|| !isFlushingActive() ))
  { // Node ID: 343 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id343in_load = id342out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id343in_data = id341out_output;

    bool id343x_1;

    (id343x_1) = ((id343in_load.getValueAsBool())&(!(((getFlushLevel())>=(71l))&(isFlushingActive()))));
    if((id343x_1)) {
      setMappedRegValue("current_run_cycle_count", id343in_data);
    }
  }
  { // Node ID: 499 (NodeConstantRawBits)
  }
  { // Node ID: 345 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 346 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id346in_enable = id499out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id346in_max = id345out_value;

    HWOffsetFix<49,0,UNSIGNED> id346x_1;
    HWOffsetFix<1,0,UNSIGNED> id346x_2;
    HWOffsetFix<1,0,UNSIGNED> id346x_3;
    HWOffsetFix<49,0,UNSIGNED> id346x_4t_1e_1;

    id346out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id346st_count)));
    (id346x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id346st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id346x_2) = (gte_fixed((id346x_1),id346in_max));
    (id346x_3) = (and_fixed((id346x_2),id346in_enable));
    id346out_wrap = (id346x_3);
    if((id346in_enable.getValueAsBool())) {
      if(((id346x_3).getValueAsBool())) {
        (id346st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id346x_4t_1e_1) = (id346x_1);
        (id346st_count) = (id346x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 348 (NodeInputMappedReg)
  }
  { // Node ID: 349 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id349in_a = id346out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id349in_b = id348out_run_cycle_count;

    id349out_result[(getCycle()+1)%2] = (eq_fixed(id349in_a,id349in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 347 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id347in_start = id349out_result[getCycle()%2];

    if((id347in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
