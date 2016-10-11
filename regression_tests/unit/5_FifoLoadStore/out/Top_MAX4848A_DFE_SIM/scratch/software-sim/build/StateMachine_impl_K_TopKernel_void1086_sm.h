#ifndef STATE_MACHINE_IMPL_TopKernel_void1086_sm_H
#define STATE_MACHINE_IMPL_TopKernel_void1086_sm_H

#include "varint_s.h"
#include "varint_u.h"
#include "Debuggable.h"

namespace maxcompilersim {
namespace state_machine {

class Kernel_TopKernel_void1086_sm {
public:
	Kernel_TopKernel_void1086_sm(maxcompilersim::DebugStreams *debug_output, int node_number);
	void reset();
	void execute() {execute(true);}
	void execute(bool sm_not_flushing);

	// stream inputs
	varint_u<1> inputdata_s0_done;
	varint_u<1> inputdata_s1_done;
	varint_u<1> inputdata_sm_en;
	varint_u<32> inputdata_sm_numIter;

	// stream outputs
	varint_u<1> outputdata_rst_en;
	varint_u<1> outputdata_s0_en;
	varint_u<1> outputdata_s1_en;
	varint_u<1> outputdata_sm_done;

private:
	maxcompilersim::DebugStreams *m_debug_output;
	int m_node_number;

	// integer state
	varint_u<32> state2;
	varint_u<32> state3;
	varint_u<32> state4;
	varint_u<1> state5;
	varint_u<1> state6;

	// enum state
	varint_u<3> state1;
};

}
}

#endif // !defined(STATE_MACHINE_IMPL_TopKernel_void1086_sm_H)
