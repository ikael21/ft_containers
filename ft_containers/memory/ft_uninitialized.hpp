#ifndef FT_UNINITIALIZED_H
# define FT_UNINITIALIZED_H
# include <memory>

namespace ft {


/**
 * Own version of std::uninitialized_copy to support
 * different Allocator classes
**/
template<typename InputIter, typename ForwardIter, typename Allocator>
ForwardIter	uninitialized_copy_a(InputIter first, InputIter last,
								ForwardIter result, Allocator& alloc) {

	ForwardIter	current = result;
	try {
		for (; first != last; ++first, ++current)
			alloc.construct(&(*current), *first);
		return current;
	}
	catch (...) {
		for (; result != current; ++result)
			alloc.destroy(&(*result));
		throw;
	}
}


/**
 * Partial specialization, when Allocator = std::allocator
**/
template<typename InputIter, typename ForwardIter, typename T>
ForwardIter	uninitialized_copy_a(InputIter first, InputIter last,
								ForwardIter result, std::allocator<T>&) {
	return std::uninitialized_copy(first, last, result);
}


/**
 * Own version of std::uninitialized_fill to support
 * different Allocator classes
**/
template<typename ForwardIter, typename T, typename Allocator>
void	uninitialized_fill_a(ForwardIter first, ForwardIter last,
							const T& value, Allocator& alloc) {

	ForwardIter current = first;
	try {
		for (; current != last; ++current)
			alloc.construct(&(*current), value);
	}
	catch (...) {
		for (; first != current; ++first)
			alloc.destroy(&(*first));
		throw;
	}
}


/**
 * Partial specialization, when Allocator = std::allocator
**/
template<typename ForwardIter, typename T1, typename T2>
void	uninitialized_fill_a(ForwardIter first, ForwardIter last,
							const T1& value, std::allocator<T2>&) {
	std::uninitialized_fill(first, last, value);
}


/**
 * Own version of std::uninitialized_fill_n to support
 * different Allocator classes
**/
template<typename ForwardIter, typename Size, typename T, typename Allocator>
void	uninitialized_fill_n_a(ForwardIter first, Size size,
							const T& value, Allocator& alloc) {

	ForwardIter current = first;
	try {
		for (; size > 0; ++current, --size)
			alloc.construct(&(*current), value);
	}
	catch (...) {
		for (; first != current; ++first)
			alloc.destroy(&(*first));
		throw;
	}
}


/**
 * Partial specialization, when Allocator = std::allocator
**/
template<typename ForwardIter, typename Size, typename T1, typename T2>
void	uninitialized_fill_n_a(ForwardIter first, Size size,
							const T1& value, std::allocator<T2>&) {
	std::uninitialized_fill_n(first, size, value);
}


}


#endif
