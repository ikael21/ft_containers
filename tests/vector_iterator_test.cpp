#include "vector.hpp"
#include <vector>
#include <iostream>

#define MAX_ITEMS	10

/* ************************************** */
/* Container must have push_back() method */
/* ************************************** */
template<class Container>
void	fill_in_container(Container& c) {

	for (int i = 0; i < MAX_ITEMS; ++i)
		c.push_back(i);
	return;
}

/* ************************************* */
/* Container must have iterator system,  */
/* begin() and end() methods             */
/* ************************************* */
template<class Container>
void	print_container_items(Container& c, const char* which_cont) {

	typedef typename Container::iterator	iter;

	std::cout << which_cont << std::endl;
	for(iter it = c.begin(); it != c.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << ">>>>>END<<<<<"
		<< std::endl << std::endl;
	return;
}

int	main(void) {

	std::vector<int>	std_vec;
	ft::vector<int>		my_vec;

	fill_in_container(std_vec);
	fill_in_container(my_vec);

	print_container_items(std_vec, "STD VECTOR");
	print_container_items(my_vec, "MY VECTOR");


}

