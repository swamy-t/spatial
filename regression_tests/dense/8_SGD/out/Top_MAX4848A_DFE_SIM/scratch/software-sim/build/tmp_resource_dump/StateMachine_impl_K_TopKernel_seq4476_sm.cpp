#include "StateMachine_impl_K_TopKernel_seq4476_sm.h"
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
maxcompilersim::state_machine::Kernel_TopKernel_seq4476_sm::Kernel_TopKernel_seq4476_sm(maxcompilersim::DebugStreams *debug_output, int node_number) :
m_debug_output(debug_output),
m_node_number(node_number),
state2(0),
state3(0),
state4(0),
state5(0),
state6(0),
state7(0),
state8(0),
state1(0)
{ }



void
maxcompilersim::state_machine::Kernel_TopKernel_seq4476_sm::reset() {
	state2 = 0;
	state3 = 0;
	state4 = 0;
	state5 = 0;
	state6 = 0;
	state7 = 0;
	state8 = 0;
	state1 = 0;
}



void
maxcompilersim::state_machine::Kernel_TopKernel_seq4476_sm::execute(const bool sm_not_flushing) {
	varint_u<1> varint_sm_not_flushing(sm_not_flushing);
	// make copies of current state
	varint_u<32> copy_state2(state2);
	varint_u<32> copy_state3(state3);
	varint_u<32> copy_state4(state4);
	varint_u<1> copy_state5(state5);
	varint_u<1> copy_state6(state6);
	varint_u<1> copy_state7(state7);
	varint_u<1> copy_state8(state8);
	varint_u<3> copy_state1(state1);
	
	// make copies of outputs
	varint_u<1> copy_outputdata_rst_en(outputdata_rst_en);
	varint_u<1> copy_outputdata_s0_en(outputdata_s0_en);
	varint_u<1> copy_outputdata_s1_en(outputdata_s1_en);
	varint_u<1> copy_outputdata_s2_en(outputdata_s2_en);
	varint_u<1> copy_outputdata_s3_en(outputdata_s3_en);
	varint_u<1> copy_outputdata_sm_done(outputdata_sm_done);
	
	
	if (inputdata_sm_en) {
		if (inputdata_s0_done) {
			copy_state5 = varint_u<1>(0x1l);
		}
		if (inputdata_s1_done) {
			copy_state6 = varint_u<1>(0x1l);
		}
		if (inputdata_s2_done) {
			copy_state7 = varint_u<1>(0x1l);
		}
		if (inputdata_s3_done) {
			copy_state8 = varint_u<1>(0x1l);
		}
		switch (static_cast<int>(state1)) {
			case 0:
				copy_state4 = inputdata_sm_numIter;
				copy_state1 = varint_u<3>(0x1l);
				copy_state2 = varint_u<32>(0x0l);
				copy_state3 = varint_u<32>(0x0l);
				break;
			case 1:
				copy_state3 = state3 + varint_u<32>(0x1l);
				if (varint_u<1>(state3 == varint_u<32>(0xal))) {
					copy_state1 = varint_u<3>(0x2l);
				} else {
					copy_state1 = varint_u<3>(0x1l);
				}
				break;
			case 2:
				if (state5) {
					copy_state5 = varint_u<1>(0x0l);
					copy_state6 = varint_u<1>(0x0l);
					copy_state7 = varint_u<1>(0x0l);
					copy_state8 = varint_u<1>(0x0l);
					copy_state1 = varint_u<3>(0x3l);
				}
				break;
			case 3:
				if (state6) {
					copy_state5 = varint_u<1>(0x0l);
					copy_state6 = varint_u<1>(0x0l);
					copy_state7 = varint_u<1>(0x0l);
					copy_state8 = varint_u<1>(0x0l);
					copy_state1 = varint_u<3>(0x4l);
				}
				break;
			case 4:
				if (state7) {
					copy_state5 = varint_u<1>(0x0l);
					copy_state6 = varint_u<1>(0x0l);
					copy_state7 = varint_u<1>(0x0l);
					copy_state8 = varint_u<1>(0x0l);
					copy_state1 = varint_u<3>(0x5l);
				}
				break;
			case 5:
				if (state8) {
					copy_state5 = varint_u<1>(0x0l);
					copy_state6 = varint_u<1>(0x0l);
					copy_state7 = varint_u<1>(0x0l);
					copy_state8 = varint_u<1>(0x0l);
					copy_state2 = state2 + varint_u<32>(0x1l);
					if (varint_u<1>(state2 >= (state4 - varint_u<32>(0x1l)))) {
						copy_state1 = varint_u<3>(0x6l);
					} else {
						copy_state1 = varint_u<3>(0x2l);
					}
				}
				break;
			case 6:
				copy_state5 = varint_u<1>(0x0l);
				copy_state6 = varint_u<1>(0x0l);
				copy_state7 = varint_u<1>(0x0l);
				copy_state8 = varint_u<1>(0x0l);
				copy_state1 = varint_u<3>(0x0l);
				break;
			default:
				copy_state1 = state1;
				break;
		}
	}
	
	// output assignment
	copy_outputdata_sm_done = varint_u<1>(0x0l);
	copy_outputdata_rst_en = varint_u<1>(0x0l);
	copy_outputdata_s0_en = varint_u<1>(0x0l);
	copy_outputdata_s1_en = varint_u<1>(0x0l);
	copy_outputdata_s2_en = varint_u<1>(0x0l);
	copy_outputdata_s3_en = varint_u<1>(0x0l);
	if (inputdata_sm_en) {
		switch (static_cast<int>(state1)) {
			case 1:
				copy_outputdata_rst_en = varint_u<1>(0x1l);
				break;
			case 2:
				copy_outputdata_s0_en = (~(state5 | inputdata_s0_done));
				break;
			case 3:
				copy_outputdata_s1_en = (~(state6 | inputdata_s1_done));
				break;
			case 4:
				copy_outputdata_s2_en = (~(state7 | inputdata_s2_done));
				break;
			case 5:
				copy_outputdata_s3_en = (~(state8 | inputdata_s3_done));
				break;
			case 6:
				copy_outputdata_sm_done = varint_u<1>(0x1l);
				break;
		}
	}
	
	// update outputs
	outputdata_rst_en = copy_outputdata_rst_en;
	outputdata_s0_en = copy_outputdata_s0_en;
	outputdata_s1_en = copy_outputdata_s1_en;
	outputdata_s2_en = copy_outputdata_s2_en;
	outputdata_s3_en = copy_outputdata_s3_en;
	outputdata_sm_done = copy_outputdata_sm_done;
	
	// update current state
	state2 = copy_state2;
	state3 = copy_state3;
	state4 = copy_state4;
	state5 = copy_state5;
	state6 = copy_state6;
	state7 = copy_state7;
	state8 = copy_state8;
	state1 = copy_state1;
	
}
