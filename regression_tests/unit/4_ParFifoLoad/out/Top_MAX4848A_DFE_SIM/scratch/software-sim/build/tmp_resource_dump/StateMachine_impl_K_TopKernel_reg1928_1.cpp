#include "StateMachine_impl_K_TopKernel_reg1928_1.h"
#include <boost/format.hpp>
#include "SimException.h"

namespace {

	using maxcompilersim::varint_u;
	using maxcompilersim::varint_s;

	template<uint size>
	varint_u<size> leading1detect(const varint_u<size> &x) {
		varint_u<size> r;

		for (uint i = 0; i < size; ++i) {
			uint j = size - 1 - i;

			if (x.get_bit(j)) {
				r.set_bit(j, true);
				break;
			}
		}

		return r;
	}

	template<uint size>
	varint_s<size> leading1detect(const varint_s<size> &x) {
		varint_s<size> r;

		for (uint i = 0; i < size; ++i) {
			uint j = size - 1 - i;

			if (x.get_bit(j)) {
				r.set_bit(j, true);
				break;
			}
		}

		return r;
	}

	template<uint size>
	varint_u<size> trailing1detect(const varint_u<size> &x) {
		varint_u<size> r;

		for (uint i = 0; i < size; ++i) {
			if (x.get_bit(i)) {
				r.set_bit(i, true);
				break;
			}
		}

		return r;
	}

	template<uint size>
	varint_s<size> trailing1detect(const varint_s<size> &x) {
		varint_s<size> r;

		for (uint i = 0; i < size; ++i) {
			if (x.get_bit(i)) {
				r.set_bit(i, true);
				break;
			}
		}

		return r;
	}

	template<uint size, uint result_size>
	varint_u<result_size> one_hot_decode(const varint_u<size> &x) {
		varint_u<result_size> r;

		for (uint i = 0; i < size; ++i) {
			if (x.get_bit(i)) {
				r.set_bits(0, result_size, i);
				break;
			}
		}

		return r;
	}

	template<uint size, uint result_size>
	varint_u<result_size> one_hot_encode(const varint_u<size> &x) {
		varint_u<result_size> r;

		r.set_bit(x.toUInt64(), true);

		return r;
	}

	template<uint size, uint result_size>
	varint_s<result_size> one_hot_encode(const varint_s<size> &x) {
		varint_s<result_size> r;

		r.set_bit(x.toUInt64(), true);

		return r;
	}

	template<uint size>
	varint_u<size> reverse(const varint_u<size> &x) {
		varint_u<size> r;

		for (uint i = 0; i < size; ++i)
			r.set_bit(i, x.get_bit(size - 1 - i));

		return r;
	}

	template<uint size>
	varint_s<size> reverse(const varint_s<size> &x) {
		varint_s<size> r;

		for (uint i = 0; i < size; ++i)
			r.set_bit(i, x.get_bit(size - 1 - i));

		return r;
	}
}
maxcompilersim::state_machine::Kernel_TopKernel_reg1928_1::Kernel_TopKernel_reg1928_1(maxcompilersim::DebugStreams *debug_output, int node_number) :
m_debug_output(debug_output),
m_node_number(node_number),
state1(1),
state2(0),
state4(0),
state5(0),
state6(0),
state3(0)
{ }



void
maxcompilersim::state_machine::Kernel_TopKernel_reg1928_1::reset() {
	state1 = 1;
	state2 = 0;
	state4 = 0;
	state5 = 0;
	state6 = 0;
	state3 = 0;
}



