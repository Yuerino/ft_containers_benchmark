#include "benchmark/benchmark.h"

#include <cstdlib>

#include "vector.hpp"
#include <vector>

namespace {
	ft::vector<int> ConstructRandomFtVector(int size) {
		ft::vector<int> v;
		for (int i = 0; i < size; ++i)
			v.push_back(std::rand() % size);
		return v;
	}

	std::vector<int> ConstructRandomStdVector(int size) {
		std::vector<int> v;
		for (int i = 0; i < size; ++i)
			v.push_back(std::rand() % size);
		return v;
	}

	class FtVector : public ::benchmark::Fixture {
	public:
		void SetUp(const ::benchmark::State& st) BENCHMARK_OVERRIDE {
			v = ConstructRandomFtVector(static_cast<int>(st.range(0)));
		}

		void TearDown(const ::benchmark::State&) BENCHMARK_OVERRIDE {
			v.clear();
		}

		ft::vector<int> v;
	};

	class StdVector : public ::benchmark::Fixture {
	public:
		void SetUp(const ::benchmark::State& st) BENCHMARK_OVERRIDE {
			v = ConstructRandomStdVector(static_cast<int>(st.range(0)));
		}

		void TearDown(const ::benchmark::State&) BENCHMARK_OVERRIDE {
			v.clear();
		}

		std::vector<int> v;
	};
}
