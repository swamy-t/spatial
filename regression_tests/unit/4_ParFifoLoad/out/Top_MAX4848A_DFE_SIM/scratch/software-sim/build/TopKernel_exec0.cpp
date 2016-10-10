#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "TopKernel.h"

namespace maxcompilersim {

void TopKernel::execute0() {
  { // Node ID: 372 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id89out_output;

  { // Node ID: 89 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id89in_input = id88out_result[getCycle()%2];

    id89out_output = id89in_input;
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 76 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id76in_memDone = id89out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id76in_sm_en = id328out_output[getCycle()%2];

    m_sm_DRAM1836_void1920_inldSM.inputdata_memDone = id76in_memDone.getBitString();
    m_sm_DRAM1836_void1920_inldSM.inputdata_sm_en = id76in_sm_en.getBitString();
    m_sm_DRAM1836_void1920_inldSM.execute(true);
    id76out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1836_void1920_inldSM.outputdata_memStart));
    id76out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1836_void1920_inldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id77out_output;

  { // Node ID: 77 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id77in_input = id76out_sm_done;

    id77out_output = id77in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id84out_output;

  { // Node ID: 84 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id84in_input = id77out_output;

    id84out_output = id84in_input;
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 86 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id86in_enable = id76out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id86in_max = id372out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id86in_userReset = id84out_output;

    HWOffsetFix<17,0,UNSIGNED> id86x_1;
    HWOffsetFix<1,0,UNSIGNED> id86x_2;
    HWOffsetFix<1,0,UNSIGNED> id86x_3;
    HWOffsetFix<1,0,UNSIGNED> id86x_4;
    HWOffsetFix<17,0,UNSIGNED> id86x_5e_1t_1e_1;

    id86out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id86st_count)));
    (id86x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id86st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id86x_2) = (gt_fixed((id86x_1),id86in_max));
    (id86x_3) = (and_fixed(id86in_enable,(not_fixed((id86x_2)))));
    (id86x_4) = (c_hw_fix_1_0_uns_bits);
    id86out_wrap = (id86x_4);
    if((id86in_userReset.getValueAsBool())) {
      (id86st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id86x_3).getValueAsBool())) {
        if(((id86x_4).getValueAsBool())) {
          (id86st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id86x_5e_1t_1e_1) = (id86x_1);
          (id86st_count) = (id86x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 371 (NodeConstantRawBits)
  }
  { // Node ID: 88 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id88in_a = id86out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id88in_b = id371out_value;

    id88out_result[(getCycle()+1)%2] = (eq_fixed(id88in_a,id88in_b));
  }
  { // Node ID: 70 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 68 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id68in_s0_done = id77out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id68in_sm_en = id327out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id68in_sm_numIter = id70out_value;

    m_sm_void1922_sm.inputdata_s0_done = id68in_s0_done.getBitString();
    m_sm_void1922_sm.inputdata_sm_en = id68in_sm_en.getBitString();
    m_sm_void1922_sm.inputdata_sm_numIter = id68in_sm_numIter.getBitString();
    m_sm_void1922_sm.execute(true);
    id68out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1922_sm.outputdata_rst_en));
    id68out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1922_sm.outputdata_s0_en));
    id68out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1922_sm.outputdata_sm_done));
    id68out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1922_sm.outputdata_sm_last));
  }
  HWOffsetFix<1,0,UNSIGNED> id69out_output;

  { // Node ID: 69 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id69in_input = id68out_sm_done;

    id69out_output = id69in_input;
  }
  { // Node ID: 370 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id150out_output;

  { // Node ID: 150 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id150in_input = id149out_result[getCycle()%2];

    id150out_output = id150in_input;
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 137 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id137in_memDone = id150out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id137in_sm_en = id312out_output[getCycle()%2];

    m_sm_DRAM1837_void1923_inldSM.inputdata_memDone = id137in_memDone.getBitString();
    m_sm_DRAM1837_void1923_inldSM.inputdata_sm_en = id137in_sm_en.getBitString();
    m_sm_DRAM1837_void1923_inldSM.execute(true);
    id137out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1837_void1923_inldSM.outputdata_memStart));
    id137out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1837_void1923_inldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id138out_output;

  { // Node ID: 138 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id138in_input = id137out_sm_done;

    id138out_output = id138in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id145out_output;

  { // Node ID: 145 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id145in_input = id138out_output;

    id145out_output = id145in_input;
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 147 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id147in_enable = id137out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id147in_max = id370out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id147in_userReset = id145out_output;

    HWOffsetFix<17,0,UNSIGNED> id147x_1;
    HWOffsetFix<1,0,UNSIGNED> id147x_2;
    HWOffsetFix<1,0,UNSIGNED> id147x_3;
    HWOffsetFix<1,0,UNSIGNED> id147x_4;
    HWOffsetFix<17,0,UNSIGNED> id147x_5e_1t_1e_1;

    id147out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id147st_count)));
    (id147x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id147st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id147x_2) = (gt_fixed((id147x_1),id147in_max));
    (id147x_3) = (and_fixed(id147in_enable,(not_fixed((id147x_2)))));
    (id147x_4) = (c_hw_fix_1_0_uns_bits);
    id147out_wrap = (id147x_4);
    if((id147in_userReset.getValueAsBool())) {
      (id147st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id147x_3).getValueAsBool())) {
        if(((id147x_4).getValueAsBool())) {
          (id147st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id147x_5e_1t_1e_1) = (id147x_1);
          (id147st_count) = (id147x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 369 (NodeConstantRawBits)
  }
  { // Node ID: 149 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id149in_a = id147out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id149in_b = id369out_value;

    id149out_result[(getCycle()+1)%2] = (eq_fixed(id149in_a,id149in_b));
  }
  { // Node ID: 131 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 129 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id129in_s0_done = id138out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id129in_sm_en = id313out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id129in_sm_numIter = id131out_value;

    m_sm_void1925_sm.inputdata_s0_done = id129in_s0_done.getBitString();
    m_sm_void1925_sm.inputdata_sm_en = id129in_sm_en.getBitString();
    m_sm_void1925_sm.inputdata_sm_numIter = id129in_sm_numIter.getBitString();
    m_sm_void1925_sm.execute(true);
    id129out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1925_sm.outputdata_rst_en));
    id129out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1925_sm.outputdata_s0_en));
    id129out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1925_sm.outputdata_sm_done));
    id129out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1925_sm.outputdata_sm_last));
  }
  { // Node ID: 312 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id312in_input = id129out_s0_en;

    id312out_output[(getCycle()+1)%2] = id312in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id130out_output;

  { // Node ID: 130 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id130in_input = id129out_sm_done;

    id130out_output = id130in_input;
  }
  if ( (getFillLevel() >= (42l)))
  { // Node ID: 198 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id198in_en = id197out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id198in_max0 = id315out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id198in_reset = id316out_output[getCycle()%39];

    m_sm_CounterChain1930_sm.inputdata_en = id198in_en.getBitString();
    m_sm_CounterChain1930_sm.inputdata_max0 = id198in_max0.getBitString();
    m_sm_CounterChain1930_sm.inputdata_reset = id198in_reset.getBitString();
    m_sm_CounterChain1930_sm.execute(true);
    id198out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1930_sm.outputdata_counter0) ));
    id198out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1930_sm.outputdata_done));
    id198out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1930_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id199out_output;

  { // Node ID: 199 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id199in_input = id198out_done;

    id199out_output = id199in_input;
  }
  { // Node ID: 32 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (41l)))
  { // Node ID: 190 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id190in_ctr_done = id199out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id190in_rst_done = id318out_output[getCycle()%37];
    const HWOffsetFix<1,0,UNSIGNED> &id190in_sm_en = id319out_output[getCycle()%38];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id190in_sm_maxIn_0 = id32out_value;

    m_sm_pipe1940_sm.inputdata_ctr_done = id190in_ctr_done.getBitString();
    m_sm_pipe1940_sm.inputdata_rst_done = id190in_rst_done.getBitString();
    m_sm_pipe1940_sm.inputdata_sm_en = id190in_sm_en.getBitString();
    m_sm_pipe1940_sm.inputdata_sm_maxIn_0 = id190in_sm_maxIn_0.getBitString();
    m_sm_pipe1940_sm.execute(true);
    id190out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1940_sm.outputdata_ctr_en));
    id190out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe1940_sm.outputdata_ctr_maxOut_0) ));
    id190out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1940_sm.outputdata_rst_en));
    id190out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1940_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id309out_output;

  { // Node ID: 309 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id309in_input = id190out_sm_done;

    id309out_output = id309in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id208out_output;

  { // Node ID: 208 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id208in_input = id320out_output[getCycle()%2];

    id208out_output = id208in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id310out_output;

  { // Node ID: 310 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id310in_input = id321out_output[getCycle()%2];

    id310out_output = id310in_input;
  }
  { // Node ID: 207 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 204 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id204in_ctr_done = id208out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id204in_rst_done = id310out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id204in_sm_en = id322out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id204in_sm_maxIn_0 = id207out_value;

    m_sm_void1944_sm.inputdata_ctr_done = id204in_ctr_done.getBitString();
    m_sm_void1944_sm.inputdata_rst_done = id204in_rst_done.getBitString();
    m_sm_void1944_sm.inputdata_sm_en = id204in_sm_en.getBitString();
    m_sm_void1944_sm.inputdata_sm_maxIn_0 = id204in_sm_maxIn_0.getBitString();
    m_sm_void1944_sm.execute(true);
    id204out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1944_sm.outputdata_ctr_en));
    id204out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_void1944_sm.outputdata_ctr_maxOut_0) ));
    id204out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1944_sm.outputdata_rst_en));
    id204out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1944_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id311out_output;

  { // Node ID: 311 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id311in_input = id204out_sm_done;

    id311out_output = id311in_input;
  }
  { // Node ID: 368 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 217 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id217in_enable = id323out_output[getCycle()%2];
    const HWOffsetFix<33,0,UNSIGNED> &id217in_max = id368out_value;

    HWOffsetFix<33,0,UNSIGNED> id217x_1;
    HWOffsetFix<1,0,UNSIGNED> id217x_2;
    HWOffsetFix<1,0,UNSIGNED> id217x_3;
    HWOffsetFix<33,0,UNSIGNED> id217x_4t_1e_1;

    id217out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id217st_count)));
    (id217x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id217st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id217x_2) = (gte_fixed((id217x_1),id217in_max));
    (id217x_3) = (and_fixed((id217x_2),id217in_enable));
    id217out_wrap = (id217x_3);
    if((id217in_enable.getValueAsBool())) {
      if(((id217x_3).getValueAsBool())) {
        (id217st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id217x_4t_1e_1) = (id217x_1);
        (id217st_count) = (id217x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id218out_output;

  { // Node ID: 218 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id218in_input = id217out_wrap;

    id218out_output = id218in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id36out_output;

  { // Node ID: 36 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id36in_input = id324out_output[getCycle()%2];

    id36out_output = id36in_input;
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_intr_done = id218out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id1in_run_done = id36out_output;
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
  { // Node ID: 37 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 35 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id35in_s0_done = id325out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id35in_sm_en = id1out_run_en;
    const HWOffsetFix<32,0,UNSIGNED> &id35in_sm_numIter = id37out_value;

    m_sm_void1948_sm.inputdata_s0_done = id35in_s0_done.getBitString();
    m_sm_void1948_sm.inputdata_sm_en = id35in_sm_en.getBitString();
    m_sm_void1948_sm.inputdata_sm_numIter = id35in_sm_numIter.getBitString();
    m_sm_void1948_sm.execute(true);
    id35out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1948_sm.outputdata_rst_en));
    id35out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1948_sm.outputdata_s0_en));
    id35out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1948_sm.outputdata_sm_done));
  }
  HWOffsetFix<32,0,UNSIGNED> id46out_o;

  { // Node ID: 46 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id46in_i = id45out_result[getCycle()%39];

    id46out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id46in_i));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 40 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id40in_s0_done = id326out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id40in_s1_done = id309out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id40in_s2_done = id311out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id40in_sm_en = id35out_s0_en;
    const HWOffsetFix<32,0,UNSIGNED> &id40in_sm_numIter = id46out_o;

    m_sm_metapipe1946_sm.inputdata_s0_done = id40in_s0_done.getBitString();
    m_sm_metapipe1946_sm.inputdata_s1_done = id40in_s1_done.getBitString();
    m_sm_metapipe1946_sm.inputdata_s2_done = id40in_s2_done.getBitString();
    m_sm_metapipe1946_sm.inputdata_sm_en = id40in_sm_en.getBitString();
    m_sm_metapipe1946_sm.inputdata_sm_numIter = id40in_sm_numIter.getBitString();
    m_sm_metapipe1946_sm.execute(true);
    id40out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1946_sm.outputdata_rst_en));
    id40out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1946_sm.outputdata_s0_en));
    id40out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1946_sm.outputdata_s1_en));
    id40out_s2_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1946_sm.outputdata_s2_en));
    id40out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1946_sm.outputdata_sm_done));
    id40out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_metapipe1946_sm.outputdata_sm_last));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 66 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id66in_s0_done = id69out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id66in_s1_done = id130out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id66in_sm_en = id40out_s0_en;

    m_sm_void1927_sm.inputdata_s0_done = id66in_s0_done.getBitString();
    m_sm_void1927_sm.inputdata_s1_done = id66in_s1_done.getBitString();
    m_sm_void1927_sm.inputdata_sm_en = id66in_sm_en.getBitString();
    m_sm_void1927_sm.execute(true);
    id66out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1927_sm.outputdata_s0_en));
    id66out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1927_sm.outputdata_s1_en));
    id66out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1927_sm.outputdata_sm_done));
  }
  { // Node ID: 313 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id313in_input = id66out_s1_en;

    id313out_output[(getCycle()+1)%2] = id313in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id67out_output;

  { // Node ID: 67 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id67in_input = id66out_sm_done;

    id67out_output = id67in_input;
  }
  { // Node ID: 326 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id326in_input = id67out_output;

    id326out_output[(getCycle()+1)%2] = id326in_input;
  }
  { // Node ID: 338 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id338in_input = id190out_ctr_en;

    id338out_output[(getCycle()+1)%2] = id338in_input;
  }
  { // Node ID: 358 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (42l)))
  { // Node ID: 194 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id194in_enable = id338out_output[getCycle()%2];
    const HWOffsetFix<9,0,UNSIGNED> &id194in_max = id358out_value;

    HWOffsetFix<10,0,UNSIGNED> id194x_1;
    HWOffsetFix<1,0,UNSIGNED> id194x_2;
    HWOffsetFix<1,0,UNSIGNED> id194x_3;
    HWOffsetFix<10,0,UNSIGNED> id194x_4t_1e_1;

    id194out_count = (cast_fixed2fixed<9,0,UNSIGNED,TRUNCATE>((id194st_count)));
    (id194x_1) = (add_fixed<10,0,UNSIGNED,TRUNCATE>((id194st_count),(c_hw_fix_10_0_uns_bits_1)));
    (id194x_2) = (gte_fixed((id194x_1),(cast_fixed2fixed<10,0,UNSIGNED,TRUNCATE>(id194in_max))));
    (id194x_3) = (and_fixed((id194x_2),id194in_enable));
    id194out_wrap = (id194x_3);
    if((id194in_enable.getValueAsBool())) {
      if(((id194x_3).getValueAsBool())) {
        (id194st_count) = (c_hw_fix_10_0_uns_bits);
      }
      else {
        (id194x_4t_1e_1) = (id194x_1);
        (id194st_count) = (id194x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id195out_output;

  { // Node ID: 195 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id195in_input = id194out_wrap;

    id195out_output = id195in_input;
  }
  { // Node ID: 197 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id197in_a = id190out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id197in_b = id195out_output;

    HWOffsetFix<1,0,UNSIGNED> id197x_1;

    (id197x_1) = (and_fixed(id197in_a,id197in_b));
    id197out_result[(getCycle()+1)%2] = (id197x_1);
  }
  { // Node ID: 315 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id315in_input = id190out_ctr_maxOut_0;

    id315out_output[(getCycle()+1)%2] = id315in_input;
  }
  { // Node ID: 316 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id316in_input = id309out_output;

    id316out_output[(getCycle()+38)%39] = id316in_input;
  }
  { // Node ID: 317 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id317in_input = id190out_rst_en;

    id317out_output[(getCycle()+1)%2] = id317in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id308out_output;

  { // Node ID: 308 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id308in_input = id317out_output[getCycle()%2];

    id308out_output = id308in_input;
  }
  { // Node ID: 318 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id318in_input = id308out_output;

    id318out_output[(getCycle()+36)%37] = id318in_input;
  }
  { // Node ID: 319 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id319in_input = id40out_s1_en;

    id319out_output[(getCycle()+37)%38] = id319in_input;
  }
  { // Node ID: 320 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id320in_input = id204out_ctr_en;

    id320out_output[(getCycle()+1)%2] = id320in_input;
  }
  { // Node ID: 321 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id321in_input = id204out_rst_en;

    id321out_output[(getCycle()+1)%2] = id321in_input;
  }
  { // Node ID: 322 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id322in_input = id40out_s2_en;

    id322out_output[(getCycle()+1)%2] = id322in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id41out_output;

  { // Node ID: 41 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id41in_input = id40out_sm_done;

    id41out_output = id41in_input;
  }
  { // Node ID: 325 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id325in_input = id41out_output;

    id325out_output[(getCycle()+1)%2] = id325in_input;
  }
  { // Node ID: 323 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id323in_input = id1out_intr_en;

    id323out_output[(getCycle()+1)%2] = id323in_input;
  }
  { // Node ID: 324 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id324in_input = id35out_sm_done;

    id324out_output[(getCycle()+1)%2] = id324in_input;
  }
  { // Node ID: 2 (NodeInputMappedReg)
  }
  { // Node ID: 269 (NodeConstantRawBits)
  }
  { // Node ID: 45 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id45in_a = id2out_argin1833;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id45in_b = id269out_value;

    id45out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id45in_a,id45in_b));
  }
  { // Node ID: 327 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id327in_input = id66out_s0_en;

    id327out_output[(getCycle()+1)%2] = id327in_input;
  }
  { // Node ID: 328 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id328in_input = id68out_s0_en;

    id328out_output[(getCycle()+1)%2] = id328in_input;
  }
  { // Node ID: 329 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id329in_input = id76out_memStart;

    id329out_output[(getCycle()+1)%2] = id329in_input;
  }
  { // Node ID: 367 (NodeConstantRawBits)
  }
  { // Node ID: 91 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id91in_a = id86out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id91in_b = id367out_value;

    id91out_result[(getCycle()+1)%2] = (eq_fixed(id91in_a,id91in_b));
  }
  { // Node ID: 92 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id92in_a = id329out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id92in_b = id91out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id92x_1;

    (id92x_1) = (and_fixed(id92in_a,id92in_b));
    id92out_result[(getCycle()+1)%2] = (id92x_1);
  }
  { // Node ID: 330 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id330in_input = id92out_result[getCycle()%2];

    id330out_output[(getCycle()+34)%35] = id330in_input;
  }
  { // Node ID: 110 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id111out_result;

  { // Node ID: 111 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id111in_a = id110out_io_DRAM1836_void1920_in_cmd_force_disabled;

    id111out_result = (not_fixed(id111in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id112out_result;

  { // Node ID: 112 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id112in_a = id330out_output[getCycle()%35];
    const HWOffsetFix<1,0,UNSIGNED> &id112in_b = id111out_result;

    HWOffsetFix<1,0,UNSIGNED> id112x_1;

    (id112x_1) = (and_fixed(id112in_a,id112in_b));
    id112out_result = (id112x_1);
  }
  { // Node ID: 270 (NodeConstantRawBits)
  }
  { // Node ID: 275 (NodeConstantRawBits)
  }
  { // Node ID: 97 (NodeConstantRawBits)
  }
  HWRawBits<8> id117out_output;

  { // Node ID: 117 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id117in_input = id97out_value;

    id117out_output = (cast_fixed2bits(id117in_input));
  }
  { // Node ID: 280 (NodeConstantRawBits)
  }
  { // Node ID: 366 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 47 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id47in_en = id67out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id47in_max0 = id2out_argin1833;
    const HWOffsetFix<1,0,UNSIGNED> &id47in_reset = id41out_output;

    m_sm_CounterChain1919_sm.inputdata_en = id47in_en.getBitString();
    m_sm_CounterChain1919_sm.inputdata_max0 = id47in_max0.getBitString();
    m_sm_CounterChain1919_sm.inputdata_reset = id47in_reset.getBitString();
    m_sm_CounterChain1919_sm.execute(true);
    id47out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1919_sm.outputdata_counter0) ));
    id47out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1919_sm.outputdata_done));
    id47out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1919_sm.outputdata_saturated));
  }
  { // Node ID: 365 (NodeConstantRawBits)
  }
  { // Node ID: 79 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id79in_a = id47out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id79in_b = id365out_value;

    id79out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id79in_a,id79in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id80out_o;

  { // Node ID: 80 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id80in_i = id79out_result[getCycle()%39];

    id80out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id80in_i));
  }
  { // Node ID: 82 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id82in_a = id366out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id82in_b = id80out_o;

    id82out_result[(getCycle()+1)%2] = (add_fixed<32,0,UNSIGNED,TONEAR>(id82in_a,id82in_b));
  }
  HWRawBits<32> id114out_output;

  { // Node ID: 114 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id114in_input = id82out_result[getCycle()%2];

    id114out_output = (cast_fixed2bits(id114in_input));
  }
  HWRawBits<40> id116out_result;

  { // Node ID: 116 (NodeCat)
    const HWRawBits<8> &id116in_in0 = id280out_value;
    const HWRawBits<32> &id116in_in1 = id114out_output;

    id116out_result = (cat(id116in_in0,id116in_in1));
  }
  HWRawBits<48> id118out_result;

  { // Node ID: 118 (NodeCat)
    const HWRawBits<8> &id118in_in0 = id117out_output;
    const HWRawBits<40> &id118in_in1 = id116out_result;

    id118out_result = (cat(id118in_in0,id118in_in1));
  }
  HWRawBits<63> id120out_result;

  { // Node ID: 120 (NodeCat)
    const HWRawBits<15> &id120in_in0 = id275out_value;
    const HWRawBits<48> &id120in_in1 = id118out_result;

    id120out_result = (cat(id120in_in0,id120in_in1));
  }
  HWRawBits<64> id122out_result;

  { // Node ID: 122 (NodeCat)
    const HWRawBits<1> &id122in_in0 = id270out_value;
    const HWRawBits<63> &id122in_in1 = id120out_result;

    id122out_result = (cat(id122in_in0,id122in_in1));
  }
  if ( (getFillLevel() >= (42l)) && (getFlushLevel() < (42l)|| !isFlushingActive() ))
  { // Node ID: 113 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id113in_output_control = id112out_result;
    const HWRawBits<64> &id113in_data = id122out_result;

    bool id113x_1;

    (id113x_1) = ((id113in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(42l))&(isFlushingActive()))));
    if((id113x_1)) {
      writeOutput(m_DRAM1836_void1920_in_cmd, id113in_data);
    }
  }
  { // Node ID: 331 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id331in_input = id137out_memStart;

    id331out_output[(getCycle()+1)%2] = id331in_input;
  }
  { // Node ID: 364 (NodeConstantRawBits)
  }
  { // Node ID: 152 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id152in_a = id147out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id152in_b = id364out_value;

    id152out_result[(getCycle()+1)%2] = (eq_fixed(id152in_a,id152in_b));
  }
  { // Node ID: 153 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id153in_a = id331out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id153in_b = id152out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id153x_1;

    (id153x_1) = (and_fixed(id153in_a,id153in_b));
    id153out_result[(getCycle()+1)%2] = (id153x_1);
  }
  { // Node ID: 332 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id332in_input = id153out_result[getCycle()%2];

    id332out_output[(getCycle()+34)%35] = id332in_input;
  }
  { // Node ID: 171 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id172out_result;

  { // Node ID: 172 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id172in_a = id171out_io_DRAM1837_void1923_in_cmd_force_disabled;

    id172out_result = (not_fixed(id172in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id173out_result;

  { // Node ID: 173 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id173in_a = id332out_output[getCycle()%35];
    const HWOffsetFix<1,0,UNSIGNED> &id173in_b = id172out_result;

    HWOffsetFix<1,0,UNSIGNED> id173x_1;

    (id173x_1) = (and_fixed(id173in_a,id173in_b));
    id173out_result = (id173x_1);
  }
  { // Node ID: 281 (NodeConstantRawBits)
  }
  { // Node ID: 286 (NodeConstantRawBits)
  }
  { // Node ID: 158 (NodeConstantRawBits)
  }
  HWRawBits<8> id178out_output;

  { // Node ID: 178 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id178in_input = id158out_value;

    id178out_output = (cast_fixed2bits(id178in_input));
  }
  { // Node ID: 291 (NodeConstantRawBits)
  }
  { // Node ID: 363 (NodeConstantRawBits)
  }
  { // Node ID: 362 (NodeConstantRawBits)
  }
  { // Node ID: 140 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id140in_a = id47out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id140in_b = id362out_value;

    id140out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id140in_a,id140in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id141out_o;

  { // Node ID: 141 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id141in_i = id140out_result[getCycle()%39];

    id141out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id141in_i));
  }
  { // Node ID: 143 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id143in_a = id363out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id143in_b = id141out_o;

    id143out_result[(getCycle()+1)%2] = (add_fixed<32,0,UNSIGNED,TONEAR>(id143in_a,id143in_b));
  }
  HWRawBits<32> id175out_output;

  { // Node ID: 175 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id175in_input = id143out_result[getCycle()%2];

    id175out_output = (cast_fixed2bits(id175in_input));
  }
  HWRawBits<40> id177out_result;

  { // Node ID: 177 (NodeCat)
    const HWRawBits<8> &id177in_in0 = id291out_value;
    const HWRawBits<32> &id177in_in1 = id175out_output;

    id177out_result = (cat(id177in_in0,id177in_in1));
  }
  HWRawBits<48> id179out_result;

  { // Node ID: 179 (NodeCat)
    const HWRawBits<8> &id179in_in0 = id178out_output;
    const HWRawBits<40> &id179in_in1 = id177out_result;

    id179out_result = (cat(id179in_in0,id179in_in1));
  }
  HWRawBits<63> id181out_result;

  { // Node ID: 181 (NodeCat)
    const HWRawBits<15> &id181in_in0 = id286out_value;
    const HWRawBits<48> &id181in_in1 = id179out_result;

    id181out_result = (cat(id181in_in0,id181in_in1));
  }
  HWRawBits<64> id183out_result;

  { // Node ID: 183 (NodeCat)
    const HWRawBits<1> &id183in_in0 = id281out_value;
    const HWRawBits<63> &id183in_in1 = id181out_result;

    id183out_result = (cat(id183in_in0,id183in_in1));
  }
  if ( (getFillLevel() >= (42l)) && (getFlushLevel() < (42l)|| !isFlushingActive() ))
  { // Node ID: 174 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id174in_output_control = id173out_result;
    const HWRawBits<64> &id174in_data = id183out_result;

    bool id174x_1;

    (id174x_1) = ((id174in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(42l))&(isFlushingActive()))));
    if((id174x_1)) {
      writeOutput(m_DRAM1837_void1923_in_cmd, id174in_data);
    }
  }
  { // Node ID: 348 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id348in_input = id36out_output;

    id348out_output[(getCycle()+64)%65] = id348in_input;
  }
  { // Node ID: 215 (NodeConstantRawBits)
  }
  { // Node ID: 214 (NodeConstantRawBits)
  }
  { // Node ID: 352 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id352in_input = id316out_output[getCycle()%39];

    id352out_output[(getCycle()+23)%24] = id352in_input;
  }
  { // Node ID: 353 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id353in_input = id352out_output[getCycle()%24];

    id353out_output[(getCycle()+1)%2] = id353in_input;
  }
  { // Node ID: 334 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id334in_input = id311out_output;

    id334out_output[(getCycle()+62)%63] = id334in_input;
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
  { // Node ID: 356 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id356in_input = id319out_output[getCycle()%38];

    id356out_output[(getCycle()+25)%26] = id356in_input;
  }
  { // Node ID: 357 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id357in_input = id322out_output[getCycle()%2];

    id357out_output[(getCycle()+61)%62] = id357in_input;
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
  if ( (getFillLevel() >= (66l)))
  { // Node ID: 3 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id3in_broadcast = id215out_value;
    const HWOffsetFix<2,0,UNSIGNED> &id3in_numBlanks = id214out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageDone0 = id353out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageDone1 = id334out_output[getCycle()%63];
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageDone2 = id4out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageDone3 = id6out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageDone4 = id8out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageDone5 = id10out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageDone6 = id12out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageDone7 = id14out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageEn0 = id356out_output[getCycle()%26];
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageEn1 = id357out_output[getCycle()%62];
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageEn2 = id5out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageEn3 = id7out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageEn4 = id9out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageEn5 = id11out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageEn6 = id13out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id3in_stageEn7 = id15out_value;

    m_sm_reg1928_1.inputdata_broadcast = id3in_broadcast.getBitString();
    m_sm_reg1928_1.inputdata_numBlanks = id3in_numBlanks.getBitString();
    m_sm_reg1928_1.inputdata_stageDone0 = id3in_stageDone0.getBitString();
    m_sm_reg1928_1.inputdata_stageDone1 = id3in_stageDone1.getBitString();
    m_sm_reg1928_1.inputdata_stageDone2 = id3in_stageDone2.getBitString();
    m_sm_reg1928_1.inputdata_stageDone3 = id3in_stageDone3.getBitString();
    m_sm_reg1928_1.inputdata_stageDone4 = id3in_stageDone4.getBitString();
    m_sm_reg1928_1.inputdata_stageDone5 = id3in_stageDone5.getBitString();
    m_sm_reg1928_1.inputdata_stageDone6 = id3in_stageDone6.getBitString();
    m_sm_reg1928_1.inputdata_stageDone7 = id3in_stageDone7.getBitString();
    m_sm_reg1928_1.inputdata_stageEn0 = id3in_stageEn0.getBitString();
    m_sm_reg1928_1.inputdata_stageEn1 = id3in_stageEn1.getBitString();
    m_sm_reg1928_1.inputdata_stageEn2 = id3in_stageEn2.getBitString();
    m_sm_reg1928_1.inputdata_stageEn3 = id3in_stageEn3.getBitString();
    m_sm_reg1928_1.inputdata_stageEn4 = id3in_stageEn4.getBitString();
    m_sm_reg1928_1.inputdata_stageEn5 = id3in_stageEn5.getBitString();
    m_sm_reg1928_1.inputdata_stageEn6 = id3in_stageEn6.getBitString();
    m_sm_reg1928_1.inputdata_stageEn7 = id3in_stageEn7.getBitString();
    m_sm_reg1928_1.execute(true);
    id3out_curBuf0 = (HWOffsetFix<2,0,UNSIGNED>(m_sm_reg1928_1.outputdata_curBuf0));
    id3out_curBuf1 = (HWOffsetFix<2,0,UNSIGNED>(m_sm_reg1928_1.outputdata_curBuf1));
  }
  HWOffsetFix<1,0,UNSIGNED> id28out_o;

  { // Node ID: 28 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id28in_i = id3out_curBuf1;

    id28out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id28in_i));
  }
  { // Node ID: 347 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id347in_input = id28out_o;

    id347out_output[(getCycle()+2)%3] = id347in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id18out_o;

  { // Node ID: 18 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id18in_i = id3out_curBuf0;

    id18out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id18in_i));
  }
  { // Node ID: 213 (NodeConstantRawBits)
  }
  { // Node ID: 19 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id19in_sel = id18out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id19in_option0 = id353out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id19in_option1 = id213out_value;

    HWOffsetFix<1,0,UNSIGNED> id19x_1;

    switch((id19in_sel.getValueAsLong())) {
      case 0l:
        id19x_1 = id19in_option0;
        break;
      case 1l:
        id19x_1 = id19in_option1;
        break;
      default:
        id19x_1 = (c_hw_fix_1_0_uns_undef);
        break;
    }
    id19out_result[(getCycle()+1)%2] = (id19x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id16out_o;

  { // Node ID: 16 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id16in_i = id3out_curBuf0;

    id16out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id16in_i));
  }
  { // Node ID: 339 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id339in_input = id195out_output;

    id339out_output[(getCycle()+1)%2] = id339in_input;
  }
  { // Node ID: 196 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id196in_a = id338out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id196in_b = id339out_output[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id196x_1;

    (id196x_1) = (and_fixed(id196in_a,id196in_b));
    id196out_result[(getCycle()+1)%2] = (id196x_1);
  }
  { // Node ID: 340 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id340in_input = id196out_result[getCycle()%2];

    id340out_output[(getCycle()+15)%16] = id340in_input;
  }
  { // Node ID: 123 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id124out_result;

  { // Node ID: 124 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id124in_a = id123out_io_DRAM1836_void1920_in_force_disabled;

    id124out_result = (not_fixed(id124in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id125out_result;

  { // Node ID: 125 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id125in_a = id340out_output[getCycle()%16];
    const HWOffsetFix<1,0,UNSIGNED> &id125in_b = id124out_result;

    HWOffsetFix<1,0,UNSIGNED> id125x_1;

    (id125x_1) = (and_fixed(id125in_a,id125in_b));
    id125out_result = (id125x_1);
  }
  if ( (getFillLevel() >= (58l)))
  { // Node ID: 126 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id126in_enable = id125out_result;

    (id126st_read_next_cycle) = ((id126in_enable.getValueAsBool())&(!(((getFlushLevel())>=(58l))&(isFlushingActive()))));
    queueReadRequest(m_DRAM1836_void1920_in, id126st_read_next_cycle.getValueAsBool());
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id128out_output;

  { // Node ID: 128 (NodeReinterpret)
    const HWRawBits<32> &id128in_input = id126out_data;

    id128out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id128in_input));
  }
  { // Node ID: 184 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id185out_result;

  { // Node ID: 185 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id185in_a = id184out_io_DRAM1837_void1923_in_force_disabled;

    id185out_result = (not_fixed(id185in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id186out_result;

  { // Node ID: 186 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id186in_a = id340out_output[getCycle()%16];
    const HWOffsetFix<1,0,UNSIGNED> &id186in_b = id185out_result;

    HWOffsetFix<1,0,UNSIGNED> id186x_1;

    (id186x_1) = (and_fixed(id186in_a,id186in_b));
    id186out_result = (id186x_1);
  }
  if ( (getFillLevel() >= (58l)))
  { // Node ID: 187 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id187in_enable = id186out_result;

    (id187st_read_next_cycle) = ((id187in_enable.getValueAsBool())&(!(((getFlushLevel())>=(58l))&(isFlushingActive()))));
    queueReadRequest(m_DRAM1837_void1923_in, id187st_read_next_cycle.getValueAsBool());
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id189out_output;

  { // Node ID: 189 (NodeReinterpret)
    const HWRawBits<32> &id189in_input = id187out_data;

    id189out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id189in_input));
  }
  { // Node ID: 203 (NodeMul)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id203in_a = id128out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id203in_b = id189out_output;

    id203out_result[(getCycle()+2)%3] = (mul_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id203in_a,id203in_b));
  }
  { // Node ID: 200 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id200in_a = id338out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id200in_b = id339out_output[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id200x_1;

    (id200x_1) = (and_fixed(id200in_a,id200in_b));
    id200out_result[(getCycle()+1)%2] = (id200x_1);
  }
  { // Node ID: 345 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id345in_input = id200out_result[getCycle()%2];

    id345out_output[(getCycle()+22)%23] = id345in_input;
  }
  if ( (getFillLevel() >= (65l)))
  { // Node ID: 201 (NodeAccumulator)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id201in_summand = id203out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id201in_clearAccumulate = id352out_output[getCycle()%24];
    const HWOffsetFix<1,0,UNSIGNED> &id201in_enable = id345out_output[getCycle()%23];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id201x_1;

    (id201x_1) = id201in_summand;
    if(((id201st_clear_reg).getValueAsBool())) {
      if((id201in_enable.getValueAsBool())) {
        (id201st_hold_reg) = (id201x_1);
      }
      else {
        (id201st_hold_reg) = (c_hw_fix_32_0_sgn_bits_2);
      }
    }
    else {
      if((id201in_enable.getValueAsBool())) {
        (id201st_hold_reg) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((id201st_hold_reg),(id201x_1)));
      }
    }
    id201out_accumulate[(getCycle()+1)%2] = (id201st_hold_reg);
    (id201st_clear_reg) = id201in_clearAccumulate;
  }
  { // Node ID: 212 (NodeConstantRawBits)
  }
  { // Node ID: 17 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id17in_sel = id16out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id17in_option0 = id201out_accumulate[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id17in_option1 = id212out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id17x_1;

    switch((id17in_sel.getValueAsLong())) {
      case 0l:
        id17x_1 = id17in_option0;
        break;
      case 1l:
        id17x_1 = id17in_option1;
        break;
      default:
        id17x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id17out_result[(getCycle()+1)%2] = (id17x_1);
  }
  { // Node ID: 202 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (67l)))
  { // Node ID: 20 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id20in_load = id19out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id20in_input = id17out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id20in_user_reset = id202out_value;

    if((id20in_user_reset.getValueAsBool())) {
      (id20st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id20in_load.getValueAsBool())) {
        (id20st_holdreg) = id20in_input;
      }
    }
    id20out_output[(getCycle()+1)%2] = (id20st_holdreg);
  }
  HWOffsetFix<1,0,UNSIGNED> id23out_o;

  { // Node ID: 23 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id23in_i = id3out_curBuf1;

    id23out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id23in_i));
  }
  { // Node ID: 24 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id24in_sel = id23out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id24in_option0 = id353out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id24in_option1 = id213out_value;

    HWOffsetFix<1,0,UNSIGNED> id24x_1;

    switch((id24in_sel.getValueAsLong())) {
      case 0l:
        id24x_1 = id24in_option0;
        break;
      case 1l:
        id24x_1 = id24in_option1;
        break;
      default:
        id24x_1 = (c_hw_fix_1_0_uns_undef);
        break;
    }
    id24out_result[(getCycle()+1)%2] = (id24x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id21out_o;

  { // Node ID: 21 (NodeCast)
    const HWOffsetFix<2,0,UNSIGNED> &id21in_i = id3out_curBuf1;

    id21out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id21in_i));
  }
  { // Node ID: 22 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id22in_sel = id21out_o;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id22in_option0 = id201out_accumulate[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id22in_option1 = id212out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id22x_1;

    switch((id22in_sel.getValueAsLong())) {
      case 0l:
        id22x_1 = id22in_option0;
        break;
      case 1l:
        id22x_1 = id22in_option1;
        break;
      default:
        id22x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id22out_result[(getCycle()+1)%2] = (id22x_1);
  }
  if ( (getFillLevel() >= (67l)))
  { // Node ID: 25 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id25in_load = id24out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id25in_input = id22out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id25in_user_reset = id202out_value;

    if((id25in_user_reset.getValueAsBool())) {
      (id25st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id25in_load.getValueAsBool())) {
        (id25st_holdreg) = id25in_input;
      }
    }
    id25out_output[(getCycle()+1)%2] = (id25st_holdreg);
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id29out_result;

  { // Node ID: 29 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id29in_sel = id347out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id29in_option0 = id20out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id29in_option1 = id25out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id29x_1;

    switch((id29in_sel.getValueAsLong())) {
      case 0l:
        id29x_1 = id29in_option0;
        break;
      case 1l:
        id29x_1 = id29in_option1;
        break;
      default:
        id29x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id29out_result = (id29x_1);
  }
  if ( (getFillLevel() >= (68l)) && (getFlushLevel() < (68l)|| !isFlushingActive() ))
  { // Node ID: 211 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id211in_load = id348out_output[getCycle()%65];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id211in_data = id29out_result;

    bool id211x_1;

    (id211x_1) = ((id211in_load.getValueAsBool())&(!(((getFlushLevel())>=(68l))&(isFlushingActive()))));
    if((id211x_1)) {
      setMappedRegValue("argout1838", id211in_data);
    }
  }
  { // Node ID: 354 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id354in_input = id323out_output[getCycle()%2];

    id354out_output[(getCycle()+1)%2] = id354in_input;
  }
  { // Node ID: 361 (NodeConstantRawBits)
  }
  { // Node ID: 220 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id220in_a = id217out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id220in_b = id361out_value;

    id220out_result[(getCycle()+1)%2] = (eq_fixed(id220in_a,id220in_b));
  }
  { // Node ID: 221 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id221in_a = id354out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id221in_b = id220out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id221x_1;

    (id221x_1) = (and_fixed(id221in_a,id221in_b));
    id221out_result[(getCycle()+1)%2] = (id221x_1);
  }
  { // Node ID: 237 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id238out_result;

  { // Node ID: 238 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id238in_a = id237out_io_intrCmd_force_disabled;

    id238out_result = (not_fixed(id238in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id239out_result;

  { // Node ID: 239 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id239in_a = id221out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id239in_b = id238out_result;

    HWOffsetFix<1,0,UNSIGNED> id239x_1;

    (id239x_1) = (and_fixed(id239in_a,id239in_b));
    id239out_result = (id239x_1);
  }
  { // Node ID: 355 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id355in_input = id354out_output[getCycle()%2];

    id355out_output[(getCycle()+1)%2] = id355in_input;
  }
  HWRawBits<1> id248out_output;

  { // Node ID: 248 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id248in_input = id355out_output[getCycle()%2];

    id248out_output = (cast_fixed2bits(id248in_input));
  }
  { // Node ID: 296 (NodeConstantRawBits)
  }
  { // Node ID: 298 (NodeConstantRawBits)
  }
  HWRawBits<8> id244out_output;

  { // Node ID: 244 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id244in_input = id298out_value;

    id244out_output = (cast_fixed2bits(id244in_input));
  }
  { // Node ID: 300 (NodeConstantRawBits)
  }
  { // Node ID: 301 (NodeConstantRawBits)
  }
  HWRawBits<40> id243out_result;

  { // Node ID: 243 (NodeCat)
    const HWRawBits<8> &id243in_in0 = id300out_value;
    const HWRawBits<32> &id243in_in1 = id301out_value;

    id243out_result = (cat(id243in_in0,id243in_in1));
  }
  HWRawBits<48> id245out_result;

  { // Node ID: 245 (NodeCat)
    const HWRawBits<8> &id245in_in0 = id244out_output;
    const HWRawBits<40> &id245in_in1 = id243out_result;

    id245out_result = (cat(id245in_in0,id245in_in1));
  }
  HWRawBits<63> id247out_result;

  { // Node ID: 247 (NodeCat)
    const HWRawBits<15> &id247in_in0 = id296out_value;
    const HWRawBits<48> &id247in_in1 = id245out_result;

    id247out_result = (cat(id247in_in0,id247in_in1));
  }
  HWRawBits<64> id249out_result;

  { // Node ID: 249 (NodeCat)
    const HWRawBits<1> &id249in_in0 = id248out_output;
    const HWRawBits<63> &id249in_in1 = id247out_result;

    id249out_result = (cat(id249in_in0,id249in_in1));
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 240 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id240in_output_control = id239out_result;
    const HWRawBits<64> &id240in_data = id249out_result;

    bool id240x_1;

    (id240x_1) = ((id240in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id240x_1)) {
      writeOutput(m_intrCmd, id240in_data);
    }
  }
  { // Node ID: 250 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 251 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id251in_load = id250out_value;
    const HWOffsetFix<64,0,UNSIGNED> &id251in_data = id1out_cycles;

    bool id251x_1;

    (id251x_1) = ((id251in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id251x_1)) {
      setMappedRegValue("cycles", id251in_data);
    }
  }
  { // Node ID: 253 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id254out_result;

  { // Node ID: 254 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id254in_a = id253out_io_intrStream_force_disabled;

    id254out_result = (not_fixed(id254in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id255out_result;

  { // Node ID: 255 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id255in_a = id355out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id255in_b = id254out_result;

    HWOffsetFix<1,0,UNSIGNED> id255x_1;

    (id255x_1) = (and_fixed(id255in_a,id255in_b));
    id255out_result = (id255x_1);
  }
  { // Node ID: 252 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 256 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id256in_output_control = id255out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id256in_data = id252out_value;

    bool id256x_1;

    (id256x_1) = ((id256in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id256x_1)) {
      writeOutput(m_intrStream, id256in_data);
    }
  }
  { // Node ID: 261 (NodeConstantRawBits)
  }
  { // Node ID: 360 (NodeConstantRawBits)
  }
  { // Node ID: 258 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (68l)))
  { // Node ID: 259 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id259in_enable = id360out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id259in_max = id258out_value;

    HWOffsetFix<49,0,UNSIGNED> id259x_1;
    HWOffsetFix<1,0,UNSIGNED> id259x_2;
    HWOffsetFix<1,0,UNSIGNED> id259x_3;
    HWOffsetFix<49,0,UNSIGNED> id259x_4t_1e_1;

    id259out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id259st_count)));
    (id259x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id259st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id259x_2) = (gte_fixed((id259x_1),id259in_max));
    (id259x_3) = (and_fixed((id259x_2),id259in_enable));
    id259out_wrap = (id259x_3);
    if((id259in_enable.getValueAsBool())) {
      if(((id259x_3).getValueAsBool())) {
        (id259st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id259x_4t_1e_1) = (id259x_1);
        (id259st_count) = (id259x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id260out_output;

  { // Node ID: 260 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id260in_input = id259out_count;

    id260out_output = id260in_input;
  }
  if ( (getFillLevel() >= (69l)) && (getFlushLevel() < (69l)|| !isFlushingActive() ))
  { // Node ID: 262 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id262in_load = id261out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id262in_data = id260out_output;

    bool id262x_1;

    (id262x_1) = ((id262in_load.getValueAsBool())&(!(((getFlushLevel())>=(69l))&(isFlushingActive()))));
    if((id262x_1)) {
      setMappedRegValue("current_run_cycle_count", id262in_data);
    }
  }
  { // Node ID: 359 (NodeConstantRawBits)
  }
  { // Node ID: 264 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 265 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id265in_enable = id359out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id265in_max = id264out_value;

    HWOffsetFix<49,0,UNSIGNED> id265x_1;
    HWOffsetFix<1,0,UNSIGNED> id265x_2;
    HWOffsetFix<1,0,UNSIGNED> id265x_3;
    HWOffsetFix<49,0,UNSIGNED> id265x_4t_1e_1;

    id265out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id265st_count)));
    (id265x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id265st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id265x_2) = (gte_fixed((id265x_1),id265in_max));
    (id265x_3) = (and_fixed((id265x_2),id265in_enable));
    id265out_wrap = (id265x_3);
    if((id265in_enable.getValueAsBool())) {
      if(((id265x_3).getValueAsBool())) {
        (id265st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id265x_4t_1e_1) = (id265x_1);
        (id265st_count) = (id265x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 267 (NodeInputMappedReg)
  }
  { // Node ID: 268 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id268in_a = id265out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id268in_b = id267out_run_cycle_count;

    id268out_result[(getCycle()+1)%2] = (eq_fixed(id268in_a,id268in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 266 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id266in_start = id268out_result[getCycle()%2];

    if((id266in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
