#include "tests_includes.hpp"

static void	test1(void) {

	std::string	result;
	ft::vector<int>	test_vec(10);
	std::vector<int>	std_vec(10);

	std::vector<int>::iterator it1 = std_vec.insert(std_vec.begin() + 3, 10);
	ft::vector<int>::iterator it2 = test_vec.insert(test_vec.begin() + 3, 10);

	if (compare_size_cap(test_vec, std_vec) && *it1 == *it2
		&& is_conts_equal(test_vec, std_vec))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

void	run_insert_test(void) {

	print << MAGENTA "INSERT TESTS: ";
	test1();
	print << RESET LF;
}
