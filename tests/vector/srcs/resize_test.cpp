#include "tests_includes.hpp"

static void	test1(void) {

	std::string	result;
	std_vector	std_vec;
	ft_vector	test_vec;

	std_vec.resize(100);
	test_vec.resize(100);

	if (compare_size_cap(test_vec, std_vec)
		&& is_conts_equal(test_vec, std_vec))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

static void	test2(void) {

	std::string	result;
	std_vector	std_vec(105);
	ft_vector	test_vec(105);

	std_vec.resize(100);
	test_vec.resize(100);

	// print << LF << std_vec.capacity() << " " << std_vec.size();
	// print << LF << test_vec.capacity() << " " << test_vec.size();
	if (compare_size_cap(test_vec, std_vec)
		&& is_conts_equal(test_vec, std_vec))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

static void	test3(void) {
	std::string	result;
	std_vector	std_vec(10);
	ft_vector	test_vec(10);

	std_vec.resize(10);
	test_vec.resize(10);

	// print << LF << std_vec.capacity() << " " << std_vec.size();
	// print << LF << test_vec.capacity() << " " << test_vec.size();
	if (compare_size_cap(test_vec, std_vec)
		&& is_conts_equal(test_vec, std_vec))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

void	run_resize_test(void) {

	print << MAGENTA "RESIZE TESTS: ";
	test1(); test2(); test3();
	print << RESET LF;
}
