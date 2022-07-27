#include "vector_helper.hpp"

namespace {
	BENCHMARK_DEFINE_F(FtVector, PushBackFull)(::benchmark::State& state) {
		const int size = static_cast<int>(state.range(0));
		for (auto _ : state) {
			for (int i = 0; i < size; ++i) {
				v.push_back(std::rand() % size);
				::benchmark::ClobberMemory();
			}
		}
	}
	BENCHMARK_REGISTER_F(FtVector, PushBackFull)->Range(1 << 3, 1 << 12);

	BENCHMARK_DEFINE_F(StdVector, PushBackFull)(::benchmark::State& state) {
		const int size = static_cast<int>(state.range(0));
		for (auto _ : state) {
			for (int i = 0; i < size; ++i) {
				v.push_back(std::rand() % size);
				::benchmark::ClobberMemory();
			}
		}
	}
	BENCHMARK_REGISTER_F(StdVector, PushBackFull)->Range(1 << 3, 1 << 12);
}
