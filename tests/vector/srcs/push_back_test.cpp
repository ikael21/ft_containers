#include "tests_includes.hpp"

static void	test1(void) {

	std::string	result;
	std_vector	std_vec;
	ft_vector	test_vec;

	for (size_t i = 0; i < SMALL_COUNT; ++i) {
		std_vec.push_back(A());
		test_vec.push_back(A());
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
	std_vector	std_vec(10, A());
	ft_vector	test_vec(10, A());

	for (size_t i = 0; i < SMALL_COUNT; ++i) {
		std_vec.push_back(A());
		test_vec.push_back(A());
	}

	if (compare_size_cap(test_vec, std_vec)
		&& is_conts_equal(test_vec, std_vec))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

void	run_push_back_test(void) {

	print << MAGENTA "PUSH_BACK TESTS: ";
	test1(); test2();
	print << RESET LF;
}
