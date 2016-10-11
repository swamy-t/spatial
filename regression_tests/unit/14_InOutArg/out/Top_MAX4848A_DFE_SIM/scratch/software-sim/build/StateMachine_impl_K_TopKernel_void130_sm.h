#ifndef STATE_MACHINE_IMPL_TopKernel_void130_sm_H
#define STATE_MACHINE_IMPL_TopKernel_void130_sm_H

#include "varint_s.h"
#include "varint_u.h"
#include "Debuggable.h"

namespace maxcompilersim {
namespace state_machine {

class Kernel_TopKernel_void130_sm {
public:
	Kernel_TopKernel_void130_sm(maxcompilersim::DebugStreams *debug_output, int node_number);
	void reset();
	void execute() {execute(true);}
	void execute(bool sm_not_flushing);

	// stream inputs
	varint_u<1> inputdata_ctr_done;
	varint_u<1> inputdata_rst_done;
	varint_u<1> inputdata_sm_en;
	varint_s<32> inputdata_sm_maxIn_0;

	// stream outputs
	varint_u<1> outputdata_ctr_en;
	varint_s<32> outputdata_ctr_maxOut_0;
	varint_u<1> outputdata_rst_en;
	varint_u<1> outputdata_sm_done;

private:
	maxcompilersim::DebugStreams *m_debug_output;
	int m_node_number;

	// integer state
	varint_s<32> state1;
	varint_s<32> state3;

	// enum state
	varint_u<3> state2;
};

}
}

#endif // !defined(STATE_MACHINE_IMPL_TopKernel_void130_sm_H)
