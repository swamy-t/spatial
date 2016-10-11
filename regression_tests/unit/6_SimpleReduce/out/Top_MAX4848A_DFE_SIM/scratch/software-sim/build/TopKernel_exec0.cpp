#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "TopKernel.h"

namespace maxcompilersim {

void TopKernel::execute0() {
  { // Node ID: 5 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 21 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id21in_en = id20out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_max0 = id5out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id21in_reset = id125out_output[getCycle()%2];

    m_sm_CounterChain474_sm.inputdata_en = id21in_en.getBitString();
    m_sm_CounterChain474_sm.inputdata_max0 = id21in_max0.getBitString();
    m_sm_CounterChain474_sm.inputdata_reset = id21in_reset.getBitString();
    m_sm_CounterChain474_sm.execute(true);
    id21out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain474_sm.outputdata_counter0) ));
    id21out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain474_sm.outputdata_done));
    id21out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain474_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id22out_output;

  { // Node ID: 22 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id22in_input = id21out_done;

    id22out_output = id22in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id104out_output;

  { // Node ID: 104 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id104in_input = id110out_output[getCycle()%2];

    id104out_output = id104in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id107out_output;

  { // Node ID: 107 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id107in_input = id113out_output[getCycle()%2];

    id107out_output = id107in_input;
  }
  { // Node ID: 133 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 36 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id36in_enable = id114out_output[getCycle()%2];
    const HWOffsetFix<33,0,UNSIGNED> &id36in_max = id133out_value;

    HWOffsetFix<33,0,UNSIGNED> id36x_1;
    HWOffsetFix<1,0,UNSIGNED> id36x_2;
    HWOffsetFix<1,0,UNSIGNED> id36x_3;
    HWOffsetFix<33,0,UNSIGNED> id36x_4t_1e_1;

    id36out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id36st_count)));
    (id36x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id36st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id36x_2) = (gte_fixed((id36x_1),id36in_max));
    (id36x_3) = (and_fixed((id36x_2),id36in_enable));
    id36out_wrap = (id36x_3);
    if((id36in_enable.getValueAsBool())) {
      if(((id36x_3).getValueAsBool())) {
        (id36st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id36x_4t_1e_1) = (id36x_1);
        (id36st_count) = (id36x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id37out_output;

  { // Node ID: 37 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id37in_input = id36out_wrap;

    id37out_output = id37in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id9out_output;

  { // Node ID: 9 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id9in_input = id116out_output[getCycle()%2];

    id9out_output = id9in_input;
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_intr_done = id37out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id1in_run_done = id9out_output;
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
  { // Node ID: 10 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 8 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id8in_s0_done = id115out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id8in_s1_done = id107out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id8in_sm_en = id1out_run_en;
    const HWOffsetFix<32,0,UNSIGNED> &id8in_sm_numIter = id10out_value;

    m_sm_void487_sm.inputdata_s0_done = id8in_s0_done.getBitString();
    m_sm_void487_sm.inputdata_s1_done = id8in_s1_done.getBitString();
    m_sm_void487_sm.inputdata_sm_en = id8in_sm_en.getBitString();
    m_sm_void487_sm.inputdata_sm_numIter = id8in_sm_numIter.getBitString();
    m_sm_void487_sm.execute(true);
    id8out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void487_sm.outputdata_rst_en));
    id8out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void487_sm.outputdata_s0_en));
    id8out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void487_sm.outputdata_s1_en));
    id8out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void487_sm.outputdata_sm_done));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 13 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id13in_ctr_done = id22out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id13in_rst_done = id104out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id13in_sm_en = id8out_s0_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id13in_sm_maxIn_0 = id5out_value;

    m_sm_pipe481_sm.inputdata_ctr_done = id13in_ctr_done.getBitString();
    m_sm_pipe481_sm.inputdata_rst_done = id13in_rst_done.getBitString();
    m_sm_pipe481_sm.inputdata_sm_en = id13in_sm_en.getBitString();
    m_sm_pipe481_sm.inputdata_sm_maxIn_0 = id13in_sm_maxIn_0.getBitString();
    m_sm_pipe481_sm.execute(true);
    id13out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe481_sm.outputdata_ctr_en));
    id13out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe481_sm.outputdata_ctr_maxOut_0) ));
    id13out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe481_sm.outputdata_rst_en));
    id13out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe481_sm.outputdata_sm_done));
  }
  { // Node ID: 108 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id108in_input = id13out_ctr_en;

    id108out_output[(getCycle()+1)%2] = id108in_input;
  }
  { // Node ID: 129 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 17 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id17in_enable = id108out_output[getCycle()%2];
    const HWOffsetFix<9,0,UNSIGNED> &id17in_max = id129out_value;

    HWOffsetFix<10,0,UNSIGNED> id17x_1;
    HWOffsetFix<1,0,UNSIGNED> id17x_2;
    HWOffsetFix<1,0,UNSIGNED> id17x_3;
    HWOffsetFix<10,0,UNSIGNED> id17x_4t_1e_1;

    id17out_count = (cast_fixed2fixed<9,0,UNSIGNED,TRUNCATE>((id17st_count)));
    (id17x_1) = (add_fixed<10,0,UNSIGNED,TRUNCATE>((id17st_count),(c_hw_fix_10_0_uns_bits_1)));
    (id17x_2) = (gte_fixed((id17x_1),(cast_fixed2fixed<10,0,UNSIGNED,TRUNCATE>(id17in_max))));
    (id17x_3) = (and_fixed((id17x_2),id17in_enable));
    id17out_wrap = (id17x_3);
    if((id17in_enable.getValueAsBool())) {
      if(((id17x_3).getValueAsBool())) {
        (id17st_count) = (c_hw_fix_10_0_uns_bits);
      }
      else {
        (id17x_4t_1e_1) = (id17x_1);
        (id17st_count) = (id17x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id18out_output;

  { // Node ID: 18 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id18in_input = id17out_wrap;

    id18out_output = id18in_input;
  }
  { // Node ID: 20 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id20in_a = id13out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id20in_b = id18out_output;

    HWOffsetFix<1,0,UNSIGNED> id20x_1;

    (id20x_1) = (and_fixed(id20in_a,id20in_b));
    id20out_result[(getCycle()+1)%2] = (id20x_1);
  }
  { // Node ID: 125 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id125in_input = id115out_output[getCycle()%2];

    id125out_output[(getCycle()+1)%2] = id125in_input;
  }
  { // Node ID: 110 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id110in_input = id13out_rst_en;

    id110out_output[(getCycle()+1)%2] = id110in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id105out_output;

  { // Node ID: 105 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id105in_input = id13out_sm_done;

    id105out_output = id105in_input;
  }
  { // Node ID: 115 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id115in_input = id105out_output;

    id115out_output[(getCycle()+1)%2] = id115in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id31out_output;

  { // Node ID: 31 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id31in_input = id111out_output[getCycle()%2];

    id31out_output = id31in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id106out_output;

  { // Node ID: 106 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id106in_input = id112out_output[getCycle()%2];

    id106out_output = id106in_input;
  }
  { // Node ID: 30 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 27 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id27in_ctr_done = id31out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id27in_rst_done = id106out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id27in_sm_en = id8out_s1_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id27in_sm_maxIn_0 = id30out_value;

    m_sm_void485_sm.inputdata_ctr_done = id27in_ctr_done.getBitString();
    m_sm_void485_sm.inputdata_rst_done = id27in_rst_done.getBitString();
    m_sm_void485_sm.inputdata_sm_en = id27in_sm_en.getBitString();
    m_sm_void485_sm.inputdata_sm_maxIn_0 = id27in_sm_maxIn_0.getBitString();
    m_sm_void485_sm.execute(true);
    id27out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void485_sm.outputdata_ctr_en));
    id27out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_void485_sm.outputdata_ctr_maxOut_0) ));
    id27out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void485_sm.outputdata_rst_en));
    id27out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void485_sm.outputdata_sm_done));
  }
  { // Node ID: 111 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id111in_input = id27out_ctr_en;

    id111out_output[(getCycle()+1)%2] = id111in_input;
  }
  { // Node ID: 112 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id112in_input = id27out_rst_en;

    id112out_output[(getCycle()+1)%2] = id112in_input;
  }
  { // Node ID: 113 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id113in_input = id27out_sm_done;

    id113out_output[(getCycle()+1)%2] = id113in_input;
  }
  { // Node ID: 114 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id114in_input = id1out_intr_en;

    id114out_output[(getCycle()+1)%2] = id114in_input;
  }
  { // Node ID: 116 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id116in_input = id8out_sm_done;

    id116out_output[(getCycle()+1)%2] = id116in_input;
  }
  { // Node ID: 120 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id120in_input = id9out_output;

    id120out_output[(getCycle()+5)%6] = id120in_input;
  }
  { // Node ID: 126 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id126in_input = id125out_output[getCycle()%2];

    id126out_output[(getCycle()+2)%3] = id126in_input;
  }
  { // Node ID: 127 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id127in_input = id126out_output[getCycle()%3];

    id127out_output[(getCycle()+1)%2] = id127in_input;
  }
  { // Node ID: 2 (NodeInputMappedReg)
  }
  { // Node ID: 26 (NodeMul)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id26in_a = id2out_argin469;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id26in_b = id21out_counter0;

    id26out_result[(getCycle()+2)%3] = (mul_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id26in_a,id26in_b));
  }
  { // Node ID: 23 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id23in_a = id13out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id23in_b = id18out_output;

    HWOffsetFix<1,0,UNSIGNED> id23x_1;

    (id23x_1) = (and_fixed(id23in_a,id23in_b));
    id23out_result[(getCycle()+1)%2] = (id23x_1);
  }
  { // Node ID: 118 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id118in_input = id23out_result[getCycle()%2];

    id118out_output[(getCycle()+2)%3] = id118in_input;
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 24 (NodeAccumulator)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id24in_summand = id26out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id24in_clearAccumulate = id126out_output[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id24in_enable = id118out_output[getCycle()%3];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id24x_1;

    (id24x_1) = id24in_summand;
    if(((id24st_clear_reg).getValueAsBool())) {
      if((id24in_enable.getValueAsBool())) {
        (id24st_hold_reg) = (id24x_1);
      }
      else {
        (id24st_hold_reg) = (c_hw_fix_32_0_sgn_bits_2);
      }
    }
    else {
      if((id24in_enable.getValueAsBool())) {
        (id24st_hold_reg) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((id24st_hold_reg),(id24x_1)));
      }
    }
    id24out_accumulate[(getCycle()+1)%2] = (id24st_hold_reg);
    (id24st_clear_reg) = id24in_clearAccumulate;
  }
  { // Node ID: 25 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (8l)))
  { // Node ID: 3 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id3in_load = id127out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id3in_input = id24out_accumulate[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id3in_user_reset = id25out_value;

    if((id3in_user_reset.getValueAsBool())) {
      (id3st_holdreg) = (c_hw_fix_32_0_sgn_bits_2);
    }
    else {
      if((id3in_load.getValueAsBool())) {
        (id3st_holdreg) = id3in_input;
      }
    }
    id3out_output[(getCycle()+1)%2] = (id3st_holdreg);
  }
  if ( (getFillLevel() >= (9l)) && (getFlushLevel() < (9l)|| !isFlushingActive() ))
  { // Node ID: 34 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id34in_load = id120out_output[getCycle()%6];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id34in_data = id3out_output[getCycle()%2];

    bool id34x_1;

    (id34x_1) = ((id34in_load.getValueAsBool())&(!(((getFlushLevel())>=(9l))&(isFlushingActive()))));
    if((id34x_1)) {
      setMappedRegValue("argout470", id34in_data);
    }
  }
  { // Node ID: 128 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id128in_input = id114out_output[getCycle()%2];

    id128out_output[(getCycle()+1)%2] = id128in_input;
  }
  { // Node ID: 132 (NodeConstantRawBits)
  }
  { // Node ID: 39 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id39in_a = id36out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id39in_b = id132out_value;

    id39out_result[(getCycle()+1)%2] = (eq_fixed(id39in_a,id39in_b));
  }
  { // Node ID: 40 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id40in_a = id128out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id40in_b = id39out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id40x_1;

    (id40x_1) = (and_fixed(id40in_a,id40in_b));
    id40out_result[(getCycle()+1)%2] = (id40x_1);
  }
  { // Node ID: 56 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id57out_result;

  { // Node ID: 57 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id57in_a = id56out_io_intrCmd_force_disabled;

    id57out_result = (not_fixed(id57in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id58out_result;

  { // Node ID: 58 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id58in_a = id40out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id58in_b = id57out_result;

    HWOffsetFix<1,0,UNSIGNED> id58x_1;

    (id58x_1) = (and_fixed(id58in_a,id58in_b));
    id58out_result = (id58x_1);
  }
  HWRawBits<1> id67out_output;

  { // Node ID: 67 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id67in_input = id128out_output[getCycle()%2];

    id67out_output = (cast_fixed2bits(id67in_input));
  }
  { // Node ID: 123 (NodeFIFO)
    const HWRawBits<1> &id123in_input = id67out_output;

    id123out_output[(getCycle()+1)%2] = id123in_input;
  }
  { // Node ID: 92 (NodeConstantRawBits)
  }
  { // Node ID: 94 (NodeConstantRawBits)
  }
  HWRawBits<8> id63out_output;

  { // Node ID: 63 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id63in_input = id94out_value;

    id63out_output = (cast_fixed2bits(id63in_input));
  }
  { // Node ID: 96 (NodeConstantRawBits)
  }
  { // Node ID: 97 (NodeConstantRawBits)
  }
  HWRawBits<40> id62out_result;

  { // Node ID: 62 (NodeCat)
    const HWRawBits<8> &id62in_in0 = id96out_value;
    const HWRawBits<32> &id62in_in1 = id97out_value;

    id62out_result = (cat(id62in_in0,id62in_in1));
  }
  HWRawBits<48> id64out_result;

  { // Node ID: 64 (NodeCat)
    const HWRawBits<8> &id64in_in0 = id63out_output;
    const HWRawBits<40> &id64in_in1 = id62out_result;

    id64out_result = (cat(id64in_in0,id64in_in1));
  }
  HWRawBits<63> id66out_result;

  { // Node ID: 66 (NodeCat)
    const HWRawBits<15> &id66in_in0 = id92out_value;
    const HWRawBits<48> &id66in_in1 = id64out_result;

    id66out_result = (cat(id66in_in0,id66in_in1));
  }
  HWRawBits<64> id68out_result;

  { // Node ID: 68 (NodeCat)
    const HWRawBits<1> &id68in_in0 = id123out_output[getCycle()%2];
    const HWRawBits<63> &id68in_in1 = id66out_result;

    id68out_result = (cat(id68in_in0,id68in_in1));
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 59 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id59in_output_control = id58out_result;
    const HWRawBits<64> &id59in_data = id68out_result;

    bool id59x_1;

    (id59x_1) = ((id59in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id59x_1)) {
      writeOutput(m_intrCmd, id59in_data);
    }
  }
  { // Node ID: 69 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 70 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id70in_load = id69out_value;
    const HWOffsetFix<64,0,UNSIGNED> &id70in_data = id1out_cycles;

    bool id70x_1;

    (id70x_1) = ((id70in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id70x_1)) {
      setMappedRegValue("cycles", id70in_data);
    }
  }
  { // Node ID: 72 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id73out_result;

  { // Node ID: 73 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id73in_a = id72out_io_intrStream_force_disabled;

    id73out_result = (not_fixed(id73in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id74out_result;

  { // Node ID: 74 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id74in_a = id128out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id74in_b = id73out_result;

    HWOffsetFix<1,0,UNSIGNED> id74x_1;

    (id74x_1) = (and_fixed(id74in_a,id74in_b));
    id74out_result = (id74x_1);
  }
  { // Node ID: 71 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (6l)) && (getFlushLevel() < (6l)|| !isFlushingActive() ))
  { // Node ID: 75 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id75in_output_control = id74out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id75in_data = id71out_value;

    bool id75x_1;

    (id75x_1) = ((id75in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(6l))&(isFlushingActive()))));
    if((id75x_1)) {
      writeOutput(m_intrStream, id75in_data);
    }
  }
  { // Node ID: 80 (NodeConstantRawBits)
  }
  { // Node ID: 131 (NodeConstantRawBits)
  }
  { // Node ID: 77 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (9l)))
  { // Node ID: 78 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id78in_enable = id131out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id78in_max = id77out_value;

    HWOffsetFix<49,0,UNSIGNED> id78x_1;
    HWOffsetFix<1,0,UNSIGNED> id78x_2;
    HWOffsetFix<1,0,UNSIGNED> id78x_3;
    HWOffsetFix<49,0,UNSIGNED> id78x_4t_1e_1;

    id78out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id78st_count)));
    (id78x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id78st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id78x_2) = (gte_fixed((id78x_1),id78in_max));
    (id78x_3) = (and_fixed((id78x_2),id78in_enable));
    id78out_wrap = (id78x_3);
    if((id78in_enable.getValueAsBool())) {
      if(((id78x_3).getValueAsBool())) {
        (id78st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id78x_4t_1e_1) = (id78x_1);
        (id78st_count) = (id78x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id79out_output;

  { // Node ID: 79 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id79in_input = id78out_count;

    id79out_output = id79in_input;
  }
  if ( (getFillLevel() >= (10l)) && (getFlushLevel() < (10l)|| !isFlushingActive() ))
  { // Node ID: 81 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id81in_load = id80out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id81in_data = id79out_output;

    bool id81x_1;

    (id81x_1) = ((id81in_load.getValueAsBool())&(!(((getFlushLevel())>=(10l))&(isFlushingActive()))));
    if((id81x_1)) {
      setMappedRegValue("current_run_cycle_count", id81in_data);
    }
  }
  { // Node ID: 130 (NodeConstantRawBits)
  }
  { // Node ID: 83 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 84 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id84in_enable = id130out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id84in_max = id83out_value;

    HWOffsetFix<49,0,UNSIGNED> id84x_1;
    HWOffsetFix<1,0,UNSIGNED> id84x_2;
    HWOffsetFix<1,0,UNSIGNED> id84x_3;
    HWOffsetFix<49,0,UNSIGNED> id84x_4t_1e_1;

    id84out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id84st_count)));
    (id84x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id84st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id84x_2) = (gte_fixed((id84x_1),id84in_max));
    (id84x_3) = (and_fixed((id84x_2),id84in_enable));
    id84out_wrap = (id84x_3);
    if((id84in_enable.getValueAsBool())) {
      if(((id84x_3).getValueAsBool())) {
        (id84st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id84x_4t_1e_1) = (id84x_1);
        (id84st_count) = (id84x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 86 (NodeInputMappedReg)
  }
  { // Node ID: 87 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id87in_a = id84out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id87in_b = id86out_run_cycle_count;

    id87out_result[(getCycle()+1)%2] = (eq_fixed(id87in_a,id87in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 85 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id85in_start = id87out_result[getCycle()%2];

    if((id85in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
