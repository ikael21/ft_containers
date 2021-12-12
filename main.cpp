#include <vector>
#include <iostream>
//#include "vector.hpp"

int	main(void) {

//	will be some tests for my containers

	// std::vector<int>	vec(10);
	// ft::vector<int>		my_vec;

	// std::cout << "capacity: " << vec.capacity() << std::endl;
	// std::cout << "size: " << vec.size() << std::endl;

	// std::cout << "my vector capacity: " << my_vec.capacity() << std::endl;
	// std::cout << "my vector size: " << my_vec.size() << std::endl;

	std::allocator<int>	alloc;
	int					*ptr;

	ptr = nullptr;
	alloc.deallocate(ptr, 10);
}
