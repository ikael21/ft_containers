#include "tests_includes.hpp"
#include <algorithm>


static void	assign_test1(void) {

	std::string	result;
	ft_vector	test_vec;

	for (size_t i = 0; i < 1000; ++i)
		test_vec.assign(i, "a");

	test_vec.assign(g_begin, g_end);
	if (compare_size_cap(test_vec, g_vecToCompare)
		&& is_conts_equal(test_vec, g_vecToCompare))
		result = GREEN "OK";
	else
		result = RED "KO";
	print << "test1 assign(first, last)        " << result << RESET "  ";
}

static void	assign_test2(void) {

	std::string	result;
	ft_vector	test_vec;

	for (size_t i = 0; i < 1000; ++i)
		test_vec.assign(i, "a");

	test_vec.assign(SMALL_COUNT, TEST_STRING);
	if (compare_size_cap(test_vec, g_vecToCompare)
		&& is_conts_equal(test_vec, g_vecToCompare))
		result = GREEN "OK";
	else
		result = RED "KO";
	print << "test2 assign(count, value)       " << result << RESET "  ";
}

static void	assign_test3(void) {

	std::string	result;
	std_vector	std_one;
	ft_vector	test_vec;

	std_one.assign(SMALL_COUNT, TEST_STRING);
	test_vec.assign(SMALL_COUNT, TEST_STRING);

	for (size_t i = 1000; i > 0; --i) {
		test_vec.assign(i, "a");
		std_one.assign(i, "a");
	}

	if (compare_size_cap(test_vec, std_one)
		&& is_conts_equal(test_vec, std_one))
		result = GREEN "OK";
	else
		result = RED "KO";
	print << "test3 assign(count < size)       " << result << RESET "  ";
}

static void	assign_test4(void) {

	std::string	result;
	ft_vector	test_vec;
	std_vector	std_one;

	for (size_t i = 0; i < 100; ++i)
		test_vec.assign(g_begin + i + 1, g_end);

	test_vec.assign(g_begin, g_end);
	if (compare_size_cap(test_vec, g_vecToCompare)
		&& is_conts_equal(test_vec, g_vecToCompare))
		result = GREEN "OK";
	else
		result = RED "KO";
	print << "multiple assign(first, last)     " << result << RESET "  ";
}

void	print_item(std::string& s) { print << s << std::endl; }

void	run_assign_test(void) {

	size_t	t;

	print << MAGENTA "	ASSIGN TESTS" RESET LF;
	t = measure_time(assign_test1);
	print << "time: " << YELLOW << t / 1000 << " ms" RESET LF;
	t = measure_time(assign_test2);
	print << "time: " << YELLOW << t / 1000 << " ms" RESET LF;
	t = measure_time(assign_test3);
	print << "time: " << YELLOW << t / 1000 << " ms" RESET LF;
	t = measure_time(assign_test4);
	print << "time: " << YELLOW << t / 1000 << " ms" RESET LF;
}
