#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "TopKernel.h"

namespace maxcompilersim {

void TopKernel::execute0() {
  { // Node ID: 314 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id45out_output;

  { // Node ID: 45 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id45in_input = id44out_result[getCycle()%2];

    id45out_output = id45in_input;
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 32 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id32in_memDone = id45out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id32in_sm_en = id284out_output[getCycle()%2];

    m_sm_DRAM1198_void1247_inldSM.inputdata_memDone = id32in_memDone.getBitString();
    m_sm_DRAM1198_void1247_inldSM.inputdata_sm_en = id32in_sm_en.getBitString();
    m_sm_DRAM1198_void1247_inldSM.execute(true);
    id32out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1198_void1247_inldSM.outputdata_memStart));
    id32out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1198_void1247_inldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id33out_output;

  { // Node ID: 33 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id33in_input = id32out_sm_done;

    id33out_output = id33in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id40out_output;

  { // Node ID: 40 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id40in_input = id33out_output;

    id40out_output = id40in_input;
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 42 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id42in_enable = id32out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id42in_max = id314out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id42in_userReset = id40out_output;

    HWOffsetFix<17,0,UNSIGNED> id42x_1;
    HWOffsetFix<1,0,UNSIGNED> id42x_2;
    HWOffsetFix<1,0,UNSIGNED> id42x_3;
    HWOffsetFix<1,0,UNSIGNED> id42x_4;
    HWOffsetFix<17,0,UNSIGNED> id42x_5e_1t_1e_1;

    id42out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id42st_count)));
    (id42x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id42st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id42x_2) = (gt_fixed((id42x_1),id42in_max));
    (id42x_3) = (and_fixed(id42in_enable,(not_fixed((id42x_2)))));
    (id42x_4) = (c_hw_fix_1_0_uns_bits);
    id42out_wrap = (id42x_4);
    if((id42in_userReset.getValueAsBool())) {
      (id42st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id42x_3).getValueAsBool())) {
        if(((id42x_4).getValueAsBool())) {
          (id42st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id42x_5e_1t_1e_1) = (id42x_1);
          (id42st_count) = (id42x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 313 (NodeConstantRawBits)
  }
  { // Node ID: 44 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id44in_a = id42out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id44in_b = id313out_value;

    id44out_result[(getCycle()+1)%2] = (eq_fixed(id44in_a,id44in_b));
  }
  { // Node ID: 8 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (60l)))
  { // Node ID: 88 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id88in_en = id266out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id88in_max0 = id8out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id88in_reset = id267out_output[getCycle()%55];

    m_sm_CounterChain1249_sm.inputdata_en = id88in_en.getBitString();
    m_sm_CounterChain1249_sm.inputdata_max0 = id88in_max0.getBitString();
    m_sm_CounterChain1249_sm.inputdata_reset = id88in_reset.getBitString();
    m_sm_CounterChain1249_sm.execute(true);
    id88out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1249_sm.outputdata_counter0) ));
    id88out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1249_sm.outputdata_done));
    id88out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1249_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id89out_output;

  { // Node ID: 89 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id89in_input = id88out_done;

    id89out_output = id89in_input;
  }
  if ( (getFillLevel() >= (59l)))
  { // Node ID: 85 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id85in_ctr_done = id89out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id85in_rst_done = id268out_output[getCycle()%54];
    const HWOffsetFix<1,0,UNSIGNED> &id85in_sm_en = id269out_output[getCycle()%54];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id85in_sm_maxIn_0 = id8out_value;

    m_sm_pipe1255_sm.inputdata_ctr_done = id85in_ctr_done.getBitString();
    m_sm_pipe1255_sm.inputdata_rst_done = id85in_rst_done.getBitString();
    m_sm_pipe1255_sm.inputdata_sm_en = id85in_sm_en.getBitString();
    m_sm_pipe1255_sm.inputdata_sm_maxIn_0 = id85in_sm_maxIn_0.getBitString();
    m_sm_pipe1255_sm.execute(true);
    id85out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1255_sm.outputdata_ctr_en));
    id85out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe1255_sm.outputdata_ctr_maxOut_0) ));
    id85out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1255_sm.outputdata_rst_en));
    id85out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1255_sm.outputdata_sm_done));
  }
  { // Node ID: 266 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id266in_input = id85out_ctr_en;

    id266out_output[(getCycle()+1)%2] = id266in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id261out_output;

  { // Node ID: 261 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id261in_input = id85out_sm_done;

    id261out_output = id261in_input;
  }
  { // Node ID: 267 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id267in_input = id261out_output;

    id267out_output[(getCycle()+54)%55] = id267in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id260out_output;

  { // Node ID: 260 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id260in_input = id85out_rst_en;

    id260out_output = id260in_input;
  }
  { // Node ID: 268 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id268in_input = id260out_output;

    id268out_output[(getCycle()+53)%54] = id268in_input;
  }
  { // Node ID: 26 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 24 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id24in_s0_done = id33out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id24in_s1_done = id261out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id24in_sm_en = id283out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id24in_sm_numIter = id26out_value;

    m_sm_void1257_sm.inputdata_s0_done = id24in_s0_done.getBitString();
    m_sm_void1257_sm.inputdata_s1_done = id24in_s1_done.getBitString();
    m_sm_void1257_sm.inputdata_sm_en = id24in_sm_en.getBitString();
    m_sm_void1257_sm.inputdata_sm_numIter = id24in_sm_numIter.getBitString();
    m_sm_void1257_sm.execute(true);
    id24out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1257_sm.outputdata_rst_en));
    id24out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1257_sm.outputdata_s0_en));
    id24out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1257_sm.outputdata_s1_en));
    id24out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1257_sm.outputdata_sm_done));
    id24out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1257_sm.outputdata_sm_last));
  }
  { // Node ID: 269 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id269in_input = id24out_s1_en;

    id269out_output[(getCycle()+53)%54] = id269in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id25out_output;

  { // Node ID: 25 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id25in_input = id24out_sm_done;

    id25out_output = id25in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id96out_output;

  { // Node ID: 96 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id96in_input = id271out_output[getCycle()%2];

    id96out_output = id96in_input;
  }
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 92 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id92in_ctr_done = id96out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id92in_rst_done = id272out_output[getCycle()%60];
    const HWOffsetFix<1,0,UNSIGNED> &id92in_sm_en = id273out_output[getCycle()%60];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id92in_sm_maxIn_0 = id8out_value;

    m_sm_pipe1268_sm.inputdata_ctr_done = id92in_ctr_done.getBitString();
    m_sm_pipe1268_sm.inputdata_rst_done = id92in_rst_done.getBitString();
    m_sm_pipe1268_sm.inputdata_sm_en = id92in_sm_en.getBitString();
    m_sm_pipe1268_sm.inputdata_sm_maxIn_0 = id92in_sm_maxIn_0.getBitString();
    m_sm_pipe1268_sm.execute(true);
    id92out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1268_sm.outputdata_ctr_en));
    id92out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe1268_sm.outputdata_ctr_maxOut_0) ));
    id92out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1268_sm.outputdata_rst_en));
    id92out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1268_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id263out_output;

  { // Node ID: 263 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id263in_input = id92out_sm_done;

    id263out_output = id263in_input;
  }
  { // Node ID: 270 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id270in_input = id263out_output;

    id270out_output[(getCycle()+59)%60] = id270in_input;
  }
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 95 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id95in_en = id92out_ctr_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id95in_max0 = id92out_ctr_maxOut_0;
    const HWOffsetFix<1,0,UNSIGNED> &id95in_reset = id270out_output[getCycle()%60];

    m_sm_CounterChain1260_sm.inputdata_en = id95in_en.getBitString();
    m_sm_CounterChain1260_sm.inputdata_max0 = id95in_max0.getBitString();
    m_sm_CounterChain1260_sm.inputdata_reset = id95in_reset.getBitString();
    m_sm_CounterChain1260_sm.execute(true);
    id95out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1260_sm.outputdata_counter0) ));
    id95out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1260_sm.outputdata_done));
    id95out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1260_sm.outputdata_saturated));
  }
  { // Node ID: 271 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id271in_input = id95out_done;

    id271out_output[(getCycle()+1)%2] = id271in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id262out_output;

  { // Node ID: 262 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id262in_input = id92out_rst_en;

    id262out_output = id262in_input;
  }
  { // Node ID: 272 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id272in_input = id262out_output;

    id272out_output[(getCycle()+59)%60] = id272in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id20out_o;

  { // Node ID: 20 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id20in_i = id19out_result[getCycle()%39];

    id20out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id20in_i));
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 14 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id14in_s0_done = id25out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id14in_s1_done = id263out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id14in_s2_done = id281out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id14in_sm_en = id282out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id14in_sm_numIter = id20out_o;

    m_sm_seq1282_sm.inputdata_s0_done = id14in_s0_done.getBitString();
    m_sm_seq1282_sm.inputdata_s1_done = id14in_s1_done.getBitString();
    m_sm_seq1282_sm.inputdata_s2_done = id14in_s2_done.getBitString();
    m_sm_seq1282_sm.inputdata_sm_en = id14in_sm_en.getBitString();
    m_sm_seq1282_sm.inputdata_sm_numIter = id14in_sm_numIter.getBitString();
    m_sm_seq1282_sm.execute(true);
    id14out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1282_sm.outputdata_rst_en));
    id14out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1282_sm.outputdata_s0_en));
    id14out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1282_sm.outputdata_s1_en));
    id14out_s2_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1282_sm.outputdata_s2_en));
    id14out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq1282_sm.outputdata_sm_done));
  }
  { // Node ID: 273 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id273in_input = id14out_s1_en;

    id273out_output[(getCycle()+59)%60] = id273in_input;
  }
  if ( (getFillLevel() >= (68l)))
  { // Node ID: 110 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id110in_en = id274out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id110in_max0 = id8out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id110in_reset = id275out_output[getCycle()%64];

    m_sm_CounterChain1271_sm.inputdata_en = id110in_en.getBitString();
    m_sm_CounterChain1271_sm.inputdata_max0 = id110in_max0.getBitString();
    m_sm_CounterChain1271_sm.inputdata_reset = id110in_reset.getBitString();
    m_sm_CounterChain1271_sm.execute(true);
    id110out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1271_sm.outputdata_counter0) ));
    id110out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1271_sm.outputdata_done));
    id110out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1271_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id111out_output;

  { // Node ID: 111 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id111in_input = id110out_done;

    id111out_output = id111in_input;
  }
  if ( (getFillLevel() >= (67l)))
  { // Node ID: 107 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id107in_ctr_done = id111out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id107in_rst_done = id276out_output[getCycle()%63];
    const HWOffsetFix<1,0,UNSIGNED> &id107in_sm_en = id277out_output[getCycle()%63];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id107in_sm_maxIn_0 = id8out_value;

    m_sm_pipe1277_sm.inputdata_ctr_done = id107in_ctr_done.getBitString();
    m_sm_pipe1277_sm.inputdata_rst_done = id107in_rst_done.getBitString();
    m_sm_pipe1277_sm.inputdata_sm_en = id107in_sm_en.getBitString();
    m_sm_pipe1277_sm.inputdata_sm_maxIn_0 = id107in_sm_maxIn_0.getBitString();
    m_sm_pipe1277_sm.execute(true);
    id107out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1277_sm.outputdata_ctr_en));
    id107out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe1277_sm.outputdata_ctr_maxOut_0) ));
    id107out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1277_sm.outputdata_rst_en));
    id107out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe1277_sm.outputdata_sm_done));
  }
  { // Node ID: 274 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id274in_input = id107out_ctr_en;

    id274out_output[(getCycle()+1)%2] = id274in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id265out_output;

  { // Node ID: 265 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id265in_input = id107out_sm_done;

    id265out_output = id265in_input;
  }
  { // Node ID: 275 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id275in_input = id265out_output;

    id275out_output[(getCycle()+63)%64] = id275in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id264out_output;

  { // Node ID: 264 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id264in_input = id107out_rst_en;

    id264out_output = id264in_input;
  }
  { // Node ID: 276 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id276in_input = id264out_output;

    id276out_output[(getCycle()+62)%63] = id276in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id128out_output;

  { // Node ID: 128 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id128in_input = id127out_result[getCycle()%2];

    id128out_output = id128in_input;
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 116 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id116in_memDone = id128out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id116in_sm_en = id278out_output[getCycle()%2];

    m_sm_DRAM1199_void1278_outldSM.inputdata_memDone = id116in_memDone.getBitString();
    m_sm_DRAM1199_void1278_outldSM.inputdata_sm_en = id116in_sm_en.getBitString();
    m_sm_DRAM1199_void1278_outldSM.execute(true);
    id116out_memStart = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1199_void1278_outldSM.outputdata_memStart));
    id116out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_DRAM1199_void1278_outldSM.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id117out_output;

  { // Node ID: 117 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id117in_input = id116out_sm_done;

    id117out_output = id117in_input;
  }
  { // Node ID: 104 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 102 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id102in_s0_done = id265out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id102in_s1_done = id117out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id102in_sm_en = id14out_s2_en;
    const HWOffsetFix<32,0,UNSIGNED> &id102in_sm_numIter = id104out_value;

    m_sm_void1280_sm.inputdata_s0_done = id102in_s0_done.getBitString();
    m_sm_void1280_sm.inputdata_s1_done = id102in_s1_done.getBitString();
    m_sm_void1280_sm.inputdata_sm_en = id102in_sm_en.getBitString();
    m_sm_void1280_sm.inputdata_sm_numIter = id102in_sm_numIter.getBitString();
    m_sm_void1280_sm.execute(true);
    id102out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1280_sm.outputdata_rst_en));
    id102out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1280_sm.outputdata_s0_en));
    id102out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1280_sm.outputdata_s1_en));
    id102out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1280_sm.outputdata_sm_done));
    id102out_sm_last = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1280_sm.outputdata_sm_last));
  }
  { // Node ID: 277 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id277in_input = id102out_s0_en;

    id277out_output[(getCycle()+62)%63] = id277in_input;
  }
  { // Node ID: 312 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id123out_output;

  { // Node ID: 123 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id123in_input = id117out_output;

    id123out_output = id123in_input;
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 125 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id125in_enable = id116out_memStart;
    const HWOffsetFix<17,0,UNSIGNED> &id125in_max = id312out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id125in_userReset = id123out_output;

    HWOffsetFix<17,0,UNSIGNED> id125x_1;
    HWOffsetFix<1,0,UNSIGNED> id125x_2;
    HWOffsetFix<1,0,UNSIGNED> id125x_3;
    HWOffsetFix<1,0,UNSIGNED> id125x_4;
    HWOffsetFix<17,0,UNSIGNED> id125x_5e_1t_1e_1;

    id125out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id125st_count)));
    (id125x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id125st_count),(c_hw_fix_17_0_uns_bits_2)));
    (id125x_2) = (gt_fixed((id125x_1),id125in_max));
    (id125x_3) = (and_fixed(id125in_enable,(not_fixed((id125x_2)))));
    (id125x_4) = (c_hw_fix_1_0_uns_bits);
    id125out_wrap = (id125x_4);
    if((id125in_userReset.getValueAsBool())) {
      (id125st_count) = (c_hw_fix_17_0_uns_bits_1);
    }
    else {
      if(((id125x_3).getValueAsBool())) {
        if(((id125x_4).getValueAsBool())) {
          (id125st_count) = (c_hw_fix_17_0_uns_bits_1);
        }
        else {
          (id125x_5e_1t_1e_1) = (id125x_1);
          (id125st_count) = (id125x_5e_1t_1e_1);
        }
      }
      else {
      }
    }
  }
  { // Node ID: 311 (NodeConstantRawBits)
  }
  { // Node ID: 127 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id127in_a = id125out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id127in_b = id311out_value;

    id127out_result[(getCycle()+1)%2] = (eq_fixed(id127in_a,id127in_b));
  }
  { // Node ID: 278 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id278in_input = id102out_s1_en;

    id278out_output[(getCycle()+1)%2] = id278in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id103out_output;

  { // Node ID: 103 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id103in_input = id102out_sm_done;

    id103out_output = id103in_input;
  }
  { // Node ID: 281 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id281in_input = id103out_output;

    id281out_output[(getCycle()+1)%2] = id281in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id15out_output;

  { // Node ID: 15 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id15in_input = id14out_sm_done;

    id15out_output = id15in_input;
  }
  { // Node ID: 310 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 167 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id167in_enable = id279out_output[getCycle()%2];
    const HWOffsetFix<33,0,UNSIGNED> &id167in_max = id310out_value;

    HWOffsetFix<33,0,UNSIGNED> id167x_1;
    HWOffsetFix<1,0,UNSIGNED> id167x_2;
    HWOffsetFix<1,0,UNSIGNED> id167x_3;
    HWOffsetFix<33,0,UNSIGNED> id167x_4t_1e_1;

    id167out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id167st_count)));
    (id167x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id167st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id167x_2) = (gte_fixed((id167x_1),id167in_max));
    (id167x_3) = (and_fixed((id167x_2),id167in_enable));
    id167out_wrap = (id167x_3);
    if((id167in_enable.getValueAsBool())) {
      if(((id167x_3).getValueAsBool())) {
        (id167st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id167x_4t_1e_1) = (id167x_1);
        (id167st_count) = (id167x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id168out_output;

  { // Node ID: 168 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id168in_input = id167out_wrap;

    id168out_output = id168in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id10out_output;

  { // Node ID: 10 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id10in_input = id280out_output[getCycle()%2];

    id10out_output = id10in_input;
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_intr_done = id168out_output;
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
  { // Node ID: 279 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id279in_input = id1out_intr_en;

    id279out_output[(getCycle()+1)%2] = id279in_input;
  }
  { // Node ID: 11 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 9 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id9in_s0_done = id15out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id9in_sm_en = id1out_run_en;
    const HWOffsetFix<32,0,UNSIGNED> &id9in_sm_numIter = id11out_value;

    m_sm_void1284_sm.inputdata_s0_done = id9in_s0_done.getBitString();
    m_sm_void1284_sm.inputdata_sm_en = id9in_sm_en.getBitString();
    m_sm_void1284_sm.inputdata_sm_numIter = id9in_sm_numIter.getBitString();
    m_sm_void1284_sm.execute(true);
    id9out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1284_sm.outputdata_rst_en));
    id9out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1284_sm.outputdata_s0_en));
    id9out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void1284_sm.outputdata_sm_done));
  }
  { // Node ID: 280 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id280in_input = id9out_sm_done;

    id280out_output[(getCycle()+1)%2] = id280in_input;
  }
  { // Node ID: 282 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id282in_input = id9out_s0_en;

    id282out_output[(getCycle()+1)%2] = id282in_input;
  }
  { // Node ID: 2 (NodeInputMappedReg)
  }
  { // Node ID: 221 (NodeConstantRawBits)
  }
  { // Node ID: 19 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id19in_a = id2out_argin1238;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id19in_b = id221out_value;

    id19out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id19in_a,id19in_b));
  }
  { // Node ID: 283 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id283in_input = id14out_s0_en;

    id283out_output[(getCycle()+1)%2] = id283in_input;
  }
  { // Node ID: 284 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id284in_input = id24out_s0_en;

    id284out_output[(getCycle()+1)%2] = id284in_input;
  }
  { // Node ID: 285 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id285in_input = id32out_memStart;

    id285out_output[(getCycle()+1)%2] = id285in_input;
  }
  { // Node ID: 309 (NodeConstantRawBits)
  }
  { // Node ID: 47 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id47in_a = id42out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id47in_b = id309out_value;

    id47out_result[(getCycle()+1)%2] = (eq_fixed(id47in_a,id47in_b));
  }
  { // Node ID: 48 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id48in_a = id285out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id48in_b = id47out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id48x_1;

    (id48x_1) = (and_fixed(id48in_a,id48in_b));
    id48out_result[(getCycle()+1)%2] = (id48x_1);
  }
  { // Node ID: 66 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id67out_result;

  { // Node ID: 67 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id67in_a = id66out_io_DRAM1198_void1247_in_cmd_force_disabled;

    id67out_result = (not_fixed(id67in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id68out_result;

  { // Node ID: 68 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id68in_a = id48out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id68in_b = id67out_result;

    HWOffsetFix<1,0,UNSIGNED> id68x_1;

    (id68x_1) = (and_fixed(id68in_a,id68in_b));
    id68out_result = (id68x_1);
  }
  { // Node ID: 286 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id286in_input = id68out_result;

    id286out_output[(getCycle()+34)%35] = id286in_input;
  }
  { // Node ID: 222 (NodeConstantRawBits)
  }
  { // Node ID: 227 (NodeConstantRawBits)
  }
  { // Node ID: 53 (NodeConstantRawBits)
  }
  HWRawBits<8> id73out_output;

  { // Node ID: 73 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id73in_input = id53out_value;

    id73out_output = (cast_fixed2bits(id73in_input));
  }
  { // Node ID: 232 (NodeConstantRawBits)
  }
  { // Node ID: 308 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 21 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id21in_en = id103out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_max0 = id2out_argin1238;
    const HWOffsetFix<1,0,UNSIGNED> &id21in_reset = id15out_output;

    m_sm_CounterChain1245_sm.inputdata_en = id21in_en.getBitString();
    m_sm_CounterChain1245_sm.inputdata_max0 = id21in_max0.getBitString();
    m_sm_CounterChain1245_sm.inputdata_reset = id21in_reset.getBitString();
    m_sm_CounterChain1245_sm.execute(true);
    id21out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain1245_sm.outputdata_counter0) ));
    id21out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1245_sm.outputdata_done));
    id21out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain1245_sm.outputdata_saturated));
  }
  { // Node ID: 307 (NodeConstantRawBits)
  }
  { // Node ID: 35 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id35in_a = id21out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id35in_b = id307out_value;

    id35out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id35in_a,id35in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id36out_o;

  { // Node ID: 36 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id36in_i = id35out_result[getCycle()%39];

    id36out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id36in_i));
  }
  { // Node ID: 38 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id38in_a = id308out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id38in_b = id36out_o;

    id38out_result[(getCycle()+1)%2] = (add_fixed<32,0,UNSIGNED,TONEAR>(id38in_a,id38in_b));
  }
  HWRawBits<32> id70out_output;

  { // Node ID: 70 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id70in_input = id38out_result[getCycle()%2];

    id70out_output = (cast_fixed2bits(id70in_input));
  }
  HWRawBits<40> id72out_result;

  { // Node ID: 72 (NodeCat)
    const HWRawBits<8> &id72in_in0 = id232out_value;
    const HWRawBits<32> &id72in_in1 = id70out_output;

    id72out_result = (cat(id72in_in0,id72in_in1));
  }
  HWRawBits<48> id74out_result;

  { // Node ID: 74 (NodeCat)
    const HWRawBits<8> &id74in_in0 = id73out_output;
    const HWRawBits<40> &id74in_in1 = id72out_result;

    id74out_result = (cat(id74in_in0,id74in_in1));
  }
  HWRawBits<63> id76out_result;

  { // Node ID: 76 (NodeCat)
    const HWRawBits<15> &id76in_in0 = id227out_value;
    const HWRawBits<48> &id76in_in1 = id74out_result;

    id76out_result = (cat(id76in_in0,id76in_in1));
  }
  HWRawBits<64> id78out_result;

  { // Node ID: 78 (NodeCat)
    const HWRawBits<1> &id78in_in0 = id222out_value;
    const HWRawBits<63> &id78in_in1 = id76out_result;

    id78out_result = (cat(id78in_in0,id78in_in1));
  }
  if ( (getFillLevel() >= (43l)) && (getFlushLevel() < (43l)|| !isFlushingActive() ))
  { // Node ID: 69 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id69in_output_control = id286out_output[getCycle()%35];
    const HWRawBits<64> &id69in_data = id78out_result;

    bool id69x_1;

    (id69x_1) = ((id69in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(43l))&(isFlushingActive()))));
    if((id69x_1)) {
      writeOutput(m_DRAM1198_void1247_in_cmd, id69in_data);
    }
  }
  { // Node ID: 287 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id287in_input = id116out_memStart;

    id287out_output[(getCycle()+1)%2] = id287in_input;
  }
  { // Node ID: 306 (NodeConstantRawBits)
  }
  { // Node ID: 130 (NodeEq)
    const HWOffsetFix<16,0,UNSIGNED> &id130in_a = id125out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id130in_b = id306out_value;

    id130out_result[(getCycle()+1)%2] = (eq_fixed(id130in_a,id130in_b));
  }
  { // Node ID: 131 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id131in_a = id287out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id131in_b = id130out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id131x_1;

    (id131x_1) = (and_fixed(id131in_a,id131in_b));
    id131out_result[(getCycle()+1)%2] = (id131x_1);
  }
  { // Node ID: 148 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id149out_result;

  { // Node ID: 149 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id149in_a = id148out_io_DRAM1199_void1278_out_cmd_force_disabled;

    id149out_result = (not_fixed(id149in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id150out_result;

  { // Node ID: 150 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id150in_a = id131out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id150in_b = id149out_result;

    HWOffsetFix<1,0,UNSIGNED> id150x_1;

    (id150x_1) = (and_fixed(id150in_a,id150in_b));
    id150out_result = (id150x_1);
  }
  { // Node ID: 288 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id288in_input = id150out_result;

    id288out_output[(getCycle()+35)%36] = id288in_input;
  }
  { // Node ID: 233 (NodeConstantRawBits)
  }
  { // Node ID: 238 (NodeConstantRawBits)
  }
  { // Node ID: 135 (NodeConstantRawBits)
  }
  HWRawBits<8> id155out_output;

  { // Node ID: 155 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id155in_input = id135out_value;

    id155out_output = (cast_fixed2bits(id155in_input));
  }
  { // Node ID: 243 (NodeConstantRawBits)
  }
  { // Node ID: 305 (NodeConstantRawBits)
  }
  { // Node ID: 304 (NodeConstantRawBits)
  }
  { // Node ID: 119 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id119in_a = id21out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id119in_b = id304out_value;

    id119out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id119in_a,id119in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id120out_o;

  { // Node ID: 120 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id120in_i = id119out_result[getCycle()%39];

    id120out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id120in_i));
  }
  { // Node ID: 122 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id122in_a = id305out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id122in_b = id120out_o;

    id122out_result[(getCycle()+1)%2] = (add_fixed<32,0,UNSIGNED,TONEAR>(id122in_a,id122in_b));
  }
  HWRawBits<32> id152out_output;

  { // Node ID: 152 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id152in_input = id122out_result[getCycle()%2];

    id152out_output = (cast_fixed2bits(id152in_input));
  }
  HWRawBits<40> id154out_result;

  { // Node ID: 154 (NodeCat)
    const HWRawBits<8> &id154in_in0 = id243out_value;
    const HWRawBits<32> &id154in_in1 = id152out_output;

    id154out_result = (cat(id154in_in0,id154in_in1));
  }
  HWRawBits<48> id156out_result;

  { // Node ID: 156 (NodeCat)
    const HWRawBits<8> &id156in_in0 = id155out_output;
    const HWRawBits<40> &id156in_in1 = id154out_result;

    id156out_result = (cat(id156in_in0,id156in_in1));
  }
  HWRawBits<63> id158out_result;

  { // Node ID: 158 (NodeCat)
    const HWRawBits<15> &id158in_in0 = id238out_value;
    const HWRawBits<48> &id158in_in1 = id156out_result;

    id158out_result = (cat(id158in_in0,id158in_in1));
  }
  HWRawBits<64> id160out_result;

  { // Node ID: 160 (NodeCat)
    const HWRawBits<1> &id160in_in0 = id233out_value;
    const HWRawBits<63> &id160in_in1 = id158out_result;

    id160out_result = (cat(id160in_in0,id160in_in1));
  }
  if ( (getFillLevel() >= (43l)) && (getFlushLevel() < (43l)|| !isFlushingActive() ))
  { // Node ID: 151 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id151in_output_control = id288out_output[getCycle()%36];
    const HWRawBits<64> &id151in_data = id160out_result;

    bool id151x_1;

    (id151x_1) = ((id151in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(43l))&(isFlushingActive()))));
    if((id151x_1)) {
      writeOutput(m_DRAM1199_void1278_out_cmd, id151in_data);
    }
  }
  { // Node ID: 161 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id162out_result;

  { // Node ID: 162 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id162in_a = id161out_io_DRAM1199_void1278_out_force_disabled;

    id162out_result = (not_fixed(id162in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id163out_result;

  { // Node ID: 163 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id163in_a = id274out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id163in_b = id162out_result;

    HWOffsetFix<1,0,UNSIGNED> id163x_1;

    (id163x_1) = (and_fixed(id163in_a,id163in_b));
    id163out_result = (id163x_1);
  }
  { // Node ID: 294 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id294in_input = id163out_result;

    id294out_output[(getCycle()+2)%3] = id294in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id101out_o;

  { // Node ID: 101 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id101in_i = id95out_counter0;

    id101out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id101in_i));
  }
  { // Node ID: 292 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id292in_input = id101out_o;

    id292out_output[(getCycle()+4)%5] = id292in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id91out_o;

  { // Node ID: 91 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id91in_i = id88out_counter0;

    id91out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id91in_i));
  }
  { // Node ID: 290 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id290in_input = id91out_o;

    id290out_output[(getCycle()+4)%5] = id290in_input;
  }
  { // Node ID: 79 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id80out_result;

  { // Node ID: 80 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id80in_a = id79out_io_DRAM1198_void1247_in_force_disabled;

    id80out_result = (not_fixed(id80in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id81out_result;

  { // Node ID: 81 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id81in_a = id85out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id81in_b = id80out_result;

    HWOffsetFix<1,0,UNSIGNED> id81x_1;

    (id81x_1) = (and_fixed(id81in_a,id81in_b));
    id81out_result = (id81x_1);
  }
  if ( (getFillLevel() >= (59l)))
  { // Node ID: 82 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id82in_enable = id81out_result;

    (id82st_read_next_cycle) = ((id82in_enable.getValueAsBool())&(!(((getFlushLevel())>=(59l))&(isFlushingActive()))));
    queueReadRequest(m_DRAM1198_void1247_in, id82st_read_next_cycle.getValueAsBool());
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id84out_output;

  { // Node ID: 84 (NodeReinterpret)
    const HWRawBits<32> &id84in_input = id82out_data;

    id84out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id84in_input));
  }
  { // Node ID: 299 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id299in_input = id266out_output[getCycle()%2];

    id299out_output[(getCycle()+4)%5] = id299in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id99out_o;

  { // Node ID: 99 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id99in_i = id95out_counter0;

    id99out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id99in_i));
  }
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 207 (NodeRAM)
    const bool id207_inputvalid = !(isFlushingActive() && getFlushLevel() >= (64l));
    const HWOffsetFix<7,0,UNSIGNED> &id207in_addrA = id290out_output[getCycle()%5];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id207in_dina = id84out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id207in_wea = id299out_output[getCycle()%5];
    const HWOffsetFix<7,0,UNSIGNED> &id207in_addrB = id99out_o;

    long id207x_1;
    long id207x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id207x_3;

    (id207x_1) = (id207in_addrA.getValueAsLong());
    (id207x_2) = (id207in_addrB.getValueAsLong());
    switch(((long)((id207x_2)<(96l)))) {
      case 0l:
        id207x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id207x_3 = (id207sta_ram_store[(id207x_2)]);
        break;
      default:
        id207x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id207out_doutb[(getCycle()+2)%3] = (id207x_3);
    if(((id207in_wea.getValueAsBool())&id207_inputvalid)) {
      if(((id207x_1)<(96l))) {
        (id207sta_ram_store[(id207x_1)]) = id207in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_1("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 207) on port A, ram depth is 96.")));
      }
    }
  }
  { // Node ID: 3 (NodeInputMappedReg)
  }
  { // Node ID: 100 (NodeMul)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id100in_a = id207out_doutb[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id100in_b = id3out_argin1239;

    id100out_result[(getCycle()+2)%3] = (mul_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id100in_a,id100in_b));
  }
  { // Node ID: 293 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id293in_input = id92out_ctr_en;

    id293out_output[(getCycle()+4)%5] = id293in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id114out_o;

  { // Node ID: 114 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id114in_i = id110out_counter0;

    id114out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAR>(id114in_i));
  }
  if ( (getFillLevel() >= (68l)))
  { // Node ID: 208 (NodeRAM)
    const bool id208_inputvalid = !(isFlushingActive() && getFlushLevel() >= (68l));
    const HWOffsetFix<7,0,UNSIGNED> &id208in_addrA = id292out_output[getCycle()%5];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id208in_dina = id100out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id208in_wea = id293out_output[getCycle()%5];
    const HWOffsetFix<7,0,UNSIGNED> &id208in_addrB = id114out_o;

    long id208x_1;
    long id208x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id208x_3;

    (id208x_1) = (id208in_addrA.getValueAsLong());
    (id208x_2) = (id208in_addrB.getValueAsLong());
    switch(((long)((id208x_2)<(96l)))) {
      case 0l:
        id208x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id208x_3 = (id208sta_ram_store[(id208x_2)]);
        break;
      default:
        id208x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id208out_doutb[(getCycle()+2)%3] = (id208x_3);
    if(((id208in_wea.getValueAsBool())&id208_inputvalid)) {
      if(((id208x_1)<(96l))) {
        (id208sta_ram_store[(id208x_1)]) = id208in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_2("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 208) on port A, ram depth is 96.")));
      }
    }
  }
  HWRawBits<32> id165out_output;

  { // Node ID: 165 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id165in_input = id208out_doutb[getCycle()%3];

    id165out_output = (cast_fixed2bits(id165in_input));
  }
  if ( (getFillLevel() >= (70l)) && (getFlushLevel() < (70l)|| !isFlushingActive() ))
  { // Node ID: 164 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id164in_output_control = id294out_output[getCycle()%3];
    const HWRawBits<32> &id164in_data = id165out_output;

    bool id164x_1;

    (id164x_1) = ((id164in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(70l))&(isFlushingActive()))));
    if((id164x_1)) {
      writeOutput(m_DRAM1199_void1278_out, id164in_data);
    }
  }
  { // Node ID: 300 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id300in_input = id279out_output[getCycle()%2];

    id300out_output[(getCycle()+1)%2] = id300in_input;
  }
  { // Node ID: 303 (NodeConstantRawBits)
  }
  { // Node ID: 170 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id170in_a = id167out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id170in_b = id303out_value;

    id170out_result[(getCycle()+1)%2] = (eq_fixed(id170in_a,id170in_b));
  }
  { // Node ID: 171 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id171in_a = id300out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id171in_b = id170out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id171x_1;

    (id171x_1) = (and_fixed(id171in_a,id171in_b));
    id171out_result[(getCycle()+1)%2] = (id171x_1);
  }
  { // Node ID: 187 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id188out_result;

  { // Node ID: 188 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id188in_a = id187out_io_intrCmd_force_disabled;

    id188out_result = (not_fixed(id188in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id189out_result;

  { // Node ID: 189 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id189in_a = id171out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id189in_b = id188out_result;

    HWOffsetFix<1,0,UNSIGNED> id189x_1;

    (id189x_1) = (and_fixed(id189in_a,id189in_b));
    id189out_result = (id189x_1);
  }
  HWRawBits<1> id198out_output;

  { // Node ID: 198 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id198in_input = id300out_output[getCycle()%2];

    id198out_output = (cast_fixed2bits(id198in_input));
  }
  { // Node ID: 297 (NodeFIFO)
    const HWRawBits<1> &id297in_input = id198out_output;

    id297out_output[(getCycle()+1)%2] = id297in_input;
  }
  { // Node ID: 248 (NodeConstantRawBits)
  }
  { // Node ID: 250 (NodeConstantRawBits)
  }
  HWRawBits<8> id194out_output;

  { // Node ID: 194 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id194in_input = id250out_value;

    id194out_output = (cast_fixed2bits(id194in_input));
  }
  { // Node ID: 252 (NodeConstantRawBits)
  }
  { // Node ID: 253 (NodeConstantRawBits)
  }
  HWRawBits<40> id193out_result;

  { // Node ID: 193 (NodeCat)
    const HWRawBits<8> &id193in_in0 = id252out_value;
    const HWRawBits<32> &id193in_in1 = id253out_value;

    id193out_result = (cat(id193in_in0,id193in_in1));
  }
  HWRawBits<48> id195out_result;

  { // Node ID: 195 (NodeCat)
    const HWRawBits<8> &id195in_in0 = id194out_output;
    const HWRawBits<40> &id195in_in1 = id193out_result;

    id195out_result = (cat(id195in_in0,id195in_in1));
  }
  HWRawBits<63> id197out_result;

  { // Node ID: 197 (NodeCat)
    const HWRawBits<15> &id197in_in0 = id248out_value;
    const HWRawBits<48> &id197in_in1 = id195out_result;

    id197out_result = (cat(id197in_in0,id197in_in1));
  }
  HWRawBits<64> id199out_result;

  { // Node ID: 199 (NodeCat)
    const HWRawBits<1> &id199in_in0 = id297out_output[getCycle()%2];
    const HWRawBits<63> &id199in_in1 = id197out_result;

    id199out_result = (cat(id199in_in0,id199in_in1));
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 190 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id190in_output_control = id189out_result;
    const HWRawBits<64> &id190in_data = id199out_result;

    bool id190x_1;

    (id190x_1) = ((id190in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id190x_1)) {
      writeOutput(m_intrCmd, id190in_data);
    }
  }
  { // Node ID: 200 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 201 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id201in_load = id200out_value;
    const HWOffsetFix<64,0,UNSIGNED> &id201in_data = id1out_cycles;

    bool id201x_1;

    (id201x_1) = ((id201in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id201x_1)) {
      setMappedRegValue("cycles", id201in_data);
    }
  }
  { // Node ID: 203 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id204out_result;

  { // Node ID: 204 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id204in_a = id203out_io_intrStream_force_disabled;

    id204out_result = (not_fixed(id204in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id205out_result;

  { // Node ID: 205 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id205in_a = id300out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id205in_b = id204out_result;

    HWOffsetFix<1,0,UNSIGNED> id205x_1;

    (id205x_1) = (and_fixed(id205in_a,id205in_b));
    id205out_result = (id205x_1);
  }
  { // Node ID: 202 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (6l)) && (getFlushLevel() < (6l)|| !isFlushingActive() ))
  { // Node ID: 206 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id206in_output_control = id205out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id206in_data = id202out_value;

    bool id206x_1;

    (id206x_1) = ((id206in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(6l))&(isFlushingActive()))));
    if((id206x_1)) {
      writeOutput(m_intrStream, id206in_data);
    }
  }
  { // Node ID: 213 (NodeConstantRawBits)
  }
  { // Node ID: 302 (NodeConstantRawBits)
  }
  { // Node ID: 210 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (69l)))
  { // Node ID: 211 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id211in_enable = id302out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id211in_max = id210out_value;

    HWOffsetFix<49,0,UNSIGNED> id211x_1;
    HWOffsetFix<1,0,UNSIGNED> id211x_2;
    HWOffsetFix<1,0,UNSIGNED> id211x_3;
    HWOffsetFix<49,0,UNSIGNED> id211x_4t_1e_1;

    id211out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id211st_count)));
    (id211x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id211st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id211x_2) = (gte_fixed((id211x_1),id211in_max));
    (id211x_3) = (and_fixed((id211x_2),id211in_enable));
    id211out_wrap = (id211x_3);
    if((id211in_enable.getValueAsBool())) {
      if(((id211x_3).getValueAsBool())) {
        (id211st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id211x_4t_1e_1) = (id211x_1);
        (id211st_count) = (id211x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id212out_output;

  { // Node ID: 212 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id212in_input = id211out_count;

    id212out_output = id212in_input;
  }
  if ( (getFillLevel() >= (70l)) && (getFlushLevel() < (70l)|| !isFlushingActive() ))
  { // Node ID: 214 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id214in_load = id213out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id214in_data = id212out_output;

    bool id214x_1;

    (id214x_1) = ((id214in_load.getValueAsBool())&(!(((getFlushLevel())>=(70l))&(isFlushingActive()))));
    if((id214x_1)) {
      setMappedRegValue("current_run_cycle_count", id214in_data);
    }
  }
  { // Node ID: 301 (NodeConstantRawBits)
  }
  { // Node ID: 216 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 217 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id217in_enable = id301out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id217in_max = id216out_value;

    HWOffsetFix<49,0,UNSIGNED> id217x_1;
    HWOffsetFix<1,0,UNSIGNED> id217x_2;
    HWOffsetFix<1,0,UNSIGNED> id217x_3;
    HWOffsetFix<49,0,UNSIGNED> id217x_4t_1e_1;

    id217out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id217st_count)));
    (id217x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id217st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id217x_2) = (gte_fixed((id217x_1),id217in_max));
    (id217x_3) = (and_fixed((id217x_2),id217in_enable));
    id217out_wrap = (id217x_3);
    if((id217in_enable.getValueAsBool())) {
      if(((id217x_3).getValueAsBool())) {
        (id217st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id217x_4t_1e_1) = (id217x_1);
        (id217st_count) = (id217x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 219 (NodeInputMappedReg)
  }
  { // Node ID: 220 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id220in_a = id217out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id220in_b = id219out_run_cycle_count;

    id220out_result[(getCycle()+1)%2] = (eq_fixed(id220in_a,id220in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 218 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id218in_start = id220out_result[getCycle()%2];

    if((id218in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
