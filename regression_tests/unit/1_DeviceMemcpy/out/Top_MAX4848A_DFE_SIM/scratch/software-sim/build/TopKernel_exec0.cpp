#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "TopKernel.h"

namespace maxcompilersim {

void TopKernel::execute0() {
  HWOffsetFix<1,0,UNSIGNED> id16out_output;

  { // Node ID: 16 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id16in_input = id87out_output[getCycle()%2];

    id16out_output = id16in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id85out_output;

  { // Node ID: 85 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id85in_input = id88out_output[getCycle()%2];

    id85out_output = id85in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id86out_output;

  { // Node ID: 86 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id86in_input = id89out_output[getCycle()%2];

    id86out_output = id86in_input;
  }
  { // Node ID: 101 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 21 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id21in_enable = id90out_output[getCycle()%2];
    const HWOffsetFix<33,0,UNSIGNED> &id21in_max = id101out_value;

    HWOffsetFix<33,0,UNSIGNED> id21x_1;
    HWOffsetFix<1,0,UNSIGNED> id21x_2;
    HWOffsetFix<1,0,UNSIGNED> id21x_3;
    HWOffsetFix<33,0,UNSIGNED> id21x_4t_1e_1;

    id21out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id21st_count)));
    (id21x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id21st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id21x_2) = (gte_fixed((id21x_1),id21in_max));
    (id21x_3) = (and_fixed((id21x_2),id21in_enable));
    id21out_wrap = (id21x_3);
    if((id21in_enable.getValueAsBool())) {
      if(((id21x_3).getValueAsBool())) {
        (id21st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id21x_4t_1e_1) = (id21x_1);
        (id21st_count) = (id21x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id22out_output;

  { // Node ID: 22 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id22in_input = id21out_wrap;

    id22out_output = id22in_input;
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_intr_done = id22out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id1in_run_done = id92out_output[getCycle()%2];
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
  { // Node ID: 9 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 7 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id7in_s0_done = id86out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id7in_sm_en = id1out_run_en;
    const HWOffsetFix<32,0,UNSIGNED> &id7in_sm_numIter = id9out_value;

    m_sm_void752_sm.inputdata_s0_done = id7in_s0_done.getBitString();
    m_sm_void752_sm.inputdata_sm_en = id7in_sm_en.getBitString();
    m_sm_void752_sm.inputdata_sm_numIter = id7in_sm_numIter.getBitString();
    m_sm_void752_sm.execute(true);
    id7out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void752_sm.outputdata_rst_en));
    id7out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void752_sm.outputdata_s0_en));
    id7out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void752_sm.outputdata_sm_done));
  }
  { // Node ID: 15 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 12 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id12in_ctr_done = id16out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id12in_rst_done = id85out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id12in_sm_en = id7out_s0_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id12in_sm_maxIn_0 = id15out_value;

    m_sm_void750_sm.inputdata_ctr_done = id12in_ctr_done.getBitString();
    m_sm_void750_sm.inputdata_rst_done = id12in_rst_done.getBitString();
    m_sm_void750_sm.inputdata_sm_en = id12in_sm_en.getBitString();
    m_sm_void750_sm.inputdata_sm_maxIn_0 = id12in_sm_maxIn_0.getBitString();
    m_sm_void750_sm.execute(true);
    id12out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void750_sm.outputdata_ctr_en));
    id12out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_void750_sm.outputdata_ctr_maxOut_0) ));
    id12out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void750_sm.outputdata_rst_en));
    id12out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void750_sm.outputdata_sm_done));
  }
  { // Node ID: 87 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id87in_input = id12out_ctr_en;

    id87out_output[(getCycle()+1)%2] = id87in_input;
  }
  { // Node ID: 88 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id88in_input = id12out_rst_en;

    id88out_output[(getCycle()+1)%2] = id88in_input;
  }
  { // Node ID: 89 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id89in_input = id12out_sm_done;

    id89out_output[(getCycle()+1)%2] = id89in_input;
  }
  { // Node ID: 90 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id90in_input = id1out_intr_en;

    id90out_output[(getCycle()+1)%2] = id90in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id8out_output;

  { // Node ID: 8 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id8in_input = id7out_sm_done;

    id8out_output = id8in_input;
  }
  { // Node ID: 92 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id92in_input = id8out_output;

    id92out_output[(getCycle()+1)%2] = id92in_input;
  }
  { // Node ID: 4 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 19 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id19in_load = id92out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id19in_data = id4out_value;

    bool id19x_1;

    (id19x_1) = ((id19in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id19x_1)) {
      setMappedRegValue("argout747", id19in_data);
    }
  }
  { // Node ID: 97 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id97in_input = id90out_output[getCycle()%2];

    id97out_output[(getCycle()+1)%2] = id97in_input;
  }
  { // Node ID: 100 (NodeConstantRawBits)
  }
  { // Node ID: 24 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id24in_a = id21out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id24in_b = id100out_value;

    id24out_result[(getCycle()+1)%2] = (eq_fixed(id24in_a,id24in_b));
  }
  { // Node ID: 25 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id25in_a = id97out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id25in_b = id24out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id25x_1;

    (id25x_1) = (and_fixed(id25in_a,id25in_b));
    id25out_result[(getCycle()+1)%2] = (id25x_1);
  }
  { // Node ID: 41 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id42out_result;

  { // Node ID: 42 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id42in_a = id41out_io_intrCmd_force_disabled;

    id42out_result = (not_fixed(id42in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id43out_result;

  { // Node ID: 43 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id43in_a = id25out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id43in_b = id42out_result;

    HWOffsetFix<1,0,UNSIGNED> id43x_1;

    (id43x_1) = (and_fixed(id43in_a,id43in_b));
    id43out_result = (id43x_1);
  }
  HWRawBits<1> id52out_output;

  { // Node ID: 52 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id52in_input = id97out_output[getCycle()%2];

    id52out_output = (cast_fixed2bits(id52in_input));
  }
  { // Node ID: 95 (NodeFIFO)
    const HWRawBits<1> &id95in_input = id52out_output;

    id95out_output[(getCycle()+1)%2] = id95in_input;
  }
  { // Node ID: 77 (NodeConstantRawBits)
  }
  { // Node ID: 79 (NodeConstantRawBits)
  }
  HWRawBits<8> id48out_output;

  { // Node ID: 48 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id48in_input = id79out_value;

    id48out_output = (cast_fixed2bits(id48in_input));
  }
  { // Node ID: 81 (NodeConstantRawBits)
  }
  { // Node ID: 82 (NodeConstantRawBits)
  }
  HWRawBits<40> id47out_result;

  { // Node ID: 47 (NodeCat)
    const HWRawBits<8> &id47in_in0 = id81out_value;
    const HWRawBits<32> &id47in_in1 = id82out_value;

    id47out_result = (cat(id47in_in0,id47in_in1));
  }
  HWRawBits<48> id49out_result;

  { // Node ID: 49 (NodeCat)
    const HWRawBits<8> &id49in_in0 = id48out_output;
    const HWRawBits<40> &id49in_in1 = id47out_result;

    id49out_result = (cat(id49in_in0,id49in_in1));
  }
  HWRawBits<63> id51out_result;

  { // Node ID: 51 (NodeCat)
    const HWRawBits<15> &id51in_in0 = id77out_value;
    const HWRawBits<48> &id51in_in1 = id49out_result;

    id51out_result = (cat(id51in_in0,id51in_in1));
  }
  HWRawBits<64> id53out_result;

  { // Node ID: 53 (NodeCat)
    const HWRawBits<1> &id53in_in0 = id95out_output[getCycle()%2];
    const HWRawBits<63> &id53in_in1 = id51out_result;

    id53out_result = (cat(id53in_in0,id53in_in1));
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 44 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id44in_output_control = id43out_result;
    const HWRawBits<64> &id44in_data = id53out_result;

    bool id44x_1;

    (id44x_1) = ((id44in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id44x_1)) {
      writeOutput(m_intrCmd, id44in_data);
    }
  }
  { // Node ID: 54 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 55 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id55in_load = id54out_value;
    const HWOffsetFix<64,0,UNSIGNED> &id55in_data = id1out_cycles;

    bool id55x_1;

    (id55x_1) = ((id55in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id55x_1)) {
      setMappedRegValue("cycles", id55in_data);
    }
  }
  { // Node ID: 57 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id58out_result;

  { // Node ID: 58 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id58in_a = id57out_io_intrStream_force_disabled;

    id58out_result = (not_fixed(id58in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id59out_result;

  { // Node ID: 59 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id59in_a = id90out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id59in_b = id58out_result;

    HWOffsetFix<1,0,UNSIGNED> id59x_1;

    (id59x_1) = (and_fixed(id59in_a,id59in_b));
    id59out_result = (id59x_1);
  }
  { // Node ID: 56 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)) && (getFlushLevel() < (5l)|| !isFlushingActive() ))
  { // Node ID: 60 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id60in_output_control = id59out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id60in_data = id56out_value;

    bool id60x_1;

    (id60x_1) = ((id60in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(5l))&(isFlushingActive()))));
    if((id60x_1)) {
      writeOutput(m_intrStream, id60in_data);
    }
  }
  { // Node ID: 65 (NodeConstantRawBits)
  }
  { // Node ID: 99 (NodeConstantRawBits)
  }
  { // Node ID: 62 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 63 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id63in_enable = id99out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id63in_max = id62out_value;

    HWOffsetFix<49,0,UNSIGNED> id63x_1;
    HWOffsetFix<1,0,UNSIGNED> id63x_2;
    HWOffsetFix<1,0,UNSIGNED> id63x_3;
    HWOffsetFix<49,0,UNSIGNED> id63x_4t_1e_1;

    id63out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id63st_count)));
    (id63x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id63st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id63x_2) = (gte_fixed((id63x_1),id63in_max));
    (id63x_3) = (and_fixed((id63x_2),id63in_enable));
    id63out_wrap = (id63x_3);
    if((id63in_enable.getValueAsBool())) {
      if(((id63x_3).getValueAsBool())) {
        (id63st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id63x_4t_1e_1) = (id63x_1);
        (id63st_count) = (id63x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id64out_output;

  { // Node ID: 64 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id64in_input = id63out_count;

    id64out_output = id64in_input;
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 66 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id66in_load = id65out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id66in_data = id64out_output;

    bool id66x_1;

    (id66x_1) = ((id66in_load.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id66x_1)) {
      setMappedRegValue("current_run_cycle_count", id66in_data);
    }
  }
  { // Node ID: 98 (NodeConstantRawBits)
  }
  { // Node ID: 68 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 69 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id69in_enable = id98out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id69in_max = id68out_value;

    HWOffsetFix<49,0,UNSIGNED> id69x_1;
    HWOffsetFix<1,0,UNSIGNED> id69x_2;
    HWOffsetFix<1,0,UNSIGNED> id69x_3;
    HWOffsetFix<49,0,UNSIGNED> id69x_4t_1e_1;

    id69out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id69st_count)));
    (id69x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id69st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id69x_2) = (gte_fixed((id69x_1),id69in_max));
    (id69x_3) = (and_fixed((id69x_2),id69in_enable));
    id69out_wrap = (id69x_3);
    if((id69in_enable.getValueAsBool())) {
      if(((id69x_3).getValueAsBool())) {
        (id69st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id69x_4t_1e_1) = (id69x_1);
        (id69st_count) = (id69x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 71 (NodeInputMappedReg)
  }
  { // Node ID: 72 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id72in_a = id69out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id72in_b = id71out_run_cycle_count;

    id72out_result[(getCycle()+1)%2] = (eq_fixed(id72in_a,id72in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 70 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id70in_start = id72out_result[getCycle()%2];

    if((id70in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
