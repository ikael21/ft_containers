#ifndef TESTS_INCLUDES_H
# define TESTS_INCLUDES_H

# include <iostream>
# include <vector>
# include <chrono>
# include <vector>
# include <map>
# include <stack>

# include "vector.hpp"
# include "stack.hpp"

void	iterator_test(void);
void	speed_test(void);
void	run_insert_tests(void);

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
	std::cout << "\n>>>>>END<<<<<\n" << '\n';
	return;
}

#endif
