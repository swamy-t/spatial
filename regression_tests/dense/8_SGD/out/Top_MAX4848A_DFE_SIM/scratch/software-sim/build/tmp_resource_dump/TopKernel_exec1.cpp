#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "TopKernel_exec1.h"
//#include "TopKernel.h"

namespace maxcompilersim {

void TopKernel::execute1(const TopKernelBlock1Vars &in_vars) {
  { // Node ID: 910 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id910in_input = id890out_output[getCycle()%2];

    id910out_output[(getCycle()+1)%2] = id910in_input;
  }
  HWRawBits<1> id578out_output;

  { // Node ID: 578 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id578in_input = id910out_output[getCycle()%2];

    id578out_output = (cast_fixed2bits(id578in_input));
  }
  { // Node ID: 669 (NodeConstantRawBits)
  }
  { // Node ID: 671 (NodeConstantRawBits)
  }
  HWRawBits<8> id574out_output;

  { // Node ID: 574 (NodeReinterpret)
    const HWOffsetFix<8,0,UNSIGNED> &id574in_input = id671out_value;

    id574out_output = (cast_fixed2bits(id574in_input));
  }
  { // Node ID: 673 (NodeConstantRawBits)
  }
  { // Node ID: 674 (NodeConstantRawBits)
  }
  HWRawBits<40> id573out_result;

  { // Node ID: 573 (NodeCat)
    const HWRawBits<8> &id573in_in0 = id673out_value;
    const HWRawBits<32> &id573in_in1 = id674out_value;

    id573out_result = (cat(id573in_in0,id573in_in1));
  }
  HWRawBits<48> id575out_result;

  { // Node ID: 575 (NodeCat)
    const HWRawBits<8> &id575in_in0 = id574out_output;
    const HWRawBits<40> &id575in_in1 = id573out_result;

    id575out_result = (cat(id575in_in0,id575in_in1));
  }
  HWRawBits<63> id577out_result;

  { // Node ID: 577 (NodeCat)
    const HWRawBits<15> &id577in_in0 = id669out_value;
    const HWRawBits<48> &id577in_in1 = id575out_result;

    id577out_result = (cat(id577in_in0,id577in_in1));
  }
  HWRawBits<64> id579out_result;

  { // Node ID: 579 (NodeCat)
    const HWRawBits<1> &id579in_in0 = id578out_output;
    const HWRawBits<63> &id579in_in1 = id577out_result;

    id579out_result = (cat(id579in_in0,id579in_in1));
  }
  if ( (getFillLevel() >= (6l)) && (getFlushLevel() < (6l)|| !isFlushingActive() ))
  { // Node ID: 570 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id570in_output_control = in_vars.id569out_result;
    const HWRawBits<64> &id570in_data = id579out_result;

    bool id570x_1;

    (id570x_1) = ((id570in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(6l))&(isFlushingActive()))));
    if((id570x_1)) {
      writeOutput(m_intrCmd, id570in_data);
    }
  }
  { // Node ID: 580 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 581 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id581in_load = id580out_value;
    const HWOffsetFix<64,0,UNSIGNED> &id581in_data = in_vars.id1out_cycles;

    bool id581x_1;

    (id581x_1) = ((id581in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id581x_1)) {
      setMappedRegValue("cycles", id581in_data);
    }
  }
  { // Node ID: 583 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id584out_result;

  { // Node ID: 584 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id584in_a = id583out_io_intrStream_force_disabled;

    id584out_result = (not_fixed(id584in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id585out_result;

  { // Node ID: 585 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id585in_a = id910out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id585in_b = id584out_result;

    HWOffsetFix<1,0,UNSIGNED> id585x_1;

    (id585x_1) = (and_fixed(id585in_a,id585in_b));
    id585out_result = (id585x_1);
  }
  { // Node ID: 582 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (6l)) && (getFlushLevel() < (6l)|| !isFlushingActive() ))
  { // Node ID: 586 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id586in_output_control = id585out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id586in_data = id582out_value;

    bool id586x_1;

    (id586x_1) = ((id586in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(6l))&(isFlushingActive()))));
    if((id586x_1)) {
      writeOutput(m_intrStream, id586in_data);
    }
  }
  { // Node ID: 599 (NodeConstantRawBits)
  }
  { // Node ID: 914 (NodeConstantRawBits)
  }
  { // Node ID: 596 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (124l)))
  { // Node ID: 597 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id597in_enable = id914out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id597in_max = id596out_value;

    HWOffsetFix<49,0,UNSIGNED> id597x_1;
    HWOffsetFix<1,0,UNSIGNED> id597x_2;
    HWOffsetFix<1,0,UNSIGNED> id597x_3;
    HWOffsetFix<49,0,UNSIGNED> id597x_4t_1e_1;

    id597out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id597st_count)));
    (id597x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id597st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id597x_2) = (gte_fixed((id597x_1),id597in_max));
    (id597x_3) = (and_fixed((id597x_2),id597in_enable));
    id597out_wrap = (id597x_3);
    if((id597in_enable.getValueAsBool())) {
      if(((id597x_3).getValueAsBool())) {
        (id597st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id597x_4t_1e_1) = (id597x_1);
        (id597st_count) = (id597x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id598out_output;

  { // Node ID: 598 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id598in_input = id597out_count;

    id598out_output = id598in_input;
  }
  if ( (getFillLevel() >= (125l)) && (getFlushLevel() < (125l)|| !isFlushingActive() ))
  { // Node ID: 600 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id600in_load = id599out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id600in_data = id598out_output;

    bool id600x_1;

    (id600x_1) = ((id600in_load.getValueAsBool())&(!(((getFlushLevel())>=(125l))&(isFlushingActive()))));
    if((id600x_1)) {
      setMappedRegValue("current_run_cycle_count", id600in_data);
    }
  }
  { // Node ID: 913 (NodeConstantRawBits)
  }
  { // Node ID: 602 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 603 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id603in_enable = id913out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id603in_max = id602out_value;

    HWOffsetFix<49,0,UNSIGNED> id603x_1;
    HWOffsetFix<1,0,UNSIGNED> id603x_2;
    HWOffsetFix<1,0,UNSIGNED> id603x_3;
    HWOffsetFix<49,0,UNSIGNED> id603x_4t_1e_1;

    id603out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id603st_count)));
    (id603x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id603st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id603x_2) = (gte_fixed((id603x_1),id603in_max));
    (id603x_3) = (and_fixed((id603x_2),id603in_enable));
    id603out_wrap = (id603x_3);
    if((id603in_enable.getValueAsBool())) {
      if(((id603x_3).getValueAsBool())) {
        (id603st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id603x_4t_1e_1) = (id603x_1);
        (id603st_count) = (id603x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 605 (NodeInputMappedReg)
  }
  { // Node ID: 606 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id606in_a = id603out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id606in_b = id605out_run_cycle_count;

    id606out_result[(getCycle()+1)%2] = (eq_fixed(id606in_a,id606in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 604 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id604in_start = id606out_result[getCycle()%2];

    if((id604in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
