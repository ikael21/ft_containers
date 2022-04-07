#include "tests_includes.hpp"

static void	test1(void) {

	ft_vector::iterator		iter3;
	ft_vector::iterator		iter4;
	std::string				result;

	if (iter3 == iter4)
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

static void	test2(void) {

	ft_vector				ft_vec(10);
	std_vector::iterator	iter1;
	std_vector::iterator	iter2;
	ft_vector::iterator		iter3;
	ft_vector::iterator		iter4;
	std::string				result;

	iter1 = g_vecToCompare.begin();
	iter2 = g_vecToCompare.end();
	iter3 = ft_vec.begin();
	iter4 = ft_vec.end();
	if (iter1 < iter2 and iter3 < iter4)
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

static void	test3(void) {

	ft_vector				ft_vec(10);
	std_vector::iterator	iter1;
	std_vector::iterator	iter2;
	ft_vector::iterator		iter3;
	ft_vector::iterator		iter4;
	std::string				result;

	iter1 = g_vecToCompare.begin();
	iter2 = g_vecToCompare.end();
	iter3 = ft_vec.begin();
	iter4 = ft_vec.end();

	iter1 = 1 + iter1;
	iter3 = 1 + iter3;
	if (iter1 <= iter2 and iter3 <= iter4)
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

void	run_iterator_test(void) {

	print << MAGENTA "ITERATOR TESTS: ";
	test1(); test2(); test3();
	print << RESET LF;

	std::vector<int>::iterator it1;
	ft::vector<int>::iterator it2;

}
