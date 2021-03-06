#include "tests_includes.hpp"

typedef TEST_VECTOR<A>	ft_v;

static void	test1(void) {

	std::string	result;
	std_vector	std_vec(SMALL_COUNT, A());
	ft_vector	test_vec(SMALL_COUNT, A());

	for (size_t i = 0; i < SMALL_COUNT; ++i) {
		std_vec.pop_back();
		test_vec.pop_back();
	}

	if (compare_size_cap(test_vec, std_vec)
		&& is_conts_equal(test_vec, std_vec))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

static void	test2(void) {

	std::string	result;
	std_vector	std_vec(g_vecToCompare);
	ft_vector	test_vec(SMALL_COUNT, A());

	std_vec.pop_back();
	test_vec.pop_back();
	for (size_t i = 0; i < SMALL_COUNT / 10; ++i) {
		std_vec.pop_back();
		test_vec.pop_back();
	}

	if (compare_size_cap(test_vec, std_vec)
		&& is_conts_equal(test_vec, std_vec))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

void	run_pop_back_test(void) {

	print << MAGENTA "POP_BACK TESTS: ";
	test1(); test2();
	print << RESET LF;
}
