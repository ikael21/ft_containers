#include "tests_includes.hpp"

static void	test1(void) {

	std::string			result;
	ft::vector<int>		test_vec(2);
	std::vector<int>	std_vec(2);

	test_vec.insert(test_vec.begin() + 1, 10, 1);
	std_vec.insert(std_vec.begin() + 1, 10, 1);

	if (compare_size_cap(test_vec, std_vec)
		&& is_conts_equal(test_vec, std_vec))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

static void test2(void) {

	std::string			result;
	ft::vector<A>		test_vec;
	std::vector<A>		std_vec;

	std::vector<A>	tmp(4, A());

	for (size_t i = 0; i < 10; ++i) {
		test_vec.push_back(A());
		std_vec.push_back(A());
	}

	test_vec.insert(test_vec.begin() + 1, tmp.begin(), tmp.end());
	std_vec.insert(std_vec.begin() + 1, tmp.begin(), tmp.end());

	if (compare_size_cap(test_vec, std_vec)
		&& is_conts_equal(test_vec, std_vec))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

void	run_insert_test(void) {

	print << MAGENTA "INSERT TESTS: ";
	test1(); test2();
	print << RESET LF;
}
