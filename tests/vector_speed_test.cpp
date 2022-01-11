#include "tests_includes.hpp"

using namespace std::chrono;

#define MAX_RAM			4294967296
#define BUFFER_SIZE		4096
#define MY_VEC			"my vector"
#define STD_VEC			"std. vector"

struct Buffer {
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT	(MAX_RAM / (int)sizeof(Buffer))

typedef std::vector<Buffer>	std_vector;
typedef ft::vector<Buffer>	my_vector;

/* ************************************** */
/* Container must have push_back() method */
/* ************************************** */
template<class Container>
void	speed_test(void) {

	Container	c;

	for(size_t i = 0; i < COUNT; ++i)
		c.push_back(Buffer());
	return;
}

void	measure_time(void (*func)(void),
					const std::string& which_vec) {

	system_clock::time_point	start, end;
	microseconds				duration;

	start = high_resolution_clock::now();
	func();
	end = high_resolution_clock::now();

	duration = duration_cast<microseconds>(end - start);
	std::cout << which_vec << ": "
		<< duration.count() / 1000 << " ms" << std::endl;
	return;
}

void	run_speed_test(void) {
	measure_time(speed_test<my_vector> ,MY_VEC);
	measure_time(speed_test<std_vector>, STD_VEC);
	return;
}

//	if I want to compile this file as separate binary
int	main(void) {
	run_speed_test();
}
