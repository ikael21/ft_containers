#include <iostream>
#include <vector>
#include "vector.hpp"
#include <algorithm>
#include <iterator>



int	main(void) {

	ft::vector<int>	vec(10, 10);

	std::fill(vec.begin(), vec.end(), 5);
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
