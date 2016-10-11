#include "StateMachine_impl_K_TopKernel_void566_sm.h"
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
maxcompilersim::state_machine::Kernel_TopKernel_void566_sm::Kernel_TopKernel_void566_sm(maxcompilersim::DebugStreams *debug_output, int node_number) :
m_debug_output(debug_output),
m_node_number(node_number),
state1(0),
state3(0),
state2(0)
{ }



void
maxcompilersim::state_machine::Kernel_TopKernel_void566_sm::reset() {
	state1 = 0;
	state3 = 0;
	state2 = 0;
}



void
maxcompilersim::state_machine::Kernel_TopKernel_void566_sm::execute(const bool sm_not_flushing) {
	varint_u<1> varint_sm_not_flushing(sm_not_flushing);
	// make copies of current state
	varint_s<32> copy_state1(state1);
	varint_s<32> copy_state3(state3);
	varint_u<3> copy_state2(state2);
	
	// make copies of outputs
	varint_u<1> copy_outputdata_ctr_en(outputdata_ctr_en);
	varint_s<32> copy_outputdata_ctr_maxOut_0(outputdata_ctr_maxOut_0);
	varint_u<1> copy_outputdata_rst_en(outputdata_rst_en);
	varint_u<1> copy_outputdata_sm_done(outputdata_sm_done);
	
	
	if (inputdata_sm_en) {
		switch (static_cast<int>(state2)) {
			case 0:
				copy_state3 = varint_s<32>(0x0l);
				copy_state1 = inputdata_sm_maxIn_0;
				copy_state2 = varint_u<3>(0x1l);
				break;
			case 1:
				if (inputdata_rst_done) {
					copy_state2 = varint_u<3>(0x2l);
				}
				break;
			case 2:
				if (inputdata_ctr_done) {
					copy_state1 = varint_s<32>(0x0l);
					copy_state2 = varint_u<3>(0x3l);
				} else {
					copy_state2 = varint_u<3>(0x2l);
				}
				break;
			case 3:
				copy_state2 = varint_u<3>(0x4l);
				break;
			case 4:
				copy_state2 = varint_u<3>(0x4l);
				break;
			default:
				copy_state2 = state2;
				break;
		}
	} else {
		copy_state2 = varint_u<3>(0x0l);
	}
	
	// output assignment
	copy_outputdata_sm_done = varint_u<1>(0x0l);
	copy_outputdata_ctr_en = varint_u<1>(0x0l);
	copy_outputdata_rst_en = varint_u<1>(0x0l);
	copy_outputdata_ctr_maxOut_0 = varint_s<32>(0x0l);
	if (inputdata_sm_en) {
		switch (static_cast<int>(state2)) {
			case 1:
				copy_outputdata_rst_en = varint_u<1>(0x1l) & (~(inputdata_rst_done));
				break;
			case 2:
				copy_outputdata_ctr_en = varint_u<1>(0x1l) & (~(inputdata_ctr_done));
				copy_outputdata_ctr_maxOut_0 = state1;
				break;
			case 3:
				copy_outputdata_sm_done = varint_u<1>(0x1l);
				break;
		}
	}
	
	// update outputs
	outputdata_ctr_en = copy_outputdata_ctr_en;
	outputdata_ctr_maxOut_0 = copy_outputdata_ctr_maxOut_0;
	outputdata_rst_en = copy_outputdata_rst_en;
	outputdata_sm_done = copy_outputdata_sm_done;
	
	// update current state
	state1 = copy_state1;
	state3 = copy_state3;
	state2 = copy_state2;
	
}
