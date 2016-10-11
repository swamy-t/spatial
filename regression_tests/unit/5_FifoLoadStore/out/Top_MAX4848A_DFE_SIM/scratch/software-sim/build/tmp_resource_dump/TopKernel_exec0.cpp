#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "TopKernel.h"

namespace maxcompilersim {

void TopKernel::execute0() {
  { // Node ID: 269 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id39out_output;

  { // Node ID: 39 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id39in_input = id38out_result[getCycle()%2];

    id39out_output = id39in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id19out_output;

  { // Node ID: 19 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id19in_input = id238out_output[getCycle()%2];

    id19out_output = id19in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id96out_output;

  { // Node ID: 96 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id96in_input = id95out_result[getCycle()%2];

    id96out_output = id96in_input;
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 84 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id84in_memDone = id96out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id84in_sm_en = id239out_output[getCycle()%2];

    m_sm_DRAM1038_void1082_outldSM.inputdata_memDone = id84in_memDone.getBitString();
    m_sm_DRAM1038_void1082_outldSM.inputdata_sm_en = id84in_sm_en.getBitString();
    m_sm_DRAM1038_void1082_outldSM.execute(true);
    id84out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1038_void1082_outldSM.outputdata_memStart));
    id84out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1038_void1082_outldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id85out_output;

  { // Node ID: 85 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id85in_input = id84out_sm_done;

    id85out_output = id85in_input;
  }
  { // Node ID: 81 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 79 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id79in_s0_done = id85out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id79in_sm_en = id240out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id79in_sm_numIter = id81out_value;

    m_sm_void1084_sm.inputdata_s0_done = id79in_s0_done.getBitString();
    m_sm_void1084_sm.inputdata_sm_en = id79in_sm_en.getBitString();
    m_sm_void1084_sm.inputdata_sm_numIter = id79in_sm_numIter.getBitString();
    m_sm_void1084_sm.execute(true);
    id79out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1084_sm.outputdata_rst_en));
    id79out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1084_sm.outputdata_s0_en));
    id79out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1084_sm.outputdata_sm_done));
    id79out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1084_sm.outputdata_sm_last));
  }
  HWOffsetFix<1,0,UNSIGNED> id80out_output;

  { // Node ID: 80 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id80in_input = id79out_sm_done;

    id80out_output = id80in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id14out_output;

  { // Node ID: 14 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id14in_input = id241out_output[getCycle()%2];

    id14out_output = id14in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id237out_output;

  { // Node ID: 237 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id237in_input = id244out_output[getCycle()%2];

    id237out_output = id237in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id12out_output;

  { // Node ID: 12 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id12in_input = id245out_output[getCycle()%2];

    id12out_output = id12in_input;
  }
  { // Node ID: 265 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 142 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id142in_enable = id246out_output[getCycle()%2];
    const HWOffsetFix<33,0,UNSIGNED> &id142in_max = id265out_value;

    HWOffsetFix<33,0,UNSIGNED> id142x_1;
    HWOffsetFix<1,0,UNSIGNED> id142x_2;
    HWOffsetFix<1,0,UNSIGNED> id142x_3;
    HWOffsetFix<33,0,UNSIGNED> id142x_4t_1e_1;

    id142out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id142st_count)));
    (id142x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id142st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id142x_2) = (gte_fixed((id142x_1),id142in_max));
    (id142x_3) = (and_fixed((id142x_2),id142in_enable));
    id142out_wrap = (id142x_3);
    if((id142in_enable.getValueAsBool())) {
      if(((id142x_3).getValueAsBool())) {
        (id142st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id142x_4t_1e_1) = (id142x_1);
        (id142st_count) = (id142x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id143out_output;

  { // Node ID: 143 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id143in_input = id142out_wrap;

    id143out_output = id143in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id7out_output;

  { // Node ID: 7 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id7in_input = id247out_output[getCycle()%2];

    id7out_output = id7in_input;
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_intr_done = id143out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id1in_run_done = id7out_output;
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
  { // Node ID: 8 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 6 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id6in_s0_done = id12out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id6in_sm_en = id1out_run_en;
    const HWOffsetFix<32,0,UNSIGNED> &id6in_sm_numIter = id8out_value;

    m_sm_void1095_sm.inputdata_s0_done = id6in_s0_done.getBitString();
    m_sm_void1095_sm.inputdata_sm_en = id6in_sm_en.getBitString();
    m_sm_void1095_sm.inputdata_sm_numIter = id6in_sm_numIter.getBitString();
    m_sm_void1095_sm.execute(true);
    id6out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1095_sm.outputdata_rst_en));
    id6out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1095_sm.outputdata_s0_en));
    id6out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1095_sm.outputdata_sm_done));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 11 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id11in_s0_done = id14out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id11in_s1_done = id237out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id11in_sm_en = id6out_s0_en;

    m_sm_void1093_sm.inputdata_s0_done = id11in_s0_done.getBitString();
    m_sm_void1093_sm.inputdata_s1_done = id11in_s1_done.getBitString();
    m_sm_void1093_sm.inputdata_sm_en = id11in_sm_en.getBitString();
    m_sm_void1093_sm.execute(true);
    id11out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1093_sm.outputdata_s0_en));
    id11out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1093_sm.outputdata_s1_en));
    id11out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1093_sm.outputdata_sm_done));
  }
  { // Node ID: 15 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 13 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id13in_s0_done = id19out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id13in_s1_done = id80out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id13in_sm_en = id11out_s0_en;
    const HWOffsetFix<32,0,UNSIGNED> &id13in_sm_numIter = id15out_value;

    m_sm_void1086_sm.inputdata_s0_done = id13in_s0_done.getBitString();
    m_sm_void1086_sm.inputdata_s1_done = id13in_s1_done.getBitString();
    m_sm_void1086_sm.inputdata_sm_en = id13in_sm_en.getBitString();
    m_sm_void1086_sm.inputdata_sm_numIter = id13in_sm_numIter.getBitString();
    m_sm_void1086_sm.execute(true);
    id13out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1086_sm.outputdata_rst_en));
    id13out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1086_sm.outputdata_s0_en));
    id13out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1086_sm.outputdata_s1_en));
    id13out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1086_sm.outputdata_sm_done));
  }
  { // Node ID: 20 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 18 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id18in_s0_done = id248out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id18in_sm_en = id13out_s0_en;
    const HWOffsetFix<32,0,UNSIGNED> &id18in_sm_numIter = id20out_value;

    m_sm_void1081_sm.inputdata_s0_done = id18in_s0_done.getBitString();
    m_sm_void1081_sm.inputdata_sm_en = id18in_sm_en.getBitString();
    m_sm_void1081_sm.inputdata_sm_numIter = id18in_sm_numIter.getBitString();
    m_sm_void1081_sm.execute(true);
    id18out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1081_sm.outputdata_rst_en));
    id18out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1081_sm.outputdata_s0_en));
    id18out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1081_sm.outputdata_sm_done));
    id18out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1081_sm.outputdata_sm_last));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 26 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id26in_memDone = id39out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id26in_sm_en = id18out_s0_en;

    m_sm_DRAM1037_void1079_inldSM.inputdata_memDone = id26in_memDone.getBitString();
    m_sm_DRAM1037_void1079_inldSM.inputdata_sm_en = id26in_sm_en.getBitString();
    m_sm_DRAM1037_void1079_inldSM.execute(true);
    id26out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1037_void1079_inldSM.outputdata_memStart));
    id26out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1037_void1079_inldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id27out_output;

  { // Node ID: 27 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id27in_input = id26out_sm_done;

    id27out_output = id27in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id34out_output;

  { // Node ID: 34 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id34in_input = id27out_output;

    id34out_output = id34in_input;
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 36 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id36in_enable = id26out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id36in_max = id269out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id36in_userReset = id34out_output;

    HWOffsetFix<17,0,UNSIGNED> id36x_1;
    HWOffsetFix<1,0,UNSIGNED> id36x_2;
    HWOffsetFix<1,0,UNSIGNED> id36x_3;
    HWOffsetFix<1,0,UNSIGNED> id36x_4;
    HWOffsetFix<17,0,UNSIGNED> id36x_5e_1t_1e_1;

    id36out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id36st_count)));
    (id36x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id36st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id36x_2) = (gt_fixed((id36x_1),id36in_max));
    (id36x_3) = (and_fixed(id36in_enable,(not_fixed((id36x_2)))));
    (id36x_4) = (c_hw_fix_1_0_uns_bits);
    id36out_wrap = (id36x_4);
    if((id36in_userReset.getValueAsBool())) {
      (id36st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id36x_3).getValueAsBool())) {
        if(((id36x_4).getValueAsBool())) {
          (id36st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id36x_5e_1t_1e_1) = (id36x_1);
          (id36st_count) = (id36x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 268 (NodeConstantRawBits)
  }
  { // Node ID: 38 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id38in_a = id36out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id38in_b = id268out_value;

    id38out_result[(getCycle()+1)%2] = (eq_fixed(id38in_a,id38in_b));
  }
  { // Node ID: 248 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id248in_input = id27out_output;

    id248out_output[(getCycle()+1)%2] = id248in_input;
  }
  { // Node ID: 238 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id238in_input = id18out_sm_done;

    id238out_output[(getCycle()+1)%2] = id238in_input;
  }
  { // Node ID: 267 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id91out_output;

  { // Node ID: 91 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id91in_input = id85out_output;

    id91out_output = id91in_input;
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 93 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id93in_enable = id84out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id93in_max = id267out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id93in_userReset = id91out_output;

    HWOffsetFix<17,0,UNSIGNED> id93x_1;
    HWOffsetFix<1,0,UNSIGNED> id93x_2;
    HWOffsetFix<1,0,UNSIGNED> id93x_3;
    HWOffsetFix<1,0,UNSIGNED> id93x_4;
    HWOffsetFix<17,0,UNSIGNED> id93x_5e_1t_1e_1;

    id93out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id93st_count)));
    (id93x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id93st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id93x_2) = (gt_fixed((id93x_1),id93in_max));
    (id93x_3) = (and_fixed(id93in_enable,(not_fixed((id93x_2)))));
    (id93x_4) = (c_hw_fix_1_0_uns_bits);
    id93out_wrap = (id93x_4);
    if((id93in_userReset.getValueAsBool())) {
      (id93st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id93x_3).getValueAsBool())) {
        if(((id93x_4).getValueAsBool())) {
          (id93st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id93x_5e_1t_1e_1) = (id93x_1);
          (id93st_count) = (id93x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 266 (NodeConstantRawBits)
  }
  { // Node ID: 95 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id95in_a = id93out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id95in_b = id266out_value;

    id95out_result[(getCycle()+1)%2] = (eq_fixed(id95in_a,id95in_b));
  }
  { // Node ID: 239 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id239in_input = id79out_s0_en;

    id239out_output[(getCycle()+1)%2] = id239in_input;
  }
  { // Node ID: 240 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id240in_input = id13out_s1_en;

    id240out_output[(getCycle()+1)%2] = id240in_input;
  }
  { // Node ID: 241 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id241in_input = id13out_sm_done;

    id241out_output[(getCycle()+1)%2] = id241in_input;
  }
  { // Node ID: 2 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id138out_output;

  { // Node ID: 138 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id138in_input = id242out_output[getCycle()%2];

    id138out_output = id138in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id236out_output;

  { // Node ID: 236 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id236in_input = id243out_output[getCycle()%2];

    id236out_output = id236in_input;
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 134 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id134in_ctr_done = id138out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id134in_rst_done = id236out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id134in_sm_en = id11out_s1_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id134in_sm_maxIn_0 = id2out_value;

    m_sm_pipe1091_sm.inputdata_ctr_done = id134in_ctr_done.getBitString();
    m_sm_pipe1091_sm.inputdata_rst_done = id134in_rst_done.getBitString();
    m_sm_pipe1091_sm.inputdata_sm_en = id134in_sm_en.getBitString();
    m_sm_pipe1091_sm.inputdata_sm_maxIn_0 = id134in_sm_maxIn_0.getBitString();
    m_sm_pipe1091_sm.execute(true);
    id134out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1091_sm.outputdata_ctr_en));
    id134out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe1091_sm.outputdata_ctr_maxOut_0) ));
    id134out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1091_sm.outputdata_rst_en));
    id134out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1091_sm.outputdata_sm_done));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 137 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id137in_en = id134out_ctr_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id137in_max0 = id2out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id137in_reset = id237out_output;

    m_sm_CounterChain1088_sm.inputdata_en = id137in_en.getBitString();
    m_sm_CounterChain1088_sm.inputdata_max0 = id137in_max0.getBitString();
    m_sm_CounterChain1088_sm.inputdata_reset = id137in_reset.getBitString();
    m_sm_CounterChain1088_sm.execute(true);
    id137out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1088_sm.outputdata_counter0) ));
    id137out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1088_sm.outputdata_done));
    id137out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1088_sm.outputdata_saturated));
  }
  { // Node ID: 242 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id242in_input = id137out_done;

    id242out_output[(getCycle()+1)%2] = id242in_input;
  }
  { // Node ID: 243 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id243in_input = id134out_rst_en;

    id243out_output[(getCycle()+1)%2] = id243in_input;
  }
  { // Node ID: 244 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id244in_input = id134out_sm_done;

    id244out_output[(getCycle()+1)%2] = id244in_input;
  }
  { // Node ID: 245 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id245in_input = id11out_sm_done;

    id245out_output[(getCycle()+1)%2] = id245in_input;
  }
  { // Node ID: 246 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id246in_input = id1out_intr_en;

    id246out_output[(getCycle()+1)%2] = id246in_input;
  }
  { // Node ID: 247 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id247in_input = id6out_sm_done;

    id247out_output[(getCycle()+1)%2] = id247in_input;
  }
  { // Node ID: 249 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id249in_input = id26out_memStart;

    id249out_output[(getCycle()+1)%2] = id249in_input;
  }
  { // Node ID: 264 (NodeConstantRawBits)
  }
  { // Node ID: 41 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id41in_a = id36out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id41in_b = id264out_value;

    id41out_result[(getCycle()+1)%2] = (eq_fixed(id41in_a,id41in_b));
  }
  { // Node ID: 42 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id42in_a = id249out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id42in_b = id41out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id42x_1;

    (id42x_1) = (and_fixed(id42in_a,id42in_b));
    id42out_result[(getCycle()+1)%2] = (id42x_1);
  }
  { // Node ID: 60 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id61out_result;

  { // Node ID: 61 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id61in_a = id60out_io_DRAM1037_void1079_in_cmd_force_disabled;

    id61out_result = (not_fixed(id61in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id62out_result;

  { // Node ID: 62 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id62in_a = id42out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id62in_b = id61out_result;

    HWOffsetFix<1,0,UNSIGNED> id62x_1;

    (id62x_1) = (and_fixed(id62in_a,id62in_b));
    id62out_result = (id62x_1);
  }
  { // Node ID: 194 (NodeConstantRawBits)
  }
  { // Node ID: 199 (NodeConstantRawBits)
  }
  { // Node ID: 47 (NodeConstantRawBits)
  }
  HWRawBits<8> id67out_output;

  { // Node ID: 67 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id67in_input = id47out_value;

    id67out_output = (cast_fixed2bits(id67in_input));
  }
  { // Node ID: 204 (NodeConstantRawBits)
  }
  { // Node ID: 208 (NodeConstantRawBits)
  }
  HWRawBits<40> id66out_result;

  { // Node ID: 66 (NodeCat)
    const HWRawBits<8> &id66in_in0 = id204out_value;
    const HWRawBits<32> &id66in_in1 = id208out_value;

    id66out_result = (cat(id66in_in0,id66in_in1));
  }
  HWRawBits<48> id68out_result;

  { // Node ID: 68 (NodeCat)
    const HWRawBits<8> &id68in_in0 = id67out_output;
    const HWRawBits<40> &id68in_in1 = id66out_result;

    id68out_result = (cat(id68in_in0,id68in_in1));
  }
  HWRawBits<63> id70out_result;

  { // Node ID: 70 (NodeCat)
    const HWRawBits<15> &id70in_in0 = id199out_value;
    const HWRawBits<48> &id70in_in1 = id68out_result;

    id70out_result = (cat(id70in_in0,id70in_in1));
  }
  HWRawBits<64> id72out_result;

  { // Node ID: 72 (NodeCat)
    const HWRawBits<1> &id72in_in0 = id194out_value;
    const HWRawBits<63> &id72in_in1 = id70out_result;

    id72out_result = (cat(id72in_in0,id72in_in1));
  }
  if ( (getFillLevel() >= (6l)) && (getFlushLevel() < (6l)|| !isFlushingActive() ))
  { // Node ID: 63 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id63in_output_control = id62out_result;
    const HWRawBits<64> &id63in_data = id72out_result;

    bool id63x_1;

    (id63x_1) = ((id63in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(6l))&(isFlushingActive()))));
    if((id63x_1)) {
      writeOutput(m_DRAM1037_void1079_in_cmd, id63in_data);
    }
  }
  { // Node ID: 250 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id250in_input = id84out_memStart;

    id250out_output[(getCycle()+1)%2] = id250in_input;
  }
  { // Node ID: 263 (NodeConstantRawBits)
  }
  { // Node ID: 98 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id98in_a = id93out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id98in_b = id263out_value;

    id98out_result[(getCycle()+1)%2] = (eq_fixed(id98in_a,id98in_b));
  }
  { // Node ID: 99 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id99in_a = id250out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id99in_b = id98out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id99x_1;

    (id99x_1) = (and_fixed(id99in_a,id99in_b));
    id99out_result[(getCycle()+1)%2] = (id99x_1);
  }
  { // Node ID: 116 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id117out_result;

  { // Node ID: 117 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id117in_a = id116out_io_DRAM1038_void1082_out_cmd_force_disabled;

    id117out_result = (not_fixed(id117in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id118out_result;

  { // Node ID: 118 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id118in_a = id99out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id118in_b = id117out_result;

    HWOffsetFix<1,0,UNSIGNED> id118x_1;

    (id118x_1) = (and_fixed(id118in_a,id118in_b));
    id118out_result = (id118x_1);
  }
  { // Node ID: 209 (NodeConstantRawBits)
  }
  { // Node ID: 214 (NodeConstantRawBits)
  }
  { // Node ID: 103 (NodeConstantRawBits)
  }
  HWRawBits<8> id123out_output;

  { // Node ID: 123 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id123in_input = id103out_value;

    id123out_output = (cast_fixed2bits(id123in_input));
  }
  { // Node ID: 219 (NodeConstantRawBits)
  }
  { // Node ID: 223 (NodeConstantRawBits)
  }
  HWRawBits<40> id122out_result;

  { // Node ID: 122 (NodeCat)
    const HWRawBits<8> &id122in_in0 = id219out_value;
    const HWRawBits<32> &id122in_in1 = id223out_value;

    id122out_result = (cat(id122in_in0,id122in_in1));
  }
  HWRawBits<48> id124out_result;

  { // Node ID: 124 (NodeCat)
    const HWRawBits<8> &id124in_in0 = id123out_output;
    const HWRawBits<40> &id124in_in1 = id122out_result;

    id124out_result = (cat(id124in_in0,id124in_in1));
  }
  HWRawBits<63> id126out_result;

  { // Node ID: 126 (NodeCat)
    const HWRawBits<15> &id126in_in0 = id214out_value;
    const HWRawBits<48> &id126in_in1 = id124out_result;

    id126out_result = (cat(id126in_in0,id126in_in1));
  }
  HWRawBits<64> id128out_result;

  { // Node ID: 128 (NodeCat)
    const HWRawBits<1> &id128in_in0 = id209out_value;
    const HWRawBits<63> &id128in_in1 = id126out_result;

    id128out_result = (cat(id128in_in0,id128in_in1));
  }
  if ( (getFillLevel() >= (8l)) && (getFlushLevel() < (8l)|| !isFlushingActive() ))
  { // Node ID: 119 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id119in_output_control = id118out_result;
    const HWRawBits<64> &id119in_data = id128out_result;

    bool id119x_1;

    (id119x_1) = ((id119in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(8l))&(isFlushingActive()))));
    if((id119x_1)) {
      writeOutput(m_DRAM1038_void1082_out_cmd, id119in_data);
    }
  }
  { // Node ID: 251 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id251in_input = id18out_s0_en;

    id251out_output[(getCycle()+1)%2] = id251in_input;
  }
  { // Node ID: 129 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id130out_result;

  { // Node ID: 130 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id130in_a = id129out_io_DRAM1038_void1082_out_force_disabled;

    id130out_result = (not_fixed(id130in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id131out_result;

  { // Node ID: 131 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id131in_a = id251out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id131in_b = id130out_result;

    HWOffsetFix<1,0,UNSIGNED> id131x_1;

    (id131x_1) = (and_fixed(id131in_a,id131in_b));
    id131out_result = (id131x_1);
  }
  { // Node ID: 254 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id254in_input = id131out_result;

    id254out_output[(getCycle()+22)%23] = id254in_input;
  }
  { // Node ID: 73 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id74out_result;

  { // Node ID: 74 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id74in_a = id73out_io_DRAM1037_void1079_in_force_disabled;

    id74out_result = (not_fixed(id74in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id75out_result;

  { // Node ID: 75 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id75in_a = id239out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id75in_b = id74out_result;

    HWOffsetFix<1,0,UNSIGNED> id75x_1;

    (id75x_1) = (and_fixed(id75in_a,id75in_b));
    id75out_result = (id75x_1);
  }
  { // Node ID: 253 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id253in_input = id75out_result;

    id253out_output[(getCycle()+16)%17] = id253in_input;
  }
  if ( (getFillLevel() >= (22l)))
  { // Node ID: 76 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id76in_enable = id253out_output[getCycle()%17];

    (id76st_read_next_cycle) = ((id76in_enable.getValueAsBool())&(!(((getFlushLevel())>=(22l))&(isFlushingActive()))));
    queueReadRequest(m_DRAM1037_void1079_in, id76st_read_next_cycle.getValueAsBool());
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id78out_output;

  { // Node ID: 78 (NodeReinterpret)
    const HWRawBits<32> &id78in_input = id76out_data;

    id78out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id78in_input));
  }
  HWRawBits<32> id133out_output;

  { // Node ID: 133 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id133in_input = id78out_output;

    id133out_output = (cast_fixed2bits(id133in_input));
  }
  if ( (getFillLevel() >= (27l)) && (getFlushLevel() < (27l)|| !isFlushingActive() ))
  { // Node ID: 132 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id132in_output_control = id254out_output[getCycle()%23];
    const HWRawBits<32> &id132in_data = id133out_output;

    bool id132x_1;

    (id132x_1) = ((id132in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(27l))&(isFlushingActive()))));
    if((id132x_1)) {
      writeOutput(m_DRAM1038_void1082_out, id132in_data);
    }
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 140 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id140in_load = id7out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id140in_data = id137out_counter0;

    bool id140x_1;

    (id140x_1) = ((id140in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id140x_1)) {
      setMappedRegValue("argout1039", id140in_data);
    }
  }
  { // Node ID: 259 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id259in_input = id246out_output[getCycle()%2];

    id259out_output[(getCycle()+1)%2] = id259in_input;
  }
  { // Node ID: 262 (NodeConstantRawBits)
  }
  { // Node ID: 145 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id145in_a = id142out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id145in_b = id262out_value;

    id145out_result[(getCycle()+1)%2] = (eq_fixed(id145in_a,id145in_b));
  }
  { // Node ID: 146 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id146in_a = id259out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id146in_b = id145out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id146x_1;

    (id146x_1) = (and_fixed(id146in_a,id146in_b));
    id146out_result[(getCycle()+1)%2] = (id146x_1);
  }
  { // Node ID: 162 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id163out_result;

  { // Node ID: 163 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id163in_a = id162out_io_intrCmd_force_disabled;

    id163out_result = (not_fixed(id163in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id164out_result;

  { // Node ID: 164 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id164in_a = id146out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id164in_b = id163out_result;

    HWOffsetFix<1,0,UNSIGNED> id164x_1;

    (id164x_1) = (and_fixed(id164in_a,id164in_b));
    id164out_result = (id164x_1);
  }
  HWRawBits<1> id173out_output;

  { // Node ID: 173 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id173in_input = id259out_output[getCycle()%2];

    id173out_output = (cast_fixed2bits(id173in_input));
  }
  { // Node ID: 257 (NodeFIFO)
    const HWRawBits<1> &id257in_input = id173out_output;

    id257out_output[(getCycle()+1)%2] = id257in_input;
  }
  { // Node ID: 228 (NodeConstantRawBits)
  }
  { // Node ID: 230 (NodeConstantRawBits)
  }
  HWRawBits<8> id169out_output;

  { // Node ID: 169 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id169in_input = id230out_value;

    id169out_output = (cast_fixed2bits(id169in_input));
  }
  { // Node ID: 232 (NodeConstantRawBits)
  }
  { // Node ID: 233 (NodeConstantRawBits)
  }
  HWRawBits<40> id168out_result;

  { // Node ID: 168 (NodeCat)
    const HWRawBits<8> &id168in_in0 = id232out_value;
    const HWRawBits<32> &id168in_in1 = id233out_value;

    id168out_result = (cat(id168in_in0,id168in_in1));
  }
  HWRawBits<48> id170out_result;

  { // Node ID: 170 (NodeCat)
    const HWRawBits<8> &id170in_in0 = id169out_output;
    const HWRawBits<40> &id170in_in1 = id168out_result;

    id170out_result = (cat(id170in_in0,id170in_in1));
  }
  HWRawBits<63> id172out_result;

  { // Node ID: 172 (NodeCat)
    const HWRawBits<15> &id172in_in0 = id228out_value;
    const HWRawBits<48> &id172in_in1 = id170out_result;

    id172out_result = (cat(id172in_in0,id172in_in1));
  }
  HWRawBits<64> id174out_result;

  { // Node ID: 174 (NodeCat)
    const HWRawBits<1> &id174in_in0 = id257out_output[getCycle()%2];
    const HWRawBits<63> &id174in_in1 = id172out_result;

    id174out_result = (cat(id174in_in0,id174in_in1));
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 165 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id165in_output_control = id164out_result;
    const HWRawBits<64> &id165in_data = id174out_result;

    bool id165x_1;

    (id165x_1) = ((id165in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id165x_1)) {
      writeOutput(m_intrCmd, id165in_data);
    }
  }
  { // Node ID: 175 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 176 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id176in_load = id175out_value;
    const HWOffsetFix<64,0,UNSIGNED> &id176in_data = id1out_cycles;

    bool id176x_1;

    (id176x_1) = ((id176in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id176x_1)) {
      setMappedRegValue("cycles", id176in_data);
    }
  }
  { // Node ID: 178 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id179out_result;

  { // Node ID: 179 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id179in_a = id178out_io_intrStream_force_disabled;

    id179out_result = (not_fixed(id179in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id180out_result;

  { // Node ID: 180 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id180in_a = id246out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id180in_b = id179out_result;

    HWOffsetFix<1,0,UNSIGNED> id180x_1;

    (id180x_1) = (and_fixed(id180in_a,id180in_b));
    id180out_result = (id180x_1);
  }
  { // Node ID: 177 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)) && (getFlushLevel() < (5l)|| !isFlushingActive() ))
  { // Node ID: 181 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id181in_output_control = id180out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id181in_data = id177out_value;

    bool id181x_1;

    (id181x_1) = ((id181in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(5l))&(isFlushingActive()))));
    if((id181x_1)) {
      writeOutput(m_intrStream, id181in_data);
    }
  }
  { // Node ID: 186 (NodeConstantRawBits)
  }
  { // Node ID: 261 (NodeConstantRawBits)
  }
  { // Node ID: 183 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (26l)))
  { // Node ID: 184 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id184in_enable = id261out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id184in_max = id183out_value;

    HWOffsetFix<49,0,UNSIGNED> id184x_1;
    HWOffsetFix<1,0,UNSIGNED> id184x_2;
    HWOffsetFix<1,0,UNSIGNED> id184x_3;
    HWOffsetFix<49,0,UNSIGNED> id184x_4t_1e_1;

    id184out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id184st_count)));
    (id184x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id184st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id184x_2) = (gte_fixed((id184x_1),id184in_max));
    (id184x_3) = (and_fixed((id184x_2),id184in_enable));
    id184out_wrap = (id184x_3);
    if((id184in_enable.getValueAsBool())) {
      if(((id184x_3).getValueAsBool())) {
        (id184st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id184x_4t_1e_1) = (id184x_1);
        (id184st_count) = (id184x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id185out_output;

  { // Node ID: 185 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id185in_input = id184out_count;

    id185out_output = id185in_input;
  }
  if ( (getFillLevel() >= (27l)) && (getFlushLevel() < (27l)|| !isFlushingActive() ))
  { // Node ID: 187 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id187in_load = id186out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id187in_data = id185out_output;

    bool id187x_1;

    (id187x_1) = ((id187in_load.getValueAsBool())&(!(((getFlushLevel())>=(27l))&(isFlushingActive()))));
    if((id187x_1)) {
      setMappedRegValue("current_run_cycle_count", id187in_data);
    }
  }
  { // Node ID: 260 (NodeConstantRawBits)
  }
  { // Node ID: 189 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 190 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id190in_enable = id260out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id190in_max = id189out_value;

    HWOffsetFix<49,0,UNSIGNED> id190x_1;
    HWOffsetFix<1,0,UNSIGNED> id190x_2;
    HWOffsetFix<1,0,UNSIGNED> id190x_3;
    HWOffsetFix<49,0,UNSIGNED> id190x_4t_1e_1;

    id190out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id190st_count)));
    (id190x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id190st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id190x_2) = (gte_fixed((id190x_1),id190in_max));
    (id190x_3) = (and_fixed((id190x_2),id190in_enable));
    id190out_wrap = (id190x_3);
    if((id190in_enable.getValueAsBool())) {
      if(((id190x_3).getValueAsBool())) {
        (id190st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id190x_4t_1e_1) = (id190x_1);
        (id190st_count) = (id190x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 192 (NodeInputMappedReg)
  }
  { // Node ID: 193 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id193in_a = id190out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id193in_b = id192out_run_cycle_count;

    id193out_result[(getCycle()+1)%2] = (eq_fixed(id193in_a,id193in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 191 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id191in_start = id193out_result[getCycle()%2];

    if((id191in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
