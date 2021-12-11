#ifndef VECTOR_H
# define VECTOR_H
# include <memory>
# include <algorithm>

namespace ft {


template <class T, class Allocator = std::allocator<T> >
class vector {

public:

	typedef T											value_type;
	typedef Allocator									allocator_type;
	typedef typename allocator_type::size_type			size_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	explicit vector(const allocator_type& alloc = allocator_type()) {

	}

	explicit vector(size_type count,
					const value_type& value = value_type(),
					const allocator_type& alloc = allocator_type()) {

	}

	template<class InputIt>
	vector(InputIt first, InputIt last,
			const allocator_type& alloc = allocator_type()) {

	}

	vector(const vector& other) { *this = other; }

	vector&	operator=(const vector& other) {

	}

protected:

};

}

#endif // VECTOR_H
