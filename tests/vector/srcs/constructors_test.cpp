#include "tests_includes.hpp"


static void	constructor_test1(void) {

	std::string	result;
	ft_vector	test_vec(g_begin, g_end);

	if (compare_size_cap(test_vec, g_vecToCompare)
		&& is_conts_equal(test_vec, g_vecToCompare))
		result = GREEN "OK" RESET;
	else
		result = RED "KO" RESET;
	print << "test1 (iterators constructor)    " << result << RESET "  ";
	return;
}


static void	constructor_test2(void) {

	std::string	result;
	ft_vector	test_vec(SMALL_COUNT, TEST_STRING);

	if (compare_size_cap(test_vec, g_vecToCompare)
		&& is_conts_equal(test_vec, g_vecToCompare))
		result = GREEN "OK";
	else
		result = RED "KO";
	print << "test2 (count, value constructor) " << result << RESET "  ";
}

static void	constructor_test3(void) {

	std::string	result;
	ft_vector	vec1(g_begin, g_end);

	ft_vector	test_vec(vec1);
	if (compare_size_cap(test_vec, g_vecToCompare)
		&& is_conts_equal(test_vec, g_vecToCompare))
		result = GREEN "OK";
	else
		result = RED "KO";
	print << "test3 (copy constructor)         " << result << RESET "  ";
}

void	run_constructor_test(void) {

	size_t	t;

	print << MAGENTA "	CONSTRUCTORS TESTS" RESET LF;
	t = measure_time(constructor_test1);
	print << "time: " << YELLOW << t / 1000 << " ms" RESET LF;
	t = measure_time(constructor_test2);
	print << "time: " << YELLOW << t / 1000 << " ms" RESET LF;
	t = measure_time(constructor_test3);
	print << "time: " << YELLOW << t / 1000 << " ms" RESET LF;
}
