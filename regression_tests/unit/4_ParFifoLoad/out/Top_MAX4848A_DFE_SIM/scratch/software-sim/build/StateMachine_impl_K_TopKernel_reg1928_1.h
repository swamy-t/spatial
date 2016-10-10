#ifndef STATE_MACHINE_IMPL_TopKernel_reg1928_1_H
#define STATE_MACHINE_IMPL_TopKernel_reg1928_1_H

#include "varint_s.h"
#include "varint_u.h"
#include "Debuggable.h"

namespace maxcompilersim {
namespace state_machine {

class Kernel_TopKernel_reg1928_1 {
public:
	Kernel_TopKernel_reg1928_1(maxcompilersim::DebugStreams *debug_output, int node_number);
	void reset();
	void execute() {execute(true);}
	void execute(bool sm_not_flushing);

	// stream inputs
	varint_u<1> inputdata_broadcast;
	varint_u<2> inputdata_numBlanks;
	varint_u<1> inputdata_stageDone0;
	varint_u<1> inputdata_stageDone1;
	varint_u<1> inputdata_stageDone2;
	varint_u<1> inputdata_stageDone3;
	varint_u<1> inputdata_stageDone4;
	varint_u<1> inputdata_stageDone5;
	varint_u<1> inputdata_stageDone6;
	varint_u<1> inputdata_stageDone7;
	varint_u<1> inputdata_stageEn0;
	varint_u<1> inputdata_stageEn1;
	varint_u<1> inputdata_stageEn2;
	varint_u<1> inputdata_stageEn3;
	varint_u<1> inputdata_stageEn4;
	varint_u<1> inputdata_stageEn5;
	varint_u<1> inputdata_stageEn6;
	varint_u<1> inputdata_stageEn7;

	// stream outputs
	varint_u<2> outputdata_curBuf0;
	varint_u<2> outputdata_curBuf1;

private:
	maxcompilersim::DebugStreams *m_debug_output;
	int m_node_number;

	// integer state
	varint_u<2> state1;
	varint_u<2> state2;
	varint_u<8> state4;
	varint_u<8> state5;
	varint_u<2> state6;

	// enum state
	varint_u<1> state3;
};

}
}

#endif // !defined(STATE_MACHINE_IMPL_TopKernel_reg1928_1_H)
