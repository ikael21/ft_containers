#include <memory>
#include <vector>
#include <iostream>
#include <chrono>
#include "vector.hpp"

using namespace std::chrono;

#define MAX_RAM			4294967296
#define BUFFER_SIZE		4096

struct Buffer {
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT	(MAX_RAM / (int)sizeof(Buffer))

typedef std::vector<Buffer>		std_vector;
typedef ft::vector<Buffer>		my_vector;

void	test_std_vector(void) {

	std_vector	vector_buffer;

	for(size_t i = 0; i < COUNT; ++i)
		vector_buffer.push_back(Buffer());
}

void	test_my_vector(void) {

	my_vector	vector_buffer;

	for(size_t i = 0; i < COUNT; ++i)
		vector_buffer.push_back(Buffer());
}

void	measure_time(void (*func)(void), const char* which_vec) {
	auto start = high_resolution_clock::now();
	func();
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	std::cout << which_vec << ": "
		<< duration.count() / 1000 << " ms" << std::endl;
}

int	main(void) {
	measure_time(test_std_vector, "std. vector");
	measure_time(test_my_vector, "my vector");
	return EXIT_SUCCESS;
}
