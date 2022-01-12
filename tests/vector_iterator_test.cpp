#include "tests_includes.hpp"

#define MAX_ITEMS	10

typedef typename ft::vector<int>::iterator			ft_iter;
typedef typename ft::vector<int>::const_iterator	ft_const_iter;
typedef typename std::vector<int>::iterator			std_iter;
typedef typename std::vector<int>::const_iterator	std_const_iter;

/* ************************************** */
/* Container must have push_back() method */
/* ************************************** */
template<class Container>
void	fill_in_container(Container& c) {

	for (int i = 0; i < MAX_ITEMS; ++i)
		c.push_back(i);
	return;
}

void	iterator_test(void) {

	std::vector<int>	std_vec;
	ft::vector<int>		my_vec;

	fill_in_container(std_vec);
	fill_in_container(my_vec);

	print_container_items(std_vec, "STD VEC");
	print_container_items(my_vec, "MY VEC");

	std_iter iter1 = std_vec.begin();
	std::cout << iter1[5] << std::endl;

	ft_iter iter2 = my_vec.begin();
	std::cout << iter2[5] << std::endl;
	return;
}
