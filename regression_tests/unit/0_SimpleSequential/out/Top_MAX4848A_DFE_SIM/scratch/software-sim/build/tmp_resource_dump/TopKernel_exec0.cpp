#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "TopKernel.h"

namespace maxcompilersim {

void TopKernel::execute0() {
  { // Node ID: 5 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id17out_output;

  { // Node ID: 17 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id17in_input = id154out_output[getCycle()%2];

    id17out_output = id17in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id150out_output;

  { // Node ID: 150 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id150in_input = id155out_output[getCycle()%2];

    id150out_output = id150in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id151out_output;

  { // Node ID: 151 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id151in_input = id156out_output[getCycle()%2];

    id151out_output = id151in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id63out_output;

  { // Node ID: 63 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id63in_input = id157out_output[getCycle()%2];

    id63out_output = id63in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id152out_output;

  { // Node ID: 152 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id152in_input = id158out_output[getCycle()%2];

    id152out_output = id152in_input;
  }
  { // Node ID: 62 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 59 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id59in_ctr_done = id63out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id59in_rst_done = id152out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id59in_sm_en = id159out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id59in_sm_maxIn_0 = id62out_value;

    m_sm_void474_sm.inputdata_ctr_done = id59in_ctr_done.getBitString();
    m_sm_void474_sm.inputdata_rst_done = id59in_rst_done.getBitString();
    m_sm_void474_sm.inputdata_sm_en = id59in_sm_en.getBitString();
    m_sm_void474_sm.inputdata_sm_maxIn_0 = id59in_sm_maxIn_0.getBitString();
    m_sm_void474_sm.execute(true);
    id59out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void474_sm.outputdata_ctr_en));
    id59out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_void474_sm.outputdata_ctr_maxOut_0) ));
    id59out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void474_sm.outputdata_rst_en));
    id59out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void474_sm.outputdata_sm_done));
  }
  HWOffsetFix<1,0,UNSIGNED> id153out_output;

  { // Node ID: 153 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id153in_input = id59out_sm_done;

    id153out_output = id153in_input;
  }
  { // Node ID: 183 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (5l)))
  { // Node ID: 76 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id76in_enable = id160out_output[getCycle()%2];
    const HWOffsetFix<33,0,UNSIGNED> &id76in_max = id183out_value;

    HWOffsetFix<33,0,UNSIGNED> id76x_1;
    HWOffsetFix<1,0,UNSIGNED> id76x_2;
    HWOffsetFix<1,0,UNSIGNED> id76x_3;
    HWOffsetFix<33,0,UNSIGNED> id76x_4t_1e_1;

    id76out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id76st_count)));
    (id76x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id76st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id76x_2) = (gte_fixed((id76x_1),id76in_max));
    (id76x_3) = (and_fixed((id76x_2),id76in_enable));
    id76out_wrap = (id76x_3);
    if((id76in_enable.getValueAsBool())) {
      if(((id76x_3).getValueAsBool())) {
        (id76st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id76x_4t_1e_1) = (id76x_1);
        (id76st_count) = (id76x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id77out_output;

  { // Node ID: 77 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id77in_input = id76out_wrap;

    id77out_output = id77in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id9out_output;

  { // Node ID: 9 (NodeStreamOffset)
    const HWOffsetFix<1,0,UNSIGNED> &id9in_input = id161out_output[getCycle()%2];

    id9out_output = id9in_input;
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 1 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_intr_done = id77out_output;
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
    const HWOffsetFix<1,0,UNSIGNED> &id8in_s0_done = id151out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id8in_s1_done = id153out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id8in_sm_en = id1out_run_en;
    const HWOffsetFix<32,0,UNSIGNED> &id8in_sm_numIter = id10out_value;

    m_sm_void476_sm.inputdata_s0_done = id8in_s0_done.getBitString();
    m_sm_void476_sm.inputdata_s1_done = id8in_s1_done.getBitString();
    m_sm_void476_sm.inputdata_sm_en = id8in_sm_en.getBitString();
    m_sm_void476_sm.inputdata_sm_numIter = id8in_sm_numIter.getBitString();
    m_sm_void476_sm.execute(true);
    id8out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void476_sm.outputdata_rst_en));
    id8out_s0_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void476_sm.outputdata_s0_en));
    id8out_s1_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void476_sm.outputdata_s1_en));
    id8out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_void476_sm.outputdata_sm_done));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 13 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id13in_ctr_done = id17out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id13in_rst_done = id150out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id13in_sm_en = id8out_s0_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id13in_sm_maxIn_0 = id5out_value;

    m_sm_pipe469_sm.inputdata_ctr_done = id13in_ctr_done.getBitString();
    m_sm_pipe469_sm.inputdata_rst_done = id13in_rst_done.getBitString();
    m_sm_pipe469_sm.inputdata_sm_en = id13in_sm_en.getBitString();
    m_sm_pipe469_sm.inputdata_sm_maxIn_0 = id13in_sm_maxIn_0.getBitString();
    m_sm_pipe469_sm.execute(true);
    id13out_ctr_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe469_sm.outputdata_ctr_en));
    id13out_ctr_maxOut_0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_pipe469_sm.outputdata_ctr_maxOut_0) ));
    id13out_rst_en = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe469_sm.outputdata_rst_en));
    id13out_sm_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_pipe469_sm.outputdata_sm_done));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 16 (NodeStateMachine)
    const HWOffsetFix<1,0,UNSIGNED> &id16in_en = id13out_ctr_en;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id16in_max0 = id5out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id16in_reset = id151out_output;

    m_sm_CounterChain457_sm.inputdata_en = id16in_en.getBitString();
    m_sm_CounterChain457_sm.inputdata_max0 = id16in_max0.getBitString();
    m_sm_CounterChain457_sm.inputdata_reset = id16in_reset.getBitString();
    m_sm_CounterChain457_sm.execute(true);
    id16out_counter0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain457_sm.outputdata_counter0) ));
    id16out_counter0_extension0 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain457_sm.outputdata_counter0_extension0) ));
    id16out_counter0_extension1 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain457_sm.outputdata_counter0_extension1) ));
    id16out_counter0_extension2 = (HWOffsetFix<32,0,TWOSCOMPLEMENT>( varint_u<32> (m_sm_CounterChain457_sm.outputdata_counter0_extension2) ));
    id16out_done = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain457_sm.outputdata_done));
    id16out_saturated = (HWOffsetFix<1,0,UNSIGNED>(m_sm_CounterChain457_sm.outputdata_saturated));
  }
  { // Node ID: 154 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id154in_input = id16out_done;

    id154out_output[(getCycle()+1)%2] = id154in_input;
  }
  { // Node ID: 155 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id155in_input = id13out_rst_en;

    id155out_output[(getCycle()+1)%2] = id155in_input;
  }
  { // Node ID: 156 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id156in_input = id13out_sm_done;

    id156out_output[(getCycle()+1)%2] = id156in_input;
  }
  { // Node ID: 157 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id157in_input = id59out_ctr_en;

    id157out_output[(getCycle()+1)%2] = id157in_input;
  }
  { // Node ID: 158 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id158in_input = id59out_rst_en;

    id158out_output[(getCycle()+1)%2] = id158in_input;
  }
  { // Node ID: 159 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id159in_input = id8out_s1_en;

    id159out_output[(getCycle()+1)%2] = id159in_input;
  }
  { // Node ID: 160 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id160in_input = id1out_intr_en;

    id160out_output[(getCycle()+1)%2] = id160in_input;
  }
  { // Node ID: 161 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id161in_input = id8out_sm_done;

    id161out_output[(getCycle()+1)%2] = id161in_input;
  }
  { // Node ID: 174 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id174in_input = id9out_output;

    id174out_output[(getCycle()+6)%7] = id174in_input;
  }
  { // Node ID: 3 (NodeInputMappedReg)
  }
  HWRawBits<2> id67out_result;

  { // Node ID: 67 (NodeSlice)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id67in_a = id3out_argin451;

    id67out_result = (slice<0,2>(id67in_a));
  }
  HWOffsetFix<2,0,UNSIGNED> id68out_output;

  { // Node ID: 68 (NodeReinterpret)
    const HWRawBits<2> &id68in_input = id67out_result;

    id68out_output = (cast_bits2fixed<2,0,UNSIGNED>(id68in_input));
  }
  HWRawBits<2> id23out_result;

  { // Node ID: 23 (NodeSlice)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id23in_a = id16out_counter0;

    id23out_result = (slice<0,2>(id23in_a));
  }
  HWOffsetFix<2,0,UNSIGNED> id24out_output;

  { // Node ID: 24 (NodeReinterpret)
    const HWRawBits<2> &id24in_input = id23out_result;

    id24out_output = (cast_bits2fixed<2,0,UNSIGNED>(id24in_input));
  }
  HWRawBits<2> id142out_output;

  { // Node ID: 142 (NodeReinterpret)
    const HWOffsetFix<2,0,UNSIGNED> &id142in_input = id24out_output;

    id142out_output = (cast_fixed2bits(id142in_input));
  }
  { // Node ID: 28 (NodeMux)
    const HWRawBits<2> &id28in_sel = id142out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id28in_option0 = id16out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id28in_option1 = id16out_counter0_extension0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id28in_option2 = id16out_counter0_extension1;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id28in_option3 = id16out_counter0_extension2;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id28x_1;

    switch((id28in_sel.getValueAsLong())) {
      case 0l:
        id28x_1 = id28in_option0;
        break;
      case 1l:
        id28x_1 = id28in_option1;
        break;
      case 2l:
        id28x_1 = id28in_option2;
        break;
      case 3l:
        id28x_1 = id28in_option3;
        break;
      default:
        id28x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id28out_result[(getCycle()+1)%2] = (id28x_1);
  }
  HWRawBits<5> id30out_result;

  { // Node ID: 30 (NodeSlice)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id30in_a = id28out_result[getCycle()%2];

    id30out_result = (slice<2,5>(id30in_a));
  }
  HWOffsetFix<5,0,UNSIGNED> id31out_output;

  { // Node ID: 31 (NodeReinterpret)
    const HWRawBits<5> &id31in_input = id30out_result;

    id31out_output = (cast_bits2fixed<5,0,UNSIGNED>(id31in_input));
  }
  { // Node ID: 163 (NodeFIFO)
    const HWOffsetFix<5,0,UNSIGNED> &id163in_input = id31out_output;

    id163out_output[(getCycle()+2)%3] = id163in_input;
  }
  { // Node ID: 162 (NodeFIFO)
    const HWRawBits<2> &id162in_input = id142out_output;

    id162out_output[(getCycle()+2)%3] = id162in_input;
  }
  { // Node ID: 2 (NodeInputMappedReg)
  }
  { // Node ID: 19 (NodeMul)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id19in_a = id2out_argin450;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id19in_b = id16out_counter0;

    id19out_result[(getCycle()+2)%3] = (mul_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id19in_a,id19in_b));
  }
  { // Node ID: 20 (NodeMul)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id20in_a = id2out_argin450;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id20in_b = id16out_counter0_extension0;

    id20out_result[(getCycle()+2)%3] = (mul_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id20in_a,id20in_b));
  }
  { // Node ID: 21 (NodeMul)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_a = id2out_argin450;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_b = id16out_counter0_extension1;

    id21out_result[(getCycle()+2)%3] = (mul_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id21in_a,id21in_b));
  }
  { // Node ID: 22 (NodeMul)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id22in_a = id2out_argin450;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id22in_b = id16out_counter0_extension2;

    id22out_result[(getCycle()+2)%3] = (mul_fixed<32,0,TWOSCOMPLEMENT,TONEAR>(id22in_a,id22in_b));
  }
  { // Node ID: 29 (NodeMux)
    const HWRawBits<2> &id29in_sel = id162out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id29in_option0 = id19out_result[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id29in_option1 = id20out_result[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id29in_option2 = id21out_result[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id29in_option3 = id22out_result[getCycle()%3];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id29x_1;

    switch((id29in_sel.getValueAsLong())) {
      case 0l:
        id29x_1 = id29in_option0;
        break;
      case 1l:
        id29x_1 = id29in_option1;
        break;
      case 2l:
        id29x_1 = id29in_option2;
        break;
      case 3l:
        id29x_1 = id29in_option3;
        break;
      default:
        id29x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id29out_result[(getCycle()+1)%2] = (id29x_1);
  }
  { // Node ID: 164 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id164in_input = id13out_ctr_en;

    id164out_output[(getCycle()+3)%4] = id164in_input;
  }
  HWRawBits<5> id66out_result;

  { // Node ID: 66 (NodeSlice)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id66in_a = id3out_argin451;

    id66out_result = (slice<2,5>(id66in_a));
  }
  HWOffsetFix<5,0,UNSIGNED> id69out_output;

  { // Node ID: 69 (NodeReinterpret)
    const HWRawBits<5> &id69in_input = id66out_result;

    id69out_output = (cast_bits2fixed<5,0,UNSIGNED>(id69in_input));
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 116 (NodeRAM)
    const bool id116_inputvalid = !(isFlushingActive() && getFlushLevel() >= (7l));
    const HWOffsetFix<5,0,UNSIGNED> &id116in_addrA = id163out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id116in_dina = id29out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id116in_wea = id164out_output[getCycle()%4];
    const HWOffsetFix<5,0,UNSIGNED> &id116in_addrB = id69out_output;

    long id116x_1;
    long id116x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id116x_3;

    (id116x_1) = (id116in_addrA.getValueAsLong());
    (id116x_2) = (id116in_addrB.getValueAsLong());
    switch(((long)((id116x_2)<(24l)))) {
      case 0l:
        id116x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id116x_3 = (id116sta_ram_store[(id116x_2)]);
        break;
      default:
        id116x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id116out_doutb[(getCycle()+2)%3] = (id116x_3);
    if(((id116in_wea.getValueAsBool())&id116_inputvalid)) {
      if(((id116x_1)<(24l))) {
        (id116sta_ram_store[(id116x_1)]) = id116in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_1("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 116) on port A, ram depth is 24.")));
      }
    }
  }
  HWRawBits<2> id32out_result;

  { // Node ID: 32 (NodeSlice)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id32in_a = id16out_counter0_extension0;

    id32out_result = (slice<0,2>(id32in_a));
  }
  HWOffsetFix<2,0,UNSIGNED> id33out_output;

  { // Node ID: 33 (NodeReinterpret)
    const HWRawBits<2> &id33in_input = id32out_result;

    id33out_output = (cast_bits2fixed<2,0,UNSIGNED>(id33in_input));
  }
  HWRawBits<2> id143out_output;

  { // Node ID: 143 (NodeReinterpret)
    const HWOffsetFix<2,0,UNSIGNED> &id143in_input = id33out_output;

    id143out_output = (cast_fixed2bits(id143in_input));
  }
  { // Node ID: 37 (NodeMux)
    const HWRawBits<2> &id37in_sel = id143out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id37in_option0 = id16out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id37in_option1 = id16out_counter0_extension0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id37in_option2 = id16out_counter0_extension1;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id37in_option3 = id16out_counter0_extension2;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id37x_1;

    switch((id37in_sel.getValueAsLong())) {
      case 0l:
        id37x_1 = id37in_option0;
        break;
      case 1l:
        id37x_1 = id37in_option1;
        break;
      case 2l:
        id37x_1 = id37in_option2;
        break;
      case 3l:
        id37x_1 = id37in_option3;
        break;
      default:
        id37x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id37out_result[(getCycle()+1)%2] = (id37x_1);
  }
  HWRawBits<5> id39out_result;

  { // Node ID: 39 (NodeSlice)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id39in_a = id37out_result[getCycle()%2];

    id39out_result = (slice<2,5>(id39in_a));
  }
  HWOffsetFix<5,0,UNSIGNED> id40out_output;

  { // Node ID: 40 (NodeReinterpret)
    const HWRawBits<5> &id40in_input = id39out_result;

    id40out_output = (cast_bits2fixed<5,0,UNSIGNED>(id40in_input));
  }
  { // Node ID: 166 (NodeFIFO)
    const HWOffsetFix<5,0,UNSIGNED> &id166in_input = id40out_output;

    id166out_output[(getCycle()+2)%3] = id166in_input;
  }
  { // Node ID: 165 (NodeFIFO)
    const HWRawBits<2> &id165in_input = id143out_output;

    id165out_output[(getCycle()+2)%3] = id165in_input;
  }
  { // Node ID: 38 (NodeMux)
    const HWRawBits<2> &id38in_sel = id165out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id38in_option0 = id19out_result[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id38in_option1 = id20out_result[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id38in_option2 = id21out_result[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id38in_option3 = id22out_result[getCycle()%3];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id38x_1;

    switch((id38in_sel.getValueAsLong())) {
      case 0l:
        id38x_1 = id38in_option0;
        break;
      case 1l:
        id38x_1 = id38in_option1;
        break;
      case 2l:
        id38x_1 = id38in_option2;
        break;
      case 3l:
        id38x_1 = id38in_option3;
        break;
      default:
        id38x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id38out_result[(getCycle()+1)%2] = (id38x_1);
  }
  HWOffsetFix<5,0,UNSIGNED> id70out_output;

  { // Node ID: 70 (NodeReinterpret)
    const HWRawBits<5> &id70in_input = id66out_result;

    id70out_output = (cast_bits2fixed<5,0,UNSIGNED>(id70in_input));
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 117 (NodeRAM)
    const bool id117_inputvalid = !(isFlushingActive() && getFlushLevel() >= (7l));
    const HWOffsetFix<5,0,UNSIGNED> &id117in_addrA = id166out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id117in_dina = id38out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id117in_wea = id164out_output[getCycle()%4];
    const HWOffsetFix<5,0,UNSIGNED> &id117in_addrB = id70out_output;

    long id117x_1;
    long id117x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id117x_3;

    (id117x_1) = (id117in_addrA.getValueAsLong());
    (id117x_2) = (id117in_addrB.getValueAsLong());
    switch(((long)((id117x_2)<(24l)))) {
      case 0l:
        id117x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id117x_3 = (id117sta_ram_store[(id117x_2)]);
        break;
      default:
        id117x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id117out_doutb[(getCycle()+2)%3] = (id117x_3);
    if(((id117in_wea.getValueAsBool())&id117_inputvalid)) {
      if(((id117x_1)<(24l))) {
        (id117sta_ram_store[(id117x_1)]) = id117in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_2("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 117) on port A, ram depth is 24.")));
      }
    }
  }
  HWRawBits<2> id41out_result;

  { // Node ID: 41 (NodeSlice)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id41in_a = id16out_counter0_extension1;

    id41out_result = (slice<0,2>(id41in_a));
  }
  HWOffsetFix<2,0,UNSIGNED> id42out_output;

  { // Node ID: 42 (NodeReinterpret)
    const HWRawBits<2> &id42in_input = id41out_result;

    id42out_output = (cast_bits2fixed<2,0,UNSIGNED>(id42in_input));
  }
  HWRawBits<2> id144out_output;

  { // Node ID: 144 (NodeReinterpret)
    const HWOffsetFix<2,0,UNSIGNED> &id144in_input = id42out_output;

    id144out_output = (cast_fixed2bits(id144in_input));
  }
  { // Node ID: 46 (NodeMux)
    const HWRawBits<2> &id46in_sel = id144out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id46in_option0 = id16out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id46in_option1 = id16out_counter0_extension0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id46in_option2 = id16out_counter0_extension1;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id46in_option3 = id16out_counter0_extension2;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id46x_1;

    switch((id46in_sel.getValueAsLong())) {
      case 0l:
        id46x_1 = id46in_option0;
        break;
      case 1l:
        id46x_1 = id46in_option1;
        break;
      case 2l:
        id46x_1 = id46in_option2;
        break;
      case 3l:
        id46x_1 = id46in_option3;
        break;
      default:
        id46x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id46out_result[(getCycle()+1)%2] = (id46x_1);
  }
  HWRawBits<5> id48out_result;

  { // Node ID: 48 (NodeSlice)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id48in_a = id46out_result[getCycle()%2];

    id48out_result = (slice<2,5>(id48in_a));
  }
  HWOffsetFix<5,0,UNSIGNED> id49out_output;

  { // Node ID: 49 (NodeReinterpret)
    const HWRawBits<5> &id49in_input = id48out_result;

    id49out_output = (cast_bits2fixed<5,0,UNSIGNED>(id49in_input));
  }
  { // Node ID: 169 (NodeFIFO)
    const HWOffsetFix<5,0,UNSIGNED> &id169in_input = id49out_output;

    id169out_output[(getCycle()+2)%3] = id169in_input;
  }
  { // Node ID: 168 (NodeFIFO)
    const HWRawBits<2> &id168in_input = id144out_output;

    id168out_output[(getCycle()+2)%3] = id168in_input;
  }
  { // Node ID: 47 (NodeMux)
    const HWRawBits<2> &id47in_sel = id168out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id47in_option0 = id19out_result[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id47in_option1 = id20out_result[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id47in_option2 = id21out_result[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id47in_option3 = id22out_result[getCycle()%3];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id47x_1;

    switch((id47in_sel.getValueAsLong())) {
      case 0l:
        id47x_1 = id47in_option0;
        break;
      case 1l:
        id47x_1 = id47in_option1;
        break;
      case 2l:
        id47x_1 = id47in_option2;
        break;
      case 3l:
        id47x_1 = id47in_option3;
        break;
      default:
        id47x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id47out_result[(getCycle()+1)%2] = (id47x_1);
  }
  HWOffsetFix<5,0,UNSIGNED> id71out_output;

  { // Node ID: 71 (NodeReinterpret)
    const HWRawBits<5> &id71in_input = id66out_result;

    id71out_output = (cast_bits2fixed<5,0,UNSIGNED>(id71in_input));
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 118 (NodeRAM)
    const bool id118_inputvalid = !(isFlushingActive() && getFlushLevel() >= (7l));
    const HWOffsetFix<5,0,UNSIGNED> &id118in_addrA = id169out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id118in_dina = id47out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id118in_wea = id164out_output[getCycle()%4];
    const HWOffsetFix<5,0,UNSIGNED> &id118in_addrB = id71out_output;

    long id118x_1;
    long id118x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id118x_3;

    (id118x_1) = (id118in_addrA.getValueAsLong());
    (id118x_2) = (id118in_addrB.getValueAsLong());
    switch(((long)((id118x_2)<(24l)))) {
      case 0l:
        id118x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id118x_3 = (id118sta_ram_store[(id118x_2)]);
        break;
      default:
        id118x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id118out_doutb[(getCycle()+2)%3] = (id118x_3);
    if(((id118in_wea.getValueAsBool())&id118_inputvalid)) {
      if(((id118x_1)<(24l))) {
        (id118sta_ram_store[(id118x_1)]) = id118in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_3("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 118) on port A, ram depth is 24.")));
      }
    }
  }
  HWRawBits<2> id50out_result;

  { // Node ID: 50 (NodeSlice)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id50in_a = id16out_counter0_extension2;

    id50out_result = (slice<0,2>(id50in_a));
  }
  HWOffsetFix<2,0,UNSIGNED> id51out_output;

  { // Node ID: 51 (NodeReinterpret)
    const HWRawBits<2> &id51in_input = id50out_result;

    id51out_output = (cast_bits2fixed<2,0,UNSIGNED>(id51in_input));
  }
  HWRawBits<2> id145out_output;

  { // Node ID: 145 (NodeReinterpret)
    const HWOffsetFix<2,0,UNSIGNED> &id145in_input = id51out_output;

    id145out_output = (cast_fixed2bits(id145in_input));
  }
  { // Node ID: 55 (NodeMux)
    const HWRawBits<2> &id55in_sel = id145out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id55in_option0 = id16out_counter0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id55in_option1 = id16out_counter0_extension0;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id55in_option2 = id16out_counter0_extension1;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id55in_option3 = id16out_counter0_extension2;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id55x_1;

    switch((id55in_sel.getValueAsLong())) {
      case 0l:
        id55x_1 = id55in_option0;
        break;
      case 1l:
        id55x_1 = id55in_option1;
        break;
      case 2l:
        id55x_1 = id55in_option2;
        break;
      case 3l:
        id55x_1 = id55in_option3;
        break;
      default:
        id55x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id55out_result[(getCycle()+1)%2] = (id55x_1);
  }
  HWRawBits<5> id57out_result;

  { // Node ID: 57 (NodeSlice)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id57in_a = id55out_result[getCycle()%2];

    id57out_result = (slice<2,5>(id57in_a));
  }
  HWOffsetFix<5,0,UNSIGNED> id58out_output;

  { // Node ID: 58 (NodeReinterpret)
    const HWRawBits<5> &id58in_input = id57out_result;

    id58out_output = (cast_bits2fixed<5,0,UNSIGNED>(id58in_input));
  }
  { // Node ID: 172 (NodeFIFO)
    const HWOffsetFix<5,0,UNSIGNED> &id172in_input = id58out_output;

    id172out_output[(getCycle()+2)%3] = id172in_input;
  }
  { // Node ID: 171 (NodeFIFO)
    const HWRawBits<2> &id171in_input = id145out_output;

    id171out_output[(getCycle()+2)%3] = id171in_input;
  }
  { // Node ID: 56 (NodeMux)
    const HWRawBits<2> &id56in_sel = id171out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id56in_option0 = id19out_result[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id56in_option1 = id20out_result[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id56in_option2 = id21out_result[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id56in_option3 = id22out_result[getCycle()%3];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id56x_1;

    switch((id56in_sel.getValueAsLong())) {
      case 0l:
        id56x_1 = id56in_option0;
        break;
      case 1l:
        id56x_1 = id56in_option1;
        break;
      case 2l:
        id56x_1 = id56in_option2;
        break;
      case 3l:
        id56x_1 = id56in_option3;
        break;
      default:
        id56x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id56out_result[(getCycle()+1)%2] = (id56x_1);
  }
  HWOffsetFix<5,0,UNSIGNED> id72out_output;

  { // Node ID: 72 (NodeReinterpret)
    const HWRawBits<5> &id72in_input = id66out_result;

    id72out_output = (cast_bits2fixed<5,0,UNSIGNED>(id72in_input));
  }
  if ( (getFillLevel() >= (7l)))
  { // Node ID: 119 (NodeRAM)
    const bool id119_inputvalid = !(isFlushingActive() && getFlushLevel() >= (7l));
    const HWOffsetFix<5,0,UNSIGNED> &id119in_addrA = id172out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id119in_dina = id56out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id119in_wea = id164out_output[getCycle()%4];
    const HWOffsetFix<5,0,UNSIGNED> &id119in_addrB = id72out_output;

    long id119x_1;
    long id119x_2;
    HWOffsetFix<32,0,TWOSCOMPLEMENT> id119x_3;

    (id119x_1) = (id119in_addrA.getValueAsLong());
    (id119x_2) = (id119in_addrB.getValueAsLong());
    switch(((long)((id119x_2)<(24l)))) {
      case 0l:
        id119x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
      case 1l:
        id119x_3 = (id119sta_ram_store[(id119x_2)]);
        break;
      default:
        id119x_3 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id119out_doutb[(getCycle()+2)%3] = (id119x_3);
    if(((id119in_wea.getValueAsBool())&id119_inputvalid)) {
      if(((id119x_1)<(24l))) {
        (id119sta_ram_store[(id119x_1)]) = id119in_dina;
      }
      else {
        throw std::runtime_error((format_string_TopKernel_4("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 119) on port A, ram depth is 24.")));
      }
    }
  }
  { // Node ID: 73 (NodeMux)
    const HWOffsetFix<2,0,UNSIGNED> &id73in_sel = id68out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id73in_option0 = id116out_doutb[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id73in_option1 = id117out_doutb[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id73in_option2 = id118out_doutb[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id73in_option3 = id119out_doutb[getCycle()%3];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id73x_1;

    switch((id73in_sel.getValueAsLong())) {
      case 0l:
        id73x_1 = id73in_option0;
        break;
      case 1l:
        id73x_1 = id73in_option1;
        break;
      case 2l:
        id73x_1 = id73in_option2;
        break;
      case 3l:
        id73x_1 = id73in_option3;
        break;
      default:
        id73x_1 = (c_hw_fix_32_0_sgn_undef);
        break;
    }
    id73out_result[(getCycle()+1)%2] = (id73x_1);
  }
  if ( (getFillLevel() >= (10l)) && (getFlushLevel() < (10l)|| !isFlushingActive() ))
  { // Node ID: 74 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id74in_load = id174out_output[getCycle()%7];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id74in_data = id73out_result[getCycle()%2];

    bool id74x_1;

    (id74x_1) = ((id74in_load.getValueAsBool())&(!(((getFlushLevel())>=(10l))&(isFlushingActive()))));
    if((id74x_1)) {
      setMappedRegValue("argout452", id74in_data);
    }
  }
  { // Node ID: 179 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id179in_input = id160out_output[getCycle()%2];

    id179out_output[(getCycle()+1)%2] = id179in_input;
  }
  { // Node ID: 182 (NodeConstantRawBits)
  }
  { // Node ID: 79 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id79in_a = id76out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id79in_b = id182out_value;

    id79out_result[(getCycle()+1)%2] = (eq_fixed(id79in_a,id79in_b));
  }
  { // Node ID: 80 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id80in_a = id179out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id80in_b = id79out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id80x_1;

    (id80x_1) = (and_fixed(id80in_a,id80in_b));
    id80out_result[(getCycle()+1)%2] = (id80x_1);
  }
  { // Node ID: 96 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id97out_result;

  { // Node ID: 97 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id97in_a = id96out_io_intrCmd_force_disabled;

    id97out_result = (not_fixed(id97in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id98out_result;

  { // Node ID: 98 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id98in_a = id80out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id98in_b = id97out_result;

    HWOffsetFix<1,0,UNSIGNED> id98x_1;

    (id98x_1) = (and_fixed(id98in_a,id98in_b));
    id98out_result = (id98x_1);
  }
  HWRawBits<1> id107out_output;

  { // Node ID: 107 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id107in_input = id179out_output[getCycle()%2];

    id107out_output = (cast_fixed2bits(id107in_input));
  }
  { // Node ID: 177 (NodeFIFO)
    const HWRawBits<1> &id177in_input = id107out_output;

    id177out_output[(getCycle()+1)%2] = id177in_input;
  }
  { // Node ID: 136 (NodeConstantRawBits)
  }
  { // Node ID: 138 (NodeConstantRawBits)
  }
  HWRawBits<8> id103out_output;

  { // Node ID: 103 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id103in_input = id138out_value;

    id103out_output = (cast_fixed2bits(id103in_input));
  }
  { // Node ID: 140 (NodeConstantRawBits)
  }
  { // Node ID: 141 (NodeConstantRawBits)
  }
  HWRawBits<40> id102out_result;

  { // Node ID: 102 (NodeCat)
    const HWRawBits<8> &id102in_in0 = id140out_value;
    const HWRawBits<32> &id102in_in1 = id141out_value;

    id102out_result = (cat(id102in_in0,id102in_in1));
  }
  HWRawBits<48> id104out_result;

  { // Node ID: 104 (NodeCat)
    const HWRawBits<8> &id104in_in0 = id103out_output;
    const HWRawBits<40> &id104in_in1 = id102out_result;

    id104out_result = (cat(id104in_in0,id104in_in1));
  }
  HWRawBits<63> id106out_result;

  { // Node ID: 106 (NodeCat)
    const HWRawBits<15> &id106in_in0 = id136out_value;
    const HWRawBits<48> &id106in_in1 = id104out_result;

    id106out_result = (cat(id106in_in0,id106in_in1));
  }
  HWRawBits<64> id108out_result;

  { // Node ID: 108 (NodeCat)
    const HWRawBits<1> &id108in_in0 = id177out_output[getCycle()%2];
    const HWRawBits<63> &id108in_in1 = id106out_result;

    id108out_result = (cat(id108in_in0,id108in_in1));
  }
  if ( (getFillLevel() >= (7l)) && (getFlushLevel() < (7l)|| !isFlushingActive() ))
  { // Node ID: 99 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id99in_output_control = id98out_result;
    const HWRawBits<64> &id99in_data = id108out_result;

    bool id99x_1;

    (id99x_1) = ((id99in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(7l))&(isFlushingActive()))));
    if((id99x_1)) {
      writeOutput(m_intrCmd, id99in_data);
    }
  }
  { // Node ID: 109 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 110 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id110in_load = id109out_value;
    const HWOffsetFix<64,0,UNSIGNED> &id110in_data = id1out_cycles;

    bool id110x_1;

    (id110x_1) = ((id110in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id110x_1)) {
      setMappedRegValue("cycles", id110in_data);
    }
  }
  { // Node ID: 112 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id113out_result;

  { // Node ID: 113 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id113in_a = id112out_io_intrStream_force_disabled;

    id113out_result = (not_fixed(id113in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id114out_result;

  { // Node ID: 114 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id114in_a = id179out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id114in_b = id113out_result;

    HWOffsetFix<1,0,UNSIGNED> id114x_1;

    (id114x_1) = (and_fixed(id114in_a,id114in_b));
    id114out_result = (id114x_1);
  }
  { // Node ID: 111 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (6l)) && (getFlushLevel() < (6l)|| !isFlushingActive() ))
  { // Node ID: 115 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id115in_output_control = id114out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id115in_data = id111out_value;

    bool id115x_1;

    (id115x_1) = ((id115in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(6l))&(isFlushingActive()))));
    if((id115x_1)) {
      writeOutput(m_intrStream, id115in_data);
    }
  }
  { // Node ID: 124 (NodeConstantRawBits)
  }
  { // Node ID: 181 (NodeConstantRawBits)
  }
  { // Node ID: 121 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (10l)))
  { // Node ID: 122 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id122in_enable = id181out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id122in_max = id121out_value;

    HWOffsetFix<49,0,UNSIGNED> id122x_1;
    HWOffsetFix<1,0,UNSIGNED> id122x_2;
    HWOffsetFix<1,0,UNSIGNED> id122x_3;
    HWOffsetFix<49,0,UNSIGNED> id122x_4t_1e_1;

    id122out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id122st_count)));
    (id122x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id122st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id122x_2) = (gte_fixed((id122x_1),id122in_max));
    (id122x_3) = (and_fixed((id122x_2),id122in_enable));
    id122out_wrap = (id122x_3);
    if((id122in_enable.getValueAsBool())) {
      if(((id122x_3).getValueAsBool())) {
        (id122st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id122x_4t_1e_1) = (id122x_1);
        (id122st_count) = (id122x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id123out_output;

  { // Node ID: 123 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id123in_input = id122out_count;

    id123out_output = id123in_input;
  }
  if ( (getFillLevel() >= (11l)) && (getFlushLevel() < (11l)|| !isFlushingActive() ))
  { // Node ID: 125 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id125in_load = id124out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id125in_data = id123out_output;

    bool id125x_1;

    (id125x_1) = ((id125in_load.getValueAsBool())&(!(((getFlushLevel())>=(11l))&(isFlushingActive()))));
    if((id125x_1)) {
      setMappedRegValue("current_run_cycle_count", id125in_data);
    }
  }
  { // Node ID: 180 (NodeConstantRawBits)
  }
  { // Node ID: 127 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 128 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id128in_enable = id180out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id128in_max = id127out_value;

    HWOffsetFix<49,0,UNSIGNED> id128x_1;
    HWOffsetFix<1,0,UNSIGNED> id128x_2;
    HWOffsetFix<1,0,UNSIGNED> id128x_3;
    HWOffsetFix<49,0,UNSIGNED> id128x_4t_1e_1;

    id128out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id128st_count)));
    (id128x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id128st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id128x_2) = (gte_fixed((id128x_1),id128in_max));
    (id128x_3) = (and_fixed((id128x_2),id128in_enable));
    id128out_wrap = (id128x_3);
    if((id128in_enable.getValueAsBool())) {
      if(((id128x_3).getValueAsBool())) {
        (id128st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id128x_4t_1e_1) = (id128x_1);
        (id128st_count) = (id128x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 130 (NodeInputMappedReg)
  }
  { // Node ID: 131 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id131in_a = id128out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id131in_b = id130out_run_cycle_count;

    id131out_result[(getCycle()+1)%2] = (eq_fixed(id131in_a,id131in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 129 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id129in_start = id131out_result[getCycle()%2];

    if((id129in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
