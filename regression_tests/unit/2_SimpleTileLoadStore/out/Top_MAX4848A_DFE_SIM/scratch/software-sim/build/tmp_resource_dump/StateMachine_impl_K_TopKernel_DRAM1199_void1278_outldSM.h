#ifndef STATE_MACHINE_IMPL_TopKernel_DRAM1199_void1278_outldSM_H
#define STATE_MACHINE_IMPL_TopKernel_DRAM1199_void1278_outldSM_H

#include "varint_s.h"
#include "varint_u.h"
#include "Debuggable.h"

namespace maxcompilersim {
namespace state_machine {

class Kernel_TopKernel_DRAM1199_void1278_outldSM {
public:
	Kernel_TopKernel_DRAM1199_void1278_outldSM(maxcompilersim::DebugStreams *debug_output, int node_number);
	void reset();
	void execute() {execute(true);}
	void execute(bool sm_not_flushing);

	// stream inputs
	varint_u<1> inputdata_memDone;
	varint_u<1> inputdata_sm_en;

	// stream outputs
	varint_u<1> outputdata_memStart;
	varint_u<1> outputdata_sm_done;

private:
	maxcompilersim::DebugStreams *m_debug_output;
	int m_node_number;

	// enum state
	varint_u<2> state1;
};

}
}

#endif // !defined(STATE_MACHINE_IMPL_TopKernel_DRAM1199_void1278_outldSM_H)
