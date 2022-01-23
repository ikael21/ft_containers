#include "tests_includes.hpp"

typedef std::vector<int>		std_vector;
typedef ft::vector<int>			ft_vector;
typedef ft_vector::iterator		ft_iter;
typedef std_vector::iterator	std_iter;

void	pop_back_test(void) {

	ft_vector	ft_vec(3, 1111);
	std_vector	std_vec(3, 1111);

	print_container_items(ft_vec, FT_VEC);
	print << "size: " << ft_vec.size()
		<< "   capacity: " << ft_vec.capacity() << '\n';
	print_container_items(std_vec, STD_VEC);
	print << "size: " << std_vec.size()
		<< "   capacity: " << std_vec.capacity() << '\n';

	ft_vec.pop_back();
	std_vec.pop_back();

	print << MAGENTA "after pop_back()\n" RESET;
	print_container_items(ft_vec, FT_VEC);
	print << "size: " << ft_vec.size()
		<< "   capacity: " << ft_vec.capacity() << '\n';
	print_container_items(std_vec, STD_VEC);
	print << "size: " << std_vec.size()
		<< "   capacity: " << std_vec.capacity() << '\n';
}
