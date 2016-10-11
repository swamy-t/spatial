#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "TopKernel.h"

namespace maxcompilersim {

void TopKernel::execute0() {
  { // Node ID: 253 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id48out_output;

  { // Node ID: 48 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id48in_input = id47out_result[getCycle()%2];

    id48out_output = id48in_input;
  }
  { // Node ID: 6 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (23l)))
  { // Node ID: 91 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id91in_en = id214out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id91in_max0 = id6out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id91in_reset = id215out_output[getCycle()%20];

    m_sm_CounterChain827_sm.inputdata_en = id91in_en.getBitString();
    m_sm_CounterChain827_sm.inputdata_max0 = id91in_max0.getBitString();
    m_sm_CounterChain827_sm.inputdata_reset = id91in_reset.getBitString();
    m_sm_CounterChain827_sm.execute(true);
    id91out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain827_sm.outputdata_counter0) ));
    id91out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain827_sm.outputdata_done));
    id91out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain827_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id92out_output;

  { // Node ID: 92 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id92in_input = id91out_done;

    id92out_output = id92in_input;
  }
  if ( (getFillLevel() >= (22l)))
  { // Node ID: 88 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id88in_ctr_done = id92out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id88in_rst_done = id217out_output[getCycle()%18];
    const HWOffsetFix<1,0,UNSIGNED> &id88in_sm_en = id218out_output[getCycle()%19];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id88in_sm_maxIn_0 = id6out_value;

    m_sm_pipe833_sm.inputdata_ctr_done = id88in_ctr_done.getBitString();
    m_sm_pipe833_sm.inputdata_rst_done = id88in_rst_done.getBitString();
    m_sm_pipe833_sm.inputdata_sm_en = id88in_sm_en.getBitString();
    m_sm_pipe833_sm.inputdata_sm_maxIn_0 = id88in_sm_maxIn_0.getBitString();
    m_sm_pipe833_sm.execute(true);
    id88out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe833_sm.outputdata_ctr_en));
    id88out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe833_sm.outputdata_ctr_maxOut_0) ));
    id88out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe833_sm.outputdata_rst_en));
    id88out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe833_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id208out_output;

  { // Node ID: 208 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id208in_input = id88out_sm_done;

    id208out_output = id208in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id20out_output;

  { // Node ID: 20 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id20in_input = id219out_output[getCycle()%2];

    id20out_output = id20in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id15out_output;

  { // Node ID: 15 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id15in_input = id220out_output[getCycle()%2];

    id15out_output = id15in_input;
  }
  if ( (getFillLevel() >= (27l)))
  { // Node ID: 103 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id103in_en = id102out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id103in_max0 = id6out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id103in_reset = id222out_output[getCycle()%24];

    m_sm_CounterChain840_sm.inputdata_en = id103in_en.getBitString();
    m_sm_CounterChain840_sm.inputdata_max0 = id103in_max0.getBitString();
    m_sm_CounterChain840_sm.inputdata_reset = id103in_reset.getBitString();
    m_sm_CounterChain840_sm.execute(true);
    id103out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain840_sm.outputdata_counter0) ));
    id103out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain840_sm.outputdata_done));
    id103out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain840_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id104out_output;

  { // Node ID: 104 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id104in_input = id103out_done;

    id104out_output = id104in_input;
  }
  if ( (getFillLevel() >= (26l)))
  { // Node ID: 95 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id95in_ctr_done = id104out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id95in_rst_done = id223out_output[getCycle()%23];
    const HWOffsetFix<1,0,UNSIGNED> &id95in_sm_en = id224out_output[getCycle()%23];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id95in_sm_maxIn_0 = id6out_value;

    m_sm_pipe847_sm.inputdata_ctr_done = id95in_ctr_done.getBitString();
    m_sm_pipe847_sm.inputdata_rst_done = id95in_rst_done.getBitString();
    m_sm_pipe847_sm.inputdata_sm_en = id95in_sm_en.getBitString();
    m_sm_pipe847_sm.inputdata_sm_maxIn_0 = id95in_sm_maxIn_0.getBitString();
    m_sm_pipe847_sm.execute(true);
    id95out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe847_sm.outputdata_ctr_en));
    id95out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe847_sm.outputdata_ctr_maxOut_0) ));
    id95out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe847_sm.outputdata_rst_en));
    id95out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe847_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id211out_output;

  { // Node ID: 211 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id211in_input = id95out_sm_done;

    id211out_output = id211in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id114out_output;

  { // Node ID: 114 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id114in_input = id225out_output[getCycle()%2];

    id114out_output = id114in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id212out_output;

  { // Node ID: 212 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id212in_input = id226out_output[getCycle()%2];

    id212out_output = id212in_input;
  }
  { // Node ID: 113 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 110 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id110in_ctr_done = id114out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id110in_rst_done = id212out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id110in_sm_en = id227out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id110in_sm_maxIn_0 = id113out_value;

    m_sm_void851_sm.inputdata_ctr_done = id110in_ctr_done.getBitString();
    m_sm_void851_sm.inputdata_rst_done = id110in_rst_done.getBitString();
    m_sm_void851_sm.inputdata_sm_en = id110in_sm_en.getBitString();
    m_sm_void851_sm.inputdata_sm_maxIn_0 = id110in_sm_maxIn_0.getBitString();
    m_sm_void851_sm.execute(true);
    id110out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void851_sm.outputdata_ctr_en));
    id110out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_void851_sm.outputdata_ctr_maxOut_0) ));
    id110out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void851_sm.outputdata_rst_en));
    id110out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void851_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id213out_output;

  { // Node ID: 213 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id213in_input = id110out_sm_done;

    id213out_output = id213in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id120out_output;

  { // Node ID: 120 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id120in_input = id228out_output[getCycle()%2];

    id120out_output = id120in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id10out_output;

  { // Node ID: 10 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id10in_input = id229out_output[getCycle()%2];

    id10out_output = id10in_input;
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_intr_done = id120out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id1in_run_done = id10out_output;
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
  { // Node ID: 11 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 9 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id9in_s0_done = id15out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id9in_s1_done = id211out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id9in_s2_done = id213out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id9in_sm_en = id1out_run_en;
    const HWOffsetFix<32,0,UNSIGNED> &id9in_sm_numIter = id11out_value;

    m_sm_void853_sm.inputdata_s0_done = id9in_s0_done.getBitString();
    m_sm_void853_sm.inputdata_s1_done = id9in_s1_done.getBitString();
    m_sm_void853_sm.inputdata_s2_done = id9in_s2_done.getBitString();
    m_sm_void853_sm.inputdata_sm_en = id9in_sm_en.getBitString();
    m_sm_void853_sm.inputdata_sm_numIter = id9in_sm_numIter.getBitString();
    m_sm_void853_sm.execute(true);
    id9out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void853_sm.outputdata_rst_en));
    id9out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void853_sm.outputdata_s0_en));
    id9out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void853_sm.outputdata_s1_en));
    id9out_s2_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void853_sm.outputdata_s2_en));
    id9out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void853_sm.outputdata_sm_done));
  }
  { // Node ID: 16 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 14 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id14in_s0_done = id20out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id14in_sm_en = id9out_s0_en;
    const HWOffsetFix<32,0,UNSIGNED> &id14in_sm_numIter = id16out_value;

    m_sm_void837_sm.inputdata_s0_done = id14in_s0_done.getBitString();
    m_sm_void837_sm.inputdata_sm_en = id14in_sm_en.getBitString();
    m_sm_void837_sm.inputdata_sm_numIter = id14in_sm_numIter.getBitString();
    m_sm_void837_sm.execute(true);
    id14out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void837_sm.outputdata_rst_en));
    id14out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void837_sm.outputdata_s0_en));
    id14out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void837_sm.outputdata_sm_done));
    id14out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void837_sm.outputdata_sm_last));
  }
  { // Node ID: 21 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 19 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id19in_s0_done = id230out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id19in_s1_done = id208out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id19in_sm_en = id14out_s0_en;
    const HWOffsetFix<32,0,UNSIGNED> &id19in_sm_numIter = id21out_value;

    m_sm_void835_sm.inputdata_s0_done = id19in_s0_done.getBitString();
    m_sm_void835_sm.inputdata_s1_done = id19in_s1_done.getBitString();
    m_sm_void835_sm.inputdata_sm_en = id19in_sm_en.getBitString();
    m_sm_void835_sm.inputdata_sm_numIter = id19in_sm_numIter.getBitString();
    m_sm_void835_sm.execute(true);
    id19out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void835_sm.outputdata_rst_en));
    id19out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void835_sm.outputdata_s0_en));
    id19out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void835_sm.outputdata_s1_en));
    id19out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void835_sm.outputdata_sm_done));
    id19out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void835_sm.outputdata_sm_last));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 27 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id27in_memDone = id48out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id27in_sm_en = id19out_s0_en;

    m_sm_DRAM783_void825_inldSM.inputdata_memDone = id27in_memDone.getBitString();
    m_sm_DRAM783_void825_inldSM.inputdata_sm_en = id27in_sm_en.getBitString();
    m_sm_DRAM783_void825_inldSM.execute(true);
    id27out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM783_void825_inldSM.outputdata_memStart));
    id27out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM783_void825_inldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id28out_output;

  { // Node ID: 28 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id28in_input = id27out_sm_done;

    id28out_output = id28in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id43out_output;

  { // Node ID: 43 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id43in_input = id28out_output;

    id43out_output = id43in_input;
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 45 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id45in_enable = id27out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id45in_max = id253out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id45in_userReset = id43out_output;

    HWOffsetFix<17,0,UNSIGNED> id45x_1;
    HWOffsetFix<1,0,UNSIGNED> id45x_2;
    HWOffsetFix<1,0,UNSIGNED> id45x_3;
    HWOffsetFix<1,0,UNSIGNED> id45x_4;
    HWOffsetFix<17,0,UNSIGNED> id45x_5e_1t_1e_1;

    id45out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id45st_count)));
    (id45x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id45st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id45x_2) = (gt_fixed((id45x_1),id45in_max));
    (id45x_3) = (and_fixed(id45in_enable,(not_fixed((id45x_2)))));
    (id45x_4) = (c_hw_fix_1_0_uns_bits);
    id45out_wrap = (id45x_4);
    if((id45in_userReset.getValueAsBool())) {
      (id45st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id45x_3).getValueAsBool())) {
        if(((id45x_4).getValueAsBool())) {
          (id45st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id45x_5e_1t_1e_1) = (id45x_1);
          (id45st_count) = (id45x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 252 (NodeConstantRawBits)
  }
  { // Node ID: 47 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id47in_a = id45out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id47in_b = id252out_value;

    id47out_result[(getCycle()+1)%2] = (eq_fixed(id47in_a,id47in_b));
  }
  { // Node ID: 230 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id230in_input = id28out_output;

    id230out_output[(getCycle()+1)%2] = id230in_input;
  }
  { // Node ID: 214 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id214in_input = id88out_ctr_en;

    id214out_output[(getCycle()+1)%2] = id214in_input;
  }
  { // Node ID: 215 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id215in_input = id208out_output;

    id215out_output[(getCycle()+19)%20] = id215in_input;
  }
  { // Node ID: 216 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id216in_input = id88out_rst_en;

    id216out_output[(getCycle()+1)%2] = id216in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id207out_output;

  { // Node ID: 207 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id207in_input = id216out_output[getCycle()%2];

    id207out_output = id207in_input;
  }
  { // Node ID: 217 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id217in_input = id207out_output;

    id217out_output[(getCycle()+17)%18] = id217in_input;
  }
  { // Node ID: 218 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id218in_input = id19out_s1_en;

    id218out_output[(getCycle()+18)%19] = id218in_input;
  }
  { // Node ID: 219 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id219in_input = id19out_sm_done;

    id219out_output[(getCycle()+1)%2] = id219in_input;
  }
  { // Node ID: 220 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id220in_input = id14out_sm_done;

    id220out_output[(getCycle()+1)%2] = id220in_input;
  }
  { // Node ID: 246 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (26l)))
  { // Node ID: 99 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id99in_enable = id95out_ctr_en;
    const HWOffsetFix<9,0,UNSIGNED> &id99in_max = id246out_value;

    HWOffsetFix<10,0,UNSIGNED> id99x_1;
    HWOffsetFix<1,0,UNSIGNED> id99x_2;
    HWOffsetFix<1,0,UNSIGNED> id99x_3;
    HWOffsetFix<10,0,UNSIGNED> id99x_4t_1e_1;

    id99out_count = (cast_fixed2fixed<9,0,UNSIGNED,TRUNCATE>((id99st_count)));
    (id99x_1) = (add_fixed<10,0,UNSIGNED,TRUNCATE>((id99st_count),(c_hw_fix_10_0_uns_bits_1)));
    (id99x_2) = (gte_fixed((id99x_1),(cast_fixed2fixed<10,0,UNSIGNED,TRUNCATE>(id99in_max))));
    (id99x_3) = (and_fixed((id99x_2),id99in_enable));
    id99out_wrap = (id99x_3);
    if((id99in_enable.getValueAsBool())) {
      if(((id99x_3).getValueAsBool())) {
        (id99st_count) = (c_hw_fix_10_0_uns_bits);
      }
      else {
        (id99x_4t_1e_1) = (id99x_1);
        (id99st_count) = (id99x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id100out_output;

  { // Node ID: 100 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id100in_input = id99out_wrap;

    id100out_output = id100in_input;
  }
  { // Node ID: 221 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id221in_input = id100out_output;

    id221out_output[(getCycle()+1)%2] = id221in_input;
  }
  { // Node ID: 102 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id102in_a = id95out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id102in_b = id221out_output[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id102x_1;

    (id102x_1) = (and_fixed(id102in_a,id102in_b));
    id102out_result[(getCycle()+1)%2] = (id102x_1);
  }
  { // Node ID: 222 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id222in_input = id211out_output;

    id222out_output[(getCycle()+23)%24] = id222in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id210out_output;

  { // Node ID: 210 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id210in_input = id95out_rst_en;

    id210out_output = id210in_input;
  }
  { // Node ID: 223 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id223in_input = id210out_output;

    id223out_output[(getCycle()+22)%23] = id223in_input;
  }
  { // Node ID: 224 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id224in_input = id9out_s1_en;

    id224out_output[(getCycle()+22)%23] = id224in_input;
  }
  { // Node ID: 225 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id225in_input = id110out_ctr_en;

    id225out_output[(getCycle()+1)%2] = id225in_input;
  }
  { // Node ID: 226 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id226in_input = id110out_rst_en;

    id226out_output[(getCycle()+1)%2] = id226in_input;
  }
  { // Node ID: 227 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id227in_input = id9out_s2_en;

    id227out_output[(getCycle()+1)%2] = id227in_input;
  }
  { // Node ID: 251 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 119 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id119in_enable = id1out_intr_en;
    const HWOffsetFix<33,0,UNSIGNED> &id119in_max = id251out_value;

    HWOffsetFix<33,0,UNSIGNED> id119x_1;
    HWOffsetFix<1,0,UNSIGNED> id119x_2;
    HWOffsetFix<1,0,UNSIGNED> id119x_3;
    HWOffsetFix<33,0,UNSIGNED> id119x_4t_1e_1;

    id119out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id119st_count)));
    (id119x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id119st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id119x_2) = (gte_fixed((id119x_1),id119in_max));
    (id119x_3) = (and_fixed((id119x_2),id119in_enable));
    id119out_wrap = (id119x_3);
    if((id119in_enable.getValueAsBool())) {
      if(((id119x_3).getValueAsBool())) {
        (id119st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id119x_4t_1e_1) = (id119x_1);
        (id119st_count) = (id119x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 228 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id228in_input = id119out_wrap;

    id228out_output[(getCycle()+1)%2] = id228in_input;
  }
  { // Node ID: 229 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id229in_input = id9out_sm_done;

    id229out_output[(getCycle()+1)%2] = id229in_input;
  }
  { // Node ID: 231 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id231in_input = id27out_memStart;

    id231out_output[(getCycle()+1)%2] = id231in_input;
  }
  { // Node ID: 250 (NodeConstantRawBits)
  }
  { // Node ID: 50 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id50in_a = id45out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id50in_b = id250out_value;

    id50out_result[(getCycle()+1)%2] = (eq_fixed(id50in_a,id50in_b));
  }
  { // Node ID: 51 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id51in_a = id231out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id51in_b = id50out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id51x_1;

    (id51x_1) = (and_fixed(id51in_a,id51in_b));
    id51out_result[(getCycle()+1)%2] = (id51x_1);
  }
  { // Node ID: 69 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id70out_result;

  { // Node ID: 70 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id70in_a = id69out_io_DRAM783_void825_in_cmd_force_disabled;

    id70out_result = (not_fixed(id70in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id71out_result;

  { // Node ID: 71 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id71in_a = id51out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id71in_b = id70out_result;

    HWOffsetFix<1,0,UNSIGNED> id71x_1;

    (id71x_1) = (and_fixed(id71in_a,id71in_b));
    id71out_result = (id71x_1);
  }
  { // Node ID: 175 (NodeConstantRawBits)
  }
  { // Node ID: 180 (NodeConstantRawBits)
  }
  { // Node ID: 56 (NodeConstantRawBits)
  }
  HWRawBits<8> id76out_output;

  { // Node ID: 76 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id76in_input = id56out_value;

    id76out_output = (cast_fixed2bits(id76in_input));
  }
  { // Node ID: 185 (NodeConstantRawBits)
  }
  { // Node ID: 189 (NodeConstantRawBits)
  }
  HWRawBits<40> id75out_result;

  { // Node ID: 75 (NodeCat)
    const HWRawBits<8> &id75in_in0 = id185out_value;
    const HWRawBits<32> &id75in_in1 = id189out_value;

    id75out_result = (cat(id75in_in0,id75in_in1));
  }
  HWRawBits<48> id77out_result;

  { // Node ID: 77 (NodeCat)
    const HWRawBits<8> &id77in_in0 = id76out_output;
    const HWRawBits<40> &id77in_in1 = id75out_result;

    id77out_result = (cat(id77in_in0,id77in_in1));
  }
  HWRawBits<63> id79out_result;

  { // Node ID: 79 (NodeCat)
    const HWRawBits<15> &id79in_in0 = id180out_value;
    const HWRawBits<48> &id79in_in1 = id77out_result;

    id79out_result = (cat(id79in_in0,id79in_in1));
  }
  HWRawBits<64> id81out_result;

  { // Node ID: 81 (NodeCat)
    const HWRawBits<1> &id81in_in0 = id175out_value;
    const HWRawBits<63> &id81in_in1 = id79out_result;

    id81out_result = (cat(id81in_in0,id81in_in1));
  }
  if ( (getFillLevel() >= (6l)) && (getFlushLevel() < (6l)|| !isFlushingActive() ))
  { // Node ID: 72 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id72in_output_control = id71out_result;
    const HWRawBits<64> &id72in_data = id81out_result;

    bool id72x_1;

    (id72x_1) = ((id72in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(6l))&(isFlushingActive()))));
    if((id72x_1)) {
      writeOutput(m_DRAM783_void825_in_cmd, id72in_data);
    }
  }
  { // Node ID: 238 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id238in_input = id10out_output;

    id238out_output[(getCycle()+27)%28] = id238in_input;
  }
  { // Node ID: 244 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id244in_input = id222out_output[getCycle()%24];

    id244out_output[(getCycle()+2)%3] = id244in_input;
  }
  { // Node ID: 245 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id245in_input = id244out_output[getCycle()%3];

    id245out_output[(getCycle()+1)%2] = id245in_input;
  }
  HWOffsetFix<8,0,UNSIGNED> id94out_o;

  { // Node ID: 94 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id94in_i = id91out_counter0;

    id94out_o = (cast_fixed2fixed<8,0,UNSIGNED,TONEAR>(id94in_i));
  }
  { // Node ID: 232 (NodeFIFO)
    const HWOffsetFix<8,0,UNSIGNED> &id232in_input = id94out_o;

    id232out_output[(getCycle()+4)%5] = id232in_input;
  }
  { // Node ID: 82 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id83out_result;

  { // Node ID: 83 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id83in_a = id82out_io_DRAM783_void825_in_force_disabled;

    id83out_result = (not_fixed(id83in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id84out_result;

  { // Node ID: 84 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id84in_a = id88out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id84in_b = id83out_result;

    HWOffsetFix<1,0,UNSIGNED> id84x_1;

    (id84x_1) = (and_fixed(id84in_a,id84in_b));
    id84out_result = (id84x_1);
  }
  if ( (getFillLevel() >= (22l)))
  { // Node ID: 85 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id85in_enable = id84out_result;

    (id85st_read_next_cycle) = ((id85in_enable.getValueAsBool())&(!(((getFlushLevel())>=(22l))&(isFlushingActive()))));
    queueReadRequest(m_DRAM783_void825_in, id85st_read_next_cycle.getValueAsBool());
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id87out_output;

  { // Node ID: 87 (NodeReinterpret)
    const HWRawBits<32> &id87in_input = id85out_data;

    id87out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id87in_input));
  }
  { // Node ID: 243 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id243in_input = id214out_output[getCycle()%2];

    id243out_output[(getCycle()+4)%5] = id243in_input;
  }
  HWOffsetFix<8,0,UNSIGNED> id106out_o;

  { // Node ID: 106 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id106in_i = id103out_counter0;

    id106out_o = (cast_fixed2fixed<8,0,UNSIGNED,TONEAR>(id106in_i));
  }
  if ( (getFillLevel() >= (27l)))
  { // Node ID: 159 (NodeRAM)
    const bool id159_inputvalid = !(isFlushingActive() && getFlushLevel() >= (27l));
    const HWOffsetFix<8,0,UNSIGNED> &id159in_addrA = id232out_output[getCycle()%5];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id159in_dina = id87out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id159in_wea = id243out_output[getCycle()%5];
    const HWOffsetFix<8,0,UNSIGNED> &id159in_addrB = id106out_o;

    long id159x_1;
    long id159x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id159x_3;

    (id159x_1) = (id159in_addrA.getValueAsLong());
    (id159x_2) = (id159in_addrB.getValueAsLong());
    switch(((long)((id159x_2)<(155l)))) {
      case 0l:
        id159x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id159x_3 = (id159sta_ram_store[(id159x_2)]);
        break;
      default:
        id159x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id159out_doutb[(getCycle()+2)%3] = (id159x_3);
    if(((id159in_wea.getValueAsBool())&id159_inputvalid)) {
      if(((id159x_1)<(155l))) {
        (id159sta_ram_store[(id159x_1)]) = id159in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_1("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 159) on port A, ram depth is 155.")));
      }
    }
  }
  { // Node ID: 107 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id107in_a = id95out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id107in_b = id221out_output[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id107x_1;

    (id107x_1) = (and_fixed(id107in_a,id107in_b));
    id107out_result[(getCycle()+1)%2] = (id107x_1);
  }
  { // Node ID: 236 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id236in_input = id107out_result[getCycle()%2];

    id236out_output[(getCycle()+2)%3] = id236in_input;
  }
  if ( (getFillLevel() >= (29l)))
  { // Node ID: 108 (NodeAccumulator)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id108in_summand = id159out_doutb[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id108in_clearAccumulate = id244out_output[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id108in_enable = id236out_output[getCycle()%3];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id108x_1;

    (id108x_1) = id108in_summand;
    if(((id108st_clear_reg).getValueAsBool())) {
      if((id108in_enable.getValueAsBool())) {
        (id108st_hold_reg) = (id108x_1);
      }
      else {
        (id108st_hold_reg) = (c_hw_fix_32_0_sgn_bits_2);
      }
    }
    else {
      if((id108in_enable.getValueAsBool())) {
        (id108st_hold_reg) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((id108st_hold_reg),(id108x_1)));
      }
    }
    id108out_accumulate[(getCycle()+1)%2] = (id108st_hold_reg);
    (id108st_clear_reg) = id108in_clearAccumulate;
  }
  { // Node ID: 109 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (30l)))
  { // Node ID: 2 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id2in_load = id245out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id2in_input = id108out_accumulate[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id2in_user_reset = id109out_value;

    if((id2in_user_reset.getValueAsBool())) {
      (id2st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id2in_load.getValueAsBool())) {
        (id2st_holdreg) = id2in_input;
      }
    }
    id2out_output[(getCycle()+1)%2] = (id2st_holdreg);
  }
  if ( (getFillLevel() >= (31l)) && (getFlushLevel() < (31l)|| !isFlushingActive() ))
  { // Node ID: 117 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id117in_load = id238out_output[getCycle()%28];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id117in_data = id2out_output[getCycle()%2];

    bool id117x_1;

    (id117x_1) = ((id117in_load.getValueAsBool())&(!(((getFlushLevel())>=(31l))&(isFlushingActive()))));
    if((id117x_1)) {
      setMappedRegValue("argout784", id117in_data);
    }
  }
  { // Node ID: 239 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id239in_input = id1out_intr_en;

    id239out_output[(getCycle()+1)%2] = id239in_input;
  }
  { // Node ID: 249 (NodeConstantRawBits)
  }
  { // Node ID: 122 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id122in_a = id119out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id122in_b = id249out_value;

    id122out_result[(getCycle()+1)%2] = (eq_fixed(id122in_a,id122in_b));
  }
  { // Node ID: 123 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id123in_a = id239out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id123in_b = id122out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id123x_1;

    (id123x_1) = (and_fixed(id123in_a,id123in_b));
    id123out_result[(getCycle()+1)%2] = (id123x_1);
  }
  { // Node ID: 139 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id140out_result;

  { // Node ID: 140 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id140in_a = id139out_io_intrCmd_force_disabled;

    id140out_result = (not_fixed(id140in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id141out_result;

  { // Node ID: 141 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id141in_a = id123out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id141in_b = id140out_result;

    HWOffsetFix<1,0,UNSIGNED> id141x_1;

    (id141x_1) = (and_fixed(id141in_a,id141in_b));
    id141out_result = (id141x_1);
  }
  HWRawBits<1> id150out_output;

  { // Node ID: 150 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id150in_input = id239out_output[getCycle()%2];

    id150out_output = (cast_fixed2bits(id150in_input));
  }
  { // Node ID: 241 (NodeFIFO)
    const HWRawBits<1> &id241in_input = id150out_output;

    id241out_output[(getCycle()+1)%2] = id241in_input;
  }
  { // Node ID: 194 (NodeConstantRawBits)
  }
  { // Node ID: 196 (NodeConstantRawBits)
  }
  HWRawBits<8> id146out_output;

  { // Node ID: 146 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id146in_input = id196out_value;

    id146out_output = (cast_fixed2bits(id146in_input));
  }
  { // Node ID: 198 (NodeConstantRawBits)
  }
  { // Node ID: 199 (NodeConstantRawBits)
  }
  HWRawBits<40> id145out_result;

  { // Node ID: 145 (NodeCat)
    const HWRawBits<8> &id145in_in0 = id198out_value;
    const HWRawBits<32> &id145in_in1 = id199out_value;

    id145out_result = (cat(id145in_in0,id145in_in1));
  }
  HWRawBits<48> id147out_result;

  { // Node ID: 147 (NodeCat)
    const HWRawBits<8> &id147in_in0 = id146out_output;
    const HWRawBits<40> &id147in_in1 = id145out_result;

    id147out_result = (cat(id147in_in0,id147in_in1));
  }
  HWRawBits<63> id149out_result;

  { // Node ID: 149 (NodeCat)
    const HWRawBits<15> &id149in_in0 = id194out_value;
    const HWRawBits<48> &id149in_in1 = id147out_result;

    id149out_result = (cat(id149in_in0,id149in_in1));
  }
  HWRawBits<64> id151out_result;

  { // Node ID: 151 (NodeCat)
    const HWRawBits<1> &id151in_in0 = id241out_output[getCycle()%2];
    const HWRawBits<63> &id151in_in1 = id149out_result;

    id151out_result = (cat(id151in_in0,id151in_in1));
  }
  if ( (getFillLevel() >= (6l)) && (getFlushLevel() < (6l)|| !isFlushingActive() ))
  { // Node ID: 142 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id142in_output_control = id141out_result;
    const HWRawBits<64> &id142in_data = id151out_result;

    bool id142x_1;

    (id142x_1) = ((id142in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(6l))&(isFlushingActive()))));
    if((id142x_1)) {
      writeOutput(m_intrCmd, id142in_data);
    }
  }
  { // Node ID: 152 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 153 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id153in_load = id152out_value;
    const HWOffsetFix<64,0,UNSIGNED> &id153in_data = id1out_cycles;

    bool id153x_1;

    (id153x_1) = ((id153in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id153x_1)) {
      setMappedRegValue("cycles", id153in_data);
    }
  }
  { // Node ID: 155 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id156out_result;

  { // Node ID: 156 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id156in_a = id155out_io_intrStream_force_disabled;

    id156out_result = (not_fixed(id156in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id157out_result;

  { // Node ID: 157 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id157in_a = id239out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id157in_b = id156out_result;

    HWOffsetFix<1,0,UNSIGNED> id157x_1;

    (id157x_1) = (and_fixed(id157in_a,id157in_b));
    id157out_result = (id157x_1);
  }
  { // Node ID: 154 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)) && (getFlushLevel() < (5l)|| !isFlushingActive() ))
  { // Node ID: 158 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id158in_output_control = id157out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id158in_data = id154out_value;

    bool id158x_1;

    (id158x_1) = ((id158in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(5l))&(isFlushingActive()))));
    if((id158x_1)) {
      writeOutput(m_intrStream, id158in_data);
    }
  }
  { // Node ID: 164 (NodeConstantRawBits)
  }
  { // Node ID: 248 (NodeConstantRawBits)
  }
  { // Node ID: 161 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (31l)))
  { // Node ID: 162 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id162in_enable = id248out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id162in_max = id161out_value;

    HWOffsetFix<49,0,UNSIGNED> id162x_1;
    HWOffsetFix<1,0,UNSIGNED> id162x_2;
    HWOffsetFix<1,0,UNSIGNED> id162x_3;
    HWOffsetFix<49,0,UNSIGNED> id162x_4t_1e_1;

    id162out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id162st_count)));
    (id162x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id162st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id162x_2) = (gte_fixed((id162x_1),id162in_max));
    (id162x_3) = (and_fixed((id162x_2),id162in_enable));
    id162out_wrap = (id162x_3);
    if((id162in_enable.getValueAsBool())) {
      if(((id162x_3).getValueAsBool())) {
        (id162st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id162x_4t_1e_1) = (id162x_1);
        (id162st_count) = (id162x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id163out_output;

  { // Node ID: 163 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id163in_input = id162out_count;

    id163out_output = id163in_input;
  }
  if ( (getFillLevel() >= (32l)) && (getFlushLevel() < (32l)|| !isFlushingActive() ))
  { // Node ID: 165 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id165in_load = id164out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id165in_data = id163out_output;

    bool id165x_1;

    (id165x_1) = ((id165in_load.getValueAsBool())&(!(((getFlushLevel())>=(32l))&(isFlushingActive()))));
    if((id165x_1)) {
      setMappedRegValue("current_run_cycle_count", id165in_data);
    }
  }
  { // Node ID: 247 (NodeConstantRawBits)
  }
  { // Node ID: 167 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 168 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id168in_enable = id247out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id168in_max = id167out_value;

    HWOffsetFix<49,0,UNSIGNED> id168x_1;
    HWOffsetFix<1,0,UNSIGNED> id168x_2;
    HWOffsetFix<1,0,UNSIGNED> id168x_3;
    HWOffsetFix<49,0,UNSIGNED> id168x_4t_1e_1;

    id168out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id168st_count)));
    (id168x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id168st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id168x_2) = (gte_fixed((id168x_1),id168in_max));
    (id168x_3) = (and_fixed((id168x_2),id168in_enable));
    id168out_wrap = (id168x_3);
    if((id168in_enable.getValueAsBool())) {
      if(((id168x_3).getValueAsBool())) {
        (id168st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id168x_4t_1e_1) = (id168x_1);
        (id168st_count) = (id168x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 170 (NodeInputMappedReg)
  }
  { // Node ID: 171 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id171in_a = id168out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id171in_b = id170out_run_cycle_count;

    id171out_result[(getCycle()+1)%2] = (eq_fixed(id171in_a,id171in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 169 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id169in_start = id171out_result[getCycle()%2];

    if((id169in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
