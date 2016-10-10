#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "TopKernel.h"

namespace maxcompilersim {

void TopKernel::execute0() {
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 37 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id37in_en = id36out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id37in_max0 = id148out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id37in_reset = id182out_output[getCycle()%2];

    m_sm_CounterChain557_sm.inputdata_en = id37in_en.getBitString();
    m_sm_CounterChain557_sm.inputdata_max0 = id37in_max0.getBitString();
    m_sm_CounterChain557_sm.inputdata_reset = id37in_reset.getBitString();
    m_sm_CounterChain557_sm.execute(true);
    id37out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain557_sm.outputdata_counter0) ));
    id37out_counter0_extension0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain557_sm.outputdata_counter0_extension0) ));
    id37out_counter0_extension1 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain557_sm.outputdata_counter0_extension1) ));
    id37out_counter0_extension2 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain557_sm.outputdata_counter0_extension2) ));
    id37out_counter0_extension3 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain557_sm.outputdata_counter0_extension3) ));
    id37out_counter0_extension4 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain557_sm.outputdata_counter0_extension4) ));
    id37out_counter0_extension5 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain557_sm.outputdata_counter0_extension5) ));
    id37out_counter0_extension6 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain557_sm.outputdata_counter0_extension6) ));
    id37out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain557_sm.outputdata_done));
    id37out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain557_sm.outputdata_saturated));
  }
  HWOffsetFix<1,0,UNSIGNED> id38out_output;

  { // Node ID: 38 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id38in_input = id37out_done;

    id38out_output = id38in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id143out_output;

  { // Node ID: 143 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id143in_input = id150out_output[getCycle()%2];

    id143out_output = id143in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id146out_output;

  { // Node ID: 146 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id146in_input = id153out_output[getCycle()%2];

    id146out_output = id146in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id20out_output;

  { // Node ID: 20 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id20in_input = id155out_output[getCycle()%2];

    id20out_output = id20in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id15out_output;

  { // Node ID: 15 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id15in_input = id156out_output[getCycle()%2];

    id15out_output = id15in_input;
  }
  { // Node ID: 195 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 66 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id66in_enable = id157out_output[getCycle()%2];
    const HWOffsetFix<33,0,UNSIGNED> &id66in_max = id195out_value;

    HWOffsetFix<33,0,UNSIGNED> id66x_1;
    HWOffsetFix<1,0,UNSIGNED> id66x_2;
    HWOffsetFix<1,0,UNSIGNED> id66x_3;
    HWOffsetFix<33,0,UNSIGNED> id66x_4t_1e_1;

    id66out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id66st_count)));
    (id66x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id66st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id66x_2) = (gte_fixed((id66x_1),id66in_max));
    (id66x_3) = (and_fixed((id66x_2),id66in_enable));
    id66out_wrap = (id66x_3);
    if((id66in_enable.getValueAsBool())) {
      if(((id66x_3).getValueAsBool())) {
        (id66st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id66x_4t_1e_1) = (id66x_1);
        (id66st_count) = (id66x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id67out_output;

  { // Node ID: 67 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id67in_input = id66out_wrap;

    id67out_output = id67in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id10out_output;

  { // Node ID: 10 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id10in_input = id158out_output[getCycle()%2];

    id10out_output = id10in_input;
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_intr_done = id67out_output;
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
    const HWOffsetFix<1,0,UNSIGNED> &id9in_sm_en = id1out_run_en;
    const HWOffsetFix<32,0,UNSIGNED> &id9in_sm_numIter = id11out_value;

    m_sm_void572_sm.inputdata_s0_done = id9in_s0_done.getBitString();
    m_sm_void572_sm.inputdata_sm_en = id9in_sm_en.getBitString();
    m_sm_void572_sm.inputdata_sm_numIter = id9in_sm_numIter.getBitString();
    m_sm_void572_sm.execute(true);
    id9out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void572_sm.outputdata_rst_en));
    id9out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void572_sm.outputdata_s0_en));
    id9out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void572_sm.outputdata_sm_done));
  }
  { // Node ID: 16 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 14 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id14in_s0_done = id20out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id14in_sm_en = id9out_s0_en;
    const HWOffsetFix<32,0,UNSIGNED> &id14in_sm_numIter = id16out_value;

    m_sm_void570_sm.inputdata_s0_done = id14in_s0_done.getBitString();
    m_sm_void570_sm.inputdata_sm_en = id14in_sm_en.getBitString();
    m_sm_void570_sm.inputdata_sm_numIter = id14in_sm_numIter.getBitString();
    m_sm_void570_sm.execute(true);
    id14out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void570_sm.outputdata_rst_en));
    id14out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void570_sm.outputdata_s0_en));
    id14out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void570_sm.outputdata_sm_done));
  }
  HWOffsetFix<32,0,UNSIGNED> id25out_o;

  { // Node ID: 25 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id25in_i = id24out_result[getCycle()%39];

    id25out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id25in_i));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 19 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id19in_s0_done = id154out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id19in_s1_done = id146out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id19in_sm_en = id14out_s0_en;
    const HWOffsetFix<32,0,UNSIGNED> &id19in_sm_numIter = id25out_o;

    m_sm_seq568_sm.inputdata_s0_done = id19in_s0_done.getBitString();
    m_sm_seq568_sm.inputdata_s1_done = id19in_s1_done.getBitString();
    m_sm_seq568_sm.inputdata_sm_en = id19in_sm_en.getBitString();
    m_sm_seq568_sm.inputdata_sm_numIter = id19in_sm_numIter.getBitString();
    m_sm_seq568_sm.execute(true);
    id19out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq568_sm.outputdata_rst_en));
    id19out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq568_sm.outputdata_s0_en));
    id19out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq568_sm.outputdata_s1_en));
    id19out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_seq568_sm.outputdata_sm_done));
  }
  { // Node ID: 5 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 29 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id29in_ctr_done = id38out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_rst_done = id143out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id29in_sm_en = id19out_s0_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id29in_sm_maxIn_0 = id5out_value;

    m_sm_pipe562_sm.inputdata_ctr_done = id29in_ctr_done.getBitString();
    m_sm_pipe562_sm.inputdata_rst_done = id29in_rst_done.getBitString();
    m_sm_pipe562_sm.inputdata_sm_en = id29in_sm_en.getBitString();
    m_sm_pipe562_sm.inputdata_sm_maxIn_0 = id29in_sm_maxIn_0.getBitString();
    m_sm_pipe562_sm.execute(true);
    id29out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe562_sm.outputdata_ctr_en));
    id29out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe562_sm.outputdata_ctr_maxOut_0) ));
    id29out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe562_sm.outputdata_rst_en));
    id29out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe562_sm.outputdata_sm_done));
  }
  { // Node ID: 147 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id147in_input = id29out_ctr_en;

    id147out_output[(getCycle()+1)%2] = id147in_input;
  }
  { // Node ID: 191 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 33 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id33in_enable = id147out_output[getCycle()%2];
    const HWOffsetFix<9,0,UNSIGNED> &id33in_max = id191out_value;

    HWOffsetFix<10,0,UNSIGNED> id33x_1;
    HWOffsetFix<1,0,UNSIGNED> id33x_2;
    HWOffsetFix<1,0,UNSIGNED> id33x_3;
    HWOffsetFix<10,0,UNSIGNED> id33x_4t_1e_1;

    id33out_count = (cast_fixed2fixed<9,0,UNSIGNED,TRUNCATE>((id33st_count)));
    (id33x_1) = (add_fixed<10,0,UNSIGNED,TRUNCATE>((id33st_count),(c_hw_fix_10_0_uns_bits_1)));
    (id33x_2) = (gte_fixed((id33x_1),(cast_fixed2fixed<10,0,UNSIGNED,TRUNCATE>(id33in_max))));
    (id33x_3) = (and_fixed((id33x_2),id33in_enable));
    id33out_wrap = (id33x_3);
    if((id33in_enable.getValueAsBool())) {
      if(((id33x_3).getValueAsBool())) {
        (id33st_count) = (c_hw_fix_10_0_uns_bits);
      }
      else {
        (id33x_4t_1e_1) = (id33x_1);
        (id33st_count) = (id33x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id34out_output;

  { // Node ID: 34 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id34in_input = id33out_wrap;

    id34out_output = id34in_input;
  }
  { // Node ID: 36 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id36in_a = id29out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id36in_b = id34out_output;

    HWOffsetFix<1,0,UNSIGNED> id36x_1;

    (id36x_1) = (and_fixed(id36in_a,id36in_b));
    id36out_result[(getCycle()+1)%2] = (id36x_1);
  }
  { // Node ID: 148 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id148in_input = id29out_ctr_maxOut_0;

    id148out_output[(getCycle()+1)%2] = id148in_input;
  }
  { // Node ID: 182 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id182in_input = id154out_output[getCycle()%2];

    id182out_output[(getCycle()+1)%2] = id182in_input;
  }
  { // Node ID: 150 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id150in_input = id29out_rst_en;

    id150out_output[(getCycle()+1)%2] = id150in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id144out_output;

  { // Node ID: 144 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id144in_input = id29out_sm_done;

    id144out_output = id144in_input;
  }
  { // Node ID: 154 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id154in_input = id144out_output;

    id154out_output[(getCycle()+1)%2] = id154in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id61out_output;

  { // Node ID: 61 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id61in_input = id151out_output[getCycle()%2];

    id61out_output = id61in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id145out_output;

  { // Node ID: 145 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id145in_input = id152out_output[getCycle()%2];

    id145out_output = id145in_input;
  }
  { // Node ID: 60 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 57 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id57in_ctr_done = id61out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id57in_rst_done = id145out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id57in_sm_en = id19out_s1_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id57in_sm_maxIn_0 = id60out_value;

    m_sm_void566_sm.inputdata_ctr_done = id57in_ctr_done.getBitString();
    m_sm_void566_sm.inputdata_rst_done = id57in_rst_done.getBitString();
    m_sm_void566_sm.inputdata_sm_en = id57in_sm_en.getBitString();
    m_sm_void566_sm.inputdata_sm_maxIn_0 = id57in_sm_maxIn_0.getBitString();
    m_sm_void566_sm.execute(true);
    id57out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void566_sm.outputdata_ctr_en));
    id57out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_void566_sm.outputdata_ctr_maxOut_0) ));
    id57out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void566_sm.outputdata_rst_en));
    id57out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void566_sm.outputdata_sm_done));
  }
  { // Node ID: 151 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id151in_input = id57out_ctr_en;

    id151out_output[(getCycle()+1)%2] = id151in_input;
  }
  { // Node ID: 152 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id152in_input = id57out_rst_en;

    id152out_output[(getCycle()+1)%2] = id152in_input;
  }
  { // Node ID: 153 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id153in_input = id57out_sm_done;

    id153out_output[(getCycle()+1)%2] = id153in_input;
  }
  { // Node ID: 2 (NodeInputMappedReg)
  }
  { // Node ID: 118 (NodeConstantRawBits)
  }
  { // Node ID: 24 (NodeDiv)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id24in_a = id2out_argin549;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id24in_b = id118out_value;

    id24out_result[(getCycle()+38)%39] = (div_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id24in_a,id24in_b));
  }
  { // Node ID: 155 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id155in_input = id19out_sm_done;

    id155out_output[(getCycle()+1)%2] = id155in_input;
  }
  { // Node ID: 156 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id156in_input = id14out_sm_done;

    id156out_output[(getCycle()+1)%2] = id156in_input;
  }
  { // Node ID: 157 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id157in_input = id1out_intr_en;

    id157out_output[(getCycle()+1)%2] = id157in_input;
  }
  { // Node ID: 158 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id158in_input = id9out_sm_done;

    id158out_output[(getCycle()+1)%2] = id158in_input;
  }
  { // Node ID: 177 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id177in_input = id10out_output;

    id177out_output[(getCycle()+11)%12] = id177in_input;
  }
  { // Node ID: 183 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id183in_input = id182out_output[getCycle()%2];

    id183out_output[(getCycle()+8)%9] = id183in_input;
  }
  { // Node ID: 184 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id184in_input = id183out_output[getCycle()%9];

    id184out_output[(getCycle()+1)%2] = id184in_input;
  }
  { // Node ID: 159 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id159in_input = id146out_output;

    id159out_output[(getCycle()+1)%2] = id159in_input;
  }
  { // Node ID: 160 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id160in_input = id20out_output;

    id160out_output[(getCycle()+1)%2] = id160in_input;
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 26 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id26in_en = id159out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id26in_max0 = id2out_argin549;
    const HWOffsetFix<1,0,UNSIGNED> &id26in_reset = id160out_output[getCycle()%2];

    m_sm_CounterChain554_sm.inputdata_en = id26in_en.getBitString();
    m_sm_CounterChain554_sm.inputdata_max0 = id26in_max0.getBitString();
    m_sm_CounterChain554_sm.inputdata_reset = id26in_reset.getBitString();
    m_sm_CounterChain554_sm.execute(true);
    id26out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain554_sm.outputdata_counter0) ));
    id26out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain554_sm.outputdata_done));
    id26out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain554_sm.outputdata_saturated));
  }
  { // Node ID: 129 (NodeTriAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id129in_a = id26out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id129in_b = id37out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id129in_c = id26out_counter0;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id129x_1;

    (id129x_1) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>(id129in_a,id129in_b)),id129in_c));
    id129out_result[(getCycle()+1)%2] = (id129x_1);
  }
  { // Node ID: 161 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id161in_input = id37out_counter0_extension0;

    id161out_output[(getCycle()+1)%2] = id161in_input;
  }
  { // Node ID: 162 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id162in_input = id26out_counter0;

    id162out_output[(getCycle()+1)%2] = id162in_input;
  }
  { // Node ID: 130 (NodeTriAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id130in_a = id129out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id130in_b = id161out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id130in_c = id162out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id130x_1;

    (id130x_1) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>(id130in_a,id130in_b)),id130in_c));
    id130out_result[(getCycle()+1)%2] = (id130x_1);
  }
  { // Node ID: 163 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id163in_input = id37out_counter0_extension1;

    id163out_output[(getCycle()+2)%3] = id163in_input;
  }
  { // Node ID: 186 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id186in_input = id162out_output[getCycle()%2];

    id186out_output[(getCycle()+1)%2] = id186in_input;
  }
  { // Node ID: 131 (NodeTriAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id131in_a = id130out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id131in_b = id163out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id131in_c = id186out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id131x_1;

    (id131x_1) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>(id131in_a,id131in_b)),id131in_c));
    id131out_result[(getCycle()+1)%2] = (id131x_1);
  }
  { // Node ID: 165 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id165in_input = id37out_counter0_extension2;

    id165out_output[(getCycle()+3)%4] = id165in_input;
  }
  { // Node ID: 187 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id187in_input = id186out_output[getCycle()%2];

    id187out_output[(getCycle()+1)%2] = id187in_input;
  }
  { // Node ID: 132 (NodeTriAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id132in_a = id131out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id132in_b = id165out_output[getCycle()%4];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id132in_c = id187out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id132x_1;

    (id132x_1) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>(id132in_a,id132in_b)),id132in_c));
    id132out_result[(getCycle()+1)%2] = (id132x_1);
  }
  { // Node ID: 167 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id167in_input = id37out_counter0_extension3;

    id167out_output[(getCycle()+4)%5] = id167in_input;
  }
  { // Node ID: 188 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id188in_input = id187out_output[getCycle()%2];

    id188out_output[(getCycle()+1)%2] = id188in_input;
  }
  { // Node ID: 133 (NodeTriAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id133in_a = id132out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id133in_b = id167out_output[getCycle()%5];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id133in_c = id188out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id133x_1;

    (id133x_1) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>(id133in_a,id133in_b)),id133in_c));
    id133out_result[(getCycle()+1)%2] = (id133x_1);
  }
  { // Node ID: 169 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id169in_input = id37out_counter0_extension4;

    id169out_output[(getCycle()+5)%6] = id169in_input;
  }
  { // Node ID: 189 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id189in_input = id188out_output[getCycle()%2];

    id189out_output[(getCycle()+1)%2] = id189in_input;
  }
  { // Node ID: 134 (NodeTriAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id134in_a = id133out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id134in_b = id169out_output[getCycle()%6];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id134in_c = id189out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id134x_1;

    (id134x_1) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>(id134in_a,id134in_b)),id134in_c));
    id134out_result[(getCycle()+1)%2] = (id134x_1);
  }
  { // Node ID: 171 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id171in_input = id37out_counter0_extension5;

    id171out_output[(getCycle()+6)%7] = id171in_input;
  }
  { // Node ID: 190 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id190in_input = id189out_output[getCycle()%2];

    id190out_output[(getCycle()+1)%2] = id190in_input;
  }
  { // Node ID: 135 (NodeTriAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id135in_a = id134out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id135in_b = id171out_output[getCycle()%7];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id135in_c = id190out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id135x_1;

    (id135x_1) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>(id135in_a,id135in_b)),id135in_c));
    id135out_result[(getCycle()+1)%2] = (id135x_1);
  }
  { // Node ID: 173 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id173in_input = id37out_counter0_extension6;

    id173out_output[(getCycle()+7)%8] = id173in_input;
  }
  { // Node ID: 136 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id136in_a = id135out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id136in_b = id173out_output[getCycle()%8];

    id136out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id136in_a,id136in_b));
  }
  { // Node ID: 39 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id39in_a = id29out_ctr_en;
    const HWOffsetFix<1,0,UNSIGNED> &id39in_b = id34out_output;

    HWOffsetFix<1,0,UNSIGNED> id39x_1;

    (id39x_1) = (and_fixed(id39in_a,id39in_b));
    id39out_result[(getCycle()+1)%2] = (id39x_1);
  }
  { // Node ID: 175 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id175in_input = id39out_result[getCycle()%2];

    id175out_output[(getCycle()+8)%9] = id175in_input;
  }
  if ( (getFillLevel() >= (13l)))
  { // Node ID: 40 (NodeAccumulator)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id40in_summand = id136out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id40in_clearAccumulate = id183out_output[getCycle()%9];
    const HWOffsetFix<1,0,UNSIGNED> &id40in_enable = id175out_output[getCycle()%9];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id40x_1;

    (id40x_1) = id40in_summand;
    if(((id40st_clear_reg).getValueAsBool())) {
      if((id40in_enable.getValueAsBool())) {
        (id40st_hold_reg) = (id40x_1);
      }
      else {
        (id40st_hold_reg) = (c_hw_fix_32_0_sgn_bits_2);
      }
    }
    else {
      if((id40in_enable.getValueAsBool())) {
        (id40st_hold_reg) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((id40st_hold_reg),(id40x_1)));
      }
    }
    id40out_accumulate[(getCycle()+1)%2] = (id40st_hold_reg);
    (id40st_clear_reg) = id40in_clearAccumulate;
  }
  { // Node ID: 41 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (14l)))
  { // Node ID: 3 (NodeHold)
    const HWOffsetFix<1,0,UNSIGNED> &id3in_load = id184out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id3in_input = id40out_accumulate[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id3in_user_reset = id41out_value;

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
  if ( (getFillLevel() >= (15l)) && (getFlushLevel() < (15l)|| !isFlushingActive() ))
  { // Node ID: 64 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id64in_load = id177out_output[getCycle()%12];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id64in_data = id3out_output[getCycle()%2];

    bool id64x_1;

    (id64x_1) = ((id64in_load.getValueAsBool())&(!(((getFlushLevel())>=(15l))&(isFlushingActive()))));
    if((id64x_1)) {
      setMappedRegValue("argout550", id64in_data);
    }
  }
  { // Node ID: 185 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id185in_input = id157out_output[getCycle()%2];

    id185out_output[(getCycle()+1)%2] = id185in_input;
  }
  { // Node ID: 194 (NodeConstantRawBits)
  }
  { // Node ID: 69 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id69in_a = id66out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id69in_b = id194out_value;

    id69out_result[(getCycle()+1)%2] = (eq_fixed(id69in_a,id69in_b));
  }
  { // Node ID: 70 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id70in_a = id185out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id70in_b = id69out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id70x_1;

    (id70x_1) = (and_fixed(id70in_a,id70in_b));
    id70out_result[(getCycle()+1)%2] = (id70x_1);
  }
  { // Node ID: 86 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id87out_result;

  { // Node ID: 87 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id87in_a = id86out_io_intrCmd_force_disabled;

    id87out_result = (not_fixed(id87in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id88out_result;

  { // Node ID: 88 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id88in_a = id70out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id88in_b = id87out_result;

    HWOffsetFix<1,0,UNSIGNED> id88x_1;

    (id88x_1) = (and_fixed(id88in_a,id88in_b));
    id88out_result = (id88x_1);
  }
  HWRawBits<1> id97out_output;

  { // Node ID: 97 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id97in_input = id185out_output[getCycle()%2];

    id97out_output = (cast_fixed2bits(id97in_input));
  }
  { // Node ID: 180 (NodeFIFO)
    const HWRawBits<1> &id180in_input = id97out_output;

    id180out_output[(getCycle()+1)%2] = id180in_input;
  }
  { // Node ID: 123 (NodeConstantRawBits)
  }
  { // Node ID: 125 (NodeConstantRawBits)
  }
  HWRawBits<8> id93out_output;

  { // Node ID: 93 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id93in_input = id125out_value;

    id93out_output = (cast_fixed2bits(id93in_input));
  }
  { // Node ID: 127 (NodeConstantRawBits)
  }
  { // Node ID: 128 (NodeConstantRawBits)
  }
  HWRawBits<40> id92out_result;

  { // Node ID: 92 (NodeCat)
    const HWRawBits<8> &id92in_in0 = id127out_value;
    const HWRawBits<32> &id92in_in1 = id128out_value;

    id92out_result = (cat(id92in_in0,id92in_in1));
  }
  HWRawBits<48> id94out_result;

  { // Node ID: 94 (NodeCat)
    const HWRawBits<8> &id94in_in0 = id93out_output;
    const HWRawBits<40> &id94in_in1 = id92out_result;

    id94out_result = (cat(id94in_in0,id94in_in1));
  }
  HWRawBits<63> id96out_result;

  { // Node ID: 96 (NodeCat)
    const HWRawBits<15> &id96in_in0 = id123out_value;
    const HWRawBits<48> &id96in_in1 = id94out_result;

    id96out_result = (cat(id96in_in0,id96in_in1));
  }
  HWRawBits<64> id98out_result;

  { // Node ID: 98 (NodeCat)
    const HWRawBits<1> &id98in_in0 = id180out_output[getCycle()%2];
    const HWRawBits<63> &id98in_in1 = id96out_result;

    id98out_result = (cat(id98in_in0,id98in_in1));
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 89 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id89in_output_control = id88out_result;
    const HWRawBits<64> &id89in_data = id98out_result;

    bool id89x_1;

    (id89x_1) = ((id89in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id89x_1)) {
      writeOutput(m_intrCmd, id89in_data);
    }
  }
  { // Node ID: 99 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 100 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id100in_load = id99out_value;
    const HWOffsetFix<64,0,UNSIGNED> &id100in_data = id1out_cycles;

    bool id100x_1;

    (id100x_1) = ((id100in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id100x_1)) {
      setMappedRegValue("cycles", id100in_data);
    }
  }
  { // Node ID: 102 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id103out_result;

  { // Node ID: 103 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id103in_a = id102out_io_intrStream_force_disabled;

    id103out_result = (not_fixed(id103in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id104out_result;

  { // Node ID: 104 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id104in_a = id185out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id104in_b = id103out_result;

    HWOffsetFix<1,0,UNSIGNED> id104x_1;

    (id104x_1) = (and_fixed(id104in_a,id104in_b));
    id104out_result = (id104x_1);
  }
  { // Node ID: 101 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (6l)) && (getFlushLevel() < (6l)|| !isFlushingActive() ))
  { // Node ID: 105 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id105in_output_control = id104out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id105in_data = id101out_value;

    bool id105x_1;

    (id105x_1) = ((id105in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(6l))&(isFlushingActive()))));
    if((id105x_1)) {
      writeOutput(m_intrStream, id105in_data);
    }
  }
  { // Node ID: 110 (NodeConstantRawBits)
  }
  { // Node ID: 193 (NodeConstantRawBits)
  }
  { // Node ID: 107 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (15l)))
  { // Node ID: 108 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id108in_enable = id193out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id108in_max = id107out_value;

    HWOffsetFix<49,0,UNSIGNED> id108x_1;
    HWOffsetFix<1,0,UNSIGNED> id108x_2;
    HWOffsetFix<1,0,UNSIGNED> id108x_3;
    HWOffsetFix<49,0,UNSIGNED> id108x_4t_1e_1;

    id108out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id108st_count)));
    (id108x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id108st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id108x_2) = (gte_fixed((id108x_1),id108in_max));
    (id108x_3) = (and_fixed((id108x_2),id108in_enable));
    id108out_wrap = (id108x_3);
    if((id108in_enable.getValueAsBool())) {
      if(((id108x_3).getValueAsBool())) {
        (id108st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id108x_4t_1e_1) = (id108x_1);
        (id108st_count) = (id108x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id109out_output;

  { // Node ID: 109 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id109in_input = id108out_count;

    id109out_output = id109in_input;
  }
  if ( (getFillLevel() >= (16l)) && (getFlushLevel() < (16l)|| !isFlushingActive() ))
  { // Node ID: 111 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id111in_load = id110out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id111in_data = id109out_output;

    bool id111x_1;

    (id111x_1) = ((id111in_load.getValueAsBool())&(!(((getFlushLevel())>=(16l))&(isFlushingActive()))));
    if((id111x_1)) {
      setMappedRegValue("current_run_cycle_count", id111in_data);
    }
  }
  { // Node ID: 192 (NodeConstantRawBits)
  }
  { // Node ID: 113 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 114 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id114in_enable = id192out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id114in_max = id113out_value;

    HWOffsetFix<49,0,UNSIGNED> id114x_1;
    HWOffsetFix<1,0,UNSIGNED> id114x_2;
    HWOffsetFix<1,0,UNSIGNED> id114x_3;
    HWOffsetFix<49,0,UNSIGNED> id114x_4t_1e_1;

    id114out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id114st_count)));
    (id114x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id114st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id114x_2) = (gte_fixed((id114x_1),id114in_max));
    (id114x_3) = (and_fixed((id114x_2),id114in_enable));
    id114out_wrap = (id114x_3);
    if((id114in_enable.getValueAsBool())) {
      if(((id114x_3).getValueAsBool())) {
        (id114st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id114x_4t_1e_1) = (id114x_1);
        (id114st_count) = (id114x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 116 (NodeInputMappedReg)
  }
  { // Node ID: 117 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id117in_a = id114out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id117in_b = id116out_run_cycle_count;

    id117out_result[(getCycle()+1)%2] = (eq_fixed(id117in_a,id117in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 115 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id115in_start = id117out_result[getCycle()%2];

    if((id115in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
