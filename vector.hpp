#ifndef VECTOR_H
# define VECTOR_H
# include <memory>

namespace ft {


template <class T, class Allocator = std::allocator<T> >
class vector {

public:

	typedef T																value_type;
	typedef Allocator														allocator_type;
	typedef typename allocator_type::size_type								size_type;
	typedef typename allocator_type::reference								reference;
	typedef typename allocator_type::const_reference						const_reference;
	typedef typename allocator_type::pointer								pointer;
	typedef typename allocator_type::const_pointer							const_pointer;

	explicit vector(const allocator_type& alloc = allocator_type())
	: _alloc(alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr) {}

	explicit vector(size_type count, const value_type& value = value_type(),
					const allocator_type& alloc = allocator_type())
	: _alloc(alloc) {
		_start = _alloc.allocate(count);
		for (std::size_t i = 0; i < count; ++i)
			_start[i] = value;
		_end = _start + count;
		_end_capacity = _start + count;
		return;
	}

/*	constructor with iterators as arguments

	template<class InputIt>
	vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type());
*/

	vector(const vector& other) { *this = other; }

	vector&	operator=(const vector& other) {
		if (this == &other)
			return *this;
		_alloc.deallocate(_start, _end_capacity - _start);
		_alloc = other._alloc;
		_start = _alloc.allocate(other.capacity());
		for (std::size_t i = 0; i < other.size(); ++i)
			_start[i] = other._start[i];
		_end = _start + other.size();
		_end_capacity = _start + other.capacity();
		return *this;
	}

	std::size_t	capacity(void) const { return _end_capacity - _start; }
	std::size_t	size(void) const { return _end - _start; }
	bool		empty(void) const { return (_start == _end); }

protected:

	allocator_type	_alloc;
	pointer			_start;
	pointer			_end;
	pointer			_end_capacity;

};

}

#endif // VECTOR_H
