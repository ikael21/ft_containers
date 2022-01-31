#include "tests_includes.hpp"


static void	test1(void) {

	std::string	result;
	ft_vector	test_vec(g_begin, g_end);

	if (compare_size_cap(test_vec, g_vecToCompare)
		&& is_conts_equal(test_vec, g_vecToCompare))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}


static void	test2(void) {

	std::string	result;
	ft_vector	test_vec(SMALL_COUNT, A());

	if (compare_size_cap(test_vec, g_vecToCompare)
		&& is_conts_equal(test_vec, g_vecToCompare))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

static void	test3(void) {

	std::string	result;
	ft_vector	vec1(g_begin, g_end);

	ft_vector	test_vec(vec1);
	if (compare_size_cap(test_vec, g_vecToCompare)
		&& is_conts_equal(test_vec, g_vecToCompare))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

void	run_constructor_test(void) {

	print << MAGENTA "CONSTRUCTORS TESTS: ";
	test1(); test2(); test3();
	print << RESET LF;
}
