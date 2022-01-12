#include "tests_includes.hpp"

typedef std::vector<int>				std_vector;
typedef ft::vector<int>					ft_vector;
typedef typename ft_vector::iterator	ft_iter;
typedef typename std_vector::iterator	std_iter;

static void	insert_test1(const char* test_name) {

	ft_vector	ft_vec;
	std_vector	std_vec;
	ft_iter		iter_ft;
	std_iter	iter_std;

	std::cout << test_name << std::endl;
	print_container_items(std_vec, "STD VEC");
	print_container_items(ft_vec, "MY VEC");

	iter_ft = ft_vec.insert(ft_vec.end(), 10);
	iter_std = std_vec.insert(std_vec.end(), 10);

	print_container_items(std_vec, "STD VEC");
	print_container_items(ft_vec, "MY VEC");

	std::cout << *iter_std << "    " << *iter_ft << "\n";

	iter_ft = ft_vec.insert(ft_vec.end(), 10);
	iter_std = std_vec.insert(std_vec.end(), 10);

	print_container_items(std_vec, "STD VEC");
	print_container_items(ft_vec, "MY VEC");

	std::cout << *iter_std << "    " << *iter_ft << "\n";
	std::cout << "END OF " << test_name << std::endl;
}

static void	insert_test2(const char* test_name) {

	ft::vector<int>		my_vec(10, 1);
	std::vector<int>	std_vec(10, 1);
	ft_iter				iter1;
	std_iter			iter2;

	std::cout << test_name << std::endl;
	ft_iter mid1 = my_vec.end() - (my_vec.size() / 2);
	std_iter mid2 = std_vec.end() - (std_vec.size() / 2);

	print_container_items(std_vec, "STD VEC");
	print_container_items(my_vec, "MY VEC");

	iter2 = std_vec.insert(mid2, 5);
	iter1 = my_vec.insert(mid1, 5);

	print_container_items(std_vec, "STD VEC");
	print_container_items(my_vec, "MY VEC");

	std::cout << *iter2 << "    " << *iter1 << "\n";
	std::cout << "END OF " << test_name << std::endl;
}

void	run_insert_tests(void) {

	insert_test1("insert method (empty vector)");
	insert_test2("insert method (at the middle)");
}
