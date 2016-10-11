#ifndef STATE_MACHINE_IMPL_TopKernel_metapipe1065_FixedPoint8741_2_H
#define STATE_MACHINE_IMPL_TopKernel_metapipe1065_FixedPoint8741_2_H

#include "varint_s.h"
#include "varint_u.h"
#include "Debuggable.h"

namespace maxcompilersim {
namespace state_machine {

class Kernel_TopKernel_metapipe1065_FixedPoint8741_2 {
public:
	Kernel_TopKernel_metapipe1065_FixedPoint8741_2(maxcompilersim::DebugStreams *debug_output, int node_number);
	void reset();
	void execute() {execute(true);}
	void execute(bool sm_not_flushing);

	// stream inputs
	varint_u<1> inputdata_r_done;
	varint_u<1> inputdata_w_done;

	// stream outputs
	varint_u<1> outputdata_curBuf;

private:
	maxcompilersim::DebugStreams *m_debug_output;
	int m_node_number;

	// integer state
	varint_u<1> state2;

	// enum state
	varint_u<2> state1;
};

}
}

#endif // !defined(STATE_MACHINE_IMPL_TopKernel_metapipe1065_FixedPoint8741_2_H)
