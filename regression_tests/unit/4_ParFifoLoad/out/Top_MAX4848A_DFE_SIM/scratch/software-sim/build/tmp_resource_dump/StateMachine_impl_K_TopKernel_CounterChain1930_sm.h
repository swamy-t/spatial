#ifndef STATE_MACHINE_IMPL_TopKernel_CounterChain1930_sm_H
#define STATE_MACHINE_IMPL_TopKernel_CounterChain1930_sm_H

#include "varint_s.h"
#include "varint_u.h"
#include "Debuggable.h"

namespace maxcompilersim {
namespace state_machine {

class Kernel_TopKernel_CounterChain1930_sm {
public:
	Kernel_TopKernel_CounterChain1930_sm(maxcompilersim::DebugStreams *debug_output, int node_number);
	void reset();
	void execute() {execute(true);}
	void execute(bool sm_not_flushing);

	// stream inputs
	varint_u<1> inputdata_en;
	varint_s<32> inputdata_max0;
	varint_u<1> inputdata_reset;

	// stream outputs
	varint_s<32> outputdata_counter0;
	varint_u<1> outputdata_done;
	varint_u<1> outputdata_saturated;

private:
	maxcompilersim::DebugStreams *m_debug_output;
	int m_node_number;

	// integer state
	varint_s<32> state2;

	// enum state
	varint_u<1> state1;
};

}
}

#endif // !defined(STATE_MACHINE_IMPL_TopKernel_CounterChain1930_sm_H)