void
maxcompilersim::state_machine::Kernel_TopKernel_reg1928_1::execute(const bool sm_not_flushing) {
	varint_u<1> varint_sm_not_flushing(sm_not_flushing);
	// make copies of current state
	varint_u<2> copy_state1(state1);
	varint_u<2> copy_state2(state2);
	varint_u<8> copy_state4(state4);
	varint_u<8> copy_state5(state5);
	varint_u<2> copy_state6(state6);
	varint_u<1> copy_state3(state3);
	
	// make copies of outputs
	varint_u<2> copy_outputdata_curBuf0(outputdata_curBuf0);
	varint_u<2> copy_outputdata_curBuf1(outputdata_curBuf1);
	
	
	switch (static_cast<int>(state3)) {
		case 0:
			copy_state4 = ((((((((varint_u<8>(inputdata_stageDone0) << 0) | (varint_u<8>(inputdata_stageDone1) << 1)) | (varint_u<8>(inputdata_stageDone2) << 2)) | (varint_u<8>(inputdata_stageDone3) << 3)) | (varint_u<8>(inputdata_stageDone4) << 4)) | (varint_u<8>(inputdata_stageDone5) << 5)) | (varint_u<8>(inputdata_stageDone6) << 6)) | (varint_u<8>(inputdata_stageDone7) << 7)) | state4;
			copy_state5 = ((((((((varint_u<8>(inputdata_stageEn0) << 0) | (varint_u<8>(inputdata_stageEn1) << 1)) | (varint_u<8>(inputdata_stageEn2) << 2)) | (varint_u<8>(inputdata_stageEn3) << 3)) | (varint_u<8>(inputdata_stageEn4) << 4)) | (varint_u<8>(inputdata_stageEn5) << 5)) | (varint_u<8>(inputdata_stageEn6) << 6)) | (varint_u<8>(inputdata_stageEn7) << 7)) | state5;
			if (varint_u<1>(state4 == state5) & varint_u<1>(state5 != varint_u<8>(0x0l))) {
				copy_state3 = varint_u<1>(0x1l);
			}
			break;
		case 1:
			if (varint_u<1>(state5 == varint_u<8>(0x2l))) {
				if (varint_u<1>(state6 >= inputdata_numBlanks)) {
					copy_state6 = varint_u<2>(0x0l);
				} else {
					copy_state6 = state6 + varint_u<2>(0x1l);
					if (varint_u<1>(state1 == varint_u<2>(0x1l))) {
						copy_state1 = varint_u<2>(0x0l);
					} else {
						copy_state1 = state1 + varint_u<2>(0x1l);
					}
					if (varint_u<1>(state2 == varint_u<2>(0x1l))) {
						copy_state2 = varint_u<2>(0x0l);
					} else {
						copy_state2 = state2 + varint_u<2>(0x1l);
					}
				}
			} else {
				if (varint_u<1>(state1 == varint_u<2>(0x1l))) {
					copy_state1 = varint_u<2>(0x0l);
				} else {
					copy_state1 = state1 + varint_u<2>(0x1l);
				}
				if (varint_u<1>(state2 == varint_u<2>(0x1l))) {
					copy_state2 = varint_u<2>(0x0l);
				} else {
					copy_state2 = state2 + varint_u<2>(0x1l);
				}
			}
			copy_state5 = varint_u<8>(0x0l);
			copy_state4 = varint_u<8>(0x0l);
			copy_state5 = varint_u<8>(0x0l);
			copy_state4 = varint_u<8>(0x0l);
			copy_state3 = varint_u<1>(0x0l);
			break;
	}
	
	// output assignment
	if (inputdata_broadcast) {
		copy_outputdata_curBuf0 = varint_u<2>(0x2l);
	} else {
		copy_outputdata_curBuf0 = state1;
	}
	if (inputdata_broadcast) {
		copy_outputdata_curBuf1 = varint_u<2>(0x2l);
	} else {
		copy_outputdata_curBuf1 = state2;
	}
	
	// update outputs
	outputdata_curBuf0 = copy_outputdata_curBuf0;
	outputdata_curBuf1 = copy_outputdata_curBuf1;
	
	// update current state
	state1 = copy_state1;
	state2 = copy_state2;
	state4 = copy_state4;
	state5 = copy_state5;
	state6 = copy_state6;
	state3 = copy_state3;
	
}
