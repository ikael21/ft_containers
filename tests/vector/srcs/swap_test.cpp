#include "tests_includes.hpp"

static void	std_vec(void) {

	std::vector<std::string>	vec1(SMALL_COUNT * 10, "vec1");
	std::vector<std::string>	vec2(SMALL_COUNT * 10, "vec2");

	std::swap(vec1, vec2);
}

static void	ft_vec(void) {

	ft::vector<std::string>	vec1(SMALL_COUNT * 10, "vec1");
	ft::vector<std::string>	vec2(SMALL_COUNT * 10, "vec2");

	std::swap(vec1, vec2);
}

static void	test1(void) {

	size_t	time;

	time = measure_time(std_vec);
	print << YELLOW "std_vec: " << time / 1000 << " ms" RESET LF;
	time = measure_time(ft_vec);
	print << YELLOW "ft_vec: " << time / 1000 << " ms" RESET LF;
}

void	run_swap_test(void) {

	print << MAGENTA "SWAP TESTS:\n";
	test1();
	print << RESET LF;
}
