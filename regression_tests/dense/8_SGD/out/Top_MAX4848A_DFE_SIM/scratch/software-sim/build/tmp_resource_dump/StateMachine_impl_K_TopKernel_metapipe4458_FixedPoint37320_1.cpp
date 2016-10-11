#include "StateMachine_impl_K_TopKernel_metapipe4458_FixedPoint37320_1.h"
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
maxcompilersim::state_machine::Kernel_TopKernel_metapipe4458_FixedPoint37320_1::Kernel_TopKernel_metapipe4458_FixedPoint37320_1(maxcompilersim::DebugStreams *debug_output, int node_number) :
m_debug_output(debug_output),
m_node_number(node_number),
state2(0),
state1(0)
{ }



void
maxcompilersim::state_machine::Kernel_TopKernel_metapipe4458_FixedPoint37320_1::reset() {
	state2 = 0;
	state1 = 0;
}



void
maxcompilersim::state_machine::Kernel_TopKernel_metapipe4458_FixedPoint37320_1::execute(const bool sm_not_flushing) {
	varint_u<1> varint_sm_not_flushing(sm_not_flushing);
	// make copies of current state
	varint_u<1> copy_state2(state2);
	varint_u<2> copy_state1(state1);
	
	// make copies of outputs
	varint_u<1> copy_outputdata_curBuf(outputdata_curBuf);
	
	
	switch (static_cast<int>(state1)) {
		case 0:
			if (inputdata_w_done) {
				copy_state1 = varint_u<2>(0x3l);
			}
			break;
		case 2:
			if (inputdata_r_done & inputdata_w_done) {
				copy_state1 = varint_u<2>(0x3l);
			} else {
				if (inputdata_r_done) {
					copy_state1 = varint_u<2>(0x0l);
				} else {
					if (inputdata_w_done) {
						copy_state1 = varint_u<2>(0x1l);
					}
				}
			}
			break;
		case 1:
			if (inputdata_r_done) {
				copy_state1 = varint_u<2>(0x3l);
			}
			break;
		case 3:
			copy_state2 = (~(state2));
			copy_state1 = varint_u<2>(0x2l);
			break;
		default:
			copy_state1 = state1;
			break;
	}
	
	// output assignment
	copy_outputdata_curBuf = state2;
	
	// update outputs
	outputdata_curBuf = copy_outputdata_curBuf;
	
	// update current state
	state2 = copy_state2;
	state1 = copy_state1;
	
}
