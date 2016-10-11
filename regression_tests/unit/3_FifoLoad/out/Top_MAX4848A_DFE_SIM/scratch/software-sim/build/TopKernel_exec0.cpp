#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "TopKernel.h"

namespace maxcompilersim {

void TopKernel::execute0() {
  { // Node ID: 290 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id43out_output;

  { // Node ID: 43 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id43in_input = id42out_result[getCycle()%2];

    id43out_output = id43in_input;
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 30 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id30in_memDone = id43out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id30in_sm_en = id263out_output[getCycle()%2];

    m_sm_DRAM1133_void1177_inldSM.inputdata_memDone = id30in_memDone.getBitString();
    m_sm_DRAM1133_void1177_inldSM.inputdata_sm_en = id30in_sm_en.getBitString();
    m_sm_DRAM1133_void1177_inldSM.execute(true);
    id30out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1133_void1177_inldSM.outputdata_memStart));
    id30out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1133_void1177_inldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id31out_output;

  { // Node ID: 31 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id31in_input = id30out_sm_done;

    id31out_output = id31in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id38out_output;

  { // Node ID: 38 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id38in_input = id31out_output;

    id38out_output = id38in_input;
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 40 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id40in_enable = id30out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id40in_max = id290out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id40in_userReset = id38out_output;

    HWOffsetFix<17,0,UNSIGNED> id40x_1;
    HWOffsetFix<1,0,UNSIGNED> id40x_2;
    HWOffsetFix<1,0,UNSIGNED> id40x_3;
    HWOffsetFix<1,0,UNSIGNED> id40x_4;
    HWOffsetFix<17,0,UNSIGNED> id40x_5e_1t_1e_1;

    id40out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id40st_count)));
    (id40x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id40st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id40x_2) = (gt_fixed((id40x_1),id40in_max));
    (id40x_3) = (and_fixed(id40in_enable,(not_fixed((id40x_2)))));
    (id40x_4) = (c_hw_fix_1_0_uns_bits);
    id40out_wrap = (id40x_4);
    if((id40in_userReset.getValueAsBool())) {
      (id40st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id40x_3).getValueAsBool())) {
        if(((id40x_4).getValueAsBool())) {
          (id40st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id40x_5e_1t_1e_1) = (id40x_1);
          (id40st_count) = (id40x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 289 (NodeConstantRawBits)
  }
  { // Node ID: 42 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id42in_a = id40out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id42in_b = id289out_value;

    id42out_result[(getCycle()+1)%2] = (eq_fixed(id42in_a,id42in_b));
  }
  { // Node ID: 24 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 22 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id22in_s0_done = id31out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id22in_sm_en = id262out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id22in_sm_numIter = id24out_value;

    m_sm_void1179_sm.inputdata_s0_done = id22in_s0_done.getBitString();
    m_sm_void1179_sm.inputdata_sm_en = id22in_sm_en.getBitString();
    m_sm_void1179_sm.inputdata_sm_numIter = id22in_sm_numIter.getBitString();
    m_sm_void1179_sm.execute(true);
    id22out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1179_sm.outputdata_rst_en));
    id22out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1179_sm.outputdata_s0_en));
    id22out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1179_sm.outputdata_sm_done));
    id22out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1179_sm.outputdata_sm_last));
  }
  HWOffsetFix<1,0,UNSIGNED> id23out_output;

  { // Node ID: 23 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id23in_input = id22out_sm_done;

    id23out_output = id23in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id87out_output;

  { // Node ID: 87 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id87in_input = id250out_output[getCycle()%2];

    id87out_output = id87in_input;
  }
  { // Node ID: 4 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (59l)))
  { // Node ID: 83 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id83in_ctr_done = id87out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id83in_rst_done = id251out_output[getCycle()%55];
    const HWOffsetFix<1,0,UNSIGNED> &id83in_sm_en = id252out_output[getCycle()%55];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id83in_sm_maxIn_0 = id4out_value;

    m_sm_pipe1188_sm.inputdata_ctr_done = id83in_ctr_done.getBitString();
    m_sm_pipe1188_sm.inputdata_rst_done = id83in_rst_done.getBitString();
    m_sm_pipe1188_sm.inputdata_sm_en = id83in_sm_en.getBitString();
    m_sm_pipe1188_sm.inputdata_sm_maxIn_0 = id83in_sm_maxIn_0.getBitString();
    m_sm_pipe1188_sm.execute(true);
    id83out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1188_sm.outputdata_ctr_en));
    id83out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe1188_sm.outputdata_ctr_maxOut_0) ));
    id83out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1188_sm.outputdata_rst_en));
    id83out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1188_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id246out_output;

  { // Node ID: 246 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id246in_input = id83out_sm_done;

    id246out_output = id246in_input;
  }
  { // Node ID: 249 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id249in_input = id246out_output;

    id249out_output[(getCycle()+54)%55] = id249in_input;
  }
  if ( (getFillLevel() >= (59l)))
  { // Node ID: 86 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id86in_en = id83out_ctr_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id86in_max0 = id83out_ctr_maxOut_0;
    const HWOffsetFix<1,0,UNSIGNED> &id86in_reset = id249out_output[getCycle()%55];

    m_sm_CounterChain1182_sm.inputdata_en = id86in_en.getBitString();
    m_sm_CounterChain1182_sm.inputdata_max0 = id86in_max0.getBitString();
    m_sm_CounterChain1182_sm.inputdata_reset = id86in_reset.getBitString();
    m_sm_CounterChain1182_sm.execute(true);
    id86out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1182_sm.outputdata_counter0) ));
    id86out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1182_sm.outputdata_done));
    id86out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1182_sm.outputdata_saturated));
  }
  { // Node ID: 250 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id250in_input = id86out_done;

    id250out_output[(getCycle()+1)%2] = id250in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id245out_output;

  { // Node ID: 245 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id245in_input = id83out_rst_en;

    id245out_output = id245in_input;
  }
  { // Node ID: 251 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id251in_input = id245out_output;

    id251out_output[(getCycle()+54)%55] = id251in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id18out_o;

  { // Node ID: 18 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id18in_i = id17out_result[getCycle()%39];

    id18out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id18in_i));
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 12 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id12in_s0_done = id23out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id12in_s1_done = id246out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id12in_s2_done = id260out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id12in_sm_en = id261out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id12in_sm_numIter = id18out_o;

    m_sm_seq1202_sm.inputdata_s0_done = id12in_s0_done.getBitString();
    m_sm_seq1202_sm.inputdata_s1_done = id12in_s1_done.getBitString();
    m_sm_seq1202_sm.inputdata_s2_done = id12in_s2_done.getBitString();
    m_sm_seq1202_sm.inputdata_sm_en = id12in_sm_en.getBitString();
    m_sm_seq1202_sm.inputdata_sm_numIter = id12in_sm_numIter.getBitString();
    m_sm_seq1202_sm.execute(true);
    id12out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1202_sm.outputdata_rst_en));
    id12out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1202_sm.outputdata_s0_en));
    id12out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1202_sm.outputdata_s1_en));
    id12out_s2_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1202_sm.outputdata_s2_en));
    id12out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1202_sm.outputdata_sm_done));
  }
  { // Node ID: 252 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id252in_input = id12out_s1_en;

    id252out_output[(getCycle()+54)%55] = id252in_input;
  }
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 98 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id98in_en = id253out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id98in_max0 = id4out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id98in_reset = id254out_output[getCycle()%60];

    m_sm_CounterChain1191_sm.inputdata_en = id98in_en.getBitString();
    m_sm_CounterChain1191_sm.inputdata_max0 = id98in_max0.getBitString();
    m_sm_CounterChain1191_sm.inputdata_reset = id98in_reset.getBitString();
    m_sm_CounterChain1191_sm.execute(true);
    id98out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1191_sm.outputdata_counter0) ));
    id98out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1191_sm.outputdata_done));
    id98out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1191_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id99out_output;

  { // Node ID: 99 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id99in_input = id98out_done;

    id99out_output = id99in_input;
  }
  if ( (getFillLevel() >= (63l)))
  { // Node ID: 95 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id95in_ctr_done = id99out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id95in_rst_done = id255out_output[getCycle()%59];
    const HWOffsetFix<1,0,UNSIGNED> &id95in_sm_en = id256out_output[getCycle()%59];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id95in_sm_maxIn_0 = id4out_value;

    m_sm_pipe1197_sm.inputdata_ctr_done = id95in_ctr_done.getBitString();
    m_sm_pipe1197_sm.inputdata_rst_done = id95in_rst_done.getBitString();
    m_sm_pipe1197_sm.inputdata_sm_en = id95in_sm_en.getBitString();
    m_sm_pipe1197_sm.inputdata_sm_maxIn_0 = id95in_sm_maxIn_0.getBitString();
    m_sm_pipe1197_sm.execute(true);
    id95out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1197_sm.outputdata_ctr_en));
    id95out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe1197_sm.outputdata_ctr_maxOut_0) ));
    id95out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1197_sm.outputdata_rst_en));
    id95out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1197_sm.outputdata_sm_done));
  }
  { // Node ID: 253 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id253in_input = id95out_ctr_en;

    id253out_output[(getCycle()+1)%2] = id253in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id248out_output;

  { // Node ID: 248 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id248in_input = id95out_sm_done;

    id248out_output = id248in_input;
  }
  { // Node ID: 254 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id254in_input = id248out_output;

    id254out_output[(getCycle()+59)%60] = id254in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id247out_output;

  { // Node ID: 247 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id247in_input = id95out_rst_en;

    id247out_output = id247in_input;
  }
  { // Node ID: 255 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id255in_input = id247out_output;

    id255out_output[(getCycle()+58)%59] = id255in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id116out_output;

  { // Node ID: 116 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id116in_input = id115out_result[getCycle()%2];

    id116out_output = id116in_input;
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 104 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id104in_memDone = id116out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id104in_sm_en = id257out_output[getCycle()%2];

    m_sm_DRAM1134_void1198_outldSM.inputdata_memDone = id104in_memDone.getBitString();
    m_sm_DRAM1134_void1198_outldSM.inputdata_sm_en = id104in_sm_en.getBitString();
    m_sm_DRAM1134_void1198_outldSM.execute(true);
    id104out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1134_void1198_outldSM.outputdata_memStart));
    id104out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1134_void1198_outldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id105out_output;

  { // Node ID: 105 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id105in_input = id104out_sm_done;

    id105out_output = id105in_input;
  }
  { // Node ID: 92 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 90 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id90in_s0_done = id248out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_s1_done = id105out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id90in_sm_en = id12out_s2_en;
    const HWOffsetFix<32,0,UNSIGNED> &id90in_sm_numIter = id92out_value;

    m_sm_void1200_sm.inputdata_s0_done = id90in_s0_done.getBitString();
    m_sm_void1200_sm.inputdata_s1_done = id90in_s1_done.getBitString();
    m_sm_void1200_sm.inputdata_sm_en = id90in_sm_en.getBitString();
    m_sm_void1200_sm.inputdata_sm_numIter = id90in_sm_numIter.getBitString();
    m_sm_void1200_sm.execute(true);
    id90out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1200_sm.outputdata_rst_en));
    id90out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1200_sm.outputdata_s0_en));
    id90out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1200_sm.outputdata_s1_en));
    id90out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1200_sm.outputdata_sm_done));
    id90out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1200_sm.outputdata_sm_last));
  }
  { // Node ID: 256 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id256in_input = id90out_s0_en;

    id256out_output[(getCycle()+58)%59] = id256in_input;
  }
  { // Node ID: 288 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id111out_output;

  { // Node ID: 111 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id111in_input = id105out_output;

    id111out_output = id111in_input;
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 113 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id113in_enable = id104out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id113in_max = id288out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id113in_userReset = id111out_output;

    HWOffsetFix<17,0,UNSIGNED> id113x_1;
    HWOffsetFix<1,0,UNSIGNED> id113x_2;
    HWOffsetFix<1,0,UNSIGNED> id113x_3;
    HWOffsetFix<1,0,UNSIGNED> id113x_4;
    HWOffsetFix<17,0,UNSIGNED> id113x_5e_1t_1e_1;

    id113out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id113st_count)));
    (id113x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id113st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id113x_2) = (gt_fixed((id113x_1),id113in_max));
    (id113x_3) = (and_fixed(id113in_enable,(not_fixed((id113x_2)))));
    (id113x_4) = (c_hw_fix_1_0_uns_bits);
    id113out_wrap = (id113x_4);
    if((id113in_userReset.getValueAsBool())) {
      (id113st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id113x_3).getValueAsBool())) {
        if(((id113x_4).getValueAsBool())) {
          (id113st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id113x_5e_1t_1e_1) = (id113x_1);
          (id113st_count) = (id113x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 287 (NodeConstantRawBits)
  }
  { // Node ID: 115 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id115in_a = id113out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id115in_b = id287out_value;

    id115out_result[(getCycle()+1)%2] = (eq_fixed(id115in_a,id115in_b));
  }
  { // Node ID: 257 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id257in_input = id90out_s1_en;

    id257out_output[(getCycle()+1)%2] = id257in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id91out_output;

  { // Node ID: 91 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id91in_input = id90out_sm_done;

    id91out_output = id91in_input;
  }
  { // Node ID: 260 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id260in_input = id91out_output;

    id260out_output[(getCycle()+1)%2] = id260in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id13out_output;

  { // Node ID: 13 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id13in_input = id12out_sm_done;

    id13out_output = id13in_input;
  }
  { // Node ID: 286 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 155 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id155in_enable = id258out_output[getCycle()%2];
    const HWOffsetFix<33,0,UNSIGNED> &id155in_max = id286out_value;

    HWOffsetFix<33,0,UNSIGNED> id155x_1;
    HWOffsetFix<1,0,UNSIGNED> id155x_2;
    HWOffsetFix<1,0,UNSIGNED> id155x_3;
    HWOffsetFix<33,0,UNSIGNED> id155x_4t_1e_1;

    id155out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id155st_count)));
    (id155x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id155st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id155x_2) = (gte_fixed((id155x_1),id155in_max));
    (id155x_3) = (and_fixed((id155x_2),id155in_enable));
    id155out_wrap = (id155x_3);
    if((id155in_enable.getValueAsBool())) {
      if(((id155x_3).getValueAsBool())) {
        (id155st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id155x_4t_1e_1) = (id155x_1);
        (id155st_count) = (id155x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id156out_output;

  { // Node ID: 156 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id156in_input = id155out_wrap;

    id156out_output = id156in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id8out_output;

  { // Node ID: 8 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id8in_input = id259out_output[getCycle()%2];

    id8out_output = id8in_input;
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_intr_done = id156out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id1in_run_done = id8out_output;
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
  { // Node ID: 258 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id258in_input = id1out_intr_en;

    id258out_output[(getCycle()+1)%2] = id258in_input;
  }
  { // Node ID: 9 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 7 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id7in_s0_done = id13out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id7in_sm_en = id1out_run_en;
    const HWOffsetFix<32,0,UNSIGNED> &id7in_sm_numIter = id9out_value;

    m_sm_void1204_sm.inputdata_s0_done = id7in_s0_done.getBitString();
    m_sm_void1204_sm.inputdata_sm_en = id7in_sm_en.getBitString();
    m_sm_void1204_sm.inputdata_sm_numIter = id7in_sm_numIter.getBitString();
    m_sm_void1204_sm.execute(true);
    id7out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1204_sm.outputdata_rst_en));
    id7out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1204_sm.outputdata_s0_en));
    id7out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1204_sm.outputdata_sm_done));
  }
  { // Node ID: 259 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id259in_input = id7out_sm_done;

    id259out_output[(getCycle()+1)%2] = id259in_input;
  }
  { // Node ID: 261 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id261in_input = id7out_s0_en;

    id261out_output[(getCycle()+1)%2] = id261in_input;
  }
  { // Node ID: 2 (NodeInputMappedReg)
  }
  { // Node ID: 208 (NodeConstantRawBits)
  }
  { // Node ID: 17 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id17in_a = id2out_argin1130;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id17in_b = id208out_value;

    id17out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id17in_a,id17in_b));
  }
  { // Node ID: 262 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id262in_input = id12out_s0_en;

    id262out_output[(getCycle()+1)%2] = id262in_input;
  }
  { // Node ID: 263 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id263in_input = id22out_s0_en;

    id263out_output[(getCycle()+1)%2] = id263in_input;
  }
  { // Node ID: 264 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id264in_input = id30out_memStart;

    id264out_output[(getCycle()+1)%2] = id264in_input;
  }
  { // Node ID: 285 (NodeConstantRawBits)
  }
  { // Node ID: 45 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id45in_a = id40out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id45in_b = id285out_value;

    id45out_result[(getCycle()+1)%2] = (eq_fixed(id45in_a,id45in_b));
  }
  { // Node ID: 46 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id46in_a = id264out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id46in_b = id45out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id46x_1;

    (id46x_1) = (and_fixed(id46in_a,id46in_b));
    id46out_result[(getCycle()+1)%2] = (id46x_1);
  }
  { // Node ID: 64 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id65out_result;

  { // Node ID: 65 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id65in_a = id64out_io_DRAM1133_void1177_in_cmd_force_disabled;

    id65out_result = (not_fixed(id65in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id66out_result;

  { // Node ID: 66 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id66in_a = id46out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id66in_b = id65out_result;

    HWOffsetFix<1,0,UNSIGNED> id66x_1;

    (id66x_1) = (and_fixed(id66in_a,id66in_b));
    id66out_result = (id66x_1);
  }
  { // Node ID: 265 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id265in_input = id66out_result;

    id265out_output[(getCycle()+34)%35] = id265in_input;
  }
  { // Node ID: 209 (NodeConstantRawBits)
  }
  { // Node ID: 214 (NodeConstantRawBits)
  }
  { // Node ID: 51 (NodeConstantRawBits)
  }
  HWRawBits<8> id71out_output;

  { // Node ID: 71 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id71in_input = id51out_value;

    id71out_output = (cast_fixed2bits(id71in_input));
  }
  { // Node ID: 219 (NodeConstantRawBits)
  }
  { // Node ID: 284 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 19 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id19in_en = id91out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id19in_max0 = id2out_argin1130;
    const HWOffsetFix<1,0,UNSIGNED> &id19in_reset = id13out_output;

    m_sm_CounterChain1176_sm.inputdata_en = id19in_en.getBitString();
    m_sm_CounterChain1176_sm.inputdata_max0 = id19in_max0.getBitString();
    m_sm_CounterChain1176_sm.inputdata_reset = id19in_reset.getBitString();
    m_sm_CounterChain1176_sm.execute(true);
    id19out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1176_sm.outputdata_counter0) ));
    id19out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1176_sm.outputdata_done));
    id19out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1176_sm.outputdata_saturated));
  }
  { // Node ID: 283 (NodeConstantRawBits)
  }
  { // Node ID: 33 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id33in_a = id19out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id33in_b = id283out_value;

    id33out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id33in_a,id33in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id34out_o;

  { // Node ID: 34 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id34in_i = id33out_result[getCycle()%39];

    id34out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id34in_i));
  }
  { // Node ID: 36 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id36in_a = id284out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id36in_b = id34out_o;

    id36out_result[(getCycle()+1)%2] = (add_fixed<32,0,UNSIGNED,TONEAR>(id36in_a,id36in_b));
  }
  HWRawBits<32> id68out_output;

  { // Node ID: 68 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id68in_input = id36out_result[getCycle()%2];

    id68out_output = (cast_fixed2bits(id68in_input));
  }
  HWRawBits<40> id70out_result;

  { // Node ID: 70 (NodeCat)
    const HWRawBits<8> &id70in_in0 = id219out_value;
    const HWRawBits<32> &id70in_in1 = id68out_output;

    id70out_result = (cat(id70in_in0,id70in_in1));
  }
  HWRawBits<48> id72out_result;

  { // Node ID: 72 (NodeCat)
    const HWRawBits<8> &id72in_in0 = id71out_output;
    const HWRawBits<40> &id72in_in1 = id70out_result;

    id72out_result = (cat(id72in_in0,id72in_in1));
  }
  HWRawBits<63> id74out_result;

  { // Node ID: 74 (NodeCat)
    const HWRawBits<15> &id74in_in0 = id214out_value;
    const HWRawBits<48> &id74in_in1 = id72out_result;

    id74out_result = (cat(id74in_in0,id74in_in1));
  }
  HWRawBits<64> id76out_result;

  { // Node ID: 76 (NodeCat)
    const HWRawBits<1> &id76in_in0 = id209out_value;
    const HWRawBits<63> &id76in_in1 = id74out_result;

    id76out_result = (cat(id76in_in0,id76in_in1));
  }
  if ( (getFillLevel() >= (43l)) && (getFlushLevel() < (43l)|| !isFlushingActive() ))
  { // Node ID: 67 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id67in_output_control = id265out_output[getCycle()%35];
    const HWRawBits<64> &id67in_data = id76out_result;

    bool id67x_1;

    (id67x_1) = ((id67in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(43l))&(isFlushingActive()))));
    if((id67x_1)) {
      writeOutput(m_DRAM1133_void1177_in_cmd, id67in_data);
    }
  }
  { // Node ID: 266 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id266in_input = id104out_memStart;

    id266out_output[(getCycle()+1)%2] = id266in_input;
  }
  { // Node ID: 282 (NodeConstantRawBits)
  }
  { // Node ID: 118 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id118in_a = id113out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id118in_b = id282out_value;

    id118out_result[(getCycle()+1)%2] = (eq_fixed(id118in_a,id118in_b));
  }
  { // Node ID: 119 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id119in_a = id266out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id119in_b = id118out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id119x_1;

    (id119x_1) = (and_fixed(id119in_a,id119in_b));
    id119out_result[(getCycle()+1)%2] = (id119x_1);
  }
  { // Node ID: 136 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id137out_result;

  { // Node ID: 137 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id137in_a = id136out_io_DRAM1134_void1198_out_cmd_force_disabled;

    id137out_result = (not_fixed(id137in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id138out_result;

  { // Node ID: 138 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id138in_a = id119out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id138in_b = id137out_result;

    HWOffsetFix<1,0,UNSIGNED> id138x_1;

    (id138x_1) = (and_fixed(id138in_a,id138in_b));
    id138out_result = (id138x_1);
  }
  { // Node ID: 267 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id267in_input = id138out_result;

    id267out_output[(getCycle()+35)%36] = id267in_input;
  }
  { // Node ID: 220 (NodeConstantRawBits)
  }
  { // Node ID: 225 (NodeConstantRawBits)
  }
  { // Node ID: 123 (NodeConstantRawBits)
  }
  HWRawBits<8> id143out_output;

  { // Node ID: 143 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id143in_input = id123out_value;

    id143out_output = (cast_fixed2bits(id143in_input));
  }
  { // Node ID: 230 (NodeConstantRawBits)
  }
  { // Node ID: 281 (NodeConstantRawBits)
  }
  { // Node ID: 280 (NodeConstantRawBits)
  }
  { // Node ID: 107 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id107in_a = id19out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id107in_b = id280out_value;

    id107out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id107in_a,id107in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id108out_o;

  { // Node ID: 108 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id108in_i = id107out_result[getCycle()%39];

    id108out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id108in_i));
  }
  { // Node ID: 110 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id110in_a = id281out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id110in_b = id108out_o;

    id110out_result[(getCycle()+1)%2] = (add_fixed<32,0,UNSIGNED,TONEAR>(id110in_a,id110in_b));
  }
  HWRawBits<32> id140out_output;

  { // Node ID: 140 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id140in_input = id110out_result[getCycle()%2];

    id140out_output = (cast_fixed2bits(id140in_input));
  }
  HWRawBits<40> id142out_result;

  { // Node ID: 142 (NodeCat)
    const HWRawBits<8> &id142in_in0 = id230out_value;
    const HWRawBits<32> &id142in_in1 = id140out_output;

    id142out_result = (cat(id142in_in0,id142in_in1));
  }
  HWRawBits<48> id144out_result;

  { // Node ID: 144 (NodeCat)
    const HWRawBits<8> &id144in_in0 = id143out_output;
    const HWRawBits<40> &id144in_in1 = id142out_result;

    id144out_result = (cat(id144in_in0,id144in_in1));
  }
  HWRawBits<63> id146out_result;

  { // Node ID: 146 (NodeCat)
    const HWRawBits<15> &id146in_in0 = id225out_value;
    const HWRawBits<48> &id146in_in1 = id144out_result;

    id146out_result = (cat(id146in_in0,id146in_in1));
  }
  HWRawBits<64> id148out_result;

  { // Node ID: 148 (NodeCat)
    const HWRawBits<1> &id148in_in0 = id220out_value;
    const HWRawBits<63> &id148in_in1 = id146out_result;

    id148out_result = (cat(id148in_in0,id148in_in1));
  }
  if ( (getFillLevel() >= (43l)) && (getFlushLevel() < (43l)|| !isFlushingActive() ))
  { // Node ID: 139 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id139in_output_control = id267out_output[getCycle()%36];
    const HWRawBits<64> &id139in_data = id148out_result;

    bool id139x_1;

    (id139x_1) = ((id139in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(43l))&(isFlushingActive()))));
    if((id139x_1)) {
      writeOutput(m_DRAM1134_void1198_out_cmd, id139in_data);
    }
  }
  { // Node ID: 149 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id150out_result;

  { // Node ID: 150 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id150in_a = id149out_io_DRAM1134_void1198_out_force_disabled;

    id150out_result = (not_fixed(id150in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id151out_result;

  { // Node ID: 151 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id151in_a = id253out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id151in_b = id150out_result;

    HWOffsetFix<1,0,UNSIGNED> id151x_1;

    (id151x_1) = (and_fixed(id151in_a,id151in_b));
    id151out_result = (id151x_1);
  }
  { // Node ID: 271 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id271in_input = id151out_result;

    id271out_output[(getCycle()+2)%3] = id271in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id89out_o;

  { // Node ID: 89 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id89in_i = id86out_counter0;

    id89out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id89in_i));
  }
  { // Node ID: 269 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id269in_input = id89out_o;

    id269out_output[(getCycle()+5)%6] = id269in_input;
  }
  { // Node ID: 77 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id78out_result;

  { // Node ID: 78 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id78in_a = id77out_io_DRAM1133_void1177_in_force_disabled;

    id78out_result = (not_fixed(id78in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id79out_result;

  { // Node ID: 79 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id79in_a = id83out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id79in_b = id78out_result;

    HWOffsetFix<1,0,UNSIGNED> id79x_1;

    (id79x_1) = (and_fixed(id79in_a,id79in_b));
    id79out_result = (id79x_1);
  }
  if ( (getFillLevel() >= (59l)))
  { // Node ID: 80 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id80in_enable = id79out_result;

    (id80st_read_next_cycle) = ((id80in_enable.getValueAsBool())&(!(((getFlushLevel())>=(59l))&(isFlushingActive()))));
    queueReadRequest(m_DRAM1133_void1177_in, id80st_read_next_cycle.getValueAsBool());
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id82out_output;

  { // Node ID: 82 (NodeReinterpret)
    const HWRawBits<32> &id82in_input = id80out_data;

    id82out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id82in_input));
  }
  { // Node ID: 270 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id270in_input = id83out_ctr_en;

    id270out_output[(getCycle()+5)%6] = id270in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id102out_o;

  { // Node ID: 102 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id102in_i = id98out_counter0;

    id102out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id102in_i));
  }
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 195 (NodeRAM)
    const bool id195_inputvalid = !(isFlushingActive() && getFlushLevel() >= (64l));
    const HWOffsetFix<7,0,UNSIGNED> &id195in_addrA = id269out_output[getCycle()%6];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id195in_dina = id82out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id195in_wea = id270out_output[getCycle()%6];
    const HWOffsetFix<7,0,UNSIGNED> &id195in_addrB = id102out_o;

    long id195x_1;
    long id195x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id195x_3;

    (id195x_1) = (id195in_addrA.getValueAsLong());
    (id195x_2) = (id195in_addrB.getValueAsLong());
    switch(((long)((id195x_2)<(96l)))) {
      case 0l:
        id195x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id195x_3 = (id195sta_ram_store[(id195x_2)]);
        break;
      default:
        id195x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id195out_doutb[(getCycle()+2)%3] = (id195x_3);
    if(((id195in_wea.getValueAsBool())&id195_inputvalid)) {
      if(((id195x_1)<(96l))) {
        (id195sta_ram_store[(id195x_1)]) = id195in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_1("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 195) on port A, ram depth is 96.")));
      }
    }
  }
  HWRawBits<32> id153out_output;

  { // Node ID: 153 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id153in_input = id195out_doutb[getCycle()%3];

    id153out_output = (cast_fixed2bits(id153in_input));
  }
  if ( (getFillLevel() >= (66l)) && (getFlushLevel() < (66l)|| !isFlushingActive() ))
  { // Node ID: 152 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id152in_output_control = id271out_output[getCycle()%3];
    const HWRawBits<32> &id152in_data = id153out_output;

    bool id152x_1;

    (id152x_1) = ((id152in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(66l))&(isFlushingActive()))));
    if((id152x_1)) {
      writeOutput(m_DRAM1134_void1198_out, id152in_data);
    }
  }
  { // Node ID: 276 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id276in_input = id258out_output[getCycle()%2];

    id276out_output[(getCycle()+1)%2] = id276in_input;
  }
  { // Node ID: 279 (NodeConstantRawBits)
  }
  { // Node ID: 158 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id158in_a = id155out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id158in_b = id279out_value;

    id158out_result[(getCycle()+1)%2] = (eq_fixed(id158in_a,id158in_b));
  }
  { // Node ID: 159 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id159in_a = id276out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id159in_b = id158out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id159x_1;

    (id159x_1) = (and_fixed(id159in_a,id159in_b));
    id159out_result[(getCycle()+1)%2] = (id159x_1);
  }
  { // Node ID: 175 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id176out_result;

  { // Node ID: 176 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id176in_a = id175out_io_intrCmd_force_disabled;

    id176out_result = (not_fixed(id176in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id177out_result;

  { // Node ID: 177 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id177in_a = id159out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id177in_b = id176out_result;

    HWOffsetFix<1,0,UNSIGNED> id177x_1;

    (id177x_1) = (and_fixed(id177in_a,id177in_b));
    id177out_result = (id177x_1);
  }
  HWRawBits<1> id186out_output;

  { // Node ID: 186 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id186in_input = id276out_output[getCycle()%2];

    id186out_output = (cast_fixed2bits(id186in_input));
  }
  { // Node ID: 274 (NodeFIFO)
    const HWRawBits<1> &id274in_input = id186out_output;

    id274out_output[(getCycle()+1)%2] = id274in_input;
  }
  { // Node ID: 235 (NodeConstantRawBits)
  }
  { // Node ID: 237 (NodeConstantRawBits)
  }
  HWRawBits<8> id182out_output;

  { // Node ID: 182 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id182in_input = id237out_value;

    id182out_output = (cast_fixed2bits(id182in_input));
  }
  { // Node ID: 239 (NodeConstantRawBits)
  }
  { // Node ID: 240 (NodeConstantRawBits)
  }
  HWRawBits<40> id181out_result;

  { // Node ID: 181 (NodeCat)
    const HWRawBits<8> &id181in_in0 = id239out_value;
    const HWRawBits<32> &id181in_in1 = id240out_value;

    id181out_result = (cat(id181in_in0,id181in_in1));
  }
  HWRawBits<48> id183out_result;

  { // Node ID: 183 (NodeCat)
    const HWRawBits<8> &id183in_in0 = id182out_output;
    const HWRawBits<40> &id183in_in1 = id181out_result;

    id183out_result = (cat(id183in_in0,id183in_in1));
  }
  HWRawBits<63> id185out_result;

  { // Node ID: 185 (NodeCat)
    const HWRawBits<15> &id185in_in0 = id235out_value;
    const HWRawBits<48> &id185in_in1 = id183out_result;

    id185out_result = (cat(id185in_in0,id185in_in1));
  }
  HWRawBits<64> id187out_result;

  { // Node ID: 187 (NodeCat)
    const HWRawBits<1> &id187in_in0 = id274out_output[getCycle()%2];
    const HWRawBits<63> &id187in_in1 = id185out_result;

    id187out_result = (cat(id187in_in0,id187in_in1));
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 178 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id178in_output_control = id177out_result;
    const HWRawBits<64> &id178in_data = id187out_result;

    bool id178x_1;

    (id178x_1) = ((id178in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id178x_1)) {
      writeOutput(m_intrCmd, id178in_data);
    }
  }
  { // Node ID: 188 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 189 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id189in_load = id188out_value;
    const HWOffsetFix<64,0,UNSIGNED> &id189in_data = id1out_cycles;

    bool id189x_1;

    (id189x_1) = ((id189in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id189x_1)) {
      setMappedRegValue("cycles", id189in_data);
    }
  }
  { // Node ID: 191 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id192out_result;

  { // Node ID: 192 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id192in_a = id191out_io_intrStream_force_disabled;

    id192out_result = (not_fixed(id192in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id193out_result;

  { // Node ID: 193 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id193in_a = id276out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id193in_b = id192out_result;

    HWOffsetFix<1,0,UNSIGNED> id193x_1;

    (id193x_1) = (and_fixed(id193in_a,id193in_b));
    id193out_result = (id193x_1);
  }
  { // Node ID: 190 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (6l)) && (getFlushLevel() < (6l)|| !isFlushingActive() ))
  { // Node ID: 194 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id194in_output_control = id193out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id194in_data = id190out_value;

    bool id194x_1;

    (id194x_1) = ((id194in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(6l))&(isFlushingActive()))));
    if((id194x_1)) {
      writeOutput(m_intrStream, id194in_data);
    }
  }
  { // Node ID: 200 (NodeConstantRawBits)
  }
  { // Node ID: 278 (NodeConstantRawBits)
  }
  { // Node ID: 197 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (65l)))
  { // Node ID: 198 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id198in_enable = id278out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id198in_max = id197out_value;

    HWOffsetFix<49,0,UNSIGNED> id198x_1;
    HWOffsetFix<1,0,UNSIGNED> id198x_2;
    HWOffsetFix<1,0,UNSIGNED> id198x_3;
    HWOffsetFix<49,0,UNSIGNED> id198x_4t_1e_1;

    id198out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id198st_count)));
    (id198x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id198st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id198x_2) = (gte_fixed((id198x_1),id198in_max));
    (id198x_3) = (and_fixed((id198x_2),id198in_enable));
    id198out_wrap = (id198x_3);
    if((id198in_enable.getValueAsBool())) {
      if(((id198x_3).getValueAsBool())) {
        (id198st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id198x_4t_1e_1) = (id198x_1);
        (id198st_count) = (id198x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id199out_output;

  { // Node ID: 199 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id199in_input = id198out_count;

    id199out_output = id199in_input;
  }
  if ( (getFillLevel() >= (66l)) && (getFlushLevel() < (66l)|| !isFlushingActive() ))
  { // Node ID: 201 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id201in_load = id200out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id201in_data = id199out_output;

    bool id201x_1;

    (id201x_1) = ((id201in_load.getValueAsBool())&(!(((getFlushLevel())>=(66l))&(isFlushingActive()))));
    if((id201x_1)) {
      setMappedRegValue("current_run_cycle_count", id201in_data);
    }
  }
  { // Node ID: 277 (NodeConstantRawBits)
  }
  { // Node ID: 203 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 204 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id204in_enable = id277out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id204in_max = id203out_value;

    HWOffsetFix<49,0,UNSIGNED> id204x_1;
    HWOffsetFix<1,0,UNSIGNED> id204x_2;
    HWOffsetFix<1,0,UNSIGNED> id204x_3;
    HWOffsetFix<49,0,UNSIGNED> id204x_4t_1e_1;

    id204out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id204st_count)));
    (id204x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id204st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id204x_2) = (gte_fixed((id204x_1),id204in_max));
    (id204x_3) = (and_fixed((id204x_2),id204in_enable));
    id204out_wrap = (id204x_3);
    if((id204in_enable.getValueAsBool())) {
      if(((id204x_3).getValueAsBool())) {
        (id204st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id204x_4t_1e_1) = (id204x_1);
        (id204st_count) = (id204x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 206 (NodeInputMappedReg)
  }
  { // Node ID: 207 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id207in_a = id204out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id207in_b = id206out_run_cycle_count;

    id207out_result[(getCycle()+1)%2] = (eq_fixed(id207in_a,id207in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 205 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id205in_start = id207out_result[getCycle()%2];

    if((id205in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
