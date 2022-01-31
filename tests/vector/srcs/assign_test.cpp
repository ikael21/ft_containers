#include "tests_includes.hpp"


static void	test1(void) {

	std::string	result;
	ft_vector	test_vec;

	for (size_t i = 0; i < 1000; ++i)
		test_vec.assign(i, A());

	test_vec.assign(g_begin, g_end);
	if (compare_size_cap(test_vec, g_vecToCompare)
		&& is_conts_equal(test_vec, g_vecToCompare))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

static void	test2(void) {

	std::string	result;
	ft_vector	test_vec;

	for (size_t i = 0; i < 1000; ++i)
		test_vec.assign(i, A());

	test_vec.assign(SMALL_COUNT, A());
	if (compare_size_cap(test_vec, g_vecToCompare)
		&& is_conts_equal(test_vec, g_vecToCompare))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

static void	test3(void) {

	std::string	result;
	std_vector	std_one;
	ft_vector	test_vec;

	std_one.assign(SMALL_COUNT, A());
	test_vec.assign(SMALL_COUNT, A());

	for (size_t i = 1000; i > 0; --i) {
		test_vec.assign(i, A());
		std_one.assign(i, A());
	}

	if (compare_size_cap(test_vec, std_one)
		&& is_conts_equal(test_vec, std_one))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

static void	test4(void) {

	std::string	result;
	ft_vector	test_vec;

	for (size_t i = 0; i < 100; ++i)
		test_vec.assign(g_begin + i + 1, g_end);

	test_vec.assign(g_begin, g_end);
	if (compare_size_cap(test_vec, g_vecToCompare)
		&& is_conts_equal(test_vec, g_vecToCompare))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

static void	test5(void) {

	std::string	result;
	ft_vector	test_vec(10);
	std_vector	std_vec(10);

	test_vec.assign(3, A());
	std_vec.assign(3, A());
	if (compare_size_cap(test_vec, std_vec)
		&& is_conts_equal(test_vec, std_vec))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

void	run_assign_test(void) {

	print << MAGENTA "ASSIGN TESTS: ";
	test1(); test2(); test3(); test4(); test5();
	print << RESET LF;
}
